---
title: "-MP (com v&#225;rios processos de compila&#231;&#227;o) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.VCCLCompilerTool.MultiProcessorCompilation"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de compilador -MP (C++)"
  - "Opção de compilador /MP (C++)"
  - "Opção de compilador MP (C++)"
  - "compilador cl.exe, compilação de multiprocesso"
ms.assetid: a932b14a-74fe-4b45-84e4-6bf53f0f5e07
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /MP (compilar com v&#225;rios processos)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O **\/MP** opção pode reduzir o tempo total para compilar os arquivos de origem na linha de comando. O **\/MP** opção faz com que o compilador para criar uma ou mais cópias de si mesmo, cada um deles em um processo separado. Essas cópias simultaneamente compila os arquivos de origem. Consequentemente, o tempo total para compilar os arquivos de origem pode ser reduzido significativamente.  
  
## Sintaxe  
  
```  
/MP[processMax]  
```  
  
## Arguments  
 `processMax`  
 \(Opcional\) O número máximo de processos que o compilador pode criar.  
  
 O `processMax` argumento deve variar de 1 a 65536. Caso contrário, o compilador emite a mensagem de aviso `D9014`, ignora o `processMax` argumento e pressupõe que o número máximo de processos é 1.  
  
 Se você omitir o `processMax` argumento, o compilador recupera o número de [processadores efetivos](#effective_processors) no computador do sistema operacional e cria um processo para cada processador.  
  
## Comentários  
 O **\/MP** opção de compilador pode reduzir significativamente o tempo de compilação quando você compila a muitos arquivos. Para melhorar o tempo de compilação, o compilador cria até `processMax` cópias de si mesmo e, em seguida, usa essas cópias para compilar os arquivos de origem ao mesmo tempo. O **\/MP** opção aplica\-se com as compilações, mas não para geração de código link\-time ou vinculação. Por padrão o **\/MP** opção está desativada.  
  
 A melhoria no tempo de compilação depende do número de processadores em um computador, o número de arquivos para compilar e a disponibilidade de recursos do sistema, como a capacidade de e\/s. Experimente o **\/MP** opção para determinar a melhor configuração para criar um projeto específico. Para obter orientações para ajudá\-lo a tomar essa decisão, consulte [diretrizes](#guidelines).  
  
## Opções incompatíveis e recursos de linguagem  
 O **\/MP** opção é incompatível com algumas opções do compilador e recursos de linguagem. Se você usar uma opção de compilador incompatível com o **\/MP** opção, o compilador emite aviso `D9030` e ignora o **\/MP** opção. Se você usar um recurso de idioma incompatível, o compilador emite erro `C2813`em seguida, termina ou continua dependendo do opção de nível de aviso do compilador de atual.  
  
> [!NOTE]
>  A maioria das opções são incompatíveis porque se eles foram permitidos, os compiladores executados simultaneamente escreveria sua saída ao mesmo tempo para o console ou para um arquivo específico. Como resultado, a saída seria misturar e adulterada. Em alguns casos, a combinação de opções tornaria o pior desempenho.  
  
 A tabela a seguir lista Opções do compilador e recursos de linguagem que são incompatíveis com o **\/MP** opção:  
  
|Opção ou recurso de linguagem|Descrição|  
|-----------------------------------|---------------|  
|[\#import](../Topic/%23import%20Directive%20\(C++\).md) diretiva de pré\-processador|Converte os tipos em uma biblioteca de tipos em classes C\+\+ e, em seguida, grava essas classes em um arquivo de cabeçalho.|  
|[\/E](../../build/reference/e-preprocess-to-stdout.md), [\/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md)|Copia a saída de pré\-processador para a saída padrão \(**stdout**\).|  
|[\/GM](../../build/reference/gm-enable-minimal-rebuild.md)|Permite uma recriação incremental.|  
|[\/showIncludes](../Topic/-showIncludes%20\(List%20Include%20Files\).md)|Grava uma lista de arquivos de inclusão para o erro padrão \(**stderr**\).|  
|[\/Yc](../../build/reference/yc-create-precompiled-header-file.md)|Grava um arquivo de cabeçalho pré\-compilado.|  
  
## Mensagens de diagnóstico  
 Se você especificar um recurso de opção ou linguagem que é incompatível com o **\/MP** opção, você receberá uma mensagem de diagnóstico. A tabela a seguir lista as mensagens e o comportamento do compilador:  
  
|Mensagem de diagnóstico|Descrição|Comportamento do compilador|  
|-----------------------------|---------------|---------------------------------|  
|`C2813`|O **\#import** diretiva não é compatível com o **\/MP** opção.|A compilação termina, a menos que um [nível de aviso do compilador](../../build/reference/compiler-option-warning-level.md) opção especifique o contrário.|  
|`D9014`|Um valor inválido é especificado para o `processMax` argumento.|O compilador ignora o valor inválido e assume um valor de 1.|  
|`D9030`|A opção especificada é incompatível com **\/MP**.|O compilador ignora o **\/MP** opção.|  
  
##  <a name="guidelines"></a> Diretrizes  
  
### Medir o desempenho  
 Use o tempo de compilação total para medir o desempenho. Você pode medir o tempo de compilação com um relógio de físico, ou você pode usar o software que calcula a diferença entre quando a compilação é iniciada e interrompida. Se o computador tiver vários processadores, um relógio físico pode produzir resultados mais precisos que uma medida de tempo de software.  
  
###  <a name="effective_processors"></a> Processadores efetivos  
 Um computador pode ter um ou mais processadores virtuais, que são também conhecidos como processadores efetivos, para cada um dos seus processadores físicos. Cada processador físico pode ter um ou mais núcleos, e se o sistema operacional permite que o hyperthreading de um núcleo, cada núcleo parece ser dois processadores virtuais.  
  
 Por exemplo, um computador tem um processador eficaz se ele tem um processador físico que tem um núcleo e hyperthreading está desabilitado. Por outro lado, um computador tem oito processadores eficaz se tiver dois processadores físicos, cada qual com dois núcleos, e todos os núcleos têm o hyperthreading habilitado. Isto é, \(8 processadores efetivos\) \= \(2 processadores físicos\) x \(2 núcleos por processador físico\) x \(2 processadores eficazes por núcleo devido hyperthreading\).  
  
 Se você omitir o `processMax` argumento o **\/MP** opção, o compilador obtém o número de processadores efetivos do sistema operacional e, em seguida, cria um processo por processador efetivo. No entanto, o compilador não pode garantir um processo que executa em um processador específico; o sistema operacional toma essa decisão.  
  
### Número de processos  
 O compilador calcula o número de processos que serão usados para compilar os arquivos de origem. Se o valor é o menor número de arquivos de origem que você especificar na linha de comando e o número de processos que você especificar explicitamente ou implicitamente com o **\/MP** opção. Você pode definir explicitamente o número máximo de processos se você fornecer o `processMax` argumento o **\/MP** opção. Ou você pode usar o padrão, que é igual ao número de processadores efetivos em um computador, se você omitir o `processMax` argumento.  
  
 Por exemplo, suponha que você especifique a seguinte linha de comando:  
  
 `cl /MP7 a.cpp b.cpp c.cpp d.cpp e.cpp`  
  
 Nesse caso o compilador usa cinco processos porque é o menos de cinco arquivos de origem e um máximo de sete processos. Como alternativa, suponha que o computador tiver dois processadores eficazes e especifique a seguinte linha de comando:  
  
 `cl /MP a.cpp b.cpp c.cpp`  
  
 Nesse caso, o sistema operacional relata dois processadores; Portanto, o compilador usa dois processos em seu cálculo. Como resultado, o compilador executará a compilação com dois processos, porque esse é o menor dos dois processos e três arquivos de origem.  
  
### Arquivos de origem e a ordem de compilação  
 Os arquivos de origem não podem ser compilados na mesma ordem em que aparecem na linha de comando. Embora o compilador cria um conjunto de processos que contêm cópias do compilador, o sistema operacional agenda quando cada processo é executado. Consequentemente, você não pode garantir que os arquivos de origem serão compilados em uma ordem específica.  
  
 Um arquivo de origem é compilado quando um processo está disponível para compilá\-lo. Se houver mais arquivos de processos, o primeiro conjunto de arquivos é compilado, os processos disponíveis. Os arquivos restantes são processados quando um processo termina tratando um arquivo anterior e está disponível para trabalhar em um dos arquivos restantes.  
  
 Não especifique o mesmo arquivo de origem várias vezes em uma linha de comando. Isso pode ocorrer, por exemplo, se uma ferramenta cria automaticamente um [makefile](../../build/contents-of-a-makefile.md) que se baseia em informações de dependência em um projeto. Se você não especificar o **\/MP** opção, o compilador processa a lista de arquivos sequencialmente e recompilações cada ocorrência do arquivo. No entanto, se você especificar o **\/MP** opção compiladores diferentes podem compilar o mesmo arquivo ao mesmo tempo. Consequentemente, os compiladores diferentes tentará gravar no mesmo arquivo de saída ao mesmo tempo. Um compilador será adquirir acesso de gravação exclusivo ao arquivo de saída bem\-sucedida e os outros compiladores falhará com um erro de acesso de arquivo.  
  
### Usando bibliotecas de tipo \(\#import\)  
 O compilador não suporta o uso do [\#import](../Topic/%23import%20Directive%20\(C++\).md) diretiva com o **\/MP** alternar. Se possível, siga estas etapas para solucionar esse problema:  
  
-   Mova todos os `#import` diretivas no seu vários arquivos de origem para um ou mais arquivos e compila os arquivos sem o **\/MP** opção. O resultado é um conjunto de arquivos de cabeçalho gerado.  
  
-   No seu restantes arquivos de origem, insira [\#include](../../preprocessor/hash-include-directive-c-cpp.md) arquivos de origem de diretivas que especificam os cabeçalhos gerados e, em seguida, compile o restante usando o **\/MP** opção.  
  
### Configurações de projeto do Visual Studio  
  
#### A ferramenta MSBUILD.exe  
 [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)] usa o [MSBuild.exe](../Topic/MSBuild%20Reference.md) ferramenta para criar soluções e projetos. O **\/maxcpucount:**`number` \(ou **\/m:**`number`\) a opção de linha de comando da ferramenta MSBuild.exe pode criar vários projetos ao mesmo tempo. E o **\/MP** opção de compilador pode criar várias unidades de compilação ao mesmo tempo. Se for apropriado para seu aplicativo, melhoram o tempo de compilação da solução utilizando um ou ambos **\/MP** e **\/maxcpucount**.  
  
 O tempo de compilação da solução depende parcialmente do número de processos que executam a compilação. O `number` argumento o [\/maxcpucount](../Topic/MSBuild%20Command-Line%20Reference.md) MSBuild opção especifica o número máximo de projetos que serão compilados ao mesmo tempo. Da mesma forma, o `processMax` argumento o **\/MP** opção de compilador Especifica o número máximo de unidades de compilação a compilação ao mesmo tempo. Se o **\/maxcpucount** opção especifica *P* projetos e o **\/MP** opção especifica *C* processa um máximo de *P*x*C* processos executem ao mesmo tempo.  
  
 A diretriz para decidir se deve usar `MSBuild` ou **\/MP** tecnologia é o seguinte:  
  
-   Se houver muitos projetos com alguns arquivos em cada projeto, use o `MSBuild` ferramenta.  
  
-   Se houver alguns projetos com muitos arquivos em cada projeto, use o **\/MP** opção.  
  
-   Se o número de projetos e arquivos por projeto é equilibrado, use ambos `MSBuild` e **\/MP**. Definir inicialmente o **\/maxcpucount** opção para o número de projetos para criar e o **\/MP** opção para o número de processadores no computador. Medir o desempenho e, em seguida, ajuste as configurações para produzir os melhores resultados. Repita esse ciclo até ficar satisfeito com o tempo de compilação total.  
  
#### A opção de compilador \/Gm  
 Por padrão, um projeto de compilação permite que o **\/Gm** a opção de compilador \(compilações incrementais\) para compilações de depuração e desabilita\-versão de compilações. Portanto, o **\/MP** opção de compilador é desabilitada automaticamente em compilações de depuração porque está em conflito com o padrão **\/Gm** opção de compilador.  
  
## Consulte também  
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md)   
 [Referência de linha de comando](../Topic/MSBuild%20Command-Line%20Reference.md)