---
title: "rdx | Microsoft Docs"
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
  - "vc-attr.rdx"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "rdx attribute"
ms.assetid: ff8e4312-c1ad-4934-bdaa-86f54409651e
caps.latest.revision: 14
caps.handback.revision: 14
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# rdx
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria uma chave do registro ou modifica uma chave de registro existente.  
  
## Sintaxe  
  
```  
  
      [ rdx(   
   key,   
   valuename=NULL,   
   regtype   
) ]  
```  
  
#### Parâmetros  
 `key`  
 O nome da chave a ser criado ou aberto.  
  
 `valuename`\(opcional\)  
 Especifica o campo de valor a ser definido.  Se um valor de campo com este nome ainda não existir na chave, ela é adicionada.  
  
 *regtype*  
 O tipo de chave de registro que está sendo adicionado.  Pode ser uma das seguintes opções:  **texto**,  **dword**,  **binário**, ou `CString`.  
  
## Comentários  
 O  **rdx** atributo C\+\+ cria ou modifica uma chave do registro existente para um componente COM.  O atributo adiciona uma macro BEGIN\_RDX\_MAP para o objeto que implementa o membro de destino.  `RegistryDataExchange`, uma função injetada como resultado de uma macro BEGIN\_RDX\_MAP, pode ser usado para transferir dados entre o registro e os membros de dados  
  
 Esse atributo pode ser usado em conjunto com o  [coclass](../windows/coclass.md),  [progid](../Topic/progid.md), ou  [vi\_progid](../windows/vi-progid.md) atributos ou outros atributos que implica um destes procedimentos.  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|**classe** ou `struct` membro|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Exemplo  
 O código a seguir adiciona uma chave de registro chamada MeuValor para o sistema que descreve o componente COM CMyClass.  
  
```  
// cpp_attr_ref_rdx.cpp  
// compile with: /LD /link /OPT:NOREF  
#define _ATL_ATTRIBUTES  
#include "atlbase.h"  
  
[module (name="MyLib")];  
  
class CMyClass {  
public:  
   CMyClass() {  
      strcpy_s(m_sz, "SomeValue");  
   }  
  
   [ rdx(key = "HKCR\\MyApp.MyApp.1", valuename = "MyValue", regtype = "text")]   
   char m_sz[256];  
};  
```  
  
## Consulte também  
 [COM Attributes](../Topic/COM%20Attributes.md)   
 [registration\_script](../windows/registration-script.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)