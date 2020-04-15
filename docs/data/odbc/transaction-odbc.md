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
ms.openlocfilehash: 56629f8c5ff74aff4e0df589cda1e7b988fb5fd3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376407"
---
# <a name="transaction-odbc"></a>Transação (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Uma transação é uma maneira de agrupar, ou em lote, uma série de atualizações para uma fonte de [dados](../../data/odbc/data-source-odbc.md) para que todas sejam cometidas de uma vez ou nenhuma são cometidas se você reverter a transação. Se você não usar uma transação, as alterações na fonte de dados são cometidas automaticamente em vez de serem cometidas sob demanda.

> [!NOTE]
> Nem todos os drivers de banco de dados ODBC suportam transações. Ligue `CanTransact` para a função membro do seu objeto [CDatabase](../../mfc/reference/cdatabase-class.md) ou [CRecordset](../../mfc/reference/crecordset-class.md) para determinar se o driver suporta transações para um determinado banco de dados. Observe `CanTransact` que não diz se a fonte de dados fornece suporte total à transação. Você também `CDatabase::GetCursorCommitBehavior` deve `CDatabase::GetCursorRollbackBehavior` `CommitTrans` ligar `Rollback` e depois e verificar o `CRecordset` efeito da transação no objeto aberto.

As chamadas `AddNew` `Edit` para as funções e membros de um `CRecordset` `Update`objeto afetam imediatamente a fonte de dados quando você chama . `Delete`as chamadas também fazem efeito imediatamente. Em contraste, você pode usar uma transação `Update`que `Delete`consiste em várias chamadas para `CommitTrans` `AddNew`, `Edit`e , que são realizadas, mas não comprometidas até que você ligue explicitamente. Ao estabelecer uma transação, você pode executar uma série de chamadas desse tipo, mantendo a capacidade de revertê-las. Se um recurso crítico não estiver disponível ou alguma outra condição impedir que toda a transação seja concluída, você poderá reverter a transação em vez de cometê-la. Nesse caso, nenhuma das alterações pertencentes à transação afeta a fonte de dados.

> [!NOTE]
> Atualmente, `CRecordset` a classe não suporta atualizações para a fonte de dados se você tiver implementado a busca em linha em massa. Isso significa que você `AddNew` `Edit`não `Delete`pode `Update`fazer chamadas para, ou . No entanto, você pode escrever suas próprias funções para executar atualizações e, em seguida, chamar essas funções dentro de uma determinada transação. Para obter mais informações sobre a busca de linhas em massa, consulte [Recordset: Fetching Records in Bulk (ODBC)](../../data/odbc/recordset-fetching-records-in-bulk-odbc.md).

> [!NOTE]
> Além de afetar o seu conjunto de registros, as transações afetam as instruções SQL que você executa diretamente desde que você use o ODBC **HDBC** associado ao seu `CDatabase` objeto ou um ODBC **HSTMT** baseado nesse **HDBC**.

As transações são particularmente úteis quando você tem vários registros que devem ser atualizados simultaneamente. Neste caso, você deseja evitar uma transação semi-concluída, como pode acontecer se uma exceção foi lançada antes da última atualização ser feita. O agrupamento dessas atualizações em uma transação permite uma recuperação (reversão) das alterações e retorna os registros para o estado de pré-transação. Por exemplo, se um banco transfere dinheiro da conta A para a conta B, tanto o saque de A quanto o depósito para B devem ter sucesso para processar os fundos corretamente ou toda a transação deve falhar.

Nas classes de banco de `CDatabase` dados, você realiza transações através de objetos. Um `CDatabase` objeto representa uma conexão com uma fonte de dados, e um ou mais conjuntos de registros associados a esse `CDatabase` objeto operam em tabelas do banco de dados através de funções de membro do conjunto de registros.

> [!NOTE]
> Apenas um nível de transações é suportado. Você não pode fazer transações nest nem uma transação pode abranger vários objetos de banco de dados.

Os seguintes tópicos fornecem mais informações sobre como as transações são realizadas:

- [Transação: realizando uma transação em um conjunto de registros (ODBC)](../../data/odbc/transaction-performing-a-transaction-in-a-recordset-odbc.md)

- [Transação: como as transações afetam atualizações (ODBC)](../../data/odbc/transaction-how-transactions-affect-updates-odbc.md)

## <a name="see-also"></a>Confira também

[Conectividade de banco de dados aberto (ODBC)](../../data/odbc/open-database-connectivity-odbc.md)
