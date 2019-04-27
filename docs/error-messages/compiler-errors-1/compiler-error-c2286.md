---
title: Erro do compilador C2286
ms.date: 11/04/2016
f1_keywords:
- C2286
helpviewer_keywords:
- C2286
ms.assetid: 078e0201-35cc-42e2-8dbc-6f8cf557b098
ms.openlocfilehash: 7d3b8297c5f5da29b99abe78999396e8c44df0fd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62182763"
---
# <a name="compiler-error-c2286"></a>Erro do compilador C2286

ponteiros para membros de representação 'identifier' já está definido como 'herança' - declaração ignorada

Existem duas representações diferentes de membros do ponteiro para a classe.

Para obter mais informações, consulte [palavras-chave de herança](../../cpp/inheritance-keywords.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2286:

```
// C2286.cpp
// compile with: /c
class __single_inheritance X;
class __multiple_inheritance X;   // C2286
class  __multiple_inheritance Y;   // OK
```