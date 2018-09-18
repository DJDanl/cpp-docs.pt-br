---
title: Erro do compilador C2292 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2292
dev_langs:
- C++
helpviewer_keywords:
- C2292
ms.assetid: 256b392f-2b8f-4162-b578-e7633984e162
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a075b198f615e9b7d98577910f0866b9096fed79
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46041240"
---
# <a name="compiler-error-c2292"></a>Erro do compilador C2292

'identifier': melhor caso, a representação de herança: 'representation1' declarado mas 'representation2' necessária

Compilando o código a seguir com [/vmb](../../build/reference/vmb-vmg-representation-method.md) ("mais favorável sempre" representação) faz com que o C2292.

```
// C2292.cpp
// compile with: /vmb
class __single_inheritance X;

struct A { };
struct B { };
struct X : A, B { };  // C2292, X uses multiple inheritance
```