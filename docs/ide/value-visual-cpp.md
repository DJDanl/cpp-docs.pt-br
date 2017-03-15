---
title: "&lt;valor&gt; (Visual C++) | Microsoft Docs"
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
  - "value"
  - "<value>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <value>"
  - "marca XML C++ value"
ms.assetid: 0ba0a0d5-bcd7-4862-a169-83f2721ad80e
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;valor&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A marca de \<value\> permite que você descreva métodos de propriedade e do assessor de propriedade.  Observe que quando você adicionar uma propriedade com um assistente de código no ambiente de desenvolvimento integrado Visual Studio, adicionar uma marca de [\<summary\>](../ide/summary-visual-cpp.md) para a nova propriedade.  Você deve adicionar manualmente em uma marca de \<value\> para descrever o valor que a propriedade representa.  
  
## Sintaxe  
  
```  
<value>property-description</value>  
```  
  
#### Parâmetros  
 `property-description`  
 Uma descrição para a propriedade.  
  
## Comentários  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
## Exemplo  
  
```  
// xml_value_tag.cpp  
// compile with: /LD /clr /doc  
// post-build command: xdcmake xml_value_tag.dll  
using namespace System;  
/// Text for class Employee.  
public ref class Employee {  
private:  
   String ^ name;  
   /// <value>Name accesses the value of the name data member</value>  
public:  
   property String ^ Name {  
      String ^ get() {  
         return name;   
      }  
      void set(String ^ i) {  
         name = i;  
      }  
   }  
};  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)