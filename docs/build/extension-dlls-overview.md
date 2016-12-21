---
title: "DLLs de extens&#227;o: vis&#227;o geral | Microsoft Docs"
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
  - "Biblioteca AFXDLL"
  - "DLLs [C++], extensão"
  - "DLLs de extensão [C++], sobre DLLs de extensão"
  - "DLLs MFC [C++], DLLs de extensão"
  - "versões de DLLs compartilhadas [C++]"
ms.assetid: eb5e10b7-d615-4bc7-908d-e3e99b7b1d5f
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# DLLs de extens&#227;o: vis&#227;o geral
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma DLL da extensão MFC é uma DLL que implementa normalmente reutilizáveis as classes derivadas das classes existentes da biblioteca de classes do Microsoft.  Dlls de extensão são criados usando a versão da biblioteca de vínculo dinâmico\) nativa MFC \(também conhecido como a versão compartilhada MFC\).  Somente os executáveis \(MFC aplicativos ou DLL normais\) que é criado com uma versão compartilhada MFC podem usar uma DLL da extensão.  Com uma DLL da extensão, você pode derivar novas classes personalizadas MFC e depois oferecer essa versão estendida de MFC para aplicativos que chamam o DLL.  
  
 Dlls de extensão também podem ser usados passando objetos MFC\- derivadas entre o aplicativo e a DLL.  As funções de membro associadas ao objeto passado existem no módulo em que o objeto foi criado.  Como essas funções são exportadas corretamente ao usar a versão compartilhada MFC da DLL, você pode transmitir livremente MFC o ou ponteiros MFC\- derivados do objeto entre um aplicativo e as dlls de extensão que carregou.  
  
 Para obter um exemplo de uma DLL que atenda aos requisitos básicos de uma DLL de extensão, consulte o exemplo [DLLHUSK](http://msdn.microsoft.com/pt-br/dfcaa6ff-b8e2-4efd-8100-ee3650071f90)MFC.  Em particular, verifique os arquivos de Testdll1.cpp e de Testdll2.cpp.  
  
 Observe que o termo está AFXDLL mais utilizado na documentação do Visual C\+\+.  Uma DLL da extensão tem as mesmas características do AFXDLL antigo.  
  
## O que você deseja fazer?  
  
-   [Inicializar uma DLL da extensão](../build/initializing-extension-dlls.md)  
  
## Que você deseja saber mais?  
  
-   [DLLs de Extensão](../build/extension-dlls.md)  
  
-   [Usando o base de dados, o OLE, e as dlls de extensão de soquetes na DLL normais](../build/using-database-ole-and-sockets-extension-dlls-in-regular-dlls.md)  
  
-   [DLLs não MFC: Visão Geral](../Topic/Non-MFC%20DLLs:%20Overview.md)  
  
-   [DLL normais vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLL normais vinculadas dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [Criar uma DLL MFC](../mfc/reference/mfc-dll-wizard.md)  
  
## Consulte também  
 [Tipos de DLLs](../build/kinds-of-dlls.md)