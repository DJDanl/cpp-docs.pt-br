---
title: Compilador aviso (nível 1) C4190
ms.date: 11/04/2016
f1_keywords:
- C4190
helpviewer_keywords:
- C4190
ms.assetid: a4d0ad93-a19a-4063-addd-36d605831567
ms.openlocfilehash: 05984594a57878aad8037861a15ac9284ff65192
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50521223"
---
# <a name="compiler-warning-level-1-c4190"></a>Compilador aviso (nível 1) C4190

'identifier1' possui vínculo a C especificado, mas retorna UDT 'identifier2', que é incompatível com C

Uma função ou um ponteiro para função tem um UDT (definido pelo usuário type, que é uma classe, estrutura, enumeração ou união) como tipo de retorno e `extern` vínculo "C". Isso é legal se:

- Todas as chamadas para essa função ocorrerem do C++.

- É a definição da função em C++.

## <a name="example"></a>Exemplo

```cpp
// C4190.cpp
// compile with: /W1 /LD
struct X
{
   int i;
   X ();
   virtual ~X ();
};

extern "C" X func ();   // C4190
```