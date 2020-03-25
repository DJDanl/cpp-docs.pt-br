---
title: Aviso do compilador C4430
ms.date: 11/04/2016
f1_keywords:
- C4430
helpviewer_keywords:
- C4430
ms.assetid: 12efbfff-aa58-4a86-a7d6-2c6a12d01dd3
ms.openlocfilehash: 091d988a5af277e78a2954eb5b0b95bc64c56069
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165256"
---
# <a name="compiler-warning-c4430"></a>Aviso do compilador C4430

faltando especificador de tipo - int assumido. Observação: C++ não dá suporte a default-int

Esse erro pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: todas as declarações devem especificar explicitamente o tipo; int não é mais pressuposto.

C4430 é sempre emitido como um erro.  Você pode desativar esse aviso com o `#pragma warning` ou **/WD**; consulte [Warning](../../preprocessor/warning.md) ou [/w,/W0,/W1,/W2,/W3,/W4,/W1,/W2,/W3,/W4,/Wall,/WD,/We,/wo,/WV,/WX (nível de aviso)](../../build/reference/compiler-option-warning-level.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4430.

```cpp
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
