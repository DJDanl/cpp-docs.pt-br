---
title: "TN042: recomenda&#231;&#245;es do desenvolvedor de driver ODBC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.odbc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "bancos de dados [C++], ODBC"
  - "Drivers ODBC [C++], gravando"
  - "TN042"
ms.assetid: ecc6b5d9-f480-4582-9e22-8309fe561dad
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN042: recomenda&#231;&#245;es do desenvolvedor de driver ODBC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve diretrizes para gravadores de driver ODBC.  Descreve requisitos gerais e suposições da funcionalidade do ODBC que as classes da base de dados de MFC ocorrer, e vários detalhes semânticos esperados.  A funcionalidade necessária do driver para dar suporte a três modos abertos de `CRecordset` \(**forwardOnly**, **snapshot** e **dynaset**\) é descrita.  
  
## A biblioteca de cursores ODBC  
 O base de dados de MFC classifica a funcionalidade atual ao usuário que ultrapassa em muitos casos a funcionalidade fornecida pela maioria dos drivers ODBC de nível 1.  Felizmente, a biblioteca de cursores ODBC mergulhar\-se\-á entre as classes da base de dados e o driver, e fornecer\-se\-&z automaticamente grande parte dessa funcionalidade adicional.  
  
 Por exemplo, a maioria 1,0 motoristas não dão suporte à rolagem para trás.  A biblioteca de cursores pode detectar essa, e armazenará em cachê linhas do driver e apresentá\-las\-á como solicitado em chamadas de FETCH\_PREV em **SQLExtendedFetch**.  
  
 Outro exemplo importante de dependência da biblioteca de cursores é atualizações posicionadas.  A maioria 1,0 drivers também não posicionaram atualizações, mas a biblioteca de cursores gerará as instruções de atualização que identificam uma linha de destino na fonte de dados com base em seus valores de dados armazenados em cachê atuais, ou um valor armazenado em cachê de carimbo de data\/hora.  
  
 A biblioteca de classes nunca utiliza vários conjuntos de linhas.  Em virtude disso, algumas instruções de **SQLSetPos** são aplicadas sempre 1 para enfileirar do conjunto de linhas.  
  
## CDatabases  
 Cada `CDatabase` atribui único **HDBC**. \(Se a função de `CDatabase``ExecuteSQL` é usada, **HSTMT** é atribuído temporariamente.\) Portanto, se vários `CDatabase`s forem necessários, vários **HDBC**s por **HENV** devem ter suporte.  
  
 As classes da base de dados requerem a biblioteca de cursores.  Isso é refletido em uma chamada **SQL\_ODBC\_CURSORS**de **SQLSetConnections** , **SQL\_CUR\_USE\_ODBC**.  
  
 **SQLDriverConnect**, **SQL\_DRIVER\_COMPLETE** é usado por `CDatabase::Open` para estabelecer a conexão com a fonte de dados.  
  
 O driver deve oferecer suporte **SQLGetInfo SQL\_ODBC\_API\_CONFORMANCE** \>\= **SQL\_OAC\_LEVEL1**, **SQLGetInfo SQL\_ODBC\_SQL\_CONFORMANCE** \>\= **SQL\_OSC\_MINIMUM**.  
  
 Para que as transações sejam suporte para `CDatabase` e os conjuntos de registros dependentes, **SQLGetInfo SQL\_CURSOR\_COMMIT\_BEHAVIOR** e **SQL\_CURSOR\_ROLLBACK\_BEHAVIOR** devem ter **SQL\_CR\_PRESERVE**.  Caso contrário, o tenta executar o controle de transação serão ignoradas.  
  
 **SQLGetInfo SQL\_DATA\_SOURCE\_READ\_ONLY** deve ser suporte.  Se retornar “Y”, nenhuma operação de atualização é executada na fonte de dados.  
  
 Se `CDatabase` é readonly aberto, uma tentativa de definir a fonte de dados somente leitura será feita com **SQLSetConnectOption SQL\_ACCESS\_MODE**, **SQL\_MODE\_READ\_ONLY**.  
  
 Se os identificadores exigem a citação, essas informações devem ser retornadas do driver com uma chamada de **SQLGetInfoSQL\_IDENTIFIER\_QUOTE\_CHAR** .  
  
 Para fins de depuração, **SQLGetInfo SQL\_DBMS\_VER** e **SQL\_DBMS\_NAME** são recuperados de driver.  
  
 **SQLSetStmtOption SQL\_QUERY\_TIMEOUT** e **SQL\_ASYNC\_ENABLE** podem ser chamados `CDatabase`**HDBC**.  
  
 **SQLError** pode ser chamado com alguns ou todos os argumentos NULL.  
  
 Naturalmente, **SQLAllocEnv**, **SQLAllocConnect**, **SQLDisconnect** e **SQLFreeConnect** serão suportados.  
  
## ExecuteSQL  
 Além da alocação e a liberação de **HSTMT**temporário, `ExecuteSQL` chama **SQLExecDirect**, **SQLFetch**, **SQLNumResultCol** e `SQLMoreResults`.  **SQLCancel** pode ser chamado **HSTMT**.  
  
## GetDatabaseName  
 **SQLGetInfo SQL\_DATABASE\_NAME** será chamado.  
  
## BeginTrans, CommitTrans, reversão  
 **SQLSetConnectOption SQL\_AUTOCOMMIT** e **SQLTransact SQL\_COMMIT**, **SQL\_ROLLBACK** e **SQL\_AUTOCOMMIT** serão destacados se as solicitações de transação são feitas.  
  
## CRecordsets  
 **SQLAllocStmt**, **SQLPrepare**, **SQLExecute** \(para **Abrir** e **Requery**\), **SQLExecDirect** \(para operações de atualização\), **SQLFreeStmt** deve ser suporte.  **SQLNumResultCols** e **SQLDescribeCol** serão chamados os resultados diversas vezes.  
  
 **SQLSetParam** é usado para extensivamente dados do parâmetro e funcionalidade de associação de **DATA\_AT\_EXEC** .  
  
 **SQLBindCol** extensivamente é usado para registrar locais de armazenamento da coluna de saída com ODBC.  
  
 Duas chamadas de **SQLGetData** são usados para recuperar dados de **SQL\_LONG\_VARCHAR** e de **SQL\_LONG\_VARBINARY** .  As tentativas da primeira chamada de localizar o comprimento total do valor da coluna **SQLGetData** chamando com cbMaxValue de 0, mas com um pcbValue válido.  Se o pcbValue contém **SQL\_NO\_TOTAL**, uma exceção será lançada.  Caso contrário, `HGLOBAL` é atribuído, e outra chamada de **SQLGetData** é feito para recuperar o resultado inteiro.  
  
## Atualizando  
 Se o bloqueio pessimista é solicitado, **SQLGetInfo SQL\_LOCK\_TYPES** será consultado.  Se **SQL\_LCK\_EXCLUSIVE** não tem suporte, uma exceção será gerada.  
  
 As tentativas de atualização `CRecordset` \(**snapshot** ou **dynaset**\) causará um segundo **HSTMT** a ser atribuído.  Para drivers que não dão suporte a **HSTMT**, dependendo da biblioteca de cursores simulará essa funcionalidade.  Infelizmente, isso às vezes pode significar forçar a consulta atual em primeiro **HSTMT** até a conclusão antes de processar a segunda solicitação de **HSTMT** .  
  
 **SQLFreeStmt SQL\_CLOSE** e **SQL\_RESET\_PARAMS** e **SQLGetCursorName** serão chamados durante operações de atualização.  
  
 Se houver **CLongBinarys** em **outputColumns**, a funcionalidade de **DATA\_AT\_EXEC** ODBC deve haver suporte.  Isso inclui retornar **SQL\_NEED\_DATA** de **SQLExecDirect**, de **SQLParamData** e de **SQLPutData**.  
  
 **SQLRowCount** é chamado depois execute para verificar se somente 1 registro seja atualizado por **SQLExecDirect**.  
  
## Cursores de ForwardOnly  
 Somente **SQLFetch** é necessário para as operações de **Mover** .  Observe que os cursores de **forwardOnly** não dão suporte a atualizações.  
  
## Cursores de instantâneo  
 A funcionalidade de instantâneo requer suporte de **SQLExtendedFetch** .  Como observado anteriormente, a biblioteca de cursores detectará quando um driver não oferece suporte **SQLExtendedFetch**, e fornece suporte necessário próprio ODBC.  
  
 **SQLGetInfo**, **SQL\_SCROLL\_OPTIONS** deve oferecer suporte **SQL\_SO\_STATIC**.  
  
## Cursores de Dynaset  
 Abaixo está o suporte mínimo necessário abrir um dynaset:  
  
 **SQLGetInfo**, **SQL\_ODBC\_VER** deve retornar \> “01 ".  
  
 **SQLGetInfo**, **SQL\_SCROLL\_OPTIONS** deve oferecer suporte **SQL\_SO\_KEYSET\_DRIVEN**.  
  
 **SQLGetInfo**, **SQL\_ROW\_UPDATES** deve retornar “Y”.  
  
 **SQLGetInfo**, **SQL\_POSITIONED\_UPDATES** deve oferecer suporte **SQL\_PS\_POSITIONED\_DELETE** e **SQL\_PS\_POSITIONED\_UPDATE**.  
  
 Além disso, se o bloqueio pessimista é solicitado, uma chamada para irow **SQLSetPos** com 1, fRefresh FALSE e rebanho **SQL\_LCK\_EXCLUSIVE** será feito.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)