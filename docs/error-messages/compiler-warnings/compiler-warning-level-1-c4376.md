---
title: Compilador aviso (nível 1) C4376
ms.date: 11/04/2016
f1_keywords:
- C4376
helpviewer_keywords:
- C4376
ms.assetid: 5f202c74-9489-48fe-b36f-19cd882b1589
ms.openlocfilehash: b1f6e7b403931f7fe1a67974ae85001cf80eab66
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62410415"
---
# <a name="compiler-warning-level-1-c4376"></a>Compilador aviso (nível 1) C4376

access specifier 'old_specifier:' is no longer supported: please use 'new_specifier:' instead

Para obter mais informações sobre como especificar a acessibilidade de tipo e membro nos metadados, consulte [visibilidade de tipo](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Type_visibility) e [visibilidade de membro](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Member_visibility) em [como: Definir e consumir Classes e Structs (C++/CLI)](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4376.

```
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