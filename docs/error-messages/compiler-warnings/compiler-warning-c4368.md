---
title: Aviso do compilador C4368
ms.date: 11/04/2016
f1_keywords:
- C4368
helpviewer_keywords:
- C4368
ms.assetid: cb85bcee-fd3d-4aa5-b626-2324f07a4f1b
ms.openlocfilehash: b2af1166738d867c84ff4ebae832f831af7940ff
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62311476"
---
# <a name="compiler-warning-c4368"></a>Aviso do compilador C4368

não é possível definir 'member' como um membro do tipo' gerenciado': não há suporte para tipos mistos

É possível inserir um membro de dados nativos em um tipo CLR.

No entanto, você pode declarar um ponteiro para um tipo nativo e controlar seu tempo de vida no construtor e destruidor e o finalizador da classe gerenciada. Para obter mais informações, consulte [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

Esse aviso é emitido sempre como um erro. Use o [aviso](../../preprocessor/warning.md) pragma para desabilitar C4368.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4368.

```
// C4368.cpp
// compile with: /clr /c
struct N {};
ref struct O {};
ref struct R {
    R() : m_p( new N ) {}
    ~R() { delete m_p; }

   property N prop;   // C4368
   int i[10];   // C4368

   property O ^ prop2;   // OK
   N * m_p;   // OK
};
```