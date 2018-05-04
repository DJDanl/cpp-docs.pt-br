---
title: Operadores unários de sobrecarga | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- unary operators [C++], plus
- increment operators [C++], overloaded
- unary operators [C++], minus
- operators [C++], unary
- redefinable unary operators [C++]
- unary operators [C++]
- pointer dereference operator overloading
- plus operator
ms.assetid: 7683ef08-42a4-4283-928f-d3dd4f3ab4c0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d7f242fac0d81c6d46c2d810bf07459fde2fb2ae
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="overloading-unary-operators"></a>Operadores unários de sobrecarga
Os operadores unários que podem ser sobrecarregados são os seguintes:  
  
1.  `!` ([NOT lógico](../cpp/logical-negation-operator-exclpt.md))  
  
2.  `&` ([endereço de](../cpp/address-of-operator-amp.md))  
  
3.  `~` ([complemento de um](../cpp/one-s-complement-operator-tilde.md))  
  
4.  `*` ([desreferenciamento do ponteiro](../cpp/indirection-operator-star.md))  
  
5.  `+` ([adição unária](../cpp/additive-operators-plus-and.md))  
  
6.  `-` ([negação unário](../cpp/additive-operators-plus-and.md))  
  
7.  `++` ([incremento](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md))  
  
8.  `--` ([decrementar](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md))  
  
9. operadores de conversão  
  
 Os operadores de incremento e de operadores de decremento (`++` e **--**) são tratados separadamente no [incrementar e decrementar](../cpp/increment-and-decrement-operator-overloading-cpp.md).  
  
 Operadores de conversão também são discutidos em um tópico separado; consulte [conversões de tipo definido pelo usuário](../cpp/user-defined-type-conversions-cpp.md).  
  
 As regras a seguir são verdadeiras para todos os outros operadores unários. Para declarar uma função de operador unário como um membro não estático, você deve declará-la na forma:  
  
 `ret-type operator``op``()`  
  
 em que `ret-type` é o tipo de retorno e `op` é um dos operadores listados na tabela anterior.  
  
 Para declarar uma função de operador unário como uma função global, você deve declará-la na forma:  
  
 `ret-type operator` `op` (`arg` )  
  
 em que `ret-type` e `op` são conforme descritos para funções de operador de membro e `arg` é um argumento do tipo de classe no qual operar.  
  
> [!NOTE]
>  Não há nenhuma restrição quanto aos tipos de retorno dos operadores unários. Por exemplo, faz sentido para NOT lógico (`!`) retornar um valor integral, mas isso não é imposto.  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)