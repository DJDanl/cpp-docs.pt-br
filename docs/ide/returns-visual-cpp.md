---
title: "&lt;returns&gt; (Visual C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "returns"
  - "<returns>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <returns>"
  - "marca XML C++ returns"
ms.assetid: 5e3b0ed9-838d-4953-a93e-76d2d0a19fb9
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;returns&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A marca de \<returns\> deve ser usada no comentário de uma declaração de método para descrever o valor de retorno.  
  
## Sintaxe  
  
```  
<returns>description</returns>  
```  
  
#### Parâmetros  
 `description`  
 Uma descrição de valor de retorno.  
  
## Comentários  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
## Exemplo  
  
```  
// xml_returns_tag.cpp  
// compile with: /LD /clr /doc  
// post-build command: xdcmake xml_returns_tag.dll  
  
/// Text for class MyClass.  
public ref class MyClass {  
public:  
   /// <returns>Returns zero.</returns>  
   int GetZero() { return 0; }  
};  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)