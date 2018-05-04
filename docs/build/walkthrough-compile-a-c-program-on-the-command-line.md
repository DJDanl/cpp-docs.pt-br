---
title: 'Passo a passo: Compilar um programa em C na linha de comando | Microsoft Docs'
ms.custom: conceptual
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
helpviewer_keywords:
- command-line applications [C++], C programs
- Visual C, compiling
- compiling programs [C++]
- C program compiling [C++]
ms.assetid: 7e74cc2d-54b1-49de-b7ad-d3ae6b39ab8d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 033c29ff9871a427222b59fbf5c8350794a9bbe2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="walkthrough-compile-a-c-program-on-the-command-line"></a>Passo a passo: Compilar um programa em C na linha de comando
O Visual C++ inclui um compilador C que você pode usar para criar tudo de programas básico do console para aplicativos de área de trabalho do Windows completos, aplicativos móveis e muito mais.  
  
 Este passo a passo mostra como criar um basic, "Olá, mundo"-estilo de programa C usando um texto de editor e, em seguida, compile-o na linha de comando. Se você preferir trabalhar em C++ na linha de comando, consulte [passo a passo: compilando um programa C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md). Se você gostaria de tentar o IDE do Visual Studio, em vez de usar a linha de comando, consulte [passo a passo: Trabalhando com projetos e soluções (C++)](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) ou [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Para concluir este passo a passo, você deve ter instalado o Visual Studio e os componentes opcionais do Visual C++ ou o Microsoft Visual C++ ferramentas de compilação.  
  
 O Visual Studio é um ambiente de desenvolvimento integrado avançado que oferece suporte a um editor completo e compiladores, depuradores e gerenciadores de recursos para várias plataformas e idiomas. Para obter informações sobre esses recursos e como baixar e instalar o Visual Studio, incluindo o Visual Studio Community edition gratuito, consulte [VisualStudio.com](https://www.visualstudio.com/).  
  
 As ferramentas do Visual Studio compilar instala somente os compiladores de linha de comando, ferramentas e bibliotecas que necessárias para criar programas C e C++. Ele é perfeito para laboratórios de compilação ou sala de aula exercícios e instala relativamente rapidamente. Para instalar apenas as ferramentas de linha de comando, baixe [ferramentas de compilação do Visual Studio](https://go.microsoft.com/fwlink/p/?linkid=840931) e execute o instalador. Para obter mais informações, consulte [ferramentas de compilação do Visual C++](http://landinghub.visualstudio.com/visual-cpp-build-tools).  
  
 Antes de criar um programa C ou C++ na linha de comando, você deve verificar se as ferramentas estão instaladas e se você pode acessá-los na linha de comando. Visual C++ tem requisitos complexos para o ambiente de linha de comando para encontrar as ferramentas, cabeçalhos e bibliotecas que ele usa. **Você não pode usar o Visual C++ em uma janela de prompt de comando simples**. É necessário um *prompt de comando do desenvolvedor* janela, que é uma janela de prompt de comando regular que tem todas as variáveis de ambiente necessário definido. Felizmente, o Visual C++ instala atalhos para iniciar os prompts de comando do desenvolvedor com o ambiente para compilações de linha de comando. Infelizmente, os nomes dos atalhos de prompt de comando do desenvolvedor e onde eles estão localizados são diferentes em quase todas as versões do Visual C++ e em versões diferentes do Windows. É a primeira tarefa do passo a passo localizar o atalho direito a ser usado.  
  
> [!NOTE]
>  Um atalho de prompt de comando do desenvolvedor define automaticamente os caminhos corretos para o compilador e ferramentas e para quaisquer cabeçalhos necessários e bibliotecas. Alguns desses valores são diferentes para cada configuração de build. Você deve definir esses valores do ambiente mesmo se você não usar um dos atalhos. Para obter mais informações, consulte [definir o caminho e as variáveis de ambiente para compilações de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md). Como o ambiente de compilação é complexo, é altamente recomendável que você usar um atalho de prompt de comando do desenvolvedor, em vez de criar seus próprios.  
  
## <a name="open-a-developer-command-prompt"></a>Abra um prompt de comando do desenvolvedor  
  
1.  Se você tiver instalado o Visual Studio de 2017 no Windows 10, abra o menu Iniciar e, em seguida, role para baixo e abra o **2017 do Visual Studio** pasta (não o aplicativo do Visual Studio de 2017). Escolha **Prompt de comando do desenvolvedor para VS 2017** para abrir a janela de prompt de comando.  
  
     Se você tiver instalado o Microsoft Visual C++ Build Tools 2015 no Windows 10, abra o **iniciar** menu e, em seguida, role para baixo e abra o **ferramentas de compilação do Visual C++** pasta. Escolha **Prompt de comando de ferramentas nativas do Visual C++ 2015 x86** para abrir a janela de prompt de comando.  
  
     Se você estiver usando uma versão diferente do Visual Studio ou estiver executando uma versão diferente do Windows, procure no menu Iniciar ou iniciar a página de uma pasta de ferramentas do Visual Studio que contém um atalho de prompt de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para pesquisar "prompt de comando do desenvolvedor" e escolha uma que corresponde à sua versão instalada do Visual Studio. Use o atalho para abrir a janela de prompt de comando.  
  
2.  Em seguida, verifique se o prompt de comando do desenvolvedor do Visual C++ está configurado corretamente. Na janela do prompt de comando, digite `cl` e verifique se que a saída parecida com esta:  
  
    ```Output  
    C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>cl  
    Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86  
    Copyright (C) Microsoft Corporation.  All rights reserved.  
    
    usage: cl [ option... ] filename... [ /link linkoption... ]  
    
    C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>  
    ```  
  
     Pode haver diferenças no diretório atual ou os números de versão, dependendo da versão do Visual C++ e atualizações instaladas. Se isso é semelhante ao que você vê, em seguida, você está pronto para criar programas C ou C++ na linha de comando.  
  
    > [!NOTE]
    >  Se você receber um erro, como "'cl' não é reconhecido como um comando interno ou externo, um programa operável ou arquivo em lotes," Erro C1034 ou erro LNK1104 quando você executa o **cl** de comando, em seguida, ou você não estiver usando um prompt de comando do desenvolvedor, ou algo está errado com a instalação do Visual C++. Você deve corrigir esse problema antes de continuar.  
  
     Se você não encontrar o desenvolvedor do atalho do prompt de comando, ou se você receber uma mensagem de erro quando você insere `cl`, em seguida, a instalação do Visual C++ pode ter um problema. Tente reinstalar o componente do Visual C++ no Visual Studio ou reinstalar as ferramentas do Visual Studio compilar. Não vá para a próxima seção até que isso funciona. Para obter mais informações sobre como instalar e solução de problemas do Visual C++, consulte [instale o Visual Studio](/visualstudio/install/install-visual-studio).  
  
    > [!NOTE]
    >  Dependendo da versão do Windows no computador e a configuração de segurança do sistema, talvez você precise com o botão direito para abrir o menu de atalho para o atalho do prompt de comando do desenvolvedor e, em seguida, escolha **executar como administrador** para compilar e executar o programa que você criar seguindo este passo a passo com êxito.  
  
## <a name="create-a-c-source-file-and-compile-it-on-the-command-line"></a>Criar um arquivo de origem C e compilá-lo na linha de comando  
  
1.  Na janela de prompt de comando do desenvolvedor, digite **cd c:\\**  para alterar o diretório de trabalho atual para a raiz da unidade c:. Em seguida, digite **md c:\simple** para criar um diretório e, em seguida, digite **c:\simple cd** para alterar a esse diretório. Este é o diretório que contém o arquivo de origem e o programa compilado.  
  
2.  Digite **simple.c o bloco de notas** no prompt de comando do desenvolvedor. O bloco de notas alerta caixa de diálogo que aparece, escolha **Sim** para criar um novo arquivo de simple.c no diretório de trabalho.  
  
3.  No bloco de notas, digite as seguintes linhas de código:  
  
    ```C  
    #include <stdio.h>  
  
    int main()  
    {  
        printf("Hello, World! This is a native C program compiled on the command line.\n");  
        return 0;  
    }   
    ```  
  
4.  Na barra de menus do bloco de notas, escolha **arquivo**, **salvar** salvar simple.c no diretório de trabalho.  
  
5.  Alterne novamente para a janela de prompt de comando do desenvolvedor. Digite **dir** no prompt de comando para listar o conteúdo do diretório c:\simple. Você deve ver o simple.c de arquivo de origem na lista de diretórios, que tem a seguinte aparência:  
  
    ```Output  
    C:\simple>dir  
     Volume in drive C has no label.  
     Volume Serial Number is CC62-6545  
  
     Directory of C:\simple  
  
    10/02/2017  03:46 PM    <DIR>          .  
    10/02/2017  03:46 PM    <DIR>          ..  
    10/02/2017  03:36 PM               143 simple.c  
                   1 File(s)            143 bytes  
                   2 Dir(s)  514,900,566,016 bytes free  
  
    ```  
  
     As datas e outros detalhes serão diferentes em seu computador. Se você não vir o seu arquivo de código fonte, simple.c, verifique se você alterar o diretório c:\simple criado e no bloco de notas, certifique-se de que você salvou o arquivo de origem nesse diretório. Além disso, certifique-se de que você salvou o código-fonte com uma extensão de nome de arquivo. c, não uma extensão. txt.  
  
6.  Para compilar seu programa, digite **simple.c cl** no prompt de comando do desenvolvedor.  
  
     Você pode ver o nome do programa executável, simple.exe nas linhas de informações de saída que o compilador exibe:  
  
    ```Output  
    c:\simple>cl simple.c  
    Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86  
    Copyright (C) Microsoft Corporation.  All rights reserved.  
  
    simple.c  
    Microsoft (R) Incremental Linker Version 14.10.25017.0  
    Copyright (C) Microsoft Corporation.  All rights reserved.  
  
    /out:simple.exe  
    simple.obj  
    ```  
  
    > [!NOTE]
    >  Se você receber um erro, como "'cl' não é reconhecido como um comando interno ou externo, um programa operável ou arquivo em lotes," Erro C1034 ou erro LNK1104, o prompt de comando do desenvolvedor não está configurado corretamente. Para obter informações sobre como resolver esse problema, volte para o **abra um prompt de comando do desenvolvedor** seção.  
  
    > [!NOTE]
    >  Se você receber um compilador diferente ou aviso ou erro de vinculador, revise seu código-fonte para corrigir os erros, em seguida, salvá-lo e executar o compilador novamente. Para obter informações sobre erros específicos, use a caixa de pesquisa nessa página do MSDN para procurar o número do erro.  
  
7.  Para executar o programa, digite **simples** no prompt de comando.  
  
     O programa exibe este texto e fecha na sequência:  
  
    ```Output  
    Hello, World! This is a native C program compiled on the command line.  
    ```  
  
     Parabéns, você apenas compilados e executar um programa em C usando a linha de comando.  
  
## <a name="next-steps"></a>Próximas etapas  
 Este exemplo "Olá, mundo" é mais simple que pode obter um programa em C. Programas do mundo real tem arquivos de cabeçalho e mais arquivos de origem, vincular em bibliotecas e, em seguida, faça o trabalho útil.  
  
 Você pode usar as etapas neste passo a passo para criar seu próprio código C em vez de digitar o código de exemplo mostrado. Você também pode criar muitos programas C de exemplo de código que você pode encontrar em outro lugar. Para compilar um programa com vários arquivos de código fonte, inseri-los em linha de comando, como esta:  
  
 `cl file1.c file2.c file3.c`  
  
 O compilador gera um programa chamado file1.exe. Para alterar o nome para program1.exe, adicione um [/out](../build/reference/out-output-file-name.md) opção de vinculador:  
  
 `cl file1.c file2.c file3.c /link /out:program1.exe`  
  
 E para capturar erros de programação mais automaticamente, é recomendável que você compila usando o [/W3](../build/reference/compiler-option-warning-level.md) ou [/W4](../build/reference/compiler-option-warning-level.md) opção de nível de aviso:  
  
 `cl /W4 file1.c file2.c file3.c /link /out:program1.exe`  
  
 O compilador, cl.exe, tem muitas opções mais você pode aplicar para criar, otimizar, depurar e analisar seu código. Para obter uma lista rápida, digite **cl /?** no prompt de comando do desenvolvedor. Você também pode compilar e vincular separadamente e aplicar opções de vinculador em cenários mais complexos de compilação. Para obter mais informações sobre opções de vinculador e compilador e uso, consulte [referência de build do C/C++](../build/reference/c-cpp-building-reference.md).  
  
 Você pode usar NMAKE e makefiles ou arquivos de projeto MSBuild para configurar e criar projetos mais complexos na linha de comando. Para obter mais informações sobre como usar essas ferramentas, consulte [referência a NMAKE](../build/nmake-reference.md) e [MSBuild](../build/msbuild-visual-cpp.md).  
  
 Linguagens C e C++ são semelhantes, mas não é o mesmo. O compilador do Visual C++ usa uma regra simples para determinar o idioma a ser usado ao compilar seu código. Por padrão, o compilador do Visual C++ trata todos os arquivos que terminam em .c como código-fonte C e todos os arquivos que terminam em .cpp como código-fonte C++. Para forçar o compilador trate todos os arquivos como C, independentemente da extensão de nome de arquivo, use o [/Tc](../build/reference/tc-tp-tc-tp-specify-source-file-type.md) opção de compilador.  
  
 O compilador do Visual C++ C é geralmente compatível com o padrão ISO C99, mas não é estritamente compatível. Na maioria dos casos, o código C portátil compilar e executados conforme esperado. Visual C++ não dá suporte à maioria das alterações em C11 ISO. Determinadas funções de biblioteca e nomes de função POSIX foram preteridos pelo compilador do Visual C++. As funções têm suporte, mas os nomes preferenciais foram alterados. Para obter mais informações, consulte [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md) e [C4996 de aviso do compilador (nível 3)](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).  
  
## <a name="see-also"></a>Consulte também  
 [Passo a passo: Criando um programa padrão do C++ (C++)](../windows/walkthrough-creating-a-standard-cpp-program-cpp.md)   
 [Referência da linguagem C](../c-language/c-language-reference.md)   
 [Compilando programas C/C++](../build/building-c-cpp-programs.md)   
 [Compatibilidade](../c-runtime-library/compatibility.md)