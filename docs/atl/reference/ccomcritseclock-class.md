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
ms.openlocfilehash: fd2904f67d84db42d6b35aa4e505b063d6ea9a9f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224286"
---
# <a name="ccomcritseclock-class"></a>Classe CComCritSecLock

Essa classe fornece métodos para bloquear e desbloquear um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
template<class TLock> class CComCritSecLock
```

#### <a name="parameters"></a>parâmetros

*TLock*<br/>
O objeto a ser bloqueado e desbloqueado.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCritSecLock::CComCritSecLock](#ctor)|O construtor.|
|[CComCritSecLock:: ~ CComCritSecLock](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCritSecLock:: Lock](#lock)|Chame esse método para bloquear o objeto da seção crítica.|
|[CComCritSecLock:: desbloquear](#unlock)|Chame esse método para desbloquear o objeto de seção crítica.|

## <a name="remarks"></a>Comentários

Use essa classe para bloquear e desbloquear objetos de maneira mais segura do que com a classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) ou [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

## <a name="ccomcritseclockccomcritseclock"></a><a name="ctor"></a>CComCritSecLock::CComCritSecLock

O construtor.

```
CComCritSecLock(TLock& cs, bool bInitialLock = true);
```

### <a name="parameters"></a>parâmetros

*CS*<br/>
O objeto da seção crítica.

*bInitialLock*<br/>
O estado de bloqueio inicial: **`true`** significa bloqueado.

### <a name="remarks"></a>Comentários

Inicializa o objeto da seção crítica.

## <a name="ccomcritseclockccomcritseclock"></a><a name="dtor"></a>CComCritSecLock:: ~ CComCritSecLock

O destruidor.

```
~CComCritSecLock() throw();
```

### <a name="remarks"></a>Comentários

Desbloqueia o objeto da seção crítica.

## <a name="ccomcritseclocklock"></a><a name="lock"></a>CComCritSecLock:: Lock

Chame esse método para bloquear o objeto da seção crítica.

```
HRESULT Lock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK se o objeto foi bloqueado com êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Se o objeto já estiver bloqueado, ocorrerá um erro de ASSERÇÃO nas compilações de depuração.

## <a name="ccomcritseclockunlock"></a><a name="unlock"></a>CComCritSecLock:: desbloquear

Chame esse método para desbloquear o objeto de seção crítica.

```cpp
void Unlock() throw();
```

### <a name="remarks"></a>Comentários

Se o objeto já estiver desbloqueado, ocorrerá um erro de ASSERÇÃO nas compilações de depuração.

## <a name="see-also"></a>Confira também

[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)<br/>
[Classe CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)
