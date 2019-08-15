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
ms.openlocfilehash: 116c550f45bf622e7620b3a6f552339b4bcc24a7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497924"
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

`CComAutoCriticalSection`é semelhante à classe [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md), exceto `CComAutoCriticalSection` que inicializa automaticamente o objeto de seção crítica no construtor.

Normalmente, você usa `CComAutoCriticalSection` o `typedef` nome [AutoCriticalSection](ccommultithreadmodel-class.md#autocriticalsection). Esse nome faz `CComAutoCriticalSection` referência quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) está sendo usado.

Os `Init` métodos `Term` e de [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) não estão disponíveis ao usar essa classe.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)

`CComAutoCriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore. h

##  <a name="ccomautocriticalsection"></a>  CComAutoCriticalSection::CComAutoCriticalSection

O construtor.

```
CComAutoCriticalSection();
```

### <a name="remarks"></a>Comentários

Chama a função [InitializeCriticalSection](/windows/win32/api/synchapi/nf-synchapi-initializecriticalsection)do Win32, que inicializa o objeto da seção crítica.

##  <a name="dtor"></a>CComAutoCriticalSection:: ~ CComAutoCriticalSection

O destruidor.

```
~CComAutoCriticalSection() throw();
```

### <a name="remarks"></a>Comentários

O destruidor chama [DeleteCriticalSection](/windows/win32/api/synchapi/nf-synchapi-deletecriticalsection), que libera todos os recursos do sistema usados pelo objeto da seção crítica.

## <a name="see-also"></a>Consulte também

[Classe CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)
