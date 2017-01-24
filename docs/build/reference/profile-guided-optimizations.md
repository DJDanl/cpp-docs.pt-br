---
title: "Otimiza&#231;&#245;es orientadas a perfil | Microsoft Docs"
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
  - "otimização, guiado por perfil [C++]"
  - "otimizações guiadas por perfil"
ms.assetid: 2225c307-d3ae-42c1-8345-a5a959d132dc
caps.latest.revision: 26
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Otimiza&#231;&#245;es orientadas a perfil
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Otimização Guiada por perfil permite otimizar um arquivo de saída, em que o otimizador usa dados de execuções de teste do arquivo .exe ou. dll.  Os dados representam como o programa é provável executar em um ambiente de produção.  
  
 Otimizações guiadas por perfil só estão disponíveis para computadores x86 ou [!INCLUDE[vcprx64](../Token/vcprx64_md.md)] destinos nativos.  Otimizações guiadas por perfil não estão disponíveis para arquivos de saída que serão executado no common language runtime.  Mesmo se você gerar um assembly com código nativo e gerenciado misto \(compilar com **\/clr**\), você não pode usar a Otimização Guiada por perfil no código nativo.  Se você tentar criar um projeto com essas opções definidas no IDE, resultará um erro de compilação.  
  
> [!NOTE]
>  Informações coletadas de execuções de teste de criação de perfil substituirá otimizações que seriam em vigor se você especificar **\/Ob**, **\/Os**, ou **\/Ot**.  Para obter mais informações, consulte [\/Ob \(expansão de função embutida\)](../../build/reference/ob-inline-function-expansion.md) e [\/Os, \/Ot \(favorecer código pequeno, favorecer código rápido\)](../../build/reference/os-ot-favor-small-code-favor-fast-code.md).  
  
 Você pode usar a otimização guiada automatizada de perfil para o plug\-in no Hub desempenho e diagnóstico do Visual C\+\+ para simplificar e facilitar o processo de otimização no Visual Studio, ou você pode executar as etapas de otimização manualmente no Visual Studio ou na linha de comando.  Recomendamos o plug\-in porque é mais fácil de usar.  Para obter informações sobre como obter o plug\-in e usá\-lo para otimizar o seu aplicativo, consulte [Plug\-in de Otimização Guiada por Perfil](../../build/reference/profile-guided-optimization-in-the-performance-and-diagnostics-hub.md).  
  
 Os dois a Otimização Guiada por perfil plug\-in manual guiada por perfil otimização e siga estas etapas para otimizar seu aplicativo:  
  
-   Compilar um ou mais arquivos de código fonte com [\/GL](../../build/reference/gl-whole-program-optimization.md).  
  
     Cada módulo criado com \/GL pode ser examinado durante execuções de teste de Otimização Guiada por perfil para capturar o comportamento de tempo de execução.  Cada módulo em uma compilação de Otimização Guiada por perfil não precisa ser compilado com \/GL.  No entanto, somente os módulos compilados com \/GL serão instrumentados e posterior disponível para otimizações guiadas por perfil.  
  
-   Vincular com [\/LTCG:PGINSTRUMENT](../../build/reference/ltcg-link-time-code-generation.md).  
  
     \/LTCG:PGINSTRUMENT cria um arquivo PGD vazia.  Depois de adicionar os dados de execução de teste para o arquivo PGD, ele pode ser usado como entrada para a próxima etapa de link \(Criando a imagem otimizada\).  Ao especificar \/LTCG:PGINSTRUMENT, você pode opcionalmente especificar [\/PGD](../../build/reference/pgd-specify-database-for-profile-guided-optimizations.md) com um nome não padrão ou local para o arquivo PGD.  
  
-   O perfil do aplicativo.  
  
     Sempre que uma sessão EXE perfilada termina ou uma DLL com perfil for descarregada, um *appname*\! .pgc \# arquivo é criado.  Um arquivo de .pgc contém informações sobre a execução de um teste de aplicativo específico.  \# é um número começando com 1 é incrementado com base no número de outros *appname*\! .pgc \# arquivos no diretório.  Você pode excluir um arquivo .pgc se a execução do teste não representa um cenário em que você deseja otimizar.  
  
     Durante uma execução de teste, você pode forçar o fechamento do arquivo .pgc aberto no momento e a criação de um novo arquivo de .pgc com o [pgosweep](../../build/reference/pgosweep.md) utility \(por exemplo, ao final de um cenário de teste não coincide com o desligamento do aplicativo\).  
  
     Você pode usar o `PogoSafeMode` opção quando você cria o perfil de seu aplicativo.  Essa opção permite que você especifique se você deseja analisar o aplicativo no modo de segurança ou no modo rápido.  Para obter mais informações sobre esses modos, consulte [PogoSafeMode](../../build/reference/pogosafemode.md).  
  
-   Link de \/LTCG:PGOPTIMIZE.  
  
     \/LTCG:PGOPTIMIZE cria uma imagem otimizada.  Esta etapa usa como entrada de arquivo PGD.  Para obter mais informações, consulte [\/LTCG:PGOPTIMIZE](../../build/reference/ltcg-link-time-code-generation.md).  
  
 É possível criar o arquivo de saída otimizada e depois determinar que perfis adicionais seriam úteis para criar uma imagem mais otimizada.  Se a imagem instrumentada e seu arquivo PGD estiverem disponíveis, você pode fazer execuções de teste adicionais e recriado imagem otimizada com o arquivo PGD mais recente.  
  
 A seguir está uma lista das otimizações guiadas por perfil:  
  
-   **Inlining** – por exemplo, se houver uma função A que com freqüência chamadas de função B, a função B é relativamente pequena e otimizações guiadas por perfil serão função embutida B na função A.  
  
-   **Virtual especulação chamar** – se uma chamada virtual ou outra chamada através de um ponteiro de função, freqüentemente tem como alvo uma determinada função, uma otimização guiada por perfil pode inserir uma chamada direta condicionalmente executado para a função direcionados com freqüência e a chamada direta pode ser embutida.  
  
-   **Alocação registrar** – otimização com os dados de perfil resulta em melhor alocação de registro.  
  
-   **Otimização de bloco básico** – otimização do bloco básico permite executados básicos que executam temporariamente em um período especificado sejam colocados no mesmo conjunto de páginas \(localidade\).  Isso minimiza o número de páginas usadas, minimizando a sobrecarga de memória.  
  
-   **Otimização de tamanho\/velocidade** – funções onde o programa passa muito tempo podem ser otimizadas para velocidade.  
  
-   **Layout de função** – com base no gráfico de chamada e comportamento de chamador\/receptor perfilada, funções que tendem a ser ao longo do mesmo caminho de execução são colocadas na mesma seção.  
  
-   **Otimização de ramificação condicional** – com os testes de valor, guiada por perfil otimizações podem localizar se um determinado valor em uma instrução switch é usado com mais freqüência do que outros valores.  Esse valor pode ser obtida da instrução switch.  O mesmo pode ser feito com if\/else instruções em que o otimizador pode solicitar o if\/else para que qualquer if ou bloco else é colocado primeiro dependendo de qual bloco é mais frequentemente verdadeiro.  
  
-   **a separação de código inativo** – código que não é chamado durante a criação de perfil é movido para uma seção especial que é acrescentada ao final do conjunto de seções.  Isso efetivamente manterá essa seção de páginas usadas com freqüência.  
  
-   **EH separação de código** – EH o código, excepcionalmente executado, com freqüência pode ser movido para uma seção separada quando otimizações guiadas por perfil podem determinar que as exceções ocorrem apenas em condições excepcionais.  
  
-   **Memória intrínsecos** – a expansão de intrínsecos pode decidir melhor se é possível determinar se a função intrínseca é chamada com freqüência.  Função intrínseca pode também ser otimizada com base no tamanho do bloco de cópias ou movimentações.  
  
 Para obter mais informações sobre desempenho otimização manual no IDE ou na linha de comando, consulte [passo a passo: otimizações de Using Profile\-Guided](http://msdn.microsoft.com/pt-br/6e36421b-ec8c-4626-9c29-fa5ffb6f27f8).  
  
## Nesta seção  
 [Plug\-in de Otimização Guiada por Perfil](../../build/reference/profile-guided-optimization-in-the-performance-and-diagnostics-hub.md)  
  
 [Ferramentas para otimização orientada a perfil](../../build/reference/tools-for-manual-profile-guided-optimization.md)  
  
 [Como mesclar vários perfis PGO em um único perfil](../Topic/How%20to:%20Merge%20Multiple%20PGO%20Profiles%20into%20a%20Single%20Profile.md)  
  
## Consulte também  
 [Ferramentas de compilação do C\/C\+\+](../Topic/C-C++%20Build%20Tools.md)