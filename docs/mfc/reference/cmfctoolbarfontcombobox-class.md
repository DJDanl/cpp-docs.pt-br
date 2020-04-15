---
title: Classe CMFCToolBarFontComboBox
ms.date: 11/04/2016
f1_keywords:
- CMFCToolBarFontComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontComboBox::CMFCToolBarFontComboBox
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontComboBox::GetFontDesc
- AFXTOOLBARFONTCOMBOBOX/CMFCToolBarFontComboBox::SetFont
helpviewer_keywords:
- CMFCToolBarFontComboBox [MFC], CMFCToolBarFontComboBox
- CMFCToolBarFontComboBox [MFC], GetFontDesc
- CMFCToolBarFontComboBox [MFC], SetFont
ms.assetid: 25f8e08c-aadd-4cb5-9581-a99d49d444b1
ms.openlocfilehash: 7b31f4b725a6983171162d9805d08224ad787808
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360459"
---
# <a name="cmfctoolbarfontcombobox-class"></a>Classe CMFCToolBarFontComboBox

Um botão de barra de ferramentas que contém um controle de caixa de combinação que permite ao usuário selecionar uma fonte de uma lista de fontes do sistema.

## <a name="syntax"></a>Sintaxe

```
class CMFCToolBarFontComboBox : public CMFCToolBarComboBoxButton
```

## <a name="members"></a>Membros

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarFontComboBox::CMFCToolBarFontComboBox](#cmfctoolbarfontcombobox)|Constrói um objeto `CMFCToolBarFontComboBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCToolBarFontComboBox::GetFontDesc](#getfontdesc)|Retorna um ponteiro `CMFCFontInfo` ao objeto para um índice especificado na caixa de combinação.|
|[CMFCToolBarFontComboBox::SetFont](#setfont)|Seleciona uma fonte na caixa de combinação de fontes de acordo com o nome da fonte ou o prefixo e o conjunto de caracteres da fonte.|

### <a name="data-members"></a>Membros de dados

[CMFCToolBarFontComboBox::m_nFontHeight](#m_nfontheight)<br/>
A altura dos caracteres na caixa de combinação de fontes.

## <a name="remarks"></a>Comentários

Para adicionar um botão de caixa de combinação de fonte a uma barra de ferramentas, siga estas etapas:

1. Reserve um ID de recurso de boneco para o botão no recurso da barra de ferramentas pai.

1. Construa `CMFCToolBarFontComboBox` um objeto.

1. No manipulador de mensagens que processa a mensagem AFX_WM_RESETTOOLBAR, substitua o botão original pelo novo botão de caixa de combinação usando [CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).

1. Sincronize a fonte selecionada na caixa de combinação com a fonte no documento usando o [método CMFCToolBarFontComboBox::SetFont](#setfont) method.

Para sincronizar a fonte do documento com a fonte selecionada na caixa de combinação, use o método [CMFCToolBarFontComboBox::GetFontDesc](#getfontdesc) method to recuperar os atributos da fonte selecionada e usar esses atributos para criar um objeto [CFont Class.](../../mfc/reference/cfont-class.md)

O botão de caixa de combinação de fontes chama a função Win32 [EnumFontFamiliesEx](/windows/win32/api/wingdi/nf-wingdi-enumfontfamiliesexw) para determinar as fontes de tela e impressora disponíveis para o sistema.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfctoolbarbutton](../../mfc/reference/cmfctoolbarbutton-class.md)

[Cmfctoolbarcomboboxbutton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)

[Cmfctoolbarfontcombobox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarfontcombobox.h

## <a name="cmfctoolbarfontcomboboxcmfctoolbarfontcombobox"></a><a name="cmfctoolbarfontcombobox"></a>CMFCToolBarFontComboBox::CMFCToolBarFontComboBox

Constrói um objeto [CMFCToolBarFontComboBox.](../../mfc/reference/cmfctoolbarfontcombobox-class.md)

```
public:
CMFCToolBarFontComboBox(
    UINT uiID,
    int iImage,
    int nFontType = DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE,
    BYTE nCharSet = DEFAULT_CHARSET,
    DWORD dwStyle = CBS_DROPDOWN,
    int iWidth = 0,
    BYTE nPitchAndFamily = DEFAULT_PITCH);

protected:
CMFCToolBarFontComboBox(
    CObList* pLstFontsExternal,
    int nFontType,
    BYTE nCharSet,
    BYTE nPitchAndFamily);

CMFCToolBarFontComboBox();
```

### <a name="parameters"></a>Parâmetros

*Uiid*<br/>
[em] O id de comando da caixa de combinação.

*Iimage*<br/>
[em] O índice baseado em zero de uma imagem de barra de ferramentas. A imagem está localizada no objeto [CMFCToolBarImages Class](../../mfc/reference/cmfctoolbarimages-class.md) que a classe [CMFCToolBar class](../../mfc/reference/cmfctoolbar-class.md) mantém.

*nFontType*<br/>
[em] Os tipos de fontes que a caixa de combinação contém. Este parâmetro pode ser uma combinação (booleana OR) dos seguintes valores:

Device_fonttype

RASTER_FONTTYPE

Truetype_fonttype

*nCharSet*<br/>
[em] Se definido para DEFAULT_CHARSET, a caixa de combinação contém todas as fontes com nome exclusivo em todos os conjuntos de caracteres. (Se houver duas fontes com o mesmo nome, a caixa de combinação contém uma delas.) Se definido como um valor definido de caractere válido, a caixa de combinação contém apenas fontes no conjunto de caracteres especificado. Consulte [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) para obter uma lista de possíveis conjuntos de caracteres.

*Dwstyle*<br/>
[em] O estilo da caixa de combinação. (veja [Estilos combo-box)](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles)

*iWidth*<br/>
[em] A largura em pixels do controle de edição.

*nPitchAndFamily*<br/>
[em] Se definido para DEFAULT_PITCH, a caixa de combinação contém fontes independentemente do tom. Se definido para FIXED_PITCH ou VARIABLE_PITCH, a caixa de combinação contém apenas fontes com esse tipo de pitch. A filtragem com base na família de fontes não é suportada no momento.

*pLstFontsExterno*<br/>
[fora] Pointer para um objeto [CObList Class](../../mfc/reference/coblist-class.md) que armazena as fontes disponíveis.

### <a name="remarks"></a>Comentários

Normalmente, `CMFCToolBarFontComboBox` os objetos armazenam a lista `CObList` de fontes disponíveis em um único objeto compartilhado. Se você usar a segunda sobrecarga do construtor e fornecer um ponteiro `CMFCToolBarFontComboBox` válido para *pLstFontsExterno,* esse objeto preencherá os `CObList` pontos externos que *pLstFonts externos* com fontes disponíveis.

### <a name="example"></a>Exemplo

O exemplo a seguir `CMFCToolBarFontComboBox` demonstra como construir um objeto. Este trecho de código faz parte da amostra do [Word Pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#7](../../mfc/reference/codesnippet/cpp/cmfctoolbarfontcombobox-class_1.cpp)]

## <a name="cmfctoolbarfontcomboboxgetfontdesc"></a><a name="getfontdesc"></a>CMFCToolBarFontComboBox::GetFontDesc

Retorna um ponteiro `CMFCFontInfo` ao objeto para um índice especificado na caixa de combinação.

```
const CMFCFontInfo* GetFontDesc(int iIndex=-1) const;
```

### <a name="parameters"></a>Parâmetros

*Iindex*<br/>
[em] Especifica o índice baseado em zero de um item de caixa de combinação.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CMFCFontInfo`. Se *o iIndex* não especificar um índice de item válido, o valor de retorno será NULO.

## <a name="cmfctoolbarfontcomboboxm_nfontheight"></a><a name="m_nfontheight"></a>CMFCToolBarFontComboBox::m_nFontHeight

Especifica a altura, em pixels, dos caracteres na caixa de combinação de fontes se a caixa de combinação tiver estilo de desenho do proprietário.

```
static int m_nFontHeight
```

### <a name="remarks"></a>Comentários

Se `m_nFontHeight` a variável for 0, a altura é calculada automaticamente de acordo com a fonte padrão da caixa de combinação. A altura inclui tanto a ascensão de caracteres acima da linha de base quanto a descida de caracteres abaixo da linha de base.

## <a name="cmfctoolbarfontcomboboxsetfont"></a><a name="setfont"></a>CMFCToolBarFontComboBox::SetFont

Seleciona a fonte na caixa de combinação de fontes de acordo com o nome da fonte e o conjunto de caracteres especificados nos parâmetros.

```
BOOL SetFont(
    LPCTSTR lpszName,
    BYTE nCharSet=DEFAULT_CHARSET,
    BOOL bExact=FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
[em] Especifica o nome da fonte ou prefixo.

*nCharSet*<br/>
[em] Especifica o conjunto de caracteres.

*bExact*<br/>
[em] Especifica se *lpszName* contém o nome da fonte ou o prefixo da fonte.

### <a name="return-value"></a>Valor retornado

Não zero se a fonte foi selecionada com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bExact* for TRUE, este método selecionará uma fonte que corresponda exatamente ao nome que você especificou como *lpszName*. Se *bExact* for FALSE, este método selecionará uma fonte que começa com o texto especificado como *lpszName* e que usa o conjunto de caracteres que você especificou como *nCharSet*. Se *nCharSet* estiver definido como DEFAULT_CHARSET, o conjunto de caracteres será ignorado e apenas *lpszName* será usado para selecionar uma fonte.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[CMFCToolBarComboBoxClasse de botão](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)<br/>
[Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)<br/>
[CMFCToolBar::Substituir botão](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Instruções passo a passo: colocando controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
