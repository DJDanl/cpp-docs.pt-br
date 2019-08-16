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
ms.openlocfilehash: 69365b66b12d5a9284c9b097b225ba041e07b6b0
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69506801"
---
# <a name="cdrawingmanager-class"></a>Classe CDrawingManager

A `CDrawingManager` classe implementa algoritmos de desenho complexos.

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
|[CDrawingManager::CreateBitmap_32](#createbitmap_32)|Cria um bitmap independente de dispositivo de 32 bits (DIB) que os aplicativos podem gravar diretamente.|
|[CDrawingManager::DrawAlpha](#drawalpha)|Exibe os bitmaps que têm pixels transparentes ou semitransparentes.|
|[CDrawingManager::DrawRotated](#drawrotated)|Gira um conteúdo de DC de origem dentro do retângulo fornecido em +/-90 graus|
|[CDrawingManager::DrawEllipse](#drawellipse)|Desenha uma elipse com as cores de preenchimento e borda fornecidas.|
|[CDrawingManager::DrawGradientRing](#drawgradientring)|Desenha um anel e o preenche com um gradiente de cor.|
|[CDrawingManager::D rawLine, CDrawingManager::D rawLineA](#drawline_cdrawingmanager__drawlinea)|Desenha uma linha.|
|[CDrawingManager::DrawRect](#drawrect)|Desenha um retângulo com as cores de preenchimento e borda fornecidas.|
|[CDrawingManager::DrawShadow](#drawshadow)|Desenha uma sombra para uma área retangular.|
|[CDrawingManager::Fill4ColorsGradient](#fill4colorsgradient)|Preenche uma área retangular com dois gradientes de cor.|
|[CDrawingManager::FillGradient](#fillgradient)|Preenche uma área retangular com um gradiente de cor especificado.|
|[CDrawingManager::FillGradient2](#fillgradient2)|Preenche uma área retangular com um gradiente de cor especificado. A direção da alteração de cor do gradiente também é especificada.|
|[CDrawingManager::GrayRect](#grayrect)|Preenche um retângulo com uma cor cinza especificada.|
|[CDrawingManager::HighlightRect](#highlightrect)|Realça uma área retangular.|
|[CDrawingManager::HLStoRGB_ONE](#hlstorgb_one)|Converte uma cor de uma representação HLS em uma representação RGB.|
|[CDrawingManager::HLStoRGB_TWO](#hlstorgb_two)|Converte uma cor de uma representação HLS em uma representação RGB.|
|[CDrawingManager::HSVtoRGB](#hsvtorgb)|Converte uma cor de uma representação HSV em uma representação RGB.|
|[CDrawingManager::HuetoRGB](#huetorgb)|Método auxiliar que converte um valor de matiz em um componente vermelho, verde ou azul.|
|[CDrawingManager::MirrorRect](#mirrorrect)|Inverte uma área retangular.|
|[CDrawingManager::PixelAlpha](#pixelalpha)|Método auxiliar que determina a cor final para um pixel semitransparente.|
|[CDrawingManager::PrepareShadowMask](#prepareshadowmask)|Cria um bitmap que pode ser usado como sombra.|
|[CDrawingManager::RGBtoHSL](#rgbtohsl)|Converte uma cor de uma representação RGB em uma representação HSL.|
|[CDrawingManager::RGBtoHSV](#rgbtohsv)|Converte uma cor de uma representação RGB em uma representação HSV.|
|[CDrawingManager::SetAlphaPixel](#setalphapixel)|O método auxiliar que colore um pixel parcialmente transparente em um bitmap.|
|[CDrawingManager::SetPixel](#setpixel)|O método auxiliar que altera um único pixel em um bitmap para a cor especificada.|
|[CDrawingManager::SmartMixColors](#smartmixcolors)|Combina duas cores com base em uma taxa ponderada.|

## <a name="remarks"></a>Comentários

A `CDrawingManager` classe fornece funções para desenhar sombras, gradientes de cor e retângulos realçados. Ele também executa a mistura alfa. Você pode usar essa classe para alterar diretamente a interface do usuário do seu aplicativo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)<br/>
`CDrawingManager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdrawmanager. h

##  <a name="cdrawingmanager"></a>CDrawingManager::CDrawingManager

Constrói um objeto [CDrawingManager](../../mfc/reference/cdrawingmanager-class.md) .

```
CDrawingManager(CDC& dc);
```

### <a name="parameters"></a>Parâmetros

*dc*<br/>
no Uma referência a um contexto de dispositivo. O `CDrawingManager` usa esse contexto para desenhar.

##  <a name="createbitmap_32"></a>  CDrawingManager::CreateBitmap_32

Cria um bitmap independente de dispositivo de 32 bits (DIB) que os aplicativos podem gravar diretamente.

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
|*size*|no Um parâmetro [CSize](../../atl-mfc-shared/reference/csize-class.md) que indica o tamanho do bitmap.|
|*pBits*|fora Um ponteiro para um ponteiro de dados que recebe o local dos valores de bits de DIB.|
|*bitmap*|Um identificador para o bitmap original|
|*clrTransparent*|Um valor RGB que especifica a cor transparente do bitmap original.|

### <a name="return-value"></a>Valor de retorno

Um identificador para o bitmap DIB recém-criado se esse método for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como criar um bitmap DIB, consulte [CreateDIBSection](/windows/win32/api/wingdi/nf-wingdi-createdibitmap).

##  <a name="drawalpha"></a>  CDrawingManager::DrawAlpha

Exibe os bitmaps que têm pixels transparentes ou semitransparentes.

```
void DrawAlpha(
    CDC* pDstDC,
    const CRect& rectDst,
    CDC* pSrcDC,
    const CRect& rectSrc);
```

### <a name="parameters"></a>Parâmetros

*pDstDC*<br/>
no Um ponteiro para o contexto do dispositivo para o destino.

*rectDst*<br/>
no O retângulo de destino.

*pSrcDC*<br/>
no Um ponteiro para o contexto do dispositivo para a origem.

*rectSrc*<br/>
no O retângulo de origem.

### <a name="remarks"></a>Comentários

Esse método executa a mistura alfa para dois bitmaps. Para obter mais informações sobre a mistura alfa, consulte [AlphaBlend](/windows/win32/api/wingdi/nf-wingdi-alphablend) no SDK do Windows.

##  <a name="drawellipse"></a>  CDrawingManager::DrawEllipse

Desenha uma elipse com as cores de preenchimento e borda fornecidas.

```
void DrawEllipse(
    const CRect& rect,
    COLORREF clrFill,
    COLORREF clrLine);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
no O retângulo delimitador para a elipse.

*clrFill*<br/>
no A cor que esse método usa para preencher a elipse.

*clrLine*<br/>
no A cor que esse método usa como a borda da elipse.

### <a name="remarks"></a>Comentários

Esse método retornará sem desenhar uma elipse se a cor for definida como-1. Ele também retornará sem desenhar uma elipse se qualquer dimensão do retângulo delimitador for 0.

##  <a name="drawgradientring"></a>  CDrawingManager::DrawGradientRing

Desenha um anel e o preenche com um gradiente de cor.

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

*rect*<br/>
no Um parâmetro [CRect](../../atl-mfc-shared/reference/crect-class.md) que especifica o limite para o anel de gradiente.

*colorStart*<br/>
no A primeira cor do gradiente.

*colorFinish*<br/>
no A última cor do gradiente.

*colorBorder*<br/>
no A cor da borda.

*nAngle*<br/>
no Um parâmetro que especifica o ângulo de desenho de gradiente inicial. Esse valor deve estar entre 0 e 360.

*nWidth*<br/>
no A largura da borda do anel.

*clrFace*<br/>
no A cor do interior do anel.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O retângulo definido por *Rect* deve ter pelo menos 5 pixels de largura e 5 pixels de altura.

##  <a name="drawline_cdrawingmanager__drawlinea"></a>CDrawingManager::D rawLine, CDrawingManager::D rawLineA

Desenha uma linha.

```
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
|*x1*|no A coordenada x onde a linha é iniciada.|
|*y1*|no A coordenada y onde a linha é iniciada.|
|*x2*|no A coordenada x onde a linha termina.|
|*Y2*|no A coordenada y onde termina a linha.|
|*clrLine*|no A cor da linha.|

### <a name="remarks"></a>Comentários

Esse método falhará se *clrLine* for igual a-1.

##  <a name="drawrect"></a>  CDrawingManager::DrawRect

Desenha um retângulo com as cores de preenchimento e borda fornecidas.

```
void DrawRect(
    const CRect& rect,
    COLORREF clrFill,
    COLORREF clrLine);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
no Os limites para o retângulo.

*clrFill*<br/>
no A cor que esse método usa para preencher o retângulo.

*clrLine*<br/>
no A cor que esse método usa para a borda do retângulo.

### <a name="remarks"></a>Comentários

Esse método retornará sem desenhar um retângulo se a cor for definida como-1. Ele também retorna se uma das dimensões do retângulo for 0.

##  <a name="drawshadow"></a>  CDrawingManager::DrawShadow

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

*rect*<br/>
no Uma área retangular em seu aplicativo. O Gerenciador de desenho desenhará uma sombra embaixo dessa área.

*nDepth*<br/>
no A largura e a altura da sombra.

*iMinBrightness*<br/>
no O brilho mínimo da sombra.

*iMaxBrightness*<br/>
no O brilho máximo da sombra.

*pBmpSaveBottom*<br/>
no Um ponteiro para um bitmap que contém a imagem para a parte inferior da sombra.

*pBmpSaveRight*<br/>
no Um ponteiro para um bitmap que contém a imagem para a sombra que é desenhada no lado direito do retângulo.

*clrBase*<br/>
no A cor da sombra.

*bRightShadow*<br/>
no Um parâmetro booliano que indica como a sombra é desenhada. Se *bRightShadow* for `TRUE`, `DrawShadow` desenha uma sombra no lado direito do retângulo.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você pode fornecer dois bitmaps válidos para as sombras inferior e direita usando os parâmetros *pBmpSaveBottom* e *pBmpSaveRight*. Se esses objetos [CBitmap](../../mfc/reference/cbitmap-class.md) tiverem um objeto GDI anexado, `DrawShadow` o usará esses bitmaps como sombras. Se os `CBitmap` parâmetros não tiverem um objeto GDI anexado, `DrawShadow` o desenha a sombra e anexa os bitmaps aos parâmetros. Em chamadas futuras para `DrawShadow`o, você pode fornecer esses bitmaps para acelerar o processo de desenho. Para obter mais informações sobre `CBitmap` a classe e os objetos GDI, consulte [objetos gráficos](../../mfc/graphic-objects.md).

Se um desses parâmetros for `NULL`, `DrawShadow` o iniciará automaticamente a sombra.

Se você definir *bRightShadow* como false, a sombra será desenhada abaixo e à esquerda da área retangular.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `DrawShadow` método `CDrawingManager` da classe. Este trecho de código faz parte do [exemplo de demonstração de folha prop](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_PropSheetDemo#1](../../mfc/reference/codesnippet/cpp/cdrawingmanager-class_1.cpp)]

##  <a name="fill4colorsgradient"></a>CDrawingManager::Fill4ColorsGradient

Preenche uma área retangular com dois gradientes de cor.

```
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

*rect*<br/>
no O retângulo para preencher.

*colorStart1*<br/>
no A cor inicial do primeiro gradiente de cor.

*colorFinish1*<br/>
no A cor final do primeiro gradiente de cor.

*colorStart2*<br/>
no A cor inicial do segundo gradiente de cor.

*colorFinish2*<br/>
no A cor final do segundo gradiente de cor.

*bHorz*<br/>
no Um parâmetro booliano que indica `Fill4ColorsGradient` se as cores são um gradiente horizontal ou vertical. VERDADEIRO indica um gradiente horizontal.

*nPercentage*<br/>
no Um inteiro de 0-100. Esse valor indica a porcentagem do retângulo a ser preenchida com o primeiro gradiente de cor.

### <a name="remarks"></a>Comentários

Quando um retângulo é preenchido com dois gradientes de cor, eles são localizados acima um do outro ou ao lado um do outro, dependendo do valor de *bHorz*. Cada gradiente de cor é calculado de forma independente com o método [CDrawingManager:: FillGradient](#fillgradient).

Esse método gera uma falha de asserção se *nPercentage* é menor que 0 ou maior que 100.

##  <a name="fillgradient"></a>CDrawingManager::FillGradient

Preenche uma área retangular com o gradiente de cor especificado.

```
void FillGradient(
    CRect rect,
    COLORREF colorStart,
    COLORREF colorFinish,
    BOOL bHorz = TRUE,
    int nStartFlatPercentage = 0,
    int nEndFlatPercentage = 0);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
no A área retangular a ser preenchida.

*colorStart*<br/>
no A primeira cor do gradiente.

*colorFinish*<br/>
no A cor final do gradiente.

*bHorz*<br/>
no Um parâmetro booliano que especifica `FillGradient` se o deve desenhar um gradiente horizontal ou vertical.

*nStartFlatPercentage*<br/>
no A porcentagem do retângulo que `FillGradient` preenche com *colorStart* antes de iniciar o gradiente.

*nEndFlatPercentage*<br/>
no A porcentagem do retângulo que `FillGradient` preenche com *colorFinish* depois de concluir o gradiente.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `FillGradient` método `CDrawingManager` da classe. Este trecho de código faz parte do [exemplo de demonstração do MS Office 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#12](../../mfc/reference/codesnippet/cpp/cdrawingmanager-class_2.cpp)]

##  <a name="fillgradient2"></a>CDrawingManager::FillGradient2

Preenche uma área retangular com um gradiente de cor especificado.

```
void FillGradient2 (
    CRect rect,
    COLORREF colorStart,
    COLORREF colorFinish,
    int nAngle = 0);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
no A área retangular a ser preenchida.

*colorStart*<br/>
no A primeira cor do gradiente.

*colorFinish*<br/>
no A última cor do gradiente.

*nAngle*<br/>
no Um inteiro entre 0 e 360. Esse parâmetro especifica a direção do gradiente de cor.

### <a name="remarks"></a>Comentários

Use *nAngle* para especificar a direção do gradiente de cor. Quando você especifica a direção do gradiente de cor, também especifica onde o gradiente de cor é iniciado. Um valor de 0 para *nAngle* indica que o gradiente começa na parte superior do retângulo. À medida que o *nAngle* aumenta, o local inicial do gradiente se move em uma direção do sentido anti-horário com base no ângulo.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `FillGradient2` método `CDrawingManager` da classe. Este trecho de código faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#37](../../mfc/reference/codesnippet/cpp/cdrawingmanager-class_3.cpp)]

##  <a name="grayrect"></a>  CDrawingManager::GrayRect

Preenche um retângulo com uma cor cinza especificada.

```
BOOL GrayRect(
    CRect rect,
    int nPercentage = -1,
    COLORREF clrTransparent = (COLORREF)-1,
    COLORREF clrDisabled = (COLORREF)-1);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
no A área retangular a ser preenchida.

*nPercentage*<br/>
no A porcentagem de cinza que você deseja no retângulo.

*clrTransparent*<br/>
no A cor transparente.

*clrDisabled*<br/>
no A cor que esse método usa para dessaturação se *nPercentage* estiver definido como-1.

### <a name="return-value"></a>Valor de retorno

TRUE se o método foi bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Para o parâmetro *nPercentage*, um valor mais baixo indica uma cor mais escura.

O valor máximo para *nPercentage* é 200. Um valor maior que 200 não altera a aparência do retângulo. Se o valor for-1, esse método usará *clrDisabled* para limitar a saturação do retângulo.

##  <a name="highlightrect"></a>  CDrawingManager::HighlightRect

Realça uma área retangular.

```
BOOL HighlightRect(
    CRect rect,
    int nPercentage = -1,
    COLORREF clrTransparent = (COLORREF)-1,
    int nTolerance = 0,
    COLORREF clrBlend = (COLORREF)-1);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
no Uma área retangular para realçar.

*nPercentage*<br/>
no Uma porcentagem que indica a transparência do realce.

*clrTransparent*<br/>
no A cor transparente.

*nTolerance*<br/>
no Um inteiro entre 0 e 255 que indica a tolerância de cor.

*clrBlend*<br/>
no A cor base para mesclagem.

### <a name="return-value"></a>Valor de retorno

TRUE se o método for bem-sucedido; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Se *nPercentage* estiver entre 0 e 99, `HighlightRect` o usará o algoritmo de mistura alfa. Para obter mais informações sobre a mistura alfa, consulte [preenchimentos e linhas de mistura alfa](/dotnet/framework/winforms/advanced/alpha-blending-lines-and-fills). Se *nPercentage* for-1, esse método usará o nível de realce padrão. Se *nPercentage* for 100, esse método não fará nada e retornará true.

O método usa o parâmetro *nTolerance* para determinar se a área retangular deve ser realçada. Para realçar o retângulo, a diferença entre a cor do plano de fundo do seu aplicativo e o *clrTransparent* deve ser menor que *nTolerance* em cada componente de cor (vermelho, verde e azul).

##  <a name="hlstorgb_one"></a>  CDrawingManager::HLStoRGB_ONE

Converte uma cor de uma representação HLS em uma representação RGB.

```
static COLORREF __stdcall HLStoRGB_ONE(
    double H,
    double L,
    double S);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
no Um número entre 0 e 1 que representa o matiz da cor.

*L*<br/>
no Um número entre 0 e 1 que indica a luminosidade da cor.

*S*<br/>
no Um número entre 0 e 1 que indica a saturação da cor.

### <a name="return-value"></a>Valor de retorno

A representação RGB da cor HLS fornecida.

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (Matiz, saturação e valor), HSL (Matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Color](/windows/win32/uxguide/vis-color).

Esse método e o `CDrawingManager::HLStoRGB_TWO` método executam a mesma operação, mas exigem valores diferentes para o parâmetro *H* . Nesse método, *H* é uma porcentagem do círculo. No método, H é um valor de grau entre 0 e 360, que ambos representam vermelho. `CDrawingManager::HLStoRGB_TWO` Por exemplo, com `HLStoRGB_ONE`, um valor de 0,25 para *H* é equivalente a um valor de 90 com `HLStoRGB_TWO`.

##  <a name="hlstorgb_two"></a>  CDrawingManager::HLStoRGB_TWO

Converte uma cor de uma representação HLS em uma representação RGB.

```
static COLORREF __stdcall HLStoRGB_TWO(
    double H,
    double L,
    double S);
```

### <a name="parameters"></a>Parâmetros

*H*<br/>
no Um número entre 0 e 360 que representa o matiz da cor.

*L*<br/>
no Um número entre 0 e 1 que indica a luminosidade da cor.

*S*<br/>
no Um número entre 0 e 1 que indica a saturação da cor.

### <a name="return-value"></a>Valor de retorno

A representação RGB da cor HLS fornecida.

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (Matiz, saturação e valor), HSL (Matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Color](/windows/win32/uxguide/vis-color).

Esse método e o método [CDrawingManager:: HLStoRGB_ONE](#hlstorgb_one) executam a mesma operação, mas exigem valores diferentes para o parâmetro *H* . Nesse método, *H* é um valor de grau entre 0 e 360, que ambos representam vermelho. No método [CDrawingManager:: HLStoRGB_ONE](#hlstorgb_one) , *H* é uma porcentagem do círculo. Por exemplo, com `HLStoRGB_ONE`, um valor de 0,25 para *H* é equivalente a um valor de 90 com `HLStoRGB_TWO`.

##  <a name="hsvtorgb"></a>  CDrawingManager::HSVtoRGB

Converte uma cor de uma representação HSV em uma representação RGB.

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
|*H*|no Um número entre 0 e 360 que indica o matiz da cor.|
|*S*|no Um número entre 0 e 1 que indica a saturação da cor.|
|*V*|no Um número entre 0 e 1 que indica o valor da cor.|

### <a name="return-value"></a>Valor de retorno

A representação RGB da cor HSV fornecida.

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (Matiz, saturação e valor), HSL (Matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Color](/windows/win32/uxguide/vis-color).

##  <a name="huetorgb"></a>  CDrawingManager::HuetoRGB

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
no Consulte comentários.

*m2*<br/>
no Consulte comentários.

*h*<br/>
no Consulte comentários.

*rm1*<br/>
no Consulte comentários.

*rm2*<br/>
no Consulte comentários.

*rh*<br/>
no Consulte comentários.

### <a name="return-value"></a>Valor de retorno

O componente vermelho, verde ou azul individual para o matiz fornecido.

### <a name="remarks"></a>Comentários

Esse método é um método auxiliar que a `CDrawingManager` classe usa para computar os componentes individuais vermelho, verde e azul de uma cor em uma representação HSV ou HSL. Esse método não foi projetado para ser chamado diretamente pelo programador. Os parâmetros de entrada são valores que dependem do algoritmo de conversão.

Para converter uma cor HSV ou HSL em uma representação RGB, chame um dos seguintes métodos:

- [CDrawingManager::HSVtoRGB](#hsvtorgb)

- [CDrawingManager::HLStoRGB_ONE](#hlstorgb_one)

- [CDrawingManager::HLStoRGB_TWO](#hlstorgb_two)

##  <a name="mirrorrect"></a>  CDrawingManager::MirrorRect

Inverte uma área retangular.

```
void MirrorRect(
    CRect rect,
    BOOL bHorz = TRUE);
```

### <a name="parameters"></a>Parâmetros

*rect*<br/>
no O retângulo delimitador da área a ser invertida.

*bHorz*<br/>
no Um parâmetro booliano que indica se o retângulo é invertido horizontal ou verticalmente.

### <a name="remarks"></a>Comentários

Esse método pode inverter qualquer área do contexto de dispositivo pertencente à `CDrawingManager` classe. Se *bHorz* for definido como true, esse método inverterá a área horizontalmente. Caso contrário, ele inverte a área verticalmente.

##  <a name="pixelalpha"></a>  CDrawingManager::PixelAlpha

Calcula a cor final de um pixel semitransparente.

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
no A cor inicial do pixel.

*percent*<br/>
no Um número entre 0 e 100 que representa a porcentagem de transparência. Um valor de 100 indica que a cor inicial é completamente transparente.

*percentR*<br/>
no Um número entre 0 e 100 que representa a porcentagem de transparência do componente vermelho.

*percentG*<br/>
no Um número entre 0 e 100 que representa a porcentagem de transparência do componente verde.

*percentB*<br/>
no Um número entre 0 e 100 que representa a porcentagem de transparência do componente azul.

*dstPixel*<br/>
no A cor de base do pixel.

### <a name="return-value"></a>Valor de retorno

A cor final do pixel semitransparente.

### <a name="remarks"></a>Comentários

Essa é uma classe auxiliar para bitmaps semitransparentes de cores e não foi projetada para ser chamada diretamente pelo programador.

Quando você usa a versão do método que tem *dstPixel*, a cor final é uma combinação de *dstPixel* e *srcPixel*. A cor *srcPixel* é a cor parcialmente transparente sobre a cor base de *dstPixel*.

##  <a name="prepareshadowmask"></a>  CDrawingManager::PrepareShadowMask

Cria um bitmap que pode ser usado como sombra.

```
static HBITMAP __stdcall PrepareShadowMask (
    int nDepth,
    COLORREF clrBase,
    int iMinBrightness = 0,
    int iMaxBrightness = 100);
```

### <a name="parameters"></a>Parâmetros

*nDepth*<br/>
no A largura e a altura da sombra.

*clrBase*<br/>
no A cor da sombra.

*iMinBrightness*<br/>
no O brilho mínimo da sombra.

*iMaxBrightness*<br/>
no O brilho máximo da sombra.

### <a name="return-value"></a>Valor de retorno

Um identificador para o bitmap criado se esse método for bem-sucedido; caso contrário, NULL.

### <a name="remarks"></a>Comentários

Se *nDepth* for definido como 0, esse método será encerrado e retornará NULL. Se *nDepth* for menor que 3, a largura e a altura da sombra serão definidas como 3 pixels.

##  <a name="rgbtohsl"></a>  CDrawingManager::RGBtoHSL

Converte uma cor de uma representação vermelha, verde e azul (RGB) em uma representação de matiz, saturação e luminosidade (HSL).

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
|*rgb*|no A cor em valores RGB.|
|*H*|fora Um ponteiro para um duplo em que o método armazena o matiz para a cor.|
|*S*|fora Um ponteiro para um duplo em que o método armazena a saturação da cor.|
|*L*|fora Um ponteiro para um duplo em que o método armazena a claridade da cor.|

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (Matiz, saturação e valor), HSL (Matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Color](/windows/win32/uxguide/vis-color).

O valor retornado para *H* é representado como uma fração entre 0 e 1, onde 0 e 1 representam vermelho. Os valores retornados para *S* e *L* são números entre 0 e 1.

##  <a name="rgbtohsv"></a>  CDrawingManager::RGBtoHSV

Converte uma cor de uma representação RGB em uma representação HSV.

```
static void __stdcall RGBtoHSV(
    COLORREF rgb,
    double* H,
    double* S,
    double* V);
```

### <a name="parameters"></a>Parâmetros

*rgb*<br/>
no A cor a ser convertida em uma representação RGB.

*H*<br/>
fora Um ponteiro para um duplo em que esse método armazena o matiz resultante para a cor.

*S*<br/>
fora Um ponteiro para um duplo em que esse método armazena a saturação resultante para a cor.

*V*<br/>
fora Um ponteiro para um duplo em que esse método armazena o valor resultante para a cor.

### <a name="remarks"></a>Comentários

Uma cor pode ser representada como HSV (Matiz, saturação e valor), HSL (Matiz, saturação e luminosidade) ou RGB (vermelho, verde e azul). Para obter mais informações sobre as diferentes representações de cor, consulte [Color](/windows/win32/uxguide/vis-color).

O valor retornado para *H* é um número entre 0 e 360, onde 0 e 360 indicam vermelho. Os valores de retorno para *S* e *V* são números entre 0 e 1.

##  <a name="setalphapixel"></a>  CDrawingManager::SetAlphaPixel

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
no Um ponteiro para os valores de bit para o bitmap.

*rect*<br/>
no Uma área retangular em seu aplicativo. O Gerenciador de desenho desenha uma sombra embaixo e à direita dessa área.

*x*<br/>
no A coordenada horizontal do pixel para a cor.

*y*<br/>
no A coordenada vertical do pixel para a cor.

*percent*<br/>
no A porcentagem de transparência.

*iShadowSize*<br/>
no A largura e a altura da sombra.

*clrBase*<br/>
no A cor da sombra.

*bIsRight*<br/>
no Um parâmetro booliano que indica qual pixel deve ser colorido. Consulte a seção Comentários para obter mais informações.

### <a name="remarks"></a>Comentários

Esse método é um método auxiliar que é usado pelo método [CDrawingManager::D rawshadow](#drawshadow) . É recomendável que, se você quiser desenhar uma sombra, `CDrawingManager::DrawShadow` chame em vez disso.

Se *bIsRight* for definido como true, o pixel para Color será medido *x* pixels da borda direita de *Rect*. Se for FALSE, o pixel para Color será medido *x* pixels da borda esquerda de *Rect*.

##  <a name="setpixel"></a>  CDrawingManager::SetPixel

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
|*pBits*|no Um ponteiro para os valores de bits do bitmap.|
|*cx*|no A largura total do bitmap.|
|*cy*|no A altura total do bitmap.|
|*x*|no A coordenada x do pixel no bitmap a ser alterada.|
|*y*|no A coordenada y do pixel no bitmap a ser alterada.|
|*color*|no A nova cor do pixel identificado pelas coordenadas fornecidas.|

##  <a name="smartmixcolors"></a>  CDrawingManager::SmartMixColors

Combina duas cores com base em uma taxa ponderada.

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
|*color1*|no A primeira cor a ser combinada.|
|*color2*|no A segunda cor a ser combinada.|
|*dblLumRatio*|no A razão para a luminosidade da nova cor. `SmartMixColors`multiplica a luminosidade da cor mista por essa proporção antes de determinar uma cor final.|
|*k1*|no A taxa ponderada da primeira cor.|
|*k2*|no A taxa ponderada da segunda cor.|

### <a name="return-value"></a>Valor de retorno

Uma cor que representa uma mistura ponderada das cores fornecidas.

### <a name="remarks"></a>Comentários

Esse método falhará com um erro se *K1* ou *K2* for menor que zero. Se ambos os parâmetros forem definidos como 0, o método retornará `RGB(0, 0, 0)`.

A taxa ponderada é calculada com a seguinte fórmula: ( \* color1 K1 + \* color2 K2)/(K1 + K2). Depois que a taxa ponderada é determinada, o método calcula a luminosidade da cor mista. Em seguida, ele multiplica a luminosidade por *dblLumRatio*. Se o valor for maior que 1,0, o método definirá a luminosidade da cor mista para o novo valor. Caso contrário, a luminosidade é definida como 1,0.

##  <a name="drawrotated"></a>  CDrawingManager::DrawRotated

Gira um conteúdo de DC de origem dentro do retângulo fornecido em 90 graus.

```
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

*bClockWise*<br/>
VERDADEIRO indica rotação + 90 graus; FALSO indica girar-90 graus.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)
