---
title: Erro do compilador C2891
ms.date: 11/04/2016
f1_keywords:
- C2891
helpviewer_keywords:
- C2891
ms.assetid: e12cfb2d-df45-4b0d-b155-c51d17e812fa
ms.openlocfilehash: d9a1cdafdf7d3a2843aee4a20f71c7e6a4693150
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62366362"
---
# <a name="compiler-error-c2891"></a>Erro do compilador C2891

'parameter': não é possível obter o endereço de um parâmetro de modelo

É possível tomar o endereço de um parâmetro de modelo, a menos que ele é um lvalue. Parâmetros de tipo não são lvalues porque eles não possuem endereço. Valores sem tipo nas listas de parâmetro de modelo que não são l-Values também não tem um endereço. Este é um exemplo de código que faz com que o erro do compilador C2891, porque o valor passado como parâmetro de modelo é uma cópia gerado pelo compilador do argumento de modelo.

```
template <int i> int* f() { return &i; }
```

Parâmetros de modelo que são l-Values, como tipos de referência, pode ter seu endereço obtido.

```
template <int& r> int* f() { return &r; }
```

Para corrigir esse erro, não têm o endereço de um parâmetro de modelo, a menos que ele é um lvalue.