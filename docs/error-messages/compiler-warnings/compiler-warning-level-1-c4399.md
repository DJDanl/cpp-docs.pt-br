---
title: Aviso do compilador (nível 1) C4399
ms.date: 11/04/2016
f1_keywords:
- C4399
helpviewer_keywords:
- C4399
ms.assetid: f58d9ba7-71a0-4c3b-b26f-f946dda8af30
ms.openlocfilehash: a556fbffad41d04b3eb0ea1acfd5e8739ddd5b68
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80186797"
---
# <a name="compiler-warning-level-1-c4399"></a>Aviso do compilador (nível 1) C4399

> '*Symbol*': símbolo por processo não deve ser marcado com __declspec (dllimport) quando compilado com/CLR: Pure

## <a name="remarks"></a>Comentários

A opção de compilador **/CLR: Pure** foi preterida no visual Studio 2015 e não tem suporte no visual Studio 2017.

Os dados de uma imagem nativa ou de uma imagem com construções nativas e CLR não podem ser importados para uma imagem pura. Para resolver esse aviso, compile com **/CLR** (não **/CLR: Pure**) ou exclua `__declspec(dllimport)`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4399.

```cpp
// C4399.cpp
// compile with: /clr:pure /doc /W1 /c
__declspec(dllimport) __declspec(process) extern const int i;   // C4399
```
