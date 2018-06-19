---
title: Ferramentas de vinculador LNK1306 erro | Microsoft Docs
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
ms.openlocfilehash: bb340a4c28f94f18e0c4b65bea8749394e002bd3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33300492"
---
# <a name="linker-tools-error-lnk1306"></a>Erro das Ferramentas de Vinculador LNK1306  
  
> Função de ponto de entrada DLL não pode ser gerenciada; compilar para nativo  
  
`DllMain` não podem ser compilados para MSIL; ele deve ser compilado para nativo.  
  
Para resolver esse problema,  
  
-   Compile o arquivo que contém o ponto de entrada sem **/clr**.  
  
-   Coloque o ponto de entrada em um `#pragma unmanaged` seção.  
  
Para obter mais informações, consulte:  
  
-   [/clr (compilação do Common Language Runtime)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md)  
  
-   [Inicialização de assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md)  
  
-   [Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++](../../build/run-time-library-behavior.md)  
  
## <a name="example"></a>Exemplo  
  
O exemplo a seguir gera LNK1306.  
  
```cpp  
// LNK1306.cpp  
// compile with: /clr /link /dll /entry:NewDllMain  
// LNK1306 error expected  
#include <windows.h>  
int __stdcall NewDllMain( HINSTANCE h, ULONG ulReason, PVOID pvReserved ) {  
   return 1;  
}  
```  
  
Para corrigir esse problema, não use a opção /clr para compilar este arquivo ou use um `#pragma` diretiva para colocar a definição de ponto de entrada em uma seção não gerenciada, conforme mostrado neste exemplo:  
  
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
