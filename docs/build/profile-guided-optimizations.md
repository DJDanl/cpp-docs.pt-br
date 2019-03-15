---
title: Otimizações orientadas a perfil
ms.date: 03/14/2018
helpviewer_keywords:
- profile-guided optimizations
- optimization, profile-guided [C++]
ms.assetid: 2225c307-d3ae-42c1-8345-a5a959d132dc
ms.openlocfilehash: f4e9af0b2e08dfa4082ebe71caf788ed1188ab7b
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824349"
---
# <a name="profile-guided-optimizations"></a>Otimizações orientadas a perfil

Otimização Guiada por perfil permite otimizar um arquivo de saída, em que o otimizador usa dados de execuções de teste do arquivo .exe ou. dll. Os dados representam como o programa é tende a ter em um ambiente de produção.

Otimizações guiadas por perfil estão disponíveis apenas para destinos nativos x86 ou x64. Otimizações guiadas por perfil não estão disponíveis para arquivos de saída que são executados no common language runtime. Mesmo se você gerar um assembly com código nativo e gerenciado misto (usando o **/clr** opção de compilador), você não pode usar a Otimização Guiada por perfil no código nativo. Se você tentar compilar um projeto com essas opções definidas no IDE, os resultados a um erro de compilação.

> [!NOTE]
> Informações coletadas de execuções de teste de criação de perfil substituem as otimizações que seriam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, consulte [/Ob (expansão de função embutida)](reference/ob-inline-function-expansion.md) e [/Os, /Ot (favorecer código pequeno, favorecer código rápido)](reference/os-ot-favor-small-code-favor-fast-code.md).

## <a name="steps-to-optimize-your-app"></a>Etapas para otimizar o seu aplicativo

Para usar a Otimização Guiada por perfil, siga estas etapas para otimizar o seu aplicativo:

- Compilar um ou mais arquivos de código de origem com [/GL](reference/gl-whole-program-optimization.md).

   Cada módulo compilado com **/GL** podem ser examinados durante execuções de teste de Otimização Guiada por perfil para capturar o comportamento de tempo de execução. Cada módulo em uma compilação de Otimização Guiada por perfil não precisa ser compilado com **/GL**. No entanto, somente os módulos compilados com **/GL** são instrumentadas e disponíveis mais tarde para otimizações guiadas por perfil.

- Vincular usando [/LTCG](reference/ltcg-link-time-code-generation.md) e [/GENPROFILE ou /FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md).

   Usando os dois **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** cria um arquivo. PGD quando o aplicativo instrumentado é executado. Depois que os dados de execução de teste são adicionados ao arquivo. PGD, ele pode ser usado como entrada para a próxima etapa de link (Criar imagem otimizada). Ao especificar **/GENPROFILE**, opcionalmente, você pode adicionar uma **PGD =**_filename_ argumento para especificar um nome de não-padrão ou local para o arquivo. PGD. A combinação de **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** opções de vinculador substitui preteridas **/LTCG:PGINSTRUMENT** opção de vinculador.

- O perfil do aplicativo.

   Sempre que uma sessão com criação de perfil do EXE termina ou uma DLL de criação de perfil é descarregada, uma *appname*!. # PGC arquivo é criado. Um arquivo. PGC contém informações sobre uma execução de teste de aplicativo específico. # é um número começando com 1 que é incrementado com base no número de outras *appname*! #. PGC no diretório. Se a execução de teste não representa um cenário em que você deseja otimizar, você pode excluir um arquivo. PGC.

   Durante uma execução de teste, você pode forçar o fechamento do arquivo. PGC aberto no momento e a criação de um novo arquivo. PGC com o [pgosweep](pgosweep.md) utility (por exemplo, ao final de um cenário de teste não coincidir com o desligamento do aplicativo).

   Seu aplicativo pode invocar diretamente uma função de PGO [PgoAutoSweep](pgoautosweep.md), para capturar os dados de perfil no ponto de chamada como um arquivo. PGC. Isso pode dar um melhor controle sobre o código coberto pelos dados capturados em seus arquivos. PGC. Para obter um exemplo de como usar essa função, consulte a [PgoAutoSweep](pgoautosweep.md) documentação.

   Quando você cria sua compilação instrumentada, por padrão, a coleta de dados é feita no modo de não thread-safe, que é mais rápido, mas pode não ser completamente precisa. Usando o **EXACT** argumento **/GENPROFILE** ou **/FASTGENPROFILE**, você pode especificar a coleta de dados no modo de thread-safe, que é mais preciso, mas mais lento. Essa opção também está disponível se você definir preteridas [PogoSafeMode](environment-variables-for-profile-guided-optimizations.md#pogosafemode) variável de ambiente ou preteridas **/POGOSAFEMODE** opção de vinculador, quando você cria sua compilação instrumentada.

- Vincular usando **/LTCG** e **/USEPROFILE**.

   Usar ambos os **/LTCG** e [/USEPROFILE](reference/useprofile.md) opções do vinculador para criar a imagem otimizada. Esta etapa usa como entrada o arquivo. PGD. Quando você especifica **/USEPROFILE**, opcionalmente, você pode adicionar uma **PGD =**_filename_ argumento para especificar um nome de não-padrão ou local para o arquivo. PGD. Você também pode especificar esse nome usando preteridas **/PGD.** a opção de vinculador. A combinação de **/LTCG** e **/USEPROFILE** substitui preteridas **/LTCG:PGOPTIMIZE** e **/LTCG:PGUPDATE** opções do vinculador.

É possível até mesmo criar o arquivo de saída otimizada e determinar posteriormente que a criação de perfil adicional seria útil para criar uma imagem mais otimizada. Se a imagem instrumentada e seu arquivo. PGD estiverem disponíveis, você pode fazer as execuções de teste adicionais e recriar a imagem otimizada com o arquivo. PGD mais recente, usando o mesmo **/LTCG** e **/USEPROFILE** opções do vinculador .

## <a name="optimizations-performed-by-pgo"></a>Otimizações executadas pelo PGO

A seguir está uma lista das otimizações guiadas por perfil:

- **Inlining** - por exemplo, se houver uma função A que com frequência chamadas de função B e a função B é relativamente pequena, otimizações guiadas por perfil serão a função embutida B na função r.

- **Virtual especulação chamar** -se uma chamada virtual ou outra chamada através de um ponteiro de função, com frequência for destinado a uma determinada função, uma otimização guiada por perfil pode inserir uma chamada direta condicionalmente executado para a função frequentemente alvo, e a chamada direta pode ser embutida.

- **Alocação de registro** - otimização com o perfil de dados resulta em melhor alocação de registro.

- **Otimização de bloco básico** -otimização do bloco básico permite que blocos básicos executados comumente executadas temporariamente em um período especificado a ser colocado no mesmo conjunto de páginas (localidade). Isso minimiza o número de páginas usadas, minimizando a sobrecarga de memória.

- **Otimização de tamanho/velocidade** -funções em que o programa passa muito tempo podem ser otimizados para velocidade.

- **Função Layout** - com base no grafo de chamadas e comportamento de chamador/receptor, o perfil criado funções tendem a estar ao longo do mesmo caminho de execução são colocadas na mesma seção.

- **Otimização de ramificação condicional** - com as sondas de valor, orientada por perfil otimizações podem localizar se um determinado valor em uma instrução switch é usado com mais frequência do que outros valores.  Esse valor pode então ser extraído fora da instrução switch.  O mesmo pode ser feito com if/else instruções em que o otimizador pode ordenar o if/else, de modo que qualquer if ou bloco else é colocado pela primeira vez, dependendo de qual bloco é mais frequentemente true.

- **Separação de código inativo** -código que não é chamado durante a criação de perfil é movido para uma seção especial que é acrescentada ao final do conjunto de seções. Isso efetivamente impede que esta seção sem as páginas usadas com frequência.

- **Separação de código do EH** -EH o código, excepcionalmente executado, com muitas vezes pode ser movido para uma seção separada quando otimizações guiadas por perfil podem determinar que as exceções ocorrem apenas em condições excepcionais.

- **Memória intrínsecos** -a expansão de intrínsecos pode decidir melhor se ele puder ser determinado se um intrínseco for chamado com frequência. Um intrínseco pode também ser otimizado com base no tamanho de bloco de cópias ou movimentações.

Se você usar o Visual Studio 2013, você pode usar o automated [plug-in de otimização de guiada por perfil](profile-guided-optimization-in-the-performance-and-diagnostics-hub.md) do Visual C++ no Hub desempenho e diagnóstico para simplificar e facilitar o processo de otimização dentro do Visual Studio. Esse plug-in não está disponível em versões posteriores do Visual Studio.

## <a name="next-steps"></a>Próximas etapas

Leia mais sobre essas variáveis de ambiente, funções e ferramentas que você pode usar em otimizações guiadas por perfil:

[Variáveis de ambiente para otimizações guiadas por perfil](environment-variables-for-profile-guided-optimizations.md)<br/>
Essas variáveis podem ser usadas para especificar o comportamento de tempo de execução de cenários de teste. Eles foram substituídos por novas opções de vinculador; Leia esta para ajudá-lo a mover de variáveis de ambiente para as opções do vinculador.

[PgoAutoSweep](pgoautosweep.md)<br/>
Uma função que você pode adicionar ao seu aplicativo para fornecer controle de captura de dados de arquivo. PGC refinado.

[pgosweep](pgosweep.md)<br/>
Um utilitário de linha de comando que grava todos os dados de perfil no arquivo. PGC, fecha o arquivo. PGC e abre um novo arquivo. PGC.

[pgomgr](pgomgr.md)<br/>
Um utilitário de linha de comando que adiciona dados de perfil de um ou mais arquivos. PGC para o arquivo. PGD.

[Como: mesclar vários perfis do PGO em um único perfil](how-to-merge-multiple-pgo-profiles-into-a-single-profile.md)<br/>
Exemplos de **pgomgr** uso.

## <a name="see-also"></a>Consulte também

[Ferramentas de Build do MSVC adicionais](reference/c-cpp-build-tools.md)
