---
title: Aviso do compilador C4430
ms.date: 11/04/2016
f1_keywords:
- C4430
helpviewer_keywords:
- C4430
ms.assetid: 12efbfff-aa58-4a86-a7d6-2c6a12d01dd3
ms.openlocfilehash: fe765fa49b9aa11667e1eac4a9cfed54bb84fd8f
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447868"
---
# <a name="compiler-warning-c4430"></a>Aviso do compilador C4430

faltando especificador de tipo - int assumido. Observação: C++ não suporta default-int

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: todas as declarações devem especificar explicitamente o tipo; não é considerado int.

C4430 sempre é emitido como um erro.  Você pode desativar esse aviso com a `#pragma warning` ou **/wd**; consulte [aviso](../../preprocessor/warning.md) ou [/w, /W0, / W1, / w2, / w3, / W4, / W1, / w2, / w3, / W4, /Wall, /wd, /, /wo, /Wv, /WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md)para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4430.

```
// C4430.cpp
// compile with: /c
struct CMyClass {
   CUndeclared m_myClass;  // C4430
   int m_myClass;  // OK
};

typedef struct {
   POINT();   // C4430
   // try the following line instead
   // int POINT();
   unsigned x;
   unsigned y;
} POINT;
```