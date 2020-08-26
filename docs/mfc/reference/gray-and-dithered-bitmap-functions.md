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
ms.openlocfilehash: 57f163fd36c0f25508d94a84495fcaf1956e277d
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837197"
---
# <a name="gray-and-dithered-bitmap-functions"></a>Funções de bitmap cinza e pontilhado

**Funções de bitmap cinza**

O MFC fornece duas funções para dar a um bitmap a aparência de um controle desabilitado.

![Comparação de versões de ícones cinza e original](../../mfc/reference/media/vcgraybitmap.gif "Comparação de versões de ícones cinza e original")

|Nome|Descrição|
|-|-|
|[AfxDrawGrayBitmap](#afxdrawgraybitmap)|Desenha uma versão cinza de um bitmap.|
|[AfxGetGrayBitmap](#afxgetgraybitmap)|Copia uma versão cinza de um bitmap.|

**Funções de bitmap de diexistência**

O MFC também fornece duas funções para substituir o plano de fundo de um bitmap por um padrão pontilhado.

![Comparação de versões de ícone de diversão e originais](../../mfc/reference/media/vcditheredbitmap.gif "Comparação de versões de ícone de diversão e originais")

|Nome|Descrição|
|-|-|
|[AfxDrawDitheredBitmap](#afxdrawditheredbitmap)|Desenha um bitmap com um plano de fundo diexistente.|
|[AfxGetDitheredBitmap](#afxgetditheredbitmap)|Copia um bitmap com um plano de fundo diexistente.|

## <a name="afxdrawgraybitmap"></a><a name="afxdrawgraybitmap"></a> AfxDrawGrayBitmap

Desenha uma versão cinza de um bitmap.

```cpp
void AFXAPI AfxDrawGrayBitmap(
    CDC* pDC,
    int x,
    int y,
    const CBitmap& rSrc,
    COLORREF crBackground);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
Aponta para o DC de destino.

*x*<br/>
A coordenada x-de destino.

*y*<br/>
A coordenada y de destino.

*rSrc*<br/>
O bitmap de origem.

*crBackground*<br/>
A nova cor do plano de fundo (normalmente cinza, como COLOR_MENU).

### <a name="remarks"></a>Comentários

Um bitmap desenhado com `AfxDrawGrayBitmap` o terá a aparência de um controle desabilitado.

![Comparação de versões de ícones cinza e original](../../mfc/reference/media/vcgraybitmap.gif "Comparação de versões de ícones cinza e original")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#191](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_1.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="afxgetgraybitmap"></a><a name="afxgetgraybitmap"></a> AfxGetGrayBitmap

Copia uma versão cinza de um bitmap.

```cpp
void AFXAPI AfxGetGrayBitmap(
    const CBitmap& rSrc,
    CBitmap* pDest,
    COLORREF crBackground);
```

### <a name="parameters"></a>parâmetros

*rSrc*<br/>
O bitmap de origem.

*pDest*<br/>
O bitmap de destino.

*crBackground*<br/>
A nova cor do plano de fundo (normalmente cinza, como COLOR_MENU).

### <a name="remarks"></a>Comentários

Um bitmap copiado com `AfxGetGrayBitmap` terá a aparência de um controle desabilitado.

![Comparação de versões de ícones cinza e original](../../mfc/reference/media/vcgraybitmap.gif "Comparação de versões de ícones cinza e original")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#193](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_2.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="afxdrawditheredbitmap"></a><a name="afxdrawditheredbitmap"></a> AfxDrawDitheredBitmap

Desenha um bitmap, substituindo seu plano de fundo por um padrão de direspectiva (pedra).

```cpp
void AFXAPI AfxDrawDitheredBitmap(
    CDC* pDC,
    int x,
    int y,
    const CBitmap& rSrc,
    COLORREF cr1  ,
    COLORREF cr2);
```

### <a name="parameters"></a>parâmetros

*Primário*<br/>
Aponta para o DC de destino.

*x*<br/>
A coordenada x-de destino.

*y*<br/>
A coordenada y de destino.

*rSrc*<br/>
O bitmap de origem.

*cr1*<br/>
Uma das duas cores de pontilhamento, normalmente em branco.

*cr2*<br/>
A outra cor de pontilhamento, normalmente cinza claro (COLOR_MENU).

### <a name="remarks"></a>Comentários

O bitmap de origem é desenhado no DC de destino com um padrão quadriculado de duas cores (*cr1* e *CR2*), substituindo o plano de fundo do bitmap. O plano de fundo do bitmap de origem é definido como seus pixels brancos e todos os pixels que correspondem à cor do pixel no canto superior esquerdo do bitmap.

![Comparação de versões de ícone de diversão e originais](../../mfc/reference/media/vcditheredbitmap.gif "Comparação de versões de ícone de diversão e originais")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#190](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_3.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="afxgetditheredbitmap"></a><a name="afxgetditheredbitmap"></a> AfxGetDitheredBitmap

Copia um bitmap, substituindo seu plano de fundo por um padrão de direspectiva (pedra).

```cpp
void AFXAPI AfxGetDitheredBitmap(
    const CBitmap& rSrc,
    CBitmap* pDest,
    COLORREF cr1  ,
    COLORREF cr2);
```

### <a name="parameters"></a>parâmetros

*rSrc*<br/>
O bitmap de origem.

*pDest*<br/>
O bitmap de destino.

*cr1*<br/>
Uma das duas cores de pontilhamento, normalmente em branco.

*cr2*<br/>
A outra cor de pontilhamento, normalmente cinza claro (COLOR_MENU).

### <a name="remarks"></a>Comentários

O bitmap de origem é copiado para o bitmap de destino com um padrão quadriculado de duas cores (*cr1* e *CR2*), substituindo o plano de fundo do bitmap de origem. O plano de fundo do bitmap de origem é definido como seus pixels brancos e todos os pixels que correspondem à cor do pixel no canto superior esquerdo do bitmap.

![Comparação de versões de ícone de diversão e originais](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#192](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
