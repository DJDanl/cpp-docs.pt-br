---
title: Configurações do CStatusBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- status bar controls [MFC], settings
- CStatusBarCtrl class [MFC], settings
ms.assetid: adeba0c3-17f3-435c-b140-a57845e9ce49
ms.openlocfilehash: dd7c68d6721c48f751c04437e43c8770f6ec5736
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365374"
---
# <a name="settings-for-the-cstatusbarctrl"></a>Configurações do CStatusBarCtrl

A posição padrão de uma janela de status [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) está ao longo da parte inferior da janela pai, mas você pode especificar o estilo CCS_TOP para que ele apareça na parte superior da área cliente da janela pai.

Você pode especificar o estilo SBARS_SIZEGRIP para incluir um `CStatusBarCtrl` aperto de tamanho na extremidade direita da janela de status. Um aperto de tamanho é semelhante a uma borda de tamanho; é uma área retangular que o usuário pode clicar e arrastar para redimensionar a janela pai.

> [!NOTE]
> Se você combinar os estilos CCS_TOP e SBARS_SIZEGRIP, o aperto de tamanho resultante não é funcional, mesmo que o sistema o desenre na janela de status.

O procedimento de janela para a janela de status define automaticamente o tamanho e a posição inicial da janela de controle. A largura é a mesma da área cliente da janela pai. A altura é baseada nas métricas da fonte atualmente selecionada no contexto do dispositivo da janela de status e na largura das bordas da janela.

O procedimento da janela ajusta automaticamente o tamanho da janela de status sempre que recebe uma mensagem WM_SIZE. Normalmente, quando o tamanho da janela pai muda, o pai envia uma mensagem WM_SIZE para a janela de status.

Você pode definir a altura mínima da área de desenho de uma janela de status chamando [SetMinHeight](../mfc/reference/cstatusbarctrl-class.md#setminheight), especificando a altura mínima em pixels. A área de desenho não inclui as bordas da janela.

Você recupera as larguras das bordas de uma janela de status chamando [GetBorders](../mfc/reference/cstatusbarctrl-class.md#getborders). Esta função de membro inclui o ponteiro para uma matriz de três elementos que recebe a largura da borda horizontal, a borda vertical e a borda entre retângulos.

## <a name="see-also"></a>Confira também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
