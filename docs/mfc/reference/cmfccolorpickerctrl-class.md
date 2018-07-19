---
title: Classe CMFCColorPickerCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCColorPickerCtrl
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::CMFCColorPickerCtrl
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::GetColor
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::GetHLS
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::GetHue
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::GetLuminance
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::GetSaturation
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SelectCellHexagon
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetColor
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetHLS
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetHue
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetLuminance
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetLuminanceBarWidth
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetOriginalColor
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetPalette
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetSaturation
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::SetType
- AFXCOLORPICKERCTRL/CMFCColorPickerCtrl::DrawCursor
dev_langs:
- C++
helpviewer_keywords:
- CMFCColorPickerCtrl [MFC], CMFCColorPickerCtrl
- CMFCColorPickerCtrl [MFC], GetColor
- CMFCColorPickerCtrl [MFC], GetHLS
- CMFCColorPickerCtrl [MFC], GetHue
- CMFCColorPickerCtrl [MFC], GetLuminance
- CMFCColorPickerCtrl [MFC], GetSaturation
- CMFCColorPickerCtrl [MFC], SelectCellHexagon
- CMFCColorPickerCtrl [MFC], SetColor
- CMFCColorPickerCtrl [MFC], SetHLS
- CMFCColorPickerCtrl [MFC], SetHue
- CMFCColorPickerCtrl [MFC], SetLuminance
- CMFCColorPickerCtrl [MFC], SetLuminanceBarWidth
- CMFCColorPickerCtrl [MFC], SetOriginalColor
- CMFCColorPickerCtrl [MFC], SetPalette
- CMFCColorPickerCtrl [MFC], SetSaturation
- CMFCColorPickerCtrl [MFC], SetType
- CMFCColorPickerCtrl [MFC], DrawCursor
ms.assetid: b9bbd03c-beb0-4b55-9765-9985fd05e5dc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 709992c42cf7fd489fbe8fe8d4ebf40bf92a989e
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37849959"
---
# <a name="cmfccolorpickerctrl-class"></a>Classe CMFCColorPickerCtrl
O `CMFCColorPickerCtrl` classe fornece funcionalidade para um controle que é usado para selecionar cores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCColorPickerCtrl : public CButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorPickerCtrl::CMFCColorPickerCtrl](#cmfccolorpickerctrl)|Constrói um objeto `CMFCColorPickerCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorPickerCtrl::GetColor](#getcolor)|Recupera a cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::GetHLS](#gethls)|Recupera os valores de matiz, saturação e a luminância da cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::GetHue](#gethue)|Recupera o componente de matiz da cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::GetLuminance](#getluminance)|Recupera o componente de luminância da cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::GetSaturation](#getsaturation)|Recupera o componente de saturação da cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::SelectCellHexagon](#selectcellhexagon)|Define a cor atual para a cor definida pelos componentes de cor RGB especificados ou hexágono a célula especificada.|  
|[CMFCColorPickerCtrl::SetColor](#setcolor)|Define a cor atual para o valor de cor RGB especificado.|  
|[CMFCColorPickerCtrl::SetHLS](#sethls)|Define a cor atual para o valor de cor especificado do HLS.|  
|[CMFCColorPickerCtrl::SetHue](#sethue)|Altera o componente de matiz da cor selecionada no momento.|  
|[CMFCColorPickerCtrl::SetLuminance](#setluminance)|Altera o componente de luminância da cor selecionada no momento.|  
|[CMFCColorPickerCtrl::SetLuminanceBarWidth](#setluminancebarwidth)|Define a largura da barra de luminosidade no controle do seletor de cor.|  
|[CMFCColorPickerCtrl::SetOriginalColor](#setoriginalcolor)|Define a cor selecionada inicial.|  
|[CMFCColorPickerCtrl::SetPalette](#setpalette)|Define a paleta de cores atual.|  
|[CMFCColorPickerCtrl::SetSaturation](#setsaturation)|Altera o componente de saturação da cor selecionada no momento.|  
|[CMFCColorPickerCtrl::SetType](#settype)|Define o tipo de controle de seletor de cor para exibir.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorPickerCtrl::DrawCursor](#drawcursor)|Chamado pelo framework antes de um cursor que aponta para a cor selecionada é exibido.|  
  
## <a name="remarks"></a>Comentários  
 Cores padrão são selecionadas de uma paleta de cores hexagonal e cores personalizadas são selecionadas de uma barra de luminosidade onde as cores são especificadas usando notação de vermelho/verde/azul ou notação de matiz/satuaration/luminância.  
  
 A ilustração a seguir mostra vários `CMFCColorPickerCtrl` objetos.  
  
 ![Caixa de diálogo CMFCColorPickerCtrl](../../mfc/reference/media/colorpicker.png "colorpicker")  
  
 O `CMFCColorPickerCtrl` dá suporte a dois pares de estilos. Os estilos HEX_GREYSCALE e HEX são apropriados para a seleção de cor padrão. Os estilos de SELETOR e a LUMINÂNCIA são apropriados para a seleção de cor personalizada.  
  
 Execute as seguintes etapas para incorporar o `CMFCColorPickerCtrl` controle em sua caixa de diálogo:  
  
1.  Se você usar o **ClassWizard**, inserir um novo controle de botão em seu modelo de caixa de diálogo (como o `CMFCColorPickerCtrl` classe é herdada do `CButton` classe).  
  
2.  Insira uma variável de membro que está associada com o novo controle de botão em sua classe de caixa de diálogo. Em seguida, altere o tipo de variável de `CButton` para `CMFCColorPickerCtrl`.  
  
3.  Inserir o `WM_INITDIALOG` manipulador de mensagens para a classe de caixa de diálogo. No manipulador, defina o tipo, paleta e cor selecionada inicial do `CMFCColorPickerCtrl` controle.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como configurar uma `CMFCColorPickerCtrl` objeto usando vários métodos no `CMFCColorPickerCtrl` classe. O exemplo demonstra como definir o tipo de controle do seletor e como definir sua cor, matiz, luminância e saturação. O exemplo é parte do [exemplo de novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls#4](../../mfc/reference/codesnippet/cpp/cmfccolorpickerctrl-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls#5](../../mfc/reference/codesnippet/cpp/cmfccolorpickerctrl-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcolorpickerctrl.h  
  
##  <a name="cmfccolorpickerctrl"></a>  CMFCColorPickerCtrl::CMFCColorPickerCtrl  
 Constrói um objeto `CMFCColorPickerCtrl`.  
  
```  
CMFCColorPickerCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="drawcursor"></a>  CMFCColorPickerCtrl::DrawCursor  
 Chamado pelo framework antes de um cursor que aponta para a cor selecionada é exibido.  
  
```  
virtual void DrawCursor(
    CDC* pDC,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pDC*  
 Ponteiro para um contexto de dispositivo.  
  
 [in] *rect*  
 Especifica uma área retangular ao redor da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método quando você precisar alterar a forma do cursor que aponta para a cor selecionada.  
  
##  <a name="getcolor"></a>  CMFCColorPickerCtrl::GetColor  
 Recupera a cor selecionada pelo usuário.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor RGB da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethls"></a>  CMFCColorPickerCtrl::GetHLS  
 Recupera os valores de matiz, saturação e a luminância da cor selecionada pelo usuário.  
  
```  
void GetHLS(
    double* hue,  
    double* luminance,  
    double* saturation);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] *matiz*  
 Ponteiro para uma variável do tipo duplo que recebe informações de matiz.  
  
 [out] *luminância*  
 Ponteiro para uma variável do tipo duplo que recebe informações de luminância.  
  
 [out] *saturação*  
 Ponteiro para uma variável do tipo duplo que recebe informações de saturação.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethue"></a>  CMFCColorPickerCtrl::GetHue  
 Recupera o componente de matiz da cor selecionada pelo usuário.  
  
```  
double GetHue() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O componente de matiz da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getluminance"></a>  CMFCColorPickerCtrl::GetLuminance  
 Recupera o componente de luminância da cor selecionada pelo usuário.  
  
```  
double GetLuminance() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O componente de luminância da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsaturation"></a>  CMFCColorPickerCtrl::GetSaturation  
 Recupera o valor de saturação da cor selecionada pelo usuário.  
  
```  
double GetSaturation() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O componente de saturação da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="selectcellhexagon"></a>  CMFCColorPickerCtrl::SelectCellHexagon  
 Define a cor atual para a cor definida pelos componentes de cor RGB especificados ou hexágono a célula especificada.  
  
```  
void SelectCellHexagon(
    BYTE R,  
    BYTE G,  
    BYTE B);

 
BOOL SelectCellHexagon(
    int x,  
    int y);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *R*  
 O componente de cor vermelha.  
  
 [in] *G*  
 O componente de cor verde.  
  
 [in] *B*  
 O componente de cor azul.  
  
 [in] *x*  
 A coordenada x do cursor, que aponta para um hexágono de célula.  
  
 [in] *y*  
 A coordenada y do cursor, que aponta para um hexágono de célula.  
  
### <a name="return-value"></a>Valor de retorno  
 A segunda sobrecarga desse método sempre retorna FALSE.  
  
### <a name="remarks"></a>Comentários  
 A primeira sobrecarga desse método define atual de cores para a cor que corresponde ao controle de seleção de cor especificado do componentes de cor vermelho, verde e azul.  
  
 A segunda sobrecarga desse método define a cor atual para a cor de hexágono a célula que é apontado pelo local do cursor especificado.  
  
##  <a name="setcolor"></a>  CMFCColorPickerCtrl::SetColor  
 Define a cor atual para o valor de cor RGB especificado.  
  
```  
void SetColor(COLORREF Color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *Cor*  
 Um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sethls"></a>  CMFCColorPickerCtrl::SetHLS  
 Define a cor atual para o valor de cor especificado do HLS.  
  
```  
void SetHLS(
    double hue,  
    double luminance,  
    double saturation,  
    BOOL bInvalidate=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *matiz*  
 Um valor de matiz.  
  
 [in] *luminância*  
 Um valor de luminância.  
  
 [in] *saturação*  
 Um valor de saturação.  
  
 [in] *bInvalidate*  
 TRUE para forçar a janela para atualizar imediatamente para a nova cor; Caso contrário, FALSE. O padrão é TRUE.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sethue"></a>  CMFCColorPickerCtrl::SetHue  
 Altera o matiz da cor selecionada no momento.  
  
```  
void SetHue(double Hue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *Matiz*  
 Um valor de matiz.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setluminance"></a>  CMFCColorPickerCtrl::SetLuminance  
 Altera a luminosidade da cor selecionada no momento.  
  
```  
void SetLuminance(double Luminance);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *Luminância*  
 Um valor de luminância.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setluminancebarwidth"></a>  CMFCColorPickerCtrl::SetLuminanceBarWidth  
 Define a largura da barra de luminosidade no controle do seletor de cor.  
  
```  
void SetLuminanceBarWidth(int w);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *w*  
 A largura da barra de luminosidade medida em pixels.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para redimensionar a barra de luminosidade, que está na **personalizado** guia do controle de seletor de cor. O *w* parâmetro especifica a nova largura da barra de luminância. O valor de largura é ignorado se ele exceder três-quartos da largura da área do cliente.  
  
##  <a name="setoriginalcolor"></a>  CMFCColorPickerCtrl::SetOriginalColor  
 Define a cor selecionada inicial.  
  
```  
void SetOriginalColor(COLORREF ref);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *ref*  
 Um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método quando o controle de seletor de cor é inicializado.  
  
##  <a name="setpalette"></a>  CMFCColorPickerCtrl::SetPalette  
 Define a paleta de cores atual.  
  
```  
void SetPalette(CPalette* pPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *pPalette*  
 Ponteiro para uma paleta de cores.  
  
### <a name="remarks"></a>Comentários  
 A paleta de cores define a matriz de cores que é apresentada no controle do seletor de cor.  
  
##  <a name="setsaturation"></a>  CMFCColorPickerCtrl::SetSaturation  
 Altera a saturação da cor selecionada no momento.  
  
```  
void SetSaturation(double Saturation);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *Saturação*  
 Um valor de saturação.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="settype"></a>  CMFCColorPickerCtrl::SetType  
 Define o tipo de controle de seletor de cor para exibir.  
  
```  
void SetType(COLORTYPE colorType);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *colorType*  
 Um tipo de controle de seletor de cor.  
  
 Os tipos são definidos pelo `CMFCColorPickerCtrl::COLORTYPE` enumeração. Os possíveis tipos são LUMINÂNCIA, SELETOR, HEX e HEX_GREYSCALE. O tipo padrão é o SELETOR.  
  
### <a name="remarks"></a>Comentários  
 Para especificar um tipo de controle de seletor de cor, chame esse método antes do controle do Windows é criado.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)
