---
title: /SOURCELINK (incluir arquivo sourcelink no PDB)
description: Guia de referência para a opção de linker /SOURCELINK no Microsoft C++.
ms.date: 03/31/2020
f1_keywords:
- /sourcelink
helpviewer_keywords:
- /SOURCELINK linker option
- /SOURCELINK
ms.openlocfilehash: bde55c401e17f7b3c84ffcdad29dda2badcc260b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81336063"
---
# <a name="sourcelink-include-source-link-file-in-pdb"></a>/SOURCELINK (Incluir arquivo de link de origem no PDB)

Especifica um arquivo de configuração do Source Link para incluir no arquivo PDB gerado pelo linker.

## <a name="syntax"></a>Sintaxe

> **`/SOURCELINK:`**_`filename`_

## <a name="arguments"></a>Argumentos

*Filename*<br/>
Especifica um arquivo de configuração formatado pelo JSON que contém um mapeamento simples de caminhos de arquivo locais para URLs para arquivos de origem para exibir no depurador. Para obter mais informações sobre o formato deste arquivo, consulte [Source Link JSON Schema](https://github.com/dotnet/designs/blob/master/accepted/2020/diagnostics/source-link.md#source-link-json-schema).

## <a name="remarks"></a>Comentários

O Source Link é um sistema agnóstico de controle de idiomas e origem para fornecer depuração de origem para binários. Source Link é suportado para binários C++ nativos a partir da versão 15.8 do Visual Studio 2017. Para obter uma visão geral do Source Link, consulte [Source Link](https://github.com/dotnet/designs/blob/master/accepted/2020/diagnostics/source-link.md). Para obter informações sobre como usar o Source Link em seus projetos e como gerar o arquivo SourceLink como parte do seu projeto, consulte [Usando o Link de Origem](https://github.com/dotnet/sourcelink#using-source-link-in-c-projects).

### <a name="to-set-the-sourcelink-linker-option-in-visual-studio"></a>Para definir a opção de linker /SOURCELINK no Visual Studio

1. Abra a caixa de diálogo **Páginas** de propriedade para o projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedade **Configuração Propriedades** > **linker's** > **command line.**

1. Na **caixa De opções Adicionais,** adicione **`/SOURCELINK:`** _`filename`_ e escolha **OK** ou **Aplicar** para salvar suas alterações.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Esta opção não tem um equivalente programático.

## <a name="see-also"></a>Confira também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
