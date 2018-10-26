---
title: Rotinas de validação de dados de caixa de diálogo padrão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- standard dialog, data validation routines
ms.assetid: 44dbc222-a897-4949-925e-7660e8964ccd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3a37f79851df043a5473c82b514b7e85f418f1b6
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50067911"
---
# <a name="standard-dialog-data-validation-routines"></a>Rotinas de validação dos dados da caixa de diálogo padrão

Este tópico lista as rotinas de validação (DDV) de dados de caixa de diálogo padrão usadas para controles de caixa de diálogo comuns MFC.

> [!NOTE]
>  Rotinas de troca dos dados de caixa de diálogo padrão são definidas em afxdd_.h de arquivo de cabeçalho. No entanto, os aplicativos devem incluir afxwin. h.

### <a name="ddv-functions"></a>Funções DDV

|||
|-|-|
|[DDV_MaxChars](#ddv_maxchars)|Verifica que o número de caracteres em um valor determinado de controle não excede o máximo especificado.|
|[DDV_MinMaxByte](#ddv_minmaxbyte)|Verifica o valor de um determinado controle não exceda um determinado **bytes** intervalo.|
|[DDV_MinMaxDateTime](#ddv_minmaxdatetime)|Verifica o que valor de um determinado controle não exceda um determinado intervalo de tempo.|
|[DDV_MinMaxDouble](#ddv_minmaxdouble)|Verifica o valor de um determinado controle não exceda um determinado **duplas** intervalo.|
|[DDV_MinMaxDWord](#ddv_minmaxdword)|Verifica o valor de um determinado controle não exceda um determinado **DWORD** intervalo.|
|[DDV_MinMaxFloat](#ddv_minmaxfloat)|Verifica o valor de um determinado controle não exceda um determinado **float** intervalo.|
|[DDV_MinMaxInt](#ddv_minmaxint)|Verifica o valor de um determinado controle não exceda um determinado **int** intervalo.|
|[DDV_MinMaxLong](#ddv_minmaxlong)|Verifica o valor de um determinado controle não exceda um determinado **longo** intervalo.|
|[DDV_MinMaxLongLong](#ddv_minmaxlonglong)|Verifica o valor de um determinado controle não exceda um determinado **LONGLONG** intervalo.|
|[DDV_MinMaxMonth](#ddv_minmaxmonth)|Verifica o que valor de um determinado controle não exceda um determinado intervalo de datas.|
|[DDV_MinMaxShort](#ddv_minmaxshort)|Verifica o valor de um determinado controle não exceda um determinado **curto** intervalo.|
|[DDV_MinMaxSlider](#ddv_minmaxslider)|Verifica que o valor de um controle deslizante fornecida está dentro do intervalo determinado.|
|[DDV_MinMaxUInt](#ddv_minmaxuint)|Verifica o valor de um determinado controle não exceda um determinado **UINT** intervalo.|
|[DDV_MinMaxUnsigned](#ddv_minmaxuint)|Verifica o que valor de um determinado controle está entre dois valores especificados.|
|[DDV_MinMaxULongLong](#ddv_minmaxulonglong)|Verifica o valor de um determinado controle não exceda um determinado **ULONGLONG** intervalo.|

##  <a name="ddv_maxchars"></a>  DDV_MaxChars

Chame `DDV_MaxChars` para verificar que a quantidade de caracteres no controle associado *valor* não exceda *nChars*.

```
void AFXAPI DDV_MaxChars(
    CDataExchange* pDX,
    CString const& value,
    int nChars);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*nChars*<br/>
Número máximo de caracteres permitidos.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxbyte"></a>  DDV_MinMaxByte

Chame `DDV_MinMaxByte` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxByte(
    CDataExchange* pDX,
    BYTE value,
    BYTE minVal,
    BYTE maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo BYTE) permitido.

*maxVal*<br/>
Valor máximo (do tipo BYTE) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxdatetime"></a>  DDV_MinMaxDateTime

Chame `DDV_MinMaxDateTime` para verificar que o valor de data/hora no seletor de data e hora controla ( [CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)) associado *refValue* esteja entre *refMinRange*e *refMaxRange*.

```
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
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção. Você não precisa excluir este objeto.

*refValue*<br/>
Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto associado a uma variável de membro do objeto de exibição de controle, exibição de formulário ou caixa de diálogo. Este objeto contém os dados a ser validado.

*refMinRange*<br/>
Mínimo valor permitido de data/hora.

*refMaxRange*<br/>
Valor de data/hora máximo permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxdouble"></a>  DDV_MinMaxDouble

Chame `DDV_MinMaxDouble` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxDouble(
    CDataExchange* pDX,
    double const& value,
    double minVal,
    double maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo **duplas**) permitido.

*maxVal*<br/>
Valor máximo (do tipo **duplas**) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxdword"></a>  DDV_MinMaxDWord

Chame `DDV_MinMaxDWord` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxDWord(
    CDataExchange* pDX,
    DWORD const& value,
    DWORD minVal,
    DWORD maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo DWORD) permitido.

*maxVal*<br/>
Valor máximo (do tipo DWORD) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxfloat"></a>  DDV_MinMaxFloat

Chame `DDV_MinMaxFloat` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxFloat(
    CDataExchange* pDX,
    float value,
    float minVal,
    float maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo **float**) permitido.

*maxVal*<br/>
Valor máximo (do tipo **float**) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxint"></a>  DDV_MinMaxInt

Chame `DDV_MinMaxInt` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxInt(
    CDataExchange* pDX,
    int value,
    int minVal,
    int maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo **int**) permitido.

*maxVal*<br/>
Valor máximo (do tipo **int**) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxlong"></a>  DDV_MinMaxLong

Chame `DDV_MinMaxLong` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxLong(
    CDataExchange* pDX,
    long value,
    long minVal,
    long maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo **longo**) permitido.

*maxVal*<br/>
Valor máximo (do tipo **longo**) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxlonglong"></a>  DDV_MinMaxLongLong

Chame `DDV_MinMaxLongLong` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxLongLong(
    CDataExchange* pDX,
    LONGLONG value,
    LONGLONG minVal,
    LONGLONG maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo LONGLONG) permitido.

*maxVal*<br/>
Valor máximo (do tipo LONGLONG) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxmonth"></a>  DDV_MinMaxMonth

Chame `DDV_MinMaxMonth` para verificar que o valor de data/hora no calendário mensal de controle ( [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)) associado *refValue* esteja entre *refMinRange* e *refMaxRange*.

```
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
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*refValue*<br/>
Uma referência a um objeto do tipo `CTime` ou `COleDateTime` associada a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle. Este objeto contém os dados a ser validado. Passa MFC referência this quando `DDV_MinMaxMonth` é chamado.

*refMinRange*<br/>
Mínimo valor permitido de data/hora.

*refMaxRange*<br/>
Valor de data/hora máximo permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxshort"></a>  DDV_MinMaxShort

Chame `DDV_MinMaxShort` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxShort(
    CDataExchange* pDX,
    short value,
    short minVal,
    short maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo **curto**) permitido.

*maxVal*<br/>
Valor máximo (do tipo **curto**) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxslider"></a>  DDV_MinMaxSlider

Chame `DDV_MinMaxSlider` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxSlider(
    CDataExchange* pDX,
    DWORD value,
    DWORD minVal,
    DWORD maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência para o valor a ser validado. Este parâmetro contém ou define a posição de miniatura atual do controle deslizante.

*minVal*<br/>
Valor mínimo permitido.

*maxVal*<br/>
Valor máximo permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre controles deslizantes, consulte [usando CSliderCtrl](../../mfc/using-csliderctrl.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxuint"></a>  DDV_MinMaxUInt

Chame `DDV_MinMaxUInt` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxUInt(
    CDataExchange* pDX,
    UINT value,
    UINT minVal,
    UINT maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo UINT) permitido.

*maxVal*<br/>
Valor máximo (do tipo UINT) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

##  <a name="ddv_minmaxulonglong"></a>  DDV_MinMaxULongLong

Chame `DDV_MinMaxULongLong` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

```
void AFXAPI DDV_MinMaxULongLong(
    CDataExchange* pDX,
    ULONGLONG value,
    ULONGLONG  minVal ,
    ULONGLONG  maxVal);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo ULONGLONG) permitido.

*maxVal*<br/>
Valor máximo (do tipo ULONGLONG) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdd_.h

## <a name="see-also"></a>Consulte também

[Rotinas de troca dos dados da caixa de diálogo padrão](../../mfc/reference/standard-dialog-data-exchange-routines.md)<br/>
[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

## <a name="ddvminmaxunsigned"></a>DDV_MinMaxUnsigned

Chame `DDV_MinMaxUnsigned` para verificar que o valor no controle associado *valor* ficar entre *minVal* e *maxVal*.

### <a name="syntax"></a>Sintaxe

```
   void AFXAPI DDV_MinMaxUnsigned(
       CDataExchange* pDX,
       unsigned value,
       unsigned minVal,
       unsigned maxVal );
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*value*<br/>
Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são validados, exibição de formulário ou caixa de diálogo.

*minVal*<br/>
Valor mínimo (do tipo **sem sinal** ) permitido.

*maxVal*<br/>
Valor máximo (do tipo **sem sinal** ) permitido.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdd_.h

### <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)<br/>
[DDX_Slider](#ddx_slider)<br/>
[DDX_FieldSlider](#ddx_fieldslider)

