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
ms.openlocfilehash: ebc36d82af9bfe12ab30a86214e58610b5eaab95
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866265"
---
# <a name="cdatabase-class"></a>Classe CDatabase

Representa uma conexão com uma fonte de dados, por meio da qual você pode operar na fonte de dados.

## <a name="syntax"></a>Sintaxe

```
class CDatabase : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDatabase:: CDatabase](#cdatabase)|Constrói um objeto `CDatabase`. Você deve inicializar o objeto chamando `OpenEx` ou `Open`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDatabase:: BeginTrans](#begintrans)|Inicia uma "transação" — uma série de chamadas reversível para as funções de `AddNew`, `Edit`, `Delete`e `Update` membro do `CRecordset` de classe — na fonte de dados conectada. A fonte de dados deve dar suporte a transações para `BeginTrans` ter qualquer efeito.|
|[CDatabase:: BindParameters](#bindparameters)|Permite associar parâmetros antes de chamar `CDatabase::ExecuteSQL`.|
|[CDatabase:: Cancel](#cancel)|Cancela uma operação assíncrona ou um processo de um segundo thread.|
|[CDatabase:: CanTransact](#cantransact)|Retornará zero se a fonte de dados der suporte a transações.|
|[CDatabase:: CanUpdate](#canupdate)|Retornará zero se o objeto de `CDatabase` for atualizável (não somente leitura).|
|[CDatabase:: fechar](#close)|Fecha a conexão da fonte de dados.|
|[CDatabase:: CommitTrans](#committrans)|Conclui uma transação iniciada pelo `BeginTrans`. Os comandos na transação que alteram a fonte de dados são executados.|
|[CDatabase:: ExecuteSQL](#executesql)|Executa uma instrução SQL. Nenhum registro de dados é retornado.|
|[CDatabase:: GetBookmarkPersistence](#getbookmarkpersistence)|Identifica as operações por meio das quais os indicadores persistem em objetos Recordset.|
|[CDatabase:: GetConnect](#getconnect)|Retorna a cadeia de conexão ODBC usada para conectar o objeto `CDatabase` a uma fonte de dados.|
|[CDatabase:: GetCursorCommitBehavior](#getcursorcommitbehavior)|Identifica o efeito de confirmar uma transação em um objeto Open Recordset.|
|[CDatabase:: GetCursorRollbackBehavior](#getcursorrollbackbehavior)|Identifica o efeito de reverter uma transação em um objeto Open Recordset.|
|[CDatabase:: GetDatabaseName](#getdatabasename)|Retorna o nome do banco de dados em uso no momento.|
|[CDatabase:: IsOpen](#isopen)|Retornará zero se o objeto de `CDatabase` estiver conectado atualmente a uma fonte de dados.|
|[CDatabase:: OnSetOptions](#onsetoptions)|Chamado pelo Framework para definir opções de conexão padrão. A implementação padrão define o valor de tempo limite da consulta. Você pode estabelecer essas opções com antecedência chamando `SetQueryTimeout`.|
|[CDatabase:: abrir](#open)|Estabelece uma conexão com uma fonte de dados (por meio de um driver ODBC).|
|[CDatabase:: OpenEx](#openex)|Estabelece uma conexão com uma fonte de dados (por meio de um driver ODBC).|
|[CDatabase:: Rollback](#rollback)|Reverte as alterações feitas durante a transação atual. A fonte de dados retorna ao estado anterior, conforme definido no `BeginTrans` chamada, inalterado.|
|[CDatabase:: SetLoginTimeout](#setlogintimeout)|Define o número de segundos após o qual uma tentativa de conexão de fonte de dados atingirá o tempo limite.|
|[CDatabase:: SetQueryTimeout](#setquerytimeout)|Define o número de segundos após o qual as operações de consulta do banco de dados atingirão o tempo limite. Afeta todas as `Open`do conjunto de registros subsequentes, `AddNew`, `Edit`e chamadas `Delete`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CDatabase:: m_hdbc](#m_hdbc)|Identificador de conexão ODBC (Open Database Connectivity) para uma fonte de dados. Digite *HDBC*.|

## <a name="remarks"></a>Comentários

Uma fonte de dados é uma instância específica de dados hospedados por algum DBMS (sistema de gerenciamento de banco de dados). Os exemplos incluem Microsoft SQL Server, Microsoft Access, Borland dBASE e xBASE. Você pode ter um ou mais objetos `CDatabase` ativas por vez em seu aplicativo.

> [!NOTE]
>  Se você estiver trabalhando com as classes DAO (objetos de acesso a dados) em vez das classes ODBC (Open Database Connectivity), use a classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

Para usar `CDatabase`, construa um objeto `CDatabase` e chame sua função de membro `OpenEx`. Isso abre uma conexão. Quando você constrói `CRecordset` objetos para operar na fonte de dados conectada, passe o construtor do conjunto de registros um ponteiro para o objeto `CDatabase`. Quando você terminar de usar a conexão, chame a função membro `Close` e destrua o objeto `CDatabase`. `Close` fecha os conjuntos de registros que você não fechou anteriormente.

Para obter mais informações sobre `CDatabase`, consulte a [fonte de dados de artigos (ODBC)](../../data/odbc/data-source-odbc.md) e [visão geral: programação de banco](../../data/data-access-programming-mfc-atl.md)de dados.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CDatabase`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFXDB. h

##  <a name="begintrans"></a>CDatabase:: BeginTrans

Chame essa função de membro para iniciar uma transação com a fonte de dados conectada.

```
BOOL BeginTrans();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a chamada foi bem-sucedida e as alterações são confirmadas somente manualmente; caso contrário, 0.

### <a name="remarks"></a>Comentários

Uma transação consiste em uma ou mais chamadas para as funções de membro `AddNew`, `Edit`, `Delete`e `Update` de um objeto `CRecordset`. Antes de iniciar uma transação, o objeto `CDatabase` já deve ter sido conectado à fonte de dados chamando sua `OpenEx` ou `Open` função membro. Para encerrar a transação, chame o [CommitTrans](#committrans) para aceitar todas as alterações na fonte de dados (e realize-as) ou chame [Rollback](#rollback) para anular a transação inteira. Chame `BeginTrans` depois de abrir todos os conjuntos de registros envolvidos na transação e o mais próximo possível das operações de atualização reais.

> [!CAUTION]
>  Dependendo do seu driver ODBC, abrir um conjunto de registros antes de chamar `BeginTrans` pode causar problemas ao chamar `Rollback`. Você deve verificar o driver específico que está usando. Por exemplo, ao usar o driver do Microsoft Access incluído no Microsoft ODBC Desktop driver Pack 3,0, você deve considerar o requisito do mecanismo de banco de dados Jet que você não deve iniciar uma transação em qualquer banco de dados que tenha um cursor aberto. Nas classes de banco de dados MFC, um cursor aberto significa um objeto Open `CRecordset`. Para obter mais informações, consulte a [Nota técnica 68](../../mfc/tn068-performing-transactions-with-the-microsoft-access-7-odbc-driver.md).

`BeginTrans` também pode bloquear os registros de dados no servidor, dependendo da simultaneidade solicitada e dos recursos da fonte de dados. Para obter informações sobre como bloquear dados, consulte o artigo [Recordset: locking Records (ODBC)](../../data/odbc/recordset-locking-records-odbc.md).

As transações definidas pelo usuário são explicadas no artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).

`BeginTrans` estabelece o estado para o qual a sequência de transações pode ser revertida (invertida). Para estabelecer um novo estado para reversões, confirme qualquer transação atual e, em seguida, chame `BeginTrans` novamente.

> [!CAUTION]
>  Chamar `BeginTrans` novamente sem chamar `CommitTrans` ou `Rollback` é um erro.

Chame a função de membro [CanTransact](#cantransact) para determinar se o driver dá suporte a transações para um determinado banco de dados. Você também deve chamar [GetCursorCommitBehavior](#getcursorcommitbehavior) e [GetCursorRollbackBehavior](#getcursorrollbackbehavior) para determinar o suporte para preservação do cursor.

Para obter mais informações sobre transações, consulte o artigo [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o artigo [transação: executando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

##  <a name="bindparameters"></a>CDatabase:: BindParameters

Substitua `BindParameters` quando precisar associar parâmetros antes de chamar [CDatabase:: ExecuteSQL](#executesql).

```
virtual void BindParameters(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*hstmt*<br/>
O identificador de instrução ODBC para o qual você deseja associar parâmetros.

### <a name="remarks"></a>Comentários

Essa abordagem é útil quando você não precisa do conjunto de resultados de um procedimento armazenado.

Em sua substituição, chame `SQLBindParameters` e funções ODBC relacionadas para associar os parâmetros. O MFC chama sua substituição antes de sua chamada para `ExecuteSQL`. Você não precisa chamar `SQLPrepare`; `ExecuteSQL` chama `SQLExecDirect` e destrói o *HSTMT*, que é usado apenas uma vez.

##  <a name="cancel"></a>CDatabase:: Cancel

Chame essa função de membro para solicitar que a fonte de dados cancele uma operação assíncrona em andamento ou um processo de um segundo thread.

```
void Cancel();
```

### <a name="remarks"></a>Comentários

Observe que as classes ODBC do MFC não usam mais o processamento assíncrono; para executar uma operação assíncrona, você deve chamar diretamente a função [SQLSetConnectOption](/sql/odbc/reference/syntax/sqlsetconnectoption-function)da API ODBC. Para obter mais informações, consulte [Execução assíncrona](/sql/odbc/reference/develop-app/asynchronous-execution).

##  <a name="cantransact"></a>CDatabase:: CanTransact

Chame essa função de membro para determinar se o banco de dados permite transações.

```
BOOL CanTransact() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se os conjuntos de registros que usam este `CDatabase` objeto permitir transações; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para obter informações sobre transações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).

##  <a name="canupdate"></a>CDatabase:: CanUpdate

Chame essa função de membro para determinar se o objeto de `CDatabase` permite atualizações.

```
BOOL CanUpdate() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto `CDatabase` permitir atualizações; caso contrário, 0, indicando que você passou TRUE em *bReadOnly* quando você abriu o objeto `CDatabase` ou que a própria fonte de dados é somente leitura. A fonte de dados será somente leitura se uma chamada para a função da API do ODBC `SQLGetInfo` para SQL_DATASOURCE_READ_ONLY retornar "y".

### <a name="remarks"></a>Comentários

Nem todos os drivers dão suporte a atualizações.

##  <a name="cdatabase"></a>CDatabase:: CDatabase

Constrói um objeto `CDatabase`.

```
CDatabase();
```

### <a name="remarks"></a>Comentários

Depois de construir o objeto, você deve chamar sua `OpenEx` ou `Open` função membro para estabelecer uma conexão com uma fonte de dados especificada.

Talvez seja conveniente inserir o objeto `CDatabase` em sua classe de documento.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

Este exemplo ilustra o uso de `CDatabase` em uma classe derivada de `CDocument`.

[!code-cpp[NVC_MFCDatabase#9](../../mfc/codesnippet/cpp/cdatabase-class_1.h)]

[!code-cpp[NVC_MFCDatabase#10](../../mfc/codesnippet/cpp/cdatabase-class_2.cpp)]

##  <a name="close"></a>CDatabase:: fechar

Chame essa função de membro se você quiser se desconectar de uma fonte de dados.

```
virtual void Close();
```

### <a name="remarks"></a>Comentários

Você deve fechar todos os conjuntos de registros associados ao objeto `CDatabase` antes de chamar essa função de membro. Como `Close` não destrói o objeto `CDatabase`, você pode reutilizar o objeto abrindo uma nova conexão com a mesma fonte de dados ou uma fonte de dados diferente.

Todas as instruções pendentes de `AddNew` ou `Edit` de conjuntos de registros usando o banco de dados são canceladas e todas as transações pendentes são revertidas. Todos os conjuntos de registros dependentes do objeto `CDatabase` são deixados em um estado indefinido.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDatabase#12](../../mfc/codesnippet/cpp/cdatabase-class_3.cpp)]

##  <a name="committrans"></a>CDatabase:: CommitTrans

Chame essa função de membro na conclusão de transações.

```
BOOL CommitTrans();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se as atualizações tiverem sido confirmadas com êxito; caso contrário, 0. Se `CommitTrans` falhar, o estado da fonte de dados será indefinido. Você deve verificar os dados para determinar seu estado.

### <a name="remarks"></a>Comentários

Uma transação consiste em uma série de chamadas para as funções de membro `AddNew`, `Edit`, `Delete`e `Update` de um objeto de `CRecordset` que começou com uma chamada para a função de membro [BeginTrans](#begintrans) . `CommitTrans` confirma a transação. Por padrão, as atualizações são confirmadas imediatamente; chamar `BeginTrans` faz com que o compromisso das atualizações seja atrasado até que `CommitTrans` seja chamado.

Até que você chame `CommitTrans` para encerrar uma transação, você pode chamar a função de membro [Rollback](#rollback) para anular a transação e deixar a fonte de dados em seu estado original. Para iniciar uma nova transação, chame `BeginTrans` novamente.

Para obter mais informações sobre transações, consulte o artigo [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o artigo [transação: executando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

##  <a name="executesql"></a>CDatabase:: ExecuteSQL

Chame essa função de membro quando precisar executar um comando SQL diretamente.

```
void ExecuteSQL(LPCTSTR lpszSQL);
```

### <a name="parameters"></a>Parâmetros

*lpszSQL*<br/>
Ponteiro para uma cadeia de caracteres terminada em nulo que contém um comando SQL válido a ser executado. Você pode passar um [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

Crie o comando como uma cadeia de caracteres terminada em nulo. `ExecuteSQL` não retorna registros de dados. Se você quiser operar em registros, use um objeto Recordset em vez disso.

A maioria dos seus comandos para uma fonte de dados é emitida por meio de objetos recordset, que dão suporte a comandos para selecionar dados, inserir novos registros, excluir registros e editar registros. No entanto, nem toda a funcionalidade ODBC é diretamente suportada pelas classes de banco de dados, de modo que você pode precisar fazer uma chamada direta do SQL com `ExecuteSQL`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDatabase#13](../../mfc/codesnippet/cpp/cdatabase-class_4.cpp)]

##  <a name="getbookmarkpersistence"></a>CDatabase:: GetBookmarkPersistence

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
|SQL_BP_CLOSE|Os indicadores são válidos após uma operação de `Requery`.|
|SQL_BP_DELETE|O indicador de uma linha é válido após uma operação de `Delete` nessa linha.|
|SQL_BP_DROP|Os indicadores são válidos após uma operação de `Close`.|
|SQL_BP_SCROLL|Os indicadores são válidos após qualquer operação de `Move`. Isso simplesmente identifica se os indicadores são compatíveis com o conjunto de registros, como retornado por `CRecordset::CanBookmark`.|
|SQL_BP_TRANSACTION|Os indicadores são válidos depois que uma transação é confirmada ou revertida.|
|SQL_BP_UPDATE|O indicador de uma linha é válido após uma operação de `Update` nessa linha.|
|SQL_BP_OTHER_HSTMT|Indicadores associados a um objeto recordset são válidos em um segundo conjunto de registros.|

Para obter mais informações sobre esse valor de retorno, consulte a função da API do ODBC `SQLGetInfo` no SDK do Windows. Para obter mais informações sobre indicadores, consulte o artigo [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).

##  <a name="getconnect"></a>CDatabase:: GetConnect

Chame essa função de membro para recuperar a cadeia de conexão usada durante a chamada para `OpenEx` ou `Open` que conectou o objeto `CDatabase` a uma fonte de dados.

```
const CString GetConnect() const;
```

### <a name="return-value"></a>Valor retornado

Um[CString](../../atl-mfc-shared/reference/cstringt-class.md) de const contendo a cadeia de conexão se `OpenEx` ou `Open` tiver sido chamado; caso contrário, uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

Consulte [CDatabase:: Open](#open) para obter uma descrição de como a cadeia de conexão é criada.

##  <a name="getcursorcommitbehavior"></a>CDatabase:: GetCursorCommitBehavior

Chame essa função de membro para determinar como uma operação de [CommitTrans](#committrans) afeta os cursores em objetos Open Recordset.

```
int GetCursorCommitBehavior() const;
```

### <a name="return-value"></a>Valor retornado

Um valor que indica o efeito de transações em objetos Open Recordset. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

A tabela a seguir lista os possíveis valores de retorno para `GetCursorCommitBehavior` e o efeito correspondente no conjunto de registros aberto.

|Valor retornado|Efeito em objetos CRecordset|
|------------------|----------------------------------|
|SQL_CB_CLOSE|Chame `CRecordset::Requery` imediatamente após a confirmação da transação.|
|SQL_CB_DELETE|Chame `CRecordset::Close` imediatamente após a confirmação da transação.|
|SQL_CB_PRESERVE|Prossiga normalmente com operações de `CRecordset`.|

Para obter mais informações sobre esse valor de retorno, consulte a função da API do ODBC `SQLGetInfo` no SDK do Windows. Para obter mais informações sobre transações, consulte o artigo [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

##  <a name="getcursorrollbackbehavior"></a>CDatabase:: GetCursorRollbackBehavior

Chame essa função de membro para determinar como uma operação de [reversão](#rollback) afeta os cursores em objetos Open Recordset.

```
int GetCursorRollbackBehavior() const;
```

### <a name="return-value"></a>Valor retornado

Um valor que indica o efeito de transações em objetos Open Recordset. Para obter detalhes, consulte Observações.

### <a name="remarks"></a>Comentários

A tabela a seguir lista os possíveis valores de retorno para `GetCursorRollbackBehavior` e o efeito correspondente no conjunto de registros aberto.

|Valor retornado|Efeito em objetos CRecordset|
|------------------|----------------------------------|
|SQL_CB_CLOSE|Chame `CRecordset::Requery` imediatamente após a reversão da transação.|
|SQL_CB_DELETE|Chame `CRecordset::Close` imediatamente após a reversão da transação.|
|SQL_CB_PRESERVE|Prossiga normalmente com operações de `CRecordset`.|

Para obter mais informações sobre esse valor de retorno, consulte a função da API do ODBC `SQLGetInfo` no SDK do Windows. Para obter mais informações sobre transações, consulte o artigo [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

##  <a name="getdatabasename"></a>CDatabase:: GetDatabaseName

Chame essa função de membro para recuperar o nome do banco de dados conectado no momento (desde que a fonte de dado defina um objeto nomeado chamado "Database").

```
CString GetDatabaseName() const;
```

### <a name="return-value"></a>Valor retornado

Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o nome do banco de dados, se for bem-sucedido; caso contrário, um `CString`vazio.

### <a name="remarks"></a>Comentários

Isso não é o mesmo que o nome da fonte de dados (DSN) especificado na chamada de `OpenEx` ou `Open`. O que `GetDatabaseName` retorna depende do ODBC. Em geral, um banco de dados é uma coleção de tabelas. Se essa entidade tiver um nome, `GetDatabaseName` a retornará.

Você pode, por exemplo, querer exibir esse nome em um título. Se ocorrer um erro ao recuperar o nome do ODBC, `GetDatabaseName` retornará um `CString`vazio.

##  <a name="isopen"></a>CDatabase:: IsOpen

Chame essa função de membro para determinar se o objeto de `CDatabase` está conectado atualmente a uma fonte de dados.

```
BOOL IsOpen() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto `CDatabase` estiver conectado no momento; caso contrário, 0.

##  <a name="m_hdbc"></a>CDatabase:: m_hdbc

Contém um identificador público para uma conexão de fonte de dados ODBC — uma "identificador de conexão".

### <a name="remarks"></a>Comentários

Normalmente, não será necessário acessar essa variável de membro diretamente. Em vez disso, a estrutura aloca o identificador quando você chama `OpenEx` ou `Open`. A estrutura Desaloca o identificador quando você chama o operador **delete** no objeto `CDatabase`. Observe que a função membro `Close` não Desaloca o identificador.

Em algumas circunstâncias, no entanto, talvez seja necessário usar o identificador diretamente. Por exemplo, se você precisar chamar funções da API ODBC diretamente, em vez de `CDatabase`de classe, talvez seja necessário um identificador de conexão para passar como um parâmetro. Consulte o exemplo de código abaixo.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDatabase#15](../../mfc/codesnippet/cpp/cdatabase-class_5.cpp)]

##  <a name="onsetoptions"></a>CDatabase:: OnSetOptions

A estrutura chama essa função de membro ao executar diretamente uma instrução SQL com a função membro `ExecuteSQL`.

```
virtual void OnSetOptions(HSTMT hstmt);
```

### <a name="parameters"></a>Parâmetros

*hstmt*<br/>
O identificador de instrução ODBC para o qual as opções estão sendo definidas.

### <a name="remarks"></a>Comentários

`CRecordset::OnSetOptions` também chama essa função de membro.

`OnSetOptions` define o valor de tempo limite de logon. Se houver chamadas anteriores para a função `SetQueryTimeout` e membro, `OnSetOptions` refletirá os valores atuais; caso contrário, ele define valores padrão.

> [!NOTE]
>  Antes do MFC 4,2, `OnSetOptions` também definir o modo de processamento como snychronous ou Asynchronous. A partir do MFC 4,2, todas as operações são síncronas. Para executar uma operação assíncrona, você deve fazer uma chamada direta para a função da API do ODBC `SQLSetPos`.

Você não precisa substituir `OnSetOptions` para alterar o valor de tempo limite. Em vez disso, para personalizar o valor de tempo limite da consulta, chame `SetQueryTimeout` antes de criar um conjunto de registros; `OnSetOptions` usará o novo valor. Os valores definidos se aplicam a operações subsequentes em todos os conjuntos de registros ou chamadas diretas do SQL.

Substitua `OnSetOptions` se desejar definir opções adicionais. Sua substituição deve chamar a classe base `OnSetOptions` antes ou depois de chamar a função da API do ODBC `SQLSetStmtOption`. Siga o método ilustrado na implementação padrão da estrutura de `OnSetOptions`.

##  <a name="open"></a>CDatabase:: abrir

Chame essa função de membro para inicializar um objeto de `CDatabase` recém-criado.

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
Especifica um nome de fonte de dados — um nome registrado com ODBC por meio do programa Administrador ODBC. Se um valor de DSN for especificado em *lpszConnect* (no formato "DSN =\<> de fonte de dados"), ele não deverá ser especificado novamente em *lpszDSN*. Nesse caso, *lpszDSN* deve ser nulo. Caso contrário, você poderá passar NULL se desejar apresentar ao usuário uma caixa de diálogo de fonte de dados na qual o usuário pode selecionar uma fonte de dados. Para obter mais informações, consulte comentários.

*bExclusive*<br/>
Sem suporte nesta versão da biblioteca de classes. Atualmente, uma asserção falhará se esse parâmetro for TRUE. A fonte de dados sempre é aberta como compartilhada (não exclusiva).

*bReadOnly*<br/>
TRUE se você pretende que a conexão seja somente leitura e proíba atualizações na fonte de dados. Todos os conjuntos de registros dependentes herdam este atributo. O valor padrão é FALSE.

*lpszConnect*<br/>
Especifica uma cadeia de conexão. A cadeia de conexão concatena informações, possivelmente incluindo um nome de fonte de dados, uma ID de usuário válida na fonte de dados, uma cadeia de caracteres de autenticação de usuário (senha, se a fonte de dados exigir uma) e outras informações. A cadeia de conexão inteira deve ser prefixada pela cadeia de caracteres "ODBC;" (maiúsculas ou minúsculas). A cadeia de caracteres "ODBC;" é usada para indicar que a conexão é para uma fonte de dados ODBC; Isso é para compatibilidade com a versão posterior, quando versões futuras da biblioteca de classes podem dar suporte a fontes de dados não ODBC.

*bUseCursorLib*<br/>
TRUE se você quiser que a DLL da biblioteca de cursores ODBC seja carregada. A biblioteca de cursores mascara algumas funcionalidades do driver ODBC subjacente, evitando efetivamente o uso de dynasets (se o driver oferecer suporte a eles). Os únicos cursores com suporte se a biblioteca de cursores são carregados são instantâneos estáticos e cursores de somente avanço. O valor padrão é TRUE. Se você planeja criar um objeto Recordset diretamente do `CRecordset` sem derivar dele, você não deve carregar a biblioteca de cursores.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a conexão for feita com êxito; caso contrário, 0 se o usuário escolher cancelar quando tiver apresentado uma caixa de diálogo solicitando mais informações de conexão. Em todos os outros casos, a estrutura gera uma exceção.

### <a name="remarks"></a>Comentários

Seu objeto de banco de dados deve ser inicializado antes que você possa usá-lo para construir um objeto Recordset.

> [!NOTE]
>  Chamar a função de membro [OpenEx](#openex) é a maneira preferida de se conectar a uma fonte de dados e inicializar o objeto de banco.

Se os parâmetros em sua chamada de `Open` não contiverem informações suficientes para fazer a conexão, o driver ODBC abrirá uma caixa de diálogo para obter as informações necessárias do usuário. Quando você chama `Open`, sua cadeia de conexão, *lpszConnect*, é armazenada em modo privado no objeto `CDatabase` e está disponível chamando a função membro [GetConnect](#getconnect) .

Se desejar, você pode abrir sua própria caixa de diálogo antes de chamar `Open` para obter informações do usuário, como uma senha, e adicionar essas informações à cadeia de conexão que você passa para `Open`. Ou talvez você queira salvar a cadeia de conexão que você passa para que possa reutilizá-la na próxima vez em que o aplicativo chamar `Open` em um objeto `CDatabase`.

Você também pode usar a cadeia de conexão para vários níveis de autorização de logon (cada um para um objeto `CDatabase` diferente) ou para transmitir outras informações específicas da fonte de dados. Para obter mais informações sobre cadeias de conexão, consulte o capítulo 5 na SDK do Windows.

É possível que uma tentativa de conexão expire o tempo se, por exemplo, o host do DBMS não estiver disponível. Se a tentativa de conexão falhar, `Open` lançará uma `CDBException`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDatabase#14](../../mfc/codesnippet/cpp/cdatabase-class_6.cpp)]

##  <a name="openex"></a>CDatabase:: OpenEx

Chame essa função de membro para inicializar um objeto de `CDatabase` recém-criado.

```
virtual BOOL OpenEx(
    LPCTSTR lpszConnectString,
    DWORD dwOptions = 0);
```

### <a name="parameters"></a>Parâmetros

*lpszConnectString*<br/>
Especifica uma cadeia de conexão ODBC. Isso inclui o nome da fonte de dados, bem como outras informações opcionais, como uma ID de usuário e senha. Por exemplo, "DSN = SQLServer_Source; UID = SA; PWD = abc123 "é uma possível cadeia de conexão. Observe que, se você passar NULL para *lpszConnectString*, uma caixa de diálogo fonte de dados solicitará que o usuário selecione uma fonte de dados.

*dwOptions*<br/>
Um bitmask que especifica uma combinação dos valores a seguir. O valor padrão é 0, o que significa que o banco de dados será aberto como compartilhado com acesso de gravação, a DLL de biblioteca de cursores ODBC não será carregada e a caixa de diálogo conexão ODBC será exibida somente se não houver informações suficientes para fazer a conexão.

- Não há suporte para `CDatabase::openExclusive` nesta versão da biblioteca de classes. Uma fonte de dados é sempre aberta como compartilhada (não exclusiva). Atualmente, uma asserção falhará se você especificar essa opção.

- `CDatabase::openReadOnly` abrir a fonte de dados como somente leitura.

- `CDatabase::useCursorLib` carregar a DLL da biblioteca de cursores ODBC. A biblioteca de cursores mascara algumas funcionalidades do driver ODBC subjacente, evitando efetivamente o uso de dynasets (se o driver oferecer suporte a eles). Os únicos cursores com suporte se a biblioteca de cursores são carregados são instantâneos estáticos e cursores de somente avanço. Se você planeja criar um objeto Recordset diretamente do `CRecordset` sem derivar dele, você não deve carregar a biblioteca de cursores.

- `CDatabase::noOdbcDialog` não exibir a caixa de diálogo conexão ODBC, independentemente de as informações de conexão suficientes terem sido fornecidas.

- `CDatabase::forceOdbcDialog` sempre exibir a caixa de diálogo conexão ODBC.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a conexão for feita com êxito; caso contrário, 0 se o usuário escolher cancelar quando tiver apresentado uma caixa de diálogo solicitando mais informações de conexão. Em todos os outros casos, a estrutura gera uma exceção.

### <a name="remarks"></a>Comentários

Seu objeto de banco de dados deve ser inicializado antes que você possa usá-lo para construir um objeto Recordset.

Se o parâmetro *lpszConnectString* em sua chamada de `OpenEx` não contiver informações suficientes para fazer a conexão, o driver ODBC abrirá uma caixa de diálogo para obter as informações necessárias do usuário, desde que você não tenha definido `CDatabase::noOdbcDialog` ou `CDatabase::forceOdbcDialog` no parâmetro *dwOptions* . Quando você chama `OpenEx`, sua cadeia de conexão, *lpszConnectString*, é armazenada em modo privado no objeto `CDatabase` e está disponível chamando a função membro [GetConnect](#getconnect) .

Se desejar, você pode abrir sua própria caixa de diálogo antes de chamar `OpenEx` para obter informações do usuário, como uma senha e, em seguida, adicionar essas informações à cadeia de conexão que você passa para `OpenEx`. Ou talvez você queira salvar a cadeia de conexão que você passa para que possa reutilizá-la na próxima vez em que o aplicativo chamar `OpenEx` em um objeto `CDatabase`.

Você também pode usar a cadeia de conexão para vários níveis de autorização de logon (cada um para um objeto `CDatabase` diferente) ou para transmitir outras informações específicas da fonte de dados. Para obter mais informações sobre cadeias de conexão, consulte o capítulo 6 na *referência do programador de ODBC*.

É possível que uma tentativa de conexão expire o tempo se, por exemplo, o host do DBMS não estiver disponível. Se a tentativa de conexão falhar, `OpenEx` lançará uma `CDBException`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCDatabase#11](../../mfc/codesnippet/cpp/cdatabase-class_7.cpp)]

##  <a name="rollback"></a>CDatabase:: Rollback

Chame essa função de membro para reverter as alterações feitas durante uma transação.

```
BOOL Rollback();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se a transação tiver sido revertida com êxito; caso contrário, 0. Se uma chamada de `Rollback` falhar, a fonte de dados e os Estados de transação serão indefinidos. Se `Rollback` retornar 0, você deverá verificar a fonte de dados para determinar seu estado.

### <a name="remarks"></a>Comentários

Todas as chamadas `CRecordset` `AddNew`, `Edit`, `Delete`e `Update` executadas desde o último [BeginTrans](#begintrans) são revertidas para o estado que existia no momento da chamada.

Após uma chamada para `Rollback`, a transação terminará e você deverá chamar `BeginTrans` novamente para outra transação. O registro que era atual antes da chamada `BeginTrans` se torna o registro atual novamente após `Rollback`.

Após uma reversão, o registro que era atual antes da reversão permanece atual. Para obter detalhes sobre o estado do conjunto de registros e a fonte de dados após uma reversão, consulte a transação do artigo [(ODBC)](../../data/odbc/transaction-odbc.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o artigo [transação: executando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).

##  <a name="setlogintimeout"></a>CDatabase:: SetLoginTimeout

Chame essa função de membro — antes de chamar `OpenEx` ou `Open` — para substituir o número padrão de segundos permitido antes que uma tentativa de conexão de fonte de dados expire.

```
void SetLoginTimeout(DWORD dwSeconds);
```

### <a name="parameters"></a>Parâmetros

*dwSeconds*<br/>
O número de segundos para permitir antes que uma tentativa de conexão expire.

### <a name="remarks"></a>Comentários

Uma tentativa de conexão pode atingir o tempo limite se, por exemplo, o DBMS não estiver disponível. Chame `SetLoginTimeout` depois de construir o objeto de `CDatabase` não inicializado, mas antes de chamar `OpenEx` ou `Open`.

O valor padrão para tempos limite de logon é de 15 segundos. Nem todas as fontes de dados dão suporte à capacidade de especificar um valor de tempo limite de logon. Se a fonte de dados não der suporte ao tempo limite, você obterá a saída do rastreamento, mas não uma exceção. Um valor de 0 significa "infinito".

##  <a name="setquerytimeout"></a>CDatabase:: SetQueryTimeout

Chame essa função de membro para substituir o número padrão de segundos a permitir antes que as operações subsequentes na fonte de dados conectadas expirem.

```
void SetQueryTimeout(DWORD dwSeconds);
```

### <a name="parameters"></a>Parâmetros

*dwSeconds*<br/>
O número de segundos para permitir antes que uma tentativa de consulta expire.

### <a name="remarks"></a>Comentários

Uma operação pode atingir o tempo limite devido a problemas de acesso à rede, tempo excessivo de processamento de consultas e assim por diante. Chame `SetQueryTimeout` antes de abrir o conjunto de registros ou antes de chamar o `AddNew`do conjunto de registros, `Update` ou `Delete` funções de membro se você quiser alterar o valor de tempo limite da consulta. A configuração afeta todas as chamadas subsequentes `Open`, `AddNew`, `Update`e `Delete` para todos os conjuntos de registros associados a esse objeto `CDatabase`. Alterar o valor de tempo limite da consulta para um conjunto de registros após a abertura não altera o valor do conjunto de registros. Por exemplo, as operações de `Move` subsequentes não usam o novo valor.

O valor padrão para tempos limite de consulta é 15 segundos. Nem todas as fontes de dados dão suporte à capacidade de definir um valor de tempo limite de consulta. Se você definir um valor de tempo limite de consulta de 0, nenhum tempo limite ocorrerá; a comunicação com a fonte de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento. Se a fonte de dados não der suporte ao tempo limite, você obterá a saída do rastreamento, mas não uma exceção.

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
