#ifndef __PlaylistModel_H__
#define __PlaylistModel_H__

#include <QAbstractListModel>
#include <QModelIndex>
#include <QVariant>

class PlaylistModel : public QAbstractListModel
{
	Q_OBJECT
public:
	// PlaylistModel() = delete;
	PlaylistModel(const PlaylistModel &) = delete;
	PlaylistModel(PlaylistModel &&) = delete;
	PlaylistModel &operator=(const PlaylistModel &) = delete;
	PlaylistModel &operator=(PlaylistModel &&) = delete;

	PlaylistModel(QObject *parent = nullptr) : QAbstractListModel(parent){};
	int rowCount(const QModelIndex &parent = QModelIndex()) const override
	{
		return 4;
	}
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
	{
		return QVariant(); // TODO implement
	}
	Qt::ItemFlags flags(const QModelIndex &index) const override
	{
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
	}
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{
		return QVariant(); // TODO implement
	}

	~PlaylistModel() = default;
};

#endif // __PlaylistModel_H__