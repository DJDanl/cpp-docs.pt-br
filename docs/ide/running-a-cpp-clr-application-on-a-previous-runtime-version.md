---
title: "Executando um aplicativo C++ /clr em uma vers&#227;o de tempo de execu&#231;&#227;o anterior | Microsoft Docs"
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
  - "arquivos app.config, versão de temo de execução especificada"
  - "implantação de aplicativos [C++], versão de temo de execução especificada"
  - "aplicativos [C++], versão de temo de execução especificada"
  - "compatibilidade com versões anteriores [C++], versão de temo de execução especificada"
  - "common language runtime [C++], versão especificada"
  - "compatibilidade [C++], versão de temo de execução especificada"
  - "implantando aplicativos [C++], versão de temo de execução especificada"
  - "versões [C++]"
ms.assetid: 940171b7-6937-4b14-8e87-c199e23f4f2e
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Executando um aplicativo C++ /clr em uma vers&#227;o de tempo de execu&#231;&#227;o anterior
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Salvo indicação caso contrário, um aplicativo Visual C\+\+ o.NET Framework é compilado executar a versão do CLR do common language runtime que o compilador usa para compilar o aplicativo.  No entanto, é possível para um aplicativo .exe que é criado para uma versão do runtime para executar em qualquer outra versão que fornecer funcionalidade necessário.  
  
 Para fazer isso, forneça um arquivo app.config que contém informações de versão do runtime na marca de `supportedRuntime` .  
  
 Em tempo de execução, o arquivo app.config deve ter um nome de formulário *filename.ext*.config, onde *filename.ext* é o nome do arquivo executável que iniciou o aplicativo, e deve estar no mesmo diretório que o executável.  Por exemplo, se seu aplicativo é chamado TestApp.exe, o arquivo app.config será nomeado TestApp.exe.config.  
  
 Se você especificar mais de uma versão do runtime e executar o aplicativo em um computador que tem mais de uma versão do runtime instalada, o aplicativo usa a primeira versão que é especificado no arquivo de configuração e instalado.  
  
 Para obter mais informações, consulte [How to: Configure an App to Target a .NET Framework Version](http://msdn.microsoft.com/pt-br/5247b307-89ca-417b-8dd0-e8f9bd2f4717).  
  
 Para executar na versão 1,0 ou a versão 1,1 do CLR, um aplicativo compilado pelo compilador do Visual C\+\+ deve ser compilado usando [\/clr:initialAppDomain](../build/reference/clr-common-language-runtime-compilation.md).  
  
## Consulte também  
 [Implantando aplicativos da área de trabalho](../Topic/Deploying%20Native%20Desktop%20Applications%20\(Visual%20C++\).md)