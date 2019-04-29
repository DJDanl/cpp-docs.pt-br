---
title: Classe CDBException
ms.date: 11/04/2016
f1_keywords:
- CDBException
- AFXDB/CDBException
- AFXDB/CDBException::m_nRetCode
- AFXDB/CDBException::m_strError
- AFXDB/CDBException::m_strStateNativeOrigin
helpviewer_keywords:
- CDBException [MFC], m_nRetCode
- CDBException [MFC], m_strError
- CDBException [MFC], m_strStateNativeOrigin
ms.assetid: eb9e1119-89f5-49a7-b9d4-b91cee1ccc82
ms.openlocfilehash: 755b89635eedd7808f900dc63cd3039845db1dd3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62253407"
---
# <a name="cdbexception-class"></a>Classe CDBException

Representa uma condição de exceção decorrente das classes de banco de dados.

## <a name="syntax"></a>Sintaxe

```
class CDBException : public CException
```

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDBException::m_nRetCode](#m_nretcode)|Contém um código de retorno de conectividade de banco de dados aberto (ODBC), do tipo RETCODE.|
|[CDBException::m_strError](#m_strerror)|Contém uma cadeia de caracteres que descreve o erro em termos de alfanuméricos.|
|[CDBException::m_strStateNativeOrigin](#m_strstatenativeorigin)|Contém uma cadeia de caracteres que descreve o erro em termos dos códigos de erro retornado pelo ODBC.|

## <a name="remarks"></a>Comentários

A classe inclui dois membros de dados públicos, que você pode usar para determinar a causa da exceção ou para exibir uma mensagem de texto que descreve a exceção. `CDBException` objetos são construídos e gerados pelas funções de membro das classes de banco de dados.

> [!NOTE]
>  Essa classe é uma das classes de conectividade de banco de dados aberto (ODBC) do MFC. Se estiver usando as classes de objetos de acesso a dados (DAO) mais recentes em vez disso, use [CDaoException](../../mfc/reference/cdaoexception-class.md) em vez disso. Todos os nomes de classe do DAO têm "CDao" como um prefixo. Para obter mais informações, consulte o artigo [visão geral: Programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

As exceções são casos de execução anormal que envolvem condições fora do controle do programa, como a fonte de dados ou erros de e/s de rede. Erros que você pode esperar ver no curso normal de seu programa em execução geralmente não são considerados exceções.

Você pode acessar esses objetos dentro do escopo de um **CATCH** expressão. Você também pode lançar `CDBException` objetos do seu próprio código com o `AfxThrowDBException` função global.

Para obter mais informações sobre o tratamento de exceção no geral, ou cerca `CDBException` objetos, consulte os artigos [tratamento de exceção (MFC)](../../mfc/exception-handling-in-mfc.md) e [exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CException](../../mfc/reference/cexception-class.md)

`CDBException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb. h

##  <a name="m_nretcode"></a>  CDBException::m_nRetCode

Contém um código de erro ODBC do tipo RETCODE retornado por uma função de programação de aplicativo de ODBC API (interface).

### <a name="remarks"></a>Comentários

Esse tipo inclui códigos prefixado pelo SQL definidos pelo ODBC e o prefixo AFX_SQL códigos definidos pelas classes de banco de dados. Para um `CDBException`, esse membro conterá um dos seguintes valores:

- AFX_SQL_ERROR_API_CONFORMANCE o driver para um `CDatabase::OpenEx` ou `CDatabase::Open` chamada não corresponde ao nível necessário de conformidade com a API ODBC 1 (SQL_OAC_LEVEL1).

- Falha na Conexão AFX_SQL_ERROR_CONNECT_FAIL à fonte de dados. Você passou um valor nulo`CDatabase` ponteiro para o construtor de conjunto de registros e a tentativa subsequente para criar uma conexão com base em `GetDefaultConnect` falhou.

- Mais dados do que você forneceu o armazenamento para AFX_SQL_ERROR_DATA_TRUNCATED você será solicitado. Para obter informações sobre como aumentar o armazenamento de dados fornecidos para `CString` ou `CByteArray` tipos de dados, consulte o `nMaxLength` argumento [RFX_Text](record-field-exchange-functions.md#rfx_text) e [RFX_Binary](record-field-exchange-functions.md#rfx_binary) sob "Macros e Globals".

- Chamada AFX_SQL_ERROR_DYNASET_NOT_SUPPORTED um para `CRecordset::Open` solicitar um dynaset falhou. Não há suporte para dynasets pelo driver.

- AFX_SQL_ERROR_EMPTY_COLUMN_LIST você tentou abrir uma tabela (ou o que você forneceu não pôde ser identificado como uma chamada de procedimento ou **selecionar** instrução), mas não existem colunas identificadas no campo de registro exchange (RFX) chamadas de função em seu `DoFieldExchange` substituir.

- AFX_SQL_ERROR_FIELD_SCHEMA_MISMATCH o tipo de um RFX funcionar em seu `DoFieldExchange` substituição não é compatível com o tipo de dados de coluna no conjunto de registros.

- Você AFX_SQL_ERROR_ILLEGAL_MODE chamou `CRecordset::Update` sem chamar anteriormente `CRecordset::AddNew` ou `CRecordset::Edit`.

- AFX_SQL_ERROR_LOCK_MODE_NOT_SUPPORTED sua solicitação para registros de bloqueio de atualização não pôde ser atendida porque o driver ODBC não oferece suporte a bloqueio.

- Você AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED chamou `CRecordset::Update` ou `Delete` para uma tabela sem chave exclusiva e vários registros alterados.

- AFX_SQL_ERROR_NO_CURRENT_RECORD você tentou editar ou excluir um registro excluído anteriormente. Você deve rolar para um novo registro atual após uma exclusão.

- AFX_SQL_ERROR_NO_POSITIONED_UPDATES sua solicitação de dynaset não pôde ser atendida porque o driver ODBC não oferece suporte a atualizações posicionadas.

- Você AFX_SQL_ERROR_NO_ROWS_AFFECTED chamou `CRecordset::Update` ou `Delete`, mas no início da operação não foi possível encontrar o registro.

- AFX_SQL_ERROR_ODBC_LOAD_FAILED uma tentativa de carregar o ODBC. Falha na DLL; Windows não foi possível encontrar ou não foi possível carregar essa DLL. Esse erro é fatal.

- AFX_SQL_ERROR_ODBC_V2_REQUIRED que sua solicitação de dynaset não pôde ser atendida porque um driver de ODBC nível 2 compatível é necessário.

- AFX_SQL_ERROR_RECORDSET_FORWARD_ONLY uma tentativa de rolar não foi bem-sucedida porque a fonte de dados não oferece suporte para trás.

- Chamada AFX_SQL_ERROR_SNAPSHOT_NOT_SUPPORTED um para `CRecordset::Open` solicitar um instantâneo falhou. Instantâneos não são suportados pelo driver. (Isso só deve ocorrer quando a biblioteca de cursores ODBC ODBCCURS. DLL não está presente.)

- AFX_SQL_ERROR_SQL_CONFORMANCE o driver para um `CDatabase::OpenEx` ou `CDatabase::Open` chamada não estiver de acordo com o nível de compatibilidade do ODBC SQL necessário de "Mínimo" (SQL_OSC_MINIMUM).

- Driver ODBC AFX_SQL_ERROR_SQL_NO_TOTAL não foi possível especificar o tamanho total de um `CLongBinary` valor de dados. Provavelmente, a operação falhou porque um bloco de memória global não pode ser pré-alocado.

- AFX_SQL_ERROR_RECORDSET_READONLY você tentou atualizar um conjunto de registros somente leitura ou a fonte de dados é somente leitura. Nenhuma operação de atualização pode ser executadas com o conjunto de registros ou o `CDatabase` objeto está associado.

- Falha na função de SQL_ERROR. A mensagem de erro retornada pela função ODBC `SQLError` é armazenado no `m_strError` membro de dados.

- Função SQL_INVALID_HANDLE falhou devido a um identificador de ambiente inválida, o identificador de conexão ou o identificador de instrução. Isso indica um erro de programação. Nenhuma informação adicional está disponível da função ODBC `SQLError`.

Os códigos prefixado pelo SQL são definidos pelo ODBC. Os códigos prefixado por AFX são definidos em AFXDB. H, encontrado no MFC\INCLUDE.

##  <a name="m_strerror"></a>  CDBException::m_strError

Contém uma cadeia de caracteres que descreve o erro que causou a exceção.

### <a name="remarks"></a>Comentários

A cadeia de caracteres descreve o erro em termos de alfanuméricos. Para obter mais informações e um exemplo, consulte `m_strStateNativeOrigin`.

##  <a name="m_strstatenativeorigin"></a>  CDBException::m_strStateNativeOrigin

Contém uma cadeia de caracteres que descreve o erro que causou a exceção.

### <a name="remarks"></a>Comentários

A cadeia de caracteres é do formulário "estado: % s, nativo: % ld, origem: % s", em que os códigos de formatação, em ordem, são substituídos pelos valores que descrevem:

- O SQLSTATE retornado de uma cadeia de caracteres terminada em nulo que contém um código de erro de cinco caracteres na *szSqlState* parâmetro da função ODBC `SQLError`. Valores SQLSTATE são listados no Apêndice A, [códigos de erro ODBC](/previous-versions/windows/desktop/ms714687(v=vs.85)), no *referência do programador de ODBC*. Exemplo: "S0022".

- O código de erro nativo específico para a fonte de dados retornado na *pfNativeError* parâmetro do `SQLError` função. Exemplo: 207.

- O texto da mensagem de erro retornado na *szErrorMsg* parâmetro do `SQLError` função. Essa mensagem consiste em diversos nomes entre colchetes. Como um erro é transmitido de sua origem para o usuário, cada componente do ODBC (fonte de dados, driver, o Gerenciador de Driver) acrescenta seu próprio nome. Essas informações ajudam a identificar a origem do erro. Exemplo: [Microsoft] [Driver do ODBC SQL Server] [SQL Server]

O framework interpreta a cadeia de caracteres de erro e coloca seus componentes em `m_strStateNativeOrigin`; se `m_strStateNativeOrigin` contém informações para mais de um erro, os erros são separados por novas linhas. O framework colocará o texto de erro alfanuméricos em `m_strError`.

Para obter informações adicionais sobre os códigos usados para fazer essa cadeia de caracteres, consulte a [SQLError](/previous-versions/windows/desktop/ms716312(v=vs.85)) funcionar a *referência do programador de ODBC*.

### <a name="example"></a>Exemplo

  Do ODBC: "Estado: S0022, Native: 207, origem:\[Microsoft]\[ODBC Driver do SQL Server]\[do SQL Server] o nome de coluna inválido 'ColName'"

No `m_strStateNativeOrigin`: "Estado: S0022, Native: 207, origem:\[Microsoft]\[Driver ODBC SQL Server]\[do SQL Server]"

No `m_strError`: "Nome de coluna inválido 'ColName'"

## <a name="see-also"></a>Consulte também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CFieldExchange](../../mfc/reference/cfieldexchange-class.md)<br/>
[CRecordset::Update](../../mfc/reference/crecordset-class.md#update)<br/>
[CRecordset::Delete](../../mfc/reference/crecordset-class.md#delete)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)
