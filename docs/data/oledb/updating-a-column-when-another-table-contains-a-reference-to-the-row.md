---
title: Atualizar uma coluna quando outra tabela contém uma referência para a linha
ms.date: 10/24/2018
helpviewer_keywords:
- rowsets, column updates
ms.assetid: abb5db69-055d-431f-b12d-ad2940a661ba
ms.openlocfilehash: 46de5f54a3ec6525f779a6b55a700429a2a84fef
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389067"
---
# <a name="updating-a-column-when-another-table-contains-a-reference-to-the-row"></a>Atualizando uma coluna quando outra tabela contém uma referência para a linha

Alguns provedores podem detectar quais colunas na linha alterada, mas não de muitos provedores. Como resultado, atualizando uma coluna pode resultar em um erro quando há uma referência para a linha que você está tentando atualizar. Para resolver esse problema, crie um acessador separado mantendo apenas as colunas que você deseja alterar. Passe o número desse acessador para `SetData`.

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)