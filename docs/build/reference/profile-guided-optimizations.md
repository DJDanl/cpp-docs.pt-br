---
title: Otimizações guiadas por perfil | Microsoft Docs
ms.custom: ''
ms.date: 03/14/2018
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- profile-guided optimizations
- optimization, profile-guided [C++]
ms.assetid: 2225c307-d3ae-42c1-8345-a5a959d132dc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c7d6de281097232b1b8abc10a103af9c186e3550
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32379400"
---
# <a name="profile-guided-optimizations"></a>Otimizações orientadas a perfil

Otimização Guiada por perfil permite otimizar um arquivo de saída, em que o otimizador usa dados de execução de teste do arquivo .exe ou. dll. Os dados representam como o programa é provável que fazer em um ambiente de produção.

Otimizações guiadas por perfil só estão disponíveis para x86 ou x64 destinos nativo. Otimizações guiadas por perfil não estão disponíveis para os arquivos de saída que são executados no common language runtime. Mesmo se você gerar um assembly com código gerenciado e nativo misto (usando o **/clr** opção de compilador), você não pode usar a Otimização Guiada por perfil no código nativo. Se você tentar compilar um projeto com essas opções definidas no IDE, resultados de um erro de compilação.

> [!NOTE]
> Informações coletadas de execuções de teste de criação de perfil substituem otimizações que estariam em vigor se você especificar **/Ob**, **/Os**, ou **/Ot**. Para obter mais informações, consulte [/Ob (expansão de função embutida)](../../build/reference/ob-inline-function-expansion.md) e [/Os, /Ot (favorecer código pequeno, favorecer código rápido)](../../build/reference/os-ot-favor-small-code-favor-fast-code.md).

## <a name="steps-to-optimize-your-app"></a>Etapas para otimizar seu aplicativo

Para usar a Otimização Guiada por perfil, siga estas etapas para otimizar o seu aplicativo:

- Compilar um ou mais arquivos de código de origem com [/GL](../../build/reference/gl-whole-program-optimization.md).

   Cada módulo compilado com **/GL** podem ser examinadas durante execuções de teste de Otimização Guiada por perfil para capturar o comportamento de tempo de execução. Cada módulo em uma compilação de Otimização Guiada por perfil não precisa ser compilado com **/GL**. No entanto, somente os módulos compilados com **/GL** são instrumentadas e posterior disponíveis para otimizações guiadas por perfil.

- Vincular usando [/LTCG](../../build/reference/ltcg-link-time-code-generation.md) e [/GENPROFILE ou /FASTGENPROFILE](../../build/reference/genprofile-fastgenprofile-generate-profiling-instrumented-build.md).

   Usando **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** cria um arquivo. PGD quando o aplicativo instrumentado é executado. Depois que os dados de execução de teste são adicionados ao arquivo. PGD, ele pode ser usado como entrada para a próxima etapa de link (Criar imagem otimizada). Ao especificar **/GENPROFILE**, opcionalmente, você pode adicionar uma **PGD =**_filename_ argumento para especificar um nome não padrão ou local para o arquivo. PGD. A combinação de **/LTCG** e **/GENPROFILE** ou **/FASTGENPROFILE** opções do vinculador substitui preterido **/LTCG:PGINSTRUMENT** opção de vinculador.

- O perfil do aplicativo.

   Cada vez que uma sessão EXE analisada termina ou uma DLL com perfil é descarregada, um *appname*! arquivo. PGC de # é criado. Um arquivo. PGC contém informações sobre uma execução de teste de aplicativo específico. # é um número começando com 1 que é incrementado com base no número de outros *appname*! #. PGC no diretório. Você pode excluir um arquivo. PGC se a execução de teste não representam um cenário em que você deseja otimizar.

   Durante uma execução de teste, você pode forçar o fechamento do arquivo. PGC abertos no momento e a criação de um novo arquivo. PGC com o [pgosweep](../../build/reference/pgosweep.md) utilitário (por exemplo, ao final de um cenário de teste não coincidir com o encerramento do aplicativo).

   Seu aplicativo também diretamente pode invocar uma função PGO, [PgoAutoSweep](pgoautosweep.md), para capturar os dados de perfil no ponto de chamada como um arquivo. PGC. Isso pode fornecer um controle mais preciso sobre o código coberto pelos dados capturados no seu arquivo. PGC. Para obter um exemplo de como usar essa função, consulte o [PgoAutoSweep](pgoautosweep.md) documentação.

   Quando você cria sua compilação instrumentada, por padrão, a coleta de dados é feita no modo de non-thread-safe, que é mais rápido, mas não pode ser completamente precisa. Usando o **exato** argumento **/GENPROFILE** ou **/FASTGENPROFILE**, você pode especificar a coleta de dados no modo de thread-safe, que é mais preciso, mas mais lento. Essa opção também está disponível se você definir preterido [PogoSafeMode](environment-variables-for-profile-guided-optimizations.md#pogosafemode) variável de ambiente ou preterido **/POGOSAFEMODE** opção de vinculador, quando você cria sua compilação instrumentada.

- Vincular usando **/LTCG** e **/USEPROFILE**.

   Usar o **/LTCG** e [/USEPROFILE](useprofile.md) opções do vinculador para criar a imagem otimizada. Esta etapa usa como entrada de arquivo. PGD. Quando você especifica **/USEPROFILE**, opcionalmente, você pode adicionar uma **PGD =**_filename_ argumento para especificar um nome diferente do padrão ou local para o arquivo. PGD. Você também pode especificar esse nome usando preterido **/PGD** opção de vinculador. A combinação de **/LTCG** e **/USEPROFILE** substitui preterido **/LTCG:PGOPTIMIZE** e **/LTCG:PGUPDATE** opções do vinculador.

É possível criar o arquivo de saída otimizada e determinar posteriormente que a criação de perfil adicional seria útil para criar uma imagem mais otimizada. Se a imagem instrumentada e seu arquivo. PGD estiverem disponíveis, você pode fazer execuções de teste adicionais e recriar a imagem otimizada com o arquivo. PGD mais recente, usando o mesmo **/LTCG** e **/USEPROFILE** opções do vinculador .

## <a name="optimizations-performed-by-pgo"></a>Otimizações executadas pelo PGO

A seguir está uma lista das otimizações guiadas por perfil:

- **Inlining** - por exemplo, se houver uma função A que com frequência, chamadas de função B e função B é relativamente pequena, otimizações guiadas por perfil serão função embutida B na função A.

- **Virtual especulação chamar** -se uma chamada virtual ou outra chamada através de um ponteiro de função, frequentemente tem como alvo uma determinada função, uma otimização guiada por perfil pode inserir uma chamada direta condicionalmente executado para a função de destino com frequência, e a chamada direta pode ser embutida.

- **Registrar a alocação** - otimizar com o perfil de dados resulta em melhor alocação de registro.

- **Otimização de bloco básico** -otimização bloco básico permite básicos executados executar temporariamente em um período especificado para ser colocado no mesmo conjunto de páginas (localidade). Isso minimiza o número de páginas usadas, minimizando a sobrecarga de memória.

- **Otimização de tamanho/velocidade** -funções em que o programa gasta muito tempo podem ser otimizadas para a velocidade.

- **Função Layout** - com base no gráfico de chamada e atribuído o comportamento de chamador/receptor, funções que tendem a ser ao longo do mesmo caminho de execução são colocadas na mesma seção.

- **Otimização de ramificação condicional** - com os testes de valor, orientada a perfil otimizações podem localizar se um determinado valor em uma instrução switch é usado com mais frequência do que outros valores.  Esse valor, em seguida, pode ser extraído fora da instrução switch.  O mesmo pode ser feito com if/else instruções em que o otimizador pode ordenar o if/else para que qualquer if ou bloco else é colocado primeiro dependendo de qual bloco é mais frequentemente true.

- **Separação de código inativo** -código que não é chamado durante a criação de perfil é movido para uma seção especial que é acrescentada ao final do conjunto de seções. Isso impede efetivamente nesta seção fora das páginas usados com frequência.

- **Separação de código EH** -código o EH, excepcionalmente que está sendo executado, geralmente pode ser movido para uma seção separada quando otimizações guiadas por perfil podem determinar que as exceções ocorrem apenas em condições excepcionais.

- **Memória intrínsecos** -a expansão de intrínsecos pode decidir melhor se é possível determinar se um intrínseco for chamado com frequência. Um intrínseco também pode ser otimizado com base no tamanho do bloco de movimentações ou cópias.

Se você usar o Visual Studio 2013, você pode usar o automatizada [plug de Otimização Guiada por perfil](../../build/reference/profile-guided-optimization-in-the-performance-and-diagnostics-hub.md) do Visual C++ no Hub desempenho e diagnóstico para simplificar e simplificar o processo de otimização no Visual Studio. Esse plug-in não está disponível em versões posteriores do Visual Studio.

## <a name="next-steps"></a>Próximas etapas

Leia mais sobre essas variáveis de ambiente, funções e ferramentas que você pode usar otimizações guiadas por perfil:

[Variáveis de ambiente para otimizações guiadas por perfil](../../build/reference/environment-variables-for-profile-guided-optimizations.md)<br/>
Essas variáveis podem ser usadas para especificar o comportamento de tempo de execução de cenários de teste. Eles foram preteridos em favor de novas opções de vinculador; Leia aqui para ajudá-lo a mover de variáveis de ambiente para as opções do vinculador.

[PgoAutoSweep](pgoautosweep.md)<br/>
Uma função que você pode adicionar ao seu aplicativo para fornecer controle de captura de dados de arquivo. PGC refinada.

[pgosweep](../../build/reference/pgosweep.md)<br/>
Um utilitário de linha de comando que grava todos os dados de perfil para o arquivo. PGC, fecha o arquivo. PGC e abre um novo arquivo. PGC.

[pgomgr](../../build/reference/pgomgr.md)<br/>
Um utilitário de linha de comando que adiciona dados de perfil de um ou mais arquivos. PGC para o arquivo. PGD.

[Como: mesclar vários perfis PGO em um único perfil](../../build/reference/how-to-merge-multiple-pgo-profiles-into-a-single-profile.md) exemplos de **pgomgr** uso.

## <a name="see-also"></a>Consulte também

[Ferramentas de build do C/C++](../../build/reference/c-cpp-build-tools.md)
