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
ms.openlocfilehash: 254d7532b83a4f30c0029b2488bb0b2111cce31d
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43219391"
---
# <a name="setting-a-hot-key"></a>Definindo uma tecla de acesso
Seu aplicativo pode usar as informações fornecidas por uma tecla de acesso ([CHotKeyCtrl](../mfc/reference/chotkeyctrl-class.md)) controle de uma das duas maneiras:  
  
-   Configurar uma tecla de acesso global para ativar uma janela nonchild enviando uma [WM_SETHOTKEY](/windows/desktop/inputdev/wm-sethotkey) mensagem para a janela a ser ativado.  
  
-   Configurar uma tecla de acesso específicas de thread chamando a função do Windows [RegisterHotKey](https://msdn.microsoft.com/library/windows/desktop/ms646309).  
  
## <a name="see-also"></a>Consulte também  
 [Usando CHotKeyCtrl](../mfc/using-chotkeyctrl.md)   
 [Controles](../mfc/controls-mfc.md)

