---
title: "Funções de troca de dados de caixa de diálogo para controles OLE | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros.data
dev_langs:
- C++
helpviewer_keywords:
- OLE controls, DDX functions
- DDX (dialog data exchange), OLE support
ms.assetid: 7ef1f288-ff65-40d4-aad2-5497bc00bb27
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 0f8821051cd790d26d190c23db333ccebc9dc9d6
ms.lasthandoff: 02/25/2017

---
# <a name="dialog-data-exchange-functions-for-ole-controls"></a>Funções da troca de dados da caixa de diálogo para controles OLE
Este tópico lista as funções DDX_OC usadas para trocar dados entre uma propriedade de um controle OLE em uma caixa de diálogo, o modo de exibição de formulário ou objeto de exibição de controle e um membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
### <a name="ddxoc-functions"></a>Funções DDX_OC  
  
|||  
|-|-|  
|[DDX_OCBool](#ddx_ocbool)|Gerencia a transferência de **BOOL** dados entre uma propriedade de um controle OLE e um **BOOL** membro de dados.|  
|[DDX_OCBoolRO](#ddx_ocboolro)|Gerencia a transferência de **BOOL** dados entre uma propriedade somente leitura de um controle OLE e um **BOOL** membro de dados.|  
|[DDX_OCColor](#ddx_occolor)|Gerencia a transferência de **OLE_COLOR** dados entre uma propriedade de um controle OLE e um **OLE_COLOR** membro de dados.|  
|[DDX_OCColorRO](#ddx_occolorro)|Gerencia a transferência de **OLE_COLOR** dados entre uma propriedade somente leitura de um controle OLE e um **OLE_COLOR** membro de dados.|  
|[DDX_OCFloat](#ddx_ocfloat)|Gerencia a transferência de **float** (ou **duplo**) dados entre uma propriedade de um controle OLE e um **float** (ou **duplo**) membro de dados.|  
|[DDX_OCFloatRO](#ddx_ocfloatro)|Gerencia a transferência de **float** (ou **duplo**) dados entre uma propriedade somente leitura de um controle OLE e um **float** (ou **duplo**) membro de dados.|  
|[DDX_OCInt](#ddx_ocint)|Gerencia a transferência de `int` (ou **longo**) dados entre uma propriedade de um controle OLE e um `int` (ou **longo**) membro de dados.|  
|[DDX_OCIntRO](#ddx_ocintro)|Gerencia a transferência de `int` (ou **longo**) dados entre uma propriedade somente leitura de um controle OLE e um `int` (ou **longo**) membro de dados.|  
|[DDX_OCShort](#ddx_ocshort)|Gerencia a transferência de **curto** dados entre uma propriedade de um controle OLE e um **curto** membro de dados.|  
|[DDX_OCShortRO](#ddx_ocshortro)|Gerencia a transferência de **curto** dados entre uma propriedade somente leitura de um controle OLE e um **curto** membro de dados.|  
|[DDX_OCText](#ddx_octext)|Gerencia a transferência de **CString** dados entre uma propriedade de um controle OLE e um **CString** membro de dados.|  
|[DDX_OCTextRO](#ddx_octextro)|Gerencia a transferência de **CString** dados entre uma propriedade somente leitura de um controle OLE e um **CString** membro de dados.|  
  
##  <a name="a-nameddxocboola--ddxocbool"></a><a name="ddx_ocbool"></a>DDX_OCBool  
 O `DDX_OCBool` função gerencia a transferência de **BOOL** dados entre uma propriedade de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um **BOOL** membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
void AFXAPI DDX_OCBool(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    BOOL& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxocboolroa--ddxocboolro"></a><a name="ddx_ocboolro"></a>DDX_OCBoolRO  
 O `DDX_OCBoolRO` função gerencia a transferência de **BOOL** dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um **BOOL** membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
void AFXAPI DDX_OCBoolRO(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    BOOL& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxoccolora--ddxoccolor"></a><a name="ddx_occolor"></a>DDX_OCColor  
 O `DDX_OCColor` função gerencia a transferência de **OLE_COLOR** dados entre uma propriedade de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um **OLE_COLOR** membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
void AFXAPI DDX_OCColor(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    OLE_COLOR& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxoccolorroa--ddxoccolorro"></a><a name="ddx_occolorro"></a>DDX_OCColorRO  
 O `DDX_OCColorRO` função gerencia a transferência de **OLE_COLOR** dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um **OLE_COLOR** membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
void AFXAPI DDX_OCColorRO(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    OLE_COLOR& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxocfloata--ddxocfloat"></a><a name="ddx_ocfloat"></a>DDX_OCFloat  
 O `DDX_OCFloat` função gerencia a transferência de **float** (ou **duplo**) dados entre uma propriedade de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um **float** (ou **duplo**) membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
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
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxocfloatroa--ddxocfloatro"></a><a name="ddx_ocfloatro"></a>DDX_OCFloatRO  
 O `DDX_OCFloatRO` função gerencia a transferência de **float** (ou **duplo**) dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um **float** (ou **duplo**) membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
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
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxocinta--ddxocint"></a><a name="ddx_ocint"></a>DDX_OCInt  
 O `DDX_OCInt` função gerencia a transferência de `int` (ou **longo**) dados entre uma propriedade de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um `int` (ou **longo**) membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
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
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxocintroa--ddxocintro"></a><a name="ddx_ocintro"></a>DDX_OCIntRO  
 O `DDX_OCIntRO` função gerencia a transferência de `int` (ou **longo**) dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um `int` (ou **longo**) membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
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
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxocshorta--ddxocshort"></a><a name="ddx_ocshort"></a>DDX_OCShort  
 O `DDX_OCShort` função gerencia a transferência de dados curto entre uma propriedade de um controle OLE em uma caixa de diálogo modo de exibição de formulário, ou o objeto de exibição de controle e um membro de dados curto da caixa de diálogo, exibição de formulário ou controle de objeto de exibição.  
  
```   
void AFXAPI DDX_OCShort(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    short& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxocshortroa--ddxocshortro"></a><a name="ddx_ocshortro"></a>DDX_OCShortRO  
 O `DDX_OCShortRO` função gerencia a transferência de dados curto entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo modo de exibição de formulário, ou o objeto de exibição de controle e um membro de dados curto da caixa de diálogo, exibição de formulário ou controle de objeto de exibição.  
  
```   
void AFXAPI DDX_OCShortRO(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    short& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxoctexta--ddxoctext"></a><a name="ddx_octext"></a>DDX_OCText  
 O **DDX_OCText** função gerencia a transferência de **CString** dados entre uma propriedade de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um **CString** membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```   
void AFXAPI DDX_OCText(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    CString& value); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um **CDataExchange** objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="a-nameddxoctextroa--ddxoctextro"></a><a name="ddx_octextro"></a>DDX_OCTextRO  
 O `DDX_OCTextRO` função gerencia a transferência de `CString` dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo exibição ou objeto de exibição de controle de formulário e um `CString` membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
```  
void AFXAPI DDX_OCTextRO(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    CString& value); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um `CDataExchange` objeto. O framework fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 `dispid`  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exiba o objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

