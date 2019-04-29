---
title: Erro do compilador C2474
ms.date: 11/04/2016
f1_keywords:
- C2474
helpviewer_keywords:
- C2474
ms.assetid: 64e6c61e-6e77-480e-bcf0-b30a2fc482ac
ms.openlocfilehash: c49f38b828a41c72135ba9182d4d0f5eee4df1de
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62350878"
---
# <a name="compiler-error-c2474"></a>Erro do compilador C2474

'palavra-chave': faltando uma ponto e vírgula adjacente, poderia ser palavra-chave ou identificador.

O compilador espera encontrar um ponto e vírgula e não pôde determinar sua intenção. Adicione o ponto e vírgula para resolver esse erro.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2474.

```
// C2474.cpp
// compile with: /clr /c

ref class A {
   ref class B {}
   property int i;   // C2474 error
};

// OK
ref class B {
   ref class D {};
   property int i;
};

ref class E {
   ref class F {} property;
   int i;
};
```