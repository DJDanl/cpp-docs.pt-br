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
ms.openlocfilehash: e7ec4f69b4bba497446c94afb94cb5a1d648f7c7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209529"
---
# <a name="supporting-transactions-in-ole-db"></a>Dando suporte a transações em banco de dados OLE

Uma [transação](../../data/transactions-mfc-data-access.md) é uma maneira de agrupar, ou em lote, uma série de atualizações em uma fonte de dados para que todas tenham êxito e sejam confirmadas de uma vez ou (se qualquer uma delas falhar) nenhuma for confirmada e a transação inteira for revertida. Esse processo garante a integridade do resultado na fonte de dados.

OLE DB dá suporte a transações com os três métodos a seguir:

- [ITransactionLocal:: StartTransaction](/previous-versions/windows/desktop/ms709786(v=vs.85))

- [ITransaction:: Commit](/previous-versions/windows/desktop/ms713008(v=vs.85))

- [ITransaction:: Abort](/previous-versions/windows/desktop/ms709833(v=vs.85))

## <a name="relationship-of-sessions-and-transactions"></a>Relação de sessões e transações

Um único objeto de fonte de dados pode criar um ou mais objetos de sessão, cada um dos quais pode estar dentro ou fora do escopo de uma transação em um determinado momento.

Quando uma sessão não entra em uma transação, todo o trabalho feito nessa sessão no armazenamento de dados é imediatamente confirmado em cada chamada de método. (Às vezes, isso é chamado de modo de confirmação automática ou modo implícito.)

Quando uma sessão entra em uma transação, todo o trabalho feito nessa sessão no repositório de dados faz parte dessa transação e é confirmado ou anulado como uma única unidade. (Às vezes, isso é chamado de modo de confirmação manual.)

O suporte de transação é específico do provedor. Se o provedor que você está usando oferece suporte a transações, um objeto de sessão que dá suporte a `ITransaction` e `ITransactionLocal` pode inserir uma transação (não aninhada). A classe de modelos de OLE DB [CSession](../../data/oledb/csession-class.md) dá suporte a essas interfaces e é a maneira recomendada para implementar C++o suporte a transações no Visual.

## <a name="starting-and-ending-the-transaction"></a>Iniciando e terminando a transação

Você chama os métodos `StartTransaction`, `Commit`e `Abort` no objeto Rowset no consumidor.

Chamar `ITransactionLocal::StartTransaction` inicia uma nova transação local. Quando você inicia a transação, todas as alterações exigidas por operações posteriores não são aplicadas ao armazenamento de dados até que você confirme a transação.

Chamar `ITransaction::Commit` ou `ITransaction::Abort` termina a transação. `Commit` faz com que todas as alterações no escopo da transação sejam aplicadas ao armazenamento de dados. `Abort` faz com que todas as alterações no escopo da transação sejam canceladas e o armazenamento de dados seja deixado no estado em que tinha antes da transação ser iniciada.

## <a name="nested-transactions"></a>Transações aninhadas

Uma [transação aninhada](/previous-versions/windows/desktop/ms716985(v=vs.85)) ocorre quando você inicia uma nova transação local quando uma transação ativa já existe na sessão. A nova transação é iniciada como uma transação aninhada abaixo da transação atual. Se o provedor não oferecer suporte a transações aninhadas, chamar `StartTransaction` quando já houver uma transação ativa na sessão retornar XACT_E_XTIONEXISTS.

## <a name="distributed-transactions"></a>Transações distribuídas

Uma transação distribuída é uma transação que atualiza dados distribuídos; ou seja, dados em mais de um sistema de computador em rede. Se você quiser dar suporte a transações em um sistema distribuído, deverá usar o .NET Framework em vez do suporte de transação OLE DB.

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)
