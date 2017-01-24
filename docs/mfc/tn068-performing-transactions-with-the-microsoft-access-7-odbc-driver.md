---
title: "TN068: realizando transa&#231;&#245;es com o driver ODBC do Microsoft Access 7 | Microsoft Docs"
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
  - "vc.data.odbc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "TN068"
  - "transações, Chamando BeginTrans"
  - "transações, Microsoft Access"
ms.assetid: d3f8f5d9-b118-4194-be36-a1aefb630c45
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN068: realizando transa&#231;&#245;es com o driver ODBC do Microsoft Access 7
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve como executar transações ao usar as classes da base de dados de MFC ODBC e o driver ODBC do Microsoft Access 7,0 incluído no driver ODBC do Microsoft Área De Trabalho os pacotes a versão 3,0.  
  
## Visão Geral  
 Se seu aplicativo de base de dados executa transações, você deve ter cuidado para chamar `CDatabase::BeginTrans` e `CRecordset::Open` na sequência correta em seu aplicativo.  O driver do Microsoft Access 7,0 usa o mecanismo de base de dados do Microsoft Jet, e Jet requer que seu aplicativo não iniciar uma transação em qualquer base de dados que tenha um cursor aberto.  Para classes de base de dados de MFC ODBC, um cursor aberto é igual a `CRecordset` um objeto aberto.  
  
 Se você abrir um conjunto de registros antes de chamar **BeginTrans**, você não pode consultar nenhuma mensagem de erro.  No entanto, qualquer conjunto de registros atualizar seu aplicativo faz ponderado permanente depois de chamar `CRecordset::Update`, e as atualizações não serão revertidas chamando **Reverter**.  Para evitar esse problema, você deve chamar **BeginTrans** primeiro e abre no conjunto de registros.  
  
 MFC O verifica a funcionalidade de driver para a confirmação de cursor e o comportamento de reversão.  A classe `CDatabase` fornece duas funções de membro, `GetCursorCommitBehavior` e `GetCursorRollbackBehavior`, para determinar o efeito de qualquer transação no objeto aberto de `CRecordset` .  Para o driver ODBC do Microsoft Access 7,0, essas funções de membro retornam `SQL_CB_CLOSE` porque o driver de acesso não oferece suporte à preservação de cursor.  Em virtude disso, você deve chamar `CRecordset::Requery` após uma operação de **CommitTrans** ou de **Reverter** .  
  
 Quando você precisar executar uma após a outra várias transações, você não pode chamar **Requery** depois da primeira transação e depois iniciar a seguir.  Você deve fechar o conjunto de registros antes da próxima chamada a **BeginTrans** para satisfazer o requisito do Jet.  Observe que essa técnica descreve dois métodos de tratar essa situação:  
  
-   Fechando o conjunto de registros após cada operação de **CommitTrans** ou de **Reverter** .  
  
-   Usando a função **SQLFreeStmt**de ODBC API.  
  
## Fechando o conjunto de registros após cada operação de CommitTrans ou de reversão  
 Antes de iniciar uma transação, certifique\-se de que o objeto do conjunto de registros é fechado.  Depois de chamar **BeginTrans**, chame a função de membro de **Abrir** conjunto de registros.  Feche o conjunto de registros imediatamente depois de chamar **CommitTrans** ou **Reverter**.  Observe que repetidamente abrir e fechar o conjunto de registros podem reduzir o desempenho de um aplicativo.  
  
## Usando SQLFreeStmt  
 Você também pode usar a função **SQLFreeStmt** de ODBC API para fechar explicitamente o cursor depois de ter terminado uma transação.  Para iniciar outra transação, chame **BeginTrans** seguido por `CRecordset::Requery`.  Ao chamar **SQLFreeStmt**, você deve especificar o HSTMT do conjunto de registros como o primeiro parâmetro e o **SQL\_CLOSE** como o segundo parâmetro.  Esse método é mais rápido do que abrindo e fechando o conjunto de registros no início de cada transação.  O código a seguir demonstra como implementar essa técnica:  
  
```  
CMyDatabase db;  
db.Open( "MYDATASOURCE" );  
CMyRecordset rs( &db );  
  
// start transaction 1 and   
// open the recordset  
db.BeginTrans( );  
rs.Open( );  
  
// manipulate data  
  
// end transaction 1  
db.CommitTrans( );  // or Rollback( )  
  
// close the cursor  
::SQLFreeStmt( rs.m_hstmt, SQL_CLOSE );  
  
// start transaction 2  
db.BeginTrans( );  
  
// now get the result set  
rs.Requery( );  
  
// manipulate data  
  
// end transaction 2  
db.CommitTrans( );  
  
rs.Close( );  
db.Close( );  
```  
  
 Outra maneira de implementar essa técnica é gravar uma nova função, **RequeryWithBeginTrans**, que você pode chamar para iniciar a transação seguinte depois que você confirmar ou reversão primeira.  Para escrever essa função, execute as seguintes etapas:  
  
1.  Copie o código para **CRecordset::Requery\( \)** à nova função.  
  
2.  Adicione a seguinte linha imediatamente depois da chamada para **SQLFreeStmt**:  
  
     `m_pDatabase->BeginTrans( );`  
  
 Agora você pode chamar essa função entre cada par de transações:  
  
```  
// start transaction 1 and   
// open the recordset  
db.BeginTrans( );  
rs.Open( );  
  
// manipulate data  
  
// end transaction 1  
db.CommitTrans( );  // or Rollback( )  
  
// close the cursor, start new transaction,  
// and get the result set  
rs.RequeryWithBeginTrans( );  
  
// manipulate data  
  
// end transaction 2  
db.CommitTrans( );  // or Rollback( )  
```  
  
> [!NOTE]
>  Não use essa técnica se você precisar alterar as variáveis **m\_strFilter** ou `m_strSort` do membro do conjunto de registros entre transações.  Nesse caso, você deve fechar o conjunto de registros após cada operação de **CommitTrans** ou de **Reverter** .  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)