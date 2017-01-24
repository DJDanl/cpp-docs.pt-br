---
title: "importlib | Microsoft Docs"
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
  - "vc-attr.importlib"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "importlib attribute"
ms.assetid: f129e459-b8d3-4aca-a0bc-ee53e18b62ed
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# importlib
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Torna os tipos que já tiverem sido compilados em outra biblioteca de tipos disponível para a biblioteca de tipos que está sendo criada.  
  
## Sintaxe  
  
```  
  
        [ importlib(  
   "tlb_file"  
) ];  
```  
  
#### Parâmetros  
 *tlb\_file*  
 O nome de um arquivo. tlb, entre aspas, ser importado para a biblioteca de tipos do projeto atual.  
  
## Comentários  
 O **importlib** C\+\+ atributo faz com que um `importlib` instrução será colocado no bloco de biblioteca do arquivo. idl gerado.  O **importlib** atributo tem a mesma funcionalidade que o [importlib](http://msdn.microsoft.com/library/windows/desktop/aa367050) atributo MIDL.  
  
## Exemplo  
 O código a seguir mostra um exemplo de como usar **importlib**:  
  
```  
// cpp_attr_ref_importlib.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[importlib("importlib.tlb")];  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Aplica\-se a**|Em qualquer lugar|  
|**Repetível**|Não|  
|**Atributos necessários**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## Consulte também  
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [Stand\-Alone Attributes](../Topic/Stand-Alone%20Attributes.md)   
 [import](../windows/import.md)   
 [importidl](../windows/importidl.md)   
 [include](../windows/include-cpp.md)   
 [includelib](../windows/includelib-cpp.md)