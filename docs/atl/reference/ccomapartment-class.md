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
ms.openlocfilehash: 13141d27592f6f40ea7b0529c61baba2fe83a10a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321112"
---
# <a name="ccomapartment-class"></a>Classe CComApartment

Esta classe fornece suporte para gerenciar um apartamento em um módulo EXE com rosca.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CComApartment
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComApartment::CComApartment](#ccomapartment)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComApartment::Apartamento](#apartment)|Marca o endereço inicial do segmento.|
|[CcomApartment::GetlockCount](#getlockcount)|Retorna a contagem de bloqueio atual do segmento.|
|[CComApartment::Lock](#lock)|Incrementa a contagem de bloqueios do fio.|
|[CComApartment::Unlock](#unlock)|Decreta a contagem de travas do fio.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComApartment::m_dwThreadID](#m_dwthreadid)|Contém o identificador do segmento.|
|[CComApartment::m_hThread](#m_hthread)|Contém a alça do fio.|
|[CComApartment::m_nLockCnt](#m_nlockcnt)|Contém a contagem de bloqueio sinuosa do segmento.|

## <a name="remarks"></a>Comentários

`CComApartment`é usado pelo [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md) para gerenciar um apartamento em um módulo EXE com rosca. `CComApartment`fornece métodos para incrementar e diminuir a contagem de bloqueios em um segmento.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomapartmentapartment"></a><a name="apartment"></a>CComApartment::Apartamento

Marca o endereço inicial do segmento.

```
DWORD Apartment();
```

### <a name="return-value"></a>Valor retornado

Sempre 0.

### <a name="remarks"></a>Comentários

Ajuste automaticamente durante [CComAutoThreadModule::Init](../../atl/reference/ccomautothreadmodule-class.md#init).

## <a name="ccomapartmentccomapartment"></a><a name="ccomapartment"></a>CComApartment::CComApartment

O construtor.

```
CComApartment();
```

### <a name="remarks"></a>Comentários

Inicializa os `CComApartment` membros de dados [m_nLockCnt](#m_nlockcnt) e [m_hThread](#m_hthread).

## <a name="ccomapartmentgetlockcount"></a><a name="getlockcount"></a>CcomApartment::GetlockCount

Retorna a contagem de bloqueio atual do segmento.

```
LONG GetLockCount();
```

### <a name="return-value"></a>Valor retornado

A trava conta no fio.

## <a name="ccomapartmentlock"></a><a name="lock"></a>CComApartment::Lock

Incrementa a contagem de bloqueios do fio.

```
LONG Lock();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos ou testes.

### <a name="remarks"></a>Comentários

Chamado por [CComAutoThreadModule::Lock](../../atl/reference/ccomautothreadmodule-class.md#lock).

A contagem de bloqueios no fio é usada para fins estatísticos.

## <a name="ccomapartmentm_dwthreadid"></a><a name="m_dwthreadid"></a>CComApartment::m_dwThreadID

Contém o identificador do segmento.

```
DWORD m_dwThreadID;
```

## <a name="ccomapartmentm_hthread"></a><a name="m_hthread"></a>CComApartment::m_hThread

Contém a alça do fio.

```
HANDLE m_hThread;
```

## <a name="ccomapartmentm_nlockcnt"></a><a name="m_nlockcnt"></a>CComApartment::m_nLockCnt

Contém a contagem de bloqueio sinuosa do segmento.

```
LONG m_nLockCnt;
```

## <a name="ccomapartmentunlock"></a><a name="unlock"></a>CComApartment::Unlock

Decreta a contagem de travas do fio.

```
LONG Unlock();
```

### <a name="return-value"></a>Valor retornado

Um valor que pode ser útil para diagnósticos ou testes.

### <a name="remarks"></a>Comentários

Chamado por [CComAutoThreadModule::Unlock](../../atl/reference/ccomautothreadmodule-class.md#lock).

A contagem de bloqueios no fio é usada para fins estatísticos.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
