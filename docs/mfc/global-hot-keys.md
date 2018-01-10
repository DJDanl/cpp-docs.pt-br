---
title: Teclas de acesso global | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- keyboard shortcuts [MFC], hot keys
- CHotKeyCtrl class [MFC], global hot keys
- access keys [MFC], hot keys
- global hot keys [MFC]
ms.assetid: e0b95d14-c571-4c9a-9cd1-e7fc1f0e278d
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 82297507d8725e6292def759272f48d0d63e84b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="global-hot-keys"></a>Teclas de acesso globais
Tecla de acesso global está associada uma janela nonchild específico. Ele permite que o usuário ativar a janela de qualquer parte do sistema. Um aplicativo define a tecla de acesso global para uma determinada janela, enviando o [WM_SETHOTKEY](http://msdn.microsoft.com/library/windows/desktop/ms646284) mensagem para essa janela. Por exemplo, se `m_HotKeyCtrl` é o [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md) objeto e `pMainWnd` é um ponteiro para a janela a ser ativado quando é pressionada a tecla de acesso, você pode usar o código a seguir para associar a tecla de acesso especificada no controle com a janela apontada pelo `pMainWnd`.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#18](../mfc/codesnippet/cpp/global-hot-keys_1.cpp)]  
  
 Sempre que o usuário pressiona uma tecla de acesso global, a janela especificada recebe um [WM_SYSCOMMAND](http://msdn.microsoft.com/library/windows/desktop/ms646360) mensagem especifica **SC_HOTKEY** como o tipo do comando. Essa mensagem também ativa a janela que recebe. Como esta mensagem não tem nenhuma informação sobre a chave exata que foi pressionada, usando esse método não permite fazer distinção entre as teclas de acesso diferentes que podem ser conectadas à mesma janela. A tecla de acesso permanece válida até o aplicativo que enviou **WM_SETHOTKEY** será encerrado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)   
 [Controles](../mfc/controls-mfc.md)

