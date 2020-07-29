---
title: Rotinas de validação dos dados da caixa de diálogo padrão
ms.date: 11/04/2016
helpviewer_keywords:
- standard dialog, data validation routines
ms.assetid: 44dbc222-a897-4949-925e-7660e8964ccd
ms.openlocfilehash: 2511e2ec6dbd4e27c0e12e35bdc1cd671bf72eaa
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213977"
---
# <a name="standard-dialog-data-validation-routines"></a>Rotinas de validação dos dados da caixa de diálogo padrão

Este tópico lista as rotinas de validação de dados de diálogo padrão (DDV) usadas para controles de caixa de diálogo comuns do MFC.

> [!NOTE]
> As rotinas de troca de dados de diálogo padrão são definidas no arquivo de cabeçalho afxdd_. h. No entanto, os aplicativos devem incluir afxwin. h.

### <a name="ddv-functions"></a>Funções DDV

|||
|-|-|
|[DDV_MaxChars](#ddv_maxchars)|Verifica se o número de caracteres em um determinado valor de controle não excede um determinado máximo.|
|[DDV_MinMaxByte](#ddv_minmaxbyte)|Verifica se um determinado valor de controle não excede um determinado intervalo de **bytes** .|
|[DDV_MinMaxDateTime](#ddv_minmaxdatetime)|Verifica se um determinado valor de controle não excede um determinado intervalo de tempo.|
|[DDV_MinMaxDouble](#ddv_minmaxdouble)|Verifica se um determinado valor de controle não excede um determinado **`double`** intervalo.|
|[DDV_MinMaxDWord](#ddv_minmaxdword)|Verifica se um determinado valor de controle não excede um determinado intervalo **DWORD** .|
|[DDV_MinMaxFloat](#ddv_minmaxfloat)|Verifica se um determinado valor de controle não excede um determinado **`float`** intervalo.|
|[DDV_MinMaxInt](#ddv_minmaxint)|Verifica se um determinado valor de controle não excede um determinado **`int`** intervalo.|
|[DDV_MinMaxLong](#ddv_minmaxlong)|Verifica se um determinado valor de controle não excede um determinado **`long`** intervalo.|
|[DDV_MinMaxLongLong](#ddv_minmaxlonglong)|Verifica se um determinado valor de controle não excede um determinado intervalo de **LONGLONG** .|
|[DDV_MinMaxMonth](#ddv_minmaxmonth)|Verifica se um determinado valor de controle não excede um determinado intervalo de datas.|
|[DDV_MinMaxShort](#ddv_minmaxshort)|Verifica se um determinado valor de controle não excede um determinado **`short`** intervalo.|
|[DDV_MinMaxSlider](#ddv_minmaxslider)|Verifica se um determinado valor de controle deslizante está dentro do intervalo especificado.|
|[DDV_MinMaxUInt](#ddv_minmaxuint)|Verifica se um determinado valor de controle não excede um determinado intervalo **uint** .|
|[DDV_MinMaxUnsigned](#ddv_minmaxuint)|Verifica se um determinado valor de controle cai entre dois valores especificados.|
|[DDV_MinMaxULongLong](#ddv_minmaxulonglong)|Verifica se um determinado valor de controle não excede um determinado intervalo de **ULONGLONG** .|

## <a name="ddv_maxchars"></a><a name="ddv_maxchars"></a>DDV_MaxChars

Chame `DDV_MaxChars` para verificar se a quantidade de caracteres no controle associado ao *valor* não excede *nchar*.

```cpp
void AFXAPI DDV_MaxChars(
    CDataExchange* pDX,
    CString const& value,
    int nChars);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*nChars*<br/>
Número máximo de caracteres permitidos.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxbyte"></a><a name="ddv_minmaxbyte"></a>DDV_MinMaxByte

Chame `DDV_MinMaxByte` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxByte(
    CDataExchange* pDX,
    BYTE value,
    BYTE minVal,
    BYTE maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
É permitido o valor mínimo (do tipo BYTE).

*maxVal*<br/>
É permitido o valor máximo (do tipo BYTE).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxdatetime"></a><a name="ddv_minmaxdatetime"></a>DDV_MinMaxDateTime

Chame `DDV_MinMaxDateTime` para verificar se o valor de hora/data no controle do seletor de data e hora ( [CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)) associado a *refValue* cai entre *refMinRange* e *refMaxRange*.

```cpp
void AFXAPI DDV_MinMaxDateTime(
    CDataExchange* pDX,
    CTime& refValue,
    const CTime* refMinRange,
    const CTime* refMaxRange);

void AFXAPI DDV_MinMaxDateTime(
    CDataExchange* pDX,
    COleDateTime& refValue,
    const COleDateTime* refMinRange,
    const COleDateTime* refMaxRange);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção. Você não precisa excluir este objeto.

*refValue*<br/>
Uma referência a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) associado a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle. Este objeto contém os dados a serem validados.

*refMinRange*<br/>
Valor de data/hora mínimo permitido.

*refMaxRange*<br/>
Valor de data/hora máximo permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxdouble"></a><a name="ddv_minmaxdouble"></a>DDV_MinMaxDouble

Chame `DDV_MinMaxDouble` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxDouble(
    CDataExchange* pDX,
    double const& value,
    double minVal,
    double maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
Valor mínimo (do tipo **`double`** ) permitido.

*maxVal*<br/>
Valor máximo (do tipo **`double`** ) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxdword"></a><a name="ddv_minmaxdword"></a>DDV_MinMaxDWord

Chame `DDV_MinMaxDWord` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxDWord(
    CDataExchange* pDX,
    DWORD const& value,
    DWORD minVal,
    DWORD maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
É permitido o valor mínimo (do tipo DWORD).

*maxVal*<br/>
Permitido o valor máximo (do tipo DWORD).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxfloat"></a><a name="ddv_minmaxfloat"></a>DDV_MinMaxFloat

Chame `DDV_MinMaxFloat` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxFloat(
    CDataExchange* pDX,
    float value,
    float minVal,
    float maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
Valor mínimo (do tipo **`float`** ) permitido.

*maxVal*<br/>
Valor máximo (do tipo **`float`** ) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxint"></a><a name="ddv_minmaxint"></a>DDV_MinMaxInt

Chame `DDV_MinMaxInt` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxInt(
    CDataExchange* pDX,
    int value,
    int minVal,
    int maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
Valor mínimo (do tipo **`int`** ) permitido.

*maxVal*<br/>
Valor máximo (do tipo **`int`** ) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxlong"></a><a name="ddv_minmaxlong"></a>DDV_MinMaxLong

Chame `DDV_MinMaxLong` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxLong(
    CDataExchange* pDX,
    long value,
    long minVal,
    long maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
Valor mínimo (do tipo **`long`** ) permitido.

*maxVal*<br/>
Valor máximo (do tipo **`long`** ) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxlonglong"></a><a name="ddv_minmaxlonglong"></a>DDV_MinMaxLongLong

Chame `DDV_MinMaxLongLong` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxLongLong(
    CDataExchange* pDX,
    LONGLONG value,
    LONGLONG minVal,
    LONGLONG maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
Permitido o valor mínimo (do tipo LONGLONG).

*maxVal*<br/>
Permitido o valor máximo (do tipo LONGLONG).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxmonth"></a><a name="ddv_minmaxmonth"></a>DDV_MinMaxMonth

Chame `DDV_MinMaxMonth` para verificar se o valor de data/hora no controle de calendário mensal ( [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)) associado a *refValue* cai entre *refMinRange* e *refMaxRange*.

```cpp
void AFXAPI DDV_MinMaxMonth(
    CDataExchange* pDX,
    CTime& refValue,
    const CTime* refMinRange,
    const CTime* refMaxRange);

void AFXAPI DDV_MinMaxMonth(
    CDataExchange* pDX,
    COleDateTime& refValue,
    const COleDateTime* refMinRange,
    const COleDateTime* refMaxRange);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*refValue*<br/>
Uma referência a um objeto do tipo `CTime` ou `COleDateTime` associada a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle. Este objeto contém os dados a serem validados. O MFC passa essa referência quando `DDV_MinMaxMonth` é chamado.

*refMinRange*<br/>
Valor de data/hora mínimo permitido.

*refMaxRange*<br/>
Valor de data/hora máximo permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxshort"></a><a name="ddv_minmaxshort"></a>DDV_MinMaxShort

Chame `DDV_MinMaxShort` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxShort(
    CDataExchange* pDX,
    short value,
    short minVal,
    short maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
Valor mínimo (do tipo **`short`** ) permitido.

*maxVal*<br/>
Valor máximo (do tipo **`short`** ) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxslider"></a><a name="ddv_minmaxslider"></a>DDV_MinMaxSlider

Chame `DDV_MinMaxSlider` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxSlider(
    CDataExchange* pDX,
    DWORD value,
    DWORD minVal,
    DWORD maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência ao valor a ser validado. Esse parâmetro mantém ou define a posição do polegar atual do controle deslizante.

*minVal*<br/>
Valor mínimo permitido.

*maxVal*<br/>
Valor máximo permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre controles deslizantes, consulte [usando CSliderCtrl](../../mfc/using-csliderctrl.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxuint"></a><a name="ddv_minmaxuint"></a>DDV_MinMaxUInt

Chame `DDV_MinMaxUInt` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxUInt(
    CDataExchange* pDX,
    UINT value,
    UINT minVal,
    UINT maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
É permitido o valor mínimo (do tipo UINT).

*maxVal*<br/>
Permitido o valor máximo (do tipo UINT).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxulonglong"></a><a name="ddv_minmaxulonglong"></a>DDV_MinMaxULongLong

Chame `DDV_MinMaxULongLong` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxULongLong(
    CDataExchange* pDX,
    ULONGLONG value,
    ULONGLONG  minVal ,
    ULONGLONG  maxVal);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
Permitido o valor mínimo (do tipo ULONGLONG).

*maxVal*<br/>
Permitido o valor máximo (do tipo ULONGLONG).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  Afxdd_ de **cabeçalho** . h

## <a name="ddv_minmaxunsigned"></a>DDV_MinMaxUnsigned

Chame `DDV_MinMaxUnsigned` para verificar se o valor no controle associado ao *valor* cai entre *minVal* e *maxVal*.

### <a name="syntax"></a>Sintaxe

```cpp
   void AFXAPI DDV_MinMaxUnsigned(
       CDataExchange* pDX,
       unsigned value,
       unsigned minVal,
       unsigned maxVal );
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são validados.

*minVal*<br/>
Valor mínimo (do tipo **`unsigned`** ) permitido.

*maxVal*<br/>
Valor máximo (do tipo **`unsigned`** ) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte a [caixa de diálogo troca de dados e validação](../dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdd_. h

## <a name="see-also"></a>Confira também

[Rotinas de troca de dados de diálogo padrão](standard-dialog-data-exchange-routines.md)<br/>
[Macros e globais](mfc-macros-and-globals.md)<br/>
[DDX_Slider](standard-dialog-data-exchange-routines.md#ddx_slider)<br/>
[DDX_FieldSlider](dialog-data-exchange-functions-for-crecordview-and-cdaorecordview.md#ddx_fieldslider)
