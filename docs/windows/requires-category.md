---
title: "requires_category | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "vc-attr.requires_category"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "requires_category attribute"
ms.assetid: a645fdc6-1ef5-414d-8c56-5fe2686d4687
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# requires_category
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica as categorias de componente necessário da classe destino.  
  
## Sintaxe  
  
```  
  
     [ requires_category(   
  requires_category  
) ]  
```  
  
#### Parâmetros  
 *requires\_category*  
 A identificação da categoria necessária.  
  
## Comentários  
 O  **requires\_category** atributo C\+\+ Especifica as categorias de componentes necessárias para a classe de destino.  Para obter mais informações, consulte  [REQUIRED\_CATEGORY](../Topic/REQUIRED_CATEGORY.md).  
  
 Este atributo requer que o  [coclass](../windows/coclass.md),  [progid](../Topic/progid.md), ou  [vi\_progid](../windows/vi-progid.md) atributo \(ou outro atributo implica um deles\) também ser aplicadas ao mesmo elemento.  
  
## Exemplo  
 O código a seguir requer que o objeto implementa a categoria de controle.  
  
```  
// cpp_attr_ref_requires_category.cpp  
// compile with: /LD  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
#include "atlcom.h"  
  
[module (name="MyLibrary")];  
  
[ coclass, requires_category("CATID_Control"),  
  uuid("1e1a2436-f3ea-4ff3-80bf-5409370e8144")]  
class CMyClass {};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe**,`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Um ou mais das seguintes opções:  **coclass**,  **progid**, ou  **vi\_progid**.|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [COM Attributes](../Topic/COM%20Attributes.md)   
 [implements\_category](../Topic/implements_category.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)