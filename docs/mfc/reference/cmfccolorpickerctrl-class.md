---
title: Classe CMFCColorPickerCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
- CMFCColorPickerCtrl class
ms.assetid: b9bbd03c-beb0-4b55-9765-9985fd05e5dc
caps.latest.revision: 33
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
ms.openlocfilehash: 0a819d04535ba965e2c1a10f3761c442c9840538
ms.lasthandoff: 02/25/2017

---
# <a name="cmfccolorpickerctrl-class"></a>Classe CMFCColorPickerCtrl
O `CMFCColorPickerCtrl` classe fornece funcionalidade para um controle que é usado para selecionar cores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCColorPickerCtrl : public CButton  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorPickerCtrl::CMFCColorPickerCtrl](#cmfccolorpickerctrl)|Constrói um objeto `CMFCColorPickerCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorPickerCtrl::GetColor](#getcolor)|Recupera a cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::GetHLS](#gethls)|Recupera os valores de luminância, matiz e a saturação da cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::GetHue](#gethue)|Recupera o componente de matiz da cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::GetLuminance](#getluminance)|Recupera o componente de luminância da cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::GetSaturation](#getsaturation)|Recupera o componente de saturação da cor selecionada pelo usuário.|  
|[CMFCColorPickerCtrl::SelectCellHexagon](#selectcellhexagon)|Define a cor atual para a cor definida por componentes de cor RGB especificados ou hexágono a célula especificada.|  
|[CMFCColorPickerCtrl::SetColor](#setcolor)|Define a cor atual para o valor de cor RGB especificado.|  
|[CMFCColorPickerCtrl::SetHLS](#sethls)|Define a cor atual para o valor de cor HLS especificado.|  
|[CMFCColorPickerCtrl::SetHue](#sethue)|Altera o componente de matiz da cor selecionada no momento.|  
|[CMFCColorPickerCtrl::SetLuminance](#setluminance)|Altera o componente de luminância da cor selecionada no momento.|  
|[CMFCColorPickerCtrl::SetLuminanceBarWidth](#setluminancebarwidth)|Define a largura da barra de luminosidade no controle do seletor de cores.|  
|[CMFCColorPickerCtrl::SetOriginalColor](#setoriginalcolor)|Define a cor selecionada inicial.|  
|[CMFCColorPickerCtrl::SetPalette](#setpalette)|Define a paleta de cores atual.|  
|[CMFCColorPickerCtrl::SetSaturation](#setsaturation)|Altera o componente de saturação da cor selecionada no momento.|  
|[CMFCColorPickerCtrl::SetType](#settype)|Define o tipo de controle de seletor de cores para exibir.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCColorPickerCtrl::DrawCursor](#drawcursor)|Chamado pela estrutura antes de um cursor que aponta para a cor selecionada é exibido.|  
  
## <a name="remarks"></a>Comentários  
 Cores padrão são selecionadas de uma paleta de cores hexagonal e cores personalizadas são selecionadas de uma barra de luminosidade onde cores são especificadas usando notação de vermelho/verde/azul ou notação de matiz/satuaration/luminância.  
  
 A ilustração a seguir mostra vários `CMFCColorPickerCtrl` objetos.  
  
 ![Caixa de diálogo CMFCColorPickerCtrl](../../mfc/reference/media/colorpicker.png "colorpicker")  
  
 O `CMFCColorPickerCtrl` oferece suporte a dois pares de estilos. Os estilos HEX e HEX_GREYSCALE são apropriados para a seleção de cor padrão. Os estilos de SELETOR e LUMINOSIDADE são apropriados para seleção de cor personalizada.  
  
 Execute as seguintes etapas para incorporar o `CMFCColorPickerCtrl` controle na caixa de diálogo:  
  
1.  Se você usar o **ClassWizard**, inserir um novo controle de botão no seu modelo de caixa de diálogo (como o `CMFCColorPickerCtrl` classe é herdada da `CButton` classe).  
  
2.  Insira uma variável de membro que está associada com o novo controle de botão em sua classe de caixa de diálogo. Em seguida, altere o tipo de variável de `CButton` para `CMFCColorPickerCtrl`.  
  
3.  Inserir o `WM_INITDIALOG` manipulador de mensagens para a classe de caixa de diálogo. No manipulador, definir o tipo, paleta e cor selecionada inicial do `CMFCColorPickerCtrl` controle.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como configurar um `CMFCColorPickerCtrl` objeto usando vários métodos na `CMFCColorPickerCtrl` classe. O exemplo demonstra como definir o tipo de controle de seletor e como definir suas cores, matiz, luminosidade e saturação. O exemplo é parte do [exemplo novos controles](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_NewControls n º&4;](../../mfc/reference/codesnippet/cpp/cmfccolorpickerctrl-class_1.h)]  
[!code-cpp[NVC_MFC_NewControls n º&5;](../../mfc/reference/codesnippet/cpp/cmfccolorpickerctrl-class_2.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CButton](../../mfc/reference/cbutton-class.md)  
  
 [CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcolorpickerctrl.h  
  
##  <a name="cmfccolorpickerctrl"></a>CMFCColorPickerCtrl::CMFCColorPickerCtrl  
 Constrói um objeto `CMFCColorPickerCtrl`.  
  
```  
CMFCColorPickerCtrl();
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="drawcursor"></a>CMFCColorPickerCtrl::DrawCursor  
 Chamado pela estrutura antes de um cursor que aponta para a cor selecionada é exibido.  
  
```  
virtual void DrawCursor(
    CDC* pDC,  
    const CRect& rect);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pDC`  
 Ponteiro para um contexto de dispositivo.  
  
 [in] `rect`  
 Especifica uma área retangular ao redor da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método quando você precisa alterar a forma do cursor que aponta para a cor selecionada.  
  
##  <a name="getcolor"></a>CMFCColorPickerCtrl::GetColor  
 Recupera a cor selecionada pelo usuário.  
  
```  
COLORREF GetColor() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor RGB da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethls"></a>CMFCColorPickerCtrl::GetHLS  
 Recupera os valores de luminância, matiz e a saturação da cor selecionada pelo usuário.  
  
```  
void GetHLS(
    double* hue,  
    double* luminance,  
    double* saturation);
```  
  
### <a name="parameters"></a>Parâmetros  
 [out] `hue`  
 Ponteiro para uma variável do tipo double que recebe informações de matiz.  
  
 [out] `luminance`  
 Ponteiro para uma variável do tipo double que recebe informações de luminância.  
  
 [out] `saturation`  
 Ponteiro para uma variável do tipo double que recebe informações de saturação.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="gethue"></a>CMFCColorPickerCtrl::GetHue  
 Recupera o componente de matiz da cor selecionada pelo usuário.  
  
```  
double GetHue() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O componente de matiz da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getluminance"></a>CMFCColorPickerCtrl::GetLuminance  
 Recupera o componente de luminância da cor selecionada pelo usuário.  
  
```  
double GetLuminance() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O componente de luminância da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getsaturation"></a>CMFCColorPickerCtrl::GetSaturation  
 Recupera o valor da saturação da cor selecionada pelo usuário.  
  
```  
double GetSaturation() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 O componente de saturação da cor selecionada.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="selectcellhexagon"></a>CMFCColorPickerCtrl::SelectCellHexagon  
 Define a cor atual para a cor definida por componentes de cor RGB especificados ou hexágono a célula especificada.  
  
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
 [in] `R`  
 O componente de cor vermelha.  
  
 [in] `G`  
 O componente de cor verde.  
  
 [in] `B`  
 O componente de cor azul.  
  
 [in] `x`  
 A coordenada x do cursor, que aponta para um hexágono de célula.  
  
 [in] `y`  
 A coordenada y do cursor, que aponta para um hexágono de célula.  
  
### <a name="return-value"></a>Valor de retorno  
 A segunda sobrecarga desse método sempre retorna `FALSE`.  
  
### <a name="remarks"></a>Comentários  
 A primeira sobrecarga desse método define atual de cores para a cor que corresponde ao controle de seleção de cor especificadas componentes de cor vermelho, verde e azul.  
  
 A segunda sobrecarga desse método define a cor atual para a cor de hexágono a célula que está apontado para o local do cursor especificado.  
  
##  <a name="setcolor"></a>CMFCColorPickerCtrl::SetColor  
 Define a cor atual para o valor de cor RGB especificado.  
  
```  
void SetColor(COLORREF Color);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `Color`  
 Um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sethls"></a>CMFCColorPickerCtrl::SetHLS  
 Define a cor atual para o valor de cor HLS especificado.  
  
```  
void SetHLS(
    double hue,  
    double luminance,  
    double saturation,  
    BOOL bInvalidate=TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `hue`  
 Um valor de matiz.  
  
 [in] `luminance`  
 Um valor de luminância.  
  
 [in] `saturation`  
 Um valor de saturação.  
  
 [in] `bInvalidate`  
 `TRUE`para forçar a janela para atualizar imediatamente para a nova cor; Caso contrário, `FALSE`. O padrão é `TRUE`.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="sethue"></a>CMFCColorPickerCtrl::SetHue  
 Altera o matiz da cor selecionada no momento.  
  
```  
void SetHue(double Hue);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `Hue`  
 Um valor de matiz.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setluminance"></a>CMFCColorPickerCtrl::SetLuminance  
 Altera a luminosidade da cor selecionada no momento.  
  
```  
void SetLuminance(double Luminance);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `Luminance`  
 Um valor de luminância.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="setluminancebarwidth"></a>CMFCColorPickerCtrl::SetLuminanceBarWidth  
 Define a largura da barra de luminosidade no controle do seletor de cores.  
  
```  
void SetLuminanceBarWidth(int w);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `w`  
 A largura da barra de luminosidade medido em pixels.  
  
### <a name="remarks"></a>Comentários  
 Use este método para redimensionar a barra de luminosidade, que está no **personalizado** guia do controle de seletor de cores. O `w` parâmetro especifica a nova largura da barra de luminosidade. O valor da largura é ignorado se ele exceder três-quartos da largura da área do cliente.  
  
##  <a name="setoriginalcolor"></a>CMFCColorPickerCtrl::SetOriginalColor  
 Define a cor selecionada inicial.  
  
```  
void SetOriginalColor(COLORREF ref);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `ref`  
 Um valor de cor RGB.  
  
### <a name="remarks"></a>Comentários  
 Chame esse método quando o controle de seletor de cor é inicializado.  
  
##  <a name="setpalette"></a>CMFCColorPickerCtrl::SetPalette  
 Define a paleta de cores atual.  
  
```  
void SetPalette(CPalette* pPalette);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pPalette`  
 Ponteiro para uma paleta de cores.  
  
### <a name="remarks"></a>Comentários  
 A paleta de cores define a matriz de cores é apresentada no controle do seletor de cores.  
  
##  <a name="setsaturation"></a>CMFCColorPickerCtrl::SetSaturation  
 Altera a saturação da cor selecionada no momento.  
  
```  
void SetSaturation(double Saturation);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `Saturation`  
 Um valor de saturação.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="settype"></a>CMFCColorPickerCtrl::SetType  
 Define o tipo de controle de seletor de cores para exibir.  
  
```  
void SetType(COLORTYPE colorType);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `colorType`  
 Um tipo de controle de seletor de cores.  
  
 Os tipos são definidos pelo `CMFCColorPickerCtrl::COLORTYPE` enumeração. Os tipos possíveis são `LUMINANCE`, `PICKER`, `HEX` e `HEX_GREYSCALE`. O tipo padrão é `PICKER`.  
  
### <a name="remarks"></a>Comentários  
 Para especificar um tipo de controle de seletor de cor, chame esse método antes do controle do Windows é criado.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)

