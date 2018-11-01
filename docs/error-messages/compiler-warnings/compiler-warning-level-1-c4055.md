---
title: Compilador aviso (nível 1) C4052
ms.date: 11/04/2016
f1_keywords:
- C4055
helpviewer_keywords:
- C4055
ms.assetid: f9955421-16ab-46e5-8f9d-bf1639a519ef
ms.openlocfilehash: e9fcb4356d993d86b622fd49c4a75d587554f7c2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50601312"
---
# <a name="compiler-warning-level-1-c4055"></a>Compilador aviso (nível 1) C4055

> '*conversão*': de ponteiro de dados '*type1*'para ponteiro de função'*type2*'

## <a name="remarks"></a>Comentários

**Obsoleto:** esse aviso não é gerado pelo Visual Studio 2017 e versões posteriores.

Um ponteiro de dados é convertido (possivelmente incorretamente) para um ponteiro de função. Este é um aviso de nível 1 em /Za e um aviso de nível 4 em /Ze.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4055:

```C
// C4055.c
// compile with: /Za /W1 /c
typedef int (*PFUNC)();
int *pi;
PFUNC f() {
   return (PFUNC)pi;   // C4055
}
```

Em /Ze, este é um aviso de nível 4.

```C
// C4055b.c
// compile with: /W4 /c
typedef int (*PFUNC)();
int *pi;
PFUNC f() {
return (PFUNC)pi;   // C4055
}
```
