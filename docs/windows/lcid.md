---
title: "lcid | Microsoft Docs"
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
  - "vc-attr.lcid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LCID attribute"
ms.assetid: 7f248c69-ee1c-42c3-9411-39cf27c9f43d
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# lcid
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Permite que você passa um identificador de localidade para uma função.  
  
## Sintaxe  
  
```  
  
[lcid]  
  
```  
  
## Comentários  
 O  **lcid** atributo C\+\+ implementa a funcionalidade da  [lcid](http://msdn.microsoft.com/library/windows/desktop/aa367067) atributo MIDL.  Se você deseja implementar o código de idioma para um bloco de biblioteca, use o  **lcid \=**`lcid` parâmetro para o  [módulo de](../windows/module-cpp.md) atributo.  
  
## Exemplo  
  
```  
// cpp_attr_ref_lcid.cpp  
// compile with: /LD  
#include <unknwn.h>  
[module(name="MyLibrary")];  
typedef long HRESULT;  
  
[dual, uuid("2F5F63F1-16DA-11d2-9E7B-00C04FB926DA")]  
__interface IStatic {  
   HRESULT MyFunc([in, lcid] long LocaleID, [out, retval] BSTR * ReturnVal);  
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
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Parameter Attributes](../windows/parameter-attributes.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)