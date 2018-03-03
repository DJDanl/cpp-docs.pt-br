---
title: "DLLs de extensão: Visão geral | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- AFXDLL library
- MFC DLLs [C++], MFC extension DLLs
- DLLs [C++], extension
- shared DLL versions [C++]
- extension DLLs [C++], about MFC extension DLLs
ms.assetid: eb5e10b7-d615-4bc7-908d-e3e99b7b1d5f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 407ed0c63dce8e350c24ac5f260876fb6ab47576
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-extension-dlls-overview"></a>DLLs de extensão do MFC: Visão geral
Uma extensão do MFC DLL é uma DLL que implementa normalmente reutilizáveis classes derivadas de classes de biblioteca Microsoft Foundation Class existentes. DLLs de extensão do MFC são criadas usando a versão da biblioteca de vínculo dinâmico do MFC (também conhecido como a versão compartilhada do MFC). Somente MFC executáveis (aplicativos ou a DLLs normais do MFC) que são criados com a versão compartilhada do MFC podem usar uma DLL de extensão do MFC. Com uma extensão MFC DLL, você pode derivar novas classes personalizadas de MFC e, em seguida, oferecer essa versão estendida do MFC para aplicativos que chamam a DLL.  
  
 DLLs de extensão também podem ser usados para transmitir objetos derivados de MFC entre o aplicativo e a DLL. As funções de membro associadas ao objeto passado existem no módulo onde o objeto foi criado. Como essas funções são exportadas corretamente ao usar a versão DLL compartilhada do MFC, você pode passar livremente MFC ou ponteiros para objetos derivados MFC entre um aplicativo e a extensão MFC DLLs, ele carrega.  
  
 Para obter um exemplo de uma DLL que atenda aos requisitos básicos de uma DLL de extensão do MFC, consulte o exemplo MFC [DLLHUSK](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/advanced/dllhusk). Em particular, examine os arquivos Testdll1.cpp e Testdll2.cpp.  
  
 Observe que o termo AFXDLL não é usado na documentação do Visual C++. Uma DLL de extensão do MFC tem as mesmas características que o antigo AFXDLL.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Inicializar uma DLL de extensão do MFC](../build/run-time-library-behavior.md#initializing-extension-dlls)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [DLLs de extensão de MFC](../build/extension-dlls.md)  
  
-   [Usando banco de dados, OLE e DLLs de extensão de MFC de soquetes em DLLs MFC regulares](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)  
  
-   [DLLs não MFC: visão geral](../build/non-mfc-dlls-overview.md)  
  
-   [DLLs normais do MFC vinculado estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLLs MFC regulares vinculadas dinamicamente a MFC](../build/regular-dlls-dynamically-linked-to-mfc.md)  
  
-   [Criar uma DLL MFC](../mfc/reference/mfc-dll-wizard.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de DLLs](../build/kinds-of-dlls.md)