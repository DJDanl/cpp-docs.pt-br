---
title: Erro do compilador C2728 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2728
dev_langs:
- C++
helpviewer_keywords:
- C2728
ms.assetid: 65635f91-1cd1-46e4-9ad7-14726d0546af
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fe901a5798028378e6d84a807826b42cae0d64d8
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46036157"
---
# <a name="compiler-error-c2728"></a>Erro do compilador C2728

'type': uma matriz nativa não pode conter este tipo

Sintaxe de criação de matriz foi usado para criar uma matriz de gerenciadas ou objetos do WinRT. Você não pode criar uma matriz de gerenciadas ou objetos do WinRT usando a sintaxe de matriz nativa.

Para obter mais informações, consulte [matriz](../../windows/arrays-cpp-component-extensions.md).

O exemplo a seguir gera C2728 e mostra como corrigi-lo:

```
// C2728.cpp
// compile with: /clr

int main() {
   int^ arr[5];   // C2728

   // try the following line instead
   array<int>^arr2;
}
```
