---
title: "Folhas de propriedades e p&#225;ginas de propriedade (MFC) | Microsoft Docs"
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
  - "Classe CPropertyPage, folhas de propriedades e páginas"
  - "Classe CPropertySheet, folhas de propriedades e páginas"
  - "caixas de diálogo MFC, guias"
  - "páginas de propriedade, folhas de propriedade"
  - "folhas de propriedade, páginas de propriedade"
ms.assetid: de8fea12-6c35-4cef-8625-b8073a379446
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Folhas de propriedades e p&#225;ginas de propriedade (MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC Um [caixa de diálogo](../mfc/dialog-boxes.md) pode usar de “em um aspecto da caixa de diálogo guia” inserindo folhas de propriedades e páginas de propriedade.  Chamou “folha de uma propriedade” em MFC, esse tipo de caixa de diálogo, semelhante a várias caixas de diálogo no Microsoft Word, Excel, e o Visual C\+\+, parece conter uma pilha de folhas tabuladas, bem como uma pilha de pastas de arquivos vistas da frente para fazer backup, ou grupo do windows conectadas.  Os controles na guia para frente são visíveis; somente a guia rotulado é visível nas guias de backup.  As folhas de propriedades são particularmente úteis para gerenciar um grande número de propriedades ou definições encontradas razoavelmente ordenadamente em vários grupos.  Normalmente, uma folha de propriedade pode simplificar uma interface do usuário substituindo várias caixas de diálogo separadas.  
  
 A partir da versão 4,0 do MFC, as folhas e as páginas de propriedades de propriedade são implementadas usando os controles comuns que vêm com a versão 3,51 do Windows 95 e Windows NT e posterior.  
  
 As folhas de propriedades são implementadas com classes [CPropertySheet](../mfc/reference/cpropertysheet-class.md) e [CPropertyPage](../mfc/reference/cpropertypage-class.md) \(descritos na *referência de MFC*\).  `CPropertySheet` define a caixa de diálogo total, que pode conter várias “páginas” com base em `CPropertyPage`.  
  
 Para obter informações sobre como criar e trabalhar com de folhas de propriedades, consulte o tópico [Folhas de propriedades](../mfc/property-sheets-mfc.md).  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)   
 [Folhas de propriedades e páginas de propriedade em MFC](../mfc/property-sheets-and-property-pages-in-mfc.md)   
 [Trocando dados](../mfc/exchanging-data.md)   
 [Criando uma folha de propriedades sem janela restrita](../mfc/creating-a-modeless-property-sheet.md)   
 [Manipulando o botão Aplicar](../mfc/handling-the-apply-button.md)