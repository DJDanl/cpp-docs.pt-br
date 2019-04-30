---
title: Erro do compilador C2181
ms.date: 11/04/2016
f1_keywords:
- C2181
helpviewer_keywords:
- C2181
ms.assetid: d52b2fe4-566a-40a9-b8e2-8dce1f287668
ms.openlocfilehash: a676794b5dedd17cfb973de36d3771ef1130a786
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386090"
---
# <a name="compiler-error-c2181"></a>Erro do compilador C2181

else inválido sem if correspondente

Cada `else` deve ter uma correspondência `if`.

O exemplo a seguir gera C2181:

```
// C2181.cpp
int main() {
   int i = 0;
   else   // C2181
      i = 1;
}
```

Solução possível:

```
// C2181b.cpp
int main() {
   int i = 0;
   if(i)
      i = 0;
   else
      i = 1;
}
```