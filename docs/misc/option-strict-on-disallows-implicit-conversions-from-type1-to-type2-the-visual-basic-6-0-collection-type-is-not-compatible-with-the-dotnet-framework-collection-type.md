---
title: "Option Strict On n&#227;o permite convers&#245;es impl&#237;citas de &#39;&lt; type1 &gt;&#39; para &#39;&lt; type2 &gt;&#39;; o tipo de cole&#231;&#227;o do Visual Basic 6.0 n&#227;o &#233; compat&#237;vel com o tipo de cole&#231;&#227;o do .NET Framework | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vbc30753"
  - "bc30753"
helpviewer_keywords: 
  - "BC30753"
ms.assetid: 7e1bb22e-a507-483e-bfd6-f3a43e24a232
caps.latest.revision: 12
caps.handback.revision: 12
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Option Strict On n&#227;o permite convers&#245;es impl&#237;citas de &#39;&lt; type1 &gt;&#39; para &#39;&lt; type2 &gt;&#39;; o tipo de cole&#231;&#227;o do Visual Basic 6.0 n&#227;o &#233; compat&#237;vel com o tipo de cole&#231;&#227;o do .NET Framework
`Option Strict On` não permite conversões implícitas de '`<type1>`'para'`<type2>`'; o tipo de coleção do Visual Basic 6.0 não é compatível com o [!INCLUDE[dnprdnshort](../Token/dnprdnshort_md.md)] tipo de coleção.  
  
 O objeto de coleção que é usado no Visual Basic 6.0 difere do objeto de coleção que é usado em [!INCLUDE[vs_current_long](../misc/includes/vs_current_long_md.md)].  
  
 **ID do erro:** BC30753  
  
### Para corrigir este erro  
  
-   Converta objetos coleção explicitamente usando um as palavras\-chave de conversão de tipo. O [Função CType](../Topic/CType%20Function%20\(Visual%20Basic\).md) e [Operador DirectCast](../Topic/DirectCast%20Operator%20\(Visual%20Basic\).md) palavras\-chave acionar uma exceção de tempo de execução se a conversão falhar. O [Operador TryCast](../Topic/TryCast%20Operator%20\(Visual%20Basic\).md) palavra\-chave retorna [nada](../Topic/Nothing%20\(Visual%20Basic\).md) se a conversão falhar.  
  
## Consulte também  
 [Função CType](../Topic/CType%20Function%20\(Visual%20Basic\).md)   
 [Operador DirectCast](../Topic/DirectCast%20Operator%20\(Visual%20Basic\).md)   
 [Operador TryCast](../Topic/TryCast%20Operator%20\(Visual%20Basic\).md)   
 [nada](../Topic/Nothing%20\(Visual%20Basic\).md)   
 [Coleções de PONTA em Visual Basic](http://msdn.microsoft.com/pt-br/8b2b7845-2251-4573-8dd3-c9f9c0a66a21)