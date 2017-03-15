---
title: "LoadLibrary e AfxLoadLibrary | Microsoft Docs"
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
  - "LoadLibrary"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AfxLoadLibrary"
  - "DLLs [C++], AfxLoadLibrary"
  - "DLLs [C++], LoadLibrary"
  - "vinculando explicitamente [C++]"
  - "Método LoadLibrary"
ms.assetid: b4535d19-6243-4146-a31a-a5cca4c7c9e3
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# LoadLibrary e AfxLoadLibrary
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os processos chamam [LoadLibrary](http://go.microsoft.com/fwlink/p/?LinkID=259187) \(ou [AfxLoadLibrary](../Topic/AfxLoadLibrary.md)\) para vincular explicitamente para uma DLL.  Se a função tiver êxito, ela mapeará a DLL especificada no espaço de endereço do processo de chamada e retorna um identificador para a DLL que pode ser usado com outras funções em vinculação explícita. Por exemplo, `GetProcAddress` e `FreeLibrary`.  
  
 tentativas de`LoadLibrary` de localizar o DLL usando a mesma sequência de pesquisa que é usada para vínculo implícito.  Se o sistema não pode localizar a DLL ou se a função de ponto de entrada retorna FALSA, `LoadLibrary` retornam NULOS.  Se a chamada à `LoadLibrary` especificar um módulo DLL que já está mapeado no espaço de endereço do processo de chamada, a função retornará uma alça de DLL e incrementará a contagem de referência do módulo.  
  
 Se a DLL tem uma função de ponto de entrada, o sistema operacional chama a função no contexto da thread chamado `LoadLibrary`.  A função de ponto de entrada não será chamada se a DLL já estiver anexada ao processo por causa de uma chamada anterior a `LoadLibrary` sem chamada correspondente chamada para a função `FreeLibrary`.  
  
 Para aplicativos MFC que carregam DLLs de extensão, recomendamos usar `AfxLoadLibrary` em vez de `LoadLibrary`.  `AfxLoadLibrary` controla a sincronização do thread antes de você chamar `LoadLibrary`.  A interface \(protótipo de função\) para `AfxLoadLibrary` é igual a `LoadLibrary`.  
  
 Se o Windows não pode carregar a DLL, o processo pode tentar recuperar\-se do erro.  Por exemplo, o processo pode notificar o usuário sobre o erro e pedir que o usuário especifique outro caminho para a DLL.  
  
> [!IMPORTANT]
>  Se o código é executado no Windows NT 4, Windows 2000 ou Windows XP \(antes de SP1\), certifique\-se de especificar o caminho completo de quaisquer DLLs.  Nesses sistemas operacionais, o diretório atual é procurado primeiro quando arquivos são carregados.  Se você não qualificar o caminho do arquivo, um arquivo que não seja o pretendido poderá ser carregado.  
  
## O que você deseja fazer?  
  
-   [Link implicitamente](../Topic/Linking%20Implicitly.md)  
  
-   [Determine o método de vinculação a ser usado](../build/determining-which-linking-method-to-use.md)  
  
## Que você deseja saber mais?  
  
-   [O caminho de pesquisa que é usado pelo Windows para localizar uma DLL](../build/search-path-used-by-windows-to-locate-a-dll.md)  
  
-   [FreeLibrary e AfxFreeLibrary](../build/freelibrary-and-afxfreelibrary.md)  
  
-   [GetProcAddress](../build/getprocaddress.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)   
 [LoadLibrary](http://go.microsoft.com/fwlink/p/?LinkID=259187)   
 [AfxLoadLibrary](../Topic/AfxLoadLibrary.md)