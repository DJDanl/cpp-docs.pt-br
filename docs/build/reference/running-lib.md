---
title: Executando LIB
ms.date: 09/28/2018
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
ms.openlocfilehash: e95427b571cd14ad39a7ba4f368b90e806f13862
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62318687"
---
# <a name="running-lib"></a>Executando LIB

Várias opções de linha de comando podem ser usado para controle de LIB.

## <a name="lib-command-line"></a>Linha de comando LIB

Para executar LIB, digite o comando `lib` seguido as opções e nomes de arquivo para a tarefa estiver usando LIB para executar. LIB também aceita a entrada de linha de comando em arquivos de comando, que são descritos na seção a seguir. Não usa uma variável de ambiente LIB.

> [!NOTE]
> Se você está acostumado a LINK32.exe e fornecida com o Microsoft Win32 Software Development Kit para Windows NT, você pode ter sido usando o comando das ferramentas de LIB32.exe `link32 -lib` ou o comando `lib32` para bibliotecas de gerenciamento e criação Importe as bibliotecas. Certifique-se de alterar seus arquivos em lote e de makefiles para usar o `lib` de comando em vez disso.

## <a name="lib-command-files"></a>Arquivos de comando LIB

Você pode passar argumentos de linha de comando para LIB em um arquivo de comando usando a seguinte sintaxe:

> **LIB \@**  <em>commandfile</em>

O arquivo *commandfile* é um arquivo de texto. Nenhum espaço ou tabulação é permitida entre o sinal de arroba (**\@**) e o nome do arquivo. Não há nenhuma extensão padrão; Você deve especificar o nome de arquivo completo, incluindo qualquer extensão. Caracteres curinga não pode ser usada. Você pode especificar um caminho absoluto ou relativo com o nome do arquivo.

No arquivo de comando, os argumentos podem ser separados por espaços ou tabulações, como eles podem na linha de comando. Eles também podem ser separados por caracteres de nova linha. Use um ponto e vírgula (**;**) para marcar um comentário. LIB ignora todo o texto da vírgula ao final da linha.

Você pode especificar todos ou parte da linha de comando em um arquivo de comando, e você pode usar mais de um arquivo de comando em um comando LIB. LIB aceita a entrada do arquivo de comando, como se ele foi especificado no local na linha de comando. Arquivos de comando não podem ser aninhados. LIB exibe o conteúdo dos arquivos de comando, a menos que a opção /NOLOGO é usada.

## <a name="using-lib-options"></a>Usando as opções de LIB

Uma opção consiste em um especificador de opção, qualquer um traço (**-**) ou uma barra invertida (**/**), seguido pelo nome da opção. Nomes de opção não podem ser abreviados. Algumas opções têm um argumento, especificado após dois-pontos (**:**). Não há espaços ou tabulações são permitidas em uma especificação de opção. Use um ou mais espaços ou tabulações para separar as especificações de opção na linha de comando. Nomes de opção e seus argumentos de nome de arquivo ou a palavra-chave não diferenciam maiusculas de minúsculas, mas identificadores usados como argumentos diferenciam maiusculas de minúsculas. LIB processa as opções na ordem especificada na linha de comando e nos arquivos de comando. Se uma opção é repetida com argumentos diferentes, o último a ser processada terá precedência.

As opções a seguir se aplicam a todos os modos de LIB:

> **/ERRORREPORT** [**NONE** &#124; **PROMPT** &#124; **QUEUE** &#124; **SEND**]

Se lib.exe falhar em tempo de execução, você pode usar **/ERRORREPORT** para enviar à Microsoft informações sobre esses erros internos.

Para obter mais informações sobre **/ERRORREPORT**, consulte [/errorReport (relatório de erros do compilador interno)](errorreport-report-internal-compiler-errors.md).

> **/LTCG**

"LTCG" signifca *geração de código para link-time*. Este recurso requer a cooperação entre o compilador ([cl.exe](compiler-options.md)), LIB e o vinculador ([LINK](linker-options.md)) para otimizar o código além do que qualquer componente pode fazer por si só.

Para LIB, o **/LTCG** opção especifica que as entradas de cl.exe incluem arquivos de objeto que foram gerados usando o [/GL](gl-whole-program-optimization.md) opção de compilador. Se o LIB encontrar essas entradas e **/LTCG** não for especificado, ele será reiniciado com /LTCG habilitado depois de exibir uma mensagem informativa. Em outras palavras, não é necessário definir explicitamente essa opção, mas ele acelera o desempenho de compilação para fazer isso porque não tem LIB para reiniciá-lo.

No processo de compilação, a saída de LIB é enviada ao LINK. LINK tem seu próprio separado **/LTCG** opção que é usada para executar várias otimizações, incluindo a otimização de programa inteiro e a instrumentação de Otimização Guiada por perfil (PGO). Para obter mais informações sobre a opção de LINK, consulte [/LTCG](ltcg-link-time-code-generation.md).

> **/MACHINE**

Especifica a plataforma de destino para o programa. Normalmente, você não precisa especificar /MACHINE. LIB infere o tipo de máquina de arquivos. obj. No entanto, em algumas circunstâncias, LIB não é possível determinar o tipo de computador e emite uma mensagem de erro. Se ocorrer um erro, especifique /MACHINE. No modo /EXTRACT, essa opção é para apenas da verificação. Use `lib /?` na linha de comando para ver os tipos de máquina disponíveis.

> **/NOLOGO**

Suprime a exibição do que o número de versão e mensagem de direitos autorais do LIB e impede a repetição de arquivos de comando.

> **/VERBOSE**

Exibe detalhes sobre o progresso da sessão, incluindo nomes de arquivos. obj que está sendo adicionados. A informação é enviada para uma saída padrão e pode ser redirecionada para um arquivo.

> **/WX**[**:NO**]

Trate avisos como erros. Ver [/WX (tratar avisos do vinculador como erros)](wx-treat-linker-warnings-as-errors.md) para obter mais informações.

Outras opções se aplicam somente a modos específicos de LIB. Essas opções são discutidas nas seções que descrevem cada modo.

## <a name="see-also"></a>Consulte também

[Referência de LIB](lib-reference.md)
