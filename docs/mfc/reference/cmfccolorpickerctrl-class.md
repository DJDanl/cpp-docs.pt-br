---
title: Classe CMFCColorPickerCtrl
ms.date: 11/19/2018
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
ms.openlocfilehash: c3c11db448ab31324367b7f314cd6bfe44c2e96d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367693"
---
# <a name="cmfccolorpickerctrl-class"></a>Classe CMFCColorPickerCtrl

A `CMFCColorPickerCtrl` classe fornece funcionalidade para um controle que é usado para selecionar cores.

## <a name="syntax"></a>Sintaxe

```
class CMFCColorPickerCtrl : public CButton
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorPickerCtrl:CMFCColorPickerCtrl](#cmfccolorpickerctrl)|Constrói um objeto `CMFCColorPickerCtrl`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorPickerCtrl::GetColor](#getcolor)|Recupera a cor que o usuário seleciona.|
|[CMFCColorPickerCtrl::GetHLS](#gethls)|Recupera os valores de matiz, luminância e saturação da cor que o usuário seleciona.|
|[CMFCColorPickerCtrl::GetHue](#gethue)|Recupera o componente de tonalidade da cor que o usuário seleciona.|
|[CMFCColorPickerCtrl::GetLuminance](#getluminance)|Recupera o componente de luminância da cor que o usuário seleciona.|
|[CMFCColorPickerCtrl::GetSaturaation](#getsaturation)|Recupera o componente de saturação da cor que o usuário seleciona.|
|[CMFCColorPickerCtrl::SelectCellHexagon](#selectcellhexagon)|Define a cor atual para a cor definida pelos componentes de cor RGB especificados ou pelo hexágono de célula especificado.|
|[CMFCColorPickerCtrl::SetColor](#setcolor)|Define a cor atual para o valor de cor RGB especificado.|
|[CMFCColorPickerCtrl::SetHLS](#sethls)|Define a cor atual para o valor de cor HLS especificado.|
|[CMFCColorPickerCtrl::SetHue](#sethue)|Altera o componente de tonalidade da cor selecionada no momento.|
|[CMFCColorPickerCtrl::SetLuminance](#setluminance)|Altera o componente de luminância da cor selecionada no momento.|
|[CMFCColorPickerCtrl::SetLuminanceBarWidth](#setluminancebarwidth)|Define a largura da barra de luminância no controle do seletor de cores.|
|[CMFCColorPickerCtrl::SetOriginalColor](#setoriginalcolor)|Define a cor selecionada inicial.|
|[CMFCColorPickerCtrl::SetPalette](#setpalette)|Define a paleta de cores atual.|
|[CMFCColorPickerCtrl::SetSaturação](#setsaturation)|Altera o componente de saturação da cor selecionada no momento.|
|[CMFCColorPickerCtrl::SetType](#settype)|Define o tipo de controle do seletor de cores para exibir.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorPickerCtrl::DrawCursor](#drawcursor)|Chamado pela estrutura antes de um cursor que aponta para a cor selecionada é exibido.|

## <a name="remarks"></a>Comentários

As cores padrão são selecionadas a partir de uma paleta de cores hexagonal, e as cores personalizadas são selecionadas a partir de uma barra de luminância onde as cores são especificadas usando notação vermelha/verde/azul ou notação de matiz/satuaração/luminância.

A ilustração a `CMFCColorPickerCtrl` seguir mostra vários objetos.

![Caixa de diálogo CMFCColorPickerCtrl](../../mfc/reference/media/colorpicker.png "Caixa de diálogo CMFCColorPickerCtrl")

O `CMFCColorPickerCtrl` suporta dois pares de estilos. Os estilos HEX e HEX_GREYSCALE são apropriados para a seleção padrão de cores. Os estilos PICKER e LUMINANCE são apropriados para seleção personalizada de cores.

Execute as seguintes `CMFCColorPickerCtrl` etapas para incorporar o controle na caixa de diálogo:

1. Se você usar o **ClassWizard,** insira um novo `CMFCColorPickerCtrl` controle de botão `CButton` no modelo da caixa de diálogo (porque a classe é herdada da classe).

1. Insira uma variável de membro associada ao novo controle de botão na classe da caixa de diálogo. Em seguida, altere o tipo de variável de `CButton` para `CMFCColorPickerCtrl`.

1. Insira o `WM_INITDIALOG` manipulador de mensagens para a classe caixa de diálogo. No manipulador, defina o tipo, a paleta `CMFCColorPickerCtrl` e a cor selecionada inicial do controle.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra `CMFCColorPickerCtrl` como configurar um objeto `CMFCColorPickerCtrl` usando vários métodos na classe. O exemplo demonstra como definir o tipo de controle do seletor e como definir sua cor, matiz, luminância e saturação. O exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#4](../../mfc/reference/codesnippet/cpp/cmfccolorpickerctrl-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#5](../../mfc/reference/codesnippet/cpp/cmfccolorpickerctrl-class_2.cpp)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CButton](../../mfc/reference/cbutton-class.md)

[Cmfccolorpickerctrl](../../mfc/reference/cmfccolorpickerctrl-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolorpickerctrl.h

## <a name="cmfccolorpickerctrlcmfccolorpickerctrl"></a><a name="cmfccolorpickerctrl"></a>CMFCColorPickerCtrl:CMFCColorPickerCtrl

Constrói um objeto `CMFCColorPickerCtrl`.

```
CMFCColorPickerCtrl();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrldrawcursor"></a><a name="drawcursor"></a>CMFCColorPickerCtrl::DrawCursor

Chamado pela estrutura antes de um cursor que aponta para a cor selecionada é exibido.

```
virtual void DrawCursor(
    CDC* pDC,
    const CRect& rect);
```

### <a name="parameters"></a>Parâmetros

*pDC*<br/>
[em] Ponteiro para um contexto de dispositivo.

*Rect*<br/>
[em] Especifica uma área retangular ao redor da cor selecionada.

### <a name="remarks"></a>Comentários

Anular este método quando você precisar alterar a forma do cursor que aponta para a cor selecionada.

## <a name="cmfccolorpickerctrlgetcolor"></a><a name="getcolor"></a>CMFCColorPickerCtrl::GetColor

Recupera a cor que o usuário seleciona.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

O valor RGB da cor selecionada.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlgethls"></a><a name="gethls"></a>CMFCColorPickerCtrl::GetHLS

Recupera os valores de matiz, luminância e saturação da cor que o usuário seleciona.

```
void GetHLS(
    double* hue,
    double* luminance,
    double* saturation);
```

### <a name="parameters"></a>Parâmetros

*Matiz*<br/>
[fora] Ponteiro para uma variável de tipo duplo que recebe informações de matiz.

*Luminância*<br/>
[fora] Ponteiro para uma variável de tipo duplo que recebe informações de luminância.

*Saturação*<br/>
[fora] Ponteiro para uma variável de tipo duplo que recebe informações de saturação.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlgethue"></a><a name="gethue"></a>CMFCColorPickerCtrl::GetHue

Recupera o componente de tonalidade da cor que o usuário seleciona.

```
double GetHue() const;
```

### <a name="return-value"></a>Valor retornado

O componente de matiz da cor selecionada.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlgetluminance"></a><a name="getluminance"></a>CMFCColorPickerCtrl::GetLuminance

Recupera o componente de luminância da cor que o usuário seleciona.

```
double GetLuminance() const;
```

### <a name="return-value"></a>Valor retornado

O componente de luminância da cor selecionada.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlgetsaturation"></a><a name="getsaturation"></a>CMFCColorPickerCtrl::GetSaturaation

Recupera o valor de saturação da cor que o usuário seleciona.

```
double GetSaturation() const;
```

### <a name="return-value"></a>Valor retornado

O componente de saturação da cor selecionada.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlselectcellhexagon"></a><a name="selectcellhexagon"></a>CMFCColorPickerCtrl::SelectCellHexagon

Define a cor atual para a cor definida pelos componentes de cor RGB especificados ou pelo hexágono de célula especificado.

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

*R*<br/>
[em] O componente de cor vermelha.

*G*<br/>
[em] O componente de cor verde.

*B*<br/>
[em] O componente de cor azul.

*x*<br/>
[em] A coordenada x do cursor, que aponta para um hexágono celular.

*Y*<br/>
[em] A coordenada y do cursor, que aponta para um hexágono celular.

### <a name="return-value"></a>Valor retornado

A segunda sobrecarga deste método sempre retorna FALSE.

### <a name="remarks"></a>Comentários

A primeira sobrecarga deste método define a cor atual para a cor que corresponde aos componentes de cor vermelha, verde e azul especificados do controle de seleção de cores.

A segunda sobrecarga deste método define a cor atual para a cor do hexágono celular que é apontada pelo local do cursor especificado.

## <a name="cmfccolorpickerctrlsetcolor"></a><a name="setcolor"></a>CMFCColorPickerCtrl::SetColor

Define a cor atual para o valor de cor RGB especificado.

```
void SetColor(COLORREF Color);
```

### <a name="parameters"></a>Parâmetros

*Cor*<br/>
[em] Um valor de cor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlsethls"></a><a name="sethls"></a>CMFCColorPickerCtrl::SetHLS

Define a cor atual para o valor de cor HLS especificado.

```
void SetHLS(
    double hue,
    double luminance,
    double saturation,
    BOOL bInvalidate=TRUE);
```

### <a name="parameters"></a>Parâmetros

*Matiz*<br/>
[em] Um valor de matiz.

*Luminância*<br/>
[em] Um valor de luminância.

*Saturação*<br/>
[em] Um valor de saturação.

*bInvalidar*<br/>
[em] TRUE para forçar a janela a atualizar imediatamente para a nova cor; caso contrário, FALSE. O padrão é TRUE.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlsethue"></a><a name="sethue"></a>CMFCColorPickerCtrl::SetHue

Altera a tonalidade da cor selecionada no momento.

```
void SetHue(double Hue);
```

### <a name="parameters"></a>Parâmetros

*Matiz*<br/>
[em] Um valor de matiz.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlsetluminance"></a><a name="setluminance"></a>CMFCColorPickerCtrl::SetLuminance

Altera a luminância da cor selecionada no momento.

```
void SetLuminance(double Luminance);
```

### <a name="parameters"></a>Parâmetros

*Luminância*<br/>
[em] Um valor de luminância.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlsetluminancebarwidth"></a><a name="setluminancebarwidth"></a>CMFCColorPickerCtrl::SetLuminanceBarWidth

Define a largura da barra de luminância no controle do seletor de cores.

```
void SetLuminanceBarWidth(int w);
```

### <a name="parameters"></a>Parâmetros

*w*<br/>
[em] A largura da barra de luminância medida em pixels.

### <a name="remarks"></a>Comentários

Use este método para redimensionar a barra de luminância, que está na guia **Personalizado** do controle do seletor de cores. O parâmetro *w* especifica a nova largura da barra de luminância. O valor de largura é ignorado se exceder três quartos da largura da área do cliente.

## <a name="cmfccolorpickerctrlsetoriginalcolor"></a><a name="setoriginalcolor"></a>CMFCColorPickerCtrl::SetOriginalColor

Define a cor selecionada inicial.

```
void SetOriginalColor(COLORREF ref);
```

### <a name="parameters"></a>Parâmetros

*ref*<br/>
[em] Um valor de cor RGB.

### <a name="remarks"></a>Comentários

Chame este método quando o controle do seletor de cores for inicializado.

## <a name="cmfccolorpickerctrlsetpalette"></a><a name="setpalette"></a>CMFCColorPickerCtrl::SetPalette

Define a paleta de cores atual.

```
void SetPalette(CPalette* pPalette);
```

### <a name="parameters"></a>Parâmetros

*Ppalette*<br/>
[em] Ponteiro para uma paleta de cores.

### <a name="remarks"></a>Comentários

A paleta de cores define a matriz de cores que é apresentada no controle do seletor de cores.

## <a name="cmfccolorpickerctrlsetsaturation"></a><a name="setsaturation"></a>CMFCColorPickerCtrl::SetSaturação

Altera a saturação da cor selecionada no momento.

```
void SetSaturation(double Saturation);
```

### <a name="parameters"></a>Parâmetros

*Saturação*<br/>
[em] Um valor de saturação.

### <a name="remarks"></a>Comentários

## <a name="cmfccolorpickerctrlsettype"></a><a name="settype"></a>CMFCColorPickerCtrl::SetType

Define o tipo de controle do seletor de cores para exibir.

```
void SetType(COLORTYPE colorType);
```

### <a name="parameters"></a>Parâmetros

*colorType*<br/>
[em] Um tipo de controle de seletor de cores.

Os tipos são `CMFCColorPickerCtrl::COLORTYPE` definidos pela enumeração. Os tipos possíveis são LUMINANCE, PICKER, HEX e HEX_GREYSCALE. O tipo padrão é PICKER.

### <a name="remarks"></a>Comentários

Para especificar um tipo de controle do seletor de cores, chame este método antes que o controle do Windows seja criado.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)
