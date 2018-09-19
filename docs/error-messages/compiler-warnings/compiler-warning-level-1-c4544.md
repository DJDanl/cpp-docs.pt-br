---
title: Compilador aviso (nível 1) C4544 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4544
dev_langs:
- C++
helpviewer_keywords:
- C4544
ms.assetid: 11ee04df-41ae-435f-af44-881e801315a8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c7cd274f0d1b595d374e1b108db40a51395b968
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46084270"
---
# <a name="compiler-warning-level-1-c4544"></a>Compilador aviso (nível 1) C4544

'declaração de ': argumento de modelo ignorado nessa declaração de template padrão

Um argumento de modelo padrão foi especificado em um local incorreto e foi ignorado. Um argumento de modelo padrão para um modelo de classe só pode ser especificado na declaração ou definição do modelo de classe e não em um membro do modelo de classe.

Este exemplo gera C4545 e o próximo exemplo mostra como corrigi-lo:

```
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

Neste exemplo, o parâmetro padrão se aplica ao modelo de classe `S`:

```
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