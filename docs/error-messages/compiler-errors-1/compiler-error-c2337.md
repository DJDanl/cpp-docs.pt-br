---
title: Erro do compilador C2337
ms.date: 09/19/2019
f1_keywords:
- C2337
helpviewer_keywords:
- C2337
ms.assetid: eccc9178-a15e-42cd-bbd0-3cea7cf2d55b
ms.openlocfilehash: bf9b3e782804add13aeaef0e6672d2dd66d193be
ms.sourcegitcommit: f907b15f50a6b945d0b87c03af0050946157d701
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/20/2019
ms.locfileid: "71158768"
---
# <a name="compiler-error-c2337"></a>Erro do compilador C2337

> '*Attribute-Name*': atributo não encontrado

Seu código usa um atributo que não tem suporte neste contexto. Ou, o atributo não está disponível nesta versão do compilador. Para resolver esse problema, remova o atributo sem suporte.

O exemplo a seguir gera C2337:

```cpp
// C2337.cpp
// compile with: /c
[emitidl];
[module(name="x")];
[grasshopper]   // C2337, not a supported attribute
class a{};
```
