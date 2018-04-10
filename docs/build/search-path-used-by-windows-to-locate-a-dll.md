---
title: Pesquisar o caminho usado pelo Windows para localizar uma DLL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- searching [C++], DLLs
- DLLs [C++], Windows search path
- Windows [C++], DLL search path
- known DLL searches [C++]
- locating DLLs
- finding DLLs
- search paths [C++]
ms.assetid: 84bfb380-ad7b-4962-b2d0-51b19a45f1bb
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 53350ed473226c86dd4fefa93cff376a371dedf7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="search-path-used-by-windows-to-locate-a-dll"></a>demarcador de pesquisa usado pelo Windows para localizar uma DLL
Com a vinculação implícita e explícita, o Windows primeiro procura por "DLLs conhecidas," como Kernel32 e User32. dll. O Windows, em seguida, procura as DLLs na sequência a seguir:  
  
1.  O diretório onde o módulo executável para o processo atual está localizado.  
  
2.  O diretório atual.  
  
3.  O diretório de sistema do Windows. O **GetSystemDirectory** função recupera o caminho desse diretório.  
  
4.  O diretório do Windows. O **GetWindowsDirectory** função recupera o caminho desse diretório.  
  
5.  As pastas listadas na variável de ambiente PATH.  
  
    > [!NOTE]
    >  Não é usada a variável de ambiente LIBPATH.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Como vincular implicitamente para uma DLL](../build/linking-an-executable-to-a-dll.md#linking-implicitly)  
  
-   [Como vincular explicitamente para uma DLL](../build/linking-an-executable-to-a-dll.md#linking-explicitly)  
  
-   [Determinar qual método de associação usar](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)