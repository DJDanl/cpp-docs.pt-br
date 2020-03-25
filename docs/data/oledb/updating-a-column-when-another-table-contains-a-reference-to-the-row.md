---
title: Atualizar uma coluna quando outra tabela contiver uma referência à linha
ms.date: 10/24/2018
helpviewer_keywords:
- rowsets, column updates
ms.assetid: abb5db69-055d-431f-b12d-ad2940a661ba
ms.openlocfilehash: 95cddfd5f030c7bd8d1220cf040de4bc5a883226
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209476"
---
# <a name="updating-a-column-when-another-table-contains-a-reference-to-the-row"></a>Atualizando uma coluna quando outra tabela contém uma referência para a linha

Alguns provedores podem detectar quais colunas na linha são alteradas, mas muitos provedores não podem. Como resultado, a atualização de uma coluna pode resultar em um erro quando há uma referência à linha que você está tentando atualizar. Para resolver esse problema, crie um acessador separado, mantendo apenas as colunas que você deseja alterar. Passe o número desse acessador para `SetData`.

## <a name="see-also"></a>Confira também

[Usando acessadores](../../data/oledb/using-accessors.md)
