---
title: Exportando funções C para uso em C ou executáveis da linguagem C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- functions [C], exporting
- functions [C], C or C++ executables and
- __cplusplus macro
- exporting DLLs [C++], C functions in C++ executables
- exporting functions [C++], C functions in C++ executables
ms.assetid: b51d6e5e-37cf-4c1c-b0bf-fcf188c82f00
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ee1d572bbfaa31ac626bfeb2b6ed7f61604628c8
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="exporting-c-functions-for-use-in-c-or-c-language-executables"></a>Exportando funções do C a serem usadas em executáveis da linguagem C ou C++  
  
Se você tiver funções em uma DLL escrita em C que você deseja acessar um linguagem C ou o módulo de linguagem do C++, você deve usar o **cplusplus** macro de pré-processador para determinar o idioma que está sendo compilado e, em seguida, declare essas funções com vínculo a C se está sendo usado de um módulo de linguagem do C++. Se você usar essa técnica e fornece os arquivos de cabeçalho para a DLL, essas funções podem ser usadas por usuários C e C++ sem alterações.  
  
O código a seguir mostra um arquivo de cabeçalho que pode ser usado por aplicativos cliente C e C++:  
  
```h  
// MyCFuncs.h  
#ifdef __cplusplus  
extern "C" {  // only need to export C interface if  
              // used by C++ source code  
#endif  
  
__declspec( dllimport ) void MyCFunc();  
__declspec( dllimport ) void AnotherCFunc();  
  
#ifdef __cplusplus  
}  
#endif  
```  
  
Se você precisa vincular funções C para o executável do C++ e os arquivos de cabeçalho de declaração de função não tem usado a técnica acima, o arquivo de origem do C++, faça o seguinte para impedir que o compilador decorar os nomes de função C:  
  
```cpp  
extern "C" {  
#include "MyCHeader.h"  
}  
```  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Exportar de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Determinar qual método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Nomes decorados](../build/reference/decorated-names.md)  
  
-   [Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)  
  
## <a name="see-also"></a>Consulte também  
 [Exportando de uma DLL](../build/exporting-from-a-dll.md)