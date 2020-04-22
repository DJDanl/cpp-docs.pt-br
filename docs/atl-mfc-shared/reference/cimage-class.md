---
title: Classe CImage
ms.date: 08/19/2019
f1_keywords:
- CImage
- ATLIMAGE/ATL::CImage
- ATLIMAGE/ATL::CImage::CImage
- ATLIMAGE/ATL::CImage::AlphaBlend
- ATLIMAGE/ATL::CImage::Attach
- ATLIMAGE/ATL::CImage::BitBlt
- ATLIMAGE/ATL::CImage::Create
- ATLIMAGE/ATL::CImage::CreateEx
- ATLIMAGE/ATL::CImage::Destroy
- ATLIMAGE/ATL::CImage::Detach
- ATLIMAGE/ATL::CImage::Draw
- ATLIMAGE/ATL::CImage::GetBits
- ATLIMAGE/ATL::CImage::GetBPP
- ATLIMAGE/ATL::CImage::GetColorTable
- ATLIMAGE/ATL::CImage::GetDC
- ATLIMAGE/ATL::CImage::GetExporterFilterString
- ATLIMAGE/ATL::CImage::GetHeight
- ATLIMAGE/ATL::CImage::GetImporterFilterString
- ATLIMAGE/ATL::CImage::GetMaxColorTableEntries
- ATLIMAGE/ATL::CImage::GetPitch
- ATLIMAGE/ATL::CImage::GetPixel
- ATLIMAGE/ATL::CImage::GetPixelAddress
- ATLIMAGE/ATL::CImage::GetTransparentColor
- ATLIMAGE/ATL::CImage::GetWidth
- ATLIMAGE/ATL::CImage::IsDIBSection
- ATLIMAGE/ATL::CImage::IsIndexed
- ATLIMAGE/ATL::CImage::IsNull
- ATLIMAGE/ATL::CImage::IsTransparencySupported
- ATLIMAGE/ATL::CImage::Load
- ATLIMAGE/ATL::CImage::LoadFromResource
- ATLIMAGE/ATL::CImage::MaskBlt
- ATLIMAGE/ATL::CImage::PlgBlt
- ATLIMAGE/ATL::CImage::ReleaseDC
- ATLIMAGE/ATL::CImage::ReleaseGDIPlus
- ATLIMAGE/ATL::CImage::Save
- ATLIMAGE/ATL::CImage::SetColorTable
- ATLIMAGE/ATL::CImage::SetPixel
- ATLIMAGE/ATL::CImage::SetPixelIndexed
- ATLIMAGE/ATL::CImage::SetPixelRGB
- ATLIMAGE/ATL::CImage::SetTransparentColor
- ATLIMAGE/ATL::CImage::StretchBlt
- ATLIMAGE/ATL::CImage::TransparentBlt
helpviewer_keywords:
- jpeg files
- bitmaps [C++], ATL and MFC support for
- images [C++], ATL and MFC support for
- gif files, ATL and MFC support
- .gif files, ATL and MFC support
- PNG files, ATL and MFC support
- CImage class
- transparent color
ms.assetid: 52861e3d-bf7e-481f-a240-90e88f76c490
ms.openlocfilehash: a6d20e1bf12f5fe7d1e9b41d88b088ca9fad35ed
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81747172"
---
# <a name="cimage-class"></a>Classe CImage

`CImage`fornece suporte avançado ao bitmap, incluindo a capacidade de carregar e salvar imagens nos formatos JPEG, GIF, BMP e Portable Network Graphics (PNG).

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CImage
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CImage::CImage](#cimage)|O construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CImage::AlphaBlend](#alphablend)|Exibe bitmaps que possuem pixels transparentes ou semitransparentes.|
|[CImage::Anexar](#attach)|Anexa um HBITMAP `CImage` a um objeto. Pode ser usado com bitmaps de seção não-DIB ou bitmaps da seção DIB.|
|[CImage::BitBlt](#bitblt)|Copia um bitmap do contexto do dispositivo de origem para este contexto atual do dispositivo.|
|[CImage::Criar](#create)|Cria um bitmap da seção DIB e `CImage` o anexa ao objeto previamente construído.|
|[CImage::CreateEx](#createex)|Cria um bitmap da seção DIB (com parâmetros adicionais) e o anexa ao objeto previamente `CImage` construído.|
|[CImage::Destroy](#destroy)|Destaca o bitmap do `CImage` objeto e destrói o bitmap.|
|[CImage::Detach](#detach)|Destaca o bitmap de `CImage` um objeto.|
|[CImage::Draw](#draw)|Copia um bitmap de um retângulo de origem em um retângulo de destino. `Draw`estica ou comprime o bitmap para se adequar às dimensões do retângulo de destino, se necessário, e lida com a mistura alfa e cores transparentes.|
|[CImage::GetBits](#getbits)|Recupera um ponteiro para os valores reais de pixel do bitmap.|
|[CImage::GetBPP](#getbpp)|Recupera os bits por pixel.|
|[CImage::GetColortable](#getcolortable)|Recupera valores de cor vermelho, verde, azul (RGB) de uma variedade de entradas na tabela de cores.|
|[CImage::GetDC](#getdc)|Recupera o contexto do dispositivo no qual o bitmap atual é selecionado.|
|[CImage::Getexporterfilterstring](#getexporterfilterstring)|Encontra os formatos de imagem disponíveis e suas descrições.|
|[CImage::GetHeight](#getheight)|Recupera a altura da imagem atual em pixels.|
|[CImage::getImporterfilterstring](#getimporterfilterstring)|Encontra os formatos de imagem disponíveis e suas descrições.|
|[CImage::GetMaxColorTableEntries](#getmaxcolortableentries)|Recupera o número máximo de entradas na tabela de cores.|
|[CImage::GetPitch](#getpitch)|Recupera o tom da imagem atual, em bytes.|
|[CImage::GetPixel](#getpixel)|Recupera a cor do pixel especificado por *x* e *y*.|
|[CImage::GetPixelAddress](#getpixeladdress)|Recupera o endereço de um determinado pixel.|
|[CImage::GetTransparentColor](#gettransparentcolor)|Recupera a posição da cor transparente na tabela de cores.|
|[CImage::GetWidth](#getwidth)|Recupera a largura da imagem atual em pixels.|
|[CImage::IsDIBSection](#isdibsection)|Determina se o bitmap anexado é uma seção DIB.|
|[CImage::IsIndexed](#isindexed)|Indica que as cores de um bitmap são mapeadas para uma paleta indexada.|
|[CImage::Isnull](#isnull)|Indica se um bitmap de origem está carregado no momento.|
|[CImage::IsTransparencySupportsupported](#istransparencysupported)|Indica se o aplicativo suporta bitmaps transparentes.|
|[CImage::Load](#load)|Carrega uma imagem do arquivo especificado.|
|[CImage::LoadFromResource](#loadfromresource)|Carrega uma imagem do recurso especificado.|
|[CImage::MaskBlt](#maskblt)|Combina os dados de cor para os bitmaps de origem e destino usando a operação de máscara e raster especificado.|
|[CImage::PlgBlt](#plgblt)|Executa uma transferência de bloco de bits de um retângulo em um contexto de dispositivo de origem para um paralelograma em um contexto de dispositivo de destino.|
|[CImage::ReleaseDC](#releasedc)|Libera o contexto do dispositivo que foi recuperado com [CImage::GetDC](#getdc).|
|[CImage::ReleaseGDIPlus](#releasegdiplus)|Libera recursos utilizados pelo GDI+. Deve ser chamado para liberar recursos `CImage` criados por um objeto global.|
|[CImage::Salvar](#save)|Salva uma imagem como o tipo especificado. `Save`não pode especificar opções de imagem.|
|[CImage::SetColortable](#setcolortable)|Define valores de cor vermelho, verde, azul RGB) em uma variedade de entradas na tabela de cores da seção DIB.|
|[CImage::SetPixel](#setpixel)|Define o pixel nas coordenadas especificadas para a cor especificada.|
|[CImage::SetPixelIndexed](#setpixelindexed)|Define o pixel nas coordenadas especificadas para a cor no índice especificado da paleta.|
|[CImage::SetPixelRGB](#setpixelrgb)|Define o pixel nas coordenadas especificadas para o valor especificado vermelho, verde, azul (RGB).|
|[CImage::SetTransparentColor](#settransparentcolor)|Define o índice da cor a ser tratado como transparente. Apenas uma cor em uma paleta pode ser transparente.|
|[CImage::StretchBlt](#stretchblt)|Copia um bitmap de um retângulo de origem em um retângulo de destino, esticando ou comprimindo o bitmap para se adequar às dimensões do retângulo de destino, se necessário.|
|[CImage::TransparentBlt](#transparentblt)|Copia um bitmap com cor transparente do contexto do dispositivo de origem para este contexto atual do dispositivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CImage::operador HBITMAP](#operator_hbitmap)|Retorna a alça do `CImage` Windows anexada ao objeto.|

## <a name="remarks"></a>Comentários

`CImage`pega bitmaps que são ou seções de bitmap (DIB) independentes de dispositivo ou não; no entanto, você pode usar [Criar](#create) ou [CImage::Carregar](#load) apenas seções DIB. Você pode anexar um bitmap de `CImage` seção não-DIB a um `CImage` objeto usando [Attach](#attach), mas não pode usar os seguintes métodos, que suportam apenas bitmaps da seção DIB:

- [Getbits](#getbits)

- [GetColorTable](#getcolortable)

- [Entradas GetMaxColorTableE](#getmaxcolortableentries)

- [Getpitch](#getpitch)

- [GetPixelAddress](#getpixeladdress)

- [IsIndexed](#isindexed)

- [SetColorTable](#setcolortable)

Para determinar se um bitmap conectado é uma seção DIB, chame [IsDibSection](#isdibsection).

> [!NOTE]
> No Visual Studio .NET 2003, esta classe `CImage` mantém uma contagem do número de objetos criados. Sempre que a contagem `GdiplusShutdown` vai para 0, a função é automaticamente chamada para liberar recursos usados pelo GDI+. Isso garante que `CImage` todos os objetos criados direta ou indiretamente por `GdiplusShutdown` DLLs sejam sempre destruídos adequadamente e que não sejam chamados de `DllMain`.

> [!NOTE]
> Não `CImage` é recomendado o uso de objetos globais em uma DLL. Se você precisar usar `CImage` um objeto global em uma DLL, chame [CImage::ReleaseGDIPlus](#releasegdiplus) para liberar explicitamente os recursos usados pelo GDI+.

`CImage`não pode ser selecionado em um novo [CDC](../../mfc/reference/cdc-class.md). `CImage`cria seu próprio HDC para a imagem. Como um HBITMAP só pode ser selecionado em um HDC de `CImage` cada vez, o HBITMAP associado ao não pode ser selecionado em outro HDC. Se você precisar de um CDC, `CImage` recupere o HDC do e dê-o ao [CDC::FromHandle](../../mfc/reference/cdc-class.md#fromhandle).

## <a name="example"></a>Exemplo

```cpp
// Get a CDC for the image
CDC* pDC = CDC::FromHandle(m_myImage.GetDC());

// Use pDC here
pDC->Rectangle(0, 40, 100, 50);
m_myImage.ReleaseDC();
```

Quando você `CImage` usar em um projeto De MFC, observe quais funções de membro em seu projeto esperam um ponteiro para um objeto [CBitmap.](../../mfc/reference/cbitmap-class.md) Se você quiser `CImage` usar com tal função, como [CMenu::AppendMenu,](../../mfc/reference/cmenu-class.md#appendmenu)use [CBitmap::FromHandle,](../../mfc/reference/cbitmap-class.md#fromhandle)passe-o seu `CImage` HBITMAP e use o retornado `CBitmap*`.

## <a name="example"></a>Exemplo

```cpp
void CMyDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
    UNREFERENCED_PARAMETER(nFlags);

    CBitmap* pBitmap = CBitmap::FromHandle(m_myImage);
    m_pmenuPop->AppendMenu(0, ID_BMPCOMMAND, pBitmap);
    ClientToScreen(&point);
    m_pmenuPop->TrackPopupMenu(TPM_RIGHTBUTTON | TPM_LEFTALIGN, point.x,
    point.y, this);
}
```

Através `CImage`de , você tem acesso aos bits reais de uma seção DIB. Você pode `CImage` usar um objeto em qualquer lugar que você usou anteriormente uma seção Win32 HBITMAP ou DIB.

Você pode `CImage` usar de MFC ou ATL.

> [!NOTE]
> Ao criar um `CImage`projeto usando `CString` , você deve definir antes de incluir *atlimage.h*. Se o seu projeto usar ATL sem MFC, inclua *atlstr.h* antes de incluir *atlimage.h*. Se o seu projeto usar MFC (ou se for um projeto ATL com suporte a MFC), inclua *afxstr.h* antes de incluir *atlimage.h*.<br/>
> <br/>
> Da mesma forma, você deve incluir *atlimage.h* antes de incluir *atlimpl.cpp*. Para conseguir isso facilmente, inclua *atlimage.h* em seu *pch.h* *(stdafx.h* no Visual Studio 2017 e anterior).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlimage.h

## <a name="cimagealphablend"></a><a name="alphablend"></a>CImage::AlphaBlend

Exibe bitmaps que possuem pixels transparentes ou semitransparentes.

```
BOOL AlphaBlend(
    HDC hDestDC,
    int xDest,
    int yDest,
    BYTE bSrcAlpha = 0xff,
    BYTE bBlendOp = AC_SRC_OVER) const throw();

BOOL AlphaBlend(
    HDC hDestDC,
    const POINT& pointDest,
    BYTE bSrcAlpha = 0xff,
    BYTE bBlendOp = AC_SRC_OVER) const throw();

BOOL AlphaBlend(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight,
    int xSrc,
    int ySrc,
    int nSrcWidth,
    int nSrcHeight,
    BYTE bSrcAlpha = 0xff,
    BYTE bBlendOp = AC_SRC_OVER);

BOOL AlphaBlend(
    HDC hDestDC,
    const RECT& rectDest,
    const RECT& rectSrc,
    BYTE bSrcAlpha = 0xff,
    BYTE bBlendOp = AC_SRC_OVER);
```

### <a name="parameters"></a>Parâmetros

*hDestDC*<br/>
Manuseie o contexto do dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*bSrcAlpha*<br/>
Um valor de transparência alfa a ser usado em todo o bitmap de origem. O 0xff padrão (255) assume que sua imagem é opaca, e que você deseja usar apenas valores alfa por pixel.

*bBlendOp*<br/>
A função de mistura alfa para bitmaps de origem e destino, um valor alfa global a ser aplicado a todo o bitmap de origem e informações de formato para o bitmap de origem. As funções de mesclagem de origem e destino estão atualmente limitadas a AC_SRC_OVER.

*pointDest*<br/>
Uma referência a uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*xSrc*<br/>
A coordenada x lógica do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada lógica y do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectDest*<br/>
Uma referência a uma estrutura [RECT,](/windows/win32/api/windef/ns-windef-rect) identificando o destino.

*rectSrc*<br/>
Uma referência `RECT` a uma estrutura, identificando a fonte.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os bitmaps de mistura alfa suportam a mistura de cores em uma base por pixel.

Quando *o bBlendOp* é definido como padrão de AC_SRC_OVER, o bitmap de origem é colocado sobre o bitmap de destino com base nos valores alfa dos pixels de origem.

## <a name="cimageattach"></a><a name="attach"></a>CImage::Anexar

Anexa *hBitmap* a `CImage` um objeto.

```cpp
void Attach(HBITMAP hBitmap, DIBOrientation eOrientation = DIBOR_DEFAULT) throw();
```

### <a name="parameters"></a>Parâmetros

*Hbitmap*<br/>
Uma alça para um HBITMAP.

*eOrientação*<br/>
Especifica a orientação do bitmap. Um dos seguintes pode ser feito:

- DIBOR_DEFAULT A orientação do bitmap é determinada pelo sistema operacional.

- DIBOR_BOTTOMUP As linhas do bitmap estão em ordem inversa. Isso faz com que [cImage::GetBits](#getbits) retorne um ponteiro perto do final do buffer do bitmap e [CImage::GetPitch](#getpitch) para retornar um número negativo.

- DIBOR_TOPDOWN As linhas do bitmap estão na ordem de cima para baixo. Isso faz com que [cImage::GetBits](#getbits) retorne um ponteiro para o primeiro byte do buffer bitmap e [CImage::GetPitch](#getpitch) para retornar um número positivo.

### <a name="remarks"></a>Comentários

O bitmap pode ser um bitmap de seção não-DIB ou um bitmap da seção DIB. Consulte [IsDIBSection](#isdibsection) para obter uma lista de métodos que você só pode usar com bitmaps da seção DIB.

## <a name="cimagebitblt"></a><a name="bitblt"></a>CImage::BitBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto atual do dispositivo.

```
BOOL BitBlt(
    HDC hDestDC,
    int xDest,
    int yDest,
    DWORD dwROP = SRCCOPY) const throw();

BOOL BitBlt(
    HDC hDestDC,
    const POINT& pointDest,
    DWORD dwROP = SRCCOPY) const throw();

BOOL BitBlt(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight,
    int xSrc,
    int ySrc,
    DWORD dwROP = SRCCOPY) const throw();

BOOL BitBlt(
    HDC hDestDC,
    const RECT& rectDest,
    const POINT& pointSrc,
    DWORD dwROP = SRCCOPY) const throw();
```

### <a name="parameters"></a>Parâmetros

*hDestDC*<br/>
O destino HDC.

*xDest*<br/>
A coordenada x lógica do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada lógica y do canto superior esquerdo do retângulo de destino.

*Dwrop*<br/>
A operação rastera a ser realizada. Os códigos de operação de raster definem exatamente como combinar os bits da fonte, o destino e o padrão (conforme definido pelo pincel selecionado atualmente) para formar o destino. Consulte [BitBlt](/windows/win32/api/wingdi/nf-wingdi-bitblt) no Windows SDK para obter uma lista de outros códigos de operação de rastere e suas descrições.

*pointDest*<br/>
Uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) indicando o canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*xSrc*<br/>
A coordenada x lógica do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada lógica y do canto superior esquerdo do retângulo de origem.

*rectDest*<br/>
Uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) indicando o retângulo de destino.

*pointSrc*<br/>
Uma `POINT` estrutura indicando o canto superior esquerdo do retângulo de origem.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [BitBlt](/windows/win32/api/wingdi/nf-wingdi-bitblt) no SDK do Windows.

## <a name="cimagecimage"></a><a name="cimage"></a>CImage::CImage

Constrói um objeto `CImage`.

```
CImage() throw();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, chame [Criar,](#create) [Carregar,](#load) [CarregarRecurso](#loadfromresource)ou [Anexar](#attach) um bitmap ao objeto.

**Nota** No Visual Studio, esta classe mantém `CImage` uma contagem do número de objetos criados. Sempre que a contagem `GdiplusShutdown` vai para 0, a função é automaticamente chamada para liberar recursos usados pelo GDI+. Isso garante que `CImage` quaisquer objetos criados direta ou indiretamente por DLLs sejam sempre destruídos corretamente e que `GdiplusShutdown` não seja chamado de DllMain.

Não `CImage` é recomendado o uso de objetos globais em uma DLL. Se você precisar usar `CImage` um objeto global em uma DLL, chame [CImage::ReleaseGDIPlus](#releasegdiplus) para liberar explicitamente os recursos usados pelo GDI+.

## <a name="cimagecreate"></a><a name="create"></a>CImage::Criar

Cria `CImage` um bitmap e anexa-o `CImage` ao objeto previamente construído.

```
BOOL Create(
    int nWidth,
    int nHeight,
    int nBPP,
    DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*Nwidth*<br/>
A largura `CImage` do bitmap, em pixels.

*Nheight*<br/>
A altura `CImage` do bitmap, em pixels. Se *nHeight* for positivo, o bitmap é um DIB de baixo para cima e sua origem é o canto inferior esquerdo. Se *nHeight* for negativo, o bitmap é um DIB de cima para baixo e sua origem é o canto superior esquerdo.

*Nbpp*<br/>
Os números de bits por pixel no bitmap. Normalmente 4, 8, 16, 24 ou 32. Pode ser 1 para bitmaps ou máscaras monocromáticas.

*dwFlags*<br/>
Especifica se o objeto bitmap tem um canal alfa. Pode ser uma combinação de zero ou mais dos seguintes valores:

- *criarAlphaChannel* Só pode ser usado se *nBPP* tiver 32 e *eCompressão* for BI_RGB. Se especificado, a imagem criada tem um valor alfa (transparência) para cada pixel, armazenado no 4º byte de cada pixel (não utilizado em uma imagem não-alfa de 32 bits). Este canal alfa é usado automaticamente ao chamar [CImage::AlphaBlend](#alphablend).

> [!NOTE]
> Nas chamadas para [CImage::Draw](#draw), as imagens com um canal alfa são automaticamente misturadas ao destino.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

## <a name="cimagecreateex"></a><a name="createex"></a>CImage::CreateEx

Cria `CImage` um bitmap e anexa-o `CImage` ao objeto previamente construído.

```
BOOL CreateEx(
    int nWidth,
    int nHeight,
    int nBPP,
    DWORD eCompression,
    const DWORD* pdwBitmasks = NULL,
    DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*Nwidth*<br/>
A largura `CImage` do bitmap, em pixels.

*Nheight*<br/>
A altura `CImage` do bitmap, em pixels. Se *nHeight* for positivo, o bitmap é um DIB de baixo para cima e sua origem é o canto inferior esquerdo. Se *nHeight* for negativo, o bitmap é um DIB de cima para baixo e sua origem é o canto superior esquerdo.

*Nbpp*<br/>
Os números de bits por pixel no bitmap. Normalmente 4, 8, 16, 24 ou 32. Pode ser 1 para bitmaps ou máscaras monocromáticas.

*eCompressão*<br/>
Especifica o tipo de compactação para um bitmap de baixo para cima compactado (DIBs de cima para baixo não podem ser compactados). Pode ser um dos seguintes valores:

- BI_RGB O formato é descompactado. Especificar esse valor `CImage::CreateEx` ao ligar `CImage::Create`é equivalente a chamada .

- BI_BITFIELDS O formato é descompactado e a tabela de cores consiste em três máscaras de cor DWORD que especificam os componentes vermelho, verde e azul, respectivamente, de cada pixel. Isso é válido quando usado com bitmaps de 16 e 32 bpp.

*pdwBitfields*<br/>
Somente usado se *o eCompression* for definido para BI_BITFIELDS, caso contrário, deve ser NULO. Um ponteiro para uma matriz de três máscaras de bits DWORD, especificando quais bits de cada pixel são usados para os componentes vermelho, verde e azul da cor, respectivamente. Para obter informações sobre restrições para os bitfields, consulte [BITMAPINFOHEADER](/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) no SDK do Windows.

*dwFlags*<br/>
Especifica se o objeto bitmap tem um canal alfa. Pode ser uma combinação de zero ou mais dos seguintes valores:

- *criarAlphaChannel* Só pode ser usado se *nBPP* tiver 32 e *eCompressão* for BI_RGB. Se especificado, a imagem criada tem um valor alfa (transparência) para cada pixel, armazenado no 4º byte de cada pixel (não utilizado em uma imagem não-alfa de 32 bits). Este canal alfa é usado automaticamente ao chamar [CImage::AlphaBlend](#alphablend).

   > [!NOTE]
   > Nas chamadas para [CImage::Draw](#draw), as imagens com um canal alfa são automaticamente misturadas ao destino.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido. Caso contrário, FALSO.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um bitmap de 100x100 pixels, usando 16 bits para codificar cada pixel. Em um determinado pixel de 16 bits, bits 0-3 codificam o componente vermelho, bits 4-7 codificam verde e bits 8-11 codificam azul. Os 4 bits restantes não são utilizados.

```cpp
DWORD adwBitmasks[3] = { 0x0000000f, 0x000000f0, 0x00000f00 };
m_myImage.CreateEx(100, 100, 16, BI_BITFIELDS, adwBitmasks, 0);
```

## <a name="cimagedestroy"></a><a name="destroy"></a>CImage::Destroy

Destaca o bitmap do `CImage` objeto e destrói o bitmap.

```cpp
void Destroy() throw();
```

## <a name="cimagedetach"></a><a name="detach"></a>CImage::Detach

Destaca um bitmap de `CImage` um objeto.

```
HBITMAP Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Uma alça para o bitmap desvinculado ou NULL se nenhum bitmap for anexado.

## <a name="cimagedraw"></a><a name="draw"></a>CImage::Draw

Copia um bitmap do contexto do dispositivo de origem para o contexto atual do dispositivo.

```
BOOL Draw(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight,
    int xSrc,
    int ySrc,
    int nSrcWidth,
    int nSrcHeight) const throw();

BOOL Draw(
    HDC hDestDC,
    const RECT& rectDest,
    const RECT& rectSrc) const throw();

BOOL Draw(
    HDC hDestDC,
    int xDest,
    int yDest) const throw();

BOOL Draw(
    HDC hDestDC,
    const POINT& pointDest) const throw();

BOOL Draw(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight) const throw();

BOOL Draw(
    HDC hDestDC,
    const RECT& rectDest) const throw();
```

### <a name="parameters"></a>Parâmetros

*hDestDC*<br/>
Uma alça para o contexto do dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*xSrc*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectDest*<br/>
Uma referência a uma estrutura [RECT,](/windows/win32/api/windef/ns-windef-rect) identificando o destino.

*rectSrc*<br/>
Uma referência `RECT` a uma estrutura, identificando a fonte.

*pointDest*<br/>
Uma referência a uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Draw`realiza a mesma operação [que StretchBlt,](#stretchblt)a menos que a imagem contenha uma cor transparente ou canal alfa. Nesse caso, `Draw` executa a mesma operação que [o TransparentBlt](#transparentblt) ou [o AlphaBlend,](#alphablend) conforme necessário.

Para versões `Draw` que não especifiquem um retângulo de origem, toda a imagem de origem é o padrão. Para a `Draw` versão que não especifica um tamanho para o retângulo de destino, o tamanho da imagem de origem é o padrão e não ocorre alongamento ou encolhimento.

## <a name="cimagegetbits"></a><a name="getbits"></a>CImage::GetBits

Recupera um ponteiro para os valores reais de bit de um determinado pixel em um bitmap.

```cpp
void* GetBits() throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o buffer de bitmap. Se o bitmap for um DIB de baixo para cima, o ponteiro aponta perto do final do buffer. Se o bitmap for um DIB de cima para baixo, o ponteiro apontará para o primeiro byte do buffer.

### <a name="remarks"></a>Comentários

Usando este ponteiro, juntamente com o valor retornado pelo [GetPitch,](#getpitch)você pode localizar e alterar pixels individuais em uma imagem.

> [!NOTE]
> Este método suporta apenas bitmaps de seção DIB; consequentemente, você acessa `CImage` os pixels de um objeto da mesma forma que os pixels de uma seção DIB. O ponteiro retornado aponta para o pixel no local (0, 0).

## <a name="cimagegetbpp"></a><a name="getbpp"></a>CImage::GetBPP

Recupera o valor bits por pixel.

```
int GetBPP() const throw();
```

### <a name="return-value"></a>Valor retornado

O número de bits por pixel.

### <a name="remarks"></a>Comentários

Este valor determina o número de bits que definem cada pixel e o número máximo de cores no bitmap.

Os bits por pixel são geralmente 1, 4, 8, 16, 24 ou 32. Consulte `biBitCount` o membro do [BITMAPINFOHEADER](/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) no Windows SDK para obter mais informações sobre esse valor.

## <a name="cimagegetcolortable"></a><a name="getcolortable"></a>CImage::GetColortable

Recupera valores de cor vermelho, verde, azul (RGB) de uma variedade de entradas na paleta da seção DIB.

```cpp
void GetColorTable(
    UINT iFirstColor,
    UINT nColors,
    RGBQUAD* prgbColors) const throw();
```

### <a name="parameters"></a>Parâmetros

*iFirstColor*<br/>
O índice da tabela de cores da primeira entrada a recuperar.

*nCores*<br/>
O número de entradas de tabela de cores para recuperar.

*prgbCores*<br/>
Um ponteiro para a matriz de estruturas [RGBQUAD](/windows/win32/api/wingdi/ns-wingdi-rgbquad) para recuperar as entradas da tabela de cores.

## <a name="cimagegetdc"></a><a name="getdc"></a>CImage::GetDC

Recupera o contexto do dispositivo que atualmente tem a imagem selecionada nele.

```
HDC GetDC() const throw();
```

### <a name="return-value"></a>Valor retornado

Um identificador para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

Para cada `GetDC`chamada, você deve ter uma chamada subseqüente para [ReleaseDC](#releasedc).

## <a name="cimagegetexporterfilterstring"></a><a name="getexporterfilterstring"></a>CImage::Getexporterfilterstring

Encontra formatos de imagem disponíveis para salvar imagens.

```
static HRESULT GetExporterFilterString(
    CSimpleString& strExporters,
    CSimpleArray<GUID>& aguidFileTypes,
    LPCTSTR pszAllFilesDescription = NULL,
    DWORD dwExclude = excludeDefaultSave,
    TCHAR chSeparator = _T('|'));
```

### <a name="parameters"></a>Parâmetros

*strExportadorEs*<br/>
Uma referência a um objeto `CSimpleString`. Consulte **Observações** para obter mais informações.

*aguidFileTypes*<br/>
Uma matriz de GUIDs, com cada elemento correspondente a um dos tipos de arquivo na seqüência. No exemplo em *pszAllFilesDescription* abaixo, *aguidFileTypes*[0] é GUID_NULL e os valores restantes de array são os formatos de arquivo de imagem suportados pelo sistema operacional atual.

> [!NOTE]
> Para obter uma lista completa de constantes, consulte **Constants de formato de arquivo de imagem** no SDK do Windows.

*Pszallfilesdescription*<br/>
Se este parâmetro não for NULO, a seqüência de filtros terá um filtro adicional no início da lista. Este filtro terá o valor atual de *pszAllFilesDescription* para sua descrição, e aceita arquivos de qualquer extensão suportada por qualquer outro exportador da lista.

Por exemplo:

```cpp
//First filter in the list will be titled "All Image Files", and
//will accept files with any extension supported by any exporter.
CImage::GetExporterFilterString(
    strExporters, aguidFileTypes,
_T("All Image Files"));
```

*dwExclu*<br/>
Conjunto de sinalizadores de bits especificando quais tipos de arquivo excluir da lista. As bandeiras permitidas são:

- `excludeGIF`= 0x01 Exclui arquivos GIF.

- `excludeBMP`= 0x02 Exclui arquivos BMP (Windows Bitmap).

- `excludeEMF`= 0x04 Exclui arquivos EMF (Enhanced Metafile).

- `excludeWMF`= 0x08 Exclui arquivos WMF (Windows Metafile).

- `excludeJPEG`= 0x10 Exclui arquivos JPEG.

- `excludePNG`= 0x20 Exclui arquivos PNG.

- `excludeTIFF`= 0x40 Exclui arquivos TIFF.

- `excludeIcon`= 0x80 Exclui arquivos ICO (Windows Icon).

- `excludeOther`= 0x800000000 Exclui qualquer outro tipo de arquivo não listado acima.

- `excludeDefaultLoad`= 0 Para carga, todos os tipos de arquivo são incluídos por padrão

- `excludeDefaultSave` = `excludeIcon &#124; excludeEMF &#124; excludeWMF`Para salvar, esses arquivos são excluídos por padrão porque geralmente têm requisitos especiais.

*chSeparator*<br/>
O separador usado entre os formatos de imagem. Consulte **Observações** para obter mais informações.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode passar a seqüência de formato resultante para o objeto MFC [CFileDialog](../../mfc/reference/cfiledialog-class.md) para expor as extensões de arquivo dos formatos de imagem disponíveis na caixa de diálogo 'Salvar arquivos'.

O parâmetro *strExporter* tem o formato:

descrição do \*arquivo0&#124;.ext0 \*&#124;filedescription1&#124;.ext1&#124;... descrição *n* do \*arquivo n&#124;.ext *n*&#124;&#124;

onde '&#124;' é o caractere `chSeparator`separador especificado por . Por exemplo:

`"Bitmap format|*.bmp|JPEG format|*.jpg|GIF format|*.gif|PNG format|*.png||"`

Use o separador padrão '&#124;' se passar `CFileDialog` essa seqüência para um objeto MFC. Use o separador nulo '\0' se você passar essa seqüência para uma caixa de diálogo Salvar arquivos comum.

## <a name="cimagegetheight"></a><a name="getheight"></a>CImage::GetHeight

Recupera a altura, em pixels, de uma imagem.

```
int GetHeight() const throw();
```

### <a name="return-value"></a>Valor retornado

A altura, em pixels, de uma imagem.

## <a name="cimagegetimporterfilterstring"></a><a name="getimporterfilterstring"></a>CImage::getImporterfilterstring

Encontra formatos de imagem disponíveis para carregar imagens.

```
static HRESULT GetImporterFilterString(
    CSimpleString& strImporters,
    CSimpleArray<GUID>& aguidFileTypes,
    LPCTSTR pszAllFilesDescription = NULL,
    DWORD dwExclude = excludeDefaultLoad,
    TCHAR chSeparator = _T('|'));
```

### <a name="parameters"></a>Parâmetros

*strImporters*<br/>
Uma referência a um objeto `CSimpleString`. Consulte **Observações** para obter mais informações.

*aguidFileTypes*<br/>
Uma matriz de GUIDs, com cada elemento correspondente a um dos tipos de arquivo na seqüência. No exemplo em *pszAllFilesDescription* abaixo, *aguidFileTypes*[0] é GUID_NULL com os valores restantes de array são os formatos de arquivo de imagem suportados pelo sistema operacional atual.

> [!NOTE]
> Para obter uma lista completa de constantes, consulte **Constants de formato de arquivo de imagem** no SDK do Windows.

*Pszallfilesdescription*<br/>
Se este parâmetro não for NULO, a seqüência de filtros terá um filtro adicional no início da lista. Este filtro terá o valor atual de *pszAllFilesDescription* para sua descrição, e aceita arquivos de qualquer extensão suportada por qualquer outro exportador da lista.

Por exemplo:

```cpp
//First filter in the list will be titled "All Image Files", and
//will accept files with any extension supported by any importer.
CImage::GetImporterFilterString(
    strImporters, aguidFileTypes,
_T("All Image Files"));
```

*dwExclu*<br/>
Conjunto de sinalizadores de bits especificando quais tipos de arquivo excluir da lista. As bandeiras permitidas são:

- `excludeGIF`= 0x01 Exclui arquivos GIF.

- `excludeBMP`= 0x02 Exclui arquivos BMP (Windows Bitmap).

- `excludeEMF`= 0x04 Exclui arquivos EMF (Enhanced Metafile).

- `excludeWMF`= 0x08 Exclui arquivos WMF (Windows Metafile).

- `excludeJPEG`= 0x10 Exclui arquivos JPEG.

- `excludePNG`= 0x20 Exclui arquivos PNG.

- `excludeTIFF`= 0x40 Exclui arquivos TIFF.

- `excludeIcon`= 0x80 Exclui arquivos ICO (Windows Icon).

- `excludeOther`= 0x800000000 Exclui qualquer outro tipo de arquivo não listado acima.

- `excludeDefaultLoad`= 0 Para carga, todos os tipos de arquivo são incluídos por padrão

- `excludeDefaultSave` = `excludeIcon &#124; excludeEMF &#124; excludeWMF`Para salvar, esses arquivos são excluídos por padrão porque geralmente têm requisitos especiais.

*chSeparator*<br/>
O separador usado entre os formatos de imagem. Consulte **Observações** para obter mais informações.

### <a name="remarks"></a>Comentários

Você pode passar a seqüência de formato resultante para o objeto MFC [CFileDialog](../../mfc/reference/cfiledialog-class.md) para expor as extensões de arquivo dos formatos de imagem disponíveis na caixa de diálogo **Abrir arquivos.**

O parâmetro *strImporter* tem o formato:

descrição do \*arquivo0&#124;.ext0 \*&#124;filedescription1&#124;.ext1&#124;... descrição *n* do \*arquivo n&#124;.ext *n*&#124;&#124;

onde '&#124;' é o caractere separador especificado por *chSeparator*. Por exemplo:

`"Bitmap format|*.bmp|JPEG format|*.jpg|GIF format|*.gif|PNG format|*.png||"`

Use o separador padrão '&#124;' se passar `CFileDialog` essa seqüência para um objeto MFC. Use o separador nulo '\0' se você passar essa seqüência para uma caixa de diálogo **Abrir arquivos** comum.

## <a name="cimagegetmaxcolortableentries"></a><a name="getmaxcolortableentries"></a>CImage::GetMaxColorTableEntries

Recupera o número máximo de entradas na tabela de cores.

```
int GetMaxColorTableEntries() const throw();
```

### <a name="return-value"></a>Valor retornado

O número de entradas na tabela de cores.

### <a name="remarks"></a>Comentários

Este método suporta apenas bitmaps de seção DIB.

## <a name="cimagegetpitch"></a><a name="getpitch"></a>CImage::GetPitch

Recupera o tom de uma imagem.

```
int GetPitch() const throw();
```

### <a name="return-value"></a>Valor retornado

O tom da imagem. Se o valor de retorno for negativo, o bitmap é um DIB de baixo para cima e sua origem é o canto inferior esquerdo. Se o valor de retorno for positivo, o bitmap é um DIB de cima para baixo e sua origem é o canto superior esquerdo.

### <a name="remarks"></a>Comentários

O tom é a distância, em bytes, entre dois endereços de memória que representam o início de uma linha bitmap e o início da próxima linha bitmap. Como o pitch é medido em bytes, o tom de uma imagem ajuda a determinar o formato do pixel. O pitch também pode incluir memória adicional, reservada para o bitmap.

Use `GetPitch` com [GetBits](#getbits) para encontrar pixels individuais de uma imagem.

> [!NOTE]
> Este método suporta apenas bitmaps de seção DIB.

## <a name="cimagegetpixel"></a><a name="getpixel"></a>CImage::GetPixel

Recupera a cor do pixel no local especificado por *x* e *y*.

```
COLORREF GetPixel(int x, int y) const throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A coordenada x do pixel.

*Y*<br/>
A coordenada y do pixel.

### <a name="return-value"></a>Valor retornado

O valor vermelho, verde, azul (RGB) do pixel. Se o pixel estiver fora da região de recorte atual, o valor de retorno será CLR_INVALID.

## <a name="cimagegetpixeladdress"></a><a name="getpixeladdress"></a>CImage::GetPixelAddress

Recupera o endereço exato de um pixel.

```cpp
void* GetPixelAddress(int x, int y) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A coordenada x do pixel.

*Y*<br/>
A coordenada y do pixel.

### <a name="remarks"></a>Comentários

O endereço é determinado de acordo com as coordenadas de um pixel, o tom do bitmap e os bits por pixel.

Para formatos com menos de 8 bits por pixel, este método retorna o endereço do byte contendo o pixel. Por exemplo, se o formato da sua `GetPixelAddress` imagem tiver 4 bits por pixel, retornar á endereço do primeiro pixel no byte, e você deve calcular para 2 pixels por byte.

> [!NOTE]
> Este método suporta apenas bitmaps de seção DIB.

## <a name="cimagegettransparentcolor"></a><a name="gettransparentcolor"></a>CImage::GetTransparentColor

Recupera a localização indexada da cor transparente na paleta de cores.

```
LONG GetTransparentColor() const throw();
```

### <a name="return-value"></a>Valor retornado

O índice da cor transparente.

## <a name="cimagegetwidth"></a><a name="getwidth"></a>CImage::GetWidth

Recupera a largura, em pixels, de uma imagem.

```
int GetWidth() const throw();
```

### <a name="return-value"></a>Valor retornado

A largura do bitmap, em pixels.

## <a name="cimageisdibsection"></a><a name="isdibsection"></a>CImage::IsDIBSection

Determina se o bitmap anexado é uma seção DIB.

```
bool IsDIBSection() const throw();
```

### <a name="return-value"></a>Valor retornado

VERDADE se o bitmap anexado for uma seção DIB. Caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Se o bitmap não for uma seção `CImage` DIB, não será possível usar os seguintes métodos, que suportam apenas bitmaps da seção DIB:

- [Getbits](#getbits)

- [GetColorTable](#getcolortable)

- [Entradas GetMaxColorTableE](#getmaxcolortableentries)

- [Getpitch](#getpitch)

- [GetPixelAddress](#getpixeladdress)

- [IsIndexed](#isindexed)

- [SetColorTable](#setcolortable)

## <a name="cimageisindexed"></a><a name="isindexed"></a>CImage::IsIndexed

Determina se os pixels de um bitmap são mapeados para uma paleta de cores.

```
bool IsIndexed() const throw();
```

### <a name="return-value"></a>Valor retornado

VERDADEIRO se indexado; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Este método retorna TRUE somente se o bitmap for de 8 bits (256 cores) ou menos.

> [!NOTE]
> Este método suporta apenas bitmaps de seção DIB.

## <a name="cimageisnull"></a><a name="isnull"></a>CImage::Isnull

Determina se um bitmap está carregado no momento.

```
bool IsNull() const throw();
```

### <a name="remarks"></a>Comentários

Este método retorna TRUE se um bitmap não estiver carregado no momento; caso contrário, FALSO.

## <a name="cimageistransparencysupported"></a><a name="istransparencysupported"></a>CImage::IsTransparencySupportsupported

Indica se o aplicativo suporta bitmaps transparentes.

```
static BOOL IsTransparencySupported() throw();
```

### <a name="return-value"></a>Valor retornado

Não zero se a plataforma atual suportar transparência. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o valor de retorno não for zero e a transparência for suportada, uma chamada para [AlphaBlend,](#alphablend) [TransparentBlt](#transparentblt)ou [Draw](#draw) lidará com cores transparentes.

## <a name="cimageload"></a><a name="load"></a>CImage::Load

Carrega uma imagem.

```
HRESULT Load(LPCTSTR pszFileName) throw();
HRESULT Load(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*Pszfilename*<br/>
Um ponteiro para uma seqüência contendo o nome do arquivo de imagem para carregar.

*pStream*<br/>
Um ponteiro para um fluxo contendo o nome do arquivo de imagem para carregar.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Carrega a imagem especificada por *pszFileName* ou *pStream*.

Os tipos de imagem válidos são BMP, GIF, JPEG, PNG e TIFF.

## <a name="cimageloadfromresource"></a><a name="loadfromresource"></a>CImage::LoadFromResource

Carrega uma imagem de um recurso BITMAP.

```cpp
void LoadFromResource(
    HINSTANCE hInstance,
    LPCTSTR pszResourceName) throw();

void LoadFromResource(
    HINSTANCE hInstance,
    UINT nIDResource) throw();
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
Manuseie uma instância do módulo que contém a imagem a ser carregada.

*pszResourceName*<br/>
Um ponteiro para a seqüência contendo o nome do recurso que contém a imagem a carregar.

*Nidresource*<br/>
ID do pool de recursos a carregar.

### <a name="remarks"></a>Comentários

O recurso deve ser do tipo BITMAP.

## <a name="cimagemaskblt"></a><a name="maskblt"></a>CImage::MaskBlt

Combina os dados de cor para os bitmaps de origem e destino usando a operação de máscara e raster especificado.

```
BOOL MaskBlt(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight,
    int xSrc,
    int ySrc,
    HBITMAP hbmMask,
    int xMask,
    int yMask,
    DWORD dwROP = SRCCOPY) const throw();

BOOL MaskBlt(
    HDC hDestDC,
    const RECT& rectDest,
    const POINT& pointSrc,
    HBITMAP hbmMask,
    const POINT& pointMask,
    DWORD dwROP = SRCCOPY) const throw();

BOOL MaskBlt(
    HDC hDestDC,
    int xDest,
    int yDest,
    HBITMAP hbmMask,
    DWORD dwROP = SRCCOPY) const throw();

BOOL MaskBlt(
    HDC hDestDC,
    const POINT& pointDest,
    HBITMAP hbmMask,
    DWORD dwROP = SRCCOPY) const throw();
```

### <a name="parameters"></a>Parâmetros

*hDestDC*<br/>
A alça do módulo cujo executável contém o recurso.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino e do bitmap de origem.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino e do bitmap de origem.

*xSrc*<br/>
A coordenada x lógica do canto superior esquerdo do bitmap de origem.

*ySrc*<br/>
A coordenada lógica y do canto superior esquerdo do bitmap de origem.

*Hbmmask*<br/>
Manuseie o bitmap da máscara monocromática combinado com o bitmap de cores no contexto do dispositivo de origem.

*xMask*<br/>
O deslocamento horizontal do pixel para o bitmap da máscara especificado pelo parâmetro *hbmMask.*

*yMask*<br/>
O deslocamento de pixel vertical para o bitmap da máscara especificado pelo parâmetro *hbmMask.*

*Dwrop*<br/>
Especifica códigos de operação de rasterdes de primeiro plano e de fundo que o método usa para controlar a combinação de dados de origem e destino. O código de operação de raster de fundo é armazenado no byte de alta ordem da palavra de alta ordem deste valor; o código de operação de raster em primeiro plano é armazenado no byte de baixa ordem da palavra de alta ordem deste valor; a palavra de baixa ordem deste valor é ignorada, e deve ser zero. Para uma discussão de primeiro plano e fundo no `MaskBlt` contexto deste método, consulte no Windows SDK. Para obter uma lista de códigos `BitBlt` comuns de operação de raster, consulte no SDK do Windows.

*rectDest*<br/>
Uma referência `RECT` a uma estrutura, identificando o destino.

*pointSrc*<br/>
Uma `POINT` estrutura indicando o canto superior esquerdo do retângulo de origem.

*pointMask*<br/>
Uma `POINT` estrutura indicando o canto superior esquerdo do bitmap da máscara.

*pointDest*<br/>
Uma referência `POINT` a uma estrutura que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Este método se aplica apenas ao Windows NT, versões 4.0 e posteriores.

## <a name="cimageoperator-hbitmap"></a><a name="operator_hbitmap"></a>CImage::operador HBITMAP

Use este operador para obter a alça `CImage` Windows GDI anexada do objeto. Este operador é um operador de fundição, que suporta o uso direto de um objeto HBITMAP.

## <a name="cimageplgblt"></a><a name="plgblt"></a>CImage::PlgBlt

Executa uma transferência de bloco de bits de um retângulo em um contexto de dispositivo de origem para um paralelograma em um contexto de dispositivo de destino.

```
BOOL PlgBlt(
    HDC hDestDC,
    const POINT* pPoints,
    HBITMAP hbmMask = NULL) const throw();

BOOL PlgBlt(
    HDC hDestDC,
    const POINT* pPoints,
    int xSrc,
    int ySrc,
    int nSrcWidth,
    int nSrcHeight,
    HBITMAP hbmMask = NULL,
    int xMask = 0,
    int yMask = 0) const throw();

BOOL PlgBlt(
    HDC hDestDC,
    const POINT* pPoints,
    const RECT& rectSrc,
    HBITMAP hbmMask = NULL,
    const POINT& pointMask = CPoint(0, 0)) const throw();
```

### <a name="parameters"></a>Parâmetros

*hDestDC*<br/>
Uma alça para o contexto do dispositivo de destino.

*pPontos*<br/>
Um ponteiro para uma matriz de três pontos no espaço lógico que identificam três cantos do paralelograma de destino. O canto superior esquerdo do retângulo de origem é mapeado para o primeiro ponto nesta matriz, o canto superior direito para o segundo ponto nesta matriz, e o canto inferior esquerdo para o terceiro ponto. O canto inferior direito do retângulo de origem é mapeado para o quarto ponto implícito no paralelograma.

*Hbmmask*<br/>
Uma alça para um bitmap monocromático opcional que é usado para mascarar as cores do retângulo de origem.

*xSrc*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*xMask*<br/>
A coordenada x do canto superior esquerdo do bitmap monocromático.

*yMask*<br/>
A coordenada y do canto superior esquerdo do bitmap monocromático.

*rectSrc*<br/>
Uma referência a uma estrutura [RECT](/windows/win32/api/windef/ns-windef-rect) especificando as coordenadas do retângulo de origem.

*pointMask*<br/>
Uma estrutura [POINT](/windows/win32/api/windef/ns-windef-point) indicando o canto superior esquerdo do bitmap da máscara.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Se *hbmMask* identificar um bitmap `PlgBit` monocromático válido, use este bitmap para mascarar os bits de dados de cor do retângulo de origem.

Este método se aplica apenas ao Windows NT, versões 4.0 e posteriores. Consulte [O PlgBlt](/windows/win32/api/wingdi/nf-wingdi-plgblt) no Windows SDK para obter informações mais detalhadas.

## <a name="cimagereleasedc"></a><a name="releasedc"></a>CImage::ReleaseDC

Libera o contexto do dispositivo.

```cpp
void ReleaseDC() const throw();
```

### <a name="remarks"></a>Comentários

Como apenas um bitmap pode ser selecionado em um `ReleaseDC` contexto de dispositivo de cada vez, você deve chamar para cada chamada para [GetDC](#getdc).

## <a name="cimagereleasegdiplus"></a><a name="releasegdiplus"></a>CImage::ReleaseGDIPlus

Libera recursos utilizados pelo GDI+.

```cpp
void ReleaseGDIPlus() throw();
```

### <a name="remarks"></a>Comentários

Este método deve ser chamado para liberar `CImage` recursos alocados por um objeto global. Consulte [CImage::CImage](#cimage).

## <a name="cimagesave"></a><a name="save"></a>CImage::Salvar

Salva uma imagem no fluxo ou arquivo especificado no disco.

```
HRESULT Save(
    IStream* pStream,
    REFGUID guidFileType) const throw();

HRESULT Save(
    LPCTSTR pszFileName,
    REFGUID guidFileType = GUID_NULL) const throw();
```

### <a name="parameters"></a>Parâmetros

*pStream*<br/>
Um ponteiro para um objeto COM IStream contendo os dados da imagem do arquivo.

*Pszfilename*<br/>
Um ponteiro para o nome do arquivo para a imagem.

*guidFileType*<br/>
O tipo de arquivo para salvar a imagem como. Um dos seguintes pode ser feito:

- `ImageFormatBMP`Uma imagem de bitmap não compactada.

- `ImageFormatPNG`Uma imagem compactada do Portable Network Graphic (PNG).

- `ImageFormatJPEG`Uma imagem compactada JPEG.

- `ImageFormatGIF`Uma imagem compactada GIF.

> [!NOTE]
> Para obter uma lista completa de constantes, consulte **Constants de formato de arquivo de imagem** no SDK do Windows.

### <a name="return-value"></a>Valor retornado

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Chame esta função para salvar a imagem usando um nome e tipo especificados. Se o parâmetro *guidFileType* não estiver incluído, a extensão do arquivo do nome do arquivo será usada para determinar o formato da imagem. Se nenhuma extensão for fornecida, a imagem será salva no formato BMP.

## <a name="cimagesetcolortable"></a><a name="setcolortable"></a>CImage::SetColortable

Define os valores de cor vermelho, verde, azul (RGB) para uma gama de entradas na paleta da seção DIB.

```cpp
void SetColorTable(
    UINT iFirstColor,
    UINT nColors,
    const RGBQUAD* prgbColors) throw();
```

### <a name="parameters"></a>Parâmetros

*iFirstColor*<br/>
O índice da tabela de cores da primeira entrada a definir.

*nCores*<br/>
O número de entradas da tabela de cores a definir.

*prgbCores*<br/>
Um ponteiro para a matriz de estruturas [RGBQUAD](/windows/win32/api/wingdi/ns-wingdi-rgbquad) para definir as entradas da tabela de cores.

### <a name="remarks"></a>Comentários

Este método suporta apenas bitmaps de seção DIB.

## <a name="cimagesetpixel"></a><a name="setpixel"></a>CImage::SetPixel

Define a cor de um pixel em um determinado local no bitmap.

```cpp
void SetPixel(int x, int y, COLORREF color) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A localização horizontal do pixel a ser definido.

*Y*<br/>
A localização vertical do pixel a ser definido.

*cor*<br/>
A cor para a qual você define o pixel.

### <a name="remarks"></a>Comentários

Este método falha se as coordenadas de pixel estiver fora da região de recorte selecionada.

## <a name="cimagesetpixelindexed"></a><a name="setpixelindexed"></a>CImage::SetPixelIndexed

Define a cor do pixel para a cor localizada no *iIndex* na paleta de cores.

```cpp
void SetPixelIndexed(int x, int y, int iIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A localização horizontal do pixel a ser definido.

*Y*<br/>
A localização vertical do pixel a ser definido.

*Iindex*<br/>
O índice de uma cor na paleta de cores.

## <a name="cimagesetpixelrgb"></a><a name="setpixelrgb"></a>CImage::SetPixelRGB

Define o pixel nos locais especificados por *x* e *y* para as cores indicadas por *r*, *g*, e *b*, em uma imagem vermelha, verde, azul (RGB).

```cpp
void SetPixelRGB(
    int x,
    int y,
    BYTE r,
    BYTE g,
    BYTE b) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A localização horizontal do pixel a ser definido.

*Y*<br/>
A localização vertical do pixel a ser definido.

*r*<br/>
A intensidade da cor vermelha.

*G*<br/>
A intensidade da cor verde.

*B*<br/>
A intensidade da cor azul.

### <a name="remarks"></a>Comentários

Os parâmetros vermelho, verde e azul são representados por um número entre 0 e 255. Se você definir os três parâmetros para zero, a cor combinada resultante é preto. Se você definir os três parâmetros para 255, a cor combinada resultante é branca.

## <a name="cimagesettransparentcolor"></a><a name="settransparentcolor"></a>CImage::SetTransparentColor

Define uma cor em um determinado local indexado como transparente.

```
LONG SetTransparentColor(LONG iTransparentColor) throw();
```

### <a name="parameters"></a>Parâmetros

*iTransparentColor*<br/>
O índice, em uma paleta de cores, da cor a ser definida como transparente. Se -1, nenhuma cor é definida como transparente.

### <a name="return-value"></a>Valor retornado

O índice da cor previamente definido como transparente.

## <a name="cimagestretchblt"></a><a name="stretchblt"></a>CImage::StretchBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto atual do dispositivo.

```
BOOL StretchBlt(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight,
    DWORD dwROP = SRCCOPY) const throw();

BOOL StretchBlt(
    HDC hDestDC,
    const RECT& rectDest,
    DWORD dwROP = SRCCOPY) const throw();

BOOL StretchBlt(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight,
    int xSrc,
    int ySrc,
    int nSrcWidth,
    int nSrcHeight,
    DWORD dwROP = SRCCOPY) const throw();

BOOL StretchBlt(
    HDC hDestDC,
    const RECT& rectDest,
    const RECT& rectSrc,
    DWORD dwROP = SRCCOPY) const throw();
```

### <a name="parameters"></a>Parâmetros

*hDestDC*<br/>
Uma alça para o contexto do dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*Dwrop*<br/>
A operação rastera a ser realizada. Os códigos de operação de raster definem exatamente como combinar os bits da fonte, o destino e o padrão (conforme definido pelo pincel selecionado atualmente) para formar o destino. Consulte [BitBlt](/windows/win32/api/wingdi/nf-wingdi-bitblt) no Windows SDK para obter uma lista de outros códigos de operação de rastere e suas descrições.

*rectDest*<br/>
Uma referência a uma estrutura [RECT,](/windows/win32/api/windef/ns-windef-rect) identificando o destino.

*xSrc*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectSrc*<br/>
Uma referência `RECT` a uma estrutura, identificando a fonte.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [StretchBlt](/windows/win32/api/wingdi/nf-wingdi-stretchblt) no Windows SDK.

## <a name="cimagetransparentblt"></a><a name="transparentblt"></a>CImage::TransparentBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto atual do dispositivo.

```
BOOL TransparentBlt(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight,
    UINT crTransparent = CLR_INVALID) const throw();

BOOL TransparentBlt(
    HDC hDestDC,
    const RECT& rectDest,
    UINT crTransparent = CLR_INVALID) const throw();

BOOL TransparentBlt(
    HDC hDestDC,
    int xDest,
    int yDest,
    int nDestWidth,
    int nDestHeight,
    int xSrc,
    int ySrc,
    int nSrcWidth,
    int nSrcHeight,
    UINT crTransparent = CLR_INVALID) const throw();

BOOL TransparentBlt(
    HDC hDestDC,
    const RECT& rectDest,
    const RECT& rectSrc,
    UINT crTransparent = CLR_INVALID) const throw();
```

### <a name="parameters"></a>Parâmetros

*hDestDC*<br/>
Uma alça para o contexto do dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*crTransparente*<br/>
A cor no bitmap de origem para tratar como transparente. Por padrão, CLR_INVALID, indicando que a cor atualmente definida como a cor transparente da imagem deve ser usada.

*rectDest*<br/>
Uma referência a uma estrutura [RECT,](/windows/win32/api/windef/ns-windef-rect) identificando o destino.

*xSrc*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectSrc*<br/>
Uma referência `RECT` a uma estrutura, identificando a fonte.

### <a name="return-value"></a>Valor retornado

VERDADE se bem sucedido, caso contrário FALSO.

### <a name="remarks"></a>Comentários

`TransparentBlt`é suportado para bitmaps de origem de 4 bits por pixel e 8 bits por pixel. Use [CImage::AlphaBlend](#alphablend) para especificar bitmaps de 32 bits por pixel com transparência.

### <a name="example"></a>Exemplo

```cpp
// Performs a transparent blit from the source image to the destination
// image using the images' current transparency settings
BOOL TransparentBlt(CImage* pSrcImage, CImage* pDstImage,
       int xDest, int yDest, int nDestWidth, int nDestHeight)
{
    HDC hDstDC = NULL;
    BOOL bResult;

    if(pSrcImage == NULL || pDstImage == NULL)
    {
        // Invalid parameter
        return FALSE;
    }

    // Obtain a DC to the destination image
    hDstDC = pDstImage->GetDC();
    // Perform the blit
    bResult = pSrcImage->TransparentBlt(hDstDC, xDest, yDest, nDestWidth, nDestHeight);

    // Release the destination DC
    pDstImage->ReleaseDC();

    return bResult;
}
```

## <a name="see-also"></a>Confira também

[Amostra de MMXSwarm](../../overview/visual-cpp-samples.md)<br/>
[Amostra de Imagem Simples](../../overview/visual-cpp-samples.md)<br/>
[Bitmaps independentes de dispositivos](/windows/win32/gdi/device-independent-bitmaps)<br/>
[Createdibsection](/windows/win32/api/wingdi/nf-wingdi-createdibsection)<br/>
[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)<br/>
[Bitmaps independentes de dispositivos](/windows/win32/gdi/device-independent-bitmaps)<br/>
[Createdibsection](/windows/win32/api/wingdi/nf-wingdi-createdibsection)
