---
title: "Usando PInvoke expl&#237;cito em C++ (atributo DllImport) | Microsoft Docs"
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
  - "Interoperabilidade C++, invocação de plataforma"
  - "realização de marshaling em dados [C++], invocação de plataforma"
  - "interoperabilidade [C++], invocação de plataforma"
  - "realização de marshaling [C++], invocação de plataforma"
  - "invocação de plataforma [C++], realizando marshaling em C++"
ms.assetid: 18e5218c-6916-48a1-a127-f66e22ef15fc
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando PInvoke expl&#237;cito em C++ (atributo DllImport)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O .NET Framework fornece recursos explícitos de invocação de plataforma \(ou o PInvoke\) com o atributo de `Dllimport` para permitir que os aplicativos gerenciados chamar funções não gerenciados DLL internos empacotados.  PInvoke explícito é necessário em situações em que as APIs não gerenciados são empacotados porque as dlls e o código\-fonte não estão disponíveis.  A chamada do Win32 funciona, por exemplo, requer PInvoke.  Se não, use implícito invocar; {P consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md) para obter mais informações.  
  
 Trabalho de PInvoke usando <xref:System.Runtime.InteropServices.DllImportAttribute>.  Esse atributo, que usa o nome da DLL como seu primeiro argumento, será colocado antes de uma declaração de função para cada ponto de entrada da DLL que será usado.  A assinatura da função deve corresponder ao nome de uma função exportada pela DLL \(mas por qualquer conversão de tipos pode ser executado definindo implicitamente as declarações de `DllImport` em termos de tipos gerenciados.\)  
  
 O resultado é um ponto de entrada gerenciado para cada função de DLL nativa de que contém o código necessário de transição \(ou o thunk\) e conversões de dados simples.  As funções gerenciados podem chamar na DLL esses pontos de entrada.  O código inserido em um módulo como o resultado de PInvoke é totalmente gerenciado e PInvoke explícito tem suporte para **\/clr**, **\/clr:pure**, e compilações de **\/clr:safe** .  Para obter mais informações, consulte [Código puro e verificável](../dotnet/pure-and-verifiable-code-cpp-cli.md).  
  
## Nesta seção  
  
-   [Chamando funções nativas a partir do código gerenciado](../dotnet/calling-native-functions-from-managed-code.md)  
  
-   [Como chamar DLLs nativas a partir do código gerenciado usando PInvoke](../dotnet/how-to-call-native-dlls-from-managed-code-using-pinvoke.md)  
  
-   [Como realizar marshaling de cadeias de caracteres usando PInvoke](../dotnet/how-to-marshal-strings-using-pinvoke.md)  
  
-   [Como realizar marshaling de estruturas usando PInvoke](../dotnet/how-to-marshal-structures-using-pinvoke.md)  
  
-   [Como realizar marshaling de matrizes usando PInvoke](../dotnet/how-to-marshal-arrays-using-pinvoke.md)  
  
-   [Como realizar marshaling de ponteiros de função usando PInvoke](../dotnet/how-to-marshal-function-pointers-using-pinvoke.md)  
  
-   [Como realizar marshaling de ponteiros inseridos usando PInvoke](../dotnet/how-to-marshal-embedded-pointers-using-pinvoke.md)  
  
## Consulte também  
 [Chamando funções nativas a partir do código gerenciado](../dotnet/calling-native-functions-from-managed-code.md)