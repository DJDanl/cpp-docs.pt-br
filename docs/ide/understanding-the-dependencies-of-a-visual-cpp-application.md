---
title: "No&#231;&#245;es b&#225;sicas sobre as depend&#234;ncias de um aplicativo do Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "implantação de aplicativos [C++], dependências"
  - "dependências [C++], implantação de aplicativos e"
  - "Dependency Walker"
  - "depends.exe"
  - "implantando aplicativos [C++], dependências"
  - "DLLs [C++], dependências"
  - "Utilitário DUMPBIN"
  - "bibliotecas [C++], problemas de implantação de aplicativos"
ms.assetid: 62a44c95-c389-4c5f-82fd-07d7ef09dbf9
caps.latest.revision: 20
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# No&#231;&#245;es b&#225;sicas sobre as depend&#234;ncias de um aplicativo do Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para determinar de quais bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] um aplicativo depende, você pode ver as propriedades do projeto.  \(No Solution Explorer, clique com botão direito no projeto e escolha **propriedades** para abrir o **Property Pages** caixa de diálogo.\) Você também pode usar o Dependency Walker \(depends.exe\), que fornece um panorama mais abrangente das dependências.  
  
 Na caixa de diálogo **Páginas de Propriedades**, você pode examinar várias páginas em **Propriedades de Configuração** para entender as dependências.  Por exemplo, se seu projeto usa as bibliotecas MFC e você escolher **uso do MFC**, **Usar MFC em uma DLL compartilhada** sobre o **Propriedades de configuração**, **geral** página, seu aplicativo em tempo de execução depende de DLLs MFC como. dll da mfc \< versão \>.  Se seu aplicativo não usar MFC, poderá depender da biblioteca CRT se você escolher um valor da **Biblioteca em Tempo de Execução** de **DLL de Depuração Multi\-threaded \(\/MDd\)** ou **DLL Multi\-threaded \(\/MD\)** na página **Propriedades de Configuração**, **C\/C\+\+**, **Geração de Código**.  
  
 Uma forma mais abrangente para determinar quais DLLs seu aplicativo depende é usar o Dependency Walker \(depends.exe\) para abrir o aplicativo.  Você pode baixar a ferramenta a partir do [Dependency Walker](http://go.microsoft.com/fwlink/p/?LinkId=132640) site da web.  
  
 Usando depends.exe, você pode examinar uma lista de DLLs vinculadas ao aplicativo em tempo de carregamento e uma lista de suas DLLs carregadas com atraso.  Se você quiser obter uma lista completa de DLLs carregadas dinamicamente em tempo de execução, você pode usar o recurso de criação de perfil em depends.exe para testar o aplicativo até ter certeza de que todos os caminhos de código que foram utilizados.  Quando você terminar a sessão de criação de perfil, depends.exe mostra quais DLLs foram carregadas dinamicamente em tempo de execução.  
  
 Quando você usar o depends.exe, lembre\-se de que uma DLL pode depender de outra DLL ou de uma versão específica de uma DLL.  Você pode usar o depends.exe no computador de desenvolvimento ou em um computador de destino.  No computador de desenvolvimento, o depends.exe relata as DLLs que são necessárias para oferecer suporte a um aplicativo.  Se você tiver dificuldade para executar um aplicativo em um computador de destino, copie o depends.exe para ele e abra o aplicativo na ferramenta para que você possa determinar se alguma DLL necessária está ausente ou incorreta.  
  
 Quando você souber de quais DLLs seu aplicativo depende, poderá determinar quais precisam ser redistribuídas com seu aplicativo ao implantá\-lo em outro computador.  Na maioria dos casos, não é necessário redistribuir DLLs do sistema, mas talvez seja necessário redistribuir DLLs para bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  Para obter mais informações, consulte [Determinando quais DLLs devem ser redistribuídas](../ide/determining-which-dlls-to-redistribute.md).  
  
## Consulte também  
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)