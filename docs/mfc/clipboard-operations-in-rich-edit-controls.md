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
ms.openlocfilehash: 882c589d0d25b54650affa7fd41f916ecf6097d5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62327100"
---
# <a name="clipboard-operations-in-rich-edit-controls"></a>Operações da Área de Transferência em controles de edição avançada

Seu aplicativo pode colar o conteúdo da área de transferência em um controle rich edit ([CRichEditCtrl](../mfc/reference/cricheditctrl-class.md)) usando o formato de área de transferência melhor disponível ou em um formato específico da área de transferência. Você também pode determinar se um controle rich edit é capaz de colando um formato de área de transferência.

É possível copiar ou recortar o conteúdo da seleção atual, usando o [cópia](../mfc/reference/cricheditctrl-class.md#copy) ou [Recortar](../mfc/reference/cricheditctrl-class.md#cut) função de membro. Da mesma forma, você pode colar o conteúdo da área de transferência em um controle rich edit usando o [colar](../mfc/reference/cricheditctrl-class.md#paste) função de membro. O controle cola o primeiro formato disponível que ele reconhece que provavelmente é o formato mais descritivo.

Para colar um formato específico da área de transferência, você pode usar o [PasteSpecial](../mfc/reference/cricheditctrl-class.md#pastespecial) função de membro. Essa função é útil para aplicativos com um comando Colar especial que permite ao usuário selecionar o formato de área de transferência. Você pode usar o [CanPaste](../mfc/reference/cricheditctrl-class.md#canpaste) função de membro para determinar se um determinado formato é reconhecido pelo controle.

Você também pode usar `CanPaste` para determinar se qualquer formato de área de transferência disponível é reconhecido por um controle rich edit. Essa função é útil para o `OnInitMenuPopup` manipulador. Um aplicativo pode habilitar ou cinza seu comando Colar, dependendo se o controle pode colar qualquer formato disponível.

Formatos Registre-se na área de transferência dois controles edição rica: formato rich text e um formato chamado RichEdit texto e objetos. Um aplicativo pode registrar esses formatos usando o [RegisterClipboardFormat](/windows/desktop/api/winuser/nf-winuser-registerclipboardformata) funcionar, especificando as **CF_RTF** e **CF_RETEXTOBJ** valores.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
