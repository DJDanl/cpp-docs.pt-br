---
title: Classe CMFCColorDialog
ms.date: 11/04/2016
f1_keywords:
- CMFCColorDialog
- AFXCOLORDIALOG/CMFCColorDialog
- AFXCOLORDIALOG/CMFCColorDialog::CMFCColorDialog
- AFXCOLORDIALOG/CMFCColorDialog::GetColor
- AFXCOLORDIALOG/CMFCColorDialog::GetPalette
- AFXCOLORDIALOG/CMFCColorDialog::RebuildPalette
- AFXCOLORDIALOG/CMFCColorDialog::SetCurrentColor
- AFXCOLORDIALOG/CMFCColorDialog::SetNewColor
- AFXCOLORDIALOG/CMFCColorDialog::SetPageOne
- AFXCOLORDIALOG/CMFCColorDialog::SetPageTwo
helpviewer_keywords:
- CMFCColorDialog [MFC], CMFCColorDialog
- CMFCColorDialog [MFC], GetColor
- CMFCColorDialog [MFC], GetPalette
- CMFCColorDialog [MFC], RebuildPalette
- CMFCColorDialog [MFC], SetCurrentColor
- CMFCColorDialog [MFC], SetNewColor
- CMFCColorDialog [MFC], SetPageOne
- CMFCColorDialog [MFC], SetPageTwo
ms.assetid: 235bbbbc-a3b1-46e0-801b-fb55093ec579
ms.openlocfilehash: 9e018c122cded09e5366c3b349525fa7cc004897
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505334"
---
# <a name="cmfccolordialog-class"></a>Classe CMFCColorDialog

A `CMFCColorDialog` classe representa uma caixa de diálogo de seleção de cores.

## <a name="syntax"></a>Sintaxe

```
class CMFCColorDialog : public CDialogEx
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorDialog::CMFCColorDialog](#cmfccolordialog)|Constrói um objeto `CMFCColorDialog`.|
|`CMFCColorDialog::~CMFCColorDialog`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCColorDialog::GetColor](#getcolor)|Retorna a cor selecionada atual.|
|[CMFCColorDialog::GetPalette](#getpalette)|Retorna a paleta da cor.|
|`CMFCColorDialog::PreTranslateMessage`|Traduz mensagens de janela antes de serem expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) . Para obter a sintaxe e obter mais informações, consulte [CWnd::P retranslatemessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CDialogEx::PreTranslateMessage`.)|
|[CMFCColorDialog::RebuildPalette](#rebuildpalette)|Deriva uma paleta da paleta do sistema.|
|[CMFCColorDialog::SetCurrentColor](#setcurrentcolor)|Define a cor selecionada atualmente.|
|[CMFCColorDialog::SetNewColor](#setnewcolor)|Define a cor que é mais equivalente a um valor RGB especificado.|
|[CMFCColorDialog::SetPageOne](#setpageone)|Seleciona um valor RGB para a primeira página de propriedades.|
|[CMFCColorDialog::SetPageTwo](#setpagetwo)|Seleciona um valor RGB para a segunda página de propriedades.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|`m_bIsMyPalette`|TRUE se a caixa de diálogo de seleção de cor usar sua própria paleta de cores ou false se a caixa de diálogo usar uma paleta especificada `CMFCColorDialog` no construtor.|
|`m_bPickerMode`|TRUE enquanto o usuário está selecionando uma cor na caixa de diálogo de seleção; caso contrário, FALSE.|
|`m_btnColorSelect`|O botão de cor que o usuário selecionou.|
|`m_CurrentColor`|A cor selecionada no momento.|
|`m_hcurPicker`|O cursor usado para escolher uma cor.|
|`m_NewColor`|A cor selecionada em potencial, que pode ser permanentemente selecionada ou revertida para a cor original.|
|`m_pColourSheetOne`|Um ponteiro para a primeira página de propriedades da folha de propriedades de seleção de cores.|
|`m_pColourSheetTwo`|Um ponteiro para a segunda página de propriedades da folha de propriedades de seleção de cores.|
|`m_pPalette`|A paleta lógica atual.|
|`m_pPropSheet`|Um ponteiro para a folha de propriedades da caixa de diálogo de seleção de cores.|
|`m_wndColors`|Um objeto de controle do seletor de cores.|
|`m_wndStaticPlaceHolder`|Um controle estático que é um espaço reservado para a folha de propriedades do seletor de cores.|

## <a name="remarks"></a>Comentários

A caixa de diálogo seleção de cor é exibida como uma folha de propriedades com duas páginas. Na primeira página, você seleciona uma cor padrão na paleta do sistema; na segunda página, você seleciona uma cor personalizada.

Você pode construir um `CMFCColorDialog` objeto na pilha e, em seguida `DoModal`, chamar, passando a cor inicial como um parâmetro `CMFCColorDialog` para o construtor. A caixa de diálogo seleção de cor cria vários objetos de [Classe CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md) para lidar com cada paleta de cores.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CDialogEx](../../mfc/reference/cdialogex-class.md)

[CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma caixa de diálogo de cor usando vários métodos `CMFCColorDialog` na classe. O exemplo mostra como definir as cores atual e novas da caixa de diálogo e como definir os componentes vermelho, verde e azul de uma cor selecionada nas duas páginas de propriedades da caixa de diálogo cor. Este exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#3](../../mfc/reference/codesnippet/cpp/cmfccolordialog-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolordialog. h

##  <a name="cmfccolordialog"></a>CMFCColorDialog::CMFCColorDialog

Constrói um objeto `CMFCColorDialog`.

```
CMFCColorDialog(
    COLORREF clrInit=0,
    DWORD dwFlags=0,
    CWnd* pParentWnd=NULL,
    HPALETTE hPal=NULL);
```

### <a name="parameters"></a>Parâmetros

*clrInit*<br/>
no A seleção de cor padrão. Se nenhum valor for especificado, o padrão será RGB (0, 0, 0) (preto).

*dwFlags*<br/>
[in] Reservado.

*pParentWnd*<br/>
no Um ponteiro para a janela pai ou proprietário da caixa de diálogo.

*hPal*<br/>
no Um identificador para uma paleta de cores.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getcolor"></a>CMFCColorDialog:: GetColor

Recupera a cor que o usuário seleciona na caixa de diálogo cor.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um valor de [COLORREF](/windows/win32/gdi/colorref) que contém as informações RGB para a cor selecionada na caixa de diálogo cor.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar o `DoModal` método.

##  <a name="getpalette"></a>CMFCColorDialog:: GetPalette

Recupera a paleta de cores que está disponível na caixa de diálogo cor atual.

```
CPalette* GetPalette() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CPalette` objeto que foi especificado `CMFCColorDialog` no construtor.

### <a name="remarks"></a>Comentários

A paleta de cores especifica as cores que o usuário pode escolher.

##  <a name="rebuildpalette"></a>  CMFCColorDialog::RebuildPalette

Deriva uma paleta da paleta do sistema.

```
void RebuildPalette();
```

##  <a name="setcurrentcolor"></a>CMFCColorDialog::SetCurrentColor

Define a cor atual da caixa de diálogo.

```
void SetCurrentColor(COLORREF rgb);
```

### <a name="parameters"></a>Parâmetros

*rgb*<br/>
no Um valor de cor RGB

### <a name="remarks"></a>Comentários

##  <a name="setnewcolor"></a>CMFCColorDialog::SetNewColor

Define a cor atual como a cor na paleta atual que é mais semelhante.

```
void SetNewColor(COLORREF rgb);
```

### <a name="parameters"></a>Parâmetros

*rgb*<br/>
no Um [COLORREF](/windows/win32/gdi/colorref) que especifica uma cor RGB.

### <a name="remarks"></a>Comentários

##  <a name="setpageone"></a>CMFCColorDialog::SetPageOne

Especifica explicitamente os componentes vermelho, verde e azul de uma cor selecionada na primeira página de propriedades de uma caixa de diálogo de cor.

```
void SetPageOne(
    BYTE R,
    BYTE G,
    BYTE B);
```

### <a name="parameters"></a>Parâmetros

*R*<br/>
no Especifica o componente vermelho do valor RGB.

*G*<br/>
no Especifica o componente verde do valor RGB.

*B*<br/>
no Especifica o componente azul do valor RGB.

### <a name="remarks"></a>Comentários

##  <a name="setpagetwo"></a>CMFCColorDialog::SetPageTwo

Especifica explicitamente os componentes vermelho, verde e azul de uma cor selecionada na segunda página de propriedades de uma caixa de diálogo de cor.

```
void SetPageTwo(
    BYTE R,
    BYTE G,
    BYTE B);
```

### <a name="parameters"></a>Parâmetros

*R*<br/>
no Especifica um componente vermelho do valor RGB

*G*<br/>
no Especifica um componente verde de um valor RGB

*B*<br/>
no Especifica um componente azul de um valor RGB

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md)
