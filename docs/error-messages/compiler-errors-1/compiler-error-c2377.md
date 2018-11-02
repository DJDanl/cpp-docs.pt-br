---
title: Erro do compilador C2377
ms.date: 11/04/2016
f1_keywords:
- C2377
helpviewer_keywords:
- C2377
ms.assetid: f7660965-bf4c-4cd9-8307-1bd7016678a1
ms.openlocfilehash: b4789469fe27dafb2fb13bf3db085958db8d1478
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50528759"
---
# <a name="compiler-error-c2377"></a>Erro do compilador C2377

'identifier': redefinição; TypeDef não pode ser sobrecarregado com nenhum outro símbolo

Um `typedef` identificador será redefinido.

O exemplo a seguir gera C2377:

```
// C2377.cpp
// compile with: /c
typedef int i;
int i;   // C2377
int j;   // OK
```