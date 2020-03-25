---
title: Usando vários conjuntos de resultados a partir de um procedimento armazenado
ms.date: 10/24/2018
helpviewer_keywords:
- stored procedures, returning result sets
- multiple result sets
ms.assetid: c450c12c-a76c-4ae4-9675-071a41eeac05
ms.openlocfilehash: 6163eb8bf18edfc3d205f1d012de0c64c5570693
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209281"
---
# <a name="using-multiple-result-sets-from-one-stored-procedure"></a>Usando vários conjuntos de resultados a partir de um procedimento armazenado

A maioria dos procedimentos armazenados retorna vários conjuntos de resultados. Esse procedimento armazenado geralmente inclui uma ou mais instruções SELECT. O consumidor precisa considerar essa inclusão para lidar com todos os conjuntos de resultados.

## <a name="to-handle-multiple-result-sets"></a>Para lidar com vários conjuntos de resultados

1. Crie uma classe de `CCommand` com `CMultipleResults` como um argumento de modelo e com o acessador de sua escolha, geralmente um acessador dinâmico ou manual. Se você usar outro tipo de acessador, talvez não seja possível determinar as colunas de saída para cada conjunto de linhas.

1. Execute o procedimento armazenado como de costume e associe as colunas (consulte [como faço para buscar dados?](../../data/oledb/fetching-data.md)).

1. Use os dados.

1. Chame `GetNextResult` na classe `CCommand`. Se outro conjunto de linhas de resultado estiver disponível, `GetNextResult` retornará S_OK e você deverá reassociar suas colunas se estiver usando um acessador manual. Se `GetNextResult` retornar um erro, não haverá mais conjuntos de resultados disponíveis.

## <a name="see-also"></a>Confira também

[Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)
