---
title: Configurações do CStatusBarCtrl
ms.date: 11/04/2016
f1_keywords:
- CStatusBarCtrl
helpviewer_keywords:
- status bar controls [MFC], settings
- CStatusBarCtrl class [MFC], settings
ms.assetid: adeba0c3-17f3-435c-b140-a57845e9ce49
ms.openlocfilehash: b41997fb9342a651260bc2196d212016dc0deb7e
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62307686"
---
# <a name="settings-for-the-cstatusbarctrl"></a>Configurações do CStatusBarCtrl

A posição padrão de um [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) é de janela de status na parte inferior da janela pai, mas você pode especificar o estilo CCS_TOP para que ele apareça na parte superior da área de cliente da janela pai.

Você pode especificar o estilo SBARS_SIZEGRIP para incluir uma alça de dimensionamento na extremidade direita do `CStatusBarCtrl` janela de status. Uma alça de dimensionamento é semelhante a uma borda de dimensionamento; é uma área retangular que o usuário possa clicar e arrastar para redimensionar a janela pai.

> [!NOTE]
>  Se você combinar os estilos CCS_TOP e SBARS_SIZEGRIP, a alça de dimensionamento resultante não é funcional, embora o sistema desenha na janela de status.

O procedimento de janela para a janela de status define automaticamente o tamanho inicial e a posição da janela de controle. A largura é o mesmo da área de cliente da janela pai. A altura é baseada nas métricas da fonte selecionada no momento no contexto de dispositivo da janela de status e na largura das bordas da janela.

O procedimento de janela automaticamente ajusta o tamanho da janela de status sempre que receber uma mensagem WM_SIZE. Normalmente, quando o tamanho da janela pai for alterado, o pai envia uma mensagem WM_SIZE para a janela de status.

Você pode definir a altura mínima da área de desenho de uma janela de status chamando [SetMinHeight](../mfc/reference/cstatusbarctrl-class.md#setminheight), especificando a altura mínima, em pixels. A área de desenho não incluem bordas da janela.

Recuperar as larguras das bordas de uma janela de status, chamando [GetBorders](../mfc/reference/cstatusbarctrl-class.md#getborders). Essa função membro inclui o ponteiro para uma matriz de três elementos que recebe a largura da borda horizontal, a borda vertical e a borda entre os retângulos.

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
