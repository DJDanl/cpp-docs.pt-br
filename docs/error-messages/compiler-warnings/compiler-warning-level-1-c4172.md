---
title: Compilador aviso (nível 1) C4172 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4172
dev_langs:
- C++
helpviewer_keywords:
- C4172
ms.assetid: a8d2bf65-d8b1-4fe3-8340-a223d7e7fde6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 56f606b48fb060472dd67d34800c06946bc41712
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46043502"
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