---
title: Estrutura TOOLTIPTEXT
ms.date: 11/04/2016
f1_keywords:
- TOOLTIPTEXT
helpviewer_keywords:
- TOOLTIPTEXT structure [MFC]
- tool tips [MFC], notifications
ms.assetid: 547591bf-80f5-400e-a2a7-0708cfffbb5d
ms.openlocfilehash: 80b95225a277a7985c30e5ea453597b06e501753
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513313"
---
# <a name="tooltiptext-structure"></a>Estrutura TOOLTIPTEXT

Ao escrever seu [manipulador de notificação de dica de ferramenta](../mfc/handling-ttn-needtext-notification-for-tool-tips.md), você precisa usar a estrutura **ToolTipText** . Os membros da estrutura **ToolTipText** são:

```cpp
typedef struct {
    NMHDR     hdr;        // required for all WM_NOTIFY messages
    LPTSTR    lpszText;   // see below
    TCHAR     szText[80]; // buffer for tool tip text
    HINSTANCE hinst;      // see below
    UINT      uflags;     // flag indicating how to interpret the
                          // idFrom member of the NMHDR structure
                          // that is included in the structure
} TOOLTIPTEXT, FAR *LPTOOLTIPTEXT;
```

*hdr*<br/>
Identifica a ferramenta que precisa de texto. O único membro dessa estrutura que você pode precisar é a ID de comando do controle. A ID de comando do controle estará no membro *idFrom* da estrutura **NMHDR** , acessada com a sintaxe `hdr.idFrom`. Consulte [NMHDR](/windows/win32/api/richedit/ns-richedit-nmhdr) para obter uma discussão dos membros da estrutura **NMHDR** .

*lpszText*<br/>
Endereço de uma cadeia de caracteres para receber o texto de uma ferramenta.

*szText*<br/>
Buffer que recebe o texto da dica de ferramenta. Um aplicativo pode copiar o texto para esse buffer como uma alternativa para especificar um endereço de cadeia de caracteres.

*hinst*<br/>
Identificador da instância do que contém uma cadeia de caracteres a ser usada como texto da dica de ferramenta. Se *lpszText* for o endereço do texto da dica de ferramenta, esse membro será nulo.

Ao manipular a `TTN_NEEDTEXT` mensagem de notificação, especifique a cadeia de caracteres a ser exibida de uma das seguintes maneiras:

- Copie o texto para o buffer especificado pelo membro *szText* .

- Copie o endereço do buffer que contém o texto para o membro *lpszText* .

- Copie o identificador de um recurso de cadeia de caracteres para o membro *lpszText* e copie o identificador da instância que contém o recurso para o membro *hinst* .

## <a name="see-also"></a>Consulte também

[Dicas de ferramenta no Windows não derivadas de CFrameWnd](../mfc/tool-tips-in-windows-not-derived-from-cframewnd.md)
