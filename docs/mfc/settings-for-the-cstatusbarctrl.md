---
title: Configurações do CStatusBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- status bar controls [MFC], settings
- CStatusBarCtrl class [MFC], settings
ms.assetid: adeba0c3-17f3-435c-b140-a57845e9ce49
ms.openlocfilehash: 18c4c780ecf7865d8d648bfa4c54961bbffe7b18
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446391"
---
# <a name="settings-for-the-cstatusbarctrl"></a>Configurações do CStatusBarCtrl

A posição padrão de uma janela de status [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md) está ao longo da parte inferior da janela pai, mas você pode especificar o estilo de CCS_TOP para que ele apareça na parte superior da área do cliente da janela pai.

Você pode especificar o estilo de SBARS_SIZEGRIP para incluir uma alça de dimensionamento na extremidade direita da janela de status de `CStatusBarCtrl`. Uma alça de dimensionamento é semelhante a uma borda de dimensionamento; é uma área retangular que o usuário pode clicar e arrastar para redimensionar a janela pai.

> [!NOTE]
>  Se você combinar os estilos de CCS_TOP e de SBARS_SIZEGRIP, a alça de dimensionamento resultante não será funcional, mesmo que o sistema o desenhe na janela de status.

O procedimento de janela para a janela de status define automaticamente o tamanho inicial e a posição da janela de controle. A largura é a mesma da área cliente da janela pai. A altura se baseia nas métricas da fonte selecionada no momento no contexto do dispositivo da janela de status e na largura das bordas da janela.

O procedimento de janela ajusta automaticamente o tamanho da janela de status sempre que recebe uma mensagem de WM_SIZE. Normalmente, quando o tamanho da janela pai é alterado, o pai envia uma mensagem de WM_SIZE para a janela de status.

Você pode definir a altura mínima da área de desenho de uma janela de status chamando [SetMinHeight](../mfc/reference/cstatusbarctrl-class.md#setminheight), especificando a altura mínima em pixels. A área de desenho não inclui as bordas da janela.

Você recupera as larguras das bordas de uma janela de status chamando [GetBorders](../mfc/reference/cstatusbarctrl-class.md#getborders). Essa função de membro inclui o ponteiro para uma matriz de três elementos que recebe a largura da borda horizontal, a borda vertical e a borda entre retângulos.

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
