---
title: Erro do compilador C3369
ms.date: 11/04/2016
f1_keywords:
- C3369
helpviewer_keywords:
- C3369
ms.assetid: c6ceb9cb-3df9-4334-9a5c-d16db351d476
ms.openlocfilehash: 3b2e6f38e93514154b20e674139a2d771dcf586e
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91503233"
---
# <a name="compiler-error-c3369"></a>Erro do compilador C3369

' nome do módulo ': idl_module já definido

O uso de [idl_module](../../windows/attributes/idl-module.md) onde você define a DLL só pode ocorrer uma vez em um programa.

O exemplo a seguir gera C3369:

```cpp
// C3369.cpp
// compile with: /c
[idl_module(name="name1", dllname="x.dll")]; // C3369
[idl_module(name="name1", dllname="x.dll")];
```
