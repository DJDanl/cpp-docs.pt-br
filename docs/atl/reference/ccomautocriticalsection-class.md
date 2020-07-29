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
ms.openlocfilehash: 26b43fa4adc40993a44318c67be990c781b5cdf6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226627"
---
# <a name="ccomautocriticalsection-class"></a>Classe CComAutoCriticalSection

`CComAutoCriticalSection`fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComAutoCriticalSection : public CComCriticalSection
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAutoCriticalSection::CComAutoCriticalSection](#ccomautocriticalsection)|O construtor.|
|[CComAutoCriticalSection:: ~ CComAutoCriticalSection](#dtor)|O destruidor.|

## <a name="remarks"></a>Comentários

`CComAutoCriticalSection`é semelhante à classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md), exceto que `CComAutoCriticalSection` inicializa automaticamente o objeto de seção crítica no construtor.

Normalmente, você usa `CComAutoCriticalSection` o **`typedef`** nome [AutoCriticalSection](ccommultithreadmodel-class.md#autocriticalsection). Esse nome faz referência `CComAutoCriticalSection` quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.

Os `Init` `Term` métodos e de [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) não estão disponíveis ao usar essa classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)

`CComAutoCriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore. h

## <a name="ccomautocriticalsectionccomautocriticalsection"></a><a name="ccomautocriticalsection"></a>CComAutoCriticalSection::CComAutoCriticalSection

O construtor.

```
CComAutoCriticalSection();
```

### <a name="remarks"></a>Comentários

Chama a função [InitializeCriticalSection](/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)do Win32, que inicializa o objeto da seção crítica.

## <a name="ccomautocriticalsectionccomautocriticalsection"></a><a name="dtor"></a>CComAutoCriticalSection:: ~ CComAutoCriticalSection

O destruidor.

```
~CComAutoCriticalSection() throw();
```

### <a name="remarks"></a>Comentários

O destruidor chama [DeleteCriticalSection](/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection), que libera todos os recursos do sistema usados pelo objeto da seção crítica.

## <a name="see-also"></a>Confira também

[Classe CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)
