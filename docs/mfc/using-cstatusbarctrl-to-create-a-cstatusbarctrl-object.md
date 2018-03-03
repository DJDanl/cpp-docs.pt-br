---
title: Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CStatusBarCtrl
dev_langs:
- C++
helpviewer_keywords:
- status bar controls [MFC], creating
- CStatusBarCtrl class [MFC], creating
ms.assetid: 365c2b65-12de-49e6-9a2e-416c6ee10d60
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 94043fa3ff8dbbc68c91b8d621303ab4afe29877
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="using-cstatusbarctrl-to-create-a-cstatusbarctrl-object"></a>Usando CStatusBarCtrl para criar um objeto CStatusBarCtrl
Aqui está um exemplo de um uso típico de [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md):  
  
### <a name="to-use-a-status-bar-control-with-parts"></a>Para usar um controle de barra de status com partes  
  
1.  Construir o `CStatusBarCtrl` objeto.  
  
2.  Chamar [SetMinHeight](../mfc/reference/cstatusbarctrl-class.md#setminheight) se você deseja definir a altura mínima do controle de barra de status da área de desenho.  
  
3.  Chamar [SetBkColor](../mfc/reference/cstatusbarctrl-class.md#setbkcolor) para definir a cor de plano de fundo do controle de barra de status.  
  
4.  Chamar [SetParts](../mfc/reference/cstatusbarctrl-class.md#setparts) para definir o número de partes em uma barra de controle e a coordenada da borda direita de cada parte de status.  
  
5.  Chamar [SetText](../mfc/reference/cstatusbarctrl-class.md#settext) para definir o texto em uma determinada parte do controle da barra de status. A mensagem invalida a parte do controle que foi alterada, fazendo com que ele exibir o novo texto quando o controle recebe lado a `WM_PAINT` mensagem.  
  
 Em alguns casos, a barra de status só precisa exibir uma linha de texto. Nesse caso, fazer uma chamada para [SetSimple](../mfc/reference/cstatusbarctrl-class.md#setsimple). Isso coloca o controle de barra de status no modo "simple", que exibe uma única linha de texto.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)   
 [Controles](../mfc/controls-mfc.md)

