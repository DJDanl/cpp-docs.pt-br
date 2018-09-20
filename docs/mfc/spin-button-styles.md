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
ms.openlocfilehash: 71da44858ea018d0393af6267e4bb522a2c57391
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393588"
---
# <a name="spin-button-styles"></a>Estilos de botão Girar

Muitas das configurações para um botão de rotação ([CSpinButtonCtrl](../mfc/reference/cspinbuttonctrl-class.md)) são controladas por estilos. Você pode definir os seguintes estilos usando o **propriedades** janela no editor de caixa de diálogo.

- **Orientação** Vertical ou Horizontal. Controla a orientação dos botões de seta. Associado com o estilo UDS_HORZ.

- **Alinhamento** desconectados, à esquerda ou direita. Controla o local do botão de rotação. Left e Right posicionar o botão de rotação ao lado da janela buddy. A largura da janela buddy é reduzida para acomodar o botão de rotação. Associado com os estilos UDS_ALIGNLEFT e UDS_ALIGNRIGHT.

- **Auto Buddy** seleciona automaticamente a janela anterior na ordem Z como a janela buddy para o botão de rotação. Em um modelo de caixa de diálogo, esse é o controle que precede o botão de rotação na ordem de tabulação. Associado com o estilo UDS_AUTOBUDDY.

- **Definir inteiro Buddy** faz com que o controle de rotação incrementar e diminuir a legenda da janela buddy como as alterações na posição atual. Associado com o estilo UDS_SETBUDDYINT.

- **Sem milhares** não inserir os milhares separador no valor na legenda da janela buddy. Associado com o estilo UDS_NOTHOUSANDS.

    > [!NOTE]
    >  Defina esse estilo se você quiser usar a troca de dados de caixa de diálogo (DDX) para obter o valor inteiro do controle buddy. `DDX_Text` não aceita os separadores de milhar incorporados.

- **Encapsular** faz com que a posição "encapsular" como o valor é incrementado ou diminuído além do intervalo do controle. Associado com o estilo UDS_WRAP.

- **Teclas de direção** faz com que o botão de rotação incrementar ou decrementar a posição quando as teclas de seta para cima e seta para baixo são pressionadas. Associado com o estilo UDS_ARROWKEYS.

## <a name="see-also"></a>Consulte também

[Usando CSpinButtonCtrl](../mfc/using-cspinbuttonctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

