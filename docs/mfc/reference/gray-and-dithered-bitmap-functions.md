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
ms.openlocfilehash: fb764dbd71d89ae3317816df3539c2881b9695b6
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57290772"
---
# <a name="gray-and-dithered-bitmap-functions"></a>Funções de bitmap cinza e pontilhado

**Funções de Bitmap cinza**

MFC fornece duas funções para fornecer um bitmap a aparência de um controle desabilitado.

![Comparação de versões de ícone cinza e originais](../../mfc/reference/media/vcgraybitmap.gif "comparação de versões de ícone cinza e original")

|||
|-|-|
|[AfxDrawGrayBitmap](#afxdrawgraybitmap)|Desenha uma versão de cinza de um bitmap.|
|[AfxGetGrayBitmap](#afxgetgraybitmap)|Copia uma versão de cinza de um bitmap.|

**Funções de Bitmap pontilhado**

MFC também fornece duas funções para substituir o plano de fundo de um bitmap com um padrão de pontilhado.

![Comparação de versões de ícone original e pontilhado](../../mfc/reference/media/vcditheredbitmap.gif "comparação de versões de ícone original e pontilhado")

|||
|-|-|
|[AfxDrawDitheredBitmap](#afxdrawditheredbitmap)|Desenha um bitmap com um plano de fundo pontilhado.|
|[AfxGetDitheredBitmap](#afxgetditheredbitmap)|Copia um bitmap com um plano de fundo pontilhado.|

##  <a name="afxdrawgraybitmap"></a>  AfxDrawGrayBitmap

Desenha uma versão de cinza de um bitmap.

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
Aponta para o controlador de domínio de destino.

*x*<br/>
A destino coordenada x.

*y*<br/>
A destino coordenada y.

*rSrc*<br/>
O bitmap de origem.

*crBackground*<br/>
A nova cor de plano de fundo (normalmente cinza, como COLOR_MENU).

### <a name="remarks"></a>Comentários

Um bitmap desenhado com `AfxDrawGrayBitmap` terá a aparência de um controle desabilitado.

![Comparação de versões de ícone cinza e originais](../../mfc/reference/media/vcgraybitmap.gif "comparação de versões de ícone cinza e original")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#191](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_1.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="afxgetgraybitmap"></a>  AfxGetGrayBitmap

Copia uma versão de cinza de um bitmap.

```
void AFXAPI AfxGetGrayBitmap(
    const CBitmap& rSrc,
    CBitmap* pDest,
    COLORREF crBackground);
```

### <a name="parameters"></a>Parâmetros

*rSrc*<br/>
O bitmap de origem.

*pDest*<br/>
O bitmap de destino.

*crBackground*<br/>
A nova cor de plano de fundo (normalmente cinza, como COLOR_MENU).

### <a name="remarks"></a>Comentários

Um bitmap copiado com `AfxGetGrayBitmap` terá a aparência de um controle desabilitado.

![Comparação de versões de ícone cinza e originais](../../mfc/reference/media/vcgraybitmap.gif "comparação de versões de ícone cinza e original")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#193](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_2.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="afxdrawditheredbitmap"></a>  AfxDrawDitheredBitmap

Desenha um bitmap, substituindo seu plano de fundo com um padrão de pontilhado (Verificador).

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
Aponta para o controlador de domínio de destino.

*x*<br/>
A destino coordenada x.

*y*<br/>
A destino coordenada y.

*rSrc*<br/>
O bitmap de origem.

*cr1*<br/>
Uma das cores dois pontilhamento, normalmente em branco.

*cr2*<br/>
A outra pontilhamento cor, normalmente acinzentado (COLOR_MENU).

### <a name="remarks"></a>Comentários

O bitmap de origem é desenhado no controlador de domínio de destino com duas cores (*cr1* e *cr2*) quadriculada padrão que substitui o plano de fundo do bitmap. O plano de fundo do bitmap de origem é definido como seus pixels brancas e todos os pixels correspondentes a cor do pixel no canto superior esquerdo do bitmap.

![Comparação de versões de ícone original e pontilhado](../../mfc/reference/media/vcditheredbitmap.gif "comparação de versões de ícone original e pontilhado")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#190](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_3.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="afxgetditheredbitmap"></a>  AfxGetDitheredBitmap

Copia um bitmap, substituindo seu plano de fundo com um padrão de pontilhado (Verificador).

```
void AFXAPI AfxGetDitheredBitmap(
    const CBitmap& rSrc,
    CBitmap* pDest,
    COLORREF cr1  ,
    COLORREF cr2);
```

### <a name="parameters"></a>Parâmetros

*rSrc*<br/>
O bitmap de origem.

*pDest*<br/>
O bitmap de destino.

*cr1*<br/>
Uma das cores dois pontilhamento, normalmente em branco.

*cr2*<br/>
A outra pontilhamento cor, normalmente acinzentado (COLOR_MENU).

### <a name="remarks"></a>Comentários

O bitmap de origem é copiado para o bitmap de destino com duas cores (*cr1* e *cr2*) quadriculada padrão que substitui o plano de fundo do bitmap de origem. O plano de fundo do bitmap de origem é definido como seus pixels brancas e todos os pixels correspondentes a cor do pixel no canto superior esquerdo do bitmap.

![Comparação de versões de ícone original e pontilhado](../../mfc/reference/media/vcditheredbitmap.gif "vcditheredbitmap")

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDocView#192](../../mfc/codesnippet/cpp/gray-and-dithered-bitmap-functions_4.cpp)]

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
