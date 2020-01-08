---
title: Erro do compilador C2191
ms.date: 11/04/2016
f1_keywords:
- C2191
helpviewer_keywords:
- C2191
ms.assetid: 051b8350-e5de-4f51-ab6e-96d32366bcef
ms.openlocfilehash: 66b7d70b9010855ada7b9d24fba80915450a685b
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301867"
---
# <a name="compiler-error-c2191"></a>Erro do compilador C2191

segunda lista de parâmetros mais longa do que a primeira

Uma função C foi declarada uma segunda vez com uma lista de parâmetros mais longa. C não oferece suporte a funções sobrecarregadas.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2191:

```c
// C2191.c
// compile with: /Za /c
void func( int );
void func( int, float );   // C2191 different parameter list
void func2( int, float );   // OK
```
