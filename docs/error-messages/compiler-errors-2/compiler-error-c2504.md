---
title: Erro do compilador C2504
ms.date: 11/04/2016
f1_keywords:
- C2504
helpviewer_keywords:
- C2504
ms.assetid: c9e002a6-a4ee-4ba7-970e-edf4adb83692
ms.openlocfilehash: 8f428699aa14cbd1f021a57ed8dcabefa8b24c16
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62165080"
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

// OK

```
class C{};
class D : public C {};
```