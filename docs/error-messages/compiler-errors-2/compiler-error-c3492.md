---
title: Erro do compilador C3492 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3492
dev_langs:
- C++
helpviewer_keywords:
- C3492
ms.assetid: b1dc6342-9133-4b1f-a9c3-e8c65d20d121
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 54b3689a6ee565788e2a469a8321727a9fdd822f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46089210"
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