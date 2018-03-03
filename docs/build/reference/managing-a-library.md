---
title: Gerenciando uma biblioteca | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 05ced49a960aea0b32365b80fe76095893f63d5e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="managing-a-library"></a>Gerenciando uma biblioteca
É o modo padrão para LIB criar ou modificar uma biblioteca de objetos COFF. LIB é executado nesse modo, quando você não especificar /EXTRACT (para copiar um objeto para um arquivo) ou /DEF (para criar uma biblioteca de importação).  
  
 Para criar uma biblioteca de objetos e/ou bibliotecas, use a seguinte sintaxe:  
  
```  
LIB [options...] files...  
```  
  
 Este comando cria uma biblioteca de entrada de um ou mais *arquivos*. O *arquivos* podem ser arquivos de objeto COFF, arquivos de objeto OMF de 32 bits ou bibliotecas COFF existentes. LIB cria uma biblioteca que contém todos os objetos em arquivos especificados. Se um arquivo de entrada é um arquivo de objeto OMF 32 bits, LIB converte em COFF antes de criar a biblioteca. LIB não pode aceitar um objeto OMF de 32 bits que está em uma biblioteca criada pela versão de 16 bits de LIB. Primeiro você deve usar a biblioteca de 16 bits para extrair o objeto; em seguida, você pode usar o arquivo de objeto extraído como entrada para a biblioteca de 32 bits.  
  
 Por padrão, LIB nomeia o arquivo de saída usando o nome base do primeiro arquivo de objeto ou de biblioteca e a extensão. lib. O arquivo de saída é colocado no diretório atual. Se já existir um arquivo com o mesmo nome, o arquivo de saída substitui o arquivo existente. Para preservar a uma biblioteca existente, use a opção /OUT para especificar um nome para o arquivo de saída.  
  
 As opções a seguir se aplicam a criação e modificação de uma biblioteca:  
  
 /LIBPATH:`dir`  
 Substitui o caminho da biblioteca de ambiente. Para obter detalhes, consulte a descrição do LINK [/LIBPATH](../../build/reference/libpath-additional-libpath.md) opção.  
  
 / LISTA  
 Exibe informações sobre a biblioteca de saída para a saída padrão. A saída pode ser redirecionada para um arquivo. Você pode usar /LIST para determinar o conteúdo de uma biblioteca existente sem modificá-lo.  
  
 / NOME: *filename*  
 Ao criar uma biblioteca de importação, especifica o nome da DLL para o qual a biblioteca de importação está sendo compilada.  
  
 /NODEFAULTLIB  
 Remove uma ou mais bibliotecas padrão da lista de bibliotecas que busca ao resolver referências externas. Consulte [/NODEFAULTLIB](../../build/reference/nodefaultlib-ignore-libraries.md) para obter mais informações.  
  
 / Entrada saída: *filename*  
 Substitui o nome do arquivo de saída padrão. Por padrão, a biblioteca de saída é criada no diretório atual, com o nome base do primeiro arquivo de biblioteca ou o objeto na linha de comando e a extensão. lib.  
  
 Ou remover: *objeto*  
 Omite especificado *objeto* da biblioteca de saída. LIB cria uma biblioteca de saída combinando todos os objetos (seja em arquivos de objeto ou bibliotecas) e, em seguida, excluindo qualquer objeto especificado com /remove.  
  
 /SUBSYSTEM: {CONSOLE &#124; EFI_APPLICATION &#124; EFI_BOOT_SERVICE_DRIVER &#124; EFI_ROM &#124; EFI_RUNTIME_DRIVER &#124; NATIVO &#124; POSIX &#124; WINDOWS &#124; WINDOWSCE} [, N º [. # #]]  
 Informa o sistema operacional como executar um programa criado por meio da vinculação para a biblioteca de saída. Para obter mais informações, consulte a descrição do LINK [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) opção.  
  
 Opções de LIB especificadas na linha de comando não diferenciam maiusculas de minúsculas.  
  
 Você pode usar o LIB para executar as seguintes tarefas de gerenciamento de biblioteca:  
  
-   Para adicionar objetos a uma biblioteca, especifique o nome de arquivo para a biblioteca existente e os nomes de arquivo para os novos objetos.  
  
-   Para combinar bibliotecas, especifique os nomes de arquivo de biblioteca. Você pode adicionar objetos e combinar bibliotecas com um único comando LIB.  
  
-   Para substituir um membro de biblioteca com um novo objeto, especifique a biblioteca que contém o objeto do membro a ser substituído e o nome do arquivo para o novo objeto (ou a biblioteca que contém). Quando um objeto que tem o mesmo nome existe em mais de um arquivo de entrada, LIB coloca o último objeto especificado no comando LIB para a biblioteca de saída. Quando você substituir um membro de biblioteca, certifique-se de especificar o novo objeto ou biblioteca após a biblioteca que contém o objeto.  
  
-   Para excluir um membro de uma biblioteca, use a opção /REMOVE. LIB processa quaisquer especificações de /REMOVE após a combinação de todos os objetos de entrada, independentemente da ordem de linha de comando.  
  
> [!NOTE]
>  Você não pode excluir um membro e extraia-o em um arquivo na mesma etapa. Você deve primeiro extrair o objeto do membro usando /EXTRACT, execute novamente usando /REMOVE de LIB. Esse comportamento é diferente do que a biblioteca de 16 bits (para bibliotecas OMF) fornecida em outros produtos da Microsoft.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de LIB](../../build/reference/lib-reference.md)