---
title: Atualizar uma coluna quando outra tabela contém uma referência para a linha
ms.date: 10/24/2018
helpviewer_keywords:
- rowsets, column updates
ms.assetid: abb5db69-055d-431f-b12d-ad2940a661ba
ms.openlocfilehash: 2adca735558033aa9324f37b5a61385b5f48096c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519880"
---
# <a name="updating-a-column-when-another-table-contains-a-reference-to-the-row"></a>Atualizando uma coluna quando outra tabela contém uma referência para a linha

Alguns provedores podem detectar quais colunas na linha alterada, mas não de muitos provedores. Como resultado, atualizando uma coluna pode resultar em um erro quando há uma referência para a linha que você está tentando atualizar. Para resolver esse problema, crie um acessador separado mantendo apenas as colunas que você deseja alterar. Passe o número desse acessador para `SetData`.

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)