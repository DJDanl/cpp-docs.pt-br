---
title: "GetProcAddress | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "GetProcAddress"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DLLs [C++], GetProcAddress"
  - "Método GetProcAddress"
  - "exportações ordinais [C++]"
ms.assetid: 48d14ae0-47ea-4c5d-96b1-2c158f1a26af
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# GetProcAddress
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os processos que estejam vinculando explicitamente para uma DLL chamam [GetProcAddress](http://msdn.microsoft.com/library/windows/desktop/ms683212) para obter o endereço de uma função exportada na DLL.  Você usa o ponteiro de função retornado para chamar a função DLL.  **GetProcAddress** leva como parâmetros o identificador de módulo DLL \(retornado por **LoadLibrary**, por `AfxLoadLibrary` ou por **GetModuleHandle**\) e usa o nome da função que você deseja chamar ou o ordinal de exportação da função.  
  
 Como você está chamando a função DLL por um ponteiro e não há nenhuma verificação de tipo em tempo de compilação, verifique se os parâmetros para a função estão corretos, de modo que você não ultrapasse a memória alocada na pilha e cause uma violação de acesso.  Uma forma de ajudar a oferecer segurança de tipos é examinar os protótipos de função das funções exportadas e criar typedefs correspondentes para ponteiros de função.  Por exemplo:  
  
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
  
 Como você especifica a função que deseja ao chamar **GetProcAddress** depende de como a DLL foi criada.  
  
 É possível obter o ordinal de exportação somente se a DLL à qual você esta se conectando for compilada com um arquivo de definição de módulo \(.def\) e se os ordinais estiverem listados com funções na seção **EXPORTS** do arquivo .def de DLL.  A chamada **GetProcAddress** com um ordinal de exportação, em oposição ao nome da função, é ligeiramente mais rápido se a DLL tem muitas funções exportadas porque os ordinais de exportação servem como índices na tabela de exportação da DLL.  Com um ordinal de exportação, o **GetProcAddress** pode localizar a função de forma direta, em vez de comparar o nome especificado com os nomes de função na tabela de exportação de DLL.  No entanto, você deve chamar **GetProcAddress** com um ordinal de exportação somente se você tiver controle sobre a atribuição dos ordinais para as funções exportadas no arquivo .def.  
  
## O que você deseja fazer?  
  
-   [Link implicitamente](../Topic/Linking%20Implicitly.md)  
  
-   [Determine o método de vinculação a ser usado](../build/determining-which-linking-method-to-use.md)  
  
## Que você deseja saber mais?  
  
-   [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)  
  
-   [\<caps:sentence id\="tgt17" sentenceid\="8c920606bb67e2587dd3c3e5cf977593" class\="tgtSentence"\>FreeLibrary\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms683152)  
  
-   [Exportando a partir de uma DLL usando arquivos DEF](../build/exporting-from-a-dll-using-def-files.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)