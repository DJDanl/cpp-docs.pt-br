---
title: Erro do compilador C2014
ms.date: 11/04/2016
f1_keywords:
- C2014
helpviewer_keywords:
- C2014
ms.assetid: 231d8e9c-48c0-4027-99a3-245d186275ec
ms.openlocfilehash: 58cf9867a9e36b304ab9da79084bc01dff453892
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62350696"
---
# <a name="compiler-error-c2014"></a>Erro do compilador C2014

comando de pré-processador deve começar como primeiro caractere diferente de espaço

O `#` sinal de uma diretiva de pré-processador deve ser o primeiro caractere em uma linha que não seja espaço em branco.

O exemplo a seguir gera C2014:

```
// C2014.cpp
int k; #include <stdio.h>   // C2014
```

Solução possível:

```
// C2014b.cpp
// compile with: /c
int k;
#include <stdio.h>
```