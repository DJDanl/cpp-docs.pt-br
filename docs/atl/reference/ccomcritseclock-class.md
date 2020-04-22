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
ms.openlocfilehash: 4b2ef093c1142b592ad2a6605a08bd8c34a643ea
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748077"
---
# <a name="ccomcritseclock-class"></a>Classe CComCritSecLock

Esta classe fornece métodos para bloquear e desbloquear um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
template<class TLock> class CComCritSecLock
```

#### <a name="parameters"></a>Parâmetros

*Rio TLock*<br/>
O objeto a ser bloqueado e desbloqueado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCritSecLock::CComCritSecLock](#ctor)|O construtor.|
|[CComCritSecLock::~CComCritSecLock](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCritSecLock::Bloqueio](#lock)|Chame este método para bloquear o objeto da seção crítica.|
|[CComCritSecLock::Unlock](#unlock)|Chame este método para desbloquear o objeto da seção crítica.|

## <a name="remarks"></a>Comentários

Use esta classe para bloquear e desbloquear objetos de forma mais segura do que com a [Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) ou [CComAutoCriticalSection Class](../../atl/reference/ccomautocriticalsection-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomcritseclockccomcritseclock"></a><a name="ctor"></a>CComCritSecLock::CComCritSecLock

O construtor.

```
CComCritSecLock(TLock& cs, bool bInitialLock = true);
```

### <a name="parameters"></a>Parâmetros

*Cs*<br/>
O objeto da seção crítica.

*bInitialLock*<br/>
O estado inicial de bloqueio: **verdadeiro** significa bloqueado.

### <a name="remarks"></a>Comentários

Inicializa o objeto da seção crítica.

## <a name="ccomcritseclockccomcritseclock"></a><a name="dtor"></a>CComCritSecLock::~CComCritSecLock

O destruidor.

```
~CComCritSecLock() throw();
```

### <a name="remarks"></a>Comentários

Desbloqueia o objeto da seção crítica.

## <a name="ccomcritseclocklock"></a><a name="lock"></a>CComCritSecLock::Bloqueio

Chame este método para bloquear o objeto da seção crítica.

```
HRESULT Lock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK se o objeto tiver sido bloqueado com sucesso ou um erro HRESULT na falha.

### <a name="remarks"></a>Comentários

Se o objeto já estiver bloqueado, um erro ASSERT ocorrerá em compilações de depuração.

## <a name="ccomcritseclockunlock"></a><a name="unlock"></a>CComCritSecLock::Unlock

Chame este método para desbloquear o objeto da seção crítica.

```cpp
void Unlock() throw();
```

### <a name="remarks"></a>Comentários

Se o objeto já estiver desbloqueado, um erro ASSERT ocorrerá em compilações de depuração.

## <a name="see-also"></a>Confira também

[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)<br/>
[Classe CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)
