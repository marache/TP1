#include "File.h"
#include "Folder.h"

File::File(const QString &name, Size size, Folder &parent) :
    Element { name, &parent},
    size {size}
{
    size = size;
}

void File::on_element_displayed(QTextStream &ts, const QString &/*tab*/)
{
    ts << "\n";
}
