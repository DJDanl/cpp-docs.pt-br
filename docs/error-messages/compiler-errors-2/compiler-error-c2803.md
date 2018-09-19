---
title: Erro do compilador C2803 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2803
dev_langs:
- C++
helpviewer_keywords:
- C2803
ms.assetid: 2cdbe374-8cc4-4c4e-ba15-062a7479e937
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7885735ebad1ff90afaf4ba8eaf6dfca9f3e0ab3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46027031"
---
# <a name="compiler-error-c2803"></a>Erro do compilador C2803

'operator operador' deve ter pelo menos um parâmetro formal do tipo de classe

O operador sobrecarregado não tem um parâmetro de tipo de classe.

Você precisa passar pelo menos um parâmetro por referência (não usando ponteiros, mas as referências) ou por valor para ser capaz de gravar "um < b" (da classe de tipo A e b).

Se ambos os parâmetros forem ponteiros, ela será uma comparação pura de endereços de ponteiro e não usará a conversão definida pelo usuário.

O exemplo a seguir gera C2803:

```
// C2803.cpp
// compile with: /c
class A{};
bool operator< (const A *left, const A *right);   // C2803
// try the following line instead
// bool operator< (const A& left, const A& right);
```