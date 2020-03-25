---
title: Erro do compilador C2891
ms.date: 11/04/2016
f1_keywords:
- C2891
helpviewer_keywords:
- C2891
ms.assetid: e12cfb2d-df45-4b0d-b155-c51d17e812fa
ms.openlocfilehash: 2544cfc9e8cff283a7c3e0ace499408bb84cd046
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201624"
---
# <a name="compiler-error-c2891"></a>Erro do compilador C2891

' Parameter ': não é possível obter o endereço de um parâmetro de template

Você não pode obter o endereço de um parâmetro de modelo, a menos que seja um lvalue. Parâmetros de tipo não são lvalues porque não têm endereço. Valores não tipo em listas de parâmetros de modelo que não são lvalue também não têm um endereço. Este é um exemplo de código que causa o erro do compilador C2891, pois o valor passado como parâmetro de modelo é uma cópia gerada pelo compilador do argumento de modelo.

```
template <int i> int* f() { return &i; }
```

Os parâmetros de modelo que são lvalue, como tipos de referência, podem ter seu endereço obtido.

```
template <int& r> int* f() { return &r; }
```

Para corrigir esse erro, não assuma o endereço de um parâmetro de modelo, a menos que seja um lvalue.
