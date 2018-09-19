---
title: Erro do compilador C2019 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2019
dev_langs:
- C++
helpviewer_keywords:
- C2019
ms.assetid: 4f37b1e1-9eca-418f-a4c3-141e8512d7b6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e6f1ae1b22cca0d00e990f64ccaf469359563f8e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46038692"
---
# <a name="compiler-error-c2019"></a>Erro do compilador C2019

esperada diretiva de pré-processador, encontrado 'character'

O caractere seguido um `#` logon, mas isso não é a primeira letra de uma diretiva de pré-processador.

O exemplo a seguir gera C2019:

```
// C2019.cpp
#!define TRUE 1   // C2019
```

Solução possível:

```
// C2019b.cpp
// compile with: /c
#define TRUE 1
```