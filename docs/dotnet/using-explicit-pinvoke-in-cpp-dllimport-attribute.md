---
title: "Usando PInvoke explícito em C++ (atributo DllImport) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- marshaling [C++], platform invoke
- C++ Interop, platform invoke
- interop [C++], platform invoke
- platform invoke [C++], marshaling in C++
- data marshaling [C++], platform invoke
ms.assetid: 18e5218c-6916-48a1-a127-f66e22ef15fc
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 15c6d458af041479d14f41088f0038c519c6aa89
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="using-explicit-pinvoke-in-c-dllimport-attribute"></a>Usando PInvoke explícito em C++ (atributo DllImport)
O .NET Framework fornece recursos de invocação de plataforma (ou PInvoke) explícitos com o `Dllimport` atributo para permitir que aplicativos gerenciados chamar funções não gerenciadas empacotadas em DLLs. PInvoke explícito é necessário em situações onde APIs não gerenciadas são empacotadas como DLLs e o código-fonte não está disponível. Por exemplo, chamar funções Win32, requer PInvoke. Caso contrário, use implícita P {Invoke; consulte [usando Interop C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md) para obter mais informações.  
  
 PInvoke funciona usando <xref:System.Runtime.InteropServices.DllImportAttribute>. Esse atributo, que usa o nome da DLL como seu primeiro argumento, é colocado antes de uma declaração de função para cada ponto de entrada DLL que será usado. A assinatura da função deve corresponder ao nome de uma função exportada pela DLL (mas alguns conversão de tipo pode ser realizada implicitamente definindo o `DllImport` declarações em termos de tipos gerenciados.)  
  
 O resultado é um ponto de entrada gerenciado para cada função DLL nativa que contém o código de transição necessárias (ou conversão) e conversões de dados simples. Funções gerenciadas, em seguida, podem chamar a DLL por meio desses pontos de entrada. O código inserido em um módulo como resultado de PInvoke é totalmente gerenciado.  
  
## <a name="in-this-section"></a>Nesta seção  
  
-   [Chamando funções nativas de código gerenciado](../dotnet/calling-native-functions-from-managed-code.md)  
  
-   [Como chamar DLLs nativas de código gerenciado usando PInvoke](../dotnet/how-to-call-native-dlls-from-managed-code-using-pinvoke.md)  
  
-   [Como realizar marshaling de cadeias de caracteres usando PInvoke](../dotnet/how-to-marshal-strings-using-pinvoke.md)  
  
-   [Como realizar marshaling de estruturas usando PInvoke](../dotnet/how-to-marshal-structures-using-pinvoke.md)  
  
-   [Como realizar marshaling de matrizes usando PInvoke](../dotnet/how-to-marshal-arrays-using-pinvoke.md)  
  
-   [Como realizar marshaling de ponteiros de função usando PInvoke](../dotnet/how-to-marshal-function-pointers-using-pinvoke.md)  
  
-   [Como realizar marshaling de ponteiros inseridos usando PInvoke](../dotnet/how-to-marshal-embedded-pointers-using-pinvoke.md)  
  
## <a name="see-also"></a>Consulte também  
 [Chamando funções nativas de código gerenciado](../dotnet/calling-native-functions-from-managed-code.md)