---
title: Erro do compilador C3269
ms.date: 11/04/2016
f1_keywords:
- C3269
helpviewer_keywords:
- C3269
ms.assetid: c575f067-244d-4dd5-bf58-9e7630ea58b7
ms.openlocfilehash: 406b388460b3d449471c884dd6461f2ce59a10f6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62365709"
---
# <a name="compiler-error-c3269"></a>Erro do compilador C3269

'function': uma função de membro de uma ou não gerenciado WinRTtype não pode ser declarada com '...'

Gerenciado e funções de membro de classe WinRT não podem declarar a listas de parâmetros de comprimento variável.

O exemplo a seguir gera C3269 e mostra como corrigi-lo:

```
// C3269_2.cpp
// compile with: /clr

ref struct A
{
   void func(int i, ...)   // C3269
   // try the following line instead
   // void func(int i )
   {
   }
};

int main()
{
}
```
