---
title: Exportando funções C++ para uso em executáveis da linguagem C | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- functions [C++], C++ functions in C executables
- exporting DLLs [C++], C++ functions in C executables
- exporting functions [C++], C++ functions in C executables
- functions [C++], exporting
ms.assetid: 80b9e982-f52d-4312-a891-f73cc69f3c2b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cf5f348675752ff9c0b548693c442812fa6be697
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367580"
---
# <a name="exporting-c-functions-for-use-in-c-language-executables"></a>Exportando funções do C++ a serem usadas em executáveis da linguagem C  
  
Se você tem funções em uma DLL escrita em C++ que você deseja acessar de um módulo de linguagem C, você deve declarar essas funções com vínculo a C em vez de vinculação do C++. A menos que especificado em contrário, o compilador do C++ usa fortemente tipado (também conhecido como decoração do nome) de nomenclatura do C++ e C++ chamando convenções, o que podem ser difícil de chamada de C.  
  
Para especificar o vínculo a C, especifique `extern "C"` para suas declarações de função. Por exemplo:  
  
```  
extern "C" __declspec( dllexport ) int MyFunc(long parm1);  
```  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Exportar de uma DLL usando arquivos. def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções C para uso em executáveis C ou linguagem C++](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Determinar qual método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Nomes decorados](../build/reference/decorated-names.md)  
  
-   [Usando extern para especificar a ligação](../cpp/using-extern-to-specify-linkage.md)  
  
## <a name="see-also"></a>Consulte também  
 [Exportando de uma DLL](../build/exporting-from-a-dll.md)