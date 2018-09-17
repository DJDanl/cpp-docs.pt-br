---
title: 'Passo a passo: Compilar um programa em C na linha de comando | Microsoft Docs'
ms.custom: conceptual
ms.date: 06/21/2018
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
ms.openlocfilehash: 3f1390259838302a56e58397afa79fa8c458b939
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710327"
---
# <a name="walkthrough-compile-a-c-program-on-the-command-line"></a>Passo a passo: Compilar um programa em C na linha de comando

O Visual C++ inclui um compilador de C que você pode usar para criar tudo, desde programas de console básico para aplicativos de área de trabalho do Windows completos, aplicativos móveis e muito mais.

Este passo a passo mostra como criar um básico "Hello, World"-estilo programa C, usando um texto de editor e, em seguida, compilá-lo na linha de comando. Se preferir trabalhar em C++ na linha de comando, consulte [instruções passo a passo: compilando um programa C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md). Se você gostaria de experimentar o IDE do Visual Studio em vez de usar a linha de comando, consulte [instruções passo a passo: Trabalhando com projetos e soluções (C++)](../ide/walkthrough-working-with-projects-and-solutions-cpp.md) ou [usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C++](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).

## <a name="prerequisites"></a>Pré-requisitos

Para concluir este passo a passo, você deve ter instalado o Visual Studio e os componentes opcionais do Visual C++ ou as ferramentas de Build para o Visual Studio.

Visual Studio é um ambiente de desenvolvimento integrado que oferece suporte a um editor completo e compiladores, depuradores e gerenciadores de recursos para várias linguagens e plataformas. Para obter informações sobre esses recursos e como baixar e instalar o Visual Studio, incluindo o Visual Studio Community edition gratuito, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio).

As ferramentas de Build de versão do Visual Studio do Visual Studio instala apenas o conjunto de ferramentas de linha de comando, os compiladores, ferramentas e bibliotecas que necessárias para compilar programas em C e C++. Ele é perfeito para a criação de laboratórios ou sala de aula exercícios e instala relativamente rápido. Para instalar somente o conjunto de ferramentas de linha de comando, baixe [ferramentas de Build para o Visual Studio](https://go.microsoft.com/fwlink/p/?linkid=875721) e execute o instalador.

Antes de compilar um programa C ou C++ na linha de comando, você deve verificar se as ferramentas são instaladas e que você pode acessá-los na linha de comando. Visual C++ tem requisitos complexos para o ambiente de linha de comando para encontrar as ferramentas, cabeçalhos e bibliotecas que ele usa. **Não é possível usar o Visual C++ em uma janela de prompt de comando simples** sem um pouco de preparação. Você precisa de uma *prompt de comando do desenvolvedor* janela, que é uma janela do prompt de comando regular com todas as variáveis de ambiente necessárias definidas. Felizmente, o Visual C++ instala atalhos para inicializar os prompts de comando do desenvolvedor que têm a configuração de ambiente para compilações de linha de comando. Infelizmente, os nomes dos atalhos de prompt de comando do desenvolvedor e onde eles estão localizados são diferentes em quase todas as versões do Visual C++ e em versões diferentes do Windows. A primeira tarefa do passo a passo é encontrar o atalho correto para usar.

> [!NOTE]
> Um atalho de prompt de comando do desenvolvedor define automaticamente os caminhos corretos para o compilador e ferramentas e para quaisquer cabeçalhos necessários e bibliotecas. Alguns desses valores são diferentes para cada configuração de build. Você deve definir esses valores de ambiente por conta própria se você não usar um dos atalhos. Para obter mais informações, consulte [definir o caminho e variáveis de ambiente para Builds de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md). Como o ambiente de compilação é complexo, é altamente recomendável que usar um atalho de prompt de comando do desenvolvedor em vez de criar seus próprios.

## <a name="open-a-developer-command-prompt"></a>Abra um prompt de comando do desenvolvedor

1. Se você tiver instalado o Visual Studio 2017 no Windows 10, abra o menu Iniciar e, em seguida, role para baixo e abra o **Visual Studio 2017** pasta (não o aplicativo do Visual Studio 2017). Escolher **Prompt de comando do desenvolvedor para VS 2017** para abrir a janela de prompt de comando.

   Se você tiver instalado o Microsoft Visual C++ Build Tools 2015 no Windows 10, abra o **inicie** menu e, em seguida, role para baixo e abra o **ferramentas de Build do Visual C++** pasta. Escolher **Prompt de comando de ferramentas nativas do Visual C++ 2015 x86** para abrir a janela de prompt de comando.

   Se você estiver usando uma versão diferente do Visual Studio ou estiver executando uma versão diferente do Windows, procure no seu menu Iniciar ou página inicial para uma pasta de ferramentas do Visual Studio que contém um atalho de prompt de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para procurar por "prompt de comando do desenvolvedor" e escolha aquela que corresponde à sua versão instalada do Visual Studio. Use o atalho para abrir a janela de prompt de comando.

2. Em seguida, verifique se o prompt de comando do desenvolvedor de Visual C++ está definido corretamente. Na janela do prompt de comando, digite `cl` e verifique se que a saída é semelhante a:

   ```Output
   C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>cl
   Microsoft (R) C/C++ Optimizing Compiler Version 19.10.25017 for x86
   Copyright (C) Microsoft Corporation.  All rights reserved.

   usage: cl [ option... ] filename... [ /link linkoption... ]

   C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise>
   ```

   Pode haver diferenças no diretório atual ou os números de versão, dependendo da versão do Visual C++ e qualquer atualização instalada. Se isso é semelhante ao que você vê, em seguida, você está pronto para criar programas C ou C++ na linha de comando.

   > [!NOTE]
   > Se você receber um erro, como "'cl' não é reconhecido como um comando interno ou externo, programa operável ou arquivo em lotes," Erro C1034 ou erro LNK1104 quando você executa o **cl** de comando, em seguida, ou você não estiver usando um prompt de comando do desenvolvedor, ou algo está errado com sua instalação do Visual C++. Você deve corrigir esse problema antes de continuar.

   Se você não encontrar o desenvolvedor de atalho do prompt de comando, ou se você receber uma mensagem de erro quando você insere `cl`, em seguida, a instalação do Visual C++ pode ter um problema. Se você estiver usando o Visual Studio 2017, tente reinstalar o **desenvolvimento para Desktop com C++** carga de trabalho no instalador do Visual Studio. Para obter detalhes, consulte [suporte de instalar o C++ no Visual Studio](../build/vscpp-step-0-installation.md). Ou então, reinstalar o [ferramentas de Build para o Visual Studio](https://go.microsoft.com/fwlink/p/?linkid=875721). Não vá para a próxima seção até que isso funciona. Para obter mais informações sobre como instalar e solução de problemas de Visual Studio, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio).

   > [!NOTE]
   > Dependendo da versão do Windows no computador e a configuração de segurança do sistema, talvez seja necessário com o botão direito para abrir o menu de atalho para o atalho de prompt de comando do desenvolvedor e, em seguida, escolha **executar como administrador** para compilar e executar o programa que você criar seguindo este passo a passo com êxito.

## <a name="create-a-c-source-file-and-compile-it-on-the-command-line"></a>Criar um arquivo de código-fonte C e compilá-lo na linha de comando

1. Na janela de prompt de comando do desenvolvedor, digite **cd c:\\**  para alterar o diretório de trabalho atual para a raiz da unidade c:. Em seguida, insira **c:\simple md** para criar um diretório e, em seguida, insira **c:\simple cd** para alterar para aquele diretório. Este é o diretório que contém seu arquivo de origem e o programa compilado.

2. Insira **bloco de notas simple.c** no prompt de comando do desenvolvedor. No bloco de notas alerta diálogo pop-up, escolha **Sim** para criar um novo arquivo simple.c no diretório de trabalho.

3. No bloco de notas, insira as seguintes linhas de código:

    ```C
    #include <stdio.h>

    int main()
    {
        printf("Hello, World! This is a native C program compiled on the command line.\n");
        return 0;
    }
    ```

4. Na barra de menus do bloco de notas, escolha **arquivo**, **salvar** salvar simple.c no diretório de trabalho.

5. Alterne para a janela de prompt de comando do desenvolvedor. Insira **dir** no prompt de comando para listar o conteúdo do diretório c:\simple. Você deve ver o simple.c do arquivo de origem na listagem de diretório, que pode ter esta aparência:

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

   As datas e outros detalhes serão diferentes em seu computador. Se você não vir seu arquivo de código fonte, simple.c, verifique se você tiver alterado para o diretório c:\simple que você criou e no bloco de notas, certifique-se de que você salvou o arquivo de origem nesse diretório. Além disso, certifique-se de que você salvou o código-fonte com uma extensão de nome de arquivo. c, não é uma extensão. txt.

6. Para compilar seu programa, insira **cl simple.c** no prompt de comando do desenvolvedor.

   Você pode ver o nome do programa executável, simple.exe, nas linhas das informações de saída exibidas pelo compilador:

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
   > Se você receber um erro, como "'cl' não é reconhecido como um comando interno ou externo, programa operável ou arquivo em lotes," Erro C1034 ou erro LNK1104, seu prompt de comando do desenvolvedor não está configurado corretamente. Para obter informações sobre como corrigir esse problema, volte para o **abra um prompt de comando do desenvolvedor** seção.

   > [!NOTE]
   > Se você receber um diferente do compilador ou aviso ou erro de vinculador, revise seu código-fonte para corrigir os erros, em seguida, salvá-lo e executar o compilador novamente. Para obter informações sobre erros específicos, use a caixa de pesquisa na parte superior desta página para procurar o número do erro.

7. Para executar seu programa, digite **simples** no prompt de comando.

   O programa exibe este texto e fecha na sequência:

    ```Output
    Hello, World! This is a native C program compiled on the command line.
    ```

   Parabéns, você apenas compilado e executar um programa C, usando a linha de comando.

## <a name="next-steps"></a>Próximas etapas

Este exemplo "Hello, World" é mais simple como um programa C pode obter. Programas do mundo real têm arquivos de cabeçalho e mais arquivos de código-fonte, vincular nas bibliotecas e fazer trabalho útil.

Você pode usar as etapas neste passo a passo para criar seu próprio código do C em vez de digitar o código de exemplo mostrado. Você também pode criar muitos programas C de exemplo de código que você encontre em outro lugar. Para compilar um programa que tem vários arquivos de código-fonte, inseri-las all na linha de comando, como este:

`cl file1.c file2.c file3.c`

O compilador gera um programa chamado file1.exe. Para alterar o nome para program1.exe, adicione uma [/out](../build/reference/out-output-file-name.md) a opção de vinculador:

`cl file1.c file2.c file3.c /link /out:program1.exe`

E para capturar erros de programação mais automaticamente, é recomendável que você compilar usando o [/w3](../build/reference/compiler-option-warning-level.md) ou [/W4](../build/reference/compiler-option-warning-level.md) opção de nível de aviso:

`cl /W4 file1.c file2.c file3.c /link /out:program1.exe`

O compilador, cl.exe, tem muito mais opções se aplicam para compilar, otimizar, depurar e analisar seu código. Para obter uma lista rápida, insira **cl /?** no prompt de comando do desenvolvedor. Também pode compilar e vincular separadamente e aplicar opções de vinculador em cenários mais complexos de compilação. Para obter mais informações sobre o compilador e as opções do vinculador e uso, consulte [referência de build do C/C++](../build/reference/c-cpp-building-reference.md).

Você pode usar o MSBuild e arquivos de projeto e makefiles ou NMAKE para configurar e criar projetos mais complexos na linha de comando. Para obter mais informações sobre como usar essas ferramentas, consulte [referência de NMAKE](../build/nmake-reference.md) e [MSBuild](../build/msbuild-visual-cpp.md).

As linguagens C e C++ são semelhantes, mas não o mesmo. O compilador do Visual C++ usa uma regra simples para determinar qual idioma usar quando ele compila seu código. Por padrão, o compilador do Visual C++ trata todos os arquivos que terminam em .c como código-fonte C e todos os arquivos que terminam em .cpp como código-fonte C++. Para forçar o compilador trate todos os arquivos como C, independentemente da extensão de nome de arquivo, use o [/Tc](../build/reference/tc-tp-tc-tp-specify-source-file-type.md) opção de compilador.

O compilador do Visual C++ C é geralmente compatível com o padrão ISO C99, mas não estritamente em conformidade. Na maioria dos casos, o código do C portátil compilará e executará conforme o esperado. Visual C++ não oferece suporte a maioria das alterações no ISO C11. Determinadas funções de biblioteca e nomes de função POSIX foram preteridos pelo compilador Visual C++. As funções têm suporte, mas os nomes preferenciais foram alterados. Para obter mais informações, consulte [recursos de segurança no CRT](../c-runtime-library/security-features-in-the-crt.md) e [aviso do compilador (nível 3) C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).

## <a name="see-also"></a>Consulte também

[Passo a passo: Criando um programa C++ padrão (C++)](../windows/walkthrough-creating-a-standard-cpp-program-cpp.md)
[referência da linguagem C](../c-language/c-language-reference.md)<br/>
[Compilando programas do C/C++](../build/building-c-cpp-programs.md)<br/>
[Compatibilidade](../c-runtime-library/compatibility.md)
