---
title: Imprimindo em controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- printing [MFC], CRichEditCtrl
- rich edit controls [MFC], printing
- CRichEditCtrl class [MFC], printing
ms.assetid: dbda0e40-018f-424e-b5d8-7b489aaf27af
ms.openlocfilehash: 671aec27584af975ce1635793ae80879e7208d4b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508006"
---
# <a name="printing-in-rich-edit-controls"></a>Imprimindo em controles de edição avançada

Você pode dizer a um[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)(controle de edição rico) para renderizar sua saída para um dispositivo especificado, como uma impressora. Você também pode especificar o dispositivo de saída para o qual um controle de edição rico formata seu texto.

Para formatar parte do conteúdo de um controle de edição rico para um dispositivo específico, você pode usar a função de membro [FORMATRANGE](../mfc/reference/cricheditctrl-class.md#formatrange) . A estrutura [FORMATRANGE](/windows/win32/api/richedit/ns-richedit-formatrange) usada com essa função especifica o intervalo de texto a ser formatado, bem como o contexto do dispositivo (DC) para o dispositivo de destino.

Depois de Formatar o texto de um dispositivo de saída, você pode enviar a saída para o dispositivo usando a função de membro [DisplayBand](../mfc/reference/cricheditctrl-class.md#displayband) . Ao usar `FormatRange` e `DisplayBand`, repetidamente, um aplicativo que imprime o conteúdo de um controle de edição rico pode implementar a faixa. (A faixa é a divisão da saída em partes menores para fins de impressão.)

Você pode usar a função de membro [SetTargetDevice](../mfc/reference/cricheditctrl-class.md#settargetdevice) para especificar o dispositivo de destino para o qual um controle de edição rico formata seu texto. Essa função é útil para a formatação WYSIWYG (o que você vê é o que você obtém), na qual um aplicativo posiciona o texto usando as métricas de fonte da impressora padrão em vez da tela.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
