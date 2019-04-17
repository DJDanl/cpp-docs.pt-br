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
ms.openlocfilehash: 1b9f57e46d5ac74dd52f7ddb7ebd90f8888891e3
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58772745"
---
# <a name="cmfccolordialog-class"></a>Classe CMFCColorDialog

O `CMFCColorDialog` classe representa uma caixa de diálogo de seleção de cor.

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
|[CMFCColorDialog::GetPalette](#getpalette)|Retorna a paleta de cores.|
|`CMFCColorDialog::PreTranslateMessage`|Converte as mensagens da janela antes de serem expedidas para o [TranslateMessage](/windows/desktop/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/desktop/api/winuser/nf-winuser-dispatchmessage) funções do Windows. Para sintaxe e obter mais informações, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CDialogEx::PreTranslateMessage`.)|
|[CMFCColorDialog::RebuildPalette](#rebuildpalette)|Uma paleta deriva da paleta do sistema.|
|[CMFCColorDialog::SetCurrentColor](#setcurrentcolor)|Define a cor selecionada atual.|
|[CMFCColorDialog::SetNewColor](#setnewcolor)|Define a cor mais equivalente a um valor RGB especificado.|
|[CMFCColorDialog::SetPageOne](#setpageone)|Seleciona um valor RGB para a primeira página de propriedade.|
|[CMFCColorDialog::SetPageTwo](#setpagetwo)|Seleciona um valor RGB para a segunda página de propriedade.|

### <a name="protected-data-members"></a>Membros de dados protegidos

|Nome|Descrição|
|----------|-----------------|
|`m_bIsMyPalette`|TRUE se a caixa de diálogo de seleção de cor usa sua própria paleta de cores, ou FALSE se a caixa de diálogo usa uma paleta que é especificada no `CMFCColorDialog` construtor.|
|`m_bPickerMode`|TRUE enquanto o usuário está selecionando uma cor na caixa de diálogo de seleção; Caso contrário, FALSE.|
|`m_btnColorSelect`|O botão de cor que o usuário selecionou.|
|`m_CurrentColor`|A cor atualmente selecionada.|
|`m_hcurPicker`|O cursor é usado para selecionar uma cor.|
|`m_NewColor`|O potencial cor selecionada, que pode ser selecionado permanentemente ou revertido para a cor original.|
|`m_pColourSheetOne`|Um ponteiro para a primeira página de propriedade da folha de propriedades de seleção de cor.|
|`m_pColourSheetTwo`|Um ponteiro para a segunda página de propriedade da folha de propriedades de seleção de cor.|
|`m_pPalette`|A paleta lógica atual.|
|`m_pPropSheet`|Um ponteiro para a folha de propriedades para a caixa de diálogo de seleção de cor.|
|`m_wndColors`|Um objeto de controle de seletor de cor.|
|`m_wndStaticPlaceHolder`|Um controle estático que é um espaço reservado para a folha de propriedades de selecionador de cores.|

## <a name="remarks"></a>Comentários

A caixa de diálogo de seleção de cor é exibida como uma folha de propriedades com duas páginas. Na primeira página, você deve selecionar uma cor padrão na paleta do sistema; na segunda página, você deve selecionar uma cor personalizada.

Você pode construir uma `CMFCColorDialog` do objeto na pilha e, em seguida, chame `DoModal`, passando a cor inicial como um parâmetro para o `CMFCColorDialog` construtor. A caixa de diálogo de seleção de cor, em seguida, cria vários [classe CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md) objetos para lidar com cada paleta de cores.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CDialogEx](../../mfc/reference/cdialogex-class.md)

[CMFCColorDialog](../../mfc/reference/cmfccolordialog-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma caixa de diálogo de cor usando vários métodos no `CMFCColorDialog` classe. O exemplo mostra como definir o atual e as novas cores da caixa de diálogo e como definir os componentes vermelhos, verdes e azuis da cor selecionada nas páginas de propriedades de dois da caixa de diálogo de cor. Este exemplo é parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#3](../../mfc/reference/codesnippet/cpp/cmfccolordialog-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolordialog.h

##  <a name="cmfccolordialog"></a>  CMFCColorDialog::CMFCColorDialog

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
[in] A seleção de cor padrão. Se nenhum valor for especificado, o padrão é RGB(0,0,0) (preto).

*dwFlags*<br/>
[in] Reservado.

*pParentWnd*<br/>
[in] Um ponteiro para a janela do pai ou proprietária da caixa de diálogo.

*hPal*<br/>
[in] Um identificador para uma paleta de cores.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getcolor"></a>  CMFCColorDialog::GetColor

Recupera a cor que o usuário seleciona na caixa de diálogo de cor.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor de retorno

Um [COLORREF](/windows/desktop/gdi/colorref) valor que contém as informações de RGB para a cor selecionada na caixa de diálogo de cor.

### <a name="remarks"></a>Comentários

Chame essa função depois de chamar o `DoModal` método.

##  <a name="getpalette"></a>  CMFCColorDialog::GetPalette

Recupera a paleta de cores que está disponível na caixa de diálogo de cor atual.

```
CPalette* GetPalette() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CPalette` objeto que foi especificado no `CMFCColorDialog` construtor.

### <a name="remarks"></a>Comentários

A paleta de cores Especifica as cores que o usuário pode escolher.

##  <a name="rebuildpalette"></a>  CMFCColorDialog::RebuildPalette

Uma paleta deriva da paleta do sistema.

```
void RebuildPalette();
```

##  <a name="setcurrentcolor"></a>  CMFCColorDialog::SetCurrentColor

Define a cor atual da caixa de diálogo.

```
void SetCurrentColor(COLORREF rgb);
```

### <a name="parameters"></a>Parâmetros

*rgb*<br/>
[in] Um valor de cor RGB

### <a name="remarks"></a>Comentários

##  <a name="setnewcolor"></a>  CMFCColorDialog::SetNewColor

Define a cor atual para a cor na paleta atual que é mais semelhante.

```
void SetNewColor(COLORREF rgb);
```

### <a name="parameters"></a>Parâmetros

*rgb*<br/>
[in] Um [COLORREF](/windows/desktop/gdi/colorref) que especifica uma cor RGB.

### <a name="remarks"></a>Comentários

##  <a name="setpageone"></a>  CMFCColorDialog::SetPageOne

Especifica explicitamente os componentes vermelhos, verdes e azuis da cor selecionada na primeira página de propriedade de uma caixa de diálogo de cor.

```
void SetPageOne(
    BYTE R,
    BYTE G,
    BYTE B);
```

### <a name="parameters"></a>Parâmetros

*R*<br/>
[in] Especifica o componente vermelho do valor RGB.

*G*<br/>
[in] Especifica o componente verde do valor RGB.

*B*<br/>
[in] Especifica o componente azul do valor RGB.

### <a name="remarks"></a>Comentários

##  <a name="setpagetwo"></a>  CMFCColorDialog::SetPageTwo

Especifica explicitamente os componentes vermelhos, verdes e azuis da cor selecionada na segunda página de propriedade de uma caixa de diálogo de cor.

```
void SetPageTwo(
    BYTE R,
    BYTE G,
    BYTE B);
```

### <a name="parameters"></a>Parâmetros

*R*<br/>
[in] Especifica um componente vermelho do valor RGB

*G*<br/>
[in] Especifica um componente verde de um valor RGB

*B*<br/>
[in] Especifica um componente azul de um valor RGB

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md)
