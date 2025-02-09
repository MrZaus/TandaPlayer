#ifndef PlaylistModel_H_
#define PlaylistModel_H_

#include <QAbstractListModel>
#include <QModelIndex>
#include <QVariant>
#include <qabstractitemmodel.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qtmetamacros.h>
#include <qvariant.h>

#include "playlist.h"

enum class TPRoles : int
{
	TypeRole = Qt::UserRole + 0,
	SizeRole = Qt::UserRole + 1,
	DurationRole = Qt::UserRole + 2,
	ListRole = Qt::UserRole + 3
};

class PlaylistModel : public QAbstractListModel
{
	Q_OBJECT
public:
	PlaylistModel(const PlaylistModel &) = delete;
	PlaylistModel(PlaylistModel &&) = delete;
	PlaylistModel &operator=(const PlaylistModel &) = delete;
	PlaylistModel &operator=(PlaylistModel &&) = delete;

	PlaylistModel(QObject *parent = nullptr) : QAbstractListModel(parent) {};
	int rowCount(const QModelIndex & /*parent*/ = QModelIndex()) const override
	{
		return static_cast<int>(playlist.size());
	}
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
	{
		switch (role)
		{
		case std::to_underlying(TPRoles::TypeRole):
			return QVariant::fromValue(playlist.getItem(index.row())->getTypeName());
		case std::to_underlying(TPRoles::SizeRole):
			return QVariant::fromValue(playlist.getItem(index.row())->getSize());
		case std::to_underlying(TPRoles::DurationRole):
			return QVariant::fromValue(playlist.getItem(index.row())->getTotalTime());
		case std::to_underlying(TPRoles::ListRole):
			return QVariant::fromValue(playlist.getItem(index.row())->getItems());
		default:
			return {}; // TODO implement
		}
	}
	Qt::ItemFlags flags(const QModelIndex & /*index*/) const override
	{
		return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
	}
	QVariant headerData(int /*section*/, Qt::Orientation /*orientation*/, int /*role*/ = Qt::DisplayRole) const override
	{
		return {}; // TODO implement
	}
	bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override
	{
		beginInsertRows(parent, row, count);
		playlist.addNextTanda();
		setData(index(row), QVariant::fromValue(playlist.getItem(row)->getTypeName()), Qt::UserRole);
		endInsertRows();
		return true; // TODO implement
	}
	~PlaylistModel() override = default;

private:
	Playlist playlist;
};

#endif // __PlaylistModel_H__