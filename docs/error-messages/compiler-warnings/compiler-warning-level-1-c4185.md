---
title: Aviso do compilador (nível 1) C4185
ms.date: 11/04/2016
f1_keywords:
- C4185
helpviewer_keywords:
- C4185
ms.assetid: 37e7063a-35b1-4e05-ae31-e811dced02b9
ms.openlocfilehash: 6c818f99afb4cd60f5e129f48494aee0c24ba86a
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626208"
---
# <a name="compiler-warning-level-1-c4185"></a>Aviso do compilador (nível 1) C4185

ignorando atributo de #import desconhecido ' attribute '

O atributo não é um atributo válido de `#import`. É ignorado.

## <a name="example"></a>Exemplo

```cpp
// C4185.cpp
// compile with: /W1 /c
#import "stdole2.tlb" no_such_attribute   // C4185
```