---
title: FreeLibrary e AfxFreeLibrary | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- FreeLibrary
- AfxFreeLibrary
dev_langs: C++
helpviewer_keywords:
- extension DLLs [C++], unloading
- AfxFreeLibrary method
- unloading DLLs
- FreeLibrary method
- DLLs [C++], linking
- explicit linking [C++]
- DLLs [C++], unloading
ms.assetid: 4a48d290-3971-43e9-8e97-ba656cd0c8f8
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3d5f2c1cce980f97e7a99ff2347daceac05f984f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="freelibrary-and-afxfreelibrary"></a>FreeLibrary e AfxFreeLibrary
Processos que explicitamente vincular a uma chamada DLL a [FreeLibrary](http://go.microsoft.com/fwlink/p/?LinkID=259188) funcionar quando o módulo DLL não é mais necessário. Essa função diminui a contagem de referência do módulo e, se a contagem de referência for zero, cancela o mapeamento do espaço de endereço de processo.  
  
 Em um aplicativo MFC, use [AfxFreeLibrary](../mfc/reference/application-information-and-management.md#afxfreelibrary) em vez de `FreeLibrary` descarregar uma DLL de extensão do MFC. A interface (protótipo de função) para `AfxFreeLibrary` é o mesmo que `FreeLibrary`.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Como vincular implicitamente para uma DLL](../build/linking-an-executable-to-a-dll.md#linking-implicitly)  
  
-   [Determinar qual método de associação usar](../build/linking-an-executable-to-a-dll.md#determining-which-linking-method-to-use)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)  
  
-   [GetProcAddress](../build/getprocaddress.md)  
  
## <a name="see-also"></a>Consulte também  
 [DLLs no Visual C++](../build/dlls-in-visual-cpp.md)   
 [FreeLibrary](http://go.microsoft.com/fwlink/p/?LinkID=259188)   
 [AfxFreeLibrary](../mfc/reference/application-information-and-management.md#afxfreelibrary)