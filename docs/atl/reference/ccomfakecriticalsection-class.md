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
ms.openlocfilehash: 4a5b9ba3551397a9c3d59a343e9c6b55b1c1207e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327847"
---
# <a name="ccomfakecriticalsection-class"></a>Classe CComFakeCriticalSection

Esta classe fornece os mesmos métodos que [CComCriticalSection,](../../atl/reference/ccomcriticalsection-class.md) mas não fornece uma seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComFakeCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComFakeCriticalSection::Init](#init)|Não faz nada, já que não há uma seção crítica.|
|[CComFakeCriticalSection::bloqueio](#lock)|Não faz nada, já que não há uma seção crítica.|
|[CComFakeCriticalSection::Termo](#term)|Não faz nada, já que não há uma seção crítica.|
|[CComFakeCriticalSection::Unlock](#unlock)|Não faz nada, já que não há uma seção crítica.|

## <a name="remarks"></a>Comentários

`CComFakeCriticalSection`espelha os métodos encontrados no [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No `CComFakeCriticalSection` entanto, não fornece uma seção crítica; portanto, seus métodos não fazem nada.

Normalmente, você `CComFakeCriticalSection` usa `typedef` através `AutoCriticalSection` de `CriticalSection`um nome, ou . Ao usar [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModelNoCS,](../../atl/reference/ccommultithreadmodelnocs-class.md)ambos os `typedef` nomes fazem referência `CComFakeCriticalSection`. Ao usar [ccomMultiThreadModel,](../../atl/reference/ccommultithreadmodel-class.md)eles referenciam `CComCriticalSection` [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md) e , respectivamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="ccomfakecriticalsectioninit"></a><a name="init"></a>CComFakeCriticalSection::Init

Não faz nada, já que não há uma seção crítica.

```
HRESULT Init() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ccomfakecriticalsectionlock"></a><a name="lock"></a>CComFakeCriticalSection::bloqueio

Não faz nada, já que não há uma seção crítica.

```
HRESULT Lock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ccomfakecriticalsectionterm"></a><a name="term"></a>CComFakeCriticalSection::Termo

Não faz nada, já que não há uma seção crítica.

```
HRESULT Term() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="ccomfakecriticalsectionunlock"></a><a name="unlock"></a>CComFakeCriticalSection::Unlock

Não faz nada, já que não há uma seção crítica.

```
HRESULT Unlock() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
