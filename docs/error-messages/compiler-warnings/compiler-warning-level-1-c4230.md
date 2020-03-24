---
title: Aviso do compilador (nível 1) C4230
ms.date: 11/04/2016
f1_keywords:
- C4230
helpviewer_keywords:
- C4230
ms.assetid: a4be8729-74b6-44df-a5ea-e3f45aad0f8f
ms.openlocfilehash: be402eed4474dd736ab237cfb5c7986741338eec
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80163265"
---
# <a name="compiler-warning-level-1-c4230"></a>Aviso do compilador (nível 1) C4230

anacronismo usado: modificadores/qualificadores intercalados; qualificador ignorado

Usar um qualificador antes de um modificador da Microsoft como `__cdecl` é uma prática desatualizada.

## <a name="example"></a>Exemplo

```cpp
// C4230.cpp
// compile with: /W1 /LD
int __cdecl const function1();   // C4230 const ignored
```
