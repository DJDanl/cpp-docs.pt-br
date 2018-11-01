---
title: Classe CComAutoCriticalSection
ms.date: 11/04/2016
f1_keywords:
- CComAutoCriticalSection
- ATLCORE/ATL::CComAutoCriticalSection
- ATLCORE/ATL::CComAutoCriticalSection::CComAutoCriticalSection
helpviewer_keywords:
- CComAutoCriticalSection class
ms.assetid: 491a9d90-3398-4f90-88f5-fd2172a46b30
ms.openlocfilehash: 1da9aeb0ff285893ed4f81277f379ad8bffcc65b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50590899"
---
# <a name="ccomautocriticalsection-class"></a>Classe CComAutoCriticalSection

`CComAutoCriticalSection` fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComAutoCriticalSection : public CComCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAutoCriticalSection::CComAutoCriticalSection](#ccomautocriticalsection)|O construtor.|
|[CComAutoCriticalSection:: ~ CComAutoCriticalSection](#dtor)|O destruidor.|

## <a name="remarks"></a>Comentários

`CComAutoCriticalSection` é semelhante à classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md), exceto `CComAutoCriticalSection` automaticamente inicializa o objeto de seção crítica no construtor.

Normalmente, você usa `CComAutoCriticalSection` por meio de `typedef` nome [AutoCriticalSection](ccommultithreadmodel-class.md#autocriticalsection). Esse nome faz referência a `CComAutoCriticalSection` quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.

O `Init` e `Term` métodos do [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) não estão disponíveis ao usar essa classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)

`CComAutoCriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

##  <a name="ccomautocriticalsection"></a>  CComAutoCriticalSection::CComAutoCriticalSection

O construtor.

```
CComAutoCriticalSection();
```

### <a name="remarks"></a>Comentários

Chama a função Win32 [InitializeCriticalSection](/windows/desktop/api/synchapi/nf-synchapi-initializecriticalsection), que inicializa o objeto de seção crítica.

##  <a name="dtor"></a>  CComAutoCriticalSection:: ~ CComAutoCriticalSection

O destruidor.

```
~CComAutoCriticalSection() throw();
```

### <a name="remarks"></a>Comentários

As chamadas de destruidor [DeleteCriticalSection](/windows/desktop/api/synchapi/nf-synchapi-deletecriticalsection), que libera todos os recursos do sistema usados pelo objeto de seção crítica.

## <a name="see-also"></a>Consulte também

[Classe CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)
