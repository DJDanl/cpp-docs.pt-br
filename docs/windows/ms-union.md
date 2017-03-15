---
title: "ms_union | Microsoft Docs"
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
  - "vc-attr.ms_union"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ms_union attribute"
ms.assetid: bb548689-6962-457e-af56-8ffdf68987eb
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ms_union
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Controla o alinhamento de representação de dados de rede de uniões nonencapsulated.  
  
## Sintaxe  
  
```  
  
[ms_union]  
  
```  
  
## Comentários  
 O  **ms\_union** o atributo do C\+\+ tem a mesma funcionalidade que o  [ms\_union](http://msdn.microsoft.com/library/windows/desktop/aa367100) atributo MIDL.  
  
## Exemplo  
 O código a seguir mostra a colocação do  **ms\_union**:  
  
```  
// cpp_attr_ref_ms_union.cpp  
// compile with: /LD  
#include <unknwn.h>  
[object, ms_union, uuid("00000000-0000-0000-0000-000000000001")]  
__interface IFireTabCtrl {  
   HRESULT DisplayString([in, string] char * p1);  
};  
  
[export, switch_type(short)] union _WILLIE_UNION_TYPE  {  
   [case(24)]  
      float fMays;  
   [case(25)]  
      double dMcCovey;  
   [default]  
      int x;  
 };  
  
[public] typedef _WILLIE_UNION_TYPE WILLIE_UNION_TYPE;  
  
[module(name="ATLFIRELib")];  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Nonencapsulated uniões|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|**dispinterface**|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Typedef, Enum, Union, and Struct Attributes](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)