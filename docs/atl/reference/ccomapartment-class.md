---
title: Classe CComApartment
ms.date: 11/04/2016
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
helpviewer_keywords:
- apartments in ATL EXE modules
- CComApartment class
ms.assetid: dbc177d7-7ee4-45f2-b563-d578a467ca93
ms.openlocfilehash: 5f4c7fc356e61210e9b99bf9989b1bb3f0abc98a
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821669"
---
# <a name="ccomapartment-class"></a>Classe CComApartment

Essa classe fornece suporte para gerenciar um apartamento em um módulo EXE de pool de threads.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CComApartment
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Name|Descrição|
|----------|-----------------|
|[CComApartment::CComApartment](#ccomapartment)|O construtor.|

### <a name="public-methods"></a>Métodos Públicos

|Name|Descrição|
|----------|-----------------|
|[CComApartment:: Apartment](#apartment)|Marca o endereço inicial do thread.|
|[CComApartment::GetLockCount](#getlockcount)|Retorna a contagem de bloqueios atual do thread.|
|[CComApartment::Lock](#lock)|Incrementa a contagem de bloqueios do thread.|
|[CComApartment::Unlock](#unlock)|Decrementa a contagem de bloqueios do thread.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Name|Descrição|
|----------|-----------------|
|[CComApartment::m_dwThreadID](#m_dwthreadid)|Contém o identificador do thread.|
|[CComApartment::m_hThread](#m_hthread)|Contém o identificador do thread.|
|[CComApartment::m_nLockCnt](#m_nlockcnt)|Contém a contagem de bloqueios atual do thread.|

## <a name="remarks"></a>Comentários

`CComApartment` é usado pelo [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) para gerenciar um apartamento em um módulo exe de pool de threads. `CComApartment` fornece métodos para incrementar e decrementar a contagem de bloqueios em um thread.

## <a name="requirements"></a>Requisitos do

**Cabeçalho:** atlbase. h

##  <a name="apartment"></a>CComApartment:: Apartment

Marca o endereço inicial do thread.

```
DWORD Apartment();
```

### <a name="return-value"></a>Valor de retorno

Sempre 0.

### <a name="remarks"></a>Comentários

Definido automaticamente durante [CComAutoThreadModule:: init](../../atl/reference/ccomautothreadmodule-class.md#init).

##  <a name="ccomapartment"></a>CComApartment::CComApartment

O construtor.

```
CComApartment();
```

### <a name="remarks"></a>Comentários

Inicializa os membros de dados do `CComApartment` [m_nLockCnt](#m_nlockcnt) e [m_hThread](#m_hthread).

##  <a name="getlockcount"></a>  CComApartment::GetLockCount

Retorna a contagem de bloqueios atual do thread.

```
LONG GetLockCount();
```

### <a name="return-value"></a>Valor de retorno

A contagem de bloqueios no thread.

##  <a name="lock"></a>CComApartment:: Lock

Incrementa a contagem de bloqueios do thread.

```
LONG Lock();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

### <a name="remarks"></a>Comentários

Chamado por [CComAutoThreadModule:: Lock](../../atl/reference/ccomautothreadmodule-class.md#lock).

A contagem de bloqueios no thread é usada para fins estatísticos.

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

Contém a contagem de bloqueios atual do thread.

```
LONG m_nLockCnt;
```

##  <a name="unlock"></a>CComApartment:: desbloquear

Decrementa a contagem de bloqueios do thread.

```
LONG Unlock();
```

### <a name="return-value"></a>Valor de retorno

Um valor que pode ser útil para diagnóstico ou teste.

### <a name="remarks"></a>Comentários

Chamado por [CComAutoThreadModule:: Unlock](../../atl/reference/ccomautothreadmodule-class.md#lock).

A contagem de bloqueios no thread é usada para fins estatísticos.

## <a name="see-also"></a>Veja também

[Visão geral da classe](../../atl/atl-class-overview.md)
