---
title: Funções de bitmap cinza e pontilhado
ms.date: 11/19/2018
f1_keywords:
- AFXWIN/AfxDrawGrayBitmap
- AFXWIN/AfxGetGrayBitmap
- AFXWIN/AfxDrawDitheredBitmap
- AFXWIN/AfxGetDitheredBitmap
helpviewer_keywords:
- gray and dithered bitmap functions [MFC]
ms.assetid: cb139a77-b85e-4504-9d93-24156ad77a41
ms.openlocfilehash: bbc64aad0d65c0430ad23b96f635be8fe2b396e0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81357036"
---
# <a name="gray-and-dithered-bitmap-functions"></a>Funções de bitmap cinza e pontilhado

**Funções do bitmap cinza**

O MFC fornece duas funções para dar a um bitmap a aparência de um controle desativado.

![Comparação das versões de ícones cinza e original](../../mfc/reference/media/vcgraybitmap.gif "Comparação das versões de ícones cinza e original")

|||
|-|-|
|[AfxDrawGrayBitmap](#afxdrawgraybitmap)|Desenha uma versão cinza de um bitmap.|
|[AfxGetGrayBitmap](#afxgetgraybitmap)|Copia uma versão cinza de um bitmap.|

**Funções do Bitmap Dithered**

O MFC também fornece duas funções para substituir o fundo de um bitmap por um padrão dithered.

![Comparação das versões dithered e original do ícone](../../mfc/reference/media/vcditheredbitmap.gif "Comparação das versões dithered e original do ícone")

|||
|-|-|
|[AfxDrawDitheredBitmap](#afxdrawditheredbitmap)|Desenha um bitmap com um fundo dithered.|
|[AfxGetDitheredBitmap](#afxgetditheredbitmap)|Copia um bitmap com um fundo dithered.|

## <a name="afxdrawgraybitmap"></a><a name="afxdrawgraybitmap"></a>AfxDrawGrayBitmap

Desenha uma versão cinza de um bitmap.

```
void AFXAPI AfxDrawGrayBitmap(
    CDC* pDC,
    int x,
    int y,
    const CBitmap& rSrc,
    COLORREF crBackground);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o destino DC.

*x*<br/>
O destino x-coordenada.

*Y*<br/>
O destino y-coordenada.

*Rsrc*<br/>
O bitmap de origem.

*crBackground*<br/>
A nova cor de fundo (tipicamente cinza, como COLOR_MENU).

### <a name="remarks"></a>Comentários

Um bitmap `AfxDrawGrayBitmap` desenhado terá a aparência de um controle desativado.

![Comparação das versões de ícones cinza e original](../../mfc/reference/media/vcgraybitmap.gif "Comparação das versões de ícones cinza e original")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#191](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_1.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="afxgetgraybitmap"></a><a name="afxgetgraybitmap"></a>AfxGetGrayBitmap

Copia uma versão cinza de um bitmap.

```
void AFXAPI AfxGetGrayBitmap(
    const CBitmap& rSrc,
    CBitmap* pDest,
    COLORREF crBackground);
```

### <a name="parameters"></a>Parâmetros

*Rsrc*<br/>
O bitmap de origem.

*pDest*<br/>
O bitmap de destino.

*crBackground*<br/>
A nova cor de fundo (tipicamente cinza, como COLOR_MENU).

### <a name="remarks"></a>Comentários

Um bitmap copiado com `AfxGetGrayBitmap` terá a aparência de um controle desativado.

![Comparação das versões de ícones cinza e original](../../mfc/reference/media/vcgraybitmap.gif "Comparação das versões de ícones cinza e original")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#193](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_2.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="afxdrawditheredbitmap"></a><a name="afxdrawditheredbitmap"></a>AfxDrawDitheredBitmap

Desenha um bitmap, substituindo seu fundo por um padrão dithered (dac) .

```
void AFXAPI AfxDrawDitheredBitmap(
    CDC* pDC,
    int x,
    int y,
    const CBitmap& rSrc,
    COLORREF cr1  ,
    COLORREF cr2);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
Aponta para o destino DC.

*x*<br/>
O destino x-coordenada.

*Y*<br/>
O destino y-coordenada.

*Rsrc*<br/>
O bitmap de origem.

*cr1*<br/>
Uma das duas cores dither, tipicamente branca.

*cr2*<br/>
A outra cor dither, tipicamente cinza claro (COLOR_MENU).

### <a name="remarks"></a>Comentários

O bitmap de origem é desenhado no DC de destino com um padrão quadricolor *(cr1* e *cr2)* substituindo o plano de fundo do bitmap. O plano de fundo do bitmap de origem é definido como seus pixels brancos e todos os pixels que correspondem à cor do pixel no canto superior esquerdo do bitmap.

![Comparação das versões dithered e original do ícone](../../mfc/reference/media/vcditheredbitmap.gif "Comparação das versões dithered e original do ícone")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#190](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_3.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="afxgetditheredbitmap"></a><a name="afxgetditheredbitmap"></a>AfxGetDitheredBitmap

Copia um bitmap, substituindo seu plano de fundo por um padrão dithered (verificador).

```
void AFXAPI AfxGetDitheredBitmap(
    const CBitmap& rSrc,
    CBitmap* pDest,
    COLORREF cr1  ,
    COLORREF cr2);
```

### <a name="parameters"></a>Parâmetros

*Rsrc*<br/>
O bitmap de origem.

*pDest*<br/>
O bitmap de destino.

*cr1*<br/>
Uma das duas cores dither, tipicamente branca.

*cr2*<br/>
A outra cor dither, tipicamente cinza claro (COLOR_MENU).

### <a name="remarks"></a>Comentários

O bitmap de origem é copiado para o bitmap de destino com um padrão verificado de duas cores *(cr1* e *cr2)* substituindo o plano de fundo do bitmap de origem. O plano de fundo do bitmap de origem é definido como seus pixels brancos e todos os pixels que correspondem à cor do pixel no canto superior esquerdo do bitmap.

![Comparação das versões dithered e original do ícone](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#192](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
