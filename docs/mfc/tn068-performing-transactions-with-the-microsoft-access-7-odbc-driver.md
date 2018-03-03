---
title: "TN068: Realizando transações com o Driver ODBC do Microsoft Access 7 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.data.odbc
dev_langs:
- C++
helpviewer_keywords:
- TN068 [MFC]
- transactions [MFC], calling BeginTrans
- transactions [MFC], Microsoft Access
ms.assetid: d3f8f5d9-b118-4194-be36-a1aefb630c45
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 6db31d6301f2f0937d7bb5b83e77bf59936efdfe
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn068-performing-transactions-with-the-microsoft-access-7-odbc-driver"></a>TN068: realizando transações com o driver ODBC do Microsoft Access 7
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve como executar transações ao usar as classes de banco de dados ODBC MFC e o driver ODBC do Microsoft Access 7.0 incluída na versão de pacote de Driver de área de trabalho do Microsoft ODBC 3.0.  
  
## <a name="overview"></a>Visão geral  
 Se o aplicativo de banco de dados executa transações, você deve ter cuidado para chamar `CDatabase::BeginTrans` e `CRecordset::Open` na sequência correta em seu aplicativo. O driver do Microsoft Access 7.0 usa o mecanismo de banco de dados Microsoft Jet e Jet requer que seu aplicativo não iniciar uma transação em qualquer banco de dados que tem um cursor aberto. Para as classes de banco de dados ODBC do MFC, um cursor aberto é igual a um aberto `CRecordset` objeto.  
  
 Se você abrir um conjunto de registros antes de chamar **BeginTrans**, você não poderá ver as mensagens de erro. No entanto, qualquer conjunto de registros atualiza o aplicativo faz se tornam permanentes após a chamada `CRecordset::Update`, e as atualizações não voltará chamando **reversão**. Para evitar esse problema, você deve chamar **BeginTrans** primeiro e, em seguida, abra o conjunto de registros.  
  
 MFC verifica a funcionalidade do driver para o comportamento de confirmação e reversão de cursor. Classe `CDatabase` fornece duas funções de membro, `GetCursorCommitBehavior` e `GetCursorRollbackBehavior`, para determinar o efeito de qualquer transação em seu aberto `CRecordset` objeto. Para o driver ODBC do Microsoft Access 7.0, essas funções de membro retornam `SQL_CB_CLOSE` porque o driver do Access não dá suporte a preservação do cursor. Portanto, você deve chamar `CRecordset::Requery` seguir um **CommitTrans** ou **reversão** operação.  
  
 Quando você precisa executar várias transações após o outro, não é possível chamar **Requery** após a primeira transação e, em seguida, iniciar o outro. Você deve fechar o conjunto de registros antes da próxima chamada para **BeginTrans** para satisfazer o requisito do Jet. Essa observação técnica descreve dois métodos para tratar essa situação:  
  
-   O conjunto de registros de fechamento após cada **CommitTrans** ou **reversão** operação.  
  
-   Usando a função de API ODBC **SQLFreeStmt**.  
  
## <a name="closing-the-recordset-after-each-committrans-or-rollback-operation"></a>O conjunto de registros de fechamento após cada operação de reversão ou CommitTrans  
 Antes de iniciar uma transação, verifique se que o objeto de conjunto de registros é fechado. Depois de chamar **BeginTrans**, chame o conjunto de registros **abrir** função de membro. Feche o conjunto de registros imediatamente depois de chamar **CommitTrans** ou **reversão**. Observe que repetidamente abrir e fechar o conjunto de registros podem prejudicar o desempenho de um aplicativo.  
  
## <a name="using-sqlfreestmt"></a>Usando SQLFreeStmt  
 Você também pode usar a função de API ODBC **SQLFreeStmt** fechar explicitamente o cursor após o término de uma transação. Para iniciar outra transação, chame **BeginTrans** seguido por `CRecordset::Requery`. Ao chamar **SQLFreeStmt**, você deve especificar HSTMT o conjunto de registros como o primeiro parâmetro e **SQL_CLOSE** como o segundo parâmetro. Esse método é mais rápido do que o conjunto de registros no início de cada transação de abertura e fechamento. O código a seguir demonstra como implementar essa técnica:  
  
```  
CMyDatabase db;  
db.Open("MYDATASOURCE");

CMyRecordset rs(&db);

 
// start transaction 1 and   
// open the recordset  
db.BeginTrans();

rs.Open();

 
// manipulate data  
 
// end transaction 1  
db.CommitTrans();
*// or Rollback()  
 
// close the cursor  
::SQLFreeStmt(rs.m_hstmt, SQL_CLOSE);

 
// start transaction 2  
db.BeginTrans();

 
// now get the result set  
rs.Requery();

 
// manipulate data  
 
// end transaction 2  
db.CommitTrans();

 
rs.Close();

db.Close();
```  
  
 Outra maneira de implementar essa técnica é para gravar uma nova função, **RequeryWithBeginTrans**, que pode ser chamado para iniciar a próxima transação após a confirmação ou reversão primeiro. Para escrever uma função, siga as etapas a seguir:  
  
1.  Copie o código para **(CRecordset::Requery)** para a nova função.  
  
2.  Adicione a seguinte linha imediatamente após a chamada a **SQLFreeStmt**:  
  
 `m_pDatabase->BeginTrans( );`  
  
 Agora você pode chamar essa função entre cada par de transações:  
  
```  
// start transaction 1 and   
// open the recordset  
db.BeginTrans();

rs.Open();

 
// manipulate data  
 
// end transaction 1  
db.CommitTrans();
*// or Rollback()  
 
// close the cursor,
    start new transaction,  
// and get the result set  
rs.RequeryWithBeginTrans();

 
// manipulate data  
 
// end transaction 2  
db.CommitTrans();
*// or Rollback()  
```  
  
> [!NOTE]
>  Não use essa técnica se você precisar alterar as variáveis de membro do conjunto de registros **m_strFilter** ou `m_strSort` entre as transações. Nesse caso, você deve fechar o conjunto de registros após cada **CommitTrans** ou **reversão** operação.  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

