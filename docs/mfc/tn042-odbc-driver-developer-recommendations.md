---
title: 'TN042: recomendações do desenvolvedor de driver ODBC'
ms.date: 11/04/2016
f1_keywords:
- vc.odbc
helpviewer_keywords:
- ODBC drivers [MFC], writing
- databases [MFC], ODBC
- TN042
ms.assetid: ecc6b5d9-f480-4582-9e22-8309fe561dad
ms.openlocfilehash: 67f7a86a247b60be66dabb0a89f04d39ce76222b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372130"
---
# <a name="tn042-odbc-driver-developer-recommendations"></a>TN042: recomendações do desenvolvedor de driver ODBC

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluída pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizados ou incorretos. Para as últimas informações, recomenda-se que você pesquise o tópico de interesse no índice de documentação on-line.

Esta nota descreve as diretrizes para os escritores de driver da ODBC. Ele descreve requisitos gerais e suposições da funcionalidade ODBC que as classes de banco de dados do MFC fazem e vários detalhes semânticos esperados. A funcionalidade necessária do `CRecordset` driver para suportar os três modos Open **(forwardOnly,** **snapshot** e **dynaset)** são descritas.

## <a name="odbcs-cursor-library"></a>Biblioteca cursor da ODBC

As classes MFC Database apresentam funcionalidade ao usuário que, em muitos casos, supera a funcionalidade fornecida pela maioria dos drivers ODBC nível 1. Felizmente, a Biblioteca cursor do ODBC se colocará em camadas entre as classes de banco de dados e o driver, e fornecerá automaticamente grande parte dessa funcionalidade adicional.

Por exemplo, a maioria dos drivers 1.0 não suporta rolagem para trás. A Biblioteca cursor pode detectar isso e armazenar álinha do driver e `SQLExtendedFetch`apresentá-las conforme solicitado em FETCH_PREV chamadas dentro .

Outro exemplo importante de dependência da biblioteca do cursor são as atualizações posicionadas. A maioria dos drivers 1.0 também não tem atualizações posicionadas, mas a biblioteca do cursor gerará instruções de atualização que identificam uma linha de destino na fonte de dados com base nos valores atuais de dados armazenados em cache ou um valor de carimbo de tempo em cache.

A biblioteca de classes nunca faz uso de vários conjuntos de linhas. Portanto, as `SQLSetPos` poucas instruções são sempre aplicadas à linha 1 do conjunto de linhas.

## <a name="cdatabases"></a>CBancos de dados

Cada `CDatabase` um aloca um único **HDBC**. (Se `CDatabase`a `ExecuteSQL` função 'for usada, um **HSTMT** será alocado temporariamente.) Portanto, se `CDatabase`vários 's forem necessários, vários **HDBC**s por **HENV** devem ser suportados.

As classes de banco de dados requerem a biblioteca do cursor. Isso se reflete `SQLSetConnections` em uma chamada **SQL_ODBC_CURSORS,** **SQL_CUR_USE_ODBC**.

`SQLDriverConnect`, **SQL_DRIVER_COMPLETE** é `CDatabase::Open` usado para estabelecer a conexão com a fonte de dados.

O motorista `SQLGetInfo SQL_ODBC_API_CONFORMANCE`  >= deve `SQLGetInfo SQL_ODBC_SQL_CONFORMANCE`  >= apoiar **SQL_OAC_LEVEL1**, **SQL_OSC_MINIMUM**.

Para que as transações sejam `CDatabase` suportadas para os `SQLGetInfo SQL_CURSOR_COMMIT_BEHAVIOR` registros dependentes e **SQL_CURSOR_ROLLBACK_BEHAVIOR** deve ter **SQL_CR_PRESERVE**. Caso contrário, as tentativas de realizar o controle de transações serão ignoradas.

`SQLGetInfo SQL_DATA_SOURCE_READ_ONLY`deve ser apoiado. Se retornar "Y", nenhuma operação de atualização será realizada na fonte de dados.

Se `CDatabase` o readOnly for aberto, uma tentativa de definir `SQLSetConnectOption SQL_ACCESS_MODE`a fonte de dados lida apenas será feita com **SQL_MODE_READ_ONLY**.

Se os identificadores exigirem a citação, essas informações `SQLGetInfo SQL_IDENTIFIER_QUOTE_CHAR` devem ser devolvidas do motorista com uma chamada.

Para fins de `SQLGetInfo SQL_DBMS_VER` depuração, **e SQL_DBMS_NAME** são recuperados do motorista.

`SQLSetStmtOption SQL_QUERY_TIMEOUT`e **SQL_ASYNC_ENABLE** pode ser `CDatabase`chamado em um **HDBC**'s .

`SQLError`pode ser chamado com qualquer ou todos os argumentos NULO.

É `SQLAllocEnv`claro, `SQLAllocConnect` `SQLDisconnect` e `SQLFreeConnect` deve ser apoiado.

## <a name="executesql"></a>ExecuteSQL

Além de alocar e liberar um **HSTMT**temporário, `ExecuteSQL` chamadas `SQLExecDirect`e `SQLFetch` `SQLNumResultCol` . `SQLMoreResults` `SQLCancel`pode ser chamado no **HSTMT**.

## <a name="getdatabasename"></a>Obternome de banco de dados

`SQLGetInfo SQL_DATABASE_NAME`será chamado.

## <a name="begintrans-committrans-rollback"></a>StartTrans, CommitTrans, Reversão

`SQLSetConnectOption SQL_AUTOCOMMIT`e `SQLTransact SQL_COMMIT`, **SQL_ROLLBACK** e **SQL_AUTOCOMMIT** serão chamados se as solicitações de transação forem feitas.

## <a name="crecordsets"></a>CRecordsets

`SQLAllocStmt`, `SQLPrepare` `SQLExecute` , `Open` (Para e `Requery`), `SQLExecDirect` `SQLFreeStmt` (para operações de atualização), deve ser suportado. `SQLNumResultCols`e `SQLDescribeCol` será chamado sobre os resultados definidos em vários momentos.

`SQLSetParam`é usado extensivamente para vincular dados de parâmetros e **funcionalidade DATA_AT_EXEC.**

`SQLBindCol`é usado extensivamente para registrar os locais de armazenamento de dados da Coluna com o ODBC.

Duas `SQLGetData` chamadas são usadas para recuperar **dados SQL_LONG_VARCHAR** e **SQL_LONG_VARBINARY.** A primeira chamada tenta encontrar o comprimento total `SQLGetData` do valor da coluna ligando com cbMaxValue de 0, mas com um pcbValue válido. Se o pcbValue tiver **SQL_NO_TOTAL,** uma exceção será descartada. Caso contrário, um **HGLOBAL** é `SQLGetData` alocado, e outra chamada feita para recuperar todo o resultado.

## <a name="updating"></a>Atualizando

Se o bloqueio pessimista for solicitado, `SQLGetInfo SQL_LOCK_TYPES` será consultado. Se **SQL_LCK_EXCLUSIVE** não for suportado, uma exceção será lançada.

As tentativas `CRecordset` de atualizar um (**snapshot** ou **dynaset**) farão com que um segundo **HSTMT** seja alocado. Para drivers que não suportam o segundo **HSTMT,** a biblioteca do cursor simulará essa funcionalidade. Infelizmente, isso pode às vezes significar forçar a consulta atual no primeiro **HSTMT** a ser concluída antes de processar a solicitação do segundo **HSTMT.**

`SQLFreeStmt SQL_CLOSE`e **SQL_RESET_PARAMS** SQL_RESET_PARAMS `SQLGetCursorName` e serão chamados durante as operações de atualização.

Se houver **CLongBinarys** na **saídaColunas,** a funcionalidade **DATA_AT_EXEC** do ODBC deve ser suportada. Isso inclui o retorno `SQLExecDirect` `SQLParamData` de `SQLPutData` **SQL_NEED_DATA** e .

`SQLRowCount`é chamado após a execução para verificar `SQLExecDirect`se apenas 1 registro foi atualizado pelo .

## <a name="forwardonly-cursors"></a>ForwardOnly Cursors

Só `SQLFetch` é necessário `Move` para as operações. Observe que os cursores **forwardOnly** não suportam atualizações.

## <a name="snapshot-cursors"></a>Cursors de instantâneos

A funcionalidade `SQLExtendedFetch` do snapshot requer suporte. Como observado acima, a biblioteca do cursor ODBC `SQLExtendedFetch`detectará quando um driver não oferece suporte , e fornecerá o suporte necessário em si.

`SQLGetInfo`, **SQL_SCROLL_OPTIONS** deve apoiar **SQL_SO_STATIC.**

## <a name="dynaset-cursors"></a>Dynaset Cursors

Abaixo está o suporte mínimo necessário para abrir um dynaset:

`SQLGetInfo`**, SQL_ODBC_VER** deve retornar > "01".

`SQLGetInfo`, **SQL_SCROLL_OPTIONS** deve apoiar **SQL_SO_KEYSET_DRIVEN**.

`SQLGetInfo`**, SQL_ROW_UPDATES** deve retornar "Y".

`SQLGetInfo`, **SQL_POSITIONED_UPDATES** deve apoiar **SQL_PS_POSITIONED_DELETE** e **SQL_PS_POSITIONED_UPDATE**.

Além disso, se for solicitado bloqueio `SQLSetPos` pessimista, uma chamada para com irow 1, fRefresh FALSE e fLock **SQL_LCK_EXCLUSIVE** será feita.

## <a name="see-also"></a>Confira também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
