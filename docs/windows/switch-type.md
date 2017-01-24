---
title: "switch_type | Microsoft Docs"
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
  - "vc-attr.switch_type"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "switch_type attribute"
ms.assetid: e24544dc-b3bc-48ae-b249-f967db49271e
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# switch_type
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Identifica o tipo da variável usado como o discriminant de união.  
  
## Sintaxe  
  
```  
  
[switch_type(  
type  
}]  
  
```  
  
#### Parâmetros  
 `type`  
 O tipo de comutação, pode ser um tipo de caractere, inteiro, booleano ou enumeração.  
  
## Comentários  
 O  **switch\_type** o atributo do C\+\+ tem a mesma funcionalidade que o  [switch\_type](http://msdn.microsoft.com/library/windows/desktop/aa367276) atributo MIDL.  
  
 Atributos do C\+\+ não oferecem suporte a  [encapsulado uniões](http://msdn.microsoft.com/library/windows/desktop/aa366811).  [Uniões nonencapsulated](http://msdn.microsoft.com/library/windows/desktop/aa367119) são suportados apenas no seguinte formato:  
  
```  
// cpp_attr_ref_switch_type.cpp  
// compile with: /LD  
#include <windows.h>  
[module(name="MyLibrary")];  
[ export ]  
struct SizedValue2 {  
   [switch_type("char"), switch_is(kind)] union {  
      [case(1), string]  
         wchar_t* wval;  
      [default, string]  
         char* val;  
   };  
   char kind;  
};  
```  
  
## Exemplo  
 Consulte o  [case](../windows/case-cpp.md) exemplo para um uso de amostra de  **switch\_type**.  
  
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
 [export](../windows/export.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)