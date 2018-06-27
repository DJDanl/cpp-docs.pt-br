---
title: Estilos de botão Girar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- styles [MFC], CSpinButtonCtrl
- CSpinButtonCtrl class [MFC], styles
- styles [MFC], spin button control
- spin button control, styles
ms.assetid: fb4a7f6f-9182-47be-bccf-0728fdc5332f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 223b7e0875a5382edf5f4d350c9343d117768c41
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36953772"
---
# <a name="spin-button-styles"></a>Estilos de botão Girar
Muitas das configurações para um botão de rotação ([CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)) são controladas por estilos. Você pode definir os seguintes estilos usando o **propriedades** janela no editor de caixa de diálogo.  
  
-   **Orientação** Vertical ou Horizontal. Controla a orientação dos botões de seta. Associado com o estilo UDS_HORZ.  
  
-   **Alinhamento** desanexado, esquerda ou direita. Controla o local do botão de rotação. Left e Right posicionar o botão de rotação ao lado da janela buddy. A largura da janela buddy é reduzida para acomodar o botão de rotação. Associados com os estilos UDS_ALIGNLEFT e UDS_ALIGNRIGHT.  
  
-   **Auto Buddy** seleciona automaticamente a janela anterior na ordem Z como a janela buddy para o botão de rotação. Em um modelo de caixa de diálogo, este é o controle que precede o botão de rotação na ordem de tabulação. Associado com o estilo UDS_AUTOBUDDY.  
  
-   **Definir inteiro Buddy** faz com que o controle de rotação incrementar e decrementar a legenda da janela buddy como as alterações na posição atual. Associado com o estilo UDS_SETBUDDYINT.  
  
-   **Sem milhares** não insere milhares separador no valor na legenda da janela buddy. Associado com o estilo UDS_NOTHOUSANDS.  
  
    > [!NOTE]
    >  Se você quiser usar a troca de dados de caixa de diálogo (DDX) para obter o valor inteiro do controle buddy, defina esse estilo. `DDX_Text` não aceita incorporados separadores de milhar.  
  
-   **Encapsular** faz com que a posição "encapsular" como o valor for incrementada ou diminuído além do intervalo do controle. Associado com o estilo UDS_WRAP.  
  
-   **Teclas de direção** faz com que o botão de rotação incrementar ou decrementar a posição quando as teclas de seta para cima e seta para baixo forem pressionadas. Associado com o estilo UDS_ARROWKEYS.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CSpinButtonCtrl](../mfc/using-cspinbuttonctrl.md)   
 [Controles](../mfc/controls-mfc.md)

