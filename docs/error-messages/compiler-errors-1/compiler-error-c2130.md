---
title: Erro do compilador C2130
ms.date: 11/04/2016
f1_keywords:
- C2130
helpviewer_keywords:
- C2130
ms.assetid: c6fd5a7e-8f28-4f67-99d1-95a13b0dff90
ms.openlocfilehash: aee0931926cad2ac30631c152aeb94bfd24befd2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50579728"
---
# <a name="compiler-error-c2130"></a>Erro do compilador C2130

\#linha esperada uma cadeia de caracteres que contém o nome do arquivo, encontrado 'token'

O seguinte token de nome de arquivo opcional [#line](../../preprocessor/hash-line-directive-c-cpp.md) `linenumber` deve ser uma cadeia de caracteres.

O exemplo a seguir gera C2130:

```
// C2130.cpp
int main() {
   #line 1000 test   // C2130
   #line 1000 "test"   // OK
}
```