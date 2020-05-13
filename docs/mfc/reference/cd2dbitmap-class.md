---
title: Classe CD2DBitmap
ms.date: 11/04/2016
f1_keywords:
- CD2DBitmap
- AFXRENDERTARGET/CD2DBitmap
- AFXRENDERTARGET/CD2DBitmap::CD2DBitmap
- AFXRENDERTARGET/CD2DBitmap::Attach
- AFXRENDERTARGET/CD2DBitmap::CopyFromBitmap
- AFXRENDERTARGET/CD2DBitmap::CopyFromMemory
- AFXRENDERTARGET/CD2DBitmap::CopyFromRenderTarget
- AFXRENDERTARGET/CD2DBitmap::Create
- AFXRENDERTARGET/CD2DBitmap::Destroy
- AFXRENDERTARGET/CD2DBitmap::Detach
- AFXRENDERTARGET/CD2DBitmap::Get
- AFXRENDERTARGET/CD2DBitmap::GetDPI
- AFXRENDERTARGET/CD2DBitmap::GetPixelFormat
- AFXRENDERTARGET/CD2DBitmap::GetPixelSize
- AFXRENDERTARGET/CD2DBitmap::GetSize
- AFXRENDERTARGET/CD2DBitmap::IsValid
- AFXRENDERTARGET/CD2DBitmap::CommonInit
- AFXRENDERTARGET/CD2DBitmap::m_bAutoDestroyHBMP
- AFXRENDERTARGET/CD2DBitmap::m_hBmpSrc
- AFXRENDERTARGET/CD2DBitmap::m_lpszType
- AFXRENDERTARGET/CD2DBitmap::m_pBitmap
- AFXRENDERTARGET/CD2DBitmap::m_sizeDest
- AFXRENDERTARGET/CD2DBitmap::m_strPath
- AFXRENDERTARGET/CD2DBitmap::m_uiResID
helpviewer_keywords:
- CD2DBitmap [MFC], CD2DBitmap
- CD2DBitmap [MFC], CD2DBitmap
- CD2DBitmap [MFC], Attach
- CD2DBitmap [MFC], CopyFromBitmap
- CD2DBitmap [MFC], CopyFromMemory
- CD2DBitmap [MFC], CopyFromRenderTarget
- CD2DBitmap [MFC], Create
- CD2DBitmap [MFC], Destroy
- CD2DBitmap [MFC], Detach
- CD2DBitmap [MFC], Get
- CD2DBitmap [MFC], GetDPI
- CD2DBitmap [MFC], GetPixelFormat
- CD2DBitmap [MFC], GetPixelSize
- CD2DBitmap [MFC], GetSize
- CD2DBitmap [MFC], IsValid
- CD2DBitmap [MFC], CommonInit
- CD2DBitmap [MFC], m_bAutoDestroyHBMP
- CD2DBitmap [MFC], m_hBmpSrc
- CD2DBitmap [MFC], m_lpszType
- CD2DBitmap [MFC], m_pBitmap
- CD2DBitmap [MFC], m_sizeDest
- CD2DBitmap [MFC], m_strPath
- CD2DBitmap [MFC], m_uiResID
ms.assetid: 2b3686f1-812c-462b-b449-9f0cb6949bf6
ms.openlocfilehash: a3cabb00ded7dbc5f9c396a1de767058443a4436
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754212"
---
# <a name="cd2dbitmap-class"></a>Classe CD2DBitmap

Um invólucro para ID2D1Bitmap.

## <a name="syntax"></a>Sintaxe

```
class CD2DBitmap : public CD2DResource;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmap::CD2DBitmap](#cd2dbitmap)|Sobrecarregado. Constrói um objeto CD2DBitmap a partir do HBITMAP.|
|[CD2DBitmap::~CD2DBitmap](#_dtorcd2dbitmap)|O destruidor. Chamado quando um objeto de bitmap D2D está sendo destruído.|

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmap::CD2DBitmap](#cd2dbitmap)|Sobrecarregado. Constrói um objeto CD2DBitmap.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmap::Anexar](#attach)|Anexa a interface de recurso existente ao objeto|
|[CD2DBitmap::CopyFromBitmap](#copyfrombitmap)|Copia a região especificada do bitmap especificado no bitmap atual|
|[CD2DBitmap::CópiaDememóriamemória](#copyfrommemory)|Copia a região especificada da memória no bitmap atual|
|[CD2DBitmap::CopyFromRenderTarget](#copyfromrendertarget)|Copia a região especificada do destino de renderização especificado no bitmap atual|
|[CD2DBitmap::Criar](#create)|Cria um CD2DBitmap. (Substitui [cd2DResource::Create](../../mfc/reference/cd2dresource-class.md#create).)|
|[CD2DBitmap::Destroy](#destroy)|Destrói um objeto CD2DBitmap. (Substitui [cd2DResource::Destroy](../../mfc/reference/cd2dresource-class.md#destroy).)|
|[CD2DBitmap::Detach](#detach)|Destaca a interface de recursos do objeto|
|[CD2DBitmap::Obter](#get)|Retorna interface ID2D1Bitmap|
|[CD2DBitmap::GetDPI](#getdpi)|Retorne os pontos por polegada (DPI) do bitmap|
|[CD2DBitmap::GetPixelFormat](#getpixelformat)|Recupera o formato de pixel e o modo alfa do bitmap|
|[CD2DBitmap::GetPixelSize](#getpixelsize)|Retorna o tamanho, em unidades dependentes do dispositivo (pixels), do bitmap|
|[CD2DBitmap::GetSize](#getsize)|Retorna o tamanho, em pixels independentes de dispositivo (DIPs), do bitmap|
|[CD2DBitmap::IsValid](#isvalid)|Verifica a validade do recurso (Substitui [cd2DResource::IsValid](../../mfc/reference/cd2dresource-class.md#isvalid).)|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmap::CommonInit](#commoninit)|Inicializa o objeto|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmap::operador ID2D1Bitmap*](#operator_id2d1bitmap_star)|Retorna interface ID2D1Bitmap|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CD2DBitmap::m_bAutoDestroyHBMP](#m_bautodestroyhbmp)|VERDADE se m_hBmpSrc deve ser destruído; caso contrário, FALSO.|
|[CD2DBitmap::m_hBmpSrc](#m_hbmpsrc)|Alça do bitmap de origem.|
|[CD2DBitmap::m_lpszType](#m_lpsztype)|Tipo de recurso.|
|[CD2DBitmap::m_pBitmap](#m_pbitmap)|Armazena um ponteiro para um objeto ID2D1Bitmap.|
|[CD2DBitmap::m_sizeDest](#m_sizedest)|Tamanho do destino do Bitmap.|
|[CD2DBitmap::m_strPath](#m_strpath)|Caminho do arquivo Botmap.|
|[CD2DBitmap::m_uiResID](#m_uiresid)|ID de recurso do BitMap.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[CD2DResource](../../mfc/reference/cd2dresource-class.md)

`CD2DBitmap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxrendertarget.h

## <a name="cd2dbitmapcd2dbitmap"></a><a name="_dtorcd2dbitmap"></a>CD2DBitmap::~CD2DBitmap

O destruidor. Chamado quando um objeto de bitmap D2D está sendo destruído.

```
virtual ~CD2DBitmap();
```

## <a name="cd2dbitmapattach"></a><a name="attach"></a>CD2DBitmap::Anexar

Anexa a interface de recurso existente ao objeto.

```cpp
void Attach(ID2D1Bitmap* pResource);
```

### <a name="parameters"></a>Parâmetros

*Presource*<br/>
Interface de recurso existente. Não pode ser NULL.

## <a name="cd2dbitmapcd2dbitmap"></a><a name="cd2dbitmap"></a>CD2DBitmap::CD2DBitmap

Constrói um objeto CD2DBitmap a partir de recurso.

```
CD2DBitmap(
    CRenderTarget* pParentTarget,
    UINT uiResID,
    LPCTSTR lpszType = NULL,
    CD2DSizeU sizeDest = CD2DSizeU(0, 0),
    BOOL bAutoDestroy = TRUE);

CD2DBitmap(
    CRenderTarget* pParentTarget,
    LPCTSTR lpszPath,
    CD2DSizeU sizeDest = CD2DSizeU(0, 0),
    BOOL bAutoDestroy = TRUE);

CD2DBitmap(
    CRenderTarget* pParentTarget,
    HBITMAP hbmpSrc,
    CD2DSizeU sizeDest = CD2DSizeU(0, 0),
    BOOL bAutoDestroy = TRUE);

CD2DBitmap(
    CRenderTarget* pParentTarget,
    BOOL bAutoDestroy = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pParentTarget*<br/>
Um ponteiro para o alvo de renderização.

*uiResID*<br/>
O número de id de recurso do recurso.

*lpszType*<br/>
Ponteiro para uma seqüência de terminadas nula que contém o tipo de recurso.

*tamanhoDest*<br/>
Tamanho do destino do bitmap.

*bAutoDestroy*<br/>
Indica que o objeto será destruído pelo proprietário (pParentTarget).

*lpszPath*<br/>
Ponteiro para uma seqüência de terminadas nula que contém o nome do arquivo.

*hbmpSrc*<br/>
Manuseie para o bitmap.

## <a name="cd2dbitmapcommoninit"></a><a name="commoninit"></a>CD2DBitmap::CommonInit

Inicializa o objeto.

```cpp
void CommonInit();
```

## <a name="cd2dbitmapcopyfrombitmap"></a><a name="copyfrombitmap"></a>CD2DBitmap::CopyFromBitmap

Copia a região especificada do bitmap especificado no bitmap atual.

```
HRESULT CopyFromBitmap(
    const CD2DBitmap* pBitmap,
    const CD2DPointU* destPoint = NULL,
    const CD2DRectU* srcRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*Pbitmap*<br/>
O bitmap para copiar.

*destPoint*<br/>
No bitmap atual, o canto superior esquerdo da área para a qual a região especificada por srcRect é copiada.

*Srcrect*<br/>
A área do bitmap para copiar.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dbitmapcopyfrommemory"></a><a name="copyfrommemory"></a>CD2DBitmap::CópiaDememóriamemória

Copia a região especificada da memória para o bitmap atual.

```
HRESULT CopyFromMemory(
    const void* srcData,
    UINT32 pitch,
    const CD2DRectU* destRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*srcData*<br/>
Os dados a serem copiados.

*Campo*<br/>
O passo, ou passo, do bitmap de origem armazenado no srcData. O passo é a contagem de bytes de uma linha de varredura (uma linha de pixels na memória). O passo pode ser calculado a partir \* da seguinte fórmula: bytes de largura de pixel por pixel + preenchimento de memória.

*destRect*<br/>
No bitmap atual, o canto superior esquerdo da área para a qual a região especificada por srcRect é copiada.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dbitmapcopyfromrendertarget"></a><a name="copyfromrendertarget"></a>CD2DBitmap::CopyFromRenderTarget

Copia a região especificada do destino de renderização especificado no bitmap atual.

```
HRESULT CopyFromRenderTarget(
    const CRenderTarget* pRenderTarget,
    const CD2DPointU* destPoint = NULL,
    const CD2DRectU* srcRect = NULL);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
O alvo de renderização que contém a região a ser copiada.

*destPoint*<br/>
No bitmap atual, o canto superior esquerdo da área para a qual a região especificada por srcRect é copiada.

*Srcrect*<br/>
A área de renderTarget para copiar.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dbitmapcreate"></a><a name="create"></a>CD2DBitmap::Criar

Cria um CD2DBitmap.

```
virtual HRESULT Create(CRenderTarget* pRenderTarget);
```

### <a name="parameters"></a>Parâmetros

*pRenderTarget*<br/>
Um ponteiro para o alvo de renderização.

### <a name="return-value"></a>Valor retornado

Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.

## <a name="cd2dbitmapdestroy"></a><a name="destroy"></a>CD2DBitmap::Destroy

Destrói um objeto CD2DBitmap.

```
virtual void Destroy();
```

## <a name="cd2dbitmapdetach"></a><a name="detach"></a>CD2DBitmap::Detach

Destaca a interface de recursos do objeto.

```
ID2D1Bitmap* Detach();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para interface de recurso separada.

## <a name="cd2dbitmapget"></a><a name="get"></a>CD2DBitmap::Obter

Retorna interface ID2D1Bitmap.

```
ID2D1Bitmap* Get();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Bitmap ou NULL se o objeto ainda não estiver inicializado.

## <a name="cd2dbitmapgetdpi"></a><a name="getdpi"></a>CD2DBitmap::GetDPI

Retorne os pontos por polegada (DPI) do bitmap.

```
CD2DSizeF GetDPI() const;
```

### <a name="return-value"></a>Valor retornado

O DPI horizontal e vertical do bitmap.

## <a name="cd2dbitmapgetpixelformat"></a><a name="getpixelformat"></a>CD2DBitmap::GetPixelFormat

Recupera o formato de pixel e o modo alfa do bitmap

```
D2D1_PIXEL_FORMAT GetPixelFormat() const;
```

### <a name="return-value"></a>Valor retornado

O formato de pixel e o modo alfa do bitmap.

## <a name="cd2dbitmapgetpixelsize"></a><a name="getpixelsize"></a>CD2DBitmap::GetPixelSize

Retorna o tamanho, em unidades dependentes do dispositivo (pixels), do bitmap.

```
CD2DSizeU GetPixelSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho, em pixels, do bitmap..

## <a name="cd2dbitmapgetsize"></a><a name="getsize"></a>CD2DBitmap::GetSize

Retorna o tamanho, em pixels independentes do dispositivo (DIPs), do bitmap.

```
CD2DSizeF GetSize() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho, em DIPs, do bitmap.

## <a name="cd2dbitmapisvalid"></a><a name="isvalid"></a>CD2DBitmap::IsValid

Verifica a validade do recurso.

```
virtual BOOL IsValid() const;
```

### <a name="return-value"></a>Valor retornado

TRUE se o recurso for válido; caso contrário, FALSO.

## <a name="cd2dbitmapm_bautodestroyhbmp"></a><a name="m_bautodestroyhbmp"></a>CD2DBitmap::m_bAutoDestroyHBMP

VERDADE se m_hBmpSrc deve ser destruído; caso contrário, FALSO.

```
BOOL m_bAutoDestroyHBMP;
```

## <a name="cd2dbitmapm_hbmpsrc"></a><a name="m_hbmpsrc"></a>CD2DBitmap::m_hBmpSrc

Alça do bitmap de origem.

```
HBITMAP m_hBmpSrc;
```

## <a name="cd2dbitmapm_lpsztype"></a><a name="m_lpsztype"></a>CD2DBitmap::m_lpszType

Tipo de recurso.

```
LPCTSTR m_lpszType;
```

## <a name="cd2dbitmapm_pbitmap"></a><a name="m_pbitmap"></a>CD2DBitmap::m_pBitmap

Armazena um ponteiro para um objeto ID2D1Bitmap.

```
ID2D1Bitmap* m_pBitmap;
```

## <a name="cd2dbitmapm_sizedest"></a><a name="m_sizedest"></a>CD2DBitmap::m_sizeDest

Tamanho do destino do Bitmap.

```
CD2DSizeU m_sizeDest;
```

## <a name="cd2dbitmapm_strpath"></a><a name="m_strpath"></a>CD2DBitmap::m_strPath

Caminho do arquivo Botmap.

```
CString m_strPath;
```

## <a name="cd2dbitmapm_uiresid"></a><a name="m_uiresid"></a>CD2DBitmap::m_uiResID

ID de recurso do BitMap.

```
UINT m_uiResID;
```

## <a name="cd2dbitmapoperator-id2d1bitmap"></a><a name="operator_id2d1bitmap_star"></a>CD2DBitmap::operador ID2D1Bitmap*

Retorna interface ID2D1Bitmap

```
operator ID2D1Bitmap*();
```

### <a name="return-value"></a>Valor retornado

Ponteiro para uma interface ID2D1Bitmap ou NULL se o objeto ainda não estiver inicializado.

## <a name="see-also"></a>Confira também

[Classes](../../mfc/reference/mfc-classes.md)
