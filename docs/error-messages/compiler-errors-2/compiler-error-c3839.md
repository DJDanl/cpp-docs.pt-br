---
title: Erro do compilador C3839
ms.date: 11/04/2016
f1_keywords:
- C3839
helpviewer_keywords:
- C3839
ms.assetid: 0957faff-1e9f-439b-876b-85bd8d2c578d
ms.openlocfilehash: 19a1055a461d76856cc3bccbd9f8af0f0dcff356
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74754921"
---
# <a name="compiler-error-c3839"></a>Erro do compilador C3839

Não é possível alterar o alinhamento em um tipo gerenciado ou WinRT

O alinhamento de variáveis em tipos gerenciados ou Windows Runtime é controlado pelo CLR ou Windows Runtime e não pode ser modificado com [align](../../cpp/align-cpp.md).

O exemplo a seguir gera C3839:

```cpp
// C3839a.cpp
// compile with: /clr
ref class C
{
public:
   __declspec(align(32)) int m_j; // C3839
};

int main()
{
}
```
