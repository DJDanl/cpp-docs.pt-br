---
title: Aviso do compilador (nível 1) C4544
ms.date: 11/04/2016
f1_keywords:
- C4544
helpviewer_keywords:
- C4544
ms.assetid: 11ee04df-41ae-435f-af44-881e801315a8
ms.openlocfilehash: 094662270569c7362b7bb3c4953a466b19ed2e65
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966478"
---
# <a name="compiler-warning-level-1-c4544"></a>Aviso do compilador (nível 1) C4544

' declaração ': argumento de modelo padrão ignorado nesta declaração de modelo

Um argumento de modelo padrão foi especificado em um local incorreto e foi ignorado. Um argumento de modelo padrão para um modelo de classe só pode ser especificado na declaração ou na definição do modelo de classe, e não em um membro do modelo de classe.

Este exemplo gera C4545 e o próximo exemplo mostra como corrigi-lo:

```cpp
// C4544.cpp
// compile with: /W1 /LD
template <class T>
struct S
{
   template <class T1>
      struct S1;
   void f();
};

template <class T=int>
template <class T1>
struct S<T>::S1 {};   // C4544
```

Neste exemplo, o parâmetro padrão aplica-se ao modelo de classe `S`:

```cpp
// C4544b.cpp
// compile with: /LD
template <class T = int>
struct S
{
   template <class T1>
      struct S1;
   void f();
};

template <class T>
template <class T1>
struct S<T>::S1 {};
```