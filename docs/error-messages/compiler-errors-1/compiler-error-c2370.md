---
title: Erro do compilador C2370
ms.date: 11/04/2016
f1_keywords:
- C2370
helpviewer_keywords:
- C2370
ms.assetid: 03403e8f-f393-47c4-bd25-5c1c7ea7d5cd
ms.openlocfilehash: 28c337a5cadfaeced39ee6ed73601338941029fc
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50471741"
---
# <a name="compiler-error-c2370"></a>Erro do compilador C2370

'identifier': redefinição; classe de armazenamento diferentes

O identificador já foi declarado com uma classe de armazenamento diferente.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2370:

```
// C2370.cpp
// compile with: /Za /c
extern int i;
static int i;   // C2370
int i;   // OK
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2370:

```
// C2370b.cpp
#define Thread __declspec( thread )
extern int tls_i;
int Thread tls_i;   // C2370 declaration and the definition differ
int tls_i;   // OK
```