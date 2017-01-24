---
title: "Instru&#231;&#245;es passo a passo: compilando um programa em C na linha de comando | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "compilação de programa C [C++]"
  - "aplicações de linha de comando [C++], programas C"
  - "compilando programas [C++]"
  - "Visual C, compilando"
ms.assetid: 7e74cc2d-54b1-49de-b7ad-d3ae6b39ab8d
caps.latest.revision: 46
caps.handback.revision: 44
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: compilando um programa em C na linha de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O Visual C\+\+ inclui um compilador C que você pode usar para criar tudo de programas de console básicos até aplicativos completos de área de trabalho do Windows, aplicativos móveis e muito mais.  
  
 Este passo a passo mostra como criar um basic, "Hello, World"\-estilo C programa usando um texto de editor e compila na linha de comando. Se você preferir trabalhar em C\+\+ na linha de comando, consulte [Instruções passo a passo: compilando um programa do C\+\+ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md). Se você gostaria de tentar o IDE do Visual Studio em vez de usar a linha de comando, consulte [Instruções passo a passo: trabalhando com projetos e soluções \(C\+\+\)](../Topic/Walkthrough:%20Working%20with%20Projects%20and%20Solutions%20\(C++\).md) ou [Usando o IDE do Visual Studio para desenvolvimento de área de trabalho do C\+\+](../ide/using-the-visual-studio-ide-for-cpp-desktop-development.md).  
  
## Pré-requisitos  
 Para concluir este passo a passo, você deve ter instalado o Visual Studio e os componentes opcionais do Visual C\+\+ ou o Microsoft Visual C\+\+ ferramentas de compilação.  
  
 O Visual Studio é um ambiente de desenvolvimento integrado poderosa que oferece suporte a um editor completo e compiladores, depuradores e gerenciadores de recursos para várias linguagens e plataformas. Para obter informações sobre esses recursos e como baixar e instalar o Visual Studio, incluindo a edição gratuita do Visual Studio Community, consulte [VisualStudio.com](https://www.visualstudio.com/).  
  
 O Microsoft Visual C\+\+ ferramentas de compilação instala apenas o compilador de linha de comando, ferramentas e bibliotecas que necessárias para criar programas em C e C\+\+. Ele é perfeito para laboratórios de compilação ou em sala de aula exercícios e instala relativamente rápido. Para instalar apenas as ferramentas de linha de comando, baixe e instale o [Microsoft Visual C\+\+ Build Tools 2015](http://go.microsoft.com/fwlink/?LinkId=691126).  
  
 Antes de criar um programa C ou C\+\+ na linha de comando, você deve verificar que as ferramentas são instaladas e se você pode acessá\-los na linha de comando. Visual C\+\+ tem requisitos complexos para o ambiente de linha de comando para localizar as ferramentas, cabeçalhos e bibliotecas que ele usa.**Não é possível usar o Visual C\+\+ em uma janela de prompt de comando simples**. Felizmente, o Visual C\+\+ instala atalhos para iniciar um prompt de comando do desenvolvedor com o ambiente configurado para compilações de linha de comando. Infelizmente, os nomes dos atalhos do prompt de comando do desenvolvedor e onde estão localizados são diferentes em quase todas as versões do Visual C\+\+ e em versões diferentes do Windows. A primeira tarefa do passo a passo é encontrar um certo para usar.  
  
> [!NOTE]
>  Um atalho de prompt de comando do desenvolvedor define automaticamente os caminhos corretos para o compilador e ferramentas e para quaisquer cabeçalhos necessários e bibliotecas. Você deve definir esses valores do ambiente mesmo se você usar uma janela de Prompt de comando normal. Para obter mais informações, consulte [Definindo as variáveis de caminho e ambiente para compilações de linha de comando](../build/setting-the-path-and-environment-variables-for-command-line-builds.md). É recomendável que usar um atalho de prompt de comando do desenvolvedor em vez de criar seus próprios.  
  
### Abra um prompt de comando do desenvolvedor  
  
1.  Se você tiver instalado o Visual Studio 2015 no Windows 10, abra o menu Iniciar e escolha **todos os aplicativos**. Role para baixo e abra o **Visual Studio 2015** pasta \(não o aplicativo do Visual Studio 2015\). Escolha **Prompt de comando do desenvolvedor para VS2015** para abrir a janela de prompt de comando.  
  
     Se você tiver instalado o Microsoft Visual C\+\+ Build Tools 2015 no Windows 10, abra o **Iniciar** menu e escolha **todos os aplicativos**. Role para baixo e abra o **Ferramentas de compilação do Visual C\+\+** pasta. Escolha **Prompt de comando de ferramentas nativas do Visual C\+\+ 2015 x86** para abrir a janela de prompt de comando.  
  
     Se você estiver usando uma versão diferente do Visual Studio ou está executando uma versão diferente do Windows, procure no menu Iniciar ou iniciar a página para uma pasta de ferramentas do Visual Studio que contém um atalho de prompt de comando do desenvolvedor. Você também pode usar a função de pesquisa do Windows para procurar por "prompt de comando do desenvolvedor" e escolha aquela que corresponde a sua versão instalada do Visual Studio. Use o atalho para abrir a janela de prompt de comando.  
  
2.  Em seguida, verifique se o prompt de comando do desenvolvedor de Visual C\+\+ está configurado corretamente. Na janela do prompt de comando, digite `cl` e verifique se que a saída é semelhante a:  
  
    ```Output  
    C:\Program arquivos (x86) \Microsoft Visual Studio 14.0 > cl Microsoft (R) C/C++ Optimizing Compiler versão 19.00.23918 para x86 Copyright (C) Microsoft Corporation.  Todos os direitos reservados. uso: nome de arquivo cl [opção...]... [/ link linkoption...]  
    ```  
  
     Pode haver diferenças no diretório atual ou números de versão, dependendo da versão do Visual C\+\+ e qualquer atualização instalada. Se isso é semelhante ao que você vê, em seguida, você está pronto para criar programas C ou C\+\+ na linha de comando.  
  
    > [!NOTE]
    >  Se você receber um erro, como "'cl' não é reconhecido como um comando interno ou externo, um programa operável ou arquivo em lotes," Erro C1034 ou erro LNK1104 quando você executa o **cl** de comando, em seguida, ou você não estiver usando um prompt de comando do desenvolvedor, ou algo está errado com sua instalação do Visual C\+\+. Você deve corrigir esse problema antes de continuar.  
  
     Se você não encontrar o desenvolvedor de atalho do prompt de comando, ou se você receber uma mensagem de erro quando você insere `cl`, em seguida, a instalação do Visual C\+\+ pode ter um problema. Tente reinstalar o componente do Visual C\+\+ no Visual Studio ou reinstale o Microsoft Visual C\+\+ ferramentas de compilação. Não vá para a próxima seção até que isso funciona. Para obter mais informações sobre como instalar e solucionar problemas do Visual C\+\+, consulte [Instalando o Visual Studio](../Topic/Installing%20Visual%20Studio%202015.md).  
  
    > [!NOTE]
    >  Dependendo da versão do Windows no computador e a configuração de segurança do sistema, talvez você precise clique para abrir o menu de atalho para o atalho do prompt de comando de desenvolvedor e, em seguida, escolha **Executar como administrador** para compilar e executar o programa que você criar seguindo este passo a passo.  
  
### Criar um arquivo de código\-fonte C e compilá\-lo na linha de comando  
  
1.  Na janela de prompt de comando do desenvolvedor, digite **md c:\\simple** para criar um diretório e digite **cd c:\\simple** para alterar para aquele diretório. Este é o diretório que contém o arquivo de origem e o programa compilado.  
  
2.  Digite **o bloco de notas simple.c** no prompt de comando do desenvolvedor. No bloco de notas alerta diálogo pop\-up, escolha **Sim** para criar um novo arquivo de simple.c no diretório de trabalho.  
  
3.  No bloco de notas, digite as seguintes linhas de código:  
  
    ```c  
    #include <stdio.h>  
  
    int main()  
    {  
        printf("Hello, World! This is a native C program compiled on the command line.\n");  
        return 0;  
    }   
    ```  
  
4.  Na barra de menus do bloco de notas, escolha **arquivo**, **Salvar** salvar simple.c no diretório de trabalho.  
  
5.  Alterne para a janela de prompt de comando do desenvolvedor. Digite **dir** no prompt de comando para listar o conteúdo da pasta c:\\simple. Você deve ver o simple.c de arquivo de origem na lista de diretórios, que é semelhante a:  
  
    ```Output  
    C:\simple > dir Volume na unidade C não tem nenhum rótulo. Número de série do volume é CC62 6545 diretório de C:\simple 02/10/2015 03:46 PM < DIR >. 02/10/2015 03:46 PM < DIR >... 02/10/2015 03:36 PM 143 simple.c 1 143 arquivos bytes 2 pasta (s) 514,900,566,016 bytes livres  
    ```  
  
     As datas e outros detalhes serão diferentes em seu computador. Se você não vir seu arquivo de código fonte, simple.c, verifique se você alterar o diretório c:\\simple criado e no bloco de notas, certifique\-se de que você salvou o arquivo de origem nesse diretório. Além disso, certifique\-se de que você salvou o código\-fonte com uma extensão de nome de arquivo. c, não uma extensão. txt.  
  
6.  Para compilar o programa, digite **cl simple.c** no prompt de comando do desenvolvedor.  
  
     Você pode ver o nome do programa executável, simple.exe, nas linhas das informações de saída que o compilador exibirá:  
  
    ```Output  
    c:\simple > cl simple.c Microsoft (R) C/C++ Optimizing Compiler versão 19.00.23918 para x86 Copyright (C) Microsoft Corporation.  Todos os direitos reservados. Simple.c Microsoft (R) Incremental Linker versão 14.00.23918.0 Copyright (C) Microsoft Corporation.  Todos os direitos reservados. /out:Simple.exe simple.obj  
    ```  
  
    > [!NOTE]
    >  Se você receber um erro, como "'cl' não é reconhecido como um comando interno ou externo, um programa operável ou arquivo em lotes," C1034 ou erro de LNK1104, o prompt de comando do desenvolvedor não está configurado corretamente. Para obter informações sobre como corrigir esse problema, volte para o **Abra um prompt de comando do desenvolvedor** seção.  
  
    > [!NOTE]
    >  Se você receber um compilador diferente ou aviso ou erro de vinculador, revise seu código\-fonte para corrigir os erros, em seguida, salvá\-la e executar o compilador novamente. Para obter informações sobre erros específicos, use a caixa de pesquisa nesta página do MSDN para procurar o número do erro.  
  
7.  Para executar o programa, digite **simples** no prompt de comando.  
  
     O programa exibe este texto e será encerrado:  
  
    ```Output  
    Olá, mundo! Este é um programa de C nativo compilado na linha de comando.  
    ```  
  
     Parabéns, você apenas compilado e executar um programa em C usando a linha de comando.  
  
## Próximas etapas  
 Este exemplo "Olá, mundo" é mais simple como um programa em C pode obter. Programas do mundo real tem arquivos de cabeçalho e mais arquivos de origem, vincular em bibliotecas e fazer trabalho útil.  
  
 Você pode usar as etapas neste passo a passo para criar seu próprio código C em vez de digitar o código de exemplo mostrado. Você também pode criar muitos programas C de exemplo de código que você encontrar em outro lugar. Para compilar um programa com vários arquivos de código fonte, insira\-os em linha de comando, como esta:  
  
 `cl file1.c file2.c file3.c`  
  
 O compilador gera um programa chamado file1.exe. Para alterar o nome para program1.exe, adicione um [\/out](../build/reference/out-output-file-name.md) opção de vinculador:  
  
 `cl file1.c file2.c file3.c /link /out:program1.exe`  
  
 E para capturar erros de programação mais automaticamente, é recomendável compilar usando o [\/W3](../build/reference/compiler-option-warning-level.md) ou [\/W4](../build/reference/compiler-option-warning-level.md) opção de nível de aviso:  
  
 `cl /W4 file1.c file2.c file3.c /link /out:program1.exe`  
  
 O compilador, cl.exe, tem muito mais opções você pode aplicar para criar, otimizar, depurar e analisar seu código. Para obter uma lista rápida, digite **cl \/?** no prompt de comando do desenvolvedor. Você também pode compilar e vincular separadamente e aplicar opções de vinculador em cenários mais complexos de compilação. Para obter mais informações sobre o compilador e as opções do vinculador e uso, consulte  [referência de compilação do C\/C\+\+](../Topic/C-C++%20Building%20Reference.md).  
  
 Você pode usar NMAKE e makefiles ou arquivos de projeto MSBuild para configurar e criar projetos mais complexos na linha de comando. Para obter mais informações sobre como usar essas ferramentas, consulte [referência a NMAKE](../build/nmake-reference.md) e [MSBuild](../Topic/MSBuild%20\(Visual%20C++\).md).  
  
 As linguagens C e C\+\+ são semelhantes, mas não é a mesma. O compilador do Visual C\+\+ usa uma regra simples para determinar qual idioma a ser usado ao compilar seu código. Por padrão, o compilador do Visual C\+\+ trata todos os arquivos que terminam em. c como código\-fonte C e todos os arquivos que terminam em. cpp como código\-fonte C\+\+. Para forçar o compilador a tratar todos os arquivos como C, independentemente da extensão de nome de arquivo, use o [\/Tc](../build/reference/tc-tp-tc-tp-specify-source-file-type.md) opção de compilador.  
  
 O compilador do Visual C\+\+ C é geralmente compatível com o padrão ISO C99, mas não é totalmente compatível. Na maioria dos casos, o código C portátil compilar e executado conforme o esperado. Visual C\+\+ não oferece suporte a maioria das alterações no ISO C11. Determinadas funções de biblioteca e nomes de função POSIX são substituídos pelo compilador Visual C\+\+. As funções são suportadas, mas os nomes preferenciais foram alterados. Para obter mais informações, consulte [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md) e [Compilador \(nível 3\) aviso C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).  
  
## Consulte também  
 [Instruções passo a passo: criando um programa de console Win32 \(C\+\+\)](../windows/walkthrough-creating-a-standard-cpp-program-cpp.md)   
 [Referência de linguagem C](../Topic/C%20Language%20Reference.md)   
 [Compilando programas do C\/C\+\+](../build/building-c-cpp-programs.md)   
 [Compatibilidade](../c-runtime-library/compatibility.md)