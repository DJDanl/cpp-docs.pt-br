---
title: Aviso do compilador C4867
ms.date: 11/04/2016
f1_keywords:
- C4867
helpviewer_keywords:
- C4867
ms.assetid: 8a257d70-c3a7-462d-b285-e57c952a8bf7
ms.openlocfilehash: 0fd5de46f713aed08508f8755c9e54c3ff46366b
ms.sourcegitcommit: 7d64c5f226f925642a25e07498567df8bebb00d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2019
ms.locfileid: "65447197"
---
# <a name="compiler-warning-c4867"></a>Aviso do compilador C4867

'function': chamada de função faltando lista de argumentos; Use 'chamar' para criar um ponteiro para membro

Um ponteiro para função de membro foi inicializado incorretamente.

Esse aviso pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: conformidade aprimorada do ponteiro para membro.  O código compilado antes do Visual Studio 2005 agora irá gerar C4867.

Esse aviso é emitido sempre como um erro. Use o [aviso](../../preprocessor/warning.md) pragma para desabilitar esse aviso. Para obter mais informações sobre C4867 e MFC/ATL, consulte [_ATL_ENABLE_PTM_WARNING](../../atl/reference/compiler-options-macros.md#_atl_enable_ptm_warning).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4867.

```
// C4867.cpp
// compile with: /c
class A {
public:
   void f(int) {}

   typedef void (A::*TAmtd)(int);

   struct B {
      TAmtd p;
   };

   void g() {
      B b = {f};   // C4867
      B b2 = {&A::f};   // OK
   }
};
```