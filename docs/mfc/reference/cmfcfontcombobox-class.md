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
ms.openlocfilehash: 69e8f81e7e01d0610f3cbf88ac1725a21d59838f
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505294"
---
# <a name="cmfcfontcombobox-class"></a>Classe CMFCFontComboBox

A `CMFCFontComboBox` classe cria um controle de caixa de combinação que contém uma lista de fontes.

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
|`CMFCFontComboBox::CompareItem`|Chamado pelo Framework para determinar a posição relativa de um novo item na caixa de listagem classificada do controle da caixa de combinação de fonte atual. (Substitui [CComboBox:: CompareItem](../../mfc/reference/ccombobox-class.md#compareitem).)|
|`CMFCFontComboBox::DrawItem`|Chamado pelo Framework para desenhar um item especificado no controle da caixa de combinação de fonte atual. (Substitui [CComboBox::D rawitem](../../mfc/reference/ccombobox-class.md#drawitem).)|
|[CMFCFontComboBox::GetSelFont](#getselfont)|Recupera informações sobre a fonte selecionada no momento.|
|`CMFCFontComboBox::MeasureItem`|Chamado pelo Framework para informar o Windows das dimensões da caixa de listagem no controle da caixa de combinação de fonte atual. (Substitui [CComboBox:: MeasureItem](../../mfc/reference/ccombobox-class.md#measureitem).)|
|`CMFCFontComboBox::PreTranslateMessage`|Traduz mensagens de janela antes de serem expedidas para as funções do Windows [TranslateMessage](/windows/win32/api/winuser/nf-winuser-translatemessage) e [DispatchMessage](/windows/win32/api/winuser/nf-winuser-dispatchmessage) . (Substitui [CWnd::P retranslatemessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|
|[CMFCFontComboBox::SelectFont](#selectfont)|Seleciona a fonte que corresponde aos critérios especificados na caixa de combinação de fontes.|
|[CMFCFontComboBox::Setup](#setup)|Inicializa a lista de itens na caixa de combinação de fontes.|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCFontComboBox::m_bDrawUsingFont](#m_bdrawusingfont)|Indica ao Framework a fonte a ser usada para desenhar os rótulos de item na caixa de combinação de fonte atual.|

## <a name="remarks"></a>Comentários

Para usar um `CMFCFontComboBox` objeto em uma caixa de diálogo, adicione `CMFCFontComboBox` uma variável à classe da caixa de diálogo. Em seguida, `OnInitDialog` no método da classe da caixa de diálogo, chame o método [CMFCFontComboBox:: Setup](#setup) para inicializar a lista de itens no controle da caixa de combinação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CComboBox](../../mfc/reference/ccombobox-class.md)

[CMFCFontComboBox](../../mfc/reference/cmfcfontcombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxfontcombobox. h

##  <a name="cmfcfontcombobox"></a>CMFCFontComboBox::CMFCFontComboBox

Constrói um objeto `CMFCFontComboBox`.

```
CMFCFontComboBox();
```

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="getselfont"></a>  CMFCFontComboBox::GetSelFont

Recupera informações sobre a fonte selecionada no momento.

```
CMFCFontInfo* GetSelFont() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto da [classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md) que descreve uma fonte. Ele poderá ser nulo se nenhuma fonte for selecionada na caixa de combinação.

### <a name="remarks"></a>Comentários

##  <a name="m_bdrawusingfont"></a>  CMFCFontComboBox::m_bDrawUsingFont

Indica ao Framework a fonte a ser usada para desenhar os rótulos de item na caixa de combinação de fonte atual.

```
static BOOL m_bDrawUsingFont;
```

### <a name="remarks"></a>Comentários

Defina esse membro como TRUE para direcionar a estrutura para usar a mesma fonte para desenhar cada rótulo de item. Defina esse membro como FALSE para direcionar a estrutura para desenhar cada rótulo de item com a fonte cujo nome é o mesmo que o rótulo. O valor padrão desse membro é FALSE.

##  <a name="selectfont"></a>CMFCFontComboBox::SelectFont

Seleciona a fonte que corresponde aos critérios especificados na caixa de combinação de fontes.

```
BOOL SelectFont(CMFCFontInfo* pDesc);

BOOL SelectFont(
    LPCTSTR lpszName,
    BYTE nCharSet=DEFAULT_CHARSET);
```

### <a name="parameters"></a>Parâmetros

*pDesc*<br/>
no Aponta para um objeto de descrição de fonte.

*lpszName*<br/>
no Especifica um nome de fonte.

*nCharSet*<br/>
no Especifica um conjunto de caracteres. O valor padrão é DEFAULT_CHARSET. Para obter mais informações, consulte `lfCharSet` o membro da estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) .

### <a name="return-value"></a>Valor de retorno

TRUE se um item na caixa de combinação de fontes corresponder ao objeto de descrição de fonte especificado ou ao nome da fonte e ao conjunto de caracteres; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Use esse método para selecionar e rolar para o item na caixa de combinação de fontes que corresponde à fonte especificada.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `SelectFont` método `CMFCFontComboBox` na classe. Este exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#34](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#35](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_2.cpp)]

##  <a name="setup"></a>CMFCFontComboBox:: instalação

Inicializa a lista de itens na caixa de combinação de fontes.

```
BOOL Setup(
    int nFontType=DEVICE_FONTTYPE|RASTER_FONTTYPE|TRUETYPE_FONTTYPE,
    BYTE nCharSet=DEFAULT_CHARSET,
    BYTE nPitchAndFamily=DEFAULT_PITCH);
```

### <a name="parameters"></a>Parâmetros

*nFontType*<br/>
no Especifica o tipo de fonte. O valor padrão é a combinação de bits (ou) de DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE.

*nCharSet*<br/>
no Especifica o conjunto de caracteres da fonte. O valor padrão é DEFAULT_CHARSET.

*nPitchAndFamily*<br/>
no Especifica a densidade da fonte e a família. O valor padrão é DEFAULT_PITCH.

### <a name="return-value"></a>Valor de retorno

TRUE se a caixa de combinação de fontes tiver sido inicializada com êxito; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Esse método inicializa a caixa de combinação de fontes enumerando as fontes atualmente instaladas que correspondem aos parâmetros especificados e inserindo esses nomes de fonte na caixa de combinação de fontes.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar o `Setup` método `CMFCFontComboBox` na classe. Este exemplo faz parte do [exemplo de novos controles](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_NewControls#34](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_1.h)]
[!code-cpp[NVC_MFC_NewControls#36](../../mfc/reference/codesnippet/cpp/cmfcfontcombobox-class_3.cpp)]

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)<br/>
[Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)
