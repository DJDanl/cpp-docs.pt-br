---
title: Erro do compilador C2891 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2891
dev_langs:
- C++
helpviewer_keywords:
- C2891
ms.assetid: e12cfb2d-df45-4b0d-b155-c51d17e812fa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 86d81662cb02fa3c8f6af75009daf4dab9b70196
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46016553"
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