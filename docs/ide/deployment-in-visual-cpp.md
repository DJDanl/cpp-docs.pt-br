---
title: "Implanta&#231;&#227;o no Visual C++ | Microsoft Docs"
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
  - "implantação de aplicativos [C++]"
  - "implantando aplicativos [C++]"
ms.assetid: d4b4ffc0-d2bd-4e4a-84a6-62f1c26f6a09
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Implanta&#231;&#227;o no Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você implanta um aplicativo do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] em outro computador, deve instalar o aplicativo e os arquivos de biblioteca de que ele depende.  Se uma biblioteca for atualizada – por exemplo, quando uma vulnerabilidade de segurança é corrigida – você provavelmente vai querer aplicar a atualização sempre que seu aplicativo for implantado.  
  
 O Visual Studio oferece três maneiras de implantação de bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] juntamente com seu aplicativo: implantação central, implantação local e vinculação estática.  A Microsoft atualiza automaticamente as bibliotecas que são implantadas centralmente.  Para as bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] que são implantadas localmente ou vinculadas estaticamente, o criador do aplicativo deve fornecer as atualizações.  
  
## Implantação central  
 Na implantação central, os arquivos de biblioteca do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] são instalados no diretório %windir%\\system32\\.  Para implantar centralmente as bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], você pode usar um destes métodos:  
  
-   *Arquivos de pacotes redistribuíveis*, que são executáveis de linha de comando autônomos que você pode usar para instalar as bibliotecas redistribuíveis do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  
  
-   *Módulos de mesclagem redistribuíveis \(arquivos .msm\)*, que podem ser usados para implantar bibliotecas específicas e incluídos no arquivo do Windows Installer \(.msi\) do aplicativo.  
  
 Um arquivo de pacote redistribuível instala as bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] para uma arquitetura de sistema específica.  Você pode programar a instalação de seu aplicativo para executar como pré\-requisito antes de instalar seu aplicativo.  Um módulo de mesclagem permite a inclusão da lógica de configuração para uma biblioteca específica do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] em um arquivo de instalação de aplicativo do Windows Installer.  Você pode incluir quantos módulos de mesclagem o aplicativo exigir.  
  
 Como a implantação central de bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] usando um pacote redistribuível permite a atualização automática pela Microsoft, recomendamos que você use a vinculação dinâmica e pacotes redistribuíveis para seu aplicativo.  
  
## Implantação local  
 Na implantação local, os arquivos de biblioteca são instalados na pasta do aplicativo junto com o arquivo executável.  Versões diferentes de bibliotecas podem ser instaladas na mesma pasta, pois o nome de arquivo de cada versão é criado exclusivamente com a inclusão do número de versão.  Por exemplo, a versão 12 do tempo de execução C é msvcr120.dll.  
  
 Como a Microsoft não pode atualizar automaticamente as bibliotecas localmente implantadas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], somos contra a implantação local dessas bibliotecas.  Se você decidir usar a implantação local de bibliotecas redistribuíveis, recomendamos implementar seu próprio método de atualização automática das bibliotecas localmente implantadas.  
  
## Vinculação estática  
 Você pode vincular estaticamente uma biblioteca do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] a um aplicativo – ou seja, compilá\-la no aplicativo – portanto, você não precisa implantar os arquivos de biblioteca do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] separadamente.  No entanto, somos contra essa abordagem porque as bibliotecas estaticamente vinculadas não podem ser atualizadas no lugar.  Se você usar a vinculação estática e quiser atualizar uma biblioteca vinculada, precisará recompilar e reimplantar seu aplicativo.  
  
## Solução de problemas  
 A ordem de carregamento das bibliotecas do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] depende do sistema.  Para diagnosticar problemas do carregador, use depends.exe ou where.exe.  Para obter mais informações, consulte o artigo sobre [ordem de pesquisa de bibliotecas de vínculo dinâmico \(DLL\) \(Windows\)](http://msdn.microsoft.com/library/windows/desktop/ms682586.aspx).  
  
## Consulte também  
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)