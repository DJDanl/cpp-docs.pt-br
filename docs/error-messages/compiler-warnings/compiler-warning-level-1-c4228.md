---
title: Aviso do compilador (nível 1) C4228
ms.date: 11/04/2016
f1_keywords:
- C4228
helpviewer_keywords:
- C4228
ms.assetid: 9301d660-d601-464e-83f5-7ed844a3c6dc
ms.openlocfilehash: c216143f2b47148f73502c847175201ea9a74fee
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175890"
---
# <a name="compiler-warning-level-1-c4228"></a>Aviso do compilador (nível 1) C4228

extensão não padrão usada: qualificadores após a vírgula na lista de declaradores são ignorados

O uso de qualificadores como **const** ou `volatile` depois de uma vírgula ao declarar variáveis é uma extensão da Microsoft ([/ze](../../build/reference/za-ze-disable-language-extensions.md)).

## <a name="example"></a>Exemplo

```cpp
// C4228.cpp
// compile with: /W1
int j, const i = 0;  // C4228
int k;
int const m = 0;  // ok
int main()
{
}
```
