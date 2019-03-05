---
title: Classe CComCritSecLock
ms.date: 11/04/2016
f1_keywords:
- CComCritSecLock
- ATLBASE/ATL::CComCritSecLock
- ATLBASE/ATL::CComCritSecLock::CComCritSecLock
- ATLBASE/ATL::CComCritSecLock::Lock
- ATLBASE/ATL::CComCritSecLock::Unlock
helpviewer_keywords:
- CComCritSecLock class
ms.assetid: 223152a1-86c3-4ef9-89a7-f455fe791b0e
ms.openlocfilehash: 045e64504707fa8978c8236b376037d9f57bf12c
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57261226"
---
# <a name="ccomcritseclock-class"></a>Classe CComCritSecLock

Essa classe fornece métodos para bloquear e desbloquear um objeto da seção crítica.

## <a name="syntax"></a>Sintaxe

```
template<class TLock> class CComCritSecLock
```

#### <a name="parameters"></a>Parâmetros

*TLock*<br/>
O objeto a ser bloqueado e desbloqueado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCritSecLock::CComCritSecLock](#ctor)|O construtor.|
|[CComCritSecLock::~CComCritSecLock](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCritSecLock::Lock](#lock)|Chame esse método para bloquear o objeto de seção crítica.|
|[CComCritSecLock::Unlock](#unlock)|Chame esse método para desbloquear o objeto de seção crítica.|

## <a name="remarks"></a>Comentários

Use esta classe para bloquear e desbloquear os objetos de uma maneira mais segura do que com o [classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) ou [classe CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="ctor"></a>  CComCritSecLock::CComCritSecLock

O construtor.

```
CComCritSecLock(TLock& cs, bool bInitialLock = true);
```

### <a name="parameters"></a>Parâmetros

*cs*<br/>
O objeto de seção crítica.

*bInitialLock*<br/>
O estado de bloqueio inicial: **verdadeira** significa bloqueada.

### <a name="remarks"></a>Comentários

Inicializa o objeto de seção crítica.

##  <a name="dtor"></a>  CComCritSecLock::~CComCritSecLock

O destruidor.

```
~CComCritSecLock() throw();
```

### <a name="remarks"></a>Comentários

Desbloqueia o objeto de seção crítica.

##  <a name="lock"></a>  CComCritSecLock::Lock

Chame esse método para bloquear o objeto de seção crítica.

```
HRESULT Lock() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK se o objeto foi bloqueado com êxito, ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Se o objeto já está bloqueado, ocorrerá um erro de ASSERÇÃO em compilações de depuração.

##  <a name="unlock"></a>  CComCritSecLock::Unlock

Chame esse método para desbloquear o objeto de seção crítica.

```
void Unlock() throw();
```

### <a name="remarks"></a>Comentários

Se o objeto já está desbloqueado, ocorrerá um erro de ASSERÇÃO em compilações de depuração.

## <a name="see-also"></a>Consulte também

[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)<br/>
[Classe CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)
