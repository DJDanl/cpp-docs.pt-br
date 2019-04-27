---
title: Erro do compilador C3846
ms.date: 11/04/2016
f1_keywords:
- C3846
helpviewer_keywords:
- C3846
ms.assetid: c470f8a5-106b-4efb-b8dc-e1319e04130f
ms.openlocfilehash: 788f03e4364404ad5c30b7edcba8b743c7f201ad
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62152417"
---
# <a name="compiler-error-c3846"></a>Erro do compilador C3846

'symbol': não é possível importar símbolo de 'assembly2': como 'symbol' já foi importado de outro assembly 'assembly1'

Não foi possível importar um símbolo de um assembly referenciado porque ele anteriormente foi importado de um assembly referenciado.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3846:

```
// C3846a.cpp
// compile with: /LD /clr
public ref struct G
{
};
```

E, em seguida, compilar isso:

```
// C3846b.cpp
// compile with: /clr
#using "c3846a.dll"
#using "c3846a.obj"   // C3846

int main()
{
}
```
