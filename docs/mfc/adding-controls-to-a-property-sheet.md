---
title: "Adicionando controles a uma folha de propriedades | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "controles [MFC], adicionando às folhas de propriedade"
  - "folhas de propriedade, adicionando controles"
ms.assetid: 24ad4c0b-c1db-4850-b9f0-34aae8d74571
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando controles a uma folha de propriedades
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Por padrão, uma folha de propriedade atribui a área da janela para as páginas de propriedades, o índice da guia, e o OK, cancel, e aplica os botões. \(A folha de propriedades modeless de não tem OK, não cancela, e não aplica os botões.\) Você pode adicionar outros controles para a folha de propriedades.  Por exemplo, você pode adicionar uma janela de visualização à direita da área da página de propriedades para mostrar ao usuário o que as configurações atuais olhariam como se aplicado a um objeto externo.  
  
 Você pode adicionar controles na caixa de diálogo de folha de propriedade no manipulador de `OnCreate` .  Os controles adicionais obsequiosos normalmente exigem expandir o tamanho da caixa de diálogo da folha de propriedades.  Depois de chamar a classe base **CPropertySheet::OnCreate**, a chamada [GetWindowRect](../Topic/CWnd::GetWindowRect.md) para obter a largura e a altura da janela atribuída atualmente da folha de propriedades, expanda as dimensões do retângulo, e chame [MoveWindow](../Topic/CWnd::MoveWindow.md) para alterar o tamanho da janela da folha de propriedades.  
  
## Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)   
 [Classe de CPropertyPage](../mfc/reference/cpropertypage-class.md)   
 [Classe de CPropertySheet](../mfc/reference/cpropertysheet-class.md)