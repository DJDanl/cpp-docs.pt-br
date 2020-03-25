---
title: Erro do compilador C3398
ms.date: 11/04/2016
f1_keywords:
- C3398
helpviewer_keywords:
- C3398
ms.assetid: 26f8c8a4-526f-415b-8047-155c5cd4f180
ms.openlocfilehash: f76515d58f020b414e6b79a7737463af80bd2d07
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80200805"
---
# <a name="compiler-error-c3398"></a>Erro do compilador C3398

' operator ': não é possível converter de ' function_signature ' em ' function_pointer '. A expressão de origem deve ser um símbolo de função

Quando a Convenção de chamada de [__clrcall](../../cpp/clrcall.md) não é especificada durante a compilação com **/CLR**, o compilador gera dois pontos de entrada (endereços) para cada função, um ponto de entrada nativo e um ponto de entrada gerenciado.

Por padrão, o compilador retorna o ponto de entrada nativo, mas há alguns casos em que o ponto de entrada gerenciado é desejado (por exemplo, ao atribuir o endereço a um ponteiro de função `__clrcall`). Para que o compilador escolha o ponto de entrada gerenciado de forma confiável em uma atribuição, o lado direito deve ser um símbolo de função.
