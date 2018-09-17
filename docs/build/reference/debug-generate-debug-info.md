---
title: -DEBUG (gerar informações de depuração) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.GenerateDebugInformation
- /debug
dev_langs:
- C++
helpviewer_keywords:
- DEBUG linker option
- /DEBUG linker option
- -DEBUG linker option
- PDB files
- debugging [C++], debug information files
- generate debug info linker option
- pdb files, generating debug info
- .pdb files, generating debug info
- debugging [C++], linker option
- program databases [C++]
ms.assetid: 1af389ae-3f8b-4d76-a087-1cdf861e9103
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 50ef5ac999a84b1f7b265cd7baab873087e56107
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705296"
---
# <a name="debug-generate-debug-info"></a>/DEBUG (gerar informações de depuração)

```
/DEBUG[:{FASTLINK|FULL|NONE}]
```

## <a name="remarks"></a>Comentários

O **/Debug** opção cria informações de depuração para o executável.

O vinculador coloca as informações de depuração em um arquivo de banco de dados (PDB) do programa. Ele atualiza o PDB durante compilações subsequentes do programa.

Um arquivo executável (arquivo .exe ou DLL) criado para depuração contém o nome e caminho de PDB correspondente. O depurador lê o nome inserido e usa o PDB quando você depura o programa. O vinculador usa o nome base do programa e a extensão. PDB para nomear o banco de dados do programa e insere o caminho onde ele foi criado. Para substituir esse padrão, defina [/PDB](../../build/reference/pdb-use-program-database.md) e especifique um nome de arquivo diferente.

O **/Debug: fastlink** opção está disponível no Visual Studio 2017 e posterior. Essa opção deixa as informações de símbolo privada nos produtos individuais de compilação usados para criar o arquivo executável. Ele gera um PDB de limitado para as informações de depuração nos arquivos de objeto e bibliotecas usadas para criar o arquivo executável em vez de fazer uma cópia completa de índices. Essa opção pode vincular de duas a quatro vezes mais depressa a geração de PDB completa e é recomendada quando você estiver depurando localmente e tiver os produtos de build disponíveis. Esse PDB limitado não pode ser usado para depuração quando os produtos de compilação necessários não estiverem disponíveis, como quando o executável é implantado em outro computador. Em um prompt de comando do desenvolvedor, você pode usar a ferramenta mspdbcmf.exe para gerar um PDB completo desse PDB limitado. No Visual Studio, use os itens de menu do projeto ou de compilação para gerar um arquivo PDB completo para criar um PDB completo para o projeto ou solução.

O **/Debug: full** opção move todas as informações de símbolo privada de produtos individuais de compilação (arquivos de objeto e bibliotecas) para um único PDB e pode ser a parte mais demorada do link. No entanto, o PDB completo pode ser usado para depurar o executável quando não há outros produtos de build estiverem disponíveis, como quando o executável é implantado.

O **/Debug: nenhum** opção não gera um PDB.

Quando você especifica **/Debug** sem opções adicionais, o vinculador usa como padrão **/Debug: full** para linha de comando e compilações de makefile, versão se baseia no IDE do Visual Studio e para depuração e versão o build no Visual Studio 2015 e versões anteriores. A partir do Visual Studio 2017, o sistema de compilação no IDE assume como padrão **/Debug: fastlink** quando você especifica a **/Debug** opção para compilações de depuração. Outros padrões não foram alterados para manter a compatibilidade com versões anteriores.

O compilador [compatível com C7](../../build/reference/z7-zi-zi-debug-information-format.md) (/ Z7) opção faz com que o compilador deixar as informações de depuração em arquivos. obj. Você também pode usar o [banco de dados do programa](../../build/reference/z7-zi-zi-debug-information-format.md) (/Zi) a opção de compilador para armazenar as informações de depuração em um PDB para o arquivo. obj. O vinculador procura PDB do objeto primeiro no caminho absoluto gravado no arquivo. obj e, em seguida, no diretório que contém o arquivo. obj. Não é possível especificar o nome do arquivo PDB de um objeto ou o local para o vinculador.

[/ INCREMENTAL](../../build/reference/incremental-link-incrementally.md) é inferido quando /DEBUG é especificado.

/ DEPURAÇÃO altera os padrões para o [/opt](../../build/reference/opt-optimizations.md) opção de REF NOREF em ICF para NOICF, portanto, se você quiser que os padrões de originais, você deve especificar explicitamente /OPT: ref ou /OPT: ICF.

Não é possível criar um .exe ou. dll que contém informações de depuração. Depurar informações sempre são colocadas em um arquivo. obj ou. PDB.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **depuração** página de propriedades.

1. Modificar a **gerar informações de depuração** propriedade para habilitar a geração de PDB. Isso permite que o /Debug: fastlink por padrão no Visual Studio 2017.

1. Modificar a **gerar arquivo completo do banco de dados do programa** propriedade para habilitar /Debug: full para geração de PDB completa para cada compilação incremental.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateDebugInformation%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
