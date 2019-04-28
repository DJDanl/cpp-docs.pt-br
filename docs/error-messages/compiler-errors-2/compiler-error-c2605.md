---
title: Erro do compilador C2605
ms.date: 11/04/2016
f1_keywords:
- C2605
helpviewer_keywords:
- C2605
ms.assetid: a0e6f132-5acf-4e19-b277-ddf196d182bf
ms.openlocfilehash: c1a3f1132edb90e119d97061fbbfb293d364ef3a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62215220"
---
# <a name="compiler-error-c2605"></a>Erro do compilador C2605

'name': esse método é reservado em gerenciada ou WinRT classe

Determinados nomes são reservados pelo compilador para funções internas.  Para obter mais informações, consulte [destruidores e finalizadores](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2605.

```
// C2605.cpp
// compile with: /clr /c
ref class R {
protected:
   void Finalize() {}   // C2605
};
```