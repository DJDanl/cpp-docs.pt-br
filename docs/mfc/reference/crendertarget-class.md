---
title: Classe CRenderTarget | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRenderTarget
- afxrendertarget/CRenderTarget
dev_langs:
- C++
helpviewer_keywords:
- CRenderTarget class
ms.assetid: 30d1607d-68d3-4d14-ac36-fdbd0ef903a1
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 6f77d482e7ee3bf0798ad488067893b3712aac62
ms.lasthandoff: 02/25/2017

---
# <a name="crendertarget-class"></a>Classe CRenderTarget
Um wrapper para ID2D1RenderTarget.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CRenderTarget : public CObject;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRenderTarget::CRenderTarget](#crendertarget)|Constrói um objeto CRenderTarget.|  
|[CRenderTarget:: ~ CRenderTarget](#crendertarget__~crendertarget)|O destruidor. Chamado quando um objeto de destino de processamento está sendo destruído.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRenderTarget::Attach](#attach)|Conexões existentes renderizam a interface de destino para o objeto|  
|[CRenderTarget::BeginDraw](#begindraw)|Inicia a esse destino de renderização de desenho.|  
|[CRenderTarget::Clear](#clear)|Limpa a área de desenho com a cor especificada.|  
|[CRenderTarget::COLORREF_TO_D2DCOLOR](#colorref_to_d2dcolor)|Converte valores de cor e alfa GDI para o objeto D2D1_COLOR_F.|  
|[CRenderTarget::CreateCompatibleRenderTarget](#createcompatiblerendertarget)|Cria um novo destino de renderização de bitmap para uso durante o desenho fora da tela intermediário que é compatível com o alvo processado atual.|  
|[CRenderTarget::Destroy](#destroy)|Exclui um ou mais recursos|  
|[CRenderTarget::Detach](#detach)|Desconecta a interface de destino de renderização do objeto|  
|[CRenderTarget::DrawBitmap](#drawbitmap)|Desenha o texto formatado descrito pelo objeto IDWriteTextLayout especificado.|  
|[CRenderTarget::DrawEllipse](#drawellipse)|Desenha a borda da elipse especificado usando o estilo de traço especificado.|  
|[CRenderTarget::DrawGeometry](#drawgeometry)|Desenha o contorno de geometry especificado usando o estilo de traço especificado.|  
|[CRenderTarget::DrawGlyphRun](#drawglyphrun)|Desenha os glifos especificados.|  
|[CRenderTarget::DrawLine](#drawline)|Desenha uma linha entre os pontos especificados usando o estilo de traço especificado.|  
|[CRenderTarget::DrawRectangle](#drawrectangle)|Desenha o contorno de um retângulo que tenha o estilo de traço e dimensões especificadas.|  
|[CRenderTarget::DrawRoundedRectangle](#drawroundedrectangle)|Desenha o contorno do retângulo arredondado especificado usando o estilo de traço especificado.|  
|[CRenderTarget::DrawText](#drawtext)|Desenha o texto especificado usando as informações de formato fornecidas por um objeto IDWriteTextFormat.|  
|[CRenderTarget::DrawTextLayout](#drawtextlayout)|Desenha o texto formatado descrito pelo objeto IDWriteTextLayout especificado.|  
|[CRenderTarget::EndDraw](#enddraw)|Termine as operações de desenho no destino de renderização e indica o estado de erro atual e as marcas associadas.|  
|[CRenderTarget::FillEllipse](#fillellipse)|Pinta o interior da elipse especificado.|  
|[CRenderTarget::FillGeometry](#fillgeometry)|Pinta o interior da geometria especificado.|  
|[CRenderTarget::FillMesh](#fillmesh)|Pinta o interior da malha especificado.|  
|[CRenderTarget::FillOpacityMask](#fillopacitymask)|Aplica-se a máscara de opacidade descrita pelo bitmap especificado como um pincel e usa esse pincel para pintar uma região de destino de renderização.|  
|[CRenderTarget::FillRectangle](#fillrectangle)|Pinta o interior do retângulo especificado.|  
|[CRenderTarget::FillRoundedRectangle](#fillroundedrectangle)|Pinta o interior do retângulo arredondado especificado.|  
|[CRenderTarget::Flush](#flush)|Executa todos os comandos de desenho pendentes.|  
|[CRenderTarget::GetAntialiasMode](#getantialiasmode)|Recupera o modo de suavização atual para operações de desenho não textual.|  
|[CRenderTarget::GetDpi](#getdpi)|Retorna a renderização pontos de destino por polegada (DPI)|  
|[CRenderTarget::GetMaximumBitmapSize](#getmaximumbitmapsize)|Obtém o tamanho máximo, em unidades dependentes de dispositivo (pixels), de qualquer dimensão de um bitmap compatíveis com o destino de renderização|  
|[CRenderTarget::GetPixelFormat](#getpixelformat)|Recupera o modo de formato e alfa do pixel do destino de renderização|  
|[CRenderTarget::GetPixelSize](#getpixelsize)|Retorna o tamanho do destino de renderização em pixels do dispositivo|  
|[CRenderTarget::GetRenderTarget](#getrendertarget)|Interface de ID2D1RenderTarget retorna|  
|[CRenderTarget::GetSize](#getsize)|Retorna o tamanho do destino de renderização em pixels independentes de dispositivo|  
|[CRenderTarget::GetTags](#gettags)|Obtém o rótulo para operações de desenho subsequentes.|  
|[CRenderTarget::GetTextAntialiasMode](#gettextantialiasmode)|Obtém o atual modo de suavização para texto e operações de desenho de glifo.|  
|[CRenderTarget::GetTextRenderingParams](#gettextrenderingparams)|Recupera as opções de renderização de texto atual do destino de renderização.|  
|[CRenderTarget::GetTransform](#gettransform)|Aplica a transformação especificada para o destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrem no espaço de transformados.|  
|[CRenderTarget::IsSupported](#issupported)|Indica se o destino de renderização oferece suporte as propriedades especificadas|  
|[CRenderTarget::IsValid](#isvalid)|Verificações de validade de recursos|  
|[CRenderTarget::PopAxisAlignedClip](#popaxisalignedclip)|Remove o último clipe alinhado por eixo no alvo processado. Depois que esse método é chamado, o clipe não for mais aplicado às operações de desenho subsequentes.|  
|[CRenderTarget::PopLayer](#poplayer)|Paradas de redirecionamento de operações de desenho à camada especificada pelo PushLayer a última chamada.|  
|[CRenderTarget::PushAxisAlignedClip](#pushaxisalignedclip)|Remove o último clipe alinhado por eixo no alvo processado. Depois que esse método é chamado, o clipe não for mais aplicado às operações de desenho subsequentes.|  
|[CRenderTarget::PushLayer](#pushlayer)|Adiciona a camada especificada para o destino de renderização para que ele recebe todas as operações de desenho subsequentes até PopLayer é chamado.|  
|[CRenderTarget::RestoreDrawingState](#restoredrawingstate)|Define o estado de desenho do destino de renderização para que o ID2D1DrawingStateBlock especificado.|  
|[CRenderTarget::SaveDrawingState](#savedrawingstate)|Salva o estado atual de desenho para o ID2D1DrawingStateBlock especificado.|  
|[CRenderTarget::SetAntialiasMode](#setantialiasmode)|Define o modo de suavização do destino de renderização. O modo de suavização se aplica a todas as operações de desenho subsequentes, excluindo o texto e operações de desenho de glifo.|  
|[CRenderTarget::SetDpi](#setdpi)|Define pontos por polegada (DPI) do destino de renderização.|  
|[CRenderTarget::SetTags](#settags)|Especifica um rótulo para operações de desenho subsequentes.|  
|[CRenderTarget::SetTextAntialiasMode](#settextantialiasmode)|Especifica o modo de suavização para usar para o texto subsequente e operações de desenho do glifo.|  
|[CRenderTarget::SetTextRenderingParams](#settextrenderingparams)|Especifica as opções de renderização de texto a ser aplicado a todo o texto subsequente e operações de desenho de glifo.|  
|[CRenderTarget::SetTransform](#settransform)|Sobrecarregado. Aplica a transformação especificada para o destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrem no espaço de transformados.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRenderTarget::VerifyResource](#verifyresource)|Verifica a validade do objeto CD2DResource; cria o objeto se ele já não existe.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRenderTarget::operator ID2D1RenderTarget *](#operator_id2d1rendertarget_star)|Interface de ID2D1RenderTarget retorna|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CRenderTarget::m_lstResources](#m_lstresources)|Uma lista de ponteiros para objetos CD2DResource.|  
|[CRenderTarget::m_pRenderTarget](#m_prendertarget)|Um ponteiro para um objeto ID2D1RenderTarget.|  
|[CRenderTarget::m_pTextFormatDefault](#m_ptextformatdefault)|Um ponteiro para o objeto CD2DTextFormat que contém um formato de texto padrão.|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CRenderTarget](../../mfc/reference/crendertarget-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxrendertarget.h  
  
##  <a name="a-namedtorcrendertargeta--crendertargetcrendertarget"></a><a name="_dtorcrendertarget"></a>CRenderTarget:: ~ CRenderTarget  
 O destruidor. Chamado quando um objeto de destino de processamento está sendo destruído.  
  
```  
virtual ~CRenderTarget();
```  
  
##  <a name="a-nameattacha--crendertargetattach"></a><a name="attach"></a>CRenderTarget::Attach  
 Conexões existentes renderizam a interface de destino para o objeto  
  
```  
void Attach(ID2D1RenderTarget* pRenderTarget);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pRenderTarget`  
 Interface de destino de renderização existente. Não pode ser nulo  
  
##  <a name="a-namebegindrawa--crendertargetbegindraw"></a><a name="begindraw"></a>CRenderTarget::BeginDraw  
 Inicia a esse destino de renderização de desenho.  
  
```  
void BeginDraw();
```  
  
##  <a name="a-namecleara--crendertargetclear"></a><a name="clear"></a>CRenderTarget::Clear  
 Limpa a área de desenho com a cor especificada.  
  
```  
void Clear(D2D1_COLOR_F color);
```  
  
### <a name="parameters"></a>Parâmetros  
 `color`  
 A cor à qual a área de desenho está desmarcada.  
  
##  <a name="a-namecolorreftod2dcolora--crendertargetcolorreftod2dcolor"></a><a name="colorref_to_d2dcolor"></a>CRenderTarget::COLORREF_TO_D2DCOLOR  
 Converte valores de cor e alfa GDI para o objeto D2D1_COLOR_F.  
  
```  
static D2D1_COLOR_F COLORREF_TO_D2DCOLOR(
    COLORREF color,  
    int nAlpha = 255);
```  
  
### <a name="parameters"></a>Parâmetros  
 `color`  
 Valor RGB.  
  
 `nAlpha`  
  
### <a name="return-value"></a>Valor de retorno  
 Valor de D2D1_COLOR_F.  
  
##  <a name="a-namecreatecompatiblerendertargeta--crendertargetcreatecompatiblerendertarget"></a><a name="createcompatiblerendertarget"></a>CRenderTarget::CreateCompatibleRenderTarget  
 Cria um novo destino de renderização de bitmap para uso durante o desenho fora da tela intermediário que é compatível com o alvo processado atual.  
  
```  
BOOL CreateCompatibleRenderTarget(
    CBitmapRenderTarget& bitmapTarget,  
    CD2DSizeF sizeDesired = CD2DSizeF(0., 0.), 
    CD2DSizeU sizePixelDesired = CD2DSizeU(0, 0), 
    D2D1_PIXEL_FORMAT* desiredFormat = NULL,  
    D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS options = D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bitmapTarget`  
 Quando este método retorna, contém o endereço de um ponteiro para um novo destino de renderização de bitmap. Este parâmetro é passado não inicializado.  
  
 `sizeDesired`  
 O tamanho desejado para o novo destino de renderização em pixels independentes de dispositivo se ele deve ser diferente do original alvo processado ou NULL. Para obter mais informações, consulte a seção Comentários.  
  
 `sizePixelDesired`  
 O tamanho desejado para o novo destino de renderização em pixels se ele deve ser diferente do original alvo processado ou NULL. Para obter mais informações, consulte a seção Comentários.  
  
 `desiredFormat`  
 O formato de pixel desejado e o modo alfa do novo destino de renderização ou NULL. Se o formato do pixel é definido como DXGI_FORMAT_UNKNOWN ou se esse parâmetro for nulo, o novo destino de renderização usa o mesmo formato de pixel como destino de renderização do original. Se o modo alfa é D2D1_ALPHA_MODE_UNKNOWN ou esse parâmetro for NULL, o modo alfa do destino de renderização novo padrão D2D1_ALPHA_MODE_PREMULTIPLIED. Para obter informações sobre formatos de pixel com suporte, consulte suporte para formatos de Pixel e modos de alfa.  
  
 `options`  
 Um valor que especifica se o novo destino de renderização deve ser compatível com o GDI.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retorna FALSE.  
  
##  <a name="a-namecrendertargeta--crendertargetcrendertarget"></a><a name="crendertarget"></a>CRenderTarget::CRenderTarget  
 Constrói um objeto CRenderTarget.  
  
```  
CRenderTarget();
```  
  
##  <a name="a-namedestroya--crendertargetdestroy"></a><a name="destroy"></a>CRenderTarget::Destroy  
 Exclui um ou mais recursos  
  
```  
BOOL Destroy(BOOL bDeleteResources = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bDeleteResources`  
 Se bDeleteResources for TRUE, todos os recursos localizados em m_lstResources serão destruídos automaticamente.  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará TRUE. Caso contrário, retornará FALSE  
  
##  <a name="a-namedetacha--crendertargetdetach"></a><a name="detach"></a>CRenderTarget::Detach  
 Desconecta a interface de destino de renderização do objeto  
  
```  
ID2D1RenderTarget* Detach ();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para desanexado renderizar a interface de destino.  
  
##  <a name="a-namedrawbitmapa--crendertargetdrawbitmap"></a><a name="drawbitmap"></a>CRenderTarget::DrawBitmap  
 Desenha o texto formatado descrito pelo objeto IDWriteTextLayout especificado.  
  
```  
void DrawBitmap(
    CD2DBitmap* pBitmap,  
    const CD2DRectF& rectDest,  
    float fOpacity = 1.0,  
    D2D1_BITMAP_INTERPOLATION_MODE interpolationMode = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR,  
    const CD2DRectF* pRectSrc = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pBitmap`  
 O bitmap para processar.  
  
 `rectDest`  
 O tamanho e posição, em pixels independentes de dispositivo no espaço de coordenadas do destino de renderização, da área à qual o bitmap é desenhado. Se o retângulo não é bem ordenado, nada é desenhado, mas o destino de renderização não entra em estado de erro.  
  
 `fOpacity`  
 Um valor entre 0, 0F e 1, 0F, inclusive, que especifica um valor de opacidade para aplicar o bitmap; Esse valor é multiplicado em relação aos valores alfabéticos do conteúdo do bitmap.  
  
 `interpolationMode`  
 O modo de interpolação a ser usado se o bitmap é dimensionado ou girado pela operação de desenho.  
  
 `pRectSrc`  
 O tamanho e posição, em pixels independentes de dispositivo no espaço de coordenadas do bitmap, da área de dentro do bitmap para desenhar.  
  
##  <a name="a-namedrawellipsea--crendertargetdrawellipse"></a><a name="drawellipse"></a>CRenderTarget::DrawEllipse  
 Desenha a borda da elipse especificado usando o estilo de traço especificado.  
  
```  
void DrawEllipse(
    const CD2DEllipse& ellipse,  
    CD2DBrush* pBrush,  
    FLOAT fStrokeWidth = 1.0,  
    ID2D1StrokeStyle* strokeStyle = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ellipse`  
 A posição e o raio da elipse para desenhar, em pixels independentes de dispositivo.  
  
 `pBrush`  
 O pincel usado para pintar o contorno da elipse.  
  
 `fStrokeWidth`  
 A espessura do traço da elipse. O traço é centralizado na estrutura de tópicos da elipse.  
  
 `strokeStyle`  
 O estilo de traço para aplicar a estrutura de tópicos ou NULL para pintar um traço sólido da elipse.  
  
##  <a name="a-namedrawgeometrya--crendertargetdrawgeometry"></a><a name="drawgeometry"></a>CRenderTarget::DrawGeometry  
 Desenha o contorno de geometry especificado usando o estilo de traço especificado.  
  
```  
void DrawGeometry(
    CD2DGeometry* pGeometry,  
    CD2DBrush* pBrush,  
    FLOAT fStrokeWidth = 1.0,  
    ID2D1StrokeStyle* strokeStyle = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGeometry`  
 A geometria para desenhar.  
  
 `pBrush`  
 O pincel usado para pintar o traço da geometria.  
  
 `fStrokeWidth`  
 A espessura do traço da geometria. O traço é centralizado no contorno da geometria.  
  
 `strokeStyle`  
 O estilo de traço para aplicar a geometria da estrutura de tópicos, ou nulo para pintar um traço sólido.  
  
##  <a name="a-namedrawglyphruna--crendertargetdrawglyphrun"></a><a name="drawglyphrun"></a>CRenderTarget::DrawGlyphRun  
 Desenha os glifos especificados.  
  
```  
void DrawGlyphRun(
    const CD2DPointF& ptBaseLineOrigin,  
    const DWRITE_GLYPH_RUN& glyphRun,  
    CD2DBrush* pForegroundBrush,  
    DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptBaseLineOrigin`  
 A origem, em pixels independentes de dispositivo, de linha de base os glifos.  
  
 `glyphRun`  
 Os glifos para processar.  
  
 `pForegroundBrush`  
 O pincel usado para pintar os glifos especificados.  
  
 `measuringMode`  
 Um valor que indica como as métricas de glifo são usadas para medir o texto quando ele é formatado. O valor padrão é DWRITE_MEASURING_MODE_NATURAL.  
  
##  <a name="a-namedrawlinea--crendertargetdrawline"></a><a name="drawline"></a>CRenderTarget::DrawLine  
 Desenha uma linha entre os pontos especificados usando o estilo de traço especificado.  
  
```  
void DrawLine(
    const CD2DPointF& ptFrom,  
    const CD2DPointF& ptTo,  
    CD2DBrush* pBrush,  
    FLOAT fStrokeWidth = 1.0,  
    ID2D1StrokeStyle* strokeStyle = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptFrom`  
 O ponto inicial da linha, em pixels independentes de dispositivo.  
  
 `ptTo`  
 O ponto final da linha, em pixels independentes de dispositivo.  
  
 `pBrush`  
 O pincel usado para pintar o traço da linha.  
  
 `fStrokeWidth`  
 Um valor maior que ou igual a 0.0 f que especifica a largura do traço. Se esse parâmetro não for especificado, o padrão é 1, 0F. O traço é centralizado na linha.  
  
 `strokeStyle`  
 O estilo de traço paint, ou nulo para pintar uma linha sólida.  
  
##  <a name="a-namedrawrectanglea--crendertargetdrawrectangle"></a><a name="drawrectangle"></a>CRenderTarget::DrawRectangle  
 Desenha o contorno de um retângulo que tenha o estilo de traço e dimensões especificadas.  
  
```  
void DrawRectangle(
    const CD2DRectF& rect,  
    CD2DBrush* pBrush,  
    FLOAT fStrokeWidth = 1.0,  
    ID2D1StrokeStyle* strokeStyle = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 As dimensões do retângulo para desenhar, em pixels independentes de dispositivo  
  
 `pBrush`  
 O pincel usado para pintar o traço do retângulo  
  
 `fStrokeWidth`  
 Um valor maior que ou igual a 0.0 f que especifica a largura do traço do retângulo. O traço é centralizado no contorno do retângulo.  
  
 `strokeStyle`  
 O estilo de traço paint, ou nulo para pintar um traço sólido.  
  
##  <a name="a-namedrawroundedrectanglea--crendertargetdrawroundedrectangle"></a><a name="drawroundedrectangle"></a>CRenderTarget::DrawRoundedRectangle  
 Desenha o contorno do retângulo arredondado especificado usando o estilo de traço especificado.  
  
```  
void DrawRoundedRectangle(
    const CD2DRoundedRect& rectRounded,  
    CD2DBrush* pBrush,  
    FLOAT fStrokeWidth = 1.0,  
    ID2D1StrokeStyle* strokeStyle = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rectRounded`  
 As dimensões do retângulo arredondado para desenhar, em pixels independentes de dispositivo.  
  
 `pBrush`  
 O pincel usado para pintar o contorno do retângulo arredondado.  
  
 `fStrokeWidth`  
 A largura do traço do retângulo arredondado. O traço é centralizado no contorno do retângulo arredondado. O valor padrão é 1, 0F.  
  
 `strokeStyle`  
 O estilo de traço ou nulo para pintar um traço sólido o retângulo arredondado. O valor padrão é NULL.  
  
##  <a name="a-namedrawtexta--crendertargetdrawtext"></a><a name="drawtext"></a>CRenderTarget::DrawText  
 Desenha o texto especificado usando as informações de formato fornecidas por um objeto IDWriteTextFormat.  
  
```  
void DrawText(
    const CString& strText,  
    const CD2DRectF& rect,  
    CD2DBrush* pForegroundBrush,  
    CD2DTextFormat* textFormat = NULL,  
    D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE,  
    DWRITE_MEASURING_MODE measuringMode = DWRITE_MEASURING_MODE_NATURAL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `strText`  
 Um ponteiro para uma matriz de caracteres Unicode para desenhar.  
  
 `rect`  
 O tamanho e a posição da área na qual o texto é desenhado.  
  
 `pForegroundBrush`  
 O pincel usado para pintar o texto.  
  
 `textFormat`  
 Um objeto que descreve a formatação de detalhes do texto para desenhar, como a fonte, o tamanho da fonte e direção do fluxo.  
  
 `options`  
 Um valor que indica se o texto deve ser ajustado para limites de pixels e se o texto deve ser recortado para o retângulo de layout. O valor padrão é D2D1_DRAW_TEXT_OPTIONS_NONE, que indica que o texto deve ser ajustado para limites de pixels e não deve ser recortada para o retângulo de layout.  
  
 `measuringMode`  
 Um valor que indica como as métricas de glifo são usadas para medir o texto quando ele é formatado. O valor padrão é DWRITE_MEASURING_MODE_NATURAL.  
  
##  <a name="a-namedrawtextlayouta--crendertargetdrawtextlayout"></a><a name="drawtextlayout"></a>CRenderTarget::DrawTextLayout  
 Desenha o texto formatado descrito pelo objeto IDWriteTextLayout especificado.  
  
```  
void DrawTextLayout(
    const CD2DPointF& ptOrigin,  
    CD2DTextLayout* textLayout,  
    CD2DBrush* pBrushForeground,  
    D2D1_DRAW_TEXT_OPTIONS options = D2D1_DRAW_TEXT_OPTIONS_NONE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ptOrigin`  
 O ponto, descrito em pixels independentes de dispositivo, em que o canto superior esquerdo do texto descrito por textLayout é desenhado.  
  
 `textLayout`  
 O texto formatado para desenhar. Os efeitos de desenho que não herdam de ID2D1Resource são ignorados. Se houver efeitos de desenho que herdam de ID2D1Resource que não são pincéis, esse método falhar e o destino de renderização é colocado em um estado de erro.  
  
 `pBrushForeground`  
 O pincel usado para pintar o texto em textLayout que ainda não tiver um pincel associado a ele como um efeito de desenho (especificado pelo método IDWriteTextLayout::SetDrawingEffect).  
  
 `options`  
 Um valor que indica se o texto deve ser ajustado para limites de pixels e se o texto deve ser recortado para o retângulo de layout. O valor padrão é D2D1_DRAW_TEXT_OPTIONS_NONE, que indica que o texto deve ser ajustado para limites de pixels e não deve ser recortada para o retângulo de layout.  
  
##  <a name="a-nameenddrawa--crendertargetenddraw"></a><a name="enddraw"></a>CRenderTarget::EndDraw  
 Termine as operações de desenho no destino de renderização e indica o estado de erro atual e as marcas associadas.  
  
```  
HRESULT EndDraw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se o método for bem-sucedido, retornará S_OK. Caso contrário, ele retorna um código de erro HRESULT.  
  
##  <a name="a-namefillellipsea--crendertargetfillellipse"></a><a name="fillellipse"></a>CRenderTarget::FillEllipse  
 Pinta o interior da elipse especificado.  
  
```  
void FillEllipse(
    const CD2DEllipse& ellipse,  
    CD2DBrush* pBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ellipse`  
 A posição e o radius em pixels independentes de dispositivo, da elipse para pintar.  
  
 `pBrush`  
 O pincel usado para pintar o interior da elipse.  
  
##  <a name="a-namefillgeometrya--crendertargetfillgeometry"></a><a name="fillgeometry"></a>CRenderTarget::FillGeometry  
 Pinta o interior da geometria especificado.  
  
```  
void FillGeometry(
    CD2DGeometry* pGeometry,  
    CD2DBrush* pBrush,  
    CD2DBrush* pOpacityBrush = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pGeometry`  
 A geometria para pintar.  
  
 `pBrush`  
 O pincel usado para pintar a geometria está interior.  
  
 `pOpacityBrush`  
 A máscara de opacidade para aplicar à geometria; NULL para sem máscara de opacidade. Se uma máscara de opacidade (o parâmetro opacityBrush) for especificada, o pincel deve ser um ID2D1BitmapBrush com seus modos de x e y estender definidos como D2D1_EXTEND_MODE_CLAMP. Para obter mais informações, consulte a seção Comentários.  
  
##  <a name="a-namefillmesha--crendertargetfillmesh"></a><a name="fillmesh"></a>CRenderTarget::FillMesh  
 Pinta o interior da malha especificado.  
  
```  
void FillMesh(
    CD2DMesh* pMesh,  
    CD2DBrush* pBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMesh`  
 A malha para pintar.  
  
 `pBrush`  
 O pincel usado para pintar a malha.  
  
##  <a name="a-namefillopacitymaska--crendertargetfillopacitymask"></a><a name="fillopacitymask"></a>CRenderTarget::FillOpacityMask  
 Aplica-se a máscara de opacidade descrita pelo bitmap especificado como um pincel e usa esse pincel para pintar uma região de destino de renderização.  
  
```  
void FillOpacityMask(
    CD2DBitmap* pOpacityMask,  
    CD2DBrush* pBrush,  
    D2D1_OPACITY_MASK_CONTENT content,  
    const CD2DRectF& rectDest,  
    const CD2DRectF& rectSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pOpacityMask`  
 A posição e o radius em pixels independentes de dispositivo, da elipse para pintar.  
  
 `pBrush`  
 O pincel usado para pintar a região do destino de renderização especificado por destinationRectangle.  
  
 `content`  
 O tipo de conteúdo que contém a máscara de opacidade. O valor é usado para determinar o espaço de cor em que a máscara de opacidade é combinada.  
  
 `rectDest`  
 A região do destino de renderização para pintar em pixels independentes de dispositivo.  
  
 `rectSrc`  
 A região do bitmap para usar como a máscara de opacidade, em pixels independentes de dispositivo.  
  
##  <a name="a-namefillrectanglea--crendertargetfillrectangle"></a><a name="fillrectangle"></a>CRenderTarget::FillRectangle  
 Pinta o interior do retângulo especificado.  
  
```  
void FillRectangle(
    const CD2DRectF& rect,  
    CD2DBrush* pBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rect`  
 A dimensão do retângulo para pintar em pixels independentes de dispositivo.  
  
 `pBrush`  
 O pincel usado para pintar o retângulo está interior.  
  
##  <a name="a-namefillroundedrectanglea--crendertargetfillroundedrectangle"></a><a name="fillroundedrectangle"></a>CRenderTarget::FillRoundedRectangle  
 Pinta o interior do retângulo arredondado especificado.  
  
```  
void FillRoundedRectangle(
    const CD2DRoundedRect& rectRounded,  
    CD2DBrush* pBrush);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rectRounded`  
 As dimensões do retângulo arredondado para pintar em pixels independentes de dispositivo.  
  
 `pBrush`  
 O pincel usado para pintar o interior do retângulo arredondado.  
  
##  <a name="a-nameflusha--crendertargetflush"></a><a name="flush"></a>CRenderTarget::Flush  
 Executa todos os comandos de desenho pendentes.  
  
```  
void Flush(
    D2D1_TAG* tag1 = NULL,  
    D2D1_TAG* tag2 = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `tag1`  
 Contém a marca para operações que causou a erros ou 0 se não há erros de desenho. Este parâmetro é passado não inicializado.  
  
 `tag2`  
 Contém a marca para operações que causou a erros ou 0 se não há erros de desenho. Este parâmetro é passado não inicializado.  
  
##  <a name="a-namegetantialiasmodea--crendertargetgetantialiasmode"></a><a name="getantialiasmode"></a>CRenderTarget::GetAntialiasMode  
 Recupera o modo de suavização atual para operações de desenho não textual.  
  
```  
D2D1_ANTIALIAS_MODE GetAntialiasMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Modo de suavização atual para operações de desenho não sejam de texto.  
  
##  <a name="a-namegetdpia--crendertargetgetdpi"></a><a name="getdpi"></a>CRenderTarget::GetDpi  
 Retorna a renderização pontos de destino por polegada (DPI)  
  
```  
CD2DSizeF GetDpi() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Pontos do destino de renderização por polegada (DPI).  
  
##  <a name="a-namegetmaximumbitmapsizea--crendertargetgetmaximumbitmapsize"></a><a name="getmaximumbitmapsize"></a>CRenderTarget::GetMaximumBitmapSize  
 Obtém o tamanho máximo, em unidades dependentes de dispositivo (pixels), de qualquer dimensão de um bitmap compatíveis com o destino de renderização  
  
```  
UINT32 GetMaximumBitmapSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho máximo, em pixels, de qualquer dimensão de um bitmap compatíveis com o destino de renderização  
  
##  <a name="a-namegetpixelformata--crendertargetgetpixelformat"></a><a name="getpixelformat"></a>CRenderTarget::GetPixelFormat  
 Recupera o modo de formato e alfa do pixel do destino de renderização  
  
```  
D2D1_PIXEL_FORMAT GetPixelFormat() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O modo de formato e alfa do pixel do destino de renderização  
  
##  <a name="a-namegetpixelsizea--crendertargetgetpixelsize"></a><a name="getpixelsize"></a>CRenderTarget::GetPixelSize  
 Retorna o tamanho do destino de renderização em pixels do dispositivo  
  
```  
CD2DSizeU GetPixelSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho do destino de renderização em pixels do dispositivo  
  
##  <a name="a-namegetrendertargeta--crendertargetgetrendertarget"></a><a name="getrendertarget"></a>CRenderTarget::GetRenderTarget  
 Interface de ID2D1RenderTarget retorna  
  
```  
ID2D1RenderTarget* GetRenderTarget();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1RenderTarget ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="a-namegetsizea--crendertargetgetsize"></a><a name="getsize"></a>CRenderTarget::GetSize  
 Retorna o tamanho do destino de renderização em pixels independentes de dispositivo  
  
```  
CD2DSizeF GetSize() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O tamanho atual do destino de renderização em pixels independentes de dispositivo  
  
##  <a name="a-namegettagsa--crendertargetgettags"></a><a name="gettags"></a>CRenderTarget::GetTags  
 Obtém o rótulo para operações de desenho subsequentes.  
  
```  
void GetTags(
    D2D1_TAG* tag1 = NULL,  
    D2D1_TAG* tag2 = NULL) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `tag1`  
 Contém o primeiro rótulo para operações de desenho subsequentes. Este parâmetro é passado não inicializado. Se NULL for especificado, nenhum valor é recuperado para esse parâmetro.  
  
 `tag2`  
 Contém o segundo rótulo para operações de desenho subsequentes. Este parâmetro é passado não inicializado. Se NULL for especificado, nenhum valor é recuperado para esse parâmetro.  
  
##  <a name="a-namegettextantialiasmodea--crendertargetgettextantialiasmode"></a><a name="gettextantialiasmode"></a>CRenderTarget::GetTextAntialiasMode  
 Obtém o atual modo de suavização para texto e operações de desenho de glifo.  
  
```  
D2D1_TEXT_ANTIALIAS_MODE GetTextAntialiasMode() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Modo atual de suavização para texto e operações de desenho de glifo.  
  
##  <a name="a-namegettextrenderingparamsa--crendertargetgettextrenderingparams"></a><a name="gettextrenderingparams"></a>CRenderTarget::GetTextRenderingParams  
 Recupera as opções de renderização de texto atual do destino de renderização.  
  
```  
void GetTextRenderingParams(IDWriteRenderingParams** textRenderingParams);
```  
  
### <a name="parameters"></a>Parâmetros  
 `textRenderingParams`  
 Quando este método retorna, atual textRenderingParamscontains o endereço de um ponteiro para o destino de renderização do opções de processamento de texto.  
  
##  <a name="a-namegettransforma--crendertargetgettransform"></a><a name="gettransform"></a>CRenderTarget::GetTransform  
 Aplica a transformação especificada para o destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrem no espaço de transformados.  
  
```  
void GetTransform(D2D1_MATRIX_3X2_F* transform);
```  
  
### <a name="parameters"></a>Parâmetros  
 `transform`  
 A transformação a ser aplicada para o destino de renderização.  
  
##  <a name="a-nameissupporteda--crendertargetissupported"></a><a name="issupported"></a>CRenderTarget::IsSupported  
 Indica se o destino de renderização oferece suporte as propriedades especificadas  
  
```  
BOOL IsSupported(const D2D1_RENDER_TARGET_PROPERTIES& renderTargetProperties) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `renderTargetProperties`  
 As propriedades de destino de renderização para testar  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se as propriedades de destino de processamento especificados são suportadas pelo destino de renderização; Caso contrário, FALSE  
  
##  <a name="a-nameisvalida--crendertargetisvalid"></a><a name="isvalid"></a>CRenderTarget::IsValid  
 Verificações de validade de recursos  
  
```  
BOOL IsValid() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o recurso é válido. Caso contrário, FALSE.  
  
##  <a name="a-namemlstresourcesa--crendertargetmlstresources"></a><a name="m_lstresources"></a>CRenderTarget::m_lstResources  
 Uma lista de ponteiros para objetos CD2DResource.  
  
```  
CObList m_lstResources;  
```  
  
##  <a name="a-namemprendertargeta--crendertargetmprendertarget"></a><a name="m_prendertarget"></a>CRenderTarget::m_pRenderTarget  
 Um ponteiro para um objeto ID2D1RenderTarget.  
  
```  
ID2D1RenderTarget* m_pRenderTarget;  
```  
  
##  <a name="a-namemptextformatdefaulta--crendertargetmptextformatdefault"></a><a name="m_ptextformatdefault"></a>CRenderTarget::m_pTextFormatDefault  
 Um ponteiro para o objeto CD2DTextFormat que contém um formato de texto padrão.  
  
```  
CD2DTextFormat* m_pTextFormatDefault;  
```  
  
##  <a name="a-nameoperatorid2d1rendertargetstara--crendertargetoperator-id2d1rendertarget"></a><a name="operator_id2d1rendertarget_star"></a>CRenderTarget::operator ID2D1RenderTarget *  
 Interface de ID2D1RenderTarget retorna  
  
```  
operator ID2D1RenderTarget*();
```   
  
### <a name="return-value"></a>Valor de retorno  
 Ponteiro para uma interface ID2D1RenderTarget ou NULL se o objeto ainda não foi inicializado.  
  
##  <a name="a-namepopaxisalignedclipa--crendertargetpopaxisalignedclip"></a><a name="popaxisalignedclip"></a>CRenderTarget::PopAxisAlignedClip  
 Remove o último clipe alinhado por eixo no alvo processado. Depois que esse método é chamado, o clipe não for mais aplicado às operações de desenho subsequentes.  
  
```  
void PopAxisAlignedClip();
```  
  
##  <a name="a-namepoplayera--crendertargetpoplayer"></a><a name="poplayer"></a>CRenderTarget::PopLayer  
 Paradas de redirecionamento de operações de desenho à camada especificada pelo PushLayer a última chamada.  
  
```  
void PopLayer();
```  
  
##  <a name="a-namepushaxisalignedclipa--crendertargetpushaxisalignedclip"></a><a name="pushaxisalignedclip"></a>CRenderTarget::PushAxisAlignedClip  
 Remove o último clipe alinhado por eixo no alvo processado. Depois que esse método é chamado, o clipe não for mais aplicado às operações de desenho subsequentes.  
  
```  
void PushAxisAlignedClip(
    const CD2DRectF& rectClip,  
    D2D1_ANTIALIAS_MODE mode = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `rectClip`  
 O tamanho e a posição da área de recorte, em pixels independentes de dispositivo.  
  
 `mode`  
 O modo de suavização é usado para desenhar as bordas do clipe rects que têm limites de sub-pixel e mesclar o clipe com o conteúdo da cena. A mesclagem é executada uma vez quando o método PopAxisAlignedClip é chamado e não se aplicam a cada primitiva dentro da camada.  
  
##  <a name="a-namepushlayera--crendertargetpushlayer"></a><a name="pushlayer"></a>CRenderTarget::PushLayer  
 Adiciona a camada especificada para o destino de renderização para que ele recebe todas as operações de desenho subsequentes até PopLayer é chamado.  
  
```  
void PushLayer(
    const D2D1_LAYER_PARAMETERS& layerParameters,  
    CD2DLayer& layer);
```  
  
### <a name="parameters"></a>Parâmetros  
 `layerParameters`  
 O conteúdo limites, máscara geométrica, opacidade, máscara de opacidade e opções de suavização para a camada.  
  
 `layer`  
 A camada que recebe as operações subsequentes de desenho.  
  
##  <a name="a-namerestoredrawingstatea--crendertargetrestoredrawingstate"></a><a name="restoredrawingstate"></a>CRenderTarget::RestoreDrawingState  
 Define o estado de desenho do destino de renderização para que o ID2D1DrawingStateBlock especificado.  
  
```  
void RestoreDrawingState(ID2D1DrawingStateBlock& drawingStateBlock);
```  
  
### <a name="parameters"></a>Parâmetros  
 `drawingStateBlock`  
 O novo estado de desenho do destino de renderização.  
  
##  <a name="a-namesavedrawingstatea--crendertargetsavedrawingstate"></a><a name="savedrawingstate"></a>CRenderTarget::SaveDrawingState  
 Salva o estado atual de desenho para o ID2D1DrawingStateBlock especificado.  
  
```  
void SaveDrawingState(ID2D1DrawingStateBlock& drawingStateBlock) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `drawingStateBlock`  
 Quando este método retorna, contém o estado atual de desenho do destino de renderização. Esse parâmetro deve ser inicializado antes de passar para o método.  
  
##  <a name="a-namesetantialiasmodea--crendertargetsetantialiasmode"></a><a name="setantialiasmode"></a>CRenderTarget::SetAntialiasMode  
 Define o modo de suavização do destino de renderização. O modo de suavização se aplica a todas as operações de desenho subsequentes, excluindo o texto e operações de desenho de glifo.  
  
```  
void SetAntialiasMode(D2D1_ANTIALIAS_MODE antialiasMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `antialiasMode`  
 O modo de suavização para operações futuras de desenho.  
  
##  <a name="a-namesetdpia--crendertargetsetdpi"></a><a name="setdpi"></a>CRenderTarget::SetDpi  
 Define pontos por polegada (DPI) do destino de renderização.  
  
```  
void SetDpi(const CD2DSizeF& sizeDPI);
```  
  
### <a name="parameters"></a>Parâmetros  
 `sizeDPI`  
 Um valor maior que ou igual a zero que especifica o horizontal/verticalDPI do destino de renderização.  
  
##  <a name="a-namesettagsa--crendertargetsettags"></a><a name="settags"></a>CRenderTarget::SetTags  
 Especifica um rótulo para operações de desenho subsequentes.  
  
```  
void SetTags(
    D2D1_TAG tag1,  
    D2D1_TAG tag2);
```  
  
### <a name="parameters"></a>Parâmetros  
 `tag1`  
 Um rótulo para aplicar a operações de desenho subsequentes.  
  
 `tag2`  
 Um rótulo para aplicar a operações de desenho subsequentes.  
  
##  <a name="a-namesettextantialiasmodea--crendertargetsettextantialiasmode"></a><a name="settextantialiasmode"></a>CRenderTarget::SetTextAntialiasMode  
 Especifica o modo de suavização para usar para o texto subsequente e operações de desenho do glifo.  
  
```  
void SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE textAntialiasMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `textAntialiasMode`  
 O modo de suavização para usar para o texto subsequente e operações de desenho de glifo.  
  
##  <a name="a-namesettextrenderingparamsa--crendertargetsettextrenderingparams"></a><a name="settextrenderingparams"></a>CRenderTarget::SetTextRenderingParams  
 Especifica as opções de renderização de texto a ser aplicado a todo o texto subsequente e operações de desenho de glifo.  
  
```  
void SetTextRenderingParams(IDWriteRenderingParams* textRenderingParams = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `textRenderingParams`  
 As opções de processamento de texto a ser aplicado a todo o texto subsequente e glifo desenho operações; NULL para limpar as opções de processamento de texto atual.  
  
##  <a name="a-namesettransforma--crendertargetsettransform"></a><a name="settransform"></a>CRenderTarget::SetTransform  
 Aplica a transformação especificada para o destino de renderização, substituindo a transformação existente. Todas as operações de desenho subsequentes ocorrem no espaço de transformados.  
  
```  
void SetTransform(const D2D1_MATRIX_3X2_F* transform);  
void SetTransform(const D2D1_MATRIX_3X2_F& transform);
```  
  
### <a name="parameters"></a>Parâmetros  
 `transform`  
 A transformação a ser aplicada para o destino de renderização.  
  
##  <a name="a-nameverifyresourcea--crendertargetverifyresource"></a><a name="verifyresource"></a>CRenderTarget::VerifyResource  
 Verifica a validade do objeto CD2DResource; cria o objeto se ele já não existe.  
  
```  
BOOL VerifyResource(CD2DResource* pResource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pResource`  
 Ponteiro para o objeto CD2DResource.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE é o objeto se válidas. Caso contrário, FALSE.  
  
## <a name="see-also"></a>Consulte também  
 [Classes](../../mfc/reference/mfc-classes.md)

