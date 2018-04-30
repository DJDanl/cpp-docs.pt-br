---
title: Compilador (nível 1) de aviso C4052 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- C4055
dev_langs:
- C++
helpviewer_keywords:
- C4055
ms.assetid: f9955421-16ab-46e5-8f9d-bf1639a519ef
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 29b1c8bcc836e35f7b8b81954ef247527d8ec35e
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="compiler-warning-level-1-c4055"></a>Compilador C4055 de aviso (nível 1)

> '*conversão*': de ponteiro de dados '*type1*'para o ponteiro de função'*type2*'

## <a name="remarks"></a>Comentários

**Obsoleto:** esse aviso não é gerado pelo Visual Studio de 2017 e versões posteriores.

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
