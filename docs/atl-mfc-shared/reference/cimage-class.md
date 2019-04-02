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
ms.openlocfilehash: 14a4691e0c1f25a8f9e8b2b652c6e582f51c954a
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58775940"
---
# <a name="cimage-class"></a>Classe CImage

`CImage` fornece suporte a bitmap aprimorada, incluindo a capacidade de carregar e salvar imagens em formatos GIF, JPEG, BMP e elementos gráficos PNG (Portable Network).

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

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
|[CImage::AlphaBlend](#alphablend)|Exibe os bitmaps que possuem pixels transparentes ou semitransparentes.|
|[CImage::Attach](#attach)|Anexa um HBITMAP para um `CImage` objeto. Pode ser usado com bitmaps de seção não DIB ou bitmaps de seção DIB.|
|[CImage::BitBlt](#bitblt)|Copia um bitmap do contexto do dispositivo de origem para este contexto de dispositivo atual.|
|[CImage::Create](#create)|Cria um bitmap de seção DIB e a anexa ao anteriormente construído `CImage` objeto.|
|[CImage::CreateEx](#createex)|Cria um bitmap de seção DIB (com parâmetros adicionais) e a anexa ao anteriormente construído `CImage` objeto.|
|[CImage::Destroy](#destroy)|Desanexa o bitmap a partir de `CImage` do objeto e destrói o bitmap.|
|[CImage::Detach](#detach)|Desanexa o bitmap de um `CImage` objeto.|
|[CImage::Draw](#draw)|Copia um bitmap de um retângulo de origem em um retângulo de destino. `Draw` Alonga ou compacta o bitmap para se ajustar às dimensões do retângulo de destino, se necessário e lida com a combinação alfa e cores transparentes.|
|[CImage::GetBits](#getbits)|Recupera um ponteiro para os valores reais de pixel do bitmap.|
|[CImage::GetBPP](#getbpp)|Recupera os bits por pixel.|
|[CImage::GetColorTable](#getcolortable)|Recupera os valores de cor vermelhos, verdes e azuis (RGB) de um intervalo de entradas na tabela de cores.|
|[CImage::GetDC](#getdc)|Recupera o contexto de dispositivo no qual o bitmap atual está selecionado.|
|[CImage::GetExporterFilterString](#getexporterfilterstring)|Localiza os formatos de imagem disponíveis e suas descrições.|
|[CImage::GetHeight](#getheight)|Recupera a altura da imagem atual em pixels.|
|[CImage::GetImporterFilterString](#getimporterfilterstring)|Localiza os formatos de imagem disponíveis e suas descrições.|
|[CImage::GetMaxColorTableEntries](#getmaxcolortableentries)|Recupera o número máximo de entradas na tabela de cores.|
|[CImage::GetPitch](#getpitch)|Recupera o tom da imagem atual, em bytes.|
|[CImage::GetPixel](#getpixel)|Recupera a cor do pixel especificado por *x* e *y*.|
|[CImage::GetPixelAddress](#getpixeladdress)|Recupera o endereço de um determinado pixel.|
|[CImage::GetTransparentColor](#gettransparentcolor)|Recupera a posição da cor transparente na tabela de cores.|
|[CImage::GetWidth](#getwidth)|Recupera a largura da imagem atual em pixels.|
|[CImage::IsDIBSection](#isdibsection)|Determina se o bitmap anexado é uma seção DIB.|
|[CImage::IsIndexed](#isindexed)|Indica que as cores do bitmap são mapeadas para uma paleta indexada.|
|[CImage::IsNull](#isnull)|Indica se um bitmap de origem está carregado no momento.|
|[CImage::IsTransparencySupported](#istransparencysupported)|Indica se o aplicativo dá suporte a bitmaps transparentes.|
|[CImage::Load](#load)|Carrega uma imagem do arquivo especificado.|
|[CImage::LoadFromResource](#loadfromresource)|Carrega uma imagem do recurso especificado.|
|[CImage::MaskBlt](#maskblt)|Combina os dados de cor para bitmaps de origem e de destino usando a máscara especificada e a operação de varredura.|
|[CImage::PlgBlt](#plgblt)|Executa uma transferência de bloco de bits de um retângulo em um contexto de dispositivo de origem em um paralelogramo em um contexto de dispositivo de destino.|
|[CImage::ReleaseDC](#releasedc)|Libera o contexto de dispositivo que foi recuperado com [CImage::GetDC](#getdc).|
|[CImage::ReleaseGDIPlus](#releasegdiplus)|Libera recursos usados pelo GDI+. Deve ser chamado para liberar recursos criados por um global `CImage` objeto.|
|[CImage::Save](#save)|Salva uma imagem como o tipo especificado. `Save` não é possível especificar opções de imagem.|
|[CImage::SetColorTable](#setcolortable)|Define RGB de vermelho, verde, azul) valores em um intervalo de entradas na tabela de cores da seção DIB de cor.|
|[CImage::SetPixel](#setpixel)|Define o pixel nas coordenadas especificadas com a cor especificada.|
|[CImage::SetPixelIndexed](#setpixelindexed)|Define o pixel nas coordenadas especificadas para a cor do índice especificado da paleta.|
|[CImage::SetPixelRGB](#setpixelrgb)|Define o pixel nas coordenadas especificadas ao valor especificado de vermelho, verde, azul (RGB).|
|[CImage::SetTransparentColor](#settransparentcolor)|Define o índice da cor deve ser tratada como transparente. Apenas uma cor em uma paleta pode ser transparente.|
|[CImage::StretchBlt](#stretchblt)|Copia um bitmap de um retângulo de origem em um retângulo de destino, alongando-o ou compactando-o para se ajustar às dimensões do retângulo de destino, se necessário.|
|[CImage::TransparentBlt](#transparentblt)|Copia um bitmap com cor transparente do contexto do dispositivo de origem para este contexto de dispositivo atual.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CImage::operator HBITMAP](#operator_hbitmap)|Retorna o identificador do Windows anexado ao `CImage` objeto.|

## <a name="remarks"></a>Comentários

`CImage` usa os bitmaps são ambos seções independentes de dispositivo DIB (bitmap) ou não; No entanto, você pode usar [Create](#create) ou [CImage::Load](#load) com apenas pelas seções DIB. Você pode anexar um bitmap de seção não DIB para um `CImage` do objeto usando [Attach](#attach), mas, em seguida, você não pode usar o seguinte `CImage` métodos, que oferecem suporte a somente os bitmaps de seção DIB:

- [GetBits](#getbits)

- [GetColorTable](#getcolortable)

- [GetMaxColorTableEntries](#getmaxcolortableentries)

- [GetPitch](#getpitch)

- [GetPixelAddress](#getpixeladdress)

- [IsIndexed](#isindexed)

- [SetColorTable](#setcolortable)

Para determinar se um bitmap anexado é uma seção DIB, chame [IsDibSection](#isdibsection).

> [!NOTE]
> No Visual Studio .NET 2003, essa classe mantém uma contagem do número de `CImage` objetos criados. Sempre que a contagem chegar a 0, a função `GdiplusShutdown` é chamado automaticamente para liberar recursos usados pelo GDI+. Isso garante que qualquer `CImage` objetos criados diretamente ou indiretamente por DLLs sempre são destruídos corretamente e que `GdiplusShutdown` não é chamado de `DllMain`.

> [!NOTE]
> Usando global `CImage` objetos em uma DLL não é recomendado. Se você precisar usar global `CImage` objeto em uma DLL, chamada [CImage::ReleaseGDIPlus](#releasegdiplus) liberar explicitamente os recursos usados pelo GDI+.

`CImage` não pode ser selecionado em uma nova [CDC](../../mfc/reference/cdc-class.md). `CImage` cria seu próprio HDC para a imagem. Porque um HBITMAP só pode ser selecionado em um HDC por vez, o HBITMAP associado com o `CImage` não podem ser selecionados em outra HDC. Se você precisar de uma de CDC, recupere o HDC do `CImage` e dê a ele [CDC::FromHandle] (... /.. /MFC/Reference/CDC-Class.MD#cdc__fromhandle.

## <a name="example"></a>Exemplo

```cpp
// Get a CDC for the image
CDC* pDC = CDC::FromHandle(m_myImage.GetDC());

// Use pDC here
pDC->Rectangle(0, 40, 100, 50);
m_myImage.ReleaseDC();
```

Quando você usa `CImage` em um projeto MFC, observe quais funções de membro em seu projeto esperam um ponteiro para uma [CBitmap](../../mfc/reference/cbitmap-class.md) objeto. Se você quiser usar `CImage` com uma função, como [CMenu::AppendMenu](../../mfc/reference/cmenu-class.md#appendmenu), use [CBitmap::FromHandle](../../mfc/reference/cbitmap-class.md#fromhandle), passá-lo seu `CImage` HBITMAP e usar retornado `CBitmap*`.

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

Por meio de `CImage`, você tem acesso aos bits reais de uma seção DIB. Você pode usar um `CImage` objeto em qualquer lugar, você usou anteriormente uma seção HBITMAP Win32 ou DIB.

Você pode usar `CImage` do MFC ou ATL.

> [!NOTE]
> Quando você cria um projeto usando `CImage`, você deve definir `CString` antes de incluir `atlimage.h`. Se seu projeto usa ATL sem MFC, inclua `atlstr.h` antes de incluir `atlimage.h`. Se seu projeto usa o MFC (ou se ele é um projeto ATL com suporte do MFC), inclua `afxstr.h` antes de incluir `atlimage.h`.<br/>
> <br/>
> Da mesma forma, você deve incluir `atlimage.h` antes de incluir `atlimpl.cpp`. Para fazer isso facilmente, incluir `atlimage.h` em seu `stdafx.h`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlimage.h

##  <a name="alphablend"></a>  CImage::AlphaBlend

Exibe os bitmaps que possuem pixels transparentes ou semitransparentes.

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
Identificador para o contexto de dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*bSrcAlpha*<br/>
Um valor de transparência alfa a ser usado o bitmap de origem inteira. O padrão de 0xff (255) pressupõe que sua imagem é opaca e que você deseja usar valores alfa por pixel apenas.

*bBlendOp*<br/>
A função de combinação alfa para origem e bitmaps de destino, um valor alfa global a ser aplicada ao bitmap de origem inteira e informações de formato para o bitmap de origem. As funções de mistura de origem e destino estão limitadas a AC_SRC_OVER.

*pointDest*<br/>
Uma referência a um [ponto](/previous-versions/dd162805\(v=vs.85\)) estrutura que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*xSrc*<br/>
A lógica coordenada x do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A lógica coordenada y do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectDest*<br/>
Uma referência a um [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura, identificando o destino.

*rectSrc*<br/>
Uma referência a um `RECT` estrutura, identificando a origem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Combinação alfa bitmaps dão suporte a cores de mesclagem em uma base por pixel.

Quando *bBlendOp* é definido como o padrão de AC_SRC_OVER, o bitmap de origem é colocado sobre o bitmap de destino com base nos valores alfabéticos de pixels de origem.

##  <a name="attach"></a>  CImage::Attach

Anexa *hBitmap* para um `CImage` objeto.

```
void Attach(HBITMAP hBitmap, DIBOrientation eOrientation = DIBOR_DEFAULT) throw();
```

### <a name="parameters"></a>Parâmetros

*hBitmap*<br/>
Um identificador para um HBITMAP.

*eOrientation*<br/>
Especifica a orientação do bitmap. Pode ser uma das seguintes opções:

- DIBOR_DEFAULT a orientação do bitmap é determinado pelo sistema operacional.

- DIBOR_BOTTOMUP as linhas do bitmap estão na ordem inversa. Isso faz com que [CImage::GetBits](#getbits) para retornar um ponteiro perto do fim do buffer de bitmap e [CImage::GetPitch](#getpitch) para retornar um número negativo.

- DIBOR_TOPDOWN as linhas do bitmap são na parte superior para a parte inferior. Isso faz com que [CImage::GetBits](#getbits) para retornar um ponteiro para o primeiro byte do buffer de bitmap e [CImage::GetPitch](#getpitch) para retornar um número positivo.

### <a name="remarks"></a>Comentários

O bitmap pode ser um bitmap de seção não DIB ou um bitmap da seção DIB. Ver [IsDIBSection](#isdibsection) para obter uma lista dos métodos que você pode usar apenas com DIB seção bitmaps.

##  <a name="bitblt"></a>  CImage::BitBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto de dispositivo atual.

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
A lógica coordenada x do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A lógica coordenada y do canto superior esquerdo do retângulo de destino.

*dwROP*<br/>
A operação de varredura a ser executada. Códigos de operação de varredura definem como combinar os bits do código-fonte, o destino e o padrão (conforme definido pelo pincel selecionado no momento) para formar o destino. Ver [BitBlt](/windows/desktop/api/wingdi/nf-wingdi-bitblt) no SDK do Windows para obter uma lista de outros códigos de operação de varredura e suas descrições.

*pointDest*<br/>
Um [ponto](/previous-versions/dd162805\(v=vs.85\)) estrutura que indica o canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*xSrc*<br/>
A lógica coordenada x do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A lógica coordenada y do canto superior esquerdo do retângulo de origem.

*rectDest*<br/>
Um [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura indicando o retângulo de destino.

*pointSrc*<br/>
Um `POINT` estrutura que indica o canto superior esquerdo do retângulo de origem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, zero.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [BitBlt](/windows/desktop/api/wingdi/nf-wingdi-bitblt) no SDK do Windows.

##  <a name="cimage"></a>  CImage::CImage

Constrói um objeto `CImage`.

```
CImage() throw();
```

### <a name="remarks"></a>Comentários

Após você ter criado o objeto, chame [Create](#create), [Load](#load), [LoadFromResource](#loadfromresource), ou [Attach](#attach) para anexar um bitmap para o objeto.

**Observação** no Visual Studio, essa classe mantém uma contagem do número de `CImage` objetos criados. Sempre que a contagem chegar a 0, a função `GdiplusShutdown` é chamado automaticamente para liberar recursos usados pelo GDI+. Isso garante que qualquer `CImage` objetos criados diretamente ou indiretamente por DLLs sempre são destruídos corretamente e que `GdiplusShutdown` não é chamado a partir da DllMain.

Usando global `CImage` objetos em uma DLL não é recomendado. Se você precisar usar global `CImage` objeto em uma DLL, chamada [CImage::ReleaseGDIPlus](#releasegdiplus) liberar explicitamente os recursos usados pelo GDI+.

##  <a name="create"></a>  CImage::Create

Cria uma `CImage` bitmap e anexá-lo a anteriormente construído `CImage` objeto.

```
BOOL Create(
    int nWidth,
    int nHeight,
    int nBPP,
    DWORD dwFlags = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*nWidth*<br/>
A largura do `CImage` bitmap em pixels.

*nHeight*<br/>
A altura do `CImage` bitmap em pixels. Se *nHeight* for positivo, o bitmap for um DIB de baixo para cima e sua origem é o canto inferior esquerdo. Se *nHeight* é negativo, o bitmap for um DIB de cima para baixo e sua origem é o canto superior esquerdo.

*nBPP*<br/>
Os números de bits por pixel no bitmap. Normalmente, 4, 8, 16, 24 ou 32. Pode ser 1 para bitmaps monocromático ou máscaras.

*dwFlags*<br/>
Especifica se o objeto de bitmap tem um canal alfa. Pode ser uma combinação de zero ou mais dos seguintes valores:

- *createAlphaChannel* só pode ser usado se *nBPP* é 32, e *eCompression* é BI_RGB. Se for especificado, a imagem criada tem um valor de alfa (transparência) para cada pixel, armazenada em do 4º byte de cada pixel (não usado em uma imagem de 32 bits não alfanuméricos). Esse canal alfa automaticamente é usado ao chamar [CImage::AlphaBlend](#alphablend).

> [!NOTE]
> Em chamadas para [CImage::Draw](#draw), as imagens com um canal alfa são automaticamente alfa combinada ao destino.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

##  <a name="createex"></a>  CImage::CreateEx

Cria uma `CImage` bitmap e anexá-lo a anteriormente construído `CImage` objeto.

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
A largura do `CImage` bitmap em pixels.

*nHeight*<br/>
A altura do `CImage` bitmap em pixels. Se *nHeight* for positivo, o bitmap for um DIB de baixo para cima e sua origem é o canto inferior esquerdo. Se *nHeight* é negativo, o bitmap for um DIB de cima para baixo e sua origem é o canto superior esquerdo.

*nBPP*<br/>
Os números de bits por pixel no bitmap. Normalmente, 4, 8, 16, 24 ou 32. Pode ser 1 para bitmaps monocromático ou máscaras.

*eCompression*<br/>
Especifica o tipo de compactação para um bitmap de baixo para cima compactado (DIBs de cima para baixo não podem ser compactadas). pode ser um dos seguintes valores:

- O formato BI_RGB é descompactado. A especificação desse valor ao chamar `CImage::CreateEx` é equivalente a chamar `CImage::Create`.

- BI_BITFIELDS o formato é descompactado e a tabela de cores consiste em três máscaras de cor DWORD que especificam os componentes vermelhos, verdes e azuis, respectivamente, de cada pixel. Isso é válido quando usado com bitmaps de 16 e 32 bpp.

*pdwBitfields*<br/>
Usado somente se *eCompression* é definido para BI_BITFIELDS, caso contrário, ele deve ser NULL. Um ponteiro para uma matriz de três bitmasks DWORD, especificando os bits de cada pixel são usados para os componentes vermelhos, verdes e azuis da cor, respectivamente. Para obter informações sobre as restrições para os campos de bits, consulte [BITMAPINFOHEADER](https://msdn.microsoft.com/library/windows/desktop/dd183376) no SDK do Windows.

*dwFlags*<br/>
Especifica se o objeto de bitmap tem um canal alfa. Pode ser uma combinação de zero ou mais dos seguintes valores:

- *createAlphaChannel* só pode ser usado se *nBPP* é 32, e *eCompression* é BI_RGB. Se for especificado, a imagem criada tem um valor de alfa (transparência) para cada pixel, armazenada em do 4º byte de cada pixel (não usado em uma imagem de 32 bits não alfanuméricos). Esse canal alfa automaticamente é usado ao chamar [CImage::AlphaBlend](#alphablend).

   > [!NOTE]
   > Em chamadas para [CImage::Draw](#draw), as imagens com um canal alfa são automaticamente alfa combinada ao destino.

### <a name="return-value"></a>Valor de retorno

VERDADEIRO se bem-sucedido. Caso contrário, FALSE.

### <a name="example"></a>Exemplo

O exemplo a seguir cria um bitmap de 100 x 100 pixels, usando os 16 bits para codificar cada pixel. Em um determinado pixel de 16 bits, bits de 0 a 3 codificar o componente vermelho, verde de codificar de bits de 4 a 7 e bits de 8 a 11 codificam o azul. Os 4 bits restantes não são utilizados.

```cpp
DWORD adwBitmasks[3] = { 0x0000000f, 0x000000f0, 0x00000f00 };
m_myImage.CreateEx(100, 100, 16, BI_BITFIELDS, adwBitmasks, 0);
```

##  <a name="destroy"></a>  CImage::Destroy

Desanexa o bitmap a partir de `CImage` do objeto e destrói o bitmap.

```
void Destroy() throw();
```

##  <a name="detach"></a>  CImage::Detach

Desanexa um bitmap de um `CImage` objeto.

```
HBITMAP Detach() throw();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para o bitmap desanexado ou nulo se nenhum bitmap está anexado.

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
Um identificador para o contexto de dispositivo de destino.

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
Uma referência a um [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura, identificando o destino.

*rectSrc*<br/>
Uma referência a um `RECT` estrutura, identificando a origem.

*pointDest*<br/>
Uma referência a um [ponto](/previous-versions/dd162805\(v=vs.85\)) estrutura que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se bem-sucedido; Caso contrário, 0.

### <a name="remarks"></a>Comentários

`Draw` executa a mesma operação que [StretchBlt](#stretchblt), a menos que a imagem contém uma cor transparente ou um canal alfa. Nesse caso, `Draw` executa a mesma operação como [TransparentBlt](#transparentblt) ou [AlphaBlend](#alphablend) conforme necessário.

Para versões do `Draw` que não especificam um retângulo de origem, a imagem de origem inteiro é o padrão. Para obter a versão de `Draw` que não especifique um tamanho para o retângulo de destino, o tamanho da imagem de origem é o padrão e nenhuma ampliação ou redução ocorre.

##  <a name="getbits"></a>  CImage::GetBits

Recupera um ponteiro para os valores de bits real de um determinado pixel no bitmap.

```
void* GetBits() throw();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o buffer de bitmap. Se o bitmap for um DIB de baixo para cima, o ponteiro aponta perto do final do buffer. Se o bitmap for um DIB de cima para baixo, o ponteiro aponta para o primeiro byte do buffer.

### <a name="remarks"></a>Comentários

Usando esse ponteiro, juntamente com o valor retornado por [GetPitch](#getpitch), você pode localizar e alterar os pixels individuais em uma imagem.

> [!NOTE]
> Esse método dá suporte a somente os bitmaps de seção DIB; Consequentemente, você pode acessar os pixels de um `CImage` da mesma maneira que faria com os pixels de uma seção DIB do objeto. O ponteiro retornado aponta para o pixel no local (0, 0).

##  <a name="getbpp"></a>  CImage::GetBPP

Recupera o valor de bits por pixel.

```
int GetBPP() const throw();
```

### <a name="return-value"></a>Valor de retorno

O número de bits por pixel.

### <a name="remarks"></a>Comentários

Esse valor determina o número de bits que definem cada pixel e o número máximo de cores no bitmap.

Geralmente, os bits por pixel é 1, 4, 8, 16, 24 ou 32. Consulte a `biBitCount` membro [BITMAPINFOHEADER](https://msdn.microsoft.com/library/windows/desktop/dd183376) no SDK do Windows para obter mais informações sobre esse valor.

##  <a name="getcolortable"></a>  CImage::GetColorTable

Recupera os valores de cor vermelhos, verdes e azuis (RGB) de um intervalo de entradas da paleta da seção DIB.

```
void GetColorTable(
    UINT iFirstColor,
    UINT nColors,
    RGBQUAD* prgbColors) const throw();
```

### <a name="parameters"></a>Parâmetros

*iFirstColor*<br/>
O índice da tabela de cores da primeira entrada para recuperar.

*nColors*<br/>
O número de entradas de tabela de cores para recuperar.

*prgbColors*<br/>
Um ponteiro para a matriz de [RGBQUAD](/windows/desktop/api/wingdi/ns-wingdi-tagrgbquad) estruturas para recuperar a cor de entradas de tabela.

##  <a name="getdc"></a>  CImage::GetDC

Recupera o contexto de dispositivo que tem no momento, a imagem selecionada para ele.

```
HDC GetDC() const throw();
```

### <a name="return-value"></a>Valor de retorno

Um identificador para um contexto de dispositivo.

### <a name="remarks"></a>Comentários

Para cada chamada para `GetDC`, você deve ter uma chamada posterior ao [ReleaseDC](#releasedc).

##  <a name="getexporterfilterstring"></a>  CImage::GetExporterFilterString

Localiza os formatos de imagem disponível para salvar as imagens.

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
Uma referência a um objeto `CSimpleString`. Ver **comentários** para obter mais informações.

*aguidFileTypes*<br/>
Uma matriz de GUIDs, com cada elemento que corresponde a um dos tipos de arquivo na cadeia de caracteres. No exemplo na *pszAllFilesDescription* abaixo *aguidFileTypes*[0] é GUID_NULL e os valores restantes da matriz são os formatos de arquivo de imagem compatíveis com o sistema operacional atual.

> [!NOTE]
> Para obter uma lista completa das constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.

*pszAllFilesDescription*<br/>
Se esse parâmetro não for nulo, a cadeia de caracteres de filtro terá um filtro adicional no início da lista. Esse filtro terá o valor atual da *pszAllFilesDescription* para sua descrição e aceita arquivos de qualquer extensão compatíveis com qualquer outro exportador na lista.

Por exemplo:

```cpp
//First filter in the list will be titled "All Image Files", and
//will accept files with any extension supported by any exporter.
CImage::GetExporterFilterString(
    strExporters, aguidFileTypes,
_T("All Image Files"));
```

*dwExclude*<br/>
Conjunto de sinalizadores de bit especificando quais tipos de arquivo a ser excluído da lista. Sinalizadores permitidos são:

- `excludeGIF` = 0x01 arquivos de GIF exclui.

- `excludeBMP` = 0x02 arquivos de exclui BMP (Bitmap do Windows).

- `excludeEMF` = 0x04 arquivos de exclui EMF (metarquivo avançado).

- `excludeWMF` = arquivos do 0x08 exclui WMF (Windows Metafile).

- `excludeJPEG` = arquivos de JPEG exclui 0x10.

- `excludePNG` = arquivos de PNG exclui 0x20.

- `excludeTIFF` = arquivos de TIFF exclui 0x40.

- `excludeIcon` = arquivos do 0x80 exclui ICO (ícone do Windows).

- `excludeOther` = 0x80000000 exclui qualquer outro tipo de arquivo não listado acima.

- `excludeDefaultLoad` = 0 para o arquivo de todos os tipos são incluídos por padrão de carga

- `excludeDefaultSave` = `excludeIcon &#124; excludeEMF &#124; excludeWMF` Para salvar, esses arquivos são excluídos por padrão, pois eles geralmente têm requisitos especiais.

*chSeparator*<br/>
O separador usado entre os formatos de imagem. Ver **comentários** para obter mais informações.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Você pode passar a cadeia de caracteres de formato resultante para o MFC [CFileDialog](../../mfc/reference/cfiledialog-class.md) formatos de objetos para expor as extensões de arquivo da imagem disponível na caixa de diálogo Salvar arquivo como.

O parâmetro *strExporter* tem o formato:

arquivo description0&#124;\*.ext0&#124;filedescription1&#124;\*. ext1&#124;... descrição do arquivo *n*&#124;\*. ext *n*&#124;&#124;

em que '&#124;' é o caractere separador especificado por `chSeparator`. Por exemplo:

`"Bitmap format|*.bmp|JPEG format|*.jpg|GIF format|*.gif|PNG format|*.png||"`

Use o separador padrão '&#124;' se você passar essa cadeia de caracteres para um MFC `CFileDialog` objeto. Se você passar essa cadeia de caracteres a uma caixa de diálogo comum salvar arquivo, use o separador nulo '\0'.

##  <a name="getheight"></a>  CImage::GetHeight

Recupera a altura, em pixels, de uma imagem.

```
int GetHeight() const throw();
```

### <a name="return-value"></a>Valor de retorno

A altura, em pixels, de uma imagem.

##  <a name="getimporterfilterstring"></a>  CImage::GetImporterFilterString

Localiza os formatos de imagem disponível para carregar imagens.

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
Uma referência a um objeto `CSimpleString`. Ver **comentários** para obter mais informações.

*aguidFileTypes*<br/>
Uma matriz de GUIDs, com cada elemento que corresponde a um dos tipos de arquivo na cadeia de caracteres. No exemplo na *pszAllFilesDescription* abaixo *aguidFileTypes*[0] é GUID_NULL com os valores restantes da matriz são os formatos de arquivo de imagem compatíveis com o sistema operacional atual.

> [!NOTE]
> Para obter uma lista completa das constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.

*pszAllFilesDescription*<br/>
Se esse parâmetro não for nulo, a cadeia de caracteres de filtro terá um filtro adicional no início da lista. Esse filtro terá o valor atual da *pszAllFilesDescription* para sua descrição e aceita arquivos de qualquer extensão compatíveis com qualquer outro exportador na lista.

Por exemplo:

```cpp
//First filter in the list will be titled "All Image Files", and
//will accept files with any extension supported by any importer.
CImage::GetImporterFilterString(
    strImporters, aguidFileTypes,
_T("All Image Files"));
```

*dwExclude*<br/>
Conjunto de sinalizadores de bit especificando quais tipos de arquivo a ser excluído da lista. Sinalizadores permitidos são:

- `excludeGIF` = 0x01 arquivos de GIF exclui.

- `excludeBMP` = 0x02 arquivos de exclui BMP (Bitmap do Windows).

- `excludeEMF` = 0x04 arquivos de exclui EMF (metarquivo avançado).

- `excludeWMF` = arquivos do 0x08 exclui WMF (Windows Metafile).

- `excludeJPEG` = arquivos de JPEG exclui 0x10.

- `excludePNG` = arquivos de PNG exclui 0x20.

- `excludeTIFF` = arquivos de TIFF exclui 0x40.

- `excludeIcon` = arquivos do 0x80 exclui ICO (ícone do Windows).

- `excludeOther` = 0x80000000 exclui qualquer outro tipo de arquivo não listado acima.

- `excludeDefaultLoad` = 0 para o arquivo de todos os tipos são incluídos por padrão de carga

- `excludeDefaultSave` = `excludeIcon &#124; excludeEMF &#124; excludeWMF` Para salvar, esses arquivos são excluídos por padrão, pois eles geralmente têm requisitos especiais.

*chSeparator*<br/>
O separador usado entre os formatos de imagem. Ver **comentários** para obter mais informações.

### <a name="remarks"></a>Comentários

Você pode passar a cadeia de caracteres de formato resultante para o MFC [CFileDialog](../../mfc/reference/cfiledialog-class.md) formatos de objetos para expor as extensões de arquivo da imagem disponível na **abrir arquivo** caixa de diálogo.

O parâmetro *strImporter* tem o formato:

arquivo description0&#124;\*.ext0&#124;filedescription1&#124;\*. ext1&#124;... descrição do arquivo *n*&#124;\*. ext *n*&#124;&#124;

em que '&#124;' é o caractere separador especificado por *chSeparator*. Por exemplo:

`"Bitmap format|*.bmp|JPEG format|*.jpg|GIF format|*.gif|PNG format|*.png||"`

Use o separador padrão '&#124;' se você passar essa cadeia de caracteres para um MFC `CFileDialog` objeto. Use o separador de nulo '\0' se você passar essa cadeia de caracteres para um comum **abrir arquivo** caixa de diálogo.

##  <a name="getmaxcolortableentries"></a>  CImage::GetMaxColorTableEntries

Recupera o número máximo de entradas na tabela de cores.

```
int GetMaxColorTableEntries() const throw();
```

### <a name="return-value"></a>Valor de retorno

O número de entradas na tabela de cores.

### <a name="remarks"></a>Comentários

Esse método dá suporte a somente os bitmaps de seção DIB.

##  <a name="getpitch"></a>  CImage::GetPitch

Recupera o tom de uma imagem.

```
int GetPitch() const throw();
```

### <a name="return-value"></a>Valor de retorno

A densidade da imagem. Se o valor de retorno for negativo, o bitmap for um DIB de baixo para cima e sua origem é o canto inferior esquerdo. Se o valor retornado for positivo, o bitmap for um DIB de cima para baixo e sua origem é o canto superior esquerdo.

### <a name="remarks"></a>Comentários

O tom é a distância, em bytes, entre dois endereços de memória que representam o início da linha de um bitmap e o início da próxima linha do bitmap. Porque o tom é medido em bytes, o tom de uma imagem ajuda a determinar o formato de pixel. O tom também pode incluir a memória adicional, reservada para o bitmap.

Use `GetPitch` com [GetBits](#getbits) para localizar os pixels individuais de uma imagem.

> [!NOTE]
> Esse método dá suporte a somente os bitmaps de seção DIB.

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

O valor (RGB) do vermelho, verde e azul do pixel. Se o pixel estiver fora da região de recorte atual, o valor de retorno é CLR_INVALID.

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

O endereço é determinado de acordo com as coordenadas de um pixel, o tom de bitmap e os bits por pixel.

Para formatos que tenham menos de 8 bits por pixel, esse método retorna o endereço do byte que contém o pixel. Por exemplo, se seu formato de imagem tem 4 bits por pixel, `GetPixelAddress` retorna o endereço do primeiro pixel no byte e você deve calcular para 2 pixels por byte.

> [!NOTE]
> Esse método dá suporte a somente os bitmaps de seção DIB.

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

A largura do bitmap em pixels.

##  <a name="isdibsection"></a>  CImage::IsDIBSection

Determina se o bitmap anexado é uma seção DIB.

```
bool IsDIBSection() const throw();
```

### <a name="return-value"></a>Valor de retorno

TRUE se o bitmap anexado é uma seção DIB. Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se o bitmap não é uma seção DIB, será possível usar o seguinte `CImage` métodos, que oferecem suporte a somente os bitmaps de seção DIB:

- [GetBits](#getbits)

- [GetColorTable](#getcolortable)

- [GetMaxColorTableEntries](#getmaxcolortableentries)

- [GetPitch](#getpitch)

- [GetPixelAddress](#getpixeladdress)

- [IsIndexed](#isindexed)

- [SetColorTable](#setcolortable)

##  <a name="isindexed"></a>  CImage::IsIndexed

Determina se os pixels do bitmap são mapeados para uma paleta de cores.

```
bool IsIndexed() const throw();
```

### <a name="return-value"></a>Valor de retorno

TRUE se indexadas; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método retornará TRUE somente se o bitmap é de 8 bits (256 cores) ou menos.

> [!NOTE]
> Esse método dá suporte a somente os bitmaps de seção DIB.

##  <a name="isnull"></a>  CImage::IsNull

Determina se um bitmap é carregado no momento.

```
bool IsNull() const throw();
```

### <a name="remarks"></a>Comentários

Esse método retornará TRUE se um bitmap não está carregado no momento; Caso contrário, FALSE.

##  <a name="istransparencysupported"></a>  CImage::IsTransparencySupported

Indica se o aplicativo dá suporte a bitmaps transparentes.

```
static BOOL IsTransparencySupported() throw();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a plataforma atual dá suporte à transparência. Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se o valor de retorno é diferente de zero, e suporte à transparência, uma chamada para [AlphaBlend](#alphablend), [TransparentBlt](#transparentblt), ou [desenhar](#draw) manipulará cores transparentes.

##  <a name="load"></a>  CImage::Load

Carrega uma imagem.

```
HRESULT Load(LPCTSTR pszFileName) throw();
HRESULT Load(IStream* pStream) throw();
```

### <a name="parameters"></a>Parâmetros

*pszFileName*<br/>
Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo de imagem para carregar.

*pStream*<br/>
Um ponteiro para um fluxo que contém o nome do arquivo de imagem para carregar.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Carrega a imagem especificada pela *pszFileName* ou *pStream*.

Tipos de imagem válidos são BMP, GIF, JPEG, PNG e TIFF.

##  <a name="loadfromresource"></a>  CImage::LoadFromResource

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
Identificador para uma instância do módulo que contém a imagem a ser carregado.

*pszResourceName*<br/>
Um ponteiro para a cadeia de caracteres que contém o nome do recurso que contém a imagem a ser carregada.

*nIDResource*<br/>
A ID do recurso para carregar.

### <a name="remarks"></a>Comentários

O recurso deve ser do tipo de BITMAP.

##  <a name="maskblt"></a>  CImage::MaskBlt

Combina os dados de cor para bitmaps de origem e de destino usando a máscara especificada e a operação de varredura.

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
A largura, em unidades lógicas, do bitmap retângulo e a fonte de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do bitmap retângulo e a fonte de destino.

*xSrc*<br/>
A lógica coordenada x do canto superior esquerdo do bitmap de origem.

*ySrc*<br/>
A lógica coordenada y do canto superior esquerdo do bitmap de origem.

*hbmMask*<br/>
Identificador para o bitmap de máscara monocromática combinado com o bitmap colorido no contexto de dispositivo de origem.

*xMask*<br/>
O deslocamento horizontal do pixel do bitmap de máscara especificado pelo *hbmMask* parâmetro.

*yMask*<br/>
O deslocamento vertical de pixel do bitmap de máscara especificado pelo *hbmMask* parâmetro.

*dwROP*<br/>
Especifica o primeiro e segundo plano códigos de operação varredura Ternário que o método usa para controlar a combinação de dados de origem e destino. O código de operação de varredura de plano de fundo é armazenado no byte de ordem superior da palavra de ordem superior desse valor; o código de operação de varredura de primeiro plano é armazenado no byte de ordem baixa da palavra de ordem superior desse valor; a palavra de ordem inferior desse valor é ignorada e deve ser zero. Para uma discussão sobre o primeiro e segundo plano no contexto desse método, consulte `MaskBlt` no SDK do Windows. Para obter uma lista de códigos de operação de varredura comuns, consulte `BitBlt` no SDK do Windows.

*rectDest*<br/>
Uma referência a um `RECT` estrutura, identificando o destino.

*pointSrc*<br/>
Um `POINT` estrutura que indica o canto superior esquerdo do retângulo de origem.

*pointMask*<br/>
Um `POINT` estrutura que indica o canto superior esquerdo do bitmap de máscara.

*pointDest*<br/>
Uma referência a um `POINT` estrutura que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido, caso contrário, 0.

### <a name="remarks"></a>Comentários

Esse método se aplica ao Windows NT, as versões 4.0 e posterior somente.

##  <a name="operator_hbitmap"></a>  CImage::operator HBITMAP

Use este operador para obter o identificador do Windows GDI anexado do `CImage` objeto. Esse operador é um operador de conversão, que dá suporte ao uso direto de um objeto HBITMAP.

##  <a name="plgblt"></a>  CImage::PlgBlt

Executa uma transferência de bloco de bits de um retângulo em um contexto de dispositivo de origem em um paralelogramo em um contexto de dispositivo de destino.

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
Um identificador para o contexto de dispositivo de destino.

*pPoints*<br/>
Um ponteiro para uma matriz de três pontos no espaço lógico que identificam os três cantos do paralelogramo de destino. O canto superior esquerdo do retângulo de origem é mapeado para o primeiro ponto nessa matriz, o canto superior direito para o segundo ponto nessa matriz e o canto inferior esquerdo para o terceiro ponto. O canto inferior direito do retângulo de origem é mapeado para o ponto de quarto implícito em um paralelogramo.

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
Uma referência a um [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura especificando as coordenadas do retângulo de origem.

*pointMask*<br/>
Um [ponto](/previous-versions/dd162805\(v=vs.85\)) estrutura que indica o canto superior esquerdo do bitmap de máscara.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido, caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *hbmMask* identifica um bitmap monocromático válido, `PlgBit` usa esse bitmap para mascarar os bits de dados de cor do retângulo de origem.

Esse método se aplica ao Windows NT, as versões 4.0 e posterior somente. Ver [PlgBlt](/windows/desktop/api/wingdi/nf-wingdi-plgblt) no SDK do Windows para obter mais informações.

##  <a name="releasedc"></a>  CImage::ReleaseDC

Libera o contexto de dispositivo.

```
void ReleaseDC() const throw();
```

### <a name="remarks"></a>Comentários

Como apenas um bitmap pode ser selecionado em um contexto de dispositivo por vez, você deve chamar `ReleaseDC` para cada chamada para [GetDC](#getdc).

##  <a name="releasegdiplus"></a>  CImage::ReleaseGDIPlus

Libera recursos usados pelo GDI+.

```
void ReleaseGDIPlus() throw();
```

### <a name="remarks"></a>Comentários

Esse método deve ser chamado para liberar recursos alocados por um global `CImage` objeto. Ver [CImage::CImage](#cimage).

##  <a name="save"></a>  CImage::Save

Salva uma imagem para o arquivo no disco ou fluxo especificado.

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
Um ponteiro para um objeto COM IStream que contém os dados de imagem do arquivo.

*pszFileName*<br/>
Um ponteiro para o nome do arquivo da imagem.

*guidFileType*<br/>
O tipo de arquivo para salvar a imagem como. Pode ser uma das seguintes opções:

- `ImageFormatBMP` Uma imagem de bitmap não compactado.

- `ImageFormatPNG` Uma imagem compactada do gráfico PNG (Portable Network).

- `ImageFormatJPEG` Uma imagem JPEG compactada.

- `ImageFormatGIF` Uma imagem compactada do GIF.

> [!NOTE]
> Para obter uma lista completa das constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.

### <a name="return-value"></a>Valor de retorno

Um HRESULT padrão.

### <a name="remarks"></a>Comentários

Chame essa função para salvar a imagem usando um nome e tipo especificados. Se o *guidFileType* parâmetro não for incluído, a extensão de arquivo do nome do arquivo será usado para determinar o formato de imagem. Se nenhuma extensão for fornecido, a imagem será salva no formato BMP.

##  <a name="setcolortable"></a>  CImage::SetColorTable

Define valores de cor vermelhos, verdes e azuis (RGB) para um intervalo de entradas da paleta da seção DIB.

```
void SetColorTable(
    UINT iFirstColor,
    UINT nColors,
    const RGBQUAD* prgbColors) throw();
```

### <a name="parameters"></a>Parâmetros

*iFirstColor*<br/>
O índice da tabela de cores da primeira entrada para definir.

*nColors*<br/>
O número de entradas de tabela de cores para definir.

*prgbColors*<br/>
Um ponteiro para a matriz de [RGBQUAD](/windows/desktop/api/wingdi/ns-wingdi-tagrgbquad) estruturas para definir a cor de entradas de tabela.

### <a name="remarks"></a>Comentários

Esse método dá suporte a somente os bitmaps de seção DIB.

##  <a name="setpixel"></a>  CImage::SetPixel

Define a cor de um pixel em um determinado local no bitmap.

```
void SetPixel(int x, int y, COLORREF color) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O local horizontal do pixel a ser definida.

*y*<br/>
O local vertical do pixel a ser definida.

*color*<br/>
A cor que você definiu o pixel.

### <a name="remarks"></a>Comentários

Esse método falhará se o pixel coordena a mentira fora da região de recorte selecionado.

##  <a name="setpixelindexed"></a>  CImage::SetPixelIndexed

Define a cor do pixel para a cor localizada em *iIndex* na paleta de cores.

```
void SetPixelIndexed(int x, int y, int iIndex) throw();
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O local horizontal do pixel a ser definida.

*y*<br/>
O local vertical do pixel a ser definida.

*iIndex*<br/>
O índice de uma cor na paleta de cores.

##  <a name="setpixelrgb"></a>  CImage::SetPixelRGB

Define o pixel nos locais especificados por *x* e *y* para as cores indicadas por *r*, *g*, e *b*, em um vermelho, verde, azul imagem (RGB).

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
O local horizontal do pixel a ser definida.

*y*<br/>
O local vertical do pixel a ser definida.

*r*<br/>
A intensidade da cor vermelha.

*g*<br/>
A intensidade da cor verde.

*b*<br/>
A intensidade da cor azul.

### <a name="remarks"></a>Comentários

Os parâmetros de vermelhos, verdes e azuis são representados por um número entre 0 e 255. Se você definir todos os três parâmetros como zero, a cor resultante combinada é preta. Se você definir todos os três parâmetros a 255, a cor resultante combinada é branca.

##  <a name="settransparentcolor"></a>  CImage::SetTransparentColor

Define uma cor em um determinado local indexado como transparente.

```
LONG SetTransparentColor(LONG iTransparentColor) throw();
```

### <a name="parameters"></a>Parâmetros

*iTransparentColor*<br/>
O índice em uma paleta de cores da cor para definir como transparente. Se-1, nenhuma cor é definido como transparente.

### <a name="return-value"></a>Valor de retorno

O índice da cor definidos anteriormente como transparente.

##  <a name="stretchblt"></a>  CImage::StretchBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto de dispositivo atual.

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
Um identificador para o contexto de dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*dwROP*<br/>
A operação de varredura a ser executada. Códigos de operação de varredura definem como combinar os bits do código-fonte, o destino e o padrão (conforme definido pelo pincel selecionado no momento) para formar o destino. Ver [BitBlt](/windows/desktop/api/wingdi/nf-wingdi-bitblt) no SDK do Windows para obter uma lista de outros códigos de operação de varredura e suas descrições.

*rectDest*<br/>
Uma referência a um [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura, identificando o destino.

*xSrc*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectSrc*<br/>
Uma referência a um `RECT` estrutura, identificando a origem.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se for bem-sucedido, caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte [StretchBlt](/windows/desktop/api/wingdi/nf-wingdi-stretchblt) no SDK do Windows.

##  <a name="transparentblt"></a>  CImage::TransparentBlt

Copia um bitmap do contexto do dispositivo de origem para este contexto de dispositivo atual.

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
Um identificador para o contexto de dispositivo de destino.

*xDest*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*yDest*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.

*nDestWidth*<br/>
A largura, em unidades lógicas, do retângulo de destino.

*nDestHeight*<br/>
A altura, em unidades lógicas, do retângulo de destino.

*crTransparent*<br/>
A cor em que o bitmap de origem a ser tratada como transparente. Por padrão, CLR_INVALID, indicando que a cor atualmente definido como a cor transparente da imagem deve ser usado.

*rectDest*<br/>
Uma referência a um [RECT](/previous-versions/dd162897\(v=vs.85\)) estrutura, identificando o destino.

*xSrc*<br/>
A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*ySrc*<br/>
A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.

*nSrcWidth*<br/>
A largura, em unidades lógicas, do retângulo de origem.

*nSrcHeight*<br/>
A altura, em unidades lógicas, do retângulo de origem.

*rectSrc*<br/>
Uma referência a um `RECT` estrutura, identificando a origem.

### <a name="return-value"></a>Valor de retorno

TRUE se bem-sucedido, caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`TransparentBlt` há suporte para bitmaps de origem de 4 bits por pixel e 8 bits por pixel. Use [CImage::AlphaBlend](#alphablend) para especificar os bitmaps de 32 bits por pixel com transparência.

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
[Bitmaps independentes de dispositivo](/windows/desktop/gdi/device-independent-bitmaps)<br/>
[CreateDIBSection](/windows/desktop/api/wingdi/nf-wingdi-createdibsection)<br/>
[Componentes de área de trabalho COM da ATL](../../atl/atl-com-desktop-components.md)<br/>
[Bitmaps independentes de dispositivo](/windows/desktop/gdi/device-independent-bitmaps)<br/>
[CreateDIBSection](/windows/desktop/api/wingdi/nf-wingdi-createdibsection)
