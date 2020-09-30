---
title: Erro do compilador C3370
ms.date: 11/04/2016
f1_keywords:
- C3370
helpviewer_keywords:
- C3370
ms.assetid: ee6d4c85-78fc-42b2-836e-5cc491a3b2ba
ms.openlocfilehash: 4200cb7840899ad7b3719e949138010bd478ea3f
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91503184"
---
# <a name="compiler-error-c3370"></a>Erro do compilador C3370

' idl_module Name ': idl_module ainda não definido

Antes de poder usar [idl_module](../../windows/attributes/idl-module.md) para especificar um ponto de entrada em uma dll, você deve primeiro usar `idl_module` para especificar o nome da dll.

O exemplo a seguir gera C3370:

```cpp
// C3370.cpp
[module(name=MyLibrary)];
// uncomment the following line to resolve the error
// [idl_module(name="name1", dllname=x.dll)];
[idl_module(name="name1"), entry(100)] // C3370
int f1();

int main()
{
}
```
