---
title: Classe CComObjectRoot | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComObjectRoot
- atlcom/ATL::CComObjectRoot
dev_langs:
- C++
helpviewer_keywords:
- CComObjectRoot class
ms.assetid: f8797c38-6e73-4f67-85c2-71654cffa8eb
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 31295a07704e272799398aa82c6a9f0bbac17717
ms.openlocfilehash: 34653d55091a8e872f075010a0ef7cecbb3484c8
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ccomobjectroot-class"></a>Classe CComObjectRoot
Este typedef de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) é modelada no padrão, o modelo do servidor de threading.  
  
## <a name="syntax"></a>Sintaxe  
  
```
typedef CComObjectRootEx<CComObjectThreadModel> CComObjectRoot;
```  
  
## <a name="remarks"></a>Comentários  
 `CComObjectRoot`é um `typedef` de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) modelada no padrão de threading de modelo do servidor. Portanto, [CComObjectThreadModel](atl-typedefs.md#ccomobjectthreadmodel) fará referência a um [CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md).  
  
 `CComObjectRootEx`lida com gerenciamento de contagem de referência de objeto para objetos agregados e agregados. Ele contém a contagem de referência de objeto se o objeto não está sendo agregado e mantém o ponteiro para o externo desconhecido se o objeto está sendo agregado. Objetos agregados, `CComObjectRootEx` métodos podem ser usados para lidar com falhas do objeto interno para construir e proteger o objeto externo da exclusão quando forem lançadas interfaces internas ou o objeto interno é excluído.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
## <a name="see-also"></a>Consulte também  
 [Membros de classe CComObjectRootEx](http://msdn.microsoft.com/en-us/e3ce9c3d-9c8e-4fe5-b682-8e56740a0164)   
 [Classe CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [Classe CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe CComObject](../../atl/reference/ccomobject-class.md)   
 [Classe CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

