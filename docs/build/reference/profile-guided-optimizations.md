---
title: "Otimizações guiadas por perfil | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- profile-guided optimizations
- optimization, profile-guided [C++]
ms.assetid: 2225c307-d3ae-42c1-8345-a5a959d132dc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f2d72ddda460a88830f7f7692f4c9707fa3101a7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="profile-guided-optimizations"></a>Otimizações orientadas a perfil
Otimização Guiada por perfil permite otimizar um arquivo de saída, em que o otimizador usa dados de execução de teste do arquivo .exe ou. dll. Os dados representam como o programa é provável que fazer em um ambiente de produção.  
  
 Otimizações guiadas por perfil só estão disponíveis para x86 ou [!INCLUDE[vcprx64](../../assembler/inline/includes/vcprx64_md.md)] destinos nativo. Otimizações guiadas por perfil não estão disponíveis para os arquivos de saída que serão executados no common language runtime. Mesmo se você gerar um assembly com código gerenciado e nativo misto (compilar com **/clr**), você não pode usar a Otimização Guiada por perfil no código nativo. Se você tentar compilar um projeto com essas opções definidas no IDE, isso resultará em um erro de compilação.  
  
> [!NOTE]
>  Informações coletadas de execuções de teste de criação de perfil substituirão otimizações que estariam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, consulte [/Ob (expansão de função embutida)](../../build/reference/ob-inline-function-expansion.md) e [/Os, /Ot (favorecer código pequeno, favorecer código rápido)](../../build/reference/os-ot-favor-small-code-favor-fast-code.md).  
  
 Você pode usar o automatizada Otimização Guiada por perfil para o plug-in no Hub desempenho e diagnóstico do Visual C++, para simplificar e simplificar o processo de otimização no Visual Studio, ou você pode executar as etapas de otimização manualmente no Visual Studio ou em a linha de comando. Recomendamos o plug-in porque é mais fácil de usar. Para obter informações sobre como obter o plug-in e usá-la para otimizar seu aplicativo, consulte [plug de Otimização Guiada por perfil](../../build/reference/profile-guided-optimization-in-the-performance-and-diagnostics-hub.md).  
  
 Os dois a Otimização Guiada por perfil plug-in manual guiadas por perfil otimização e siga estas etapas para otimizar seu aplicativo:  
  
-   Compilar um ou mais arquivos de código de origem com [/GL](../../build/reference/gl-whole-program-optimization.md).  
  
     Cada módulo compilado com /GL pode ser examinado durante execuções de teste de Otimização Guiada por perfil para capturar o comportamento de tempo de execução. Cada módulo em uma compilação de Otimização Guiada por perfil não precisa ser compilado com /GL. No entanto, somente os módulos compilados com /GL será instrumentado e posterior disponível para otimizações guiadas por perfil.  
  
-   Vincular usando [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) e [/GENPROFILE](../../build/reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md).  
  
     Usando /LTCG e /GENPROFILE cria um arquivo. PGD vazio. Depois que os dados de execução de teste são adicionados ao arquivo. PGD, ele pode ser usado como entrada para a próxima etapa de link (Criar imagem otimizada). Ao especificar /GENPROFILE, você pode opcionalmente adicionar: PGD =`filename` para especificar um nome não padrão ou local para o arquivo. PGD.  
  
-   O perfil do aplicativo.  
  
     Cada vez que uma sessão EXE analisada termina ou uma DLL com perfil é descarregada, um *appname*! arquivo. PGC de # é criado. Um arquivo. PGC contém informações sobre uma execução de teste de aplicativo específico. # é um número começando com 1 que é incrementado com base no número de outros *appname*! #. PGC no diretório. Você pode excluir um arquivo. PGC se a execução de teste não representam um cenário em que você deseja otimizar.  
  
     Durante uma execução de teste, você pode forçar o fechamento do arquivo. PGC abertos no momento e a criação de um novo arquivo. PGC com o [pgosweep](../../build/reference/pgosweep.md) utilitário (por exemplo, ao final de um cenário de teste não coincidir com o encerramento do aplicativo).  
  
     Você pode usar o `PogoSafeMode` opção quando você cria o perfil de seu aplicativo. Essa opção permite que você especifique se deseja criar o perfil de aplicativo no modo de segurança ou no modo rápido. Para obter mais informações sobre esses modos, consulte [PogoSafeMode](../../build/reference/pogosafemode.md).  
  
-   Link com /LTCG e /USEPROFILE.  
  
     Usando /LTCG e /USEPROFILE cria uma imagem otimizada. Esta etapa usa como entrada de arquivo. PGD. Ao especificar /USEPROFILE, você pode opcionalmente adicionar: PGD =`filename` para especificar um nome não padrão ou local para o arquivo. PGD. Para obter mais informações, consulte [/LTCG](../../build/reference/ltcg-link-time-code-generation.md).  
  
 É possível criar o arquivo de saída otimizada e determinar posteriormente que a criação de perfil adicional seria útil para criar uma imagem mais otimizada. Se a imagem instrumentada e seu arquivo. PGD estiverem disponíveis, você pode fazer as execuções de teste adicionais e recriado imagem otimizada com o arquivo. PGD mais recente.  
  
 A seguir está uma lista das otimizações guiadas por perfil:  
  
-   **Inlining** - por exemplo, se houver uma função A que com frequência, chamadas de função B e função B é relativamente pequena, otimizações guiadas por perfil serão função embutida B na função A.  
  
-   **Virtual especulação chamar** -se uma chamada virtual ou outra chamada através de um ponteiro de função, frequentemente tem como alvo uma determinada função, uma otimização guiada por perfil pode inserir uma chamada direta condicionalmente executado para a função de destino com frequência, e a chamada direta pode ser embutida.  
  
-   **Registrar a alocação** - otimizar com o perfil de dados resulta em melhor alocação de registro.  
  
-   **Otimização de bloco básico** -otimização bloco básico permite básicos executados executar temporariamente em um período especificado para ser colocado no mesmo conjunto de páginas (localidade). Isso minimiza o número de páginas usadas, minimizando a sobrecarga de memória.  
  
-   **Otimização de tamanho/velocidade** -funções em que o programa gasta muito tempo podem ser otimizadas para a velocidade.  
  
-   **Função Layout** - com base no gráfico de chamada e atribuído o comportamento de chamador/receptor, funções que tendem a ser ao longo do mesmo caminho de execução são colocadas na mesma seção.  
  
-   **Otimização de ramificação condicional** - com os testes de valor, orientada a perfil otimizações podem localizar se um determinado valor em uma instrução switch é usado com mais frequência do que outros valores.  Esse valor, em seguida, pode ser extraído fora da instrução switch.  O mesmo pode ser feito com if/else instruções em que o otimizador pode ordenar o if/else para que qualquer if ou bloco else é colocado primeiro dependendo de qual bloco é mais frequentemente true.  
  
-   **Separação de código inativo** -código que não é chamado durante a criação de perfil é movido para uma seção especial que é acrescentada ao final do conjunto de seções. Isso impede efetivamente nesta seção fora das páginas usados com frequência.  
  
-   **Separação de código EH** -código o EH, excepcionalmente que está sendo executado, geralmente pode ser movido para uma seção separada quando otimizações guiadas por perfil podem determinar que as exceções ocorrem apenas em condições excepcionais.  
  
-   **Memória intrínsecos** -a expansão de intrínsecos pode decidir melhor se é possível determinar se um intrínseco for chamado com frequência. Um intrínseco também pode ser otimizado com base no tamanho do bloco de movimentações ou cópias.  
  
 Para obter mais informações sobre desempenho otimização manual no IDE ou na linha de comando, consulte [plug de Otimização Guiada por perfil](../../build/reference/profile-guided-optimization-in-the-performance-and-diagnostics-hub.md).  
  
## <a name="in-this-section"></a>Nesta seção  
 [Plug-in de Otimização Guiada por perfil](../../build/reference/profile-guided-optimization-in-the-performance-and-diagnostics-hub.md)  
  
 [Ferramentas para otimização guiada por perfil manual](../../build/reference/tools-for-manual-profile-guided-optimization.md)  
  
 [Como mesclar vários perfis do PGO em um único perfil](../../build/reference/how-to-merge-multiple-pgo-profiles-into-a-single-profile.md)  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)