---
title: Aviso do compilador (nível 1) C4747
ms.date: 11/04/2016
f1_keywords:
- C4747
helpviewer_keywords:
- C4747
ms.assetid: af37befd-ba1f-4bdc-96e1-a953f7a2ad9c
ms.openlocfilehash: 2fd7f0960966a981d82d19e7b2533b1ffcd3bc00
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80175188"
---
# <a name="compiler-warning-level-1-c4747"></a>Aviso do compilador (nível 1) C4747

Chamando ' entrypoint ' gerenciado: o código gerenciado não pode ser executado sob o bloqueio do carregador, incluindo o ponto de entrada da DLL e chamadas atingidas do ponto de entrada da DLL

O compilador encontrou um ponto de entrada da DLL (provável) compilado para MSIL.  Devido a problemas potenciais com o carregamento de uma DLL cujo ponto de entrada foi compilado para MSIL, você não é altamente recomendável de compilar uma função de ponto de entrada de DLL para MSIL.

Para obter mais informações, consulte [inicialização de assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md) e [erro de ferramentas do vinculador LNK1306](../../error-messages/tool-errors/linker-tools-error-lnk1306.md).

### <a name="to-correct-this-error"></a>Para corrigir esse erro

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
