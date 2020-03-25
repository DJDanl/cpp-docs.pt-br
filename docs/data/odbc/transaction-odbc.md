---
title: Transação (ODBC)
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC recordsets [C++], updating
- transactions [C++], MFC ODBC classes
- ODBC [C++], transactions
- recordsets [C++], updating
- databases [C++], transactions
- recordsets [C++], transactions
- ODBC recordsets [C++], transactions
ms.assetid: a2ec0995-2029-45f2-8092-6efd6f2a77f4
ms.openlocfilehash: 49fc0e244dd4f63bd7a69d963ff2a9fbc00ddb6c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80212596"
---
# <a name="transaction-odbc"></a>Transação (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Uma transação é uma maneira de agrupar, ou em lote, uma série de atualizações em uma [fonte de dados](../../data/odbc/data-source-odbc.md) para que todas sejam confirmadas de uma só vez ou nenhuma seja confirmada se você reverter a transação. Se você não usar uma transação, as alterações na fonte de dados serão confirmadas automaticamente em vez de serem confirmadas sob demanda.

> [!NOTE]
>  Nem todos os drivers de banco de dados ODBC dão suporte a transações. Chame a função membro `CanTransact` do seu objeto [CDatabase](../../mfc/reference/cdatabase-class.md) ou [CRecordset](../../mfc/reference/crecordset-class.md) para determinar se o driver dá suporte a transações para um determinado banco de dados. Observe que `CanTransact` não informa se a fonte de dados fornece suporte completo a transações. Você também deve chamar `CDatabase::GetCursorCommitBehavior` e `CDatabase::GetCursorRollbackBehavior` após `CommitTrans` e `Rollback` para verificar o efeito da transação no objeto Open `CRecordset`.

As chamadas para as funções de membro `AddNew` e `Edit` de um objeto `CRecordset` afetam a fonte de dados imediatamente quando você chama `Update`. `Delete` chamadas também entram em vigor imediatamente. Por outro lado, você pode usar uma transação que consiste em várias chamadas para `AddNew`, `Edit`, `Update`e `Delete`, que são executadas, mas não confirmadas até que você chame `CommitTrans` explicitamente. Ao estabelecer uma transação, você pode executar uma série de chamadas desse tipo e, ao mesmo tempo, manter a capacidade de redistribuí-las. Se um recurso crítico não estiver disponível ou alguma outra condição impedir a conclusão da transação inteira, você poderá reverter a transação em vez de confirmá-la. Nesse caso, nenhuma das alterações pertencentes à transação afeta a fonte de dados.

> [!NOTE]
>  Atualmente, a classe `CRecordset` não oferece suporte a atualizações para a fonte de dados se você tiver implementado a busca em massa de linha. Isso significa que você não pode fazer chamadas para `AddNew`, `Edit`, `Delete`ou `Update`. No entanto, você pode escrever suas próprias funções para executar atualizações e, em seguida, chamar essas funções em uma determinada transação. Para obter mais informações sobre a busca de linha em massa, consulte [conjunto de registros: buscando registros em massa (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

> [!NOTE]
>  Além de afetar o conjunto de registros, as transações afetam as instruções SQL executadas diretamente, desde que você use o **HDBC** ODBC associado ao seu objeto `CDatabase` ou a um **HSTMT** ODBC com base nesse **HDBC**.

As transações são particularmente úteis quando você tem vários registros que devem ser atualizados simultaneamente. Nesse caso, você deseja evitar uma transação com meia conclusão, como pode acontecer se uma exceção foi lançada antes da última atualização ter sido feita. O agrupamento dessas atualizações em uma transação permite uma recuperação (reversão) das alterações e retorna os registros para o estado de pretransação. Por exemplo, se um banco transferir dinheiro da conta A para a conta B, tanto a retirada de um quanto o depósito para B deverão ter êxito em processar os fundos corretamente ou a transação inteira deverá falhar.

Nas classes de banco de dados, você executa transações por meio de `CDatabase` objetos. Um objeto `CDatabase` representa uma conexão com uma fonte de dados e um ou mais conjuntos de registros associados a esse objeto `CDatabase` operam em tabelas do banco de dados por meio de funções membro do conjunto de registros.

> [!NOTE]
>  Há suporte para apenas um nível de transações. Não é possível aninhar transações nem uma transação abranger vários objetos de banco de dados.

Os tópicos a seguir fornecem mais informações sobre como as transações são executadas:

- [Transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)

- [Transação: como as transações afetam atualizações (ODBC)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)

## <a name="see-also"></a>Confira também

[ODBC (conectividade de banco de dados aberto)](../../data/odbc/open-database-connectivity-odbc.md)
