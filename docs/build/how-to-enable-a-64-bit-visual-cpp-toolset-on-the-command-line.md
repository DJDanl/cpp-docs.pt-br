---
title: "Como habilitar um Conjunto de Ferramentas Visual C++ de 64 bits na linha de comando | Microsoft Docs"
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
  - "compilador de 64 bits [C++], uso de linha de comando"
  - "compilador de 64 bits [C++], habilitação de conjunto de ferramentas na linha de comando"
  - "linha de comando [C++], compilador de 64 bits"
  - "IPF"
  - "IPF, compilador de linha de comando"
  - "Itanium [C++]"
  - "Itanium [C++], compilador de linha de comando"
  - "x64 [C++]"
  - "x64 [C++], compilador de linha de comando"
ms.assetid: 4da93a19-e20d-4778-902a-5eee9a6a90b5
caps.latest.revision: 30
caps.handback.revision: 30
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Como habilitar um Conjunto de Ferramentas Visual C++ de 64 bits na linha de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Visual C\+\+ inclui compiladores que podem ser usados para criar aplicativos que podem ser executados em um sistema operacional Windows de 32 bits, 64 bits ou baseado em ARM.  
  
> [!NOTE]
>  Para obter informações sobre as ferramentas específicas incluídas em cada edição do Visual C\+\+, consulte [Ferramentas e modelos do Visual C\+\+ em edições do Visual Studio](../ide/visual-cpp-tools-and-templates-in-visual-studio-editions.md).  
>   
>  Para obter informações sobre como usar o Visual Studio IDE para criar aplicativos de 64 bits, consulte [Como configurar projetos do Visual C\+\+ para destinar plataformas de 64 bits](../build/how-to-configure-visual-cpp-projects-to-target-64-bit-platforms.md).  
  
 O [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] inclui compiladores de 32 bits nativos e cruzados hospedados em x86 para destinos x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] e ARM.  Quando o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] é instalado em um sistema operacional Windows de 64 bits, compiladores de 32 bits nativos e cruzados hospedados em x86 e também compiladores de 64 bits nativos e cruzados hospedados em [!INCLUDE[vcprx64](../Token/vcprx64_md.md)], são instalados para cada destino \(x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] e ARM\).  Os compiladores de 32 bits e de 64 bits para cada destino geram código idêntico, porém, os compiladores de 64 bits suportam mais memória para símbolos pré\-compilados do cabeçalho e as opções de Otimização de Programa Integral \([\/GL](../build/reference/gl-whole-program-optimization.md), [\/LTCG](../build/reference/ltcg-link-time-code-generation.md)\).  Caso você atinja os limites de memória ao usar um compilador de 32 bits, tente o compilador de 64 bits.  
  
 Quando o Visual Studio é instalado em um sistema operacional Windows de 64 bits, atalhos adicionais do Prompt de Comando para os compiladores de 64 bits nativos [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] e cruzados x86 estão disponíveis.  Para acessar os prompts de comando no Windows 8, na tela **Iniciar**, abra **Todos os aplicativos**.  Sob a versão instalada do **[!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)]**, abra **Ferramentas do Visual Studio** e escolha um dos prompts de comando de ferramenta nativa ou de ferramenta cruzada.  Em versões anteriores do Windows, escolha **Iniciar**, expanda **Todos os Programas**, **[!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)]**, **Ferramentas do Visual Studio** e escolha um prompt de comando.  
  
## Vcvarsall.bat  
 Qualquer um dos compiladores pode ser usado na linha de comando executando o arquivo de comando vcvarsall.bat para configurar as variáveis de ambiente e o caminho que habilitam o conjunto de ferramentas do compilador.  Como não há atalhos do Prompts de Comando para habilitar um conjunto de ferramentas de 64 bits para destinar plataformas x86 ou ARM, use o vcvarsall.bat em uma janela do Prompt de Comando para usar, ao invés disso, o conjunto de ferramentas de 64 bits.  Para obter mais informações, consulte [Definindo as variáveis de caminho e ambiente para compilações de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md).  
  
 As etapas a seguir mostram como configurar um Prompt de Comando para usar o conjunto de ferramentas de 64 bits nativo para destinar plataformas x86, x64 e ARM.  
  
#### Executar o vcvarsall.bat para usar um conjunto de ferramentas de 64 bits  
  
1.  No prompt de comando, mude para o diretório de instalação do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  \(O local depende do sistema e da instalação do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)], mas um local típico é C:\\Arquivos de Programas \(x86\)\\Microsoft Visual Studio *versão*\\VC\\.\) Por exemplo, insira:  
  
     cd "\\Arquivos de Programas \(x86\)\\Microsoft Visual Studio 12.0\\VC"  
  
2.  Para configurar essa janela do Prompt de Comando para compilações de linha de comando de 64 bits que se destinam a plataformas x64, no prompt de comando, insira:  
  
     `vcvarsall amd64`  
  
3.  Para configurar essa janela do Prompt de Comando para compilações de linha de comando de 64 bits que se destinam a plataformas x86, no prompt de comando, insira:  
  
     `vcvarsall amd64_x86`  
  
4.  Para configurar essa janela do Prompt de Comando para compilações de linha de comando de 64 bits que se destinam a plataformas ARM, no prompt de comando, insira:  
  
     `vcvarsall amd64_arm`  
  
## Consulte também  
 [Configurando programas para 64 bits](../build/configuring-programs-for-64-bit-visual-cpp.md)