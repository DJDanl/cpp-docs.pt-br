---
title: "Mapeando mensagens do Windows para a classe | Microsoft Docs"
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
  - "mapeamentos, mensagens para classe de caixa de diálogo"
  - "mapas de mensagem [C++], na classe de caixa de diálogo"
  - "mapas de mensagem [C++], mapeando mensagens do Windows para classes"
  - "mensagens para classe de caixa de diálogo"
  - "mensagens para classe de caixa de diálogo, mapeamento"
  - "caixas de diálogo MFC, mensagens do Windows"
  - "mensagens do Windows [C++], mapeando em classes de caixa de diálogo"
ms.assetid: a4c6fd1f-1d33-47c9-baa0-001755746d6d
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapeando mensagens do Windows para a classe
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você precisar a caixa de diálogo de tratar mensagens do windows, substitua as funções apropriadas do manipulador.  Para fazer isso, use a janela Propriedades a [mapeie as mensagens](../Topic/Mapping%20Messages%20to%20Functions.md) à classe da caixa de diálogo.  Isso grava uma entrada retornadas mapa para cada mensagem e adiciona as funções de membro retornadas à classe.  Use o editor de origem do Visual C\+\+ para escrever o código nos manipuladores de mensagem.  
  
 Você também pode substituir as funções de membro de [CDialog](../mfc/reference/cdialog-class.md) e suas classes base, especialmente [CWnd](../Topic/CWnd%20Class.md).  
  
## Que você deseja saber mais?  
  
-   [Manipulando e mapeamento de mensagem](../mfc/message-handling-and-mapping.md)  
  
-   [Funções de membro geralmente substituídas](../mfc/commonly-overridden-member-functions.md)  
  
-   [Funções de membro geralmente unidas](../Topic/Commonly%20Added%20Member%20Functions.md)  
  
## Consulte também  
 [Caixas de diálogo](../mfc/dialog-boxes.md)   
 [Ciclo de vida de uma caixa de diálogo](../mfc/life-cycle-of-a-dialog-box.md)