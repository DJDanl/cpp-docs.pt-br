---
title: "System.Diagnostics.DebuggerHiddenAttribute n&#227;o afeta &#39;Get&#39; ou &#39;Set&#39; quando aplicado &#224; defini&#231;&#227;o da propriedade | Microsoft Docs"
ms.custom: ""
ms.date: "11/23/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-visual-basic"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "bc40051"
  - "vbc40051"
helpviewer_keywords: 
  - "BC40051"
ms.assetid: 623d5e48-7fb2-48a9-bbbb-92914b08c01c
caps.latest.revision: 10
caps.handback.revision: 10
author: "stevehoag"
ms.author: "shoag"
manager: "wpickett"
---
# System.Diagnostics.DebuggerHiddenAttribute n&#227;o afeta &#39;Get&#39; ou &#39;Set&#39; quando aplicado &#224; defini&#231;&#227;o da propriedade
System.Diagnostics.DebuggerHiddenAttribute não afeta 'Get' ou 'Set' quando aplicado à definição da propriedade. Aplique o atributo diretamente aos procedimentos 'Get' e 'Set' conforme apropriado.  
  
 O <xref:System.Diagnostics.DebuggerHiddenAttribute> é aplicado a uma declaração de propriedade.  
  
 Código\-fonte pode aplicar o <xref:System.Diagnostics.DebuggerHiddenAttribute> para um procedimento. Isso informa o depurador do Visual Studio para não parar dentro do procedimento e não permitir que os pontos de interrupção ser definido no procedimento.  
  
 Embora você possa aplicar <xref:System.Diagnostics.DebuggerHiddenAttribute> a uma propriedade, ela não tem qualquer efeito. Ele tem o efeito que você deseja somente se você aplicá\-lo para a propriedade `Get` ou `Set` procedimento.  
  
 Por padrão, essa mensagem é um aviso. Para obter informações sobre como ocultar avisos ou tratar avisos como erros, consulte [Configurando avisos no Visual Basic](../Topic/Configuring%20Warnings%20in%20Visual%20Basic.md).  
  
 **ID do erro:** BC40051  
  
### Para corrigir este erro  
  
-   Remover o <xref:System.Diagnostics.DebuggerHiddenAttribute> da declaração de propriedade e aplicá\-lo para a propriedade `Get` ou `Set` procedimento conforme apropriado.  
  
## Consulte também  
 <xref:System.Diagnostics.DebuggerHiddenAttribute>   
 [Procedimentos de propriedade](../Topic/Property%20Procedures%20\(Visual%20Basic\).md)   
 [Instrução Property](../Topic/Property%20Statement.md)   
 [Instrução Get](../Topic/Get%20Statement.md)   
 [Instrução Set](../Topic/Set%20Statement%20\(Visual%20Basic\).md)