---
title: "Classe de CComObjectRoot | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "CComObjectRoot"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComObjectRoot"
ms.assetid: f8797c38-6e73-4f67-85c2-71654cffa8eb
caps.latest.revision: 17
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComObjectRoot
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este typedef de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) templatized no modelo de threads padrão do servidor.  
  
## Sintaxe  
  
```  
  
typedef CComObjectRootEx<CComObjectThreadModel> CComObjectRoot;  
  
```  
  
## Comentários  
 `CComObjectRoot` é `typedef` de [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md) templatized no modelo de threads padrão do servidor.  Isso fará referência [CComObjectThreadModel](../Topic/CComObjectThreadModel.md)[CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md) ou [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md).  
  
 As alças de`CComObjectRootEx` manipula o gerenciamento de contagem de referência para objetos nonaggregated e agregados.  Ele contém a contagem de referência de objeto se o objeto não está sendo agregado, e mantém o ponteiro ao desconhecido externo se o objeto está sendo agregado.  Para objetos agregados, os métodos de `CComObjectRootEx` podem ser usados para manipular a falha do objeto interno para a compilação, e para proteger o objeto externo de exclusão quando as interfaces são liberadas internas ou o objeto interno é excluído.  
  
## Requisitos  
 **Cabeçalho:** atlcom.h  
  
## Consulte também  
 [CComObjectRootEx Class Members](http://msdn.microsoft.com/pt-br/e3ce9c3d-9c8e-4fe5-b682-8e56740a0164)   
 [Classe de CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md)   
 [Classe de CComAggObject](../../atl/reference/ccomaggobject-class.md)   
 [Classe de CComObject](../../atl/reference/ccomobject-class.md)   
 [Classe de CComPolyObject](../../atl/reference/ccompolyobject-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)