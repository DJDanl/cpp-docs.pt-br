---
title: Classe CDatabase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6cb88decfd69fd7fb81667164f651e934ee08775
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42538784"
---
# <a name="cdatabase-class"></a>Classe CDatabase
Representa uma conexão a uma fonte de dados, por meio do qual você pode operar na fonte de dados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CDatabase : public CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDatabase::CDatabase](#cdatabase)|Constrói um objeto `CDatabase`. Você deve inicializar o objeto chamando `OpenEx` ou `Open`.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDatabase::BeginTrans](#begintrans)|Inicia uma transação de"" — uma série de chamadas reversíveis para o `AddNew`, `Edit`, `Delete`, e `Update` funções de membro de classe `CRecordset` — na fonte de dados conectada. A fonte de dados deve dar suporte a transações para `BeginTrans` tenha efeito.|  
|[CDatabase::BindParameters](#bindparameters)|Permite que você associe parâmetros antes de chamar `CDatabase::ExecuteSQL`.|  
|[CDatabase::Cancel](#cancel)|Cancela uma operação assíncrona ou um processo de um thread de segundo.|  
|[CDatabase::CanTransact](#cantransact)|Retorna diferente de zero se a fonte de dados oferece suporte a transações.|  
|[CDatabase::CanUpdate](#canupdate)|Retorna se diferente de zero a `CDatabase` objeto é atualizável (não somente leitura).|  
|[CDatabase::Close](#close)|Fecha a conexão de fonte de dados.|  
|[CDatabase::CommitTrans](#committrans)|Conclui uma transação iniciada por `BeginTrans`. Comandos na transação que alteram a fonte de dados são realizados.|  
|[CDatabase::](#executesql)|Executa uma instrução SQL. Não há registros de dados são retornados.|  
|[CDatabase::GetBookmarkPersistence](#getbookmarkpersistence)|Identifica as operações por meio dos quais persistem os indicadores em objetos de conjunto de registros.|  
|[CDatabase:: Getconnect](#getconnect)|Retorna a cadeia de conexão do ODBC usada para conectar-se a `CDatabase` objeto para uma fonte de dados.|  
|[CDatabase::GetCursorCommitBehavior](#getcursorcommitbehavior)|Identifica o efeito de confirmar uma transação em um objeto de conjunto de registros aberto.|  
|[CDatabase::GetCursorRollbackBehavior](#getcursorrollbackbehavior)|Identifica o efeito da reversão de uma transação em um objeto de conjunto de registros aberto.|  
|[CDatabase::GetDatabaseName](#getdatabasename)|Retorna o nome do banco de dados atualmente em uso.|  
|[CDatabase::IsOpen](#isopen)|Retorna se diferente de zero a `CDatabase` objeto está atualmente conectado a uma fonte de dados.|  
|[CDatabase::OnSetOptions](#onsetoptions)|Chamado pelo framework para definir opções de conexão padrão. A implementação padrão define o valor de tempo limite de consulta. Você pode estabelecer essas opções antecipadamente chamando `SetQueryTimeout`.|  
|[CDatabase:: Open](#open)|Estabelece uma conexão a uma fonte de dados (por meio de um driver ODBC).|  
|[CDatabase:: Openex](#openex)|Estabelece uma conexão a uma fonte de dados (por meio de um driver ODBC).|  
|[CDatabase::Rollback](#rollback)|Reverte as alterações feitas durante a transação atual. A fonte de dados retorna ao estado anterior, conforme definido no `BeginTrans` chamada, inalterada.|  
|[CDatabase::SetLoginTimeout](#setlogintimeout)|Define o número de segundos após o qual uma tentativa de conexão de fonte de dados atingirá o tempo limite.|  
|[CDatabase::SetQueryTimeout](#setquerytimeout)|Define o número de segundos após o qual banco de dados de operações de consulta atingirá o tempo limite. Afeta o conjunto de registros de todas as próximas `Open`, `AddNew`, `Edit`, e `Delete` chamadas.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDatabase::m_hdbc](#m_hdbc)|Abra o identificador de conexão de banco de dados ODBC (conectividade) para uma fonte de dados. Tipo de *HDBC*.|  
  
## <a name="remarks"></a>Comentários  
 Uma fonte de dados é uma instância específica de dados hospedados por algum sistema de gerenciamento de banco de dados (DBMS). Exemplos incluem o Microsoft SQL Server, Microsoft Access, dBASE Borland e xBASE. Você pode ter um ou mais `CDatabase` objetos ativos por vez em seu aplicativo.  
  
> [!NOTE]
>  Se você estiver trabalhando com as classes de objetos de acesso a dados (DAO) em vez das classes de conectividade de banco de dados aberto (ODBC), use a classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) em vez disso. Para obter mais informações, consulte o artigo [visão geral: banco de dados de programação](../../data/data-access-programming-mfc-atl.md).  
  
 Para usar `CDatabase`, construa um `CDatabase` objeto e chame seu `OpenEx` função de membro. Isso abre uma conexão. Quando você constrói, em seguida, `CRecordset` objetos para operar na fonte de dados conectada, passe ao construtor de conjunto de registros de um ponteiro para sua `CDatabase` objeto. Quando você terminar de usar a conexão, chame o `Close` membro de função e destruir o `CDatabase` objeto. `Close` Fecha a quaisquer conjuntos de registros que não tenha fechado anteriormente.  
  
 Para obter mais informações sobre `CDatabase`, consulte os artigos [fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md) e [visão geral: banco de dados de programação](../../data/data-access-programming-mfc-atl.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CDatabase`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdb. h  
  
##  <a name="begintrans"></a>  CDatabase::BeginTrans  
 Chame essa função de membro para iniciar uma transação com a fonte de dados conectada.  
  
```  
BOOL BeginTrans();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a chamada foi bem-sucedida e as alterações são confirmadas manualmente; apenas Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma transação consiste em uma ou mais chamadas para o `AddNew`, `Edit`, `Delete`, e `Update` funções de membro de um `CRecordset` objeto. Antes de iniciar uma transação, o `CDatabase` objeto deve já se conectou à fonte de dados, chamando seu `OpenEx` ou `Open` função de membro. Para terminar a transação, chame [CommitTrans](#committrans) para aceitar todas as alterações à fonte de dados (e executá-las) ou chamar [reversão](#rollback) para anular a transação inteira. Chamar `BeginTrans` depois de abrir qualquer envolvidos na transação de conjuntos de registros e como perto real operações de atualização quanto possível.  
  
> [!CAUTION]
>  Dependendo do seu driver de ODBC, abrir um conjunto de registros antes de chamar `BeginTrans` pode causar problemas ao chamar `Rollback`. Você deve verificar o driver específico que você está usando. Por exemplo, ao usar o driver do Microsoft Access incluído no Microsoft ODBC Desktop Driver Pack 3.0, você deve considerar os requisitos do mecanismo de banco de dados Jet que você não deve iniciar uma transação em qualquer banco de dados que tem um cursor aberto. As classes de banco de dados do MFC, um cursor aberto significa um aberto `CRecordset` objeto. Para obter mais informações, consulte [68 de observação técnica](../../mfc/tn068-performing-transactions-with-the-microsoft-access-7-odbc-driver.md).  
  
 `BeginTrans` também pode bloquear os registros de dados no servidor, dependendo da simultaneidade solicitada e os recursos da fonte de dados. Para obter informações sobre bloqueio de dados, consulte o artigo [conjunto de registros: bloqueando registros (ODBC)](../../data/odbc/recordset-locking-records-odbc.md).  
  
 Transações definidas pelo usuário são explicadas no artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
 `BeginTrans` estabelece o estado para o qual a sequência de transações pode ser revertida (invertido). Para estabelecer um novo estado para reversões, confirmar qualquer transação atual, em seguida, chame `BeginTrans` novamente.  
  
> [!CAUTION]
>  Chamando `BeginTrans` novamente sem chamar `CommitTrans` ou `Rollback` é um erro.  
  
 Chame o [CanTransact](#cantransact) a função de membro para determinar se o driver dá suporte a transações para um determinado banco de dados. Você também deve chamar [GetCursorCommitBehavior](#getcursorcommitbehavior) e [GetCursorRollbackBehavior](#getcursorrollbackbehavior) para determinar o suporte para preservação de cursor.  
  
 Para obter mais informações sobre transações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
### <a name="example"></a>Exemplo  
  Consulte o artigo [transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).  
  
##  <a name="bindparameters"></a>  CDatabase::BindParameters  
 Substituir `BindParameters` quando você precisa associar parâmetros antes de chamar [CDatabase::](#executesql).  
  
```  
virtual void BindParameters(HSTMT hstmt);
```  
  
### <a name="parameters"></a>Parâmetros  
 *HSTMT*  
 O identificador de instrução ODBC para o qual você deseja associar parâmetros.  
  
### <a name="remarks"></a>Comentários  
 Essa abordagem é útil quando o resultado não é necessário definir a partir de um procedimento armazenado.  
  
 Em sua substituição, chamar `SQLBindParameters` e relacionadas a funções ODBC para vincular os parâmetros. MFC chama sua substituição antes de chamar `ExecuteSQL`. Você não precisará chamar `SQLPrepare`; `ExecuteSQL` chamadas `SQLExecDirect` e destrói o *hstmt*, que é usado apenas uma vez.  
  
##  <a name="cancel"></a>  CDatabase::Cancel  
 Chame essa função de membro para solicitar que a fonte de dados cancela uma operação assíncrona em andamento ou um processo de um thread de segundo.  
  
```  
void Cancel();
```  
  
### <a name="remarks"></a>Comentários  
 Observe que as classes MFC ODBC não for mais usam o processamento assíncrono; para executar uma operação assíncrona, você deve chamar diretamente a função da API do ODBC [SQLSetConnectOption](/previous-versions/windows/desktop/ms713564\(v=vs.85\)). Para obter mais informações, consulte [execução assíncrona](/previous-versions/windows/desktop/ms713563\(v=vs.85\)) no SDK do Windows.  
  
##  <a name="cantransact"></a>  CDatabase::CanTransact  
 Chame essa função de membro para determinar se o banco de dados permite que as transações.  
  
```  
BOOL CanTransact() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se conjuntos de registros usando este `CDatabase` objeto permitir transações; caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Para obter informações sobre transações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="canupdate"></a>  CDatabase::CanUpdate  
 Chame essa função de membro para determinar se o `CDatabase` objeto permite atualizações.  
  
```  
BOOL CanUpdate() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CDatabase` objeto permite atualizações; caso contrário, 0, indicando que você passado verdadeira *bReadOnly* quando você abriu o `CDatabase` objeto ou da fonte de dados em si é somente leitura. A fonte de dados é somente leitura se uma chamada para a função ODBC API `SQLGetInfo` para SQL_DATASOURCE_READ_ONLY retorna "y".  
  
### <a name="remarks"></a>Comentários  
 Nem todos os drivers dão suporte a atualizações.  
  
##  <a name="cdatabase"></a>  CDatabase::CDatabase  
 Constrói um objeto `CDatabase`.  
  
```  
CDatabase();
```  
  
### <a name="remarks"></a>Comentários  
 Depois de construir o objeto, você deve chamar seu `OpenEx` ou `Open` a função de membro para estabelecer uma conexão a uma fonte de dados especificado.  
  
 Talvez seja conveniente para incorporar o `CDatabase` objeto em sua classe de documento.  
  
### <a name="example"></a>Exemplo  
 Este exemplo ilustra o uso `CDatabase` em um `CDocument`-classe derivada.  
  
 [!code-cpp[NVC_MFCDatabase#9](../../mfc/codesnippet/cpp/cdatabase-class_1.h)]  
  
 [!code-cpp[NVC_MFCDatabase#10](../../mfc/codesnippet/cpp/cdatabase-class_2.cpp)]  
  
##  <a name="close"></a>  CDatabase::Close  
 Chame essa função de membro, se você deseja desconectar de uma fonte de dados.  
  
```  
virtual void Close();
```  
  
### <a name="remarks"></a>Comentários  
 Você deve fechar quaisquer conjuntos de registros associados com o `CDatabase` antes de chamar essa função de membro de objeto. Porque `Close` não destrói o `CDatabase` do objeto, você pode reutilizar o objeto abrindo uma nova conexão para a mesma fonte de dados ou outra fonte de dados.  
  
 Todas as pendentes `AddNew` ou `Edit` instruções de conjuntos de registros usando o banco de dados são canceladas e todas as transações pendentes são revertidas. Qualquer dependentes de conjuntos de registros a `CDatabase` objeto são deixados em um estado indefinido.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDatabase#12](../../mfc/codesnippet/cpp/cdatabase-class_3.cpp)]  
  
##  <a name="committrans"></a>  CDatabase::CommitTrans  
 Chame essa função de membro após a conclusão de transações.  
  
```  
BOOL CommitTrans();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se as atualizações foram confirmadas com êxito; Caso contrário, 0. Se `CommitTrans` falhar, o estado da fonte de dados é indefinido. Você deve verificar os dados para determinar seu estado.  
  
### <a name="remarks"></a>Comentários  
 Uma transação consiste em uma série de chamadas para o `AddNew`, `Edit`, `Delete`, e `Update` funções de membro de um `CRecordset` objeto começou com uma chamada para o [BeginTrans](#begintrans) função de membro. `CommitTrans` confirma a transação. Por padrão, as atualizações são confirmadas imediatamente; chamando `BeginTrans` faz com que o compromisso de atualizações ser atrasada até `CommitTrans` é chamado.  
  
 Até que você chame `CommitTrans` para encerrar uma transação, você pode chamar o [Rollback](#rollback) função de membro para anular a transação e deixar a fonte de dados em seu estado original. Para iniciar uma nova transação, chame `BeginTrans` novamente.  
  
 Para obter mais informações sobre transações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
### <a name="example"></a>Exemplo  
  Consulte o artigo [transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).  
  
##  <a name="executesql"></a>  CDatabase::  
 Chame essa função de membro quando você precisa executar um comando SQL diretamente.  
  
```  
void ExecuteSQL(LPCTSTR lpszSQL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszSQL*  
 Ponteiro para uma cadeia de caracteres terminada em nulo que contém um comando SQL válido seja executado. Você pode passar uma [CString](../../atl-mfc-shared/reference/cstringt-class.md).  
  
### <a name="remarks"></a>Comentários  
 Crie o comando como uma cadeia de caracteres terminada em nulo. `ExecuteSQL` não retorna registros de dados. Se você quiser operam em registros, use um objeto de conjunto de registros.  
  
 A maioria dos seus comandos de uma fonte de dados é emitida por meio de objetos de conjunto de registros, que oferece suporte a comandos para selecionar os dados, inserir novos registros, exclusão de registros e editar registros. No entanto, nem todas as funcionalidades ODBC diretamente é suportada pelas classes de banco de dados, portanto você às vezes precisa fazer uma chamada direta de SQL com `ExecuteSQL`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDatabase#13](../../mfc/codesnippet/cpp/cdatabase-class_4.cpp)]  
  
##  <a name="getbookmarkpersistence"></a>  CDatabase::GetBookmarkPersistence  
 Chame essa função de membro para determinar a persistência de indicadores em um objeto Recordset depois de determinadas operações.  
  
```  
DWORD GetBookmarkPersistence() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma bitmask que identifica as operações através das quais persistem os indicadores em um objeto recordset. Para obter detalhes, consulte Observações.  
  
### <a name="remarks"></a>Comentários  
 Por exemplo, se você chamar `CRecordset::GetBookmark` e chamar `CRecordset::Requery`, o indicador obtido a partir de `GetBookmark` pode não ser mais válido. Você deve chamar `GetBookmarkPersistence` antes de chamar `CRecordset::SetBookmark`.  
  
 A tabela a seguir lista os valores de bitmask que podem ser combinados para o valor retornado de `GetBookmarkPersistence`.  
  
|Valor de bitmask|Persistência de indicador|  
|-------------------|--------------------------|  
|SQL_BP_CLOSE|Os indicadores são válidos após uma `Requery` operação.|  
|SQL_BP_DELETE|O indicador de uma linha é válido após um `Delete` operação nessa linha.|  
|SQL_BP_DROP|Os indicadores são válidos após uma `Close` operação.|  
|SQL_BP_SCROLL|Os indicadores são válidos após qualquer `Move` operação. Isso simplesmente identifica se os indicadores são compatíveis com o conjunto de registros, como retornado por `CRecordset::CanBookmark`.|  
|SQL_BP_TRANSACTION|Os indicadores são válidos depois que uma transação é confirmada ou revertida.|  
|SQL_BP_UPDATE|O indicador de uma linha é válido após um `Update` operação nessa linha.|  
|SQL_BP_OTHER_HSTMT|Indicadores associados a um objeto recordset são válidos em um segundo conjunto de registros.|  
  
 Para obter mais informações sobre esse valor de retorno, consulte a função de API ODBC `SQLGetInfo` no SDK do Windows. Para obter mais informações sobre os indicadores, consulte o artigo [conjunto de registros: indicadores e posições absolutas (ODBC)](../../data/odbc/recordset-bookmarks-and-absolute-positions-odbc.md).  
  
##  <a name="getconnect"></a>  CDatabase:: Getconnect  
 Chame essa função de membro para recuperar a cadeia de conexão usada durante a chamada para `OpenEx` ou `Open` que conectado a `CDatabase` objeto para uma fonte de dados.  
  
```  
const CString GetConnect() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um **const**[CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém a cadeia de caracteres de conexão se `OpenEx` ou `Open` tiver sido chamado; caso contrário, uma cadeia de caracteres vazia.  
  
### <a name="remarks"></a>Comentários  
 Ver [CDatabase:: Open](#open) para obter uma descrição de como a cadeia de caracteres de conexão é criada.  
  
##  <a name="getcursorcommitbehavior"></a>  CDatabase::GetCursorCommitBehavior  
 Chame essa função de membro para determinar como um [CommitTrans](#committrans) operação afeta cursores em objetos de conjunto de registros aberto.  
  
```  
int GetCursorCommitBehavior() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica o efeito de transações em objetos de conjunto de registros aberto. Para obter detalhes, consulte Observações.  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir lista os possíveis valores de retornados para `GetCursorCommitBehavior` e o efeito correspondente no conjunto de registros aberto.  
  
|Valor retornado|Efeito sobre objetos CRecordset|  
|------------------|----------------------------------|  
|SQL_CB_CLOSE|Chamar `CRecordset::Requery` imediatamente após a confirmação de transação.|  
|SQL_CB_DELETE|Chamar `CRecordset::Close` imediatamente após a confirmação de transação.|  
|SQL_CB_PRESERVE|Prosseguir normalmente com `CRecordset` operações.|  
  
 Para obter mais informações sobre esse valor de retorno, consulte a função de API ODBC `SQLGetInfo` no SDK do Windows. Para obter mais informações sobre transações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="getcursorrollbackbehavior"></a>  CDatabase::GetCursorRollbackBehavior  
 Chame essa função de membro para determinar como um [reversão](#rollback) operação afeta cursores em objetos de conjunto de registros aberto.  
  
```  
int GetCursorRollbackBehavior() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor que indica o efeito de transações em objetos de conjunto de registros aberto. Para obter detalhes, consulte Observações.  
  
### <a name="remarks"></a>Comentários  
 A tabela a seguir lista os possíveis valores de retornados para `GetCursorRollbackBehavior` e o efeito correspondente no conjunto de registros aberto.  
  
|Valor retornado|Efeito sobre objetos CRecordset|  
|------------------|----------------------------------|  
|SQL_CB_CLOSE|Chamar `CRecordset::Requery` imediatamente após a reversão de transação.|  
|SQL_CB_DELETE|Chamar `CRecordset::Close` imediatamente após a reversão de transação.|  
|SQL_CB_PRESERVE|Prosseguir normalmente com `CRecordset` operações.|  
  
 Para obter mais informações sobre esse valor de retorno, consulte a função de API ODBC `SQLGetInfo` no SDK do Windows. Para obter mais informações sobre transações, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="getdatabasename"></a>  CDatabase::GetDatabaseName  
 Chame essa função de membro para recuperar o nome do banco de dados conectado no momento (desde que a fonte de dados define um objeto nomeado chamado "banco de dados").  
  
```  
CString GetDatabaseName() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um [CString](../../atl-mfc-shared/reference/cstringt-class.md) que contém o nome de banco de dados se for bem-sucedido; caso contrário, um vazio, `CString`.  
  
### <a name="remarks"></a>Comentários  
 Isso não é o mesmo que o nome da fonte de dados (DSN) especificado na `OpenEx` ou `Open` chamar. O que `GetDatabaseName` retorna depende do ODBC. Em geral, um banco de dados é uma coleção de tabelas. Se esta entidade tem um nome, `GetDatabaseName` retorna-o.  
  
 Por exemplo, convém exibir esse nome em um título. Se ocorrer um erro ao recuperar o nome do ODBC, `GetDatabaseName` retornará um `CString`.  
  
##  <a name="isopen"></a>  CDatabase::IsOpen  
 Chame essa função de membro para determinar se o `CDatabase` objeto está atualmente conectado a uma fonte de dados.  
  
```  
BOOL IsOpen() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o `CDatabase` objeto está conectado no momento; caso contrário, 0.  
  
##  <a name="m_hdbc"></a>  CDatabase::m_hdbc  
 Contém um identificador público para uma conexão de fonte de dados ODBC — um "identificador de conexão".  
  
### <a name="remarks"></a>Comentários  
 Normalmente, você terá que não há necessidade de acessar essa variável de membro diretamente. Em vez disso, o framework aloca o identificador quando você chama `OpenEx` ou `Open`. O framework desaloca a alça quando você chama o **exclua** operador no `CDatabase` objeto. Observe que o `Close` função membro desaloca a alça.  
  
 Em algumas circunstâncias, no entanto, você talvez precise usar o identificador diretamente. Por exemplo, se você precisa chamar funções API ODBC diretamente em vez de por meio da classe `CDatabase`, talvez seja necessário um identificador de conexão para passar como um parâmetro. Veja o exemplo de código abaixo.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDatabase#15](../../mfc/codesnippet/cpp/cdatabase-class_5.cpp)]  
  
##  <a name="onsetoptions"></a>  CDatabase::OnSetOptions  
 O framework chama essa função de membro ao executar diretamente uma instrução SQL com o `ExecuteSQL` função de membro.  
  
```  
virtual void OnSetOptions(HSTMT hstmt);
```  
  
### <a name="parameters"></a>Parâmetros  
 *HSTMT*  
 O identificador de instrução ODBC para o qual estão sendo definidas opções.  
  
### <a name="remarks"></a>Comentários  
 `CRecordset::OnSetOptions` também chama essa função de membro.  
  
 `OnSetOptions` Define o valor de tempo limite de logon. Se tiverem sido chamadas anteriores para o `SetQueryTimeout` e a função de membro, `OnSetOptions` reflete os valores atuais; caso contrário, ele define os valores padrão.  
  
> [!NOTE]
>  Antes de MFC 4.2, `OnSetOptions` também definir o modo de processamento para ambos snychronous ou assíncrona. Começando com o MFC 4.2, todas as operações são síncronas. Para executar uma operação assíncrona, você deve fazer uma chamada direta para a função ODBC API `SQLSetPos`.  
  
 Você não precisará substituir `OnSetOptions` para alterar o valor de tempo limite. Em vez disso, para personalizar o valor de tempo limite de consulta, chame `SetQueryTimeout` antes de criar um conjunto de registros; `OnSetOptions` usarão o novo valor. O conjunto de valores se aplicam a operações subsequentes em todos os conjuntos de registros ou chamadas SQL diretas.  
  
 Substituir `OnSetOptions` se você quiser definir opções adicionais. Sua substituição deve chamar a classe base `OnSetOptions` antes ou depois de chamar a função ODBC API `SQLSetStmtOption`. Execute o método ilustrado na implementação do padrão da estrutura de `OnSetOptions`.  
  
##  <a name="open"></a>  CDatabase:: Open  
 Chame essa função de membro para inicializar um recentemente construído `CDatabase` objeto.  
  
```  
virtual BOOL Open(
    LPCTSTR lpszDSN,  
    BOOL bExclusive = FALSE,  
    BOOL bReadOnly = FALSE,  
    LPCTSTR lpszConnect = _T("ODBC;"),  
    BOOL bUseCursorLib = TRUE);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszDSN*  
 Especifica um nome de fonte de dados — um nome registrado com o ODBC por meio do programa Administrador de ODBC. Se for especificado um valor DSN em *lpszConnect* (na forma "DSN =\<fonte de dados >"), ele não deve ser especificado novamente na *lpszDSN*. Nesse caso, *lpszDSN* deve ser NULL. Caso contrário, é possível passar NULL para apresentar ao usuário uma caixa de diálogo de fonte de dados no qual o usuário pode selecionar uma fonte de dados. Para obter mais informações, consulte comentários.  
  
 *bExclusive*  
 Não tem suporte nesta versão da biblioteca de classes. Atualmente, uma asserção falha se esse parâmetro for TRUE. A fonte de dados sempre é aberta como compartilhadas (não exclusivo).  
  
 *bReadOnly*  
 TRUE se você pretende que a conexão para ser somente leitura e para impedir atualizações à fonte de dados. Todos os conjuntos de registros dependentes herdam esse atributo. O valor padrão é FALSE.  
  
 *lpszConnect*  
 Especifica uma cadeia de caracteres de conexão. A cadeia de caracteres de conexão concatena informações, incluindo, possivelmente, um nome de fonte de dados, uma ID de usuário válida na fonte de dados, uma cadeia de caracteres de autenticação de usuário (senha, se a fonte de dados requer uma) e outras informações. A cadeia de caracteres de conexão inteira deve ser prefixada por cadeia de caracteres "ODBC;" (maiusculas ou minúsculas). "ODBC;" cadeia de caracteres é usada para indicar que a conexão é a uma fonte de dados ODBC; Isso é para compatibilidade com versões posteriores, quando as versões futuras da biblioteca de classes podem dar suporte a fontes de dados não-ODBC.  
  
 *bUseCursorLib*  
 TRUE se você quiser que a DLL de biblioteca de Cursor ODBC a serem carregados. A biblioteca de cursores máscaras alguma funcionalidade do driver ODBC subjacente, efetivamente evitar o uso de dynasets (se o driver oferece suporte a eles). Os cursores de somente terá suportados se a biblioteca de cursor é carregada são instantâneos estáticos e cursores de somente avanço. O valor padrão é TRUE. Se você planeja criar um objeto recordset diretamente do `CRecordset` sem derivar dela, você não deve carregar a biblioteca de cursores.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a conexão é estabelecida com êxito; Caso contrário, 0 se o usuário escolher Cancelar quando apresentada uma caixa de diálogo pedindo para obter mais informações de conexão. Em todos os outros casos, o framework gerará uma exceção.  
  
### <a name="remarks"></a>Comentários  
 O objeto de banco de dados deve ser inicializado antes que você pode usá-lo para construir um objeto de conjunto de registros.  
  
> [!NOTE]
>  Chamar o [OpenEx](#openex) função de membro é a maneira preferencial para se conectar a uma fonte de dados e inicializar o objeto de banco de dados.  
  
 Se os parâmetros em seu `Open` chamada não contêm informações suficientes para fazer a conexão, o driver ODBC abre uma caixa de diálogo para obter as informações necessárias do usuário. Quando você chama `Open`, sua cadeia de conexão *lpszConnect*, são armazenados em particular no `CDatabase` do objeto e está disponível por meio da chamada a [GetConnect](#getconnect) função de membro.  
  
 Se desejar, você pode abrir a caixa de diálogo antes de chamar `Open` para obter informações do usuário, como uma senha, em seguida, adicione essas informações para a cadeia de caracteres de conexão que você passa para `Open`. Ou talvez você queira salvar a cadeia de conexão que você passa para que você possa reutilizá-lo na próxima vez seu aplicativo chamará `Open` em um `CDatabase` objeto.  
  
 Você também pode usar a cadeia de caracteres de conexão para vários níveis de autorização de logon (cada um para outro `CDatabase` objeto) ou para transmitir a outras informações específicas da fonte de dados. Para obter mais informações sobre cadeias de caracteres de conexão, consulte o capítulo 5 no SDK do Windows.  
  
 É possível que uma tentativa de conexão de tempo limite se, por exemplo, o host DBMS não está disponível. Se a tentativa de conexão falhar, `Open` lança um `CDBException`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDatabase#14](../../mfc/codesnippet/cpp/cdatabase-class_6.cpp)]  
  
##  <a name="openex"></a>  CDatabase:: Openex  
 Chame essa função de membro para inicializar um recentemente construído `CDatabase` objeto.  
  
```  
virtual BOOL OpenEx(
    LPCTSTR lpszConnectString,  
    DWORD dwOptions = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lpszConnectString*  
 Especifica uma cadeia de caracteres de conexão do ODBC. Isso inclui o nome da fonte de dados, bem como outras informações opcionais, como uma ID de usuário e senha. Por exemplo, "DSN = SQLServer_Source; UID = SA; PWD = abc123 "é uma cadeia de caracteres de conexão possíveis. Observe que, se você passar NULL para *lpszConnectString*, uma caixa de diálogo de fonte de dados solicitará que o usuário selecione uma fonte de dados.  
  
 *dwOptions*  
 Um bitmask que especifica uma combinação dos valores a seguir. O valor padrão é 0, o que significa que o banco de dados será aberto como compartilhado com acesso de gravação, a DLL de biblioteca de Cursor ODBC não será carregada e a caixa de diálogo de conexão ODBC será exibido somente se não houver informações suficientes para fazer a conexão.  
  
- `CDatabase::openExclusive` Não tem suporte nesta versão da biblioteca de classes. Uma fonte de dados sempre é aberta como compartilhadas (não exclusivo). Atualmente, uma asserção falha se você especificar essa opção.  
  
- `CDatabase::openReadOnly` Abra a fonte de dados como somente leitura.  
  
- `CDatabase::useCursorLib` Carregar a DLL da biblioteca de cursores ODBC. A biblioteca de cursores máscaras alguma funcionalidade do driver ODBC subjacente, efetivamente evitar o uso de dynasets (se o driver oferece suporte a eles). Os cursores de somente terá suportados se a biblioteca de cursor é carregada são instantâneos estáticos e cursores de somente avanço. Se você planeja criar um objeto recordset diretamente do `CRecordset` sem derivar dela, você não deve carregar a biblioteca de cursores.  
  
- `CDatabase::noOdbcDialog` Não exiba a caixa de diálogo de conexão ODBC, independentemente se as informações de conexão suficientes são fornecidas.  
  
- `CDatabase::forceOdbcDialog` Sempre exiba a caixa de diálogo de conexão ODBC.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a conexão é estabelecida com êxito; Caso contrário, 0 se o usuário escolher Cancelar quando apresentada uma caixa de diálogo pedindo para obter mais informações de conexão. Em todos os outros casos, o framework gerará uma exceção.  
  
### <a name="remarks"></a>Comentários  
 O objeto de banco de dados deve ser inicializado antes que você pode usá-lo para construir um objeto de conjunto de registros.  
  
 Se o *lpszConnectString* parâmetro em seu `OpenEx` chamada não contém informações suficientes para que a conexão, o driver ODBC abre uma caixa de diálogo para obter as informações necessárias do usuário, desde que você não tenha definir `CDatabase::noOdbcDialog` ou `CDatabase::forceOdbcDialog` na *dwOptions* parâmetro. Quando você chama `OpenEx`, sua cadeia de conexão *lpszConnectString*, são armazenados em particular no `CDatabase` do objeto e está disponível por meio da chamada a [GetConnect](#getconnect) função de membro.  
  
 Se desejar, você pode abrir a caixa de diálogo antes de chamar `OpenEx` para obter informações do usuário, como uma senha e, em seguida, adicionar essas informações para a cadeia de caracteres de conexão que você passa para `OpenEx`. Ou talvez você queira salvar a cadeia de conexão que você passa para que você possa reutilizá-lo na próxima vez seu aplicativo chamará `OpenEx` em um `CDatabase` objeto.  
  
 Você também pode usar a cadeia de caracteres de conexão para vários níveis de autorização de logon (cada um para outro `CDatabase` objeto) ou para transmitir a outras informações específicas da fonte de dados. Para obter mais informações sobre cadeias de caracteres de conexão, consulte o capítulo 6 na *referência do programador de ODBC*.  
  
 É possível que uma tentativa de conexão de tempo limite se, por exemplo, o host DBMS não está disponível. Se a tentativa de conexão falhar, `OpenEx` lança um `CDBException`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDatabase#11](../../mfc/codesnippet/cpp/cdatabase-class_7.cpp)]  
  
##  <a name="rollback"></a>  CDatabase::Rollback  
 Chame essa função de membro para reverter as alterações feitas durante uma transação.  
  
```  
BOOL Rollback();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a transação foi revertida com êxito; Caso contrário, 0. Se um `Rollback` chamada falhar, a fonte de dados e a transação estados são indefinidos. Se `Rollback` retorna 0, você deve verificar a fonte de dados para determinar seu estado.  
  
### <a name="remarks"></a>Comentários  
 Todos os `CRecordset` `AddNew`, `Edit`, `Delete`, e `Update` chamadas executadas desde a última [BeginTrans](#begintrans) são revertidas para o estado que existia no momento da chamada.  
  
 Após uma chamada para `Rollback`, a transação está acima e você deve chamar `BeginTrans` novamente por outra transação. O registro que foi atual antes de você chamou `BeginTrans` torna-se o registro atual novamente após `Rollback`.  
  
 Depois de uma reversão, o registro que foi atual antes da reversão permanece atual. Para obter detalhes sobre o estado do conjunto de registros e a fonte de dados após uma reversão, consulte o artigo [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
### <a name="example"></a>Exemplo  
  Consulte o artigo [transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md).  
  
##  <a name="setlogintimeout"></a>  CDatabase::SetLoginTimeout  
 Chame essa função de membro — antes de chamar `OpenEx` ou `Open` — para substituir o número padrão de segundos permitido antes de uma tentativa conexão de fonte atinge o tempo limite.  
  
```  
void SetLoginTimeout(DWORD dwSeconds);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwSeconds*  
 O número de segundos para permitir que uma tentativa de conexão antes de expirar.  
  
### <a name="remarks"></a>Comentários  
 Uma tentativa de conexão pode atingir o tempo limite se, por exemplo, o DBMS não estiver disponível. Chame `SetLoginTimeout` depois de construir o não inicializada `CDatabase` do objeto, mas antes de você chamar `OpenEx` ou `Open`.  
  
 O valor padrão para tempos limite de logon é 15 segundos. Nem todas as fontes de dados dão suporte a capacidade de especificar um valor de tempo limite de logon. Se a fonte de dados não oferece suporte a tempo limite, você receberá a saída de rastreamento, mas não uma exceção. Um valor de 0 significa "infinite".  
  
##  <a name="setquerytimeout"></a>  CDatabase::SetQueryTimeout  
 Chame essa função de membro para substituir o número padrão de segundos permitido antes do tempo limite da fonte de dados conectada operações posteriores.  
  
```  
void SetQueryTimeout(DWORD dwSeconds);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwSeconds*  
 O número de segundos para permitir que uma tentativa de consulta antes de expirar.  
  
### <a name="remarks"></a>Comentários  
 Uma operação talvez o tempo limite devido a problemas de acesso de rede, o tempo de processamento de consulta excessiva e assim por diante. Chame `SetQueryTimeout` antes de abrir seu conjunto de registros ou antes de chamar o conjunto de registros `AddNew`, `Update` ou `Delete` funções de membro, se você quiser alterar o valor de tempo limite de consulta. A configuração afeta todos os próximos `Open`, `AddNew`, `Update`, e `Delete` chamadas para quaisquer conjuntos de registros associados a este `CDatabase` objeto. Alterar o valor de tempo limite de consulta para um conjunto de registros após a abertura não altera o valor para o conjunto de registros. Por exemplo, subsequente `Move` operações não usam o novo valor.  
  
 O valor padrão para tempos limite de consulta é 15 segundos. Nem todas as fontes de dados dão suporte a capacidade de definir um valor de tempo limite de consulta. Se você definir um valor de tempo limite de consulta igual a 0, nenhum tempo limite ocorre; a comunicação com a fonte de dados pode parar de responder. Esse comportamento pode ser útil durante o desenvolvimento. Se a fonte de dados não oferece suporte a tempo limite, você receberá a saída de rastreamento, mas não uma exceção.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)
