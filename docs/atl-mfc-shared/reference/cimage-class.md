---
title: Classe CImage | Microsoft Docs
ms.custom: ''
ms.date: 02/01/2018
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 762941834820edda09970750af752d4c8a9df61c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32366309"
---
# <a name="cimage-class"></a>Classe CImage
`CImage` Fornece suporte de bitmap aprimorada, incluindo a capacidade de carregar e salvar imagens em formatos JPEG, GIF, BMP e elementos gráficos PNG (Portable Network).  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CImage
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CImage::CImage](#cimage)|O construtor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CImage::AlphaBlend](#alphablend)|Exibe os bitmaps que têm pixels transparentes ou semitransparentes.|  
|[CImage::Attach](#attach)|Anexa uma `HBITMAP` para um `CImage` objeto. Pode ser usado com bitmaps de seção não DIB ou DIB bitmaps de seção.|  
|[CImage::BitBlt](#bitblt)|Copia um bitmap do contexto de dispositivo de origem para este contexto de dispositivo atual.|  
|[CImage::Create](#create)|Cria um bitmap de seção DIB e a anexa ao criado anteriormente `CImage` objeto.|  
|[CImage::CreateEx](#createex)|Cria um bitmap de seção DIB (com parâmetros adicionais) e a anexa ao criado anteriormente `CImage` objeto.|  
|[CImage::Destroy](#destroy)|Desanexa o bitmap do `CImage` de objeto e destrói o bitmap.|  
|[CImage::Detach](#detach)|Desanexa o bitmap de uma `CImage` objeto.|  
|[CImage::Draw](#draw)|Copia um bitmap de um retângulo de origem em um retângulo de destino. **Desenhar** alonga ou compacta o bitmap para se ajustar às dimensões do retângulo de destino, se necessário e lida com a combinação alfa e cores transparentes.|  
|[CImage::GetBits](#getbits)|Recupera um ponteiro para os valores de pixel real do bitmap.|  
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
|[CImage::IsIndexed](#isindexed)|Indica que as cores deste bitmap são mapeadas para uma paleta indexada.|  
|[CImage::IsNull](#isnull)|Indica se um bitmap de origem é carregado no momento.|  
|[CImage::IsTransparencySupported](#istransparencysupported)|Indica se o aplicativo dá suporte a bitmaps transparentes.|  
|[CImage::Load](#load)|Carrega uma imagem do arquivo especificado.|  
|[CImage::LoadFromResource](#loadfromresource)|Carrega uma imagem do recurso especificado.|  
|[CImage::MaskBlt](#maskblt)|Combina os dados de cor para os bitmaps de origem e de destino usando a máscara especificada e a operação de varredura.|  
|[CImage::PlgBlt](#plgblt)|Executa uma transferência de bloco de bits de um retângulo em um contexto de dispositivo de origem em um paralelogramo em um contexto de dispositivo de destino.|  
|[CImage::ReleaseDC](#releasedc)|Libera o contexto de dispositivo que foi recuperado com [CImage::GetDC](#getdc).|  
|[CImage::ReleaseGDIPlus](#releasegdiplus)|Libera recursos usados pelo GDI+. Deve ser chamado para liberar recursos criados por um global `CImage` objeto.|  
|[CImage::Save](#save)|Salva uma imagem como o tipo especificado. **Salvar** não é possível especificar opções de imagem.|  
|[CImage::SetColorTable](#setcolortable)|Define o RGB de vermelho, verde e azul) valores em um intervalo de entradas na tabela de cores da seção DIB de cor.|  
|[CImage::SetPixel](#setpixel)|Define o pixel em coordenadas especificadas para a cor especificada.|  
|[CImage::SetPixelIndexed](#setpixelindexed)|Define o pixel em coordenadas especificadas para a cor no índice especificado da paleta.|  
|[CImage::SetPixelRGB](#setpixelrgb)|Define o pixel em coordenadas especificadas ao valor especificado de vermelho, verde, azul (RGB).|  
|[CImage::SetTransparentColor](#settransparentcolor)|Define o índice da cor a ser tratada como transparente. Apenas uma cor em uma paleta pode ser transparente.|  
|[CImage::StretchBlt](#stretchblt)|Copia um bitmap de um retângulo de origem em um retângulo de destino, expansão ou compactar o bitmap para se ajustar às dimensões do retângulo de destino, se necessário.|  
|[CImage::TransparentBlt](#transparentblt)|Copia um bitmap com cor transparente do contexto de dispositivo de origem para este contexto de dispositivo atual.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CImage::operator HBITMAP](#operator_hbitmap)|Retorna o identificador anexado para o `CImage` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CImage` leva bitmaps que são ambos seções independente de dispositivo DIB (bitmap) ou não; No entanto, você pode usar [criar](#create) ou [CImage::Load](#load) com apenas as seções DIB. Você pode anexar um bitmap de seção não DIB para um `CImage` objeto usando [Attach](#attach), mas, em seguida, você não pode usar o seguinte `CImage` métodos que oferecem suporte a somente os bitmaps de seção DIB:  
  
- [GetBits](#getbits)  
  
- [GetColorTable](#getcolortable)  
  
- [GetMaxColorTableEntries](#getmaxcolortableentries)  
  
- [GetPitch](#getpitch)  
  
- [GetPixelAddress](#getpixeladdress)  
  
- [IsIndexed](#isindexed)  
  
- [SetColorTable](#setcolortable)  
  
 Para determinar se um bitmap anexado é uma seção DIB, chame [IsDibSection](#isdibsection)**.**  
  
> [!NOTE]
> **Observação** no Visual Studio .NET 2003, essa classe mantém uma contagem do número de `CImage` objetos criados. Sempre que a contagem chegar a 0, a função **GdiplusShutdown** é chamado automaticamente para liberar recursos usados pelo GDI+. Isso garante que qualquer `CImage` objetos criados diretamente ou indiretamente por DLLs sempre são destruídos corretamente e que **GdiplusShutdown** não é chamado de `DllMain`.  
  
> [!NOTE]
>  Usando global `CImage` objetos em uma DLL não é recomendado. Se você precisar usar global `CImage` objeto em uma DLL, chamada [CImage::ReleaseGDIPlus](#releasegdiplus) explicitamente liberar recursos usados pelo GDI+.  
  
 `CImage` não é possível selecionar em uma nova [CDC](../../mfc/reference/cdc-class.md). `CImage` cria seu próprio **HDC** para a imagem. Porque um `HBITMAP` só pode ser selecionado em uma **HDC** ao mesmo tempo, o `HBITMAP` associados a `CImage` não pode ser selecionada para outra **HDC**. Se você precisar de um `CDC`, recuperar o **HDC** do `CImage` e dê a ele [CDC::FromHandle] (... /.. /MFC/Reference/CDC-Class.MD#cdc__fromhandle.  
  
## <a name="example"></a>Exemplo  
```cpp  
// Get a CDC for the image
CDC* pDC = CDC::FromHandle(m_myImage.GetDC());

// Use pDC here
pDC->Rectangle(0, 40, 100, 50);
m_myImage.ReleaseDC();
```  
  
 Quando você usa `CImage` em um projeto MFC, observe quais funções de membro em seu projeto esperam um ponteiro para um [CBitmap](../../mfc/reference/cbitmap-class.md) objeto. Se você quiser usar `CImage` com uma função, como [CMenu::AppendMenu](../../mfc/reference/cmenu-class.md#appendmenu), use [CBitmap::FromHandle](../../mfc/reference/cbitmap-class.md#fromhandle), passá-lo seu `CImage` `HBITMAP`e usar o retornado`CBitmap*`.  

  
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

  
 Por meio de `CImage`, você tem acesso para os bits reais de uma seção DIB. Você pode usar um `CImage` do objeto em qualquer lugar você usou uma seção HBITMAP do Win32 ou DIB.  
  
 Você pode usar `CImage` do MFC ou do ATL  
  
> [!NOTE]
>  Quando você cria um projeto usando `CImage`, você deve definir `CString` antes de incluir `atlimage.h`. Se seu projeto usa ATL sem MFC, inclua `atlstr.h` antes de incluir `atlimage.h`. Se seu projeto usa MFC (ou se ele é um projeto ATL com suporte do MFC), inclua `afxstr.h` antes de incluir `atlimage.h`.  
>   
>  Da mesma forma, você deve incluir `atlimage.h` antes de incluir `atlimpl.cpp`. Para fazer isso facilmente, inclua `atlimage.h` em seu `stdafx.h`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlimage.h  
  
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
 `hDestDC`  
 Identificador para o contexto de dispositivo de destino.  
  
 `xDest`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `yDest`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 *bSrcAlpha*  
 Um valor de transparência alfa para ser usado no bitmap de origem inteiro. O padrão 0xff (255) pressupõe que sua imagem é opaca e que você deseja usar por pixel valores alfa.  
  
 `bBlendOp`  
 A função transparência para origem e destino bitmaps, um valor alfa global a ser aplicado para o bitmap de origem inteiro e informações de formato para o bitmap de origem. As funções de mesclagem de origem e destino estão limitadas a **AC_SRC_OVER**.  
  
 `pointDest`  
 Uma referência a um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.  
  
 `nDestWidth`  
 A largura, em unidades lógicas, do retângulo de destino.  
  
 `nDestHeight`  
 A altura, em unidades lógicas, do retângulo de destino.  
  
 `xSrc`  
 A lógica coordenada x do canto superior esquerdo do retângulo de origem.  
  
 `ySrc`  
 A lógica coordenada y do canto superior esquerdo do retângulo de origem.  
  
 `nSrcWidth`  
 A largura, em unidades lógicas, do retângulo de origem.  
  
 `nSrcHeight`  
 A altura, em unidades lógicas, do retângulo de origem.  
  
 `rectDest`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, identificando o destino.  
  
 `rectSrc`  
 Uma referência a um `RECT` estrutura, identificando a origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Bitmaps alpha blend suporte a cor de mesclagem em uma base por pixel.  
  
 Quando `bBlendOp` é definido como o padrão de **AC_SRC_OVER**, o bitmap de origem é colocado sobre o bitmap de destino com base nos valores alfa de pixels de origem.  

##  <a name="attach"></a>  CImage::Attach  
 Anexa `hBitmap` para um `CImage` objeto.  
  
```
void Attach(HBITMAP hBitmap, DIBOrientation eOrientation = DIBOR_DEFAULT) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hBitmap`  
 Um identificador para um `HBITMAP`.  
  
 *eOrientation*  
 Especifica a orientação do bitmap. Pode ser um dos seguintes:  
  
- **DIBOR_DEFAULT** a orientação do bitmap é determinada pelo sistema operacional. No entanto, isso nem sempre tem os resultados desejados em todos os sistemas operacionais. Para obter mais informações sobre isso, consulte o seguinte artigo da Base de dados de Conhecimento ( **Q186586**): PRB: GetObject () sempre retorna positivo altura para DIB seções.  
  
- **DIBOR_BOTTOMUP** as linhas do bitmap estão na ordem inversa. Isso faz com que [CImage::GetBits](#getbits) para retornar um ponteiro no final do buffer de bitmap e [CImage::GetPitch](#getpitch) para retornar um número negativo.  
  
- **DIBOR_TOPDOWN** as linhas de bitmap são na parte superior para a parte inferior. Isso faz com que [CImage::GetBits](#getbits) para retornar um ponteiro para o primeiro byte do buffer de bitmap e [CImage::GetPitch](#getpitch) para retornar um número positivo.  
  
### <a name="remarks"></a>Comentários  
 O bitmap pode ser um bitmap de seção não DIB ou um bitmap de seção DIB. Consulte [IsDIBSection](#isdibsection) para obter uma lista de métodos que podem ser usados somente com DIB bitmaps de seção.  
  
##  <a name="bitblt"></a>  CImage::BitBlt  
 Copia um bitmap do contexto de dispositivo de origem para este contexto de dispositivo atual.  
  
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
 `hDestDC`  
 O destino **HDC**.  
  
 `xDest`  
 A lógica coordenada x do canto superior esquerdo do retângulo de destino.  
  
 `yDest`  
 A lógica coordenada y do canto superior esquerdo do retângulo de destino.  
  
 `dwROP`  
 A operação de varredura a ser executada. Códigos de operação de varredura definem exatamente como combinar os bits de origem, destino e o padrão (conforme definido pelo pincel selecionado no momento) para formar o destino. Consulte [BitBlt](http://msdn.microsoft.com/library/windows/desktop/dd183370) no SDK do Windows para obter uma lista de outros códigos de operação de varredura e suas descrições.  
  
 `pointDest`  
 Um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura indicando o canto superior esquerdo do retângulo de destino.  
  
 `nDestWidth`  
 A largura, em unidades lógicas, do retângulo de destino.  
  
 `nDestHeight`  
 A altura, em unidades lógicas, do retângulo de destino.  
  
 `xSrc`  
 A lógica coordenada x do canto superior esquerdo do retângulo de origem.  
  
 `ySrc`  
 A lógica coordenada y do canto superior esquerdo do retângulo de origem.  
  
 `rectDest`  
 Um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura indicando o retângulo de destino.  
  
 `pointSrc`  
 Um **ponto** estrutura indicando o canto superior esquerdo do retângulo de origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [BitBlt](http://msdn.microsoft.com/library/windows/desktop/dd183370) no SDK do Windows.  
  
##  <a name="cimage"></a>  CImage::CImage  
 Constrói um objeto `CImage`.  
  
```
CImage() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de criar o objeto, chame [criar](#create), [carga](#load), [LoadFromResource](#loadfromresource), ou [Attach](#attach) para anexar um bitmap para o objeto.  
  
 **Observação** no Visual Studio, essa classe mantém uma contagem do número de `CImage` objetos criados. Sempre que a contagem chegar a 0, a função **GdiplusShutdown** é chamado automaticamente para liberar recursos usados pelo GDI+. Isso garante que qualquer `CImage` objetos criados diretamente ou indiretamente por DLLs sempre são destruídos corretamente e que **GdiplusShutdown** não é chamado de DllMain.  
  
 Usando global `CImage` objetos em uma DLL não é recomendado. Se você precisar usar global `CImage` objeto em uma DLL, chamada [CImage::ReleaseGDIPlus](#releasegdiplus) explicitamente liberar recursos usados pelo GDI+.  
  
##  <a name="create"></a>  CImage::Create  
 Cria um `CImage` bitmap e anexá-lo à criado anteriormente `CImage` objeto.  
  
```
BOOL Create(
 int nWidth,
 int nHeight,
 int nBPP,
 DWORD dwFlags = 0) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nWidth`  
 A largura do `CImage` bitmap, em pixels.  
  
 `nHeight`  
 A altura do `CImage` bitmap, em pixels. Se `nHeight` for positivo, o bitmap é DIB ascendente e sua origem é o canto inferior esquerdo. Se `nHeight` é negativo, o bitmap é DIB de cima para baixo e sua origem é o canto superior esquerdo.  
  
 `nBPP`  
 Os números de bits por pixel no bitmap. Geralmente, 4, 8, 16, 24 ou 32. Pode ser 1 para bitmaps monocromático ou máscaras.  
  
 `dwFlags`  
 Especifica se o objeto bitmap tem um canal alfa. Pode ser uma combinação de zero ou mais dos seguintes valores:  
  
- **createAlphaChannel** só pode ser usado se `nBPP` é 32, e `eCompression` é **BI_RGB**. Se especificado, a imagem criada tem um valor alfa (transparência) para cada pixel, armazenado no 4º byte de cada pixel (não usado em uma imagem de 32 bits não alfanuméricos). Esse canal alfa automaticamente é usado ao chamar [CImage::AlphaBlend](#alphablend).  
  
> [!NOTE]
>  Em chamadas para [CImage::Draw](#draw), imagens com um canal alfa são automaticamente alfa mesclados para o destino.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
##  <a name="createex"></a>  CImage::CreateEx  
 Cria um `CImage` bitmap e anexá-lo à criado anteriormente `CImage` objeto.  
  
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
 `nWidth`  
 A largura do `CImage` bitmap, em pixels.  
  
 `nHeight`  
 A altura do `CImage` bitmap, em pixels. Se `nHeight` for positivo, o bitmap é DIB ascendente e sua origem é o canto inferior esquerdo. Se `nHeight` é negativo, o bitmap é DIB de cima para baixo e sua origem é o canto superior esquerdo.  
  
 `nBPP`  
 Os números de bits por pixel no bitmap. Geralmente, 4, 8, 16, 24 ou 32. Pode ser 1 para bitmaps monocromático ou máscaras.  
  
 `eCompression`  
 Especifica o tipo de compactação para um bitmap de baixo para cima compactado (DIBs de cima para baixo não podem ser compactados). Pode ser um dos seguintes valores:  
  
- **BI_RGB** o formato é descompactado. A especificação desse valor ao chamar `CImage::CreateEx` é equivalente a chamar `CImage::Create`.  
  
- **BI_BITFIELDS** o formato é descompactado e a tabela de cores consiste em três `DWORD` máscaras de cor que especificam o vermelho, verde e azul componentes, respectivamente, de cada pixel. Isso é válido quando usado com bitmaps de 16 e 32 bpp.  
  
 *pdwBitfields*  
 Usado somente se `eCompression` é definido como **BI_BITFIELDS**, caso contrário, ele deve ser **nulo**. Um ponteiro para uma matriz de três `DWORD` bitmasks, especificando os bits de cada pixel são usados para vermelho, verde e azul componentes da cor, respectivamente. Para obter informações sobre as restrições para os campos de bits, consulte [BITMAPINFOHEADER](http://msdn.microsoft.com/library/windows/desktop/dd183376) no SDK do Windows.  
  
 `dwFlags`  
 Especifica se o objeto bitmap tem um canal alfa. Pode ser uma combinação de zero ou mais dos seguintes valores:  
  
- **createAlphaChannel** só pode ser usado se `nBPP` é 32, e `eCompression` é **BI_RGB**. Se especificado, a imagem criada tem um valor alfa (transparência) para cada pixel, armazenado no 4º byte de cada pixel (não usado em uma imagem de 32 bits não alfanuméricos). Esse canal alfa automaticamente é usado ao chamar [CImage::AlphaBlend](#alphablend).  
  
    > [!NOTE]
    >  Em chamadas para [CImage::Draw](#draw), imagens com um canal alfa são automaticamente alfa mesclados para o destino.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se for bem-sucedido. Caso contrário, **FALSE**.  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir cria um bitmap de 100 x 100 pixels, com 16 bits para codificar cada pixel. Em um determinado pixel de 16 bits, bits 0-3 codificar o componente vermelho, bits de 4 a 7 codificar verde e bits 11 8 codificam azul. Os bits de 4 restantes são utilizados.  

```cpp  
DWORD adwBitmasks[3] = { 0x0000000f, 0x000000f0, 0x00000f00 };
m_myImage.CreateEx(100, 100, 16, BI_BITFIELDS, adwBitmasks, 0);
```


##  <a name="destroy"></a>  CImage::Destroy  
 Desanexa o bitmap do `CImage` de objeto e destrói o bitmap.  
  
```
void Destroy() throw();
```  
  
##  <a name="detach"></a>  CImage::Detach  
 Desanexa um bitmap de um `CImage` objeto.  
  
```
HBITMAP Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para o bitmap desanexado, ou **nulo** se nenhum bitmap está anexado.  
  
##  <a name="draw"></a>  CImage::Draw  
 Copia um bitmap do contexto de dispositivo de origem para o contexto atual do dispositivo.  
  
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
 `hDestDC`  
 Um identificador para o contexto de dispositivo de destino.  
  
 `xDest`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `yDest`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `nDestWidth`  
 A largura, em unidades lógicas, do retângulo de destino.  
  
 `nDestHeight`  
 A altura, em unidades lógicas, do retângulo de destino.  
  
 `xSrc`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `ySrc`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `nSrcWidth`  
 A largura, em unidades lógicas, do retângulo de origem.  
  
 `nSrcHeight`  
 A altura, em unidades lógicas, do retângulo de origem.  
  
 `rectDest`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, identificando o destino.  
  
 `rectSrc`  
 Uma referência a um `RECT` estrutura, identificando a origem.  
  
 `pointDest`  
 Uma referência a um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 **Desenhar** executa a mesma operação que [StretchBlt](#stretchblt), a menos que a imagem contém uma cor transparente ou canal alfa. Nesse caso, **desenhar** executa a mesma operação como [TransparentBlt](#transparentblt) ou [AlphaBlend](#alphablend) conforme necessário.  
  
 Para versões do **desenhar** que não especificam um retângulo de origem, a imagem de origem inteiro é o padrão. Para obter a versão de **desenhar** que não especifique um tamanho para o retângulo de destino, o tamanho da imagem de origem é o padrão e nenhuma ampliar ou reduzir ocorre.  
  
##  <a name="getbits"></a>  CImage::GetBits  
 Recupera um ponteiro para os valores de bit real de um determinado pixel em um bitmap.  
  
```
void* GetBits() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o buffer de bitmap. Se o bitmap for DIB de baixo para cima, os pontos de ponteiro perto do final do buffer. Se o bitmap for DIB de cima para baixo, o ponteiro apontará para o primeiro byte do buffer.  
  
### <a name="remarks"></a>Comentários  
 Usando esse ponteiro, juntamente com o valor retornado por [GetPitch](#getpitch), você pode localizar e alterar pixels individuais em uma imagem.  
  
> [!NOTE]
>  Este método oferece suporte a apenas os bitmaps de seção DIB; Consequentemente, você pode acessar os pixels de um `CImage` da mesma maneira que faria pixels de uma seção DIB do objeto. O ponteiro retornado aponta para o pixel no local (0, 0).  
  
##  <a name="getbpp"></a>  CImage::GetBPP  
 Recupera o valor de bits por pixel.  
  
```
int GetBPP() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de bits por pixel.  
  
### <a name="remarks"></a>Comentários  
 Esse valor determina o número de bits que definem cada pixel e o número máximo de cores no bitmap.  
  
 Bits por pixel geralmente é 1, 4, 8, 16, 24 ou 32. Consulte o **biBitCount** membro [BITMAPINFOHEADER](http://msdn.microsoft.com/library/windows/desktop/dd183376) no SDK do Windows para obter mais informações sobre esse valor.  
  
##  <a name="getcolortable"></a>  CImage::GetColorTable  
 Recupera os valores de cor vermelhos, verdes e azuis (RGB) de um intervalo de entradas na paleta da seção DIB.  
  
```
void GetColorTable(UINT iFirstColor,
 UINT nColors,
 RGBQUAD* prgbColors) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `iFirstColor`  
 O índice da tabela de cores da primeira entrada para recuperar.  
  
 `nColors`  
 O número de entradas de tabela de cores para recuperar.  
  
 `prgbColors`  
 Um ponteiro para a matriz de [RGBQUAD](http://msdn.microsoft.com/library/windows/desktop/dd162938) estruturas para recuperar a cor de entradas de tabela.  
  
##  <a name="getdc"></a>  CImage::GetDC  
 Recupera o contexto de dispositivo que está com a imagem selecionada para ele.  
  
```
HDC GetDC() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para um contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 Cada chamada para `GetDC`, você deve ter uma chamada subsequente para [ReleaseDC](#releasedc).  
  
##  <a name="getexporterfilterstring"></a>  CImage::GetExporterFilterString  
 Localiza os formatos de imagem disponível para salvar as imagens.  
  
```
static HRESULT GetExporterFilterString(CSimpleString& strExporters,
 CSimpleArray<GUID>& aguidFileTypes,
 LPCTSTR pszAllFilesDescription = NULL,
 DWORD dwExclude = excludeDefaultSave,
 TCHAR chSeparator = _T('|'));
```  
  
### <a name="parameters"></a>Parâmetros  
 *strExporters*  
 Uma referência a um **CSimpleString** objeto. Consulte **comentários** para obter mais informações.  
  
 `aguidFileTypes`  
 Uma matriz de GUIDs, com cada elemento corresponde a um dos tipos de arquivo na cadeia de caracteres. No exemplo de `pszAllFilesDescription` abaixo, `aguidFileTypes`[0] é `GUID_NULL` e os valores de matriz restantes são os formatos de arquivo de imagem com suporte pelo sistema operacional atual.  
  
> [!NOTE]
>  Para obter uma lista completa das constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.  
  
 `pszAllFilesDescription`  
 Se esse parâmetro não for **nulo**, a cadeia de caracteres de filtro terá um filtro adicional no início da lista. Esse filtro terá o valor atual de `pszAllFilesDescription` para sua descrição e aceita arquivos de qualquer extensão de suporte por qualquer outro exportador na lista.  
  
 Por exemplo:  

```cpp  
//First filter in the list will be titled "All Image Files", and
//will accept files with any extension supported by any exporter.
CImage::GetExporterFilterString(
    strExporters, aguidFileTypes, 
 _T("All Image Files"));
```  

  
 `dwExclude`  
 Conjunto de sinalizadores de bit especificando quais tipos de arquivo a ser excluído da lista. Os sinalizadores permitidos são:  
  
- **excludeGIF** = 0x01 GIF exclui arquivos.  
  
- **excludeBMP** = 0x02 exclui BMP (Bitmap do Windows) arquivos.  
  
- **excludeEMF** = 0x04 exclui EMF (metarquivo avançado) arquivos.  
  
- **excludeWMF** = 0x08 exclui WMF (Windows Metafile) arquivos.  
  
- **excludeJPEG** = 0x10 JPEG exclui arquivos.  
  
- **excludePNG** = 0x20 PNG exclui arquivos.  
  
- **excludeTIFF** = 0x40 TIFF exclui arquivos.  
  
- **excludeIcon** = 0x80 exclui ICO (ícone do Windows) arquivos.  
  
- **excludeOther** = 0x80000000 exclui qualquer outro tipo de arquivo não listado acima.  
  
- **excludeDefaultLoad** = 0 para o arquivo de todos os tipos são incluídos por padrão de carga  
  
- **excludeDefaultSave** = **excludeIcon &#124; excludeEMF &#124; excludeWMF** para salvar, esses arquivos são excluídos por padrão porque eles normalmente têm requisitos especiais.  
  
 `chSeparator`  
 O separador usado entre os formatos de imagem. Consulte **comentários** para obter mais informações.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
### <a name="remarks"></a>Comentários  
 Você pode passar a cadeia de caracteres de formato resultante para o MFC [CFileDialog](../../mfc/reference/cfiledialog-class.md) formatos de objeto para expor as extensões de arquivo da imagem disponível na caixa de diálogo Salvar como arquivo.  
  
 O parâmetro *strExporter* tem o formato:  
  
 arquivo description0&#124;\*.ext0&#124;filedescription1&#124;\*. ext1&#124;... descrição do arquivo *n*&#124;\*. ext *n*&#124;&#124;  
  
 onde '&#124;' é o caractere separador especificado pelo `chSeparator`. Por exemplo:  
  
 `"Bitmap format|*.bmp|JPEG format|*.jpg|GIF format|*.gif|PNG format|*.png||"`  
  
 Use o separador padrão '&#124;' se você passar essa cadeia de caracteres para um MFC `CFileDialog` objeto. Use o separador nulo '\0' se você passar essa cadeia de caracteres para uma caixa de diálogo Salvar arquivo comuns.  
  
##  <a name="getheight"></a>  CImage::GetHeight  
 Recupera a altura, em pixels, de uma imagem.  
  
```
int GetHeight() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura, em pixels, de uma imagem.  
  
##  <a name="getimporterfilterstring"></a>  CImage::GetImporterFilterString  
 Localiza os formatos de imagem disponíveis para carregamento de imagens.  
  
```
static HRESULT GetImporterFilterString(CSimpleString& strImporters,
 CSimpleArray<GUID>& aguidFileTypes,
 LPCTSTR pszAllFilesDescription = NULL,
 DWORD dwExclude = excludeDefaultLoad,
 TCHAR chSeparator = _T('|'));
```  
  
### <a name="parameters"></a>Parâmetros  
 *strImporters*  
 Uma referência a um **CSimpleString** objeto. Consulte **comentários** para obter mais informações.  
  
 `aguidFileTypes`  
 Uma matriz de GUIDs, com cada elemento corresponde a um dos tipos de arquivo na cadeia de caracteres. No exemplo de `pszAllFilesDescription` abaixo, `aguidFileTypes`[0] é `GUID_NULL` com a matriz restante, os valores são os formatos de arquivo de imagem com suporte pelo sistema operacional atual.  
  
> [!NOTE]
>  Para obter uma lista completa das constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.  
  
 `pszAllFilesDescription`  
 Se esse parâmetro não for **nulo**, a cadeia de caracteres de filtro terá um filtro adicional no início da lista. Esse filtro terá o valor atual de `pszAllFilesDescription` para sua descrição e aceita arquivos de qualquer extensão de suporte por qualquer outro exportador na lista.  
  
 Por exemplo:  

```cpp  
//First filter in the list will be titled "All Image Files", and
//will accept files with any extension supported by any importer.
CImage::GetImporterFilterString(
    strImporters, aguidFileTypes, 
 _T("All Image Files"));
```  

  
 `dwExclude`  
 Conjunto de sinalizadores de bit especificando quais tipos de arquivo a ser excluído da lista. Os sinalizadores permitidos são:  
  
- **excludeGIF** = 0x01 GIF exclui arquivos.  
  
- **excludeBMP** = 0x02 exclui BMP (Bitmap do Windows) arquivos.  
  
- **excludeEMF** = 0x04 exclui EMF (metarquivo avançado) arquivos.  
  
- **excludeWMF** = 0x08 exclui WMF (Windows Metafile) arquivos.  
  
- **excludeJPEG** = 0x10 JPEG exclui arquivos.  
  
- **excludePNG** = 0x20 PNG exclui arquivos.  
  
- **excludeTIFF** = 0x40 TIFF exclui arquivos.  
  
- **excludeIcon** = 0x80 exclui ICO (ícone do Windows) arquivos.  
  
- **excludeOther** = 0x80000000 exclui qualquer outro tipo de arquivo não listado acima.  
  
- **excludeDefaultLoad** = 0 para o arquivo de todos os tipos são incluídos por padrão de carga  
  
- **excludeDefaultSave** = **excludeIcon &#124; excludeEMF &#124; excludeWMF** para salvar, esses arquivos são excluídos por padrão porque eles normalmente têm requisitos especiais.  
  
 `chSeparator`  
 O separador usado entre os formatos de imagem. Consulte **comentários** para obter mais informações.  
  
### <a name="remarks"></a>Comentários  
 Você pode passar a cadeia de caracteres de formato resultante para o MFC [CFileDialog](../../mfc/reference/cfiledialog-class.md) formatos de objeto para expor as extensões de arquivo da imagem disponível no **abrir arquivo** caixa de diálogo.  
  
 O parâmetro *strImporter* tem o formato:  
  
 arquivo description0&#124;\*.ext0&#124;filedescription1&#124;\*. ext1&#124;... descrição do arquivo *n*&#124;\*. ext *n*&#124;&#124;  
  
 onde '&#124;' é o caractere separador especificado pelo `chSeparator`. Por exemplo:  
  
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
 Este método dá suporte a apenas os bitmaps de seção DIB.  
  
##  <a name="getpitch"></a>  CImage::GetPitch  
 Recupera o tom de uma imagem.  
  
```
int GetPitch() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A densidade da imagem. Se o valor de retorno for negativo, o bitmap é DIB ascendente e sua origem é o canto inferior esquerdo. Se o valor de retorno for positivo, o bitmap é DIB de cima para baixo e sua origem é o canto superior esquerdo.  
  
### <a name="remarks"></a>Comentários  
 O campo é a distância, em bytes, entre dois endereços de memória que representam o início de uma linha de bitmap e o início da próxima linha de bitmap. Porque a distância é medida em bytes, o tom de uma imagem ajuda a determinar o formato de pixel. O tom também pode incluir mais memória, reservada para o bitmap.  
  
 Use `GetPitch` com [GetBits](#getbits) para localizar os pixels individuais de uma imagem.  
  
> [!NOTE]
>  Este método dá suporte a apenas os bitmaps de seção DIB.  
  
##  <a name="getpixel"></a>  CImage::GetPixel  
 Recupera a cor do pixel no local especificado por *x* e *y*.  
  
```
COLORREF GetPixel(int x,int y) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 A coordenada x do pixel.  
  
 *y*  
 A coordenada y do pixel.  
  
### <a name="return-value"></a>Valor de retorno  
 O valor (RGB) do vermelho, verde e azul do pixel. Se o pixel está fora da região de recorte atual, o valor de retorno é **CLR_INVALID**.  
  
##  <a name="getpixeladdress"></a>  CImage::GetPixelAddress  
 Recupera o endereço exato de um pixel.  
  
```
void* GetPixelAddress(int x,int y) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 A coordenada x do pixel.  
  
 *y*  
 A coordenada y do pixel.  
  
### <a name="remarks"></a>Comentários  
 O endereço é determinado de acordo com as coordenadas de um pixel, o tom de bitmap e bits por pixel.  
  
 Para formatos que tenham menos de 8 bits por pixel, esse método retorna o endereço do byte que contém o pixel. Por exemplo, se seu formato de imagem tem 4 bits por pixel, `GetPixelAddress` retorna o endereço do pixel primeiro o byte, e você deve calcular 2 pixels por byte.  
  
> [!NOTE]
>  Este método dá suporte a apenas os bitmaps de seção DIB.  
  
##  <a name="gettransparentcolor"></a>  CImage::GetTransparentColor  
 Recupera a localização indexada da cor transparente na paleta de cores.  
  
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
 A largura de bitmap, em pixels.  
  
##  <a name="isdibsection"></a>  CImage::IsDIBSection  
 Determina se o bitmap anexado é uma seção DIB.  
  
```
bool IsDIBSection() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 **True** se o bitmap anexado é uma seção DIB. Caso contrário, **false**.  
  
### <a name="remarks"></a>Comentários  
 Se o bitmap não é uma seção DIB, você não pode usar o seguinte `CImage` métodos que oferecem suporte a somente os bitmaps de seção DIB:  
  
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
 **True** se indexado; caso contrário **false**.  
  
### <a name="remarks"></a>Comentários  
 Este método retorna **true** somente se o bitmap é de 8 bits (256 cores) ou menos.  
  
> [!NOTE]
>  Este método dá suporte a apenas os bitmaps de seção DIB.  
  
##  <a name="isnull"></a>  CImage::IsNull  
 Determina se um bitmap é carregado no momento.  
  
```
bool IsNull() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Este método retorna **True** se um bitmap não é atualmente carregado; caso contrário **False**.  
  
##  <a name="istransparencysupported"></a>  CImage::IsTransparencySupported  
 Indica se o aplicativo dá suporte a bitmaps transparentes.  
  
```
static BOOL IsTransparencySupported() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a plataforma atual oferece suporte à transparência. Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se o valor de retorno é diferente de zero, e há suporte para transparência, uma chamada para [AlphaBlend](#alphablend), [TransparentBlt](#transparentblt), ou [desenhar](#draw) tratará cores transparentes.  
  

##  <a name="load"></a>  CImage::Load  
 Carrega uma imagem.  
  
```
HRESULT Load(LPCTSTR pszFileName) throw();
HRESULT Load(IStream* pStream) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszFileName`  
 Um ponteiro para uma cadeia de caracteres que contém o nome do arquivo de imagem para carregar.  
  
 `pStream`  
 Um ponteiro para um fluxo que contém o nome do arquivo de imagem para carregar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
### <a name="remarks"></a>Comentários  
 Carrega a imagem especificada por *pszFileName* ou `pStream`.  
  
 Tipos de imagem válidos são BMP, GIF, JPEG, PNG e TIFF.  
  
##  <a name="loadfromresource"></a>  CImage::LoadFromResource  
 Carrega uma imagem de um `BITMAP` recursos.  
  
```
void LoadFromResource(
 HINSTANCE hInstance,
 LPCTSTR pszResourceName) throw();

void LoadFromResource(
 HINSTANCE hInstance,
 UINT nIDResource) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hInstance`  
 Identificador para uma instância do módulo que contém a imagem a ser carregado.  
  
 `pszResourceName`  
 Um ponteiro para a cadeia de caracteres que contém o nome do recurso que contém a imagem a ser carregado.  
  
 `nIDResource`  
 A ID do recurso para carregar.  
  
### <a name="remarks"></a>Comentários  
 O recurso deve ser do tipo `BITMAP`.  
  
##  <a name="maskblt"></a>  CImage::MaskBlt  
 Combina os dados de cor para os bitmaps de origem e de destino usando a máscara especificada e a operação de varredura.  
  
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
 `hDestDC`  
 O identificador para o módulo cujo executável contém o recurso.  
  
 `xDest`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `yDest`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `nDestWidth`  
 A largura, em unidades lógicas, o bitmap de retângulo e fonte de destino.  
  
 `nDestHeight`  
 A altura, em unidades lógicas, o bitmap de retângulo e fonte de destino.  
  
 `xSrc`  
 A lógica coordenada x do canto superior esquerdo do bitmap de origem.  
  
 `ySrc`  
 A lógica coordenada y do canto superior esquerdo do bitmap de origem.  
  
 `hbmMask`  
 Identificador para o bitmap de máscara monocromático combinado com o bitmap de cor no contexto do dispositivo de origem.  
  
 `xMask`  
 O deslocamento de pixel horizontal para o bitmap de máscara especificado pelo `hbmMask` parâmetro.  
  
 `yMask`  
 O deslocamento vertical de pixel do bitmap máscara especificado pelo `hbmMask` parâmetro.  
  
 `dwROP`  
 Especifica o primeiro e segundo plano códigos de operação varredura Ternário que usa o método para controlar a combinação de dados de origem e de destino. O código de operação de varredura em segundo plano é armazenado no byte de ordem superior da palavra de ordem superior desse valor; o código de operação de varredura de primeiro plano é armazenado no byte de ordem inferior da palavra de ordem superior desse valor; a palavra de ordem inferior desse valor é ignorada e deve ser zero. Para obter uma discussão de primeiro plano e plano de fundo no contexto desse método, consulte `MaskBlt` no SDK do Windows. Para obter uma lista dos códigos de operação de varredura comuns, consulte `BitBlt` no SDK do Windows.  
  
 `rectDest`  
 Uma referência a um `RECT` estrutura, identificando o destino.  
  
 `pointSrc`  
 Um `POINT` estrutura indicando o canto superior esquerdo do retângulo de origem.  
  
 `pointMask`  
 Um **ponto** estrutura indicando o canto superior esquerdo do bitmap máscara.  
  
 `pointDest`  
 Uma referência a um **ponto** estrutura que identifica o canto superior esquerdo do retângulo de destino, em unidades lógicas.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Esse método se aplica ao Windows NT, as versões 4.0 e posterior somente.  
  
##  <a name="operator_hbitmap"></a>  CImage::operator HBITMAP  
 Use este operador para obter o identificador de Windows GDI anexado do `CImage` objeto. Esse operador é um operador de conversão, que dá suporte ao uso direto de um `HBITMAP` objeto.  
  
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
 `hDestDC`  
 Um identificador para o contexto de dispositivo de destino.  
  
 *pPoints*  
 Um ponteiro para uma matriz de três pontos no espaço lógico que identificam três cantos do paralelogramo de destino. O canto superior esquerdo do retângulo de origem é mapeado para o primeiro ponto nessa matriz, o canto superior direito e o segundo ponto nessa matriz e o canto inferior esquerdo para o terceiro ponto. O canto inferior direito do retângulo de origem é mapeado para o ponto de quarto implícita em paralelogramo.  
  
 `hbmMask`  
 Um identificador para um bitmap monocromático opcional que é usado para mascarar as cores do retângulo de origem.  
  
 `xSrc`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `ySrc`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `nSrcWidth`  
 A largura, em unidades lógicas, do retângulo de origem.  
  
 `nSrcHeight`  
 A altura, em unidades lógicas, do retângulo de origem.  
  
 `xMask`  
 A coordenada x do canto superior esquerdo do bitmap monocromático.  
  
 `yMask`  
 A coordenada y do canto superior esquerdo do bitmap monocromático.  
  
 `rectSrc`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura especificando as coordenadas do retângulo de origem.  
  
 `pointMask`  
 Um [ponto](http://msdn.microsoft.com/library/windows/desktop/dd162805) estrutura indicando o canto superior esquerdo do bitmap máscara.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Se `hbmMask` identifica um bitmap monocromático válido, **PlgBit** usa este bitmap para a máscara de bits de dados de cor do retângulo de origem.  
  
 Esse método se aplica ao Windows NT, as versões 4.0 e posterior somente. Consulte [PlgBlt](http://msdn.microsoft.com/library/windows/desktop/dd162804) no SDK do Windows para obter informações mais detalhadas.  
  
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
 Esse método deve ser chamado para liberar recursos alocados por global `CImage` objeto. Consulte [CImage::CImage](#cimage).  
  
##  <a name="save"></a>  CImage::Save  
 Salva uma imagem para o arquivo em disco ou o fluxo especificado.  
  
```
HRESULT Save(IStream* pStream,
 REFGUID guidFileType) const throw();

HRESULT Save(LPCTSTR pszFileName,
 REFGUID guidFileType= GUID_NULL) const throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `pStream`  
 Um ponteiro para um objeto COM IStream que contém os dados de imagem do arquivo.  
  
 *pszFileName*  
 Um ponteiro para o nome do arquivo da imagem.  
  
 `guidFileType`  
 O tipo de arquivo para salvar a imagem como. Pode ser um dos seguintes:  
  
- **ImageFormatBMP** uma imagem de bitmap não compactado.  
  
- **ImageFormatPNG** imagem compactada um gráfico PNG (Portable Network).  
  
- **ImageFormatJPEG** imagem compactada um JPEG.  
  
- **ImageFormatGIF** imagem compactada um GIF.  
  
> [!NOTE]
>  Para obter uma lista completa das constantes, consulte **constantes de formato de arquivo de imagem** no SDK do Windows.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
### <a name="remarks"></a>Comentários  
 Chame essa função para salvar a imagem usando um nome e tipo especificados. Se o `guidFileType` parâmetro não for incluído, a extensão do nome de arquivo será usado para determinar o formato de imagem. Se não for fornecido, a imagem será salva no formato BMP.  
  
##  <a name="setcolortable"></a>  CImage::SetColorTable  
 Define os valores de cor (RGB) vermelhos, verdes e azuis para um intervalo de entradas na paleta da seção DIB.  
  
```
void SetColorTable(
  UINT iFirstColor, 
  UINT nColors,
  const RGBQUAD* prgbColors) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `iFirstColor`  
 O índice da tabela de cores da primeira entrada para definir.  
  
 `nColors`  
 O número de entradas de tabela de cores para definir.  
  
 `prgbColors`  
 Um ponteiro para a matriz de [RGBQUAD](http://msdn.microsoft.com/library/windows/desktop/dd162938) estruturas para definir a cor de entradas de tabela.  
  
### <a name="remarks"></a>Comentários  
 Este método dá suporte a apenas os bitmaps de seção DIB.  
  
##  <a name="setpixel"></a>  CImage::SetPixel  
 Define a cor de um pixel em um local específico no bitmap.  
  
```
void SetPixel(int x, int y, COLORREF color) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 O local horizontal de pixel para definir.  
  
 *y*  
 O local vertical de pixel para definir.  
  
 `color`  
 A cor que você definiu o pixel.  
  
### <a name="remarks"></a>Comentários  
 Esse método falhar se situa fora da região de recorte selecionado de coordenadas de pixel.  
  
##  <a name="setpixelindexed"></a>  CImage::SetPixelIndexed  
 Define a cor de pixel para a cor em `iIndex` na paleta de cores.  
  
```
void SetPixelIndexed(int x, int y, int iIndex) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 O local horizontal de pixel para definir.  
  
 *y*  
 O local vertical de pixel para definir.  
  
 `iIndex`  
 O índice de uma cor na paleta de cores.  
  
##  <a name="setpixelrgb"></a>  CImage::SetPixelRGB  
 Define o pixel nos locais especificados por *x* e *y* para as cores indicadas pelo *r*, *g*, e *b*, em um vermelho, verde e azul imagem (RGB).  
  
```
void SetPixelRGB(  
 int x,
 int y,
 BYTE r,
 BYTE g,
 BYTE b) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 O local horizontal de pixel para definir.  
  
 *y*  
 O local vertical de pixel para definir.  
  
 *r*  
 A intensidade da cor vermelha.  
  
 *g*  
 A intensidade da cor verde.  
  
 *b*  
 A intensidade da cor azul.  
  
### <a name="remarks"></a>Comentários  
 Os parâmetros de vermelhos, verdes e azuis são representados por um número entre 0 e 255. Se você definir todos os três parâmetros como zero, a cor resultante combinada é preta. Se você definir todos os três parâmetros até 255, combinada cor resultante é branca.  
  
##  <a name="settransparentcolor"></a>  CImage::SetTransparentColor  
 Define uma cor em um determinado local indexado como transparente.  
  
```
LONG SetTransparentColor(LONG iTransparentColor) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 *iTransparentColor*  
 O índice em uma paleta de cores, da cor a ser definida como transparente. Se-1, nenhuma cor é definida como transparente.  
  
### <a name="return-value"></a>Valor de retorno  
 O índice da cor definida anteriormente como transparente.  
  
##  <a name="stretchblt"></a>  CImage::StretchBlt  
 Copia um bitmap do contexto de dispositivo de origem para este contexto de dispositivo atual.  
  
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
 `hDestDC`  
 Um identificador para o contexto de dispositivo de destino.  
  
 `xDest`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `yDest`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `nDestWidth`  
 A largura, em unidades lógicas, do retângulo de destino.  
  
 `nDestHeight`  
 A altura, em unidades lógicas, do retângulo de destino.  
  
 `dwROP`  
 A operação de varredura a ser executada. Códigos de operação de varredura definem exatamente como combinar os bits de origem, destino e o padrão (conforme definido pelo pincel selecionado no momento) para formar o destino. Consulte [BitBlt](http://msdn.microsoft.com/library/windows/desktop/dd183370) no SDK do Windows para obter uma lista de outros códigos de operação de varredura e suas descrições.  
  
 `rectDest`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, identificando o destino.  
  
 `xSrc`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `ySrc`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `nSrcWidth`  
 A largura, em unidades lógicas, do retângulo de origem.  
  
 `nSrcHeight`  
 A altura, em unidades lógicas, do retângulo de origem.  
  
 `rectSrc`  
 Uma referência a um `RECT` estrutura, identificando a origem.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedido, caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações, consulte [StretchBlt](http://msdn.microsoft.com/library/windows/desktop/dd145120) no SDK do Windows.  
  
##  <a name="transparentblt"></a>  CImage::TransparentBlt  
 Copia um bitmap do contexto de dispositivo de origem para este contexto de dispositivo atual.  
  
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
 `hDestDC`  
 Um identificador para o contexto de dispositivo de destino.  
  
 `xDest`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `yDest`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de destino.  
  
 `nDestWidth`  
 A largura, em unidades lógicas, do retângulo de destino.  
  
 `nDestHeight`  
 A altura, em unidades lógicas, do retângulo de destino.  
  
 *crTransparent*  
 A cor no bitmap de origem a ser tratada como transparente. Por padrão, **CLR_INVALID**, indicando que a cor atualmente definida como a cor transparente da imagem deve ser usada.  
  
 `rectDest`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura, identificando o destino.  
  
 `xSrc`  
 A coordenada x, em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `ySrc`  
 A coordenada y, em unidades lógicas, do canto superior esquerdo do retângulo de origem.  
  
 `nSrcWidth`  
 A largura, em unidades lógicas, do retângulo de origem.  
  
 `nSrcHeight`  
 A altura, em unidades lógicas, do retângulo de origem.  
  
 `rectSrc`  
 Uma referência a um `RECT` estrutura, identificando a origem.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se for bem-sucedido, caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 `TransparentBlt` há suporte para os bitmaps de origem de 4 bits por pixel e 8 bits por pixel. Use [CImage::AlphaBlend](#alphablend) para especificar os bitmaps de 32 bits por pixel com transparência.  
  
  
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
 [Exemplo de MMXSwarm](../../visual-cpp-samples.md)   
 [Exemplo de SimpleImage](../../visual-cpp-samples.md)   
 [Bitmaps independentes de dispositivo](http://msdn.microsoft.com/library/windows/desktop/dd183562)   
 [CreateDIBSection](http://msdn.microsoft.com/library/windows/desktop/dd183494)   
 [Componentes de área de trabalho COM ATL](../../atl/atl-com-desktop-components.md) [Bitmaps independentes de dispositivo](http://msdn.microsoft.com/library/windows/desktop/dd183562)   
 [CreateDIBSection](http://msdn.microsoft.com/library/windows/desktop/dd183494)   









