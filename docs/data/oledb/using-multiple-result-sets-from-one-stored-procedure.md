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
ms.openlocfilehash: 6393901839e8450ebc45b11f1d4bd2250da2ca56
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="using-multiple-result-sets-from-one-stored-procedure"></a>Usando vários conjuntos de resultados a partir de um procedimento armazenado
Mais procedimentos armazenados retornam vários conjuntos de resultados. Tal procedimento armazenado geralmente inclui um ou mais instruções select. O consumidor deve considerar isso para lidar com todos os conjuntos de resultados.  
  
### <a name="to-handle-multiple-result-sets"></a>Para lidar com resultados múltiplos define  
  
1.  Criar um `CCommand` classe com `CMultipleResults` como um argumento de template e com o acessador de sua escolha. Geralmente, isso é um acessador dinâmico ou manual. Se você usar outro tipo de acessador, você não poderá determinar as colunas de saída para cada conjunto de linhas.  
  
2.  Execute o procedimento armazenado como de costume e associar as colunas (consulte [como fazer busca de dados?](../../data/oledb/fetching-data.md)).  
  
3.  Use os dados.  
  
4.  Chamar `GetNextResult` no `CCommand` classe. Se outro conjunto de linhas de resultado estiver disponível, `GetNextResult` Retorna S_OK e você deve associar novamente as colunas se você estiver usando um acessador manual. Se `GetNextResult` retorna um erro, não há nenhum resultado mais conjuntos disponível.  
  
## <a name="see-also"></a>Consulte também  
 [Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)