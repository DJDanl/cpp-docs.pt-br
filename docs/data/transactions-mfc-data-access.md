---
title: Transações (acesso a dados MFC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- transactions [C++], support for
- transactions [C++]
- databases [C++], transactions
ms.assetid: f80afbfe-1517-4fec-8870-9ffc70a58b05
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a9dd531aee6ac8014f2ce47ddee7fc5f82e35a63
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33107812"
---
# <a name="transactions--mfc-data-access"></a>Transações (Acesso a dados MFC)
O conceito de uma transação foi desenvolvido para lidar com casos em que o estado resultante do banco de dados depende do sucesso total de uma série de operações. Isso pode ocorrer porque operações sucessivas podem modificar os resultados de operações anteriores. Nesses casos, se uma operação falhar, o estado resultante poderá ser indeterminado.  
  
 Para resolver esse problema, as transações agrupam uma série de operações de tal forma que a integridade do resultado final pode ser garantido. Todas as operações devem ser bem-sucedidas e depois aplicadas (gravadas no banco de dados) ou toda a transação falhará. O cancelamento da transação é chamado de reversão. Reversão permite uma recuperação das alterações e retorna o banco de dados ao estado anterior à transação.  
  
 Por exemplo, em uma transação bancária automatizada, se você transferir dinheiro de uma conta A para a conta B, tanto a retirada de A e o depósito em B devem ser bem-sucedidas para processar os fundos corretamente ou a transação inteira falhará.  
  
 Uma transação deve ter propriedades ACID, o que significa o seguinte:  
  
-   **Atomicidade** uma transação é uma unidade atômica de trabalho e executa exatamente uma vez; todo o trabalho é feito ou nenhum.  
  
-   **Consistência** uma transação preserva a consistência dos dados, transformar um estado consistente de dados em outro estado consistente de dados. Dados vinculados por uma transação devem ser preservados semanticamente.  
  
-   **Isolamento** uma transação é uma unidade de isolamento e cada ocorre separadamente e independentemente das transações simultâneas. Uma transação nunca deve ver os estágios intermediários de outra transação.  
  
-   **Durabilidade** uma transação é uma unidade de recuperação. Se uma transação for bem-sucedida, suas atualizações persistem, mesmo se o sistema falhar ou for desligado. Se uma transação falhar, o sistema permanecerá no estado anterior à confirmação da transação.  
  
 Você pode dar suporte a transações no banco de dados OLE (consulte [transações com suporte no OLE DB](../data/oledb/supporting-transactions-in-ole-db.md)) ou ODBC (consulte [transação (ODBC)](../data/odbc/transaction-odbc.md)).  
  
 Uma transação distribuída é uma transação que atualiza dados distribuídos, ou seja, os dados em mais de um sistema de computador da rede. Se você quiser oferecer suporte a transações em um sistema distribuído, você deve usar o ADO.NET em vez do suporte a transações OLE DB.  
  
## <a name="see-also"></a>Consulte também  
 [Acesso a dados (MFC/ATL) de programação](../data/data-access-programming-mfc-atl.md)