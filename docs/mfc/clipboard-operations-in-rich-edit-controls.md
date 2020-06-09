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
ms.openlocfilehash: 3dea112ed32ae618991f6ff5f05823bd5be001b6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624855"
---
# <a name="clipboard-operations-in-rich-edit-controls"></a>Operações da Área de Transferência em controles de edição avançada

Seu aplicativo pode colar o conteúdo da área de transferência em um[CRichEditCtrl](reference/cricheditctrl-class.md)(controle de edição rico) usando o melhor formato de área de transferência disponível ou um formato de área de transferência específico. Você também pode determinar se um controle de edição rico é capaz de colar um formato de área de transferência.

Você pode copiar ou recortar o conteúdo da seleção atual usando a função [copiar](reference/cricheditctrl-class.md#copy) ou [recortar](reference/cricheditctrl-class.md#cut) membro. Da mesma forma, você pode colar o conteúdo da área de transferência em um controle de edição rico usando a função [colar](reference/cricheditctrl-class.md#paste) membro. O controle cola o primeiro formato disponível que ele reconhece, o que presumivelmente é o formato mais descritivo.

Para colar um formato de área de transferência específico, você pode usar a função de membro [PasteSpecial](reference/cricheditctrl-class.md#pastespecial) . Essa função é útil para aplicativos com um comando colar especial que permite ao usuário selecionar o formato da área de transferência. Você pode usar a função de membro [CanPaste](reference/cricheditctrl-class.md#canpaste) para determinar se um determinado formato é reconhecido pelo controle.

Você também pode usar `CanPaste` para determinar se qualquer formato de área de transferência disponível é reconhecido por um controle de edição rico. Essa função é útil no `OnInitMenuPopup` manipulador. Um aplicativo pode habilitar ou cinza o comando Paste, dependendo se o controle pode colar qualquer formato disponível.

Os controles de edição avançados registram dois formatos de área de transferência: Rich-Text Format e um formato chamado texto RichEdit e objetos. Um aplicativo pode registrar esses formatos usando a função [RegisterClipboardFormat](/windows/win32/api/winuser/nf-winuser-registerclipboardformatw) , especificando os valores de **CF_RTF** e **CF_RETEXTOBJ** .

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](using-cricheditctrl.md)<br/>
[Controles](controls-mfc.md)
