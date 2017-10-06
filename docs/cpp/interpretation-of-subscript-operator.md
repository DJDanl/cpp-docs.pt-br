---
title: "Interpretação do operador subscrito | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- subscript operator [C++], interpretation of
- arrays [C++], subscripting
- interpreting subscript operators [C++]
- operators [C++], interpretation of subscript
ms.assetid: 8852ca18-9d5b-43f7-b8bd-abc89364fbf2
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 1a83ff6aea4380688d3b6298b93e04caab1dbb7f
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="interpretation-of-subscript-operator"></a>Interpretação do operador subscrito
Como outros operadores, o operador de subscrito (**[]**) pode ser redefinido pelo usuário. O comportamento padrão do operador subscrito, se não sobrecarregado, é combinar o nome da matriz e o subscrito usando o seguinte método:  
  
 \*((*nome de matriz*) + (*subscrito*))  
  
 Como em qualquer adição que envolve tipos do ponteiro, o dimensionamento é executado automaticamente para se ajustar ao tamanho do tipo. Portanto, o valor resultante não é *subscrito* bytes da origem de *nome de matriz*; em vez disso, é o *subscrito*elemento th da matriz. (Para obter mais informações sobre essa conversão, consulte [operadores aditivos](../cpp/additive-operators-plus-and.md).)  
  
 De maneira semelhante, para matrizes multidimensionais, o endereço é derivado usando o seguinte método:  
  
 **((**   
 ***nome da matriz* ) + (**   
 ***subscrito* 1***max*2 * \* max*3*. .max*n) ** + ** *subscrito*2 * \* max*3*. .max*n).   . . *+**subscrito*n))  
  
## <a name="see-also"></a>Consulte também  
 [Matrizes](../cpp/arrays-cpp.md)
