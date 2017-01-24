---
title: "Recursos localizados em aplicativos MFC: DLLs sat&#233;lites | Microsoft Docs"
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
  - "DLLs [C++], localizando MFC"
  - "localização [C++], Recursos MFC"
  - "recursos localizados [C++]"
  - "DLLs MFC [C++], localizando"
  - "suporte a vários idiomas [C++]"
  - "DLLs somente de recursos [C++]"
  - "DLLs somente de recursos [C++], Aplicativos MFC"
  - "recursos [MFC], localizando"
  - "DLLs satélites [C++]"
ms.assetid: 3a1100ae-a9c8-47b5-adbd-cbedef5992ef
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Recursos localizados em aplicativos MFC: DLLs sat&#233;lites
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC a versão 7,0 e posterior oferece suporte aprimorado para a DLL satélite, um recurso que ajuda a criar aplicativos localizados em vários idiomas.  Uma DLL satélite é [a DLL de recurso somente](../build/creating-a-resource-only-dll.md) que contém os recursos de um aplicativo localizados para um idioma específico.  Quando o aplicativo inicia a execução, o MFC carregará automaticamente o recurso localizada o mais apropriado para o ambiente.  Por exemplo, você pode ter um aplicativo com recursos de idioma inglês com dois DLL satélite, um que contém uma tradução francesa de seus recursos e outro que contém uma tradução alemão.  Quando o aplicativo for executado em um sistema de idioma inglês, use os recursos em inglês.  Se for executado em um sistema francês, usa os recursos franceses; se for executado em um sistema alemão, usar os recursos de alemão.  
  
 Para dar suporte a recursos localizada em um aplicativo, MFC tentativas de MFC de carregar uma DLL satélite que contém os recursos encontrados em um idioma específico.  Os DLL satélite são nomeados *ApplicationNameXXX.dll*, onde ApplicationNameis o nome do arquivo .dll ou de MFC usando o, e o XXXIS o código de três letras para o idioma dos recursos \(por exemplo, “POR” ou “DEU "\).  
  
 MFC O tentar carregar a DLL de recurso para cada um dos seguintes idiomas em ordem, parando quando encontrar um:  
  
1.  \(Windows 2000 ou posterior\) somente o idioma padrão da interface do usuário do usuário atual, como retornado de GetUserDefaultUILanguage\(\) a API do Win32.  
  
2.  \(Windows 2000 ou posterior\) somente o idioma padrão da interface do usuário do usuário atual, sem qualquer subidioma específico \(isto é, o ENC \[\] inglês canadense se torna \[POR E.U.  Inglês\]\).  
  
3.  O idioma da interface do usuário padrão do sistema.  No Windows 2000 ou posterior, isto é retornado de GetSystemDefaultUILanguage\(\) API.  Em outras plataformas, esse é o idioma do sistema operacional próprio.  
  
4.  O idioma da interface do usuário padrão do sistema, sem qualquer subidioma específico.  
  
5.  Falso um idioma com o código LOC de 3 letras.  
  
 Se o MFC não encontrar DLL satélite, o usa recursos que estão contidos no próprio aplicativo.  
  
 Como exemplo, suponha que um aplicativo LangExample.exe usa o MFC e o estiver executando o sistema da interface do usuário do Windows 2000 em vários; o idioma do sistema interface do usuário é ENU \[E.U.  O inglês\] e o idioma atual da interface de usuário do usuário são definidos como FRC \[\] francês canadense.  O MFC procura os seguintes dlls na seguinte ordem:  
  
1.  LangExampleFRC.dll \(linguagem de interface de usuário do usuário\).  
  
2.  LangExampleFRA.dll \(linguagem de interface de usuário do usuário sem subidioma, neste exemplo de francês \(França\).  
  
3.  LangExampleENU.dll \(linguagem de interface do usuário do sistema\).  
  
4.  LangExampleLOC.dll.  
  
 Se nenhum desses DLL for encontrado, o MFC usa os recursos em LangExample.exe.  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)   
 [TN057: localização de componentes MFC](../mfc/tn057-localization-of-mfc-components.md)