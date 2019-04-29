---
title: Erro do compilador C2779
ms.date: 11/04/2016
f1_keywords:
- C2779
helpviewer_keywords:
- C2779
ms.assetid: 4a00e492-855a-41f3-8a18-5f60ee20c2f2
ms.openlocfilehash: 7cf8aed276ab2aea61dc92b9e9fcbff9552c2ad6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62257043"
---
# <a name="compiler-error-c2779"></a>Erro do compilador C2779

'declaração de ': métodos de propriedade só podem ser associados a membros de dados não estáticos

O `property` atributo estendido incorretamente é aplicado a um membro de dados estáticos.

O exemplo a seguir gera C2779:

```
// C2779.cpp
struct A {
   static __declspec(property(put=PutProp))
   // try the following line instead
   __declspec(property(put=PutProp))
      int prop;   // C2779
   int PutProp(void);
};
```