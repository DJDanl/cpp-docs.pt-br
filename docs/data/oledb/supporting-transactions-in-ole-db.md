---
title: Dando suporte a transações em banco de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB consumer templates [C++], transaction support
- transactions [C++], OLE DB support for
- nested transactions [C++]
- OLE DB [C++], transaction support
- databases [C++], transactions
- distributed transactions [C++]
ms.assetid: 3d72e583-ad38-42ff-8f11-e2166d60a5a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ecd5b7274e62508289a83d6c0420d5f76e239e4d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="supporting-transactions-in-ole-db"></a>Dando suporte a transações em banco de dados OLE
Um [transação](../../data/transactions-mfc-data-access.md) é uma maneira de agrupar ou lote, uma série de atualizações para uma fonte de dados de modo que todos os tenha êxito e são confirmados ao mesmo tempo ou (se qualquer um dos falhá-los) nenhum são confirmadas e a transação inteira é revertida. Esse processo garante a integridade do resultado na fonte de dados.  
  
 OLE DB oferece suporte a transações com três métodos a seguir:  
  
-   [ITransactionLocal::StartTransaction](https://msdn.microsoft.com/en-us/library/ms709786.aspx)  
  
-   [ITransaction::Commit](https://msdn.microsoft.com/en-us/library/ms713008.aspx)  
  
-   [ITransaction::Abort](https://msdn.microsoft.com/en-us/library/ms709833.aspx)  
  
## <a name="relationship-of-sessions-and-transactions"></a>Relação de sessões e transações  
 Um objeto de fonte de dados pode criar um ou mais objetos de sessão, cada um deles pode estar dentro ou fora do escopo de uma transação em um determinado momento.  
  
 Quando uma sessão não insere uma transação, todo o trabalho feito na sessão no armazenamento de dados é confirmado imediatamente em cada chamada de método. (Isso é, às vezes, conhecido como modo de confirmação automática ou implícita.)  
  
 Quando uma sessão entra em uma transação, todo o trabalho feito na sessão no armazenamento de dados faz parte da transação e é confirmado ou anulado como uma única unidade. (Isto é, às vezes, conhecido como modo de confirmação manual.)  
  
 Suporte a transações é específica do provedor. Se o provedor que você está usando dá suporte a transações, um objeto de sessão que dá suporte a **ITransaction** e **ITransactionLocal** pode inserir um simples (ou seja, não aninhada) transações. A classe de modelos OLE DB [CSession](../../data/oledb/csession-class.md) oferece suporte a essas interfaces e é a maneira recomendada para implementar o suporte a transações em Visual C++.  
  
## <a name="starting-and-ending-the-transaction"></a>Início e término da transação  
 Você chama o `StartTransaction`, **confirmar**, e **anular** métodos do objeto de conjunto de linhas no consumidor.  
  
 Chamando **itransactionlocal:: Starttransaction** inicia uma nova transação local. Quando você inicia a transação, as alterações exigidas por operações subsequentes não são realmente aplicadas ao repositório de dados até que você confirme a transação.  
  
 Chamando **ITransaction:: Commit** ou **ITransaction:: Abort** termina a transação. **Confirmar** faz com que todas as alterações dentro do escopo da transação a ser aplicado ao repositório de dados. **Anular** faz com que todas as alterações dentro do escopo de transação a ser cancelada e o repositório de dados será deixado no estado que ele tinha antes do início da transação.  
  
## <a name="nested-transactions"></a>Transações aninhadas  
 Um [transaction aninhada](https://msdn.microsoft.com/en-us/library/ms716985.aspx) ocorre quando você inicia uma nova transação local quando uma transação ativa já existe na sessão. A nova transação seja iniciada como uma transação aninhada abaixo da transação atual. Se o provedor não oferece suporte a transações aninhadas, chamando `StartTransaction` quando já há uma transação ativa na sessão retorna **XACT_E_XTIONEXISTS**.  
  
## <a name="distributed-transactions"></a>Transações distribuídas  
 Uma transação distribuída é uma transação que atualiza dados distribuídos; ou seja, os dados em mais de um sistema de computador na rede. Se você quiser oferecer suporte a transações em um sistema distribuído, você deve usar o .NET Framework em vez do suporte a transações OLE DB.  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)