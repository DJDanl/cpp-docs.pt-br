---
title: "Selecionando um objeto gr&#225;fico em um contexto de dispositivo | Microsoft Docs"
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
  - "contextos de dispositivo, objetos gráficos"
  - "contextos de dispositivo, selecionando objetos gráficos em"
  - "Objetos GDI [C++], contextos de dispositivo"
  - "objetos gráficos, selecionando no contexto do dispositivo"
  - "tempo de vida, objetos gráficos"
  - "Método SelectObject"
ms.assetid: cf54a330-63ef-421f-83eb-90ec7bd82eef
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Selecionando um objeto gr&#225;fico em um contexto de dispositivo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico aplica\-se ao uso de objetos gráficos no contexto do dispositivo de uma janela.  Depois que você [crie um objeto de desenho](../mfc/one-stage-and-two-stage-construction-of-objects.md), você deve selecionar o no contexto do dispositivo no lugar do objeto padrão armazenado:  
  
 [!code-cpp[NVC_MFCDocViewSDI#7](../mfc/codesnippet/CPP/selecting-a-graphic-object-into-a-device-context_1.cpp)]  
  
## Tempo de vida de objetos gráficos  
 O objeto retornado por [SelectObject](../Topic/CDC::SelectObject.md) gráfico é “temporário.” Ou seja, será excluído pela função de membro de [OnIdle](../Topic/CWinApp::OnIdle.md) da classe `CWinApp` a próxima vez que o programa obtém o tempo ocioso.  Como você usa o objeto retornado por `SelectObject` em uma única função não retornará o controle ao loop principal da mensagem, você não terá nenhum problema.  
  
### Que você deseja saber mais?  
  
-   [Objetos gráficos](../mfc/graphic-objects.md)  
  
-   [Uma fase de construção e dois estágios de objetos gráficos](../mfc/one-stage-and-two-stage-construction-of-objects.md)  
  
-   [Contextos de dispositivo](../Topic/Device%20Contexts.md)  
  
-   [Desenhar em uma exibição](../mfc/drawing-in-a-view.md)  
  
## Consulte também  
 [Objetos gráficos](../mfc/graphic-objects.md)