---
title: Teclas de acesso global | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- keyboard shortcuts [MFC], hot keys
- CHotKeyCtrl class [MFC], global hot keys
- access keys [MFC], hot keys
- global hot keys [MFC]
ms.assetid: e0b95d14-c571-4c9a-9cd1-e7fc1f0e278d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cd597271d949770ec1a5871cad3ea7be0004e288
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33344224"
---
# <a name="global-hot-keys"></a>Teclas de acesso globais
Tecla de acesso global está associada uma janela nonchild específico. Ele permite que o usuário ativar a janela de qualquer parte do sistema. Um aplicativo define a tecla de acesso global para uma determinada janela, enviando o [WM_SETHOTKEY](http://msdn.microsoft.com/library/windows/desktop/ms646284) mensagem para essa janela. Por exemplo, se `m_HotKeyCtrl` é o [CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md) objeto e `pMainWnd` é um ponteiro para a janela a ser ativado quando é pressionada a tecla de acesso, você pode usar o código a seguir para associar a tecla de acesso especificada no controle com a janela apontada pelo `pMainWnd`.  
  
 [!code-cpp[NVC_MFCControlLadenDialog#18](../mfc/codesnippet/cpp/global-hot-keys_1.cpp)]  
  
 Sempre que o usuário pressiona uma tecla de acesso global, a janela especificada recebe um [WM_SYSCOMMAND](http://msdn.microsoft.com/library/windows/desktop/ms646360) mensagem especifica **SC_HOTKEY** como o tipo do comando. Essa mensagem também ativa a janela que recebe. Como esta mensagem não tem nenhuma informação sobre a chave exata que foi pressionada, usando esse método não permite fazer distinção entre as teclas de acesso diferentes que podem ser conectadas à mesma janela. A tecla de acesso permanece válida até o aplicativo que enviou **WM_SETHOTKEY** será encerrado.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)   
 [Controles](../mfc/controls-mfc.md)

