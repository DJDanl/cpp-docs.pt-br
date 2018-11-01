---
title: Erro do compilador C3492
ms.date: 11/04/2016
f1_keywords:
- C3492
helpviewer_keywords:
- C3492
ms.assetid: b1dc6342-9133-4b1f-a9c3-e8c65d20d121
ms.openlocfilehash: 53dd22368aee5e0de9eca1349eb4d7dd3ed1c570
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50485001"
---
# <a name="compiler-error-c3492"></a>Erro do compilador C3492

'var': não é possível capturar um membro de uma união anônima

Não é possível capturar um membro de uma união sem nome.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Dê um nome de união e passar a estrutura de união completa para a lista de captura da expressão lambda.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3492 porque ele captura um membro de uma união anônima:

```
// C3492a.cpp

int main()
{
   union
   {
      char ch;
      int x;
   };

   ch = 'y';
   [&x](char ch) { x = ch; }(ch); // C3492
}
```

## <a name="example"></a>Exemplo

O exemplo a seguir resolve C3492 fornecendo um nome para a união e passando a estrutura de união completa para a lista de captura da expressão lambda:

```
// C3492b.cpp

int main()
{
   union
   {
      char ch;
      int x;
   } u;

   u.ch = 'y';
   [&u](char ch) { u.x = ch; }(u.ch);
}
```

## <a name="see-also"></a>Consulte também

[Expressões Lambda](../../cpp/lambda-expressions-in-cpp.md)