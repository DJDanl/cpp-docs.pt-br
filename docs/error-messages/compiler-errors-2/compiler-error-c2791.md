---
title: Erro do compilador C2791
ms.date: 11/04/2016
f1_keywords:
- C2791
helpviewer_keywords:
- C2791
ms.assetid: 938ad1fb-75d9-4ce2-ad92-83d6249005b5
ms.openlocfilehash: 66a111ea6fe2ca5acfbc473d19da62d9de67372a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360158"
---
# <a name="compiler-error-c2791"></a>Erro do compilador C2791

Uso inválido de 'super': 'class' não tem nenhuma classe base

A palavra-chave [super](../../cpp/super.md) foi usado dentro do contexto de uma função de membro de uma classe que não tem nenhuma classe base.

O exemplo a seguir gera C2791:

```
// C2791.cpp
struct D {
   void mf() {
      __super::mf();   // C2791
   }
};
```