---
title: "Rotinas de validação de dados de caixa de diálogo padrão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- standard dialog, data validation routines
ms.assetid: 44dbc222-a897-4949-925e-7660e8964ccd
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 33566bcdfab1a618dc8ff79deb375b3f9d1221f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="standard-dialog-data-validation-routines"></a>Rotinas de validação dos dados da caixa de diálogo padrão
Este tópico lista as rotinas de validação (DDV) de dados de caixa de diálogo padrão usadas para controles de caixa de diálogo comuns do MFC.  
  
> [!NOTE]
>  As rotinas de troca de dados de caixa de diálogo padrão são definidas em afxdd_.h de arquivo de cabeçalho. No entanto, os aplicativos devem incluir afxwin.h.  
  
### <a name="ddv-functions"></a>Funções DDV  
  
|||  
|-|-|  
|[DDV_MaxChars](#ddv_maxchars)|Verifica que o número de caracteres em um valor de controle fornecido não excede o máximo especificado.|  
|[DDV_MinMaxByte](#ddv_minmaxbyte)|Verifica o valor de um determinado controle não exceder um determinado **bytes** intervalo.|  
|[DDV_MinMaxDateTime](#ddv_minmaxdatetime)|Verifica que um valor de controle fornecido não exceda um intervalo de tempo determinado.|  
|[DDV_MinMaxDouble](#ddv_minmaxdouble)|Verifica o valor de um determinado controle não exceder um determinado **duplo** intervalo.|  
|[DDV_MinMaxDWord](#ddv_minmaxdword)|Verifica o valor de um determinado controle não exceder um determinado **DWORD** intervalo.|  
|[DDV_MinMaxFloat](#ddv_minmaxfloat)|Verifica o valor de um determinado controle não exceder um determinado **float** intervalo.|  
|[DDV_MinMaxInt](#ddv_minmaxint)|Verifica o valor de um determinado controle não exceder um determinado **int** intervalo.|  
|[DDV_MinMaxLong](#ddv_minmaxlong)|Verifica o valor de um determinado controle não exceder um determinado **longo** intervalo.|  
|[DDV_MinMaxLongLong](#ddv_minmaxlonglong)|Verifica o valor de um determinado controle não exceder um determinado **LONGLONG** intervalo.|  
|[DDV_MinMaxMonth](#ddv_minmaxmonth)|Verifica que um valor de controle fornecido não exceda um determinado intervalo de datas.|  
|[DDV_MinMaxShort](#ddv_minmaxshort)|Verifica o valor de um determinado controle não exceder um determinado **curto** intervalo.|  
|[DDV_MinMaxSlider](#ddv_minmaxslider)|Verifica que o valor de um controle deslizante determinado esteja dentro do intervalo especificado.|  
|[DDV_MinMaxUInt](#ddv_minmaxuint)|Verifica o valor de um determinado controle não exceder um determinado **UINT** intervalo.|  
|[DDV_MinMaxUnsigned](#ddv_minmaxuint)|Verifica o que valor de um determinado controle está entre dois valores especificados.| 
|[DDV_MinMaxULongLong](#ddv_minmaxulonglong)|Verifica o valor de um determinado controle não exceder um determinado **ULONGLONG** intervalo.|  
  

  
##  <a name="ddv_maxchars"></a>DDV_MaxChars  
 Chamar `DDV_MaxChars` para verificar se a quantidade de caracteres no controle associado *valor* não exceda *nChars*.  
  
```   
void AFXAPI DDV_MaxChars(
    CDataExchange* pDX,  
    CString const& value,  
    int nChars); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `nChars`  
 Número máximo de caracteres permitidos.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxbyte"></a>DDV_MinMaxByte  
 Chamar `DDV_MinMaxByte` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxByte(
    CDataExchange* pDX,  
    BYTE value,  
    BYTE minVal,  
    BYTE maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **bytes**) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **bytes**) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxdatetime"></a>DDV_MinMaxDateTime  
 Chamar `DDV_MinMaxDateTime` para verificar que o valor de data/hora no seletor de data e hora de controle ( [CDateTimeCtrl](../../mfc/reference/cdatetimectrl-class.md)) associado *refValue* fica entre `refMinRange` e `refMaxRange`.  
  
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
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção. Você não precisa excluir este objeto.  
  
 *refValue*  
 Uma referência a um [CTime](../../atl-mfc-shared/reference/ctime-class.md) ou [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) objeto associado a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle. Este objeto contém os dados a ser validado.  
  
 `refMinRange`  
 Mínimo permitido de valor de data/hora.  
  
 `refMaxRange`  
 Valor de data/hora máximo permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxdouble"></a>DDV_MinMaxDouble  
 Chamar `DDV_MinMaxDouble` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxDouble(
    CDataExchange* pDX,  
    double const& value,  
    double minVal,  
    double maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **duplo**) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **duplo**) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxdword"></a>DDV_MinMaxDWord  
 Chamar `DDV_MinMaxDWord` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxDWord(
    CDataExchange* pDX,  
    DWORD const& value,  
    DWORD minVal,  
    DWORD maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo `DWORD`) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo `DWORD`) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxfloat"></a>DDV_MinMaxFloat  
 Chamar `DDV_MinMaxFloat` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxFloat(
    CDataExchange* pDX,  
    float value,  
    float minVal,  
    float maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **float**) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **float**) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxint"></a>DDV_MinMaxInt  
 Chamar `DDV_MinMaxInt` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxInt(
    CDataExchange* pDX,  
    int value,  
    int minVal,  
    int maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo `int`) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo `int`) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxlong"></a>DDV_MinMaxLong  
 Chamar `DDV_MinMaxLong` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxLong(
    CDataExchange* pDX,  
    long value,  
    long minVal,  
    long maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **longo**) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **longo**) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxlonglong"></a>DDV_MinMaxLongLong  
 Chamar `DDV_MinMaxLongLong` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxLongLong(
    CDataExchange* pDX,  
    LONGLONG value,  
    LONGLONG minVal,  
    LONGLONG maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **LONGLONG**) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **LONGLONG**) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxmonth"></a>DDV_MinMaxMonth  
 Chamar `DDV_MinMaxMonth` para verificar que o valor de data/hora no calendário do mês de controle ( [CMonthCalCtrl](../../mfc/reference/cmonthcalctrl-class.md)) associado *refValue* fica entre `refMinRange` e `refMaxRange`.  
  
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
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *refValue*  
 Uma referência a um objeto do tipo `CTime` ou `COleDateTime` associada a uma variável de membro da caixa de diálogo, exibição de formulário ou controle de objeto de exibição. Este objeto contém os dados a ser validado. Passa MFC essa referência quando `DDV_MinMaxMonth` é chamado.  
  
 `refMinRange`  
 Mínimo permitido de valor de data/hora.  
  
 `refMaxRange`  
 Valor de data/hora máximo permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxshort"></a>DDV_MinMaxShort  
 Chamar `DDV_MinMaxShort` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxShort(
    CDataExchange* pDX,  
    short value,  
    short minVal,  
    short maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **curto**) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **curto**) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxslider"></a>DDV_MinMaxSlider  
 Chamar `DDV_MinMaxSlider` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxSlider(
    CDataExchange* pDX,  
    DWORD value,  
    DWORD minVal,  
    DWORD maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência para o valor a ser validado. Este parâmetro contém ou define a posição de miniatura atual do controle deslizante.  
  
 `minVal`  
 Valor mínimo permitido.  
  
 `maxVal`  
 Valor máximo permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter informações sobre controles deslizantes, consulte [usando CSliderCtrl](../../mfc/using-csliderctrl.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxuint"></a>DDV_MinMaxUInt  
 Chamar `DDV_MinMaxUInt` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxUInt(
    CDataExchange* pDX,  
    UINT value,  
    UINT minVal,  
    UINT maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **UINT**) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **UINT**) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
  
##  <a name="ddv_minmaxulonglong"></a>DDV_MinMaxULongLong  
 Chamar `DDV_MinMaxULongLong` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
  
```   
void AFXAPI DDV_MinMaxULongLong(
    CDataExchange* pDX,  
    ULONGLONG value,  
    ULONGLONG  minVal ,  
    ULONGLONG  maxVal); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **ULONGLONG**) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **ULONGLONG**) permitido.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdd_.h  
    
## <a name="see-also"></a>Consulte também  
 [Rotinas de troca de dados de caixa de diálogo padrão](../../mfc/reference/standard-dialog-data-exchange-routines.md)   
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

 ## <a name="ddvminmaxunsigned"></a>DDV_MinMaxUnsigned
Chamar `DDV_MinMaxUnsigned` para verificar se o valor no controle associado *valor* fica entre `minVal` e `maxVal`.  
   
### <a name="syntax"></a>Sintaxe    
```
   void AFXAPI DDV_MinMaxUnsigned(  
       CDataExchange* pDX,  
       unsigned value,  
       unsigned minVal,  
       unsigned maxVal );  
```
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle com o qual os dados são validados.  
  
 `minVal`  
 Valor mínimo (do tipo **sem sinal** ) permitido.  
  
 `maxVal`  
 Valor máximo (do tipo **sem sinal** ) permitido.  
   
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDV, consulte [troca de dados de caixa de diálogo e validação](../dialog-data-exchange-and-validation.md).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdd_.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [DDX_Slider](#ddx_slider)   
 [DDX_FieldSlider](#ddx_fieldslider)
 


