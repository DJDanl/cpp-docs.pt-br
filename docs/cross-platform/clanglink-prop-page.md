---
title: Propriedades do vinculador Clang (Android C++)
ms.date: 10/23/2017
ms.assetid: 66e88848-116c-4eb0-bc57-183394d35b57
f1_keywords:
- VC.Project.VCLinkerTool.Clang.OutputFile
- VC.Project.VCLinkerTool.Clang.Soname
- VC.Project.VCLinkerTool.Clang.ShowProgress
- VC.Project.VCLinkerTool.Clang.Version
- VC.Project.VCLinkerTool.Clang.VerboseOutput
- VC.Project.VCLinkerTool.Clang.IncrementalLink
- VC.Project.VCLinkerTool.Clang.SharedLibrarySearchPath
- VC.Project.VCLinkerTool.Clang.AdditionalLibraryDirectories
- VC.Project.VCLinkerTool.Clang.UnresolvedReferences
- VC.Project.VCLinkerTool.Clang.OptimizeForMemory
- VC.Project.VCLinkerTool.Clang.IgnoreDefaultLibraryNames
- VC.Project.VCLinkerTool.Clang.ForceSymbolReferences
- VC.Project.VCLinkerTool.Clang.ForceFileOutput
- VC.Project.VCLinkerTool.Clang.OmitDebuggerSymbolInformation
- VC.Project.VCLinkerTool.Clang.GenerateMapFile
- VC.Project.VCLinkerTool.Clang.Relocation
- VC.Project.VCLinkerTool.Clang.FunctionBinding
- VC.Project.VCLinkerTool.Clang.NoExecStackRequired
- VC.Project.VCLinkerTool.Clang.WholeArchive
- VC.Project.VCLinkerTool.Clang.AdditionalOptionsPage
- VC.Project.VCLinkerTool.Clang.AdditionalDependencies
- VC.Project.VCLinkerTool.Clang.LibraryDependencies
ms.openlocfilehash: 55b944040157d13741b992f4ec66c35d1b117d95
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79446530"
---
# <a name="clang-linker-properties-android-c"></a>Propriedades do vinculador Clang (C++ para Android)

| Propriedade | Descrição | Opções |
|--|--|--|
| Arquivo de Saída | A opção substitui o nome e o local padrão do programa que o vinculador cria. (-o) |
| Mostrar progresso | Imprime mensagens de progresso do vinculador. |
| {1&gt;Version&lt;1} | A opção -version instrui o vinculador a colocar um número de versão no cabeçalho do executável. |
| Habilitar saída detalhada | A opção -verbose instrui o vinculador a produzir mensagens detalhadas para depuração. |
| Habilitar vinculação incremental | A opção instrui o vinculador a habilitar a vinculação incremental. |
| Caminho de Pesquisa de Biblioteca Compartilhada | Permite que o usuário popule o caminho de pesquisa de biblioteca compartilhada. |
| Diretórios de Biblioteca Adicionais | Permite que o usuário substitua o caminho da biblioteca ambiental. (-L folder). |
| Relatar referências de símbolo não resolvidas | Essa opção quando habilitada relata referências de símbolo não resolvidas. |
| Otimizar uso de memória | Otimizar para uso de memória relendo as tabelas de símbolo se necessário. |
| Ignorar bibliotecas padrão específicas | Especifica um ou mais nomes de bibliotecas padrão a serem ignoradas. |
| Forçar referências de símbolo | Forçar o símbolo a ser inserido no arquivo de saída como um símbolo indefinido. |
| Informações do Símbolo do Depurador | Informações de símbolo do depurador do arquivo de saída. | **Incluir tudo**<br /><br />**Omitir símbolos desnecessários para o processamento de realocação**<br /><br />**Omitir Somente Informações do Símbolo do Depurador**<br /><br />**Omitir Todas as Informações de Símbolos** |
| Informações de símbolo do depurador de pacotes | Remover as informações de símbolos do depurador antes do empacotamento.  Uma cópia do binário original é usada para depuração. |
| Nome do arquivo de mapa | A opção Map instrui o vinculador a criar um arquivo de mapa com o nome especificado pelo usuário. |
| Marcar variáveis como ReadOnly após a realocação | Essa opção marca as variáveis como somente leitura após a realocação. |
| Habilitar associação de função imediata | Essa opção marca o objeto para associação de função imediata. |
| Exigir pilha executável | Essa opção marca que a saída não exigirá pilha executável. |
| Arquivo morto inteiro | O arquivo morto inteiro usa todo o código das fontes e das dependências adicionais. |
| Opções adicionais | Opções adicionais. |
| {1&gt;Dependências adicionais&lt;1} | Especifica itens adicionais a serem adicionados à linha de comando do link. |
| Dependências da Biblioteca | Essa opção permite especificar as bibliotecas adicionais a serem adicionadas à linha de comando do vinculador. As bibliotecas adicionais são adicionadas ao final da linha de comando do vinculador iniciar com *lib* e terminar com a extensão *. a* ou *..* .  (-lFILE) |
