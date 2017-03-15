---
title: "wire_marshal | Microsoft Docs"
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
  - "vc-attr.wire_marshal"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "wire_marshal attribute"
ms.assetid: 244f9d72-776d-4ebd-b60a-cee600a126b5
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# wire_marshal
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica um tipo de dados que será usado para transmissão em vez de um tipo de dados específicos do aplicativo.  
  
## Sintaxe  
  
```  
  
[wire_marshal]  
  
```  
  
## Comentários  
 O  **wire\_marshal** o atributo do C\+\+ tem a mesma funcionalidade que o  [wire\_marshal](http://msdn.microsoft.com/library/windows/desktop/aa367309) atributo MIDL.  
  
## Exemplo  
 O código a seguir mostra um uso de  **wire\_marshal**:  
  
```  
// cpp_attr_ref_wire_marshal.cpp  
// compile with: /LD  
#include "windows.h"  
[module(name="MyLibrary")];  
  
[export, public] typedef unsigned long _FOUR_BYTE_DATA;  
  
[export] typedef struct _TWO_X_TWO_BYTE_DATA {  
   unsigned short low;  
   unsigned short high;  
} TWO_X_TWO_BYTE_DATA ;  
  
[export, wire_marshal(TWO_X_TWO_BYTE_DATA)] typedef _FOUR_BYTE_DATA FOUR_BYTE_DATA;  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|`typedef`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)