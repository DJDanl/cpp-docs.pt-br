---
title: Classe CnoworkerThread
ms.date: 11/04/2016
f1_keywords:
- CNoWorkerThread
- ATLUTIL/ATL::CNoWorkerThread
- ATLUTIL/ATL::CNoWorkerThread::AddHandle
- ATLUTIL/ATL::CNoWorkerThread::AddTimer
- ATLUTIL/ATL::CNoWorkerThread::GetThreadHandle
- ATLUTIL/ATL::CNoWorkerThread::GetThreadId
- ATLUTIL/ATL::CNoWorkerThread::Initialize
- ATLUTIL/ATL::CNoWorkerThread::RemoveHandle
- ATLUTIL/ATL::CNoWorkerThread::Shutdown
helpviewer_keywords:
- CNoWorkerThread class
ms.assetid: 29f06bae-b658-4aac-9c14-331e996d25d1
ms.openlocfilehash: 90056e648a53218ac06083d43ca34870e1ca72fc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326701"
---
# <a name="cnoworkerthread-class"></a>Classe CnoworkerThread

Use esta classe como `MonitorClass` argumento para o parâmetro de modelo para classes de cache se você quiser desativar a manutenção do cache dinâmico.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CNoWorkerThread
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CnoWorkerthread::AddHandle](#addhandle)|Equivalente não funcional do [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).|
|[CNoWorkerThread::AddTimer](#addtimer)|Equivalente não funcional do [CWorkerThread::AddTimer](../../atl/reference/cworkerthread-class.md#addtimer).|
|[Cnoworkerthread::GetThreadHandle](#getthreadhandle)|Equivalente não funcional do [CWorkerThread::GetThreadHandle](../../atl/reference/cworkerthread-class.md#getthreadhandle).|
|[CNoWorkerThread::GetThreadId](#getthreadid)|Equivalente não funcional do [CWorkerThread::GetThreadId](../../atl/reference/cworkerthread-class.md#getthreadid).|
|[CNoWorkerThread::Inicializar](#initialize)|Equivalente não funcional do [CWorkerThread::Initialize](../../atl/reference/cworkerthread-class.md#initialize).|
|[CnoWorkerthread::removeHandle](#removehandle)|Equivalente não funcional do [CWorkerThread::RemoveHandle](../../atl/reference/cworkerthread-class.md#removehandle).|
|[CNoWorkerThread::Desligamento](#shutdown)|Equivalente não funcional do [CWorkerThread::Shutdown](../../atl/reference/cworkerthread-class.md#shutdown).|

## <a name="remarks"></a>Comentários

Esta classe fornece a mesma interface pública que [cWorkerThread](../../atl/reference/cworkerthread-class.md). Espera-se que essa interface `MonitorClass` seja fornecida pelo parâmetro modelo para classes de cache.

Os métodos desta classe são implementados para não fazer nada. Os métodos que retornam um HRESULT sempre retornam S_OK, e os métodos que retornam um HANDLE ou thread ID retornam sempre 0.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="cnoworkerthreadaddhandle"></a><a name="addhandle"></a>CnoWorkerthread::AddHandle

Equivalente não funcional do [CWorkerThread::AddHandle](../../atl/reference/cworkerthread-class.md#addhandle).

```
HRESULT AddHandle(HANDLE /* hObject */,
    IWorkerThreadClient* /* pClient */,
    DWORD_PTR /* dwParam */) throw();
```

### <a name="return-value"></a>Valor retornado

Sempre volta S_OK.

### <a name="remarks"></a>Comentários

A implementação fornecida por esta classe não faz nada.

## <a name="cnoworkerthreadaddtimer"></a><a name="addtimer"></a>CNoWorkerThread::AddTimer

Equivalente não funcional do [CWorkerThread::AddTimer](../../atl/reference/cworkerthread-class.md#addtimer).

```
HRESULT AddTimer(DWORD /* dwInterval */,
    IWorkerThreadClient* /* pClient */,
    DWORD_PTR /* dwParam */,
    HANDLE* /* phTimer */) throw();
```

### <a name="return-value"></a>Valor retornado

Sempre volta S_OK.

### <a name="remarks"></a>Comentários

A implementação fornecida por esta classe não faz nada.

## <a name="cnoworkerthreadgetthreadhandle"></a><a name="getthreadhandle"></a>Cnoworkerthread::GetThreadHandle

Equivalente não funcional do [CWorkerThread::GetThreadHandle](../../atl/reference/cworkerthread-class.md#getthreadhandle).

```
HANDLE GetThreadHandle() throw();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna NULL.

### <a name="remarks"></a>Comentários

A implementação fornecida por esta classe não faz nada.

## <a name="cnoworkerthreadgetthreadid"></a><a name="getthreadid"></a>CNoWorkerThread::GetThreadId

Equivalente não funcional do [CWorkerThread::GetThreadId](../../atl/reference/cworkerthread-class.md#getthreadid).

```
DWORD GetThreadId() throw();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna 0.

### <a name="remarks"></a>Comentários

A implementação fornecida por esta classe não faz nada.

## <a name="cnoworkerthreadinitialize"></a><a name="initialize"></a>CNoWorkerThread::Inicializar

Equivalente não funcional do [CWorkerThread::Initialize](../../atl/reference/cworkerthread-class.md#initialize).

```
HRESULT Initialize() throw();
```

### <a name="return-value"></a>Valor retornado

Sempre volta S_OK.

### <a name="remarks"></a>Comentários

A implementação fornecida por esta classe não faz nada.

## <a name="cnoworkerthreadremovehandle"></a><a name="removehandle"></a>CnoWorkerthread::removeHandle

Equivalente não funcional do [CWorkerThread::RemoveHandle](../../atl/reference/cworkerthread-class.md#removehandle).

```
HRESULT RemoveHandle(HANDLE /* hObject */) throw();
```

### <a name="return-value"></a>Valor retornado

Sempre volta S_OK.

### <a name="remarks"></a>Comentários

A implementação fornecida por esta classe não faz nada.

## <a name="cnoworkerthreadshutdown"></a><a name="shutdown"></a>CNoWorkerThread::Desligamento

Equivalente não funcional do [CWorkerThread::Shutdown](../../atl/reference/cworkerthread-class.md#shutdown).

```
HRESULT Shutdown(DWORD dwWait = ATL_WORKER_THREAD_WAIT) throw();
```

### <a name="return-value"></a>Valor retornado

Sempre volta S_OK.

### <a name="remarks"></a>Comentários

A implementação fornecida por esta classe não faz nada.
