---
title: Erro do compilador C2844
ms.date: 11/04/2016
f1_keywords:
- C2844
helpviewer_keywords:
- C2844
ms.assetid: dcaf4cd2-21b0-4280-ae42-0a706c524d83
ms.openlocfilehash: fdfd2200503f80addb120117ce06f5f837d6b9f2
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74752009"
---
# <a name="compiler-error-c2844"></a>Erro do compilador C2844

' member ': não pode ser um membro da interface ' interface '

Uma [classe de interface](../../extensions/interface-class-cpp-component-extensions.md) não pode conter um membro de dados, a menos que também seja uma propriedade.

Qualquer coisa diferente de uma propriedade ou função membro não é permitida em uma interface. Além disso, construtores, destruidores e operadores não são permitidos.

O exemplo a seguir gera C2844:

```cpp
// C2844a.cpp
// compile with: /clr /c
public interface class IFace {
   int i;   // C2844
   // try the following line instead
   // property int Size;
};
```
