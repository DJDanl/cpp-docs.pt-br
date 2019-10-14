---
title: Funções da troca de dados da caixa de diálogo para CRecordView e CDaoRecordView
ms.date: 09/17/2019
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
helpviewer_keywords:
- DDX_Field functions [MFC]
- ODBC [MFC], dialog data exchange (DDX) support
- DDX (dialog data exchange) [MFC], database support
- DDX (dialog data exchange) [MFC], functions
- databases [MFC], dialog data exchange (DDX) support
- DAO [MFC], dialog data exchange (DDX) support
ms.assetid: 0d8cde38-3a2c-4100-9589-ac80a7b1ce91
ms.openlocfilehash: 078e0f450514881084786086683ac026e15ea8be
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71095773"
---
# <a name="dialog-data-exchange-functions-for-crecordview-and-cdaorecordview"></a>Funções da troca de dados da caixa de diálogo para CRecordView e CDaoRecordView

Este tópico lista as funções DDX_Field usadas para trocar dados entre um formulário [CRecordset](../../mfc/reference/crecordset-class.md) e um [CRecordView](../../mfc/reference/crecordview-class.md) ou um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) e um formulário [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) . O DAO é usado com bancos de dados do Access e tem suporte por meio do Office 2013. 3,6 é a versão final e é considerada obsoleta.

> [!NOTE]
>  As funções DDX_Field são como as funções campo DDX no que trocam dados com controles em um formulário. Mas, ao contrário de campo DDX, eles trocam dados com os campos do objeto Recordset associado do modo de exibição em vez de campos da exibição de registro em si. Para obter mais informações, consulte `CRecordView` classes `CDaoRecordView`e.

### <a name="ddx_field-functions"></a>Funções DDX_Field

|||
|-|-|
|[DDX_FieldCBIndex](#ddx_fieldcbindex)|Transfere dados inteiros entre um membro de dados de campo do conjunto de registros e o índice da seleção atual em uma caixa de combinação em um [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md).|
|[DDX_FieldCBString](#ddx_fieldcbstring)|Transfere `CString` dados entre um membro de dados de campo do conjunto de registros e o controle de `CRecordView` edição de uma caixa de combinação em um ou `CDaoRecordView`. Ao mover dados do conjunto de registros para o controle, essa função seleciona o item na caixa de combinação que começa com os caracteres na cadeia de caracteres especificada.|
|[DDX_FieldCBStringExact](#ddx_fieldcbstringexact)|Transfere `CString` dados entre um membro de dados de campo do conjunto de registros e o controle de `CRecordView` edição de uma caixa de combinação em um ou `CDaoRecordView`. Ao mover dados do conjunto de registros para o controle, essa função seleciona o item na caixa de combinação que corresponde exatamente à cadeia de caracteres especificada.|
|[DDX_FieldCheck](#ddx_fieldcheck)|Transfere dados boolianos entre um membro de dados de campo do conjunto de `CRecordView` registros `CDaoRecordView`e uma caixa de seleção em um ou.|
|[DDX_FieldLBIndex](#ddx_fieldlbindex)|Transfere dados inteiros entre um membro de dados de campo do conjunto de registros e o índice da seleção atual em `CRecordView` uma `CDaoRecordView`caixa de listagem em um ou.|
|[DDX_FieldLBString](#ddx_fieldlbstring)|Gerencia a transferência de dados de [CString](../../atl-mfc-shared/reference/cstringt-class.md) entre um controle de caixa de listagem e os membros de dados de campo de um conjunto de registros. Ao mover dados do conjunto de registros para o controle, essa função seleciona o item na caixa de listagem que começa com os caracteres na cadeia de caracteres especificada.|
|[DDX_FieldLBStringExact](#ddx_fieldlbstringexact)|Gerencia a transferência de `CString` dados entre um controle de caixa de listagem e os membros de dados de campo de um conjunto de registros. Ao mover dados do conjunto de registros para o controle, essa função seleciona o primeiro item que corresponde exatamente à cadeia de caracteres especificada.|
|[DDX_FieldRadio](#ddx_fieldradio)|Transfere dados inteiros entre um membro de dados de campo do conjunto de registros e um `CRecordView` grupo `CDaoRecordView`de botões de opção em um ou.|
|[DDX_FieldScroll](#ddx_fieldscroll)|Define ou obtém a posição de rolagem de um controle de barra `CRecordView` de `CDaoRecordView`rolagem em um ou. Chame a partir de sua função [DoFieldExchange](../../mfc/reference/cdaorecordset-class.md#dofieldexchange) .|
|[DDX_FieldSlider](#ddx_fieldslider)|Sincroniza a posição de miniatura de um controle deslizante em uma exibição de registro `int` e um membro de dados de campo de um conjunto de registros. |
|[DDX_FieldText](#ddx_fieldtext)|As versões sobrecarregadas estão disponíveis para `int`transferência, **uint**, **longo**, `DWORD`, [CString](../../atl-mfc-shared/reference/cstringt-class.md), **float**, **Double**, **Short**, [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)e dados de [COleCurrency](../../mfc/reference/colecurrency-class.md) entre um membro de dados de campo do conjunto de registros e `CRecordView` uma `CDaoRecordView`caixa de edição em um ou.|

##  <a name="ddx_fieldcbindex"></a>  DDX_FieldCBIndex

A `DDX_FieldCBIndex` função sincroniza o índice do item selecionado no controle caixa de listagem de um controle de caixa de combinação em uma exibição de registro e `int` um membro de dados de campo de um conjunto de registros associado à exibição de registro.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*index*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, essa função define a seleção no controle com base no valor especificado em *índice*. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, o MFC definirá o valor do índice como 0. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio ou se nenhum item for selecionado, o campo conjunto de registros será definido como 0.

Use a primeira versão se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral. O exemplo seria semelhante para `DDX_FieldCBIndex`.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

##  <a name="ddx_fieldcbstring"></a>  DDX_FieldCBString

A `DDX_FieldCBString` função gerencia a transferência de dados de [CString](../../atl-mfc-shared/reference/cstringt-class.md) entre o controle de edição de um controle de caixa de combinação em uma `CString` exibição de registro e um membro de dados de campo de um conjunto de registros associado à exibição de registro.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*value*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, essa função define a seleção atual na caixa de combinação para a primeira linha que começa com os caracteres na cadeia de caracteres especificada em *valor*. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, qualquer seleção será removida da caixa de combinação e o controle de edição da caixa de combinação será definido como vazio. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo conjunto de registros será definido como nulo se o campo permitir.

Use a primeira versão se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral. O exemplo inclui uma chamada para `DDX_FieldCBString`.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

## <a name="ddx_fieldcbstringexact"></a>  DDX_FieldCBStringExact

A `DDX_FieldCBStringExact` função gerencia a transferência de dados de [CString](../../atl-mfc-shared/reference/cstringt-class.md) entre o controle de edição de um controle de caixa de combinação em uma `CString` exibição de registro e um membro de dados de campo de um conjunto de registros associado à exibição de registro.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*value*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, essa função define a seleção atual na caixa de combinação para a primeira linha que corresponde exatamente à cadeia de caracteres especificada em *valor*. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, qualquer seleção será removida da caixa de combinação e a caixa de edição da caixa de combinação será definida como vazia. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo conjunto de registros será definido como nulo.

Use a primeira versão se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral. As chamadas `DDX_FieldCBStringExact` para seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

##  <a name="ddx_fieldcheck"></a>  DDX_FieldCheck

A `DDX_FieldCheck` função gerencia a transferência de dados **int** entre um controle de caixa de seleção em uma caixa de diálogo, modo de exibição de formulário ou objeto de exibição de controle e um membro de dados **int** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de recurso do controle de caixa de seleção associada à propriedade de controle.

*value*<br/>
Uma referência a uma variável de membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com os quais os dados são trocados.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_FieldCheck` é chamado, o *valor* é definido como o estado atual do controle da caixa de seleção ou o estado do controle é definido como *valor*, dependendo da direção da transferência.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

##  <a name="ddx_fieldlbindex"></a>  DDX_FieldLBIndex

A `DDX_FieldLBIndex` função sincroniza o índice do item selecionado em um controle de caixa de listagem em uma exibição de registro e um membro de dados de campo **int** de um conjunto de registros associado à exibição de registro.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*index*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, essa função define a seleção no controle com base no valor especificado em *índice*. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, o MFC definirá o valor do índice como 0. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo conjunto de registros será definido como 0.

Use a primeira versão se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

##  <a name="ddx_fieldlbstring"></a>  DDX_FieldLBString

O `DDX_FieldLBString` copia a seleção atual de um controle de caixa de listagem em uma exibição de registro para um membro de dados de campo [CString](../../atl-mfc-shared/reference/cstringt-class.md) de um conjunto de registros associado à exibição de registro.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*value*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Na direção inversa, essa função define a seleção atual na caixa de listagem para a primeira linha que começa com os caracteres na cadeia de caracteres especificada pelo *valor*. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, qualquer seleção será removida da caixa de listagem. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo conjunto de registros será definido como nulo.

Use a primeira versão se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral. As chamadas `DDX_FieldLBString` para seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

##  <a name="ddx_fieldlbstringexact"></a>  DDX_FieldLBStringExact

A `DDX_FieldLBStringExact` função copia a seleção atual de um controle de caixa de listagem em uma exibição de registro para um membro de dados de campo [CString](../../atl-mfc-shared/reference/cstringt-class.md) de um conjunto de registros associado à exibição de registro.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*value*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Na direção inversa, essa função define a seleção atual na caixa de listagem para a primeira linha que corresponde exatamente à cadeia de caracteres especificada em *valor*. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, qualquer seleção será removida da caixa de listagem. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo conjunto de registros será definido como nulo.

Use a primeira versão se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral. As chamadas `DDX_FieldLBStringExact` para seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

##  <a name="ddx_fieldradio"></a>  DDX_FieldRadio

A `DDX_FieldRadio` função associa uma variável de membro **int** com base em zero do conjunto de registros de um modo de exibição de registro com o botão de opção selecionado no momento em um grupo de botões de opção na exibição de registro.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID do primeiro em um grupo (com WS_GROUP de estilo) de controles de botão de opção adjacentes no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*value*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Ao transferir do campo conjunto de registros para a exibição, essa função ativa o *enésimo* botão de opção (baseado em zero) e desativa os outros botões. Na direção inversa, essa função define o campo conjunto de registros como o número ordinal do botão de opção atualmente ativado (marcado). Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, nenhum botão será selecionado. Em uma transferência do controle para o conjunto de registros, se nenhum controle for selecionado, o campo conjunto de registros será definido como nulo se o campo permitir.

Use a primeira versão se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral. As chamadas `DDX_FieldRadio` para seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

##  <a name="ddx_fieldscroll"></a>  DDX_FieldScroll

A `DDX_FieldScroll` função sincroniza a posição de rolagem de um controle de barra de rolagem em uma exibição de registro e um membro de dados de campo **int** de um conjunto de registros associado à exibição de registro (ou com qualquer variável de inteiro que você escolher para mapeá-lo).

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID do primeiro em um grupo (com WS_GROUP de estilo) de controles de botão de opção adjacentes no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*value*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, essa função define a posição de rolagem do controle da barra de rolagem para o valor especificado em *valor*. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, o controle da barra de rolagem será definido como 0. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o valor do campo conjunto de registros será 0.

Use a primeira versão se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral. As chamadas `DDX_FieldScroll` para seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

  ## <a name="ddx_fieldslider"></a>  DDX_FieldSlider
A `DDX_FieldSlider` função sincroniza a posição de Thumb de um controle deslizante em uma exibição de registro e um membro de dados de campo **int** de um conjunto de registros associado à exibição de registro (ou com qualquer variável de inteiro que você escolher para mapeá-lo).

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID do recurso do controle deslizante.

*value*<br/>
Uma referência ao valor a ser trocado. Esse parâmetro mantém ou será usado para definir a posição atual do polegar do controle deslizante.

*pRecordset*<br/>
Um ponteiro para o `CRecordset` `CDaoRecordset` objeto associado ao qual os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle deslizante, essa função define a posição do controle deslizante para o valor especificado em *valor*. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, a posição do controle deslizante será definida como 0. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o valor do campo conjunto de registros será 0.

`DDX_FieldSlider`Não troca informações de intervalo com controles Slider capazes de definir um intervalo em vez de simplesmente uma posição.

Use a primeira substituição da função se você estiver trabalhando com as classes baseadas em ODBC. Use a segunda substituição com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX `CRecordView` para `CDaoRecordView` campos e, consulte [exibições de registro](../../data/record-views-mfc-data-access.md). Para obter informações sobre controles deslizantes, consulte [usando CSliderCtrl](../using-csliderctrl.md).

### <a name="example"></a>Exemplo

Consulte [DDX_FieldText](#ddx_fieldtext) para ver um exemplo de DDX_Field geral. As chamadas `DDX_FieldSlider` para seriam semelhantes.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

##  <a name="ddx_fieldtext"></a>  DDX_FieldText

A `DDX_FieldText` função gerencia a transferência de **inteiros**, **curtos**, **longos**, DWORD, [CString](../../atl-mfc-shared/reference/cstringt-class.md), **float**, **Double**, **bool**ou dados de **byte** entre um controle de caixa de edição e os membros de dados de campo de um registros.

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

*pDX*<br/>
Um ponteiro para um objeto [CDataExchange](../../mfc/reference/cdataexchange-class.md) . A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
A ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) .

*value*<br/>
Uma referência a um membro de dados de campo no `CRecordset` objeto `CDaoRecordset` associado ou. O tipo de dados de valor depende de qual das versões sobrecarregadas do `DDX_FieldText` você usa.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com os quais os dados são trocados. Esse ponteiro permite `DDX_FieldText` que o detecte e defina valores nulos.

### <a name="remarks"></a>Comentários

Para objetos [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) , `DDX_FieldText` o também gerencia a transferência de valores [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)e [COleCurrency](../../mfc/reference/colecurrency-class.md) . Um controle de caixa de edição vazio indica um valor nulo. Em uma transferência do conjunto de registros para o controle, se o campo do conjunto de registros for nulo, a caixa de edição será definida como vazia. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo conjunto de registros será definido como nulo.

Use as versões com parâmetros [CRecordset](../../mfc/reference/crecordset-class.md) se você estiver trabalhando com as classes baseadas em ODBC. Use as versões com parâmetros [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) se você estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o campo DDX, consulte a [caixa de diálogo troca de dados e validação](../../mfc/dialog-data-exchange-and-validation.md). Para obter exemplos e mais informações sobre campo DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md) , consulte o artigo [registros de exibições](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

A função `DoDataExchange` a seguir para um [CRecordView](../../mfc/reference/crecordview-class.md) contém chamadas de função `DDX_FieldText` para três tipos de dados: `IDC_COURSELIST` é uma caixa de combinação; os outros dois controles são caixas de edição. Para a programação do DAO, o parâmetro *m_pSet* é um ponteiro para um [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

[!code-cpp[NVC_MFCDatabase#43](../../mfc/codesnippet/cpp/dialog-data-exchange-functions-for-crecordview-and-cdaorecordview_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** AFXDAO. h

## <a name="see-also"></a>Consulte também

[Macros e globais](mfc-macros-and-globals.md)
