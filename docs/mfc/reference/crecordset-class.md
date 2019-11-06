---
title: Classe CRecordset
ms.date: 11/04/2016
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
ms.openlocfilehash: 1ebdb18254171d28b5d5e02367596b79142df284
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626186"
---
# <a name="crecordset-class"></a>Classe CRecordset

Representa um conjunto de registros selecionados de uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```
class CRecordset : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Name|Descrição|
|----------|-----------------|
|[CRecordset::CRecordset](#crecordset)|Constrói um objeto `CRecordset`. Sua classe derivada deve fornecer um construtor que chame este.|

### <a name="public-methods"></a>Métodos Públicos

|Name|Descrição|
|----------|-----------------|
|[CRecordset:: AddNew](#addnew)|Prepara para adicionar um novo registro. Chame `Update` para concluir a adição.|
|[CRecordset:: CanAppend](#canappend)|Retornará zero se novos registros puderem ser adicionados ao conjunto de registros por meio da função membro `AddNew`.|
|[CRecordset:: CanBookmark](#canbookmark)|Retornará zero se o conjunto de registros der suporte a indicadores.|
|[CRecordset:: Cancel](#cancel)|Cancela uma operação assíncrona ou um processo de um segundo thread.|
|[CRecordset:: CancelUpdate](#cancelupdate)|Cancela as atualizações pendentes devido a uma operação de `AddNew` ou `Edit`.|
|[CRecordset:: Restart](#canrestart)|Retornará zero se `Requery` puder ser chamado para executar a consulta do conjunto de registros novamente.|
|[CRecordset:: canrole](#canscroll)|Retornará zero se você puder percorrer os registros.|
|[CRecordset:: CanTransact](#cantransact)|Retornará zero se a fonte de dados der suporte a transações.|
|[CRecordset:: CanUpdate](#canupdate)|Retornará zero se o conjunto de registros puder ser atualizado (você pode adicionar, atualizar ou excluir registros).|
|[CRecordset::CheckRowsetError](#checkrowseterror)|Chamado para tratar erros gerados durante a busca de registro.|
|[CRecordset:: fechar](#close)|Fecha o conjunto de registros e o HSTMT ODBC associado a ele.|
|[CRecordset::D excluir](#delete)|Exclui o registro atual do conjunto de registros. Você deve rolar explicitamente para outro registro após a exclusão.|
|[CRecordset::D oBulkFieldExchange](#dobulkfieldexchange)|Chamado para trocar linhas de dados em massa da fonte de dados para o conjunto de registros. Implementa a troca de campo de registro em massa (suporte RFX em massa).|
|[CRecordset::D oFieldExchange](#dofieldexchange)|Chamado para trocar dados (em ambas as direções) entre os membros de dados de campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa a troca de campo de registro (suporte RFX).|
|[CRecordset:: editar](#edit)|Prepara para alterações no registro atual. Chame `Update` para concluir a edição.|
|[CRecordset::FlushResultSet](#flushresultset)|Retornará zero se houver outro conjunto de resultados a ser recuperado ao usar uma consulta predefinida.|
|[CRecordset:: GetBookmark](#getbookmark)|Atribui o valor de indicador de um registro ao objeto de parâmetro.|
|[CRecordset::GetDefaultConnect](#getdefaultconnect)|Chamado para obter a cadeia de conexão padrão.|
|[CRecordset::GetDefaultSQL](#getdefaultsql)|Chamado para obter a cadeia de caracteres SQL padrão a ser executada.|
|[CRecordset::GetFieldValue](#getfieldvalue)|Retorna o valor de um campo em um conjunto de registros.|
|[CRecordset::GetODBCFieldCount](#getodbcfieldcount)|Retorna o número de campos no conjunto de registros.|
|[CRecordset::GetODBCFieldInfo](#getodbcfieldinfo)|Retorna tipos específicos de informações sobre os campos em um conjunto de registros.|
|[CRecordset::GetRecordCount](#getrecordcount)|Retorna o número de registros no conjunto de registros.|
|[CRecordset::GetRowsetSize](#getrowsetsize)|Retorna o número de registros que você deseja recuperar durante uma única busca.|
|[CRecordset::GetRowsFetched](#getrowsfetched)|Retorna o número real de linhas recuperadas durante uma busca.|
|[CRecordset::GetRowStatus](#getrowstatus)|Retorna o status da linha após uma busca.|
|[CRecordset::GetSQL](#getsql)|Obtém a cadeia de caracteres SQL usada para selecionar registros para o conjunto de registros.|
|[CRecordset:: GetStatus](#getstatus)|Obtém o status do conjunto de registros: o índice do registro atual e se uma contagem final dos registros foi obtida.|
|[CRecordset:: getTableName](#gettablename)|Obtém o nome da tabela na qual o conjunto de registros é baseado.|
|[CRecordset::IsBOF](#isbof)|Retornará zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há registro atual.|
|[CRecordset:: IsDeleted](#isdeleted)|Retornará zero se o conjunto de registros estiver posicionado em um registro excluído.|
|[CRecordset::IsEOF](#iseof)|Retornará zero se o conjunto de registros tiver sido posicionado após o último registro. Não há registro atual.|
|[CRecordset::IsFieldDirty](#isfielddirty)|Retornará zero se o campo especificado no registro atual tiver sido alterado.|
|[CRecordset::IsFieldNull](#isfieldnull)|Retornará zero se o campo especificado no registro atual for nulo (não tem valor).|
|[CRecordset::IsFieldNullable](#isfieldnullable)|Retornará zero se o campo especificado no registro atual puder ser definido como nulo (sem valor).|
|[CRecordset:: IsOpen](#isopen)|Retornará zero se `Open` tiver sido chamado anteriormente.|
|[CRecordset:: mover](#move)|Posiciona o conjunto de registros em um número especificado de registos do registro atual em qualquer direção.|
|[CRecordset:: MoveFirst](#movefirst)|Posiciona o registro atual no primeiro registro no conjunto de registros. Teste `IsBOF` primeiro.|
|[CRecordset:: MoveLast](#movelast)|Posiciona o registro atual no último registro ou no último conjunto de linhas. Teste `IsEOF` primeiro.|
|[CRecordset:: MoveNext](#movenext)|Posiciona o registro atual no próximo registro ou no próximo conjunto de linhas. Teste `IsEOF` primeiro.|
|[CRecordset::MovePrev](#moveprev)|Posiciona o registro atual no registro anterior ou no conjunto de linhas anterior. Teste `IsBOF` primeiro.|
|[CRecordset::OnSetOptions](#onsetoptions)|Chamado para definir opções (usadas na seleção) para a instrução ODBC especificada.|
|[CRecordset::OnSetUpdateOptions](#onsetupdateoptions)|Chamado para definir opções (usadas na atualização) para a instrução ODBC especificada.|
|[CRecordset:: abrir](#open)|Abre o conjunto de registros recuperando a tabela ou executando a consulta que o conjunto de registros representa.|
|[CRecordset::RefreshRowset](#refreshrowset)|Atualiza os dados e o status das linhas especificadas.|
|[CRecordset:: Requery](#requery)|Executa a consulta do conjunto de registros novamente para atualizar os registros selecionados.|
|[CRecordset::SetAbsolutePosition](#setabsoluteposition)|Posiciona o conjunto de registros no registro correspondente ao número de registro especificado.|
|[CRecordset:: SetBookmark](#setbookmark)|Posiciona o conjunto de registros no registro especificado pelo indicador.|
|[CRecordset::SetFieldDirty](#setfielddirty)|Marca o campo especificado no registro atual como alterado.|
|[CRecordset::SetFieldNull](#setfieldnull)|Define o valor do campo especificado no registro atual como nulo (sem valor).|
|[CRecordset:: setlockmode](#setlockingmode)|Define o modo de bloqueio como bloqueio "otimista" (o padrão) ou o bloqueio "pessimista". Determina como os registros são bloqueados para atualizações.|
|[CRecordset::SetParamNull](#setparamnull)|Define o parâmetro especificado como nulo (sem valor).|
|[CRecordset::SetRowsetCursorPosition](#setrowsetcursorposition)|Posiciona o cursor na linha especificada dentro do conjunto de linhas.|
|[CRecordset::SetRowsetSize](#setrowsetsize)|Especifica o número de registros que você deseja recuperar durante uma busca.|
|[CRecordset:: atualizar](#update)|Conclui uma operação de `AddNew` ou `Edit` salvando os dados novos ou editados na fonte de dados.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Name|Descrição|
|----------|-----------------|
|[CRecordset::m_hstmt](#m_hstmt)|Contém o identificador da instrução ODBC para o conjunto de registros. Digite `HSTMT`.|
|[CRecordset::m_nFields](#m_nfields)|Contém o número de membros de dados de campo no conjunto de registros. Digite `UINT`.|
|[CRecordset::m_nParams](#m_nparams)|Contém o número de membros de dados de parâmetro no conjunto de registros. Digite `UINT`.|
|[CRecordset::m_pDatabase](#m_pdatabase)|Contém um ponteiro para o objeto `CDatabase` por meio do qual o conjunto de registros está conectado a uma fonte de dados.|
|[CRecordset::m_strFilter](#m_strfilter)|Contém um `CString` que especifica uma cláusula de `WHERE` de linguagem SQL (SQL). Usado como um filtro para selecionar apenas os registros que atendem a determinados critérios.|
|[CRecordset::m_strSort](#m_strsort)|Contém um `CString` que especifica uma cláusula SQL `ORDER BY`. Usado para controlar como os registros são classificados.|

## <a name="remarks"></a> Comentários

Conhecidos como "conjuntos de registros", os objetos `CRecordset` geralmente são usados em duas formas: Dynasets e instantâneos. Um dynaset permanece sincronizado com as atualizações de dados feitas por outros usuários. Um instantâneo é uma exibição estática dos dados. Cada formulário representa um conjunto de registros corrigidos no momento em que o conjunto de registros é aberto, mas quando você rola para um registro em um dynaset, ele reflete as alterações feitas posteriormente no registro, seja por outros usuários ou por outros conjuntos de registros em seu aplicativo.

> [!NOTE]
>  Se você estiver trabalhando com as classes DAO (objetos de acesso a dados) em vez das classes ODBC (Open Database Connectivity), use a classe [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

Para trabalhar com qualquer tipo de conjunto de registros, normalmente deriva uma classe de conjunto de registros específica do aplicativo de `CRecordset`. Os conjuntos de registros selecionam registros de uma fonte de dados e você pode:

- Percorra os registros.

- Atualize os registros e especifique um modo de bloqueio.

- Filtre o conjunto de registros para restringir os registros que ele seleciona entre os disponíveis na fonte de dados.

- Classificar o conjunto de registros.

- Parametrizar o conjunto de registros para personalizar sua seleção com informações não conhecidas até o tempo de execução.

Para usar sua classe, abra um banco de dados e construa um objeto recordset, passando o construtor de um ponteiro para o objeto `CDatabase`. Em seguida, chame a função de membro `Open` do conjunto de registros, onde você pode especificar se o objeto é um dynaset ou um instantâneo. Chamar `Open` seleciona dados da fonte de dados. Depois que o objeto Recordset for aberto, use suas funções de membro e membros de dados para percorrer os registros e operar neles. As operações disponíveis dependem de o objeto ser um dynaset ou um instantâneo, seja atualizável ou somente leitura (isso depende da capacidade da fonte de dados ODBC (Open Database Connectivity)) e se você implementou a busca em massa de linhas. Para atualizar os registros que podem ter sido alterados ou adicionados desde a chamada de `Open`, chame a função de membro `Requery` do objeto. Chame a função de membro `Close` do objeto e destrua o objeto quando terminar com ele.

Em uma classe de `CRecordset` derivada, a troca de campo de registro (suporte RFX) ou a troca de campo de registro em massa (suporte RFX em massa) é usada para dar suporte à leitura e à atualização de campos de registro.

Para obter mais informações sobre conjuntos de registros e troca de campo de registro, consulte a [visão geral dos artigos: programação de banco de dados](../../data/data-access-programming-mfc-atl.md), conjunto de [registros (ODBC)](../../data/odbc/recordset-odbc.md), [conjunto de registros: busca de registro em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md)e [troca de campo (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md). Para ter um foco em dynasets e instantâneos, consulte os artigos [dynaset](../../data/odbc/dynaset.md) e [snapshot](../../data/odbc/snapshot.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CRecordset`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

##  <a name="addnew"></a>CRecordset:: AddNew

Prepara para adicionar um novo registro à tabela.

```
virtual void AddNew();
```

### <a name="remarks"></a>Comentários

Você deve chamar a função de membro [Requery](#requery) para ver o registro recém-adicionado. Os campos do registro são inicialmente nulos. (Na terminologia do banco de dados, NULL significa "sem valor" e não é o mesmo que NULL C++em.) Para concluir a operação, você deve chamar a função de membro de [atualização](#update) . `Update` salva as alterações na fonte de dados.

> [!NOTE]
>  Se você tiver implementado a busca de linha em massa, não será possível chamar `AddNew`. Isso resultará em uma asserção com falha. Embora a classe `CRecordset` não forneça um mecanismo para atualizar linhas de dados em massa, você pode escrever suas próprias funções usando a função da API do ODBC `SQLSetPos`. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

`AddNew` prepara um novo registro vazio usando os membros de dados de campo do conjunto de registros. Depois de chamar `AddNew`, defina os valores desejados nos membros de dados de campo do conjunto de registros. (Você não precisa chamar a função [Editar](#edit) membro para essa finalidade; use `Edit` apenas para registros existentes.) Quando você chama subsequentemente `Update`, os valores alterados no campo membros de dados são salvos na fonte de dados.

> [!CAUTION]
>  Se você rolar para um novo registro antes de chamar `Update`, o novo registro será perdido e nenhum aviso será fornecido.

Se a fonte de dados der suporte a transações, você poderá fazer seu `AddNew` chamar parte de uma transação. Para obter mais informações sobre transações, consulte Class [CDatabase](../../mfc/reference/cdatabase-class.md). Observe que você deve chamar [CDatabase:: BeginTrans](../../mfc/reference/cdatabase-class.md#begintrans) antes de chamar `AddNew`.

> [!NOTE]
>  Para dynasets, novos registros são adicionados ao conjunto de registros como o último registro. Registros adicionados não são adicionados a instantâneos; Você deve chamar `Requery` para atualizar o conjunto de registros.

É ilegal chamar `AddNew` para um conjunto de registros cuja função membro `Open` não foi chamada. Uma `CDBException` será gerada se você chamar `AddNew` para um conjunto de registros que não possa ser anexado. Você pode determinar se o conjunto de registros é atualizável chamando [CanAppend](#canappend).

Para obter mais informações, consulte os seguintes artigos: conjunto de registros [: como os conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md), [conjunto de registros: adição, atualização e exclusão de registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)e [transação (ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>Exemplo

Consulte o artigo [transação: executando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

##  <a name="canappend"></a>CRecordset:: CanAppend

Determina se o conjunto de registros aberto anteriormente permite que você adicione novos registros.

```
BOOL CanAppend() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros permitir a adição de novos registros; caso contrário, 0. `CanAppend` retornará 0 se você tiver aberto o conjunto de registros como somente leitura.

##  <a name="canbookmark"></a>CRecordset:: CanBookmark

Determina se o conjunto de registros permite marcar registros usando indicadores.

```
BOOL CanBookmark() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros der suporte a indicadores; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função é independente da opção `CRecordset::useBookmarks` no parâmetro *dwOptions* da função de membro [Open](#open) . `CanBookmark` indica se o driver ODBC e o tipo de cursor fornecidos dão suporte a indicadores. `CRecordset::useBookmarks` indica se os indicadores estarão disponíveis, desde que eles tenham suporte.

> [!NOTE]
>  Não há suporte para indicadores em conjuntos de registros somente de encaminhamento.

Para obter mais informações sobre indicadores e a navegação do conjunto de registros, consulte o conjunto de registros de artigos [: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

##  <a name="cancel"></a>CRecordset:: Cancel

Solicita que a fonte de dados cancele uma operação assíncrona em andamento ou um processo de um segundo thread.

```
void Cancel();
```

### <a name="remarks"></a>Comentários

Observe que as classes ODBC do MFC não usam mais o processamento assíncrono; para executar uma operação assíncrona, você deve chamar diretamente a função da API do ODBC `SQLSetConnectOption`. Para obter mais informações, consulte o tópico "executando funções de forma assíncrona" no *Guia do programador do ODBC SDK*.

##  <a name="cancelupdate"></a>CRecordset:: CancelUpdate

Cancela todas as atualizações pendentes, causadas por uma operação de [edição](#edit) ou [AddNew](#addnew) , antes da [atualização](#update) ser chamada.

```
void CancelUpdate();
```

### <a name="remarks"></a>Comentários

> [!NOTE]
>  Essa função de membro não é aplicável em conjuntos de registros que estão usando a busca de linha em massa, pois esses conjuntos de registros não podem chamar `Edit`, `AddNew`ou `Update`. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Se a verificação automática de campo sujo estiver habilitada, `CancelUpdate` irá restaurar as variáveis de membro para os valores que eles tinham antes `Edit` ou `AddNew` foi chamado; caso contrário, qualquer alteração de valor permanecerá. Por padrão, a verificação automática de campo é habilitada quando o conjunto de registros é aberto. Para desabilitá-lo, você deve especificar o `CRecordset::noDirtyFieldCheck` no parâmetro *dwOptions* da função de membro [Open](#open) .

Para obter mais informações sobre como atualizar dados, consulte o artigo [conjunto de registros: adicionando, atualizando e excluindo registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md).

##  <a name="canrestart"></a>CRecordset:: Restart

Determina se o conjunto de registros permite reiniciar sua consulta (para atualizar seus registros) chamando a função membro `Requery`.

```
BOOL CanRestart() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a consulta for permitida; caso contrário, 0.

##  <a name="canscroll"></a>CRecordset:: canrole

Determina se o conjunto de registros permite a rolagem.

```
BOOL CanScroll() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros permitir a rolagem; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a rolagem, consulte o artigo [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

##  <a name="cantransact"></a>CRecordset:: CanTransact

Determina se o conjunto de registros permite transações.

```
BOOL CanTransact() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros permitir transações; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte a [transação do artigo (ODBC)](../../data/odbc/transaction-odbc.md).

##  <a name="canupdate"></a>CRecordset:: CanUpdate

Determina se o conjunto de registros pode ser atualizado.

```
BOOL CanUpdate() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros puder ser atualizado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um conjunto de registros pode ser somente leitura se a fonte de dados subjacente for somente leitura ou se você tiver especificado `CRecordset::readOnly` no parâmetro *dwOptions* ao abrir o conjunto de registros.

##  <a name="checkrowseterror"></a>CRecordset::CheckRowsetError

Chamado para tratar erros gerados durante a busca de registro.

```
virtual void CheckRowsetError(RETCODE nRetCode);
```

### <a name="parameters"></a>Parâmetros

*nRetCode*<br/>
Um código de retorno de função da API ODBC. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Essa função de membro virtual manipula os erros que ocorrem quando os registros são buscados e é útil durante a busca de linha em massa. Talvez você queira considerar a substituição de `CheckRowsetError` para implementar seu próprio tratamento de erros.

`CheckRowsetError` é chamado automaticamente em uma operação de navegação de cursor, como `Open`, `Requery`ou qualquer operação de `Move`. É passado o valor de retorno da função da API do ODBC `SQLExtendedFetch`. A tabela a seguir lista os possíveis valores para o parâmetro *nRetCode* .

|nRetCode|Descrição|
|--------------|-----------------|
|SQL_SUCCESS|Função concluída com êxito; Não há informações adicionais disponíveis.|
|SQL_SUCCESS_WITH_INFO|A função foi concluída com êxito, possivelmente com um erro não fatal. Informações adicionais podem ser obtidas chamando `SQLError`.|
|SQL_NO_DATA_FOUND|Todas as linhas do conjunto de resultados foram buscadas.|
|SQL_ERROR|Falha na função. Informações adicionais podem ser obtidas chamando `SQLError`.|
|SQL_INVALID_HANDLE|Falha na função devido a um identificador de ambiente, identificador de conexão ou identificador de instrução inválido. Isso indica um erro de programação. Não há informações adicionais disponíveis em `SQLError`.|
|SQL_STILL_EXECUTING|Uma função que foi iniciada assincronamente ainda está em execução. Observe que, por padrão, o MFC nunca passará esse valor para `CheckRowsetError`; O MFC continuará chamando `SQLExtendedFetch` até não retornar mais SQL_STILL_EXECUTING.|

Para obter mais informações sobre `SQLError`, consulte a SDK do Windows. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="close"></a>CRecordset:: fechar

Fecha o conjunto de registros.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

A HSTMT ODBC e todas as memórias que a estrutura alocada para o conjunto de registros são desalocadas. Normalmente, depois de chamar `Close`, você C++ exclui o objeto Recordset se ele foi alocado com **New**.

Você pode chamar `Open` novamente após a chamada de `Close`. Isso permite que você reutilize o objeto Recordset. A alternativa é chamar `Requery`.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#17](../../mfc/codesnippet/cpp/crecordset-class_1.cpp)]

##  <a name="crecordset"></a>CRecordset::CRecordset

Constrói um objeto `CRecordset`.

```
CRecordset(CDatabase* pDatabase = NULL);
```

### <a name="parameters"></a>Parâmetros

*pDatabase*<br/>
Contém um ponteiro para um objeto `CDatabase` ou o valor NULL. Se não for nulo e a função de membro `Open` do objeto de `CDatabase` não tiver sido chamada para conectá-lo à fonte de dados, o conjunto de registros tentará abri-lo para você durante sua própria chamada de `Open`. Se você passar NULL, um objeto `CDatabase` será construído e conectado para você usando as informações da fonte de dados que você especificou quando derivou a classe recordset com ClassWizard.

### <a name="remarks"></a>Comentários

Você pode usar o `CRecordset` diretamente ou derivar uma classe específica do aplicativo do `CRecordset`. Você pode usar ClassWizard para derivar suas classes do conjunto de registros.

> [!NOTE]
>  Uma classe derivada *deve* fornecer seu próprio construtor. No construtor de sua classe derivada, chame o Construtor `CRecordset::CRecordset`, passando os parâmetros apropriados junto com ele.

Passe NULL para o construtor do conjunto de registros para ter um objeto `CDatabase` construído e conectado para você automaticamente. Essa é uma abreviação útil que não exige que você construa e conecte um objeto de `CDatabase` antes de construir seu conjunto de registros.

### <a name="example"></a>Exemplo

Para obter mais informações, consulte o artigo [conjunto de registros: declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md).

##  <a name="delete"></a>CRecordset::D excluir

Exclui o registro atual.

```
virtual void Delete();
```

### <a name="remarks"></a>Comentários

Após uma exclusão bem-sucedida, os membros de dados de campo do conjunto de registros são definidos como um valor nulo e você deve chamar explicitamente uma das funções de `Move` para sair do registro excluído. Depois que você sair do registro excluído, não será possível retornar a ele. Se a fonte de dados der suporte a transações, você poderá fazer com que o `Delete` chame parte de uma transação. Para obter mais informações, consulte a [transação do artigo (ODBC)](../../data/odbc/transaction-odbc.md).

> [!NOTE]
>  Se você tiver implementado a busca de linha em massa, não será possível chamar `Delete`. Isso resultará em uma asserção com falha. Embora a classe `CRecordset` não forneça um mecanismo para atualizar linhas de dados em massa, você pode escrever suas próprias funções usando a função da API do ODBC `SQLSetPos`. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

> [!CAUTION]
>  O conjunto de registros deve ser atualizável e deve haver um registro válido atual no conjunto de registros quando você chama `Delete`; caso contrário, ocorrerá um erro. Por exemplo, se você excluir um registro, mas não rolar para um novo registro antes de chamar `Delete` novamente, `Delete` lançará um [CDBException](../../mfc/reference/cdbexception-class.md).

Ao contrário de [AddNew](#addnew) e [Edit](#edit), uma chamada para `Delete` não é seguida por uma chamada para [Update](#update). Se uma chamada de `Delete` falhar, os membros dos dados de campo permanecerão inalterados.

### <a name="example"></a>Exemplo

Este exemplo mostra um conjunto de registros criado no quadro de uma função. O exemplo pressupõe a existência de `m_dbCust`, uma variável de membro do tipo `CDatabase` já conectado à fonte de dados.

[!code-cpp[NVC_MFCDatabase#18](../../mfc/codesnippet/cpp/crecordset-class_2.cpp)]

##  <a name="dobulkfieldexchange"></a>CRecordset::D oBulkFieldExchange

Chamado para trocar linhas de dados em massa da fonte de dados para o conjunto de registros. Implementa a troca de campo de registro em massa (suporte RFX em massa).

```
virtual void DoBulkFieldExchange(CFieldExchange* pFX);
```

### <a name="parameters"></a>Parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) . A estrutura já terá configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Quando a busca de linha em massa é implementada, a estrutura chama essa função de membro para transferir automaticamente os dados da fonte de dados para o objeto Recordset. `DoBulkFieldExchange` também associa os membros de dados de parâmetro, se houver, aos espaços reservados de parâmetro na cadeia de caracteres da instrução SQL para a seleção do conjunto de registros.

Se a busca de linha em massa não for implementada, a estrutura chamará [DoFieldExchange](#dofieldexchange). Para implementar a busca de linha em massa, você deve especificar a opção `CRecordset::useMultiRowFetch` do parâmetro *dwOptions* na função de membro [Open](#open) .

> [!NOTE]
> `DoBulkFieldExchange` estará disponível somente se você estiver usando uma classe derivada de `CRecordset`. Se você tiver criado um objeto Recordset diretamente do `CRecordset`, deverá chamar a função membro [GetFieldValue](#getfieldvalue) para recuperar dados.

A troca de campo de registro em massa (suporte RFX em massa) é semelhante à suporte RFX (Record Field Exchange). Os dados são transferidos automaticamente da fonte de dados para o objeto Recordset. No entanto, você não pode chamar `AddNew`, `Edit`, `Delete`ou `Update` para transferir alterações de volta para a fonte de dados. A classe `CRecordset` atualmente não fornece um mecanismo para atualizar linhas de dados em massa; no entanto, você pode escrever suas próprias funções usando a função da API do ODBC `SQLSetPos`.

Observe que o ClassWizard não dá suporte à troca de campo de registro em massa; Portanto, você deve substituir `DoBulkFieldExchange` manualmente escrevendo chamadas para as funções de suporte RFX em massa. Para obter mais informações sobre essas funções, consulte o tópico [registro de campo Exchange Functions](../../mfc/reference/record-field-exchange-functions.md).

Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter informações relacionadas, consulte o artigo [registro de campo Exchange (suporte RFX)](../../data/odbc/record-field-exchange-rfx.md).

##  <a name="dofieldexchange"></a>CRecordset::D oFieldExchange

Chamado para trocar dados (em ambas as direções) entre os membros de dados de campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa a troca de campo de registro (suporte RFX).

```
virtual void DoFieldExchange(CFieldExchange* pFX);
```

### <a name="parameters"></a>Parâmetros

*pFX*<br/>
Um ponteiro para um objeto [CFieldExchange](../../mfc/reference/cfieldexchange-class.md) . A estrutura já terá configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Quando a busca de linha em massa não é implementada, a estrutura chama essa função de membro para trocar dados automaticamente entre os membros de dados de campo do seu objeto Recordset e as colunas correspondentes do registro atual na fonte de dados. `DoFieldExchange` também associa os membros de dados de parâmetro, se houver, aos espaços reservados de parâmetro na cadeia de caracteres da instrução SQL para a seleção do conjunto de registros.

Se a busca de linha em massa for implementada, a estrutura chamará [DoBulkFieldExchange](#dobulkfieldexchange). Para implementar a busca de linha em massa, você deve especificar a opção `CRecordset::useMultiRowFetch` do parâmetro *dwOptions* na função de membro [Open](#open) .

> [!NOTE]
> `DoFieldExchange` estará disponível somente se você estiver usando uma classe derivada de `CRecordset`. Se você tiver criado um objeto Recordset diretamente do `CRecordset`, deverá chamar a função membro [GetFieldValue](#getfieldvalue) para recuperar dados.

A troca de dados de campo, chamada de troca de campo de registro (suporte RFX), funciona em ambas as direções: dos membros de dados de campo do objeto Recordset para os campos do registro na fonte de dados e do registro na fonte de dados para o objeto Recordset.

A única ação que você deve executar normalmente para implementar `DoFieldExchange` para sua classe de conjunto de registros derivada é criar a classe com ClassWizard e especificar os nomes e tipos de dados dos membros de dados de campo. Você também pode adicionar código ao que ClassWizard escreve para especificar membros de dados de parâmetro ou para lidar com todas as colunas que você associa dinamicamente. Para obter mais informações, consulte o artigo [conjunto de registros: vinculação dinâmica de colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Quando você declara sua classe de conjunto de registros derivada com ClassWizard, o assistente grava uma substituição de `DoFieldExchange` para você, que se assemelha ao exemplo a seguir:

[!code-cpp[NVC_MFCDatabase#19](../../mfc/codesnippet/cpp/crecordset-class_3.cpp)]

Para obter mais informações sobre as funções suporte RFX, consulte o tópico [registro de campo Exchange Functions](../../mfc/reference/record-field-exchange-functions.md).

Para obter mais exemplos e detalhes sobre `DoFieldExchange`, consulte o artigo [registro de campo Exchange: como o suporte RFX funciona](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter informações gerais sobre suporte RFX, consulte o artigo [registro de campo troca](../../data/odbc/record-field-exchange-rfx.md).

##  <a name="edit"></a>CRecordset:: editar

Permite alterações no registro atual.

```
virtual void Edit();
```

### <a name="remarks"></a>Comentários

Depois de chamar `Edit`, você pode alterar os membros de dados do campo redefinindo diretamente seus valores. A operação é concluída quando você chama subsequentemente a função de membro [Update](#update) para salvar as alterações na fonte de dados.

> [!NOTE]
>  Se você tiver implementado a busca de linha em massa, não será possível chamar `Edit`. Isso resultará em uma asserção com falha. Embora a classe `CRecordset` não forneça um mecanismo para atualizar linhas de dados em massa, você pode escrever suas próprias funções usando a função da API do ODBC `SQLSetPos`. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

`Edit` salva os valores dos membros de dados do conjunto de registros. Se você chamar `Edit`, fazer alterações e, em seguida, chamar `Edit` novamente, os valores do registro serão restaurados para o que estavam antes da primeira chamada de `Edit`.

Em alguns casos, talvez você queira atualizar uma coluna tornando-a nula (que não contém dados). Para fazer isso, chame [SetFieldNull](#setfieldnull) com um parâmetro de true para marcar o campo como nulo; Isso também faz com que a coluna seja atualizada. Se você quiser que um campo seja gravado na fonte de dados, mesmo que seu valor não tenha sido alterado, chame [SetFieldDirty](#setfielddirty) com um parâmetro de true. Isso funciona mesmo que o campo tenha o valor NULL.

Se a fonte de dados der suporte a transações, você poderá fazer com que o `Edit` chame parte de uma transação. Observe que você deve chamar [CDatabase:: BeginTrans](../../mfc/reference/cdatabase-class.md#begintrans) antes de chamar `Edit` e depois que o conjunto de registros tiver sido aberto. Observe também que chamar [CDatabase:: CommitTrans](../../mfc/reference/cdatabase-class.md#committrans) não é um substituto para chamar `Update` para concluir a operação de `Edit`. Para obter mais informações sobre transações, consulte Class [CDatabase](../../mfc/reference/cdatabase-class.md).

Dependendo do modo de bloqueio atual, o registro que está sendo atualizado pode ser bloqueado pelo `Edit` até que você chame `Update` ou role para outro registro, ou pode ser bloqueado somente durante a chamada de `Edit`. Você pode alterar o modo de bloqueio com [Setlockmode](#setlockingmode).

O valor anterior do registro atual será restaurado se você rolar para um novo registro antes de chamar `Update`. Uma `CDBException` será gerada se você chamar `Edit` para um conjunto de registros que não pode ser atualizado ou se não houver registro atual.

Para obter mais informações, consulte os artigos [Transaction (ODBC)](../../data/odbc/transaction-odbc.md) and [Recordset: locking Records (ODBC)](../../data/odbc/recordset-locking-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#20](../../mfc/codesnippet/cpp/crecordset-class_4.cpp)]

##  <a name="flushresultset"></a>CRecordset::FlushResultSet

Recupera o próximo conjunto de resultados de uma consulta predefinida (procedimento armazenado), se houver vários conjuntos de resultados.

```
BOOL FlushResultSet();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se houver mais conjuntos de resultados a serem recuperados; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve chamar `FlushResultSet` somente quando terminar completamente com o cursor no conjunto de resultados atual. Observe que quando você recupera o próximo conjunto de resultados chamando `FlushResultSet`, o cursor não é válido nesse conjunto de resultados; Você deve chamar a função de membro [MoveNext](#movenext) depois de chamar `FlushResultSet`.

Se uma consulta predefinida usar um parâmetro de saída ou parâmetros de entrada/saída, você deverá chamar `FlushResultSet` até que ele retorne `FALSE` (o valor 0), a fim de obter esses valores de parâmetro.

`FlushResultSet` chama a função de API do ODBC `SQLMoreResults`. Se `SQLMoreResults` retornar SQL_ERROR ou SQL_INVALID_HANDLE, `FlushResultSet` gerará uma exceção. Para obter mais informações sobre `SQLMoreResults`, consulte a SDK do Windows.

O procedimento armazenado precisa ter campos associados se você quiser chamar `FlushResultSet`.

### <a name="example"></a>Exemplo

O código a seguir pressupõe que `COutParamRecordset` é um objeto derivado de `CRecordset`com base em uma consulta predefinida com um parâmetro de entrada e um parâmetro de saída e que tem vários conjuntos de resultados. Observe a estrutura da substituição de [DoFieldExchange](#dofieldexchange) .

[!code-cpp[NVC_MFCDatabase#21](../../mfc/codesnippet/cpp/crecordset-class_5.cpp)]

[!code-cpp[NVC_MFCDatabase#22](../../mfc/codesnippet/cpp/crecordset-class_6.cpp)]

##  <a name="getbookmark"></a>CRecordset:: GetBookmark

Obtém o valor do indicador para o registro atual.

```
void GetBookmark(CDBVariant& varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Uma referência a um objeto [CDBVariant](../../mfc/reference/cdbvariant-class.md) que representa o indicador no registro atual.

### <a name="remarks"></a>Comentários

Para determinar se há suporte para indicadores no conjunto de registros, chame [CanBookmark](#canbookmark). Para disponibilizar indicadores, se houver suporte, você deverá definir a opção `CRecordset::useBookmarks` no parâmetro *dwOptions* da função de membro [Open](#open) .

> [!NOTE]
>  Se os indicadores não forem compatíveis ou estiverem indisponíveis, chamar `GetBookmark` resultará na geração de uma exceção. Não há suporte para indicadores em conjuntos de registros somente de encaminhamento.

`GetBookmark` atribui o valor do indicador para o registro atual a um objeto `CDBVariant`. Para retornar a esse registro a qualquer momento depois de mover para um registro diferente, chame [SetBookmark](#setbookmark) com o objeto de `CDBVariant` correspondente.

> [!NOTE]
>  Depois de determinadas operações de conjunto de registros, os indicadores podem não ser mais válidos. Por exemplo, se você chamar `GetBookmark` seguido por `Requery`, talvez não seja possível retornar ao registro com `SetBookmark`. Chame [CDatabase:: GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se você pode chamar `SetBookmark`com segurança.

Para obter mais informações sobre indicadores e a navegação do conjunto de registros, consulte o conjunto de registros de artigos [: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

##  <a name="getdefaultconnect"></a>CRecordset::GetDefaultConnect

Chamado para obter a cadeia de conexão padrão.

```
virtual CString GetDefaultConnect();
```

### <a name="return-value"></a>Valor retornado

Um `CString` que contém a cadeia de conexão padrão.

### <a name="remarks"></a>Comentários

A estrutura chama essa função de membro para obter a cadeia de conexão padrão para a fonte de dados na qual o conjunto de registros é baseado. O ClassWizard implementa essa função para você identificando a mesma fonte de dados usada no ClassWizard para obter informações sobre tabelas e colunas. Provavelmente, você achará conveniente confiar nessa conexão padrão ao desenvolver seu aplicativo. Mas a conexão padrão pode não ser apropriada para os usuários do seu aplicativo. Se esse for o caso, você deverá reimplementar essa função, descartando a versão do ClassWizard. Para obter mais informações sobre cadeias de conexão, consulte o artigo [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md).

##  <a name="getdefaultsql"></a>CRecordset::GetDefaultSQL

Chamado para obter a cadeia de caracteres SQL padrão a ser executada.

```
virtual CString GetDefaultSQL();
```

### <a name="return-value"></a>Valor retornado

Um `CString` que contém a instrução SQL padrão.

### <a name="remarks"></a>Comentários

A estrutura chama essa função de membro para obter a instrução SQL padrão na qual o conjunto de registros é baseado. Pode ser um nome de tabela ou uma instrução SQL **Select** .

Você define indiretamente a instrução SQL padrão declarando sua classe recordset com ClassWizard e ClassWizard executa essa tarefa para você.

Se você precisar da cadeia de caracteres da instrução SQL para seu próprio uso, chame `GetSQL`, que retorna a instrução SQL usada para selecionar os registros do conjunto de registros quando ele foi aberto. Você pode editar a cadeia de caracteres SQL padrão na substituição da sua classe de `GetDefaultSQL`. Por exemplo, você pode especificar uma chamada para uma consulta predefinida usando uma instrução **Call** . (No entanto, observe que, se você editar `GetDefaultSQL`, também precisará modificar `m_nFields` para corresponder ao número de colunas na fonte de dados.)

Para obter mais informações, consulte o artigo [conjunto de registros: declarando uma classe para uma tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md).

> [!CAUTION]
>  O nome da tabela estará vazio se a estrutura não pôde identificar um nome de tabela, se vários nomes de tabela foram fornecidos ou se uma instrução de **chamada** não pôde ser interpretada. Observe que, ao usar uma instrução **Call** , você não deve inserir o espaço em branco entre as chaves e a palavra-chave **Call** , nem deve inserir o espaço em branco antes da chave ou antes da palavra-chave **Select** em uma instrução **Select** .

##  <a name="getfieldvalue"></a>CRecordset::GetFieldValue

Recupera dados de campo no registro atual.

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

*varValu*e uma referência a um objeto [CDBVariant](../../mfc/reference/cdbvariant-class.md) que armazenará o valor do campo.

*nFieldType*<br/>
O tipo de dados ODBC C do campo. Usando o valor padrão, DEFAULT_FIELD_TYPE, força `GetFieldValue` a determinar o tipo de dados C do tipo de dados SQL, com base na tabela a seguir. Caso contrário, você pode especificar o tipo de dados diretamente ou escolher um tipo de dados compatível; por exemplo, você pode armazenar qualquer tipo de dados em SQL_C_CHAR.

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

Para obter mais informações sobre tipos de dados ODBC, consulte os tópicos "tipos de dados SQL" e "tipos de dados C" no Apêndice D do SDK do Windows.

*nIndex*<br/>
O índice de base zero do campo.

*strValue*<br/>
Uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que armazenará o valor do campo convertido em texto, independentemente do tipo de dados do campo.

### <a name="remarks"></a>Comentários

Você pode procurar um campo por nome ou por índice. Você pode armazenar o valor do campo em um objeto `CDBVariant` ou um objeto `CString`.

Se você tiver implementado a busca de linha em massa, o registro atual sempre estará posicionado no primeiro registro em um conjunto de linhas. Para usar `GetFieldValue` em um registro dentro de um determinado conjunto de linhas, você deve primeiro chamar a função de membro [SetRowsetCursorPosition](#setrowsetcursorposition) para mover o cursor para a linha desejada dentro desse conjunto de linhas. Em seguida, chame `GetFieldValue` para essa linha. Para implementar a busca de linha em massa, você deve especificar a opção `CRecordset::useMultiRowFetch` do parâmetro *dwOptions* na função de membro [Open](#open) .

Você pode usar `GetFieldValue` para buscar campos dinamicamente em tempo de execução em vez de ligá-los estaticamente em tempo de design. Por exemplo, se você declarou um objeto Recordset diretamente do `CRecordset`, deverá usar `GetFieldValue` para recuperar os dados do campo; a troca de campo de registro (suporte RFX) ou a troca de campo de registro em massa (suporte RFX em massa) não está implementada.

> [!NOTE]
>  Se você declarar um objeto Recordset sem derivar de `CRecordset`, não terá a biblioteca de cursores ODBC carregada. A biblioteca de cursores exige que o conjunto de registros tenha pelo menos uma coluna associada; no entanto, quando você usa `CRecordset` diretamente, nenhuma das colunas é associada. As funções de membro [CDatabase:: OpenEx](../../mfc/reference/cdatabase-class.md#openex) e [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open) controlam se a biblioteca de cursores será carregada.

`GetFieldValue` chama a função de API do ODBC `SQLGetData`. Se o driver gerar o valor SQL_NO_TOTAL para o comprimento real do valor do campo, `GetFieldValue` lançará uma exceção. Para obter mais informações sobre `SQLGetData`, consulte a SDK do Windows.

### <a name="example"></a>Exemplo

O código de exemplo a seguir ilustra chamadas para `GetFieldValue` para um objeto Recordset declarado diretamente do `CRecordset`.

[!code-cpp[NVC_MFCDatabase#23](../../mfc/codesnippet/cpp/crecordset-class_7.cpp)]

> [!NOTE]
>  Ao contrário da classe DAO `CDaoRecordset`, `CRecordset` não tem uma função de membro `SetFieldValue`. Se você criar um objeto diretamente do `CRecordset`, ele será efetivamente somente leitura.

Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="getodbcfieldcount"></a>CRecordset::GetODBCFieldCount

Recupera o número total de campos em seu objeto Recordset.

```
short GetODBCFieldCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de campos no conjunto de registros.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como criar conjuntos de registros, consulte o artigo conjunto de registros [: Criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

##  <a name="getodbcfieldinfo"></a>CRecordset::GetODBCFieldInfo

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
Uma referência a uma estrutura de `CODBCFieldInfo`.

*nIndex*<br/>
O índice de base zero do campo.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você pesquise um campo por nome. A outra versão permite pesquisar um campo por índice.

Para obter uma descrição sobre as informações retornadas, consulte a estrutura [CODBCFieldInfo](../../mfc/reference/codbcfieldinfo-structure.md) .

Para obter mais informações sobre como criar conjuntos de registros, consulte o artigo conjunto de registros [: Criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

##  <a name="getrecordcount"></a>CRecordset::GetRecordCount

Determina o tamanho do conjunto de registros.

```
long GetRecordCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de registros no conjunto de registros; 0 se o conjunto de registros não contiver nenhum registro; ou-1 se a contagem de registros não puder ser determinada.

### <a name="remarks"></a>Comentários

> [!CAUTION]
>  A contagem de registros é mantida como uma "marca d' água alta", o registro de número mais alto ainda visto quando o usuário percorre os registros. O número total de registros só é conhecido depois que o usuário se moveu além do último registro. Por motivos de desempenho, a contagem não é atualizada quando você chama `MoveLast`. Para contar os registros por conta própria, chame `MoveNext` repetidamente até que `IsEOF` retorne diferente de zero. Adicionar um registro por meio de `CRecordset:AddNew` e `Update` aumenta a contagem; a exclusão de um registro por meio de `CRecordset::Delete` diminui a contagem.

##  <a name="getrowsetsize"></a>CRecordset::GetRowsetSize

Obtém a configuração atual para o número de linhas que você deseja recuperar durante uma determinada busca.

```
DWORD GetRowsetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de linhas a serem recuperadas durante uma determinada busca.

### <a name="remarks"></a>Comentários

Se você estiver usando a busca de linha em massa, o tamanho do conjunto de linhas padrão quando o conjunto de registros for aberto será 25; caso contrário, será 1.

Para implementar a busca de linha em massa, você deve especificar a opção `CRecordset::useMultiRowFetch` no parâmetro *dwOptions* da função de membro [Open](#open) . Para alterar a configuração do tamanho do conjunto de linhas, chame [SetRowsetSize](#setrowsetsize).

Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="getrowsfetched"></a>CRecordset::GetRowsFetched

Determina quantos registros foram realmente recuperados após uma busca.

```
DWORD GetRowsFetched() const;
```

### <a name="return-value"></a>Valor retornado

O número de linhas recuperadas da fonte de dados após uma determinada busca.

### <a name="remarks"></a>Comentários

Isso é útil quando você implementa a busca de linha em massa. O tamanho do conjunto de linhas normalmente indica quantas linhas serão recuperadas de uma busca; no entanto, o número total de linhas no conjunto de registros também afeta a quantidade de linhas que serão recuperadas em um conjunto de linhas. Por exemplo, se o conjunto de registros tiver 10 registros com uma configuração de tamanho de conjunto de linhas de 4, o loop pelo conjunto de registros chamando `MoveNext` resultará no conjunto de linhas final com apenas dois registros.

Para implementar a busca de linha em massa, você deve especificar a opção `CRecordset::useMultiRowFetch` no parâmetro *dwOptions* da função de membro [Open](#open) . Para especificar o tamanho do conjunto de linhas, chame [SetRowsetSize](#setrowsetsize).

Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#24](../../mfc/codesnippet/cpp/crecordset-class_8.cpp)]

##  <a name="getrowstatus"></a>CRecordset::GetRowStatus

Obtém o status de uma linha no conjunto de linhas atual.

```
WORD GetRowStatus(WORD wRow) const;
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A posição de uma linha baseada em um no conjunto de linhas atual. Esse valor pode variar de 1 até o tamanho do conjunto de linhas.

### <a name="return-value"></a>Valor retornado

Um valor de status para a linha. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

`GetRowStatus` retorna um valor que indica qualquer alteração no status para a linha desde que ela foi recuperada pela última vez da fonte de dados ou que nenhuma linha correspondente a *wRow* foi buscada. A tabela a seguir lista os possíveis valores de retorno.

|Valor de status|Descrição|
|------------------|-----------------|
|SQL_ROW_SUCCESS|A linha está inalterada.|
|SQL_ROW_UPDATED|A linha foi atualizada.|
|SQL_ROW_DELETED|A linha foi excluída.|
|SQL_ROW_ADDED|A linha foi adicionada.|
|SQL_ROW_ERROR|A linha não é recuperável devido a um erro.|
|SQL_ROW_NOROW|Não há nenhuma linha que corresponda a *wRow*.|

Para obter mais informações, consulte a função da API do ODBC `SQLExtendedFetch` no SDK do Windows.

##  <a name="getstatus"></a>CRecordset:: GetStatus

Determina o índice do registro atual no conjunto de registros e se o último registro foi visto.

```
void GetStatus(CRecordsetStatus& rStatus) const;
```

### <a name="parameters"></a>Parâmetros

*rStatus*<br/>
Uma referência a um objeto `CRecordsetStatus`. Consulte a seção Comentários para obter mais informações.

### <a name="remarks"></a>Comentários

`CRecordset` tenta controlar o índice, mas, em algumas circunstâncias, isso pode não ser possível. Consulte [GetRecordCount](#getrecordcount) para obter uma explicação.

A estrutura de `CRecordsetStatus` tem o seguinte formato:

```cpp
struct CRecordsetStatus
{
    long m_lCurrentRecord;
    BOOL m_bRecordCountFinal;
};
```

Os dois membros de `CRecordsetStatus` têm os seguintes significados:

- `m_lCurrentRecord` contém o índice de base zero do registro atual no conjunto de registros, se conhecido. Se o índice não puder ser determinado, esse membro conterá AFX_CURRENT_RECORD_UNDEFINED (-2). Se `IsBOF` for TRUE (conjunto de registros vazio ou tentar rolar antes do primeiro registro), `m_lCurrentRecord` será definido como AFX_CURRENT_RECORD_BOF (-1). Se estiver no primeiro registro, ele será definido como 0, segundo registro 1 e assim por diante.

- `m_bRecordCountFinal` diferente de zero se o número total de registros no conjunto de registros tiver sido determinado. Geralmente, isso deve ser feito iniciando no início do conjunto de registros e chamando `MoveNext` até que `IsEOF` retorne diferente de zero. Se esse membro for zero, a contagem de registros como retornada por `GetRecordCount`, se não for-1, será apenas uma contagem de "marca d' água alta" dos registros.

##  <a name="getsql"></a>CRecordset::GetSQL

Chame essa função de membro para obter a instrução SQL que foi usada para selecionar os registros do conjunto de registros quando ele foi aberto.

```
const CString& GetSQL() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência **const** a um `CString` que contém a instrução SQL.

### <a name="remarks"></a>Comentários

Isso geralmente será uma instrução SQL **Select** . A cadeia de caracteres retornada por `GetSQL` é somente leitura.

A cadeia de caracteres retornada por `GetSQL` normalmente é diferente de qualquer cadeia de caracteres que você possa ter passado para o conjunto de registros no parâmetro *lpszSQL* para a função de membro `Open`. Isso ocorre porque o conjunto de registros constrói uma instrução SQL completa com base no que você passou para `Open`, o que você especificou com ClassWizard, o que você pode ter especificado no `m_strFilter` e `m_strSort` membros de dados e quaisquer parâmetros que você tenha especificado. Para obter detalhes sobre como o conjunto de registros constrói essa instrução SQL, consulte o artigo conjunto de registros [: como os conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

> [!NOTE]
>  Chame essa função de membro somente depois de chamar [Open](#open).

##  <a name="gettablename"></a>CRecordset:: getTableName

Obtém o nome da tabela SQL na qual a consulta do conjunto de registros é baseada.

```
const CString& GetTableName() const;
```

### <a name="return-value"></a>Valor retornado

Uma referência **const** a um `CString` que contém o nome da tabela, se o conjunto de registros for baseado em uma tabela; caso contrário, uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

`GetTableName` só será válida se o conjunto de registros for baseado em uma tabela, não em uma junção de várias tabelas ou em uma consulta predefinida (procedimento armazenado). O nome é somente leitura.

> [!NOTE]
>  Chame essa função de membro somente depois de chamar [Open](#open).

##  <a name="isbof"></a>CRecordset::IsBOF

Retornará zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há registro atual.

```
BOOL IsBOF() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros não contiver nenhum registro ou se você tiver rolado para trás antes do primeiro registro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função de membro antes de rolar de registro para registro para saber se você já passou antes do primeiro registro do conjunto de registros. Você também pode usar `IsBOF` junto com `IsEOF` para determinar se o conjunto de registros contém registros ou se está vazio. Imediatamente depois de chamar `Open`, se o conjunto de registros não contiver nenhum registro, `IsBOF` retornará zero. Quando você abre um conjunto de registros que tem pelo menos um registro, o primeiro registro é o registro atual e `IsBOF` retorna 0.

Se o primeiro registro for o registro atual e você chamar `MovePrev`, `IsBOF` retornará subseqüentemente diferente de zero. Se `IsBOF` retornar zero e você chamar `MovePrev`, ocorrerá um erro. Se `IsBOF` retornar zero, o registro atual será indefinido e qualquer ação que exigir um registro atual resultará em um erro.

### <a name="example"></a>Exemplo

Este exemplo usa `IsBOF` e `IsEOF` para detectar os limites de um conjunto de registros à medida que o código rola pelo conjunto de registros em ambas as direções.

[!code-cpp[NVC_MFCDatabase#25](../../mfc/codesnippet/cpp/crecordset-class_9.cpp)]

##  <a name="isdeleted"></a>CRecordset:: IsDeleted

Determina se o registro atual foi excluído.

```
BOOL IsDeleted() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros estiver posicionado em um registro excluído; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você rolar para um registro e `IsDeleted` retornar TRUE (diferente de zero), você deverá rolar para outro registro antes de executar qualquer outra operação de conjunto de registros.

O resultado de `IsDeleted` depende de muitos fatores, como o tipo do conjunto de registros, se o conjunto de registros é atualizável, se você especificou a opção `CRecordset::skipDeletedRecords` ao abrir o conjunto de registros, se os pacotes de driver excluíram registros e se há vários podem.

Para obter mais informações sobre `CRecordset::skipDeletedRecords` e empacotamento de driver, consulte a função de membro [Open](#open) .

> [!NOTE]
>  Se você tiver implementado a busca de linha em massa, não deverá chamar `IsDeleted`. Em vez disso, chame a função de membro [GetRowStatus](#getrowstatus) . Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="iseof"></a>CRecordset::IsEOF

Retornará zero se o conjunto de registros tiver sido posicionado após o último registro. Não há registro atual.

```
BOOL IsEOF() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros não contiver nenhum registro ou se você tiver rolado para além do último registro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função de membro à medida que você rolar de registro para registro para saber se você ultrapassou o último registro do conjunto de registros. Você também pode usar `IsEOF` para determinar se o conjunto de registros contém registros ou se está vazio. Imediatamente depois de chamar `Open`, se o conjunto de registros não contiver nenhum registro, `IsEOF` retornará zero. Quando você abre um conjunto de registros que tem pelo menos um registro, o primeiro registro é o registro atual e `IsEOF` retorna 0.

Se o último registro for o registro atual quando você chamar `MoveNext`, `IsEOF` retornará subseqüentemente diferente de zero. Se `IsEOF` retornar zero e você chamar `MoveNext`, ocorrerá um erro. Se `IsEOF` retornar zero, o registro atual será indefinido e qualquer ação que exigir um registro atual resultará em um erro.

### <a name="example"></a>Exemplo

Consulte o exemplo de [IsBOF](#isbof).

##  <a name="isfielddirty"></a>CRecordset::IsFieldDirty

Determina se o membro de dados do campo especificado foi alterado desde que [Editar](#edit) ou [AddNew](#addnew) foi chamado.

```
BOOL IsFieldDirty(void* pv);
```

### <a name="parameters"></a>Parâmetros

*PV*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos está sujo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o membro de dados do campo especificado foi alterado desde a chamada de `AddNew` ou `Edit`; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os dados em todos os membros de dados de campo sujos serão transferidos para o registro na fonte de dados quando o registro atual for atualizado por uma chamada para a função de membro de [atualização](#update) de `CRecordset` (seguindo uma chamada para `Edit` ou `AddNew`).

> [!NOTE]
>  Essa função de membro não é aplicável em conjuntos de registros que estão usando a busca de linha em massa. Se você tiver implementado a busca de linha em massa, `IsFieldDirty` sempre retornará FALSE e resultará em uma asserção com falha. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Chamar `IsFieldDirty` redefinirá os efeitos das chamadas anteriores para [SetFieldDirty](#setfielddirty) , uma vez que o status sujo do campo é reavaliado. No caso de `AddNew`, se o valor do campo atual diferir do valor pseudo nulo, o status do campo será definido como sujo. No caso de `Edit`, se o valor do campo for diferente do valor armazenado em cache, o status do campo será definido como sujo.

o `IsFieldDirty` é implementado por meio de [DoFieldExchange](#dofieldexchange).

Para obter mais informações sobre o sinalizador sujo, consulte o artigo conjunto de registros [: como os conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

##  <a name="isfieldnull"></a>CRecordset::IsFieldNull

Retornará zero se o campo especificado no registro atual for nulo (não tem valor).

```
BOOL IsFieldNull(void* pv);
```

### <a name="parameters"></a>Parâmetros

*PV*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos é nulo.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o membro de dados do campo especificado for sinalizado como nulo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame essa função de membro para determinar se o membro de dados de campo especificado de um conjunto de registros foi sinalizado como nulo. (Na terminologia do banco de dados, NULL significa "sem valor" e não é o mesmo que NULL C++em.) Se um membro de dados de campo for sinalizado como nulo, ele será interpretado como uma coluna do registro atual para o qual não há nenhum valor.

> [!NOTE]
>  Essa função de membro não é aplicável em conjuntos de registros que estão usando a busca de linha em massa. Se você tiver implementado a busca de linha em massa, `IsFieldNull` sempre retornará FALSE e resultará em uma asserção com falha. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

o `IsFieldNull` é implementado por meio de [DoFieldExchange](#dofieldexchange).

##  <a name="isfieldnullable"></a>CRecordset::IsFieldNullable

Retornará zero se o campo especificado no registro atual puder ser definido como nulo (sem valor).

```
BOOL IsFieldNullable(void* pv);
```

### <a name="parameters"></a>Parâmetros

*PV*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se qualquer um dos campos pode ser definido como um valor nulo.

### <a name="remarks"></a>Comentários

Chame essa função de membro para determinar se o membro de dados de campo especificado é "Nullable" (pode ser definido como um valor nulo; C++ NULL não é o mesmo que NULL, que, na terminologia do banco de dados, significa "sem valor").

> [!NOTE]
>  Se você tiver implementado a busca de linha em massa, não será possível chamar `IsFieldNullable`. Em vez disso, chame a função de membro [GetODBCFieldInfo](#getodbcfieldinfo) para determinar se um campo pode ser definido como um valor nulo. Observe que você sempre pode chamar `GetODBCFieldInfo`, independentemente se você implementou a busca em massa de linha. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Um campo que não pode ser nulo deve ter um valor. Se você tentar definir um campo como nulo ao adicionar ou atualizar um registro, a fonte de dados rejeitará a adição ou atualização e a [atualização](#update) gerará uma exceção. A exceção ocorre quando você chama `Update`, não quando você chama [SetFieldNull](#setfieldnull).

Usar NULL para o primeiro argumento da função aplicará a função somente para `outputColumn` campos, não `param` campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

definirá somente campos `outputColumn` como nulos; `param` campos não serão afetados.

Para trabalhar em campos de `param`, você deve fornecer o endereço real do `param` individual em que deseja trabalhar, como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que você não pode definir todos os campos de `param` como NULL, como é possível com `outputColumn` campos.

o `IsFieldNullable` é implementado por meio de [DoFieldExchange](#dofieldexchange).

##  <a name="isopen"></a>CRecordset:: IsOpen

Determina se o conjunto de registros já está aberto.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função de membro [Open](#open) ou [Requery](#requery) do objeto Recordset tiver sido chamada anteriormente e o conjunto de registros não tiver sido fechado; caso contrário, 0.

##  <a name="m_hstmt"></a>CRecordset::m_hstmt

Contém um identificador para a estrutura de dados da instrução ODBC, do tipo HSTMT, associado ao conjunto de registros.

### <a name="remarks"></a>Comentários

Cada consulta a uma fonte de dados ODBC é associada a um HSTMT.

> [!CAUTION]
>  Não use `m_hstmt` antes de o [Open](#open) ter sido chamado.

Normalmente, você não precisa acessar o HSTMT diretamente, mas pode precisar dele para a execução direta de instruções SQL. A função membro `ExecuteSQL` da classe `CDatabase` fornece um exemplo de como usar `m_hstmt`.

##  <a name="m_nfields"></a>CRecordset::m_nFields

Contém o número de membros de dados de campo na classe recordset; ou seja, o número de colunas selecionadas pelo conjunto de registros da fonte de dados.

### <a name="remarks"></a>Comentários

O construtor para a classe do conjunto de registros deve inicializar `m_nFields` com o número correto. Se você não tiver implementado a busca de linha em massa, o ClassWizard gravará essa inicialização para você quando você usá-la para declarar a classe do conjunto de registros. Você também pode escrevê-lo manualmente.

A estrutura usa esse número para gerenciar a interação entre os membros de dados de campo e as colunas correspondentes do registro atual na fonte de dados.

> [!CAUTION]
>  Esse número deve corresponder ao número de "colunas de saída" registrado em `DoFieldExchange` ou `DoBulkFieldExchange` após uma chamada para [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) com o parâmetro `CFieldExchange::outputColumn`.

Você pode associar colunas dinamicamente, conforme explicado no artigo "conjunto de registros: vinculação dinâmica de colunas de dados". Se você fizer isso, deverá aumentar a contagem em `m_nFields` para refletir o número de chamadas de função suporte RFX ou suporte RFX em massa em sua `DoFieldExchange` ou `DoBulkFieldExchange` função de membro para as colunas vinculadas dinamicamente.

Para obter mais informações, consulte o [conjunto de registros de artigos: vinculação dinâmica de colunas de dados (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md) e [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

Consulte o artigo [registro de campo Exchange: usando suporte RFX](../../data/odbc/record-field-exchange-using-rfx.md).

##  <a name="m_nparams"></a>CRecordset::m_nParams

Contém o número de membros de dados de parâmetro na classe recordset; ou seja, o número de parâmetros passados com a consulta do conjunto de registros.

### <a name="remarks"></a>Comentários

Se a classe do conjunto de registros tiver quaisquer membros de dados de parâmetro, o construtor para a classe deverá inicializar `m_nParams` com o número correto. O valor de `m_nParams` usa como padrão 0. Se você adicionar membros de dados de parâmetro (que você deve fazer manualmente), também deverá adicionar manualmente uma inicialização no construtor de classe para refletir o número de parâmetros (que deve ser pelo menos tão grande quanto o número de espaços reservados ' ' no `m_strFilter` ou `m_strSort` Cadeia de caracteres).

A estrutura usa esse número quando parametriza a consulta do conjunto de registros.

> [!CAUTION]
>  Esse número deve corresponder ao número de "params" registrado em `DoFieldExchange` ou `DoBulkFieldExchange` após uma chamada para [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) com um valor de parâmetro de `CFieldExchange::inputParam`, `CFieldExchange::param`, `CFieldExchange::outputParam`ou `CFieldExchange::inoutParam`.

### <a name="example"></a>Exemplo

  Consulte o conjunto de registros de artigos [: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) e [gravar campo Exchange: usando suporte RFX](../../data/odbc/record-field-exchange-using-rfx.md).

##  <a name="m_pdatabase"></a>CRecordset::m_pDatabase

Contém um ponteiro para o objeto `CDatabase` por meio do qual o conjunto de registros está conectado a uma fonte de dados.

### <a name="remarks"></a>Comentários

Essa variável é definida de duas maneiras. Normalmente, você passa um ponteiro para um objeto de `CDatabase` já conectado ao construir o objeto Recordset. Se você passar NULL em vez disso, `CRecordset` criará um objeto `CDatabase` para você e o conectará. Em ambos os casos, `CRecordset` armazena o ponteiro nessa variável.

Normalmente, você não precisará usar diretamente o ponteiro armazenado em `m_pDatabase`. No entanto, se você escrever suas próprias extensões para `CRecordset`, talvez seja necessário usar o ponteiro. Por exemplo, talvez você precise do ponteiro se lançar seus próprios `CDBException`s. Ou talvez seja necessário se você precisar fazer algo usando o mesmo objeto `CDatabase`, como executar transações, definir tempos limite ou chamar a função membro `ExecuteSQL` da classe `CDatabase` para executar instruções SQL diretamente.

##  <a name="m_strfilter"></a>CRecordset::m_strFilter

Depois de construir o objeto recordset, mas antes de chamar sua função de membro `Open`, use esse membro de dados para armazenar um `CString` contendo uma cláusula SQL **Where** .

### <a name="remarks"></a>Comentários

O conjunto de registros usa essa cadeia de caracteres para restringir (ou filtrar) os registros que ele seleciona durante a chamada de `Open` ou `Requery`. Isso é útil para selecionar um subconjunto de registros, como "todos os vendedores baseados na Califórnia" ("estado = AC"). A sintaxe ODBC SQL para uma cláusula **Where** é

`WHERE search-condition`

Observe que você não inclui a palavra-chave **Where** em sua cadeia de caracteres. A estrutura fornece a ela.

Você também pode parametrizar sua cadeia de caracteres de filtro colocando os espaços reservados ' ', declarando um membro de dados de parâmetro em sua classe para cada espaço reservado e passando parâmetros para o conjunto de registros em tempo de execução. Isso permite que você construa o filtro em tempo de execução. Para obter mais informações, consulte o artigo [conjunto de registros: parametrizando um conjunto de registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

Para obter mais informações sobre as cláusulas do SQL **Where** , consulte o artigo [SQL](../../data/odbc/sql.md). Para obter mais informações sobre como selecionar e filtrar registros, consulte o artigo conjunto de registros [: filtragem de registros (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#30](../../mfc/codesnippet/cpp/crecordset-class_12.cpp)]

##  <a name="m_strsort"></a>CRecordset::m_strSort

Depois de construir o objeto recordset, mas antes de chamar sua função de membro `Open`, use esse membro de dados para armazenar um `CString` que contém uma cláusula **order by** SQL.

### <a name="remarks"></a>Comentários

O conjunto de registros usa essa cadeia de caracteres para classificar os registros que ele seleciona durante a chamada de `Open` ou `Requery`. Você pode usar esse recurso para classificar um conjunto de registros em uma ou mais colunas. A sintaxe ODBC SQL para uma cláusula **order by** é

`ORDER BY sort-specification [, sort-specification]...`

em que uma especificação de classificação é um nome inteiro ou de coluna. Você também pode especificar ordem crescente ou decrescente (a ordem é ascendente por padrão) acrescentando "ASC" ou "DESC" à lista de colunas na cadeia de caracteres de classificação. Os registros selecionados são classificados primeiro pela primeira coluna listada, depois pelo segundo e assim por diante. Por exemplo, você pode solicitar um conjunto de registros "Customers" por sobrenome e primeiro nome. O número de colunas que você pode listar depende da fonte de dados. Para obter mais informações, consulte a SDK do Windows.

Observe que você não inclui a palavra-chave **order by** em sua cadeia de caracteres. A estrutura fornece a ela.

Para obter mais informações sobre as cláusulas SQL, consulte o artigo [SQL](../../data/odbc/sql.md). Para obter mais informações sobre como classificar registros, consulte o artigo conjunto de registros [: classificando registros (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#31](../../mfc/codesnippet/cpp/crecordset-class_13.cpp)]

##  <a name="move"></a>CRecordset:: mover

Move o ponteiro de registro atual dentro do conjunto de registros, para frente ou para trás.

```
virtual void Move(
    long nRows,
    WORD wFetchType = SQL_FETCH_RELATIVE);
```

### <a name="parameters"></a>Parâmetros

*nRows*<br/>
O número de linhas a serem passadas para frente ou para trás. Os valores positivos avançam para o final do conjunto de registros. Valores negativos se movem para trás, em direção ao início.

*wFetchType*<br/>
Determina o conjunto de linhas que `Move` será buscado. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Se você passar um valor de 0 para *nRows*, `Move` atualizará o registro atual; `Move` encerrará qualquer `AddNew` atual ou modo de `Edit` e restaurará o valor do registro atual antes que `AddNew` ou `Edit` seja chamado.

> [!NOTE]
>  Quando você percorre um conjunto de registros, não pode ignorar os registros excluídos. Consulte [CRecordset:: IsDeleted](#isdeleted) para obter mais informações. Quando você abre um `CRecordset` com a opção `skipDeletedRecords` definida, `Move` afirma se o parâmetro *nRows* é 0. Esse comportamento impede a atualização de linhas que são excluídas por outros aplicativos cliente usando os mesmos dados. Consulte o parâmetro *dwOption* em [abrir](#open) para obter uma descrição de `skipDeletedRecords`.

`Move` reposiciona o conjunto de registros por conjuntos de linhas. Com base nos valores de *nRows* e *wFetchType*, `Move` busca o conjunto de linhas apropriado e, em seguida, torna o primeiro registro nesse conjunto de linhas o registro atual. Se você não tiver implementado a busca de linha em massa, o tamanho do conjunto de linhas será sempre 1. Ao buscar um conjunto de linhas, `Move` chama diretamente a função de membro [CheckRowsetError](#checkrowseterror) para lidar com quaisquer erros resultantes da busca.

Dependendo dos valores que você passa, `Move` é equivalente a outras funções de membro de `CRecordset`. Em particular, o valor de *wFetchType* pode indicar uma função de membro que é mais intuitiva e, geralmente, o método preferencial para mover o registro atual.

A tabela a seguir lista os possíveis valores para *wFetchType*, o conjunto de linhas que `Move` será buscado com base em *wFetchType* e *nRows*e qualquer função de membro equivalente correspondente a *wFetchType*.

|wFetchType|Conjunto de linhas buscado|Função membro equivalente|
|----------------|--------------------|--------------------------------|
|SQL_FETCH_RELATIVE (o valor padrão)|O conjunto de linhas que inicia *nRows* linha (s) da primeira linha no conjunto de linhas atual.||
|SQL_FETCH_NEXT|O próximo conjunto de linhas; *nRows* é ignorado.|[MoveNext](#movenext)|
|SQL_FETCH_PRIOR|O conjunto de linhas anterior; *nRows* é ignorado.|[MovePrev](#moveprev)|
|SQL_FETCH_FIRST|O primeiro conjunto de linhas no conjunto de registros; *nRows* é ignorado.|[MoveFirst](#movefirst)|
|SQL_FETCH_LAST|O último conjunto de linhas completo no conjunto de registros; *nRows* é ignorado.|[Velas](#movelast)|
|SQL_FETCH_ABSOLUTE|Se *nRows* > 0, o conjunto de linhas iniciando *nRows* linha (s) desde o início do conjunto de registros. Se *nRows* < 0, o conjunto de linhas iniciando *nRows* linha (s) a partir do final do conjunto de registros. Se *nRows* = 0, uma condição de início de arquivo (BOF) será retornada.|[SetAbsolutePosition](#setabsoluteposition)|
|SQL_FETCH_BOOKMARK|O conjunto de linhas que começa na linha cujo valor de indicador corresponde a *nRows*.|[SetBookmark](#setbookmark)|

> [!NOTE]
>  Para conjuntos de registros somente de encaminhamento, `Move` só é válida com um valor de SQL_FETCH_NEXT para *wFetchType*.

> [!CAUTION]
>  Chamar `Move` gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem algum registro, chame [IsBOF](#isbof) e [IsEOF](#iseof).

> [!NOTE]
>  Se você tiver rolado para cima do início ou término do conjunto de registros (`IsBOF` ou `IsEOF` retorna zero), chamar uma função `Move` poderá gerar um `CDBException`. Por exemplo, se `IsEOF` retornar zero e `IsBOF` não for, `MoveNext` gerará uma exceção, mas `MovePrev` não.

> [!NOTE]
>  Se você chamar `Move` enquanto o registro atual está sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre a navegação do conjunto de registros, consulte os artigos [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter informações relacionadas, consulte a função da API do ODBC `SQLExtendedFetch` no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#28](../../mfc/codesnippet/cpp/crecordset-class_14.cpp)]

##  <a name="movefirst"></a>CRecordset:: MoveFirst

Faz com que o primeiro registro no primeiro conjunto de linhas seja o registro atual.

```
void MoveFirst();
```

### <a name="remarks"></a>Comentários

Independentemente de a busca de linha em massa ter sido implementada, esse será sempre o primeiro registro no conjunto de registros.

Você não precisa chamar `MoveFirst` imediatamente depois de abrir o conjunto de registros. Nesse momento, o primeiro registro (se houver) é automaticamente o registro atual.

> [!NOTE]
>  Esta função de membro não é válida para conjuntos de registros somente de encaminhamento.

> [!NOTE]
>  Quando você percorre um conjunto de registros, não pode ignorar os registros excluídos. Consulte a função membro [IsDeleted](#isdeleted) para obter detalhes.

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem algum registro, chame `IsBOF` e `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre a navegação do conjunto de registros, consulte os artigos [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [IsBOF](#isbof).

##  <a name="movelast"></a>CRecordset:: MoveLast

Faz com que o primeiro registro no último conjunto de linhas completo seja o registro atual.

```
void MoveLast();
```

### <a name="remarks"></a>Comentários

Se você não tiver implementado a busca de linha em massa, o conjunto de registros terá um tamanho de conjunto de linhas de 1, portanto `MoveLast` simplesmente se moverá para o último registro no conjunto de registros.

> [!NOTE]
>  Esta função de membro não é válida para conjuntos de registros somente de encaminhamento.

> [!NOTE]
>  Quando você percorre um conjunto de registros, não pode ignorar os registros excluídos. Consulte a função membro [IsDeleted](#isdeleted) para obter detalhes.

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem algum registro, chame `IsBOF` e `IsEOF`.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre a navegação do conjunto de registros, consulte os artigos [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [IsBOF](#isbof).

##  <a name="movenext"></a>CRecordset:: MoveNext

Faz com que o primeiro registro no próximo conjunto de linhas seja o registro atual.

```
void MoveNext();
```

### <a name="remarks"></a>Comentários

Se você não tiver implementado a busca de linha em massa, o conjunto de registros terá um tamanho de conjunto de linhas de 1, portanto `MoveNext` simplesmente se moverá para o próximo registro.

> [!NOTE]
>  Quando você percorre um conjunto de registros, não pode ignorar os registros excluídos. Consulte a função membro [IsDeleted](#isdeleted) para obter detalhes.

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem algum registro, chame `IsBOF` e `IsEOF`.

> [!NOTE]
>  Também é recomendável chamar `IsEOF` antes de chamar `MoveNext`. Por exemplo, se você tiver rolado após o final do conjunto de registros, `IsEOF` retornará diferente de zero; uma chamada subsequente para `MoveNext` geraria uma exceção.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre a navegação do conjunto de registros, consulte os artigos [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [IsBOF](#isbof).

##  <a name="moveprev"></a>CRecordset::MovePrev

Torna o primeiro registro no conjunto de linhas anterior o registro atual.

```
void MovePrev();
```

### <a name="remarks"></a>Comentários

Se você não tiver implementado a busca de linha em massa, o conjunto de registros terá um tamanho de conjunto de linhas de 1, portanto `MovePrev` simplesmente se moverá para o registro anterior.

> [!NOTE]
>  Esta função de membro não é válida para conjuntos de registros somente de encaminhamento.

> [!NOTE]
>  Quando você percorre um conjunto de registros, não pode ignorar os registros excluídos. Consulte a função membro [IsDeleted](#isdeleted) para obter detalhes.

> [!CAUTION]
>  Chamar qualquer uma das funções de `Move` gera uma exceção se o conjunto de registros não tem registros. Para determinar se o conjunto de registros tem algum registro, chame `IsBOF` e `IsEOF`.

> [!NOTE]
>  Também é recomendável chamar `IsBOF` antes de chamar `MovePrev`. Por exemplo, se você tiver rolado para frente do início do conjunto de registros, `IsBOF` retornará diferente de zero; uma chamada subsequente para `MovePrev` geraria uma exceção.

> [!NOTE]
>  Se você chamar qualquer uma das funções de `Move` enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso.

Para obter mais informações sobre a navegação do conjunto de registros, consulte os artigos [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Consulte o exemplo de [IsBOF](#isbof).

##  <a name="onsetoptions"></a>CRecordset::OnSetOptions

Chamado para definir opções (usadas na seleção) para a instrução ODBC especificada.

```
virtual void OnSetOptions(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*hstmt*<br/>
O HSTMT da instrução ODBC cujas opções devem ser definidas.

### <a name="remarks"></a>Comentários

Chame `OnSetOptions` para definir opções (usadas na seleção) para a instrução ODBC especificada. A estrutura chama essa função de membro para definir as opções iniciais do conjunto de registros. `OnSetOptions` determina o suporte da fonte de dados para cursores roláveis e para a simultaneidade do cursor e define as opções do conjunto de registros de acordo. (Enquanto `OnSetOptions` é usado para operações de seleção, `OnSetUpdateOptions` é usado para operações de atualização.)

Substitua `OnSetOptions` para definir opções específicas para o driver ou a fonte de dados. Por exemplo, se a fonte de dados der suporte à abertura para acesso exclusivo, você poderá substituir `OnSetOptions` para aproveitar essa capacidade.

Para obter mais informações sobre cursores, consulte o artigo [ODBC](../../data/odbc/odbc-basics.md).

##  <a name="onsetupdateoptions"></a>CRecordset::OnSetUpdateOptions

Chamado para definir opções (usadas na atualização) para a instrução ODBC especificada.

```
virtual void OnSetUpdateOptions(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*hstmt*<br/>
O HSTMT da instrução ODBC cujas opções devem ser definidas.

### <a name="remarks"></a>Comentários

Chame `OnSetUpdateOptions` para definir opções (usadas na atualização) para a instrução ODBC especificada. A estrutura chama essa função de membro depois de criar um HSTMT para atualizar registros em um conjunto de registros. (Enquanto `OnSetOptions` é usado para operações de seleção, `OnSetUpdateOptions` é usado para operações de atualização.) `OnSetUpdateOptions` determina o suporte da fonte de dados para cursores roláveis e para a simultaneidade do cursor e define as opções do conjunto de registros de acordo.

Substitua `OnSetUpdateOptions` para definir opções de uma instrução ODBC antes que essa instrução seja usada para acessar um banco de dados.

Para obter mais informações sobre cursores, consulte o artigo [ODBC](../../data/odbc/odbc-basics.md).

##  <a name="open"></a>CRecordset:: abrir

Abre o conjunto de registros recuperando a tabela ou executando a consulta que o conjunto de registros representa.

```
virtual BOOL Open(
    UINT nOpenType = AFX_DB_USE_DEFAULT_TYPE,
    LPCTSTR lpszSQL = NULL,
    DWORD dwOptions = none);
```

### <a name="parameters"></a>Parâmetros

*nOpenType*<br/>
Aceite o valor padrão, AFX_DB_USE_DEFAULT_TYPE, ou use um dos seguintes valores do `enum OpenType`:

- `CRecordset::dynaset` um conjunto de registros com rolagem bidirecional. A associação e a ordenação dos registros são determinadas quando o conjunto de registros é aberto, mas as alterações feitas por outros usuários nos valores de dados são visíveis após uma operação de busca. Os dynasets também são conhecidos como conjuntos de registros controlados por conjunto de chaves.

- `CRecordset::snapshot` um conjunto de registros estático com rolagem bidirecional. A associação e a ordenação dos registros são determinadas quando o conjunto de registros é aberto; os valores de dados são determinados quando os registros são buscados. As alterações feitas por outros usuários não ficam visíveis até que o conjunto de registros seja fechado e, em seguida, reaberto.

- `CRecordset::dynamic` um conjunto de registros com rolagem bidirecional. As alterações feitas por outros usuários nos valores de associação, ordenação e dados são visíveis após uma operação de busca. Observe que muitos drivers ODBC não dão suporte a esse tipo de conjunto de registros.

- `CRecordset::forwardOnly` um conjunto de registros somente leitura com somente rolagem de encaminhamento.

   Por `CRecordset`, o valor padrão é `CRecordset::snapshot`. O mecanismo de valor padrão permite que os C++ assistentes do Visual interajam com os `CDaoRecordset`ODBC `CRecordset` e DAO, que têm padrões diferentes.

Para obter mais informações sobre esses tipos de conjuntos de registros, consulte o artigo [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md). Para obter informações relacionadas, consulte o artigo "usando cursores de bloco e rolável" na SDK do Windows.

> [!CAUTION]
>  Se o tipo solicitado não for suportado, a estrutura lançará uma exceção.

*lpszSQL*<br/>
Um ponteiro de cadeia de caracteres que contém um dos seguintes:

- Um ponteiro nulo.

- O nome de uma tabela.

- Uma instrução SQL **Select** (opcionalmente com uma cláusula SQL **Where** ou **order by** ).

- Uma instrução de **chamada** especificando o nome de uma consulta predefinida (procedimento armazenado). Tenha cuidado para não inserir espaço em branco entre as chaves e a palavra-chave **Call** .

Para obter mais informações sobre essa cadeia de caracteres, consulte a tabela e a discussão da função do ClassWizard na seção [comentários](#remarks) .

> [!NOTE]
>  A ordem das colunas em seu conjunto de resultados deve corresponder à ordem das chamadas de função suporte RFX ou suporte RFX em massa na substituição da função [DoFieldExchange](#dofieldexchange) ou [DoBulkFieldExchange](#dobulkfieldexchange) .

*dwOptions*<br/>
Um bitmask que pode especificar uma combinação dos valores listados abaixo. Alguns deles são mutuamente exclusivos. O valor padrão é **None**.

- Não `CRecordset::none` conjunto de opções. Esse valor de parâmetro é mutuamente exclusivo com todos os outros valores. Por padrão, o conjunto de registros pode ser atualizado com [Editar](#edit) ou [excluir](#delete) e permite anexar novos registros com [AddNew](#addnew). A capacidade de atualização depende da fonte de dados, bem como da opção *nOpenType* que você especificar. A otimização para adições em massa não está disponível. A busca de linha em massa não será implementada. Os registros excluídos não serão ignorados durante a navegação do conjunto de registros. Indicadores não estão disponíveis. A verificação automática de campo sujo é implementada.

- `CRecordset::appendOnly` não permitir `Edit` ou `Delete` no conjunto de registros. Permitir somente `AddNew`. Essa opção é mutuamente exclusiva com `CRecordset::readOnly`.

- `CRecordset::readOnly` abrir o conjunto de registros como somente leitura. Essa opção é mutuamente exclusiva com `CRecordset::appendOnly`.

- `CRecordset::optimizeBulkAdd` usar uma instrução SQL preparada para otimizar a adição de vários registros ao mesmo tempo. Aplica-se somente se você não estiver usando a função da API do ODBC `SQLSetPos` para atualizar o conjunto de registros. A primeira atualização determina quais campos são marcados com problemas. Essa opção é mutuamente exclusiva com `CRecordset::useMultiRowFetch`.

- `CRecordset::useMultiRowFetch` implementar a busca em massa de linha para permitir que várias linhas sejam recuperadas em uma única operação de busca. Esse é um recurso avançado projetado para melhorar o desempenho; no entanto, a troca de campo de registro em massa não é suportada pelo ClassWizard. Essa opção é mutuamente exclusiva com `CRecordset::optimizeBulkAdd`. Observe que, se você especificar `CRecordset::useMultiRowFetch`, a opção `CRecordset::noDirtyFieldCheck` será ativada automaticamente (o buffer duplo não estará disponível); em conjuntos de registros somente de encaminhamento, a opção `CRecordset::useExtendedFetch` será ativada automaticamente. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

- `CRecordset::skipDeletedRecords` ignorar todos os registros excluídos ao navegar pelo conjunto de registros. Isso reduzirá o desempenho em determinadas buscas relativas. Essa opção não é válida em conjuntos de registros somente de encaminhamento. Se você chamar [move](#move) com o parâmetro *nRows* definido como 0 e a opção `CRecordset::skipDeletedRecords` definida, `Move` será declarado. Observe que `CRecordset::skipDeletedRecords` é semelhante ao *empacotamento de driver*, o que significa que as linhas excluídas são removidas do conjunto de registros. No entanto, se os pacotes de driver forem registros, ele ignorará apenas os registros que você excluir; Ele não ignorará os registros excluídos por outros usuários enquanto o conjunto de registros estiver aberto. `CRecordset::skipDeletedRecords` irá ignorar linhas excluídas por outros usuários.

- `CRecordset::useBookmarks` pode usar indicadores no conjunto de registros, se houver suporte. Os indicadores são lentos para recuperação de dados, mas melhoram o desempenho para navegação de dados. Não é válido em conjuntos de registros somente de encaminhamento. Para obter mais informações, consulte o artigo [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

- `CRecordset::noDirtyFieldCheck` desativar a verificação automática de campo sujo (buffer duplo). Isso irá melhorar o desempenho; no entanto, você deve marcar manualmente os campos como sujos chamando as funções de membro `SetFieldDirty` e `SetFieldNull`. Observe que o buffer duplo na classe `CRecordset` é semelhante ao buffer duplo na `CDaoRecordset`de classe. No entanto, no `CRecordset`, não é possível habilitar o buffer duplo em campos individuais; Habilite-o para todos os campos ou desabilite-o para todos os campos. Observe que, se você especificar a opção `CRecordset::useMultiRowFetch`, `CRecordset::noDirtyFieldCheck` será ativado automaticamente; no entanto, `SetFieldDirty` e `SetFieldNull` não podem ser usados em conjuntos de registros que implementam busca de linha em massa.

- `CRecordset::executeDirect` não usar uma instrução SQL preparada. Para melhorar o desempenho, especifique essa opção se a função de membro de `Requery` nunca será chamada.

- `CRecordset::useExtendedFetch` implementar `SQLExtendedFetch` em vez de `SQLFetch`. Isso é projetado para implementar a busca em massa de linha em conjuntos de registros somente de encaminhamento. Se você especificar a opção `CRecordset::useMultiRowFetch` em um conjunto de registros somente de encaminhamento, `CRecordset::useExtendedFetch` será ativado automaticamente.

- `CRecordset::userAllocMultiRowBuffers` o usuário irá alocar buffers de armazenamento para os dados. Use essa opção em conjunto com `CRecordset::useMultiRowFetch` se você quiser alocar seu próprio armazenamento; caso contrário, a estrutura alocará automaticamente o armazenamento necessário. Para obter mais informações, consulte o artigo [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Observe que especificar `CRecordset::userAllocMultiRowBuffers` sem especificar `CRecordset::useMultiRowFetch` resultará em uma asserção com falha.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto de `CRecordset` foi aberto com êxito; caso contrário, 0 se [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open) (se chamado) retornar 0.

### <a name="remarks"></a>Comentários

Você deve chamar essa função de membro para executar a consulta definida pelo conjunto de registros. Antes de chamar `Open`, você deve construir o objeto Recordset.

A conexão desse conjunto de registros com a fonte de dados depende de como você constrói o conjunto de registros antes de chamar `Open`. Se você passar um objeto [CDatabase](../../mfc/reference/cdatabase-class.md) para o Construtor Recordset que não foi conectado à fonte de dados, essa função de membro usará [GetDefaultConnect](#getdefaultconnect) para tentar abrir o objeto Database. Se você passar NULL para o construtor do conjunto de registros, o Construtor construirá um objeto `CDatabase` para você e `Open` tentará conectar o objeto de banco de dados. Para obter detalhes sobre como fechar o conjunto de registros e a conexão sob essas diversas circunstâncias, consulte [fechar](#close).

> [!NOTE]
>  O acesso a uma fonte de dados por meio de um objeto `CRecordset` é sempre compartilhado. Ao contrário da classe `CDaoRecordset`, você não pode usar um objeto `CRecordset` para abrir uma fonte de dados com acesso exclusivo.

Quando você chama `Open`, uma consulta, geralmente uma instrução SQL **Select** , seleciona registros com base nos critérios mostrados na tabela a seguir.

|Valor do parâmetro lpszSQL|Os registros selecionados são determinados por|Exemplo|
|------------------------------------|----------------------------------------|-------------|
|NULL|A cadeia de caracteres retornada por `GetDefaultSQL`.||
|Nome da tabela SQL|Todas as colunas da tabela-List em `DoFieldExchange` ou `DoBulkFieldExchange`.|`"Customer"`|
|Nome da consulta predefinida (procedimento armazenado)|As colunas que a consulta está definida para retornar.|`"{call OverDueAccts}"`|
|**Selecione** a lista **de colunas na lista de** tabelas|As colunas especificadas das tabelas especificadas.|`"SELECT CustId, CustName FROM`<br /><br /> `Customer"`|

> [!CAUTION]
>  Tenha cuidado para não inserir espaço em branco extra na sua cadeia de caracteres SQL. Por exemplo, se você inserir espaço em branco entre as chaves e a palavra-chave **Call** , o MFC irá misinterpret a cadeia de caracteres SQL como um nome de tabela e incorporá-la a uma instrução **Select** , o que resultará em uma exceção sendo gerada. Da mesma forma, se sua consulta predefinida usar um parâmetro de saída, não insira o espaço em branco entre as chaves e o símbolo ' '. Por fim, você não deve inserir espaço em branco antes da chave em uma instrução **Call** ou antes da palavra-chave **Select** em uma instrução **Select** .

O procedimento habitual é passar NULL para `Open`; Nesse caso, `Open` chama [GetDefaultSQL](#getdefaultsql). Se você estiver usando uma classe de `CRecordset` derivada, `GetDefaultSQL` fornecerá os nomes de tabela especificados em ClassWizard. Em vez disso, você pode especificar outras informações no parâmetro `lpszSQL`.

Seja qual for a sua passagem, `Open` construirá uma cadeia de caracteres SQL final para a consulta (a cadeia de caracteres poderá ter as cláusulas SQL **Where** e **order by** anexadas à cadeia de caracteres de `lpszSQL` que você aprovou) e, em seguida, executará a consulta. Você pode examinar a cadeia de caracteres construída chamando [GetSQL](#getsql) depois de chamar `Open`. Para obter detalhes adicionais sobre como o conjunto de registros constrói uma instrução SQL e seleciona registros, consulte o artigo conjunto de registros [: como os conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

Os membros de dados de campo da classe do conjunto de registros estão associados às colunas dos dados selecionados. Se qualquer registro for retornado, o primeiro registro se tornará o registro atual.

Se você quiser definir opções para o conjunto de registros, como um filtro ou uma classificação, especifique-os depois de construir o objeto recordset, mas antes de chamar `Open`. Se você quiser atualizar os registros no conjunto de registros depois que o conjunto de registros já estiver aberto, chame [Requery](#requery).

Para obter mais informações, incluindo exemplos adicionais, consulte o [conjunto de registros de artigos (ODBC)](../../data/odbc/recordset-odbc.md), conjunto de registros [: como os conjuntos de registros selecionam registros (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)e conjunto de registros [: Criando e fechando conjuntos de registros (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

### <a name="example"></a>Exemplo

Os exemplos de código a seguir mostram diferentes formas da chamada `Open`.

[!code-cpp[NVC_MFCDatabase#16](../../mfc/codesnippet/cpp/crecordset-class_15.cpp)]

##  <a name="refreshrowset"></a>CRecordset::RefreshRowset

Atualiza os dados e o status de uma linha no conjunto de linhas atual.

```
void RefreshRowset(
    WORD wRow,
    WORD wLockType = SQL_LOCK_NO_CHANGE);
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A posição de uma linha baseada em um no conjunto de linhas atual. Esse valor pode variar de zero até o tamanho do conjunto de linhas.

*wLockType*<br/>
Um valor que indica como bloquear a linha depois de ser atualizada. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Se você passar um valor zero para *wRow*, todas as linhas no conjunto de linhas serão atualizadas.

Para usar `RefreshRowset`, você deve ter implementado a busca de linha em massa especificando a opção `CRecordset::useMulitRowFetch` na função de membro [abrir](#open) .

`RefreshRowset` chama a função de API do ODBC `SQLSetPos`. O parâmetro *wLockType* especifica o estado de bloqueio da linha depois que `SQLSetPos` foi executado. A tabela a seguir descreve os valores possíveis para *wLockType*.

|wLockType|Descrição|
|---------------|-----------------|
|SQL_LOCK_NO_CHANGE (o valor padrão)|O driver ou a fonte de dados garante que a linha esteja no mesmo estado bloqueado ou desbloqueado, uma vez que o `RefreshRowset` foi chamado.|
|SQL_LOCK_EXCLUSIVE|O driver ou a fonte de dados bloqueia a linha exclusivamente. Nem todas as fontes de dados dão suporte a esse tipo de bloqueio.|
|SQL_LOCK_UNLOCK|O driver ou a fonte de dados desbloqueia a linha. Nem todas as fontes de dados dão suporte a esse tipo de bloqueio.|

Para obter mais informações sobre `SQLSetPos`, consulte a SDK do Windows. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="requery"></a>CRecordset:: Requery

Recria (atualiza) um conjunto de registros.

```
virtual BOOL Requery();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o conjunto de registros foi recriado com êxito; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se qualquer registro for retornado, o primeiro registro se tornará o registro atual.

Para que o conjunto de registros reflita as adições e exclusões que você ou outros usuários estão fazendo na fonte de dados, você deve recompilar o conjunto de registros chamando `Requery`. Se o conjunto de registros for um dynaset, ele refletirá automaticamente as atualizações que você ou outros usuários fazem em seus registros existentes (mas não em adições). Se o conjunto de registros for um instantâneo, você deverá chamar `Requery` para refletir edições por outros usuários, bem como adições e exclusões.

Para um dynaset ou um instantâneo, chame `Requery` sempre que desejar recriar o conjunto de registros usando um novo filtro ou classificação, ou novos valores de parâmetro. Defina a nova propriedade de filtro ou de classificação atribuindo novos valores a `m_strFilter` e `m_strSort` antes de chamar `Requery`. Defina novos parâmetros atribuindo novos valores aos membros de dados de parâmetro antes de chamar `Requery`. Se as cadeias de caracteres de filtro e classificação estiverem inalteradas, você poderá reutilizar a consulta, o que melhora o desempenho.

Se a tentativa de recriar o conjunto de registros falhar, o conjunto de registros será fechado. Antes de chamar `Requery`, você pode determinar se o conjunto de registros pode ser consultado chamando a função membro `CanRestart`. `CanRestart` não garante que `Requery` terá sucesso.

> [!CAUTION]
>  Chame `Requery` somente depois de ter chamado [abrir](#open).

### <a name="example"></a>Exemplo

Este exemplo recria um conjunto de registros para aplicar uma ordem de classificação diferente.

[!code-cpp[NVC_MFCDatabase#29](../../mfc/codesnippet/cpp/crecordset-class_16.cpp)]

##  <a name="setabsoluteposition"></a>CRecordset::SetAbsolutePosition

Posiciona o conjunto de registros no registro correspondente ao número de registro especificado.

```
void SetAbsolutePosition(long nRows);
```

### <a name="parameters"></a>Parâmetros

*nRows*<br/>
A posição ordinal com base em um para o registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

`SetAbsolutePosition` move o ponteiro de registro atual com base nessa posição ordinal.

> [!NOTE]
>  Esta função de membro não é válida em conjuntos de registros somente de encaminhamento.

Para conjuntos de registros ODBC, uma configuração de posição absoluta de 1 refere-se ao primeiro registro no conjunto de registros; uma configuração de 0 refere-se à posição de início de arquivo (BOF).

Você também pode passar valores negativos para `SetAbsolutePosition`. Nesse caso, a posição do conjunto de registros é avaliada a partir do final do conjunto de registros. Por exemplo, `SetAbsolutePosition( -1 )` move o ponteiro de registro atual para o último registro no conjunto de registros.

> [!NOTE]
>  A posição absoluta não deve ser usada como um número de registro substituto. Os indicadores ainda são a maneira recomendada de reter e retornar a uma determinada posição, já que a posição de um registro é alterada quando registros anteriores são excluídos. Além disso, você não pode ter certeza de que um determinado registro terá a mesma posição absoluta se o conjunto de registros for recriado novamente porque a ordem dos registros individuais em um conjunto de registros não é garantida, a menos que ele seja criado com uma instrução SQL usando um **order by** cláusula.

Para obter mais informações sobre a navegação do conjunto de registros e indicadores, consulte os artigos [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

##  <a name="setbookmark"></a>CRecordset:: SetBookmark

Posiciona o conjunto de registros no registro que contém o indicador especificado.

```
void SetBookmark(const CDBVariant& varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Uma referência a um objeto [CDBVariant](../../mfc/reference/cdbvariant-class.md) que contém o valor de indicador para um registro específico.

### <a name="remarks"></a>Comentários

Para determinar se há suporte para indicadores no conjunto de registros, chame [CanBookmark](#canbookmark). Para disponibilizar indicadores, se houver suporte, você deverá definir a opção `CRecordset::useBookmarks` no parâmetro *dwOptions* da função de membro [Open](#open) .

> [!NOTE]
>  Se os indicadores não forem compatíveis ou estiverem indisponíveis, chamar `SetBookmark` resultará na geração de uma exceção. Não há suporte para indicadores em conjuntos de registros somente de encaminhamento.

Para recuperar primeiro o indicador para o registro atual, chame [GetBookmark](#getbookmark), que salva o valor do indicador em um objeto `CDBVariant`. Posteriormente, você pode retornar a esse registro chamando `SetBookmark` usando o valor de indicador salvo.

> [!NOTE]
>  Após determinadas operações de conjunto de registros, você deve verificar a persistência do indicador antes de chamar `SetBookmark`. Por exemplo, se você recuperar um indicador com `GetBookmark` e, em seguida, chamar `Requery`, o indicador poderá não ser mais válido. Chame [CDatabase:: GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se você pode chamar `SetBookmark`com segurança.

Para obter mais informações sobre indicadores e a navegação do conjunto de registros, consulte o conjunto de registros de artigos [: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [conjunto de registros: rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

##  <a name="setfielddirty"></a>CRecordset::SetFieldDirty

Sinaliza um membro de dados de campo do conjunto de registros como alterado ou inalterado.

```
void SetFieldDirty(void* pv, BOOL bDirty = TRUE);
```

### <a name="parameters"></a>Parâmetros

*PV*<br/>
Contém o endereço de um membro de dados de campo no conjunto de registros ou nulo. Se for NULL, todos os membros de dados de campo no conjunto de registros serão sinalizados. (C++ NULL não é o mesmo que NULL na terminologia do banco de dados, o que significa "sem valor".)

*bDirty*<br/>
TRUE se o membro de dados de campo for sinalizado como "sujo" (alterado). Caso contrário, FALSE se o membro de dados de campo for sinalizado como "limpo" (inalterado).

### <a name="remarks"></a>Comentários

Marcar campos como inalterados garante que o campo não seja atualizado e resulte em menos tráfego SQL.

> [!NOTE]
>  Essa função de membro não é aplicável em conjuntos de registros que estão usando a busca de linha em massa. Se você tiver implementado a busca de linha em massa, `SetFieldDirty` resultará em uma asserção com falha. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

A estrutura marca os membros de dados de campo alterados para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo de troca de campo de registro (suporte RFX). A alteração do valor de um campo geralmente define o campo sujo automaticamente, portanto, raramente será necessário chamar `SetFieldDirty` você mesmo, mas às vezes você desejará garantir que as colunas sejam explicitamente atualizadas ou inseridas, independentemente de qual valor está nos dados do campo associado.

> [!CAUTION]
>  Chame essa função de membro somente depois de ter chamado [Editar](#edit) ou [AddNew](#addnew).

Usar NULL para o primeiro argumento da função aplicará a função somente para `outputColumn` campos, não `param` campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

definirá somente campos `outputColumn` como nulos; `param` campos não serão afetados.

Para trabalhar em campos de `param`, você deve fornecer o endereço real do `param` individual em que deseja trabalhar, como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que você não pode definir todos os campos de `param` como NULL, como é possível com `outputColumn` campos.

##  <a name="setfieldnull"></a>CRecordset::SetFieldNull

Sinaliza um membro de dados de campo do conjunto de registros como nulo (especificamente sem valor) ou como não nulo.

```
void SetFieldNull(void* pv, BOOL bNull = TRUE);
```

### <a name="parameters"></a>Parâmetros

*PV*<br/>
Contém o endereço de um membro de dados de campo no conjunto de registros ou nulo. Se for NULL, todos os membros de dados de campo no conjunto de registros serão sinalizados. (C++ NULL não é o mesmo que NULL na terminologia do banco de dados, o que significa "sem valor".)

*bNull*<br/>
Diferente de zero se o membro de dados de campo for sinalizado como sem valor (nulo). Caso contrário, 0 se o membro de dados do campo for sinalizado como não nulo.

### <a name="remarks"></a>Comentários

Quando você adiciona um novo registro a um conjunto de registros, todos os membros de dados de campo são inicialmente definidos como um valor nulo e sinalizados como "sujos" (alterados). Quando você recupera um registro de uma fonte de dados, suas colunas já têm valores ou são nulas.

> [!NOTE]
>  Não chame essa função de membro em conjuntos de registros que estejam usando a busca de linha em massa. Se você tiver implementado a busca de linha em massa, chamar `SetFieldNull` resultará em uma asserção com falha. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Se você quiser especificamente designar um campo do registro atual como não tendo um valor, chame `SetFieldNull` com *bNull* definido como true para sinalizá-lo como nulo. Se um campo tiver sido marcado como nulo anteriormente e você quiser dar a ele um valor, basta definir seu novo valor. Não é necessário remover o sinalizador nulo com `SetFieldNull`. Para determinar se o campo pode ser nulo, chame `IsFieldNullable`.

> [!CAUTION]
>  Chame essa função de membro somente depois de ter chamado [Editar](#edit) ou [AddNew](#addnew).

Usar NULL para o primeiro argumento da função aplicará a função somente para `outputColumn` campos, não `param` campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

definirá somente campos `outputColumn` como nulos; `param` campos não serão afetados.

Para trabalhar em campos de `param`, você deve fornecer o endereço real do `param` individual em que deseja trabalhar, como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que você não pode definir todos os campos de `param` como NULL, como é possível com `outputColumn` campos.

> [!NOTE]
>  Ao definir parâmetros como NULL, uma chamada para `SetFieldNull` antes que o conjunto de registros seja aberto resulta em uma asserção. Nesse caso, chame [SetParamNull](#setparamnull).

o `SetFieldNull` é implementado por meio de [DoFieldExchange](#dofieldexchange).

##  <a name="setlockingmode"></a>CRecordset:: setlockmode

Define o modo de bloqueio como bloqueio "otimista" (o padrão) ou o bloqueio "pessimista". Determina como os registros são bloqueados para atualizações.

```
void SetLockingMode(UINT nMode);
```

### <a name="parameters"></a>Parâmetros

*nMode*<br/>
Contém um dos seguintes valores do `enum LockMode`:

- `optimistic` bloqueio otimista bloqueia o registro que está sendo atualizado somente durante a chamada para `Update`.

- `pessimistic` bloqueio pessimista bloqueia o registro assim que `Edit` é chamado e o mantém bloqueado até que a chamada de `Update` seja concluída ou você passe para um novo registro.

### <a name="remarks"></a>Comentários

Chame essa função de membro se você precisar especificar quais das duas estratégias de bloqueio de registro o conjunto de registros está usando para atualizações. Por padrão, o modo de bloqueio de um conjunto de registros é `optimistic`. Você pode alterar isso para uma estratégia de bloqueio de `pessimistic` com mais cuidado. Chame `SetLockingMode` depois de construir e abrir o objeto recordset, mas antes de chamar `Edit`.

##  <a name="setparamnull"></a>CRecordset::SetParamNull

Sinaliza um parâmetro como nulo (especificamente sem valor) ou como não nulo.

```
void SetParamNull(
    int nIndex,
    BOOL bNull = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do parâmetro.

*bNull*<br/>
Se for TRUE (o valor padrão), o parâmetro será sinalizado como NULL. Caso contrário, o parâmetro será sinalizado como não nulo.

### <a name="remarks"></a>Comentários

Ao contrário de [SetFieldNull](#setfieldnull), você pode chamar `SetParamNull` antes de abrir o conjunto de registros.

`SetParamNull` normalmente é usado com consultas predefinidas (procedimentos armazenados).

##  <a name="setrowsetcursorposition"></a>CRecordset::SetRowsetCursorPosition

Move o cursor para uma linha dentro do conjunto de linhas atual.

```
void SetRowsetCursorPosition(WORD wRow, WORD wLockType = SQL_LOCK_NO_CHANGE);
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A posição de uma linha baseada em um no conjunto de linhas atual. Esse valor pode variar de 1 até o tamanho do conjunto de linhas.

*wLockType*<br/>
Valor que indica como bloquear a linha após sua atualização. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Ao implementar a busca de linha em massa, os registros são recuperados por conjuntos de linhas, onde o primeiro registro no conjunto de linhas buscado é o registro atual. Para fazer com que outro registro no conjunto de linhas seja o registro atual, chame `SetRowsetCursorPosition`. Por exemplo, você pode combinar `SetRowsetCursorPosition` com a função membro [GetFieldValue](#getfieldvalue) para recuperar dinamicamente os dados de qualquer registro do conjunto de registros.

Para usar `SetRowsetCursorPosition`, você deve ter implementado a busca de linha em massa especificando a opção `CRecordset::useMultiRowFetch` do parâmetro *dwOptions* na função de membro [Open](#open) .

`SetRowsetCursorPosition` chama a função de API do ODBC `SQLSetPos`. O parâmetro *wLockType* especifica o estado de bloqueio da linha depois que `SQLSetPos` foi executado. A tabela a seguir descreve os valores possíveis para *wLockType*.

|wLockType|Descrição|
|---------------|-----------------|
|SQL_LOCK_NO_CHANGE (o valor padrão)|O driver ou a fonte de dados garante que a linha esteja no mesmo estado bloqueado ou desbloqueado, uma vez que o `SetRowsetCursorPosition` foi chamado.|
|SQL_LOCK_EXCLUSIVE|O driver ou a fonte de dados bloqueia a linha exclusivamente. Nem todas as fontes de dados dão suporte a esse tipo de bloqueio.|
|SQL_LOCK_UNLOCK|O driver ou a fonte de dados desbloqueia a linha. Nem todas as fontes de dados dão suporte a esse tipo de bloqueio.|

Para obter mais informações sobre `SQLSetPos`, consulte a SDK do Windows. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="setrowsetsize"></a>CRecordset::SetRowsetSize

Especifica o número de registros que você deseja recuperar durante uma busca.

```
virtual void SetRowsetSize(DWORD dwNewRowsetSize);
```

### <a name="parameters"></a>Parâmetros

*dwNewRowsetSize*<br/>
O número de linhas a serem recuperadas durante uma determinada busca.

### <a name="remarks"></a>Comentários

Essa função de membro virtual especifica quantas linhas você deseja recuperar durante uma única busca ao usar a busca de linha em massa. Para implementar a busca de linha em massa, você deve definir a opção `CRecordset::useMultiRowFetch` no parâmetro *dwOptions* da função de membro [Open](#open) .

> [!NOTE]
>  Chamar `SetRowsetSize` sem implementar a busca de linha em massa resultará em uma asserção com falha.

Chame `SetRowsetSize` antes de chamar `Open` para definir inicialmente o tamanho do conjunto de linhas para o conjunto de registros. O tamanho do conjunto de linhas padrão ao implementar a busca de linha em massa é 25.

> [!NOTE]
>  Tenha cuidado ao chamar `SetRowsetSize`. Se você estiver alocando manualmente o armazenamento para os dados (conforme especificado pela opção `CRecordset::userAllocMultiRowBuffers` do parâmetro dwOptions no `Open`), verifique se você precisa realocar esses buffers de armazenamento depois de chamar `SetRowsetSize`, mas antes de executar qualquer cursor operação de navegação.

Para obter a configuração atual para o tamanho do conjunto de linhas, chame [GetRowsetSize](#getrowsetsize).

Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

##  <a name="update"></a>CRecordset:: atualizar

Conclui uma operação de `AddNew` ou `Edit` salvando os dados novos ou editados na fonte de dados.

```
virtual BOOL Update();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se um registro foi atualizado com êxito; caso contrário, 0 se nenhuma coluna tiver sido alterada. Se nenhum registro tiver sido atualizado ou se mais de uma gravação tiver sido atualizada, uma exceção será lançada. Uma exceção também é gerada para qualquer outra falha na fonte de dados.

### <a name="remarks"></a>Comentários

Chame essa função de membro após uma chamada para a função [AddNew](#addnew) ou [Edit](#edit) member. Essa chamada é necessária para concluir a operação de `AddNew` ou `Edit`.

> [!NOTE]
>  Se você tiver implementado a busca de linha em massa, não será possível chamar `Update`. Isso resultará em uma asserção com falha. Embora a classe `CRecordset` não forneça um mecanismo para atualizar linhas de dados em massa, você pode escrever suas próprias funções usando a função da API do ODBC `SQLSetPos`. Para obter mais informações sobre a busca de linha em massa, consulte o artigo conjunto de registros [: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Ambos `AddNew` e `Edit` preparar um buffer de edição no qual os dados adicionados ou editados são colocados para salvar na fonte de dados. `Update` salva os dados. Somente os campos marcados ou detectados como alterados são atualizados.

Se a fonte de dados der suporte a transações, você poderá fazer com que o `Update` chame (e sua parte correspondente `AddNew` ou `Edit` chamada) de uma transação. Para obter mais informações sobre transações, consulte o artigo [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

> [!CAUTION]
>  Se você chamar `Update` sem primeiro chamar `AddNew` ou `Edit`, o `Update` lançará um `CDBException`. Se você chamar `AddNew` ou `Edit`, deverá chamar `Update` antes de chamar uma operação de `Move` ou antes de fechar o conjunto de registros ou a conexão de fonte de dados. Caso contrário, suas alterações serão perdidas sem notificação.

Para obter detalhes sobre como lidar com falhas de `Update`, consulte o artigo conjunto de registros [: como os conjuntos de registros atualizam os registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

### <a name="example"></a>Exemplo

Consulte o artigo [transação: executando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordView](../../mfc/reference/crecordview-class.md)
