---
title: Operações da Área de Transferência em controles de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- pasting Clipboard data
- CRichEditCtrl class [MFC], paste operation
- cut operation in CRichEditCtrl class [MFC]
- CRichEditCtrl class [MFC], Clipboard operations
- copy operations in rich edit controls
- Clipboard, operations in CRichEditCtrl
- rich edit controls [MFC], Clipboard operations
ms.assetid: 15ce66bc-2636-4a35-a2ae-d52285dc1af6
ms.openlocfilehash: e232010b443ace245844f1c28649477cccc8e9e4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69508964"
---
# <a name="clipboard-operations-in-rich-edit-controls"></a>Operações da Área de Transferência em controles de edição avançada

Seu aplicativo pode colar o conteúdo da área de transferência em um[CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)(controle de edição rico) usando o melhor formato de área de transferência disponível ou um formato de área de transferência específico. Você também pode determinar se um controle de edição rico é capaz de colar um formato de área de transferência.

Você pode copiar ou recortar o conteúdo da seleção atual usando a função [copiar](../mfc/reference/cricheditctrl-class.md#copy) ou [recortar](../mfc/reference/cricheditctrl-class.md#cut) membro. Da mesma forma, você pode colar o conteúdo da área de transferência em um controle de edição rico usando a função [colar](../mfc/reference/cricheditctrl-class.md#paste) membro. O controle cola o primeiro formato disponível que ele reconhece, o que presumivelmente é o formato mais descritivo.

Para colar um formato de área de transferência específico, você pode usar a função de membro [PasteSpecial](../mfc/reference/cricheditctrl-class.md#pastespecial) . Essa função é útil para aplicativos com um comando colar especial que permite ao usuário selecionar o formato da área de transferência. Você pode usar a função de membro [CanPaste](../mfc/reference/cricheditctrl-class.md#canpaste) para determinar se um determinado formato é reconhecido pelo controle.

Você também pode usar `CanPaste` para determinar se qualquer formato de área de transferência disponível é reconhecido por um controle de edição rico. Essa função é útil no `OnInitMenuPopup` manipulador. Um aplicativo pode habilitar ou cinza o comando Paste, dependendo se o controle pode colar qualquer formato disponível.

Os controles de edição avançados registram dois formatos de área de transferência: Rich-Text Format e um formato chamado texto RichEdit e objetos. Um aplicativo pode registrar esses formatos usando a função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) , especificando os valores **CF_RTF** e **CF_RETEXTOBJ** .

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
