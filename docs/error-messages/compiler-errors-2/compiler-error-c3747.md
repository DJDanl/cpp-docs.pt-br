---
title: Erro do compilador C3747 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3747
dev_langs:
- C++
helpviewer_keywords:
- C3747
ms.assetid: a9a4be67-5d9c-4dcc-9ae9-baae46cbecde
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f1f657e6d3f64a4d8a2244ab2927a9a712c14b1a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091667"
---
# <a name="compiler-error-c3747"></a>Erro do compilador C3747

parâmetro de tipo padrão ausente: parâmetro param

Parâmetros de modelo ou genérico com valores padrão não podem ser seguidos na lista de parâmetros parâmetros que não têm valores padrão.

O exemplo a seguir gera C3747:

```
// C3747.cpp
template <class T1 = int, class T2>   // C3747
struct MyStruct {};
```

Solução possível:

```
// C3747b.cpp
// compile with: /c
template <class T1, class T2 = int>
struct MyStruct {};
```