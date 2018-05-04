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
ms.openlocfilehash: 9bba312c6969acf95be8899f58f65e31c75386c4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="interpretation-of-subscript-operator"></a>Interpretação do operador subscrito
Como outros operadores, o operador de subscrito (**[]**) pode ser redefinido pelo usuário. O comportamento padrão do operador subscrito, se não sobrecarregado, é combinar o nome da matriz e o subscrito usando o seguinte método:  
  
 \*((*nome de matriz*) + (*subscrito*))  
  
 Como em qualquer adição que envolve tipos do ponteiro, o dimensionamento é executado automaticamente para se ajustar ao tamanho do tipo. Portanto, o valor resultante não é *subscrito* bytes da origem de *nome de matriz*; em vez disso, é o *subscrito*elemento th da matriz. (Para obter mais informações sobre essa conversão, consulte [operadores aditivos](../cpp/additive-operators-plus-and.md).)  
  
 De maneira semelhante, para matrizes multidimensionais, o endereço é derivado usando o seguinte método:  
  
 **((**   
 ***nome da matriz* ) + (**   
 ***subscrito* 1***max*2  *\* max*3 *. .max*n) **+** *subscrito*2  *\* max*3 *. .max*n).   . . *+* *subscrito*n))  
  
## <a name="see-also"></a>Consulte também  
 [Matrizes](../cpp/arrays-cpp.md)