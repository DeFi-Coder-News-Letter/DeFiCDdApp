/*
 *
 * Copyright (C) 2003-2008 Sebastian Trueg <trueg@k3b.org>
 *
 * This file is part of the K3b project.
 * Copyright (C) 1998-2008 Sebastian Trueg <trueg@k3b.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * See the file "COPYING" for the exact licensing terms.
 */

#ifndef _K3B_SESSION_IMPORT_ITEM_H_
#define _K3B_SESSION_IMPORT_ITEM_H_

#include "k3bspecialdataitem.h"

namespace K3b {
    class DataDoc;
    class FileItem;
    class DirItem;
    class Iso9660File;

    class SessionImportItem : public SpecialDataItem
    {
    public:
        explicit SessionImportItem( const Iso9660File* );
        SessionImportItem( const SessionImportItem& );
        ~SessionImportItem() override;

        DataItem* copy() const override;

        FileItem* replaceItem() const { return m_replaceItem; }
        void setReplaceItem( FileItem* item ) { m_replaceItem = item; }

        bool isRemoveable() const override { return false; }
        bool isMoveable() const override { return false; }
        bool isRenameable() const override { return false; }
        bool isHideable() const override { return false; }
        bool writeToCd() const override { return false; }

    private:
        FileItem* m_replaceItem;
    };
}

#endif
