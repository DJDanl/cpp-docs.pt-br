---
title: Aviso do compilador (nível 4) C4019
ms.date: 11/04/2016
f1_keywords:
- C4019
helpviewer_keywords:
- C4019
ms.assetid: 4ecfe85d-673f-4334-8154-36fe7f0b3444
ms.openlocfilehash: 6245a32aff0769a2f30dfe88ca6111579eda6ea9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185458"
---
# <a name="compiler-warning-level-4-c4019"></a>Aviso do compilador (nível 4) C4019

instrução vazia no escopo global

Um ponto e vírgula no escopo global não é precedido por uma instrução.

Esse aviso pode ser corrigido se você remover o ponto-e-vírgula extra.

## <a name="example"></a>Exemplo

```c
// C4019.c
// compile with: /Za /W4
#define declint( varname ) int varname;
declint( a );   // C4019, int a;;
declint( b )   // OK, int b;

int main()
{
}
```
