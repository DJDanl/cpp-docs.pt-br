---
title: Erro do compilador C3807
ms.date: 11/04/2016
f1_keywords:
- C3807
helpviewer_keywords:
- C3807
ms.assetid: 7e2b0aab-8c61-4e71-b9c1-fcaeb6a1b5ea
ms.openlocfilehash: b5599914666af95a29667acc1ad4ad35eef7608f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391927"
---
# <a name="compiler-error-c3807"></a>Erro do compilador C3807

'type': uma classe com o atributo ComImport não pode derivar de 'type2', a implementação da interface somente é permitida

Um tipo derivado de <xref:System.Runtime.InteropServices.ComImportAttribute> só é possível implementar uma interface.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3807.

```
// C3807.cpp
// compile with: /clr /c
ref struct S {};
interface struct I {};

[System::Runtime::InteropServices::ComImportAttribute()]
ref struct S1 : S {};   // C3807
ref struct S2 : I {};
```