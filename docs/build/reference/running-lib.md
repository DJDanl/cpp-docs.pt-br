---
title: Executando LIB
description: Descreve as opções de linha de comando que você pode usar com o lib. exe.
ms.date: 09/25/2019
f1_keywords:
- VC.Project.VCLibrarianTool.TargetMachine
- Lib
- VC.Project.VCLibrarianTool.PrintProgress
- VC.Project.VCLibrarianTool.SuppressStartupBanner
helpviewer_keywords:
- -MACHINE target platform option
- command files, LIB
- MACHINE target platform option
- colon command files
- VERBOSE library manager option
- /NOLOGO library manager option
- dash option specifier
- /MACHINE target platform option
- forward slash option specifier
- -NOLOGO library manager option
- LIB [C++], running LIB
- -VERBOSE library manager option
- /VERBOSE library manager option
- command files
- NOLOGO library manager option
- slash (/)
- semicolon, command files
- / command files
ms.assetid: d54f5c81-7147-4b2c-a8db-68ce6eb1eabd
ms.openlocfilehash: 0d65c8d8b3b0cd28c7cccda25bfd9512321172f9
ms.sourcegitcommit: 1e6386be9084f70def7b3b8b4bab319a117102b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/30/2019
ms.locfileid: "71685542"
---
# <a name="running-lib"></a>Executando LIB

Várias opções de linha de comando podem ser usadas para controlar a LIB.

## <a name="lib-command-line"></a>Linha de comando LIB

Para executar a LIB, digite o comando `lib` seguido pelas opções e nomes de arquivo para a tarefa que você está usando LIB para executar. A LIB também aceita a entrada de linha de comando em arquivos de comando, que são descritos na seção a seguir. LIB não usa uma variável de ambiente.

## <a name="lib-command-files"></a>Arquivos de comando LIB

Você pode passar argumentos de linha de comando para LIB em um arquivo de comando usando a seguinte sintaxe:

> **LIB \@** <em>arquivo de comando</em>

O arquivo *de comando de* arquivo é um arquivo de texto. Não são permitidos espaços ou guias entre o sinal de arroba ( **\@** ) e o nome do arquivo. O nome do *arquivo de comando* não tem extensão padrão; Você deve especificar o nome completo do arquivo, incluindo qualquer extensão. Caracteres curinga não podem ser usados. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo.

No arquivo de comando, os argumentos podem ser separados por espaços ou tabulações, como podem ser na linha de comando. Os argumentos também podem ser separados por caracteres de nova linha. Use um ponto-e-vírgula ( **;** ) para marcar um comentário. LIB ignora todo o texto do ponto e vírgula para o final da linha.

Você pode especificar todos ou parte da linha de comando em um arquivo de comando, e pode usar mais de um arquivo de comando em um comando LIB. A LIB aceita a entrada do arquivo de comando como se fosse especificada nesse local na linha de comando. Os arquivos de comando não podem ser aninhados. LIB ecoa o conteúdo dos arquivos de comando, a menos que a opção **/nologo** seja usada.

## <a name="using-lib-options"></a>Usando opções de LIB

Uma opção consiste em um especificador de opção, que é um traço ( **-** ) ou uma barra ( **/** ), seguido pelo nome da opção. Nomes de opção não podem ser abreviados. Algumas opções usam um argumento, especificado após dois-pontos ( **:** ). Não são permitidos espaços ou guias dentro de uma especificação de opção. Use um ou mais espaços ou guias para separar as especificações de opção na linha de comando. Nomes de opção e seus argumentos de nome de arquivo ou palavra-chave não diferenciam maiúsculas de minúsculas, mas identificadores usados como argumentos diferenciam maiúsculas de minúsculas. A LIB processa as opções na ordem especificada na linha de comando e nos arquivos de comando. Se uma opção for repetida com argumentos diferentes, o último a ser processado terá precedência.

As opções a seguir se aplicam a todos os modos de LIB:

> **/ERRORREPORT** \[**NENHUM** &#124; **PROMPT** &#124; **FILA** &#124; **ENVIAR**]

Se o lib. exe falhar em tempo de execução, você poderá usar **/errorreport** para enviar informações à Microsoft sobre esses erros internos.

Para obter mais informações sobre **/errorreport**, consulte [/errorReport (relatar erros de compilador interno)](errorreport-report-internal-compiler-errors.md).

> **/LINKREPRO:** _diretório-caminho_ \
> **/LINKREPROTARGET:** _nome de arquivo_

Para ajudar a Microsoft a diagnosticar falhas de lib. exe e erros internos, você pode usar a opção [/LINKREPRO](linkrepro.md) . Ele gera uma *reprodução de link*, um conjunto de artefatos de compilação que permite à Microsoft reproduzir um problema que ocorre durante operações de biblioteca. A opção [/LINKREPROTARGET](linkreprotarget.md) pode ser usada com a opção **/LINKREPRO** . Ele gera apenas artefatos de reprodução de link quando o lib. exe produz o arquivo especificado. Para obter mais informações, consulte [como relatar um problema com o conjunto C++ de ferramentas da Microsoft](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md).

> **/LTCG**

"LTCG" significa *geração de código de tempo de vinculação*. Esse recurso requer a cooperação entre o compilador ([CL. exe](compiler-options.md)), a lib e o vinculador ([link](linker-options.md)) para otimizar o código além do que qualquer componente pode fazer por si só.

Para LIB, a opção **/LTCG** especifica que as entradas de CL. exe incluem arquivos de objeto que foram gerados usando a opção de compilador [/GL](gl-whole-program-optimization.md) . Se LIB encontrar essas entradas e **/LTCG** não for especificado, ela será reiniciada com/LTCG habilitado após a exibição de uma mensagem informativa. Em outras palavras, não é necessário definir explicitamente essa opção, mas acelera o desempenho da compilação para fazer isso, pois a LIB não precisa ser reiniciada.

No processo de compilação, a saída de LIB é enviada para o LINK. O LINK tem sua própria opção **/LTCG** separada. Ele é usado para executar várias otimizações, incluindo otimização de programa inteiro e instrumentação de PGO (otimização guiada por perfil). Para obter mais informações sobre a opção de LINK, consulte [/LTCG](ltcg-link-time-code-generation.md).

> **/MACHINE**

Especifica a plataforma de destino para o programa. Normalmente, você não precisa especificar **/Machine**. LIB infere o tipo de computador dos arquivos. obj. No entanto, em algumas circunstâncias, a LIB não pode determinar o tipo de computador e emite uma mensagem de erro. Se esse erro ocorrer, especifique **/Machine**. No modo **/Extract** , essa opção é somente para verificação. Use `lib /?` na linha de comando para ver os tipos de computador disponíveis.

> **/NOLOGO**

Suprime a exibição da mensagem de direitos autorais de LIB e o número de versão e impede o eco de arquivos de comando.

> **/VERBOSE**

Exibe detalhes sobre o progresso da sessão, incluindo nomes dos arquivos. obj que estão sendo adicionados. A informação é enviada para uma saída padrão e pode ser redirecionada para um arquivo.

> **/WX**[ **:NO**]

Tratar avisos como erros. Para obter mais informações, consulte [/WX (Tratar Avisos do Vinculador como Erros)](wx-treat-linker-warnings-as-errors.md).

Outras opções se aplicam somente a modos específicos de LIB. Essas opções são discutidas nas seções que descrevem cada modo.

## <a name="see-also"></a>Consulte também

[Referência de LIB](lib-reference.md)
