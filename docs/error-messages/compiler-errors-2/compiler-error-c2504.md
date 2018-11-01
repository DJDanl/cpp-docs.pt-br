---
title: Erro do compilador C2504
ms.date: 11/04/2016
f1_keywords:
- C2504
helpviewer_keywords:
- C2504
ms.assetid: c9e002a6-a4ee-4ba7-970e-edf4adb83692
ms.openlocfilehash: 8f428699aa14cbd1f021a57ed8dcabefa8b24c16
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50444385"
---
# <a name="compiler-error-c2504"></a>Erro do compilador C2504

'class': classe base indefinida

A classe base é declarada mas nunca foi definida.  Possíveis causas:

1. Faltando o arquivo de inclusão.

1. Classe base externo não declarado com [extern](../../cpp/using-extern-to-specify-linkage.md).

O exemplo a seguir gera C2504:

```
// C2504.cpp
// compile with: /c
class A;
class B : public A {};   // C2504
```

OKEY

```
class C{};
class D : public C {};
```