---
title: "Usando CHotKeyCtrl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "CHotKeyCtrl"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CHotKeyCtrl, usando"
  - "controles de tecla de acesso"
  - "chaves, acesso e CHotKeyCtrl"
ms.assetid: 9b207117-d848-4224-8888-c3d197bb0c95
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando CHotKeyCtrl
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um controle de tecla de acesso, representado pela classe [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md), é uma janela que exibe uma representação de texto da combinação de teclas o usuário nela, como CTRL\+SHIFT\+Q.  Também mantém uma representação interna dessa chave na forma de um código chave virtual e um conjunto de sinalizadores que representam o estado do turno.  O controle de tecla de acesso não realmente define a tecla de acesso — fazer isso ocorre até o programa. \(Para obter uma lista de códigos chaves virtuais, consulte Winuser.h.\)  
  
 Use um controle de tecla de acesso para obter a entrada de um usuário para o qual a tecla de acesso desejada a ser associado a uma janela ou um thread.  Os controles de tecla de acesso são usadas frequentemente nas caixas de diálogo, como você pode exibir ao solicitar que o usuário aloque uma tecla de acesso.  É responsabilidade do programa recuperar valores que descrevem a tecla de acesso do controle de tecla de acesso e chame as funções apropriadas para associar a tecla de acesso com uma janela ou um thread.  
  
## Que você deseja saber mais?  
  
-   [Usando um controle de tecla de acesso](../Topic/Using%20a%20Hot%20Key%20Control.md)  
  
-   [Definindo uma tecla de acesso](../Topic/Setting%20a%20Hot%20Key.md)  
  
-   [Teclas de acesso globais](../Topic/Global%20Hot%20Keys.md)  
  
-   [Teclas de acesso específicas de threads](../Topic/Thread-Specific%20Hot%20Keys.md)  
  
## Consulte também  
 [Controles](../mfc/controls-mfc.md)