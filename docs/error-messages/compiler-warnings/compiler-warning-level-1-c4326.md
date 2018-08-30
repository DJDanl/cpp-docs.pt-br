---
title: Compilador aviso (nível 1) C4326 | Microsoft Docs
ms.custom: ''
ms.date: 08/27/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4326
dev_langs:
- C++
helpviewer_keywords:
- C4326
ms.assetid: d44d2c4e-9456-42d3-b35b-4ba4b2d42ec7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cee18a9ccc807370cf2fb40748939f211a4ba52f
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43210998"
---
# <a name="compiler-warning-level-1-c4326"></a>Compilador aviso (nível 1) C4326

> tipo de retorno de '*função*'deve ser'*type1*'em vez de'*type2*'

## <a name="remarks"></a>Comentários

Uma função retornou um tipo diferente de *type1*. Por exemplo, usando [/Za](../../build/reference/za-ze-disable-language-extensions.md), **principal** não retornou uma **int**.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4326 e mostra como corrigi-lo:

```cpp
// C4326.cpp
// compile with: /Za /W1
char main()
{
    // C4326, instead use int main()
}
```