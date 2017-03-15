---
title: "optional (C++) | Microsoft Docs"
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
  - "vc-attr.optional"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "optional attribute"
ms.assetid: 86656a66-8e11-4589-8e30-9b0f34eeed03
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# optional (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica um parâmetro opcional para uma função de membro.  
  
## Sintaxe  
  
```  
  
[optional]  
  
```  
  
## Comentários  
 O  **opcional** o atributo do C\+\+ tem a mesma funcionalidade que o  [opcional](http://msdn.microsoft.com/library/windows/desktop/aa367132) atributo MIDL.  
  
## Exemplo  
 O seguinte código mostra como  **opcional** pode ser usado:  
  
```  
// cpp_attr_ref_optional.cpp  
// compile with: /LD  
#include "unknwn.h"  
[module(name="ATLFIRELib")];  
  
[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]  
__interface IFireTabCtrl : IDispatch  
{  
   [id(1)] long procedure ([in, optional] VARIANT i);  
};  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Parâmetro de interface|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Parameter Attributes](../windows/parameter-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)