---
title: Rotinas de validação dos dados da caixa de diálogo padrão
ms.date: 11/04/2016
helpviewer_keywords:
- standard dialog, data validation routines
ms.assetid: 44dbc222-a897-4949-925e-7660e8964ccd
ms.openlocfilehash: 83e3e215ec8d66321bbac5a4a308b04ef69dc68c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372900"
---
# <a name="standard-dialog-data-validation-routines"></a>Rotinas de validação dos dados da caixa de diálogo padrão

Este tópico lista as rotinas padrão de validação de dados de diálogo (DDV) usadas para controles comuns de diálogo MFC.

> [!NOTE]
> As rotinas padrão de troca de dados de diálogo são definidas no arquivo de cabeçalho afxdd_.h. No entanto, os aplicativos devem incluir afxwin.h.

### <a name="ddv-functions"></a>Funções DDV

|||
|-|-|
|[DDV_MaxChars](#ddv_maxchars)|Verifica que o número de caracteres em um determinado valor de controle não excede um determinado máximo.|
|[DDV_MinMaxByte](#ddv_minmaxbyte)|Verifica se um determinado valor de controle não excede uma determinada faixa **BYTE.**|
|[DDV_MinMaxDateTime](#ddv_minmaxdatetime)|Verifica se um determinado valor de controle não excede um determinado intervalo de tempo.|
|[DDV_MinMaxDouble](#ddv_minmaxdouble)|Verifica se um determinado valor de controle não excede uma determinada **faixa dupla.**|
|[DDV_MinMaxDWord](#ddv_minmaxdword)|Verifica se um determinado valor de controle não excede um determinado intervalo **De DWORD.**|
|[DDV_MinMaxFloat](#ddv_minmaxfloat)|Verifica se um determinado valor de controle não excede um determinado intervalo **de flutuação.**|
|[DDV_MinMaxInt](#ddv_minmaxint)|Verifica se um determinado valor de controle não excede um determinado intervalo **int.**|
|[DDV_MinMaxLong](#ddv_minmaxlong)|Verifica que um determinado valor de controle não excede um determinado **longo** alcance.|
|[DDV_MinMaxLongLong](#ddv_minmaxlonglong)|Verifica se um determinado valor de controle não excede um determinado **intervalo LONGLONG.**|
|[DDV_MinMaxMonth](#ddv_minmaxmonth)|Verifica se um determinado valor de controle não excede um determinado intervalo de data.|
|[DDV_MinMaxShort](#ddv_minmaxshort)|Verifica se um determinado valor de controle não excede um determinado **curto** alcance.|
|[DDV_MinMaxSlider](#ddv_minmaxslider)|Verifica se um determinado valor de controle deslizante está dentro do intervalo dado.|
|[DDV_MinMaxUInt](#ddv_minmaxuint)|Verifica se um determinado valor de controle não excede uma determinada faixa **UINT.**|
|[DDV_MinMaxUnsigned](#ddv_minmaxuint)|Verifica se um determinado valor de controle se encaixa entre dois valores especificados.|
|[DDV_MinMaxULongLong](#ddv_minmaxulonglong)|Verifica se um determinado valor de controle não excede um determinado intervalo **ULONGLONG.**|

## <a name="ddv_maxchars"></a><a name="ddv_maxchars"></a>DDV_MaxChars

Ligue `DDV_MaxChars` para verificar se a quantidade de caracteres no controle associado ao *valor* não excede *nChars*.

```cpp
void AFXAPI DDV_MaxChars(
    CDataExchange* pDX,
    CString const& value,
    int nChars);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Nchars*<br/>
Número máximo de caracteres permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxbyte"></a><a name="ddv_minmaxbyte"></a>DDV_MinMaxByte

Ligue `DDV_MinMaxByte` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxByte(
    CDataExchange* pDX,
    BYTE value,
    BYTE minVal,
    BYTE maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo BYTE) permitido.

*Maxval*<br/>
Valor máximo (do tipo BYTE) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxdatetime"></a><a name="ddv_minmaxdatetime"></a>DDV_MinMaxDateTime

Ligue `DDV_MinMaxDateTime` para verificar se o valor de hora/data no controle de data e hora do seletor [(CDateTimeCtrl)](../../mfc/reference/cdatetimectrl-class.md)associado ao *refValue* está entre *refMinRange* e *refMaxRange*.

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

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção. Você não precisa excluir este objeto.

*refValue*<br/>
Uma referência a um objeto [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) associado a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle. Este objeto contém os dados a serem validados.

*refMinRange*<br/>
Valor mínimo de data/hora permitido.

*refMaxRange*<br/>
Valor máximo de data/hora permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxdouble"></a><a name="ddv_minmaxdouble"></a>DDV_MinMaxDouble

Ligue `DDV_MinMaxDouble` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxDouble(
    CDataExchange* pDX,
    double const& value,
    double minVal,
    double maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo **duplo)** permitido.

*Maxval*<br/>
Valor máximo (do tipo **duplo)** permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxdword"></a><a name="ddv_minmaxdword"></a>DDV_MinMaxDWord

Ligue `DDV_MinMaxDWord` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxDWord(
    CDataExchange* pDX,
    DWORD const& value,
    DWORD minVal,
    DWORD maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo DWORD) permitido.

*Maxval*<br/>
Valor máximo (do tipo DWORD) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxfloat"></a><a name="ddv_minmaxfloat"></a>DDV_MinMaxFloat

Ligue `DDV_MinMaxFloat` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxFloat(
    CDataExchange* pDX,
    float value,
    float minVal,
    float maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (de tipo **flutuante)** permitido.

*Maxval*<br/>
Valor máximo (de tipo **flutuante)** permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxint"></a><a name="ddv_minmaxint"></a>DDV_MinMaxInt

Ligue `DDV_MinMaxInt` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxInt(
    CDataExchange* pDX,
    int value,
    int minVal,
    int maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo **int)** permitido.

*Maxval*<br/>
Valor máximo (do tipo **int)** permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxlong"></a><a name="ddv_minmaxlong"></a>DDV_MinMaxLong

Ligue `DDV_MinMaxLong` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxLong(
    CDataExchange* pDX,
    long value,
    long minVal,
    long maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (de tipo **longo)** permitido.

*Maxval*<br/>
Valor máximo (de tipo **longo)** permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxlonglong"></a><a name="ddv_minmaxlonglong"></a>DDV_MinMaxLongLong

Ligue `DDV_MinMaxLongLong` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxLongLong(
    CDataExchange* pDX,
    LONGLONG value,
    LONGLONG minVal,
    LONGLONG maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo LONGLONG) permitido.

*Maxval*<br/>
Valor máximo (do tipo LONGLONG) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxmonth"></a><a name="ddv_minmaxmonth"></a>DDV_MinMaxMonth

Ligue `DDV_MinMaxMonth` para verificar se o valor de hora/data no controle do calendário do mês [(CMonthCalCtrl)](../../mfc/reference/cmonthcalctrl-class.md)associado ao *refValue* está entre *refMinRange* e *refMaxRange*.

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

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*refValue*<br/>
Uma referência a um `CTime` `COleDateTime` objeto de tipo ou associada a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle. Este objeto contém os dados a serem validados. O MFC passa `DDV_MinMaxMonth` esta referência quando é chamado.

*refMinRange*<br/>
Valor mínimo de data/hora permitido.

*refMaxRange*<br/>
Valor máximo de data/hora permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxshort"></a><a name="ddv_minmaxshort"></a>DDV_MinMaxShort

Ligue `DDV_MinMaxShort` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxShort(
    CDataExchange* pDX,
    short value,
    short minVal,
    short maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo **curto)** permitido.

*Maxval*<br/>
Valor máximo (do tipo **curto)** permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxslider"></a><a name="ddv_minmaxslider"></a>DDV_MinMaxSlider

Ligue `DDV_MinMaxSlider` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxSlider(
    CDataExchange* pDX,
    DWORD value,
    DWORD minVal,
    DWORD maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência ao valor a ser validado. Este parâmetro mantém ou define a posição atual do polegar do controle deslizante.

*Minval*<br/>
Valor mínimo permitido.

*Maxval*<br/>
Valor máximo permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre controles deslizantes, consulte [Usando CSliderCtrl](../../mfc/using-csliderctrl.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxuint"></a><a name="ddv_minmaxuint"></a>DDV_MinMaxUInt

Ligue `DDV_MinMaxUInt` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxUInt(
    CDataExchange* pDX,
    UINT value,
    UINT minVal,
    UINT maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo UINT) permitido.

*Maxval*<br/>
Valor máximo (do tipo UINT) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxulonglong"></a><a name="ddv_minmaxulonglong"></a>DDV_MinMaxULongLong

Ligue `DDV_MinMaxULongLong` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

```cpp
void AFXAPI DDV_MinMaxULongLong(
    CDataExchange* pDX,
    ULONGLONG value,
    ULONGLONG  minVal ,
    ULONGLONG  maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo ULONGLONG) permitido.

*Maxval*<br/>
Valor máximo (do tipo ULONGLONG) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="ddv_minmaxunsigned"></a>DDV_MinMaxUnsigned

Ligue `DDV_MinMaxUnsigned` para verificar se o valor no controle associado ao *valor* está entre *minVal* e *maxVal*.

### <a name="syntax"></a>Sintaxe

```cpp
   void AFXAPI DDV_MinMaxUnsigned(
       CDataExchange* pDX,
       unsigned value,
       unsigned minVal,
       unsigned maxVal );
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um objeto `CDataExchange`. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são validados.

*Minval*<br/>
Valor mínimo (do tipo **não assinado)** permitido.

*Maxval*<br/>
Valor máximo (do tipo **não assinado)** permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre o DDV, consulte [Troca e Validação de Dados de Diálogo](../dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdd_.h

## <a name="see-also"></a>Confira também

[Rotinas de troca dos dados da caixa de diálogo padrão](standard-dialog-data-exchange-routines.md)<br/>
[Macros e globais](mfc-macros-and-globals.md)<br/>
[DDX_Slider](standard-dialog-data-exchange-routines.md#ddx_slider)<br/>
[DDX_FieldSlider](dialog-data-exchange-functions-for-crecordview-and-cdaorecordview.md#ddx_fieldslider)
