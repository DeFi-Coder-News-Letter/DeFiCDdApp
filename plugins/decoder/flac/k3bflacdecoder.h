/* 
 * FLAC decoder module for K3b.
 * Based on the Ogg Vorbis module for same.
 * Copyright (C) 1998-2008 Sebastian Trueg <trueg@k3b.org>
 * Copyright (C) 2003 John Steele Scott <toojays@toojays.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * See the file "COPYING" for the exact licensing terms.
 */


#ifndef _K3B_FLAC_DECODER_H_
#define _K3B_FLAC_DECODER_H_


#include "k3baudiodecoder.h"

class K3bFLACDecoderFactory : public K3b::AudioDecoderFactory
{
    Q_OBJECT

public:
    K3bFLACDecoderFactory( QObject* parent, const QVariantList& args );
    ~K3bFLACDecoderFactory() override;

    bool canDecode( const QUrl& filename ) override;

    int pluginSystemVersion() const override { return K3B_PLUGIN_SYSTEM_VERSION; }

    K3b::AudioDecoder* createDecoder( QObject* parent = 0  ) const override;
};


class K3bFLACDecoder : public K3b::AudioDecoder
{
    Q_OBJECT

public: 
    explicit K3bFLACDecoder( QObject* parent = 0  );
    ~K3bFLACDecoder() override;

    void cleanup() override;

    bool seekInternal( const K3b::Msf& ) override;

    QString fileType() const override;
    QStringList supportedTechnicalInfos() const override;
    QString technicalInfo( const QString& ) const override;

protected:
    bool analyseFileInternal( K3b::Msf& frames, int& samplerate, int& ch ) override;
    bool initDecoderInternal() override;

    int decodeInternal( char* _data, int maxLen ) override;

private:
    class Private;
    Private* d;
};

#endif
