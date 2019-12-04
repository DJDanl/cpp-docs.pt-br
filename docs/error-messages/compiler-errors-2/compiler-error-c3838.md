---
title: Erro do compilador C3838
ms.date: 11/04/2016
f1_keywords:
- C3838
helpviewer_keywords:
- C3838
ms.assetid: d6f470c2-131a-4a8c-843a-254acd43da83
ms.openlocfilehash: 468fc5e8cb6b3a76880f12fe0aab14810f458a90
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74741346"
---
# <a name="compiler-error-c3838"></a>Erro do compilador C3838

Não é possível herdar explicitamente de ' type '

O `type` especificado não pode atuar como uma classe base em nenhuma classe.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3838:

```cpp
// C3838a.cpp
// compile with: /clr /c
public ref class B : public System::Enum {};   // C3838
```
