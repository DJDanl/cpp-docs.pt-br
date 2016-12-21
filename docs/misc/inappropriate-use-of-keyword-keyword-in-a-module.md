---
title: "Uso inadequado da palavra-chave &lt; palavra-chave &gt; em um m&#243;dulo | Microsoft Docs"
ms.custom: ""
ms.date: "11/17/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vbc42028"
  - "BC42028"
helpviewer_keywords: 
  - "BC42028"
ms.assetid: a9bc1e9d-ba2c-4a71-b147-0fb66f670316
caps.latest.revision: 12
caps.handback.revision: 12
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# Uso inadequado da palavra-chave &lt; palavra-chave &gt; em um m&#243;dulo
Módulos não têm instâncias, suporte a herança ou implementar interfaces. Portanto, as seguintes palavras\-chave não se aplicam a uma declaração de módulo:  
  
-   [MustInherit](../Topic/MustInherit%20\(Visual%20Basic\).md)  
  
-   [NotInheritable](../Topic/NotInheritable%20\(Visual%20Basic\).md)  
  
-   [Sobrecargas](../Topic/Overloads%20\(Visual%20Basic\).md)  
  
-   [Particular](../Topic/Private%20\(Visual%20Basic\).md)  
  
-   [Protegido](../Topic/Protected%20\(Visual%20Basic\).md)  
  
-   [Sombras](../Topic/Shadows%20\(Visual%20Basic\).md)  
  
-   [Compartilhado](../Topic/Shared%20\(Visual%20Basic\).md)  
  
-   [Estático](../Topic/Static%20\(Visual%20Basic\).md)  
  
 As palavras\-chave só tem suportadas em um [Instrução Module](../Topic/Module%20Statement.md) são [Público](../Topic/Public%20\(Visual%20Basic\).md) e [Friend](../Topic/Friend%20\(Visual%20Basic\).md).  
  
 Além disso, você não pode usar o [Implements](../Topic/Implements%20Clause%20\(Visual%20Basic\).md) instrução ou o [Instrução Inherits](../Topic/Inherits%20Statement.md) no bloco de declaração do módulo.  
  
 Por padrão, essa mensagem é um aviso. Para obter mais informações sobre como ocultar avisos ou tratar avisos como erros, consulte [Configurando avisos no Visual Basic](../Topic/Configuring%20Warnings%20in%20Visual%20Basic.md).  
  
 **ID do erro:** BC42028  
  
### Para corrigir este erro  
  
-   Se você pretender este elemento de programação para que seja um módulo, use apenas o `Public` ou `Friend` palavra\-chave na sua declaração. Por padrão, um módulo usa `Friend` se você não especificar seu nível de acesso.  
  
-   Se você pretende criar instâncias deste elemento de programação, declare\-o como uma classe. Você pode usar as palavras\-chave que se aplicam a uma declaração de classe.  
  
## Consulte também  
 [Instrução Class](../Topic/Class%20Statement%20\(Visual%20Basic\).md)