---
title: Erro do compilador C3231 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3231
dev_langs:
- C++
helpviewer_keywords:
- C3231
ms.assetid: fe5dc352-e634-45fa-9534-3da176294c98
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 57727fbd71314201ec76119d37ab9c73b01d471d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46097298"
---
# <a name="compiler-error-c3231"></a>Erro do compilador C3231

'arg': argumento de tipo de modelo não é possível usar um parâmetro de tipo genérico

Modelos são instanciados em tempo de compilação, mas os genéricos são instanciados em tempo de execução. Portanto, não é possível gerar código genérico que pode chamar o modelo porque o modelo não pode ser instanciado em tempo de execução quando o tipo genérico, por fim, é conhecido.

O exemplo a seguir gera C3231:

```
// C3231.cpp
// compile with: /clr /LD
template <class T> class A;

generic <class T>
ref class C {
   void f() {
      A<T> a;   // C3231
   }
};
```