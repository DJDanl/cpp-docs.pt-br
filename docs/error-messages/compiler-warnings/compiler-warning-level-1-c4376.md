---
title: Aviso do compilador (nível 1) C4376
ms.date: 11/04/2016
f1_keywords:
- C4376
helpviewer_keywords:
- C4376
ms.assetid: 5f202c74-9489-48fe-b36f-19cd882b1589
ms.openlocfilehash: 73143e38b66471a41cc61f818f7618b9ddafcaa1
ms.sourcegitcommit: e5192a25c084eda9eabfa37626f3274507e026b3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2019
ms.locfileid: "73966464"
---
# <a name="compiler-warning-level-1-c4376"></a>Aviso do compilador (nível 1) C4376

o especificador de acesso ' old_specifier: ' não tem mais suporte: use ' new_specifier: ' em vez disso

Para obter mais informações sobre como especificar a acessibilidade de tipo e membro em metadados, consulte [visibilidade de tipos](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [visibilidade de membros](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Member_visibility) em [How to: define andC++consuma classes and structs (/CLI)](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4376.

```cpp
// C4376.cpp
// compile with: /clr /W1 /c
public ref class G {
public public:   // C4376
   void m2();
};

public ref class H {
public:   // OK
   void m2();
};
```