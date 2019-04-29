---
title: Classe CComObjectRoot
ms.date: 11/04/2016
f1_keywords:
- CComObjectRoot
- atlcom/ATL::CComObjectRoot
helpviewer_keywords:
- CComObjectRoot class
ms.assetid: f8797c38-6e73-4f67-85c2-71654cffa8eb
ms.openlocfilehash: 9a9ffa1813fb15297d209894050b6bcce6802df2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62259359"
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
