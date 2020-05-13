---
title: Classe CMFCFontComboBox
ms.date: 11/04/2016
f1_keywords:
- CMFCFontComboBox
- AFXFONTCOMBOBOX/CMFCFontComboBox
- AFXFONTCOMBOBOX/CMFCFontComboBox::CMFCFontComboBox
- AFXFONTCOMBOBOX/CMFCFontComboBox::GetSelFont
- AFXFONTCOMBOBOX/CMFCFontComboBox::SelectFont
- AFXFONTCOMBOBOX/CMFCFontComboBox::Setup
- AFXFONTCOMBOBOX/CMFCFontComboBox::m_bDrawUsingFont
helpviewer_keywords:
- CMFCFontComboBox [MFC], CMFCFontComboBox
- CMFCFontComboBox [MFC], GetSelFont
- CMFCFontComboBox [MFC], SelectFont
- CMFCFontComboBox [MFC], Setup
- CMFCFontComboBox [MFC], m_bDrawUsingFont
ms.assetid: 9a53fb0c-7b45-486d-8187-2a4c723d9fbb
ms.openlocfilehash: 60b4b7cdfdace2332de35dd93c43eacf592e99e2
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367498"
---
# <a name="cmfcfontcombobox-class"></a>Classe CMFCFontComboBox

A `CMFCFontComboBox` classe cria um controle de caixa combo que contém uma lista de fontes.

## <a name="syntax"></a>Sintaxe

```
class CMFCFontComboBox : public CComboBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCFontComboBox::CMFCFontComboBox](#cmfcfontcombobox)|Constrói um objeto `CMFCFontComboBox`.|
|`CMFCFontComboBox::~CMFCFontComboBox`|Destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCFontComboBox::CompareItem`|Chamado pelo framework para determinar a posição relativa de um novo item na caixa de lista classificada do controle atual da caixa de combinação de fontes. (Substitui [ccombobox::CompareItem](../../mfc/reference/ccombobox-class.md#compareitem).)|
|`CMFCFontComboBox::DrawItem`|Chamado pelo framework para desenhar um item especificado no controle atual da caixa de combinação de fonte. (Substitui [cComboBox::DrawItem](../../mfc/reference/ccombobox-class.md#drawitem).)|
|[CMFCFontComboBox::GetSelFont](#getselfont)|Recupera informações sobre a fonte selecionada no momento.|
|`CMFCFontComboBox::MeasureItem`|Chamado pela estrutura para informar o Windows das dimensões da caixa de lista no controle atual da caixa de combinação de fontes. (Substitui [ccombobox::MeasureItem](../../mfc/reference/ccombobox-class.md#measureitem).)|
|`CMFCFontComboBox::PreTranslateMessage`|Traduz mensagens de janela antes de serem enviadas para as funções [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) Windows. (Substitui [cwnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCFontComboBox::SelectFont](#selectfont)|Seleciona a fonte que corresponde aos critérios especificados da caixa de combinação de fontes.|
|[CMFCFontComboBox::Configuração](#setup)|Inicializa a lista de itens na caixa de combinação de fontes.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCFontComboBox::m_bDrawUsingFont](#m_bdrawusingfont)|Indica para a estrutura qual fonte usar para desenhar os rótulos do item na caixa de combinação de fonte atual.|

## <a name="remarks"></a>Comentários

Para usar `CMFCFontComboBox` um objeto em uma `CMFCFontComboBox` caixa de diálogo, adicione uma variável à classe caixa de diálogo. Em seguida, no `OnInitDialog` método da classe caixa de diálogo, chame o método [CMFCFontComboBox::Configuração](#setup) para inicializar a lista de itens no controle da caixa de combinação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CComboBox](../../mfc/reference/ccombobox-class.md)

[Cmfcfontcombobox](../../mfc/reference/cmfcfontcombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxfontcombobox.h

## <a name="cmfcfontcomboboxcmfcfontcombobox"></a><a name="cmfcfontcombobox"></a>CMFCFontComboBox::CMFCFontComboBox

Constrói um objeto `CMFCFontComboBox`.

```
CMFCFontComboBox();
```

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcfontcomboboxgetselfont"></a><a name="getselfont"></a>CMFCFontComboBox::GetSelFont

Recupera informações sobre a fonte selecionada no momento.

```
CMFCFontInfo* GetSelFont() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto [CMFCFontInfo Class](../../mfc/reference/cmfcfontinfo-class.md) que descreve uma fonte. Ele pode ser NULO se nenhuma fonte for selecionada na caixa de combinação.

### <a name="remarks"></a>Comentários

## <a name="cmfcfontcomboboxm_bdrawusingfont"></a><a name="m_bdrawusingfont"></a>CMFCFontComboBox::m_bDrawUsingFont

Indica para a estrutura qual fonte usar para desenhar os rótulos do item na caixa de combinação de fonte atual.

```
static BOOL m_bDrawUsingFont;
```

### <a name="remarks"></a>Comentários

Defina este membro como TRUE para direcionar a estrutura para usar a mesma fonte para desenhar cada rótulo de item. Defina este membro como FALSE para direcionar a estrutura para desenhar cada rótulo de item com a fonte cujo nome é o mesmo que o rótulo. O valor padrão deste membro é FALSO.

## <a name="cmfcfontcomboboxselectfont"></a><a name="selectfont"></a>CMFCFontComboBox::SelectFont

Seleciona a fonte que corresponde aos critérios especificados da caixa de combinação de fontes.

```
BOOL SelectFont(CMFCFontInfo* pDesc);

BOOL SelectFont(
    LPCTSTR lpszName,
    BYTE nCharSet=DEFAULT_CHARSET);
```

### <a name="parameters"></a>Parâmetros

*pDesc*<br/>
[em] Aponta para um objeto de descrição da fonte.

*lpszName*<br/>
[em] Especifica um nome de fonte.

*nCharSet*<br/>
[em] Especifica um conjunto de caracteres. O valor padrão é DEFAULT_CHARSET. Para obter mais `lfCharSet` informações, consulte o membro da estrutura [LOGFONT.](/windows/win32/api/wingdi/ns-wingdi-logfontw)

### <a name="return-value"></a>Valor retornado

TRUE se um item na caixa de combinação de fontes corresponder ao objeto de descrição da fonte especificado ou nome da fonte e charset; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use este método para selecionar e rolar até o item na caixa de combinação de fontes que corresponde à fonte especificada.

### <a name="example"></a>Exemplo

O exemplo a seguir `SelectFont` demonstra como `CMFCFontComboBox` usar o método na classe. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#34](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#35](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_2.cpp)]

## <a name="cmfcfontcomboboxsetup"></a><a name="setup"></a>CMFCFontComboBox::Configuração

Inicializa a lista de itens na caixa de combinação de fontes.

```
BOOL Setup(
    int nFontType=DEVICE_FONTTYPE|RASTER_FONTTYPE|TRUETYPE_FONTTYPE,
    BYTE nCharSet=DEFAULT_CHARSET,
    BYTE nPitchAndFamily=DEFAULT_PITCH);
```

### <a name="parameters"></a>Parâmetros

*nFontType*<br/>
[em] Especifica o tipo de fonte. O valor padrão é a combinação bitwise (OR) de DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE.

*nCharSet*<br/>
[em] Especifica o conjunto de caracteres da fonte. O valor padrão é DEFAULT_CHARSET.

*nPitchAndFamily*<br/>
[em] Especifica o tom de fonte e a família. O valor padrão é DEFAULT_PITCH.

### <a name="return-value"></a>Valor retornado

TRUE se a caixa de combinação de fontes foi inicializada com sucesso; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Este método inicializa a caixa de combinação de fontes enumerando as fontes instaladas no momento que correspondem aos parâmetros especificados e inserindo esses nomes de fonte na caixa de combinação de fontes.

### <a name="example"></a>Exemplo

O exemplo a seguir `Setup` demonstra como `CMFCFontComboBox` usar o método na classe. Este exemplo faz parte da [amostra Novos Controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#34](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#36](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_3.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)<br/>
[Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)
