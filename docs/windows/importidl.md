---
title: "importidl | Microsoft Docs"
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
  - "vc-attr.importidl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "importidl attribute"
ms.assetid: 4b0a4b55-6c57-4e6e-bc7b-a12cc8063941
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# importidl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Insere o arquivo. idl especificado no arquivo. idl gerado.  
  
## Sintaxe  
  
```  
  
      [ importidl(  
   idl_file  
) ];  
```  
  
#### Parâmetros  
 `idl_file`  
 Identifica o nome do arquivo. idl que você deseja mesclar com o arquivo. idl que será gerado para o seu aplicativo.  
  
## Comentários  
 O  **importidl** atributo C\+\+ coloca a seção fora do bloco de biblioteca \(em `idl_file`\) em seu arquivo de programa. idl gerado e a seção de biblioteca \(em `idl_file`\) para a biblioteca a seção do seu programa gerou o arquivo. idl.  
  
 Você talvez queira usar  **importidl**, por exemplo, se você quiser usar um arquivo. idl do codificado manualmente com seu arquivo. idl gerado.  
  
## Exemplo  
  
```  
// cpp_attr_ref_importidl.cpp  
// compile with: /LD  
[module(name="MyLib")];  
[importidl("import.idl")];  
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
 [Compiler Attributes](../windows/compiler-attributes.md)   
 [Stand\-Alone Attributes](../Topic/Stand-Alone%20Attributes.md)   
 [import](../windows/import.md)   
 [importlib](../windows/importlib.md)   
 [include](../windows/include-cpp.md)   
 [includelib](../windows/includelib-cpp.md)   
 [Attributes Samples](http://msdn.microsoft.com/pt-br/558ebdb2-082f-44dc-b442-d8d33bf7bdb8)