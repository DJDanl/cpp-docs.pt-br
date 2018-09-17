---
title: / SOURCELINK (Sourcelink incluem arquivos PDB) | Microsoft Docs
ms.custom: ''
ms.date: 08/20/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /sourcelink
dev_langs:
- C++
helpviewer_keywords:
- /SOURCELINK linker option
- /SOURCELINK
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dff53f7a4db12e32bca2494ba99f5b3b8203d48f
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45706661"
---
# <a name="sourcelink-include-sourcelink-file-in-pdb"></a>/ SOURCELINK (Sourcelink incluem arquivos PDB)

Especifica um arquivo de configuração SourceLink para incluir no arquivo PDB gerado pelo vinculador.

## <a name="syntax"></a>Sintaxe

> **/ SOURCELINK:**_nome de arquivo_

## <a name="arguments"></a>Arguments

*filename*<br/>
Especifica um formato JSON arquivo de configuração que contém um mapeamento simples de caminhos de arquivo local a URLs onde o arquivo de origem pode ser recuperado para exibição pelo depurador. Para obter mais informações sobre o formato desse arquivo, consulte [esquema de JSON do Link de origem](https://github.com/dotnet/designs/blob/master/accepted/diagnostics/source-link.md#source-link-json-schema).

## <a name="remarks"></a>Comentários

SourceLink é um sistema de controle de origem e de linguagem independente para fornecer a depuração de origem para binários. SourceLink há suporte para binários nativos do C++ a partir do Visual Studio 2017 versão 15,8. Para obter uma visão geral de SourceLink, consulte [vínculo da fonte](https://github.com/dotnet/designs/blob/master/accepted/diagnostics/source-link.md). Para obter informações sobre como usar SourceLink em seus projetos e como gerar o arquivo SourceLink como parte do seu projeto, consulte [SourceLink usando](https://github.com/dotnet/sourcelink#using-sourcelink).

### <a name="to-set-the-sourcelink-linker-option-in-visual-studio"></a>Para definir a opção de vinculador /SOURCELINK no Visual Studio

1. Abra o **páginas de propriedade** caixa de diálogo para o projeto. Para obter mais informações, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. No **opções adicionais** caixa, adicione **/SOURCELINK:**_filename_ e, em seguida, escolha **Okey** ou **aplicar**para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Essa opção não tem um equivalente programático.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
