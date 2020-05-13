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
ms.openlocfilehash: 1ab7daeb3af55c92985c951c632b1d4050681474
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321901"
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
|[CDBException::m_strError](#m_strerror)|Contém uma seqüência que descreve o erro em termos alfanuméricos.|
|[CDBExceção::m_strStateNativeOrigin](#m_strstatenativeorigin)|Contém uma seqüência descrevendo o erro em termos dos códigos de erro retornados pela ODBC.|

## <a name="remarks"></a>Comentários

A classe inclui dois membros de dados públicos que você pode usar para determinar a causa da exceção ou para exibir uma mensagem de texto descrevendo a exceção. `CDBException`objetos são construídos e jogados pelas funções dos membros das classes de banco de dados.

> [!NOTE]
> Esta classe é uma das classes de Conectividade de Banco de Dados Aberto (ODBC) da MFC. Se você estiver usando as classes DAO (Data Access Objects, objetos de acesso de dados) mais novos, use [cDaoException.](../../mfc/reference/cdaoexception-class.md) Todos os nomes de classe DAO têm "CDao" como prefixo. Para obter mais informações, consulte a visão geral do [artigo: Programação de banco de dados](../../data/data-access-programming-mfc-atl.md).

Exceções são casos de execução anormal envolvendo condições fora do controle do programa, como fonte de dados ou erros de I/O da rede. Erros que você pode esperar ver no curso normal de execução do seu programa geralmente não são considerados exceções.

Você pode acessar esses objetos no escopo de uma expressão **CATCH.** Você também `CDBException` pode jogar objetos `AfxThrowDBException` do seu próprio código com a função global.

Para obter mais informações sobre o `CDBException` tratamento de exceções em geral ou sobre objetos, consulte os artigos [Manipulação de Exceções (MFC)](../../mfc/exception-handling-in-mfc.md) e [Exceções: Exceções de banco de dados](../../mfc/exceptions-database-exceptions.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cexception](../../mfc/reference/cexception-class.md)

`CDBException`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="cdbexceptionm_nretcode"></a><a name="m_nretcode"></a>CDBException::m_nRetCode

Contém um código de erro ODBC do tipo RETCODE retornado por uma função API (Application Programming Interface, interface de programação de aplicativos ODBC).

### <a name="remarks"></a>Comentários

Esse tipo inclui códigos prefixados por SQL definidos pela ODBC e códigos prefixados por AFX_SQL definidos pelas classes de banco de dados. Para `CDBException`a, este membro conterá um dos seguintes valores:

- AFX_SQL_ERROR_API_CONFORMANCE O driver `CDatabase::OpenEx` `CDatabase::Open` para uma ou chamada não está de acordo com a conformidade com a API API exigida nível 1 (SQL_OAC_LEVEL1).

- AFX_SQL_ERROR_CONNECT_FAIL Conexão com a fonte de dados falhou. Você passou`CDatabase` um ponteiro NULL para o construtor do conjunto de `GetDefaultConnect` registros e a tentativa subsequente de criar uma conexão com base na falha.

- AFX_SQL_ERROR_DATA_TRUNCATED Você solicitou mais dados do que forneceu armazenamento. Para obter informações sobre o `CString` aumento `CByteArray` do armazenamento `nMaxLength` de dados fornecido suster ou tipos de dados, consulte o argumento [para RFX_Text](record-field-exchange-functions.md#rfx_text) e [RFX_Binary](record-field-exchange-functions.md#rfx_binary) em "Macros e Globals".

- AFX_SQL_ERROR_DYNASET_NOT_SUPPORTED Uma `CRecordset::Open` chamada para solicitar um dynaset falhou. Os dynasets não são suportados pelo motorista.

- AFX_SQL_ERROR_EMPTY_COLUMN_LIST Você tentou abrir uma tabela (ou o que você deu não pôde ser identificado como uma chamada de procedimento ou declaração **SELECT),** mas não há colunas identificadas nas chamadas de função RFX (Record Field Exchange) em sua `DoFieldExchange` substituição.

- AFX_SQL_ERROR_FIELD_SCHEMA_MISMATCH O tipo de função `DoFieldExchange` RFX na sua substituição não é compatível com o tipo de dados da coluna no conjunto de registros.

- AFX_SQL_ERROR_ILLEGAL_MODE Você `CRecordset::Update` ligou sem ligar `CRecordset::AddNew` antes ou `CRecordset::Edit`.

- AFX_SQL_ERROR_LOCK_MODE_NOT_SUPPORTED Sua solicitação de bloqueio de registros para atualização não pôde ser cumprida porque o driver ODBC não suporta bloqueio.

- AFX_SQL_ERROR_MULTIPLE_ROWS_AFFECTED Você `CRecordset::Update` `Delete` ligou ou para uma tabela sem chave única e alterou vários registros.

- AFX_SQL_ERROR_NO_CURRENT_RECORD Você tentou editar ou excluir um registro excluído anteriormente. Você deve rolar para um novo registro atual após uma exclusão.

- AFX_SQL_ERROR_NO_POSITIONED_UPDATES Sua solicitação de um dynaset não pôde ser atendida porque seu driver ODBC não suporta atualizações posicionadas.

- AFX_SQL_ERROR_NO_ROWS_AFFECTED você `CRecordset::Update` `Delete`ligou ou, mas quando a operação começou o registro não pôde mais ser encontrado.

- AFX_SQL_ERROR_ODBC_LOAD_FAILED Uma tentativa de carregar o ODBC. DLL falhou; O Windows não conseguiu encontrar ou não conseguiu carregar este DLL. Este erro é fatal.

- AFX_SQL_ERROR_ODBC_V2_REQUIRED Sua solicitação de um dynaset não pôde ser atendida porque um driver ODBC compatível com nível 2 é necessário.

- AFX_SQL_ERROR_RECORDSET_FORWARD_ONLY Uma tentativa de rolar não teve sucesso porque a fonte de dados não suporta rolagem para trás.

- AFX_SQL_ERROR_SNAPSHOT_NOT_SUPPORTED Uma `CRecordset::Open` chamada para solicitar um instantâneo falhou. Os instantâneos não são suportados pelo motorista. (Isso só deve ocorrer quando a biblioteca de cursor ODBC ODBC ODBCCURS. DLL não está presente.)

- AFX_SQL_ERROR_SQL_CONFORMANCE O driver `CDatabase::OpenEx` `CDatabase::Open` de uma ou chamada não está de acordo com o nível de conformidade ODBC SQL necessário de "Mínimo" (SQL_OSC_MINIMUM).

- AFX_SQL_ERROR_SQL_NO_TOTAL o driver ODBC não pôde especificar o tamanho total de um `CLongBinary` valor de dados. A operação provavelmente falhou porque um bloco de memória global não pôde ser pré-alocado.

- AFX_SQL_ERROR_RECORDSET_READONLY Você tentou atualizar um conjunto de registros somente leitura, ou a fonte de dados é somente leitura. Nenhuma operação de atualização pode ser `CDatabase` realizada com o conjunto de registros ou com o objeto com o que está associado.

- SQL_ERROR função falhou. A mensagem de erro retornada `SQLError` pela função `m_strError` ODBC é armazenada no membro de dados.

- SQL_INVALID_HANDLE função falhou devido a uma alça de ambiente inválida, cabo de conexão ou alça de declaração. Isso indica um erro de programação. Não há informações adicionais disponíveis `SQLError`na função ODBC .

Os códigos prefixados por SQL são definidos pela ODBC. Os códigos prefixados aFX são definidos no AFXDB. H, encontrado em MFC\INCLUDE.

## <a name="cdbexceptionm_strerror"></a><a name="m_strerror"></a>CDBException::m_strError

Contém uma seqüência descrevendo o erro que causou a exceção.

### <a name="remarks"></a>Comentários

A seqüência descreve o erro em termos alfanuméricos. Para obter informações mais detalhadas e um exemplo, consulte `m_strStateNativeOrigin`.

## <a name="cdbexceptionm_strstatenativeorigin"></a><a name="m_strstatenativeorigin"></a>CDBExceção::m_strStateNativeOrigin

Contém uma seqüência descrevendo o erro que causou a exceção.

### <a name="remarks"></a>Comentários

A seqüência é do formulário "Estado:%s,Nativo:%ld,Origin:%s", onde os códigos de formato, em ordem, são substituídos por valores que descrevem:

- O SQLSTATE, uma seqüência de terminação nula contendo um código de erro de cinco caracteres `SQLError`retornado no parâmetro *szSqlState* da função ODBC . Os valores SQLSTATE estão listados no apêndice A, [Códigos de Erro ODBC,](/sql/odbc/reference/appendixes/appendix-a-odbc-error-codes)na *referência do programador ODBC*. Exemplo: "S0022".

- O código de erro nativo, específico da fonte de dados, `SQLError` retornou no parâmetro *pfNativeError* da função. Exemplo: 207.

- O texto da mensagem de erro retornou no `SQLError` parâmetro *szErrorMsg* da função. Esta mensagem consiste em vários nomes entrelaçados. Como um erro é passado de sua fonte para o usuário, cada componente ODBC (fonte de dados, driver, Driver Manager) anexa seu próprio nome. Essas informações ajudam a identificar a origem do erro. Exemplo: [Microsoft][ODBC SQL Server Driver][SQL Server]

A estrutura interpreta a seqüência de `m_strStateNativeOrigin`erros e coloca seus componentes em; se `m_strStateNativeOrigin` contiver informações para mais de um erro, os erros serão separados por novas linhas. A estrutura coloca o texto de `m_strError`erro alfanumérico em .

Para obter informações adicionais sobre os códigos usados para compor essa string, consulte a função [SQLError](/sql/odbc/reference/syntax/sqlerror-function) na *referência do programador ODBC*.

### <a name="example"></a>Exemplo

Da ODBC:\["Estado:S0022,Nativo:207,Origem:\[Microsoft] ODBC SQL Server Driver]\[SQL Server] Nome inválido da coluna 'ColName'"

In `m_strStateNativeOrigin`: "State:S0022,Native:207,Origin:\[Microsoft]\[ODBC SQL Server Driver]\[SQL Server]"

Em `m_strError`: "Nome da coluna inválida 'ColName'"

## <a name="see-also"></a>Confira também

[Classe CException](../../mfc/reference/cexception-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDatabase](../../mfc/reference/cdatabase-class.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)<br/>
[Classe CfieldExchange](../../mfc/reference/cfieldexchange-class.md)<br/>
[CRecordset::Atualização](../../mfc/reference/crecordset-class.md#update)<br/>
[CRecordset::Delete](../../mfc/reference/crecordset-class.md#delete)<br/>
[Classe CException](../../mfc/reference/cexception-class.md)
