---
title: Classe CMFCRibbonFontComboBox
ms.date: 11/04/2016
f1_keywords:
- CMFCRibbonFontComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::CMFCRibbonFontComboBox
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::BuildFonts
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::GetCharSet
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::GetFontDesc
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::GetFontType
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::GetPitchAndFamily
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::RebuildFonts
- AFXRIBBONCOMBOBOX/CMFCRibbonFontComboBox::SetFont
helpviewer_keywords:
- CMFCRibbonFontComboBox [MFC], CMFCRibbonFontComboBox
- CMFCRibbonFontComboBox [MFC], BuildFonts
- CMFCRibbonFontComboBox [MFC], GetCharSet
- CMFCRibbonFontComboBox [MFC], GetFontDesc
- CMFCRibbonFontComboBox [MFC], GetFontType
- CMFCRibbonFontComboBox [MFC], GetPitchAndFamily
- CMFCRibbonFontComboBox [MFC], RebuildFonts
- CMFCRibbonFontComboBox [MFC], SetFont
ms.assetid: 33b4db50-df4f-45fa-8f05-2e6e73c31435
ms.openlocfilehash: 822f4f6fe76bb5b82b455daec54ed96568ea6ba7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375161"
---
# <a name="cmfcribbonfontcombobox-class"></a>Classe CMFCRibbonFontComboBox

Implementa uma caixa de combinação que contém uma lista de fontes. Você coloca a caixa de combinação em um painel de fita.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonFontComboBox : public CMFCRibbonComboBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCRibbonFontComboBox::~CMFCRibbonFontComboBox`|Destruidor.|

### <a name="protected-constructors"></a>Construtores Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonFontComboBox::CMFCRibbonFontComboBox](#cmfcribbonfontcombobox)|Constrói e inicializa um objeto `CMFCRibbonFontComboBox`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCRibbonFontComboBox::BuildFonts](#buildfonts)|Preenche a caixa de combinação de fonte de fita com fontes do tipo de fonte especificado, conjunto de caracteres e pitch e família.|
|`CMFCRibbonFontComboBox::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCRibbonFontComboBox::GetCharSet](#getcharset)|Retorna o conjunto de caracteres especificado.|
|[CMFCRibbonFontComboBox::GetFontDesc](#getfontdesc)||
|[CMFCRibbonFontComboBox::GetFontType](#getfonttype)|Retorna quais tipos de fonte a serem exibidos na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE, ou qualquer combinação bitwise dele.|
|[CMFCRibbonFontComboBox::GetPitchAndFamily](#getpitchandfamily)|Retorna o pitch e a família das fontes que são exibidas na caixa de combinação.|
|`CMFCRibbonFontComboBox::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a este tipo de classe.|
|[CMFCRibbonFontComboBox::RebuildFonts](#rebuildfonts)|Preenche a caixa de combinação de fonte de fita com fontes do tipo de fonte especificado anteriormente, conjunto de caracteres e pitch e família.|
|[CMFCRibbonFontComboBox::SetFont](#setfont)|Seleciona a fonte especificada na caixa de combinação.|

## <a name="remarks"></a>Comentários

Depois de `CMFCRibbonFontComboBox` criar um objeto, adicione-o a um painel de fita chamando [CMFCRibbonPanel::Adicionar](../../mfc/reference/cmfcribbonpanel-class.md#add).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cmfcribbonbaseelement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[Cmfcribbonbutton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)

[Cmfcribboncombobox](../../mfc/reference/cmfcribboncombobox-class.md)

[Cmfcribbonfontcombobox](../../mfc/reference/cmfcribbonfontcombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonComboBox.h

## <a name="cmfcribbonfontcomboboxbuildfonts"></a><a name="buildfonts"></a>CMFCRibbonFontComboBox::BuildFonts

Preenche a caixa de combinação na fita com fontes.

```
void BuildFonts(
    int nFontType = DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE,
    BYTE nCharSet = DEFAULT_CHARSET,
    BYTE nPitchAndFamily = DEFAULT_PITCH);
```

### <a name="parameters"></a>Parâmetros

*nFontType*<br/>
[em] Especifica o tipo de fonte das fontes a serem adicionadas.

*nCharSet*<br/>
[em] Especifica o conjunto de caracteres das fontes a serem adicionados.

*nPitchAndFamily*<br/>
[em] Especifica o tom e a família das fontes a serem adicionados.

## <a name="cmfcribbonfontcomboboxcmfcribbonfontcombobox"></a><a name="cmfcribbonfontcombobox"></a>CMFCRibbonFontComboBox::CMFCRibbonFontComboBox

Constrói e inicializa um objeto [CMFCRibbonFontComboBox.](../../mfc/reference/cmfcribbonfontcombobox-class.md)

```
CMFCRibbonFontComboBox(
    UINT nID,
    int nFontType = DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE,
    BYTE nCharSet = DEFAULT_CHARSET,
    BYTE nPitchAndFamily = DEFAULT_PITCH,
    int nWidth = -1);
```

### <a name="parameters"></a>Parâmetros

*nID*<br/>
[em] O ID de comando do comando que é executado quando o usuário seleciona um item na caixa de combinação.

*nFontType*<br/>
[em] Especifica quais tipos de fonte a serem exibidos na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE, ou qualquer combinação bitwise dele.

*nCharSet*<br/>
[em] Filtra as fontes na caixa de combinação para aquelas que pertencem ao conjunto de caracteres especificado..

*nPitchAndFamily*<br/>
[em] Especifica o tom e a família das fontes exibidas na caixa de combinação.

*Nwidth*<br/>
[em] Especifica a largura, em pixels, da caixa de combinação.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre possíveis valores de parâmetro *snFontType,* consulte [EnumFontFamProc](/previous-versions/dd162621\(v=vs.85\)) na documentação do Windows SDK.

Para obter mais informações sobre conjuntos de caracteres válidos que podem ser atribuídos ao *nCharSet*e valores válidos que podem ser atribuídos ao *nPitchAndFamily,* consulte [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) na documentação do Windows SDK.

## <a name="cmfcribbonfontcomboboxgetfontdesc"></a><a name="getfontdesc"></a>CMFCRibbonFontComboBox::GetFontDesc

Para obter mais detalhes, consulte o código-fonte localizado na pasta **VC\\atlmfc\\src\\mfc** da instalação do Visual Studio.

```
const CMFCFontInfo* GetFontDesc(int iIndex = -1) const;
```

### <a name="parameters"></a>Parâmetros

[em] *iIndex*<br/>

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonfontcomboboxrebuildfonts"></a><a name="rebuildfonts"></a>CMFCRibbonFontComboBox::RebuildFonts

Preenche a caixa de combinação na fita com fontes de um tipo de fonte especificado anteriormente, conjunto de caracteres e pitch e família.

```
void RebuildFonts();
```

### <a name="remarks"></a>Comentários

Você pode especificar o tipo de fonte, o conjunto de caracteres e o pitch e a família das fontes para incluir na caixa de combinação de fontes de fita no [construtor](#cmfcribbonfontcombobox) para esta classe ou ligando para [CMFCRibbonFontComboBox::BuildFonts](#buildfonts).

## <a name="cmfcribbonfontcomboboxsetfont"></a><a name="setfont"></a>CMFCRibbonFontComboBox::SetFont

Seleciona a fonte especificada na caixa de combinação.

```
BOOL SetFont(
    LPCTSTR lpszName,
    BYTE nCharSet = DEFAULT_CHARSET,
    BOOL bExact = FALSE);
```

### <a name="parameters"></a>Parâmetros

'lpszName* Especifica o nome da fonte a ser selecionada.

*nCharSet*<br/>
Especifica o conjunto de caracteres para a fonte selecionada.

*bExact*<br/>
TRUE para especificar que o conjunto de caracteres deve corresponder ao selecionar uma fonte; FALSO para especificar que o conjunto de caracteres pode ser ignorado ao selecionar uma fonte.

### <a name="return-value"></a>Valor retornado

Não zero se a fonte especificada foi encontrada e selecionada; caso contrário, zero.

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonfontcomboboxgetcharset"></a><a name="getcharset"></a>CMFCRibbonFontComboBox::GetCharSet

Retorna o conjunto de caracteres especificado.

```
BYTE GetCharSet() const;
```

### <a name="return-value"></a>Valor retornado

Conjunto de caracteres (consulte LOGFONT na documentação do Windows SDK).

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonfontcomboboxgetfonttype"></a><a name="getfonttype"></a>CMFCRibbonFontComboBox::GetFontType

Retorna quais tipos de fonte a serem exibidos na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE, ou qualquer combinação bitwise dele.

```
int GetFontType() const;
```

### <a name="return-value"></a>Valor retornado

Tipos de fonte (consulte EnumFontFamProc na documentação do Windows SDK).

### <a name="remarks"></a>Comentários

## <a name="cmfcribbonfontcomboboxgetpitchandfamily"></a><a name="getpitchandfamily"></a>CMFCRibbonFontComboBox::GetPitchAndFamily

Retorna o pitch e a família das fontes que são exibidas na caixa de combinação.

```
BYTE GetPitchAndFamily() const;
```

### <a name="return-value"></a>Valor retornado

Pitch e a família (consulte LOGFONT na documentação do Windows SDK).

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)
