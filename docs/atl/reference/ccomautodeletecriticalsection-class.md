---
title: Classe CComAutoDeleteCriticalSection
ms.date: 11/04/2016
f1_keywords:
- CComAutoDeleteCriticalSection
- atlcore/ATL::CComAutoDeleteCriticalSection
helpviewer_keywords:
- CComAutoDeleteCriticalSection class
ms.assetid: 2396dbea-1c60-4841-b50e-c4e18af311a3
ms.openlocfilehash: d479adce489e0329be3a93b55a70aa3e58a0e038
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62246651"
---
# <a name="ccomautodeletecriticalsection-class"></a>Classe CComAutoDeleteCriticalSection

Essa classe fornece métodos para obter e liberar a propriedade de um objeto de seção crítica.

## <a name="syntax"></a>Sintaxe

```
class CComAutoDeleteCriticalSection : public CComSafeDeleteCriticalSection
```

## <a name="remarks"></a>Comentários

`CComAutoDeleteCriticalSection` deriva da classe [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md). No entanto, `CComAutoDeleteCriticalSection` substitui o [termo](ccomsafedeletecriticalsection-class.md#term) método **privada** acesso, o que força a limpeza de memória interna para ocorrer somente quando as instâncias dessa classe saem do escopo ou explicitamente são excluídas do memória.

Essa classe apresenta não há métodos adicionais ao longo de sua classe base. Ver [CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md) e [CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md) para obter mais informações sobre classes de auxiliar de seção crítica.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)

[CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md)

`CComAutoDeleteCriticalSection`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="see-also"></a>Consulte também

[Classe CComSafeDeleteCriticalSection](../../atl/reference/ccomsafedeletecriticalsection-class.md)<br/>
[Classe CComCriticalSection](../../atl/reference/ccomcriticalsection-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
