---
title: 'TN047: relaxando requisitos de transação de banco de dados'
ms.date: 11/04/2016
f1_keywords:
- vc.data
helpviewer_keywords:
- TN047
ms.assetid: f93c51cf-a8c0-43d0-aa47-7bcb8333d693
ms.openlocfilehash: d609576c5ffda1a3ba8021e6a459943092c40e98
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50658829"
---
# <a name="tn047-relaxing-database-transaction-requirements"></a>TN047: relaxando requisitos de transação de banco de dados

Esta Observação técnica, que abordados os requisitos de transação das classes de banco de dados ODBC do MFC, agora é obsoleta. Antes de MFC 4.2, as classes de banco de dados necessários que cursores seja preservado em conjuntos de registros após um **CommitTrans** ou **reversão** operação. Se o driver ODBC e o DBMS não oferecia suporte a esse nível de preservação de cursor, as classes de banco de dados não habilitou as transações.

Começando com o 4.2 do MFC, as classes de banco de dados têm relaxada a restrição da exigência de preservação de cursor. Transações serão habilitadas se o driver oferece suporte a eles. No entanto, agora você deve verificar o efeito de uma **CommitTrans** ou **reversão** operação em conjuntos de registros abertos. Consulte as funções de membro [CDatabase::GetCursorCommitBehavior](../mfc/reference/cdatabase-class.md#getcursorcommitbehavior) e [CDatabase::GetCursorRollbackBehavior](../mfc/reference/cdatabase-class.md#getcursorrollbackbehavior) para obter mais informações.

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

