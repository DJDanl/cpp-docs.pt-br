---
title: "Exportando fun&#231;&#245;es do C a serem usadas em execut&#225;veis da linguagem C ou C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro __cplusplus"
  - "exportando DLLs [C++], Funções C em executáveis C++"
  - "exportando funções [C++], Funções C em executáveis C++"
  - "funções [C], Executáveis C ou C++ e"
  - "funções [C], exportando"
ms.assetid: b51d6e5e-37cf-4c1c-b0bf-fcf188c82f00
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exportando fun&#231;&#245;es do C a serem usadas em execut&#225;veis da linguagem C ou C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Se você tiver funções em uma DLL escrito em C que você deseja acessar o módulo da linguagem c ou da linguagem C\+\+, você deve usar a macro de pré\-processador de **\_\_cplusplus** para determinar qual idioma está sendo compilado, e para declarar essas funções com esse tipo de C se sendo usado no módulo da linguagem c. criando  Se você usar esta técnica e fornece arquivos de cabeçalho para o DLL, essas funções podem ser usadas pelos usuários de 2.0 C e C\+\+ sem a alteração.  
  
 O código a seguir mostra um arquivo de cabeçalho que pode ser usado por aplicativos cliente c e C\+\+: 2.0  
  
```  
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
  
 Se você precisar vincular funções de C ao executável C\+\+ e os arquivos de cabeçalho de declaração da função não usam a técnica acima, no arquivo de origem C\+\+, faça o seguinte para impedir que o compilador decore os nomes de função c: 2.0  
  
```  
extern "C" {  
#include "MyCHeader.h"  
}  
```  
  
## O que você deseja fazer?  
  
-   [Exportação de uma DLL usando arquivos .def](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando \_\_declspec\(dllexport\)](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX\_EXT\_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Determine o método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar em um aplicativo usando \_\_declspec \(dllimport\)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Que você deseja saber mais?  
  
-   [Nomes decorados](../Topic/Decorated%20Names.md)  
  
-   [Especificações de vinculação](http://msdn.microsoft.com/pt-br/d2b0cff1-7798-4c38-9ac8-61c3bfe2bfb9)  
  
## Consulte também  
 [Exportando a partir de uma DLL](../build/exporting-from-a-dll.md)