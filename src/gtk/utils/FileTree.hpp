#pragma once

#include <map>
#include <string>
#include <memory>

#include <libtorrent/file_storage.hpp>

#include <gtorrent/Torrent.hpp>

// It's safe to assume alphabetical order, so we can mix the
// files in the hierarchy with various torrent information on the files
// and the torrent state

class FileTree
{
	public:
	FileTree(libtorrent::file_storage files, std::shared_ptr<gt::Torrent> tor);
	FileTree(FileTree *Parent);
	~FileTree();

	std::string fullname();
	void add(std::string &str);

	bool                             is_dir;
	int                              index;
	FileTree                        *parent = nullptr;
	libtorrent::file_storage         fs;
	std::map<std::string, FileTree*> children;
	std::shared_ptr<gt::Torrent>     t;
	std::string                      filename;
};
