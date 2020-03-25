---
title: Transações (Acesso a dados MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- transactions [C++], support for
- transactions [C++]
- databases [C++], transactions
ms.assetid: f80afbfe-1517-4fec-8870-9ffc70a58b05
ms.openlocfilehash: 742e95d896d107fb89b3d65f0eeb6d418f1b2057
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209060"
---
# <a name="transactions--mfc-data-access"></a>Transações (Acesso a dados MFC)

O conceito de uma transação foi desenvolvido para lidar com casos em que o estado resultante do banco de dados depende do sucesso total de uma série de operações. Isso pode ocorrer porque operações sucessivas podem modificar os resultados de operações anteriores. Nesses casos, se uma operação falhar, o estado resultante poderá ser indeterminado.

Para resolver esse problema, as transações agrupam uma série de operações de tal forma que a integridade do resultado final pode ser garantido. Todas as operações devem ser bem-sucedidas e depois aplicadas (gravadas no banco de dados) ou toda a transação falhará. O cancelamento da transação é chamado de reversão. Reversão permite uma recuperação das alterações e retorna o banco de dados ao estado anterior à transação.

Por exemplo, em uma transação bancária automatizada, se você transferir dinheiro de uma conta A para a conta B, tanto a retirada de A e o depósito em B devem ser bem-sucedidas para processar os fundos corretamente ou a transação inteira falhará.

Uma transação deve ter propriedades ACID, o que significa o seguinte:

- **Atomicidade** Uma transação é uma unidade atômica de trabalho e é executada exatamente uma vez; todo o trabalho é feito ou nenhum deles é.

- **Consistência** do Uma transação preserva a consistência dos dados, transformando um estado consistente dos dados em outro Estado de dados consistente. Dados vinculados por uma transação devem ser preservados semanticamente.

- **Isolamento** do Uma transação é uma unidade de isolamento e cada uma ocorre separadamente e independentemente de transações simultâneas. Uma transação nunca deve ver os estágios intermediários de outra transação.

- **Durabilidade** Uma transação é uma unidade de recuperação. Se uma transação for bem-sucedida, suas atualizações persistem, mesmo se o sistema falhar ou for desligado. Se uma transação falhar, o sistema permanecerá no estado anterior à confirmação da transação.

Você pode dar suporte a transações em OLE DB (consulte [Transações de suporte no OLE DB](../data/oledb/supporting-transactions-in-ole-db.md)) ou ODBC (consulte [transação (ODBC)](../data/odbc/transaction-odbc.md)).

Uma transação distribuída é uma transação que atualiza dados distribuídos, ou seja, os dados em mais de um sistema de computador da rede. Se você quiser dar suporte a transações em um sistema distribuído, deverá usar ADO.NET em vez do suporte OLE DB transação.

## <a name="see-also"></a>Confira também

[Programação de Acesso a Dados (MFC/ATL)](../data/data-access-programming-mfc-atl.md)
