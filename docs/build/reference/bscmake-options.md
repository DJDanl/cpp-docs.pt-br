---
title: Opções de BSCMAKE
description: Referência às opções de linha de comando do utilitário do Microsoft BSCMAKE.
ms.date: 02/09/2020
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
ms.openlocfilehash: f0fd0e01d3325267ac175435aab65b5d0a9d47ea
ms.sourcegitcommit: 8414cd91297dea88c480e208c7b5301db9972f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2020
ms.locfileid: "77257787"
---
# <a name="bscmake-options"></a>Opções de BSCMAKE

> [!WARNING]
> Embora o BSCMAKE ainda esteja instalado com o Visual Studio, ele não é mais usado pelo IDE. Como o Visual Studio 2008, as informações de procura e símbolo são armazenadas automaticamente em um arquivo de SQL Server *`.sdf`* na pasta da solução.

Esta seção descreve as opções disponíveis para controlar o BSCMAKE. Várias opções controlam o conteúdo do arquivo de informações de procura, excluindo ou incluindo determinadas informações. As opções de exclusão podem permitir que o BSCMAKE seja executado mais rapidamente e pode resultar em um arquivo de *`.bsc`* menor. Os nomes de opção diferenciam maiúsculas de minúsculas (exceto para **/Help** e **/nologo**).

Somente **/nologo** e **/o** estão disponíveis no ambiente de desenvolvimento do Visual Studio.  Consulte [definir C++ compilador e propriedades de compilação no Visual Studio](../working-with-project-properties.md) para obter informações sobre como acessar as páginas de propriedades de um projeto.

**/Ei (nome de**_arquivo_... **)** \
Exclui o conteúdo dos arquivos de inclusão especificados do arquivo de informações de procura. Para especificar vários arquivos, separe os nomes com um espaço e coloque a lista entre parênteses. Os parênteses não serão necessários se você especificar apenas um *nome de arquivo*. Use **/Ei** juntamente com a opção **/es** para excluir arquivos não excluídos pelo **/es**.

\ **/El**
Exclui símbolos locais. O padrão é incluir símbolos locais. Para obter mais informações sobre símbolos locais, consulte [criando um arquivo. sbr](creating-an-dot-sbr-file.md).

\ **/em**
Exclui símbolos no corpo de macros. Use **/em** para incluir somente os nomes de macros no arquivo de informações de procura. O padrão é incluir os nomes de macro e o resultado das expansões de macro.

**/Er (** _símbolo_... **)** \
Exclui os símbolos especificados do arquivo de informações de procura. Para especificar vários nomes de símbolo, separe os nomes com um espaço e coloque a lista entre parênteses. Os parênteses são desnecessários se você especificar apenas um *símbolo*.

\ **/es**
Exclui todos os arquivos de inclusão especificados com um caminho absoluto ou encontrados em um caminho absoluto especificado na variável de ambiente INCLUDE. (Normalmente, esses arquivos são os arquivos de inclusão do sistema, que contêm muitas informações que talvez não sejam necessárias no arquivo de informações de procura.) Essa opção não exclui arquivos especificados sem um caminho, ou com caminhos relativos, ou arquivos encontrados em um caminho relativo em INCLUDE. Você pode usar a opção **/Ei** junto com **/es** para excluir arquivos que **/es** não exclui. Se você quiser excluir apenas alguns dos arquivos, use **/Ei** em vez de **/es**e liste os arquivos que deseja excluir.

**/errorreport:** [**None** &#124; **prompt** &#124; **Queue** &#124; **Send**] \
Essa opção foi preterida. A partir do Windows Vista, o relatório de erros é controlado pelas configurações [do relatório de erros do Windows (WER)](/windows/win32/wer/windows-error-reporting) .

**/Help**\
Exibe um resumo da sintaxe da linha de comando BSCMAKE.

\ **/IU**
Inclui símbolos não referenciados. Por padrão, BSCMAKE não registra nenhum símbolo definido, mas não referenciado. Se um arquivo de *`.sbr`* tiver sido empacotado, essa opção não terá nenhum efeito para esse arquivo de entrada porque o compilador já removeu os símbolos não referenciados.

**/n**\
Força uma compilação não incremental. Use **/n** para forçar uma compilação completa do arquivo de informações de procura se um arquivo de *`.bsc`* existe ou não e para impedir que *`.sbr`* arquivos sejam truncados. Veja [como o BSCMAKE cria um arquivo. BSC](how-bscmake-builds-a-dot-bsc-file.md).

**/Nologo**\
Suprime a mensagem de direitos autorais BSCMAKE.

**/o** *nome do arquivo*\
Especifica um nome para o arquivo de informações de procura. Por padrão, BSCMAKE fornece ao arquivo de informações de procura o nome base do primeiro arquivo *`.sbr`* e uma extensão *`.bsc`* .

**/S (nome do**_arquivo_... **)** \
Informa ao BSCMAKE para processar o arquivo de inclusão especificado na primeira vez que ele for encontrado e para excluí-lo de outra forma. Use esta opção para economizar tempo de processamento quando um arquivo (como um cabeçalho, ou *`.h`* , arquivo para um arquivo de origem *`.c`* ou *`.cpp`* ) estiver incluído em vários arquivos de origem, mas não for alterado por diretivas de pré-processamento a cada vez. Use esta opção se um arquivo for alterado de maneiras não importantes para o arquivo de informações de procura que você está criando. Para especificar vários arquivos, separe os nomes com um espaço e coloque a lista entre parênteses. Os parênteses não serão necessários se você especificar apenas um *nome de arquivo*. Se você quiser excluir o arquivo toda vez que ele for incluído, use a opção **/Ei** ou **/es** .

**/v**\
Fornece saída detalhada, que inclui o nome de cada arquivo de *`.sbr`* que está sendo processado e informações sobre a execução BSCMAKE completa.

**/?** \
Exibe um breve resumo da sintaxe de linha de comando BSCMAKE.

A linha de comando a seguir diz ao BSCMAKE para fazer uma compilação completa do MAIN. bsc de três arquivos de *`.sbr`* . Ele também diz ao BSCMAKE para excluir instâncias duplicadas da TOOLBOX. h:

```cmd
BSCMAKE /n /S toolbox.h /o main.bsc file1.sbr file2.sbr file3.sbr
```

## <a name="see-also"></a>Confira também

[Referência de BSCMAKE](bscmake-reference.md)
