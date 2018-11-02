---
title: Compilador aviso (nível 1) C4747
ms.date: 11/04/2016
f1_keywords:
- C4747
helpviewer_keywords:
- C4747
ms.assetid: af37befd-ba1f-4bdc-96e1-a953f7a2ad9c
ms.openlocfilehash: ecaabd482049771b1d3915470a2be7a52e36d361
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50462381"
---
# <a name="compiler-warning-level-1-c4747"></a>Compilador aviso (nível 1) C4747

Chamar 'entrypoint' gerenciado: código gerenciado não pode ser executado sob bloqueio do carregador, incluindo o ponto de entrada da DLL e chamadas acessadas do ponto de entrada DLL

O compilador encontra um ponto de entrada DLL (provável) compilado para MSIL.  Devido a problemas potenciais com o carregamento de uma DLL cujo ponto de entrada tiver sido compilado em MSIL, você é altamente desaconselhável de compilar uma função de ponto de entrada da DLL para MSIL.

Para obter mais informações, consulte [inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md) e [erro das ferramentas de vinculador LNK1306](../../error-messages/tool-errors/linker-tools-error-lnk1306.md).

### <a name="to-correct-this-error"></a>Para corrigir este erro

1. Não compilar o módulo com **/clr**.

1. Marcar a função de ponto de entrada com `#pragma unmanaged`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4747.

```
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