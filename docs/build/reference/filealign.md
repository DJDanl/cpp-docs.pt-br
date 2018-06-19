---
title: / /FILEALIGN (Alinhar seções em arquivos) | Microsoft Docs
ms.date: 10/23/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /filealign
dev_langs:
- C++
helpviewer_keywords:
- linker align sections
- /FILEALIGN linker option
- -FILEALIGN linker option
- FILEALIGN linker option
ms.assetid: c1017a35-8d71-4ad9-934b-a3e3ea037fa0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c8a737801663a2c7c1e896166291a1635fbbe6c4
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32373264"
---
# <a name="filealign-align-sections-in-files"></a>/ /FILEALIGN (Alinhar seções em arquivos)

O **/FILEALIGN** opção de vinculador permite que você especifique o alinhamento das seções gravados para o arquivo de saída como um múltiplo de um tamanho especificado.

## <a name="syntax"></a>Sintaxe

> __/ /FILEALIGN:__*tamanho*

### <a name="parameters"></a>Parâmetros

*size*  
O tamanho de alinhamento de seção em bytes, que deve ser uma potência de dois.

## <a name="remarks"></a>Comentários

O **/FILEALIGN** opção faz com que o vinculador alinhar cada seção no arquivo de saída em um limite que é um múltiplo do *tamanho* valor. Por padrão, o vinculador não usa um tamanho fixo de alinhamento.

O **/FILEALIGN** opção pode ser usada para tornar mais eficiente a utilização de disco ou tornar a página carrega de disco mais rápido. Um tamanho menor de seção pode ser útil para aplicativos que são executados em dispositivos menores, ou para manter os downloads menores. Alinhamento de seção em disco não afeta o alinhamento em memória.

Use [DUMPBIN](dumpbin-reference.md) para ver informações sobre as seções em seu arquivo de saída.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **linha de comando** página de propriedades no **vinculador** pasta.

1. Digite o nome da opção **/FILEALIGN:** e o tamanho no **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
[Opções do vinculador](../../build/reference/linker-options.md)