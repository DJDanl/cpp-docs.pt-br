---
title: /FILEALIGN (Alinhar seções em arquivos)
ms.date: 10/23/2017
f1_keywords:
- /filealign
helpviewer_keywords:
- linker align sections
- /FILEALIGN linker option
- -FILEALIGN linker option
- FILEALIGN linker option
ms.assetid: c1017a35-8d71-4ad9-934b-a3e3ea037fa0
ms.openlocfilehash: 43cfdd6efb163013d05877e91c8375eb592295a9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62271145"
---
# <a name="filealign-align-sections-in-files"></a>/FILEALIGN (Alinhar seções em arquivos)

O **/FILEALIGN** a opção de vinculador permite que você especifique o alinhamento das seções gravados para o arquivo de saída como um múltiplo de um tamanho especificado.

## <a name="syntax"></a>Sintaxe

> __/FILEALIGN:__*size*

### <a name="parameters"></a>Parâmetros

*size*<br/>
O tamanho de alinhamento de seção em bytes, que deve ser uma potência de dois.

## <a name="remarks"></a>Comentários

O **/FILEALIGN** opção faz com que o vinculador alinhar cada seção no arquivo de saída em um limite que é um múltiplo da *tamanho* valor. Por padrão, o vinculador não usa um tamanho fixo de alinhamento.

O **/FILEALIGN** opção pode ser usada para tornar mais eficiente a utilização de disco ou tornar a página carrega no disco com mais rapidez. Um tamanho menor de seção pode ser útil para aplicativos que são executados em dispositivos menores, ou para manter os downloads menores. Alinhamento de seção no disco não afeta o alinhamento na memória.

Use [DUMPBIN](dumpbin-reference.md) para ver informações sobre as seções em seu arquivo de saída.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **linha de comando** página de propriedades na **vinculador** pasta.

1. Digite o nome da opção **/FILEALIGN:** e o tamanho na **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
