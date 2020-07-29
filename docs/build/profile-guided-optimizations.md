---
title: Otimizações orientadas a perfil
ms.date: 04/23/2019
helpviewer_keywords:
- profile-guided optimizations
- optimization, profile-guided [C++]
ms.assetid: 2225c307-d3ae-42c1-8345-a5a959d132dc
ms.openlocfilehash: efa4c35810f6272b89ff11cd1c890a7f535cfc1c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232723"
---
# <a name="profile-guided-optimizations"></a>Otimizações orientadas a perfil

A PGO (otimização guiada por perfil) permite otimizar um arquivo executável inteiro, no qual o otimizador usa dados de execuções de teste do arquivo. exe ou. dll. Os dados representam o desempenho provável do programa em um ambiente de produção.

As otimizações guiadas por perfil estão disponíveis somente para destinos nativos x86 ou x64. As otimizações guiadas por perfil não estão disponíveis para arquivos executáveis que são executados no Common Language Runtime. Mesmo que você produza um assembly com código nativo e gerenciado Misto (usando a opção de compilador **/CLR** ), não é possível usar a otimização guiada por perfil apenas no código nativo. Se você tentar criar um projeto com essas opções definidas no IDE, ocorrerá um erro de compilação.

> [!NOTE]
> As informações coletadas de execuções de teste de criação de perfil substituem otimizações que, de outra forma, teriam efeito se você especificar **/OB**, **/os**ou **/OT**. Para obter mais informações, consulte [/Ob (expansão de função embutida)](reference/ob-inline-function-expansion.md) e [/os,/OT (favorecer código pequeno, favorecer código rápido)](reference/os-ot-favor-small-code-favor-fast-code.md).

## <a name="steps-to-optimize-your-app"></a>Etapas para otimizar seu aplicativo

Para usar a otimização guiada por perfil, siga estas etapas para otimizar seu aplicativo:

- Compilar um ou mais arquivos de código-fonte com [/GL](reference/gl-whole-program-optimization.md).

   Cada módulo criado com **/GL** pode ser examinado durante execuções de teste de Otimização Guiada por perfil para capturar o comportamento em tempo de execução. Cada módulo em uma compilação de Otimização Guiada por perfil não precisa ser compilado com **/GL**. No entanto, somente os módulos compilados com **/GL** são instrumentados e posteriormente disponíveis para otimizações guiadas por perfil.

- Link usando [/LTCG](reference/ltcg-link-time-code-generation.md) e [/GENPROFILE ou/FASTGENPROFILE](reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md).

   O uso de **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** cria um `.pgd` arquivo quando o aplicativo instrumentado é executado. Depois que os dados de execução de teste são adicionados ao `.pgd` arquivo, ele pode ser usado como entrada para a próxima etapa de link (criando a imagem otimizada). Ao especificar **/GENPROFILE**, você pode opcionalmente adicionar um argumento **PGD =**_filename_ para especificar um nome ou local não padrão para o `.pgd` arquivo. A combinação das opções de vinculador **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** substitui a opção de vinculador **/LTCG: PGINSTRUMENT** preterida.

- Criar o perfil do aplicativo.

   Cada vez que uma sessão EXE com criação de perfil é encerrada ou uma DLL de criação de perfil é descarregada, um `appname!N.pgc` arquivo é criado. Um `.pgc` arquivo contém informações sobre uma execução de teste de aplicativo específico. *AppName* é o nome do seu aplicativo e *N* é um número que começa com 1 que é incrementado com base no número de outros `appname!N.pgc` arquivos no diretório. Você pode excluir um `.pgc` arquivo se a execução de teste não representar um cenário que você deseja otimizar.

   Durante uma execução de teste, você pode forçar o fechamento do arquivo aberto no momento `.pgc` e a criação de um novo `.pgc` arquivo com o utilitário [PGOSWEEP](pgosweep.md) (por exemplo, quando o final de um cenário de teste não coincide com o desligamento do aplicativo).

   Seu aplicativo também pode invocar diretamente uma função PGO, [PgoAutoSweep](pgoautosweep.md), para capturar os dados de perfil no ponto da chamada como um `.pgc` arquivo. Ele pode lhe dar um melhor controle sobre o código coberto pelos dados capturados em seus `.pgc` arquivos. Para obter um exemplo de como usar essa função, consulte a documentação do [PgoAutoSweep](pgoautosweep.md) .

   Quando você cria sua compilação instrumentada, por padrão, a coleta de dados é feita no modo não seguro de thread, que é mais rápido, mas pode ser imprecisa. Usando o argumento **exato** para **/GENPROFILE** ou **/FASTGENPROFILE**, você pode especificar a coleta de dados no modo de thread-safe, o que é mais preciso, mas mais lento. Essa opção também estará disponível se você definir a variável de ambiente [PogoSafeMode](environment-variables-for-profile-guided-optimizations.md#pogosafemode) preterida ou a opção de vinculador **/POGOSAFEMODE** preterida ao criar sua compilação instrumentada.

- Link usando **/LTCG** e **/USEPROFILE**.

   Use as opções do vinculador **/LTCG** e [/USEPROFILE](reference/useprofile.md) para criar a imagem otimizada. Essa etapa usa como entrada do `.pgd` arquivo. Ao especificar **/USEPROFILE**, você pode opcionalmente adicionar um argumento **PGD =**_filename_ para especificar um nome ou local não padrão para o `.pgd` arquivo. Você também pode especificar esse nome usando a opção de vinculador **/PGD** preterida. A combinação de **/LTCG** e **/USEPROFILE** substitui as opções de vinculador **/LTCG: PGOPTIMIZE** e **/LTCG: PGUPDATE** preteridas.

É possível, até mesmo, criar o arquivo executável otimizado e, posteriormente, determinar que a criação de perfil adicional seria útil para criar uma imagem mais otimizada. Se a imagem instrumentada e seu `.pgd` arquivo estiverem disponíveis, você poderá executar execuções de teste adicionais e recriar a imagem otimizada com o arquivo mais recente `.pgd` , usando as mesmas opções de vinculador **/LTCG** e **/USEPROFILE** .

> [!NOTE]
> Os `.pgc` `.pgd` arquivos e são tipos de arquivo binários. Se estiver armazenado em um sistema de controle do código-fonte, evite qualquer transformação automática que possa ser feita em arquivos de texto.

## <a name="optimizations-performed-by-pgo"></a>Otimizações executadas pelo PGO

As otimizações guiadas por perfil incluem essas verificações e aprimoramentos:

- **Outlining** – por exemplo, se uma função com frequência chamar a função b e a função b for relativamente pequena, as otimizações guiadas por perfil a função b embutida na função a.

- **Speculation de chamada virtual** -se uma chamada virtual ou outra chamada por meio de um ponteiro de função, com freqüência se destina a uma determinada função, uma otimização guiada por perfil pode inserir uma chamada direta executada condicionalmente para a função direcionada com frequência e a chamada direta pode ser embutida.

- **Registrar** a otimização de alocação com base nos dados de perfil resulta em melhor alocação de registro.

- **Otimização de bloco básica** -a otimização de bloco básica permite blocos básicos executados com frequência que são executados de forma temporal em um determinado quadro para serem colocados no mesmo conjunto de páginas (localidade). Ele minimiza o número de páginas usadas, o que minimiza a sobrecarga de memória.

- **Otimização de tamanho/velocidade** -as funções nas quais o programa gasta mais tempo de execução podem ser otimizadas para velocidade.

- **Layout de função** – com base no grafo de chamada e no comportamento de chamador/receptor de perfil, as funções que tendem a estar ao longo do mesmo caminho de execução são colocadas na mesma seção.

- **Otimização de ramificação condicional** -com as investigações de valor, as otimizações guiadas por perfil podem descobrir se um determinado valor em uma instrução switch é usado com mais frequência do que outros valores.  Esse valor pode então ser extraído da instrução switch.  O mesmo pode ser feito com **`if`** instruções... **`else`** em que o otimizador pode ordenar o **`if`** ... **`else`** para que **`if`** o **`else`** bloco ou seja colocado primeiro, dependendo de qual bloco é mais frequentemente válido.

- **Separação de código inativo** -o código que não é chamado durante a criação de perfil é movido para uma seção especial que é acrescentada ao final do conjunto de seções. Isso efetivamente mantém essa seção fora das páginas usadas com frequência.

- **Separação de código eh** -como o código eh é executado de uma única exceção, ele geralmente pode ser movido para uma seção separada. Ela é movida quando as otimizações guiadas por perfil podem determinar que as exceções ocorrem apenas em condições excepcionais.

- **Intrínsecos de memória** – se é preciso expandir um intrínseco ou não depende se ele é chamado com frequência. Um intrínseco também pode ser otimizado com base no tamanho do bloco de movimentações ou cópias.

## <a name="next-steps"></a>Próximas etapas

Leia mais sobre essas variáveis, funções e ferramentas de ambiente que você pode usar em otimizações guiadas por perfil:

[Variáveis de ambiente para otimizações orientadas a perfil](environment-variables-for-profile-guided-optimizations.md)<br/>
Essas variáveis foram usadas para especificar o comportamento de tempo de execução de cenários de teste. Agora eles são preteridos e substituídos por novas opções do vinculador. Este documento mostra como mover das variáveis de ambiente para as opções do vinculador.

[PgoAutoSweep](pgoautosweep.md)<br/>
Uma função que você pode adicionar ao seu aplicativo para fornecer controle refinado de `.pgc` captura de dados de arquivo.

[pgosweep](pgosweep.md)<br/>
Um utilitário de linha de comando que grava todos os dados de perfil no `.pgc` arquivo, fecha o `.pgc` arquivo e abre um novo `.pgc` arquivo.

[pgomgr](pgomgr.md)<br/>
Um utilitário de linha de comando que adiciona dados de perfil de um ou mais `.pgc` arquivos ao `.pgd` arquivo.

[Como: mesclar vários perfis do PGO em um único perfil](how-to-merge-multiple-pgo-profiles-into-a-single-profile.md)<br/>
Exemplos de uso de **pgomgr** .

## <a name="see-also"></a>Confira também

[Ferramentas de build adicionais do MSVC](reference/c-cpp-build-tools.md)
