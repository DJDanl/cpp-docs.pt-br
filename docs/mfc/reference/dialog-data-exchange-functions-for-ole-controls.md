---
title: Funções da troca de dados da caixa de diálogo para controles OLE
ms.date: 11/04/2016
f1_keywords:
- AFXDISP/DDX_OCBool
- AFXDISP/DDX_OCBoolRO
- AFXDISP/DDX_OCColor
- AFXDISP/DDX_OCColorRO
- AFXDISP/DDX_OCFloat
- AFXDISP/DDX_OCFloatRO
- AFXDISP/DDX_OCInt
- AFXDISP/DDX_OCIntRO
- AFXDISP/DDX_OCShort
- AFXDISP/DDX_OCShortRO
- AFXDISP/DDX_OCText
- AFXDISP/DDX_OCTextRO
helpviewer_keywords:
- OLE controls [MFC], DDX functions
- DDX (dialog data exchange), OLE support
ms.assetid: 7ef1f288-ff65-40d4-aad2-5497bc00bb27
ms.openlocfilehash: 9133c30dd1ac069145862d4bf61ba0bc0d504838
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837353"
---
# <a name="dialog-data-exchange-functions-for-ole-controls"></a>Funções da troca de dados da caixa de diálogo para controles OLE

Este tópico lista as funções de DDX_OC usadas para trocar dados entre uma propriedade de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

### <a name="ddx_oc-functions"></a>Funções de DDX_OC

|Nome|Descrição|
|-|-|
|[DDX_OCBool](#ddx_ocbool)|Gerencia a transferência de dados **bool** entre uma propriedade de um controle OLE e um membro de dados **bool** .|
|[DDX_OCBoolRO](#ddx_ocboolro)|Gerencia a transferência de dados **bool** entre uma propriedade somente leitura de um controle OLE e um membro de dados **bool** .|
|[DDX_OCColor](#ddx_occolor)|Gerencia a transferência de dados de **OLE_COLOR** entre uma propriedade de um controle OLE e um membro de dados **OLE_COLOR** .|
|[DDX_OCColorRO](#ddx_occolorro)|Gerencia a transferência de dados de **OLE_COLOR** entre uma propriedade somente leitura de um controle OLE e um membro de dados **OLE_COLOR** .|
|[DDX_OCFloat](#ddx_ocfloat)|Gerencia a transferência de **`float`** (ou **`double`** ) dados entre uma propriedade de um controle OLE e um **`float`** membro de **`double`** dados (ou).|
|[DDX_OCFloatRO](#ddx_ocfloatro)|Gerencia a transferência de **`float`** (ou **`double`** ) dados entre uma propriedade somente leitura de um controle OLE e um **`float`** membro de dados (ou **`double`** ).|
|[DDX_OCInt](#ddx_ocint)|Gerencia a transferência de **`int`** (ou **`long`** ) dados entre uma propriedade de um controle OLE e um **`int`** membro de **`long`** dados (ou).|
|[DDX_OCIntRO](#ddx_ocintro)|Gerencia a transferência de **`int`** (ou **`long`** ) dados entre uma propriedade somente leitura de um controle OLE e um **`int`** membro de dados (ou **`long`** ).|
|[DDX_OCShort](#ddx_ocshort)|Gerencia a transferência de **`short`** dados entre uma propriedade de um controle OLE e um **`short`** membro de dados.|
|[DDX_OCShortRO](#ddx_ocshortro)|Gerencia a transferência de **`short`** dados entre uma propriedade somente leitura de um controle OLE e um **`short`** membro de dados.|
|[DDX_OCText](#ddx_octext)|Gerencia a transferência de dados de **CString** entre uma propriedade de um controle OLE e um membro de dados **CString** .|
|[DDX_OCTextRO](#ddx_octextro)|Gerencia a transferência de dados de **CString** entre uma propriedade somente leitura de um controle OLE e um membro de dados **CString** .|

## <a name="ddx_ocbool"></a><a name="ddx_ocbool"></a> DDX_OCBool

A `DDX_OCBool` função gerencia a transferência de dados **bool** entre uma propriedade de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados **bool** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCBool(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    BOOL& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho:** AFXDISP. h

## <a name="ddx_ocboolro"></a><a name="ddx_ocboolro"></a> DDX_OCBoolRO

A `DDX_OCBoolRO` função gerencia a transferência de dados **bool** entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados **bool** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCBoolRO(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    BOOL& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_occolor"></a><a name="ddx_occolor"></a> DDX_OCColor

A `DDX_OCColor` função gerencia a transferência de dados de OLE_COLOR entre uma propriedade de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados de OLE_COLOR da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCColor(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    OLE_COLOR& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_occolorro"></a><a name="ddx_occolorro"></a> DDX_OCColorRO

A `DDX_OCColorRO` função gerencia a transferência de dados de OLE_COLOR entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados de OLE_COLOR da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCColorRO(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    OLE_COLOR& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_ocfloat"></a><a name="ddx_ocfloat"></a> DDX_OCFloat

A `DDX_OCFloat` função gerencia a transferência de **`float`** (ou **`double`** ) dados entre uma propriedade de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`float`** **`double`** membro de dados (ou) da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCFloat(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    float& value);

void AFXAPI DDX_OCFloat(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    double& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_ocfloatro"></a><a name="ddx_ocfloatro"></a> DDX_OCFloatRO

A `DDX_OCFloatRO` função gerencia a transferência de **`float`** (ou **`double`** ) dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`float`** **`double`** membro de dados (ou) da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCFloatRO(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    float& value);

void AFXAPI DDX_OCFloatRO(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    double& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_ocint"></a><a name="ddx_ocint"></a> DDX_OCInt

A `DDX_OCInt` função gerencia a transferência de **`int`** (ou **`long`** ) dados entre uma propriedade de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`int`** **`long`** membro de dados (ou) da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCInt(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    int& value);

void AFXAPI DDX_OCInt(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    long& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_ocintro"></a><a name="ddx_ocintro"></a> DDX_OCIntRO

A `DDX_OCIntRO` função gerencia a transferência de **`int`** (ou **`long`** ) dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um **`int`** **`long`** membro de dados (ou) da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCIntRO(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    int& value);

void AFXAPI DDX_OCIntRO(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    long& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_ocshort"></a><a name="ddx_ocshort"></a> DDX_OCShort

A `DDX_OCShort` função gerencia a transferência de dados curtos entre uma propriedade de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados curto da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCShort(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    short& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_ocshortro"></a><a name="ddx_ocshortro"></a> DDX_OCShortRO

A `DDX_OCShortRO` função gerencia a transferência de dados curtos entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados curto da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCShortRO(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    short& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_octext"></a><a name="ddx_octext"></a> DDX_OCText

A função **DDX_OCText** gerencia a transferência de dados de **CString** entre uma propriedade de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados **CString** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCText(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto **CDataExchange** . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="ddx_octextro"></a><a name="ddx_octextro"></a> DDX_OCTextRO

A `DDX_OCTextRO` função gerencia a transferência de `CString` dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um `CString` membro de dados da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
void AFXAPI DDX_OCTextRO(
    CDataExchange* pDX,
    int nIDC,
    DISPID dispid,
    CString& value);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle OLE na caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

*DISPID*<br/>
A ID de expedição de uma propriedade do controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDISP. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
