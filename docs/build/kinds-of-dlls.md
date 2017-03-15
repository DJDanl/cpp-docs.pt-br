---
title: "Tipos de DLLs | Microsoft Docs"
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
  - "DLLs [C++], MFC"
  - "DLLs [C++], tipos"
  - "DLLs MFC [C++], tipos"
ms.assetid: f6a30db9-6138-4b2c-90cc-a17855e499a6
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tipos de DLLs
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico oferece informações para ajudá\-lo a determinar o tipo de DLL a ser compilada.  
  
##  <a name="_core_the_different_kinds_of_dlls_available_with_visual_c.2b2b"></a> Diferentes tipos de DLLs disponíveis  
 Usando o Visual C\+\+, você pode criar as dlls Win32 em C ou C\+\+ que não usam a biblioteca de classes \(MFC\) do Microsoft Foundation.  É possível criar um projeto de DLL não MFC com o assistente de aplicação Win32.  
  
 A própria biblioteca do MFC está disponível, em bibliotecas de vínculo estático ou um número de DLLs, com o assistente de DLL do MFC.  Se a sua DLL estiver usando o MFC, o Visual C\+\+ oferece suporte a três diferentes cenários de desenvolvimento do DLL:  
  
-   Compilando uma DLL regular que vincula estaticamente o MFC  
  
-   Compilando uma DLL regular que vincula dinamicamente o MFC  
  
-   Compilando uma DLL de extensão do MFC, que sempre vinculam dinamicamente o MFC  
  
### Que você deseja saber mais?  
  
-   [DLLs não MFC: Visão Geral](../Topic/Non-MFC%20DLLs:%20Overview.md)  
  
-   [DLL normais vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLL normais vinculadas dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [DLLs de extensão: visão geral](../build/extension-dlls-overview.md)  
  
-   [que tipo de DLL usar](#_core_which_kind_of_dll_to_use)  
  
##  <a name="_core_which_kind_of_dll_to_use"></a> Decidindo que tipo de DLL usar  
 Se a sua DLL não usa o MFC, use o Visual C\+\+ para criar uma DLL Win32 não MFC.  Vincular seu DLL ao MFC \(estaticamente ou dinamicamente\) ocupa espaço significativo em disco e na memória.  Você não deve vincular ao MFC a menos que a DLL realmente use o MFC.  
  
 Se a sua DLL for usar o MFC e for ser usada por aplicativos do MFC ou não MFC, você deverá compilar um DLL normal que se vincula dinamicamente ao MFC ou um DLL normal que se vincula estaticamente ao MFC.  Na maioria dos casos, você provavelmente desejará usar uma DLL normal que vincule dinamicamente ao MFC, porque o tamanho de arquivo da DLL será muito menor e a economia de memória em relação ao uso da versão compartilhada de MFC poderá ser significativa.  Se você vincular de forma estática ao MFC, o tamanho de arquivo da DLL será maior e usará memória extra porque ela carrega a própria cópia particular do código de biblioteca do MFC.  
  
 Compilar uma DLL que vincula dinamicamente ao MFC é mais rápido que compilar uma DLL que vincula estaticamente ao MFC, porque não é necessário vincular o próprio MFC.  Isso é especialmente verdadeiro em compilações de depuração onde o vinculador deverá compactar informações de depuração.  Ao vincular com uma DLL que já contém informações de depuração, há menos informações de depuração para compactar dentro da DLL.  
  
 Uma desvantagem de vincular dinamicamente ao MFC é que você deve distribuir as DLLs compartilhadas Mfcx0.dll e Msvcrxx.dll \(ou arquivos semelhantes\) com sua DLL.  As DLLs do MFC são livremente redistribuíveis, mas você ainda deve instalar as DLLs no seu programa de instalação.  Além disso, você deve enviar o Msvcrxx.dll, que contém a biblioteca em tempo de execução do C usada pelo programa e as próprias DLLs MFC.  
  
 Se a sua DLL for ser usada somente por executáveis MFC, você poderá escolher entre criar uma DLL normal ou uma DLL de extensão.  Se a sua DLL implementa as classes reutilizáveis derivadas de classes existentes do MFC, você precisa passar objetos derivados do MFC entre o aplicativo e o DLL, você deve criar uma extensão.  
  
 Se a sua DLL se vincula dinamicamente ao MFC, as DLLs do MFC podem ser redistribuídas com o DLL.  Essa arquitetura é particularmente útil para compartilhamento da biblioteca de classes entre vários arquivos executáveis para economizar espaço em disco e minimizar uso de memória.  
  
 Antes de versão 4.0, o Visual C\+\+ oferecia suporte apenas para dois tipos de DLL que usavam o MFC: USRDLLs e AFXDLLs.  As DLLs normais vinculadas estaticamente ao MFC têm as mesmas características da antiga USRDLL.  DLLs de extensão MFC têm as mesmas características que o AFXDLLs antigo.  
  
### Que você deseja saber mais?  
  
-   [DLLs não MFC: Visão Geral](../Topic/Non-MFC%20DLLs:%20Overview.md)  
  
-   [DLL normais vinculadas estaticamente ao MFC](../build/regular-dlls-statically-linked-to-mfc.md)  
  
-   [DLL normais vinculadas dinamicamente ao MFC](../Topic/Regular%20DLLs%20Dynamically%20Linked%20to%20MFC.md)  
  
-   [DLLs de extensão: visão geral](../build/extension-dlls-overview.md)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)