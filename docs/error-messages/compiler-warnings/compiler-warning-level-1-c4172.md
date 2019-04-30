---
title: Compilador aviso (nível 1) C4172
ms.date: 11/04/2016
f1_keywords:
- C4172
helpviewer_keywords:
- C4172
ms.assetid: a8d2bf65-d8b1-4fe3-8340-a223d7e7fde6
ms.openlocfilehash: caa71da9182c1da1d17d87d901084d0ee9badf73
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391784"
---
# <a name="compiler-warning-level-1-c4172"></a>Compilador aviso (nível 1) C4172

retornando o endereço de variável local ou temporário

Uma função retorna o endereço de um objeto temporário ou variável local. Objetos temporários e variáveis locais são destruídos quando uma função retornar, portanto, o endereço retornado não é válido.

Recrie a função para que ela não retorna o endereço de um objeto local.

O exemplo a seguir gera C4172:

```
// C4172.cpp
// compile with: /W1 /LD
float f = 10;

const double& bar() {
// try the following line instead
// const float& bar() {
   return f;   // C4172
}
```