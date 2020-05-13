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
ms.openlocfilehash: 3128b1ba459cb017d1cdb2321bc55d865aa4f8b9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365784"
---
# <a name="dialog-data-exchange-functions-for-crecordview-and-cdaorecordview"></a>Funções da troca de dados da caixa de diálogo para CRecordView e CDaoRecordView

Este tópico lista as funções DDX_Field usadas para trocar dados entre um [CRecordset](../../mfc/reference/crecordset-class.md) e um [formulário CRecordView](../../mfc/reference/crecordview-class.md) ou um [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) e um formulário [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md) O DAO é usado com bancos de dados access e é suportado através do Office 2013. DAO 3.6 é a versão final, e é considerada obsoleta.

> [!NOTE]
> DDX_Field funções são como funções DDX na forma em que trocam dados com controles de forma. Mas, ao contrário do DDX, eles trocam dados com os campos do objeto de conjunto de registros associados da exibição, em vez de com os campos da própria exibição de registro. Para obter mais `CRecordView` informações, consulte as aulas e `CDaoRecordView`.

### <a name="ddx_field-functions"></a>funções DDX_Field

|||
|-|-|
|[DDX_FieldCBIndex](#ddx_fieldcbindex)|Transfere dados inteiros entre um membro de dados de campo de conjunto de registros e o índice da seleção atual em uma caixa de combinação em um [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView](../../mfc/reference/cdaorecordview-class.md).|
|[DDX_FieldCBString](#ddx_fieldcbstring)|Transfere `CString` dados entre um membro de dados de campo do `CRecordView` `CDaoRecordView`conjunto de registros e o controle de edição de uma caixa de combinação em um ou . Ao mover dados do conjunto de registros para o controle, esta função seleciona o item na caixa de combinação que começa com os caracteres na seqüência especificada.|
|[DDX_FieldCBStringExact](#ddx_fieldcbstringexact)|Transfere `CString` dados entre um membro de dados de campo do `CRecordView` `CDaoRecordView`conjunto de registros e o controle de edição de uma caixa de combinação em um ou . Ao mover dados do conjunto de registros para o controle, esta função seleciona o item na caixa de combinação que corresponde exatamente à seqüência especificada.|
|[DDX_FieldCheck](#ddx_fieldcheck)|Transfere dados booleanos entre um membro de `CRecordView` dados `CDaoRecordView`de campo de conjunto de registros e uma caixa de seleção em um ou .|
|[DDX_FieldLBIndex](#ddx_fieldlbindex)|Transfere dados inteiros entre um membro de dados de campo de conjunto `CRecordView` `CDaoRecordView`de registros e o índice da seleção atual em uma caixa de lista em um ou .|
|[DDX_FieldLBString](#ddx_fieldlbstring)|Gerencia a transferência de dados [CString](../../atl-mfc-shared/reference/cstringt-class.md) entre um controle de caixa de lista e os membros de dados de campo de um conjunto de registros. Ao mover dados do conjunto de registros para o controle, esta função seleciona o item na caixa de lista que começa com os caracteres na seqüência especificada.|
|[DDX_FieldLBStringExact](#ddx_fieldlbstringexact)|Gerencia a transferência `CString` de dados entre um controle de caixa de lista e os membros de dados de campo de um conjunto de registros. Ao mover dados do conjunto de registros para o controle, esta função seleciona o primeiro item que corresponde exatamente à seqüência especificada.|
|[DDX_FieldRadio](#ddx_fieldradio)|Transfere dados inteiros entre um membro de dados de campo `CRecordView` `CDaoRecordView`de conjunto de registros e um grupo de botões de rádio em um ou .|
|[DDX_FieldScroll](#ddx_fieldscroll)|Define ou obtém a posição de `CRecordView` rolagem de um controle de barra de rolagem em um ou `CDaoRecordView`. Ligue da função [DoFieldExchange.](../../mfc/reference/cdaorecordset-class.md#dofieldexchange)|
|[DDX_FieldSlider](#ddx_fieldslider)|Sincroniza a posição do polegar de um controle deslizante `int` em uma exibição de registro e um membro de dados de campo de um conjunto de registros. |
|[DDX_FieldText](#ddx_fieldtext)|As `int`versões sobrecarregadas estão disponíveis para transferência, **UINT,** **longa**, `DWORD` [CString,](../../atl-mfc-shared/reference/cstringt-class.md) **flutuação,** **duplo,** **curto,** [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)e `CRecordView` [COleCurrency](../../mfc/reference/colecurrency-class.md) data entre um membro de campo de registro e uma caixa de edição em um ou `CDaoRecordView`.|

## <a name="ddx_fieldcbindex"></a><a name="ddx_fieldcbindex"></a>DDX_FieldCBIndex

A `DDX_FieldCBIndex` função sincroniza o índice do item selecionado no controle da caixa de lista `int` de um controle de caixa de combinação em uma exibição de registro e um membro de dados de campo de um conjunto de registros associado à exibição de registro.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*Índice*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, esta função define a seleção no controle com base no valor especificado no *índice*. Em uma transferência do conjunto de registros para o controle, se o campo de recordset for Nulo, o MFC define o valor do índice como 0. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio ou se nenhum item estiver selecionado, o campo recordset será definido como 0.

Use a primeira versão se estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral. O exemplo seria `DDX_FieldCBIndex`semelhante para .

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="ddx_fieldcbstring"></a><a name="ddx_fieldcbstring"></a>DDX_FieldCBString

A `DDX_FieldCBString` função gerencia a transferência de dados [CString](../../atl-mfc-shared/reference/cstringt-class.md) entre o controle de edição `CString` de um controle de caixa de combinação em uma exibição de registro e um membro de dados de campo de um conjunto de registros associado à exibição de registro.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*value*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, esta função define a seleção atual na caixa de combinação para a primeira linha que começa com os caracteres na seqüência especificada no *valor*. Em uma transferência do conjunto de registros para o controle, se o campo de gravação for Nulo, qualquer seleção será removida da caixa de combinação e o controle de edição da caixa de combinação será definido como vazio. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros será definido como Nulo se o campo permitir.

Use a primeira versão se estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral. O exemplo inclui uma `DDX_FieldCBString`chamada para .

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="ddx_fieldcbstringexact"></a><a name="ddx_fieldcbstringexact"></a>DDX_FieldCBStringExact

A `DDX_FieldCBStringExact` função gerencia a transferência de dados [CString](../../atl-mfc-shared/reference/cstringt-class.md) entre o controle de edição `CString` de um controle de caixa de combinação em uma exibição de registro e um membro de dados de campo de um conjunto de registros associado à exibição de registro.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*value*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, esta função define a seleção atual na caixa de combinação para a primeira linha que corresponde exatamente à seqüência especificada no *valor*. Em uma transferência do conjunto de registros para o controle, se o campo de gravação for NULO, qualquer seleção será removida da caixa de combinação e a caixa de edição da caixa de combinação será definida como vazia. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros será definido como NULL.

Use a primeira versão se estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral. As `DDX_FieldCBStringExact` chamadas seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="ddx_fieldcheck"></a><a name="ddx_fieldcheck"></a>DDX_FieldCheck

A `DDX_FieldCheck` função gerencia a transferência de dados **int** entre um controle de caixa de seleção em uma caixa de diálogo, exibição de formulário ou objeto de exibição de controle e um membro de dados **int** da caixa de diálogo, exibição de formulário ou objeto de exibição de controle.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de recurso do controle da caixa de seleção associado à propriedade de controle.

*value*<br/>
Uma referência a uma variável membro da caixa de diálogo, exibição de formulário ou objeto de exibição de controle com o qual os dados são trocados.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Quando `DDX_FieldCheck` é chamado, o *valor* é definido para o estado atual do controle da caixa de seleção, ou o estado do controle é definido como *valor,* dependendo da direção da transferência.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="ddx_fieldlbindex"></a><a name="ddx_fieldlbindex"></a>DDX_FieldLBIndex

A `DDX_FieldLBIndex` função sincroniza o índice do item selecionado em um controle de caixa de lista em uma exibição de registro e um membro de dados de campo **int** de um conjunto de registros associado à exibição de registro.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*Índice*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, esta função define a seleção no controle com base no valor especificado no *índice*. Em uma transferência do conjunto de registros para o controle, se o campo de recordset for Nulo, o MFC define o valor do índice como 0. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo de conjunto de registros é definido como 0.

Use a primeira versão se estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="ddx_fieldlbstring"></a><a name="ddx_fieldlbstring"></a>DDX_FieldLBString

O `DDX_FieldLBString` copia a seleção atual de um controle de caixa de lista em uma exibição de registro para um membro de campo [CString](../../atl-mfc-shared/reference/cstringt-class.md) de um conjunto de registros associado à exibição de registro.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*value*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

No sentido inverso, esta função define a seleção atual na caixa de lista para a primeira linha que começa com os caracteres na seqüência especificada pelo *valor*. Em uma transferência do conjunto de registros para o controle, se o campo de gravação for nulo, qualquer seleção será removida da caixa de lista. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo de gravação definido será definido como Nulo.

Use a primeira versão se estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral. As `DDX_FieldLBString` chamadas seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="ddx_fieldlbstringexact"></a><a name="ddx_fieldlbstringexact"></a>DDX_FieldLBStringExact

A `DDX_FieldLBStringExact` função copia a seleção atual de um controle de caixa de lista em uma exibição de registro para um membro de campo [CString](../../atl-mfc-shared/reference/cstringt-class.md) de um conjunto de registros associado à exibição de registro.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*value*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

No sentido inverso, esta função define a seleção atual na caixa de lista para a primeira linha que corresponde exatamente à seqüência especificada no *valor*. Em uma transferência do conjunto de registros para o controle, se o campo de gravação for nulo, qualquer seleção será removida da caixa de lista. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo de gravação definido será definido como Nulo.

Use a primeira versão se estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral. As `DDX_FieldLBStringExact` chamadas seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="ddx_fieldradio"></a><a name="ddx_fieldradio"></a>DDX_FieldRadio

A `DDX_FieldRadio` função associa uma variável de membro **int** baseada em zero do conjunto de registros de uma exibição de gravação com o botão de rádio atualmente selecionado em um grupo de botões de rádio na exibição de gravação.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID do primeiro em um grupo (com estilo WS_GROUP) de controles de botão de rádio adjacentes no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*value*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Ao transferir do campo do conjunto de gravações para a visualização, esta função liga o botão de rádio *nésimo* (baseado em zero) e desliga os outros botões. No sentido inverso, esta função define o campo de conjunto de registros para o número ordinal do botão de rádio que está atualmente ligado (verificado). Em uma transferência do conjunto de registros para o controle, se o campo recordset for Nulo, nenhum botão será selecionado. Em uma transferência do controle para o conjunto de registros, se nenhum controle for selecionado, o campo de conjunto de registros será definido como Nulo se o campo permitir isso.

Use a primeira versão se estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral. As `DDX_FieldRadio` chamadas seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="ddx_fieldscroll"></a><a name="ddx_fieldscroll"></a>DDX_FieldScroll

A `DDX_FieldScroll` função sincroniza a posição de rolagem de um controle de barra de rolagem em uma exibição de registro e um membro de dados de campo **int** de um conjunto de registros associado à exibição de registro (ou com qualquer variável inteira que você escolher para mapeá-lo).

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID do primeiro em um grupo (com estilo WS_GROUP) de controles de botão de rádio adjacentes no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*value*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle, esta função define a posição de rolagem do controle da barra de rolagem para o valor especificado no *valor*. Em uma transferência do conjunto de registros para o controle, se o campo de gravação estiver nulo, o controle da barra de rolagem será definido como 0. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o valor do campo recordset é 0.

Use a primeira versão se estiver trabalhando com as classes baseadas em ODBC. Use a segunda versão se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral. As `DDX_FieldScroll` chamadas seriam semelhantes.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="ddx_fieldslider"></a><a name="ddx_fieldslider"></a>DDX_FieldSlider

A `DDX_FieldSlider` função sincroniza a posição do polegar de um controle deslizante em uma exibição de registro e um membro de dados de campo **int** de um conjunto de registros associado à exibição de registro (ou com qualquer variável inteira que você escolher para mapeá-lo).

### <a name="syntax"></a>Sintaxe

```cpp
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
Um ponteiro para um objeto [CDataExchange.](cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O id de recurso do controle deslizante.

*value*<br/>
Uma referência ao valor a ser trocado. Este parâmetro contém ou será usado para definir a posição atual do polegar do controle deslizante.

*pRecordset*<br/>
Um ponteiro para `CRecordset` `CDaoRecordset` o objeto associado ou com o qual os dados são trocados.

### <a name="remarks"></a>Comentários

Ao mover dados do conjunto de registros para o controle deslizante, esta função define a posição do controle deslizante para o valor especificado no *valor*. Em uma transferência do conjunto de registros para o controle, se o campo de gravação estiver nulo, a posição do controle deslizante será definida como 0. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o valor do campo recordset é 0.

`DDX_FieldSlider`não troca informações de intervalo com controles deslizantes capazes de definir um intervalo em vez de simplesmente uma posição.

Use a primeira substituição da função se estiver trabalhando com as classes baseadas em ODBC. Use a segunda substituição com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre `CRecordView` `CDaoRecordView` dDX para campos e campos, consulte [Record Views](../../data/record-views-mfc-data-access.md). Para obter informações sobre controles deslizantes, consulte [Usando CSliderCtrl](../using-csliderctrl.md).

### <a name="example"></a>Exemplo

Veja [DDX_FieldText](#ddx_fieldtext) para um exemplo de DDX_Field geral. As `DDX_FieldSlider` chamadas seriam semelhantes.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="ddx_fieldtext"></a><a name="ddx_fieldtext"></a>Ddx_fieldtext

A `DDX_FieldText` função gerencia a transferência de dados **int,** **curto,** **longo,** DWORD, [CString](../../atl-mfc-shared/reference/cstringt-class.md), **float,** **double,** **BOOL**ou **BYTE** entre um controle de caixa de edição e os membros de dados de campo de um conjunto de registros.

```cpp
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
Um ponteiro para um objeto [CDataExchange.](../../mfc/reference/cdataexchange-class.md) A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*nIDC*<br/>
O ID de um controle no objeto [CRecordView](../../mfc/reference/crecordview-class.md) ou [CDaoRecordView.](../../mfc/reference/cdaorecordview-class.md)

*value*<br/>
Uma referência a um membro `CRecordset` de `CDaoRecordset` dados de campo no objeto associado. O tipo de valor dos dados depende de `DDX_FieldText` qual das versões sobrecarregadas de você usa.

*pRecordset*<br/>
Um ponteiro para o objeto [CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) com o qual os dados são trocados. Este ponteiro `DDX_FieldText` permite detectar e definir valores nulos.

### <a name="remarks"></a>Comentários

Para objetos [CDaoRecordset,](../../mfc/reference/cdaorecordset-class.md) `DDX_FieldText` também gerencia a transferência de valores [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md)e [COleCurrency.](../../mfc/reference/colecurrency-class.md) Um controle de caixa de edição vazio indica um valor nulo. Em uma transferência do conjunto de registros para o controle, se o campo de gravação estiver nulo, a caixa de edição será definida como vazia. Em uma transferência do controle para o conjunto de registros, se o controle estiver vazio, o campo de gravação definido será definido como Nulo.

Use as versões com parâmetros [CRecordset](../../mfc/reference/crecordset-class.md) se estiver trabalhando com as classes baseadas em ODBC. Use as versões com parâmetros [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) se estiver trabalhando com as classes baseadas em DAO.

Para obter mais informações sobre o DDX, consulte [Troca e Validação de Dados de Diálogo](../../mfc/dialog-data-exchange-and-validation.md). Para exemplos e mais informações sobre o DDX para os campos [CRecordView](../../mfc/reference/crecordview-class.md) e [CDaoRecordView,](../../mfc/reference/cdaorecordview-class.md) consulte o artigo [Record Views](../../data/record-views-mfc-data-access.md).

### <a name="example"></a>Exemplo

A função `DoDataExchange` a seguir para um [CRecordView](../../mfc/reference/crecordview-class.md) contém chamadas de função `DDX_FieldText` para três tipos de dados: `IDC_COURSELIST` é uma caixa de combinação; os outros dois controles são caixas de edição. Para programação DAO, o parâmetro *m_pSet* é um ponteiro para um [conjunto CRecordset](../../mfc/reference/crecordset-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

[!code-cpp[NVC_MFCDatabase#43](../../mfc/codesnippet/cpp/dialog-data-exchange-functions-for-crecordview-and-cdaorecordview_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxdao.h

## <a name="see-also"></a>Confira também

[Macros e globais](mfc-macros-and-globals.md)
