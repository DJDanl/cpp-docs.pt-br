---
title: Classe CComObjectRoot
ms.date: 11/04/2016
f1_keywords:
- CComObjectRoot
- atlcom/ATL::CComObjectRoot
helpviewer_keywords:
- CComObjectRoot class
ms.assetid: f8797c38-6e73-4f67-85c2-71654cffa8eb
ms.openlocfilehash: 98868e67fd14899a75f86837034ba540d22039e3
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224234"
---
# <a name="ccomobjectroot-class"></a>Classe CComObjectRoot

Este typedef de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) é modelos no modelo de Threading padrão do servidor.

## <a name="syntax"></a>Sintaxe

```
typedef CComObjectRootEx<CComObjectThreadModel> CComObjectRoot;
```

## <a name="remarks"></a>Comentários

`CComObjectRoot`é um **`typedef`** de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) modelos no modelo de Threading padrão do servidor. Portanto, [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) fará referência a [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md).

`CComObjectRootEx`manipula o gerenciamento de contagem de referência de objeto para objetos não agregados e agregados. Ela conterá a contagem de referências de objetos se o objeto não estiver sendo agregado e manterá o ponteiro para o desconhecido externo se o objeto estiver sendo agregado. Para objetos agregados, `CComObjectRootEx` os métodos podem ser usados para lidar com a falha do objeto interno a ser construído e para proteger o objeto externo da exclusão quando interfaces internas são liberadas ou o objeto interno é excluído.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom. h

## <a name="see-also"></a>Confira também

[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
