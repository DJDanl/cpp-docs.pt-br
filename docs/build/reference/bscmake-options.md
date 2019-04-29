---
title: Opções de BSCMAKE
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCBscMakeTool.OutputFile
- VC.Project.VCBscMakeTool.SuppressStartupBanner
- VC.Project.VCBscMakeTool.PreserveSBR
helpviewer_keywords:
- /v BSCMAKE option
- Iu BSCMAKE option
- browse information files (.bsc), content
- /Er BSCMAKE option
- NOLOGO BSCMAKE option
- /s BSCMAKE option
- /Ei BSCMAKE option
- /o BSCMAKE option
- /NOLOGO BSCMAKE option
- /Iu BSCMAKE option
- s BSCMAKE option (/s)
- /Em BSCMAKE option
- Em BSCMAKE option
- Es BSCMAKE option
- files [C++], BSCMAKE
- Er BSCMAKE option
- BSCMAKE, options for controlling files
- controlling BSCMAKE options
- El BSCMAKE option
- /El BSCMAKE option
- /Es BSCMAKE option
- Ei BSCMAKE option
ms.assetid: fa2f1e06-c684-41cf-80dd-6a554835ebd2
ms.openlocfilehash: b1d62e8d122cb4f08feef60d6936359b3e246749
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62272865"
---
# <a name="bscmake-options"></a>Opções de BSCMAKE

> [!WARNING]
> Embora BSCMAKE ainda está instalado com o Visual Studio, ele não é mais usado pelo IDE. Desde o Visual Studio 2008, as informações de símbolo e procura são armazenadas automaticamente em um arquivo. sdf de SQL Server na pasta da solução.

Esta seção descreve as opções disponíveis para controlar o BSCMAKE. Várias opções de controlam o conteúdo do arquivo de informações de procura, excluindo ou incluindo determinadas informações. As opções de exclusão podem permitir BSCMAKE seja executado mais rapidamente e podem resultar em um arquivo. bsc menor. Nomes de opção diferenciam maiusculas de minúsculas (exceto para **/Help** e **/NOLOGO**).

Somente **/NOLOGO** e **/o** estão disponíveis no ambiente de desenvolvimento do Visual Studio.  Ver [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md) para informações sobre como acessar as páginas de propriedades de um projeto.

**/Ei (** *filename*... **)**<br/>
Exclui o conteúdo dos arquivos de inclusão especificado do arquivo de informações de procura. Para especificar vários arquivos, separe os nomes com um espaço e coloque a lista entre parênteses. Parênteses não são necessários se você especificar apenas um *filename*. Use **/Ei** juntamente com o **/Es** opção para excluir arquivos que não são excluídos pelo **/Es**.

**/El**<br/>
Exclui os símbolos locais. O padrão é incluir símbolos locais. Para obter mais informações sobre símbolos locais, consulte [criando um arquivo. SBR](creating-an-dot-sbr-file.md).

**/Em**<br/>
Exclui os símbolos no corpo de macros. Use **/Em** para incluir apenas os nomes de macros no arquivo de informações de procura. O padrão é incluir os nomes de macro e o resultado de expansões de macro.

**/ER (** *símbolo*... **)**<br/>
Exclui os símbolos especificados do arquivo de informações de procura. Para especificar vários nomes de símbolo, separe os nomes com um espaço e coloque a lista entre parênteses. Parênteses não são necessários se você especificar apenas um *símbolo*.

**/Es**<br/>
Exclui o arquivo de informações de procura todos os arquivos de inclusão especificado com um caminho absoluto ou localizado em um caminho absoluto especificado na variável de ambiente INCLUDE. (Normalmente, esses são o sistema incluem arquivos, que contêm muitas informações que talvez não seja necessário em seu arquivo de informações de procura.) Essa opção não exclui arquivos especificados sem um caminho ou com caminhos relativos ou arquivos encontrados em um caminho relativo em inclusão. Você pode usar o **/Ei** junto com a opção **/Es** para excluir arquivos que **/Es** não excluir. Se você deseja excluir apenas alguns dos arquivos que **/Es** exclui, use **/Ei** em vez de **/Es** e listar os arquivos que você deseja excluir.

**/errorreport:**[**none** &#124; **prompt** &#124; **queue** &#124; **send**]<br/>
Permite que você enviar à Microsoft informações sobre erros internos no bscmake.exe.

Para obter mais informações sobre **/errorreport**, consulte [/errorReport (relatório de erros do compilador interno)](errorreport-report-internal-compiler-errors.md).

**/HELP**<br/>
Exibe um resumo da sintaxe de linha de comando BSCMAKE.

**/Iu**<br/>
Inclui símbolos não referenciados. Por padrão, o BSCMAKE não registra quaisquer símbolos que são definidos, mas não referenciados. Se tiver sido compactado e um arquivo. SBR, essa opção não terá efeito para esse arquivo de entrada porque o compilador já removeu os símbolos não referenciados.

**/n**<br/>
Ele forçará um build. Use **/n** para forçar uma compilação completa do arquivo de informações de procura se existe ou não um arquivo. bsc e para impedir que arquivos. SBR sejam truncados. Ver [como BSCMAKE compila um arquivo. bsc](how-bscmake-builds-a-dot-bsc-file.md).

**/NOLOGO**<br/>
Suprime a mensagem de direitos autorais de BSCMAKE.

**/o** *filename*<br/>
Especifica um nome para o arquivo de informações de procura. Por padrão, BSCMAKE fornece o arquivo de informações de procura o nome base do primeiro arquivo. SBR e uma extensão. bsc.

**/S (** *filename*...**)**<br/>
Informa ao BSCMAKE para processar o arquivo de inclusão especificado na primeira vez que ela for encontrada e excluí-lo caso contrário. Use esta opção para economizar tempo de processamento quando um arquivo (como um cabeçalho, ou. h, o arquivo para um. c ou o arquivo de origem. cpp) está incluído em vários arquivos de origem, mas não é alterado por diretivas de pré-processamento de cada vez. Você talvez queira usar esta opção se um arquivo for alterado de maneiras que não são importantes para o arquivo de informações de procura que você está criando. Para especificar vários arquivos, separe os nomes com um espaço e coloque a lista entre parênteses. Parênteses não são necessários se você especificar apenas um *filename*. Se você quiser excluir o arquivo sempre que ele é incluído, use o **/Ei** ou **/Es** opção.

**/v**<br/>
Fornece a saída detalhada, que inclui o nome de cada arquivo. SBR que está sendo processado e obter informações sobre o BSCMAKE completa executar.

**/?**<br/>
Exibe um resumo da sintaxe de linha de comando BSCMAKE.

A seguinte linha de comando informa BSCMAKE fazer uma compilação completa de MAIN.bsc dos três arquivos. SBR. Ele também informa BSCMAKE para excluir instâncias duplicadas de TOOLBOX.h:

```
BSCMAKE /n /S toolbox.h /o main.bsc file1.sbr file2.sbr file3.sbr
```

## <a name="see-also"></a>Consulte também

[Referência de BSCMAKE](bscmake-reference.md)
