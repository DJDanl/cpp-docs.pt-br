---
title: Erro do compilador C2914
ms.date: 11/04/2016
f1_keywords:
- C2914
helpviewer_keywords:
- C2914
ms.assetid: fc6a0592-f53e-4f5a-88cb-780bbed4acf2
ms.openlocfilehash: 2500736f799032aea71173931139404b4406a16a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62384342"
---
# <a name="compiler-error-c2914"></a>Erro do compilador C2914

'identifier': não é possível deduzir argumento de tipo como argumento da função é ambíguo

O compilador não pode determinar qual sobrecarregado funções a serem usadas para um argumento genérico ou modelo.

O exemplo a seguir gera C2914:

```
// C2914.cpp
// compile with: /c
void f(int);
void f(double);
template<class T> void g(void (*) (T));
void h() { g(f); }   // C2914
// try the following line instead
// void h() { g<int>(f); }
```

C2914 também podem ocorrer ao usar genéricos.  O exemplo a seguir gera C2914:

```
// C2914b.cpp
// compile with: /clr /c
void f(int);
void f(double);

template<class T>
void gf(void (*) (T));

void h() { gf(f);}   // C2914
// try the following line instead
void h() { gf<int>(f); }
```