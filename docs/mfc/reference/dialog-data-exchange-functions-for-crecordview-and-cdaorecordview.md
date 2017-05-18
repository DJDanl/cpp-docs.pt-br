---
title: "Funções de troca de dados de caixa de diálogo para CRecordView e CDaoRecordView | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- AFXDAO/DDX_FieldCBIndex
- AFXDAO/DDX_FieldCBString
- AFXDAO/DDX_FieldCBStringExact
- AFXDAO/DDX_FieldCheck
- AFXDAO/DDX_FieldLBIndex
- AFXDAO/DDX_FieldLBString
- AFXDAO/DDX_FieldLBStringExact
- AFXDAO/DDX_FieldRadio
- AFXDAO/DDX_FieldScroll
- AFXDAO/DDX_FieldText
dev_langs:
- C++
helpviewer_keywords:
- DDX_Field functions
- ODBC [C++], dialog data exchange (DDX) support
- DDX (dialog data exchange) [C++], database support
- DDX (dialog data exchange) [C++], functions
- databases [C++], dialog data exchange (DDX) support
- DAO [C++], dialog data exchange (DDX) support
ms.assetid: 0d8cde38-3a2c-4100-9589-ac80a7b1ce91
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: b943ef8dd652df061965fe81ecc9c08115636141
ms.openlocfilehash: c6256e6a510e3640bfdfd43cace5afbdec72b849
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="dialog-data-exchange-functions-for-crecordview-and-cdaorecordview"></a>Funções da troca de dados da caixa de diálogo para CRecordView e CDaoRecordView
Este tópico lista as funções DDX_Field usadas para trocar dados entre um [CRecordset](../../mfc/reference/crecordset-class.md) e um [CRecordView](../../mfc/reference/crecordview-class.md) formulário ou uma [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) e um [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) formulário.  
  
> [!NOTE]
>  Funções DDX_Field são como funções DDX que eles trocam dados com controles em um formulário. Mas, ao contrário de DDX, eles trocam dados com os campos do objeto de conjunto de registros associado do modo de exibição em vez de com campos da própria exibição do registro. Para obter mais informações, consulte classes `CRecordView` e `CDaoRecordView`.  
  
### <a name="ddxfield-functions"></a>Funções DDX_Field  
  
|||  
|-|-|  
|[DDX_FieldCBIndex](#ddx_fieldcbindex)|Transfere dados de número inteiro entre um membro de dados de campo do conjunto de registros e o índice da seleção atual em uma caixa de combinação em uma [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md).|  
|[DDX_FieldCBString](#ddx_fieldcbstring)|Transferências de `CString` caixa de dados entre um membro de dados de campo do conjunto de registros e o controle de edição de uma combinação um `CRecordView` ou `CDaoRecordView`. Ao mover dados do conjunto de registros para o controle, essa função seleciona o item na caixa de combinação que começa com os caracteres na cadeia de caracteres especificada.|  
|[DDX_FieldCBStringExact](#ddx_fieldcbstringexact)|Transferências de `CString` caixa de dados entre um membro de dados de campo do conjunto de registros e o controle de edição de uma combinação um `CRecordView` ou `CDaoRecordView`. Ao mover dados do conjunto de registros para o controle, essa função seleciona o item na caixa de combinação que coincide com a cadeia de caracteres especificada.|  
|[DDX_FieldCheck](#ddx_fieldcheck)|Transfere dados Boolean entre um membro de dados de campo do conjunto de registros e uma caixa de seleção em uma `CRecordView` ou `CDaoRecordView`.|  
|[DDX_FieldLBIndex](#ddx_fieldlbindex)|Transfere dados de número inteiro entre um membro de dados de campo do conjunto de registros e o índice da seleção atual em uma caixa de lista em uma `CRecordView` ou `CDaoRecordView`.|  
|[DDX_FieldLBString](#ddx_fieldlbstring)|Gerencia a transferência de [CString](../../atl-mfc-shared/reference/cstringt-class.md) dados entre um controle de caixa de listagem e os membros de um conjunto de registros de dados de campo. Ao mover dados do conjunto de registros para o controle, essa função seleciona o item na caixa de listagem que começa com os caracteres na cadeia de caracteres especificada.|  
|[DDX_FieldLBStringExact](#ddx_fieldlbstringexact)|Gerencia a transferência de `CString` dados entre um controle de caixa de listagem e os membros de um conjunto de registros de dados de campo. Ao mover dados do conjunto de registros para o controle, essa função seleciona o primeiro item que corresponda exatamente a cadeia de caracteres especificada.|  
|[DDX_FieldRadio](#ddx_fieldradio)|Transfere dados de número inteiro entre um membro de dados de campo do conjunto de registros e um grupo de botões de opção em um `CRecordView` ou `CDaoRecordView`.|  
|[DDX_FieldScroll](#ddx_fieldscroll)|Define ou obtém a posição de rolagem de um controle de barra de rolagem em uma `CRecordView` ou `CDaoRecordView`. Chamar a partir de seu [DoFieldExchange](../../mfc/reference/cdaorecordset-class.md#dofieldexchange) função.|  
|[DDX_FieldSlider](#ddx_fieldslider)|Sincroniza a posição de miniatura de um controle deslizante em uma exibição de registro e um `int` membro de dados do campo de um conjunto de registros. |
|[DDX_FieldText](#ddx_fieldtext)|Versões sobrecarregadas estão disponíveis para a transferência de `int`, **UINT**, **longo**, `DWORD`, [CString](../../atl-mfc-shared/reference/cstringt-class.md), **float**, **duplas**, **curto**, [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md), e [COleCurrency](../../mfc/reference/colecurrency-class.md) caixa dados entre um membro de dados de campo do conjunto de registros e uma edição de um `CRecordView` ou `CDaoRecordView`.|  
  
##  <a name="ddx_fieldcbindex"></a>DDX_FieldCBIndex  
 O `DDX_FieldCBIndex` função sincroniza o índice do item selecionado na lista de controle de caixa de um controle de caixa de combinação em uma exibição de registro e um `int` membro de dados do campo de um conjunto de registros associado à exibição de registro.  
  
```  
void AFXAPI DDX_FieldCBIndex(
    CDataExchange* pDX,    
    int nIDC,   
    int& index,  
    CRecordset* pRecordset);

void AFXAPI DDX_FieldCBIndex(
    CDataExchange* pDX,    
    int nIDC,   
    int& index,  
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *índice*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Ao mover dados do conjunto de registros para o controle, essa função define a seleção no controle com base no valor especificado em *índice*. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, o MFC define o valor do índice para 0. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio ou se nenhum item for selecionado, o campo de conjunto de registros é definido como 0.  
  
 Use a primeira versão, se você estiver trabalhando com as classes com base em ODBC. Use a segunda versão se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral. O exemplo seria semelhante para `DDX_FieldCBIndex`.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  

##  <a name="ddx_fieldcbstring"></a>DDX_FieldCBString  
 O `DDX_FieldCBString` função gerencia a transferência de [CString](../../atl-mfc-shared/reference/cstringt-class.md) dados entre o controle de edição de um controle de caixa de combinação em uma exibição de registro e um `CString` membro de dados do campo de um conjunto de registros associado à exibição de registro.  
  
```  
void AFXAPI DDX_FieldCBString(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldCBString(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *value*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Ao mover dados do conjunto de registros para o controle, esta função define a seleção atual na caixa de combinação para a primeira linha que começa com os caracteres na cadeia de caracteres especificada em *valor*. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, nenhuma seleção é removida da caixa de combinação e o controle de edição da caixa de combinação está definido como vazio. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros é definido como Null se permite que o campo.  
  
 Use a primeira versão, se você estiver trabalhando com as classes com base em ODBC. Use a segunda versão se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral. O exemplo inclui uma chamada para `DDX_FieldCBString`.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
## <a name="ddx_fieldcbstringexact"></a>DDX_FieldCBStringExact  
 O `DDX_FieldCBStringExact` função gerencia a transferência de [CString](../../atl-mfc-shared/reference/cstringt-class.md) dados entre o controle de edição de um controle de caixa de combinação em uma exibição de registro e um `CString` membro de dados do campo de um conjunto de registros associado à exibição de registro.  
  
```  
void AFXAPI DDX_FieldCBStringExact(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldCBStringExact(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *value*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Ao mover dados do conjunto de registros para o controle, esta função define a seleção atual na caixa de combinação para a primeira linha que coincide com a cadeia de caracteres especificada em *valor*. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é NULL, nenhuma seleção é removida da caixa de combinação e caixa de edição da caixa de combinação é definida como vazio. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros é definido como NULL.  
  
 Use a primeira versão, se você estiver trabalhando com as classes com base em ODBC. Use a segunda versão se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral. Chamadas para `DDX_FieldCBStringExact` seria semelhante.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="ddx_fieldcheck"></a>DDX_FieldCheck  
 O `DDX_FieldCheck` função gerencia a transferência de `int` dados entre um controle de caixa de seleção em uma caixa de diálogo, exibição ou objeto de exibição de controle de formulário e um `int` membro de dados da caixa de diálogo, a exibição de formulário ou o objeto de exibição de controle.  
  
```  
void AFXAPI DDX_FieldCheck(
    CDataExchange* pDX,    
    int nIDC,   
    int& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldCheck(
    CDataExchange* pDX,    
    int nIDC,   
    int& value,   
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de recurso do controle de caixa de seleção associada com a propriedade de controle.  
  
 *value*  
 Uma referência a uma variável de membro do objeto de exibição de controle com o qual os dados são trocados, exibição de formulário ou caixa de diálogo.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Quando `DDX_FieldCheck` é chamado, *valor* está definido para o estado atual do controle de caixa de seleção, ou o estado do controle é definido como *valor*, dependendo da direção da transferência.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md).  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="ddx_fieldlbindex"></a>DDX_FieldLBIndex  
 O `DDX_FieldLBIndex` função sincroniza o índice do item selecionado em um controle de caixa de lista em uma exibição de registro e um `int` membro de dados do campo de um conjunto de registros associado à exibição de registro.  
  
```  
void AFXAPI DDX_FieldLBIndex(
    CDataExchange* pDX,    
    int nIDC,   
    int& index,  
    CRecordset* pRecordset);

void AFXAPI DDX_FieldLBIndex(
    CDataExchange* pDX,    
    int nIDC,   
    int& index,  
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *índice*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Ao mover dados do conjunto de registros para o controle, essa função define a seleção no controle com base no valor especificado em *índice*. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, o MFC define o valor do índice para 0. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros é definido como 0.  
  
 Use a primeira versão, se você estiver trabalhando com as classes com base em ODBC. Use a segunda versão se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="ddx_fieldlbstring"></a>DDX_FieldLBString  
 O `DDX_FieldLBString` copia a seleção atual de um controle de caixa de lista em uma exibição de registro para um [CString](../../atl-mfc-shared/reference/cstringt-class.md) membro de dados do campo de um conjunto de registros associado à exibição de registro.  
  
```  
void AFXAPI DDX_FieldLBString(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldLBString(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *value*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Na direção inversa, esta função define a seleção atual na caixa de listagem para a primeira linha que começa com os caracteres na cadeia de caracteres especificado por *valor*. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, nenhuma seleção será removida da caixa de listagem. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros é definido como Null.  
  
 Use a primeira versão, se você estiver trabalhando com as classes com base em ODBC. Use a segunda versão se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral. Chamadas para `DDX_FieldLBString` seria semelhante.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="ddx_fieldlbstringexact"></a>DDX_FieldLBStringExact  
 O `DDX_FieldLBStringExact` função copia a seleção atual de um controle de caixa de lista em uma exibição de registro para um [CString](../../atl-mfc-shared/reference/cstringt-class.md) membro de dados do campo de um conjunto de registros associado à exibição de registro.  
  
```  
void AFXAPI DDX_FieldLBStringExact(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldLBStringExact(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *value*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Na direção inversa, esta função define a seleção atual na caixa de listagem para a primeira linha que coincide com a cadeia de caracteres especificada em *valor*. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, nenhuma seleção será removida da caixa de listagem. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros é definido como Null.  
  
 Use a primeira versão, se você estiver trabalhando com as classes com base em ODBC. Use a segunda versão se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral. Chamadas para `DDX_FieldLBStringExact` seria semelhante.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="ddx_fieldradio"></a>DDX_FieldRadio  
 O `DDX_FieldRadio` função associa um com base em zero `int` variável de membro do conjunto de registros da exibição de um registro com o botão de opção selecionado no momento em um grupo de botões de opção na exibição do registro.  
  
```  
void AFXAPI DDX_FieldRadio(
    CDataExchange* pDX,    
    int nIDC,   
    int& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldRadio(
    CDataExchange* pDX,    
    int nIDC,   
    int& value,   
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID do primeiro em um grupo (com estilo **WS_GROUP**) de controles de botão de opção adjacente no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *value*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Ao transferir do campo de conjunto de registros para o modo de exibição, essa função ativa o *enésimo* botão de opção (com base em zero) e desativa os outros botões. Na direção inversa, essa função define o campo de conjunto de registros para o número ordinal do botão de opção é no momento (marcado). Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, nenhum botão é selecionado. Em uma transferência de controle para o conjunto de registros, se nenhum controle é selecionado, o campo de conjunto de registros é definido como Null se o campo permite que.  
  
 Use a primeira versão, se você estiver trabalhando com as classes com base em ODBC. Use a segunda versão se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral. Chamadas para `DDX_FieldRadio` seria semelhante.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
  
##  <a name="ddx_fieldscroll"></a>DDX_FieldScroll  
 O `DDX_FieldScroll` função sincroniza a posição de rolagem de um controle de barra de rolagem em uma exibição de registro e um `int` membro de dados do campo de um conjunto de registros associado com a exibição de registro (ou com qualquer variável de inteiro que você escolher para mapeá-la para).  
  
```  
void AFXAPI DDX_FieldScroll(
    CDataExchange* pDX,    
    int nIDC,   
    int& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldScroll(
    CDataExchange* pDX,    
    int nIDC,   
    int& value,   
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 *nIDC\**  
 A ID do primeiro em um grupo (com estilo **WS_GROUP**) de controles de botão de opção adjacente no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *value*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados.  
  
### <a name="remarks"></a>Comentários  
 Ao mover dados do conjunto de registros para o controle, esta função define a posição de rolagem do controle da barra de rolagem para o valor especificado em *valor*. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, o controle de barra de rolagem é definido como 0. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio, o valor do campo de conjunto de registros é 0.  
  
 Use a primeira versão, se você estiver trabalhando com as classes com base em ODBC. Use a segunda versão se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral. Chamadas para `DDX_FieldScroll` seria semelhante.  
  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  

  ## <a name="nameddxfieldslidera--ddxfieldslider"></a>Name = "ddx_fieldslider" ></a> DDX_FieldSlider
O `DDX_FieldSlider` função sincroniza a posição de miniatura de um controle deslizante em uma exibição de registro e um `int` membro de dados do campo de um conjunto de registros associado com a exibição de registro (ou com qualquer variável de inteiro que você escolher para mapeá-la para).  
   
### <a name="syntax"></a>Sintaxe  
  ```
   void AFXAPI DDX_FieldSlider(  
       CDataExchange* pDX,  
       int nIDC,  
       int& value,  
       CRecordset* pRecordset );  

void AFXAPI DDX_FieldSlider(  
     CDataExchange* pDX,  
     int nIDC,  
     int& value,  
     CDaoRecordset* pRecordset );  
```
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de recurso do controle deslizante.  
  
 *value*  
 Uma referência para o valor a ser trocadas. Este parâmetro contém ou será usado para definir a posição de miniatura atual do controle deslizante.  
  
 `pRecordset`  
 Um ponteiro para o associado `CRecordset` ou `CDaoRecordset` objeto com o qual os dados são trocados.  
   
### <a name="remarks"></a>Comentários  
 Ao mover dados do conjunto de registros para o controle deslizante, essa função define a posição do controle deslizante para o valor especificado em *valor*. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, posição do controle deslizante está definida como 0. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio, o valor do campo de conjunto de registros é 0.  
  
 `DDX_FieldSlider`não trocam informações de intervalo com controles deslizantes capazes de configurar um intervalo, em vez de simplesmente uma posição.  
  
 Se você estiver trabalhando com as classes com base em ODBC, use a primeira substituição da função. Use a substituição de segundo com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para `CRecordView` e `CDaoRecordView` campos, consulte [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter informações sobre controles deslizantes, consulte [usando CSliderCtrl](../using-csliderctrl.md).  
   
### <a name="example"></a>Exemplo  
 Consulte [DDX_FieldText](#ddx_fieldtext) para obter um exemplo de DDX_Field geral. Chamadas para `DDX_FieldSlider` seria semelhante.  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
  
##  <a name="ddx_fieldtext"></a>DDX_FieldText  
 O `DDX_FieldText` função gerencia a transferência de `int`, **curto**, **longo**, `DWORD`, [CString](../../atl-mfc-shared/reference/cstringt-class.md), **float**, **duplas**, **BOOL**, ou **bytes** dados entre um controle de caixa de edição e os membros de um conjunto de registros de dados de campo.  
  
```  
void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    BYTE& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    int& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    UINT& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    long& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    DWORD& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    float& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    double& value,   
    CRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    short& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    BOOL& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    BYTE& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    long& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    DWORD& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    CString& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    float& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    double& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    COleDateTime& value,   
    CDaoRecordset* pRecordset);

void AFXAPI DDX_FieldText(
    CDataExchange* pDX,    
    int nIDC,   
    COleCurrency& value,   
    CDaoRecordset* pRecordset);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDX`  
 Um ponteiro para um [CDataExchange](../../mfc/reference/cdataexchange-class.md) objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.  
  
 `nIDC`  
 A ID de um controle no [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) objeto.  
  
 *value*  
 Uma referência a um membro de dados do campo associada `CRecordset` ou `CDaoRecordset` objeto. O tipo de dados do valor depende de qual das versões sobrecarregadas `DDX_FieldText` você usar.  
  
 `pRecordset`  
 Um ponteiro para o [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objeto com o qual os dados são trocados. Este ponteiro permite `DDX_FieldText` para detectar e definir valores Null.  
  
### <a name="remarks"></a>Comentários  
 Para [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) objetos, `DDX_FieldText` também gerencia a transferência [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md), e [COleCurrency](../../mfc/reference/colecurrency-class.md) valores. Um controle de caixa de edição vazia indica um valor nulo. Em uma transferência de conjunto de registros para o controle, se o campo de conjunto de registros é Null, a caixa de edição é definida como vazia. Em uma transferência de controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros é definido como Null.  
  
 Use as versões com [CRecordset](../../mfc/reference/crecordset-class.md) parâmetros se você estiver trabalhando com as classes com base em ODBC. Use as versões com [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) parâmetros se você estiver trabalhando com as classes com base em DAO.  
  
 Para obter mais informações sobre DDX, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e obter mais informações sobre DDX para [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) campos, consulte o artigo [exibições de registro](../../data/record-views-mfc-data-access.md).  
  
### <a name="example"></a>Exemplo  
 O seguinte `DoDataExchange` funcionar para um [CRecordView](../../mfc/reference/crecordview-class.md) contém `DDX_FieldText` chamadas de função para três tipos de dados: `IDC_COURSELIST` é uma caixa de combinação; os outros dois controles são caixas de edição. Para a programação de DAO o *m_pSet* parâmetro é um ponteiro para um [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).  
  
 [!code-cpp[NVC_MFCDatabase º 43](../../mfc/codesnippet/cpp/dialog-data-exchange-functions-for-crecordview-and-cdaorecordview_1.cpp)]  

  
### <a name="requirements"></a>Requisitos  
  **Cabeçalho** afxdao.h  
    
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

