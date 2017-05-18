---
title: Ferramentas de vinculador LNK1306 erro | Documentos do Microsoft
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
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 85ccd30abe8784a185fadc39dcdf91b8ac6cd125
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1306"></a>Erro das Ferramentas de Vinculador LNK1306
Não é possível gerenciar a função de ponto de entrada DLL; compilar para nativo  
  
 DllMain não pode ser compilado para MSIL; ele deve ser compilado para nativo.  
  
 Para resolver,  
  
-   Compile o arquivo que contém o ponto de entrada sem **/clr**.  
  
-   Coloque o ponto de entrada em um `#pragma unmanaged` seção.  
  
-   Para saber mais, veja  
  
-   [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [gerenciado, não gerenciado](../../preprocessor/managed-unmanaged.md)  
  
-   [Inicialização de Assemblies mistos](../../dotnet/initialization-of-mixed-assemblies.md)  
  
-   [Comportamento da biblioteca em tempo de execução](../../build/run-time-library-behavior.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera LNK1306.  
  
```  
// LNK1306.cpp  
// compile with: /clr /link /dll /entry:NewDllMain  
// LNK1306 error expected  
#include <windows.h>  
int __stdcall NewDllMain( HINSTANCE h, ULONG ulReason, PVOID pvReserved ) {  
   return 1;  
}  
```
