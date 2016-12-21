---
title: "Inicializando uma DLL | Microsoft Docs"
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
  - "DLLs [C++], inicializando"
  - "inicializando DLLs"
  - "código de encerramento [C++]"
ms.assetid: f655c5ff-ab5b-493a-a1da-4d1074e60c5b
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Inicializando uma DLL
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Em geral, o DLL tem o código de inicialização \(como a alocação de memória\) que deve ser executado quando o DLL for carregado.  Ao usar o Visual C\+\+, o local onde você adiciona o código para inicializar sua DLL depende do tipo de DLL que você está criando.  Se você não precisar adicionar o código de inicialização ou de terminação, não há nada especial que você tenha de fazer ao criar sua DLL.  Caso você precise inicializar a DLL, a tabela a seguir descreve onde adicionar o código.  
  
|Tipo DLL|Onde adicionar a inicialização e o código de finalização|  
|--------------|--------------------------------------------------------------|  
|DLL normal|Em `InitInstance` e `ExitInstance` do objeto `CWinApp` de DLL.|  
|DLL de Extensão|Na função `DllMain` gerada pelo assistente de DLL do MFC.|  
|DLL não MFC|Em uma função chamada `DllMain` fornecida por você.|  
  
 No Win32, todos os DLLs podem conter uma função opcional de ponto de entrada \(geralmente chamada de `DllMain`\) que é chamada para inicialização e encerramento.  Isso oferece a você uma oportunidade para alocar ou liberar recursos adicionais como necessário.  O Windows chama a função de ponto de entrada em quatro situações: processar anexação, processar desanexação, segmentar anexação e segmentar desanexação.  
  
 A biblioteca em tempo de execução do C oferece uma função de ponto de entrada chamada **\_DllMainCRTStartup** e chama `DllMain`.  Dependendo do tipo de DLL, você deve ter uma função chamada `DllMain` em seu código\-fonte ou usar a `DllMain` fornecida na biblioteca MFC.  
  
## O que você deseja fazer?  
  
-   [Inicializar DLL normais](../Topic/Initializing%20Regular%20DLLs.md)  
  
-   [Inicializar extensão DLL](../build/initializing-extension-dlls.md)  
  
-   [Inicialize DLL não MFC](../Topic/Initializing%20Non-MFC%20DLLs.md)  
  
## Que você deseja saber mais?  
  
-   [O comportamento da biblioteca em tempo de execução do C e \_DllMainCRTStartup](../build/run-time-library-behavior.md)  
  
-   [\<caps:sentence id\="tgt24" sentenceid\="58bb7328659bda9ffb73a1dcd39da06b" class\="tgtSentence"\>A especificação de função para DllMain \(Windows SDK\)\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms682583)  
  
-   [\<caps:sentence id\="tgt25" sentenceid\="f29344705c59343b34b642944921cbdf" class\="tgtSentence"\>Função de ponto de entrada da biblioteca de link dinâmico \(Windows SDK\)\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms682596)  
  
## Consulte também  
 [DLLs no Visual C\+\+](../build/dlls-in-visual-cpp.md)