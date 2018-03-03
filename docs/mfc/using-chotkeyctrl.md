---
title: Usando CHotKeyCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CHotKeyCtrl
dev_langs:
- C++
helpviewer_keywords:
- keys, hot and CHotKeyCtrl
- CHotKeyCtrl class [MFC], using
- hot key controls
ms.assetid: 9b207117-d848-4224-8888-c3d197bb0c95
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 36d577369dea4f5fe2fffa9801bbd8ae8501f71a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-chotkeyctrl"></a>Usando CHotKeyCtrl
Um controle de tecla ativo, representado pela classe [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md), é uma janela que exibe uma representação de texto da combinação de chave, o usuário digita, como CTRL + SHIFT + Q. Ele também mantém uma representação interna dessa chave na forma de um código de tecla virtual e um conjunto de sinalizadores que representam o estado de shift. O controle de chave de acesso não definem a tecla de acesso — isso é até seu programa. (Para obter uma lista de códigos de tecla virtuais padrão, consulte WinUser.)  
  
 Use um controle de chave de acesso para obter a entrada do usuário para o qual tecla de atalho associar uma janela ou thread. Controles de chave de acesso geralmente são usados nas caixas de diálogo, como você pode exibir ao usuário para atribuir uma tecla de acesso. É responsabilidade do programa para recuperar os valores que descrevem a tecla de atalho do controle de chave de acesso e para chamar as funções apropriadas para associar a tecla de acesso uma janela ou thread.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Usando um controle de tecla de acesso](../mfc/using-a-hot-key-control.md)  
  
-   [Configurando uma tecla de acesso](../mfc/setting-a-hot-key.md)  
  
-   [Teclas de acesso globais](../mfc/global-hot-keys.md)  
  
-   [Teclas de acesso específicas de thread](../mfc/thread-specific-hot-keys.md)  
  
## <a name="see-also"></a>Consulte também  
 [Controles](../mfc/controls-mfc.md)

