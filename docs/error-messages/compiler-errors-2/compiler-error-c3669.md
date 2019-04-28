---
title: Erro do compilador C3669
ms.date: 11/04/2016
f1_keywords:
- C3669
helpviewer_keywords:
- C3669
ms.assetid: be9c7ae4-e96f-47ab-922a-39a3537d5ca6
ms.openlocfilehash: 3b0ad3aa7395f5f423c8c36f547d4a0e2ad792c1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62214895"
---
# <a name="compiler-error-c3669"></a>Erro do compilador C3669

'member': especificador de substituição 'override' não permitido em funções de membro estático ou em construtores

Uma substituição foi especificada incorretamente. Para obter mais informações, consulte [substituições explícitas](../../extensions/explicit-overrides-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3669.

```
// C3669.cpp
// compile with: /clr
public ref struct R {
   R() override {}   // C3669
};
```