---
title: Classe CMFCFontInfo
ms.date: 11/04/2016
f1_keywords:
- CMFCFontInfo
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::GetFullName
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_nCharSet
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_nPitchAndFamily
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_nType
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_strName
- AFXTOOLBARFONTCOMBOBOX/CMFCFontInfo::m_strScript
helpviewer_keywords:
- CMFCFontInfo [MFC], GetFullName
- CMFCFontInfo [MFC], m_nCharSet
- CMFCFontInfo [MFC], m_nPitchAndFamily
- CMFCFontInfo [MFC], m_nType
- CMFCFontInfo [MFC], m_strName
- CMFCFontInfo [MFC], m_strScript
ms.assetid: f88329b2-d74e-4921-9441-a3bb6536a049
ms.openlocfilehash: a27606b494b13cd7b50f01b38fa95a918bacc7aa
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505271"
---
# <a name="cmfcfontinfo-class"></a>Classe CMFCFontInfo

A `CMFCFontInfo` classe descreve o nome e outros atributos de uma fonte.

## <a name="syntax"></a>Sintaxe

```
class CMFCFontInfo : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|`CMFCFontInfo`|Constrói um objeto `CMFCFontInfo`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCFontInfo::GetFullName](#getfullname)|Recupera os nomes concatenados de uma fonte e seu conjunto de caracteres (script).|

### <a name="data-members"></a>Membros de Dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCFontInfo::m_nCharSet](#m_ncharset)|Um valor que especifica o conjunto de caracteres (script) associado à fonte.|
|[CMFCFontInfo::m_nPitchAndFamily](#m_npitchandfamily)|Um valor que especifica a densidade e a família da fonte.|
|[CMFCFontInfo::m_nType](#m_ntype)|Um valor que especifica o tipo da fonte.|
|[CMFCFontInfo::m_strName](#m_strname)|O nome da fonte; por exemplo, **Arial**.|
|[CMFCFontInfo::m_strScript](#m_strscript)|O nome de um conjunto de caracteres (script) associado à fonte.|

## <a name="remarks"></a>Comentários

Você pode anexar um `CMFCFontInfo` objeto a um item da classe de [classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md) . Chame o método [CMFCToolBarFontComboBox:: GetFontDesc](../../mfc/reference/cmfctoolbarfontcombobox-class.md#getfontdesc) para recuperar um ponteiro para um `CMFCFontInfo` objeto.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como usar vários membros da `CMFCFontInfo` classe. O exemplo demonstra como obter um `CMFCFontInfo` objeto de um `CMFCRibbonFontComboBox`e como acessar suas variáveis locais. Este exemplo faz parte do [exemplo de demonstração do MSOffice 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#6](../../mfc/reference/codesnippet/cpp/cmfcfontinfo-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarfontcombobox. h

##  <a name="cmfcfontinfo"></a>  CMFCFontInfo::CMFCFontInfo

Constrói um objeto `CMFCFontInfo`.

```
CMFCFontInfo(
    LPCTSTR lpszName,
    LPCTSTR lpszScript,
    BYTE nCharSet,
    BYTE nPitchAndFamily,
    int nType);

CMFCFontInfo(const CMFCFontInfo& src);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
no O nome da fonte. Para obter mais informações, consulte `lfFaceName` o membro da estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) .

*lpszScript*<br/>
no O nome do script (conjunto de caracteres) da fonte.

*nCharSet*<br/>
no Um valor que especifica o conjunto de caracteres (script) da fonte. Para obter mais informações, consulte `lfCharSet` o membro da estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) .

*nPitchAndFamily*<br/>
no Um valor que especifica a densidade e a família da fonte. Para obter mais informações, consulte `lfPitchAndFamily` o membro da estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) .

*nType*<br/>
no Um valor que especifica o tipo de fonte. Esse parâmetro pode ser uma combinação bit-a-bit (ou) de DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE.

*src*<br/>
no Um objeto `CMFCFontInfo` existente cujos membros são usados para construir esse `CMFCFontInfo` objeto.

### <a name="return-value"></a>Valor de retorno

### <a name="remarks"></a>Comentários

Esta documentação usa os termos *conjunto de caracteres* e *script* de maneira intercambiável. Um *script*, que também é conhecido como sistema de escrita, é uma coleção de caracteres e regras para gravar esses caracteres em um ou mais idiomas. A coleção de caracteres inclui o alfabeto e a pontuação usados nesse script. Por exemplo, o script Latin é usado para inglês, pois é falado no Estados Unidos, e seu alfabeto inclui os caracteres de A a Z. O `lfCharSet` membro da estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) especifica um conjunto de caracteres. Por exemplo, o valor ANSI_CHARSET especifica o conjunto de caracteres ANSI, que inclui o alfabeto do script latino.

##  <a name="getfullname"></a>  CMFCFontInfo::GetFullName

Recupera os nomes concatenados de uma fonte e seu conjunto de caracteres (script).

```
CString GetFullName() const;
```

### <a name="return-value"></a>Valor de retorno

Uma cadeia de caracteres que contém o nome e o script da fonte.

### <a name="remarks"></a>Comentários

Use esse método para obter o nome completo da fonte. Por exemplo, se o nome da fonte for **Arial** e o script da fonte for **cirílico**, esse método retornará "Arial (cirílico)".

##  <a name="m_ncharset"></a>  CMFCFontInfo::m_nCharSet

Um valor que especifica o conjunto de caracteres (script) associado à fonte.

```
const BYTE m_nCharSet;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro nCharSet do construtor [CMFCFontInfo:: CMFCFontInfo](#cmfcfontinfo) .

##  <a name="m_npitchandfamily"></a>  CMFCFontInfo::m_nPitchAndFamily

Um valor que especifica a densidade (tamanho do ponto) e a família (por exemplo, serif, Sans-Serif e monospace) da fonte.

```
const BYTE m_nPitchAndFamily;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *nPitchAndFamily* do construtor [CMFCFontInfo:: CMFCFontInfo](#cmfcfontinfo) .

##  <a name="m_ntype"></a>CMFCFontInfo::m_nType

Um valor que especifica o tipo da fonte.

```
const int m_nType;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *ndeclarações* do construtor [CMFCFontInfo:: CMFCFontInfo](#cmfcfontinfo) .

##  <a name="m_strname"></a>  CMFCFontInfo::m_strName

O nome da fonte: por exemplo, **Arial**.

```
const CString m_strName;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *lpszName* do construtor [CMFCFontInfo:: CMFCFontInfo](#cmfcfontinfo) .

##  <a name="m_strscript"></a>  CMFCFontInfo::m_strScript

O nome de um conjunto de caracteres (script) associado à fonte.

```
const CString m_strScript;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *lpszScript* do construtor [CMFCFontInfo:: CMFCFontInfo](#cmfcfontinfo) .

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)<br/>
[Classe CMFCToolBarFontSizeComboBox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)
