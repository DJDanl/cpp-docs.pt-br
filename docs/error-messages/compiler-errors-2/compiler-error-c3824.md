---
title: Erro do compilador C3824
ms.date: 11/04/2016
f1_keywords:
- C3824
helpviewer_keywords:
- C3824
ms.assetid: b6c6adf1-0a29-401c-a06e-616fd50d4c37
ms.openlocfilehash: 47363da66416c326755cad12fe4cfd448e3154e2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74741723"
---
# <a name="compiler-error-c3824"></a>Erro do compilador C3824

' member ': este tipo não pode aparecer neste contexto (parâmetro de função, tipo de retorno ou um membro estático)

Ponteiros de fixação não podem ser parâmetros de função, tipos de retorno ou `static`declarados.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3824:

```cpp
// C3824a.cpp
// compile with: /clr /c
void func() {
   static pin_ptr<int> a; // C3824
   pin_ptr<int> b; // OK
}
```
