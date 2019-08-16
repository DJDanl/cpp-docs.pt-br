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
ms.openlocfilehash: 186c4bc3e1b26529ed0e000d2893e1b2d81c4304
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504963"
---
# <a name="cmfcribbonfontcombobox-class"></a>Classe CMFCRibbonFontComboBox

Implementa uma caixa de combinação que contém uma lista de fontes. Você coloca a caixa de combinação em um painel da faixa de medida.

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
|[CMFCRibbonFontComboBox::BuildFonts](#buildfonts)|Popula a caixa de combinação de fonte da faixa de tipos com fontes do tipo de fonte especificado, conjunto de caracteres e densidade e família.|
|`CMFCRibbonFontComboBox::CreateObject`|Usado pela estrutura para criar uma instância dinâmica desse tipo de classe.|
|[CMFCRibbonFontComboBox::GetCharSet](#getcharset)|Retorna o conjunto de caracteres especificado.|
|[CMFCRibbonFontComboBox::GetFontDesc](#getfontdesc)||
|[CMFCRibbonFontComboBox::GetFontType](#getfonttype)|Retorna quais tipos de fonte exibir na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE, ou qualquer combinação bit-a-da.|
|[CMFCRibbonFontComboBox::GetPitchAndFamily](#getpitchandfamily)|Retorna a densidade e a família das fontes que são exibidas na caixa de combinação.|
|`CMFCRibbonFontComboBox::GetThisClass`|Usado pela estrutura para obter um ponteiro para o objeto [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) que está associado a esse tipo de classe.|
|[CMFCRibbonFontComboBox::RebuildFonts](#rebuildfonts)|Popula a caixa de combinação de fonte da faixa de tipos com fontes do tipo de fonte especificado anteriormente, conjunto de caracteres e densidade e família.|
|[CMFCRibbonFontComboBox::SetFont](#setfont)|Seleciona a fonte especificada na caixa de combinação.|

## <a name="remarks"></a>Comentários

Depois de criar um `CMFCRibbonFontComboBox` objeto, adicione-o a um painel da faixa de medida chamando [CMFCRibbonPanel:: Add](../../mfc/reference/cmfcribbonpanel-class.md#add).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)

[CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)

[CMFCRibbonFontComboBox](../../mfc/reference/cmfcribbonfontcombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonComboBox. h

##  <a name="buildfonts"></a>CMFCRibbonFontComboBox::BuildFonts

Popula a caixa de combinação na faixa de tipos com fontes.

```
void BuildFonts(
    int nFontType = DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE,
    BYTE nCharSet = DEFAULT_CHARSET,
    BYTE nPitchAndFamily = DEFAULT_PITCH);
```

### <a name="parameters"></a>Parâmetros

*nFontType*<br/>
no Especifica o tipo de fonte das fontes a serem adicionadas.

*nCharSet*<br/>
no Especifica o conjunto de caracteres das fontes a serem adicionadas.

*nPitchAndFamily*<br/>
no Especifica a densidade e a família das fontes a serem adicionadas.

##  <a name="cmfcribbonfontcombobox"></a>CMFCRibbonFontComboBox::CMFCRibbonFontComboBox

Constrói e inicializa um objeto [CMFCRibbonFontComboBox](../../mfc/reference/cmfcribbonfontcombobox-class.md) .

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
no A ID de comando do comando que é executado quando o usuário seleciona um item da caixa de combinação.

*nFontType*<br/>
no Especifica quais tipos de fonte exibir na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE, ou qualquer combinação bit-a-da.

*nCharSet*<br/>
no Filtra as fontes na caixa de combinação àquelas que pertencem ao conjunto de caracteres especificado.

*nPitchAndFamily*<br/>
no Especifica a densidade e a família das fontes que são exibidas na caixa de combinação.

*nWidth*<br/>
no Especifica a largura, em pixels, da caixa de combinação.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre possíveis valores de parâmetro *nFontType* , consulte [EnumFontFamProc](/previous-versions/dd162621\(v=vs.85\)) na documentação do SDK do Windows.

Para obter mais informações sobre conjuntos de caracteres válidos que podem seratribuídos a nCharSet e os valores válidos que podem ser atribuídos a *NPitchAndFamily*, consulte [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) na documentação do SDK do Windows.

##  <a name="getfontdesc"></a>  CMFCRibbonFontComboBox::GetFontDesc

Para obter mais detalhes, consulte o código-fonte localizado na pasta **vc\\atlmfc\\src\\MFC** da instalação do Visual Studio.

```
const CMFCFontInfo* GetFontDesc(int iIndex = -1) const;
```

### <a name="parameters"></a>Parâmetros

no *iIndex*<br/>

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="rebuildfonts"></a>  CMFCRibbonFontComboBox::RebuildFonts

Popula a caixa de combinação na faixa de tipos com fontes de um tipo de fonte especificado, conjunto de caracteres e densidade e família especificados anteriormente.

```
void RebuildFonts();
```

### <a name="remarks"></a>Comentários

Você pode especificar o tipo de fonte, o conjunto de caracteres e a densidade e a família das fontes a serem incluídas na caixa de combinação de fonte da faixa de tipos no [Construtor](#cmfcribbonfontcombobox) para essa classe, ou chamando [CMFCRibbonFontComboBox:: BuildFonts](#buildfonts).

##  <a name="setfont"></a>CMFCRibbonFontComboBox:: SetFont

Seleciona a fonte especificada na caixa de combinação.

```
BOOL SetFont(
    LPCTSTR lpszName,
    BYTE nCharSet = DEFAULT_CHARSET,
    BOOL bExact = FALSE);
```

### <a name="parameters"></a>Parâmetros

' lpszName * Especifica o nome da fonte a ser selecionada.

*nCharSet*<br/>
Especifica o conjunto de caracteres para a fonte selecionada.

*bExact*<br/>
TRUE para especificar que o conjunto de caracteres deve corresponder ao selecionar uma fonte; FALSE para especificar que o conjunto de caracteres pode ser ignorado ao selecionar uma fonte.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fonte especificada foi encontrada e selecionada; caso contrário, zero.

### <a name="remarks"></a>Comentários

##  <a name="getcharset"></a>  CMFCRibbonFontComboBox::GetCharSet

Retorna o conjunto de caracteres especificado.

```
BYTE GetCharSet() const;
```

### <a name="return-value"></a>Valor de retorno

Conjunto de caracteres (consulte LOGFONT na documentação do SDK do Windows).

### <a name="remarks"></a>Comentários

##  <a name="getfonttype"></a>CMFCRibbonFontComboBox:: getfonttype

Retorna quais tipos de fonte exibir na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE, ou qualquer combinação bit-a-da.

```
int GetFontType() const;
```

### <a name="return-value"></a>Valor de retorno

Tipos de fonte (consulte EnumFontFamProc na documentação do SDK do Windows).

### <a name="remarks"></a>Comentários

##  <a name="getpitchandfamily"></a>  CMFCRibbonFontComboBox::GetPitchAndFamily

Retorna a densidade e a família das fontes que são exibidas na caixa de combinação.

```
BYTE GetPitchAndFamily() const;
```

### <a name="return-value"></a>Valor de retorno

Pitch e a família (consulte LOGFONT na documentação SDK do Windows).

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)
