---
title: Compilador aviso (nível 1) C4230 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4230
dev_langs:
- C++
helpviewer_keywords:
- C4230
ms.assetid: a4be8729-74b6-44df-a5ea-e3f45aad0f8f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fb091b6cffe0bc049e7501fb006b1c84d9e0f6d2
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46112480"
---
# <a name="compiler-warning-level-1-c4230"></a>Compilador aviso (nível 1) C4230

anacronismo usado: modificadores/qualificadores intercalados; kvalifikátor se ignoruje.

Usando um qualificador antes de um modificador da Microsoft, como `__cdecl` é uma prática antiquada.

## <a name="example"></a>Exemplo

```
// C4230.cpp
// compile with: /W1 /LD
int __cdecl const function1();   // C4230 const ignored
```