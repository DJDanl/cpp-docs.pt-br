---
title: Estrutura PAINTSTRUCT
ms.date: 11/04/2016
f1_keywords:
- PAINTSTRUCT
helpviewer_keywords:
- PAINTSTRUCT structure [MFC]
ms.assetid: 81ce4993-3e89-43b2-8c98-7946f1314d24
ms.openlocfilehash: f1b901ef26c61adbedb3bbe56808cd94bdfad30d
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51694641"
---
# <a name="paintstruct-structure"></a>Estrutura PAINTSTRUCT

O `PAINTSTRUCT` estrutura contém informações que podem ser usadas para pintar a área de cliente de uma janela.

## <a name="syntax"></a>Sintaxe

```
typedef struct tagPAINTSTRUCT {
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[16];
} PAINTSTRUCT;
```

#### <a name="parameters"></a>Parâmetros

*hDC*<br/>
Identifica o contexto de exibição a ser usado para pintura.

*fErase*<br/>
Especifica se o plano de fundo precisa ser redesenhado. Não é 0 se o aplicativo deve redesenhar a tela de fundo. O aplicativo é responsável por desenhar a tela de fundo se uma classe de janela do Windows é criada sem um pincel de plano de fundo (consulte a descrição do `hbrBackground` membro do [WNDCLASS](/windows/desktop/api/winuser/ns-winuser-tagwndclassa) estrutura no SDK do Windows).

*rcPaint*<br/>
Especifica o canto superior esquerdo e inferior direita cantos do retângulo no qual a pintura é solicitada.

*fRestore*<br/>
Membro reservado. Ele é usado internamente pelo Windows.

*fIncUpdate*<br/>
Membro reservado. Ele é usado internamente pelo Windows.

*rgbReserved [16]*<br/>
Membro reservado. Um bloco reservado de memória usada internamente pelo Windows.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** WinUser. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CPaintDC::m_ps](../../mfc/reference/cpaintdc-class.md#m_ps)

