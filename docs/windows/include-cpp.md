---
title: "include (C++) | Microsoft Docs"
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
  - "vc-attr.include"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "include attribute"
ms.assetid: d23f8b91-fe5b-48fa-9371-8bd73af7b8e3
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# include (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica um ou mais arquivos de cabeçalho a serem incluídos no arquivo. idl gerado.  
  
## Sintaxe  
  
```  
  
      [ include(  
   header_file  
) ];  
```  
  
#### Parâmetros  
 *header\_file*  
 O nome de um arquivo que você deseja incluído no arquivo. idl gerado.  
  
## Comentários  
 O  **incluem** C\+\+ atributo faz com que uma `#include` instrução deve ser colocada abaixo de `import "docobj.idl"` declaração no arquivo. idl gerado.  
  
 O  **incluem** o atributo do C\+\+ tem a mesma funcionalidade que o  [incluem](http://msdn.microsoft.com/library/windows/desktop/aa367052) atributo MIDL.  
  
## Exemplo  
 O código a seguir mostra um exemplo de como usar o  **incluem**.  Neste exemplo, include.h o arquivo contém somente uma instrução \# include.  
  
```  
// cpp_attr_ref_include.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[include(cpp_attr_ref_include.h)];  
```  
  
## Requisitos  
  
### Contexto de atributo  
  
|||  
|-|-|  
|**Se aplica a**|Em qualquer lugar|  
|**Reproduzíveis**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte  [Atributo contextos](../windows/attribute-contexts.md).  
  
## Consulte também  
 [IDL Attributes](../windows/idl-attributes.md)   
 [Stand\-Alone Attributes](../Topic/Stand-Alone%20Attributes.md)   
 [import](../windows/import.md)   
 [importidl](../windows/importidl.md)   
 [includelib](../windows/includelib-cpp.md)   
 [importlib](../windows/importlib.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)