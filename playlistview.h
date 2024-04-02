#ifndef __PlaylistView_H__
#define __PlaylistView_H__

#include <QListView>
#include <QMouseEvent>

class PlaylistView : public QListView
{
	Q_OBJECT
public:
	PlaylistView(QWidget *parent = nullptr) : QListView(parent)
	{
		setMouseTracking(true);
		connect(this, &QListView::entered, this, &PlaylistView::entered);
	};
	PlaylistView(const PlaylistView &) = delete;
	PlaylistView(PlaylistView &&) = delete;
	PlaylistView &operator=(const PlaylistView &);
	PlaylistView &operator=(PlaylistView &&) = delete;

	~PlaylistView() override = default;

	// void mouseMoveEvent(QMouseEvent *event) override;

private slots:
	void entered(const QModelIndex &index)
	{
		setCurrentIndex(index);
		edit(index, QAbstractItemView::AllEditTriggers, new QHoverEvent(QMouseEvent::HoverEnter, QPointF{}, QPointF{}, QPointF{}));
	}
};

#endif // __PlaylistView_H__