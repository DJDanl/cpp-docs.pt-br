---
title: Aviso do compilador (nível 1) C4172
ms.date: 11/04/2016
f1_keywords:
- C4172
helpviewer_keywords:
- C4172
ms.assetid: a8d2bf65-d8b1-4fe3-8340-a223d7e7fde6
ms.openlocfilehash: 7258172c00b1ff4aebb18fa2c715559fd82a2180
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163540"
---
# <a name="compiler-warning-level-1-c4172"></a>Aviso do compilador (nível 1) C4172

retornando endereço de variável local ou temporária

Uma função retorna o endereço de uma variável local ou de um objeto temporário. Variáveis locais e objetos temporários são destruídos quando uma função retorna, de modo que o endereço retornado não é válido.

Reprojete a função para que ela não retorne o endereço de um objeto local.

O exemplo a seguir gera C4172:

```cpp
// C4172.cpp
// compile with: /W1 /LD
float f = 10;

const double& bar() {
// try the following line instead
// const float& bar() {
   return f;   // C4172
}
```
