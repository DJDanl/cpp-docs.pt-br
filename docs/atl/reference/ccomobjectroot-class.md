---
title: Classe CComObjectRoot
ms.date: 11/04/2016
f1_keywords:
- CComObjectRoot
- atlcom/ATL::CComObjectRoot
helpviewer_keywords:
- CComObjectRoot class
ms.assetid: f8797c38-6e73-4f67-85c2-71654cffa8eb
ms.openlocfilehash: 4761aa9ae9c8ffacfb393311d7e058b1450b4628
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50554957"
---
# <a name="ccomobjectroot-class"></a>Classe CComObjectRoot

Este typedef de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) é modelada no modelo do servidor de threading padrão.

## <a name="syntax"></a>Sintaxe

```
typedef CComObjectRootEx<CComObjectThreadModel> CComObjectRoot;
```

## <a name="remarks"></a>Comentários

`CComObjectRoot` é um `typedef` dos [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) modelada no modelo do servidor de threading padrão. Assim [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) fará referência a [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md).

`CComObjectRootEx` lida com gerenciamento de contagem de referência de objeto para objetos não agregados e agregados. Ele armazena a contagem de referência de objeto, se seu objeto não está sendo agregado e mantém o ponteiro para o externo desconhecido se o objeto está sendo agregado. Para objetos agregados, `CComObjectRootEx` métodos podem ser usados para tratar a falha do objeto interno para construir e proteger o objeto externo quando as interfaces internas são liberadas após a exclusão ou o objeto interno é excluído.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcom

## <a name="see-also"></a>Consulte também

[Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)<br/>
[Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)<br/>
[Classe CComObject](../../atl/reference/ccomobject-class.md)<br/>
[Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
