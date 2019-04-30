---
title: Compilador aviso (nível 1) C4165
ms.date: 11/04/2016
f1_keywords:
- C4165
helpviewer_keywords:
- C4165
ms.assetid: f5bed515-2290-4f88-8dab-b45d95fe26ef
ms.openlocfilehash: 4d6377730e262efafb38f5e714989e9075a77a04
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62391732"
---
# <a name="compiler-warning-level-1-c4165"></a>Compilador aviso (nível 1) C4165

'HRESULT' está sendo convertido em 'bool'; Tem certeza de que é isso que você deseja?

Ao usar um HRESULT em um [se](../../cpp/if-else-statement-cpp.md) instrução, o HRESULT será convertido em um [bool](../../cpp/bool-cpp.md) , a menos que você testa de maneira explícita para a variável como um HRESULT. Esse aviso é desativado por padrão.

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