---
title: Estrutura WINDOWPOS
ms.date: 11/04/2016
f1_keywords:
- WINDOWPOS
helpviewer_keywords:
- WINDOWPOS structure [MFC]
ms.assetid: a4ea7cd9-c4c2-4480-9c55-cbbff72195e1
ms.openlocfilehash: 16d9122a4141d2516118304fcdb4dd1b8fc14421
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50439423"
---
# <a name="windowpos-structure"></a>Estrutura WINDOWPOS

O `WINDOWPOS` estrutura contém informações sobre o tamanho e a posição de uma janela.

## <a name="syntax"></a>Sintaxe

```
typedef struct tagWINDOWPOS { /* wp */
    HWND hwnd;
    HWND hwndInsertAfter;
    int x;
    int y;
    int cx;
    int cy;
    UINT flags;
} WINDOWPOS;
```

#### <a name="parameters"></a>Parâmetros

*HWND*<br/>
Identifica a janela.

*hwndInsertAfter*<br/>
Identifica a janela atrás da qual esta janela é colocada.

*x*<br/>
Especifica a posição da borda esquerda da janela.

*y*<br/>
Especifica a posição da borda direita da janela.

*CX*<br/>
Especifica a largura da janela, em pixels.

*Cy*<br/>
Especifica a altura da janela, em pixels.

*flags*<br/>
Especifica as opções de posicionamento de janela. Esse membro pode ser um dos seguintes valores:

- SWP_DRAWFRAME desenha um quadro (definido na descrição da classe da janela) ao redor da janela. A janela recebe uma mensagem WM_NCCALCSIZE.

- Um WM_NCCALCSIZE SWP_FRAMECHANGED envia mensagens para a janela, mesmo se o tamanho da janela não está sendo alterado. Se este sinalizador não for especificado, WM_NCCALCSIZE é enviada somente quando o tamanho da janela está sendo alterado.

- SWP_HIDEWINDOW oculta a janela.

- SWP_NOACTIVATE não ativa a janela.

- SWP_NOCOPYBITS descartará todo o conteúdo da área de cliente. Se este sinalizador não for especificado, o conteúdo válido da área de cliente é salvos e copiado de volta para a área de cliente depois que a janela é dimensionada ou reposicionada.

- SWP_NOMOVE retém a posição atual (ignora a `x` e `y` membros).

- SWP_NOOWNERZORDER não altera a posição da janela do proprietário na ordem Z.

- Tamanho atual SWP_NOSIZE retém (ignora a `cx` e `cy` membros).

- SWP_NOREDRAW não atualiza as alterações.

- SWP_NOREPOSITION mesmo que SWP_NOOWNERZORDER.

- SWP_NOSENDCHANGING impede que a janela de recebimento da mensagem WM_WINDOWPOSCHANGING.

- Retém SWP_NOZORDER ordenação atual (ignora a `hwndInsertAfter` membro).

- SWP_SHOWWINDOW exibe a janela.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CWnd::OnWindowPosChanging](../../mfc/reference/cwnd-class.md#onwindowposchanging)

