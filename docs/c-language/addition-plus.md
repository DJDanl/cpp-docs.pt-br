---
title: "Adição (+) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- pointers, adding integers
ms.assetid: b9014fee-825d-46ef-91db-5d46807081fc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d41fe0369235bbdaf6723d01fdaf4bbf552a9ea5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="addition-"></a>Adição (+)
O operador de adição (**+**) faz com que dois operandos sejam somados. Ambos os operandos podem ser do tipo integral ou flutuante, ou um operando pode ser um ponteiro e o outro um inteiro.  
  
 Quando um inteiro é adicionado a um ponteiro, o valor do inteiro (*i*) é convertido ao multiplicá-lo pelo tamanho do valor que o ponteiro indica. Após a conversão, o valor de inteiro representa as posições de memória *i*, no qual cada posição tem o comprimento especificado pelo tipo de ponteiro. Quando o valor do inteiro convertido é somado ao valor do ponteiro, o resultado é um novo valor de ponteiro que representa as posições do endereço *i* do endereço original. O novo valor de ponteiro indica um valor do mesmo tipo que o valor do ponteiro original e, portanto, é o mesmo que a indexação de matriz (consulte [Matrizes unidimensionais](../c-language/one-dimensional-arrays.md) e [Matrizes multidimensionais](../c-language/multidimensional-arrays-c.md)). Se o ponteiro da soma apontar para fora da matriz, exceto no primeiro local após a extremidade, o resultado será indefinido. Para obter mais informações, consulte o tópico sobre [aritmética de ponteiros](../c-language/pointer-arithmetic.md).  
  
## <a name="see-also"></a>Consulte também  
 [Operadores aditivos C](../c-language/c-additive-operators.md)