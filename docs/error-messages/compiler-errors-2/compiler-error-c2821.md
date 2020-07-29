---
title: Erro do compilador C2821
ms.date: 11/04/2016
f1_keywords:
- C2821
helpviewer_keywords:
- C2821
ms.assetid: e8d71988-a968-4484-94db-e8c3bad74a4a
ms.openlocfilehash: 115874724a24530e0d85256e11c3aa355aa4d6af
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225391"
---
# <a name="compiler-error-c2821"></a>Erro do compilador C2821

o primeiro parâmetro formal para ' operator new ' deve ser ' unsigned int '

O primeiro parâmetro formal do [operador New](../../standard-library/new-operators.md#op_new) deve ser não assinado **`int`** .

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2821:

```cpp
// C2821.cpp
// compile with: /c
void * operator new( /* unsigned int,*/ void * );   // C2821
void * operator new( unsigned int, void * );
```
