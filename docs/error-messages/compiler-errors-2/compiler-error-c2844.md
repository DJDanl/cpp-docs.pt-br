---
title: Erro do compilador C2844
ms.date: 11/04/2016
f1_keywords:
- C2844
helpviewer_keywords:
- C2844
ms.assetid: dcaf4cd2-21b0-4280-ae42-0a706c524d83
ms.openlocfilehash: 8af9f42be279f728f72fc6968aeba98ee5d2474a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462706"
---
# <a name="compiler-error-c2844"></a>Erro do compilador C2844

'member': não pode ser um membro de interface 'interface'

Uma [classe de interface](../../windows/interface-class-cpp-component-extensions.md) não pode conter um membro de dados, a menos que também é uma propriedade.

Algo diferente de uma propriedade ou função de membro não é permitido em uma interface. Além disso, operadores, construtores e destruidores não são permitidas.

O exemplo a seguir gera C2844:

```
// C2844a.cpp
// compile with: /clr /c
public interface class IFace {
   int i;   // C2844
   // try the following line instead
   // property int Size;
};
```
