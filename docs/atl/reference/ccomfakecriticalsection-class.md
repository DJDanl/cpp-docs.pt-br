---
title: Classe CComFakeCriticalSection | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComFakeCriticalSection
- ATLCORE/ATL::CComFakeCriticalSection
- ATLCORE/ATL::CComFakeCriticalSection::Init
- ATLCORE/ATL::CComFakeCriticalSection::Lock
- ATLCORE/ATL::CComFakeCriticalSection::Term
- ATLCORE/ATL::CComFakeCriticalSection::Unlock
dev_langs:
- C++
helpviewer_keywords:
- CComFakeCriticalSection class
ms.assetid: a4811b97-96bb-493b-ab9f-62822aeddb10
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 48b120b7be3e605b6ed2619cbd71011b0a693bdc
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43757270"
---
# <a name="ccomfakecriticalsection-class"></a>Classe CComFakeCriticalSection

Essa classe fornece os mesmos métodos como [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) , mas não oferece uma seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComFakeCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComFakeCriticalSection::Init](#init)|Não faz nada, pois há uma seção crítica.|
|[CComFakeCriticalSection::Lock](#lock)|Não faz nada, pois há uma seção crítica.|
|[CComFakeCriticalSection::Term](#term)|Não faz nada, pois há uma seção crítica.|
|[CComFakeCriticalSection::Unlock](#unlock)|Não faz nada, pois há uma seção crítica.|

## <a name="remarks"></a>Comentários

`CComFakeCriticalSection` espelha os métodos encontrados em [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md). No entanto, `CComFakeCriticalSection` não oferece uma seção crítica; portanto, seus métodos não fazem nada.

Normalmente, você usa `CComFakeCriticalSection` por meio de um `typedef` nomear, tanto `AutoCriticalSection` ou `CriticalSection`. Ao usar [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModelNoCS](../../atl/reference/ccommultithreadmodelnocs-class.md), ambos `typedef` nomes referenciam `CComFakeCriticalSection`. Ao usar [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md), eles fazem referência a [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md) e `CComCriticalSection`, respectivamente.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

##  <a name="init"></a>  CComFakeCriticalSection::Init

Não faz nada, pois há uma seção crítica.

```
HRESULT Init() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="lock"></a>  CComFakeCriticalSection::Lock

Não faz nada, pois há uma seção crítica.

```
HRESULT Lock() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="term"></a>  CComFakeCriticalSection::Term

Não faz nada, pois há uma seção crítica.

```
HRESULT Term() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

##  <a name="unlock"></a>  CComFakeCriticalSection::Unlock

Não faz nada, pois há uma seção crítica.

```
HRESULT Unlock() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna S_OK.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
