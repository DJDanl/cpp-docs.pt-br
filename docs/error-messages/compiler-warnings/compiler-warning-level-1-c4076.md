---
title: Compilador aviso (nível 1) C4076 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4076
dev_langs:
- C++
helpviewer_keywords:
- C4076
ms.assetid: 04581066-313a-4a11-bb60-721e6d038d75
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 928b0a78c09773e334c1a291877b74304dab66ec
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43198472"
---
# <a name="compiler-warning-level-1-c4076"></a>Compilador aviso (nível 1) C4076

> '*modificador de tipo*': não pode ser usado com o tipo '*typename*'

## <a name="remarks"></a>Comentários

Um modificador de tipo, seja **assinados** ou **unsigned**, não pode ser usado com um tipo não inteiro. *modificador de tipo* será ignorado.
  
## <a name="example"></a>Exemplo  

O exemplo a seguir gera C4076; para corrigi-lo, remova os **sem sinal** modificador de tipo:

```cpp
// C4076.cpp  
// compile with: /W1 /LD  
unsigned double x;   // C4076  
```