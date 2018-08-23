---
title: /MP (compilar com vários processos) | Microsoft Docs
ms.custom: ''
ms.date: 02/22/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.MultiProcessorCompilation
dev_langs:
- C++
helpviewer_keywords:
- -MP compiler option (C++)
- /MP compiler option (C++)
- MP compiler option (C++)
- cl.exe compiler, multi-process build
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3e61f1ac30c2a50cbbefe6c0cbd9e28011a0d0bd
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42573016"
---
# <a name="mp-build-with-multiple-processes"></a>/MP (compilar com vários processos)

O **/MP** opção pode reduzir o tempo total para compilar os arquivos de origem na linha de comando. O **/MP** opção faz com que o compilador crie uma ou mais cópias de si mesmo, cada um em um processo separado. Em seguida, essas cópias simultaneamente compilar os arquivos de origem. Consequentemente, o tempo total para compilar os arquivos de origem pode ser reduzido significativamente.

## <a name="syntax"></a>Sintaxe

> **/MP**[*processMax*]

## <a name="arguments"></a>Arguments

*processMax*<br/>
(Opcional) O número máximo de processos que o compilador pode criar.

O *processMax* argumento deve variar de 1 a 65536. Caso contrário, o compilador emite a mensagem de aviso **D9014**, ignora as *processMax* argumento e pressupõe que o número máximo de processos é 1.

Se você omitir a *processMax* argumento, o compilador recupera o número de [processadores efetivos](#effective_processors) no computador do sistema operacional e cria um processo para cada processador.

## <a name="remarks"></a>Comentários

O **/MP** opção de compilador pode reduzir significativamente o tempo de compilação ao compilar vários arquivos. Para melhorar o tempo de compilação, o compilador cria até *processMax* copia de si mesmo e, em seguida, usa essas cópias para compilar os arquivos de origem ao mesmo tempo. O **/MP** opção aplica-se com as compilações, mas não a geração de código link-time ou vinculação. Por padrão o **/MP** opção está desativada.

O aprimoramento no tempo de compilação depende do número de processadores em um computador, o número de arquivos a serem compilados e a disponibilidade de recursos do sistema, como capacidade de e/s. Fazer experiências com o **/MP** opção para determinar a melhor configuração para criar um projeto específico. Para obter orientações para ajudá-lo a tomar essa decisão, consulte [diretrizes](#guidelines).

## <a name="incompatible-options-and-language-features"></a>Opções incompatíveis e recursos de linguagem

O **/MP** opção é incompatível com algumas opções de compilador e recursos de linguagem. Se você usar uma opção de compilador incompatível com o **/MP** opção, o compilador emite aviso **D9030** e ignora os **/MP** opção. Se você usar um recurso de linguagem incompatível, o compilador emite o erro [C2813](../../error-messages/compiler-errors-2/compiler-error-c2813.md) e em seguida, termina ou continua, dependendo do opção de nível de aviso do compilador de atual.

> [!NOTE]
> A maioria das opções são incompatíveis porque se eles foram permitidos, os compiladores executados simultaneamente seriam gravam sua saída ao mesmo tempo, no console ou para um arquivo específico. Como resultado, a saída seria misturar e adulterada. Em alguns casos, a combinação das opções tornaria o pior desempenho.

A tabela a seguir lista Opções do compilador e recursos de linguagem que são incompatíveis com o **/MP** opção:

|Opção ou um recurso de linguagem|Descrição|
|--------------------------------|-----------------|
|[#import](../../preprocessor/hash-import-directive-cpp.md) diretiva de pré-processador|Converte os tipos em uma biblioteca de tipos em classes C++ e, em seguida, grava essas classes em um arquivo de cabeçalho.|
|[/E](../../build/reference/e-preprocess-to-stdout.md), [/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md)|Copia a saída de pré-processador para a saída padrão (**stdout**).|
|[/Gm](../../build/reference/gm-enable-minimal-rebuild.md)|Habilita uma recompilação incremental.|
|[/showIncludes](../../build/reference/showincludes-list-include-files.md)|Grava uma lista de arquivos de inclusão para o erro padrão (**stderr**).|
|[/Yc](../../build/reference/yc-create-precompiled-header-file.md)|Grava um arquivo de cabeçalho pré-compilado.|

## <a name="diagnostic-messages"></a>Mensagens de diagnóstico

Se você especificar um recurso de opção ou linguagem que é incompatível com o **/MP** opção, você receberá uma mensagem de diagnóstico. A tabela a seguir lista as mensagens e o comportamento do compilador:

|Mensagem de diagnóstico|Descrição|Comportamento do compilador|
|------------------------|-----------------|-----------------------|
|**C2813**|O **#import** diretiva não é compatível com o **/MP** opção.|A compilação termina, a menos que um [nível de aviso do compilador](../../build/reference/compiler-option-warning-level.md) opção especifique o contrário.|
|**D9014**|Um valor inválido é especificado para o *processMax* argumento.|O compilador ignora o valor inválido e pressupõe que um valor de 1.|
|**D9030**|A opção especificada é incompatível com **/MP**.|O compilador ignora os **/MP** opção.|

## <a name="guidelines"></a> Diretrizes

### <a name="measure-performance"></a>Medir o desempenho

Use o tempo total de compilação para medir o desempenho. Você pode medir o tempo de compilação com um relógio físico ou você pode usar o software que calcula a diferença entre quando o build é iniciado e é interrompido. Se o computador tiver vários processadores, um relógio físico pode produzir resultados mais precisos do que uma medida de tempo de software.

### <a name="effective_processors"></a> Processadores efetivas

Um computador pode ter um ou mais processadores virtuais, que também são conhecidos como *processadores efetivos*, para cada um dos seus processadores físicos. Cada processador físico pode ter um ou mais núcleos, e se o sistema operacional permite que o hyperthreading de um núcleo, cada núcleo parece ser de dois processadores virtuais.

Por exemplo, um computador tem um processador efetivo se ele tiver um processador físico que tem um núcleo e hyperthreading está desativado. Por outro lado, um computador tiver oito processadores efetivação se ele tem dois processadores físicos, cada qual com dois núcleos, e todos os núcleos têm o hyperthreading habilitado. Ou seja, (8 processadores eficazes) = (2 processadores físicos) x (2 núcleos por processador físico) x (2 processadores eficazes por núcleo por causa de hyperthreading).

Se você omitir a *processMax* argumento na **/MP** opção, o compilador obtém o número de processadores em vigor do sistema operacional e, em seguida, cria um processo por processador efetivo. No entanto, o compilador não pode garantir um processo que executa em um processador específico; o sistema operacional toma essa decisão.

### <a name="number-of-processes"></a>Número de processos

O compilador calcula o número de processos que serão usados para compilar os arquivos de origem. Se o valor é o menor número de arquivos de origem que você especificar na linha de comando e o número de processos que você especificar explicitamente ou implicitamente com a **/MP** opção. Você pode definir explicitamente o número máximo de processos se você fornecer a *processMax* argumento do **/MP** opção. Ou você pode usar o padrão, que é igual ao número de processadores em vigor em um computador, se você omitir a *processMax* argumento.

Por exemplo, suponha que você especifique a seguinte linha de comando:

`cl /MP7 a.cpp b.cpp c.cpp d.cpp e.cpp`

Nesse caso, o compilador usa cinco processos porque esse é o menor dos cinco arquivos de origem e um máximo de processos de sete. Como alternativa, suponha que o computador tiver dois processadores em vigor e você especifica a seguinte linha de comando:

`cl /MP a.cpp b.cpp c.cpp`

Nesse caso, o sistema operacional relata dois processadores; Portanto, o compilador usa dois processos em seu cálculo. Como resultado, o compilador executará a compilação com dois processos, porque esse é o menor dos dois processos e três arquivos de origem.

### <a name="source-files-and-build-order"></a>Arquivos de origem e a ordem de compilação

Os arquivos de origem não podem ser compilados na mesma ordem em que aparecem na linha de comando. Embora o compilador cria um conjunto de processos que contêm cópias do compilador, o sistema operacional agenda quando cada processo é executado. Consequentemente, você não pode garantir que os arquivos de origem serão compilados em uma ordem específica.

Um arquivo de origem é compilado quando um processo está disponível para compilá-lo. Se houver mais arquivos de processos, o primeiro conjunto de arquivos é compilado por processos disponíveis. Os arquivos restantes são processados quando um processo termina de tratamento de um arquivo anterior e está disponível para trabalhar em um dos arquivos restantes.

Não especifique o mesmo arquivo de origem várias vezes em uma linha de comando. Isso pode ocorrer, por exemplo, se uma ferramenta cria automaticamente um [makefile](../../build/contents-of-a-makefile.md) que se baseia em informações de dependência em um projeto. Se você não especificar o **/MP** opção, o compilador processa a lista de arquivos em sequência e recompila cada ocorrência do arquivo. No entanto, se você especificar o **/MP** opção, compiladores diferentes podem compilar o mesmo arquivo ao mesmo tempo. Consequentemente, os compiladores diferentes tentará gravar no mesmo arquivo de saída ao mesmo tempo. Um compilador adquirirá o acesso de gravação exclusivo ao arquivo de saída e tenha êxito e os outros compiladores falhará com um erro de acesso de arquivo.

### <a name="using-type-libraries-import"></a>Usando bibliotecas de tipo (#import)

O compilador não suporta o uso do [#import](../../preprocessor/hash-import-directive-cpp.md) diretiva com o **/MP** alternar. Se possível, siga estas etapas para contornar esse problema:

- Mover todos os `#import` diretivas em seu vários arquivos de origem para um ou mais arquivos e, em seguida, compilar esses arquivos sem as **/MP** opção. O resultado é um conjunto de arquivos de cabeçalho gerado.

- No seu restantes arquivos de origem, insira [#include](../../preprocessor/hash-include-directive-c-cpp.md) arquivos de origem de diretivas que especificam os cabeçalhos gerados e, em seguida, compile seu restantes usando a **/MP** opção.

### <a name="visual-studio-project-settings"></a>Configurações de projeto do Visual Studio

#### <a name="the-msbuildexe-tool"></a>A ferramenta MSBUILD.exe

O Visual Studio usa o [MSBuild.exe](/visualstudio/msbuild/msbuild-reference) ferramenta para criar soluções e projetos. O **/maxcpucount:**_número_ (ou **/m:**_número_) a opção de linha de comando da ferramenta MSBuild.exe pode criar vários projetos no mesmo tempo. E o **/MP** opção de compilador pode criar várias unidades de compilação ao mesmo tempo. Se for apropriado para seu aplicativo, melhorar o tempo de compilação da sua solução por meio de uma ou ambas **/MP** e **/maxcpucount**.

O tempo de compilação da sua solução parcialmente depende do número de processos que executam a compilação. O *número* argumento do [/maxcpucount](/visualstudio/msbuild/msbuild-command-line-reference) MSBuild opção especifica o número máximo de projetos que serão compilados ao mesmo tempo. Da mesma forma, o *processMax* argumento do **/MP** opção do compilador Especifica o número máximo de unidades de compilação para compilar ao mesmo tempo. Se o **/maxcpucount** opção especifica *P* projetos e o **/MP** opção especifica *C* processa um máximo de *P*  x *C* processos executem ao mesmo tempo.

 A diretriz para decidir se deseja usar o MSBuild ou **/MP** tecnologia é da seguinte maneira:

- Se houver muitos projetos com alguns arquivos em cada projeto, use a ferramenta MSBuild.

- Se houver alguns projetos com muitos arquivos em cada projeto, use o **/MP** opção.

- Se o número de projetos e arquivos por projeto é equilibrado, use ambos os MSBuild e **/MP**. Inicialmente definida a **/maxcpucount** opção para o número de projetos para compilar e o **/MP** opção para o número de processadores no computador. Medir o desempenho e, em seguida, ajustar as configurações para produzir os melhores resultados. Repita esse ciclo até ficar satisfeito com o tempo total de compilação.

#### <a name="the-gm-compiler-option"></a>A opção de compilador /Gm

Por padrão, um projeto de build permite que o **/Gm** (compilações incrementais) de opção de compilador para compilações de depuração e desabilita-lo para lançamento de builds. Portanto, o **/MP** opção de compilador automaticamente está desabilitada em builds de depuração porque ele está em conflito com o padrão **/Gm** opção de compilador.

## <a name="see-also"></a>Consulte também

[#import diretiva](../../preprocessor/hash-import-directive-cpp.md)<br/>
[Referência de linha de comando](/visualstudio/msbuild/msbuild-command-line-reference)<br/>
[/Zf (gerar PDB mais rápido)](zf.md)<br/>
