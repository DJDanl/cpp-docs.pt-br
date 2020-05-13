---
title: Gerenciando uma biblioteca
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLibrarianTool.OVERWRITEAllDefaultLibraries
- VC.Project.VCLibrarianTool.AdditionalDependencies
- VC.Project.VCLibrarianTool.RemoveObjects
- VC.Project.VCLibrarianTool.LibraryPaths
- VC.Project.VCLibrarianTool.OutputFile
- VC.Project.VCLibrarianTool.OVERWRITEDefaultLibraryNames
- VC.Project.VCLibrarianTool.AdditionalLibraryDirectories
- VC.Project.VCLibrarianTool.ListContentsFile
- VC.Project.VCLibrarianTool.ListContents
- VC.Project.VCLibrarianTool.SubSystemVersion
- VC.Project.VCLibrarianTool.OVERWRITEDefaultLibraryName
- VC.Project.VCLibrarianTool.SubSystem
helpviewer_keywords:
- /LIBPATH library manager option
- OUT library manager option
- CONVERT library manager option
- LIBPATH library manager option
- /LIST library manager option
- object files, building and modifying
- -LINK50COMPAT library manager option
- REMOVE library manager option
- SUBSYSTEM library manager option
- /LINK50COMPAT library manager option
- /OUT library manager option
- LIB [C++], managing COFF libraries
- -CONVERT library manager option
- LINK50COMPAT library manager option
- -OUT library manager option
- -REMOVE library manager option
- -LIST library manager option
- /SUBSYSTEM library manager option
- -SUBSYSTEM library manager option
- /REMOVE library manager option
- -LIBPATH library manager option
- object files
- LIST library manager option
- /CONVERT library manager option
ms.assetid: f56a8b85-fbdc-4c09-8d8e-00f0ffe1da53
ms.openlocfilehash: de55059834a0887d487b7be38377af9984512b75
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336401"
---
# <a name="managing-a-library"></a>Gerenciando uma biblioteca

O modo padrão de LIB é construir ou modificar uma biblioteca de objetos COFF. O LIB é executado neste modo quando você não especifica /EXTRACT (para copiar um objeto para um arquivo) ou /DEF (para construir uma biblioteca de importação).

Para construir uma biblioteca a partir de objetos e/ou bibliotecas, use a seguinte sintaxe:

```
LIB [options...] files...
```

Este comando cria uma biblioteca a partir de um ou mais *arquivos*de entrada . Os *arquivos* podem ser arquivos de objeto COFF, arquivos de objeto OMF de 32 bits ou bibliotecas COFF existentes. LIB cria uma biblioteca que contém todos os objetos nos arquivos especificados. Se um arquivo de entrada for um arquivo de objeto OMF de 32 bits, o LIB o converterá em COFF antes de construir a biblioteca. Lib não pode aceitar um objeto OMF de 32 bits que está em uma biblioteca criada pela versão de 16 bits do LIB. Primeiro, você deve usar o LIB de 16 bits para extrair o objeto; então você pode usar o arquivo de objeto extraído como entrada para o LIB de 32 bits.

Por padrão, LIB nomeia o arquivo de saída usando o nome base do primeiro objeto ou arquivo de biblioteca e a extensão .lib. O arquivo de saída é colocado no diretório atual. Se um arquivo já existir com o mesmo nome, o arquivo de saída substituirá o arquivo existente. Para preservar uma biblioteca existente, use a opção /OUT para especificar um nome para o arquivo de saída.

As seguintes opções se aplicam à construção e modificação de uma biblioteca:

**/LIBPATH:** *dir*<br/>
Substitui o caminho da biblioteca de ambiente. Para obter detalhes, consulte a descrição da opção LINK [/LIBPATH.](libpath-additional-libpath.md)

**/list**<br/>
Exibe informações sobre a biblioteca de saída para a saída padrão. A saída pode ser redirecionada para um arquivo. Você pode usar /LIST para determinar o conteúdo de uma biblioteca existente sem modificá-la.

**/NOME:** *nome de arquivo*<br/>
Ao construir uma biblioteca de importação, especifica o nome da DLL para a qual a biblioteca de importação está sendo construída.

**/NODEFAULTLIB**<br/>
Remove uma ou mais bibliotecas padrão da lista de bibliotecas que ele pesquisa ao resolver referências externas. Consulte [/NODEFAULTLIB](nodefaultlib-ignore-libraries.md) para obter mais informações.

**/OUT:** *nome de arquivo*<br/>
Substitui o nome de arquivo de saída padrão. Por padrão, a biblioteca de saída é criada no diretório atual, com o nome base do primeiro arquivo de biblioteca ou objeto na linha de comando e na extensão .lib.

**/REMOVE:** *objeto*<br/>
Omite o *objeto* especificado da biblioteca de saída. O LIB cria uma biblioteca de saída combinando todos os objetos (seja em arquivos de objetos ou bibliotecas) e, em seguida, excluindo quaisquer objetos especificados com /REMOVE.

**/SUBSYSTEM:**{**CONSOLE** &#124; **EFI_APPLICATION EFI_APPLICATION** &#124; **EFI_BOOT_SERVICE_DRIVER &#124;** &#124; &#124; EFI_ROM &#124; **&#124;** **EFI_RUNTIME_DRIVER &#124;** &#124; &#124; &#124; &#124; **&#124;** **&#124; WINDOWS** &#124; **WINDOWSCE**}[####]] **NATIVE**<br/>
Informa ao sistema operacional como executar um programa criado vinculando-se à biblioteca de saída. Para obter mais informações, consulte a descrição da opção [LINK/SUBSYSTEM.](subsystem-specify-subsystem.md)

As opções LIB especificadas na linha de comando não são sensíveis ao caso.

Você pode usar o LIB para executar as seguintes tarefas de gerenciamento de bibliotecas:

- Para adicionar objetos a uma biblioteca, especifique o nome do arquivo para a biblioteca existente e os nomes dos arquivos para os novos objetos.

- Para combinar bibliotecas, especifique os nomes dos arquivos da biblioteca. Você pode adicionar objetos e combinar bibliotecas com um único comando LIB.

- Para substituir um membro da biblioteca por um novo objeto, especifique a biblioteca que contém o objeto membro a ser substituído e o nome do arquivo para o novo objeto (ou a biblioteca que o contém). Quando um objeto com o mesmo nome existe em mais de um arquivo de entrada, LIB coloca o último objeto especificado no comando LIB na biblioteca de saída. Ao substituir um membro da biblioteca, certifique-se de especificar o novo objeto ou biblioteca após a biblioteca que contém o objeto antigo.

- Para excluir um membro de uma biblioteca, use a opção /REMOVE. O LIB processa todas as especificações de /REMOVE depois de combinar todos os objetos de entrada, independentemente da ordem de linha de comando.

> [!NOTE]
> Você não pode excluir um membro e extraí-lo para um arquivo na mesma etapa. Primeiro, extrair o objeto membro usando /EXTRACT e executar LIB novamente usando /REMOVE. Esse comportamento difere do lib de 16 bits (para bibliotecas OMF) fornecido em outros produtos da Microsoft.

## <a name="see-also"></a>Confira também

[Referência LIB](lib-reference.md)
