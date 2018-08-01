---
title: Interpretação do operador subscrito | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- subscript operator [C++], interpretation of
- arrays [C++], subscripting
- interpreting subscript operators [C++]
- operators [C++], interpretation of subscript
ms.assetid: 8852ca18-9d5b-43f7-b8bd-abc89364fbf2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 75659730198e09a172625c54bfcbdd54b7a9f857
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39404782"
---
# <a name="interpretation-of-subscript-operator"></a>Interpretação do operador subscrito
Como outros operadores, o operador subscrito (**[]**) pode ser redefinido pelo usuário. O comportamento padrão do operador subscrito, se não sobrecarregado, é combinar o nome da matriz e o subscrito usando o seguinte método:  
  
 \*((*nome da matriz*) + (*subscrito*))  
  
 Como em qualquer adição que envolve tipos do ponteiro, o dimensionamento é executado automaticamente para se ajustar ao tamanho do tipo. Portanto, o valor resultante não é *subscrito* bytes de origem de *nome da matriz*; em vez disso, é o *subscrito*º elemento da matriz. (Para obter mais informações sobre essa conversão, consulte [operadores aditivos](../cpp/additive-operators-plus-and.md).)  
  
 De maneira semelhante, para matrizes multidimensionais, o endereço é derivado usando o seguinte método:  
  
 **((**   
 ***nome da matriz* ) + (**   
 ***subscrito* 1***max*2  *\* max*3 *... max*n) **+** *subscrito*2  *\* máx*3 *... max*n).   . . *+* *subscrito*n))  
  
## <a name="see-also"></a>Consulte também  
 [Matrizes](../cpp/arrays-cpp.md)