---
title: Executando LIB
description: Descreve as opções de linha de comando que você pode usar com o lib. exe.
ms.date: 02/09/2020
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
ms.openlocfilehash: 0688365fa83edcacd901321fead48c9c98df2faf
ms.sourcegitcommit: 8414cd91297dea88c480e208c7b5301db9972f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2020
ms.locfileid: "77257553"
---
# <a name="running-lib"></a>Executando LIB

Várias opções de linha de comando podem ser usadas para controlar a LIB.

## <a name="lib-command-line"></a>Linha de comando LIB

Para executar a LIB, digite o comando `lib`, seguido pelas opções e nomes de arquivo para a tarefa na qual você está usando a LIB. A LIB também aceita a entrada de linha de comando em arquivos de comando, que são descritos na seção a seguir. LIB não usa uma variável de ambiente.

## <a name="lib-command-files"></a>Arquivos de comando LIB

Você pode passar argumentos de linha de comando para LIB em um arquivo de comando usando a seguinte sintaxe:

> **LIB \@** <em>arquivo de comando</em>

O arquivo *de comando de* arquivo é um arquivo de texto. Não são permitidos espaços ou guias entre o sinal de arroba ( **\@** ) e o nome do arquivo. O nome do *arquivo de comando* não tem extensão padrão. Especifique o nome completo do arquivo, incluindo qualquer extensão. Caracteres curinga não podem ser usados. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo.

No arquivo de comando, os argumentos podem ser separados por espaços ou tabulações, como podem ser na linha de comando. Os argumentos também podem ser separados por caracteres de nova linha. Use um ponto-e-vírgula ( **;** ) para marcar um comentário. LIB ignora todo o texto do ponto e vírgula para o final da linha.

Você pode especificar toda ou parte da linha de comando em um arquivo de comando, e você pode usar mais de um arquivo de comando em um comando LIB. A LIB aceita a entrada do arquivo de comando como se fosse especificada nesse local na linha de comando. Os arquivos de comando não podem ser aninhados. LIB ecoa o conteúdo dos arquivos de comando, a menos que a opção **/nologo** seja usada.

## <a name="using-lib-options"></a>Usando opções de LIB

Uma opção consiste em um especificador de opção, que é um traço ( **-** ) ou uma barra ( **/** ), seguido pelo nome da opção. Nomes de opção não podem ser abreviados. Algumas opções usam um argumento, especificado após dois-pontos ( **:** ). Não são permitidos espaços ou guias dentro de uma especificação de opção. Use um ou mais espaços ou guias para separar as especificações de opção na linha de comando. Nomes de opção e seus argumentos de nome de arquivo ou palavra-chave não diferenciam maiúsculas de minúsculas, mas identificadores usados como argumentos diferenciam maiúsculas de minúsculas. A LIB processa as opções na ordem especificada na linha de comando e nos arquivos de comando. Se uma opção for repetida com argumentos diferentes, o último a ser processado terá precedência.

As opções a seguir se aplicam a todos os modos de LIB:

> **/Errorreport** \[**None** &#124; &#124; **Enviar** **fila** de **prompts** &#124; ]

A opção/ERRORREPORT é preterida. A partir do Windows Vista, o relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) .

> **/LINKREPRO:** _diretório-caminho_ \
> **/LINKREPROTARGET:** _nome de arquivo_

Para ajudar a Microsoft a diagnosticar falhas de lib. exe e erros internos, você pode usar a opção [/LINKREPRO](linkrepro.md) . Essa opção gera uma *reprodução de link*, um conjunto de artefatos de compilação que permite à Microsoft reproduzir um problema que ocorre durante operações de biblioteca. A opção [/LINKREPROTARGET](linkreprotarget.md) pode ser usada com a opção **/LINKREPRO** . Ele gera apenas artefatos de reprodução de link quando o lib. exe produz o arquivo especificado. Para obter mais informações, consulte [como relatar um problema com o conjunto C++ de ferramentas da Microsoft](../../overview/how-to-report-a-problem-with-the-visual-cpp-toolset.md).

> **/LTCG**

"LTCG" significa *geração de código de tempo de vinculação*. Esse recurso requer a cooperação entre o compilador ([CL. exe](compiler-options.md)), a lib e o vinculador ([link](linker-options.md)). Juntos, eles podem otimizar o código além do que qualquer componente pode fazer por si só.

A opção **/LTCG** para lib especifica que as entradas de CL. exe incluem arquivos de objeto gerados usando a opção de compilador [/GL](gl-whole-program-optimization.md) . Se LIB encontrar essas entradas e **/LTCG** não for especificado, ele será reiniciado com/LTCG habilitado depois de exibir uma mensagem informativa. Em outras palavras, não é necessário definir essa opção explicitamente, mas acelera o desempenho do Build. Isso porque a LIB não precisa ser reiniciada.

No processo de compilação, a saída de LIB é enviada para o LINK. O LINK tem sua própria opção **/LTCG** separada. Ele é usado para executar várias otimizações, incluindo otimização de programa inteiro e instrumentação de PGO (otimização guiada por perfil). Para obter mais informações sobre a opção de LINK, consulte [/LTCG](ltcg-link-time-code-generation.md).

> **/MACHINE**

Especifica a plataforma de destino para o programa. Normalmente, você não precisa especificar **/Machine**. LIB infere o tipo de computador dos arquivos. obj. No entanto, em algumas circunstâncias, a LIB não pode determinar o tipo de computador e emite uma mensagem de erro. Se esse erro ocorrer, especifique **/Machine**. No modo **/Extract** , essa opção é somente para verificação. Use `lib /?` na linha de comando para ver os tipos de máquina disponíveis.

> **/NOLOGO**

Suprime a exibição da mensagem de direitos autorais de LIB e o número de versão e impede o eco de arquivos de comando.

> **/VERBOSE**

Exibe detalhes sobre o progresso da sessão, incluindo nomes dos arquivos. obj que estão sendo adicionados. A informação é enviada para uma saída padrão e pode ser redirecionada para um arquivo.

> **/WX**[ **: no**]

Tratar avisos como erros. Para obter mais informações, consulte [/WX (Tratar Avisos do Vinculador como Erros)](wx-treat-linker-warnings-as-errors.md).

Outras opções se aplicam somente a modos específicos de LIB. Essas opções são discutidas nas seções que descrevem cada modo.

## <a name="see-also"></a>Confira também

[Referência de LIB](lib-reference.md)
