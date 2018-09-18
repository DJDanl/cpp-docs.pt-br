---
title: Erro das LNK1306 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1306
dev_langs:
- C++
helpviewer_keywords:
- LNK1306
ms.assetid: fad1df6a-0bd9-412f-b0d1-7c9bc749c584
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7cc007a4a594c8593d7820365377f1c811b1e23c
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46050561"
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
