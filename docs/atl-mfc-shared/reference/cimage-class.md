---
title: Classe CImage
ms.date: 02/01/2018
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
ms.openlocfilehash: 6c651f160fdab582b769cf1764add2cc482745bf
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491325"
---
# <a name="cimage-class"></a>Classe CImage

`CImage`fornece suporte a bitmap avançado, incluindo a capacidade de carregar e salvar imagens em formatos JPEG, GIF, BMP e Portable Network Graphics (PNG).

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

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
|[CImage::AlphaBlend](#alphablend)|Exibe os bitmaps que têm pixels transparentes ou semitransparentes.|
|[CImage::Attach](#attach)|Anexa um HBITMAP a um `CImage` objeto. Pode ser usado com bitmaps de seção não DIB ou bitmaps de seção DIB.|
|[CImage::BitBlt](#bitblt)|Copia um bitmap do contexto do dispositivo de origem para este contexto do dispositivo atual.|
|[CImage::Create](#create)|Cria um bitmap de seção DIB e o anexa ao objeto construído `CImage` anteriormente.|
|[CImage::CreateEx](#createex)|Cria um bitmap de seção DIB (com parâmetros adicionais) e anexa-o ao objeto construído `CImage` anteriormente.|
|[CImage::Destroy](#destroy)|Desanexa o bitmap do `CImage` objeto e destrói o bitmap.|
|[CImage::Detach](#detach)|Desanexa o bitmap de um `CImage` objeto.|
|[CImage::D bruto](#draw)|Copia um bitmap de um retângulo de origem em um retângulo de destino. `Draw`Amplia ou compacta o bitmap para se ajustar às dimensões do retângulo de destino, se necessário, e manipula a mistura alfa e as cores transparentes.|
|[CImage::GetBits](#getbits)|Recupera um ponteiro para os valores de pixel reais do bitmap.|
|[CImage::GetBPP](#getbpp)|Recupera os bits por pixel.|
|[CImage::GetColorTable](#getcolortable)|Recupera valores de cor vermelho, verde e azul (RGB) de um intervalo de entradas na tabela de cores.|
|[CImage::GetDC](#getdc)|Recupera o contexto do dispositivo no qual o bitmap atual está selecionado.|
|[CImage::GetExporterFilterString](#getexporterfilterstring)|Localiza os formatos de imagem disponíveis e suas descrições.|
|[CImage::GetHeight](#getheight)|Recupera a altura da imagem atual em pixels.|
|[CImage::GetImporterFilterString](#getimporterfilterstring)|Localiza os formatos de imagem disponíveis e suas descrições.|
|[CImage::GetMaxColorTableEntries](#getmaxcolortableentries)|Recupera o número máximo de entradas na tabela de cores.|
|[CImage::GetPitch](#getpitch)|Recupera a densidade da imagem atual, em bytes.|
|[CImage::GetPixel](#getpixel)|Recupera a cor do pixel especificado por *x* e *y*.|
|[CImage::GetPixelAddress](#getpixeladdress)|Recupera o endereço de um determinado pixel.|
|[CImage::GetTransparentColor](#gettransparentcolor)|Recupera a posição da cor transparente na tabela de cores.|
|[CImage::GetWidth](#getwidth)|Recupera a largura da imagem atual em pixels.|
|[CImage::IsDIBSection](#isdibsection)|Determina se o bitmap anexado é uma seção DIB.|
|[CImage::IsIndexed](#isindexed)|Indica que as cores de um bitmap são mapeadas para uma paleta indexada.|
|[CImage::IsNull](#isnull)|Indica se um bitmap de origem está carregado no momento.|
|[CImage::IsTransparencySupported](#istransparencysupported)|Indica se o aplicativo dá suporte a bitmaps transparentes.|
|[CImage:: Load](#load)|Carrega uma imagem do arquivo especificado.|
|[CImage::LoadFromResource](#loadfromresource)|Carrega uma imagem do recurso especificado.|
|[CImage::MaskBlt](#maskblt)|Combina os dados de cor dos bitmaps de origem e de destino usando a máscara especificada e a operação de rasterização.|
|[CImage::PlgBlt](#plgblt)|Executa uma transferência de bloco de bits de um retângulo em um contexto de dispositivo de origem para um paralelogramo em um contexto de dispositivo de destino.|
|[CImage::ReleaseDC](#releasedc)|Libera o contexto do dispositivo que foi recuperado com [CImage:: GetDC](#getdc).|
|[CImage::ReleaseGDIPlus](#releasegdiplus)|Libera recursos usados pelo GDI+. Deve ser chamado para liberar recursos criados por um objeto `CImage` global.|
|[CImage::Save](#save)|Salva uma imagem como o tipo especificado. `Save`Não é possível especificar opções de imagem.|
|[CImage::SetColorTable](#setcolortable)|Define valores de cor RGB vermelho, verde e azul em um intervalo de entradas na tabela de cores da seção DIB.|
|[CImage::SetPixel](#setpixel)|Define o pixel nas coordenadas especificadas para a cor especificada.|
|[CImage::SetPixelIndexed](#setpixelindexed)|Define o pixel nas coordenadas especificadas para a cor no índice especificado da paleta.|
|[CImage::SetPixelRGB](#setpixelrgb)|Define o pixel nas coordenadas especificadas para o valor vermelho, verde, azul (RGB) especificado.|
|[CImage::SetTransparentColor](#settransparentcolor)|Define o índice da cor a ser tratada como transparente. Somente uma cor em uma paleta pode ser transparente.|
|[CImage::StretchBlt](#stretchblt)|Copia um bitmap de um retângulo de origem em um retângulo de destino, alongando ou compactando o bitmap para se ajustar às dimensões do retângulo de destino, se necessário.|
|[CImage::TransparentBlt](#transparentblt)|Copia um bitmap com cor transparente do contexto do dispositivo de origem para este contexto do dispositivo atual.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CImage:: Operator HBITMAP](#operator_hbitmap)|Retorna o identificador do Windows anexado ao `CImage` objeto.|

## <a name="remarks"></a>Comentários

`CImage`usa bitmaps que são seções de bitmap independente de dispositivo (DIB) ou não; no entanto, você pode usar [Create](#create) ou [CImage:: Load](#load) com apenas seções DIB. Você pode anexar um bitmap de seção não DIB a um `CImage` objeto usando [Attach](#attach), mas, em seguida, você não `CImage` pode usar os seguintes métodos, que dão suporte apenas a bitmaps de seção DIB:

- [GetBits](#getbits)

- [GetColorTable](#getcolortable)

- [GetMaxColorTableEntries](#getmaxcolortableentries)

- [GetPitch](#getpitch)

- [GetPixelAddress](#getpixeladdress)

- [IsIndexed](#isindexed)

- [SetColorTable](#setcolortable)

Para determinar se um bitmap anexado é uma seção DIB, chame [IsDIBSection](#isdibsection).

> [!NOTE]
> No Visual Studio .NET 2003, essa classe mantém uma contagem do número de `CImage` objetos criados. Sempre que a contagem vai para 0, a `GdiplusShutdown` função é chamada automaticamente para liberar os recursos usados pelo GDI+. Isso garante que todos `CImage` os objetos criados direta ou indiretamente por DLLs sejam sempre destruídos `GdiplusShutdown` corretamente e que não `DllMain`são chamados de.

> [!NOTE]
> Não é `CImage` recomendável usar objetos globais em uma dll. Se você precisar usar um objeto global `CImage` em uma dll, chame [CImage:: ReleaseGDIPlus](#releasegdiplus) para liberar explicitamente os recursos usados pelo GDI+.

`CImage`Não pode ser selecionado em um novo [CDC](../../mfc/reference/cdc-class.md). `CImage`cria seu próprio HDC para a imagem. Como um HBITMAP só pode ser selecionado em um HDC de cada vez, o HBITMAP associado a ele `CImage` não pode ser selecionado em outro HDC. Se você precisar de um CDC, recupere o HDC do `CImage` e dê a ele o [CDC:: FromHandle](../../mfc/reference/cdc-class.md#fromhandle).

## <a name="example"></a>Exemplo

```cpp
// Get a CDC for the image
CDC* pDC = CDC::FromHandle(m_myImage.GetDC());

// Use pDC here
pDC->Rectangle(0, 40, 100, 50);
m_myImage.ReleaseDC();
```

Quando você usa `CImage` o em um projeto do MFC, observe quais funções de membro em seu projeto esperam um ponteiro para um objeto [CBitmap](../../mfc/reference/cbitmap-class.md) . Se você quiser `CImage` usar com essa função, como [CMenu:: AppendMenu](../../mfc/reference/cmenu-class.md#appendmenu), use [CBitmap:: FromHandle](../../mfc/reference/cbitmap-class.md#fromhandle), passe para o seu `CImage` HBITMAP e use o retornado. `CBitmap*`

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

Por `CImage`meio do, você tem acesso aos bits reais de uma seção DIB. Você pode usar um `CImage` objeto em qualquer lugar em que tenha usado anteriormente uma seção Win32 HBITMAP ou DIB.

Você pode usar `CImage` a partir do MFC ou do ATL.

> [!NOTE]
> Ao criar um projeto usando `CImage`o, você deve definir `CString` antes de incluir. `atlimage.h` Se seu projeto usar ATL sem MFC, inclua `atlstr.h` antes de incluir `atlimage.h`. Se seu projeto usar MFC (ou se for um projeto ATL com suporte MFC), inclua `afxstr.h` antes de incluir. `atlimage.h`<br/>
> <br/>
> Da mesma forma, você `atlimage.h` deve incluir antes `atlimpl.cpp`de incluir. Para fazer isso com facilidade, `atlimage.h` inclua em `stdafx.h`seu.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlimage. h

##  <a name="alphablend"></a>  CImage::AlphaBlend

Exibe os bitmaps que têm pixels transparentes ou semitransparentes.

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
Identificador para o contexto do dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*bSrcAlpha*<br/>
Um valor de transparência alfa a ser usado em todo o bitmap de origem. O 0xFF padrão (255) pressupõe que a imagem é opaca e que você deseja usar apenas valores Alfa por pixel.

*bBlendOp*<br/>
A função de mistura alfa para bitmaps de origem e de destino, um valor alfa global a ser aplicado a todo o bitmap de origem e informações de formato para o bitmap de origem. As funções de mesclagem de origem e destino estão limitadas a AC_SRC_OVER.

*pointDest*<br/>
Uma referência a uma estrutura de [ponto](/previous-versions/dd162805\(v=vs.85\)) que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*xSrc*<br/>
A coordenada x lógica do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y lógica do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectDest*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) , identificando o destino.

*rectSrc*<br/>
Uma referência a uma `RECT` estrutura, identificando a origem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os bitmaps do Alpha-Blend dão suporte à mesclagem de cores por pixel.

Quando *bBlendOp* é definido como o padrão de AC_SRC_OVER, o bitmap de origem é colocado sobre o bitmap de destino com base nos valores Alfa dos pixels de origem.

##  <a name="attach"></a>  CImage::Attach

Anexa *HBITMAP* a um `CImage` objeto.

```
void Attach(HBITMAP hBitmap, DIBOrientation eOrientation = DIBOR_DEFAULT) throw();
```

### <a name="parameters"></a>Parâmetros

*hBitmap*<br/>
Um identificador para um HBITMAP.

*eOrientation*<br/>
Especifica a orientação do bitmap. Pode ser um dos seguintes:

- DIBOR_DEFAULT a orientação do bitmap é determinada pelo sistema operacional.

- DIBOR_BOTTOMUP as linhas do bitmap estão em ordem inversa. Isso faz com que [CImage:: GetBits](#getbits) retorne um ponteiro próximo ao final do buffer de bitmap e [CImage:: GetPitch](#getpitch) para retornar um número negativo.

- DIBOR_TOPDOWN as linhas do bitmap estão na ordem superior à inferior. Isso faz com que [CImage:: GetBits](#getbits) retorne um ponteiro para o primeiro byte do buffer de bitmap e [CImage:: GetPitch](#getpitch) para retornar um número positivo.

### <a name="remarks"></a>Comentários

O bitmap pode ser um bitmap de seção não DIB ou um bitmap de seção DIB. Consulte [IsDIBSection](#isdibsection) para obter uma lista de métodos que você pode usar somente com os bitmaps da seção DIB.

##  <a name="bitblt"></a>  CImage::BitBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto do dispositivo atual.

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
O HDC de destino.

*xDest*<br/>
A coordenada x lógica do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y lógica do canto superior esquerdo do retângulo de destino.

*dwROP*<br/>
A operação de varredura a ser executada. Os códigos de operação de varredura definem exatamente como combinar os bits da origem, o destino e o padrão (conforme definido pelo pincel selecionado no momento) para formar o destino. Consulte [BitBlt](/windows/win32/api/wingdi/nf-wingdi-bitblt) no SDK do Windows para obter uma lista de outros códigos de operação de varredura e suas descrições.

*pointDest*<br/>
Uma estrutura de [ponto](/previous-versions/dd162805\(v=vs.85\)) que indica o canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*xSrc*<br/>
A coordenada x lógica do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y lógica do canto superior esquerdo do retângulo de origem.

*rectDest*<br/>
Uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que indica o retângulo de destino.

*pointSrc*<br/>
Uma `POINT` estrutura que indica o canto superior esquerdo do retângulo de origem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, zero.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [BitBlt](/windows/win32/api/wingdi/nf-wingdi-bitblt) no SDK do Windows.

##  <a name="cimage"></a>  CImage::CImage

Constrói um objeto `CImage`.

```
CImage() throw();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, chame [Create](#create), [Load](#load), [LoadFromResource](#loadfromresource)ou [Attach](#attach) para anexar um bitmap ao objeto.

**Observação** No Visual Studio, essa classe mantém uma contagem do número de `CImage` objetos criados. Sempre que a contagem vai para 0, a `GdiplusShutdown` função é chamada automaticamente para liberar os recursos usados pelo GDI+. Isso garante que todos `CImage` os objetos criados direta ou indiretamente por DLLs sejam sempre destruídos `GdiplusShutdown` corretamente e que não são chamados de DllMain.

Não é `CImage` recomendável usar objetos globais em uma dll. Se você precisar usar um objeto global `CImage` em uma dll, chame [CImage:: ReleaseGDIPlus](#releasegdiplus) para liberar explicitamente os recursos usados pelo GDI+.

##  <a name="create"></a>CImage:: criar

Cria um `CImage` bitmap e o anexa ao objeto previamente construído `CImage` .

```
BOOL Create(
    int nWidth,
    int nHeight,
    int nBPP,
    DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
A largura do `CImage` bitmap, em pixels.

*nHeight*<br/>
A altura do `CImage` bitmap, em pixels. Se *nHeight* for positivo, o bitmap será um DIB de baixo para cima e sua origem será o canto inferior esquerdo. Se *nHeight* for negativo, o bitmap será um DIB de cima para baixo e sua origem será o canto superior esquerdo.

*nBPP*<br/>
Os números de bits por pixel no bitmap. Geralmente 4, 8, 16, 24 ou 32. Pode ser 1 para bitmaps ou máscaras monocromáticas.

*dwFlags*<br/>
Especifica se o objeto de bitmap tem um canal alfa. Pode ser uma combinação de zero ou mais dos seguintes valores:

- *createAlphaChannel* Só poderá ser usado se *NBPP* for 32 e *eCompression* for BI_RGB. Se especificado, a imagem criada terá um valor alfa (transparência) para cada pixel, armazenado no 4º byte de cada pixel (não usado em uma imagem de 32 bits não alfa). Esse canal alfa é usado automaticamente ao chamar [CImage:: AlphaBlend](#alphablend).

> [!NOTE]
> Em chamadas para [CImage::D RAW](#draw), as imagens com um canal alfa são automaticamente mescladas ao destino.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

##  <a name="createex"></a>  CImage::CreateEx

Cria um `CImage` bitmap e o anexa ao objeto previamente construído `CImage` .

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

*nWidth*<br/>
A largura do `CImage` bitmap, em pixels.

*nHeight*<br/>
A altura do `CImage` bitmap, em pixels. Se *nHeight* for positivo, o bitmap será um DIB de baixo para cima e sua origem será o canto inferior esquerdo. Se *nHeight* for negativo, o bitmap será um DIB de cima para baixo e sua origem será o canto superior esquerdo.

*nBPP*<br/>
Os números de bits por pixel no bitmap. Geralmente 4, 8, 16, 24 ou 32. Pode ser 1 para bitmaps ou máscaras monocromáticas.

*eCompression*<br/>
Especifica o tipo de compactação para um bitmap de parte inferior compactado (o DIBs superior não pode ser compactado). Pode ser um dos seguintes valores:

- BI_RGB o formato é descompactado. Especificar esse valor ao chamar `CImage::CreateEx` é equivalente a chamar `CImage::Create`.

- BI_BITFIELDS o formato é descompactado e a tabela de cores consiste em três máscaras de cor DWORD que especificam os componentes vermelho, verde e azul, respectivamente, de cada pixel. Isso é válido quando usado com bitmaps de 16 e 32-bpp.

*pdwBitfields*<br/>
Usado somente se *eCompression* estiver definido como BI_BITFIELDS, caso contrário, ele deverá ser nulo. Um ponteiro para uma matriz de três bitmasks DWORD, especificando quais bits de cada pixel são usados para os componentes vermelho, verde e azul da cor, respectivamente. Para obter informações sobre restrições para o bitfields, consulte [BITMAPINFOHEADER](/previous-versions//dd183376\(v=vs.85\)) no SDK do Windows.

*dwFlags*<br/>
Especifica se o objeto de bitmap tem um canal alfa. Pode ser uma combinação de zero ou mais dos seguintes valores:

- *createAlphaChannel* Só poderá ser usado se *NBPP* for 32 e *eCompression* for BI_RGB. Se especificado, a imagem criada terá um valor alfa (transparência) para cada pixel, armazenado no 4º byte de cada pixel (não usado em uma imagem de 32 bits não alfa). Esse canal alfa é usado automaticamente ao chamar [CImage:: AlphaBlend](#alphablend).

   > [!NOTE]
   > Em chamadas para [CImage::D RAW](#draw), as imagens com um canal alfa são automaticamente mescladas ao destino.

### <a name="return-value"></a>Valor de retorno

TRUE se for bem-sucedido. Caso contrário, FALSE.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um bitmap de pixel 100x100, usando 16 bits para codificar cada pixel. Em um determinado pixel de 16 bits, os bits 0-3 codificam o componente vermelho, bits 4-7 de codificação verde e bits 8-11 codificam azul. Os quatro bits restantes não são usados.

```cpp
DWORD adwBitmasks[3] = { 0x0000000f, 0x000000f0, 0x00000f00 };
m_myImage.CreateEx(100, 100, 16, BI_BITFIELDS, adwBitmasks, 0);
```

##  <a name="destroy"></a>  CImage::Destroy

Desanexa o bitmap do `CImage` objeto e destrói o bitmap.

```
void Destroy() throw();
```

##  <a name="detach"></a>  CImage::Detach

Desanexa um bitmap de um `CImage` objeto.

```
HBITMAP Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o bitmap desanexado ou nulo se nenhum bitmap estiver anexado.

##  <a name="draw"></a>  CImage::Draw

Copia um bitmap do contexto do dispositivo de origem para o contexto do dispositivo atual.

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
Um identificador para o contexto do dispositivo de destino.

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
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) , identificando o destino.

*rectSrc*<br/>
Uma referência a uma `RECT` estrutura, identificando a origem.

*pointDest*<br/>
Uma referência a uma estrutura de [ponto](/previous-versions/dd162805\(v=vs.85\)) que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

`Draw`executa a mesma operação que [StretchBlt](#stretchblt), a menos que a imagem contenha uma cor transparente ou um canal alfa. Nesse caso, `Draw` o executa a mesma operação como [TransparentBlt](#transparentblt) ou [AlphaBlend](#alphablend) , conforme necessário.

Para versões do `Draw` que não especificam um retângulo de origem, a imagem de origem inteira é o padrão. Para a versão do `Draw` que não especifica um tamanho para o retângulo de destino, o tamanho da imagem de origem é o padrão e nenhum alongamento ou redução ocorre.

##  <a name="getbits"></a>  CImage::GetBits

Recupera um ponteiro para os valores de bits reais de um determinado pixel em um bitmap.

```
void* GetBits() throw();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o buffer de bitmap. Se o bitmap for um DIB de baixo para cima, o ponteiro apontará para perto do final do buffer. Se o bitmap for um DIB de cima para baixo, o ponteiro apontará para o primeiro byte do buffer.

### <a name="remarks"></a>Comentários

Usando esse ponteiro, junto com o valor retornado por [GetPitch](#getpitch), você pode localizar e alterar pixels individuais em uma imagem.

> [!NOTE]
> Este método dá suporte apenas a bitmaps de seção DIB; Consequentemente, você acessa os pixels de `CImage` um objeto da mesma forma que faria com os pixels de uma seção DIB. O ponteiro retornado aponta para o pixel no local (0, 0).

##  <a name="getbpp"></a>  CImage::GetBPP

Recupera o valor de bits por pixel.

```
int GetBPP() const throw();
```

### <a name="return-value"></a>Valor de retorno

O número de bits por pixel.

### <a name="remarks"></a>Comentários

Esse valor determina o número de bits que definem cada pixel e o número máximo de cores no bitmap.

Os bits por pixel geralmente são 1, 4, 8, 16, 24 ou 32. Consulte o `biBitCount` membro de [BITMAPINFOHEADER](/previous-versions//dd183376\(v=vs.85\)) no SDK do Windows para obter mais informações sobre esse valor.

##  <a name="getcolortable"></a>  CImage::GetColorTable

Recupera valores de cor vermelho, verde e azul (RGB) de um intervalo de entradas na paleta da seção DIB.

```
void GetColorTable(
    UINT iFirstColor,
    UINT nColors,
    RGBQUAD* prgbColors) const throw();
```

### <a name="parameters"></a>Parâmetros

*iFirstColor*<br/>
O índice da tabela de cores da primeira entrada a ser recuperada.

*nColors*<br/>
O número de entradas da tabela de cores a serem recuperadas.

*prgbColors*<br/>
Um ponteiro para a matriz de estruturas [RGBQUAD](/windows/win32/api/wingdi/ns-wingdi-rgbquad) para recuperar as entradas da tabela de cores.

##  <a name="getdc"></a>  CImage::GetDC

Recupera o contexto do dispositivo que atualmente tem a imagem selecionada.

```
HDC GetDC() const throw();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

Para cada chamada para `GetDC`, você deve ter uma chamada subsequente para [ReleaseDC](#releasedc).

##  <a name="getexporterfilterstring"></a>  CImage::GetExporterFilterString

Localiza os formatos de imagem disponíveis para salvar imagens.

```
static HRESULT GetExporterFilterString(
    CSimpleString& strExporters,
    CSimpleArray<GUID>& aguidFileTypes,
    LPCTSTR pszAllFilesDescription = NULL,
    DWORD dwExclude = excludeDefaultSave,
    TCHAR chSeparator = _T('|'));
```

### <a name="parameters"></a>Parâmetros

*strExporters*<br/>
Uma referência a um objeto `CSimpleString`. Consulte **comentários** para obter mais informações.

*aguidFileTypes*<br/>
Uma matriz de GUIDs, com cada elemento correspondente a um dos tipos de arquivo na cadeia de caracteres. No exemplo em *pszAllFilesDescription* abaixo, *aguidFileTypes*[0] é GUID_NULL e os valores de matriz restantes são os formatos de arquivo de imagem com suporte no sistema operacional atual.

> [!NOTE]
> Para obter uma lista completa de constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.

*pszAllFilesDescription*<br/>
Se esse parâmetro não for nulo, a cadeia de caracteres de filtro terá um filtro adicional no início da lista. Esse filtro terá o valor atual de *pszAllFilesDescription* para sua descrição e aceitará arquivos de qualquer extensão com suporte de qualquer outro exportador na lista.

Por exemplo:

```cpp
//First filter in the list will be titled "All Image Files", and
//will accept files with any extension supported by any exporter.
CImage::GetExporterFilterString(
    strExporters, aguidFileTypes,
_T("All Image Files"));
```

*dwExclude*<br/>
Conjunto de sinalizadores de bit que especificam quais tipos de arquivo excluir da lista. Os sinalizadores permitidos são:

- `excludeGIF`= 0x01 exclui arquivos GIF.

- `excludeBMP`= 0x02 exclui arquivos BMP (bitmap do Windows).

- `excludeEMF`= 0x04 exclui arquivos EMF (metarquivo avançado).

- `excludeWMF`= 0x08 exclui arquivos WMF (metarquivo do Windows).

- `excludeJPEG`= 0x10 exclui arquivos JPEG.

- `excludePNG`= 0x20 exclui arquivos PNG.

- `excludeTIFF`= 0x40 exclui arquivos TIFF.

- `excludeIcon`= 0x80 exclui arquivos ICO (ícone do Windows).

- `excludeOther`= 0x80000000 exclui qualquer outro tipo de arquivo não listado acima.

- `excludeDefaultLoad`= 0 para carga, todos os tipos de arquivo são incluídos por padrão

- `excludeDefaultSave` = `excludeIcon &#124; excludeEMF &#124; excludeWMF`Para salvar, esses arquivos são excluídos por padrão porque geralmente têm requisitos especiais.

*chSeparator*<br/>
O separador usado entre os formatos de imagem. Consulte **comentários** para obter mais informações.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode passar a cadeia de caracteres de formato resultante para o objeto MFC [CFileDialog](../../mfc/reference/cfiledialog-class.md) para expor as extensões de arquivo dos formatos de imagem disponíveis na caixa de diálogo arquivo salvar como.

O parâmetro *strExporter* tem o formato:

Arquivo description0&#124;\*. ext0&#124;&#124;filedescription1\*. EXT1&#124;... Descrição do arquivo *n*&#124;\*. ext *n*&#124;&#124;

onde '&#124;' é o caractere separador `chSeparator`especificado por. Por exemplo:

`"Bitmap format|*.bmp|JPEG format|*.jpg|GIF format|*.gif|PNG format|*.png||"`

Use o separador&#124;padrão ' ' se você passar essa cadeia de `CFileDialog` caracteres para um objeto MFC. Use o separador nulo ' \ 0 ' se você passar essa cadeia de caracteres para uma caixa de diálogo de gravação de arquivo comum.

##  <a name="getheight"></a>  CImage::GetHeight

Recupera a altura, em pixels, de uma imagem.

```
int GetHeight() const throw();
```

### <a name="return-value"></a>Valor de retorno

A altura, em pixels, de uma imagem.

##  <a name="getimporterfilterstring"></a>  CImage::GetImporterFilterString

Localiza os formatos de imagem disponíveis para carregar imagens.

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
Uma referência a um objeto `CSimpleString`. Consulte **comentários** para obter mais informações.

*aguidFileTypes*<br/>
Uma matriz de GUIDs, com cada elemento correspondente a um dos tipos de arquivo na cadeia de caracteres. No exemplo em *pszAllFilesDescription* abaixo, *aguidFileTypes*[0] é GUID_NULL com os valores de matriz restantes são os formatos de arquivo de imagem com suporte no sistema operacional atual.

> [!NOTE]
> Para obter uma lista completa de constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.

*pszAllFilesDescription*<br/>
Se esse parâmetro não for nulo, a cadeia de caracteres de filtro terá um filtro adicional no início da lista. Esse filtro terá o valor atual de *pszAllFilesDescription* para sua descrição e aceitará arquivos de qualquer extensão com suporte de qualquer outro exportador na lista.

Por exemplo:

```cpp
//First filter in the list will be titled "All Image Files", and
//will accept files with any extension supported by any importer.
CImage::GetImporterFilterString(
    strImporters, aguidFileTypes,
_T("All Image Files"));
```

*dwExclude*<br/>
Conjunto de sinalizadores de bit que especificam quais tipos de arquivo excluir da lista. Os sinalizadores permitidos são:

- `excludeGIF`= 0x01 exclui arquivos GIF.

- `excludeBMP`= 0x02 exclui arquivos BMP (bitmap do Windows).

- `excludeEMF`= 0x04 exclui arquivos EMF (metarquivo avançado).

- `excludeWMF`= 0x08 exclui arquivos WMF (metarquivo do Windows).

- `excludeJPEG`= 0x10 exclui arquivos JPEG.

- `excludePNG`= 0x20 exclui arquivos PNG.

- `excludeTIFF`= 0x40 exclui arquivos TIFF.

- `excludeIcon`= 0x80 exclui arquivos ICO (ícone do Windows).

- `excludeOther`= 0x80000000 exclui qualquer outro tipo de arquivo não listado acima.

- `excludeDefaultLoad`= 0 para carga, todos os tipos de arquivo são incluídos por padrão

- `excludeDefaultSave` = `excludeIcon &#124; excludeEMF &#124; excludeWMF`Para salvar, esses arquivos são excluídos por padrão porque geralmente têm requisitos especiais.

*chSeparator*<br/>
O separador usado entre os formatos de imagem. Consulte **comentários** para obter mais informações.

### <a name="remarks"></a>Comentários

Você pode passar a cadeia de caracteres de formato resultante para o objeto MFC [CFileDialog](../../mfc/reference/cfiledialog-class.md) para expor as extensões de arquivo dos formatos de imagem disponíveis na caixa de diálogo **Abrir arquivo** .

O parâmetro *strImporter* tem o formato:

Arquivo description0&#124;\*. ext0&#124;&#124;filedescription1\*. EXT1&#124;... Descrição do arquivo *n*&#124;\*. ext *n*&#124;&#124;

onde '&#124;' é o caractere separador especificado por *chSeparator*. Por exemplo:

`"Bitmap format|*.bmp|JPEG format|*.jpg|GIF format|*.gif|PNG format|*.png||"`

Use o separador&#124;padrão ' ' se você passar essa cadeia de `CFileDialog` caracteres para um objeto MFC. Use o separador nulo ' \ 0 ' se você passar essa cadeia de caracteres para uma caixa de diálogo de **abertura de arquivo** comum.

##  <a name="getmaxcolortableentries"></a>  CImage::GetMaxColorTableEntries

Recupera o número máximo de entradas na tabela de cores.

```
int GetMaxColorTableEntries() const throw();
```

### <a name="return-value"></a>Valor de retorno

O número de entradas na tabela de cores.

### <a name="remarks"></a>Comentários

Este método dá suporte apenas a bitmaps de seção DIB.

##  <a name="getpitch"></a>  CImage::GetPitch

Recupera a inclinação de uma imagem.

```
int GetPitch() const throw();
```

### <a name="return-value"></a>Valor de retorno

A inclinação da imagem. Se o valor de retorno for negativo, o bitmap será um DIB de baixo para cima e sua origem será o canto inferior esquerdo. Se o valor de retorno for positivo, o bitmap será um DIB de cima para baixo e sua origem será o canto superior esquerdo.

### <a name="remarks"></a>Comentários

A densidade é a distância, em bytes, entre dois endereços de memória que representam o início de uma linha de bitmap e o início da próxima linha de bitmap. Como Pitch é medido em bytes, a inclinação de uma imagem ajuda a determinar o formato de pixel. A densidade também pode incluir memória adicional, reservada para o bitmap.

Use `GetPitch` com [GetBits](#getbits) para localizar pixels individuais de uma imagem.

> [!NOTE]
> Este método dá suporte apenas a bitmaps de seção DIB.

##  <a name="getpixel"></a>  CImage::GetPixel

Recupera a cor do pixel no local especificado por *x* e *y*.

```
COLORREF GetPixel(int x, int y) const throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A coordenada x do pixel.

*y*<br/>
A coordenada y do pixel.

### <a name="return-value"></a>Valor de retorno

O valor vermelho, verde, azul (RGB) do pixel. Se o pixel estiver fora da região de recorte atual, o valor de retorno será CLR_INVALID.

##  <a name="getpixeladdress"></a>  CImage::GetPixelAddress

Recupera o endereço exato de um pixel.

```
void* GetPixelAddress(int x, int y) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A coordenada x do pixel.

*y*<br/>
A coordenada y do pixel.

### <a name="remarks"></a>Comentários

O endereço é determinado de acordo com as coordenadas de um pixel, a inclinação do bitmap e os bits por pixel.

Para formatos com menos de 8 bits por pixel, esse método retorna o endereço do byte que contém o pixel. Por exemplo, se o formato de imagem tiver 4 bits por pixel `GetPixelAddress` , o retornará o endereço do primeiro pixel do byte e você deverá calcular para 2 pixels por byte.

> [!NOTE]
> Este método dá suporte apenas a bitmaps de seção DIB.

##  <a name="gettransparentcolor"></a>  CImage::GetTransparentColor

Recupera o local indexado da cor transparente na paleta de cores.

```
LONG GetTransparentColor() const throw();
```

### <a name="return-value"></a>Valor de retorno

O índice da cor transparente.

##  <a name="getwidth"></a>  CImage::GetWidth

Recupera a largura, em pixels, de uma imagem.

```
int GetWidth() const throw();
```

### <a name="return-value"></a>Valor de retorno

A largura do bitmap, em pixels.

##  <a name="isdibsection"></a>  CImage::IsDIBSection

Determina se o bitmap anexado é uma seção DIB.

```
bool IsDIBSection() const throw();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o bitmap anexado for uma seção DIB. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o bitmap não for uma seção DIB, você não poderá usar os `CImage` seguintes métodos, que dão suporte apenas a bitmaps da seção DIB:

- [GetBits](#getbits)

- [GetColorTable](#getcolortable)

- [GetMaxColorTableEntries](#getmaxcolortableentries)

- [GetPitch](#getpitch)

- [GetPixelAddress](#getpixeladdress)

- [IsIndexed](#isindexed)

- [SetColorTable](#setcolortable)

##  <a name="isindexed"></a>  CImage::IsIndexed

Determina se os pixels de um bitmap são mapeados para uma paleta de cores.

```
bool IsIndexed() const throw();
```

### <a name="return-value"></a>Valor de retorno

TRUE se indexado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método retornará TRUE somente se o bitmap for de 8 bits (256 cores) ou menos.

> [!NOTE]
> Este método dá suporte apenas a bitmaps de seção DIB.

##  <a name="isnull"></a>  CImage::IsNull

Determina se um bitmap está carregado no momento.

```
bool IsNull() const throw();
```

### <a name="remarks"></a>Comentários

Esse método retornará TRUE se um bitmap não estiver carregado no momento; caso contrário, FALSE.

##  <a name="istransparencysupported"></a>  CImage::IsTransparencySupported

Indica se o aplicativo dá suporte a bitmaps transparentes.

```
static BOOL IsTransparencySupported() throw();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a plataforma atual oferecer suporte à transparência. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o valor de retorno for diferente de zero e houver suporte para transparência, uma chamada para [AlphaBlend](#alphablend), [TransparentBlt](#transparentblt)ou [draw](#draw) tratará cores transparentes.

##  <a name="load"></a>CImage:: Load

Carrega uma imagem.

```
HRESULT Load(LPCTSTR pszFileName) throw();
HRESULT Load(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*pszFileName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo de imagem a ser carregado.

*pStream*<br/>
Um ponteiro para um fluxo que contém o nome do arquivo de imagem a ser carregado.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Carrega a imagem especificada por *pszFileName* ou *pStream*.

Os tipos de imagem válidos são BMP, GIF, JPEG, PNG e TIFF.

##  <a name="loadfromresource"></a>CImage::LoadFromResource

Carrega uma imagem de um recurso de BITMAP.

```
void LoadFromResource(
    HINSTANCE hInstance,
    LPCTSTR pszResourceName) throw();

void LoadFromResource(
    HINSTANCE hInstance,
    UINT nIDResource) throw();
```

### <a name="parameters"></a>Parâmetros

*hInstance*<br/>
Identificador para uma instância do módulo que contém a imagem a ser carregada.

*pszResourceName*<br/>
Um ponteiro para a cadeia de caracteres que contém o nome do recurso que contém a imagem a ser carregada.

*nIDResource*<br/>
A ID do recurso a ser carregado.

### <a name="remarks"></a>Comentários

O recurso deve ser do tipo BITMAP.

##  <a name="maskblt"></a>  CImage::MaskBlt

Combina os dados de cor dos bitmaps de origem e de destino usando a máscara especificada e a operação de rasterização.

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
O identificador para o módulo cujo executável contém o recurso.

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
A coordenada y lógica do canto superior esquerdo do bitmap de origem.

*hbmMask*<br/>
Identificador para o bitmap de máscara monocromática combinado com o bitmap de cor no contexto do dispositivo de origem.

*xMask*<br/>
O deslocamento de pixel horizontal para o bitmap de máscara especificado pelo parâmetro *hbmMask* .

*yMask*<br/>
O deslocamento de pixel vertical para o bitmap de máscara especificado pelo parâmetro *hbmMask* .

*dwROP*<br/>
Especifica os códigos de operação de rasterização de primeiro plano e de fundo ternário que o método usa para controlar a combinação de dados de origem e de destino. O código da operação rasterizada em segundo plano é armazenado no byte de ordem superior da palavra de ordem superior desse valor; o código de operação de varredura em primeiro plano é armazenado no byte de ordem inferior da palavra de ordem superior desse valor; a palavra de ordem inferior desse valor é ignorada e deve ser zero. Para obter uma discussão do primeiro plano e do plano de fundo no contexto desse `MaskBlt` método, consulte na SDK do Windows. Para obter uma lista de códigos de operação de varredura `BitBlt` comuns, consulte na SDK do Windows.

*rectDest*<br/>
Uma referência a uma `RECT` estrutura, identificando o destino.

*pointSrc*<br/>
Uma `POINT` estrutura que indica o canto superior esquerdo do retângulo de origem.

*pointMask*<br/>
Uma `POINT` estrutura que indica o canto superior esquerdo do bitmap de máscara.

*pointDest*<br/>
Uma referência a uma `POINT` estrutura que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Esse método se aplica somente ao Windows NT, às versões 4,0 e posteriores.

##  <a name="operator_hbitmap"></a>Operador CImage:: Operator HBITMAP

Use esse operador para obter o identificador GDI do Windows anexado do `CImage` objeto. Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HBITMAP.

##  <a name="plgblt"></a>  CImage::PlgBlt

Executa uma transferência de bloco de bits de um retângulo em um contexto de dispositivo de origem para um paralelogramo em um contexto de dispositivo de destino.

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
Um identificador para o contexto do dispositivo de destino.

*pPoints*<br/>
Um ponteiro para uma matriz de três pontos no espaço lógico que identifica três cantos do paralelogramo de destino. O canto superior esquerdo do retângulo de origem é mapeado para o primeiro ponto dessa matriz, o canto superior direito para o segundo ponto nessa matriz e o canto inferior esquerdo para o terceiro ponto. O canto inferior direito do retângulo de origem é mapeado para o quarto ponto implícito no paralelogramo.

*hbmMask*<br/>
Um identificador para um bitmap monocromático opcional que é usado para mascarar as cores do retângulo de origem.

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
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) que especifica as coordenadas do retângulo de origem.

*pointMask*<br/>
Uma estrutura de [ponto](/previous-versions/dd162805\(v=vs.85\)) que indica o canto superior esquerdo do bitmap de máscara.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Se *hbmMask* identificar um bitmap monocromático válido, `PlgBit` o usará esse bitmap para mascarar os bits de dados de cor do retângulo de origem.

Esse método se aplica somente ao Windows NT, às versões 4,0 e posteriores. Consulte [PlgBlt](/windows/win32/api/wingdi/nf-wingdi-plgblt) no SDK do Windows para obter informações mais detalhadas.

##  <a name="releasedc"></a>  CImage::ReleaseDC

Libera o contexto do dispositivo.

```
void ReleaseDC() const throw();
```

### <a name="remarks"></a>Comentários

Como apenas um bitmap pode ser selecionado em um contexto de dispositivo de cada vez, você deve `ReleaseDC` chamar para cada chamada para [GetDC](#getdc).

##  <a name="releasegdiplus"></a>  CImage::ReleaseGDIPlus

Libera recursos usados pelo GDI+.

```
void ReleaseGDIPlus() throw();
```

### <a name="remarks"></a>Comentários

Esse método deve ser chamado para liberar recursos alocados por um `CImage` objeto global. Consulte [CImage:: CImage](#cimage).

##  <a name="save"></a>CImage:: salvar

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
Um ponteiro para um objeto de IStream COM que contém os dados de imagem de arquivo.

*pszFileName*<br/>
Um ponteiro para o nome de arquivo da imagem.

*guidFileType*<br/>
O tipo de arquivo para salvar a imagem. Pode ser um dos seguintes:

- `ImageFormatBMP`Uma imagem de bitmap descompactada.

- `ImageFormatPNG`Uma imagem compactada do PNG (gráfico de rede portátil).

- `ImageFormatJPEG`Uma imagem compactada JPEG.

- `ImageFormatGIF`Uma imagem compactada por GIF.

> [!NOTE]
> Para obter uma lista completa de constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Chame essa função para salvar a imagem usando um nome e tipo especificados. Se o parâmetro *guidFileType* não for incluído, a extensão de arquivo do nome do arquivo será usada para determinar o formato da imagem. Se nenhuma extensão for fornecida, a imagem será salva no formato BMP.

##  <a name="setcolortable"></a>  CImage::SetColorTable

Define os valores de cor vermelho, verde e azul (RGB) para um intervalo de entradas na paleta da seção DIB.

```
void SetColorTable(
    UINT iFirstColor,
    UINT nColors,
    const RGBQUAD* prgbColors) throw();
```

### <a name="parameters"></a>Parâmetros

*iFirstColor*<br/>
O índice da tabela de cores da primeira entrada a ser definida.

*nColors*<br/>
O número de entradas da tabela de cores a serem definidas.

*prgbColors*<br/>
Um ponteiro para a matriz de estruturas [RGBQUAD](/windows/win32/api/wingdi/ns-wingdi-rgbquad) para definir as entradas da tabela de cores.

### <a name="remarks"></a>Comentários

Este método dá suporte apenas a bitmaps de seção DIB.

##  <a name="setpixel"></a>  CImage::SetPixel

Define a cor de um pixel em um determinado local no bitmap.

```
void SetPixel(int x, int y, COLORREF color) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O local horizontal do pixel a ser definido.

*y*<br/>
O local vertical do pixel a ser definido.

*color*<br/>
A cor para a qual você define o pixel.

### <a name="remarks"></a>Comentários

Esse método falhará se as coordenadas de pixel estiverem fora da região de recorte selecionada.

##  <a name="setpixelindexed"></a>  CImage::SetPixelIndexed

Define a cor de pixel para a cor localizada em *iIndex* na paleta de cores.

```
void SetPixelIndexed(int x, int y, int iIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O local horizontal do pixel a ser definido.

*y*<br/>
O local vertical do pixel a ser definido.

*iIndex*<br/>
O índice de uma cor na paleta de cores.

##  <a name="setpixelrgb"></a>  CImage::SetPixelRGB

Define o pixel nos locais especificados por *x* e *y* com as cores indicadas por *r*, *g*e *b*, em uma imagem vermelha, verde, azul (RGB).

```
void SetPixelRGB(
    int x,
    int y,
    BYTE r,
    BYTE g,
    BYTE b) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O local horizontal do pixel a ser definido.

*y*<br/>
O local vertical do pixel a ser definido.

*r*<br/>
A intensidade da cor vermelha.

*g*<br/>
A intensidade da cor verde.

*b*<br/>
A intensidade da cor azul.

### <a name="remarks"></a>Comentários

Os parâmetros vermelho, verde e azul são representados por um número entre 0 e 255. Se você definir todos os três parâmetros como zero, a cor resultante combinada será preta. Se você definir todos os três parâmetros como 255, a cor resultante combinada será branca.

##  <a name="settransparentcolor"></a>  CImage::SetTransparentColor

Define uma cor em um determinado local indexado como transparente.

```
LONG SetTransparentColor(LONG iTransparentColor) throw();
```

### <a name="parameters"></a>Parâmetros

*iTransparentColor*<br/>
O índice, em uma paleta de cores, da cor a ser definida como transparente. Se-1, nenhuma cor será definida como transparente.

### <a name="return-value"></a>Valor de retorno

O índice da cor definido anteriormente como transparente.

##  <a name="stretchblt"></a>  CImage::StretchBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto do dispositivo atual.

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
Um identificador para o contexto do dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*dwROP*<br/>
A operação de varredura a ser executada. Os códigos de operação de varredura definem exatamente como combinar os bits da origem, o destino e o padrão (conforme definido pelo pincel selecionado no momento) para formar o destino. Consulte [BitBlt](/windows/win32/api/wingdi/nf-wingdi-bitblt) no SDK do Windows para obter uma lista de outros códigos de operação de varredura e suas descrições.

*rectDest*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) , identificando o destino.

*xSrc*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectSrc*<br/>
Uma referência a uma `RECT` estrutura, identificando a origem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido, caso contrário 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [StretchBlt](/windows/win32/api/wingdi/nf-wingdi-stretchblt) no SDK do Windows.

##  <a name="transparentblt"></a>  CImage::TransparentBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto do dispositivo atual.

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
Um identificador para o contexto do dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*crTransparent*<br/>
A cor no bitmap de origem a ser tratada como transparente. Por padrão, CLR_INVALID, indicando que a cor definida atualmente como a cor transparente da imagem deve ser usada.

*rectDest*<br/>
Uma referência a uma estrutura [Rect](/previous-versions/dd162897\(v=vs.85\)) , identificando o destino.

*xSrc*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectSrc*<br/>
Uma referência a uma `RECT` estrutura, identificando a origem.

### <a name="return-value"></a>Valor de retorno

TRUE se for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`TransparentBlt`tem suporte para bitmaps de origem de 4 bits por pixel e 8 bits por pixel. Use [CImage:: AlphaBlend](#alphablend) para especificar os bitmaps de 32 bits por pixel com transparência.

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

## <a name="see-also"></a>Consulte também

[Exemplo de MMXSwarm](../../overview/visual-cpp-samples.md)<br/>
[Exemplo de SimpleImage](../../overview/visual-cpp-samples.md)<br/>
[Bitmaps independentes de dispositivo](/windows/win32/gdi/device-independent-bitmaps)<br/>
[CreateDIBSection](/windows/win32/api/wingdi/nf-wingdi-createdibsection)<br/>
[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)<br/>
[Bitmaps independentes de dispositivo](/windows/win32/gdi/device-independent-bitmaps)<br/>
[CreateDIBSection](/windows/win32/api/wingdi/nf-wingdi-createdibsection)
