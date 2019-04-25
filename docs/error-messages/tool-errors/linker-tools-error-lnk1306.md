---
title: Erro das Ferramentas de Vinculador LNK1306
ms.date: 11/04/2016
f1_keywords:
- LNK1306
helpviewer_keywords:
- LNK1306
ms.assetid: fad1df6a-0bd9-412f-b0d1-7c9bc749c584
ms.openlocfilehash: ddaa8797e0cf8ff617408aedc770b21cc656cec4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160452"
---
# <a name="linker-tools-error-lnk1306"></a>Erro das Ferramentas de Vinculador LNK1306

> Função de ponto de entrada DLL não pode ser gerenciada; compilar para nativo

`DllMain` não podem ser compilados para MSIL; ele deve ser compilado para nativo.

Para resolver esse problema,

- Compile o arquivo que contém o ponto de entrada sem **/clr**.

- Coloque o ponto de entrada em um `#pragma unmanaged` seção.

Para obter mais informações, consulte:

- [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)

- [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md)

- [Inicialização de assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md)

- [Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++](../../build/run-time-library-behavior.md)

## <a name="example"></a>Exemplo

O exemplo a seguir gera das LNK1306.

```cpp
// LNK1306.cpp
// compile with: /clr /link /dll /entry:NewDllMain
// LNK1306 error expected
#include <windows.h>
int __stdcall NewDllMain( HINSTANCE h, ULONG ulReason, PVOID pvReserved ) {
   return 1;
}
```

Para corrigir esse problema, não use a opção /clr para compilar esse arquivo, ou usar um `#pragma` diretiva para colocar a definição de ponto de entrada em uma seção não gerenciada, conforme mostrado neste exemplo:

```cpp
// LNK1306fix.cpp
// compile with: /clr /link /dll /entry:NewDllMain
#include <windows.h>
#pragma managed(push, off)
int __stdcall NewDllMain( HINSTANCE h, ULONG ulReason, PVOID pvReserved ) {
   return 1;
}
#pragma managed(pop)
```
