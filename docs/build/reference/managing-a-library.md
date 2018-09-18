---
title: Gerenciando uma biblioteca | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dd6fff812d200e16b82994f9f9bbe598aface547
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713144"
---
# <a name="managing-a-library"></a>Gerenciando uma biblioteca

É o modo padrão para LIB criar ou modificar uma biblioteca de objetos COFF. LIB é executado nesse modo, quando você não especificar /EXTRACT (para copiar um objeto para um arquivo) ou /DEF (para compilar uma biblioteca de importação).

Para compilar uma biblioteca de objetos e/ou bibliotecas, use a seguinte sintaxe:

```
LIB [options...] files...
```

Este comando cria uma biblioteca de entrada de um ou mais *arquivos*. O *arquivos* podem ser arquivos de objeto COFF, arquivos de objeto OMF de 32 bits ou as bibliotecas COFF existentes. LIB cria uma biblioteca que contém todos os objetos nos arquivos especificados. Se um arquivo de entrada é um arquivo de objeto OMF de 32 bits, LIB converte para COFF antes de compilar a biblioteca. LIB não pode aceitar um objeto OMF de 32 bits que está em uma biblioteca criada pela versão de 16 bits de LIB. Primeiro você deve usar a biblioteca de 16 bits para extrair o objeto; em seguida, você pode usar o arquivo extraído do objeto como entrada para a biblioteca de 32 bits.

Por padrão, LIB nomeia o arquivo de saída usando o nome base do primeiro arquivo de biblioteca ou objeto e a extensão. lib. O arquivo de saída é colocado no diretório atual. Se já existir um arquivo com o mesmo nome, o arquivo de saída substitui o arquivo existente. Para preservar uma biblioteca existente, use a opção /out sobrescreve para especificar um nome para o arquivo de saída.

As opções a seguir se aplicam a criação e modificação de uma biblioteca:

**/LIBPATH:** *dir*<br/>
Substitui o caminho da biblioteca de ambiente. Para obter detalhes, consulte a descrição do LINK [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção.

**/ LISTA**<br/>
Exibe informações sobre a biblioteca de saída para a saída padrão. A saída pode ser redirecionada para um arquivo. Você pode usar /LIST para determinar o conteúdo de uma biblioteca existente sem modificá-lo.

**/ NOME:** *nome de arquivo*<br/>
Ao criar uma biblioteca de importação, especifica o nome da DLL para o qual a biblioteca de importação está sendo criada.

**/NODEFAULTLIB**<br/>
Remove uma ou mais bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas. Ver [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para obter mais informações.

**/ Entrada saída:** *nome de arquivo*<br/>
Substitui o nome do arquivo de saída padrão. Por padrão, a biblioteca de saída é criada no diretório atual, com o nome base do primeiro arquivo de biblioteca ou objeto na linha de comando e a extensão. lib.

**Ou remover:** *objeto*<br/>
Omite especificado *objeto* da biblioteca de saída. LIB cria uma biblioteca de saída combinando todos os objetos (arquivos de objeto ou bibliotecas) e, em seguida, excluindo qualquer objeto especificado com /remove.

**/SUBSYSTEM:**{**CONSOLE** &AMP;#124; **EFI_APPLICATION** &AMP;#124; **EFI_BOOT_SERVICE_DRIVER** &AMP;#124; **EFI_ROM** &AMP;#124; **EFI_RUNTIME_DRIVER** &AMP;#124; **NATIVO** &AMP;#124; **POSIX** &AMP;#124; **WINDOWS** &AMP;#124; **WINDOWSCE**} [, N º [. # #]]<br/>
Informa o sistema operacional como executar um programa criado por meio da vinculação para a biblioteca de saída. Para obter mais informações, consulte a descrição do LINK [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção.

Opções de LIB especificadas na linha de comando não diferenciam maiusculas de minúsculas.

Você pode usar LIB para executar as seguintes tarefas de gerenciamento de biblioteca:

- Para adicionar objetos a uma biblioteca, especifique o nome do arquivo para a biblioteca existente e os nomes de arquivo para os novos objetos.

- Para combinar as bibliotecas, especifique os nomes de arquivo de biblioteca. Você pode adicionar objetos e combinar bibliotecas com um único comando LIB.

- Para substituir um membro da biblioteca com um novo objeto, especifique a biblioteca que contém o objeto do membro a ser substituído e o nome do arquivo para o novo objeto (ou a biblioteca que o contém). Quando um objeto que tem o mesmo nome existe em mais de um arquivo de entrada, LIB coloca o último objeto especificado no comando LIB para a biblioteca de saída. Quando você substituir um membro da biblioteca, certifique-se de especificar o novo objeto ou uma biblioteca após a biblioteca que contém o objeto antigo.

- Para excluir um membro de uma biblioteca, use a opção /REMOVE. LIB processa quaisquer especificações de /REMOVE após combinar todos os objetos de entrada, independentemente da ordem de linha de comando.

> [!NOTE]
>  Você não pode excluir um membro e extraia-os em um arquivo na mesma etapa. Você deve primeiro extrair o objeto de membro usando /EXTRACT e execute novamente usando /REMOVE de LIB. Esse comportamento é diferente do BIBLIOTECÁRIO de 16 bits (para bibliotecas OMF) fornecido em outros produtos da Microsoft.

## <a name="see-also"></a>Consulte também

[Referência de LIB](../../build/reference/lib-reference.md)