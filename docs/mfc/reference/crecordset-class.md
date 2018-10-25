---
title: Classe CRecordset | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CRecordset
- AFXDB/CRecordset
- AFXDB/CRecordset::CRecordset
- AFXDB/CRecordset::AddNew
- AFXDB/CRecordset::CanAppend
- AFXDB/CRecordset::CanBookmark
- AFXDB/CRecordset::Cancel
- AFXDB/CRecordset::CancelUpdate
- AFXDB/CRecordset::CanRestart
- AFXDB/CRecordset::CanScroll
- AFXDB/CRecordset::CanTransact
- AFXDB/CRecordset::CanUpdate
- AFXDB/CRecordset::CheckRowsetError
- AFXDB/CRecordset::Close
- AFXDB/CRecordset::Delete
- AFXDB/CRecordset::DoBulkFieldExchange
- AFXDB/CRecordset::DoFieldExchange
- AFXDB/CRecordset::Edit
- AFXDB/CRecordset::FlushResultSet
- AFXDB/CRecordset::GetBookmark
- AFXDB/CRecordset::GetDefaultConnect
- AFXDB/CRecordset::GetDefaultSQL
- AFXDB/CRecordset::GetFieldValue
- AFXDB/CRecordset::GetODBCFieldCount
- AFXDB/CRecordset::GetODBCFieldInfo
- AFXDB/CRecordset::GetRecordCount
- AFXDB/CRecordset::GetRowsetSize
- AFXDB/CRecordset::GetRowsFetched
- AFXDB/CRecordset::GetRowStatus
- AFXDB/CRecordset::GetSQL
- AFXDB/CRecordset::GetStatus
- AFXDB/CRecordset::GetTableName
- AFXDB/CRecordset::IsBOF
- AFXDB/CRecordset::IsDeleted
- AFXDB/CRecordset::IsEOF
- AFXDB/CRecordset::IsFieldDirty
- AFXDB/CRecordset::IsFieldNull
- AFXDB/CRecordset::IsFieldNullable
- AFXDB/CRecordset::IsOpen
- AFXDB/CRecordset::Move
- AFXDB/CRecordset::MoveFirst
- AFXDB/CRecordset::MoveLast
- AFXDB/CRecordset::MoveNext
- AFXDB/CRecordset::MovePrev
- AFXDB/CRecordset::OnSetOptions
- AFXDB/CRecordset::OnSetUpdateOptions
- AFXDB/CRecordset::Open
- AFXDB/CRecordset::RefreshRowset
- AFXDB/CRecordset::Requery
- AFXDB/CRecordset::SetAbsolutePosition
- AFXDB/CRecordset::SetBookmark
- AFXDB/CRecordset::SetFieldDirty
- AFXDB/CRecordset::SetFieldNull
- AFXDB/CRecordset::SetLockingMode
- AFXDB/CRecordset::SetParamNull
- AFXDB/CRecordset::SetRowsetCursorPosition
- AFXDB/CRecordset::SetRowsetSize
- AFXDB/CRecordset::Update
- AFXDB/CRecordset::m_hstmt
- AFXDB/CRecordset::m_nFields
- AFXDB/CRecordset::m_nParams
- AFXDB/CRecordset::m_pDatabase
- AFXDB/CRecordset::m_strFilter
- AFXDB/CRecordset::m_strSort
dev_langs:
- C++
helpviewer_keywords:
- CRecordset [MFC], CRecordset
- CRecordset [MFC], AddNew
- CRecordset [MFC], CanAppend
- CRecordset [MFC], CanBookmark
- CRecordset [MFC], Cancel
- CRecordset [MFC], CancelUpdate
- CRecordset [MFC], CanRestart
- CRecordset [MFC], CanScroll
- CRecordset [MFC], CanTransact
- CRecordset [MFC], CanUpdate
- CRecordset [MFC], CheckRowsetError
- CRecordset [MFC], Close
- CRecordset [MFC], Delete
- CRecordset [MFC], DoBulkFieldExchange
- CRecordset [MFC], DoFieldExchange
- CRecordset [MFC], Edit
- CRecordset [MFC], FlushResultSet
- CRecordset [MFC], GetBookmark
- CRecordset [MFC], GetDefaultConnect
- CRecordset [MFC], GetDefaultSQL
- CRecordset [MFC], GetFieldValue
- CRecordset [MFC], GetODBCFieldCount
- CRecordset [MFC], GetODBCFieldInfo
- CRecordset [MFC], GetRecordCount
- CRecordset [MFC], GetRowsetSize
- CRecordset [MFC], GetRowsFetched
- CRecordset [MFC], GetRowStatus
- CRecordset [MFC], GetSQL
- CRecordset [MFC], GetStatus
- CRecordset [MFC], GetTableName
- CRecordset [MFC], IsBOF
- CRecordset [MFC], IsDeleted
- CRecordset [MFC], IsEOF
- CRecordset [MFC], IsFieldDirty
- CRecordset [MFC], IsFieldNull
- CRecordset [MFC], IsFieldNullable
- CRecordset [MFC], IsOpen
- CRecordset [MFC], Move
- CRecordset [MFC], MoveFirst
- CRecordset [MFC], MoveLast
- CRecordset [MFC], MoveNext
- CRecordset [MFC], MovePrev
- CRecordset [MFC], OnSetOptions
- CRecordset [MFC], OnSetUpdateOptions
- CRecordset [MFC], Open
- CRecordset [MFC], RefreshRowset
- CRecordset [MFC], Requery
- CRecordset [MFC], SetAbsolutePosition
- CRecordset [MFC], SetBookmark
- CRecordset [MFC], SetFieldDirty
- CRecordset [MFC], SetFieldNull
- CRecordset [MFC], SetLockingMode
- CRecordset [MFC], SetParamNull
- CRecordset [MFC], SetRowsetCursorPosition
- CRecordset [MFC], SetRowsetSize
- CRecordset [MFC], Update
- CRecordset [MFC], m_hstmt
- CRecordset [MFC], m_nFields
- CRecordset [MFC], m_nParams
- CRecordset [MFC], m_pDatabase
- CRecordset [MFC], m_strFilter
- CRecordset [MFC], m_strSort
ms.assetid: dd89a21d-ef39-4aab-891b-1e373d67c855
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c86efacf7211415bfdc2936a736d78e29dc419bf
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50076393"
---
# <a name="crecordset-class"></a>Classe CRecordset

Representa um conjunto de registros selecionados de uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```
class CRecordset : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRecordset::CRecordset](#crecordset)|Constrói um objeto `CRecordset`. Sua classe derivada deve fornecer um construtor que chama esse.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRecordset::AddNew](#addnew)|Prepara para adicionar um novo registro. Chamar `Update` para concluir a adição.|
|[CRecordset::CanAppend](#canappend)|Retorna não zero, se novos registros podem ser adicionados ao conjunto de registros por meio de `AddNew` função de membro.|
|[CRecordset::CanBookmark](#canbookmark)|Retorna diferente de zero se o conjunto de registros dá suporte a indicadores.|
|[CRecordset::Cancel](#cancel)|Cancela uma operação assíncrona ou um processo de um thread de segundo.|
|[CRecordset::CancelUpdate](#cancelupdate)|Cancela todas as atualizações pendentes devido a um `AddNew` ou `Edit` operação.|
|[CRecordset::CanRestart](#canrestart)|Retorna se diferente de zero `Requery` pode ser chamado para executar a consulta do conjunto de registros novamente.|
|[CRecordset::CanScroll](#canscroll)|Retorna diferente de zero se você pode percorrer os registros.|
|[CRecordset::CanTransact](#cantransact)|Retorna diferente de zero se a fonte de dados oferece suporte a transações.|
|[CRecordset::CanUpdate](#canupdate)|Retorna não zero se o conjunto de registros pode ser atualizado (você pode adicionar, atualizar ou excluir registros).|
|[CRecordset::CheckRowsetError](#checkrowseterror)|Chamado para manipular erros gerados durante a busca de registro.|
|[CRecordset::Close](#close)|Fecha o conjunto de registros e o HSTMT ODBC associado a ele.|
|[CRecordset::Delete](#delete)|Exclui o registro atual do conjunto de registros. Explicitamente, você deve rolar para outro registro após a exclusão.|
|[CRecordset::DoBulkFieldExchange](#dobulkfieldexchange)|Chamado para linhas em massa de dados da fonte de dados para o conjunto de registros do exchange. Implementa em massa registrar troca de campos (RFX em massa).|
|[CRecordset::DoFieldExchange](#dofieldexchange)|Chamado para trocar dados (em ambas as direções) entre os membros de dados do campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa registra troca de campos (RFX).|
|[CRecordset::Edit](#edit)|Prepara para as alterações no registro atual. Chamar `Update` para concluir a edição.|
|[CRecordset::FlushResultSet](#flushresultset)|Retorna diferente de zero se não houver outro resultado conjunto a ser recuperado, ao usar uma consulta predefinida.|
|[CRecordset::GetBookmark](#getbookmark)|Atribui o valor de indicador de um registro para o objeto de parâmetro.|
|[Crecordset:: Getdefaultconnect](#getdefaultconnect)|Chamado para obter a cadeia de caracteres de conexão padrão.|
|[CRecordset::GetDefaultSQL](#getdefaultsql)|Chamado para obter a cadeia de caracteres SQL padrão para executar.|
|[CRecordset::GetFieldValue](#getfieldvalue)|Retorna o valor de um campo em um conjunto de registros.|
|[CRecordset::GetODBCFieldCount](#getodbcfieldcount)|Retorna o número de campos no conjunto de registros.|
|[CRecordset::GetODBCFieldInfo](#getodbcfieldinfo)|Retorna os tipos específicos de informações sobre os campos em um conjunto de registros.|
|[CRecordset::GetRecordCount](#getrecordcount)|Retorna o número de registros no conjunto de registros.|
|[CRecordset::GetRowsetSize](#getrowsetsize)|Retorna o número de registros que deseja recuperar durante uma única busca.|
|[CRecordset::GetRowsFetched](#getrowsfetched)|Retorna o número real de linhas recuperadas durante uma busca.|
|[CRecordset::GetRowStatus](#getrowstatus)|Retorna o status da linha após uma busca.|
|[CRecordset::GetSQL](#getsql)|Obtém a cadeia de caracteres SQL usada para selecionar registros do conjunto de registros.|
|[CRecordset::GetStatus](#getstatus)|Obtém o status do conjunto de registros: o índice do registro atual e se uma contagem final de registros foi obtida.|
|[CRecordset::GetTableName](#gettablename)|Obtém o nome da tabela na qual o conjunto de registros se baseia.|
|[CRecordset::IsBOF](#isbof)|Retorna diferente de zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há nenhum registro atual.|
|[CRecordset::IsDeleted](#isdeleted)|Retorna diferente de zero se o conjunto de registros é posicionado em um registro excluído.|
|[CRecordset::IsEOF](#iseof)|Retorna diferente de zero se o conjunto de registros tiver sido posicionado após o último registro. Não há nenhum registro atual.|
|[CRecordset::IsFieldDirty](#isfielddirty)|Retorna diferente de zero se o campo especificado no registro atual foi alterado.|
|[CRecordset::IsFieldNull](#isfieldnull)|Retorna não zero se o campo especificado no registro atual é nulo (não tem nenhum valor).|
|[CRecordset::IsFieldNullable](#isfieldnullable)|Retorna diferente de zero se o campo especificado no registro atual pode ser definido como nulo (com nenhum valor).|
|[CRecordset::IsOpen](#isopen)|Retorna se diferente de zero `Open` foi chamado anteriormente.|
|[CRecordset::Move](#move)|Posiciona o conjunto de registros para um número especificado de registros do registro atual em qualquer direção.|
|[CRecordset::MoveFirst](#movefirst)|Posiciona o registro atual no primeiro registro no conjunto de registros. Testar a `IsBOF` primeiro.|
|[CRecordset::MoveLast](#movelast)|Posiciona o registro atual no último registro ou no último conjunto de linhas. Testar a `IsEOF` primeiro.|
|[CRecordset::MoveNext](#movenext)|Posiciona o registro atual no próximo registro ou no próximo conjunto de linhas. Testar a `IsEOF` primeiro.|
|[CRecordset::MovePrev](#moveprev)|Posiciona o registro atual no conjunto de linhas anterior ou o registro anterior. Testar a `IsBOF` primeiro.|
|[CRecordset::OnSetOptions](#onsetoptions)|Chamado para definir opções (usadas na seleção) para a instrução ODBC especificada.|
|[CRecordset::OnSetUpdateOptions](#onsetupdateoptions)|Chamado para definir as opções (usadas na atualização) para a instrução ODBC especificada.|
|[{1&gt;crecordset::Open&lt;1](#open)|Abre o conjunto de registros por recuperar a tabela ou executar a consulta que representa o conjunto de registros.|
|[CRecordset::RefreshRowset](#refreshrowset)|Atualiza os dados e o status do (s) especificado.|
|[CRecordset::Requery](#requery)|Executa a consulta do conjunto de registros novamente para atualizar os registros selecionados.|
|[CRecordset::SetAbsolutePosition](#setabsoluteposition)|Posiciona o conjunto de registros no registro correspondente ao número de registro especificado.|
|[CRecordset::SetBookmark](#setbookmark)|Posiciona o conjunto de registros em que o registro especificado pelo indicador.|
|[CRecordset::SetFieldDirty](#setfielddirty)|Marca o campo especificado no registro atual, conforme tiver sido alterado.|
|[CRecordset::SetFieldNull](#setfieldnull)|Define o valor do campo especificado no registro atual como nulo (com nenhum valor).|
|[CRecordset::SetLockingMode](#setlockingmode)|Define o modo de bloqueio para "otimista" bloqueio (o padrão) ou "" pessimista. Determina como os registros são bloqueados para atualizações.|
|[CRecordset::SetParamNull](#setparamnull)|Define o parâmetro especificado como nulo (com nenhum valor).|
|[CRecordset::SetRowsetCursorPosition](#setrowsetcursorposition)|Posiciona o cursor na linha especificada dentro do conjunto de linhas.|
|[CRecordset::SetRowsetSize](#setrowsetsize)|Especifica o número de registros que deseja recuperar durante uma busca.|
|[CRecordset::Update](#update)|Conclui uma `AddNew` ou `Edit` operação, salvando os dados novos ou editados na fonte de dados.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRecordset::m_hstmt](#m_hstmt)|Contém o identificador de instrução ODBC para o conjunto de registros. Digite `HSTMT` no terminal integrado.|
|[CRecordset::m_nFields](#m_nfields)|Contém o número de membros de dados do campo no conjunto de registros. Digite `UINT` no terminal integrado.|
|[CRecordset::m_nParams](#m_nparams)|Contém o número de membros de dados de parâmetro no conjunto de registros. Digite `UINT` no terminal integrado.|
|[CRecordset::m_pDatabase](#m_pdatabase)|Contém um ponteiro para o `CDatabase` objeto por meio do qual o conjunto de registros é conectado a uma fonte de dados.|
|[CRecordset::m_strFilter](#m_strfilter)|Contém uma `CString` que especifica uma linguagem SQL (Structured Query) `WHERE` cláusula. Usado como um filtro para selecionar apenas os registros que atendem a certos critérios.|
|[CRecordset::m_strSort](#m_strsort)|Contém uma `CString` que especifica um SQL `ORDER BY` cláusula. Usado para controlar como os registros são classificados.|

## <a name="remarks"></a>Comentários

Conhecido como "conjuntos de registros," `CRecordset` objetos são normalmente usados em duas formas: dynasets e instantâneos. Dynaset permanece sincronizado com as atualizações de dados feitas por outros usuários. Um instantâneo é uma exibição estática dos dados. Cada formulário representa um conjunto de registros corrigidos no momento em que o conjunto de registros é aberto, mas quando você rolar para um registro em um dynaset, ele refletirá as alterações feitas no registro, subsequentemente por outros usuários ou por outros conjuntos de registros em seu aplicativo.

> [!NOTE]
>  Se você estiver trabalhando com as classes de objetos de acesso a dados (DAO) em vez das classes de conectividade de banco de dados aberto (ODBC), use a classe [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: banco de dados de programação](../../data/data-access-programming-mfc-atl.md).

Para trabalhar com qualquer tipo de conjunto de registros, você normalmente deriva uma classe de conjunto de registros específicos do aplicativo de `CRecordset`. Conjuntos de registros selecionam registros da fonte de dados e, em seguida, você pode:

- Percorra os registros.

- Atualizar os registros e especificar um modo de bloqueio.

- Filtre o conjunto de registros para restringir quais registros ele seleciona daqueles disponíveis na fonte de dados.

- Classifica o conjunto de registros.

- Parametrize o conjunto de registros para personalizar sua seleção com informações não são conhecidas até o tempo de execução.

Para usar sua classe, abra um banco de dados e construir um objeto de conjunto de registros, passando ao construtor um ponteiro para sua `CDatabase` objeto. Em seguida, chame o conjunto de registros `Open` função de membro, onde você pode especificar se o objeto é um dynaset ou um instantâneo. Chamar `Open` seleciona dados da fonte de dados. Depois que o objeto de conjunto de registros é aberto, use seus membros de dados e funções de membro para percorrer os registros e operar sobre elas. As operações disponíveis dependem se o objeto é um dynaset ou um instantâneo, se ele pode ser atualizada ou somente leitura (isso depende da capacidade da fonte de dados ODBC Open Database Connectivity ()), e se você tiver implementado a busca de linhas em massa. Para atualizar os registros que podem foram alterados ou adicionados desde o `Open` chamar, chamar o objeto `Requery` função de membro. Chamar o objeto `Close` membro de função e destruir o objeto quando você terminar com ele.

Em um derivada `CRecordset` de classe, registre a troca de campos (RFX) ou em massa registrar troca de campos (RFX em massa) é usada para dar suporte à leitura e atualização dos campos de registro.

Para obter mais informações sobre a troca de campos de conjuntos de registros e o registro, consulte os artigos [visão geral: banco de dados de programação](../../data/data-access-programming-mfc-atl.md), [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md), [conjunto de registros: buscando registros em massa (ODBC) ](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md), e [registrar troca de campos (RFX)](../../data/odbc/record-field-exchange-rfx.md). Para um foco em dynasets e instantâneos, consulte os artigos [Dynaset](../../data/odbc/dynaset.md) e [instantâneo](../../data/odbc/snapshot.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CRecordset`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb. h

##  <a name="addnew"></a>  CRecordset::AddNew

Prepara para adicionar um novo registro na tabela.

```
virtual void AddNew();
```

### <a name="remarks"></a>Comentários

Você deve chamar o [Requery](#requery) função de membro para ver o registro recém-adicionado. Os campos do registro são inicialmente nulos. (Na terminologia de banco de dados, Null significa "não ter nenhum valor" e não é igual a NULL em C++.) Para concluir a operação, você deve chamar o [atualização](#update) função de membro. `Update` salva as alterações à fonte de dados.

> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa, você não pode chamar `AddNew`. Isso resultará em uma declaração com falha. Embora a classe `CRecordset` não fornece um mecanismo para atualizar linhas em massa de dados, você pode escrever suas próprias funções usando a função de API ODBC `SQLSetPos`. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

`AddNew` Prepara um registro de novo e vazio usando membros de dados de campo do conjunto de registros. Depois de chamar `AddNew`, defina os valores desejados em membros de dados de campo do conjunto de registros. (Você não precisa chamar o [edite](#edit) função de membro para essa finalidade; use `Edit` somente para os registros existentes.) Quando você chamar subsequentemente `Update`, alterados valores nos membros de dados de campo são salvos na fonte de dados.

> [!CAUTION]
>  Se você rolar para um novo registro antes de chamar `Update`, o novo registro é perdido e nenhum aviso é fornecido.

Se a fonte de dados oferece suporte a transações, você pode fazer sua `AddNew` chamar parte de uma transação. Para obter mais informações sobre transações, consulte a classe [CDatabase](../../mfc/reference/cdatabase-class.md). Observe que você deve chamar [CDatabase::BeginTrans](../../mfc/reference/cdatabase-class.md#begintrans) antes de chamar `AddNew`.

> [!NOTE]
>  Para dynasets, novos registros são adicionados ao conjunto de registros, como o último registro. Registros adicionados não são adicionados ao instantâneos; Você deve chamar `Requery` para atualizar o conjunto de registros.

É ilegal chamar `AddNew` para um conjunto de registros cujo `Open` função de membro não foi chamada. Um `CDBException` é lançada se você chamar `AddNew` para um conjunto de registros não pode ser anexado à. Você pode determinar se o conjunto de registros é atualizável, chamando [CanAppend](#canappend).

Para obter mais informações, consulte os artigos a seguir: [conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md), [conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md), e [(da transação ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>Exemplo

Consulte o artigo [transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

##  <a name="canappend"></a>  CRecordset::CanAppend

Determina se o conjunto de registros aberto anteriormente permite a adição de novos registros.

```
BOOL CanAppend() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros permite a adição de novos registros; Caso contrário, 0. `CanAppend` retornará 0 se você abriu o conjunto de registros como somente leitura.

##  <a name="canbookmark"></a>  CRecordset::CanBookmark

Determina se o conjunto de registros permite que você marque registros usando indicadores.

```
BOOL CanBookmark() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros dá suporte a indicadores; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é independente do `CRecordset::useBookmarks` opção o *dwOptions* parâmetro do [abrir](#open) função de membro. `CanBookmark` Indica se o determinado driver ODBC e o cursor de tipo de suporte a indicadores. `CRecordset::useBookmarks` Indica se indicadores estarão disponíveis, desde que eles têm suporte.

> [!NOTE]
>  Não há suporte para os indicadores em conjuntos de registros somente de encaminhamento.

Para obter mais informações sobre indicadores e navegação de conjunto de registros, consulte os artigos [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

##  <a name="cancel"></a>  CRecordset::Cancel

Solicita que a fonte de dados cancela uma operação assíncrona em andamento ou um processo de um thread de segundo.

```
void Cancel();
```

### <a name="remarks"></a>Comentários

Observe que as classes MFC ODBC não for mais usam o processamento assíncrono; para executar uma operação assíncrona, você deve chamar diretamente a função ODBC API `SQLSetConnectOption`. Para obter mais informações, consulte o tópico "Executando funções assincronamente" no *guia do programador de ODBC SDK*.

##  <a name="cancelupdate"></a>  CRecordset::CancelUpdate

Cancela as atualizações pendentes, causadas por uma [edite](#edit) ou [AddNew](#addnew) operação, antes [atualização](#update) é chamado.

```
void CancelUpdate();
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Essa função de membro não é aplicável em conjuntos de registros que estão usando em massa busca de linhas, uma vez que esses conjuntos de registros não é possível chamar `Edit`, `AddNew`, ou `Update`. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Se a verificação de campo de falta de limpeza automática estiver ativada, `CancelUpdate` restaurará as variáveis de membro para os valores que tinham antes `Edit` ou `AddNew` foi chamado; caso contrário, as alterações de valor permanecerá. Por padrão, a verificação automática de campo é habilitado quando o conjunto de registros é aberto. Para desabilitá-lo, você deve especificar o `CRecordset::noDirtyFieldCheck` no *dwOptions* parâmetro do [abrir](#open) função de membro.

Para obter mais informações sobre a atualização de dados, consulte o artigo [conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md).

##  <a name="canrestart"></a>  CRecordset::CanRestart

Determina se o conjunto de registros permite reiniciar sua consulta (para atualizar seus registros) chamando o `Requery` função de membro.

```
BOOL CanRestart() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a repetição da consulta é permitida. Caso contrário, 0.

##  <a name="canscroll"></a>  CRecordset::CanScroll

Determina se o conjunto de registros permite a rolagem.

```
BOOL CanScroll() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros que permite rolagem; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a rolagem, consulte o artigo [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

##  <a name="cantransact"></a>  CRecordset::CanTransact

Determina se o conjunto de registros permite que as transações.

```
BOOL CanTransact() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros permite que transações; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).

##  <a name="canupdate"></a>  CRecordset::CanUpdate

Determina se o conjunto de registros pode ser atualizado.

```
BOOL CanUpdate() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros pode ser atualizado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Um conjunto de registros pode ser somente leitura se a fonte de dados subjacente é somente leitura ou se você tiver especificado `CRecordset::readOnly` no *dwOptions* parâmetro quando você abriu o conjunto de registros.

##  <a name="checkrowseterror"></a>  CRecordset::CheckRowsetError

Chamado para manipular erros gerados durante a busca de registro.

```
virtual void CheckRowsetError(RETCODE nRetCode);
```

### <a name="parameters"></a>Parâmetros

*nRetCode*<br/>
Código de retorno de uma função de API do ODBC. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Essa função membro virtual manipula erros que ocorrem quando registros são encontrados, e é útil durante a busca de linhas em massa. Você talvez queira considerar substituindo `CheckRowsetError` para implementar seu próprio tratamento de erros.

`CheckRowsetError` é chamado automaticamente em uma operação de navegação do cursor, como `Open`, `Requery`, ou qualquer `Move` operação. Ele é passado o valor de retorno da função ODBC API `SQLExtendedFetch`. A tabela a seguir lista os possíveis valores para o *nRetCode* parâmetro.

|nRetCode|Descrição|
|--------------|-----------------|
|SQL_SUCCESS|Função foi concluída com êxito; Nenhuma informação adicional está disponível.|
|SQL_SUCCESS_WITH_INFO|Função foi concluída com êxito, possivelmente com um erro não fatal. Informações adicionais podem ser obtidas chamando `SQLError`.|
|SQL_NO_DATA_FOUND|Todas as linhas do conjunto de resultados tenham sido buscadas.|
|SQL_ERROR|Falha na função. Informações adicionais podem ser obtidas chamando `SQLError`.|
|SQL_INVALID_HANDLE|Função falhou devido a um identificador de ambiente inválida, o identificador de conexão ou o identificador de instrução. Isso indica um erro de programação. Nenhuma informação adicional está disponível no `SQLError`.|
|SQL_STILL_EXECUTING|Uma função que foi iniciada de forma assíncrona ainda está em execução. Observe que por padrão, MFC nunca passará esse valor para `CheckRowsetError`; MFC continuarão a chamar `SQLExtendedFetch` até que ele não retornará SQL_STILL_EXECUTING.|

Para obter mais informações sobre `SQLError`, consulte o SDK do Windows. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="close"></a>  CRecordset::Close

Fecha o conjunto de registros.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

O ODBC HSTMT e toda a memória alocada para o conjunto de registros a estrutura de são desalocados. Normalmente, depois de chamar `Close`, exclua o objeto de conjunto de registros de C++, se ele foi alocado com **nova**.

Você pode chamar `Open` novamente depois de chamar `Close`. Isso lhe permite reutilizar o objeto de conjunto de registros. A alternativa é chamar `Requery`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#17](../../mfc/codesnippet/cpp/crecordset-class_1.cpp)]

##  <a name="crecordset"></a>  CRecordset::CRecordset

Constrói um objeto `CRecordset`.

```
CRecordset(CDatabase* pDatabase = NULL);
```

### <a name="parameters"></a>Parâmetros

*pDatabase*<br/>
Contém um ponteiro para um `CDatabase` objeto ou o valor NULL. Se não for NULL e o `CDatabase` do objeto `Open` função de membro não tiver sido chamada para conectar-se à fonte de dados, o conjunto de registros tenta abri-lo para você durante a sua própria `Open` chamar. Se você passar NULL, um `CDatabase` objeto é construído e conectado para você usando as informações de fonte de dados especificado quando você derivada sua classe de conjunto de registros com ClassWizard.

### <a name="remarks"></a>Comentários

Você pode usar `CRecordset` diretamente ou derivar uma classe específica do aplicativo de `CRecordset`. Você pode usar o ClassWizard derivar suas classes de conjunto de registros.

> [!NOTE]
>  Uma classe derivada *deve* fornecer seu próprio construtor. No construtor da classe derivada, chame o construtor `CRecordset::CRecordset`, passando os parâmetros apropriados ao longo para ele.

Transmitir NULL para o construtor de conjunto de registros para ter um `CDatabase` objeto construído e conectado automaticamente para você. Isso é uma abreviação úteis que não exige que você construa e conectar-se um `CDatabase` objeto antes de construir o conjunto de registros.

### <a name="example"></a>Exemplo

Para obter mais informações, consulte o artigo [conjunto de registros: declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md).

##  <a name="delete"></a>  CRecordset::Delete

Exclui o registro atual.

```
virtual void Delete();
```

### <a name="remarks"></a>Comentários

Após a exclusão de bem-sucedida, os membros de dados de campo do conjunto de registros são definidos como um valor Null, e você deve chamar explicitamente um do `Move` funções para deixar de usar o registro excluído. Depois que você remover o registro excluído, não é possível retornar a ele. Se a fonte de dados oferece suporte a transações, você pode fazer o `Delete` chamar parte de uma transação. Para obter mais informações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).

> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa, você não pode chamar `Delete`. Isso resultará em uma declaração com falha. Embora a classe `CRecordset` não fornece um mecanismo para atualizar linhas em massa de dados, você pode escrever suas próprias funções usando a função de API ODBC `SQLSetPos`. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

> [!CAUTION]
>  O conjunto de registros deve ser atualizável e deve haver um registro válido atual no conjunto de registros ao chamar `Delete`; caso contrário, ocorrerá um erro. Por exemplo, se você excluir um registro, mas não rola para um novo registro antes de chamar `Delete` novamente, `Delete` lança uma [CDBException](../../mfc/reference/cdbexception-class.md).

Diferentemente [AddNew](#addnew) e [editar](#edit), uma chamada para `Delete` não é seguido por uma chamada para [atualização](#update). Se um `Delete` chamada falhar, os dados do campo membros são deixados inalterados.

### <a name="example"></a>Exemplo

Este exemplo mostra um conjunto de registros criado no quadro de uma função. O exemplo supõe a existência de `m_dbCust`, uma variável de membro de tipo `CDatabase` já está conectado à fonte de dados.

[!code-cpp[NVC_MFCDatabase#18](../../mfc/codesnippet/cpp/crecordset-class_2.cpp)]

##  <a name="dobulkfieldexchange"></a>  CRecordset::DoBulkFieldExchange

Chamado para linhas em massa de dados da fonte de dados para o conjunto de registros do exchange. Implementa em massa registrar troca de campos (RFX em massa).

```
virtual void DoBulkFieldExchange(CFieldExchange* pFX);
```

### <a name="parameters"></a>Parâmetros

*pFX*<br/>
Um ponteiro para um [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) objeto. A estrutura será já tiver configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Quando a busca de linhas em massa é implementada, o framework chama essa função de membro para transferir automaticamente os dados da fonte de dados para seu objeto de conjunto de registros. `DoBulkFieldExchange` também associa os membros de dados de parâmetro, se houver espaços reservados de parâmetros na cadeia de caracteres de instrução SQL para a seleção do conjunto de registros.

Se não for implementado a busca de linhas em massa, o framework chama [DoFieldExchange](#dofieldexchange). Para implementar a busca de linhas em massa, você deve especificar o `CRecordset::useMultiRowFetch` opção do *dwOptions* parâmetro no [abrir](#open) função de membro.

> [!NOTE]
> `DoBulkFieldExchange` está disponível apenas se você estiver usando uma classe derivada de `CRecordset`. Se você tiver criado um objeto recordset diretamente a partir `CRecordset`, você deve chamar o [GetFieldValue](#getfieldvalue) a função de membro para recuperar dados.

Troca de campos de registro em massa (RFX em massa) é semelhante ao registrar troca de campos (RFX). Automaticamente, os dados são transferidos da fonte de dados para o objeto de conjunto de registros. No entanto, você não pode chamar `AddNew`, `Edit`, `Delete`, ou `Update` para transferir as alterações de volta para a fonte de dados. Classe `CRecordset` atualmente não fornece um mecanismo para atualizar linhas em massa de dados; no entanto, você pode escrever suas próprias funções usando a função de API ODBC `SQLSetPos`.

Observe que o ClassWizard não suporta a troca de campos de registro em massa; Portanto, você deve substituir `DoBulkFieldExchange` manualmente ao escrever chamadas para as funções RFX em massa. Para obter mais informações sobre essas funções, consulte o tópico [funções de troca de campo do registro](../../mfc/reference/record-field-exchange-functions.md).

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter informações relacionadas, consulte o artigo [Exchange RFX (Record Field)](../../data/odbc/record-field-exchange-rfx.md).

##  <a name="dofieldexchange"></a>  CRecordset::DoFieldExchange

Chamado para trocar dados (em ambas as direções) entre os membros de dados do campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa registra troca de campos (RFX).

```
virtual void DoFieldExchange(CFieldExchange* pFX);
```

### <a name="parameters"></a>Parâmetros

*pFX*<br/>
Um ponteiro para um [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) objeto. A estrutura será já tiver configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Quando a busca de linhas em massa não for implementado, o framework chama essa função de membro para automaticamente trocar dados entre os membros de dados do campo de seu objeto de conjunto de registros e as colunas correspondentes do registro atual na fonte de dados. `DoFieldExchange` também associa os membros de dados de parâmetro, se houver espaços reservados de parâmetros na cadeia de caracteres de instrução SQL para a seleção do conjunto de registros.

Se a busca de linhas em massa for implementado, o framework chama [DoBulkFieldExchange](#dobulkfieldexchange). Para implementar a busca de linhas em massa, você deve especificar o `CRecordset::useMultiRowFetch` opção do *dwOptions* parâmetro no [abrir](#open) função de membro.

> [!NOTE]
> `DoFieldExchange` está disponível apenas se você estiver usando uma classe derivada de `CRecordset`. Se você tiver criado um objeto recordset diretamente a partir `CRecordset`, você deve chamar o [GetFieldValue](#getfieldvalue) a função de membro para recuperar dados.

A troca de dados de campo, chamados registrar troca de campos (RFX) funciona em ambas as direções: de membros de dados de campo do objeto de conjunto de registros para os campos do registro na fonte de dados e de registro na fonte de dados para o objeto de conjunto de registros.

A única ação que você normalmente deve adotar para implementar `DoFieldExchange` para seu conjunto de registros derivado classe é criar a classe com ClassWizard e especificar os tipos de dados e nomes dos membros de dados de campo. Você também pode adicionar código para o que grava ClassWizard para especificar os membros de dados de parâmetro ou lidar com quaisquer colunas que você associar dinamicamente. Para obter mais informações, consulte o artigo [conjunto de registros: dinamicamente associando dados colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Quando você declarar sua classe derivada do conjunto de registros com ClassWizard, o assistente grava uma substituição do `DoFieldExchange` para você, que se parece com o exemplo a seguir:

[!code-cpp[NVC_MFCDatabase#19](../../mfc/codesnippet/cpp/crecordset-class_3.cpp)]

Para obter mais informações sobre as funções RFX, consulte o tópico [funções de troca de campo do registro](../../mfc/reference/record-field-exchange-functions.md).

Para obter mais exemplos e detalhes sobre `DoFieldExchange`, consulte o artigo [registrar troca de campos: como funciona a RFX](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter informações gerais sobre RFX, consulte o artigo [troca de campos do registro](../../data/odbc/record-field-exchange-rfx.md).

##  <a name="edit"></a>  CRecordset::Edit

Permite que as alterações no registro atual.

```
virtual void Edit();
```

### <a name="remarks"></a>Comentários

Depois de chamar `Edit`, você pode alterar os membros de dados do campo redefinindo diretamente seus valores. A operação é concluída quando você chama subsequentemente o [atualização](#update) função de membro para salvar suas alterações na fonte de dados.

> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa, você não pode chamar `Edit`. Isso resultará em uma declaração com falha. Embora a classe `CRecordset` não fornece um mecanismo para atualizar linhas em massa de dados, você pode escrever suas próprias funções usando a função de API ODBC `SQLSetPos`. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

`Edit` salva os valores do conjunto de registros membros de dados. Se você chamar `Edit`, faça alterações, em seguida, chame `Edit` novamente, os valores do registro são restaurados ao que eram antes da primeira `Edit` chamar.

Em alguns casos, você talvez queira atualizar uma coluna, tornando a Null (que contém nenhum dado). Para fazer isso, chame [SetFieldNull](#setfieldnull) com um parâmetro de True para marcar o campo nulo; isso também faz com que a coluna a ser atualizada. Se você quiser que um campo para ser gravado para a fonte de dados, mesmo que seu valor não mudou, chame [SetFieldDirty](#setfielddirty) com um parâmetro de TRUE. Isso funciona mesmo se o campo tivesse o valor Null.

Se a fonte de dados oferece suporte a transações, você pode fazer o `Edit` chamar parte de uma transação. Observe que você deve chamar [CDatabase::BeginTrans](../../mfc/reference/cdatabase-class.md#begintrans) antes de chamar `Edit` e depois que o conjunto de registros foi aberto. Observe também que a chamada [CDatabase::CommitTrans](../../mfc/reference/cdatabase-class.md#committrans) não é um substituto para chamar `Update` para concluir o `Edit` operação. Para obter mais informações sobre transações, consulte a classe [CDatabase](../../mfc/reference/cdatabase-class.md).

Dependendo do modo de bloqueio atual, o registro que está sendo atualizado pode estar bloqueado por `Edit` até que você chame `Update` ou de rolagem para outro registro, ou ele poderá estar bloqueado somente durante o `Edit` chamar. Você pode alterar o modo de bloqueio com [SetLockingMode](#setlockingmode).

O valor anterior do registro atual é restaurado se você rolar para um novo registro antes de chamar `Update`. Um `CDBException` é lançada se você chamar `Edit` para um conjunto de registros não pode ser atualizado ou se não há nenhum registro atual.

Para obter mais informações, consulte os artigos [transação (ODBC)](../../data/odbc/transaction-odbc.md) e [conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#20](../../mfc/codesnippet/cpp/crecordset-class_4.cpp)]

##  <a name="flushresultset"></a>  CRecordset::FlushResultSet

Recupera o próximo conjunto de resultados de uma consulta predefinida (procedimento armazenado), se houver vários conjuntos de resultados.

```
BOOL FlushResultSet();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se não houver mais conjuntos de resultados a serem recuperados; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve chamar `FlushResultSet` apenas quando estiver totalmente encerrado com o cursor no conjunto de resultados atual. Observe que, quando você recupera o próximo resultado definido chamando `FlushResultSet`, o cursor não é válido nesse conjunto de resultados; você deve chamar o [MoveNext](#movenext) a função de membro depois de chamar `FlushResultSet`.

Se uma consulta predefinida usa um parâmetro de saída ou parâmetros de entrada/saída, você deve chamar `FlushResultSet` até ele retornar `FALSE` (o valor 0), para obter esses valores de parâmetro.

`FlushResultSet` chama a função ODBC API `SQLMoreResults`. Se `SQLMoreResults` retornará SQL_ERROR ou SQL_INVALID_HANDLE, em seguida, `FlushResultSet` lançará uma exceção. Para obter mais informações sobre `SQLMoreResults`, consulte o SDK do Windows.

O procedimento armazenado precisa ter associado campos se desejar chamar `FlushResultSet`.

### <a name="example"></a>Exemplo

O código a seguir supõe que `COutParamRecordset` é um `CRecordset`-objeto derivado com base em uma consulta predefinida com um parâmetro de entrada e um parâmetro de saída e ter vários conjuntos de resultados. Observe a estrutura do [DoFieldExchange](#dofieldexchange) substituir.

[!code-cpp[NVC_MFCDatabase#21](../../mfc/codesnippet/cpp/crecordset-class_5.cpp)]

[!code-cpp[NVC_MFCDatabase#22](../../mfc/codesnippet/cpp/crecordset-class_6.cpp)]

##  <a name="getbookmark"></a>  CRecordset::GetBookmark

Obtém o valor de indicador para o registro atual.

```
void GetBookmark(CDBVariant& varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Uma referência a um [CDBVariant](../../mfc/reference/cdbvariant-class.md) objeto que representa o indicador no registro atual.

### <a name="remarks"></a>Comentários

Para determinar se os indicadores são compatíveis com o conjunto de registros, chame [CanBookmark](#canbookmark). Para disponibilizar marcadores se eles tiverem suporte, você deve definir a `CRecordset::useBookmarks` opção a *dwOptions* parâmetro do [abrir](#open) função de membro.

> [!NOTE]
>  Se os indicadores são sem suporte ou não está disponível, chamada `GetBookmark` resultará em uma exceção sendo lançada. Não há suporte para os indicadores em conjuntos de registros somente de encaminhamento.

`GetBookmark` atribui o valor do indicador para o registro atual para um `CDBVariant` objeto. Para retornar a esse registro a qualquer momento após a mudança para um registro diferente, chame [SetBookmark](#setbookmark) com a correspondente `CDBVariant` objeto.

> [!NOTE]
>  Depois de determinadas operações de conjunto de registros, indicadores podem não ser válidos. Por exemplo, se você chamar `GetBookmark` seguido por `Requery`, você não poderá retornar para o registro com `SetBookmark`. Chame [CDatabase::GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se você pode chamar com segurança `SetBookmark`.

Para obter mais informações sobre indicadores e navegação de conjunto de registros, consulte os artigos [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

##  <a name="getdefaultconnect"></a>  Crecordset:: Getdefaultconnect

Chamado para obter a cadeia de caracteres de conexão padrão.

```
virtual CString GetDefaultConnect();
```

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém a cadeia de conexão padrão.

### <a name="remarks"></a>Comentários

O framework chama essa função de membro para obter a cadeia de caracteres de conexão padrão para a fonte de dados no qual o conjunto de registros é baseado. ClassWizard implementa essa função para você, identificando a mesma fonte de dados que você usa no ClassWizard para obter informações sobre tabelas e colunas. Você provavelmente achará conveniente contar com essa conexão padrão ao desenvolver seu aplicativo. Mas a conexão padrão pode não ser apropriado para usuários do seu aplicativo. Se esse for o caso, você deve reimplementar a essa função, descartando a versão do ClassWizard. Para obter mais informações sobre cadeias de caracteres de conexão, consulte o artigo [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md).

##  <a name="getdefaultsql"></a>  CRecordset::GetDefaultSQL

Chamado para obter a cadeia de caracteres SQL padrão para executar.

```
virtual CString GetDefaultSQL();
```

### <a name="return-value"></a>Valor de retorno

Um `CString` que contém a instrução SQL padrão.

### <a name="remarks"></a>Comentários

O framework chama essa função de membro para obter a instrução de SQL padrão no qual o conjunto de registros é baseado. Isso pode ser um nome de tabela ou um SQL **selecionar** instrução.

Definir, indiretamente, a instrução SQL padrão, declarando a sua classe de conjunto de registros com ClassWizard e ClassWizard realiza essa tarefa para você.

Se você precisar de cadeia de caracteres de instrução SQL para seu próprio uso, chamar `GetSQL`, que retorna a instrução SQL usada para selecionar registros do conjunto de registros quando ele foi aberto. Você pode editar a cadeia de caracteres padrão SQL em sua substituição da classe `GetDefaultSQL`. Por exemplo, você poderia especificar uma chamada para uma consulta predefinida, usando um **chamar** instrução. (Observe que, no entanto, que, se você editar `GetDefaultSQL`, você também precisará modificar `m_nFields` para corresponder ao número de colunas na fonte de dados.)

Para obter mais informações, consulte o artigo [conjunto de registros: declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md).

> [!CAUTION]
>  O nome da tabela estará vazio se a estrutura não pôde identificar um nome de tabela, se vários nomes de tabela foram fornecidos, ou se um **chamar** instrução não pôde ser interpretada. Observe que, ao usar um **chamar** instrução, você não deve inserir o espaço em branco entre a chave de abertura e o **chamar** palavra-chave, nem você deve inserir espaços em branco antes da chave de abertura ou antes do  **Selecione** palavra-chave em um **selecione** instrução.

##  <a name="getfieldvalue"></a>  CRecordset::GetFieldValue

Recupera dados do campo no registro atual.

```
void GetFieldValue(
    LPCTSTR lpszName,
    CDBVariant& varValue,
    short nFieldType = DEFAULT_FIELD_TYPE);

void GetFieldValue(
    short nIndex,
    CDBVariant& varValue,
    short nFieldType = DEFAULT_FIELD_TYPE);

void GetFieldValue(
    short nIndex,
    CStringA& strValue);

void GetFieldValue(
    short nIndex,
    CStringW& strValue);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome de um campo.

*varValu*referência e um para um [CDBVariant](../../mfc/reference/cdbvariant-class.md) objeto que armazenará o valor do campo.

*nFieldType*<br/>
O tipo de dados ODBC C do campo. Usando o valor padrão, DEFAULT_FIELD_TYPE, força `GetFieldValue` determinar o tipo de dados C do tipo de dados SQL, com base na tabela a seguir. Caso contrário, você pode especificar os dados digitados diretamente ou escolha um tipo de dados compatíveis; Por exemplo, você pode armazenar qualquer tipo de dados em SQL_C_CHAR.

|Tipo de dados C|Tipo de dados SQL|
|-----------------|-------------------|
|SQL_C_BIT|SQL_BIT|
|SQL_C_UTINYINT|SQL_TINYINT|
|SQL_C_SSHORT|SQL_SMALLINT|
|SQL_C_SLONG|SQL_INTEGER|
|SQL_C_FLOAT|SQL_REAL|
|SQL_C_DOUBLE|SQL_FLOATSQL_DOUBLE|
|SQL_C_TIMESTAMP|SQL_DATESQL_TIMESQL_TIMESTAMP|
|SQL_C_CHAR|SQL_NUMERICSQL_DECIMALSQL_BIGINTSQL_CHARSQL_VARCHARSQL_LONGVARCHAR|
|SQL_C_BINARY|SQL_BINARYSQL_VARBINARYSQL_LONGVARBINARY|

Para obter mais informações sobre tipos de dados ODBC, consulte os tópicos "Tipos de dados SQL" e "Tipos de dados C" no Apêndice D do SDK do Windows.

*nIndex*<br/>
O índice baseado em zero do campo.

*strValue*<br/>
Uma referência a um [CString](../../atl-mfc-shared/reference/cstringt-class.md) objeto que armazenará o valor do campo convertido em texto, independentemente do tipo de dados do campo.

### <a name="remarks"></a>Comentários

Você pode pesquisar um campo por nome ou por índice. Você pode armazenar o valor do campo em qualquer um uma `CDBVariant` objeto ou um `CString` objeto.

Se você tiver implementado a busca de linhas em massa, o registro atual é sempre posicionado no primeiro registro em um conjunto de linhas. Para usar `GetFieldValue` em um registro dentro de um determinado conjunto de linhas, você deve primeiro chamar o [SetRowsetCursorPosition](#setrowsetcursorposition) a função de membro para mover o cursor na linha desejada dentro desse conjunto de linhas. Em seguida, chame `GetFieldValue` para aquela linha. Para implementar a busca de linhas em massa, você deve especificar o `CRecordset::useMultiRowFetch` opção do *dwOptions* parâmetro no [abrir](#open) função de membro.

Você pode usar `GetFieldValue` ao buscar dinamicamente os campos no tempo de execução em vez de associá-los a estaticamente no tempo de design. Por exemplo, se você declarar um objeto de conjunto de registros diretamente a partir `CRecordset`, você deve usar `GetFieldValue` para recuperar os dados de campo; registrar troca de campos (RFX) ou em massa registrar troca de campos (RFX em massa), não está implementada.

> [!NOTE]
>  Se você declarar um objeto de conjunto de registros sem derivar da `CRecordset`, não tem a biblioteca de cursores ODBC carregado. A biblioteca de cursores requer que o conjunto de registros tem pelo menos uma coluna associada; No entanto, quando você usa `CRecordset` diretamente, nenhuma das colunas são associadas. As funções de membro [CDatabase:: Openex](../../mfc/reference/cdatabase-class.md#openex) e [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open) controlar se a biblioteca de cursores será carregada.

`GetFieldValue` chama a função ODBC API `SQLGetData`. Se o driver gera o valor SQL_NO_TOTAL para o comprimento real do valor do campo, `GetFieldValue` gera uma exceção. Para obter mais informações sobre `SQLGetData`, consulte o SDK do Windows.

### <a name="example"></a>Exemplo

O código de exemplo a seguir ilustra chamadas para `GetFieldValue` para um objeto recordset declarados diretamente do `CRecordset`.

[!code-cpp[NVC_MFCDatabase#23](../../mfc/codesnippet/cpp/crecordset-class_7.cpp)]

> [!NOTE]
>  Ao contrário da classe DAO `CDaoRecordset`, `CRecordset` não tem um `SetFieldValue` função de membro. Se você criar um objeto diretamente do `CRecordset`, ele é efetivamente somente leitura.

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="getodbcfieldcount"></a>  CRecordset::GetODBCFieldCount

Recupera o número total de campos em seu objeto de conjunto de registros.

```
short GetODBCFieldCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de campos no conjunto de registros.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como criar conjuntos de registros, consulte o artigo [conjunto de registros: Criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

##  <a name="getodbcfieldinfo"></a>  CRecordset::GetODBCFieldInfo

Obtém informações sobre os campos no conjunto de registros.

```
void GetODBCFieldInfo(
    LPCTSTR lpszName,
    CODBCFieldInfo& fieldinfo);

void GetODBCFieldInfo(
    short nIndex,
    CODBCFieldInfo& fieldinfo);
```

### <a name="parameters"></a>Parâmetros

*lpszName*<br/>
O nome de um campo.

*FieldInfo*<br/>
Uma referência a um `CODBCFieldInfo` estrutura.

*nIndex*<br/>
O índice baseado em zero do campo.

### <a name="remarks"></a>Comentários

Uma versão da função permite pesquisar um campo por nome. A outra versão permite pesquisar um campo por índice.

Para obter uma descrição sobre as informações retornadas, consulte o [CODBCFieldInfo](../../mfc/reference/codbcfieldinfo-structure.md) estrutura.

Para obter mais informações sobre como criar conjuntos de registros, consulte o artigo [conjunto de registros: Criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

##  <a name="getrecordcount"></a>  CRecordset::GetRecordCount

Determina o tamanho do conjunto de registros.

```
long GetRecordCount() const;
```

### <a name="return-value"></a>Valor de retorno

O número de registros no conjunto de registros; 0 se o conjunto de registros não contiver registros; ou -1 se a contagem de registros não pode ser determinada.

### <a name="remarks"></a>Comentários

> [!CAUTION]
>  A contagem de registros é mantida como uma "marca d'água alta," o registro de número mais alto ainda Vista quando o usuário move todos os registros. O número total de registros é conhecido somente depois que o usuário foi movido para fora o último registro. Por motivos de desempenho, a contagem não é atualizada quando você chamar `MoveLast`. Para contar os registros, chame `MoveNext` repetidamente até que `IsEOF` retorna não zero. Adicionar um registro por meio `CRecordset:AddNew` e `Update` aumenta a contagem; para exclusão de um registro por meio de `CRecordset::Delete` diminui a contagem.

##  <a name="getrowsetsize"></a>  CRecordset::GetRowsetSize

Obtém a configuração atual para o número de linhas que deseja recuperar durante uma busca de determinado.

```
DWORD GetRowsetSize() const;
```

### <a name="return-value"></a>Valor de retorno

O número de linhas a serem recuperadas durante uma busca de determinado.

### <a name="remarks"></a>Comentários

Se você estiver usando a busca de linhas em massa, o tamanho do conjunto de linhas padrão quando o conjunto de registros é aberto é 25; Caso contrário, ele é 1.

Para implementar a busca de linhas em massa, você deve especificar o `CRecordset::useMultiRowFetch` opção a *dwOptions* parâmetro do [abrir](#open) função de membro. Para alterar a configuração para o tamanho do conjunto de linhas, chame [SetRowsetSize](#setrowsetsize).

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="getrowsfetched"></a>  CRecordset::GetRowsFetched

Determina quantos registros foram realmente recuperado após uma busca.

```
DWORD GetRowsFetched() const;
```

### <a name="return-value"></a>Valor de retorno

O número de linhas recuperadas da fonte de dados após uma busca de determinado.

### <a name="remarks"></a>Comentários

Isso é útil quando você tiver implementado a busca de linhas em massa. O tamanho do conjunto de linhas normalmente indica quantas linhas serão recuperadas de uma busca; No entanto, o número total de linhas no conjunto de registros também afeta o número de linhas será recuperado em um conjunto de linhas. Por exemplo, se seu conjunto de registros tiver 10 registros com uma configuração de tamanho do conjunto de linhas de 4, em seguida, um loop pelo conjunto de registros chamando `MoveNext` resultará no conjunto de linhas final tendo apenas 2 registros.

Para implementar a busca de linhas em massa, você deve especificar o `CRecordset::useMultiRowFetch` opção a *dwOptions* parâmetro do [abrir](#open) função de membro. Para especificar o tamanho do conjunto de linhas, chame [SetRowsetSize](#setrowsetsize).

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#24](../../mfc/codesnippet/cpp/crecordset-class_8.cpp)]

##  <a name="getrowstatus"></a>  CRecordset::GetRowStatus

Obtém o status de uma linha no conjunto de linhas atual.

```
WORD GetRowStatus(WORD wRow) const;
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A com base em uma posição de uma linha no conjunto de linhas atual. Esse valor pode variar de 1 para o tamanho do conjunto de linhas.

### <a name="return-value"></a>Valor de retorno

Um valor de status para a linha. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

`GetRowStatus` Retorna um valor que indica a qualquer alteração no status para a linha desde a última recuperados da fonte de dados, ou que nenhuma linha correspondente ao *wRow* foi buscada. A tabela a seguir lista os possíveis valores de retorno.

|Valor de status|Descrição|
|------------------|-----------------|
|SQL_ROW_SUCCESS|A linha for alterada.|
|SQL_ROW_UPDATED|A linha foi atualizada.|
|SQL_ROW_DELETED|A linha foi excluída.|
|SQL_ROW_ADDED|A linha foi adicionada.|
|SQL_ROW_ERROR|A linha não é possível recuperar devido a um erro.|
|SQL_ROW_NOROW|Não há nenhuma linha que corresponde ao *wRow*.|

Para obter mais informações, consulte a função de API ODBC `SQLExtendedFetch` no SDK do Windows.

##  <a name="getstatus"></a>  CRecordset::GetStatus

Determina o índice do registro atual no conjunto de registros e se o último registro foi visto.

```
void GetStatus(CRecordsetStatus& rStatus) const;
```

### <a name="parameters"></a>Parâmetros

*rStatus*<br/>
Uma referência a um objeto `CRecordsetStatus`. Consulte a seção Comentários para obter mais informações.

### <a name="remarks"></a>Comentários

`CRecordset` tenta controlar o índice, mas em algumas circunstâncias isso talvez não seja possível. Ver [GetRecordCount](#getrecordcount) para obter uma explicação.

O `CRecordsetStatus` estrutura tem a seguinte forma:

```cpp
struct CRecordsetStatus
{
    long m_lCurrentRecord;
    BOOL m_bRecordCountFinal;
};
```

Os dois membros da `CRecordsetStatus` têm os seguintes significados:

- `m_lCurrentRecord` Contém o índice baseado em zero do registro atual no conjunto de registros, se conhecido. Se o índice não pode ser determinado, esse membro contém AFX_CURRENT_RECORD_UNDEFINED (-2). Se `IsBOF` é TRUE (conjunto de registros vazio ou tentativa de rolar antes do primeiro registro), em seguida, `m_lCurrentRecord` é definido como AFX_CURRENT_RECORD_BOF (-1). Se no primeiro registro, em seguida, ele é definido como 0, segundo gravar 1 e assim por diante.

- `m_bRecordCountFinal` Diferente de zero se o número total de registros no conjunto de registros foi determinado. Geralmente, isso deve ser feito desde o início do conjunto de registros e chamando `MoveNext` até que `IsEOF` retorna não zero. Se esse membro for zero, o registro de contagem como retornado por `GetRecordCount`, se não -1, é somente uma contagem de "marca d'água de alta" dos registros.

##  <a name="getsql"></a>  CRecordset::GetSQL

Chame essa função de membro para obter a instrução SQL que foi usada para selecionar registros do conjunto de registros quando ele foi aberto.

```
const CString& GetSQL() const;
```

### <a name="return-value"></a>Valor de retorno

Um **const** fazem referência a um `CString` que contém a instrução SQL.

### <a name="remarks"></a>Comentários

Isso geralmente será um SQL **selecionar** instrução. A cadeia de caracteres retornada por `GetSQL` é somente leitura.

A cadeia de caracteres retornada por `GetSQL` normalmente é diferente de qualquer cadeia de caracteres que você pode já ter passado para o conjunto de registros em de *lpszSQL* parâmetro para o `Open` função de membro. Isso ocorre porque o conjunto de registros constrói uma instrução SQL completa com base no passado para `Open`, o que você especificou com ClassWizard, o que você pode ter especificado nos `m_strFilter` e `m_strSort` membros de dados e quaisquer parâmetros que você pode ter especificado. Para obter detalhes sobre como o conjunto de registros constrói essa instrução SQL, consulte o artigo [conjunto de registros: como conjuntos de registros selecionar registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

> [!NOTE]
>  Chame essa função de membro somente depois de chamar [aberto](#open).

##  <a name="gettablename"></a>  CRecordset::GetTableName

Obtém o nome da tabela SQL no qual a consulta do conjunto de registros é baseada.

```
const CString& GetTableName() const;
```

### <a name="return-value"></a>Valor de retorno

Um **const** fazem referência a um `CString` que contém a tabela de nome, se o conjunto de registros é com base em uma tabela; Caso contrário, uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

`GetTableName` só será válida se o conjunto de registros baseia-se em uma tabela, não uma junção de várias tabelas ou uma consulta predefinida (procedimento armazenado). O nome é somente leitura.

> [!NOTE]
>  Chame essa função de membro somente depois de chamar [aberto](#open).

##  <a name="isbof"></a>  CRecordset::IsBOF

Retorna diferente de zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há nenhum registro atual.

```
BOOL IsBOF() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros não contiver registros ou se você percorreu para trás antes do primeiro registro; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função de membro antes de você rolar de registro para o registro para saber se você passou antes do primeiro registro do conjunto de registros. Você também pode usar `IsBOF` juntamente com `IsEOF` para determinar se o conjunto de registros contém todos os registros ou está vazio. Imediatamente depois de chamar `Open`, se o conjunto de registros não contiver registros, `IsBOF` retorna não zero. Quando você abre um conjunto de registros que tenha pelo menos um registro, o primeiro registro é o registro atual e `IsBOF` retornará 0.

Se o primeiro registro é o registro atual e você chamar `MovePrev`, `IsBOF` subsequentemente retornará diferente de zero. Se `IsBOF` retorna diferente de zero e você chamar `MovePrev`, ocorrerá um erro. Se `IsBOF` retorna diferente de zero, o registro atual é indefinido e qualquer ação que requer um registro atual resultará em erro.

### <a name="example"></a>Exemplo

Este exemplo usa `IsBOF` e `IsEOF` para detectar os limites de um conjunto de registros, como o código percorre o conjunto de registros em ambas as direções.

[!code-cpp[NVC_MFCDatabase#25](../../mfc/codesnippet/cpp/crecordset-class_9.cpp)]

##  <a name="isdeleted"></a>  CRecordset::IsDeleted

Determina se o registro atual foi excluído.

```
BOOL IsDeleted() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros é posicionado em um registro excluído; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você rolar para um registro e `IsDeleted` retorna TRUE (diferente de zero) e, em seguida, você deve rolar para outro registro antes de executar outras operações de conjunto de registros.

O resultado de `IsDeleted` depende de vários fatores, como o tipo de conjunto de registros, se seu conjunto de registros é atualizável, se você especificou o `CRecordset::skipDeletedRecords` opção quando você abriu o conjunto de registros, se os registros excluídos de seus pacotes de driver e se há vários usuários.

Para obter mais informações sobre `CRecordset::skipDeletedRecords` e o driver de remessa, consulte a [aberto](#open) função de membro.

> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa, você não deve chamar `IsDeleted`. Em vez disso, chame o [GetRowStatus](#getrowstatus) função de membro. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="iseof"></a>  CRecordset::IsEOF

Retorna diferente de zero se o conjunto de registros tiver sido posicionado após o último registro. Não há nenhum registro atual.

```
BOOL IsEOF() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros não contiver registros ou se você percorreu além do último registro; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função de membro conforme você rola do registro a registro para saber se você passou além do último registro do conjunto de registros. Você também pode usar `IsEOF` para determinar se o conjunto de registros contém todos os registros ou está vazio. Imediatamente depois de chamar `Open`, se o conjunto de registros não contiver registros, `IsEOF` retorna não zero. Quando você abre um conjunto de registros que tenha pelo menos um registro, o primeiro registro é o registro atual e `IsEOF` retornará 0.

Se o último registro é o registro atual quando você chama `MoveNext`, `IsEOF` subsequentemente retornará diferente de zero. Se `IsEOF` retorna diferente de zero e você chamar `MoveNext`, ocorrerá um erro. Se `IsEOF` retorna diferente de zero, o registro atual é indefinido e qualquer ação que requer um registro atual resultará em erro.

### <a name="example"></a>Exemplo

Veja o exemplo de [IsBOF](#isbof).

##  <a name="isfielddirty"></a>  CRecordset::IsFieldDirty

Determina se o membro de dados do campo especificado foi alterado desde [edite](#edit) ou [AddNew](#addnew) foi chamado.

```
BOOL IsFieldDirty(void* pv);
```

### <a name="parameters"></a>Parâmetros

*VP*<br/>
Um ponteiro para o membro de dados do campo cujo status você deseja verificar ou nulo para determinar se qualquer um dos campos estão sujos.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o membro de dados do campo especificado foi alterado desde a chamada `AddNew` ou `Edit`; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os dados em todos os membros de dados sujas do campo serão transferidos para o registro na fonte de dados quando o registro atual é atualizado por uma chamada para o [atualização](#update) função de membro `CRecordset` (após uma chamada para `Edit` ou `AddNew`).

> [!NOTE]
>  Essa função de membro não é aplicável em conjuntos de registros que estão usando a busca de linhas em massa. Se você tiver implementado busca de linhas em massa, em seguida, `IsFieldDirty` sempre retornará FALSE e resultará em uma declaração com falha. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Chamando `IsFieldDirty` redefinirá os efeitos das anteriores chamadas para [SetFieldDirty](#setfielddirty) , pois o status de falta de limpeza do campo é reavaliado. No `AddNew` caso, se o valor do campo atual difere do valor pseudo nulo, o campo status está definido sujo. No `Edit` caso, se o valor do campo for diferente do valor armazenado em cache, em seguida, o status de campo é definido sujo.

`IsFieldDirty` é implementado por meio [DoFieldExchange](#dofieldexchange).

Para obter mais informações sobre o sinalizador sujo, consulte o artigo [conjunto de registros: como conjuntos de registros selecionar registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

##  <a name="isfieldnull"></a>  CRecordset::IsFieldNull

Retorna não zero se o campo especificado no registro atual é nulo (não tem nenhum valor).

```
BOOL IsFieldNull(void* pv);
```

### <a name="parameters"></a>Parâmetros

*VP*<br/>
Um ponteiro para o membro de dados do campo cujo status você deseja verificar ou nulo para determinar se qualquer um dos campos serão Null.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o membro de dados do campo especificado é sinalizado como Null; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função de membro para determinar se o membro de dados do campo especificado de um conjunto de registros foi sinalizado como Null. (Na terminologia de banco de dados, Null significa "não ter nenhum valor" e não é igual a NULL em C++.) Se um membro de dados do campo for sinalizado como Null, ele será interpretado como uma coluna do registro atual para o qual não há nenhum valor.

> [!NOTE]
>  Essa função de membro não é aplicável em conjuntos de registros que estão usando a busca de linhas em massa. Se você tiver implementado busca de linhas em massa, em seguida, `IsFieldNull` sempre retornará FALSE e resultará em uma declaração com falha. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

`IsFieldNull` é implementado por meio [DoFieldExchange](#dofieldexchange).

##  <a name="isfieldnullable"></a>  CRecordset::IsFieldNullable

Retorna diferente de zero se o campo especificado no registro atual pode ser definido como Null (com nenhum valor).

```
BOOL IsFieldNullable(void* pv);
```

### <a name="parameters"></a>Parâmetros

*VP*<br/>
Um ponteiro para o membro de dados do campo cujo status você deseja verificar ou nulo para determinar se qualquer um dos campos podem ser definidos como um valor nulo.

### <a name="remarks"></a>Comentários

Chame essa função de membro determinar se o membro de dados do campo especificado é "que permite valor nulo" (pode ser definido como um valor nulo; C++ nulo não é igual a Null, que, na terminologia de banco de dados, significa "having sem valor").

> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa, você não pode chamar `IsFieldNullable`. Em vez disso, chame o [GetODBCFieldInfo](#getodbcfieldinfo) a função de membro para determinar se um campo pode ser definido como um valor nulo. Observe que você sempre possa chamar `GetODBCFieldInfo`, independentemente de se você tiver implementado a busca de linhas em massa. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Um campo que não pode ser Null deve ter um valor. Se você tentar definir um um campo como Null quando adicionar ou atualizar um registro, a fonte de dados rejeita a adição ou atualização, e [atualizar](#update) lançará uma exceção. A exceção ocorre quando você chama `Update`, não quando você chama [SetFieldNull](#setfieldnull).

Usando NULL para o primeiro argumento da função será aplicada somente como a função `outputColumn` campos não `param` campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

será definido somente `outputColumn` campos como NULL; `param` campos não serão afetados.

Para ser trabalhada `param` campos, você deve fornecer o endereço real da pessoa `param` você deseja trabalhar, tais como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que não é possível definir todos os `param` campos como NULL, como faria com `outputColumn` campos.

`IsFieldNullable` é implementado por meio [DoFieldExchange](#dofieldexchange).

##  <a name="isopen"></a>  CRecordset::IsOpen

Determina se o conjunto de registros já está aberto.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto de conjunto de registros [aberto](#open) ou [Requery](#requery) função membro foi chamada anteriormente e o conjunto de registros não foi fechado; caso contrário, 0.

##  <a name="m_hstmt"></a>  CRecordset::m_hstmt

Contém um identificador para a estrutura de dados de instrução ODBC, do tipo HSTMT, associado com o conjunto de registros.

### <a name="remarks"></a>Comentários

Cada consulta a uma fonte de dados ODBC está associada um HSTMT.

> [!CAUTION]
>  Não use `m_hstmt` antes de [aberto](#open) foi chamado.

Normalmente, é necessário acessar o HSTMT diretamente, mas você pode precisar dela para execução direta de instruções SQL. O `ExecuteSQL` função de membro da classe `CDatabase` fornece um exemplo de uso `m_hstmt`.

##  <a name="m_nfields"></a>  CRecordset::m_nFields

Contém o número de membros de dados do campo na classe de conjunto de registros; ou seja, o número de colunas selecionadas pelo conjunto de registros da fonte de dados.

### <a name="remarks"></a>Comentários

O construtor da classe de conjunto de registros deve inicializar `m_nFields` com o número correto. Se você não tiver implementado a linha em massa que busca, o ClassWizard grava essa inicialização para você quando você usá-lo para declarar sua classe de conjunto de registros. Você também pode escrevê-lo manualmente.

A estrutura usa esse número para gerenciar a interação entre os membros de dados de campo e as colunas correspondentes do registro atual na fonte de dados.

> [!CAUTION]
>  Esse número deve corresponder ao número de colunas de saída"" registrado no `DoFieldExchange` ou `DoBulkFieldExchange` após uma chamada para [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) com o parâmetro `CFieldExchange::outputColumn`.

Você pode associar colunas dinamicamente, conforme explicado no artigo "conjunto de registros: dinamicamente colunas de associação de dados." Se você fizer isso, você deve aumentar a contagem na `m_nFields` para refletir o número de função RFX ou RFX em massa chamadas seu `DoFieldExchange` ou `DoBulkFieldExchange` a função de membro para as colunas associadas dinamicamente.

Para obter mais informações, consulte os artigos [conjunto de registros: dinamicamente associando dados colunas (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md) e [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

Consulte o artigo [troca de campos do registro: usando RFX](../../data/odbc/record-field-exchange-using-rfx.md).

##  <a name="m_nparams"></a>  CRecordset::m_nParams

Contém o número de membros de dados de parâmetro na classe de conjunto de registros; ou seja, o número de parâmetros passados com a consulta do conjunto de registros.

### <a name="remarks"></a>Comentários

Se sua classe de conjunto de registros tem quaisquer membros de dados de parâmetro, o construtor da classe deve inicializar `m_nParams` com o número correto. O valor de `m_nParams` padrão é 0. Se você adicionar membros de dados de parâmetro (que deve ser feito manualmente) você deve também adicionar manualmente uma inicialização no construtor da classe para refletir o número de parâmetros (que deve ser pelo menos tão grande quanto o número de ' espaços reservados em sua `m_strFilter` ou `m_strSort`cadeia de caracteres).

A estrutura usa esse número quando ela parametriza a consulta do conjunto de registros.

> [!CAUTION]
>  Esse número deve corresponder ao número de "parâmetros" registrados no `DoFieldExchange` ou `DoBulkFieldExchange` após uma chamada para [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) com um valor de parâmetro `CFieldExchange::inputParam`, `CFieldExchange::param`, `CFieldExchange::outputParam`, ou `CFieldExchange::inoutParam`.

### <a name="example"></a>Exemplo

  Consulte os artigos [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) e [troca de campos do registro: usando RFX](../../data/odbc/record-field-exchange-using-rfx.md).

##  <a name="m_pdatabase"></a>  CRecordset::m_pDatabase

Contém um ponteiro para o `CDatabase` objeto por meio do qual o conjunto de registros é conectado a uma fonte de dados.

### <a name="remarks"></a>Comentários

Essa variável é definida de duas maneiras. Normalmente, você passa um ponteiro para um já está conectada `CDatabase` ao construir o objeto de conjunto de registros do objeto. Se você passar NULL em vez disso, `CRecordset` cria um `CDatabase` do objeto para você e se conecta a ele. Em ambos os casos, `CRecordset` armazena o ponteiro nessa variável.

Normalmente você não diretamente precisará usar o ponteiro armazenado em `m_pDatabase`. Se você escrever suas próprias extensões para `CRecordset`, no entanto, talvez você precise usar o ponteiro. Por exemplo, talvez seja necessário o ponteiro se você lançar sua própria `CDBException`s. Ou você pode precisar se você precisa fazer algo usando as mesmas `CDatabase` objeto, como a execução de transações, definindo tempos limite, ou chamando o `ExecuteSQL` função de membro da classe `CDatabase` para executar instruções SQL diretamente.

##  <a name="m_strfilter"></a>  CRecordset::m_strFilter

Depois de construir o objeto de conjunto de registros, mas antes de chamar seus `Open` membro de função, use este membro de dados para armazenar uma `CString` que contém um SQL **onde** cláusula.

### <a name="remarks"></a>Comentários

O conjunto de registros usa essa cadeia de caracteres para restringir (ou filtrar) os registros que ele seleciona durante o `Open` ou `Requery` chamar. Isso é útil para selecionar um subconjunto de registros, como "todos os vendedores com base na Califórnia" ("estado = CA"). A sintaxe de ODBC SQL para um **onde** cláusula for

`WHERE search-condition`

Observe que você não incluir o **onde** palavra-chave em sua cadeia de caracteres. O framework fornece a ele.

Você também pode parametrizar a cadeia de caracteres de filtro, colocando ' espaços reservados, declarando um membro de dados em sua classe de parâmetro para cada espaço reservado e passar parâmetros para o conjunto de registros no tempo de execução. Isso permite que você construir o filtro em tempo de execução. Para obter mais informações, consulte o artigo [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

Para obter mais informações sobre o SQL **onde** cláusulas, consulte o artigo [SQL](../../data/odbc/sql.md). Para obter mais informações sobre como selecionar e filtrar os registros, consulte o artigo [conjunto de registros: filtrando registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#30](../../mfc/codesnippet/cpp/crecordset-class_12.cpp)]

##  <a name="m_strsort"></a>  CRecordset::m_strSort

Depois de construir o objeto de conjunto de registros, mas antes de chamar seus `Open` membro de função, use este membro de dados para armazenar uma `CString` que contém um SQL **ORDER BY** cláusula.

### <a name="remarks"></a>Comentários

O conjunto de registros usa essa cadeia de caracteres para classificar os registros que ele seleciona durante o `Open` ou `Requery` chamar. Você pode usar esse recurso para classificar um conjunto de registros em uma ou mais colunas. A sintaxe de ODBC SQL para um **ORDER BY** cláusula for

`ORDER BY sort-specification [, sort-specification]...`

em que uma especificação de classificação é um inteiro ou um nome de coluna. Você também pode especificar a ordem crescente ou decrescente (a ordem é crescente por padrão), acrescentando "ASC" ou "DESC" à lista de colunas na cadeia de caracteres de classificação. Os registros selecionados são classificados primeiro pela primeira coluna listada e, em seguida, por segundo e assim por diante. Por exemplo, você pode solicitar um conjunto de registros por sobrenome e nome "Clientes". O número de colunas que você pode listar depende da fonte de dados. Para obter mais informações, consulte o SDK do Windows.

Observe que você não incluir o **ORDER BY** palavra-chave em sua cadeia de caracteres. O framework fornece a ele.

Para obter mais informações sobre cláusulas SQL, consulte o artigo [SQL](../../data/odbc/sql.md). Para obter mais informações sobre a classificação de registros, consulte o artigo [conjunto de registros: Classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#31](../../mfc/codesnippet/cpp/crecordset-class_13.cpp)]

##  <a name="move"></a>  CRecordset::Move

Move o ponteiro de registro atual dentro do conjunto de registros, Avançar ou recuar.

```
virtual void Move(
    long nRows,
    WORD wFetchType = SQL_FETCH_RELATIVE);
```

### <a name="parameters"></a>Parâmetros

*nRows*<br/>
O número de linhas para Avançar ou retroceder. Valores positivos movem para a frente, na direção do final do conjunto de registros. Valores negativos a movem para trás, até o início.

*wFetchType*<br/>
Determina o conjunto de linhas que `Move` buscará. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Se você passar um valor de 0 para *nRows*, `Move` atualiza o registro atual. `Move` terminará qualquer atual `AddNew` ou `Edit` modo e irá restaurar o valor do registro atual antes `AddNew` ou `Edit` foi chamado.

> [!NOTE]
>  Quando você move por meio de um conjunto de registros, não é possível ignorar registros excluídos. Ver [CRecordset::IsDeleted](#isdeleted) para obter mais informações. Quando você abre um `CRecordset` com o `skipDeletedRecords` conjunto, a opção `Move` declara se a *nRows* parâmetro é 0. Esse comportamento impede que a atualização de linhas que são excluídas por outros aplicativos de cliente usando os mesmos dados. Consulte a *dwOption* parâmetro na [abra](#open) para obter uma descrição de `skipDeletedRecords`.

`Move` reposiciona o conjunto de registros por conjuntos de linhas. Com base nos valores *nRows* e *wFetchType*, `Move` busca o conjunto de linhas apropriado e, em seguida, torna o primeiro registro no conjunto de linhas que o registro atual. Se você não tiver implementado a busca de linhas em massa, em seguida, o tamanho do conjunto de linhas é sempre 1. Ao buscar um conjunto de linhas `Move` chama diretamente o [CheckRowsetError](#checkrowseterror) a função de membro para tratar os erros resultantes de busca.

Dependendo dos valores que você passar, `Move` é equivalente a outro `CRecordset` funções de membro. Em particular, o valor de *wFetchType* pode indicar uma função de membro que é muito mais intuitiva e, com frequência, o método preferido para mover o registro atual.

A tabela a seguir lista os possíveis valores para *wFetchType*, o conjunto de linhas que `Move` buscará baseia *wFetchType* e *nRows*e qualquer equivalente função de membro correspondente ao *wFetchType*.

|wFetchType|Conjunto de linhas buscado|Função de membro equivalente|
|----------------|--------------------|--------------------------------|
|SQL_FETCH_RELATIVE (o valor padrão)|O conjunto de linhas começando *nRows* linha (s) da primeira linha no conjunto de linhas atual.||
|SQL_FETCH_NEXT|O próximo conjunto de linhas; *nRows* será ignorado.|[MoveNext](#movenext)|
|SQL_FETCH_PRIOR|O conjunto de linhas anterior; *nRows* será ignorado.|[MovePrev](#moveprev)|
|SQL_FETCH_FIRST|O primeiro conjunto de linhas no conjunto de registros; *nRows* será ignorado.|[MoveFirst](#movefirst)|
|SQL_FETCH_LAST|O último conjunto de linhas completo no conjunto de registros; *nRows* será ignorado.|[MoveLast](#movelast)|
|SQL_FETCH_ABSOLUTE|Se *nRows* > 0, o conjunto de linhas começando *nRows* linha (s) desde o início do conjunto de registros. Se *nRows* < 0, o conjunto de linhas começando *nRows* linha (s) a partir do final do conjunto de registros. Se *nRows* = 0, uma condição de início do arquivo (BOF) será retornado.|[SetAbsolutePosition](#setabsoluteposition)|
|SQL_FETCH_BOOKMARK|O conjunto de linhas começando na linha cujo valor de indicador corresponde ao *nRows*.|[SetBookmark](#setbookmark)|

> [!NOTE]
>  Para conjuntos de registros somente encaminhamento, `Move` só é válida com um valor de SQL_FETCH_NEXT para *wFetchType*.

> [!CAUTION]
>  Chamar `Move` lança uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem todos os registros, chame [IsBOF](#isbof) e [IsEOF](#iseof).

> [!NOTE]
>  Se você percorreu após o início ou fim do conjunto de registros (`IsBOF` ou `IsEOF` retorna não zero), chamar um `Move` função possivelmente gerará um `CDBException`. Por exemplo, se `IsEOF` retorna não zero e `IsBOF` não faz isso, em seguida, `MoveNext` lançará uma exceção, mas `MovePrev` será não.

> [!NOTE]
>  Se você chamar `Move` enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre navegação de conjunto de registros, consulte os artigos [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter informações relacionadas, consulte a função de API ODBC `SQLExtendedFetch` no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#28](../../mfc/codesnippet/cpp/crecordset-class_14.cpp)]

##  <a name="movefirst"></a>  CRecordset::MoveFirst

Torna o primeiro registro no conjunto de linhas primeiro o registro atual.

```
void MoveFirst();
```

### <a name="remarks"></a>Comentários

Independentemente se a busca de linhas em massa tiver sido implementado, isso sempre será o primeiro registro no conjunto de registros.

Você não precisa chamar `MoveFirst` imediatamente depois de abrir o conjunto de registros. Nesse momento, o primeiro registro (se houver) é automaticamente o registro atual.

> [!NOTE]
>  Essa função de membro não é válida para conjuntos de registros somente de encaminhamento.

> [!NOTE]
>  Quando você move por meio de um conjunto de registros, não é possível ignorar registros excluídos. Consulte a [IsDeleted](#isdeleted) função de membro para obter detalhes.

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem todos os registros, chame `IsBOF` e `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre navegação de conjunto de registros, consulte os artigos [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsBOF](#isbof).

##  <a name="movelast"></a>  CRecordset::MoveLast

Torna o primeiro registro no último conjunto de linhas completo o registro atual.

```
void MoveLast();
```

### <a name="remarks"></a>Comentários

Se você não tiver implementado a busca de linhas em massa, o seu conjunto de registros tem um tamanho de conjunto de linhas de 1, portanto, `MoveLast` simplesmente se moverá para o último registro no conjunto de registros.

> [!NOTE]
>  Essa função de membro não é válida para conjuntos de registros somente de encaminhamento.

> [!NOTE]
>  Quando você move por meio de um conjunto de registros, não é possível ignorar registros excluídos. Consulte a [IsDeleted](#isdeleted) função de membro para obter detalhes.

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem todos os registros, chame `IsBOF` e `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre navegação de conjunto de registros, consulte os artigos [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsBOF](#isbof).

##  <a name="movenext"></a>  CRecordset::MoveNext

Torna o primeiro registro no conjunto de linhas próximo registro atual.

```
void MoveNext();
```

### <a name="remarks"></a>Comentários

Se você não tiver implementado a busca de linhas em massa, o seu conjunto de registros tem um tamanho de conjunto de linhas de 1, portanto, `MoveNext` simplesmente se moverá para o próximo registro.

> [!NOTE]
>  Quando você move por meio de um conjunto de registros, não é possível ignorar registros excluídos. Consulte a [IsDeleted](#isdeleted) função de membro para obter detalhes.

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem todos os registros, chame `IsBOF` e `IsEOF`.

> [!NOTE]
>  Também é recomendável que você chame `IsEOF` antes de chamar `MoveNext`. Por exemplo, se você percorreu após o final do conjunto de registros `IsEOF` retornará diferente de zero, uma chamada subsequente para `MoveNext` lançaria uma exceção.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre navegação de conjunto de registros, consulte os artigos [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsBOF](#isbof).

##  <a name="moveprev"></a>  CRecordset::MovePrev

Torna o primeiro registro no conjunto de linhas anterior do registro atual.

```
void MovePrev();
```

### <a name="remarks"></a>Comentários

Se você não tiver implementado a busca de linhas em massa, o seu conjunto de registros tem um tamanho de conjunto de linhas de 1, portanto, `MovePrev` simplesmente se moverá para o registro anterior.

> [!NOTE]
>  Essa função de membro não é válida para conjuntos de registros somente de encaminhamento.

> [!NOTE]
>  Quando você move por meio de um conjunto de registros, não é possível ignorar registros excluídos. Consulte a [IsDeleted](#isdeleted) função de membro para obter detalhes.

> [!CAUTION]
>  Chamar qualquer um de `Move` funções gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem todos os registros, chame `IsBOF` e `IsEOF`.

> [!NOTE]
>  Também é recomendável que você chame `IsBOF` antes de chamar `MovePrev`. Por exemplo, se você percorreu antes do início do conjunto de registros `IsBOF` retornará diferente de zero, uma chamada subsequente para `MovePrev` lançaria uma exceção.

> [!NOTE]
>  Se você chamar qualquer uma da `Move` funciona enquanto o registro atual está sendo atualizada ou adicionada, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre navegação de conjunto de registros, consulte os artigos [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsBOF](#isbof).

##  <a name="onsetoptions"></a>  CRecordset::OnSetOptions

Chamado para definir opções (usadas na seleção) para a instrução ODBC especificada.

```
virtual void OnSetOptions(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*HSTMT*<br/>
HSTMT da instrução ODBC cujas opções devem ser definidas.

### <a name="remarks"></a>Comentários

Chamar `OnSetOptions` para definir opções (usadas na seleção) para a instrução ODBC especificada. O framework chama essa função de membro para definir as opções iniciais para o conjunto de registros. `OnSetOptions` Determina o suporte da fonte de dados para cursores roláveis e simultaneidade do cursor e define as opções do conjunto de registros adequadamente. (Enquanto `OnSetOptions` é usado para operações de seleção, `OnSetUpdateOptions` é usado para operações de atualização.)

Substituir `OnSetOptions` para definir as opções específicas para o driver ou a fonte de dados. Por exemplo, se dá suporte à abertura de acesso exclusivo de fonte de dados, você pode substituir `OnSetOptions` para tirar proveito dessa capacidade.

Para obter mais informações sobre cursores, consulte o artigo [ODBC](../../data/odbc/odbc-basics.md).

##  <a name="onsetupdateoptions"></a>  CRecordset::OnSetUpdateOptions

Chamado para definir as opções (usadas na atualização) para a instrução ODBC especificada.

```
virtual void OnSetUpdateOptions(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*HSTMT*<br/>
HSTMT da instrução ODBC cujas opções devem ser definidas.

### <a name="remarks"></a>Comentários

Chamar `OnSetUpdateOptions` para definir opções (usadas na atualização) para a instrução ODBC especificada. O framework chama essa função membro depois que ele cria um HSTMT para atualizar registros em um conjunto de registros. (Enquanto `OnSetOptions` é usado para operações de seleção, `OnSetUpdateOptions` é usado para operações de atualização.) `OnSetUpdateOptions` determina o suporte da fonte de dados para cursores roláveis e simultaneidade do cursor e define as opções do conjunto de registros adequadamente.

Substituir `OnSetUpdateOptions` para definir opções de uma instrução ODBC antes dessa instrução é usada para acessar um banco de dados.

Para obter mais informações sobre cursores, consulte o artigo [ODBC](../../data/odbc/odbc-basics.md).

##  <a name="open"></a>  {1&gt;crecordset::Open&lt;1

Abre o conjunto de registros por recuperar a tabela ou executar a consulta que representa o conjunto de registros.

```
virtual BOOL Open(
    UINT nOpenType = AFX_DB_USE_DEFAULT_TYPE,
    LPCTSTR lpszSQL = NULL,
    DWORD dwOptions = none);
```

### <a name="parameters"></a>Parâmetros

*nOpenType*<br/>
Aceite o valor padrão, AFX_DB_USE_DEFAULT_TYPE ou use um dos seguintes valores da `enum OpenType`:

- `CRecordset::dynaset` Um conjunto de registros com rolagem de bi-direcional. A associação e ordenação dos registros são determinados quando o conjunto de registros é aberto, mas as alterações feitas por outros usuários aos valores de dados ficam visíveis após uma operação de busca. Dynasets também são conhecidos como cursores controlados por conjuntos de registros.

- `CRecordset::snapshot` Um conjunto de registros estático com rolagem de bi-direcional. A associação e ordenação dos registros são determinados quando o conjunto de registros é aberto. os valores de dados são determinados quando os registros são buscados. As alterações feitas por outros usuários não são visíveis até que o conjunto de registros é fechado e reaberto.

- `CRecordset::dynamic` Um conjunto de registros com rolagem de bi-direcional. As alterações feitas por outros usuários para os valores de associação, a classificação e os dados ficam visíveis após uma operação de busca. Observe que muitos drivers ODBC não têm suporte para esse tipo de conjunto de registros.

- `CRecordset::forwardOnly` Um conjunto de registros somente leitura com apenas roll-forward.

   Para `CRecordset`, o valor padrão é `CRecordset::snapshot`. O mecanismo de valor padrão permite que os assistentes do Visual C++ interagir com ODBC `CRecordset` e DAO `CDaoRecordset`, que têm diferentes padrões.

Para obter mais informações sobre esses tipos de conjunto de registros, consulte o artigo [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md). Para obter informações relacionadas, consulte o artigo "Usando o bloco e cursores roláveis" no SDK do Windows.

> [!CAUTION]
>  Se não há suporte para o tipo solicitado, o framework lança uma exceção.

*lpszSQL*<br/>
Um ponteiro de cadeia de caracteres que contém um dos seguintes:

- Um ponteiro nulo.

- O nome de uma tabela.

- Um SQL **selecionar** instrução (opcionalmente com um SQL **onde** ou **ORDER BY** cláusula).

- Um **chamar** instrução, especificando o nome de uma consulta predefinida (procedimento armazenado). Tenha cuidado para que você não insira espaço em branco entre a chave de abertura e o **chamar** palavra-chave.

Para obter mais informações sobre essa cadeia de caracteres, consulte a tabela e a discussão da função do ClassWizard sob comentários.

> [!NOTE]
>  A ordem das colunas no conjunto de resultados deve corresponder a ordem do RFX ou chamadas de função RFX em massa no seu [DoFieldExchange](#dofieldexchange) ou [DoBulkFieldExchange](#dobulkfieldexchange) substituição de função.

*dwOptions*<br/>
Um bitmask que pode especificar uma combinação dos valores listados abaixo. Alguns deles são mutuamente exclusivos. O valor padrão é **none**.

- `CRecordset::none` Nenhum conjunto de opções. Esse valor de parâmetro é mutuamente exclusivo com todos os outros valores. Por padrão, o conjunto de registros pode ser atualizado com [edite](#edit) ou [excluir](#delete) e permite o acréscimo de novos registros com [AddNew](#addnew). Capacidade de atualização depende da fonte de dados, bem como na *nOpenType* opção especificada. Otimização para adições em massa não está disponível. Busca de linhas em massa não será implementado. Registros excluídos não serão ignorados durante a navegação de conjunto de registros. Indicadores não estão disponíveis. Verificando a falta de limpeza automática de campo é implementado.

- `CRecordset::appendOnly` Não permitir `Edit` ou `Delete` o conjunto de registros. Permitir `AddNew` apenas. Essa opção é mutuamente exclusiva com `CRecordset::readOnly`.

- `CRecordset::readOnly` Abra o conjunto de registros como somente leitura. Essa opção é mutuamente exclusiva com `CRecordset::appendOnly`.

- `CRecordset::optimizeBulkAdd` Use uma instrução SQL preparada para otimizar a adição de vários registros ao mesmo tempo. Aplica-se apenas se você não estiver usando a função ODBC API `SQLSetPos` para atualizar o conjunto de registros. A primeira atualização determina quais campos são marcado como sujos. Essa opção é mutuamente exclusiva com `CRecordset::useMultiRowFetch`.

- `CRecordset::useMultiRowFetch` Implemente a busca de linhas em massa para permitir várias linhas a serem recuperados em uma operação de busca único. Esse é um recurso avançado projetado para melhorar o desempenho. No entanto, troca de campos de registro em massa não tem suporte ClassWizard. Essa opção é mutuamente exclusiva com `CRecordset::optimizeBulkAdd`. Observe que, se você especificar `CRecordset::useMultiRowFetch`, em seguida, a opção `CRecordset::noDirtyFieldCheck` será ativado automaticamente (buffer duplo não estará disponível); em conjuntos de registros de somente avanço, a opção `CRecordset::useExtendedFetch` será ativado automaticamente. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

- `CRecordset::skipDeletedRecords` Ignore registros excluídos tudo ao navegar pelo conjunto de registros. Isso reduzirá o desempenho em determinados buscas relativas. Essa opção não é válida em conjuntos de registros somente de encaminhamento. Se você chamar [mova](#move) com o *nRows* parâmetro definido como 0 e o `CRecordset::skipDeletedRecords` opção set, `Move` declarará. Observe que `CRecordset::skipDeletedRecords` é semelhante ao *remessa driver*, que significa que as linhas excluídas é removidas do conjunto de registros. No entanto, se o driver de pacotes de registros, em seguida, ele ignorará apenas os registros que você exclua; ele não vai ignorar registros excluídos por outros usuários enquanto o conjunto de registros é aberto. `CRecordset::skipDeletedRecords` vai ignorar linhas excluídas por outros usuários.

- `CRecordset::useBookmarks` Pode usar indicadores no conjunto de registros, se houver suporte. Indicadores lenta a recuperação de dados, mas melhoram o desempenho de navegação pelos dados. Não é válido em conjuntos de registros somente de encaminhamento. Para obter mais informações, consulte o artigo [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

- `CRecordset::noDirtyFieldCheck` Desative automática de campo suja de verificação (buffer duplo). Isso irá melhorar o desempenho. No entanto, você deve marcar manualmente campos como suja chamando o `SetFieldDirty` e `SetFieldNull` funções de membro. Observe que esse buffer duplo na classe `CRecordset` é semelhante ao buffer duplo na classe `CDaoRecordset`. No entanto, em `CRecordset`, não é possível habilitar o buffer duplo em campos individuais; você habilitá-la para todos os campos ou desabilitá-lo para todos os campos. Observe que, se você especificar a opção `CRecordset::useMultiRowFetch`, em seguida, `CRecordset::noDirtyFieldCheck` serão ativadas automaticamente; no entanto, `SetFieldDirty` e `SetFieldNull` não pode ser usado em conjuntos de registros que implementam a busca de linhas em massa.

- `CRecordset::executeDirect` Não use uma instrução SQL preparada. Para melhorar o desempenho, especifique essa opção se o `Requery` nunca será chamada de função de membro.

- `CRecordset::useExtendedFetch` Implemente `SQLExtendedFetch` em vez de `SQLFetch`. Isso é projetado para a implementação de busca de linhas em massa em conjuntos de registros somente de encaminhamento. Se você especificar a opção `CRecordset::useMultiRowFetch` em um recordset somente de encaminhamento, em seguida, `CRecordset::useExtendedFetch` será ativado automaticamente.

- `CRecordset::userAllocMultiRowBuffers` O usuário será alocar buffers de armazenamento para os dados. Use essa opção em conjunto com `CRecordset::useMultiRowFetch` se você desejar alocar o seu próprio armazenamento; caso contrário, a estrutura serão automaticamente alocar o armazenamento necessário. Para obter mais informações, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Observe que especificar `CRecordset::userAllocMultiRowBuffers` sem especificar `CRecordset::useMultiRowFetch` resultará em uma declaração com falha.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o `CRecordset` objeto foi com êxito aberto; caso contrário, 0 se [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open) (se for chamado) retornará 0.

### <a name="remarks"></a>Comentários

Você deve chamar essa função de membro para executar a consulta definida pelo conjunto de registros. Antes de chamar `Open`, você deve construir o objeto de conjunto de registros.

Conexão desse conjunto de registros para a fonte de dados depende de como você constrói o conjunto de registros antes de chamar `Open`. Se você passar uma [CDatabase](../../mfc/reference/cdatabase-class.md) do objeto para o construtor de conjunto de registros que não foi conectado à fonte de dados, essa função membro usa [GetDefaultConnect](#getdefaultconnect) para tentar abrir o objeto de banco de dados. Se você passar NULL para o construtor de conjunto de registros, o construtor constrói um `CDatabase` objeto para você, e `Open` tenta conectar-se o objeto de banco de dados. Para obter detalhes sobre o conjunto de registros e a conexão sob essas circunstâncias variadas de fechamento, consulte [fechar](#close).

> [!NOTE]
>  Acesso a uma fonte de dados por meio de um `CRecordset` objeto sempre é compartilhado. Ao contrário do `CDaoRecordset` classe, você não pode usar um `CRecordset` objeto para abrir uma fonte de dados com acesso exclusivo.

Quando você chama `Open`, uma consulta, normalmente, um SQL **selecione** instrução, seleciona os registros com base em critérios mostrados na tabela a seguir.

|Valor do parâmetro lpszSQL|Registros selecionados são determinados pelo|Exemplo|
|------------------------------------|----------------------------------------|-------------|
|NULL|A cadeia de caracteres retornada por `GetDefaultSQL`.||
|Nome da tabela SQL|Todas as colunas da lista de tabela no `DoFieldExchange` ou `DoBulkFieldExchange`.|`"Customer"`|
|Nome de consulta predefinida (procedimento armazenado)|As colunas que a consulta é definida para retornar.|`"{call OverDueAccts}"`|
|**Selecione** lista de colunas **FROM** lista de tabelas|As colunas especificadas da tabela se o (s) especificado.|`"SELECT CustId, CustName FROM`<br /><br /> `Customer"`|

> [!CAUTION]
>  Tenha cuidado para que você não inserir o espaço em branco extra em sua cadeia de caracteres SQL. Por exemplo, se você inserir o espaço em branco entre a chave de abertura e o **chamar** palavra-chave, MFC irá interpretar incorretamente a cadeia de caracteres SQL como um nome de tabela e incorporá-la em um **selecione** instrução, o que resultará em um exceção sendo lançada. Da mesma forma, se sua consulta predefinida usa um parâmetro de saída, não insira espaço em branco entre a chave de abertura e o ' símbolo. Por fim, você não deve inserir espaços em branco antes da chave de abertura em um **chamar** instrução ou antes do **selecionar** palavra-chave em um **selecione** instrução.

O procedimento normal é passar NULL para `Open`; nesse caso, `Open` chamadas [GetDefaultSQL](#getdefaultsql). Se você estiver usando um derivado `CRecordset` classe, `GetDefaultSQL` fornece os nomes de tabela que você especificou no ClassWizard. Em vez disso, você pode especificar outras informações no `lpszSQL` parâmetro.

Tudo o que você passa `Open` constrói uma cadeia de caracteres final SQL para a consulta (a cadeia de caracteres pode ter o SQL **onde** e **ORDER BY** cláusulas acrescentado ao `lpszSQL` cadeia de caracteres passada por você) e, em seguida, executa a consulta. Você pode examinar a cadeia de caracteres construída chamando [GetSQL](#getsql) depois de chamar `Open`. Para obter mais detalhes sobre como o conjunto de registros constrói uma instrução SQL e seleciona os registros, consulte o artigo [conjunto de registros: como conjuntos de registros selecionar registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

Os membros de dados do campo da sua classe de conjunto de registros são associados às colunas dos dados selecionados. Se todos os registros são retornados, o primeiro registro torna-se o registro atual.

Se você quiser definir opções para o conjunto de registros, como um filtro ou classificação, especificá-los depois de construir o objeto de conjunto de registros, mas antes de chamar `Open`. Se você quiser atualizar os registros no conjunto de registros após o conjunto de registros já estiver aberto, chame [Requery](#requery).

Para obter mais informações, incluindo exemplos adicionais, consulte os artigos [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md), [conjunto de registros: como conjuntos de registros selecionar registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md), e [conjunto de registros: Criando e fechando Conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

### <a name="example"></a>Exemplo

Os exemplos de código a seguir mostram diferentes formas dos `Open` chamar.

[!code-cpp[NVC_MFCDatabase#16](../../mfc/codesnippet/cpp/crecordset-class_15.cpp)]

##  <a name="refreshrowset"></a>  CRecordset::RefreshRowset

Atualiza os dados e o status de uma linha no conjunto de linhas atual.

```
void RefreshRowset(
    WORD wRow,
    WORD wLockType = SQL_LOCK_NO_CHANGE);
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A com base em uma posição de uma linha no conjunto de linhas atual. Esse valor pode variar de zero para o tamanho do conjunto de linhas.

*wLockType*<br/>
Um valor que indica como bloquear a linha depois que ela tenha sido atualizada. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Se você passar um valor de zero para *wRow*, em seguida, todas as linhas no conjunto de linhas serão atualizadas.

Para usar `RefreshRowset`, tiver implementado busca de linhas em massa, especificando o `CRecordset::useMulitRowFetch` opção a [abrir](#open) função de membro.

`RefreshRowset` chama a função ODBC API `SQLSetPos`. O *wLockType* parâmetro especifica o estado de bloqueio da linha após `SQLSetPos` foi executada. A tabela a seguir descreve os possíveis valores para *wLockType*.

|wLockType|Descrição|
|---------------|-----------------|
|SQL_LOCK_NO_CHANGE (o valor padrão)|A driver ou fonte de dados garante que a linha é o mesmo estado bloqueado ou desbloqueado como era antes `RefreshRowset` foi chamado.|
|SQL_LOCK_EXCLUSIVE|A driver ou fonte de dados bloqueia a linha exclusivamente. Nem todas as fontes de dados dão suporte a esse tipo de bloqueio.|
|SQL_LOCK_UNLOCK|A fonte de dados ou driver desbloqueia a linha. Nem todas as fontes de dados dão suporte a esse tipo de bloqueio.|

Para obter mais informações sobre `SQLSetPos`, consulte o SDK do Windows. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="requery"></a>  CRecordset::Requery

Recria (atualizações) um conjunto de registros.

```
virtual BOOL Requery();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o conjunto de registros foi recriado com êxito; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Se todos os registros são retornados, o primeiro registro torna-se o registro atual.

Na ordem do conjunto de registros refletir as adições e exclusões que você ou outros usuários estão fazendo para a fonte de dados, você deve recompilar o conjunto de registros chamando `Requery`. Se o conjunto de registros for um dynaset, ela reflete automaticamente as atualizações que você ou outros usuários tornam seus registros existentes (mas não adições). Se o conjunto de registros é um instantâneo, você deve chamar `Requery` para refletir edições por outros usuários, bem como adições e exclusões.

Para um dynaset ou um instantâneo, chame `Requery` sempre que quiser para recriar o conjunto de registros usando um novo filtro ou classificação ou novos valores de parâmetro. Definir a nova propriedade de filtro ou classificação atribuindo novos valores a serem `m_strFilter` e `m_strSort` antes de chamar `Requery`. Definir novos parâmetros, atribuindo novos valores para membros de dados de parâmetro antes de chamar `Requery`. Se as cadeias de caracteres de filtro e classificação forem alteradas, você pode reutilizar a consulta, o que melhora o desempenho.

Se a tentativa de recompilar o conjunto de registros falhar, o conjunto de registros é fechado. Antes de chamar `Requery`, você pode determinar se o conjunto de registros pode ser consultadas novamente chamando a `CanRestart` função de membro. `CanRestart` não garante que `Requery` terá êxito.

> [!CAUTION]
>  Chame `Requery` somente depois de ter chamado [aberto](#open).

### <a name="example"></a>Exemplo

Este exemplo recria um conjunto de registros para aplicar uma ordem de classificação diferentes.

[!code-cpp[NVC_MFCDatabase#29](../../mfc/codesnippet/cpp/crecordset-class_16.cpp)]

##  <a name="setabsoluteposition"></a>  CRecordset::SetAbsolutePosition

Posiciona o conjunto de registros no registro correspondente ao número de registro especificado.

```
void SetAbsolutePosition(long nRows);
```

### <a name="parameters"></a>Parâmetros

*nRows*<br/>
A com base em uma posição ordinal para o registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

`SetAbsolutePosition` Move o ponteiro de registro atual com base nessa posição ordinal.

> [!NOTE]
>  Essa função de membro não é válida em conjuntos de registros somente de encaminhamento.

Para conjuntos de registros ODBC, uma configuração de posição absoluta de 1 refere-se para o primeiro registro no conjunto de registros; uma configuração de 0 refere-se para a posição do início do arquivo (BOF).

Você também pode passar valores negativos para `SetAbsolutePosition`. Nesse caso, a posição do conjunto de registros é avaliada do final do conjunto de registros. Por exemplo, `SetAbsolutePosition( -1 )` move o ponteiro de registro atual para o último registro no conjunto de registros.

> [!NOTE]
>  Posição absoluta não se destina a ser usado como um número de registro de substituto. Os indicadores ainda são a maneira recomendada de reter e retornar para uma determinada posição, desde alterações na posição de um registro quando registros anteriores são excluídos. Além disso, você não pode ter certeza de que um determinado registro terá a mesma posição absoluta se o conjunto de registros é recriado novamente porque a ordem dos registros individuais dentro de um conjunto de registros não é garantida, a menos que ele é criado com uma instrução SQL usando um **ORDER BY** cláusula.

Para obter mais informações sobre navegação de conjunto de registros e os indicadores, consulte os artigos [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

##  <a name="setbookmark"></a>  CRecordset::SetBookmark

Posiciona o conjunto de registros no registro que contém o indicador especificado.

```
void SetBookmark(const CDBVariant& varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Uma referência a um [CDBVariant](../../mfc/reference/cdbvariant-class.md) objeto que contém o valor de indicador para um registro específico.

### <a name="remarks"></a>Comentários

Para determinar se os indicadores são compatíveis com o conjunto de registros, chame [CanBookmark](#canbookmark). Para disponibilizar marcadores se eles tiverem suporte, você deve definir a `CRecordset::useBookmarks` opção a *dwOptions* parâmetro do [abrir](#open) função de membro.

> [!NOTE]
>  Se os indicadores são sem suporte ou não está disponível, chamada `SetBookmark` resultará em uma exceção sendo lançada. Não há suporte para os indicadores em conjuntos de registros somente de encaminhamento.

Para recuperar primeiro o indicador para o registro atual, chame [GetBookmark](#getbookmark), que salva o valor de indicador a um `CDBVariant` objeto. Posteriormente, você pode retornar a esse registro chamando `SetBookmark` usando o valor de indicador salvo.

> [!NOTE]
>  Depois de determinadas operações de conjunto de registros, você deve verificar a persistência de indicador antes de chamar `SetBookmark`. Por exemplo, se você recuperar um indicador com `GetBookmark` e, em seguida, chamar `Requery`, o indicador pode não ser mais válido. Chame [CDatabase::GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se você pode chamar com segurança `SetBookmark`.

Para obter mais informações sobre indicadores e navegação de conjunto de registros, consulte os artigos [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [conjunto de registros: rolando (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

##  <a name="setfielddirty"></a>  CRecordset::SetFieldDirty

Sinaliza um membro de dados do campo do conjunto de registros como alterados ou como inalterado.

```
void SetFieldDirty(void* pv, BOOL bDirty = TRUE);
```

### <a name="parameters"></a>Parâmetros

*VP*<br/>
Contém o endereço de um membro de dados do campo no conjunto de registros ou NULL. Se for NULL, todos os membros de dados de campo no conjunto de registros são sinalizados. (C++ nulo não é igual a Null na terminologia de banco de dados, que significa "não tendo nenhum valor.")

*bDirty*<br/>
TRUE se o membro de dados do campo deve ser marcado como "sujo" (alterado). Caso contrário, FALSE se o membro de dados do campo deve ser sinalizado como "Limpar" (inalterado).

### <a name="remarks"></a>Comentários

Marcar campos conforme inalterado garante que o campo não será atualizado e resulta em menos tráfego do SQL.

> [!NOTE]
>  Essa função de membro não é aplicável em conjuntos de registros que estão usando a busca de linhas em massa. Se você tiver implementado busca de linhas em massa, em seguida, `SetFieldDirty` resultará em uma declaração com falha. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

As marcas de estrutura alterada membros de dados de campo para garantir que eles serão gravados para o registro na fonte de dados do mecanismo do exchange (RFX) de campos de registro. Alterando o valor de um campo geralmente define o campo sujas automaticamente, portanto, você raramente precisa chamar `SetFieldDirty` por conta própria, mas você pode querer garantir que colunas serão explicitamente atualizadas ou inseridas, independentemente de qual é o valor dos dados de campo membro.

> [!CAUTION]
>  Chame essa função de membro somente depois de ter chamado [edite](#edit) ou [AddNew](#addnew).

Usando NULL para o primeiro argumento da função será aplicada somente como a função `outputColumn` campos não `param` campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

será definido somente `outputColumn` campos como NULL; `param` campos não serão afetados.

Para ser trabalhada `param` campos, você deve fornecer o endereço real da pessoa `param` você deseja trabalhar, tais como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que não é possível definir todos os `param` campos como NULL, como faria com `outputColumn` campos.

##  <a name="setfieldnull"></a>  CRecordset::SetFieldNull

Sinaliza um membro de dados do campo do conjunto de registros como Null (especificamente com nenhum valor) ou não nulo.

```
void SetFieldNull(void* pv, BOOL bNull = TRUE);
```

### <a name="parameters"></a>Parâmetros

*VP*<br/>
Contém o endereço de um membro de dados do campo no conjunto de registros ou NULL. Se for NULL, todos os membros de dados de campo no conjunto de registros são sinalizados. (C++ nulo não é igual a Null na terminologia de banco de dados, que significa "não tendo nenhum valor.")

*bNull*<br/>
Diferente de zero se o membro de dados do campo deve ser sinalizada como não tendo nenhum valor (nulo). Caso contrário, 0 se o membro de dados do campo deve ser marcado como não-nulo.

### <a name="remarks"></a>Comentários

Quando você adiciona um novo registro a um conjunto de registros, todos os membros de dados de campo são inicialmente definidos como um valor nulo e sinalizados como "sujo" (alterado). Quando você recupera um registro de uma fonte de dados, suas colunas já têm valores ou Null.

> [!NOTE]
>  Não chame essa função de membro em conjuntos de registros que estão usando a busca de linhas em massa. Se você tiver implementado a busca de linhas em massa, chamada `SetFieldNull` resulta em uma declaração com falha. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Se desejar designar um campo do registro atual como não tendo um valor, chamar especificamente `SetFieldNull` com *bNull* definido como TRUE para marcá-lo como Null. Se um campo foi marcado anteriormente Null, e agora você deseja dar a ela um valor, basta defina o novo valor. Não é necessário remover o sinalizador nulo com `SetFieldNull`. Para determinar se o campo pode ser Null, chamar `IsFieldNullable`.

> [!CAUTION]
>  Chame essa função de membro somente depois de ter chamado [edite](#edit) ou [AddNew](#addnew).

Usando NULL para o primeiro argumento da função será aplicada somente como a função `outputColumn` campos não `param` campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

será definido somente `outputColumn` campos como NULL; `param` campos não serão afetados.

Para ser trabalhada `param` campos, você deve fornecer o endereço real da pessoa `param` você deseja trabalhar, tais como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que não é possível definir todos os `param` campos como NULL, como faria com `outputColumn` campos.

> [!NOTE]
>  Ao definir parâmetros como Null, uma chamada para `SetFieldNull` antes que o conjunto de registros é aberta resulta em uma declaração. Nesse caso, chame [SetParamNull](#setparamnull).

`SetFieldNull` é implementado por meio [DoFieldExchange](#dofieldexchange).

##  <a name="setlockingmode"></a>  CRecordset::SetLockingMode

Define o modo de bloqueio para "otimista" bloqueio (o padrão) ou "" pessimista. Determina como os registros são bloqueados para atualizações.

```
void SetLockingMode(UINT nMode);
```

### <a name="parameters"></a>Parâmetros

*nMode*<br/>
Contém um dos seguintes valores do `enum LockMode`:

- `optimistic` Bloqueio otimista bloqueia o registro que está sendo atualizado somente durante a chamada para `Update`.

- `pessimistic` Bloqueio pessimista bloqueia o registro tão logo `Edit` é chamado e o mantém bloqueada até a `Update` chamada seja concluída ou mover para um novo registro.

### <a name="remarks"></a>Comentários

Chame essa função de membro, se você precisa especificar qual das duas estratégias de bloqueio de registros usando o conjunto de registros para atualizações. Por padrão, o modo de bloqueio de um conjunto de registros é `optimistic`. Você pode alterá-la para um mais cuidado `pessimistic` a estratégia de bloqueio. Chame `SetLockingMode` depois de construir e abrir o objeto de conjunto de registros, mas antes de chamar `Edit`.

##  <a name="setparamnull"></a>  CRecordset::SetParamNull

Um parâmetro de sinalizadores como Null (especificamente com nenhum valor) ou não nulo.

```
void SetParamNull(
    int nIndex,
    BOOL bNull = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do parâmetro.

*bNull*<br/>
Se TRUE (o valor padrão), o parâmetro é sinalizado como Null. Caso contrário, o parâmetro é sinalizado como não-nulo.

### <a name="remarks"></a>Comentários

Diferentemente [SetFieldNull](#setfieldnull), você pode chamar `SetParamNull` antes de você ter aberto o conjunto de registros.

`SetParamNull` normalmente é usado com consultas predefinidas (procedimentos armazenados).

##  <a name="setrowsetcursorposition"></a>  CRecordset::SetRowsetCursorPosition

Move o cursor para uma linha dentro do conjunto de linhas atual.

```
void SetRowsetCursorPosition(WORD wRow, WORD wLockType = SQL_LOCK_NO_CHANGE);
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A com base em uma posição de uma linha no conjunto de linhas atual. Esse valor pode variar de 1 para o tamanho do conjunto de linhas.

*wLockType*<br/>
Valor que indica como bloquear a linha depois que ela tenha sido atualizada. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Ao implementar a linha em massa que busca registros são recuperados por conjuntos de linhas, em que o primeiro registro no conjunto de linhas buscado é o registro atual. Para fazer o registro atual com outro registro dentro do conjunto de linhas, chame `SetRowsetCursorPosition`. Por exemplo, você pode combinar `SetRowsetCursorPosition` com o [GetFieldValue](#getfieldvalue) a função de membro para recuperar dinamicamente os dados de qualquer registro de seu conjunto de registros.

Para usar `SetRowsetCursorPosition`, tiver implementado busca de linhas em massa, especificando o `CRecordset::useMultiRowFetch` opção do *dwOptions* parâmetro no [abrir](#open) função de membro.

`SetRowsetCursorPosition` chama a função ODBC API `SQLSetPos`. O *wLockType* parâmetro especifica o estado de bloqueio da linha após `SQLSetPos` foi executada. A tabela a seguir descreve os possíveis valores para *wLockType*.

|wLockType|Descrição|
|---------------|-----------------|
|SQL_LOCK_NO_CHANGE (o valor padrão)|A driver ou fonte de dados garante que a linha é o mesmo estado bloqueado ou desbloqueado como era antes `SetRowsetCursorPosition` foi chamado.|
|SQL_LOCK_EXCLUSIVE|A driver ou fonte de dados bloqueia a linha exclusivamente. Nem todas as fontes de dados dão suporte a esse tipo de bloqueio.|
|SQL_LOCK_UNLOCK|A fonte de dados ou driver desbloqueia a linha. Nem todas as fontes de dados dão suporte a esse tipo de bloqueio.|

Para obter mais informações sobre `SQLSetPos`, consulte o SDK do Windows. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="setrowsetsize"></a>  CRecordset::SetRowsetSize

Especifica o número de registros que deseja recuperar durante uma busca.

```
virtual void SetRowsetSize(DWORD dwNewRowsetSize);
```

### <a name="parameters"></a>Parâmetros

*dwNewRowsetSize*<br/>
O número de linhas a serem recuperadas durante uma busca de determinado.

### <a name="remarks"></a>Comentários

Essa função membro virtual Especifica quantas linhas você deseja recuperar durante uma única busca ao usar a busca de linhas em massa. Para implementar a busca de linhas em massa, você deve definir a `CRecordset::useMultiRowFetch` opção a *dwOptions* parâmetro do [abrir](#open) função de membro.

> [!NOTE]
>  Chamando `SetRowsetSize` sem implementar em massa busca de linhas resultará em uma declaração com falha.

Chame `SetRowsetSize` antes de chamar `Open` definir inicialmente o tamanho de conjunto de linhas do conjunto de registros. O tamanho do conjunto de linhas padrão ao implementar a busca de linhas em massa é 25.

> [!NOTE]
>  Tenha cuidado ao chamar `SetRowsetSize`. Se você manualmente está alocando armazenamento para os dados (conforme especificado pela `CRecordset::userAllocMultiRowBuffers` opção do parâmetro dwOptions no `Open`), você deve verificar se é necessário realocar esses buffers de armazenamento depois de chamar `SetRowsetSize`, mas antes de você Execute qualquer operação de navegação do cursor.

Para obter a configuração atual para o tamanho do conjunto de linhas, chame [GetRowsetSize](#getrowsetsize).

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="update"></a>  CRecordset::Update

Conclui uma `AddNew` ou `Edit` operação, salvando os dados novos ou editados na fonte de dados.

```
virtual BOOL Update();
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se um registro foi atualizado com êxito; Caso contrário, 0 se nenhuma coluna tiver sido alterado. Se nenhum registro foi atualizado, ou se mais de um registro foi atualizado, uma exceção é lançada. Além disso, uma exceção é lançada para qualquer outra falha na fonte de dados.

### <a name="remarks"></a>Comentários

Chame essa função de membro após uma chamada para o [AddNew](#addnew) ou [editar](#edit) função de membro. Essa chamada é necessária para concluir a `AddNew` ou `Edit` operação.

> [!NOTE]
>  Se você tiver implementado a busca de linhas em massa, você não pode chamar `Update`. Isso resultará em uma declaração com falha. Embora a classe `CRecordset` não fornece um mecanismo para atualizar linhas em massa de dados, você pode escrever suas próprias funções usando a função de API ODBC `SQLSetPos`. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Ambos `AddNew` e `Edit` preparar um buffer de edição na qual os dados adicionados ou editados são colocados para salvá-lo a fonte de dados. `Update` salva os dados. Apenas os campos marcados ou detectado como alterado são atualizados.

Se a fonte de dados oferece suporte a transações, você pode fazer o `Update` chamar (e seus correspondentes `AddNew` ou `Edit` chamar) faz parte de uma transação. Para obter mais informações sobre transações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).

> [!CAUTION]
>  Se você chamar `Update` sem primeiro chamar `AddNew` ou `Edit`, `Update` lança um `CDBException`. Se você chamar `AddNew` ou `Edit`, você deve chamar `Update` antes de chamar um `Move` operação ou antes de fechar o conjunto de registros ou a conexão de fonte de dados. Caso contrário, suas alterações serão perdidas sem notificação.

Para obter detalhes sobre a manipulação `Update` falhas, consulte o artigo [conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

### <a name="example"></a>Exemplo

Consulte o artigo [transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordView](../../mfc/reference/crecordview-class.md)
