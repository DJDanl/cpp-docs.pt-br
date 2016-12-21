---
title: "case (C++) | Microsoft Docs"
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
  - "vc-attr.case"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "case attribute"
ms.assetid: 6fb883c3-0526-4932-a901-b4564dcaeb7d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# case (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usado com o  [switch\_type](../windows/switch-type.md) o atributo em um  **união**.  
  
## Sintaxe  
  
```  
  
      [ case(  
   value  
) ]  
```  
  
#### Parâmetros  
 *Valor*  
 Um valor de entrada possível para o qual você deseja fornecer processamento.  O tipo de  **valor** pode ser um dos seguintes tipos:  
  
-   `int`  
  
-   `char`  
  
-   **valor booleano**  
  
-   `enum`  
  
 ou um identificador desse tipo.  
  
## Comentários  
 O  **case** o atributo do C\+\+ tem a mesma funcionalidade que o  **caso** atributo MIDL.  Esse atributo é usado somente com o  [switch\_type](../windows/switch-type.md) atributo.  
  
## Exemplo  
 O código a seguir mostra um uso o  **case** atributo:  
  
```  
// cpp_attr_ref_case.cpp  
// compile with: /LD  
#include <unknwn.h>  
[export]  
struct SizedValue2 {  
   [switch_type(char), switch_is(kind)] union {  
      [case(1), string]  
          wchar_t* wval;  
      [default, string]  
          char* val;  
   };  
    char kind;  
};  
[module(name="ATLFIRELib")];  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Membro de um  **classe** ou`struct`|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Class Attributes](../windows/class-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)