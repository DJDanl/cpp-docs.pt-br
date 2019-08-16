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
ms.openlocfilehash: 7e19fc9257c1fe986ff09a8bbc86bf2fb55af7ee
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504738"
---
# <a name="cmfctoolbarfontcombobox-class"></a>Classe CMFCToolBarFontComboBox

Um botão da barra de ferramentas que contém um controle de caixa de combinação que permite ao usuário selecionar uma fonte em uma lista de fontes do sistema.

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
|[CMFCToolBarFontComboBox::GetFontDesc](#getfontdesc)|Retorna um ponteiro para o `CMFCFontInfo` objeto de um índice especificado na caixa de combinação.|
|[CMFCToolBarFontComboBox::SetFont](#setfont)|Seleciona uma fonte na caixa de combinação de fontes de acordo com o nome da fonte ou o prefixo e o conjunto de caracteres da fonte.|

### <a name="data-members"></a>Membros de Dados

[CMFCToolBarFontComboBox::m_nFontHeight](#m_nfontheight)<br/>
A altura dos caracteres na caixa de combinação de fontes.

## <a name="remarks"></a>Comentários

Para adicionar um botão da caixa de combinação de fonte a uma barra de ferramentas, siga estas etapas:

1. Reserve uma ID de recurso fictícia para o botão no recurso de barra de ferramentas pai.

1. Construa um `CMFCToolBarFontComboBox` objeto.

1. No manipulador de mensagens que processa a mensagem AFX_WM_RESETTOOLBAR, substitua o botão original pelo novo botão de caixa de combinação usando [CMFCToolBar:: ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton).

1. Sincronize a fonte selecionada na caixa de combinação com a fonte no documento usando o método [CMFCToolBarFontComboBox:: SetFont](#setfont) .

Para sincronizar a fonte do documento com a fonte selecionada na caixa de combinação, use o método [CMFCToolBarFontComboBox:: GetFontDesc](#getfontdesc) para recuperar os atributos da fonte selecionada e use esses atributos para criar um objeto de [classe CFont](../../mfc/reference/cfont-class.md) .

O botão da caixa de combinação de fontes chama a função do Win32 [EnumFontFamiliesEx](/windows/win32/api/wingdi/nf-wingdi-enumfontfamiliesexw) para determinar as fontes de tela e impressora disponíveis para o sistema.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)

[CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)

[CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarfontcombobox. h

##  <a name="cmfctoolbarfontcombobox"></a>CMFCToolBarFontComboBox::CMFCToolBarFontComboBox

Constrói um objeto [CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md) .

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

*uiID*<br/>
no A ID de comando da caixa de combinação.

*iImage*<br/>
no O índice de base zero de uma imagem de barra de ferramentas. A imagem está localizada no objeto de [Classe CMFCToolBarImages](../../mfc/reference/cmfctoolbarimages-class.md) que a classe de [Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md) mantém.

*nFontType*<br/>
no Os tipos de fontes que a caixa de combinação contém. Esse parâmetro pode ser uma combinação (booliana ou) dos seguintes valores:

DEVICE_FONTTYPE

RASTER_FONTTYPE

TRUETYPE_FONTTYPE

*nCharSet*<br/>
no Se definido como DEFAULT_CHARSET, a caixa de combinação contém todas as fontes exclusivamente nomeadas em todos os conjuntos de caracteres. (Se houver duas fontes com o mesmo nome, a caixa de combinação conterá uma delas.) Se definido como um valor de conjunto de caracteres válido, a caixa de combinação conterá apenas fontes no conjunto de caracteres especificado. Consulte [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) para obter uma lista de possíveis conjuntos de caracteres.

*dwStyle*<br/>
no O estilo da caixa de combinação. (consulte [estilos de caixa de combinação](../../mfc/reference/styles-used-by-mfc.md#combo-box-styles))

*iWidth*<br/>
no A largura em pixels do controle de edição.

*nPitchAndFamily*<br/>
no Se definido como DEFAULT_PITCH, a caixa de combinação conterá fontes independentemente de pitch. Se definido como FIXED_PITCH ou VARIABLE_PITCH, a caixa de combinação contém apenas fontes com esse tipo de timbre. Atualmente, não há suporte para a filtragem com base na família de fontes.

*pLstFontsExternal*<br/>
fora Ponteiro para um objeto de [classe CObList](../../mfc/reference/coblist-class.md) que armazena as fontes disponíveis.

### <a name="remarks"></a>Comentários

Normalmente, `CMFCToolBarFontComboBox` os objetos armazenam a lista de fontes disponíveis em um `CObList` único objeto compartilhado. Se você usar a segunda sobrecarga do construtor e fornecer um ponteiro válido para *pLstFontsExternal*, esse `CMFCToolBarFontComboBox` objeto preencherá, em vez disso, o *pLstFontsExternal* aponta para com as `CObList` fontes disponíveis.

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como construir um `CMFCToolBarFontComboBox` objeto. Este trecho de código faz parte do [exemplo do Word pad](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_WordPad#7](../../mfc/reference/codesnippet/cpp/cmfctoolbarfontcombobox-class_1.cpp)]

##  <a name="getfontdesc"></a>  CMFCToolBarFontComboBox::GetFontDesc

Retorna um ponteiro para o `CMFCFontInfo` objeto de um índice especificado na caixa de combinação.

```
const CMFCFontInfo* GetFontDesc(int iIndex=-1) const;
```

### <a name="parameters"></a>Parâmetros

*iIndex*<br/>
no Especifica o índice de base zero de um item da caixa de combinação.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CMFCFontInfo` objeto. Se *iIndex* não especificar um índice de item válido, o valor de retorno será nulo.

##  <a name="m_nfontheight"></a>  CMFCToolBarFontComboBox::m_nFontHeight

Especifica a altura, em pixels, de caracteres na caixa de combinação de fontes se a caixa de combinação tiver o estilo de desenho proprietário.

```
static int m_nFontHeight
```

### <a name="remarks"></a>Comentários

Se a `m_nFontHeight` variável for 0, a altura será calculada automaticamente de acordo com a fonte padrão da caixa de combinação. A altura inclui a ascendente de caracteres acima da linha de base e a descendente de caracteres abaixo da linha de base.

##  <a name="setfont"></a>CMFCToolBarFontComboBox:: SetFont

Seleciona a fonte na caixa de combinação de fontes de acordo com o nome da fonte e o conjunto de caracteres especificados nos parâmetros.

```
BOOL SetFont(
    LPCTSTR lpszName,
    BYTE nCharSet=DEFAULT_CHARSET,
    BOOL bExact=FALSE);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
no Especifica o nome ou o prefixo da fonte.

*nCharSet*<br/>
no Especifica o conjunto de caracteres.

*bExact*<br/>
no Especifica se *lpszName* contém o nome da fonte ou o prefixo da fonte.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fonte foi selecionada com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se *bExact* for true, esse método selecionará uma fonte que corresponda exatamente ao nome que você especificou como *lpszName*. Se *bExact* for false, esse método selecionará uma fonte que começa com o texto especificado como *lpszName* e que usa o conjunto de caracteres que você especificou como *nCharSet*. Se *nCharSet* for definido como DEFAULT_CHARSET, o conjunto de caracteres será ignorado e somente *lpszName* será usado para selecionar uma fonte.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBar](../../mfc/reference/cmfctoolbar-class.md)<br/>
[Classe CMFCToolBarButton](../../mfc/reference/cmfctoolbarbutton-class.md)<br/>
[Classe CMFCToolBarComboBoxButton](../../mfc/reference/cmfctoolbarcomboboxbutton-class.md)<br/>
[Classe CMFCFontInfo](../../mfc/reference/cmfcfontinfo-class.md)<br/>
[CMFCToolBar::ReplaceButton](../../mfc/reference/cmfctoolbar-class.md#replacebutton)<br/>
[Passo a passo: colocar controles em barras de ferramentas](../../mfc/walkthrough-putting-controls-on-toolbars.md)
