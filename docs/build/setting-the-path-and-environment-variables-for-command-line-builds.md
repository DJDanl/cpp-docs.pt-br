---
title: "Definindo as vari&#225;veis de caminho e ambiente para compila&#231;&#245;es de linha de comando | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
f1_keywords: 
  - "include"
  - "Lib"
  - "Path"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "compilador cl.exe [C++], variáveis de ambiente"
  - "compilando o código-fonte [C++], da linha de comando"
  - "variáveis de ambiente [C++]"
  - "variáveis de ambiente [C++], compilador CL"
  - "palavra reservada INCLUDE"
  - "variável de ambiente LIB"
  - "ferramenta LINK [C++], variáveis de ambiente"
  - "ferramenta LINK [C++], caminho"
  - "palavra reservada PATH"
  - "Arquivo VCVARS32.bat"
ms.assetid: 99389528-deb5-43b9-b99a-03c8773ebaf4
caps.latest.revision: 17
caps.handback.revision: 17
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Definindo as vari&#225;veis de caminho e ambiente para compila&#231;&#245;es de linha de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] Ferramentas de compilação de linha de comando requerem diversas variáveis de ambiente personalizadas para a instalação. Quando [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] é instalado, ele cria arquivos de comando que defina as variáveis de ambiente necessárias e, em seguida, cria atalhos que iniciam uma janela de Prompt de comando que já tem essas variáveis de conjunto. Quando você deseja usar as ferramentas de linha de comando, você pode executar um destes atalhos ou você pode abrir uma janela de Prompt de comando simples e, em seguida, execute o arquivo de comando vcvarsall. bat.  
  
 O [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] Ferramentas de linha de comando usam as variáveis de ambiente PATH, TMP, INCLUDE, LIB e LIBPATH e também pode usar variáveis de ambiente específicas da ferramenta. Como os valores dessas variáveis de ambiente são específicos para sua instalação e podem ser alterados por atualizações do produto, recomendamos que você use o vcvarsall. bat ou um atalho do Prompt de comando do desenvolvedor, em vez de defini\-las. Para obter informações sobre as variáveis de ambiente específicas usadas pelo compilador e vinculador, consulte [Variáveis de ambiente CL](../build/reference/cl-environment-variables.md) e [Variáveis de ambiente LINK](../build/reference/link-environment-variables.md).  
  
> [!NOTE]
>  Várias ferramentas de linha de comando ou opções da ferramenta exigem a permissão de administrador. Para usá\-los, é recomendável que você abre uma janela de Prompt de comando usando o **Executar como administrador** opção. No Windows 10, clique para abrir o menu de atalho para a janela de Prompt de comando, escolha **mais**, **Executar como administrador**.  
  
## Usando os atalhos do Prompt de comando  
 Visual Studio instala um atalho do Prompt de comando do desenvolvedor que abre uma janela de Prompt de comando e define o ambiente para usar o conjunto de ferramentas nativo x86 de 32 bits para processadores x86. Se você instalou a edição de ferramentas de compilação do Visual C\+\+, um atalho do Prompt de comando do desenvolvedor não está instalado, mas não de Prompt de comando de ferramentas nativas do x86 a mesma coisa.  
  
 Prompts de comando de 32 bits compiladores destinados a plataformas ARM e x64 também estão disponíveis. Em plataformas de 64 bits, Command Prompt atalhos para um conjunto de ferramentas de x64 nativo de 64 bits que processadores x64 destinos e de 64 bits entre compiladores cruzados ARM e x86 processadores estão instalados. Essas versões do conjunto de ferramentas de linha de comando estão disponíveis em todas as edições do Visual Studio:  
  
 x86 Prompt de comando de ferramentas nativas  
 Use esse conjunto de ferramentas para criar arquivos de saída para x86 máquinas. Ele é executado como um processo de 32 bits, nativo em um x86 de máquina e em WOW64 em um sistema de operacional do Windows de 64 bits.  
  
 x86 x64 cross Tools Command Prompt  
 Use esse conjunto de ferramentas para criar arquivos de saída para [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]. Ele é executado como um processo de 32 bits, nativo em um x86 de máquina e em WOW64 em um sistema de operacional do Windows de 64 bits.  
  
 x86 ARM Prompt de comando de ferramentas cruzadas  
 Use esse conjunto de ferramentas para criar arquivos de saída para computadores ARM. Ele é executado como um processo de 32 bits, nativo em um x86 de máquina e em WOW64 em um sistema de operacional do Windows de 64 bits.  
  
 Essas versões do conjunto de ferramentas de linha de comando estão disponíveis em plataformas de 64 bits:  
  
 x64 x86 entre o Prompt de comando de ferramentas  
 Use esse conjunto de ferramentas para criar arquivos de saída para x86 máquinas. Ele é executado como um processo nativo em um sistema de operacional do Windows de 64 bits.  
  
 x64 Prompt de comando de ferramentas nativas  
 Use esse conjunto de ferramentas para criar arquivos de saída para [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] máquinas. Ele é executado como um processo nativo em um sistema de operacional do Windows de 64 bits.  
  
 x64 ARM Prompt de comando de ferramentas cruzadas  
 Use esse conjunto de ferramentas para criar arquivos de saída para computadores ARM. Ele é executado como um processo nativo de 64 bits em um sistema de operacional do Windows de 64 bits.  
  
 O x86 Prompt de comando de ferramentas nativas tem o mesmo efeito que o atalho do Prompt de comando do desenvolvedor.  
  
#### Para abrir uma janela de Prompt de comando do desenvolvedor  
  
1.  No Windows 10 **Iniciar** menu, abrir **todos os aplicativos** e, em seguida, abra o **Visual Studio** pasta para a sua versão do Visual Studio. Em algumas versões anteriores do Visual Studio, a pasta é chamada  **Visual Studio Tools**.  
  
2.  Abra o **Prompt de comando do desenvolvedor** atalho para sua versão do [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)]. Se você tiver instalado a edição de ferramentas de compilação do Visual C\+\+, use o **x86 Prompt de comando de ferramentas nativas**. Opcionalmente, para executar como administrador, clique para abrir o menu de atalho para o Prompt de comando do desenvolvedor e escolha **mais**, **Executar como administrador**.  
  
 O atalho do Prompt de comando do desenvolvedor define o ambiente para usar o conjunto de ferramentas nativo de 32 bits para processadores x86. Na mesma pasta, há outros atalhos do prompt de comando que especificam diferentes plataformas nativas e destinos de compilador cruzado. Por exemplo, escolher o **x64 Prompt de comando de ferramentas cruzadas** para usar o conjunto de ferramentas nativo de 32 bits para processadores x64. Escolha o **ARM Cross Tools Command Prompt** para usar o conjunto de ferramentas nativo de 32 bits para processadores ARM. Escolha o **x64 Prompt de comando de ferramentas nativas** para usar o conjunto de ferramentas nativo de 64 bits para processadores x64.  
  
## Usando vcvarsall. bat em uma janela de Prompt de comando  
 Executando vcvarsall. bat em uma janela de Prompt de comando simples, você pode definir variáveis de ambiente para configurar a linha de comando de compilação nativa de 32 bits ou 64 bits ou de compilação cruzada para x86, x64 ou processadores ARM. Se nenhum argumento for fornecido, vcvarsall. bat configura as variáveis de ambiente para usar o compilador nativo de 32 bits para x86 destinos. No entanto, você pode usá\-lo para configurar qualquer um dos compiladores. Se você especificar uma configuração de compilador que não está instalada ou não está disponível em sua arquitetura de computador de compilação, uma mensagem é exibida. A tabela a seguir mostra os argumentos com suporte.  
  
|Argumento vcvarsall. bat|Compilador|Arquitetura do computador de compilação|Criar uma arquitetura de saída|  
|------------------------------|----------------|---------------------------------------------|------------------------------------|  
|x86|x86 nativo de 32 bits|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|x86|  
|x86\_amd64|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)] em x86 cruzado|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|x86\_arm|ARM em x86 cruzado|x86, [!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|ARM|  
|amd64|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)] nativa de 64 bits|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|  
|amd64\_x86|x86 em [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] cruzada|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|x86|  
|amd64\_arm|ARM em [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] cruzada|[!INCLUDE[vcprx64](../Token/vcprx64_md.md)]|ARM|  
  
 As etapas a seguir mostram como configurar um Prompt de comando para usar o conjunto de ferramentas nativo de 32 bits para plataformas de destino x86.  
  
#### Para executar o vcvarsall. bat  
  
1.  No prompt de comando, altere para o [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] diretório de instalação. \(O local depende do sistema e o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] instalação, mas um local típico é C:\\Program Files \(x86\) \\Microsoft Visual Studio *versão*\\vc\\..\) Por exemplo, digite:  
  
     **CD "14.0\\VC de Visual Studio de \\Microsoft \\Program arquivos \(x86\)"**  
  
2.  Para configurar o Prompt de comando que cria a janela de 32 bits x86 de linha de comando, no prompt de comando, digite:  
  
     `vcvarsall x86`  
  
 O arquivo de comando define as variáveis de ambiente necessárias para os caminhos para as ferramentas de compilação, bibliotecas e cabeçalhos. Agora você pode usar essa janela de prompt de comando para executar o compilador de linha de comando e ferramentas.  
  
 [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] também fornece vcvars32. bat para configurar um ambiente de linha de comando. O arquivo vcvars32. bat for encontrado no diretório bin no diretório de instalação do VC. Ele é limitado a definir variáveis de ambiente apropriadas para habilitar 32 bits x86 de linha de comando se baseia. É o equivalente a `vcvarsall x86` comando.  
  
 Se você estiver usando [DEVENV](../Topic/Devenv%20Command%20Line%20Switches.md) para compilações de linha de comando, o ambiente definido por vcvarsall. bat ou vcvars32. bat não afeta as compilações, a menos que você também especifique o **\/useenv** opção.  
  
> [!CAUTION]
>  O arquivo vcvarsall. bat pode variar de um computador para outro. Não substitua um arquivo vcvarsall está faltando ou danificado usando um arquivo de outro computador. Execute novamente [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] configuração para substituir o arquivo ausente.  
>   
>  O arquivo vcvarsall. bat também varia de versão para versão. Se a versão atual do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] é instalado em um computador que também tem uma versão anterior do [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)], não execute vcvarsall. bat ou vcvars32 de versões diferentes na mesma janela do Prompt de comando.  
  
## Consulte também  
 [Compilando na linha de comando](../Topic/Building%20on%20the%20Command%20Line.md)   
 [Vinculando](../Topic/Linking.md)   
 [Opções de vinculador](../build/reference/linker-options.md)   
 [Compilando um programa C\/C\+\+](../build/reference/compiling-a-c-cpp-program.md)   
 [Opções do compilador](../build/reference/compiler-options.md)