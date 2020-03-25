---
title: Aviso do compilador (nível 1) C4165
ms.date: 11/04/2016
f1_keywords:
- C4165
helpviewer_keywords:
- C4165
ms.assetid: f5bed515-2290-4f88-8dab-b45d95fe26ef
ms.openlocfilehash: bb036f7672a074e859d3e19083e256bd80c93578
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80176086"
---
# <a name="compiler-warning-level-1-c4165"></a>Aviso do compilador (nível 1) C4165

' HRESULT ' está sendo convertido em ' bool '; Tem certeza de que deseja?

Ao usar um HRESULT em uma instrução [If](../../cpp/if-else-statement-cpp.md) , o HRESULT será convertido em um [bool](../../cpp/bool-cpp.md) , a menos que você teste explicitamente a variável como um HRESULT. Esse aviso está desativado por padrão.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4165

```cpp
// C4165.cpp
// compile with: /W1
#include <windows.h>
#pragma warning(1:4165)

extern HRESULT hr;
int main() {
   if (hr) {
   // try either of the following ...
   // if (FAILED(hr)) { // C4165 expected
   // if (hr != S_OK) {
   }
}
```
