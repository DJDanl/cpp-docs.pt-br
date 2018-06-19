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
ms.openlocfilehash: 96b559fcda4825aec71ba4b5c1dd8c3cd319b83d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33380091"
---
# <a name="spin-button-styles"></a>Estilos de botão Girar
Muitas das configurações para um botão de rotação ([CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)) são controladas por estilos. Você pode definir os seguintes estilos usando o **propriedades** janela no editor de caixa de diálogo.  
  
-   **Orientação** Vertical ou Horizontal. Controla a orientação dos botões de seta. Associado a `UDS_HORZ` estilo.  
  
-   **Alinhamento** desanexado, esquerda ou direita. Controla o local do botão de rotação. Left e Right posicionar o botão de rotação ao lado da janela buddy. A largura da janela buddy é reduzida para acomodar o botão de rotação. Associado a `UDS_ALIGNLEFT` e `UDS_ALIGNRIGHT` estilos.  
  
-   **Auto Buddy** seleciona automaticamente a janela anterior na ordem Z como a janela buddy para o botão de rotação. Em um modelo de caixa de diálogo, este é o controle que precede o botão de rotação na ordem de tabulação. Associado a `UDS_AUTOBUDDY` estilo.  
  
-   **Definir inteiro Buddy** faz com que o controle de rotação incrementar e decrementar a legenda da janela buddy como as alterações na posição atual. Associado a `UDS_SETBUDDYINT` estilo.  
  
-   **Sem milhares** não insere milhares separador no valor na legenda da janela buddy. Associado a `UDS_NOTHOUSANDS` estilo.  
  
    > [!NOTE]
    >  Se você quiser usar a troca de dados de caixa de diálogo (DDX) para obter o valor inteiro do controle buddy, defina esse estilo. `DDX_Text` não aceita incorporados separadores de milhar.  
  
-   **Encapsular** faz com que a posição "encapsular" como o valor for incrementada ou diminuído além do intervalo do controle. Associado a `UDS_WRAP` estilo.  
  
-   **Teclas de direção** faz com que o botão de rotação incrementar ou decrementar a posição quando as teclas de seta para cima e seta para baixo forem pressionadas. Associado a `UDS_ARROWKEYS` estilo.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CSpinButtonCtrl](../mfc/using-cspinbuttonctrl.md)   
 [Controles](../mfc/controls-mfc.md)

