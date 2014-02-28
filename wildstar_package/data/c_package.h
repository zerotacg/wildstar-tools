#ifndef WILDSTAR_DATA_C_PACKAGE_H
#define WILDSTAR_DATA_C_PACKAGE_H

#include <QFile>

namespace wildstar
{
    namespace data
    {
        class CPackage
        {
        public:
            struct Header
            {
                enum {
                    UNKNOWN_8_COUNT     = 64
                };

                quint32  magic;
                quint32  version;
                quint64  unkown_008[UNKNOWN_8_COUNT];
                qint64   file_size;
                quint64  unkown_210;
                qint64   block_descriptions_offset;
                quint32  block_count;
                quint32  unkown_224_block_index; // some block index, maybe block_list block index
                quint32  type_block_index;
            };

            struct BlockDescription
            {
                qint64  offset;
                qint64  size;
            };

            enum {
                MAGIC                   = 0x5041434B // PACK
              , VERSION                 = 1
              , MINIMUM_FILE_SIZE       = 0x240
              , HEADER_SIZE             = 0x230
              , BLOCK_DESCRIPTION_SIZE  = 0x10
              , MINIMUM_BLOCK_OFFSET    = MINIMUM_FILE_SIZE
            };

            explicit CPackage( const QString& file_name );
            virtual ~CPackage() {}

            virtual void open();

            virtual quint32 getBlockCount() const;

            virtual QByteArray read( qint64 offset, qint64 bytes );
            virtual QByteArray readBlock( quint32 index );
            virtual QByteArray readTypeBlock();

        protected:
            virtual void clear();
            virtual void loadHeader();
            virtual void loadBlocks();

            virtual void checkFile();
            virtual void checkHeader() const;
            virtual void checkBlocks() const;

        private:
            QFile                       file_;
            Header                      header_;
            QList<BlockDescription>     blocks_;
        };

        QDataStream& operator>>( QDataStream& stream, CPackage::Header& header );
        QDataStream& operator>>( QDataStream& stream, CPackage::BlockDescription& description );
    }
}
#endif // WILDSTAR_DATA_C_PACKAGE_H
