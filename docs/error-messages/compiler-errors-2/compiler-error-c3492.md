---
title: Erro do compilador C3492
ms.date: 11/04/2016
f1_keywords:
- C3492
helpviewer_keywords:
- C3492
ms.assetid: b1dc6342-9133-4b1f-a9c3-e8c65d20d121
ms.openlocfilehash: facd8c78e775945924d77b09f9dc754bdc301ddd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62381118"
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