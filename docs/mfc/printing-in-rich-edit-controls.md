---
title: Imprimindo em controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- printing [MFC], CRichEditCtrl
- rich edit controls [MFC], printing
- CRichEditCtrl class [MFC], printing
ms.assetid: dbda0e40-018f-424e-b5d8-7b489aaf27af
ms.openlocfilehash: bf402f5495ad85eb0c5067d60fcedfe29e6350bb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641201"
---
# <a name="printing-in-rich-edit-controls"></a>Imprimindo em controles de edição avançada

Você pode informar ao controle de edição de uma avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) para renderizar a saída para um dispositivo especificado, como uma impressora. Você também pode especificar o dispositivo de saída para a qual controle de edição de um avançado formata o texto.

Para formatar uma parte do conteúdo de um controle rich edit para um dispositivo específico, você pode usar o [FormatRange](../mfc/reference/cricheditctrl-class.md#formatrange) função de membro. O [FORMATRANGE](/windows/desktop/api/richedit/ns-richedit-_formatrange) estrutura usada com essa função especifica o intervalo de texto para formatar, bem como o contexto de dispositivo (DC) para o dispositivo de destino.

Após a formatação de texto para um dispositivo de saída, você pode enviar a saída para o dispositivo usando o [DisplayBand](../mfc/reference/cricheditctrl-class.md#displayband) função de membro. Usando repetidamente `FormatRange` e `DisplayBand`, um aplicativo que imprime o conteúdo de um controle rich edit pode implementar a faixa. (De faixa é a divisão de saída em partes menores para fins de impressão.)

Você pode usar o [SetTargetDevice](../mfc/reference/cricheditctrl-class.md#settargetdevice) a função de membro para especificar o dispositivo de destino para a qual controle de edição de um avançado formata o texto. Essa função é útil para WYSIWYG (o que você vê é o que você obtém) formatação, em que um aplicativo posiciona o texto usando métricas de fonte da impressora padrão em vez da tela.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

