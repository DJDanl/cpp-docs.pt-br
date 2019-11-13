---
title: Aviso do compilador (nível 1) C4747
ms.date: 11/04/2016
f1_keywords:
- C4747
helpviewer_keywords:
- C4747
ms.assetid: af37befd-ba1f-4bdc-96e1-a953f7a2ad9c
ms.openlocfilehash: 623b29d345a850cc312f23e4c521aa0be5b47242
ms.sourcegitcommit: 458dcc794e3841919c01a3a5ff6b9a3767f8861b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/13/2019
ms.locfileid: "74052439"
---
# <a name="compiler-warning-level-1-c4747"></a>Aviso do compilador (nível 1) C4747

Chamando ' entrypoint ' gerenciado: o código gerenciado não pode ser executado sob o bloqueio do carregador, incluindo o ponto de entrada da DLL e chamadas atingidas do ponto de entrada da DLL

O compilador encontrou um ponto de entrada da DLL (provável) compilado para MSIL.  Devido a problemas potenciais com o carregamento de uma DLL cujo ponto de entrada foi compilado para MSIL, você não é altamente recomendável de compilar uma função de ponto de entrada de DLL para MSIL.

Para obter mais informações, consulte [inicialização de assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md) e [erro de ferramentas do vinculador LNK1306](../../error-messages/tool-errors/linker-tools-error-lnk1306.md).

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não compile o módulo com **/CLR**.

1. Marque a função de ponto de entrada com `#pragma unmanaged`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4747.

```cpp
// C4747.cpp
// compile with: /clr /c /W1
// C4747 expected
#include <windows.h>

// Uncomment the following line to resolve.
// #pragma unmanaged

BOOL WINAPI DllMain(HANDLE hInstance, ULONG Command, LPVOID Reserved) {
   return TRUE;
};
```