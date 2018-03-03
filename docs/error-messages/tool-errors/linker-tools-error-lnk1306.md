---
title: Ferramentas de vinculador LNK1306 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1306
dev_langs:
- C++
helpviewer_keywords:
- LNK1306
ms.assetid: fad1df6a-0bd9-412f-b0d1-7c9bc749c584
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 32b6589fa5e4d7dc02ccb9a6c3157c109725b895
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1306"></a>Erro das Ferramentas de Vinculador LNK1306  
  
> Função de ponto de entrada DLL não pode ser gerenciada; compilar para nativo  
  
`DllMain`não podem ser compilados para MSIL; ele deve ser compilado para nativo.  
  
Para resolver esse problema,  
  
-   Compile o arquivo que contém o ponto de entrada sem **/clr**.  
  
-   Coloque o ponto de entrada em um `#pragma unmanaged` seção.  
  
Para obter mais informações, consulte:  
  
-   [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
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
