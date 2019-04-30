---
title: Compilador aviso (nível 1) C4662
ms.date: 11/04/2016
f1_keywords:
- C4662
helpviewer_keywords:
- C4662
ms.assetid: 7efda273-d04a-47b7-ad65-ff1ff94b5ffc
ms.openlocfilehash: ecd8e757e1724fcd4c08540559eab75f1e4bed46
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62374606"
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