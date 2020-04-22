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
ms.openlocfilehash: ab6cde9f478dc6f2e3cb0ba5bb338a3852f083fd
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81750509"
---
# <a name="crecordset-class"></a>Classe CRecordset

Representa um conjunto de registros selecionados a partir de uma fonte de dados.

## <a name="syntax"></a>Sintaxe

```
class CRecordset : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Configuração de crecord::CRecordset](#crecordset)|Constrói um objeto `CRecordset`. Sua classe derivada deve fornecer um construtor que chama este.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Configuração de registro de c::AdicionarNova](#addnew)|Prepara-se para adicionar um novo recorde. Ligue `Update` para completar a adição.|
|[CRecordset::CanAppend](#canappend)|Retorna não zero se novos registros puderem `AddNew` ser adicionados ao conjunto de registros através da função membro.|
|[CRecordset::CanBookmark](#canbookmark)|Retorna não zero se o conjunto de registros suportar marcadores.|
|[CRecordset::Cancel](#cancel)|Cancela uma operação assíncrona ou um processo de um segundo segmento.|
|[CRecordset::CancelUpdate](#cancelupdate)|Cancela quaisquer atualizações pendentes `AddNew` `Edit` devido a uma operação ou operação.|
|[CRecordset::CanRestart](#canrestart)|Retorna não `Requery` zero se puder ser chamado para executar a consulta do conjunto de registros novamente.|
|[Configuração de registro de c::CanScroll](#canscroll)|Retorna não zero se você puder percorrer os registros.|
|[CRecordset::CanTransact](#cantransact)|Retorna não zero se a fonte de dados suportar transações.|
|[CRecordset::CanUpdate](#canupdate)|Retorna não zero se o conjunto de registros puder ser atualizado (você pode adicionar, atualizar ou excluir registros).|
|[CRecordset::Verificação'sRow'sError](#checkrowseterror)|Chamado para lidar com erros gerados durante a busca de registros.|
|[CRecordset::Fechar](#close)|Fecha o conjunto de registros e o ODBC HSTMT associado a ele.|
|[CRecordset::Delete](#delete)|Exclui o registro atual do conjunto de registros. Você deve rolar explicitamente para outro registro após a exclusão.|
|[CRecordset::DoBulkFieldExchange](#dobulkfieldexchange)|Chamado para trocar linhas em massa de dados da fonte de dados para o conjunto de registros. Implementa o troca de campo de registro em massa (Bulk RFX).|
|[CRecordset::DoFieldExchange](#dofieldexchange)|Chamado para trocar dados (em ambas as direções) entre os membros de dados de campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa a troca de campo de registro (RFX).|
|[Configuração de crecord::Edição](#edit)|Prepara-se para mudanças no registro atual. Ligue `Update` para completar a edição.|
|[CRecordset::FlushResultSet](#flushresultset)|Retorna não zero se houver outro resultado definido a ser recuperado, ao usar uma consulta predefinida.|
|[CRecordset::GetBookmark](#getbookmark)|Atribui o valor do marcador de um registro ao objeto parâmetro.|
|[Configuração de registro de c::GetDefaultConnect](#getdefaultconnect)|Chamado para obter a seqüência de conexão padrão.|
|[CRecordset::GetDefaultSQL](#getdefaultsql)|Chamado para obter a seqüência SQL padrão para executar.|
|[Configuração de crecord::GetFieldValue](#getfieldvalue)|Retorna o valor de um campo em um conjunto de registros.|
|[CRecordset::GetODBCFieldCount](#getodbcfieldcount)|Retorna o número de campos no conjunto de registros.|
|[CRecordset::GetODBCFieldInfo](#getodbcfieldinfo)|Retorna tipos específicos de informações sobre os campos em um conjunto de registros.|
|[CRecordset::GetRecordCount](#getrecordcount)|Retorna o número de registros no conjunto de registros.|
|[Configuração de crecord::GetRowsetSize](#getrowsetsize)|Retorna o número de registros que deseja recuperar durante uma única busca.|
|[CRecordset::GetRowsFetched](#getrowsfetched)|Retorna o número real de linhas recuperadas durante uma busca.|
|[CRecordset::GetRowStatus](#getrowstatus)|Retorna o status da linha depois de uma busca.|
|[CRecordset::GetSQL](#getsql)|Obtém a seqüência SQL usada para selecionar registros para o conjunto de registros.|
|[CRecordset::GetStatus](#getstatus)|Obtém o status do conjunto de registros: o índice do registro atual e se uma contagem final dos registros foi obtida.|
|[CRecordset::GetTableName](#gettablename)|Obtém o nome da tabela na qual o conjunto de registros é baseado.|
|[Conjunto de registros::IsBOF](#isbof)|Retorna não zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há nenhum registro atual.|
|[Configuração de registro de c::''''''''''''''''''](#isdeleted)|Retorna não zero se o conjunto de registros estiver posicionado em um registro excluído.|
|[CRecordset::IsEOF](#iseof)|Retorna não zero se o conjunto de registros tiver sido posicionado após o último registro. Não há nenhum registro atual.|
|[CRecordset::IsFieldDirty](#isfielddirty)|Retorna não zero se o campo especificado no registro atual tiver sido alterado.|
|[CRecordset::IsFieldNull](#isfieldnull)|Retorna não zero se o campo especificado no registro atual for nulo (não tem valor).|
|[CRecordset::IsFieldNullable](#isfieldnullable)|Retorna não zero se o campo especificado no registro atual pode ser definido como nulo (sem valor).|
|[CRecordset::IsOpen](#isopen)|Retorna não `Open` zero se tiver sido chamado anteriormente.|
|[CRecordset::Mover](#move)|Posiciona o conjunto de registros a um número especificado de registros do registro atual em qualquer direção.|
|[CRecordset::MoveFirst](#movefirst)|Posiciona o recorde atual no primeiro registro no conjunto de discos. Teste `IsBOF` para o primeiro.|
|[CRecordset::MoveLast](#movelast)|Posiciona o registro atual no último registro ou na última linha. Teste `IsEOF` para o primeiro.|
|[CRecordset::MoveNext](#movenext)|Posiciona o registro atual no próximo registro ou no próximo conjunto de linhas. Teste `IsEOF` para o primeiro.|
|[CRecordset::MovePrev](#moveprev)|Posiciona o registro atual no registro anterior ou no conjunto de linhas anterior. Teste `IsBOF` para o primeiro.|
|[Configuração de registro de c::Opções de gravação](#onsetoptions)|Chamado para definir opções (usadas na seleção) para a declaração ODBC especificada.|
|[CRecordset::OndaConfiguraçãoOpções de atualização](#onsetupdateoptions)|Chamado para definir opções (usadas na atualização) para a declaração ODBC especificada.|
|[CRecordset::Abrir](#open)|Abre o conjunto de registros recuperando a tabela ou realizando a consulta que o conjunto de registros representa.|
|[CRecordset::RefreshRowset](#refreshrowset)|Atualiza os dados e o status das linhas especificadas.|
|[CRecordset:Requery](#requery)|Executa novamente a consulta do conjunto de registros para atualizar os registros selecionados.|
|[CRecordset::SetAbsolutePosition](#setabsoluteposition)|Posiciona o conjunto de registros no registro correspondente ao número de registro especificado.|
|[Configuração de registro de c::Set'mark](#setbookmark)|Posiciona o conjunto de registros no registro especificado pelo marcador.|
|[Configuração de crecord::SetField',](#setfielddirty)|Marca o campo especificado no registro atual como alterado.|
|[Configuração de crecord::SetFieldNull](#setfieldnull)|Define o valor do campo especificado no registro atual como nulo (sem valor).|
|[Configuração de registro de c::SetLockingMode](#setlockingmode)|Define o modo de bloqueio como bloqueio "otimista" (o padrão) ou bloqueio "pessimista". Determina como os registros são bloqueados para atualizações.|
|[CRecordset::SetParamNull](#setparamnull)|Define o parâmetro especificado como nulo (sem valor).|
|[CRecordset::SetRowsetCursorPosição](#setrowsetcursorposition)|Posiciona o cursor na linha especificada dentro do conjunto de linhas.|
|[Configuração de registro de c::SetRow '''''''''''''''''''](#setrowsetsize)|Especifica o número de registros que deseja recuperar durante uma busca.|
|[CRecordset::Atualização](#update)|Completa uma `AddNew` `Edit` operação ou salvando os dados novos ou editados na fonte de dados.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRecordset::m_hstmt](#m_hstmt)|Contém a alça de declaração ODBC para o conjunto de registros. Digite `HSTMT`.|
|[Conjunto de registros de c::m_nFields](#m_nfields)|Contém o número de membros de dados de campo no conjunto de registros. Digite `UINT`.|
|[CRecordset::m_nParams](#m_nparams)|Contém o número de membros de dados de parâmetros no conjunto de registros. Digite `UINT`.|
|[Configuração de crecord::m_pDatabase](#m_pdatabase)|Contém um ponteiro `CDatabase` para o objeto através do qual o conjunto de registros está conectado a uma fonte de dados.|
|[CRecordset::m_strFilter](#m_strfilter)|Contém `CString` uma cláusula que especifica uma cláusula SQL (Structured Query Language). `WHERE` Usado como filtro para selecionar apenas os registros que atendam a determinados critérios.|
|[Configuração de crecord::m_strSort](#m_strsort)|Contém `CString` um que especifica uma `ORDER BY` cláusula SQL. Usado para controlar como os registros são ordenados.|

## <a name="remarks"></a><a name="remarks"></a> Comentários

Conhecidos como "conjuntos de registros", `CRecordset` os objetos são tipicamente usados em duas formas: dynasets e snapshots. Um dynaset permanece sincronizado com as atualizações de dados feitas por outros usuários. Um instantâneo é uma visão estática dos dados. Cada formulário representa um conjunto de registros fixos no momento em que o conjunto de registros é aberto, mas quando você rola para um registro em um dynaset, ele reflete alterações posteriormente feitas no registro, seja por outros usuários ou por outros conjuntos de registros em seu aplicativo.

> [!NOTE]
> Se você estiver trabalhando com as classes DAO (Data Access Objects, objetos de acesso de dados) em vez das classes ODBC (Open Database Connectivity, conectividade de banco de dados aberto), use a classe [CDaoRecordset.](../../mfc/reference/cdaorecordset-class.md) Para obter mais informações, consulte a visão geral do [artigo: Programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

Para trabalhar com qualquer tipo de conjunto de registros, você `CRecordset`normalmente deriva uma classe de conjunto de registros específica do aplicativo de . Os registros selecionam registros de uma fonte de dados e você pode:

- Perdoe os registros.

- Atualize os registros e especifique um modo de bloqueio.

- Filtre o conjunto de registros para restringir quais registros ele seleciona daqueles disponíveis na fonte de dados.

- Classifique o conjunto de discos.

- Parametrizar o conjunto de registros para personalizar sua seleção com informações não conhecidas até o tempo de execução.

Para usar sua classe, abra um banco de dados e construa `CDatabase` um objeto de conjunto de registros, passando ao construtor um ponteiro para o seu objeto. Em seguida, chame `Open` a função de membro do recordset, onde você pode especificar se o objeto é um dynaset ou um snapshot. A `Open` chamada seleciona dados da fonte de dados. Depois que o objeto do conjunto de registros for aberto, use suas funções de membro e membros de dados para percorrer os registros e operá-los. As operações disponíveis dependem se o objeto é um dynaset ou um snapshot, se ele é updatable ou somente leitura (isso depende da capacidade da fonte de dados ODBC (Open Database Connectivity) e se você implementou a busca de linhas em massa. Para atualizar registros que podem ter `Open` sido alterados ou `Requery` adicionados desde a chamada, ligue para a função de membro do objeto. Chame a função `Close` de membro do objeto e destrua o objeto quando terminar com ele.

Em uma `CRecordset` classe derivada, o Record Field Exchange (RFX) ou o Bulk Record Field Exchange (Bulk RFX) são usados para suportar a leitura e a atualização de campos de registro.

Para obter mais informações sobre conjuntos de registros e troca de campos de registro, consulte os artigos [Visão geral: Programação de Banco de Dados,](../../data/data-access-programming-mfc-atl.md) [Conjunto de Registros (ODBC)](../../data/odbc/recordset-odbc.md), Conjunto de [registros: Busto de Registros em Massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md)e [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md). Para obter um foco em dynasets e snapshots, consulte os artigos [Dynaset](../../data/odbc/dynaset.md) e [Snapshot](../../data/odbc/snapshot.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CRecordset`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="crecordsetaddnew"></a><a name="addnew"></a>Configuração de registro de c::AdicionarNova

Prepara-se para adicionar um novo recorde à mesa.

```
virtual void AddNew();
```

### <a name="remarks"></a>Comentários

Você deve chamar a função de membro [Requery](#requery) para ver o registro recém-adicionado. Os campos do registro são inicialmente nulos. (Na terminologia do banco de dados, Nulo significa "não ter valor" e não é o mesmo que NULL em C++.) Para concluir a operação, você deve chamar a função de membro [atualizar.](#update) `Update`salva suas alterações na fonte de dados.

> [!NOTE]
> Se você implementou a busca em `AddNew`linha em massa, você não pode chamar . Isso resultará em uma afirmação fracassada. Embora `CRecordset` a classe não forneça um mecanismo para atualizar linhas em massa de dados, você `SQLSetPos`pode escrever suas próprias funções usando a função API ODBC . Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

`AddNew`prepara um novo registro vazio usando os membros de dados de campo do conjunto de registros. Depois de `AddNew`ligar, defina os valores desejados nos membros de dados de campo do conjunto de registros. (Você não precisa chamar a função [Editar](#edit) membro `Edit` para este fim; usar apenas para registros existentes.) Quando você chama, `Update`os valores alterados nos membros de dados de campo são salvos na fonte de dados.

> [!CAUTION]
> Se você rolar para um `Update`novo registro antes de chamar, o novo registro será perdido e nenhum aviso será dado.

Se a fonte de dados suportar transações, você pode fazer sua `AddNew` chamada parte de uma transação. Para obter mais informações sobre transações, consulte [class CDatabase](../../mfc/reference/cdatabase-class.md). Observe que você deve ligar para [CDatabase::BeginTrans](../../mfc/reference/cdatabase-class.md#begintrans) antes de ligar `AddNew`.

> [!NOTE]
> Para dynasets, novos registros são adicionados ao conjunto de discos como o último disco. Os registros adicionados não são adicionados aos instantâneos; você deve `Requery` ligar para atualizar o conjunto de registros.

É ilegal pedir `AddNew` um conjunto `Open` de registros cuja função de membro não tenha sido chamada. A `CDBException` é lançado `AddNew` se você chamar para um conjunto de registros que não pode ser anexado. Você pode determinar se o conjunto de registros é updatable ligando para [CanAppend](#canappend).

Para obter mais informações, consulte os seguintes artigos: [Recordset: How Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md), [Recordset: Adding, Updating and Deleting Records (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md)e [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>Exemplo

Veja o artigo [Transação: Realizando uma Transação em um Conjunto de Registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

## <a name="crecordsetcanappend"></a><a name="canappend"></a>CRecordset::CanAppend

Determina se o conjunto de registros aberto anteriormente permite adicionar novos registros.

```
BOOL CanAppend() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros permitir a adição de novos registros; caso contrário, 0. `CanAppend`retornará 0 se você abriu o conjunto de registros como somente leitura.

## <a name="crecordsetcanbookmark"></a><a name="canbookmark"></a>CRecordset::CanBookmark

Determina se o conjunto de registros permite marcar registros usando marcadores.

```
BOOL CanBookmark() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros suportar marcadores; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função é `CRecordset::useBookmarks` independente da opção no parâmetro *dwOptions* da função [Membro Aberto.](#open) `CanBookmark`indica se o driver dado o dobc e marcadores de suporte tipo cursor. `CRecordset::useBookmarks`indica se os marcadores estarão disponíveis, desde que sejam suportados.

> [!NOTE]
> Os marcadores não são suportados em conjuntos de registros somente para frente.

Para obter mais informações sobre marcadores e navegação de conjunto de registros, consulte os artigos [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [Conjunto de Registros: Rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

## <a name="crecordsetcancel"></a><a name="cancel"></a>CRecordset::Cancel

Solicita que a fonte de dados cancele uma operação assíncrona em andamento ou um processo a partir de um segundo segmento.

```cpp
void Cancel();
```

### <a name="remarks"></a>Comentários

Observe que as classes MFC ODBC não usam mais processamento assíncrono; para realizar uma operação assípica, você deve chamar diretamente `SQLSetConnectOption`a função API ODBC . Para obter mais informações, consulte o tópico "Executando funções assíncronas" no *Guia do Programador SDK da ODBC*.

## <a name="crecordsetcancelupdate"></a><a name="cancelupdate"></a>CRecordset::CancelUpdate

Cancela quaisquer atualizações pendentes, causadas por uma operação [Editar](#edit) ou [AdicionarNova,](#addnew) antes [que a atualização](#update) seja chamada.

```cpp
void CancelUpdate();
```

### <a name="remarks"></a>Comentários

> [!NOTE]
> Esta função de membro não é aplicável em conjuntos de registros que `Edit` `AddNew`estão `Update`usando a busca de linhas em massa, uma vez que tais conjuntos de registros não podem chamar , ou . Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Se a verificação automática de `CancelUpdate` campo sujo estiver habilitada, restaurará as variáveis de membro aos valores que tinham antes `Edit` ou `AddNew` foram chamados; caso contrário, qualquer mudança de valor permanecerá. Por padrão, a verificação automática de campo é ativada quando o conjunto de registros é aberto. Para desativá-lo, você deve especificar o `CRecordset::noDirtyFieldCheck` parâmetro *dwOptions* da função Membro [Aberto.](#open)

Para obter mais informações sobre a atualização de dados, consulte o artigo [Recordset: Adicionando, Atualizando e Excluindo Registros (ODBC)](../../data/odbc/recordset-adding-updating-and-deleting-records-odbc.md).

## <a name="crecordsetcanrestart"></a><a name="canrestart"></a>CRecordset::CanRestart

Determina se o conjunto de registros permite reiniciar sua consulta (atualizar seus registros) chamando a `Requery` função de membro.

```
BOOL CanRestart() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se for permitido requery; caso contrário, 0.

## <a name="crecordsetcanscroll"></a><a name="canscroll"></a>Configuração de registro de c::CanScroll

Determina se o conjunto de registros permite a rolagem.

```
BOOL CanScroll() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros permitir a rolagem; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre rolagem, consulte o artigo [Recordset: Scrolling (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

## <a name="crecordsetcantransact"></a><a name="cantransact"></a>CRecordset::CanTransact

Determina se o conjunto de registros permite transações.

```
BOOL CanTransact() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros permitir transações; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte o artigo [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

## <a name="crecordsetcanupdate"></a><a name="canupdate"></a>CRecordset::CanUpdate

Determina se o conjunto de registros pode ser atualizado.

```
BOOL CanUpdate() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros puder ser atualizado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Um conjunto de registros pode ser lido somente se a fonte de `CRecordset::readOnly` dados subjacente for somente leitura ou se você tiver especificado no parâmetro *dwOptions* quando você abriu o conjunto de registros.

## <a name="crecordsetcheckrowseterror"></a><a name="checkrowseterror"></a>CRecordset::Verificação'sRow'sError

Chamado para lidar com erros gerados durante a busca de registros.

```
virtual void CheckRowsetError(RETCODE nRetCode);
```

### <a name="parameters"></a>Parâmetros

*Nretcode*<br/>
Um código de retorno da função API ODBC. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Esta função de membro virtual lida com erros que ocorrem quando os registros são buscados e é útil durante a busca em linha em massa. Você pode considerar a `CheckRowsetError` substituição para implementar seu próprio tratamento de erro.

`CheckRowsetError`é chamado automaticamente em uma operação de `Open` `Requery`navegação cursor, como , , ou qualquer `Move` operação. É passado o valor de retorno da `SQLExtendedFetch`função API ODBC . A tabela a seguir lista os valores possíveis para o parâmetro *nRetCode.*

|Nretcode|Descrição|
|--------------|-----------------|
|SQL_SUCCESS|Função concluída com sucesso; nenhuma informação adicional está disponível.|
|Sql_success_with_info|Função concluída com sucesso, possivelmente com um erro não fatal. Informações adicionais podem ser `SQLError`obtidas pelo telefone .|
|SQL_NO_DATA_FOUND|Todas as linhas do conjunto de resultados foram buscadas.|
|SQL_ERROR|Falha na função. Informações adicionais podem ser `SQLError`obtidas pelo telefone .|
|SQL_INVALID_HANDLE|A função falhou devido a uma alça de ambiente inválida, cabo de conexão ou alça de declaração. Isso indica um erro de programação. Não há informações `SQLError`adicionais disponíveis de .|
|Sql_still_executing|Uma função que foi iniciada assíncronamente ainda está sendo executada. Observe que, por padrão, o MFC nunca passará esse valor para; `CheckRowsetError` MFC continuará `SQLExtendedFetch` chamando até que não retorne mais SQL_STILL_EXECUTING.|

Para obter `SQLError`mais informações sobre, consulte o Windows SDK. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="crecordsetclose"></a><a name="close"></a>CRecordset::Fechar

Fecha o conjunto de registros.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

O ODBC HSTMT e toda a memória que a estrutura alocada para o conjunto de registros são desalocadas. Normalmente, `Close`após a chamada, você exclui o objeto c++ recordset se ele foi alocado com **novo**.

Você pode `Open` ligar `Close`de novo depois de ligar. Isso permite que você reutilize o objeto recordset. A alternativa é `Requery`chamar.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#17](../../mfc/codesnippet/cpp/crecordset-class_1.cpp)]

## <a name="crecordsetcrecordset"></a><a name="crecordset"></a>Configuração de crecord::CRecordset

Constrói um objeto `CRecordset`.

```
CRecordset(CDatabase* pDatabase = NULL);
```

### <a name="parameters"></a>Parâmetros

*pBanco de dados*<br/>
Contém um ponteiro `CDatabase` para um objeto ou o valor NULL. Se não for `CDatabase` NULA `Open` e a função de membro do objeto não tiver sido chamada para conectá-la à fonte de dados, o conjunto de registros tentará abri-lo para você durante sua própria `Open` chamada. Se você passar `CDatabase` NULL, um objeto será construído e conectado para você usando as informações de origem de dados especificadas quando você derivasua classe de conjunto de registros com o ClassWizard.

### <a name="remarks"></a>Comentários

Você pode `CRecordset` usar diretamente ou derivar `CRecordset`uma classe específica de aplicativo de . Você pode usar o ClassWizard para derivar suas classes de conjunto de registros.

> [!NOTE]
> Uma classe derivada *deve* fornecer seu próprio construtor. Na construtora de sua classe derivada, `CRecordset::CRecordset`chame o construtor, passando os parâmetros apropriados ao longo dele.

Passe NULL para o construtor do `CDatabase` conjunto de registros para ter um objeto construído e conectado automaticamente para você. Esta é uma taquigrafia útil que não `CDatabase` exige que você construa e conecte um objeto antes de construir seu conjunto de registros.

### <a name="example"></a>Exemplo

Para obter mais informações, consulte o artigo [Recordset: Declarando uma Classe para uma Tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md).

## <a name="crecordsetdelete"></a><a name="delete"></a>CRecordset::Delete

Exclui o registro atual.

```
virtual void Delete();
```

### <a name="remarks"></a>Comentários

Após uma exclusão bem-sucedida, os membros de dados de campo do conjunto de `Move` registros são definidos como um valor nulo, e você deve explicitamente chamar uma das funções para sair do registro excluído. Uma vez que você saia do registro excluído, não é possível retornar a ele. Se a fonte de dados suportar transações, você pode fazer a `Delete` chamada parte de uma transação. Para obter mais informações, consulte o artigo [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

> [!NOTE]
> Se você implementou a busca em `Delete`linha em massa, você não pode chamar . Isso resultará em uma afirmação fracassada. Embora `CRecordset` a classe não forneça um mecanismo para atualizar linhas em massa de dados, você `SQLSetPos`pode escrever suas próprias funções usando a função API ODBC . Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

> [!CAUTION]
> O conjunto de registros deve ser updatable e deve haver uma `Delete`corrente de registro válida no conjunto de registros quando você chamar ; caso contrário, ocorre um erro. Por exemplo, se você excluir um registro, mas não `Delete` rolar `Delete` para um novo registro antes de chamar novamente, jogará um [CDBException](../../mfc/reference/cdbexception-class.md).

Ao contrário [de AddNew](#addnew) `Delete` e [Edit](#edit), uma chamada não é seguida por uma chamada para [Atualizar](#update). Se `Delete` uma chamada falhar, os membros dos dados de campo serão deixados inalterados.

### <a name="example"></a>Exemplo

Este exemplo mostra um conjunto de registros criado no quadro de uma função. O exemplo assume a `m_dbCust`existência de , `CDatabase` uma variável membro do tipo já conectado à fonte de dados.

[!code-cpp[NVC_MFCDatabase#18](../../mfc/codesnippet/cpp/crecordset-class_2.cpp)]

## <a name="crecordsetdobulkfieldexchange"></a><a name="dobulkfieldexchange"></a>CRecordset::DoBulkFieldExchange

Chamado para trocar linhas em massa de dados da fonte de dados para o conjunto de registros. Implementa o troca de campo de registro em massa (Bulk RFX).

```
virtual void DoBulkFieldExchange(CFieldExchange* pFX);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](../../mfc/reference/cfieldexchange-class.md) O framework já terá configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Quando a busca de linhas em massa é implementada, a estrutura chama essa função de membro para transferir automaticamente dados da fonte de dados para o objeto do conjunto de registros. `DoBulkFieldExchange`também vincula seus membros de dados de parâmetro, se houver, a espaços reservados de parâmetros na seqüência de declaração SQL para a seleção do conjunto de registros.

Se a busca de linhas em massa não for implementada, a estrutura chamará [doFieldExchange](#dofieldexchange). Para implementar a busca de linhas `CRecordset::useMultiRowFetch` em massa, você deve especificar a opção do parâmetro *dwOptions* na função [Membro Aberto.](#open)

> [!NOTE]
> `DoBulkFieldExchange`está disponível apenas se você estiver `CRecordset`usando uma classe derivada de . Se você criou um objeto de `CRecordset`conjunto de registros diretamente de, você deve chamar a função de membro [GetFieldValue](#getfieldvalue) para recuperar dados.

A troca de campo de registro em massa (Bulk RFX) é semelhante à troca de campo de registro (RFX). Os dados são automaticamente transferidos da fonte de dados para o objeto recordset. No entanto, `AddNew` `Edit`você `Delete`não `Update` pode ligar ou transferir alterações de volta para a fonte de dados. Atualmente, `CRecordset` a classe não fornece um mecanismo para atualizar linhas em massa de dados; no entanto, você pode escrever suas próprias funções usando a função `SQLSetPos`API ODBC .

Observe que o ClassWizard não suporta troca de campo de gravação em massa; portanto, você deve `DoBulkFieldExchange` substituir manualmente escrevendo chamadas para as funções Bulk RFX. Para obter mais informações sobre essas funções, consulte o tópico [Funções de Troca de Campo de Registro](../../mfc/reference/record-field-exchange-functions.md).

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter informações relacionadas, consulte o artigo [Record Field Exchange (RFX)](../../data/odbc/record-field-exchange-rfx.md).

## <a name="crecordsetdofieldexchange"></a><a name="dofieldexchange"></a>CRecordset::DoFieldExchange

Chamado para trocar dados (em ambas as direções) entre os membros de dados de campo do conjunto de registros e o registro correspondente na fonte de dados. Implementa a troca de campo de registro (RFX).

```
virtual void DoFieldExchange(CFieldExchange* pFX);
```

### <a name="parameters"></a>Parâmetros

*Pfx*<br/>
Um ponteiro para um objeto [CFieldExchange.](../../mfc/reference/cfieldexchange-class.md) O framework já terá configurado esse objeto para especificar um contexto para a operação de troca de campo.

### <a name="remarks"></a>Comentários

Quando a busca de linhas em massa não é implementada, a estrutura chama essa função de membro para trocar automaticamente dados entre os membros de dados de campo do objeto do conjunto de registros e as colunas correspondentes do registro atual na fonte de dados. `DoFieldExchange`também vincula seus membros de dados de parâmetro, se houver, a espaços reservados de parâmetros na seqüência de declaração SQL para a seleção do conjunto de registros.

Se a busca de linhas em massa for implementada, a estrutura chamará [DoBulkFieldExchange](#dobulkfieldexchange). Para implementar a busca de linhas `CRecordset::useMultiRowFetch` em massa, você deve especificar a opção do parâmetro *dwOptions* na função [Membro Aberto.](#open)

> [!NOTE]
> `DoFieldExchange`está disponível apenas se você estiver `CRecordset`usando uma classe derivada de . Se você criou um objeto de `CRecordset`conjunto de registros diretamente de, você deve chamar a função de membro [GetFieldValue](#getfieldvalue) para recuperar dados.

A troca de dados de campo, chamada de troca de campo de registro (RFX), funciona em ambas as direções: desde os membros de dados de campo do objeto recordset até os campos do registro na fonte de dados e do registro na fonte de dados até o objeto recordset.

A única ação que você `DoFieldExchange` normalmente deve tomar para implementar para sua classe de conjunto de registros derivado é criar a classe com o ClassWizard e especificar os nomes e tipos de dados dos membros de dados de campo. Você também pode adicionar código ao que o ClassWizard grava para especificar membros de dados de parâmetros ou para lidar com quaisquer colunas que você vincule dinamicamente. Para obter mais informações, consulte o artigo [Recordset: Dynamically Binding Data Columns (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md).

Quando você declara sua classe de conjunto de gravações derivada com o ClassWizard, o assistente grava uma substituição de `DoFieldExchange` para você, que se assemelha ao seguinte exemplo:

[!code-cpp[NVC_MFCDatabase#19](../../mfc/codesnippet/cpp/crecordset-class_3.cpp)]

Para obter mais informações sobre as funções RFX, consulte o tópico [Funções](../../mfc/reference/record-field-exchange-functions.md)de Troca de Campo de Registro .

Para obter mais exemplos `DoFieldExchange`e detalhes sobre , consulte o artigo [Record Field Exchange: How RFX Works](../../data/odbc/record-field-exchange-how-rfx-works.md). Para obter informações gerais sobre o RFX, consulte o artigo [Record Field Exchange](../../data/odbc/record-field-exchange-rfx.md).

## <a name="crecordsetedit"></a><a name="edit"></a>Configuração de crecord::Edição

Permite alterações no registro atual.

```
virtual void Edit();
```

### <a name="remarks"></a>Comentários

Depois de `Edit`ligar, você pode alterar os membros de dados de campo redefinindo diretamente seus valores. A operação é concluída quando você chama posteriormente a função de membro [Atualizar](#update) para salvar suas alterações na fonte de dados.

> [!NOTE]
> Se você implementou a busca em `Edit`linha em massa, você não pode chamar . Isso resultará em uma afirmação fracassada. Embora `CRecordset` a classe não forneça um mecanismo para atualizar linhas em massa de dados, você `SQLSetPos`pode escrever suas próprias funções usando a função API ODBC . Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

`Edit`salva os valores dos membros de dados do conjunto de registros. Se você `Edit`ligar, fazer `Edit` alterações, então chamar novamente, os valores `Edit` do registro são restaurados ao que eram antes da primeira chamada.

Em alguns casos, você pode querer atualizar uma coluna tornando-a nula (sem dados). Para isso, ligue para [SetFieldNull](#setfieldnull) com um parâmetro de TRUE para marcar o campo Nulo; isso também faz com que a coluna seja atualizada. Se você quiser que um campo seja gravado na fonte de dados, mesmo que seu valor não tenha sido alterado, ligue [setFieldDirty](#setfielddirty) com um parâmetro de TRUE. Isso funciona mesmo que o campo tivesse o valor nulo.

Se a fonte de dados suportar transações, você pode fazer a `Edit` chamada parte de uma transação. Observe que você deve ligar para [CDatabase::BeginTrans](../../mfc/reference/cdatabase-class.md#begintrans) antes de ligar `Edit` e depois que o conjunto de registros tiver sido aberto. Observe também que chamar [CDatabase::CommitTrans](../../mfc/reference/cdatabase-class.md#committrans) não `Update` é `Edit` um substituto para a chamada para concluir a operação. Para obter mais informações sobre transações, consulte [class CDatabase](../../mfc/reference/cdatabase-class.md).

Dependendo do modo de bloqueio atual, o `Edit` registro que `Update` está sendo atualizado pode ser bloqueado até `Edit` que você ligue ou role para outro registro, ou ele pode ser bloqueado apenas durante a chamada. Você pode alterar o modo de bloqueio com [SetLockingMode](#setlockingmode).

O valor anterior do registro atual é restaurado se `Update`você rolar para um novo registro antes de chamar . A `CDBException` é lançado `Edit` se você chamar para um conjunto de registros que não pode ser atualizado ou se não há registro atual.

Para obter mais informações, consulte os artigos [Transaction (ODBC)](../../data/odbc/transaction-odbc.md) e [Recordset: Locking Records (ODBC)](../../data/odbc/recordset-locking-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#20](../../mfc/codesnippet/cpp/crecordset-class_4.cpp)]

## <a name="crecordsetflushresultset"></a><a name="flushresultset"></a>CRecordset::FlushResultSet

Recupera o próximo conjunto de resultados de uma consulta predefinida (procedimento armazenado), se houver vários conjuntos de resultados.

```
BOOL FlushResultSet();
```

### <a name="return-value"></a>Valor retornado

Não zero se houver mais conjuntos de resultados a serem recuperados; caso contrário, 0.

### <a name="remarks"></a>Comentários

Você deve `FlushResultSet` ligar somente quando estiver completamente terminado com o cursor no conjunto de resultados atual. Observe que quando você recuperar o `FlushResultSet`próximo resultado definido por chamada, o cursor não é válido nesse conjunto de resultados; você deve chamar a função `FlushResultSet`de membro [MoveNext](#movenext) depois de chamar .

Se uma consulta predefinida usar um parâmetro de saída ou `FlushResultSet` parâmetros `FALSE` de entrada/saída, você deve ligar até que ela retorne (o valor 0), a fim de obter esses valores de parâmetro.

`FlushResultSet`chama a função `SQLMoreResults`API odbc . Se `SQLMoreResults` retornar SQL_ERROR ou `FlushResultSet` SQL_INVALID_HANDLE, então abrirá uma exceção. Para obter `SQLMoreResults`mais informações sobre, consulte o Windows SDK.

Seu procedimento armazenado precisa ter campos vinculados se você quiser ligar `FlushResultSet`.

### <a name="example"></a>Exemplo

O código a `COutParamRecordset` seguir `CRecordset`assume que é um objeto derivado com base em uma consulta predefinida com um parâmetro de entrada e um parâmetro de saída, e tendo vários conjuntos de resultados. Observe a estrutura da substituição [do DoFieldExchange.](#dofieldexchange)

[!code-cpp[NVC_MFCDatabase#21](../../mfc/codesnippet/cpp/crecordset-class_5.cpp)]

[!code-cpp[NVC_MFCDatabase#22](../../mfc/codesnippet/cpp/crecordset-class_6.cpp)]

## <a name="crecordsetgetbookmark"></a><a name="getbookmark"></a>CRecordset::GetBookmark

Obtém o valor do marcador para o registro atual.

```cpp
void GetBookmark(CDBVariant& varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Uma referência a um objeto [CDBVariant](../../mfc/reference/cdbvariant-class.md) representando o marcador no registro atual.

### <a name="remarks"></a>Comentários

Para determinar se os marcadores são suportados no conjunto de registros, ligue para [o CanBookmark](#canbookmark). Para disponibilizar marcadores se eles forem suportados, você deve definir a `CRecordset::useBookmarks` opção no parâmetro *dwOptions* da função Membro [Aberto.](#open)

> [!NOTE]
> Se os marcadores não estiverem `GetBookmark` suportados ou indisponíveis, a chamada resultará em uma exceção. Os marcadores não são suportados em conjuntos de registros somente para frente.

`GetBookmark`atribui o valor do marcador para o `CDBVariant` registro atual a um objeto. Para retornar a esse registro a qualquer momento após a mudança `CDBVariant` para um registro diferente, ligue [setBookmark](#setbookmark) com o objeto correspondente.

> [!NOTE]
> Após certas operações de conjunto de registros, os marcadores podem não ser mais válidos. Por exemplo, se `GetBookmark` você `Requery`chamar seguido por , você pode `SetBookmark`não ser capaz de retornar ao registro com . Chamada [CDatabase::GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se `SetBookmark`você pode ligar com segurança .

Para obter mais informações sobre marcadores e navegação de conjunto de registros, consulte os artigos [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [Conjunto de Registros: Rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

## <a name="crecordsetgetdefaultconnect"></a><a name="getdefaultconnect"></a>Configuração de registro de c::GetDefaultConnect

Chamado para obter a seqüência de conexão padrão.

```
virtual CString GetDefaultConnect();
```

### <a name="return-value"></a>Valor retornado

A `CString` que contém a seqüência de conexão padrão.

### <a name="remarks"></a>Comentários

A estrutura chama essa função de membro para obter a seqüência de conexão padrão para a fonte de dados na qual o conjunto de registros é baseado. O ClassWizard implementa essa função para você identificando a mesma fonte de dados que você usa no ClassWizard para obter informações sobre tabelas e colunas. Você provavelmente achará conveniente confiar nesta conexão padrão enquanto desenvolve seu aplicativo. Mas a conexão padrão pode não ser apropriada para usuários do seu aplicativo. Se esse for o caso, você deve reimplementar essa função, descartando a versão do ClassWizard. Para obter mais informações sobre strings de conexão, consulte o artigo [Data Source (ODBC)](../../data/odbc/data-source-odbc.md).

## <a name="crecordsetgetdefaultsql"></a><a name="getdefaultsql"></a>CRecordset::GetDefaultSQL

Chamado para obter a seqüência SQL padrão para executar.

```
virtual CString GetDefaultSQL();
```

### <a name="return-value"></a>Valor retornado

A `CString` que contém a declaração SQL padrão.

### <a name="remarks"></a>Comentários

O framework chama essa função de membro para obter a declaração SQL padrão na qual o conjunto de registros é baseado. Isso pode ser um nome de tabela ou uma declaração SQL **SELECT.**

Você define indiretamente a declaração SQL padrão declarando sua classe de conjunto de discos com o ClassWizard, e o ClassWizard executa essa tarefa para você.

Se você precisar da seqüência de declaração SQL para seu próprio uso, ligue `GetSQL`, que retorna a declaração SQL usada para selecionar os registros do conjunto de registros quando ele foi aberto. Você pode editar a seqüência SQL padrão `GetDefaultSQL`na substituição de . Por exemplo, você pode especificar uma chamada para uma consulta predefinida usando uma declaração **CALL.** (Observe, no entanto, `GetDefaultSQL`que se você `m_nFields` editar, você também precisa modificar para corresponder ao número de colunas na fonte de dados.)

Para obter mais informações, consulte o artigo [Recordset: Declarando uma Classe para uma Tabela (ODBC)](../../data/odbc/recordset-declaring-a-class-for-a-table-odbc.md).

> [!CAUTION]
> O nome da tabela estará vazio se o framework não puder identificar um nome de tabela, se vários nomes de tabela foram fornecidos ou se uma declaração **CALL** não pôde ser interpretada. Observe que, ao usar uma instrução **CALL,** você não deve inserir espaço em branco entre a cinta encaracolada e a palavra-chave **CALL,** nem deve inserir espaço em branco antes da cinta encaracolada ou antes da palavra-chave **SELECT** em uma instrução **SELECT.**

## <a name="crecordsetgetfieldvalue"></a><a name="getfieldvalue"></a>Configuração de crecord::GetFieldValue

Recupera dados de campo no registro atual.

```cpp
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

*varValu*e A referência a um objeto [CDBVariant](../../mfc/reference/cdbvariant-class.md) que armazenará o valor do campo.

*nFieldType*<br/>
O tipo de dados ODBC C do campo. Usando o valor padrão, `GetFieldValue` DEFAULT_FIELD_TYPE, força a determinar o tipo de dados C do tipo de dados SQL, com base na tabela a seguir. Caso contrário, você pode especificar o tipo de dados diretamente ou escolher um tipo de dados compatível; por exemplo, você pode armazenar qualquer tipo de dados em SQL_C_CHAR.

|Tipos de dados do C|Tipo de dados SQL|
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

Para obter mais informações sobre os tipos de dados do ODBC, consulte os tópicos "Tipos de Dados SQL" e "Tipos de Dados C" no apêndice D do Windows SDK.

*nIndex*<br/>
O índice baseado em zero do campo.

*strValue*<br/>
Uma referência a um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) que armazenará o valor do campo convertido em texto, independentemente do tipo de dados do campo.

### <a name="remarks"></a>Comentários

Você pode procurar um campo pelo nome ou pelo índice. Você pode armazenar o valor `CDBVariant` de `CString` campo em um objeto ou em um objeto.

Se você implementou a busca em linha em massa, o registro atual está sempre posicionado no primeiro registro em um conjunto de linhas. Para `GetFieldValue` usar em um registro dentro de um determinado conjunto de linhas, primeiro você deve chamar a função de membro [SetRowsetCursorPosition](#setrowsetcursorposition) para mover o cursor para a linha desejada dentro desse conjunto de linhas. Então `GetFieldValue` chame por essa fila. Para implementar a busca de linhas `CRecordset::useMultiRowFetch` em massa, você deve especificar a opção do parâmetro *dwOptions* na função [Membro Aberto.](#open)

Você pode `GetFieldValue` usar para buscar dinamicamente campos em tempo de execução, em vez de vinculá-los estáticamente na hora do projeto. Por exemplo, se você declarou um objeto `CRecordset`de conjunto `GetFieldValue` de registros diretamente de , você deve usar para recuperar os dados de campo; o record field exchange (RFX), ou o bulk record field exchange (Bulk RFX), não é implementado.

> [!NOTE]
> Se você declarar um objeto de `CRecordset`conjunto de registros sem derivar, não tenha a Biblioteca Cursor ODBC carregada. A biblioteca do cursor exige que o conjunto de registros tenha pelo menos uma coluna vinculada; no entanto, `CRecordset` quando você usa diretamente, nenhuma das colunas está vinculada. O membro funciona [CDatabase::OpenEx](../../mfc/reference/cdatabase-class.md#openex) e [CDatabase::Controle aberto](../../mfc/reference/cdatabase-class.md#open) se a biblioteca do cursor será carregada.

`GetFieldValue`chama a função `SQLGetData`API odbc . Se o driver desemarcar o valor SQL_NO_TOTAL `GetFieldValue` para o comprimento real do valor do campo, será uma exceção. Para obter `SQLGetData`mais informações sobre, consulte o Windows SDK.

### <a name="example"></a>Exemplo

O código de amostra `GetFieldValue` a seguir ilustra chamadas para `CRecordset`um objeto de conjunto de registros declarado diretamente de .

[!code-cpp[NVC_MFCDatabase#23](../../mfc/codesnippet/cpp/crecordset-class_7.cpp)]

> [!NOTE]
> Ao contrário da `CDaoRecordset` `CRecordset` classe DAO, não tem uma `SetFieldValue` função de membro. Se você criar um `CRecordset`objeto diretamente de, ele é efetivamente somente leitura.

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="crecordsetgetodbcfieldcount"></a><a name="getodbcfieldcount"></a>CRecordset::GetODBCFieldCount

Recupera o número total de campos no objeto recordset.

```
short GetODBCFieldCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de campos no conjunto de registros.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre a criação de conjuntos de registros, consulte o artigo [Recordset: Creating and Closing Recordsets (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

## <a name="crecordsetgetodbcfieldinfo"></a><a name="getodbcfieldinfo"></a>CRecordset::GetODBCFieldInfo

Obtém informações sobre os campos no conjunto de registros.

```cpp
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

*Fieldinfo*<br/>
Uma referência `CODBCFieldInfo` a uma estrutura.

*nIndex*<br/>
O índice baseado em zero do campo.

### <a name="remarks"></a>Comentários

Uma versão da função permite que você procure um campo pelo nome. A outra versão permite que você procure um campo por índice.

Para obter uma descrição sobre as informações retornadas, consulte a estrutura [CODBCFieldInfo.](../../mfc/reference/codbcfieldinfo-structure.md)

Para obter mais informações sobre a criação de conjuntos de registros, consulte o artigo [Recordset: Creating and Closing Recordsets (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

## <a name="crecordsetgetrecordcount"></a><a name="getrecordcount"></a>CRecordset::GetRecordCount

Determina o tamanho do conjunto de registros.

```
long GetRecordCount() const;
```

### <a name="return-value"></a>Valor retornado

O número de registros no conjunto de registros; 0 se o conjunto de registros não contiver registros; ou -1 se a contagem de registros não puder ser determinada.

### <a name="remarks"></a>Comentários

> [!CAUTION]
> A contagem de registros é mantida como uma "marca de água alta", o registro mais alto já visto enquanto o usuário se move através dos registros. O número total de registros só é conhecido depois que o usuário ultrapassou o último registro. Por razões de desempenho, a `MoveLast`contagem não é atualizada quando você chama . Para contar os registros `MoveNext` você `IsEOF` mesmo, ligue repetidamente até que não seja zero. Adicionar um `CRecordset:AddNew` registro `Update` via e aumenta a contagem; excluir um registro `CRecordset::Delete` através diminui a contagem.

## <a name="crecordsetgetrowsetsize"></a><a name="getrowsetsize"></a>Configuração de crecord::GetRowsetSize

Obtém a configuração atual para o número de linhas que deseja recuperar durante uma determinada busca.

```
DWORD GetRowsetSize() const;
```

### <a name="return-value"></a>Valor retornado

O número de linhas para recuperar durante uma determinada busca.

### <a name="remarks"></a>Comentários

Se você estiver usando a busca de linhas em massa, o tamanho padrão do conjunto de linhas quando o conjunto de registros é aberto é de 25; caso contrário, é 1.

Para implementar a busca de linhas `CRecordset::useMultiRowFetch` em massa, você deve especificar a opção no parâmetro *dwOptions* da função [Membro Aberto.](#open) Para alterar a configuração para o tamanho do conjunto de linhas, chame [SetRowsetSize](#setrowsetsize).

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="crecordsetgetrowsfetched"></a><a name="getrowsfetched"></a>CRecordset::GetRowsFetched

Determina quantos registros foram recuperados após uma busca.

```
DWORD GetRowsFetched() const;
```

### <a name="return-value"></a>Valor retornado

O número de linhas recuperadas da fonte de dados após uma determinada busca.

### <a name="remarks"></a>Comentários

Isso é útil quando você implementou a busca de linhas em massa. O tamanho do conjunto de linhas normalmente indica quantas linhas serão recuperadas de uma busca; no entanto, o número total de linhas no conjunto de registros também afeta quantas linhas serão recuperadas em um conjunto de linhas. Por exemplo, se o seu conjunto de registros tiver 10 registros com uma configuração de tamanho de conjunto de linhas de 4, então fazer looping através do conjunto de registros por chamada `MoveNext` resultará no conjunto de linhas final com apenas 2 registros.

Para implementar a busca de linhas `CRecordset::useMultiRowFetch` em massa, você deve especificar a opção no parâmetro *dwOptions* da função [Membro Aberto.](#open) Para especificar o tamanho do conjunto de linhas, chame [SetRowsetSize](#setrowsetsize).

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#24](../../mfc/codesnippet/cpp/crecordset-class_8.cpp)]

## <a name="crecordsetgetrowstatus"></a><a name="getrowstatus"></a>CRecordset::GetRowStatus

Obtém o status de uma linha no conjunto de linhas atual.

```
WORD GetRowStatus(WORD wRow) const;
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A posição de uma linha no conjunto de linhas atual. Este valor pode variar de 1 até o tamanho do conjunto de linhas.

### <a name="return-value"></a>Valor retornado

Um valor de status para a linha. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

`GetRowStatus`retorna um valor que indica qualquer alteração de status para a linha desde que foi recuperado pela última vez da fonte de dados, ou que nenhuma linha correspondente a *wRow* foi buscada. A tabela a seguir lista os possíveis valores de retorno.

|Valor de status|Descrição|
|------------------|-----------------|
|SQL_ROW_SUCCESS|A fila está inalterada.|
|SQL_ROW_UPDATED|A linha foi atualizada.|
|SQL_ROW_DELETED|A linha foi excluída.|
|SQL_ROW_ADDED|A linha foi adicionada.|
|SQL_ROW_ERROR|A linha é irrecuperável devido a um erro.|
|SQL_ROW_NOROW|Não há nenhuma linha que corresponda a *wRow*.|

Para obter mais informações, consulte a `SQLExtendedFetch` função DePi ODBC no SDK do Windows.

## <a name="crecordsetgetstatus"></a><a name="getstatus"></a>CRecordset::GetStatus

Determina o índice do registro atual no conjunto de registros e se o último registro foi visto.

```cpp
void GetStatus(CRecordsetStatus& rStatus) const;
```

### <a name="parameters"></a>Parâmetros

*rStatus*<br/>
Uma referência a um objeto `CRecordsetStatus`. Para obter mais informações, consulte a seção Comentários.

### <a name="remarks"></a>Comentários

`CRecordset`tentativas de rastrear o índice, mas em algumas circunstâncias isso pode não ser possível. Consulte [GetRecordCount](#getrecordcount) para obter uma explicação.

A `CRecordsetStatus` estrutura tem a seguinte forma:

```cpp
struct CRecordsetStatus
{
    long m_lCurrentRecord;
    BOOL m_bRecordCountFinal;
};
```

Os dois `CRecordsetStatus` membros têm os seguintes significados:

- `m_lCurrentRecord`Contém o índice baseado em zero do registro atual no conjunto de registros, se conhecido. Se o índice não puder ser determinado, este membro contém AFX_CURRENT_RECORD_UNDEFINED (-2). Se `IsBOF` for TRUE (conjunto de registros vazio ou `m_lCurrentRecord` tentativa de rolar antes do primeiro registro), então será definido como AFX_CURRENT_RECORD_BOF (-1). Se no primeiro disco, então é definido para 0, segundo recorde 1, e assim por diante.

- `m_bRecordCountFinal`Não zero se o número total de registros no conjunto de registros tiver sido determinado. Geralmente isso deve ser feito começando no início do `MoveNext` `IsEOF` conjunto de registros e chamando até que o retorno não seja zero. Se este membro for zero, a `GetRecordCount`contagem de registros retornada por , se não -1, é apenas uma contagem de "marca d'água alta" dos registros.

## <a name="crecordsetgetsql"></a><a name="getsql"></a>CRecordset::GetSQL

Ligue para esta função de membro para obter a declaração SQL que foi usada para selecionar os registros do conjunto de registros quando ele foi aberto.

```
const CString& GetSQL() const;
```

### <a name="return-value"></a>Valor retornado

Uma **referência const** a um `CString` que contém a declaração SQL.

### <a name="remarks"></a>Comentários

Esta será geralmente uma declaração SQL **SELECT.** A seqüência `GetSQL` retornada é somente leitura.

A seqüência `GetSQL` retornada é tipicamente diferente de qualquer string que você pode ter passado `Open` para o conjunto de registros no parâmetro *lpszSQL* para a função membro. Isso porque o conjunto de registros constrói uma declaração SQL completa com base no que você `Open`passou, `m_strFilter` `m_strSort` o que você especificou com o ClassWizard, o que você pode ter especificado nos membros e dados e quaisquer parâmetros que você possa ter especificado. Para obter detalhes sobre como o conjunto de registros constrói essa declaração SQL, consulte o artigo [Recordset: How Recordsets Select Records (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

> [!NOTE]
> Chame esta função de membro somente depois de chamar [Open](#open).

## <a name="crecordsetgettablename"></a><a name="gettablename"></a>CRecordset::GetTableName

Obtém o nome da tabela SQL na qual a consulta do conjunto de registros é baseada.

```
const CString& GetTableName() const;
```

### <a name="return-value"></a>Valor retornado

Uma **referência const** a um `CString` que contenha o nome da tabela, se o conjunto de registros for baseado em uma tabela; caso contrário, uma corda vazia.

### <a name="remarks"></a>Comentários

`GetTableName`só é válido se o conjunto de registros for baseado em uma tabela, não em uma junta de várias tabelas ou em uma consulta predefinida (procedimento armazenado). O nome é somente leitura.

> [!NOTE]
> Chame esta função de membro somente depois de chamar [Open](#open).

## <a name="crecordsetisbof"></a><a name="isbof"></a>Conjunto de registros::IsBOF

Retorna não zero se o conjunto de registros tiver sido posicionado antes do primeiro registro. Não há nenhum registro atual.

```
BOOL IsBOF() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros não contiver registros ou se você tiver rolado para trás antes do primeiro registro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro antes de rolar de registro para gravar para saber se você já foi antes do primeiro registro do conjunto de discos. Você também `IsBOF` pode `IsEOF` usar junto para determinar se o conjunto de registros contém algum registro ou está vazio. Imediatamente após a `Open`chamada, se o conjunto `IsBOF` de registros não contiver registros, retorna não zero. Quando você abre um conjunto de discos que tem pelo menos `IsBOF` um disco, o primeiro disco é o disco atual e retorna 0.

Se o primeiro registro for o `MovePrev` `IsBOF` registro atual e você ligar, posteriormente retornará sem zero. Se `IsBOF` retornar não zero `MovePrev`e você ligar, um erro ocorrerá. Se `IsBOF` o retorno não for zero, o registro atual é indefinido e qualquer ação que exija um registro atual resultará em um erro.

### <a name="example"></a>Exemplo

Este exemplo `IsBOF` `IsEOF` usa e para detectar os limites de um conjunto de registros à medida que o código rola pelo conjunto de registros em ambas as direções.

[!code-cpp[NVC_MFCDatabase#25](../../mfc/codesnippet/cpp/crecordset-class_9.cpp)]

## <a name="crecordsetisdeleted"></a><a name="isdeleted"></a>Configuração de registro de c::''''''''''''''''''

Determina se o registro atual foi excluído.

```
BOOL IsDeleted() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros estiver posicionado em um registro excluído; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se você rolar para `IsDeleted` um registro e retornar TRUE (não zero), então você deve rolar para outro registro antes de executar quaisquer outras operações de conjunto de discos.

O resultado `IsDeleted` depende de muitos fatores, como o seu tipo de conjunto de registros, `CRecordset::skipDeletedRecords` se o seu conjunto de registros é updatable, se você especificou a opção quando abriu o conjunto de registros, se o driver embala registros excluídos e se há vários usuários.

Para obter `CRecordset::skipDeletedRecords` mais informações sobre e embalagem do driver, consulte a função [Open](#open) member.

> [!NOTE]
> Se você implementou a busca em `IsDeleted`linha em massa, você não deve chamar . Em vez disso, chame a função [membro GetRowStatus.](#getrowstatus) Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="crecordsetiseof"></a><a name="iseof"></a>CRecordset::IsEOF

Retorna não zero se o conjunto de registros tiver sido posicionado após o último registro. Não há nenhum registro atual.

```
BOOL IsEOF() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros não contiver registros ou se você tiver rolado além do último registro; caso contrário, 0.

### <a name="remarks"></a>Comentários

Chame esta função de membro enquanto você rola de registro para registro para saber se você foi além do último registro do conjunto de discos. Você também `IsEOF` pode usar para determinar se o conjunto de registros contém algum registro ou está vazio. Imediatamente após a `Open`chamada, se o conjunto `IsEOF` de registros não contiver registros, retorna não zero. Quando você abre um conjunto de discos que tem pelo menos `IsEOF` um disco, o primeiro disco é o disco atual e retorna 0.

Se o último registro for o `MoveNext` `IsEOF` registro atual quando você ligar, posteriormente retornará não zero. Se `IsEOF` retornar não zero `MoveNext`e você ligar, um erro ocorrerá. Se `IsEOF` o retorno não for zero, o registro atual é indefinido e qualquer ação que exija um registro atual resultará em um erro.

### <a name="example"></a>Exemplo

Veja o exemplo de [IsBOF](#isbof).

## <a name="crecordsetisfielddirty"></a><a name="isfielddirty"></a>CRecordset::IsFieldDirty

Determina se o membro de dados de campo especificado foi alterado desde [que Edit](#edit) ou [AddNew](#addnew) foi chamado.

```
BOOL IsFieldDirty(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos está sujo.

### <a name="return-value"></a>Valor retornado

Não zero se o membro de dados `AddNew` `Edit`de campo especificado tiver sido alterado desde a chamada ou ; caso contrário, 0.

### <a name="remarks"></a>Comentários

Os dados em todos os membros de dados de campo sujo serão transferidos para o registro na fonte de `Edit` `AddNew`dados quando o registro atual for atualizado por uma chamada para a função de membro [update](#update) de `CRecordset` (após uma chamada para ou ).

> [!NOTE]
> Esta função de membro não é aplicável em conjuntos de registros que estão usando a busca de linhas em massa. Se você implementou a busca `IsFieldDirty` em linha em massa, então sempre retornará FALSE e resultará em uma afirmação falha. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

A `IsFieldDirty` chamada redefinirá os efeitos das chamadas anteriores ao [SetFieldDirty,](#setfielddirty) uma vez que o status sujo do campo é reavaliado. No `AddNew` caso, se o valor de campo atual difere do valor pseudo nulo, o status do campo será definido como sujo. No `Edit` caso, se o valor de campo difere do valor armazenado em cache, então o status do campo será definido como sujo.

`IsFieldDirty`é implementado através [do DoFieldExchange](#dofieldexchange).

Para obter mais informações sobre a bandeira suja, consulte o artigo [Recordset: How Recordsets Select Records (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

## <a name="crecordsetisfieldnull"></a><a name="isfieldnull"></a>CRecordset::IsFieldNull

Retorna não zero se o campo especificado no registro atual for Nulo (não tem valor).

```
BOOL IsFieldNull(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos é Nulo.

### <a name="return-value"></a>Valor retornado

Não zero se o membro de dados de campo especificado for sinalizado como Nulo; caso contrário, 0.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro para determinar se o membro de dados de campo especificado de um conjunto de registros foi sinalizado como Nulo. (Na terminologia do banco de dados, Nulo significa "não ter valor" e não é o mesmo que NULL em C++.) Se um membro de dados de campo for sinalizado como Nulo, ele será interpretado como uma coluna do registro atual para o qual não há valor.

> [!NOTE]
> Esta função de membro não é aplicável em conjuntos de registros que estão usando a busca de linhas em massa. Se você implementou a busca `IsFieldNull` em linha em massa, então sempre retornará FALSE e resultará em uma afirmação falha. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

`IsFieldNull`é implementado através [do DoFieldExchange](#dofieldexchange).

## <a name="crecordsetisfieldnullable"></a><a name="isfieldnullable"></a>CRecordset::IsFieldNullable

Retorna não zero se o campo especificado no registro atual pode ser definido como Nulo (sem valor).

```
BOOL IsFieldNullable(void* pv);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Um ponteiro para o membro de dados de campo cujo status você deseja verificar, ou NULL para determinar se algum dos campos pode ser definido como um valor Nulo.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro para determinar se o membro de dados de campo especificado é "nulo" (pode ser definido como um valor nulo; C++ NULL não é o mesmo que Null, que, na terminologia do banco de dados, significa "não ter valor").

> [!NOTE]
> Se você implementou a busca em `IsFieldNullable`linha em massa, você não pode chamar . Em vez disso, ligue para a função [membro GetODBCFieldInfo](#getodbcfieldinfo) para determinar se um campo pode ser definido como um valor nulo. Note que você `GetODBCFieldInfo`sempre pode ligar, independentemente de ter implementado a busca em linha em massa. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Um campo que não pode ser nulo deve ter um valor. Se você tentar definir um campo como Nulo ao adicionar ou atualizar um registro, a fonte de dados rejeitará a adição ou atualização e [updatearei](#update) uma exceção. A exceção ocorre `Update`quando você chama , não quando você chama [SetFieldNull](#setfieldnull).

O uso de NULL para o primeiro argumento `outputColumn` da `param` função aplicará a função apenas aos campos, não aos campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

definirá `outputColumn` apenas campos para NULA; `param` campos não serão afetados.

Para trabalhar `param` em campos, você deve fornecer `param` o endereço real do indivíduo em que deseja trabalhar, tais como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que `param` você não pode definir `outputColumn` todos os campos como NULA, como você pode com campos.

`IsFieldNullable`é implementado através [do DoFieldExchange](#dofieldexchange).

## <a name="crecordsetisopen"></a><a name="isopen"></a>CRecordset::IsOpen

Determina se o conjunto de registros já está aberto.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se a função de membro [Open](#open) ou [Requery](#requery) do objeto recordset tiver sido previamente chamada e o conjunto de registros não tiver sido fechado; caso contrário, 0.

## <a name="crecordsetm_hstmt"></a><a name="m_hstmt"></a>CRecordset::m_hstmt

Contém uma alça para a estrutura de dados de declaração ODBC, do tipo HSTMT, associada ao conjunto de registros.

### <a name="remarks"></a>Comentários

Cada consulta a uma fonte de dados ODBC está associada a um HSTMT.

> [!CAUTION]
> Não use `m_hstmt` antes [de Abrir](#open) ter sido chamado.

Normalmente você não precisa acessar o HSTMT diretamente, mas você pode precisar dele para execução direta de instruções SQL. A `ExecuteSQL` função membro `CDatabase` da classe `m_hstmt`fornece um exemplo de uso .

## <a name="crecordsetm_nfields"></a><a name="m_nfields"></a>Conjunto de registros de c::m_nFields

Contém o número de membros de dados de campo na classe recordset; ou seja, o número de colunas selecionadas pelo conjunto de registros a partir da fonte de dados.

### <a name="remarks"></a>Comentários

O construtor para a classe recordset deve inicializar `m_nFields` com o número correto. Se você não tiver implementado a busca em linha em massa, o ClassWizard escreverá esta inicialização para você quando você usá-la para declarar sua classe de conjunto de registros. Você também pode escrevê-lo manualmente.

O framework usa esse número para gerenciar a interação entre os membros de dados de campo e as colunas correspondentes do registro atual na fonte de dados.

> [!CAUTION]
> Este número deve corresponder ao número de "colunas de saída" registradas dentro `DoFieldExchange` ou `DoBulkFieldExchange` após uma chamada para [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) com o parâmetro `CFieldExchange::outputColumn`.

Você pode vincular colunas dinamicamente, conforme explicado no artigo "Recordset: Dynamically Binding Data Columns". Se você fizer isso, você deve `m_nFields` aumentar a contagem para refletir o número `DoFieldExchange` `DoBulkFieldExchange` de chamadas de função RFX ou Bulk RFX em sua função ou membro para as colunas dinamicamente vinculadas.

Para obter mais informações, consulte os artigos [Recordset: Dynamically Binding Data Columns (ODBC)](../../data/odbc/recordset-dynamically-binding-data-columns-odbc.md) e [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

Veja o artigo [Record Field Exchange: Usando RFX](../../data/odbc/record-field-exchange-using-rfx.md).

## <a name="crecordsetm_nparams"></a><a name="m_nparams"></a>CRecordset::m_nParams

Contém o número de membros de dados de parâmetros na classe recordset; ou seja, o número de parâmetros passados com a consulta do conjunto de registros.

### <a name="remarks"></a>Comentários

Se a sua classe de conjunto de registros tiver algum membro `m_nParams` de dados de parâmetro, o construtor da classe deve inicializar com o número correto. O valor `m_nParams` da inadimplência para 0. Se você adicionar membros de dados de parâmetros (o que você deve fazer manualmente) você também deve adicionar manualmente uma inicialização no construtor de `m_strFilter` `m_strSort` classe para refletir o número de parâmetros (que deve ser pelo menos tão grande quanto o número de espaços reservados '' em sua ou string).

O framework usa esse número quando parametriza a consulta do conjunto de registros.

> [!CAUTION]
> Este número `DoFieldExchange` deve corresponder ao número de "params" registrados dentro ou `DoBulkFieldExchange` após uma chamada para `CFieldExchange::inoutParam` [SetFieldType](../../mfc/reference/cfieldexchange-class.md#setfieldtype) com um valor de parâmetro de `CFieldExchange::inputParam`, `CFieldExchange::param`, `CFieldExchange::outputParam`ou .

### <a name="example"></a>Exemplo

  Veja os artigos [Recordset: Parametrização de um Conjunto de Registros (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md) e [Troca de Campo de Registro: Usando RFX](../../data/odbc/record-field-exchange-using-rfx.md).

## <a name="crecordsetm_pdatabase"></a><a name="m_pdatabase"></a>Configuração de crecord::m_pDatabase

Contém um ponteiro `CDatabase` para o objeto através do qual o conjunto de registros está conectado a uma fonte de dados.

### <a name="remarks"></a>Comentários

Esta variável é definida de duas maneiras. Normalmente, você passa um ponteiro `CDatabase` para um objeto já conectado quando constrói o objeto recordset. Se você passar `CRecordset` NULL `CDatabase` em vez disso, criará um objeto para você e o conectará. Em ambos `CRecordset` os casos, armazena o ponteiro nesta variável.

Normalmente você não precisará usar diretamente `m_pDatabase`o ponteiro armazenado em . Se você escrever suas `CRecordset`próprias extensões para, no entanto, você pode precisar usar o ponteiro. Por exemplo, você pode precisar do `CDBException`ponteiro se você jogar o seu próprio s. Ou você pode precisar dele se precisar `CDatabase` fazer algo usando o mesmo objeto, como executar `ExecuteSQL` transações, `CDatabase` definir tempos corridos ou ligar para a função de membro da classe para executar declarações SQL diretamente.

## <a name="crecordsetm_strfilter"></a><a name="m_strfilter"></a>CRecordset::m_strFilter

Depois de construir o objeto recordset, `Open` mas antes de chamar sua `CString` função de membro, use este membro de dados para armazenar uma cláusula SQL **WHERE.**

### <a name="remarks"></a>Comentários

O conjunto de registros usa essa seqüência para restringir `Open` `Requery` (ou filtrar) os registros que seleciona durante a chamada ou chamada. Isso é útil para selecionar um subconjunto de registros, como "todos os vendedores sediados na Califórnia" ("estado = CA"). A sintaxe ODBC SQL para uma cláusula **WHERE** é

`WHERE search-condition`

Observe que você não inclui a **palavra-chave WHERE** em sua seqüência. A estrutura fornece- lo.

Você também pode parametrizar sua seqüência de filtros colocando '' espaços reservados nele, declarando um membro de dados de parâmetro sumido em sua classe para cada espaço reservado e passando parâmetros para o conjunto de registros em tempo de execução. Isso permite que você construa o filtro em tempo de execução. Para obter mais informações, consulte o artigo [Recordset: Parametisizing a Recordset (ODBC)](../../data/odbc/recordset-parameterizing-a-recordset-odbc.md).

Para obter mais informações sobre as cláusulas SQL **WHERE,** consulte o artigo [SQL](../../data/odbc/sql.md). Para obter mais informações sobre a seleção e filtração de registros, consulte o artigo [Recordset: Filtering Records (ODBC)](../../data/odbc/recordset-filtering-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#30](../../mfc/codesnippet/cpp/crecordset-class_12.cpp)]

## <a name="crecordsetm_strsort"></a><a name="m_strsort"></a>Configuração de crecord::m_strSort

Depois de construir o objeto recordset, `Open` mas antes de chamar sua `CString` função de membro, use este membro de dados para armazenar um contendo uma cláusula SQL **ORDER BY.**

### <a name="remarks"></a>Comentários

O conjunto de registros usa essa seqüência `Open` `Requery` para classificar os registros que seleciona durante a chamada ou chamada. Você pode usar esse recurso para classificar um conjunto de gravações em uma ou mais colunas. A sintaxe ODBC SQL para uma cláusula **ORDER BY** é

`ORDER BY sort-specification [, sort-specification]...`

onde uma especificação de espécie é um inteiro ou um nome de coluna. Você também pode especificar ordem ascendente ou descendente (a ordem está subindo por padrão) anexando "ASC" ou "DESC" à lista de colunas na seqüência de classificação. Os registros selecionados são classificados primeiro pela primeira coluna listada, depois pela segunda, e assim por diante. Por exemplo, você pode solicitar um conjunto de registros "Clientes" pelo sobrenome e, em seguida, primeiro nome. O número de colunas que você pode listar depende da fonte de dados. Para obter mais informações, consulte o Windows SDK.

Observe que você não inclui a palavra-chave **ORDER BY** em sua seqüência. A estrutura fornece- lo.

Para obter mais informações sobre cláusulas SQL, consulte o artigo [SQL](../../data/odbc/sql.md). Para obter mais informações sobre a classificação de registros, consulte o artigo [Recordset: Sorting Records (ODBC)](../../data/odbc/recordset-sorting-records-odbc.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#31](../../mfc/codesnippet/cpp/crecordset-class_13.cpp)]

## <a name="crecordsetmove"></a><a name="move"></a>CRecordset::Mover

Move o ponteiro de registro atual dentro do conjunto de registros, seja para frente ou para trás.

```
virtual void Move(
    long nRows,
    WORD wFetchType = SQL_FETCH_RELATIVE);
```

### <a name="parameters"></a>Parâmetros

*nRows*<br/>
O número de linhas para avançar ou para trás. Valores positivos avançam, no final do conjunto de registros. Valores negativos se movem para trás, em direção ao início.

*Wfetchtype*<br/>
Determina o conjunto `Move` de linhas que será buscado. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Se você passar um valor de `Move` 0 para *nRows,* atualizará o registro atual; `Move` terminará qualquer `AddNew` `Edit` corrente ou modo, e restaurará `AddNew` o `Edit` valor do registro atual antes ou foi chamado.

> [!NOTE]
> Quando você passa por um conjunto de registros, você não pode pular registros excluídos. Consulte [CRecordset::IsDeleted](#isdeleted) para obter mais informações. Quando você `CRecordset` abre `skipDeletedRecords` um com `Move` o conjunto de opções, afirma se o parâmetro *nRows* é 0. Esse comportamento impede a atualização de linhas que são excluídas por outros aplicativos clientes usando os mesmos dados. Consulte o parâmetro *dwOption* em [Open](#open) para obter uma descrição de `skipDeletedRecords`.

`Move`reposiciona o conjunto de registros por conjuntos de linhas. Com base nos valores para *nRows* e *wFetchType,* `Move` busca o conjunto de linhas apropriado e, em seguida, faz o primeiro registro nessa linha definir o registro atual. Se você não tiver implementado a busca de linhas em massa, então o tamanho do conjunto de linhas é sempre 1. Ao buscar um conjunto `Move` de linhas, chama diretamente a função de membro [CheckRowsetError](#checkrowseterror) para lidar com quaisquer erros resultantes da busca.

Dependendo dos valores `Move` que você `CRecordset` passar, é equivalente a outras funções de membro. Em particular, o valor do *wFetchType* pode indicar uma função de membro mais intuitiva e, muitas vezes, o método preferido para mover o registro atual.

A tabela a seguir lista os valores possíveis `Move` para *wFetchType*, o conjunto de linhas que irá buscar com base em *wFetchType* e *nRows,* e qualquer função de membro equivalente correspondente ao *wFetchType*.

|Wfetchtype|Conjunto de linhas buscados|Função de membro equivalente|
|----------------|--------------------|--------------------------------|
|SQL_FETCH_RELATIVE (o valor padrão)|O conjunto de linhas de linha *de* linha de linha de linha de linha de linha de linha a partir da primeira linha no conjunto de linhas atual.||
|SQL_FETCH_NEXT|O próximo conjunto de linhas; *nRows* é ignorado.|[MoveNext](#movenext)|
|SQL_FETCH_PRIOR|O conjunto de linhas anterior; *nRows* é ignorado.|[Moveprev](#moveprev)|
|SQL_FETCH_FIRST|O primeiro conjunto de linhas no conjunto de registros; *nRows* é ignorado.|[MoveFirst](#movefirst)|
|SQL_FETCH_LAST|A última linha completa no conjunto de registros; *nRows* é ignorado.|[Movelast](#movelast)|
|SQL_FETCH_ABSOLUTE|Se *nRows* > 0, o conjunto de linhas iniciando *nRows(s)* desde o início do conjunto de registros. Se *nRows* < 0, o conjunto de linhas de linha iniciando *nRows* a partir do final do conjunto de registros. Se *nRows* = 0, então uma condição de início de arquivo (BOF) é devolvida.|[Setabsoluteposition](#setabsoluteposition)|
|SQL_FETCH_BOOKMARK|O conjunto de linhas a partir da linha cujo valor de marcador corresponde a *nRows*.|[Setbookmark](#setbookmark)|

> [!NOTE]
> Para conjuntos de `Move` registros somente para frente, só é válido com um valor de SQL_FETCH_NEXT para *wFetchType*.

> [!CAUTION]
> Chamar `Move` abre uma exceção se o conjunto de discos não tiver registros. Para determinar se o conjunto de registros possui registros, ligue para [IsBOF](#isbof) e [IsEOF](#iseof).

> [!NOTE]
> Se você tiver rolado além do início`IsBOF` ou `IsEOF` final do conjunto `Move` de registros `CDBException`(ou retorna não zero), chamar uma função possivelmente lançará um . Por exemplo, `IsEOF` se retornar `IsBOF` não zero `MoveNext` e não o `MovePrev` fizer, então lançará uma exceção, mas não o fará.

> [!NOTE]
> Se você `Move` ligar enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Para obter mais informações sobre navegação por conjunto de registros, consulte os artigos [Recordset: Scrolling (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Para obter informações relacionadas, consulte `SQLExtendedFetch` a função API ODBC no SDK do Windows.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#28](../../mfc/codesnippet/cpp/crecordset-class_14.cpp)]

## <a name="crecordsetmovefirst"></a><a name="movefirst"></a>CRecordset::MoveFirst

Faz o primeiro disco na primeira fila definir o recorde atual.

```cpp
void MoveFirst();
```

### <a name="remarks"></a>Comentários

Independentemente de ter sido implementado o busto de linhas em massa, este será sempre o primeiro registro no conjunto de discos.

Você não precisa `MoveFirst` ligar imediatamente depois de abrir o conjunto de registros. Nesse momento, o primeiro registro (se houver) é automaticamente o registro atual.

> [!NOTE]
> Esta função de membro não é válida para conjuntos de registros somente para frente.

> [!NOTE]
> Quando você passa por um conjunto de registros, você não pode pular registros excluídos. Consulte a função [membro IsDeleted](#isdeleted) para obter detalhes.

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Para determinar se o conjunto de `IsBOF` `IsEOF`registros tem algum registro, chamada e .

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Para obter mais informações sobre navegação por conjunto de registros, consulte os artigos [Recordset: Scrolling (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsBOF](#isbof).

## <a name="crecordsetmovelast"></a><a name="movelast"></a>CRecordset::MoveLast

Faz o primeiro disco na última linha completa definir o recorde atual.

```cpp
void MoveLast();
```

### <a name="remarks"></a>Comentários

Se você não implementou a busca de linhas em massa, seu `MoveLast` conjunto de registros tem um tamanho de linha de 1, então simplesmente se move para o último registro no conjunto de registros.

> [!NOTE]
> Esta função de membro não é válida para conjuntos de registros somente para frente.

> [!NOTE]
> Quando você passa por um conjunto de registros, você não pode pular registros excluídos. Consulte a função [membro IsDeleted](#isdeleted) para obter detalhes.

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Para determinar se o conjunto de `IsBOF` `IsEOF`registros tem algum registro, chamada e .

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Para obter mais informações sobre navegação por conjunto de registros, consulte os artigos [Recordset: Scrolling (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsBOF](#isbof).

## <a name="crecordsetmovenext"></a><a name="movenext"></a>CRecordset::MoveNext

Faz o primeiro disco na próxima linha definir o recorde atual.

```cpp
void MoveNext();
```

### <a name="remarks"></a>Comentários

Se você não implementou a busca de linhas em massa, seu `MoveNext` conjunto de registros tem um tamanho de linha de 1, então simplesmente se move para o próximo registro.

> [!NOTE]
> Quando você passa por um conjunto de registros, você não pode pular registros excluídos. Consulte a função [membro IsDeleted](#isdeleted) para obter detalhes.

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Para determinar se o conjunto de `IsBOF` `IsEOF`registros tem algum registro, chamada e .

> [!NOTE]
> Também é recomendável que `IsEOF` você `MoveNext`ligue antes de ligar. Por exemplo, se você tiver rolado além `IsEOF` do fim do conjunto de registros, retornará não zero; uma chamada `MoveNext` subseqüente para lançar uma exceção.

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Para obter mais informações sobre navegação por conjunto de registros, consulte os artigos [Recordset: Scrolling (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsBOF](#isbof).

## <a name="crecordsetmoveprev"></a><a name="moveprev"></a>CRecordset::MovePrev

Faz o primeiro disco na linha anterior definir o recorde atual.

```cpp
void MovePrev();
```

### <a name="remarks"></a>Comentários

Se você não tiver implementado a busca de linhas em massa, `MovePrev` seu conjunto de registros tem um tamanho de linha de 1, então simplesmente se move para o registro anterior.

> [!NOTE]
> Esta função de membro não é válida para conjuntos de registros somente para frente.

> [!NOTE]
> Quando você passa por um conjunto de registros, você não pode pular registros excluídos. Consulte a função [membro IsDeleted](#isdeleted) para obter detalhes.

> [!CAUTION]
> Chamar qualquer `Move` uma das funções abre uma exceção se o conjunto de registros não tiver registros. Para determinar se o conjunto de `IsBOF` `IsEOF`registros tem algum registro, chamada e .

> [!NOTE]
> Também é recomendável que `IsBOF` você `MovePrev`ligue antes de ligar. Por exemplo, se você tiver rolado antes do `IsBOF` início do conjunto de registros, retornará não zero; uma chamada `MovePrev` subseqüente para lançar uma exceção.

> [!NOTE]
> Se você ligar `Move` para qualquer uma das funções enquanto o registro atual estiver sendo atualizado ou adicionado, as atualizações serão perdidas sem aviso prévio.

Para obter mais informações sobre navegação por conjunto de registros, consulte os artigos [Recordset: Scrolling (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md). Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsBOF](#isbof).

## <a name="crecordsetonsetoptions"></a><a name="onsetoptions"></a>Configuração de registro de c::Opções de gravação

Chamado para definir opções (usadas na seleção) para a declaração ODBC especificada.

```
virtual void OnSetOptions(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*hstmt*<br/>
O HSTMT da declaração ODBC cujas opções devem ser definidas.

### <a name="remarks"></a>Comentários

Chamada `OnSetOptions` para definir opções (usadas na seleção) para a declaração ODBC especificada. O framework chama essa função de membro para definir as opções iniciais para o conjunto de registros. `OnSetOptions`determina o suporte da fonte de dados para cursores roláveis e para a concorrência do cursor e define as opções do conjunto de registros de acordo. (Considerando `OnSetOptions` que é usado `OnSetUpdateOptions` para operações de seleção, é usado para operações de atualização.)

Substituir `OnSetOptions` para definir opções específicas para o driver ou a fonte de dados. Por exemplo, se sua fonte de dados suportar a `OnSetOptions` abertura para acesso exclusivo, você pode substituir para tirar proveito dessa capacidade.

Para obter mais informações sobre cursores, consulte o artigo [ODBC](../../data/odbc/odbc-basics.md).

## <a name="crecordsetonsetupdateoptions"></a><a name="onsetupdateoptions"></a>CRecordset::OndaConfiguraçãoOpções de atualização

Chamado para definir opções (usadas na atualização) para a declaração ODBC especificada.

```
virtual void OnSetUpdateOptions(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*hstmt*<br/>
O HSTMT da declaração ODBC cujas opções devem ser definidas.

### <a name="remarks"></a>Comentários

Chamada `OnSetUpdateOptions` para definir opções (usadas na atualização) para a declaração ODBC especificada. O framework chama essa função de membro depois de criar um HSTMT para atualizar registros em um conjunto de registros. (Considerando `OnSetOptions` que é usado `OnSetUpdateOptions` para operações de seleção, é usado para operações de atualização.) `OnSetUpdateOptions` determina o suporte da fonte de dados para cursores roláveis e para a concorrência do cursor e define as opções do conjunto de registros de acordo.

Substituir `OnSetUpdateOptions` para definir opções de uma declaração ODBC antes que essa declaração seja usada para acessar um banco de dados.

Para obter mais informações sobre cursores, consulte o artigo [ODBC](../../data/odbc/odbc-basics.md).

## <a name="crecordsetopen"></a><a name="open"></a>CRecordset::Abrir

Abre o conjunto de registros recuperando a tabela ou realizando a consulta que o conjunto de registros representa.

```
virtual BOOL Open(
    UINT nOpenType = AFX_DB_USE_DEFAULT_TYPE,
    LPCTSTR lpszSQL = NULL,
    DWORD dwOptions = none);
```

### <a name="parameters"></a>Parâmetros

*nOpenType*<br/>
Aceite o valor padrão, AFX_DB_USE_DEFAULT_TYPE ou use um `enum OpenType`dos seguintes valores a partir do :

- `CRecordset::dynaset`Um conjunto de registros com rolagem bidirecional. A adesão e a ordenação dos registros são determinadas quando o conjunto de registros é aberto, mas as alterações feitas por outros usuários aos valores de dados são visíveis após uma operação de busca. Dynasets também são conhecidos como conjuntos de registros orientados por keysets.

- `CRecordset::snapshot`Um conjunto de registros estáticos com rolagem bidirecional. A adesão e a ordenação dos registros são determinadas quando o conjunto de registros é aberto; os valores dos dados são determinados quando os registros são buscados. As alterações feitas por outros usuários não são visíveis até que o conjunto de registros seja fechado e, em seguida, reaberto.

- `CRecordset::dynamic`Um conjunto de registros com rolagem bidirecional. As alterações feitas por outros usuários aos valores de adesão, pedidos e dados são visíveis após uma operação de busca. Note que muitos drivers ODBC não suportam esse tipo de conjunto de registros.

- `CRecordset::forwardOnly`Um conjunto de registros somente leitura com apenas rolagem para a frente.

   Para `CRecordset`, o `CRecordset::snapshot`valor padrão é . O mecanismo de valor padrão permite que os assistentes Visuais `CRecordset` C++ `CDaoRecordset`interajam com o ODBC e o DAO, que têm padrões diferentes.

Para obter mais informações sobre esses tipos de conjuntos de registros, consulte o artigo [Recordset (ODBC)](../../data/odbc/recordset-odbc.md). Para obter informações relacionadas, consulte o artigo "Usando cursors de bloco e roláveis" no SDK do Windows.

> [!CAUTION]
> Se o tipo solicitado não for suportado, o quadro será uma exceção.

*lpszSQL*<br/>
Um ponteiro de string contendo um dos seguintes:

- Um ponteiro NULL.

- O nome de uma tabela.

- Uma declaração SQL **SELECT** (opcionalmente com uma cláusula SQL **WHERE** ou **ORDER BY).**

- Uma **declaração DE CHAMADA** especificando o nome de uma consulta predefinida (procedimento armazenado). Tenha cuidado para não inserir espaço em branco entre a cinta encaracolada e a palavra-chave **CALL.**

Para obter mais informações sobre essa seqüência, consulte a tabela e a discussão do papel do ClassWizard na seção [Observações.](#remarks)

> [!NOTE]
> A ordem das colunas no seu conjunto de resultados deve corresponder à ordem das chamadas de função RFX ou Bulk RFX em sua substituição da função [DoFieldExchange](#dofieldexchange) ou [DoBulkFieldExchange.](#dobulkfieldexchange)

*dwOptions*<br/>
Uma máscara de bit que pode especificar uma combinação dos valores listados abaixo. Algumas delas são mutuamente exclusivas. O valor padrão não é **nenhum**.

- `CRecordset::none`Sem opções definidas. Este valor de parâmetro é mutuamente exclusivo com todos os outros valores. Por padrão, o conjunto de registros pode ser atualizado com [Editar](#edit) ou [Excluir](#delete) e permite anexar novos registros com [AddNew](#addnew). A updatability depende da fonte de dados, bem como da opção *nOpenType* especificada. A otimização para adições em massa não está disponível. A busca em linha em massa não será implementada. Os registros excluídos não serão ignorados durante a navegação do conjunto de registros. Os marcadores não estão disponíveis. A verificação automática de campo sujo é implementada.

- `CRecordset::appendOnly`Não permita `Edit` `Delete` ou no conjunto de registros. Permita `AddNew` apenas. Esta opção é mutuamente exclusiva com `CRecordset::readOnly`.

- `CRecordset::readOnly`Abra o conjunto de registros apenas como leitura. Esta opção é mutuamente exclusiva com `CRecordset::appendOnly`.

- `CRecordset::optimizeBulkAdd`Use uma declaração SQL preparada para otimizar a adição de muitos registros ao mesmo tempo. Aplica-se somente se você não estiver usando `SQLSetPos` a função API ODBC para atualizar o conjunto de registros. A primeira atualização determina quais campos estão marcados como sujos. Esta opção é mutuamente exclusiva com `CRecordset::useMultiRowFetch`.

- `CRecordset::useMultiRowFetch`Implemente a busca de linhas em massa para permitir que várias linhas sejam recuperadas em uma única operação de busca. Este é um recurso avançado projetado para melhorar o desempenho; no entanto, a troca de campo de registro em massa não é suportada pelo ClassWizard. Esta opção é mutuamente exclusiva com `CRecordset::optimizeBulkAdd`. Observe que, `CRecordset::useMultiRowFetch`se você `CRecordset::noDirtyFieldCheck` especificar, a opção será ligada automaticamente (bufferduplo não estará disponível); em conjuntos de registros `CRecordset::useExtendedFetch` somente para a frente, a opção será ligada automaticamente. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

- `CRecordset::skipDeletedRecords`Pule todos os registros excluídos ao navegar pelo conjunto de registros. Isso vai retardar o desempenho em certas buscas relativas. Essa opção não é válida em conjuntos de registros somente para frente. Se você chamar [Mover](#move) com o parâmetro *nRows* definido como 0, e o `CRecordset::skipDeletedRecords` conjunto de opções, `Move` será afirmado. Note `CRecordset::skipDeletedRecords` que é semelhante à *embalagem do driver,* o que significa que as linhas excluídas são removidas do conjunto de registros. No entanto, se o seu driver embala registros, então ele pulará apenas os registros que você excluir; ele não pulará registros excluídos por outros usuários enquanto o conjunto de registros estiver aberto. `CRecordset::skipDeletedRecords`pulará linhas excluídas por outros usuários.

- `CRecordset::useBookmarks`Pode usar marcadores no conjunto de registros, se suportado. Os marcadores reduzem a recuperação de dados, mas melhoram o desempenho para navegação de dados. Não é válido em conjuntos de registros somente para a frente. Para obter mais informações, consulte o artigo [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

- `CRecordset::noDirtyFieldCheck`Desligue a verificação automática do campo sujo (buffer duplo). Isso vai melhorar o desempenho; no entanto, você deve marcar manualmente campos como sujos, chamando as `SetFieldDirty` funções e `SetFieldNull` membro. Observe que o buffer `CRecordset` duplo na classe é `CDaoRecordset`semelhante ao buffer duplo na classe . No entanto, em `CRecordset`, você não pode habilitar buffering duplo em campos individuais; você habilita-o para todos os campos ou desabilitá-lo para todos os campos. Observe que se você `CRecordset::useMultiRowFetch`especificar a opção, então `CRecordset::noDirtyFieldCheck` será ligado automaticamente; no `SetFieldDirty` entanto, e `SetFieldNull` não pode ser usado em conjuntos de registros que implementam a busca de linhas em massa.

- `CRecordset::executeDirect`Não use uma declaração SQL preparada. Para melhorar o desempenho, especifique esta opção se a `Requery` função de membro nunca será chamada.

- `CRecordset::useExtendedFetch`Implementar `SQLExtendedFetch` em `SQLFetch`vez de . Este foi projetado para implementar a busca de linhas em massa em conjuntos de discos somente para frente. Se você especificar a opção `CRecordset::useMultiRowFetch` em um `CRecordset::useExtendedFetch` conjunto de registros somente para frente, então será ligado automaticamente.

- `CRecordset::userAllocMultiRowBuffers`O usuário alocará buffers de armazenamento para os dados. Use esta opção `CRecordset::useMultiRowFetch` em conjunto com se você quiser alocar seu próprio armazenamento; caso contrário, a estrutura alocará automaticamente o armazenamento necessário. Para obter mais informações, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md). Observe que `CRecordset::userAllocMultiRowBuffers` especificar `CRecordset::useMultiRowFetch` sem especificar resultará em uma afirmação falha.

### <a name="return-value"></a>Valor retornado

Não zero `CRecordset` se o objeto foi aberto com sucesso; caso contrário 0 se [CDatabase::Abrir](../../mfc/reference/cdatabase-class.md#open) (se chamado) retorna 0.

### <a name="remarks"></a>Comentários

Você deve chamar esta função de membro para executar a consulta definida pelo conjunto de registros. Antes `Open`de chamar, você deve construir o objeto recordset.

A conexão desse conjunto de registros com a fonte de `Open`dados depende de como você constrói o conjunto de registros antes de ligar . Se você passar um objeto [CDatabase](../../mfc/reference/cdatabase-class.md) para o construtor do conjunto de registros que não foi conectado à fonte de dados, essa função de membro usará [GetDefaultConnect](#getdefaultconnect) para tentar abrir o objeto do banco de dados. Se você passar NULL para o construtor do conjunto `CDatabase` de registros, `Open` o construtor construirá um objeto para você e tentará conectar o objeto do banco de dados. Para obter detalhes sobre o fechamento do conjunto de registros e a conexão nessas circunstâncias variadas, consulte [Close](#close).

> [!NOTE]
> O acesso a uma `CRecordset` fonte de dados através de um objeto é sempre compartilhado. Ao `CDaoRecordset` contrário da classe, `CRecordset` você não pode usar um objeto para abrir uma fonte de dados com acesso exclusivo.

Quando você `Open`chama , uma consulta, geralmente uma declaração SQL **SELECT,** seleciona registros com base nos critérios mostrados na tabela a seguir.

|Valor do parâmetro lpszSQL|Os registros selecionados são determinados por|Exemplo|
|------------------------------------|----------------------------------------|-------------|
|NULO|A corda voltou `GetDefaultSQL`por .||
|Nome da tabela SQL|Todas as colunas da `DoFieldExchange` lista `DoBulkFieldExchange`de tabelas em ou .|`"Customer"`|
|Nome de consulta predefinida (procedimento armazenado)|As colunas que a consulta está definida para retornar.|`"{call OverDueAccts}"`|
|**Selecione** lista de **colunasDA** lista de tabela|As colunas especificadas das tabelas especificadas.|`"SELECT CustId, CustName FROM`<br /><br /> `Customer"`|

> [!CAUTION]
> Tenha cuidado para não inserir espaço em branco extra na sua seqüência SQL. Por exemplo, se você inserir espaço em branco entre a cinta encaracolada e a palavra-chave **CALL,** o MFC interpretará mal a seqüência SQL como um nome de tabela e a incorporará em uma instrução **SELECT,** o que resultará em uma exceção sendo lançada. Da mesma forma, se a consulta predefinida usar um parâmetro de saída, não insira espaço em branco entre a cinta encaracolada e o símbolo ''. Finalmente, você não deve inserir espaço em branco antes da cinta encaracolada em uma instrução **CALL** ou antes da palavra-chave **SELECT** em uma instrução **SELECT.**

O procedimento usual é `Open`passar NULL para; neste caso, `Open` chama [GetDefaultSQL](#getdefaultsql). Se você estiver usando `CRecordset` uma `GetDefaultSQL` classe derivada, dê o nome da tabela especificado no ClassWizard. Em vez disso, você `lpszSQL` pode especificar outras informações no parâmetro.

O que `Open` quer que você passe, constrói uma seqüência final de SQL para a consulta `lpszSQL` (a seqüência pode ter cláusulas SQL **WHERE** e ORDER **BY** anexadas à string que você passou) e, em seguida, executa a consulta. Você pode examinar a seqüência construída chamando [GetSQL](#getsql) depois de chamar `Open`. Para obter mais detalhes sobre como o conjunto de registros constrói uma declaração SQL e seleciona registros, consulte o artigo [Recordset: How Recordsets Select Records (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md).

Os membros de dados de campo da sua classe de conjunto de registros estão vinculados às colunas dos dados selecionados. Se algum registro for devolvido, o primeiro registro se torna o registro atual.

Se você quiser definir opções para o conjunto de registros, como um filtro ou classificar, especifique-as depois de construir o objeto do conjunto de registros, mas antes de chamar `Open`. Se você quiser atualizar os registros no conjunto de registros após o conjunto de registros já estar aberto, chame [Requery](#requery).

Para obter mais informações, incluindo exemplos adicionais, consulte os artigos [Recordset (ODBC)](../../data/odbc/recordset-odbc.md), [Recordset: How Recordsets Select Records (ODBC)](../../data/odbc/recordset-how-recordsets-select-records-odbc.md)e [Recordset: Creating and Closing Recordsets (ODBC)](../../data/odbc/recordset-creating-and-closing-recordsets-odbc.md).

### <a name="example"></a>Exemplo

Os exemplos de código a `Open` seguir mostram diferentes formas da chamada.

[!code-cpp[NVC_MFCDatabase#16](../../mfc/codesnippet/cpp/crecordset-class_15.cpp)]

## <a name="crecordsetrefreshrowset"></a><a name="refreshrowset"></a>CRecordset::RefreshRowset

Atualiza os dados e o status de uma linha no conjunto de linhas atual.

```cpp
void RefreshRowset(
    WORD wRow,
    WORD wLockType = SQL_LOCK_NO_CHANGE);
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A posição de uma linha no conjunto de linhas atual. Este valor pode variar de zero ao tamanho do conjunto de linhas.

*wLockType*<br/>
Um valor indicando como bloquear a linha depois de atualizada. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Se você passar um valor de zero para *wRow,* então todas as linhas do conjunto de linhas serão atualizadas.

Para `RefreshRowset`usar, você deve ter implementado a `CRecordset::useMulitRowFetch` busca em linha em massa especificando a opção na função [Membro Aberto.](#open)

`RefreshRowset`chama a função `SQLSetPos`API odbc . O parâmetro *wLockType* especifica o estado de `SQLSetPos` bloqueio da linha após a execução. A tabela a seguir descreve os valores possíveis para *wLockType*.

|wLockType|Descrição|
|---------------|-----------------|
|SQL_LOCK_NO_CHANGE (o valor padrão)|O driver ou fonte de dados garante que a linha esteja no `RefreshRowset` mesmo estado bloqueado ou desbloqueado como era antes.|
|SQL_LOCK_EXCLUSIVE|O driver ou a fonte de dados bloqueia a linha exclusivamente. Nem todas as fontes de dados suportam esse tipo de bloqueio.|
|SQL_LOCK_UNLOCK|O driver ou fonte de dados desbloqueia a linha. Nem todas as fontes de dados suportam esse tipo de bloqueio.|

Para obter `SQLSetPos`mais informações sobre, consulte o Windows SDK. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="crecordsetrequery"></a><a name="requery"></a>CRecordset:Requery

Reconstrói (atualiza) um conjunto de registros.

```
virtual BOOL Requery();
```

### <a name="return-value"></a>Valor retornado

Não zero se o conjunto de registros foi reconstruído com sucesso; caso contrário, 0.

### <a name="remarks"></a>Comentários

Se algum registro for devolvido, o primeiro registro se torna o registro atual.

Para que o conjunto de registros reflita as adições e exclusões que você ou outros usuários `Requery`estão fazendo para a fonte de dados, você deve reconstruir o conjunto de registros ligando . Se o conjunto de registros for um dynaset, ele reflete automaticamente as atualizações que você ou outros usuários fazem aos seus registros existentes (mas não adições). Se o conjunto de registros for `Requery` um instantâneo, você deve ligar para refletir edições de outros usuários, bem como adições e exclusões.

Para um dynaset ou um `Requery` snapshot, ligue quando quiser reconstruir o conjunto de registros usando um novo filtro ou classificação, ou novos valores de parâmetro. Defina o novo filtro ou a `m_strFilter` propriedade `m_strSort` classificar `Requery`atribuindo novos valores para e antes de chamar . Defina novos parâmetros atribuindo novos valores `Requery`aos membros de dados de parâmetros antes de chamar . Se as seqüências de filtro e classificação estiverem inalteradas, você poderá reutilizar a consulta, o que melhora o desempenho.

Se a tentativa de reconstruir o conjunto de registros falhar, o conjunto de registros será fechado. Antes de `Requery`ligar, você pode determinar se o conjunto `CanRestart` de registros pode ser regravado ligando para a função de membro. `CanRestart`não garante `Requery` que terá sucesso.

> [!CAUTION]
> Ligue `Requery` só depois de ter chamado [Open.](#open)

### <a name="example"></a>Exemplo

Este exemplo reconstrói um conjunto de registros para aplicar uma ordem de classificação diferente.

[!code-cpp[NVC_MFCDatabase#29](../../mfc/codesnippet/cpp/crecordset-class_16.cpp)]

## <a name="crecordsetsetabsoluteposition"></a><a name="setabsoluteposition"></a>CRecordset::SetAbsolutePosition

Posiciona o conjunto de registros no registro correspondente ao número de registro especificado.

```cpp
void SetAbsolutePosition(long nRows);
```

### <a name="parameters"></a>Parâmetros

*nRows*<br/>
A posição ordinal baseada em um para o registro atual no conjunto de registros.

### <a name="remarks"></a>Comentários

`SetAbsolutePosition`move o ponteiro de registro atual com base nesta posição ordinal.

> [!NOTE]
> Esta função de membro não é válida em conjuntos de registros somente para a frente.

Para os recordes da ODBC, uma configuração de posição absoluta de 1 refere-se ao primeiro registro no conjunto de registros; uma configuração de 0 refere-se à posição de início de arquivo (BOF).

Você também pode passar `SetAbsolutePosition`valores negativos para . Neste caso, a posição do conjunto de registros é avaliada a partir do final do conjunto de registros. Por exemplo, `SetAbsolutePosition( -1 )` move o ponteiro de registro atual para o último registro no conjunto de registros.

> [!NOTE]
> A posição absoluta não se destina a ser usada como um número recorde de substitutos. Os marcadores ainda são a maneira recomendada de reter e retornar a uma determinada posição, uma vez que a posição de um registro muda quando os registros anteriores são excluídos. Além disso, não é possível garantir que um determinado registro terá a mesma posição absoluta se o conjunto de registros for recriado novamente porque a ordem de registros individuais dentro de um conjunto de registros não é garantida a menos que seja criada com uma declaração SQL usando uma cláusula **ORDER BY.**

Para obter mais informações sobre navegação e marcadores do conjunto de registros, consulte os artigos [Recordset: Scrolling (ODBC)](../../data/odbc/recordset-scrolling-odbc.md) e [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

## <a name="crecordsetsetbookmark"></a><a name="setbookmark"></a>Configuração de registro de c::Set'mark

Posiciona o conjunto de registros no registro que contém o marcador especificado.

```cpp
void SetBookmark(const CDBVariant& varBookmark);
```

### <a name="parameters"></a>Parâmetros

*varBookmark*<br/>
Uma referência a um objeto [CDBVariant](../../mfc/reference/cdbvariant-class.md) contendo o valor do marcador para um registro específico.

### <a name="remarks"></a>Comentários

Para determinar se os marcadores são suportados no conjunto de registros, ligue para [o CanBookmark](#canbookmark). Para disponibilizar marcadores se eles forem suportados, você deve definir a `CRecordset::useBookmarks` opção no parâmetro *dwOptions* da função Membro [Aberto.](#open)

> [!NOTE]
> Se os marcadores não estiverem `SetBookmark` suportados ou indisponíveis, a chamada resultará em uma exceção. Os marcadores não são suportados em conjuntos de registros somente para frente.

Para primeiro recuperar o marcador para o registro atual, ligue [para GetBookmark](#getbookmark), que salva o valor do marcador para um `CDBVariant` objeto. Mais tarde, você pode retornar `SetBookmark` a esse registro ligando usando o valor de marcador salvo.

> [!NOTE]
> Após certas operações de conjunto de registros, `SetBookmark`você deve verificar a persistência do marcador antes de ligar . Por exemplo, se você recuperar `GetBookmark` um `Requery`marcador com e, em seguida, chamar, o marcador pode não ser mais válido. Chamada [CDatabase::GetBookmarkPersistence](../../mfc/reference/cdatabase-class.md#getbookmarkpersistence) para verificar se `SetBookmark`você pode ligar com segurança .

Para obter mais informações sobre marcadores e navegação de conjunto de registros, consulte os artigos [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md) e [Conjunto de Registros: Rolagem (ODBC)](../../data/odbc/recordset-scrolling-odbc.md).

## <a name="crecordsetsetfielddirty"></a><a name="setfielddirty"></a>Configuração de crecord::SetField',

Sinaliza um membro de dados de campo do conjunto de registros como alterado ou inalterado.

```cpp
void SetFieldDirty(void* pv, BOOL bDirty = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Contém o endereço de um membro de dados de campo no conjunto de registros ou NULL. Se NULL, todos os membros de dados de campo no conjunto de registros serão sinalizados. (C++ NULL não é o mesmo que Nulo na terminologia do banco de dados, o que significa "não ter valor".

*Bdirty*<br/>
TRUE se o membro de dados de campo for sinalizado como "sujo" (alterado). Caso contrário, FALSO se o membro de dados de campo for sinalizado como "limpo" (inalterado).

### <a name="remarks"></a>Comentários

Marcar campos como inalterados garante que o campo não seja atualizado e resulte em menos tráfego SQL.

> [!NOTE]
> Esta função de membro não é aplicável em conjuntos de registros que estão usando a busca de linhas em massa. Se você implementou a busca `SetFieldDirty` em linha em massa, então resultará em uma afirmação falha. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

As marcas-quadro alteraram os membros de dados de campo para garantir que eles serão gravados no registro na fonte de dados pelo mecanismo RFX (Record Field Exchange). Alterar o valor de um campo geralmente define o campo sujo automaticamente, `SetFieldDirty` então você raramente precisará se chamar, mas às vezes você pode querer garantir que as colunas serão explicitamente atualizadas ou inseridas independentemente do valor no membro de dados de campo.

> [!CAUTION]
> Chame esta função de membro somente depois de ter chamado [Edit](#edit) ou [AddNew](#addnew).

O uso de NULL para o primeiro argumento `outputColumn` da `param` função aplicará a função apenas aos campos, não aos campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

definirá `outputColumn` apenas campos para NULA; `param` campos não serão afetados.

Para trabalhar `param` em campos, você deve fornecer `param` o endereço real do indivíduo em que deseja trabalhar, tais como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que `param` você não pode definir `outputColumn` todos os campos como NULA, como você pode com campos.

## <a name="crecordsetsetfieldnull"></a><a name="setfieldnull"></a>Configuração de crecord::SetFieldNull

Sinaliza um membro de dados de campo do conjunto de registros como Nulo (especificamente sem valor) ou como não-nulo.

```cpp
void SetFieldNull(void* pv, BOOL bNull = TRUE);
```

### <a name="parameters"></a>Parâmetros

*Pv*<br/>
Contém o endereço de um membro de dados de campo no conjunto de registros ou NULL. Se NULL, todos os membros de dados de campo no conjunto de registros serão sinalizados. (C++ NULL não é o mesmo que Nulo na terminologia do banco de dados, o que significa "não ter valor".

*bNull*<br/>
Não zero se o membro de dados de campo for sinalizado como sem valor (Nulo). Caso contrário, 0 se o membro de dados de campo for sinalizado como não-nulo.

### <a name="remarks"></a>Comentários

Quando você adiciona um novo registro a um conjunto de registros, todos os membros de dados de campo são inicialmente definidos como um valor nulo e sinalizados como "sujos" (alterados). Quando você recupera um registro de uma fonte de dados, suas colunas já têm valores ou são Nulas.

> [!NOTE]
> Não chame esta função de membro em conjuntos de registros que estão usando a busca de linhas em massa. Se você implementou a busca `SetFieldNull` em linha em massa, chamar resulta em uma afirmação falhada. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Se você deseja especificamente designar um campo do registro `SetFieldNull` atual como não tendo um valor, ligue com *bNull* definido como TRUE para sinalizar como Nulo. Se um campo foi previamente marcado como Nulo e agora você quer dar-lhe um valor, basta definir seu novo valor. Você não tem que remover `SetFieldNull`a bandeira nula com . Para determinar se o campo pode `IsFieldNullable`ser nulo, ligue .

> [!CAUTION]
> Chame esta função de membro somente depois de ter chamado [Edit](#edit) ou [AddNew](#addnew).

O uso de NULL para o primeiro argumento `outputColumn` da `param` função aplicará a função apenas aos campos, não aos campos. Por exemplo, a chamada

[!code-cpp[NVC_MFCDatabase#26](../../mfc/codesnippet/cpp/crecordset-class_10.cpp)]

definirá `outputColumn` apenas campos para NULA; `param` campos não serão afetados.

Para trabalhar `param` em campos, você deve fornecer `param` o endereço real do indivíduo em que deseja trabalhar, tais como:

[!code-cpp[NVC_MFCDatabase#27](../../mfc/codesnippet/cpp/crecordset-class_11.cpp)]

Isso significa que `param` você não pode definir `outputColumn` todos os campos como NULA, como você pode com campos.

> [!NOTE]
> Ao definir parâmetros para `SetFieldNull` Nulo, uma chamada para antes do conjunto de registros ser aberto resulta em uma afirmação. Neste caso, ligue para [SetParamNull](#setparamnull).

`SetFieldNull`é implementado através [do DoFieldExchange](#dofieldexchange).

## <a name="crecordsetsetlockingmode"></a><a name="setlockingmode"></a>Configuração de registro de c::SetLockingMode

Define o modo de bloqueio como bloqueio "otimista" (o padrão) ou bloqueio "pessimista". Determina como os registros são bloqueados para atualizações.

```cpp
void SetLockingMode(UINT nMode);
```

### <a name="parameters"></a>Parâmetros

*nMode*<br/>
Contém um dos seguintes `enum LockMode`valores do :

- `optimistic`Bloqueio otimista bloqueia o registro sendo `Update`atualizado apenas durante a chamada para .

- `pessimistic`Bloqueio pessimista bloqueia `Edit` o registro assim que `Update` é chamado e o mantém bloqueado até que a chamada seja concluída ou você se mova para um novo registro.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro se você precisar especificar qual das duas estratégias de bloqueio de registro que o conjunto de registros está usando para atualizações. Por padrão, o modo de `optimistic`bloqueio de um conjunto de registros é . Você pode mudar isso `pessimistic` para uma estratégia de bloqueio mais cautelosa. Ligue `SetLockingMode` depois de construir e abrir o `Edit`objeto do conjunto de registros, mas antes de chamar .

## <a name="crecordsetsetparamnull"></a><a name="setparamnull"></a>CRecordset::SetParamNull

Sinaliza um parâmetro como Nulo (especificamente sem valor) ou como não nulo.

```cpp
void SetParamNull(
    int nIndex,
    BOOL bNull = TRUE);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
O índice baseado em zero do parâmetro.

*bNull*<br/>
Se TRUE (o valor padrão), o parâmetro será sinalizado como Nulo. Caso contrário, o parâmetro é sinalizado como não-nulo.

### <a name="remarks"></a>Comentários

Ao contrário [de SetFieldNull,](#setfieldnull)você pode ligar `SetParamNull` antes de abrir o conjunto de registros.

`SetParamNull`é normalmente usado com consultas predefinidas (procedimentos armazenados).

## <a name="crecordsetsetrowsetcursorposition"></a><a name="setrowsetcursorposition"></a>CRecordset::SetRowsetCursorPosição

Move o cursor para uma linha dentro do conjunto de linhas atual.

```cpp
void SetRowsetCursorPosition(WORD wRow, WORD wLockType = SQL_LOCK_NO_CHANGE);
```

### <a name="parameters"></a>Parâmetros

*wRow*<br/>
A posição de uma linha no conjunto de linhas atual. Este valor pode variar de 1 até o tamanho do conjunto de linhas.

*wLockType*<br/>
Valor indicando como bloquear a linha depois de atualizada. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Ao implementar a busca em linha em massa, os registros são recuperados por conjuntos de linhas, onde o primeiro registro no conjunto de linhas buscados é o registro atual. Para fazer outro registro dentro da linha definir `SetRowsetCursorPosition`o registro atual, ligue . Por exemplo, você `SetRowsetCursorPosition` pode combinar com a função de membro [GetFieldValue](#getfieldvalue) para recuperar dinamicamente os dados de qualquer registro do seu conjunto de registros.

Para `SetRowsetCursorPosition`usar, você deve ter implementado a `CRecordset::useMultiRowFetch` busca em linha em massa especificando a opção do parâmetro *dwOptions* na função [Membro Aberto.](#open)

`SetRowsetCursorPosition`chama a função `SQLSetPos`API odbc . O parâmetro *wLockType* especifica o estado de `SQLSetPos` bloqueio da linha após a execução. A tabela a seguir descreve os valores possíveis para *wLockType*.

|wLockType|Descrição|
|---------------|-----------------|
|SQL_LOCK_NO_CHANGE (o valor padrão)|O driver ou fonte de dados garante que a linha esteja no `SetRowsetCursorPosition` mesmo estado bloqueado ou desbloqueado como era antes.|
|SQL_LOCK_EXCLUSIVE|O driver ou a fonte de dados bloqueia a linha exclusivamente. Nem todas as fontes de dados suportam esse tipo de bloqueio.|
|SQL_LOCK_UNLOCK|O driver ou fonte de dados desbloqueia a linha. Nem todas as fontes de dados suportam esse tipo de bloqueio.|

Para obter `SQLSetPos`mais informações sobre, consulte o Windows SDK. Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="crecordsetsetrowsetsize"></a><a name="setrowsetsize"></a>Configuração de registro de c::SetRow '''''''''''''''''''

Especifica o número de registros que deseja recuperar durante uma busca.

```
virtual void SetRowsetSize(DWORD dwNewRowsetSize);
```

### <a name="parameters"></a>Parâmetros

*dwNewRowsetSize*<br/>
O número de linhas para recuperar durante uma determinada busca.

### <a name="remarks"></a>Comentários

Esta função de membro virtual especifica quantas linhas você deseja recuperar durante uma única busca ao usar a busca em linha em massa. Para implementar a busca de linhas `CRecordset::useMultiRowFetch` em massa, você deve definir a opção no parâmetro *dwOptions* da função [Membro Aberto.](#open)

> [!NOTE]
> Ligar `SetRowsetSize` sem implementar a busca em linha em massa resultará em uma afirmação fracassada.

Ligue `SetRowsetSize` antes `Open` de ligar para definir inicialmente o tamanho do conjunto de linhas para o conjunto de registros. O tamanho padrão do conjunto de linhas ao implementar a busca de linhas em massa é de 25.

> [!NOTE]
> Tenha cuidado `SetRowsetSize`ao ligar . Se você estiver alocando manualmente o armazenamento para `CRecordset::userAllocMultiRowBuffers` os dados (conforme especificado `Open`pela opção do parâmetro dwOptions em), você `SetRowsetSize`deve verificar se você precisa realocar esses buffers de armazenamento após a chamada, mas antes de executar qualquer operação de navegação do cursor.

Para obter a configuração atual para o tamanho do conjunto de linhas, chame [GetRowsetSize](#getrowsetsize).

Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

## <a name="crecordsetupdate"></a><a name="update"></a>CRecordset::Atualização

Completa uma `AddNew` `Edit` operação ou salvando os dados novos ou editados na fonte de dados.

```
virtual BOOL Update();
```

### <a name="return-value"></a>Valor retornado

Não zero se um registro foi atualizado com sucesso; caso contrário 0 se nenhuma coluna tiver mudado. Se nenhum registro foi atualizado, ou se mais de um registro foi atualizado, uma exceção será lançada. Uma exceção também é lançada para qualquer outra falha na fonte de dados.

### <a name="remarks"></a>Comentários

Ligue para esta função de membro após uma chamada para a função [AddNew](#addnew) ou [Editar](#edit) membro. Esta chamada é necessária `AddNew` `Edit` para completar a operação.

> [!NOTE]
> Se você implementou a busca em `Update`linha em massa, você não pode chamar . Isso resultará em uma afirmação fracassada. Embora `CRecordset` a classe não forneça um mecanismo para atualizar linhas em massa de dados, você `SQLSetPos`pode escrever suas próprias funções usando a função API ODBC . Para obter mais informações sobre a busca de linhas em massa, consulte o artigo [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

Ambos `AddNew` `Edit` e preparar um buffer de edição no qual os dados adicionados ou editados são colocados para salvar a fonte de dados. `Update`salva os dados. Somente os campos marcados ou detectados conforme alterados são atualizados.

Se a fonte de dados suportar transações, você pode fazer a `Update` chamada (e sua correspondente `AddNew` ou `Edit` chamada) parte de uma transação. Para obter mais informações sobre transações, consulte o artigo [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

> [!CAUTION]
> Se você `Update` ligar sem `Edit` `Update` antes `CDBException`ligar `AddNew` ou jogar um . Se você `AddNew` `Edit`ligar ou `Update` , você `Move` deve ligar antes de chamar uma operação ou antes de fechar o conjunto de registros ou a conexão fonte de dados. Caso contrário, suas alterações serão perdidas sem notificação.

Para obter detalhes sobre falhas de manuseio, `Update` consulte o artigo [Recordset: How Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md).

### <a name="example"></a>Exemplo

Veja o artigo [Transação: Realizando uma Transação em um Conjunto de Registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordView](../../mfc/reference/crecordview-class.md)
