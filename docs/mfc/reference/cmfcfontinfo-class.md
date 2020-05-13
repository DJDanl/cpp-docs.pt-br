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
ms.openlocfilehash: 6e87971e2afefc9cf1574abe951920c254dcd2ae
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367477"
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
|[CMFCFontInfo::getfullname](#getfullname)|Recupera os nomes concatenados de uma fonte e seu conjunto de caracteres (script).|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|----------|-----------------|
|[CMFCFontInfo::m_nCharSet](#m_ncharset)|Um valor que especifica o conjunto de caracteres (script) associado à fonte.|
|[CMFCFontInfo::m_nPitchAndFamily](#m_npitchandfamily)|Um valor que especifica o tom e a família da fonte.|
|[CMFCFontInfo::m_nType](#m_ntype)|Um valor que especifica o tipo da fonte.|
|[CMFCFontInfo::m_strName](#m_strname)|O nome da fonte; por exemplo, **Arial**.|
|[CMFCFontInfo::m_strScript](#m_strscript)|O nome de um conjunto de caracteres (script) associado à fonte.|

## <a name="remarks"></a>Comentários

Você pode `CMFCFontInfo` anexar um objeto a um item da classe [CMFCToolBarComboBox.](../../mfc/reference/cmfctoolbarfontcombobox-class.md) Ligue para o [método CMFCToolBarFontComboBox::GetFontDesc](../../mfc/reference/cmfctoolbarfontcombobox-class.md#getfontdesc) `CMFCFontInfo` para recuperar um ponteiro para um objeto.

## <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCFontInfo` usar vários membros da classe. O exemplo demonstra como `CMFCFontInfo` obter `CMFCRibbonFontComboBox`um objeto a partir de um , e como acessar suas variáveis locais. Este exemplo faz parte da amostra de [demonstração do MSOffice 2007](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_MSOffice2007Demo#6](../../mfc/reference/codesnippet/cpp/cmfcfontinfo-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtoolbarfontcombobox.h

## <a name="cmfcfontinfocmfcfontinfo"></a><a name="cmfcfontinfo"></a>CMFCFontInfo::CMFCFontInfo

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
[em] O nome da fonte. Para obter mais `lfFaceName` informações, consulte o membro da estrutura [LOGFONT.](/windows/win32/api/wingdi/ns-wingdi-logfontw)

*lpszScript*<br/>
[em] O nome do script (conjunto de caracteres) da fonte.

*nCharSet*<br/>
[em] Um valor que especifica o conjunto de caracteres (script) da fonte. Para obter mais `lfCharSet` informações, consulte o membro da estrutura [LOGFONT.](/windows/win32/api/wingdi/ns-wingdi-logfontw)

*nPitchAndFamily*<br/>
[em] Um valor que especifica o tom e a família da fonte. Para obter mais `lfPitchAndFamily` informações, consulte o membro da estrutura [LOGFONT.](/windows/win32/api/wingdi/ns-wingdi-logfontw)

*nType*<br/>
[em] Um valor que especifica o tipo de fonte. Este parâmetro pode ser uma combinação bitwise (OR) de DEVICE_FONTTYPE, RASTER_FONTTYPE e TRUETYPE_FONTTYPE.

*src*<br/>
[em] Um objeto `CMFCFontInfo` existente cujos membros são `CMFCFontInfo` usados para construir este objeto.

### <a name="return-value"></a>Valor retornado

### <a name="remarks"></a>Comentários

Esta documentação usa os termos *conjunto de caracteres* e *script* intercambiavelmente. Um *script*, que também é conhecido como um sistema de escrita, é uma coleção de caracteres e regras para escrever esses personagens em uma ou mais línguas. A coleção de caracteres inclui o alfabeto e a pontuação usados nesse script. Por exemplo, o script em latim é usado para o inglês como é falado nos Estados Unidos, e seu alfabeto inclui os personagens de A a Z. O `lfCharSet` membro da estrutura [LOGFONT](/windows/win32/api/wingdi/ns-wingdi-logfontw) especifica um conjunto de caracteres. Por exemplo, o ANSI_CHARSET de valor especifica o conjunto de caracteres ANSI, que inclui o alfabeto do script em latim.

## <a name="cmfcfontinfogetfullname"></a><a name="getfullname"></a>CMFCFontInfo::getfullname

Recupera os nomes concatenados de uma fonte e seu conjunto de caracteres (script).

```
CString GetFullName() const;
```

### <a name="return-value"></a>Valor retornado

Uma seqüência que contém o nome da fonte e o script.

### <a name="remarks"></a>Comentários

Use este método para obter o nome completo da fonte. Por exemplo, se o nome da fonte for **Arial** e o script de fonte for **cirílico,** este método retorna "Arial (cirílico)".

## <a name="cmfcfontinfom_ncharset"></a><a name="m_ncharset"></a>CMFCFontInfo::m_nCharSet

Um valor que especifica o conjunto de caracteres (script) associado à fonte.

```
const BYTE m_nCharSet;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *nCharSet* do [construtor CMFCFontInfo::CMFCFontInfo.](#cmfcfontinfo)

## <a name="cmfcfontinfom_npitchandfamily"></a><a name="m_npitchandfamily"></a>CMFCFontInfo::m_nPitchAndFamily

Um valor que especifica o tom (tamanho do ponto) e a família (por exemplo, serif, sans-serif e monoespaço) da fonte.

```
const BYTE m_nPitchAndFamily;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *nPitchAndFamily* do [construtor CMFCFontInfo::CMFCFontInfo.](#cmfcfontinfo)

## <a name="cmfcfontinfom_ntype"></a><a name="m_ntype"></a>CMFCFontInfo::m_nType

Um valor que especifica o tipo da fonte.

```
const int m_nType;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *nType* do [construtor CMFCFontInfo::CMFCFontInfo.](#cmfcfontinfo)

## <a name="cmfcfontinfom_strname"></a><a name="m_strname"></a>CMFCFontInfo::m_strName

O nome da fonte: por exemplo, **Arial**.

```
const CString m_strName;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *lpszName* do [construtor CMFCFontInfo::CMFCFontInfo.](#cmfcfontinfo)

## <a name="cmfcfontinfom_strscript"></a><a name="m_strscript"></a>CMFCFontInfo::m_strScript

O nome de um conjunto de caracteres (script) associado à fonte.

```
const CString m_strScript;
```

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o parâmetro *lpszScript* do [construtor CMFCFontInfo::CMFCFontInfo.](#cmfcfontinfo)

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CMFCToolBarFontComboBox](../../mfc/reference/cmfctoolbarfontcombobox-class.md)<br/>
[Classe CMFCToolBarFontSizeComboBox](../../mfc/reference/cmfctoolbarfontsizecombobox-class.md)
