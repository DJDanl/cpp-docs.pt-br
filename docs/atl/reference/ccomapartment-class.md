---
title: Classe CComApartment | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComApartment
- ATLBASE/ATL::CComApartment
- ATLBASE/ATL::CComApartment::CComApartment
- ATLBASE/ATL::CComApartment::Apartment
- ATLBASE/ATL::CComApartment::GetLockCount
- ATLBASE/ATL::CComApartment::Lock
- ATLBASE/ATL::CComApartment::Unlock
- ATLBASE/ATL::CComApartment::m_dwThreadID
- ATLBASE/ATL::CComApartment::m_hThread
- ATLBASE/ATL::CComApartment::m_nLockCnt
dev_langs:
- C++
helpviewer_keywords:
- apartments in ATL EXE modules
- CComApartment class
ms.assetid: dbc177d7-7ee4-45f2-b563-d578a467ca93
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 39750bcb6b8852e692e52f163e83bb815ecebe97
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43755431"
---
# <a name="ccomapartment-class"></a>Classe CComApartment

Essa classe fornece suporte para gerenciar um apartamento em um módulo EXE em pool de thread.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CComApartment
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComApartment::CComApartment](#ccomapartment)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComApartment::Apartment](#apartment)|Marca o endereço inicial do thread.|
|[CComApartment::GetLockCount](#getlockcount)|Retorna a contagem de bloqueio do thread atual.|
|[CComApartment::Lock](#lock)|Incrementa a contagem de bloqueio do thread.|
|[CComApartment::Unlock](#unlock)|Diminui contagem de bloqueio do thread.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComApartment::m_dwThreadID](#m_dwthreadid)|Contém o identificador do thread.|
|[CComApartment::m_hThread](#m_hthread)|Contém o identificador do thread.|
|[CComApartment::m_nLockCnt](#m_nlockcnt)|Contém a contagem de bloqueio do thread atual.|

## <a name="remarks"></a>Comentários

`CComApartment` é usado pelo [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) para gerenciar um apartamento em um módulo EXE em pool de thread. `CComApartment` fornece métodos para incrementar e diminuir o bloqueio de contam com um thread.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="apartment"></a>  CComApartment::Apartment

Marca o endereço inicial do thread.

```
DWORD Apartment();
```

### <a name="return-value"></a>Valor de retorno

Sempre 0.

### <a name="remarks"></a>Comentários

Definir automaticamente durante [CComAutoThreadModule::Init](../../atl/reference/ccomautothreadmodule-class.md#init).

##  <a name="ccomapartment"></a>  CComApartment::CComApartment

O construtor.

```
CComApartment();
```

### <a name="remarks"></a>Comentários

Inicializa o `CComApartment` membros de dados [m_nLockCnt](#m_nlockcnt) e [m_hThread](#m_hthread).

##  <a name="getlockcount"></a>  CComApartment::GetLockCount

Retorna a contagem de bloqueio do thread atual.

```
LONG GetLockCount();
```

### <a name="return-value"></a>Valor de retorno

A contagem de bloqueio no thread.

##  <a name="lock"></a>  CComApartment::Lock

Incrementa a contagem de bloqueio do thread.

```
LONG Lock();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

### <a name="remarks"></a>Comentários

Chamado pelo [CComAutoThreadModule::Lock](../../atl/reference/ccomautothreadmodule-class.md#lock).

A contagem de bloqueio no thread é usada para fins estatísticos.

##  <a name="m_dwthreadid"></a>  CComApartment::m_dwThreadID

Contém o identificador do thread.

```
DWORD m_dwThreadID;
```

##  <a name="m_hthread"></a>  CComApartment::m_hThread

Contém o identificador do thread.

```
HANDLE m_hThread;
```

##  <a name="m_nlockcnt"></a>  CComApartment::m_nLockCnt

Contém a contagem de bloqueio do thread atual.

```
LONG m_nLockCnt;
```

##  <a name="unlock"></a>  CComApartment::Unlock

Diminui contagem de bloqueio do thread.

```
LONG Unlock();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

### <a name="remarks"></a>Comentários

Chamado pelo [CComAutoThreadModule::Unlock](../../atl/reference/ccomautothreadmodule-class.md#lock).

A contagem de bloqueio no thread é usada para fins estatísticos.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
