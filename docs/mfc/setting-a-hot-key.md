---
title: Definindo uma tecla de acesso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- keyboard shortcuts [MFC], hot keys
- access keys [MFC], hot keys
- CHotKeyCtrl class [MFC], setting hot key
ms.assetid: 6f3bc141-e346-4dce-9ca7-3e6b2c453f3f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3987ddee98ae35e02a181e38cd71f181801aeb61
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="setting-a-hot-key"></a>Definindo uma tecla de acesso
Seu aplicativo pode usar as informações fornecidas por uma tecla de acesso ([CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)) controle em uma das seguintes maneiras:  
  
-   Configurar uma tecla de acesso global para ativar uma janela nonchild enviando um [WM_SETHOTKEY](http://msdn.microsoft.com/library/windows/desktop/ms646284) mensagem para a janela a ser ativado.  
  
-   Configurar uma tecla de acesso específicas de thread chamando a função do Windows [RegisterHotKey](http://msdn.microsoft.com/library/windows/desktop/ms646309).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)   
 [Controles](../mfc/controls-mfc.md)

