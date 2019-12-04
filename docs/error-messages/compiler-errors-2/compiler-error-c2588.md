---
title: Erro do compilador C2588
ms.date: 11/04/2016
f1_keywords:
- C2588
helpviewer_keywords:
- C2588
ms.assetid: 19a0cabd-ca13-44a5-9be3-ee676abf9bc4
ms.openlocfilehash: f1f73e2585606e7e86213607a96ef713345419c1
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74755402"
---
# <a name="compiler-error-c2588"></a>Erro do compilador C2588

':: ~ identificador ': destruidor global inválido

O destruidor é definido para algo diferente de uma classe, estrutura ou União. Isso não é permitido.

Esse erro pode ser causado por um nome de classe, estrutura ou União ausente no lado esquerdo do operador de resolução de escopo (`::`).

O exemplo a seguir gera C2588:

```cpp
// C2588.cpp
~F();   // C2588
```
