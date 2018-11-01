---
title: Compilador aviso (nível 1) C4662
ms.date: 11/04/2016
f1_keywords:
- C4662
helpviewer_keywords:
- C4662
ms.assetid: 7efda273-d04a-47b7-ad65-ff1ff94b5ffc
ms.openlocfilehash: ecd8e757e1724fcd4c08540559eab75f1e4bed46
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50599833"
---
# <a name="compiler-warning-level-1-c4662"></a>Compilador aviso (nível 1) C4662

instanciação explícita; classe de modelo 'identifier1' não possui nenhuma definição da qual especializar 'identifier2'

A classe de modelo especificada foi declarada, mas não definida.

## <a name="example"></a>Exemplo

```
// C4662.cpp
// compile with: /W1 /LD
template<class T, int i> class MyClass; // no definition
template MyClass< int, 1>;              // C4662
```