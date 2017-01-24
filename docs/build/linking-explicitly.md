---
title: "Vinculando explicitamente | Microsoft Docs"
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
  - "vinculando explicitamente [C++]"
ms.assetid: 1e13d960-a195-4e6d-9864-7d8f3a701f4b
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Vinculando explicitamente
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Com vincular explícito, os aplicativos devem fazer uma chamada de função para carregar explicitamente em tempo de execução a DLL.  Para vincular explicitamente a um DLL, um aplicativo deve:  
  
-   Chame **LoadLibrary** \(ou uma função similar\) para carregar a DLL e obter um identificador de módulo.  
  
-   Chame **GetProcAddress** para obter um ponteiro de função para cada função exportada que o aplicativo deseja chamar.  Como os aplicativos são chamando as funções da DLL por meio de um ponteiro, o compilador não gerencia referências externas, então não há necessidade de vincular a uma biblioteca de importação.  
  
-   Chame **FreeLibrary** quando feito com o DLL.  
  
 Por exemplo:  
  
```  
typedef UINT (CALLBACK* LPFNDLLFUNC1)(DWORD,UINT);  
...  
  
HINSTANCE hDLL;               // Handle to DLL  
LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer  
DWORD dwParam1;  
UINT  uParam2, uReturnVal;  
  
hDLL = LoadLibrary("MyDLL");  
if (hDLL != NULL)  
{  
   lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL,  
                                           "DLLFunc1");  
   if (!lpfnDllFunc1)  
   {  
      // handle the error  
      FreeLibrary(hDLL);         
      return SOME_ERROR_CODE;  
   }  
   else  
   {  
      // call the function  
      uReturnVal = lpfnDllFunc1(dwParam1, uParam2);  
   }  
}  
```  
  
## O que você deseja fazer?  
  
-   [Link implicitamente](../Topic/Linking%20Implicitly.md)  
  
-   [Determine o método de vinculação a ser usado](../build/determining-which-linking-method-to-use.md)  
  
## Que você deseja saber mais?  
  
-   [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)  
  
-   [GetProcAddress](../build/getprocaddress.md)  
  
-   [FreeLibrary e AfxFreeLibrary](../build/freelibrary-and-afxfreelibrary.md)  
  
-   [O caminho de pesquisa usado pelo Windows para localizar uma DLL](../build/search-path-used-by-windows-to-locate-a-dll.md)  
  
## Consulte também  
 [Vinculando um executável a uma DLL](../build/linking-an-executable-to-a-dll.md)