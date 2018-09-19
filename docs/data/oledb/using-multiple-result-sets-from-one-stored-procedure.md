---
title: Usar vários conjuntos de resultados de um procedimento armazenado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- stored procedures, returning result sets
- multiple result sets
ms.assetid: c450c12c-a76c-4ae4-9675-071a41eeac05
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3e75a100bb5b56b613419160a3ea063bce42bbdb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092317"
---
# <a name="using-multiple-result-sets-from-one-stored-procedure"></a>Usando vários conjuntos de resultados a partir de um procedimento armazenado

Mais procedimentos armazenados retornam vários conjuntos de resultados. Tal procedimento armazenado geralmente inclui um ou mais instruções select. O consumidor precisa considerar isso ao lidar com todos os conjuntos de resultados.  
  
### <a name="to-handle-multiple-result-sets"></a>Para lidar com resultados múltiplos define  
  
1. Criar uma `CCommand` classe com `CMultipleResults` como um argumento de modelo e com o acessador de sua escolha. Geralmente, isso é um acessador dinâmico ou manual. Se você usar outro tipo de acessador, você não poderá determinar as colunas de saída para cada conjunto de linhas.  
  
1. Execute o procedimento armazenado como de costume e associar as colunas (veja [como faço para buscar dados?](../../data/oledb/fetching-data.md)).  
  
1. Use os dados.  
  
1. Chame `GetNextResult` sobre o `CCommand` classe. Se outro conjunto de linhas de resultado estiver disponível, `GetNextResult` Retorna S_OK e você deverá associar novamente suas colunas se você estiver usando um acessador manual. Se `GetNextResult` retornará um erro, há nenhum resultado adicional conjuntos disponível.  
  
## <a name="see-also"></a>Consulte também  

[Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)