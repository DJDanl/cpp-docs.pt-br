---
title: /DEBUG (gerar informações de depuração)
ms.date: 05/16/2019
f1_keywords:
- VC.Project.VCLinkerTool.GenerateDebugInformation
- /debug
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
ms.openlocfilehash: 2ec466a6356ace437d32eb517bf2da291938f5db
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837152"
---
# <a name="debug-generate-debug-info"></a>/DEBUG (gerar informações de depuração)

```
/DEBUG[:{FASTLINK|FULL|NONE}]
```

## <a name="remarks"></a>Comentários

A opção **/DEBUG** cria informações de depuração para o executável.

O vinculador coloca as informações de depuração em um arquivo PDB (banco de dados do programa). Ele atualiza o PDB durante os builds seguintes do programa.

Um executável (arquivo .exe ou DLL) criado para depuração contém o nome e o caminho do PDB correspondente. O depurador lê o nome inserido e usa o PDB quando você depura o programa. O vinculador usa o nome base do programa e a extensão .pdb para nomear o banco de dados do programa e insere o caminho na localização em que ele foi criado. Para substituir esse padrão, defina [/PDB](pdb-use-program-database.md) e especifique outro nome de arquivo.

A opção **/DEBUG:FASTLINK** está disponível no Visual Studio 2017 e posterior. Essa opção mantém as informações de símbolo particulares nos produtos de compilação individuais usados para compilar o executável. Ele gera um PDB limitado que é indexado nas informações de depuração nos arquivos-objeto e nas bibliotecas usadas para compilar o executável em vez de fazer uma cópia completa. Essa opção pode ser vinculada duas a quatro vezes mais rapidamente comparado à geração de PDB completo e é recomendada quando você está depurando localmente e tem os produtos de build disponíveis. Esse PDB limitado não pode ser usado para depuração quando os produtos de build necessários não estão disponíveis, como quando o executável é implantado em outro computador. Em um Prompt de Comando do Desenvolvedor, use a ferramenta mspdbcmf.exe para gerar um PDB completo com base nesse PDB limitado. No Visual Studio, use os itens de menu Projeto ou Build para gerar um arquivo PDB completo a fim de criar um PDB completo para o projeto ou a solução.

A opção **/DEBUG:FULL** move todas as informações de símbolo particulares de produtos de compilação individuais (arquivos-objeto e bibliotecas) para um único PDB e pode ser a parte mais demorada da vinculação. No entanto, o PDB completo pode ser usado para depurar o executável quando não há outros produtos de build disponíveis, como quando o executável é implantado.

A opção **/DEBUG:NONE** não gera um PDB.

Quando você especifica **/DEBUG** sem opções adicionais, o vinculador usa como padrão **/DEBUG:FULL** para a linha de comando e os builds de makefile, para os builds de versão no IDE do Visual Studio e para os builds de depuração e versão no Visual Studio 2015 e versões anteriores. No Visual Studio 2017 em diante, o sistema de build no IDE usa como padrão **/DEBUG:FASTLINK** quando você especifica a opção **/DEBUG** para builds de depuração. Outros padrões não são alterados para manter a compatibilidade com versões anteriores.

A opção [Compatível com C7](z7-zi-zi-debug-information-format.md) (/ Z7) do compilador faz com que o compilador mantenha as informações de depuração nos arquivos .obj. Use também a opção do compilador [Banco de Dados do Programa](z7-zi-zi-debug-information-format.md) (/Zi) para armazenar as informações de depuração em um PDB para o arquivo .obj. O vinculador procura o PDB do objeto primeiro no caminho absoluto gravado no arquivo .obj e, em seguida, no diretório que contém o arquivo .obj. Não é possível especificar o nome do arquivo PDB de um objeto nem a localização do vinculador.

[/INCREMENTAL](incremental-link-incrementally.md) fica implícito quando /DEBUG é especificado.

/DEBUG altera os padrões para a opção [/OPT](opt-optimizations.md) de REF para NOREF e de ICF para NOICF; portanto, caso você deseje obter os padrões originais, precisará especificar explicitamente /OPT:REF ou /OPT:ICF.

Não é possível criar um .exe ou .dll que contém informações de depuração. As informações de depuração são sempre colocadas em um arquivo .obj ou .pdb.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **Vinculador**.

1. Clique na página de propriedades **Depuração**.

1. Modifique a propriedade **Gerar Informações de Depuração** para habilitar a geração de PDB. Isso habilita /DEBUG:FASTLINK por padrão no Visual Studio 2017 e posterior.

1. Modifique a propriedade **Gerar Arquivo Completo de Banco de Dados do Programa** para habilitar /DEBUG:FULL para a geração de PDB completo para cada build incremental.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateDebugInformation%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
