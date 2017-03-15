---
title: "Transa&#231;&#245;es (acesso a dados MFC) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "transações [C++], suporte para"
  - "transações [C++]"
  - "bancos de dados [C++], transações"
ms.assetid: f80afbfe-1517-4fec-8870-9ffc70a58b05
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Transa&#231;&#245;es (acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O conceito de uma transação foi desenvolvido para lidar com casos em que o estado resultante do banco de dados depende do sucesso total de uma série de operações. Isso pode ocorrer porque operações sucessivas podem modificar os resultados de operações anteriores. Nesses casos, se uma operação falhar, o estado resultante pode ser indeterminado.  
  
 Para resolver esse problema, as transações agrupam uma série de operações de tal forma que a integridade do resultado final pode ser garantida. Todas as operações devem ser bem\-sucedidas e depois confirmada \(gravados no banco de dados\) ou a transação inteira falhará. O cancelamento da transação é chamado de reversão. Reversão permite uma recuperação das alterações e retorna o banco de dados para o estado anterior.  
  
 Por exemplo, em uma transação bancária automatizada, se você transferir dinheiro de uma conta para conta B, tanto a retirada de um e o depósito em B deve ser bem\-sucedidas para processar os fundos corretamente ou a transação inteira falhará.  
  
 Uma transação deve ter propriedades ACID, o que significam o seguinte:  
  
-   **Atomicidade** uma transação é uma unidade atômica de trabalho e é executado exatamente uma vez; é todo o trabalho é feito ou nada.  
  
-   **Consistência** uma transação preserva a consistência dos dados, transformando um estado consistente dos dados em outro estado consistente dos dados. Dados vinculados por uma transação devem ser preservados semanticamente.  
  
-   **Isolamento** uma transação é uma unidade de isolamento e cada uma ocorre separadamente e independentemente das transações simultâneas. Uma transação nunca deve ver os estágios intermediários de outra transação.  
  
-   **Durabilidade** uma transação é uma unidade de recuperação. Se uma transação for bem\-sucedida, suas atualizações persistem, mesmo se o sistema falhar ou for desligado. Se uma transação falhar, o sistema permanecerá no estado anterior à confirmação da transação.  
  
 Você pode oferecer suporte a transações em OLE DB \(consulte [suportando transações em OLE DB](../data/oledb/supporting-transactions-in-ole-db.md)\) ou ODBC \(consulte [transação \(ODBC\)](../data/odbc/transaction-odbc.md)\).  
  
 Uma transação distribuída é uma transação que atualiza dados distribuídos, ou seja, os dados em mais de um sistema de computador em rede. Se você quiser oferecer suporte a transações em um sistema distribuído, você deve usar o Microsoft .NET Framework, em vez do suporte a transações OLE DB.  
  
## Consulte também  
 [Programação de acesso a dados \(MFC\/ATL\)](../data/data-access-programming-mfc-atl.md)