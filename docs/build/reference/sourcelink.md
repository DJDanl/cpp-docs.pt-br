---
title: / SOURCELINK (Sourcelink incluem arquivos PDB)
ms.date: 08/20/2018
f1_keywords:
- /sourcelink
helpviewer_keywords:
- /SOURCELINK linker option
- /SOURCELINK
ms.openlocfilehash: a5a01ca56a49791a608c5c836312c7728e9328c3
ms.sourcegitcommit: fe1e21df175cd004d21c6e4659082efceb649a8b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/02/2019
ms.locfileid: "53978277"
---
# <a name="sourcelink-include-source-link-file-in-pdb"></a>/ SOURCELINK (Link de origem incluem arquivos PDB)

Especifica um arquivo de configuração do Link de origem para incluir no arquivo PDB gerado pelo vinculador.

## <a name="syntax"></a>Sintaxe

> **/ SOURCELINK:**_nome de arquivo_

## <a name="arguments"></a>Arguments

*filename*<br/>
Especifica um formato JSON arquivo de configuração que contém um mapeamento simples de caminhos de arquivo local a URLs onde o arquivo de origem pode ser recuperado para exibição pelo depurador. Para obter mais informações sobre o formato desse arquivo, consulte [esquema de JSON do Link de origem](https://github.com/dotnet/designs/blob/master/accepted/diagnostics/source-link.md#source-link-json-schema).

## <a name="remarks"></a>Comentários

Link de origem é um sistema de controle de origem e de linguagem independente para fornecer a depuração de origem para binários. Link de origem é compatível com binários nativos do C++ a partir do Visual Studio 2017 versão 15,8. Para uma visão geral do Link de origem, consulte [vínculo da fonte](https://github.com/dotnet/designs/blob/master/accepted/diagnostics/source-link.md). Para obter informações sobre como usar o Link de origem em seus projetos e como gerar o arquivo SourceLink como parte do seu projeto, consulte [usando o Link de origem](https://github.com/dotnet/sourcelink#using-source-link-in-c-projects).

### <a name="to-set-the-sourcelink-linker-option-in-visual-studio"></a>Para definir a opção de vinculador /SOURCELINK no Visual Studio

1. Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. No **opções adicionais** caixa, adicione **/SOURCELINK:**_filename_ e, em seguida, escolha **Okey** ou **aplicar**para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
