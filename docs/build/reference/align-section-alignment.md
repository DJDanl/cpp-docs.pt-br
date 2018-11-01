---
title: /ALIGN (alinhamento da seção)
ms.date: 12/29/2017
f1_keywords:
- VC.Project.VCLinkerTool.Alignment
- /align
helpviewer_keywords:
- sections, specifying alignment
- ALIGN linker option
- /ALIGN linker option
- -ALIGN linker option
- section alignment
- sections
ms.openlocfilehash: b68ec42db9c927fe8f56dad8f5670059359a1843
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665784"
---
# <a name="align-section-alignment"></a>/ALIGN (alinhamento da seção)

## <a name="syntax"></a>Sintaxe

> **/ ALINHAR**[**:**_número_]

### <a name="arguments"></a>Arguments

*número*<br/>
O valor de alinhamento em bytes.

## <a name="remarks"></a>Comentários

O **/ALINHAR** opção especifica o alinhamento de cada seção dentro do espaço de endereço linear do programa. O *número* argumento é em bytes e deve ser uma potência de dois. O padrão é 4K (4096). O vinculador emitirá um aviso se o alinhamento produz uma imagem inválida.

A menos que você estiver escrevendo um aplicativo como um driver de dispositivo, não será preciso modificar o alinhamento.

É possível modificar o alinhamento de uma determinada seção com o parâmetro align para o [/seção](../../build/reference/section-specify-section-attributes.md) opção.

O valor de alinhamento que você especifica não pode ser menor do que o maior alinhamento de seção.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Escolha o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção na **opções adicionais** caixa. Escolher **Okey** ou **aplicar** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
