---
title: "&lt;coment&#225;rios&gt; (Visual C++) | Microsoft Docs"
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
  - "remarks"
  - "<remarks>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "marca XML C++ <remarks>"
  - "marca XML C++ remarks"
ms.assetid: c820083b-3192-40ab-9ec8-1472c55b4247
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# &lt;coment&#225;rios&gt; (Visual C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A marca de \<remarks\> é usada para adicionar informações sobre um tipo, suplementando informações especificada com [\<summary\>](../ide/summary-visual-cpp.md).  Essa informação é exibida em [Pesquisador de objetos](http://msdn.microsoft.com/pt-br/f89acfc5-1152-413d-9f56-3dc16e3f0470) e no relatório da Web de comentário de código.  
  
## Sintaxe  
  
```  
<remarks>description</remarks>  
```  
  
#### Parâmetros  
 `description`  
 Uma descrição do membro.  
  
## Comentários  
 Compile com [\/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação para um arquivo.  
  
## Exemplo  
  
```  
// xml_remarks_tag.cpp  
// compile with: /LD /clr /doc  
// post-build command: xdcmake xml_remarks_tag.dll  
  
using namespace System;  
  
/// <summary>  
/// You may have some primary information about this class.  
/// </summary>  
/// <remarks>  
/// You may have some additional information about this class.  
/// </remarks>  
public ref class MyClass {};  
```  
  
## Consulte também  
 [A Documentação XML](../ide/xml-documentation-visual-cpp.md)