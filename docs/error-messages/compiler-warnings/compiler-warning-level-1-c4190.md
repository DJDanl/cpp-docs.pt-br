---
title: Aviso do compilador (nível 1) C4190
ms.date: 11/04/2016
f1_keywords:
- C4190
helpviewer_keywords:
- C4190
ms.assetid: a4d0ad93-a19a-4063-addd-36d605831567
ms.openlocfilehash: 6d110aa70a470382e274546e95599804fa3bc7d6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80199869"
---
# <a name="compiler-warning-level-1-c4190"></a>Aviso do compilador (nível 1) C4190

' identifier1 ' tem vínculo C especificado, mas retorna UDT ' identifier2 ', que é incompatível com C

Uma função ou ponteiro para função tem um UDT (tipo definido pelo usuário, que é uma classe, estrutura, enumeração ou União) como tipo de retorno e `extern` vinculação "C". Isso é válido se:

- Todas as chamadas para essa função ocorrem C++em.

- A definição da função está em C++.

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
