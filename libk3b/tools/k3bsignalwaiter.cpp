/*
 *
 * Copyright (C) 2005 Sebastian Trueg <trueg@k3b.org>
 *
 * This file is part of the K3b project.
 * Copyright (C) 1998-2007 Sebastian Trueg <trueg@k3b.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * See the file "COPYING" for the exact licensing terms.
 */

#include "k3bsignalwaiter.h"
#include "k3bjob.h"

#include <QEventLoop>

class K3b::SignalWaiter::Private
{
public:
    QEventLoop loop;
};


K3b::SignalWaiter::SignalWaiter()
    : QObject(),
      d( new Private() )
{
}


K3b::SignalWaiter::~SignalWaiter()
{
    delete d;
}


void K3b::SignalWaiter::waitForSignal( QObject* o, const char* signal )
{
    K3b::SignalWaiter w;
    connect( o, signal,
             &w, SLOT(slotSignal()) );

    w.d->loop.exec();
}


void K3b::SignalWaiter::waitForJob( K3b::Job* job )
{
    if( !job->active() )
        return;

    waitForSignal( job, SIGNAL(finished(bool)) );
}


void K3b::SignalWaiter::slotSignal()
{
    if( d->loop.isRunning() ) {
        d->loop.exit();
    }
}


