---
title: Aviso do compilador (nível 1) C4055
ms.date: 11/04/2016
f1_keywords:
- C4055
helpviewer_keywords:
- C4055
ms.assetid: f9955421-16ab-46e5-8f9d-bf1639a519ef
ms.openlocfilehash: 47883f60c3205125a8ee88b804c1d622b3ba0b41
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041023"
---
# <a name="compiler-warning-level-1-c4055"></a>Aviso do compilador (nível 1) C4055

> '*Conversion*': do ponteiro de dados '*type1*' para o ponteiro de função '*type2*'

## <a name="remarks"></a>Comentários

**Obsoleto:** Esse aviso não é gerado pelo Visual Studio 2017 e por versões posteriores.

Um ponteiro de dados é convertido (possivelmente incorretamente) em um ponteiro de função. Este é um aviso de nível 1 em/za e um aviso de nível 4 em/ze.

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

Em/ze, esse é um aviso de nível 4.

```C
// C4055b.c
// compile with: /W4 /c
typedef int (*PFUNC)();
int *pi;
PFUNC f() {
return (PFUNC)pi;   // C4055
}
```
