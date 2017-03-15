---
title: "Trocando dados | Microsoft Docs"
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
  - "DDX (troca de dados da caixa de diálogo), folhas de propriedade"
  - "trocando dados com folhas de propriedade"
  - "folhas de propriedade, troca de dados"
ms.assetid: 689f02d0-51a9-455b-8ffb-5b44f0aefa28
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Trocando dados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como com a maioria das caixas de diálogo, a troca de dados entre a folha de propriedades e o aplicativo é uma das funções mais importantes de folha de propriedades.  Este artigo descreve como realizar esta tarefa.  
  
 Trocar dados com uma folha de propriedade são realmente uma questão de troca de dados com as páginas de propriedades individuais da folha de propriedades.  O procedimento para trocar dados com uma página de propriedades é o mesmo de troca de dados com uma caixa de diálogo, desde que um objeto de [CPropertyPage](../mfc/reference/cpropertypage-class.md) é apenas um objeto especializado de [CDialog](../mfc/reference/cdialog-class.md) .  O procedimento beneficia\-se da facilidade de troca de dados da caixa de diálogo estrutura \(DDX\), que troca dados entre controles em uma caixa de diálogo e variáveis de membro da caixa de diálogo objeto.  
  
 A diferença importante entre troca de dados com uma folha de propriedade e com uma caixa de diálogo normal é que a folha de propriedades tiver várias páginas, você deve trocar dados com todas as páginas de folha de propriedades.  Para obter mais informações sobre como DDX, consulte [Caixa de diálogo troca de dados e validação](../mfc/dialog-data-exchange-and-validation.md).  
  
 O exemplo a seguir ilustra a troca de dados entre uma exibição e duas páginas de uma folha de propriedades:  
  
 [!code-cpp[NVC_MFCDocView#4](../mfc/codesnippet/CPP/exchanging-data_1.cpp)]  
  
## Consulte também  
 [Folhas de propriedade](../mfc/property-sheets-mfc.md)