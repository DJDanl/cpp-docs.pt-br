---
title: Aviso do compilador C4867
ms.date: 11/04/2016
f1_keywords:
- C4867
helpviewer_keywords:
- C4867
ms.assetid: 8a257d70-c3a7-462d-b285-e57c952a8bf7
ms.openlocfilehash: e093d262bc26cf0acfbb181d621fffc1aa391ee9
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73626596"
---
# <a name="compiler-warning-c4867"></a>Aviso do compilador C4867

' function ': chamada de função ausente na lista de argumentos; Use ' call ' para criar um ponteiro para membro

Um ponteiro para uma função membro foi inicializado incorretamente.

Esse aviso pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio 2005: conformidade aprimorada de ponteiro para membro.  O código que compilou antes do Visual Studio 2005 agora irá gerar C4867.

Esse aviso é sempre emitido como um erro. Use o pragma de [aviso](../../preprocessor/warning.md) para desabilitar este aviso. Para obter mais informações sobre C4867 e MFC/ATL, consulte [_ATL_ENABLE_PTM_WARNING](../../atl/reference/compiler-options-macros.md#_atl_enable_ptm_warning).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4867.

```cpp
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