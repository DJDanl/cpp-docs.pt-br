---
title: Estrutura WINDOWPOS 1 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- WINDOWPOS
dev_langs:
- C++
helpviewer_keywords:
- WINDOWPOS structure [MFC]
ms.assetid: a4ea7cd9-c4c2-4480-9c55-cbbff72195e1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d4abd236998f37f0d719f41827d05a17fde56fde
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33379288"
---
# <a name="windowpos-structure1"></a>Estrutura WINDOWPOS 1
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
 *HWND*  
 Identifica a janela.  
  
 *hwndInsertAfter*  
 Identifica a janela ao qual esta janela é colocada.  
  
 *x*  
 Especifica a posição da borda esquerda da janela.  
  
 *y*  
 Especifica a posição da borda direita da janela.  
  
 `cx`  
 Especifica a largura da janela, em pixels.  
  
 `cy`  
 Especifica a altura da janela, em pixels.  
  
 `flags`  
 Especifica as opções de posicionamento de janela. Esse membro pode ser um dos seguintes valores:  
  
- **SWP_DRAWFRAME** desenha um quadro (definido na descrição de classe para a janela) em torno de janela. A janela recebe um `WM_NCCALCSIZE` mensagem.  
  
- **SWP_FRAMECHANGED** envia um `WM_NCCALCSIZE` de mensagem para a janela, mesmo se o tamanho da janela não está sendo alterado. Se este sinalizador não for especificado, `WM_NCCALCSIZE` só é enviado quando o tamanho da janela está sendo alterado.  
  
- **SWP_HIDEWINDOW** oculta a janela.  
  
- `SWP_NOACTIVATE` Não ative a janela.  
  
- **SWP_NOCOPYBITS** descartará todo o conteúdo da área do cliente. Se este sinalizador não for especificado, o conteúdo válido da área do cliente é salvas e copiado de volta para a área cliente depois que a janela é dimensionada ou reposicioná-los.  
  
- `SWP_NOMOVE` Retém a posição atual (ignora o **x** e **y** membros).  
  
- **SWP_NOOWNERZORDER** não altera a posição da janela do proprietário na ordem Z.  
  
- `SWP_NOSIZE` Mantém o tamanho atual (ignora o **cx** e **cy** membros).  
  
- **SWP_NOREDRAW** não atualiza as alterações.  
  
- **SWP_NOREPOSITION** igual **SWP_NOOWNERZORDER**.  
  
- **SWP_NOSENDCHANGING** impede que a janela de recebimento de `WM_WINDOWPOSCHANGING` mensagem.  
  
- `SWP_NOZORDER` Retém a ordenação atual (ignora o **hwndInsertAfter** membro).  
  
- **SWP_SHOWWINDOW** exibe a janela.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** WinUser  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CWnd::OnWindowPosChanging](../../mfc/reference/cwnd-class.md#onwindowposchanging)

