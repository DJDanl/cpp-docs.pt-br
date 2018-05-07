---
title: Imprimindo em controles de edição avançada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- printing [MFC], CRichEditCtrl
- rich edit controls [MFC], printing
- CRichEditCtrl class [MFC], printing
ms.assetid: dbda0e40-018f-424e-b5d8-7b489aaf27af
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 23b958e6c770260082af069544480102f6d79926
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="printing-in-rich-edit-controls"></a>Imprimindo em controles de edição avançada
Você pode ver o controle de edição de um conjunto avançado ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) para processar sua saída para um determinado dispositivo, como uma impressora. Você também pode especificar o dispositivo de saída para o qual um conjunto avançado do controle de edição formata seu texto.  
  
 Para formatar uma parte do conteúdo de um controle de edição para um dispositivo específico, você pode usar o [FormatRange](../mfc/reference/cricheditctrl-class.md#formatrange) função de membro. O [FORMATRANGE](http://msdn.microsoft.com/library/windows/desktop/bb787911) estrutura usada com esta função especifica o intervalo de texto para formatar, bem como o contexto de dispositivo (DC) para o dispositivo de destino.  
  
 Após a formatação de texto para um dispositivo de saída, você pode enviar a saída para o dispositivo usando o [DisplayBand](../mfc/reference/cricheditctrl-class.md#displayband) função de membro. Usando repetidamente `FormatRange` e `DisplayBand`, um aplicativo que imprime o conteúdo de um controle rich edit pode implementar a faixa. (Faixa é divisão de saída em partes menores para fins de impressão.)  
  
 Você pode usar o [SetTargetDevice](../mfc/reference/cricheditctrl-class.md#settargetdevice) a função de membro para especificar o dispositivo de destino para o qual um conjunto avançado do controle de edição formata seu texto. Essa função é útil para WYSIWYG (o que você vê é o que você obterá) formatação, em que um aplicativo posiciona o texto usando métricas de fonte da impressora padrão em vez da tela.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)   
 [Controles](../mfc/controls-mfc.md)

