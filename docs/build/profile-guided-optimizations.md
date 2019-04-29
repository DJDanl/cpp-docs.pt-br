---
title: Otimizações guiadas por perfil
ms.date: 04/23/2019
helpviewer_keywords:
- profile-guided optimizations
- optimization, profile-guided [C++]
ms.assetid: 2225c307-d3ae-42c1-8345-a5a959d132dc
ms.openlocfilehash: 46619e77861b6a3a78d74ce6c6d9173a3a5f270f
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64341149"
---
# <a name="profile-guided-optimizations"></a>Otimizações guiadas por perfil

Otimização Guiada por perfil (PGO) permite otimizar um arquivo executável inteiro, em que o otimizador usa dados de execuções de teste do arquivo. dll ou. .exe. Os dados representam o probabilidade de desempenho do programa em um ambiente de produção.

Otimizações guiadas por perfil estão disponíveis apenas para destinos nativos x86 ou x64. Otimizações guiadas por perfil não estão disponíveis para arquivos executáveis que são executados no common language runtime. Mesmo se você gerar um assembly com código nativo e gerenciado misto (usando o **/clr** opção de compilador), você não pode usar a Otimização Guiada por perfil no código nativo. Se você tentar compilar um projeto com essas opções definidas no IDE, os resultados a um erro de compilação.

> [!NOTE]
> Informações coletadas de execuções de teste de criação de perfil substituem as otimizações que seriam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, consulte [/Ob (expansão de função embutida)](reference/ob-inline-function-expansion.md) e [/Os, /Ot (favorecer código pequeno, favorecer código rápido)](reference/os-ot-favor-small-code-favor-fast-code.md).

## <a name="steps-to-optimize-your-app"></a>Etapas para otimizar o seu aplicativo

Para usar a Otimização Guiada por perfil, siga estas etapas para otimizar o seu aplicativo:

- Compilar um ou mais arquivos de código de origem com [/GL](reference/gl-whole-program-optimization.md).

   Cada módulo compilado com **/GL** podem ser examinados durante execuções de teste de Otimização Guiada por perfil para capturar o comportamento de tempo de execução. Cada módulo em uma compilação de Otimização Guiada por perfil não precisa ser compilado com **/GL**. No entanto, somente os módulos compilados com **/GL** são instrumentadas e disponíveis mais tarde para otimizações guiadas por perfil.

- Vincular usando [/LTCG](reference/ltcg-link-time-code-generation.md) e [/GENPROFILE ou /FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md).

   Usando os dois **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** cria um `.pgd` arquivo quando o aplicativo instrumentado é executado. Depois que os dados de execução de teste são adicionados para o `.pgd` arquivo, ele pode ser usado como entrada para a próxima etapa de link (Criar imagem otimizada). Ao especificar **/GENPROFILE**, opcionalmente, você pode adicionar uma **PGD =**_filename_ argumento para especificar um nome de não-padrão ou local para o `.pgd` arquivo. A combinação de **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** opções de vinculador substitui preteridas **/LTCG:PGINSTRUMENT** opção de vinculador.

- O perfil do aplicativo.

   Sempre que uma sessão EXE a criação de perfil termina, ou uma DLL de criação de perfil é descarregada, um `appname!N.pgc` arquivo é criado. Um `.pgc` arquivo contém informações sobre uma execução de teste de aplicativo específico. *appname* é o nome do seu aplicativo, e *N* é um número começando com 1, que é incrementado com base no número de outros `appname!N.pgc` arquivos no diretório. Você pode excluir um `.pgc` arquivo se a execução de teste não representa um cenário em que você deseja otimizar.

   Durante uma execução de teste, você pode forçar o fechamento de aberto no momento `.pgc` arquivo e a criação de um novo `.pgc` do arquivo com o [pgosweep](pgosweep.md) utility (por exemplo, ao final de um cenário de teste não coincide com o aplicativo desligamento).

   Seu aplicativo pode invocar diretamente uma função de PGO [PgoAutoSweep](pgoautosweep.md), para capturar os dados de perfil no ponto de chamada como um `.pgc` arquivo. Ele pode dar um melhor controle sobre o código coberto por dados capturados no seu `.pgc` arquivos. Para obter um exemplo de como usar essa função, consulte a [PgoAutoSweep](pgoautosweep.md) documentação.

   Quando você cria sua compilação instrumentada, por padrão, a coleta de dados é feita no modo de não thread-safe, que é mais rápido, mas pode ser imprecisa. Usando o **EXACT** argumento para **/GENPROFILE** ou **/FASTGENPROFILE**, você pode especificar a coleta de dados em modo thread-safe, que é mais preciso, mas mais lento. Essa opção também está disponível se você definir preteridas [PogoSafeMode](environment-variables-for-profile-guided-optimizations.md#pogosafemode) variável de ambiente ou preteridas **/POGOSAFEMODE** opção de vinculador, quando você cria sua compilação instrumentada.

- Vincular usando **/LTCG** e **/USEPROFILE**.

   Usar ambos os **/LTCG** e [/USEPROFILE](reference/useprofile.md) opções do vinculador para criar a imagem otimizada. Esta etapa usa como entrada o `.pgd` arquivo. Quando você especifica **/USEPROFILE**, opcionalmente, você pode adicionar uma **PGD =**_filename_ argumento para especificar um nome de não-padrão ou local para o `.pgd` arquivo. Você também pode especificar esse nome usando preteridas **/PGD.** a opção de vinculador. A combinação de **/LTCG** e **/USEPROFILE** substitui preteridas **/LTCG:PGOPTIMIZE** e **/LTCG:PGUPDATE** opções do vinculador.

É possível até mesmo criar o arquivo executável otimizado e determinar posteriormente que a criação de perfil adicional seria útil para criar uma imagem mais otimizada. Se a imagem instrumentada e sua `.pgd` arquivo estão disponíveis, você pode fazer as execuções de teste adicionais e recriar a imagem otimizada com a mais recente `.pgd` arquivo, usando o mesmo **/LTCG** e **/USEPROFILE** opções do vinculador.

## <a name="optimizations-performed-by-pgo"></a>Otimizações executadas pelo PGO

As otimizações guiadas por perfil incluem essas verificações e aprimoramentos:

- **Inlining** - por exemplo, se uma função r com frequência chamadas de função B e a função B é relativamente pequeno, em seguida, orientada por perfil otimizações função embutida B na função r.

- **Virtual especulação chamar** -se uma chamada virtual ou outra chamada através de um ponteiro de função, com frequência for destinado a uma determinada função, uma otimização guiada por perfil pode inserir uma chamada direta condicionalmente executada para a função de destino com frequência, e a chamada direta pode ser embutida.

- **Alocação de registro** -otimização com base no perfil de dados resulta em melhor alocação de registro.

- **Otimização de bloco básico** -otimização do bloco básico permite que blocos básicos executados comumente executadas temporariamente em um período especificado a ser colocado no mesmo conjunto de páginas (localidade). Ela minimiza o número de páginas usadas, o que minimiza a sobrecarga de memória.

- **Otimização de tamanho/velocidade** -funções em que o programa gasta mais tempo de execução podem ser otimizados para velocidade.

- **Função Layout** - com base no grafo de chamadas e comportamento de chamador/receptor, o perfil criado funções tendem a estar ao longo do mesmo caminho de execução são colocadas na mesma seção.

- **Otimização de ramificação condicional** - com as sondas de valor, orientada por perfil otimizações podem localizar se um determinado valor em uma instrução switch é usado com mais frequência do que outros valores.  Esse valor pode então ser extraído fora da instrução switch.  O mesmo pode ser feito com `if`... `else` instruções em que o otimizador pode ordenar o `if`... `else` assim que qualquer um os `if` ou `else` bloco é colocado em primeiro lugar, dependendo de qual bloco é mais frequentemente true.

- **Separação de código inativo** -código que não é chamado durante a criação de perfil é movido para uma seção especial que é acrescentada ao final do conjunto de seções. Ele mantém efetivamente nesta seção sem as páginas usadas com frequência.

- **Separação de código do EH** -código de EH porque somente excepcionalmente é executado, ele geralmente pode ser movido para uma seção separada. Ele é movido quando otimizações guiadas por perfil podem determinar que as exceções ocorrem apenas em condições excepcionais.

- **Memória intrínsecos** - se expandir um intrínseco ou não depende de se ele for chamado com frequência. Um intrínseco pode também ser otimizado com base no tamanho de bloco de cópias ou movimentações.

## <a name="next-steps"></a>Próximas etapas

Leia mais sobre essas variáveis de ambiente, funções e ferramentas que você pode usar em otimizações guiadas por perfil:

[Variáveis de ambiente para otimizações guiadas por perfil](environment-variables-for-profile-guided-optimizations.md)<br/>
Essas variáveis foram usadas para especificar o comportamento de tempo de execução de cenários de teste. Eles agora estão preteridos e substituídos por novas opções de vinculador. Este documento mostra como mover de variáveis de ambiente para as opções do vinculador.

[PgoAutoSweep](pgoautosweep.md)<br/>
Uma função que você pode adicionar ao seu aplicativo para fornecer refinado `.pgc` controle da captura de dados de arquivo.

[pgosweep](pgosweep.md)<br/>
Um utilitário de linha de comando que grava todos os dados de perfil para o `.pgc` de arquivos, fecha o `.pgc` de arquivo e abre um novo `.pgc` arquivo.

[pgomgr](pgomgr.md)<br/>
Um utilitário de linha de comando que adiciona dados de perfil de um ou mais `.pgc` de arquivos para o `.pgd` arquivo.

[Como: Mesclar vários perfis PGO em um único perfil](how-to-merge-multiple-pgo-profiles-into-a-single-profile.md)<br/>
Exemplos de **pgomgr** uso.

## <a name="see-also"></a>Consulte também

[Ferramentas de compilação adicionais MSVC](reference/c-cpp-build-tools.md)
