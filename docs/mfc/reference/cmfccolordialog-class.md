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
ms.openlocfilehash: 987e4f1e5e89c3c56b58adaad76cfd23d5e26c52
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367716"
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
|[CMFCColorDialog::getColor](#getcolor)|Retorna a cor selecionada atual.|
|[CMFCColorDialog::GetPalette](#getpalette)|Retorna a paleta de cores.|
|`CMFCColorDialog::PreTranslateMessage`|Traduz mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. Para obter sintaxe e mais informações, consulte [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage). (Substitui `CDialogEx::PreTranslateMessage`.)|
|[CMFCColorDialog::RebuildPalette](#rebuildpalette)|Deriva uma paleta da paleta do sistema.|
|[CMFCColorDialog::setCurrentColor](#setcurrentcolor)|Define a cor selecionada atual.|
|[CMFCColorDialog::setNewColor](#setnewcolor)|Define a cor mais equivalente a um valor RGB especificado.|
|[CMFCColordialog::setPageOne](#setpageone)|Seleciona um valor RGB para a primeira página de propriedade.|
|[CMFCColorDialog::SetPageTwo](#setpagetwo)|Seleciona um valor RGB para a segunda página de propriedade.|

### <a name="protected-data-members"></a>Membros de Dados Protegidos

|Nome|Descrição|
|----------|-----------------|
|`m_bIsMyPalette`|TRUE se a caixa de diálogo de seleção de cores usar sua própria `CMFCColorDialog` paleta de cores ou FALSA se a caixa de diálogo usar uma paleta especificada no construtor.|
|`m_bPickerMode`|TRUE enquanto o usuário estiver selecionando uma cor na caixa de diálogo de seleção; caso contrário, FALSE.|
|`m_btnColorSelect`|O botão de cor que o usuário selecionou.|
|`m_CurrentColor`|A cor atualmente selecionada.|
|`m_hcurPicker`|O cursor que é usado para escolher uma cor.|
|`m_NewColor`|A cor selecionada prospectiva, que pode ser permanentemente selecionada ou revertida para a cor original.|
|`m_pColourSheetOne`|Um ponteiro para a primeira página de propriedade da folha de propriedade de seleção de cores.|
|`m_pColourSheetTwo`|Um ponteiro para a segunda página de propriedade da folha de propriedade de seleção de cores.|
|`m_pPalette`|A paleta lógica atual.|
|`m_pPropSheet`|Um ponteiro para a folha de propriedades para a caixa de diálogo de seleção de cores.|
|`m_wndColors`|Um objeto de controle de seletor de cores.|
|`m_wndStaticPlaceHolder`|Um controle estático que é um espaço reservado para a folha de propriedade do seletor de cores.|

## <a name="remarks"></a>Comentários

A caixa de diálogo de seleção de cores é exibida como uma folha de propriedade com duas páginas. Na primeira página, você seleciona uma cor padrão na paleta do sistema; na segunda página, você seleciona uma cor personalizada.

Você pode `CMFCColorDialog` construir um objeto na `DoModal`pilha e, em seguida, `CMFCColorDialog` chamar , passando a cor inicial como um parâmetro para o construtor. A caixa de diálogo de seleção de cores cria vários objetos [CMFCColorPickerCtrl Class](../../mfc/reference/cmfccolorpickerctrl-class.md) para lidar com cada paleta de cores.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cdialogex](../../mfc/reference/cdialogex-class.md)

[Cmfccolordialog](../../mfc/reference/cmfccolordialog-class.md)

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como configurar uma caixa `CMFCColorDialog` de diálogo de cores usando vários métodos na classe. O exemplo mostra como definir a corrente e as novas cores da caixa de diálogo e como definir os componentes vermelho, verde e azul de uma cor selecionada nas duas páginas de propriedade da caixa de diálogo de cor. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#3](../../mfc/reference/codesnippet/cpp/cmfccolordialog-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcolordialog.h

## <a name="cmfccolordialogcmfccolordialog"></a><a name="cmfccolordialog"></a>CMFCColorDialog::CMFCColorDialog

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
[em] A seleção padrão de cores. Se nenhum valor for especificado, o padrão será RGB(0,0,0) (preto).

*dwFlags*<br/>
[in] Reservado.

*Pparentwnd*<br/>
[em] Um ponteiro para a janela pai ou proprietário da caixa de diálogo.

*hPal*<br/>
[em] Uma alça para uma paleta de cores.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfccolordialoggetcolor"></a><a name="getcolor"></a>CMFCColorDialog::getColor

Recupera a cor que o usuário seleciona na caixa de diálogo de cor.

```
COLORREF GetColor() const;
```

### <a name="return-value"></a>Valor retornado

Um [valor COLORREF](/windows/win32/gdi/colorref) que contém as informações RGB para a cor selecionada na caixa de diálogo de cor.

### <a name="remarks"></a>Comentários

Ligue para esta função `DoModal` depois de chamar o método.

## <a name="cmfccolordialoggetpalette"></a><a name="getpalette"></a>CMFCColorDialog::GetPalette

Recupera a paleta de cores disponível na caixa de diálogo de cores atual.

```
CPalette* GetPalette() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `CPalette` para o objeto que `CMFCColorDialog` foi especificado na construtora.

### <a name="remarks"></a>Comentários

A paleta de cores especifica as cores que o usuário pode escolher.

## <a name="cmfccolordialogrebuildpalette"></a><a name="rebuildpalette"></a>CMFCColorDialog::RebuildPalette

Deriva uma paleta da paleta do sistema.

```
void RebuildPalette();
```

## <a name="cmfccolordialogsetcurrentcolor"></a><a name="setcurrentcolor"></a>CMFCColorDialog::setCurrentColor

Define a cor atual da caixa de diálogo.

```
void SetCurrentColor(COLORREF rgb);
```

### <a name="parameters"></a>Parâmetros

*Rgb*<br/>
[em] Um valor de cor RGB

### <a name="remarks"></a>Comentários

## <a name="cmfccolordialogsetnewcolor"></a><a name="setnewcolor"></a>CMFCColorDialog::setNewColor

Define a cor atual para a cor na paleta atual que é mais semelhante.

```
void SetNewColor(COLORREF rgb);
```

### <a name="parameters"></a>Parâmetros

*Rgb*<br/>
[em] Um [COLORREF](/windows/win32/gdi/colorref) que especifica uma cor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfccolordialogsetpageone"></a><a name="setpageone"></a>CMFCColordialog::setPageOne

Especifica explicitamente os componentes vermelho, verde e azul de uma cor selecionada na primeira página de propriedade de uma caixa de diálogo de cor.

```
void SetPageOne(
    BYTE R,
    BYTE G,
    BYTE B);
```

### <a name="parameters"></a>Parâmetros

*R*<br/>
[em] Especifica o componente vermelho do valor RGB.

*G*<br/>
[em] Especifica o componente verde do valor RGB.

*B*<br/>
[em] Especifica o componente azul do valor RGB.

### <a name="remarks"></a>Comentários

## <a name="cmfccolordialogsetpagetwo"></a><a name="setpagetwo"></a>CMFCColorDialog::SetPageTwo

Especifica explicitamente os componentes vermelho, verde e azul de uma cor selecionada na segunda página de propriedade de uma caixa de diálogo de cor.

```
void SetPageTwo(
    BYTE R,
    BYTE G,
    BYTE B);
```

### <a name="parameters"></a>Parâmetros

*R*<br/>
[em] Especifica um componente vermelho do valor RGB

*G*<br/>
[em] Especifica um componente verde de um valor RGB

*B*<br/>
[em] Especifica um componente azul de um valor RGB

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCColorPickerCtrl](../../mfc/reference/cmfccolorpickerctrl-class.md)
