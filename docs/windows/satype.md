---
title: "satype | Microsoft Docs"
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
  - "vc-attr.satype"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "satype attribute"
ms.assetid: 1716590b-6bcb-4aba-b1bc-82f7335f02c3
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# satype
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica o tipo de dados da  **SAFEARRAY** estrutura.  
  
## Sintaxe  
  
```  
  
      [ satype(  
   data_type  
) ]  
```  
  
#### Parâmetros  
 *data\_type*  
 O tipo de dados para o  **SAFEARRAY** estrutura de dados que está sendo passada como um parâmetro para um método de interface.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Parâmetro de interface, método de interface|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
## Comentários  
 O  **satype** atributo C\+\+ Especifica o tipo de dados da  **SAFEARRAY**.  
  
> [!NOTE]
>  Um nível de indireção será retirado da  **SAFEARRAY** o ponteiro no arquivo. idl gerado a partir de como ele é declarado no arquivo. cpp.  
  
## Exemplo  
  
```  
// cpp_attr_ref_satype.cpp  
// compile with: /LD  
#include "unknwn.h"  
[module(name="MyModule")];  
[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]  
__interface A {  
   [id(1)] HRESULT MyMethod ([in, satype("BSTR")] SAFEARRAY **p);  
};  
```  
  
## Consulte também  
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [Parameter Attributes](../windows/parameter-attributes.md)   
 [Method Attributes](../windows/method-attributes.md)   
 [id](../windows/id.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)