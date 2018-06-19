---
title: Classe de CComObjectRoot | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComObjectRoot
- atlcom/ATL::CComObjectRoot
dev_langs:
- C++
helpviewer_keywords:
- CComObjectRoot class
ms.assetid: f8797c38-6e73-4f67-85c2-71654cffa8eb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e6a7d350f7bd50476c1c327d824089981d3e8321
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32359026"
---
# <a name="ccomobjectroot-class"></a>Classe de CComObjectRoot
Este typedef de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) é transformado em modelo no modelo do servidor de threading padrão.  
  
## <a name="syntax"></a>Sintaxe  
  
```
typedef CComObjectRootEx<CComObjectThreadModel> CComObjectRoot;
```  
  
## <a name="remarks"></a>Comentários  
 `CComObjectRoot` é um `typedef` de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) transformado em modelo no modelo do servidor de threading padrão. Portanto, [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) fará referência a um [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md).  
  
 `CComObjectRootEx` lida com gerenciamento de contagem de referência de objeto para objetos agregados e agregados. Ela contém a contagem de referência de objeto se o objeto não está sendo agregado e mantém o ponteiro para o externo desconhecido se o objeto está sendo agregado. Objetos agregados, `CComObjectRootEx` métodos podem ser usados para lidar com falhas do objeto interno para construir e proteger o objeto externo da exclusão quando forem lançadas interfaces internas ou o objeto interno é excluído.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
## <a name="see-also"></a>Consulte também  
 [Membros de classe CComObjectRootEx](http://msdn.microsoft.com/en-us/e3ce9c3d-9c8e-4fe5-b682-8e56740a0164)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe CComObject](../../atl/reference/ccomobject-class.md)   
 [Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
