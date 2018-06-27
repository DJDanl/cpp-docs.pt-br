---
title: 'TN042: Recomendações de desenvolvedor de Driver ODBC | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.odbc
dev_langs:
- C++
helpviewer_keywords:
- ODBC drivers [MFC], writing
- databases [MFC], ODBC
- TN042
ms.assetid: ecc6b5d9-f480-4582-9e22-8309fe561dad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ec79ad70f02581d5ea4481c9b2638d522b554eff
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36950569"
---
# <a name="tn042-odbc-driver-developer-recommendations"></a>TN042: recomendações do desenvolvedor de driver ODBC
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve as diretrizes para os autores de driver ODBC. Descreve os requisitos gerais e suposições da funcionalidade do ODBC que tornam as classes de banco de dados MFC e diversos detalhes de semânticos esperados. Necessário a funcionalidade do driver para dar suporte a três `CRecordset` abrir modos (**forwardOnly**, **instantâneo** e **dynaset**) são descritas.  
  
## <a name="odbcs-cursor-library"></a>Biblioteca de cursores do ODBC  
 As classes de banco de dados MFC apresentam a funcionalidade para o usuário que, em muitos casos, ultrapassa a funcionalidade proporcionada pela maioria dos drivers ODBC de nível 1. Felizmente, biblioteca de cursores da ODBC camada-se entre as classes de banco de dados e o driver e fornecerá automaticamente muito esta funcionalidade adicional.  
  
 Por exemplo, a maioria dos drivers 1.0 não dão suporte para trás. A biblioteca de cursores pode detectar isso e linhas do driver de cache e apresentá-los, conforme solicitado em chamadas FETCH_PREV em `SQLExtendedFetch`.  
  
 Outro exemplo importante de dependência de biblioteca de cursor é atualizações posicionadas. A maioria dos drivers 1.0 também não têm atualizações posicionadas, mas a biblioteca de cursores irá gerar instruções de atualização que identificam uma linha de destino na fonte de dados com base em seus valores de dados armazenados em cache atual, ou um valor de carimbo de hora armazenado em cache.  
  
 A biblioteca de classes nunca faz uso de vários conjuntos de linhas. Portanto, os poucos `SQLSetPos` instruções são sempre aplicadas para a linha 1 do conjunto de linhas.  
  
## <a name="cdatabases"></a>CDatabases  
 Cada `CDatabase` aloca um único **HDBC**. (Se `CDatabase`do `ExecuteSQL` função é usada, um **HSTMT** temporariamente alocada.) Portanto, se várias `CDatabase`do são necessários, vários **HDBC**s por **HENV** devem ter suporte.  
  
 As classes de banco de dados exigem a biblioteca de cursores. Isso é refletido em um `SQLSetConnections` chamar **SQL_ODBC_CURSORS**, **SQL_CUR_USE_ODBC**.  
  
 `SQLDriverConnect`, **SQL_DRIVER_COMPLETE** é usado pelo `CDatabase::Open` para estabelecer a conexão à fonte de dados.  
  
 O driver deve oferecer suporte `SQLGetInfo SQL_ODBC_API_CONFORMANCE`  >=  **SQL_OAC_LEVEL1**, `SQLGetInfo SQL_ODBC_SQL_CONFORMANCE`  >=  **SQL_OSC_MINIMUM**.  
  
 Para que as transações com suporte para o `CDatabase` e seus conjuntos de registros dependentes, `SQLGetInfo SQL_CURSOR_COMMIT_BEHAVIOR` e **SQL_CURSOR_ROLLBACK_BEHAVIOR** deve ter **SQL_CR_PRESERVE**. Caso contrário, será ignorada tenta executar o controle de transação.  
  
 `SQLGetInfo SQL_DATA_SOURCE_READ_ONLY` deve ser suportado. Se ele retorna "Y", nenhuma operação de atualização será executada na fonte de dados.  
  
 Se o `CDatabase` está aberto somente leitura, uma tentativa de definir a fonte de dados de leitura somente será feita com `SQLSetConnectOption SQL_ACCESS_MODE`, **SQL_MODE_READ_ONLY**.  
  
 Se precisam de identificadores de delimitação, essas informações devem ser retornadas do driver com um `SQLGetInfo SQL_IDENTIFIER_QUOTE_CHAR` chamar.  
  
 Para depuração, `SQLGetInfo SQL_DBMS_VER` e **SQL_DBMS_NAME** são recuperadas do driver.  
  
 `SQLSetStmtOption SQL_QUERY_TIMEOUT` e **SQL_ASYNC_ENABLE** pode ser chamado em um `CDatabase`do **HDBC**.  
  
 `SQLError` pode ser chamado com um ou todos os argumentos NULL.  
  
 Obviamente, `SQLAllocEnv`, `SQLAllocConnect`, `SQLDisconnect` e `SQLFreeConnect` devem ter suporte.  
  
## <a name="executesql"></a>ExecuteSQL  
 Além de alocar e liberar um temporário **HSTMT**, `ExecuteSQL` chamadas `SQLExecDirect`, `SQLFetch`, `SQLNumResultCol` e `SQLMoreResults`. `SQLCancel` pode ser chamado no **HSTMT**.  
  
## <a name="getdatabasename"></a>GetDatabaseName  
 `SQLGetInfo SQL_DATABASE_NAME` será chamado.  
  
## <a name="begintrans-committrans-rollback"></a>BeginTrans, CommitTrans e Rollback  
 `SQLSetConnectOption SQL_AUTOCOMMIT` e `SQLTransact SQL_COMMIT`, **SQL_ROLLBACK** e **SQL_AUTOCOMMIT** será chamado se as solicitações de transação são feitas.  
  
## <a name="crecordsets"></a>CRecordsets  
 `SQLAllocStmt`, `SQLPrepare`, `SQLExecute` (Para `Open` e `Requery`), `SQLExecDirect` (para operações de atualização), `SQLFreeStmt` devem ter suporte. `SQLNumResultCols` e `SQLDescribeCol` será chamado nos resultados definido várias vezes.  
  
 `SQLSetParam` é muito usado para associação de dados de parâmetro e **DATA_AT_EXEC** funcionalidade.  
  
 `SQLBindCol` usada amplamente para registrar saída locais de armazenamento de dados de coluna com ODBC.  
  
 Dois `SQLGetData` chamadas são usadas para recuperar **SQL_LONG_VARCHAR** e **SQL_LONG_VARBINARY** dados. A primeira chamada tenta localizar o comprimento total do valor da coluna chamando `SQLGetData` com cbMaxValue 0, mas com um pcbValue válido. Se mantiver pcbValue **SQL_NO_TOTAL**, uma exceção será lançada. Caso contrário, um **HGLOBAL** é alocada e outro `SQLGetData` chamada feita a recuperar todo o resultado.  
  
## <a name="updating"></a>Atualizando  
 Se for solicitada a pessimista `SQLGetInfo SQL_LOCK_TYPES` será consultado. Se **SQL_LCK_EXCLUSIVE** não é tem suporte, uma exceção será lançada.  
  
 Tenta atualizar uma `CRecordset` (**instantâneo** ou **dynaset**) fará com que um segundo **HSTMT** a ser alocada. Drivers que não suportam segundo **HSTMT**, a biblioteca de cursores simulará essa funcionalidade. Infelizmente, isso pode significar, às vezes, forçando a consulta atual na primeira **HSTMT** até a conclusão antes de processar a segunda **HSTMT**da solicitação.  
  
 `SQLFreeStmt SQL_CLOSE` e **SQL_RESET_PARAMS** e `SQLGetCursorName` será chamada durante operações de atualização.  
  
 Se não houver **CLongBinarys** no **outputColumns**, do ODBC **DATA_AT_EXEC** funcionalidade deve ter suporte. Isso inclui retornando **SQL_NEED_DATA** de `SQLExecDirect`, `SQLParamData` e `SQLPutData`.  
  
 `SQLRowCount` é chamado após a execução para verificar se o registro somente 1 foi atualizado pelo `SQLExecDirect`.  
  
## <a name="forwardonly-cursors"></a>Cursores de ForwardOnly  
 Somente `SQLFetch` é necessário para o `Move` operações. Observe que **forwardOnly** cursores dão suporte a atualizações.  
  
## <a name="snapshot-cursors"></a>Cursores de instantâneo  
 Funcionalidade de instantâneo requer `SQLExtendedFetch` suporte. Conforme observado acima, a biblioteca de cursores ODBC detecta quando um driver não dá suporte a `SQLExtendedFetch`e fornecem o suporte necessário em si.  
  
 `SQLGetInfo`, **SQL_SCROLL_OPTIONS** deve oferecer suporte a **SQL_SO_STATIC**.  
  
## <a name="dynaset-cursors"></a>Cursores de dynaset  
 Abaixo está o suporte mínimo necessário para abrir um dynaset:  
  
 `SQLGetInfo`, **SQL_ODBC_VER** deve retornar > "01".  
  
 `SQLGetInfo`, **SQL_SCROLL_OPTIONS** deve oferecer suporte a **SQL_SO_KEYSET_DRIVEN**.  
  
 `SQLGetInfo`, **SQL_ROW_UPDATES** deve retornar "Y".  
  
 `SQLGetInfo`, **SQL_POSITIONED_UPDATES** deve oferecer suporte a **SQL_PS_POSITIONED_DELETE** e **SQL_PS_POSITIONED_UPDATE**.  
  
 Além disso, se o bloqueio pessimista for solicitado, uma chamada para `SQLSetPos` com irow 1, fRefresh FALSE e fLock **SQL_LCK_EXCLUSIVE** será feita.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

