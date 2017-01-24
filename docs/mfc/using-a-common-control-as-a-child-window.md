---
title: "Usando um controle comum como uma janela filho | Microsoft Docs"
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
  - "janelas filho, controles comuns como"
  - "controles comuns [C++], janelas filho"
  - "controles [MFC], usando como janelas filho"
  - "janelas [C++], controles comuns como"
  - "controles comuns do Windows [C++], janelas filho"
ms.assetid: 608f7d47-7854-4fce-bde9-856c51e76753
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando um controle comum como uma janela filho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Alguns dos controles comum do windows podem ser usados como uma janela filho de qualquer outra janela.  O procedimento a seguir descreve como criar dinamicamente um controle comuns e trabalhar com ela.  
  
### Para usar um controle comuns como uma janela filho  
  
1.  Define o controle na classe ou no manipulador relacionada.  
  
2.  Use a substituição de controle do método de [CWnd::Create](../Topic/CWnd::Create.md) para criar o controle do windows.  
  
3.  Depois que o controle esteve criado \(a partir do manipulador de `OnCreate` se você subclasse o controle\), você pode manipular o controle usando as funções de membro.  Consulte as descrições de controles individuais em [Controles](../mfc/controls-mfc.md) para obter detalhes sobre métodos.  
  
4.  Quando você terminar com o controle, use [CWnd::DestroyWindow](../Topic/CWnd::DestroyWindow.md) para destruir o controle.  
  
## Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)