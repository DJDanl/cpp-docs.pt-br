---
title: Erro do compilador C3848
ms.date: 11/04/2016
f1_keywords:
- C3848
helpviewer_keywords:
- C3848
ms.assetid: 32d3ccef-01ec-4f8b-bbff-fb9b1a76b4c4
ms.openlocfilehash: 1d738311ada14999a5345a4e2394631254dda00a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62380988"
---
# <a name="compiler-error-c3848"></a>Erro do compilador C3848

expressão possuindo tipo 'type' perderia alguns qualificadores const-volatile a fim de chamar 'function'

Uma variável com um tipo const volátil especificado só pode chamar membros a funções definidas com qualificações constantes ou voláteis de igual ou superior.

Os exemplos a seguir geram C3848:

```
// C3848.cpp
void glbFunc1()
{
}

typedef void (* pFunc1)();

struct S3
{
   operator pFunc1() // const
   {
      return &glbFunc1;
   }
};

int main()
{
   const S3 s3;
   s3();   // C3848, uncomment const qualifier
}
```