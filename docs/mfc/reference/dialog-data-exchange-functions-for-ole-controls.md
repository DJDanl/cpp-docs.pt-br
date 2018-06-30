---
title: Funções de troca de dados de caixa de diálogo para controles OLE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- OLE controls [MFC], DDX functions
- DDX (dialog data exchange), OLE support
ms.assetid: 7ef1f288-ff65-40d4-aad2-5497bc00bb27
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 542afe8ba67e1d9c6138998320483a964a08724a
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37121819"
---
# <a name="dialog-data-exchange-functions-for-ole-controls"></a>Funções da troca de dados da caixa de diálogo para controles OLE
Este tópico lista as funções DDX_OC usadas para trocar dados entre uma propriedade de um controle OLE em uma caixa de diálogo, o modo de exibição de formulário ou o objeto de exibição de controle e um membro de dados do objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
### <a name="ddxoc-functions"></a>Funções DDX_OC  
  
|||  
|-|-|  
|[DDX_OCBool](#ddx_ocbool)|Gerencia a transferência de **BOOL** dados entre uma propriedade de um controle OLE e um **BOOL** membro de dados.|  
|[DDX_OCBoolRO](#ddx_ocboolro)|Gerencia a transferência de **BOOL** dados entre uma propriedade somente leitura de um controle OLE e um **BOOL** membro de dados.|  
|[DDX_OCColor](#ddx_occolor)|Gerencia a transferência de **OLE_COLOR** dados entre uma propriedade de um controle OLE e um **OLE_COLOR** membro de dados.|  
|[DDX_OCColorRO](#ddx_occolorro)|Gerencia a transferência de **OLE_COLOR** dados entre uma propriedade somente leitura de um controle OLE e um **OLE_COLOR** membro de dados.|  
|[DDX_OCFloat](#ddx_ocfloat)|Gerencia a transferência de **float** (ou **duplo**) dados entre uma propriedade de um controle OLE e um **float** (ou **duplo**) membro de dados.|  
|[DDX_OCFloatRO](#ddx_ocfloatro)|Gerencia a transferência de **float** (ou **duplo**) dados entre uma propriedade somente leitura de um controle OLE e um **float** (ou **duplo**) dados membro.|  
|[DDX_OCInt](#ddx_ocint)|Gerencia a transferência de **int** (ou **longo**) dados entre uma propriedade de um controle OLE e um **int** (ou **longo**) membro de dados.|  
|[DDX_OCIntRO](#ddx_ocintro)|Gerencia a transferência de **int** (ou **longo**) dados entre uma propriedade somente leitura de um controle OLE e um **int** (ou **longo**) membro de dados.|  
|[DDX_OCShort](#ddx_ocshort)|Gerencia a transferência de **curto** dados entre uma propriedade de um controle OLE e um **curto** membro de dados.|  
|[DDX_OCShortRO](#ddx_ocshortro)|Gerencia a transferência de **curto** dados entre uma propriedade somente leitura de um controle OLE e um **curto** membro de dados.|  
|[DDX_OCText](#ddx_octext)|Gerencia a transferência de **CString** dados entre uma propriedade de um controle OLE e um **CString** membro de dados.|  
|[DDX_OCTextRO](#ddx_octextro)|Gerencia a transferência de **CString** dados entre uma propriedade somente leitura de um controle OLE e um **CString** membro de dados.|  
  
##  <a name="ddx_ocbool"></a>  DDX_OCBool  
 O `DDX_OCBool` função gerencia a transferência de **BOOL** dados entre uma propriedade de um controle OLE em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um **BOOL** membro de dados da caixa de diálogo, o modo de exibição de formulário, ou objeto de exibição de controle.  
  
```   
void AFXAPI DDX_OCBool(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    BOOL& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho:** afxdisp.h  
  
##  <a name="ddx_ocboolro"></a>  DDX_OCBoolRO  
 O `DDX_OCBoolRO` função gerencia a transferência de **BOOL** dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um **BOOL** membro de dados de caixa de diálogo exibição de formulário, ou o objeto de exibição de controle.  
  
```   
void AFXAPI DDX_OCBoolRO(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    BOOL& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_occolor"></a>  DDX_OCColor  
 O `DDX_OCColor` função gerencia a transferência de dados OLE_COLOR entre uma propriedade de um controle OLE em uma caixa de diálogo, o modo de exibição de formulário, ou o objeto de exibição de controle e um membro de dados OLE_COLOR da caixa de diálogo, exibição de formulário ou controle de objeto de exibição.  
  
```   
void AFXAPI DDX_OCColor(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    OLE_COLOR& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_occolorro"></a>  DDX_OCColorRO  
 O `DDX_OCColorRO` função gerencia a transferência de dados OLE_COLOR entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, o modo de exibição de formulário, ou o objeto de exibição de controle e um membro de dados OLE_COLOR da caixa de diálogo, exibição de formulário ou controle de objeto de exibição.  
  
```   
void AFXAPI DDX_OCColorRO(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    OLE_COLOR& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_ocfloat"></a>  DDX_OCFloat  
 O `DDX_OCFloat` função gerencia a transferência de **float** (ou **duplo**) dados entre uma propriedade de um controle OLE em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um **float** (ou **duplo**) membro de dados da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle.  
  
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
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_ocfloatro"></a>  DDX_OCFloatRO  
 O `DDX_OCFloatRO` função gerencia a transferência de **float** (ou **duplo**) dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um  **float** (ou **duplo**) membro de dados da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle.  
  
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
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_ocint"></a>  DDX_OCInt  
 O `DDX_OCInt` função gerencia a transferência de **int** (ou **longo**) dados entre uma propriedade de um controle OLE em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um **int**(ou **longo**) membro de dados da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle.  
  
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
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_ocintro"></a>  DDX_OCIntRO  
 O `DDX_OCIntRO` função gerencia a transferência de **int** (ou **longo**) dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um **int** (ou **longo**) membro de dados da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle.  
  
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
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_ocshort"></a>  DDX_OCShort  
 O `DDX_OCShort` função gerencia a transferência de dados curto entre uma propriedade de um controle OLE em uma caixa de diálogo, o modo de exibição de formulário, ou o objeto de exibição de controle e um membro de dados curto da caixa de diálogo, exibição de formulário ou controle de objeto de exibição.  
  
```   
void AFXAPI DDX_OCShort(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    short& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_ocshortro"></a>  DDX_OCShortRO  
 O `DDX_OCShortRO` função gerencia a transferência de dados curto entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, o modo de exibição de formulário, ou o objeto de exibição de controle e um membro de dados curto da caixa de diálogo, exibição de formulário ou controle de objeto de exibição.  
  
```   
void AFXAPI DDX_OCShortRO(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    short& value);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_octext"></a>  DDX_OCText  
 O **DDX_OCText** função gerencia a transferência de **CString** dados entre uma propriedade de um controle OLE em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um **CString** dados membro da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle.  
  
```   
void AFXAPI DDX_OCText(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    CString& value); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDX*  
 Um ponteiro para um **CDataExchange** objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h  
  
##  <a name="ddx_octextro"></a>  DDX_OCTextRO  
 O `DDX_OCTextRO` função gerencia a transferência de `CString` dados entre uma propriedade somente leitura de um controle OLE em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `CString` membro de dados da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle.  
  
```  
void AFXAPI DDX_OCTextRO(
    CDataExchange* pDX,  
    int nIDC,  
    DISPID dispid,  
    CString& value); 
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDX*  
 Um ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC*  
 A ID de um controle OLE no objeto de exibição de controle, exibição de formulário ou caixa de diálogo.  
  
 *DISPID*  
 A ID de expedição de uma propriedade do controle.  
  
 *value*  
 Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou controle exibir objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  

### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdisp.h
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
