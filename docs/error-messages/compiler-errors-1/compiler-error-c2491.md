---
title: Erro do compilador C2491
ms.date: 11/04/2016
f1_keywords:
- C2491
helpviewer_keywords:
- C2491
ms.assetid: 4e5a8f81-124e-402c-a5ec-d35a89b5469e
ms.openlocfilehash: 3b48bebde6d7baedea73ed181cd4ea33adc44a69
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62361328"
---
# <a name="compiler-error-c2491"></a>Erro do compilador C2491

"identificador": definição da função dllimport não permitida

Dados, membros de dados estáticos e funções podem ser declarados como `dllimport`s, mas não definidos como `dllimport`s.

Para corrigir esse problema, remova o especificador `__declspec(dllimport)` da definição da função.

O seguinte exemplo gera C2491:

```
// C2491.cpp
// compile with: /c
// function definition
void __declspec(dllimport) funcB() {}   // C2491

// function declaration
void __declspec(dllimport) funcB();   // OK
```