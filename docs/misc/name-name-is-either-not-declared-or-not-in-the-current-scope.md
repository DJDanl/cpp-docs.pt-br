---
title: "O nome &#39;&lt; nome &gt;&#39; n&#227;o est&#225; declarado ou n&#227;o est&#225; no escopo atual | Microsoft Docs"
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
  - "vbc36610"
  - "bc36610"
helpviewer_keywords: 
  - "BC36610"
ms.assetid: e66a4b8a-9252-42ae-a30d-341fad4f74be
caps.latest.revision: 4
caps.handback.revision: 4
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# O nome &#39;&lt; nome &gt;&#39; n&#227;o est&#225; declarado ou n&#227;o est&#225; no escopo atual
Uma consulta LINQ se refere a um elemento de programação, mas o compilador não pode localizar um elemento que tenha exatamente com este nome.  
  
 **ID do erro:** BC36610  
  
### Para corrigir este erro  
  
1.  Verifique a ortografia do nome na declaração de referência.[!INCLUDE[vbprvb](../Token/vbprvb_md.md)] diferencia maiúsculas de minúsculas, mas qualquer outra variação de grafia constitui um nome diferente. Observe que o caractere de sublinhado \(`_`\) é parte do nome e, portanto, parte da grafia.  
  
2.  Verifique se o elemento de programação está no escopo. Se a referência está fora da região que declara o elemento de programação, você terá que qualificar o nome do elemento. Para obter mais informações, consulte [Escopo no Visual Basic](../Topic/Scope%20in%20Visual%20Basic.md).  
  
3.  Verifique se você tem o operador de acesso de membro \(`.`\) entre um objeto e seu membro. Por exemplo, se você tiver um <xref:System.Windows.Forms.TextBox> controle denominado `TextBox1`, para acessar seu <xref:System.Windows.Forms.TextBoxBase.Text%2A> propriedade, você deve digitar `TextBox1.Text`. Se em vez disso você digitar `TextBox1Text`, você criou um nome diferente.  
  
## Consulte também  
 [Introdução a LINQ no Visual Basic](../Topic/Introduction%20to%20LINQ%20in%20Visual%20Basic.md)   
 [Convenções de nomenclatura do Visual Basic](../Topic/Visual%20Basic%20Naming%20Conventions.md)   
 [Referências a elementos declarados](../Topic/References%20to%20Declared%20Elements%20\(Visual%20Basic\).md)