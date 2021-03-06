#ifndef WILDSTAR_DATA_C_INDEX_FILE_NODE_H
#define WILDSTAR_DATA_C_INDEX_FILE_NODE_H

#include <QByteArray>

#include "a_index_node.h"
#include "c_hash.h"

namespace wildstar
{
    namespace data
    {
        class CIndexDirectoryNode;

        class WILDSTAR_DATA_SHARED CIndexFileNode : public AIndexNode
        {
        public:

            explicit CIndexFileNode( CIndexDirectoryNode* parent );
            virtual ~CIndexFileNode();

            virtual void read( QDataStream& stream );

            virtual quint64 size() const;
            virtual quint64 compressedSize() const;

            virtual const CHash& hash() const;

        private:
            quint32     unknown_04_;
            quint64     file_time_; // FILETIME
            quint64     size_;
            quint64     compressed_size_;
            CHash       hash_;
            quint32     unknown_34_; // mabye padding to put sha-1 in 3 uint64
        };

        WILDSTAR_DATA_SHARED QDataStream& operator>>( QDataStream& stream, CIndexFileNode* file );
    }
}

#endif // WILDSTAR_DATA_C_INDEX_FILE_NODE_H
