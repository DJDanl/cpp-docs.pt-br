---
title: Erro do compilador C2286
ms.date: 11/04/2016
f1_keywords:
- C2286
helpviewer_keywords:
- C2286
ms.assetid: 078e0201-35cc-42e2-8dbc-6f8cf557b098
ms.openlocfilehash: 79697a17d322ae15a21e522efa7dfd5c2342f7a6
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74759159"
---
# <a name="compiler-error-c2286"></a>Erro do compilador C2286

ponteiros para membros da representação ' identifier ' já estão definidos como ' Inheritance '-Declaração ignorada

Existem duas representações de ponteiro para membro diferentes para a classe.

Para obter mais informações, consulte [palavras-chave de herança](../../cpp/inheritance-keywords.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2286:

```cpp
// C2286.cpp
// compile with: /c
class __single_inheritance X;
class __multiple_inheritance X;   // C2286
class  __multiple_inheritance Y;   // OK
```
