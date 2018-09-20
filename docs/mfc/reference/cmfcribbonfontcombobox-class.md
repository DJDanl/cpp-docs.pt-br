---
title: Classe CMFCRibbonFontComboBox | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 50094e9caaf712588c12a259f4886360374e430e
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46376773"
---
# <a name="cmfcribbonfontcombobox-class"></a>Classe CMFCRibbonFontComboBox

Implementa uma caixa de combinação que contém uma lista de fontes. Você pode colocar a caixa de combinação em um painel de faixa de opções.

## <a name="syntax"></a>Sintaxe

```
class CMFCRibbonFontComboBox : public CMFCRibbonComboBox
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

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
|[CMFCRibbonFontComboBox::BuildFonts](#buildfonts)|Preenche a caixa de combinação de fonte de faixa de opções com as fontes do tipo de fonte especificada, o conjunto de caracteres e densidade e família.|
|`CMFCRibbonFontComboBox::CreateObject`|Usado pelo framework para criar uma instância dinâmica desse tipo de classe.|
|[CMFCRibbonFontComboBox::GetCharSet](#getcharset)|Retorna o conjunto de caracteres especificada.|
|[CMFCRibbonFontComboBox::GetFontDesc](#getfontdesc)||
|[CMFCRibbonFontComboBox::GetFontType](#getfonttype)|Retorna os tipos de fonte para exibir na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE ou uma combinação bit a bit disso.|
|[CMFCRibbonFontComboBox::GetPitchAndFamily](#getpitchandfamily)|Retorna o tom e a família de fontes que são exibidos na caixa de combinação.|
|`CMFCRibbonFontComboBox::GetThisClass`|Usado pelo framework para obter um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) objeto que está associado com esse tipo de classe.|
|[CMFCRibbonFontComboBox::RebuildFonts](#rebuildfonts)|Preenche a caixa de combinação de fonte de faixa de opções com as fontes do tipo de fonte especificado anteriormente, o conjunto de caracteres e densidade e família.|
|[CMFCRibbonFontComboBox::SetFont](#setfont)|Seleciona a fonte especificada na caixa de combinação.|

## <a name="remarks"></a>Comentários

Depois de criar uma `CMFCRibbonFontComboBox` do objeto, adicione-a um painel de faixa de opções chamando [CMFCRibbonPanel::Add](../../mfc/reference/cmfcribbonpanel-class.md#add).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CMFCRibbonBaseElement](../../mfc/reference/cmfcribbonbaseelement-class.md)

[CMFCRibbonButton](../../mfc/reference/cmfcribbonbutton-class.md)

[CMFCRibbonEdit](../../mfc/reference/cmfcribbonedit-class.md)

[CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)

[CMFCRibbonFontComboBox](../../mfc/reference/cmfcribbonfontcombobox-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxRibbonComboBox.h

##  <a name="buildfonts"></a>  CMFCRibbonFontComboBox::BuildFonts

Preenche a caixa de combinação na faixa de opções com as fontes.

```
void BuildFonts(
    int nFontType = DEVICE_FONTTYPE | RASTER_FONTTYPE | TRUETYPE_FONTTYPE,
    BYTE nCharSet = DEFAULT_CHARSET,
    BYTE nPitchAndFamily = DEFAULT_PITCH);
```

### <a name="parameters"></a>Parâmetros

*nFontType*<br/>
[in] Especifica o tipo de fonte das fontes para adicionar.

*nCharSet*<br/>
[in] Especifica o conjunto de caracteres das fontes para adicionar.

*nPitchAndFamily*<br/>
[in] Especifica a densidade e a família de fontes para adicionar.

##  <a name="cmfcribbonfontcombobox"></a>  CMFCRibbonFontComboBox::CMFCRibbonFontComboBox

Constrói e inicializa um [CMFCRibbonFontComboBox](../../mfc/reference/cmfcribbonfontcombobox-class.md) objeto.

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
[in] A ID de comando do comando que é executado quando o usuário seleciona um item da caixa de combinação.

*nFontType*<br/>
[in] Especifica os tipos de qual fonte para exibir na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE ou uma combinação bit a bit disso.

*nCharSet*<br/>
[in] Filtra as fontes na caixa de combinação para aqueles que pertencem ao conjunto de caracteres especificado...

*nPitchAndFamily*<br/>
[in] Especifica a densidade e a família de fontes que são exibidos na caixa de combinação.

*nWidth*<br/>
[in] Especifica a largura, em pixels, da caixa de combinação.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre possíveis *nFontType* valores de parâmetro, consulte [EnumFontFamProc](https://msdn.microsoft.com/library/windows/desktop/dd162621) na documentação do SDK do Windows.

Para obter mais informações sobre conjuntos de caracteres válida que pode ser atribuído a *nCharSet*e os valores válidos que podem ser atribuídos aos *nPitchAndFamily*, consulte [LOGFONT](/windows/desktop/api/wingdi/ns-wingdi-taglogfonta) no Documentação do SDK do Windows.

##  <a name="getfontdesc"></a>  CMFCRibbonFontComboBox::GetFontDesc

Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.

```
const CMFCFontInfo* GetFontDesc(int iIndex = -1) const;
```

### <a name="parameters"></a>Parâmetros

[in] *iIndex*

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

##  <a name="rebuildfonts"></a>  CMFCRibbonFontComboBox::RebuildFonts

Preenche a caixa de combinação na faixa de opções com as fontes de um tipo de fonte especificado anteriormente, o conjunto de caracteres e a densidade e a família.

```
void RebuildFonts();
```

### <a name="remarks"></a>Comentários

Você pode especificar o tipo de fonte, o conjunto de caracteres, e a caixa de densidade e a família de fontes para incluir na caixa de combinação de fonte de faixa de opções na [construtor](#cmfcribbonfontcombobox) para essa classe, ou chamando [CMFCRibbonFontComboBox::BuildFonts](#buildfonts).

##  <a name="setfont"></a>  CMFCRibbonFontComboBox::SetFont

Seleciona a fonte especificada na caixa de combinação.

```
BOOL SetFont(
    LPCTSTR lpszName,
    BYTE nCharSet = DEFAULT_CHARSET,
    BOOL bExact = FALSE);
```

### <a name="parameters"></a>Parâmetros

' lpszName * Especifica o nome da fonte para selecionar.

*nCharSet*<br/>
Especifica o conjunto de caracteres para a fonte selecionada.

*bExact*<br/>
TRUE para especificar que o conjunto de caracteres deve corresponder ao selecionar uma fonte. FALSO para especificar que o conjunto de caracteres pode ser ignorado ao selecionar uma fonte.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a fonte especificada tiver sido encontrada e selecionada. Caso contrário, zero.

### <a name="remarks"></a>Comentários

##  <a name="getcharset"></a>  CMFCRibbonFontComboBox::GetCharSet

Retorna o conjunto de caracteres especificada.

```
BYTE GetCharSet() const;
```

### <a name="return-value"></a>Valor de retorno

Conjunto de caracteres (consulte LOGFONT na documentação do SDK do Windows).

### <a name="remarks"></a>Comentários

##  <a name="getfonttype"></a>  CMFCRibbonFontComboBox::GetFontType

Retorna os tipos de fonte para exibir na caixa de combinação. As opções válidas são DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE ou uma combinação bit a bit disso.

```
int GetFontType() const;
```

### <a name="return-value"></a>Valor de retorno

Tipos de fonte (consulte EnumFontFamProc na documentação do SDK do Windows).

### <a name="remarks"></a>Comentários

##  <a name="getpitchandfamily"></a>  CMFCRibbonFontComboBox::GetPitchAndFamily

Retorna o tom e a família de fontes que são exibidos na caixa de combinação.

```
BYTE GetPitchAndFamily() const;
```

### <a name="return-value"></a>Valor de retorno

Tom e a família (consulte LOGFONT na documentação do SDK do Windows).

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCRibbonComboBox](../../mfc/reference/cmfcribboncombobox-class.md)
