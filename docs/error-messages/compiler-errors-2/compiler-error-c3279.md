---
title: Erro do compilador C3279
ms.date: 11/04/2016
f1_keywords:
- C3279
helpviewer_keywords:
- C3279
ms.assetid: 639afc20-984c-4a95-be35-8bf9409f02d5
ms.openlocfilehash: 72646d7611163748fe7e27ea6c78cd38426eb6ad
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447819"
---
# <a name="compiler-error-c3279"></a>Erro do compilador C3279

especializações parciais e explícitas, bem como instanciações explícitas de modelos de classe declaradas no namespace cli não são permitidas

O `cli` namespace é definida pela Microsoft e contém modelos de pseudo. O Microsoft C++ compilador não permite especializações definidas pelo usuário, parciais e explícitas e instanciações explícitas de modelos de classe neste namespace.

O exemplo a seguir gera C3279:

```
// C3279.cpp
// compile with: /clr
namespace cli {
   template <> ref class array<int> {};   // C3279
   template <typename T> ref class array<T, 2> {};   // C3279
}
```