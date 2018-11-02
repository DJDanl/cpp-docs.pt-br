---
title: Dando suporte a transações em banco de dados OLE
ms.date: 10/24/2018
helpviewer_keywords:
- OLE DB consumer templates [C++], transaction support
- transactions [C++], OLE DB support for
- nested transactions [C++]
- OLE DB [C++], transaction support
- databases [C++], transactions
- distributed transactions [C++]
ms.assetid: 3d72e583-ad38-42ff-8f11-e2166d60a5a7
ms.openlocfilehash: 58316a6f09fcd60aae8b8de41e22af138ae88813
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50527160"
---
# <a name="supporting-transactions-in-ole-db"></a>Dando suporte a transações em banco de dados OLE

Um [transação](../../data/transactions-mfc-data-access.md) é uma maneira de grupo, ou um lote, uma série de atualizações para uma fonte de dados para que tudo tenha êxito e são confirmados ao mesmo tempo ou (se qualquer uma falha) nenhum serão confirmadas e toda a transação será revertida. Esse processo garante a integridade do resultado na fonte de dados.

OLE DB dá suporte a transações com três métodos a seguir:

- [ITransactionLocal::StartTransaction](/previous-versions/windows/desktop/ms709786)

- [ITransaction::Commit](/previous-versions/windows/desktop/ms713008)

- [ITransaction::Abort](/previous-versions/windows/desktop/ms709833)

## <a name="relationship-of-sessions-and-transactions"></a>Relação de sessões e transações

Um objeto de fonte de dados pode criar um ou mais objetos de sessão, cada um dos quais pode estar dentro ou fora do escopo de uma transação em um determinado momento.

Quando uma sessão não insere uma transação, todo o trabalho feito dentro dessa sessão no armazenamento de dados é confirmado imediatamente em cada chamada de método. (Isso é às vezes chamado como modo de confirmação automática ou implícita.)

Quando uma sessão entra em uma transação, todo o trabalho feito dentro dessa sessão no armazenamento de dados é parte dessa transação e é confirmado ou anulado como uma única unidade. (Isso é às vezes chamado como modo de confirmação manual.)

Suporte a transações é específica do provedor. Se o provedor que você está usando dá suporte a transações, um objeto de sessão que dá suporte a `ITransaction` e `ITransactionLocal` pode inserir uma transação (não aninhado). A classe de modelos OLE DB [CSession](../../data/oledb/csession-class.md) dá suporte a essas interfaces e é a maneira recomendada para implementar o suporte de transação no Visual C++.

## <a name="starting-and-ending-the-transaction"></a>Inicial e final da transação

Você chama o `StartTransaction`, `Commit`, e `Abort` métodos do objeto de conjunto de linhas no consumidor.

Chamar `ITransactionLocal::StartTransaction` inicia uma nova transação local. Quando você inicia a transação, todas as alterações exigidas por operações posteriores não são aplicadas ao armazenamento de dados até que você confirme a transação.

Chamando `ITransaction::Commit` ou `ITransaction::Abort` termina a transação. `Commit` faz com que todas as alterações dentro do escopo da transação a ser aplicado ao armazenamento de dados. `Abort` faz com que todas as alterações dentro do escopo de transação a ser cancelado e o armazenamento de dados será deixado no estado que ele tinha antes da transação foi iniciada.

## <a name="nested-transactions"></a>Transações aninhadas

Um [transaction aninhada](/previous-versions/windows/desktop/ms716985) ocorre quando você inicia uma nova transação local quando uma transação ativa já existe na sessão. A nova transação seja iniciada como uma transação aninhada abaixo da transação atual. Se o provedor não dá suporte a transações aninhadas, chamando `StartTransaction` quando já houver uma transação ativa na sessão retorna XACT_E_XTIONEXISTS.

## <a name="distributed-transactions"></a>Transações distribuídas

Uma transação distribuída é uma transação que atualiza dados distribuídos; ou seja, os dados em mais de um sistema de computador em rede. Se você quiser dar suporte a transações em um sistema distribuído, você deve usar o .NET Framework em vez do suporte a transações OLE DB.

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)