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
ms.openlocfilehash: 54529bed25fc60815f80ea8660bcf5786cb2887c
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45700669"
---
# <a name="overloading-unary-operators"></a>Operadores unários de sobrecarga
Os operadores unários que podem ser sobrecarregados são os seguintes:  
  
1.  `!` ([NOT lógico](../cpp/logical-negation-operator-exclpt.md))  
  
2.  `&` ([endereço de](../cpp/address-of-operator-amp.md))  
  
3.  `~` ([2&gt;complemento de um&lt;2](../cpp/one-s-complement-operator-tilde.md))  
  
4.  `*` ([desreferência de ponteiro](../cpp/indirection-operator-star.md))  
  
5.  `+` ([adição unária](../cpp/additive-operators-plus-and.md))  
  
6.  `-` ([negação unária](../cpp/additive-operators-plus-and.md))  
  
7.  `++` ([incremento](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md))  
  
8.  `--` ([decrementar](../cpp/prefix-increment-and-decrement-operators-increment-and-decrement.md))  
  
9. operadores de conversão  
  
 O incremento de sufixo e operadores de decremento (`++` e `--`) são tratados separadamente em [incremento e decréscimo](../cpp/increment-and-decrement-operator-overloading-cpp.md).  
  
 Operadores de conversão também são abordados em um tópico separado; ver [conversões de tipo definidas pelo usuário](../cpp/user-defined-type-conversions-cpp.md).  
  
 As regras a seguir são verdadeiras para todos os outros operadores unários. Para declarar uma função de operador unário como um membro não estático, você deve declará-la na forma:  
  
> *RET-type* **operador** *op* **)**  
  
 em que *ret-type* é o tipo de retorno e *op* é um dos operadores listado na tabela anterior.  
  
 Para declarar uma função de operador unário como uma função global, você deve declará-la na forma:  
  
> *RET-type* **operador** *op* **(** *arg* **)**  
  
 em que *ret-type* e *op* são descritos para funções de operador de membro e o *arg* é um argumento de tipo de classe no qual operar.  
  
> [!NOTE]
>  Não há nenhuma restrição quanto aos tipos de retorno dos operadores unários. Por exemplo, faz sentido para NOT lógico (`!`) retornar um valor integral, mas isso não é imposto.  
  
## <a name="see-also"></a>Consulte também  
 [Sobrecarga de Operador](../cpp/operator-overloading.md)