# GDB pretty printer for LFUCache::ListEntry.
# The stock libstdc++ iterator printer renders the whole pointed-to bucket, whose
# lru_list holds entries pointing back at the bucket -> endless recursion in CLion.
# This shows the back-iterator as the bucket count only. Loaded by ./.gdbinit.

import gdb

class ListEntryPrinter:
    """Show the back-iterator as the bucket's count only, instead of the whole bucket."""
    def __init__(self, val):
        self.val = val
    def to_string(self):
        it = self.val['it_counter_list_entry']
        node = it['_M_node']
        if not node:
            bucket = 'none'
        else:
            etype = it.type.strip_typedefs().template_argument(0)
            ntype = gdb.lookup_type('std::_List_node<%s>' % etype).pointer()
            elem = node.cast(ntype)['_M_storage'].address.cast(etype.pointer()).dereference()
            bucket = 'count=%d' % int(elem['count'])
        return '{key=%d, value=%d, bucket=%s}' % (int(self.val['key']), int(self.val['value']), bucket)

def lookup(val):
    t = val.type.strip_typedefs()
    if t.code == gdb.TYPE_CODE_STRUCT and t.tag and t.tag.split('::')[-1] == 'ListEntry':
        return ListEntryPrinter(val)
    return None

gdb.pretty_printers.insert(0, lookup)
