---
title: / ALINHAR (alinhamento de seção) | Microsoft Docs
ms.custom: ''
ms.date: 12/29/2017
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.Alignment
- /align
dev_langs:
- C++
helpviewer_keywords:
- sections, specifying alignment
- ALIGN linker option
- /ALIGN linker option
- -ALIGN linker option
- section alignment
- sections
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 543ea30b06f62939f378167d8598c73f66061f46
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="align-section-alignment"></a>/ALIGN (alinhamento da seção)

## <a name="syntax"></a>Sintaxe

> **/ ALINHAR**[**:**_número_]

### <a name="arguments"></a>Arguments

*Número*  
O valor do alinhamento em bytes.

## <a name="remarks"></a>Comentários

O **/ALINHAR** opção especifica o alinhamento de cada seção dentro do espaço de endereçamento linear do programa. O *número* argumento é em bytes e deve ser uma potência de dois. O padrão é 4 KB (4096). O vinculador emite um aviso se o alinhamento produz uma imagem inválida.

A menos que você estiver escrevendo um aplicativo como um driver de dispositivo, você não precisará modificar o alinhamento.

É possível modificar o alinhamento de uma seção específica com o parâmetro Alinhar para o [/seção](../../build/reference/section-specify-section-attributes.md) opção.

O valor do alinhamento especificado não pode ser menor do que o maior alinhamento de seção.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).

1. Escolha o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção no **opções adicionais** caixa. Escolha **Okey** ou **aplicar** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)  
[Opções do vinculador](../../build/reference/linker-options.md)  
