---
title: Erro do compilador C3803
ms.date: 11/04/2016
f1_keywords:
- C3803
helpviewer_keywords:
- C3803
ms.assetid: bad5fb9a-ed9a-4c15-96e7-cf06e200a50d
ms.openlocfilehash: f6c255ec18d6dcf94f3ec022f09b173c2c66a1dd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400091"
---
# <a name="compiler-error-c3803"></a>Erro do compilador C3803

'property': propriedade tem um tipo que é incompatível com um de seu acessadores 'o acessador'

O tipo de uma propriedade definida com [propriedade](../../cpp/property-cpp.md) não coincide com o tipo de retorno para uma de suas funções do acessador.

O exemplo a seguir gera C3803:

```
// C3803.cpp
struct A
{
   __declspec(property(get=GetIt)) int i;
   char GetIt()
   {
      return 0;
   }

   /*
   // try the following definition instead
   int GetIt()
   {
      return 0;
   }
   */
}; // C3803

int main()
{
}
```