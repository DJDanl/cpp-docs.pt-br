---
title: "Subtração (-) | Microsoft Docs"
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
- operators [C], subtraction
- subtraction operator, syntax
ms.assetid: 9cacba7d-20b3-4372-8a63-ba5d8ee64177
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
ms.translationtype: Human Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: 78723d67f5938f8c8e4cfd299a18de39da9787ab
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="subtraction--"></a>Subtração (-)
O operador de subtração (**-**) subtrai o segundo operando do primeiro. Ambos os operandos podem ser do tipo integral ou flutuante, ou um operando pode ser um ponteiro e o outro um inteiro.  
  
 Quando dois ponteiros são subtraídos, a diferença é convertida em um valor integral assinado dividindo a diferença pelo tamanho de um valor do tipo que os ponteiros indicam. O tamanho do valor integral é definido pelo tipo **ptrdiff_t** no arquivo STDDEF.H de inclusão padrão. O resultado representa o número de posições de memória desse tipo entre os dois endereços. O resultado é garantido somente para ser significativo para dois elementos da mesma matriz, como discutido em [Aritmética do ponteiro](../c-language/pointer-arithmetic.md).  
  
 Quando um valor inteiro é subtraído de um valor de ponteiro, o operador de subtração converte o valor do inteiro (*i*) multiplicando-o pelo tamanho do valor que o ponteiro indica. Após a conversão, o valor de inteiro representa as posições de memória *i*, no qual cada posição tem o comprimento especificado pelo tipo de ponteiro. Quando o valor do inteiro convertido é subtraído do valor do ponteiro, como resultado, o endereço de memória *i* se posiciona antes do endereço original. O novo ponteiro aponta para um valor do tipo indicado pelo valor do ponteiro original.  
  
## <a name="see-also"></a>Consulte também  
 [Operadores aditivos C](../c-language/c-additive-operators.md)
