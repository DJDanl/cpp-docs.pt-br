---
title: Classe CDrawingManager
ms.date: 11/04/2016
f1_keywords:
- CDrawingManager
- AFXDRAWMANAGER/CDrawingManager
- AFXDRAWMANAGER/CDrawingManager::CDrawingManager
- AFXDRAWMANAGER/CDrawingManager::CreateBitmap_32
- AFXDRAWMANAGER/CDrawingManager::DrawAlpha
- AFXDRAWMANAGER/CDrawingManager::DrawRotated
- AFXDRAWMANAGER/CDrawingManager::DrawEllipse
- AFXDRAWMANAGER/CDrawingManager::DrawGradientRing
- AFXDRAWMANAGER/CDrawingManager::DrawRect
- AFXDRAWMANAGER/CDrawingManager::DrawShadow
- AFXDRAWMANAGER/CDrawingManager::Fill4ColorsGradient
- AFXDRAWMANAGER/CDrawingManager::FillGradient
- AFXDRAWMANAGER/CDrawingManager::FillGradient2
- AFXDRAWMANAGER/CDrawingManager::GrayRect
- AFXDRAWMANAGER/CDrawingManager::HighlightRect
- AFXDRAWMANAGER/CDrawingManager::HLStoRGB_ONE
- AFXDRAWMANAGER/CDrawingManager::HLStoRGB_TWO
- AFXDRAWMANAGER/CDrawingManager::HSVtoRGB
- AFXDRAWMANAGER/CDrawingManager::HuetoRGB
- AFXDRAWMANAGER/CDrawingManager::MirrorRect
- AFXDRAWMANAGER/CDrawingManager::PixelAlpha
- AFXDRAWMANAGER/CDrawingManager::PrepareShadowMask
- AFXDRAWMANAGER/CDrawingManager::RGBtoHSL
- AFXDRAWMANAGER/CDrawingManager::RGBtoHSV
- AFXDRAWMANAGER/CDrawingManager::SetAlphaPixel
- AFXDRAWMANAGER/CDrawingManager::SetPixel
- AFXDRAWMANAGER/CDrawingManager::SmartMixColors
helpviewer_keywords:
- CDrawingManager [MFC], CDrawingManager
- CDrawingManager [MFC], CreateBitmap_32
- CDrawingManager [MFC], DrawAlpha
- CDrawingManager [MFC], DrawRotated
- CDrawingManager [MFC], DrawEllipse
- CDrawingManager [MFC], DrawGradientRing
- CDrawingManager [MFC], DrawRect
- CDrawingManager [MFC], DrawShadow
- CDrawingManager [MFC], Fill4ColorsGradient
- CDrawingManager [MFC], FillGradient
- CDrawingManager [MFC], FillGradient2
- CDrawingManager [MFC], GrayRect
- CDrawingManager [MFC], HighlightRect
- CDrawingManager [MFC], HLStoRGB_ONE
- CDrawingManager [MFC], HLStoRGB_TWO
- CDrawingManager [MFC], HSVtoRGB
- CDrawingManager [MFC], HuetoRGB
- CDrawingManager [MFC], MirrorRect
- CDrawingManager [MFC], PixelAlpha
- CDrawingManager [MFC], PrepareShadowMask
- CDrawingManager [MFC], RGBtoHSL
- CDrawingManager [MFC], RGBtoHSV
- CDrawingManager [MFC], SetAlphaPixel
- CDrawingManager [MFC], SetPixel
- CDrawingManager [MFC], SmartMixColors
ms.assetid: 9e4775ca-101b-4aa9-a85a-4d047c701215
ms.openlocfilehash: 73c5775c2cb83dea79401615b31f2194094fac8e
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81753229"
---
# <a name="cdrawingmanager-class"></a>Classe CDrawingManager

A `CDrawingManager` classe implementa algoritmos complexos de desenho.

## <a name="syntax"></a>Sintaxe

```
class CDrawingManager : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDrawingManager::CDrawingManager](#cdrawingmanager)|Constrói um objeto `CDrawingManager`.|
|`CDrawingManager::~CDrawingManager`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDrawingManager::CreateBitmap_32](#createbitmap_32)|Cria um bitmap (DIB) independente de dispositivo de 32 bits para o quais os aplicativos podem escrever diretamente.|
|[CDrawingManager::DrawAlpha](#drawalpha)|Exibe bitmaps que possuem pixels transparentes ou semitransparentes.|
|[CDrawingManager::DrawRotated](#drawrotated)|Gira um conteúdo DC de origem dentro do retângulo dado em +/- 90 graus|
|[CDrawingManager::DrawEllipse](#drawellipse)|Desenha uma elipse com as cores de enchimento e borda fornecidas.|
|[CDrawingManager::DrawGradientRing](#drawgradientring)|Desenha um anel e enche-o com um gradiente de cor.|
|[CDrawingManager::DrawLine, CDrawingManager::DrawLineA](#drawline_cdrawingmanager__drawlinea)|Desenha uma linha.|
|[CDrawingManager::DrawRect](#drawrect)|Desenha um retângulo com as cores de enchimento e borda fornecidas.|
|[CDrawingManager::DrawShadow](#drawshadow)|Desenha uma sombra para uma área retangular.|
|[CDrawingManager::Fill4ColorsGradient](#fill4colorsgradient)|Preenche uma área retangular com dois gradientes de cor.|
|[CDrawingManager::FillGradient](#fillgradient)|Preenche uma área retangular com um gradiente de cor especificado.|
|[CDrawingManager::FillGradient2](#fillgradient2)|Preenche uma área retangular com um gradiente de cor especificado. A direção da mudança de cor do gradiente também é especificada.|
|[CDrawingManager::GrayRect](#grayrect)|Preenche um retângulo com uma cor cinza especificada.|
|[CDrawingManager::HighlightRect](#highlightrect)|Destaca uma área retangular.|
|[CDrawingManager::HLStoRGB_ONE](#hlstorgb_one)|Converte uma cor de uma representação HLS para uma representação RGB.|
|[CDrawingManager::HLStoRGB_TWO](#hlstorgb_two)|Converte uma cor de uma representação HLS para uma representação RGB.|
|[CDrawingManager::HSVtoRGB](#hsvtorgb)|Converte uma cor de uma representação HSV para uma representação RGB.|
|[CDrawingManager::HuetoRGB](#huetorgb)|Método auxiliar que converte um valor de matiz em um componente vermelho, verde ou azul.|
|[CDrawingManager::MirrorRect](#mirrorrect)|Vira uma área retangular.|
|[CDrawingManager::PixelAlpha](#pixelalpha)|Método auxiliar que determina a cor final para um pixel semitransparente.|
|[CDrawingManager::PrepareShadowMask](#prepareshadowmask)|Cria um bitmap que pode ser usado como uma sombra.|
|[CDrawingManager::RGBtoHSL](#rgbtohsl)|Converte uma cor de uma representação RGB para uma representação HSL.|
|[CDrawingManager::RGBtoHSV](#rgbtohsv)|Converte uma cor de uma representação RGB para uma representação HSV.|
|[CDrawingManager::SetAlphaPixel](#setalphapixel)|Método auxiliar que colore um pixel parcialmente transparente em um bitmap.|
|[CDrawingManager::SetPixel](#setpixel)|Método auxiliar que altera um único pixel em um bitmap para a cor especificada.|
|[CDrawingManager::SmartMixCores](#smartmixcolors)|Combina duas cores com base em uma relação ponderada.|

## <a name="remarks"></a>Comentários

A `CDrawingManager` classe fornece funções para desenhar sombras, gradientes de cores e retângulos destacados. Ele também executa a mistura alfa. Você pode usar esta classe para alterar diretamente a interface do motorista do seu aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)<br/>
`CDrawingManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdrawmanager.h

## <a name="cdrawingmanagercdrawingmanager"></a><a name="cdrawingmanager"></a>CDrawingManager::CDrawingManager

Constrói um objeto [CDrawingManager.](../../mfc/reference/cdrawingmanager-class.md)

```
CDrawingManager(CDC& dc);
```

### <a name="parameters"></a>Parâmetros

*Dc*<br/>
[em] Uma referência a um contexto de dispositivo. O `CDrawingManager` uso deste contexto para desenhar.

## <a name="cdrawingmanagercreatebitmap_32"></a><a name="createbitmap_32"></a>CDrawingManager::CreateBitmap_32

Cria um bitmap (DIB) independente de dispositivo de 32 bits para o quais os aplicativos podem escrever diretamente.

```
static HBITMAP __stdcall CreateBitmap_32(
    const CSize& size,
    void** pBits);

static HBITMAP __stdcall CreateBitmap_32(
    HBITMAP bitmap,
    COLORREF clrTransparent = -1);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*size*|[em] Um [parâmetro CSize](../../atl-mfc-shared/reference/csize-class.md) que indica o tamanho do bitmap.|
|*pBits*|[fora] Um ponteiro para um ponteiro de dados que recebe a localização dos valores de bit do DIB.|
|*Bitmap*|Uma alça para o bitmap original|
|*clrTransparent*|Um valor RGB especificando a cor transparente do bitmap original.|

### <a name="return-value"></a>Valor retornado

Uma alça para o bitmap DIB recém-criado se esse método for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como criar um bitmap DIB, consulte [CreateDIBSection](/windows/win32/api/wingdi/nf-wingdi-createdibitmap).

## <a name="cdrawingmanagerdrawalpha"></a><a name="drawalpha"></a>CDrawingManager::DrawAlpha

Exibe bitmaps que possuem pixels transparentes ou semitransparentes.

```cpp
void DrawAlpha(
    CDC* pDstDC,
    const CRect& rectDst,
    CDC* pSrcDC,
    const CRect& rectSrc);
```

### <a name="parameters"></a>Parâmetros

*pDstDC*<br/>
[em] Um ponteiro para o contexto do dispositivo para o destino.

*rectDst*<br/>
[em] O retângulo de destino.

*pSrcDC*<br/>
[em] Um ponteiro para o contexto do dispositivo para a fonte.

*rectSrc*<br/>
[em] O retângulo de origem.

### <a name="remarks"></a>Comentários

Este método executa a mistura alfa para dois bitmaps. Para obter mais informações sobre a mistura alfa, consulte [AlphaBlend](/windows/win32/api/wingdi/nf-wingdi-alphablend) no SDK do Windows.

## <a name="cdrawingmanagerdrawellipse"></a><a name="drawellipse"></a>CDrawingManager::DrawEllipse

Desenha uma elipse com as cores de enchimento e borda fornecidas.

```cpp
void DrawEllipse(
    const CRect& rect,
    COLORREF clrFill,
    COLORREF clrLine);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] O retângulo delimitador para a elipse.

*clrFill*<br/>
[em] A cor que este método usa para preencher a elipse.

*clrLine*<br/>
[em] A cor que este método usa como a borda da elipse.

### <a name="remarks"></a>Comentários

Este método retorna sem desenhar uma elipse se qualquer cor estiver definida como -1. Ele também retorna sem desenhar uma elipse se qualquer dimensão do retângulo delimitador for 0.

## <a name="cdrawingmanagerdrawgradientring"></a><a name="drawgradientring"></a>CDrawingManager::DrawGradientRing

Desenha um anel e enche-o com um gradiente de cor.

```
BOOL DrawGradientRing(
    CRect rect,
    COLORREF colorStart,
    COLORREF colorFinish,
    COLORREF colorBorder,
    int nAngle,
    int nWidth,
    COLORREF clrFace = (COLORREF)-1);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] Um [parâmetro CRect](../../atl-mfc-shared/reference/crect-class.md) que especifica o limite para o anel de gradiente.

*colorStart*<br/>
[em] A primeira cor para o gradiente.

*colorFinish*<br/>
[em] A última cor para o gradiente.

*colorBorder*<br/>
[em] A cor da fronteira.

*nAngle*<br/>
[em] Um parâmetro que especifica o ângulo inicial de desenho do gradiente. Este valor deve ser entre 0 e 360.

*Nwidth*<br/>
[em] A largura da borda para o anel.

*clrFace*<br/>
[em] A cor do interior do anel.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O retângulo definido por *reto* deve ter pelo menos 5 pixels de largura e 5 pixels de altura.

## <a name="cdrawingmanagerdrawline-cdrawingmanagerdrawlinea"></a><a name="drawline_cdrawingmanager__drawlinea"></a>CDrawingManager::DrawLine, CDrawingManager::DrawLineA

Desenha uma linha.

```cpp
void DrawLine(
    int x1,
    int y1,
    int x2,
    int y2,
    COLORREF clrLine);

void DrawLineA(
    double x1,
    double y1,
    double x2,
    double y2,
    COLORREF clrLine);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*x1*|[em] A coordenada x onde a linha começa.|
|*y1*|[em] A coordenada y onde a linha começa.|
|*x2*|[em] A coordenada x onde a linha termina.|
|*y2*|[em] A coordenada y onde a linha termina.|
|*clrLine*|[em] A cor da linha.|

### <a name="remarks"></a>Comentários

Este método falha se *clrLine* for igual a -1.

## <a name="cdrawingmanagerdrawrect"></a><a name="drawrect"></a>CDrawingManager::DrawRect

Desenha um retângulo com as cores de enchimento e borda fornecidas.

```cpp
void DrawRect(
    const CRect& rect,
    COLORREF clrFill,
    COLORREF clrLine);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] Os limites para o retângulo.

*clrFill*<br/>
[em] A cor que este método usa para preencher o retângulo.

*clrLine*<br/>
[em] A cor que este método usa para a borda do retângulo.

### <a name="remarks"></a>Comentários

Este método retorna sem desenhar um retângulo se qualquer cor estiver definida como -1. Ele também retorna se qualquer dimensão do retângulo for 0.

## <a name="cdrawingmanagerdrawshadow"></a><a name="drawshadow"></a>CDrawingManager::DrawShadow

Desenha uma sombra para uma área retangular.

```
BOOL DrawShadow(
    CRect rect,
    int nDepth,
    int iMinBrightness = 100,
    int iMaxBrightness = 50,
    CBitmap* pBmpSaveBottom = NULL,
    CBitmap* pBmpSaveRight = NULL,
    COLORREF clrBase = (COLORREF)-1,
    BOOL bRightShadow = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] Uma área retangular em sua aplicação. O gerente de desenho desenhará uma sombra debaixo desta área.

*nProfundidade*<br/>
[em] A largura e a altura da sombra.

*iMinBrightness*<br/>
[em] O brilho mínimo da sombra.

*iMaxBrightness*<br/>
[em] O brilho máximo da sombra.

*pBmpSaveBottom*<br/>
[em] Um ponteiro para um bitmap que contém a imagem para a parte inferior da sombra.

*pBmpSaveRight*<br/>
[em] Um ponteiro para um bitmap que contém a imagem para a sombra que é desenhada no lado direito do retângulo.

*clrBase*<br/>
[em] A cor da sombra.

*bRightShadow*<br/>
[em] Um parâmetro booleano que indica como a sombra é desenhada. Se *bRightShadow* `DrawShadow` for, `TRUE`desenhista uma sombra no lado direito do retângulo.

### <a name="return-value"></a>Valor retornado

Não zero se bem sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode fornecer dois bitmaps válidos para as sombras inferior e direita usando os parâmetros *pBmpSaveBottom* e *pBmpSaveRight*. Se esses objetos [CBitmap](../../mfc/reference/cbitmap-class.md) tiverem um `DrawShadow` objeto GDI conectado, usarão esses bitmaps como sombras. Se `CBitmap` os parâmetros não tiverem um `DrawShadow` objeto GDI conectado, desensere a sombra e anexe os bitmaps aos parâmetros. Em chamadas `DrawShadow`futuras para , você pode fornecer esses bitmaps para acelerar o processo de desenho. Para obter mais `CBitmap` informações sobre a classe e os objetos GDI, consulte [Objetos Gráficos](../../mfc/graphic-objects.md).

Se qualquer um `NULL`desses `DrawShadow` parâmetros for, desenhará automaticamente a sombra.

Se você definir *bRightShadow* como FALSE, a sombra será desenhada por baixo e à esquerda da área retangular.

### <a name="example"></a>Exemplo

O exemplo a seguir `DrawShadow` demonstra como `CDrawingManager` usar o método da classe. Este trecho de código faz parte da [amostra de demonstração da folha de prop](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_PropSheetDemo#1](../../mfc/reference/codesnippet/cpp/cdrawingmanager-class_1.cpp)]

## <a name="cdrawingmanagerfill4colorsgradient"></a><a name="fill4colorsgradient"></a>CDrawingManager::Fill4ColorsGradient

Preenche uma área retangular com dois gradientes de cor.

```cpp
void Fill4ColorsGradient(
    CRect rect,
    COLORREF colorStart1,
    COLORREF colorFinish1,
    COLORREF colorStart2,
    COLORREF colorFinish2,
    BOOL bHorz = TRUE,
    int nPercentage = 50);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] O retângulo para preencher.

*corStart1*<br/>
[em] A cor inicial para o primeiro gradiente de cor.

*colorFinish1*<br/>
[em] A cor final para o primeiro gradiente de cor.

*corStart2*<br/>
[em] A cor inicial para o segundo gradiente de cor.

*colorFinish2*<br/>
[em] A cor final para o segundo gradiente de cor.

*Bhorz*<br/>
[em] Um parâmetro booleano `Fill4ColorsGradient` que indica se colore um gradiente horizontal ou vertical. TRUE indica um gradiente horizontal.

*Npercentage*<br/>
[em] Um inteiro de 0-100. Este valor indica a porcentagem do retângulo para preencher com o primeiro gradiente de cor.

### <a name="remarks"></a>Comentários

Quando um retângulo é preenchido com dois gradientes de cor, eles estão localizados acima um do outro ou próximos um do outro, dependendo do valor de *bHorz*. Cada gradiente de cor é calculado independentemente com o método [CDrawingManager::FillGradient](#fillgradient).

Este método gera uma falha de afirmação se *nPercentage* for menor que 0 ou mais de 100.

## <a name="cdrawingmanagerfillgradient"></a><a name="fillgradient"></a>CDrawingManager::FillGradient

Preenche uma área retangular com o gradiente de cor especificado.

```cpp
void FillGradient(
    CRect rect,
    COLORREF colorStart,
    COLORREF colorFinish,
    BOOL bHorz = TRUE,
    int nStartFlatPercentage = 0,
    int nEndFlatPercentage = 0);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] A área retangular para preencher.

*colorStart*<br/>
[em] A primeira cor para o gradiente.

*colorFinish*<br/>
[em] A cor final para o gradiente.

*Bhorz*<br/>
[em] Um parâmetro booleano que `FillGradient` especifica se deve desenhar um gradiente horizontal ou vertical.

*nIniciarFlatPercentagel*<br/>
[em] A porcentagem do retângulo que `FillGradient` se enche com *corStart* antes de iniciar o gradiente.

*nEndFlatPercentage*<br/>
[em] A porcentagem do retângulo que `FillGradient` se enche de *corTermine* depois de terminar o gradiente.

### <a name="example"></a>Exemplo

O exemplo a seguir `FillGradient` demonstra como `CDrawingManager` usar o método da classe. Este trecho de código faz parte da amostra de [demonstração do MS Office 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#12](../../mfc/reference/codesnippet/cpp/cdrawingmanager-class_2.cpp)]

## <a name="cdrawingmanagerfillgradient2"></a><a name="fillgradient2"></a>CDrawingManager::FillGradient2

Preenche uma área retangular com um gradiente de cor especificado.

```cpp
void FillGradient2 (
    CRect rect,
    COLORREF colorStart,
    COLORREF colorFinish,
    int nAngle = 0);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] A área retangular para preencher.

*colorStart*<br/>
[em] A primeira cor do gradiente.

*colorFinish*<br/>
[em] A última cor do gradiente.

*nAngle*<br/>
[em] Um inteiro entre 0 e 360. Este parâmetro especifica a direção do gradiente de cor.

### <a name="remarks"></a>Comentários

Use *nAngle* para especificar a direção do gradiente de cor. Quando você especifica a direção do gradiente de cor, você também especifica onde o gradiente de cor é iniciado. Um valor de 0 para *nAngle* indica que o gradiente começa a partir da parte superior do retângulo. À medida *que o nAngle* aumenta, o local de partida para o gradiente se move no sentido anti-horário com base no ângulo.

### <a name="example"></a>Exemplo

O exemplo a seguir `FillGradient2` demonstra como `CDrawingManager` usar o método da classe. Este trecho de código faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#37](../../mfc/reference/codesnippet/cpp/cdrawingmanager-class_3.cpp)]

## <a name="cdrawingmanagergrayrect"></a><a name="grayrect"></a>CDrawingManager::GrayRect

Preenche um retângulo com uma cor cinza especificada.

```
BOOL GrayRect(
    CRect rect,
    int nPercentage = -1,
    COLORREF clrTransparent = (COLORREF)-1,
    COLORREF clrDisabled = (COLORREF)-1);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] A área retangular para preencher.

*Npercentage*<br/>
[em] A porcentagem de cinza que você quer no retângulo.

*clrTransparent*<br/>
[em] A cor transparente.

*clrDisabled*<br/>
[em] A cor que este método usa para dessaturação se *nPercentage* for definida como -1.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método foi bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Para o parâmetro *nPercentage*, um valor mais baixo indica uma cor mais escura.

O valor máximo para *nPercentageéis* é 200. Um valor maior que 200 não altera a aparência do retângulo. Se o valor for -1, este método usa *clrDisabled* para limitar a saturação do retângulo.

## <a name="cdrawingmanagerhighlightrect"></a><a name="highlightrect"></a>CDrawingManager::HighlightRect

Destaca uma área retangular.

```
BOOL HighlightRect(
    CRect rect,
    int nPercentage = -1,
    COLORREF clrTransparent = (COLORREF)-1,
    int nTolerance = 0,
    COLORREF clrBlend = (COLORREF)-1);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] Uma área retangular para destacar.

*Npercentage*<br/>
[em] Uma porcentagem que indica o quão transparente deve ser o destaque.

*clrTransparent*<br/>
[em] A cor transparente.

*nTolerância*<br/>
[em] Um inteiro entre 0 e 255 que indica a tolerância à cor.

*clrBlend*<br/>
[em] A cor base para a mistura.

### <a name="return-value"></a>Valor retornado

VERDADEIRO se o método for bem sucedido; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Se *nPercentage* estiver entre 0 `HighlightRect` e 99, use o algoritmo de mistura alfa. Para obter mais informações sobre a mistura alfa, consulte [Alpha Blending Lines and Fills](/dotnet/framework/winforms/advanced/alpha-blending-lines-and-fills). Se *nPercentageis* for -1, este método usará o nível de destaque padrão. Se *nPercentage* for 100, este método não faz nada e retorna TRUE.

O método usa o parâmetro *nTolerance* para determinar se destaca a área retangular. Para destacar o retângulo, a diferença entre a cor de fundo do seu aplicativo e *o clrTransparent* deve ser menor que *a nTolerância* em cada componente de cor (vermelho, verde e azul).

## <a name="cdrawingmanagerhlstorgb_one"></a><a name="hlstorgb_one"></a>CDrawingManager::HLStoRGB_ONE

Converte uma cor de uma representação HLS para uma representação RGB.

```
static COLORREF __stdcall HLStoRGB_ONE(
    double H,
    double L,
    double S);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
[em] Um número entre 0 e 1 que representa a tonalidade para a cor.

*L*<br/>
[em] Um número entre 0 e 1 que indica a luminosidade para a cor.

*S*<br/>
[em] Um número entre 0 e 1 que indica a saturação para a cor.

### <a name="return-value"></a>Valor retornado

A representação RGB da cor HLS fornecida.

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (matiz, saturação e valor), HSL (matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Cor](/windows/win32/uxguide/vis-color).

Este método `CDrawingManager::HLStoRGB_TWO` e o método realizam a mesma operação, mas requerem valores diferentes para o parâmetro *H.* Neste método, *H* é uma porcentagem do círculo. No `CDrawingManager::HLStoRGB_TWO` método, *H* é um valor de grau entre 0 e 360, que ambos representam vermelho. Por exemplo, `HLStoRGB_ONE`com , um valor de 0,25 para *H* é equivalente a um valor de 90 com `HLStoRGB_TWO`.

## <a name="cdrawingmanagerhlstorgb_two"></a><a name="hlstorgb_two"></a>CDrawingManager::HLStoRGB_TWO

Converte uma cor de uma representação HLS para uma representação RGB.

```
static COLORREF __stdcall HLStoRGB_TWO(
    double H,
    double L,
    double S);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
[em] Um número entre 0 e 360 que representa a tonalidade para a cor.

*L*<br/>
[em] Um número entre 0 e 1 que indica a luminosidade para a cor.

*S*<br/>
[em] Um número entre 0 e 1 que indica a saturação para a cor.

### <a name="return-value"></a>Valor retornado

A representação RGB da cor HLS fornecida.

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (matiz, saturação e valor), HSL (matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Cor](/windows/win32/uxguide/vis-color).

Este método e o método [CDrawingManager::HLStoRGB_ONE](#hlstorgb_one) realizam a mesma operação, mas requerem valores diferentes para o parâmetro *H.* Neste método, *H* é um valor de grau entre 0 e 360, que ambos representam vermelho. No método [CDrawingManager::HLStoRGB_ONE,](#hlstorgb_one) *H* é uma porcentagem do círculo. Por exemplo, `HLStoRGB_ONE`com , um valor de 0,25 para *H* é equivalente a um valor de 90 com `HLStoRGB_TWO`.

## <a name="cdrawingmanagerhsvtorgb"></a><a name="hsvtorgb"></a>CDrawingManager::HSVtoRGB

Converte uma cor de uma representação HSV para uma representação RGB.

```
static COLORREF __stdcall HSVtoRGB(
    double H,
    double S,
    double V);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*H*|[em] Um número entre 0 e 360 que indica a tonalidade para a cor.|
|*S*|[em] Um número entre 0 e 1 que indica a saturação para a cor.|
|*V*|[em] Um número entre 0 e 1 que indica o valor para a cor.|

### <a name="return-value"></a>Valor retornado

A representação RGB da cor HSV fornecida.

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (matiz, saturação e valor), HSL (matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Cor](/windows/win32/uxguide/vis-color).

## <a name="cdrawingmanagerhuetorgb"></a><a name="huetorgb"></a>CDrawingManager::HuetoRGB

Converte um valor de matiz em um componente vermelho, verde ou azul.

```
static double __stdcall HuetoRGB(
    double m1,
    double m2,
    double h);

static BYTE __stdcall HueToRGB(
    float rm1,
    float rm2,
    float rh);
```

### <a name="parameters"></a>Parâmetros

*m1*<br/>
[em] Veja observações.

*m2*<br/>
[em] Veja observações.

*H*<br/>
[em] Veja observações.

*rm1*<br/>
[em] Veja observações.

*rm2*<br/>
[em] Veja observações.

*rh*<br/>
[em] Veja observações.

### <a name="return-value"></a>Valor retornado

O componente vermelho, verde ou azul individual para a tonalidade fornecida.

### <a name="remarks"></a>Comentários

Este método é um método `CDrawingManager` auxiliar que a classe usa para calcular os componentes individuais vermelho, verde e azul de uma cor em uma representação HSV ou HSL. Este método não foi projetado para ser chamado diretamente pelo programador. Os parâmetros de entrada são valores que dependem do algoritmo de conversão.

Para converter uma cor HSV ou HSL em uma representação RGB, ligue para um dos seguintes métodos:

- [CDrawingManager::HSVtoRGB](#hsvtorgb)

- [CDrawingManager::HLStoRGB_ONE](#hlstorgb_one)

- [CDrawingManager::HLStoRGB_TWO](#hlstorgb_two)

## <a name="cdrawingmanagermirrorrect"></a><a name="mirrorrect"></a>CDrawingManager::MirrorRect

Vira uma área retangular.

```cpp
void MirrorRect(
    CRect rect,
    BOOL bHorz = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Rect*<br/>
[em] O retângulo delimitador da área para virar.

*Bhorz*<br/>
[em] Um parâmetro booleano que indica se o retângulo gira horizontal ou verticalmente.

### <a name="remarks"></a>Comentários

Este método pode inverter qualquer área `CDrawingManager` do contexto do dispositivo de propriedade da classe. Se *bHorz* for definido como TRUE, este método inverte a área horizontalmente. Caso contrário, ele vira a área verticalmente.

## <a name="cdrawingmanagerpixelalpha"></a><a name="pixelalpha"></a>CDrawingManager::PixelAlpha

Calcula a cor final para um pixel semitransparente.

```
static COLORREF __stdcall PixelAlpha(
    COLORREF srcPixel,
    int percent);

static COLORREF __stdcall PixelAlpha(
    COLORREF srcPixel,
    double percentR,
    double percentG,
    double percentB);

static COLORREF __stdcall PixelAlpha(
    COLORREF srcPixel,
    COLORREF dstPixel,
    int percent);
```

### <a name="parameters"></a>Parâmetros

*srcPixel*<br/>
[em] A cor inicial para o pixel.

*Por cento*<br/>
[em] Um número entre 0 e 100 que representa a porcentagem de transparência. Um valor de 100 indica que a cor inicial é completamente transparente.

*percentR*<br/>
[em] Um número entre 0 e 100 que representa a porcentagem de transparência para o componente vermelho.

*percentG*<br/>
[em] Um número entre 0 e 100 que representa a porcentagem de transparência para o componente verde.

*percentB*<br/>
[em] Um número entre 0 e 100 que representa a porcentagem de transparência para o componente azul.

*dstPixel*<br/>
[em] A cor base para o pixel.

### <a name="return-value"></a>Valor retornado

A cor final para o pixel semitransparente.

### <a name="remarks"></a>Comentários

Esta é uma classe auxiliar para colorir bitmaps semitransparentes e não foi projetada para ser chamada diretamente pelo programador.

Quando você usa a versão do método que tem *dstPixel,* a cor final é uma combinação de *dstPixel* e *srcPixel*. A cor *srcPixel* é a cor parcialmente transparente sobre a cor base do *dstPixel*.

## <a name="cdrawingmanagerprepareshadowmask"></a><a name="prepareshadowmask"></a>CDrawingManager::PrepareShadowMask

Cria um bitmap que pode ser usado como uma sombra.

```
static HBITMAP __stdcall PrepareShadowMask (
    int nDepth,
    COLORREF clrBase,
    int iMinBrightness = 0,
    int iMaxBrightness = 100);
```

### <a name="parameters"></a>Parâmetros

*nProfundidade*<br/>
[em] A largura e a altura da sombra.

*clrBase*<br/>
[em] A cor da sombra.

*iMinBrightness*<br/>
[em] O brilho mínimo da sombra.

*iMaxBrightness*<br/>
[em] O brilho máximo da sombra.

### <a name="return-value"></a>Valor retornado

Uma alça para o bitmap criado se esse método for bem sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se *nDepth* estiver definido como 0, este método sairá e retornará NULL. Se *nDepth* for menor que 3, a largura e a altura da sombra serão definidas como 3 pixels.

## <a name="cdrawingmanagerrgbtohsl"></a><a name="rgbtohsl"></a>CDrawingManager::RGBtoHSL

Converte uma cor de uma representação vermelha, verde e azul (RGB) em uma representação de matiz, saturação e leveza (HSL).

```
static void __stdcall RGBtoHSL(
    COLORREF rgb,
    double* H,
    double* S,
    double* L);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*Rgb*|[em] A cor em valores RGB.|
|*H*|[fora] Um ponteiro para um duplo onde o método armazena a tonalidade para a cor.|
|*S*|[fora] Um ponteiro para um duplo onde o método armazena a saturação para a cor.|
|*L*|[fora] Um ponteiro para um duplo onde o método armazena a leveza para a cor.|

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (matiz, saturação e valor), HSL (matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Cor](/windows/win32/uxguide/vis-color).

O valor devolvido para *H* é representado como uma fração entre 0 e 1 onde ambos 0 e 1 representam vermelho. Os valores devolvidos para *S* e *L* são números entre 0 e 1.

## <a name="cdrawingmanagerrgbtohsv"></a><a name="rgbtohsv"></a>CDrawingManager::RGBtoHSV

Converte uma cor de uma representação RGB para uma representação HSV.

```
static void __stdcall RGBtoHSV(
    COLORREF rgb,
    double* H,
    double* S,
    double* V);
```

### <a name="parameters"></a>Parâmetros

*Rgb*<br/>
[em] A cor a ser convertida em uma representação RGB.

*H*<br/>
[fora] Um ponteiro para um duplo onde este método armazena a tonalidade resultante para a cor.

*S*<br/>
[fora] Um ponteiro para um duplo onde este método armazena a saturação resultante para a cor.

*V*<br/>
[fora] Um ponteiro para um duplo onde este método armazena o valor resultante para a cor.

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (matiz, saturação e valor), HSL (matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Cor](/windows/win32/uxguide/vis-color).

O valor devolvido para *H* é um número entre 0 e 360 onde ambos 0 e 360 indicam vermelho. Os valores de retorno para *S* e *V* são números entre 0 e 1.

## <a name="cdrawingmanagersetalphapixel"></a><a name="setalphapixel"></a>CDrawingManager::SetAlphaPixel

Colore um pixel transparente em um bitmap.

```
static void __stdcall SetAlphaPixel(
    COLORREF* pBits,
    CRect rect,
    int x,
    int y,
    int percent,
    int iShadowSize,
    COLORREF clrBase = (COLORREF)-1,
    BOOL bIsRight = TRUE);
```

### <a name="parameters"></a>Parâmetros

*pBits*<br/>
[em] Um ponteiro para os valores de bit para o bitmap.

*Rect*<br/>
[em] Uma área retangular em sua aplicação. O gerente de desenho desenha uma sombra por baixo e à direita desta área.

*x*<br/>
[em] A coordenada horizontal do pixel para colorir.

*Y*<br/>
[em] A coordenada vertical do pixel para colorir.

*Por cento*<br/>
[em] A porcentagem de transparência.

*iShadowSize*<br/>
[em] A largura e a altura da sombra.

*clrBase*<br/>
[em] A cor da sombra.

*bIsRight*<br/>
[em] Um parâmetro booleano que indica qual pixel para colorir. Para obter mais informações, consulte a seção Comentários.

### <a name="remarks"></a>Comentários

Este método é um método auxiliar que é usado pelo método [CDrawingManager::DrawShadow.](#drawshadow) Recomendamos que, se você quiser `CDrawingManager::DrawShadow` desenhar uma sombra, ligue em vez disso.

Se *bIsRight* estiver definido como TRUE, o pixel a colore será medido *x* pixels da borda direita do *reto*. Se for FALSE, o pixel a colorir é medido *x* pixels da borda esquerda do *reto*.

## <a name="cdrawingmanagersetpixel"></a><a name="setpixel"></a>CDrawingManager::SetPixel

Altera um único pixel em um bitmap para a cor especificada.

```
static void __stdcall SetPixel(
    COLORREF* pBits,
    int cx,
    int cy,
    int x,
    int y,
    COLORREF color);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*pBits*|[em] Um ponteiro para os valores de bit do bitmap.|
|*Cx*|[em] A largura total do bitmap.|
|*Cy*|[em] A altura total do bitmap.|
|*x*|[em] A coordenada x do pixel no bitmap para mudar.|
|*Y*|[em] A coordenada y do pixel no bitmap para mudar.|
|*cor*|[em] A nova cor para o pixel identificado pelas coordenadas fornecidas.|

## <a name="cdrawingmanagersmartmixcolors"></a><a name="smartmixcolors"></a>CDrawingManager::SmartMixCores

Combina duas cores com base em uma relação ponderada.

```
static COLORREF __stdcall SmartMixColors(
    COLORREF color1,
    COLORREF color2,
    double dblLumRatio = 1.,
    int k1 = 1,
    int k2 = 1);
```

### <a name="parameters"></a>Parâmetros

|||
|-|-|
|Parâmetro|Descrição|
|*cor1*|[em] A primeira cor a misturar.|
|*cor2*|[em] A segunda cor para misturar.|
|*dblLumRatio*|[em] A proporção para a luminosidade da nova cor. `SmartMixColors`multiplica a luminosidade da cor mista por esta razão antes de determinar uma cor final.|
|*k1*|[em] A relação ponderada para a primeira cor.|
|*k2*|[em] A relação ponderada para a segunda cor.|

### <a name="return-value"></a>Valor retornado

Uma cor que representa uma mistura ponderada das cores fornecidas.

### <a name="remarks"></a>Comentários

Este método falha com um erro se *k1* ou *k2* for inferior a zero. Se ambos os parâmetros estiverem definidos `RGB(0, 0, 0)`como 0, o método retorna .

A razão ponderada é calculada com \* a seguinte fórmula: (color1 k1 + color2 \* k2)/(k1 + k2). Após a determinação da razão ponderada, o método calcula a luminosidade para a cor mista. Em seguida, multiplica a luminosidade por *dblLumRatio*. Se o valor for maior que 1.0, o método define a luminosidade para a cor mista para o novo valor. Caso contrário, a luminosidade é definida como 1.0.

## <a name="cdrawingmanagerdrawrotated"></a><a name="drawrotated"></a>CDrawingManager::DrawRotated

Gira um conteúdo DC de origem dentro do retângulo dado em 90 graus.

```cpp
void DrawRotated(
    CRect rectDest,
    CDC& dcSrc,
    BOOL bClockWise);
```

### <a name="parameters"></a>Parâmetros

*rectDest*<br/>
Retângulo de destino.

*dcSrc*<br/>
O contexto do dispositivo de origem.

*bWise clockwise*<br/>
TRUE indica rotação +90 graus; FALSE indica girar -90 graus.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
