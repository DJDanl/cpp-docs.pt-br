---
title: "Funções de membro do botão Girar | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- spin button control, methods
- CSpinButtonCtrl class [MFC], methods
ms.assetid: a08a26fd-b803-4cbe-a509-395fa357d057
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c6f0abfd5803ea4b4d4b4478104790e0f56e5afc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="spin-button-member-functions"></a>Funções de membro do botão Girar
Há várias funções de membro disponíveis para o controle de rotação ([CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)). Use essas funções para alterar os seguintes atributos do botão de rotação.  
  
-   **Aceleração** você pode ajustar a taxa na qual a posição muda quando o usuário mantém pressionado o botão de seta. Para trabalhar com a aceleração, use o [SetAccel](../mfc/reference/cspinbuttonctrl-class.md#setaccel) e [GetAccel](../mfc/reference/cspinbuttonctrl-class.md#getaccel) funções de membro.  
  
-   **Base** você pode alterar a base (10 ou 16) usada para exibir a posição na legenda da janela buddy. Para trabalhar com a base, use o [GetBase](../mfc/reference/cspinbuttonctrl-class.md#getbase) e [SetBase](../mfc/reference/cspinbuttonctrl-class.md#setbase) funções de membro.  
  
-   **Janela de amigo** dinamicamente, você pode definir a janela buddy. Para consultar ou alterar o controle é a janela buddy, use o [GetBuddy](../mfc/reference/cspinbuttonctrl-class.md#getbuddy) e [SetBuddy](../mfc/reference/cspinbuttonctrl-class.md#setbuddy) funções de membro.  
  
-   **Posição** você pode consultar e alterar a posição. Para trabalhar diretamente com posição, use o [GetPos](../mfc/reference/cspinbuttonctrl-class.md#getpos) e [SetPos](../mfc/reference/cspinbuttonctrl-class.md#setpos) funções de membro. Como a legenda do controle buddy pode ter sido alterada (por exemplo, no caso de amigo é um controle de edição), `GetPos` recupera a legenda atual e ajusta a posição.  
  
-   **Intervalo** você pode alterar as posições de mínimas e máxima para o botão de rotação. Por padrão, o máximo é definido como 0 e o mínimo é definido como 100. Como o máximo padrão é menor do que o mínimo de padrão, as ações dos botões de seta é contrário à intuição. Normalmente, você definirá o intervalo usando os [SetRange](../mfc/reference/cspinbuttonctrl-class.md#setrange) função de membro. Para consultar o uso de intervalo [GetRange](../mfc/reference/cspinbuttonctrl-class.md#getrange).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CSpinButtonCtrl](../mfc/using-cspinbuttonctrl.md)   
 [Controles](../mfc/controls-mfc.md)

