---
title: Aviso do compilador C4368
ms.date: 11/04/2016
f1_keywords:
- C4368
helpviewer_keywords:
- C4368
ms.assetid: cb85bcee-fd3d-4aa5-b626-2324f07a4f1b
ms.openlocfilehash: d96ae14bc427568dcf7ba7bc6e5d53f3d28883ae
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165296"
---
# <a name="compiler-warning-c4368"></a>Aviso do compilador C4368

Não é possível definir ' member ' como um membro de ' type ' gerenciado: tipos mistos não são suportados

Não é possível inserir um membro de dados nativo em um tipo CLR.

No entanto, você pode declarar um ponteiro para um tipo nativo e controlar seu tempo de vida no construtor e destruidor e finalizador de sua classe gerenciada. Para obter mais informações [, consulte destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

Esse aviso é sempre emitido como um erro. Use o pragma de [aviso](../../preprocessor/warning.md) para desabilitar o C4368.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4368.

```cpp
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
