#ifndef VPZ_APKSTUDIO_HELPERS_PROJECTS_HPP
#define VPZ_APKSTUDIO_HELPERS_PROJECTS_HPP

#include <QDir>
#include <QFileInfo>
#include <QStandardItemModel>
#include "resources/embedded.hpp"
#include "settings.hpp"

namespace VPZ {
namespace APKStudio {
namespace Helpers {

class Projects : public QStandardItemModel
{
    Q_OBJECT
private:
    QList<QMetaObject::Connection> connections;
    QStringList folders;
    QStringList editables;
public:
    explicit Projects(QObject * = 0);
    bool close(const QModelIndex &);
    inline bool open(const QString &path) { return open(QFileInfo(path)); }
    bool open(const QFileInfo &);
    void traverse(QStandardItem *);
    ~Projects();
};

} // namespace Helpers
} // namespace APKStudio
} // namespace VPZ

#endif // VPZ_APKSTUDIO_HELPERS_PROJECTS_HPP
