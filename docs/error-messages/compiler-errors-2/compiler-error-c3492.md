---
title: Erro do compilador C3492
ms.date: 11/04/2016
f1_keywords:
- C3492
helpviewer_keywords:
- C3492
ms.assetid: b1dc6342-9133-4b1f-a9c3-e8c65d20d121
ms.openlocfilehash: bdaeb8797eb71b205f737d08e74430f161cb8caa
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686542"
---
# <a name="compiler-error-c3492"></a>Erro do compilador C3492

' var ': não é possível capturar um membro de uma União anônima

Você não pode capturar um membro de uma União sem nome.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Dê um nome à União e passe a estrutura de união completa para a lista de captura da expressão lambda.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C3492 porque ele captura um membro de uma União anônima:

```cpp
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

O exemplo a seguir resolve o C3492 fornecendo um nome de União e passando a estrutura de união completa para a lista de captura da expressão lambda:

```cpp
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

## <a name="see-also"></a>Confira também

[Expressões lambda](../../cpp/lambda-expressions-in-cpp.md)
