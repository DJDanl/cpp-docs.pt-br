---
title: Aviso do compilador (nível 2) C4099
ms.date: 11/04/2016
f1_keywords:
- C4099
helpviewer_keywords:
- C4099
ms.assetid: 00bb803d-cae7-4ab8-8969-b46f54139ac8
ms.openlocfilehash: 09ea9e2963735c1e011e25b42b04ad6d67d084a5
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62349809"
---
# <a name="compiler-warning-level-2-c4099"></a>Aviso do compilador (nível 2) C4099

'identifier': nome do tipo visto pela primeira vez usando 'objecttype1' agora visto usando 'objecttype2'

Um objeto declarado como uma estrutura é definido como uma classe ou um objeto declarado como uma classe é definido como uma estrutura. O compilador usa o tipo de dado na definição.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4099.

```
// C4099.cpp
// compile with: /W2 /c
struct A;
class A {};   // C4099, use different identifer or use same object type
```