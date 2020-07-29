---
title: Classe CComFakeCriticalSection
ms.date: 11/04/2016
f1_keywords:
- CComFakeCriticalSection
- ATLCORE/ATL::CComFakeCriticalSection
- ATLCORE/ATL::CComFakeCriticalSection::Init
- ATLCORE/ATL::CComFakeCriticalSection::Lock
- ATLCORE/ATL::CComFakeCriticalSection::Term
- ATLCORE/ATL::CComFakeCriticalSection::Unlock
helpviewer_keywords:
- CComFakeCriticalSection class
ms.assetid: a4811b97-96bb-493b-ab9f-62822aeddb10
ms.openlocfilehash: 5ada0fbed705af34391709653dbd3638fed32bf7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226575"
---
# <a name="ccomfakecriticalsection-class"></a>Classe CComFakeCriticalSection

Essa classe fornece os mesmos métodos que [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) , mas não fornece uma seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComFakeCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComFakeCriticalSection:: init](#init)|Não faz nada desde que não haja nenhuma seção crítica.|
|[CComFakeCriticalSection:: Lock](#lock)|Não faz nada desde que não haja nenhuma seção crítica.|
|[CComFakeCriticalSection:: termo](#term)|Não faz nada desde que não haja nenhuma seção crítica.|
|[CComFakeCriticalSection:: desbloquear](#unlock)|Não faz nada desde que não haja nenhuma seção crítica.|

## <a name="remarks"></a>Comentários

`CComFakeCriticalSection`espelha os métodos encontrados em [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No entanto, o não `CComFakeCriticalSection` fornece uma seção crítica; portanto, seus métodos não fazem nada.

Normalmente, você usa `CComFakeCriticalSection` o por meio de um **`typedef`** nome, `AutoCriticalSection` ou `CriticalSection` . Ao usar [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md), ambos os **`typedef`** nomes fazem referência `CComFakeCriticalSection` . Ao usar [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md), eles fazem referência a [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md) e `CComCriticalSection` , respectivamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore. h

## <a name="ccomfakecriticalsectioninit"></a><a name="init"></a>CComFakeCriticalSection:: init

Não faz nada desde que não haja nenhuma seção crítica.

```
HRESULT Init() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ccomfakecriticalsectionlock"></a><a name="lock"></a>CComFakeCriticalSection:: Lock

Não faz nada desde que não haja nenhuma seção crítica.

```
HRESULT Lock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ccomfakecriticalsectionterm"></a><a name="term"></a>CComFakeCriticalSection:: termo

Não faz nada desde que não haja nenhuma seção crítica.

```
HRESULT Term() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ccomfakecriticalsectionunlock"></a><a name="unlock"></a>CComFakeCriticalSection:: desbloquear

Não faz nada desde que não haja nenhuma seção crítica.

```
HRESULT Unlock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
