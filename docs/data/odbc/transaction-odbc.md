---
title: Transação (ODBC) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- ODBC recordsets [C++], updating
- transactions [C++], MFC ODBC classes
- ODBC [C++], transactions
- recordsets [C++], updating
- databases [C++], transactions
- recordsets [C++], transactions
- ODBC recordsets [C++], transactions
ms.assetid: a2ec0995-2029-45f2-8092-6efd6f2a77f4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3acd47746d3a920b679fb5509c34e5978ad43eed
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33094020"
---
# <a name="transaction-odbc"></a>Transação (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Uma transação é uma maneira de agrupar ou lote, uma série de atualizações para um [fonte de dados](../../data/odbc/data-source-odbc.md) para que todos são confirmados ao mesmo tempo ou nenhum serão confirmadas se você reverter a transação. Se você não usar uma transação, as alterações na fonte de dados são confirmadas automaticamente em vez de ser comprometida sob demanda.  
  
> [!NOTE]
>  Nem todos os drivers de banco de dados ODBC oferecem suporte a transações. Chamar o `CanTransact` função membro de sua [CDatabase](../../mfc/reference/cdatabase-class.md) ou [CRecordset](../../mfc/reference/crecordset-class.md) objeto para determinar se o driver oferece suporte a transações para um determinado banco de dados. Observe que `CanTransact` não informa se a fonte de dados fornece suporte de transação completa. Você também deve chamar `CDatabase::GetCursorCommitBehavior` e `CDatabase::GetCursorRollbackBehavior` depois **CommitTrans** e **reversão** para verificar o efeito da transação em abrir `CRecordset` objeto.  
  
 Chamadas para o `AddNew` e **editar** funções membro de um `CRecordset` objeto afetam a fonte de dados imediatamente quando você chama **atualização**. **Excluir** chamadas também entram em vigor imediatamente. Por outro lado, você pode usar uma transação consiste em várias chamadas para `AddNew`, **editar**, **atualização**, e **excluir**, que são executadas, mas não confirmado até você chamar **CommitTrans** explicitamente. Estabelecendo uma transação, você pode executar uma série de tais chamadas ao mesmo tempo, preservar a capacidade de revertê-los. Se um recurso crítico está indisponível ou outra condição impede que toda a transação seja concluída, você pode reverter a transação em vez de confirmá-la. Nesse caso, nenhuma das alterações que pertencem à transação afeta a fonte de dados.  
  
> [!NOTE]
>  No momento, a classe `CRecordset` não oferece suporte a atualizações para a fonte de dados se você tiver implementado em busca de linhas em massa. Isso significa que você não pode fazer chamadas para `AddNew`, **editar**, **excluir**, ou **atualização**. No entanto, você pode escrever funções próprias para executar atualizações e, em seguida, chamar essas funções em uma determinada transação. Para obter mais informações sobre a busca de linhas em massa, consulte [conjunto de registros: busca de registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).  
  
> [!NOTE]
>  Além de afetar o conjunto de registros, as transações afetam instruções SQL que você execute diretamente como você usar o ODBC **HDBC** associado com seu `CDatabase` objeto ou um ODBC **HSTMT** com base em que **HDBC**.  
  
 As transações são particularmente úteis quando você tem vários registros que devem ser atualizados ao mesmo tempo. Nesse caso, você deseja evitar uma transação concluída metade, tais como pode ocorrer se uma exceção foi lançada antes que a última atualização foi feita. Agrupar essas atualizações em uma transação permite uma recuperação (reversão) das alterações e retorna os registros para o estado pretransaction. Por exemplo, se um banco transfere dinheiro de conta A conta B, tanto a retirada do depósito A e a para B deve ter êxito para processar os fundos corretamente ou a transação inteira deve falhar.  
  
 As classes de banco de dados, você executará as transações por meio de `CDatabase` objetos. Um `CDatabase` objeto representa uma conexão a uma fonte de dados, e um ou mais conjuntos de registros associado que `CDatabase` objeto opera em tabelas do banco de dados por meio de funções de membro do conjunto de registros.  
  
> [!NOTE]
>  Há suporte para apenas um nível de transações. Não é possível aninhar transações, nem pode abranger de uma transação de vários objetos de banco de dados.  
  
 Os tópicos a seguir fornecem mais informações sobre como as transações são executadas:  
  
-   [Transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)  
  
-   [Transação: como as transações afetam atualizações (ODBC)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)  
  
## <a name="see-also"></a>Consulte também  
 [ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)