---
title: Estilos de botão Girar
ms.date: 09/09/2019
helpviewer_keywords:
- styles [MFC], CSpinButtonCtrl
- CSpinButtonCtrl class [MFC], styles
- styles [MFC], spin button control
- spin button control, styles
ms.assetid: fb4a7f6f-9182-47be-bccf-0728fdc5332f
ms.openlocfilehash: 1aae4b7e4c63929ebe03c97d50f05754bc13ec26
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907854"
---
# <a name="spin-button-styles"></a>Estilos de botão Girar

Muitas das configurações de um botão de rotação ([CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)) são controladas por estilos. Você pode definir os seguintes estilos usando o [Assistente de classe](reference/mfc-class-wizard.md).

- **Orientação** do Vertical ou horizontal. Controla a orientação dos botões de seta. Associado ao estilo UDS_HORZ.

- **Alinhamento** Um dos não anexados, esquerdo ou direito. Controla o local do botão de rotação. Posição esquerda e direita do botão de rotação ao lado da janela do Buddy. A largura da janela Buddy é diminuída para acomodar o botão de rotação. Associados aos estilos UDS_ALIGNLEFT e UDS_ALIGNRIGHT.

- **Amigo automático** Seleciona automaticamente a janela anterior na ordem Z como uma janela de amigo para o botão de rotação. Em um modelo de caixa de diálogo, esse é o controle que precede o botão de rotação na ordem de tabulação. Associado ao estilo UDS_AUTOBUDDY.

- **Definir o inteiro Buddy** Faz com que o controle de rotação aumente e reduza a legenda da janela Buddy à medida que a posição atual é alterada. Associado ao estilo UDS_SETBUDDYINT.

- **Sem milhares** Não insere o separador de milhar no valor da legenda da janela Buddy. Associado ao estilo UDS_NOTHOUSANDS.

    > [!NOTE]
    >  Defina este estilo se quiser usar a troca de dados de caixa de diálogo (campo DDX) para obter o valor inteiro do controle Buddy. `DDX_Text`Não aceita separadores de milhar incorporados.

- **Encapsular** Faz com que a posição seja "encapsulada" à medida que o valor é incrementado ou diminuído além do intervalo do controle. Associado ao estilo UDS_WRAP.

- **Teclas de direção** Faz com que o botão de rotação aumente ou diminua a posição quando as teclas seta para cima e seta para baixo são pressionadas. Associado ao estilo UDS_ARROWKEYS.

## <a name="see-also"></a>Consulte também

[Usando CSpinButtonCtrl](../mfc/using-cspinbuttonctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
