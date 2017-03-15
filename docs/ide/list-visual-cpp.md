---
title: "&lt;list&gt; (Visual C++) | Microsoft Docs"
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
  - "list"
  - "<list>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <list>"
  - "marca XML C++ list"
ms.assetid: c792a10b-0451-422c-9aa0-604116e69d64
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;list&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O bloco de \<listheader\> é usado para definir a linha de título de uma tabela ou da lista de definição.  Ao definir uma tabela, você só precisará fornecer uma entrada para o termo no título.  
  
## Sintaxe  
  
```  
<list type="bullet" | "number" | "table">  
   <listheader>  
      <term>term</term>  
      <description>description</description>  
   </listheader>  
   <item>  
      <term>term</term>  
      <description>description</description>  
   </item>  
</list>  
```  
  
#### Parâmetros  
 `term`  
 Um termo a definir, que é definido em `description`.  
  
 `description`  
 Um item em um marcador ou lista numerada ou a definição de `term`.  
  
## Comentários  
 Cada item na lista é especificado com um bloco de \<item\> .  Ao criar uma lista de definição, você precisará especificar `term` e `description`.  Entretanto, para uma tabela, lista com marcadores, ou lista numerada, você só precisará fornecer uma entrada para `description`.  
  
 Uma lista ou uma tabela podem ter tantas blocos de \<item\> quando necessário.  
  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
## Exemplo  
  
```  
// xml_list_tag.cpp  
// compile with: /doc /LD  
// post-build command: xdcmake xml_list_tag.dll  
/// <remarks>Here is an example of a bulleted list:  
/// <list type="bullet">  
/// <item>  
/// <description>Item 1.</description>  
/// </item>  
/// <item>  
/// <description>Item 2.</description>  
/// </item>  
/// </list>  
/// </remarks>  
class MyClass {};  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)