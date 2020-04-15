---
title: Classe CDatabase
ms.date: 11/04/2016
f1_keywords:
- CDatabase
- AFXDB/CDatabase
- AFXDB/CDatabase::CDatabase
- AFXDB/CDatabase::BeginTrans
- AFXDB/CDatabase::BindParameters
- AFXDB/CDatabase::Cancel
- AFXDB/CDatabase::CanTransact
- AFXDB/CDatabase::CanUpdate
- AFXDB/CDatabase::Close
- AFXDB/CDatabase::CommitTrans
- AFXDB/CDatabase::ExecuteSQL
- AFXDB/CDatabase::GetBookmarkPersistence
- AFXDB/CDatabase::GetConnect
- AFXDB/CDatabase::GetCursorCommitBehavior
- AFXDB/CDatabase::GetCursorRollbackBehavior
- AFXDB/CDatabase::GetDatabaseName
- AFXDB/CDatabase::IsOpen
- AFXDB/CDatabase::OnSetOptions
- AFXDB/CDatabase::Open
- AFXDB/CDatabase::OpenEx
- AFXDB/CDatabase::Rollback
- AFXDB/CDatabase::SetLoginTimeout
- AFXDB/CDatabase::SetQueryTimeout
- AFXDB/CDatabase::m_hdbc
helpviewer_keywords:
- CDatabase [MFC], CDatabase
- CDatabase [MFC], BeginTrans
- CDatabase [MFC], BindParameters
- CDatabase [MFC], Cancel
- CDatabase [MFC], CanTransact
- CDatabase [MFC], CanUpdate
- CDatabase [MFC], Close
- CDatabase [MFC], CommitTrans
- CDatabase [MFC], ExecuteSQL
- CDatabase [MFC], GetBookmarkPersistence
- CDatabase [MFC], GetConnect
- CDatabase [MFC], GetCursorCommitBehavior
- CDatabase [MFC], GetCursorRollbackBehavior
- CDatabase [MFC], GetDatabaseName
- CDatabase [MFC], IsOpen
- CDatabase [MFC], OnSetOptions
- CDatabase [MFC], Open
- CDatabase [MFC], OpenEx
- CDatabase [MFC], Rollback
- CDatabase [MFC], SetLoginTimeout
- CDatabase [MFC], SetQueryTimeout
- CDatabase [MFC], m_hdbc
ms.assetid: bd0de70a-e3c3-4441-bcaa-bbf434426ca8
ms.openlocfilehash: 260a4a38fcee8994d804267709c11279266d393c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376472"
---
# <a name="cdatabase-class"></a>Classe CDatabase

Representa uma conexão com uma fonte de dados, através da qual você pode operar na fonte de dados.

## <a name="syntax"></a>Sintaxe

```
class CDatabase : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDatabase::CDatabase](#cdatabase)|Constrói um objeto `CDatabase`. Você deve inicializar o `OpenEx` `Open`objeto ligando ou .|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[cDatabase::BeginTrans](#begintrans)|Inicia uma "transação" — uma série `AddNew` `Edit`de `Delete`chamadas `Update` reversíveis para `CRecordset` as funções de classe e membros da classe — na fonte de dados conectada. A fonte de dados `BeginTrans` deve suportar transações para ter qualquer efeito.|
|[Banco de dados C::BindParameters](#bindparameters)|Permite que você vincule parâmetros antes de ligar `CDatabase::ExecuteSQL`.|
|[CDatabase::Cancel](#cancel)|Cancela uma operação assíncrona ou um processo de um segundo segmento.|
|[CDatabase::CanTransact](#cantransact)|Retorna não zero se a fonte de dados suportar transações.|
|[CDatabase::CanUpdate](#canupdate)|Retorna não zero `CDatabase` se o objeto for updatable (não somente leitura).|
|[CDatabase::Fechar](#close)|Fecha a conexão de origem de dados.|
|[CDatabase::CommitTrans](#committrans)|Completa uma transação `BeginTrans`iniciada por . Os comandos na transação que alteram a fonte de dados são realizados.|
|[CDatabase::ExecuteSqL](#executesql)|Executa uma declaração SQL. Nenhum registro de dados é devolvido.|
|[CDatabase::GetBookmarkPersistence](#getbookmarkpersistence)|Identifica as operações através das quais os marcadores persistem em objetos de conjunto de registros.|
|[banco de dados::getconnect](#getconnect)|Retorna a seqüência de conexão ODBC usada para conectar o `CDatabase` objeto a uma fonte de dados.|
|[CDatabase::GetCursorCommitBehavior](#getcursorcommitbehavior)|Identifica o efeito de cometer uma transação em um objeto de conjunto de registros aberto.|
|[CDatabase::GetCursorRollbackBehavior](#getcursorrollbackbehavior)|Identifica o efeito de reverter uma transação em um objeto de conjunto de registros aberto.|
|[CDatabase::GetDatabaseName](#getdatabasename)|Retorna o nome do banco de dados atualmente em uso.|
|[CDatabase::IsOpen](#isopen)|Retorna não zero `CDatabase` se o objeto estiver conectado a uma fonte de dados.|
|[cDatabase::Opções de início](#onsetoptions)|Chamado pela estrutura para definir opções de conexão padrão. A implementação padrão define o valor de tempo de tempo de consulta. Você pode estabelecer essas opções `SetQueryTimeout`com antecedência ligando .|
|[CDatabase::Abrir](#open)|Estabelece uma conexão com uma fonte de dados (através de um driver ODBC).|
|[CDatabase::OpenEx](#openex)|Estabelece uma conexão com uma fonte de dados (através de um driver ODBC).|
|[CDatabase:::Reversão](#rollback)|Reverte as alterações feitas durante a transação atual. A fonte de dados retorna ao seu `BeginTrans` estado anterior, conforme definido na chamada, inalterado.|
|[Banco de dados::SetLoginTimeout](#setlogintimeout)|Define o número de segundos após o qual uma tentativa de conexão de origem de dados será cronometrada.|
|[CDatabase::SetQueryTimeout](#setquerytimeout)|Define o número de segundos após o qual as operações de consulta de banco de dados serão deshoraadas. Afeta todos os `Open`registros `AddNew` `Edit`subseqüentes e `Delete` chamadas.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[Banco de dados C::m_hdbc](#m_hdbc)|Abra o controle de conexão do Banco de Dados (ODBC) a uma fonte de dados. Tipo *HDBC*.|

## <a name="remarks"></a>Comentários

Uma fonte de dados é uma instância específica de dados hospedados por algum sistema de gerenciamento de banco de dados (DBMS). Exemplos incluem Microsoft SQL Server, Microsoft Access, Borland dBASE e xBASE. Você pode ter `CDatabase` um ou mais objetos ativos de cada vez em sua aplicação.

> [!NOTE]
> Se você estiver trabalhando com as classes DAO (Data Access Objects, objetos de acesso de dados) em vez das classes ODBC (Open Database Connectivity, conectividade de banco de dados aberto), use a classe [CDaoDatabase.](../../mfc/reference/cdaodatabase-class.md) Para obter mais informações, consulte a visão geral do [artigo: Programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

Para `CDatabase`usar, `CDatabase` construa um `OpenEx` objeto e chame sua função de membro. Isso abre uma conexão. Ao construir `CRecordset` objetos para operar na fonte de dados conectada, passe `CDatabase` ao construtor do conjunto de registros um ponteiro para o objeto. Quando terminar de usar a `Close` conexão, `CDatabase` ligue para a função do membro e destrua o objeto. `Close`fecha todos os conjuntos de registros que você não fechou anteriormente.

Para obter `CDatabase`mais informações sobre , consulte os artigos [Data Source (ODBC)](../../data/odbc/data-source-odbc.md) e [Visão Geral: Programação de Banco de Dados](../../data/data-access-programming-mfc-atl.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CDatabase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="cdatabasebegintrans"></a><a name="begintrans"></a>cDatabase::BeginTrans

Ligue para esta função de membro para iniciar uma transação com a fonte de dados conectada.

```
BOOL BeginTrans();
```

### <a name="return-value"></a>Valor retornado

Não zero se a chamada foi bem sucedida e as alterações são cometidas apenas manualmente; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma transação consiste em uma `AddNew`ou `Edit` `Delete`mais `Update` chamadas para as `CRecordset` funções de membro e membro de um objeto. Antes de iniciar `CDatabase` uma transação, o objeto já deve `OpenEx` `Open` ter sido conectado à fonte de dados, chamando sua função ou membro. Para encerrar a transação, ligue para a [CommitTrans](#committrans) para aceitar todas as alterações na fonte de dados (e executá-las) ou ligar para [a Reversão](#rollback) para abortar toda a transação. Ligue `BeginTrans` depois de abrir quaisquer conjuntos de registros envolvidos na transação e o mais próximo possível das operações de atualização reais.

> [!CAUTION]
> Dependendo do driver ODBC, abrir um `BeginTrans` conjunto de `Rollback`registros antes de ligar pode causar problemas ao ligar . Você deve verificar o driver específico que você está usando. Por exemplo, ao usar o driver Microsoft Access incluído no Microsoft ODBC Desktop Driver Pack 3.0, você deve prestar contas da exigência do mecanismo de banco de dados Jet de que você não deve iniciar uma transação em qualquer banco de dados que tenha um cursor aberto. Nas classes de banco de dados MFC, um cursor aberto significa um objeto aberto. `CRecordset` Para obter mais informações, consulte [Nota Técnica 68](../../mfc/tn068-performing-transactions-with-the-microsoft-access-7-odbc-driver.md).

`BeginTrans`também pode bloquear registros de dados no servidor, dependendo da concorrência solicitada e dos recursos da fonte de dados. Para obter informações sobre o bloqueio de dados, consulte o artigo [Recordset: Locking Records (ODBC)](../../data/odbc/recordset-locking-records-odbc.md).

As transações definidas pelo usuário são explicadas no artigo [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

`BeginTrans`estabelece o estado para o qual a seqüência de transações pode ser revertida (invertida). Para estabelecer um novo estado para reversões, cometa `BeginTrans` qualquer transação atual e ligue novamente.

> [!CAUTION]
> Ligar `BeginTrans` novamente `CommitTrans` sem ligar ou `Rollback` é um erro.

Ligue para a função de membro do [CanTransact](#cantransact) para determinar se o driver suporta transações para um determinado banco de dados. Você também deve chamar [GetCursorCommitBehavior](#getcursorcommitbehavior) e [GetCursorRollbackBehavior](#getcursorrollbackbehavior) para determinar o suporte para preservação do cursor.

Para obter mais informações sobre transações, consulte o artigo [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>Exemplo

  Veja o artigo [Transação: Realizando uma Transação em um Conjunto de Registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

## <a name="cdatabasebindparameters"></a><a name="bindparameters"></a>Banco de dados C::BindParameters

Substituir `BindParameters` quando você precisa vincular parâmetros antes de chamar [CDatabase::ExecuteSQL](#executesql).

```
virtual void BindParameters(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*hstmt*<br/>
A alça de declaração ODBC para a qual você deseja vincular parâmetros.

### <a name="remarks"></a>Comentários

Esta abordagem é útil quando você não precisa do conjunto de resultados de um procedimento armazenado.

Em sua substituição, `SQLBindParameters` as funções de chamada e ODBC relacionadas para vincular os parâmetros. MFC chama sua substituição antes `ExecuteSQL`de sua chamada para . Você não precisa `SQLPrepare`ligar; `ExecuteSQL` chama `SQLExecDirect` e destrói o *hstmt,* que é usado apenas uma vez.

## <a name="cdatabasecancel"></a><a name="cancel"></a>CDatabase::Cancel

Ligue para esta função de membro para solicitar que a fonte de dados cancele uma operação assíncrona em andamento ou um processo a partir de um segundo segmento.

```
void Cancel();
```

### <a name="remarks"></a>Comentários

Observe que as classes MFC ODBC não usam mais processamento assíncrono; para realizar uma operação assíncrona, você deve chamar diretamente a função [API ODBC SQLSetConnectOption](/sql/odbc/reference/syntax/sqlsetconnectoption-function). Para obter mais informações, consulte [Execução assíncrona](/sql/odbc/reference/develop-app/asynchronous-execution).

## <a name="cdatabasecantransact"></a><a name="cantransact"></a>CDatabase::CanTransact

Ligue para esta função de membro para determinar se o banco de dados permite transações.

```
BOOL CanTransact() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se os `CDatabase` conjuntos de registros que utilizam este objeto permitirem transações; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter informações sobre transações, consulte o artigo [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

## <a name="cdatabasecanupdate"></a><a name="canupdate"></a>CDatabase::CanUpdate

Ligue para esta função `CDatabase` de membro para determinar se o objeto permite atualizações.

```
BOOL CanUpdate() const;
```

### <a name="return-value"></a>Valor retornado

Não zero `CDatabase` se o objeto permitir atualizações; caso contrário 0, indicando que você passou TRUE em `CDatabase` *bReadOnly* quando você abriu o objeto ou que a própria fonte de dados é somente leitura. A fonte de dados é somente leitura se uma `SQLGetInfo` chamada para a função API oDBC para SQL_DATASOURCE_READ_ONLY retornar "y".

### <a name="remarks"></a>Comentários

Nem todos os drivers suportam atualizações.

## <a name="cdatabasecdatabase"></a><a name="cdatabase"></a>CDatabase::CDatabase

Constrói um objeto `CDatabase`.

```
CDatabase();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, `OpenEx` `Open` você deve chamar sua função ou membro para estabelecer uma conexão com uma fonte de dados especificada.

Você pode achar conveniente incorporar `CDatabase` o objeto em sua classe de documentos.

### <a name="example"></a>Exemplo

Este exemplo ilustra `CDatabase` o `CDocument`uso em uma classe derivada.

[!code-cpp[NVC_MFCDatabase#9](../../mfc/codesnippet/cpp/cdatabase-class_1.h)]

[!code-cpp[NVC_MFCDatabase#10](../../mfc/codesnippet/cpp/cdatabase-class_2.cpp)]

## <a name="cdatabaseclose"></a><a name="close"></a>CDatabase::Fechar

Ligue para esta função de membro se quiser se desconectar de uma fonte de dados.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Você deve fechar quaisquer conjuntos de registros associados ao `CDatabase` objeto antes de chamar esta função de membro. Como `Close` não destrói `CDatabase` o objeto, você pode reutilizar o objeto abrindo uma nova conexão com a mesma fonte de dados ou uma fonte de dados diferente.

Todas `AddNew` as `Edit` pendências ou demonstrações de conjuntos de registros usando o banco de dados são canceladas, e todas as transações pendentes são revertidas. Todos os conjuntos `CDatabase` de registros dependentes do objeto são deixados em um estado indefinido.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#12](../../mfc/codesnippet/cpp/cdatabase-class_3.cpp)]

## <a name="cdatabasecommittrans"></a><a name="committrans"></a>CDatabase::CommitTrans

Ligue para esta função de membro ao concluir transações.

```
BOOL CommitTrans();
```

### <a name="return-value"></a>Valor retornado

Não zero se as atualizações foram comprometidas com sucesso; caso contrário, 0. Se `CommitTrans` falhar, o estado da fonte de dados é indefinido. Você deve verificar os dados para determinar seu estado.

### <a name="remarks"></a>Comentários

Uma transação consiste em uma `AddNew`série `Edit` `Delete`de `Update` chamadas para as `CRecordset` funções de um objeto que começou com uma chamada para a função de membro [BeginTrans.](#begintrans) `CommitTrans`comete a transação. Por padrão, as atualizações são cometidas imediatamente; chamar `BeginTrans` faz com que o compromisso `CommitTrans` das atualizações seja adiado até que seja chamado.

Até que `CommitTrans` você ligue para encerrar uma transação, você pode chamar a função [membro Rollback](#rollback) para abortar a transação e deixar a fonte de dados em seu estado original. Para começar uma nova `BeginTrans` transação, ligue novamente.

Para obter mais informações sobre transações, consulte o artigo [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>Exemplo

  Veja o artigo [Transação: Realizando uma Transação em um Conjunto de Registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

## <a name="cdatabaseexecutesql"></a><a name="executesql"></a>CDatabase::ExecuteSqL

Chame esta função de membro quando precisar executar um comando SQL diretamente.

```
void ExecuteSQL(LPCTSTR lpszSQL);
```

### <a name="parameters"></a>Parâmetros

*lpszSQL*<br/>
Ponteiro para uma seqüência de terminadas nula contendo um comando SQL válido para executar. Você pode passar um [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Crie o comando como uma seqüência de seqüência de terminadas por nulo. `ExecuteSQL`não retorna registros de dados. Se você quiser operar em registros, use um objeto de conjunto de registros em vez disso.

A maioria de seus comandos para uma fonte de dados são emitidos através de objetos de conjunto de registros, que suportam comandos para selecionar dados, inserir novos registros, excluir registros e editar registros. No entanto, nem todas as funcionalidades do ODBC são suportadas diretamente pelas classes de `ExecuteSQL`banco de dados, então às vezes você pode precisar fazer uma chamada SQL direta com .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#13](../../mfc/codesnippet/cpp/cdatabase-class_4.cpp)]

## <a name="cdatabasegetbookmarkpersistence"></a><a name="getbookmarkpersistence"></a>CDatabase::GetBookmarkPersistence

Chame essa função de membro para determinar a persistência de indicadores em um objeto Recordset depois de determinadas operações.

```
DWORD GetBookmarkPersistence() const;
```

### <a name="return-value"></a>Valor retornado

Uma bitmask que identifica as operações através das quais persistem os indicadores em um objeto recordset. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

Por exemplo, se você chamar `CRecordset::GetBookmark` e chamar `CRecordset::Requery`, o indicador obtido a partir de `GetBookmark` pode não ser mais válido. Você deve chamar `GetBookmarkPersistence` antes de chamar `CRecordset::SetBookmark`.

A tabela a seguir lista os valores de bitmask que podem ser combinados para o valor retornado de `GetBookmarkPersistence`.

|Valor de bitmask|Persistência de indicador|
|-------------------|--------------------------|
|SQL_BP_CLOSE|Os marcadores são `Requery` válidos após uma operação.|
|SQL_BP_DELETE|O marcador para uma linha `Delete` é válido após uma operação nessa linha.|
|SQL_BP_DROP|Os marcadores são `Close` válidos após uma operação.|
|SQL_BP_SCROLL|Os marcadores são `Move` válidos após qualquer operação. Isso simplesmente identifica se os indicadores são compatíveis com o conjunto de registros, como retornado por `CRecordset::CanBookmark`.|
|SQL_BP_TRANSACTION|Os indicadores são válidos depois que uma transação é confirmada ou revertida.|
|SQL_BP_UPDATE|O marcador para uma linha `Update` é válido após uma operação nessa linha.|
|SQL_BP_OTHER_HSTMT|Indicadores associados a um objeto recordset são válidos em um segundo conjunto de registros.|

Para obter mais informações sobre esse valor de `SQLGetInfo` retorno, consulte a função API do ODBC no SDK do Windows. Para obter mais informações sobre marcadores, consulte o artigo [Recordset: Marcadores e Posições Absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

## <a name="cdatabasegetconnect"></a><a name="getconnect"></a>banco de dados::getconnect

Ligue para esta função de membro para `OpenEx` recuperar `Open` a `CDatabase` seqüência de conexão usada durante a chamada ou que conectou o objeto a uma fonte de dados.

```
const CString GetConnect() const;
```

### <a name="return-value"></a>Valor retornado

Um **const**[CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo a `OpenEx` `Open` seqüência de conexão se ou tiver sido chamado; caso contrário, uma corda vazia.

### <a name="remarks"></a>Comentários

Consulte [CDatabase::Abrir](#open) para obter uma descrição de como a seqüência de conexões é criada.

## <a name="cdatabasegetcursorcommitbehavior"></a><a name="getcursorcommitbehavior"></a>CDatabase::GetCursorCommitBehavior

Ligue para esta função de membro para determinar como uma operação [CommitTrans](#committrans) afeta cursores em objetos de conjunto de registros abertos.

```
int GetCursorCommitBehavior() const;
```

### <a name="return-value"></a>Valor retornado

Um valor que indica o efeito das transações em objetos de conjunto de registros abertos. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

A tabela a seguir lista `GetCursorCommitBehavior` os possíveis valores de retorno e o efeito correspondente no conjunto de registros abertos.

|Valor retornado|Efeito em objetos CRecordset|
|------------------|----------------------------------|
|SQL_CB_CLOSE|Ligue `CRecordset::Requery` imediatamente após o compromisso da transação.|
|SQL_CB_DELETE|Ligue `CRecordset::Close` imediatamente após o compromisso da transação.|
|SQL_CB_PRESERVE|Prossiga `CRecordset` normalmente com as operações.|

Para obter mais informações sobre esse valor de `SQLGetInfo` retorno, consulte a função API do ODBC no SDK do Windows. Para obter mais informações sobre transações, consulte o artigo [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

## <a name="cdatabasegetcursorrollbackbehavior"></a><a name="getcursorrollbackbehavior"></a>CDatabase::GetCursorRollbackBehavior

Ligue para esta função de membro para determinar como uma operação [de reversão](#rollback) afeta os cursores em objetos abertos.

```
int GetCursorRollbackBehavior() const;
```

### <a name="return-value"></a>Valor retornado

Um valor que indica o efeito das transações em objetos de conjunto de registros abertos. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

A tabela a seguir lista `GetCursorRollbackBehavior` os possíveis valores de retorno e o efeito correspondente no conjunto de registros abertos.

|Valor retornado|Efeito em objetos CRecordset|
|------------------|----------------------------------|
|SQL_CB_CLOSE|Ligue `CRecordset::Requery` imediatamente após a reversão da transação.|
|SQL_CB_DELETE|Ligue `CRecordset::Close` imediatamente após a reversão da transação.|
|SQL_CB_PRESERVE|Prossiga `CRecordset` normalmente com as operações.|

Para obter mais informações sobre esse valor de `SQLGetInfo` retorno, consulte a função API do ODBC no SDK do Windows. Para obter mais informações sobre transações, consulte o artigo [Transação (ODBC)](../../data/odbc/transaction-odbc.md).

## <a name="cdatabasegetdatabasename"></a><a name="getdatabasename"></a>CDatabase::GetDatabaseName

Ligue para esta função de membro para recuperar o nome do banco de dados atualmente conectado (desde que a fonte de dados defina um objeto chamado "banco de dados").

```
CString GetDatabaseName() const;
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) contendo o nome do banco de dados se for bem sucedido; caso contrário, `CString`um vazio .

### <a name="remarks"></a>Comentários

Isso não é o mesmo que o nome de origem `OpenEx` `Open` de dados (DSN) especificado na chamada ou chamada. O `GetDatabaseName` que retorna depende da ODBC. Em geral, um banco de dados é uma coleção de tabelas. Se essa entidade tem `GetDatabaseName` um nome, devolva-o.

Você pode, por exemplo, querer exibir esse nome em um título. Se ocorrer um erro ao recuperar o `GetDatabaseName` nome do `CString`ODBC, retorne um vazio .

## <a name="cdatabaseisopen"></a><a name="isopen"></a>CDatabase::IsOpen

Ligue para esta função `CDatabase` de membro para determinar se o objeto está conectado a uma fonte de dados.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Não zero `CDatabase` se o objeto estiver conectado no momento; caso contrário, 0.

## <a name="cdatabasem_hdbc"></a><a name="m_hdbc"></a>Banco de dados C::m_hdbc

Contém uma alça pública para uma conexão de origem de dados ODBC — uma "alça de conexão".

### <a name="remarks"></a>Comentários

Normalmente, você não terá necessidade de acessar essa variável de membro diretamente. Em vez disso, a estrutura `OpenEx` aloca `Open`a alça quando você liga ou . A estrutura desaloca a alça quando você `CDatabase` chama o operador **de exclusão** no objeto. Observe que `Close` a função do membro não desaloca a alça.

Em algumas circunstâncias, no entanto, você pode precisar usar a alça diretamente. Por exemplo, se você precisar chamar as funções de `CDatabase`API do ODBC diretamente e não através da classe, você pode precisar de uma alça de conexão para passar como parâmetro. Veja o exemplo de código abaixo.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#15](../../mfc/codesnippet/cpp/cdatabase-class_5.cpp)]

## <a name="cdatabaseonsetoptions"></a><a name="onsetoptions"></a>cDatabase::Opções de início

O framework chama essa função de membro ao executar `ExecuteSQL` diretamente uma declaração SQL com a função membro.

```
virtual void OnSetOptions(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*hstmt*<br/>
A alça de declaração oDBC para as quais as opções estão sendo definidas.

### <a name="remarks"></a>Comentários

`CRecordset::OnSetOptions`também chama essa função de membro.

`OnSetOptions`define o valor do tempo de saída de login. Se houver chamadas anteriores `SetQueryTimeout` para a `OnSetOptions` função e membro, reflete os valores atuais; caso contrário, ele define valores padrão.

> [!NOTE]
> Antes do MFC 4.2, `OnSetOptions` também defina o modo de processamento para sincronia ou assíncrona. Começando com o MFC 4.2, todas as operações são síncronas. Para realizar uma operação assíncrona, você deve fazer uma `SQLSetPos`chamada direta para a função API ODBC .

Você não precisa substituir `OnSetOptions` para alterar o valor do tempo. Em vez disso, para personalizar o `SetQueryTimeout` valor de tempo de consulta, chame antes de criar um conjunto de registros; `OnSetOptions` usará o novo valor. Os valores definidos aplicam-se às operações subseqüentes em todos os conjuntos de registros ou chamadas SQL diretas.

Anular `OnSetOptions` se você quiser definir opções adicionais. Sua substituição deve chamar `OnSetOptions` a classe base antes ou depois de `SQLSetStmtOption`chamar a função API ODBC . Siga o método ilustrado na implementação `OnSetOptions`padrão do framework de .

## <a name="cdatabaseopen"></a><a name="open"></a>CDatabase::Abrir

Chame essa função de membro para `CDatabase` inicializar um objeto recém-construído.

```
virtual BOOL Open(
    LPCTSTR lpszDSN,
    BOOL bExclusive = FALSE,
    BOOL bReadOnly = FALSE,
    LPCTSTR lpszConnect = _T("ODBC;"),
    BOOL bUseCursorLib = TRUE);
```

### <a name="parameters"></a>Parâmetros

*lpszDSN*<br/>
Especifica um nome de origem de dados — um nome registrado no ODBC através do programa Administrador ODBC. Se um valor de DSN for especificado no *lpszConnect* (no formulário "DSN=\<data-source>"), ele não deve ser especificado novamente em *lpszDSN*. Neste caso, *lpszDSN* deve ser NULO. Caso contrário, você pode passar NULL se quiser apresentar ao usuário uma caixa de diálogo Fonte de Dados na qual o usuário pode selecionar uma fonte de dados. Para obter mais informações, consulte Observações.

*bExclusivo*<br/>
Não suportado nesta versão da biblioteca de classe. Atualmente, uma afirmação falha se esse parâmetro for VERDADEIRO. A fonte de dados é sempre aberta como compartilhada (não exclusiva).

*bReadOnly*<br/>
TRUE se você pretende que a conexão seja somente lida e proibir atualizações na fonte de dados. Todos os conjuntos de registros dependentes herdam esse atributo. O valor padrão é FALSE.

*lpszConnect*<br/>
Especifica uma seqüência de conexão. A seqüência de conexões concatena informações, possivelmente incluindo um nome de origem de dados, um ID do usuário válido na fonte de dados, uma seqüência de autenticação do usuário (senha, se a fonte de dados requer uma) e outras informações. Toda a seqüência de conexão deve ser prefixada pela string "ODBC;" (maiúsculas ou minúsculas). A seqüência "ODBC;" é usada para indicar que a conexão é a uma fonte de dados ODBC; isso é para compatibilidade ascendente quando versões futuras da biblioteca de classe podem suportar fontes de dados não-ODBC.

*Busecursorlib*<br/>
VERDADE se você quiser que o DLL da Biblioteca do Cursor ODBC seja carregado. A biblioteca do cursor mascara algumas funcionalidades do driver ODBC subjacente, impedindo efetivamente o uso de dynasets (se o driver os suporta). Os únicos cursores suportados se a biblioteca do cursor estiver carregada são instantâneos estáticos e cursores somente para frente. O valor padrão é TRUE. Se você planeja criar um objeto `CRecordset` de conjunto de registros diretamente sem derivar dele, você não deve carregar a biblioteca do cursor.

### <a name="return-value"></a>Valor retornado

Não zero se a conexão for feita com sucesso; caso contrário 0 se o usuário escolher Cancelar quando apresentado uma caixa de diálogo pedindo mais informações de conexão. Em todos os outros casos, o quadro abre uma exceção.

### <a name="remarks"></a>Comentários

O objeto do banco de dados deve ser inicializado antes de poder usá-lo para construir um objeto de conjunto de registros.

> [!NOTE]
> Chamar a função de membro [OpenEx](#openex) é a maneira preferida de se conectar a uma fonte de dados e inicializar seu objeto de banco de dados.

Se os parâmetros da sua `Open` chamada não contiverem informações suficientes para fazer a conexão, o driver ODBC abrirá uma caixa de diálogo para obter as informações necessárias do usuário. Quando você `Open`chama , sua seqüência de conexão, `CDatabase` *lpszConnect*, é armazenado privadamente no objeto e está disponível chamando a função de membro [GetConnect.](#getconnect)

Se desejar, você pode abrir sua própria `Open` caixa de diálogo antes de ligar para obter informações do usuário, `Open`como uma senha, e adicionar essas informações à seqüência de conexão para a que você passa . Ou você pode querer salvar a seqüência de conexão que você `Open` passa `CDatabase` para que você possa reutilizá-la na próxima vez que seu aplicativo chamar um objeto.

Você também pode usar a seqüência de conexões `CDatabase` para vários níveis de autorização de login (cada um para um objeto diferente) ou para transmitir outras informações específicas da fonte de dados. Para obter mais informações sobre as seqüências de conexão, consulte o Capítulo 5 no SDK do Windows.

É possível para uma tentativa de conexão de tempo se, por exemplo, o host DBMS não estiver disponível. Se a tentativa `Open` de `CDBException`conexão falhar, lança um .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#14](../../mfc/codesnippet/cpp/cdatabase-class_6.cpp)]

## <a name="cdatabaseopenex"></a><a name="openex"></a>CDatabase::OpenEx

Chame essa função de membro para `CDatabase` inicializar um objeto recém-construído.

```
virtual BOOL OpenEx(
    LPCTSTR lpszConnectString,
    DWORD dwOptions = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszConnectString*<br/>
Especifica uma seqüência de conexão ODBC. Isso inclui o nome da fonte de dados, bem como outras informações opcionais, como um ID de usuário e senha. Por exemplo, "DSN=SQLServer_Source; UID=SA; PWD=abc123" é uma possível seqüência de conexão. Observe que se você passar NULL para *lpszConnectString*, uma caixa de diálogo Fonte de dados solicitará ao usuário que selecione uma fonte de dados.

*dwOptions*<br/>
Uma máscara de bit que especifica uma combinação dos seguintes valores. O valor padrão é 0, o que significa que o banco de dados será aberto conforme compartilhado com o acesso à gravação, o DLL da Biblioteca do Cursor ODBC não será carregado e a caixa de diálogo de conexão ODBC será exibida somente se não houver informações suficientes para fazer a conexão.

- `CDatabase::openExclusive`Não suportado nesta versão da biblioteca de classe. Uma fonte de dados é sempre aberta como compartilhada (não exclusiva). Atualmente, uma afirmação falha se você especificar essa opção.

- `CDatabase::openReadOnly`Abra a fonte de dados apenas como leitura.

- `CDatabase::useCursorLib`Carregar o DLL da Biblioteca do Cursor ODBC. A biblioteca do cursor mascara algumas funcionalidades do driver ODBC subjacente, impedindo efetivamente o uso de dynasets (se o driver os suporta). Os únicos cursores suportados se a biblioteca do cursor estiver carregada são instantâneos estáticos e cursores somente para frente. Se você planeja criar um objeto `CRecordset` de conjunto de registros diretamente sem derivar dele, você não deve carregar a biblioteca do cursor.

- `CDatabase::noOdbcDialog`Não exiba a caixa de diálogo de conexão ODBC, independentemente de informações de conexão suficientes.

- `CDatabase::forceOdbcDialog`Sempre exiba a caixa de diálogo de conexão ODBC.

### <a name="return-value"></a>Valor retornado

Não zero se a conexão for feita com sucesso; caso contrário 0 se o usuário escolher Cancelar quando apresentado uma caixa de diálogo pedindo mais informações de conexão. Em todos os outros casos, o quadro abre uma exceção.

### <a name="remarks"></a>Comentários

O objeto do banco de dados deve ser inicializado antes de poder usá-lo para construir um objeto de conjunto de registros.

Se o parâmetro *lpszConnectString* na `OpenEx` sua chamada não contiver informações suficientes para fazer a conexão, o driver ODBC `CDatabase::noOdbcDialog` abrirá uma caixa de diálogo para obter as informações necessárias do usuário, desde que você não tenha definido ou `CDatabase::forceOdbcDialog` no parâmetro *dwOptions.* Quando você `OpenEx`chama , sua seqüência de conexão, `CDatabase` *lpszConnectString*, é armazenado privadamente no objeto e está disponível chamando a função de membro [GetConnect.](#getconnect)

Se desejar, você pode abrir sua própria `OpenEx` caixa de diálogo antes de ligar para obter informações do usuário, `OpenEx`como uma senha, e, em seguida, adicionar essas informações à seqüência de conexão para a que você passa . Ou você pode querer salvar a seqüência de conexão que você `OpenEx` passa `CDatabase` para que você possa reutilizá-la na próxima vez que seu aplicativo chamar um objeto.

Você também pode usar a seqüência de conexões `CDatabase` para vários níveis de autorização de login (cada um para um objeto diferente) ou para transmitir outras informações específicas da fonte de dados. Para obter mais informações sobre as seqüências de conexões, consulte o Capítulo 6 no *Programador de Referência da ODBC*.

É possível para uma tentativa de conexão de tempo se, por exemplo, o host DBMS não estiver disponível. Se a tentativa `OpenEx` de `CDBException`conexão falhar, lança um .

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCDatabase#11](../../mfc/codesnippet/cpp/cdatabase-class_7.cpp)]

## <a name="cdatabaserollback"></a><a name="rollback"></a>CDatabase:::Reversão

Ligue para esta função de membro para reverter as alterações feitas durante uma transação.

```
BOOL Rollback();
```

### <a name="return-value"></a>Valor retornado

Não zero se a transação foi revertida com sucesso; caso contrário, 0. Se `Rollback` uma chamada falhar, a fonte de dados e os estados de transação serão indefinidos. Se `Rollback` retornar 0, você deve verificar a fonte de dados para determinar seu estado.

### <a name="remarks"></a>Comentários

Todas `CRecordset` `AddNew` `Edit`as `Delete` `Update` chamadas executadas desde a última [StartTrans](#begintrans) são revertidas para o estado que existia no momento da chamada.

Após uma `Rollback`chamada para , a transação `BeginTrans` acabou, e você deve chamar novamente para outra transação. O registro que era `BeginTrans` atual antes de `Rollback`você chamar torna-se o registro atual novamente depois .

Após uma reversão, o registro que estava atual antes da reversão permanece atual. Para obter detalhes sobre o estado do conjunto de registros e a fonte de dados após uma reversão, consulte o artigo [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>Exemplo

  Veja o artigo [Transação: Realizando uma Transação em um Conjunto de Registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

## <a name="cdatabasesetlogintimeout"></a><a name="setlogintimeout"></a>Banco de dados::SetLoginTimeout

Ligue para esta função `OpenEx` de `Open` membro — antes de ligar ou — para substituir o número padrão de segundos permitido antes que uma tentativa de conexão de origem de dados seja cancelada.

```
void SetLoginTimeout(DWORD dwSeconds);
```

### <a name="parameters"></a>Parâmetros

*dwSeconds*<br/>
O número de segundos para permitir antes de uma tentativa de conexão se esespera.

### <a name="remarks"></a>Comentários

Uma tentativa de conexão pode ser cronometrada se, por exemplo, o DBMS não estiver disponível. Ligue `SetLoginTimeout` depois de construir `CDatabase` o objeto não `OpenEx` `Open`inicializado, mas antes de ligar ou .

O valor padrão para intervalos de login é de 15 segundos. Nem todas as fontes de dados suportam a capacidade de especificar um valor de tempo de tempo de login. Se a fonte de dados não suportar o tempo háde, você terá uma saída de rastreamento, mas não uma exceção. Um valor de 0 significa "infinito".

## <a name="cdatabasesetquerytimeout"></a><a name="setquerytimeout"></a>CDatabase::SetQueryTimeout

Ligue para esta função de membro para substituir o número padrão de segundos para permitir antes das operações subseqüentes no tempo de saída da fonte de dados conectado.

```
void SetQueryTimeout(DWORD dwSeconds);
```

### <a name="parameters"></a>Parâmetros

*dwSeconds*<br/>
O número de segundos a serem permitidos antes de uma tentativa de consulta é eliminado.

### <a name="remarks"></a>Comentários

Uma operação pode ser deshorada devido a problemas de acesso à rede, tempo de processamento de consulta excessiva, e assim por diante. Ligue `SetQueryTimeout` antes de abrir seu conjunto de registros `AddNew`ou `Update` `Delete` antes de chamar as funções do conjunto de registros ou de membro se quiser alterar o valor de tempo de consulta. A configuração afeta `Open` `AddNew`todas `Update`as `Delete` chamadas subseqüentes e `CDatabase` chamadas para quaisquer conjuntos de registros associados a este objeto. Alterar o valor de tempo de consulta para um conjunto de registros após a abertura não altera o valor do conjunto de registros. Por exemplo, `Move` as operações subseqüentes não usam o novo valor.

O valor padrão para intervalos de consulta é de 15 segundos. Nem todas as fontes de dados suportam a capacidade de definir um valor de tempo de tempo de consulta. Se você definir um valor de tempo de consulta de 0, não haverá intervalo; a comunicação com a fonte de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento. Se a fonte de dados não suportar o tempo háde, você terá uma saída de rastreamento, mas não uma exceção.

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
