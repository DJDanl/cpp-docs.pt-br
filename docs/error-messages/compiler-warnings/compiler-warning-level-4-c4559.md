---
title: Compilador aviso (nível 4) C4559 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4559
dev_langs:
- C++
helpviewer_keywords:
- C4559
ms.assetid: ed542f60-454d-45cb-85da-987ede61b1ab
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d5743b33f62aa954c3765b729ab5c0297b20e32
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43195570"
---
# <a name="compiler-warning-level-4-c4559"></a>Compilador aviso (nível 4) C4559

> '*função*': redefinição; os ganhos de função declspec (*modificador*)

## <a name="remarks"></a>Comentários

Uma função foi redefinida ou declarado novamente e a segunda definição ou declaração adicionada uma **declspec** modificador (*modificador*). Esse aviso é informativo. Para corrigir este aviso, exclua uma das definições.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4559:

```cpp
// C4559.cpp
// compile with: /W4 /LD
void f();
__declspec(noalias) void f();   // C4559
```