---
title: Quebras de palavra em controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- CRichEditCtrl class [MFC], word breaks in
- word breaks
- breaking words in CRichEditCtrl
- rich edit controls [MFC], word breaks in
ms.assetid: 641dcf9e-7b40-4dc0-85f7-575a8c142f73
ms.openlocfilehash: e71643350ced5b8ecff7c8ac7829741cc3e8493b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399532"
---
# <a name="word-breaks-in-rich-edit-controls"></a>Quebras de palavra em controles de edição avançada

Controle de edição de uma avançada ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) chama uma função de chamada de "procedimento de quebra de palavra" para encontrar quebras entre as palavras e determinar onde ele pode quebrar a linha. O controle usa essas informações ao executar operações de quebra automática e ao processar as combinações de teclas CTRL + esquerda e CTRL + seta para direita. Um aplicativo pode enviar mensagens para um controle rich edit para substituir o procedimento de quebra de palavras do padrão, para recuperar informações de quebra de palavras e para determinar o que um determinado caractere de linha cai.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
