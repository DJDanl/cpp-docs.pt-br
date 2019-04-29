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
ms.openlocfilehash: d8d2e6a859c68af473d49dc04b76f0a15056aa56
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62295260"
---
# <a name="align-section-alignment"></a>/ALIGN (alinhamento da seção)

## <a name="syntax"></a>Sintaxe

> **/ALIGN**[**:**_number_]

### <a name="arguments"></a>Arguments

*number*<br/>
O valor de alinhamento em bytes.

## <a name="remarks"></a>Comentários

O **/ALINHAR** opção especifica o alinhamento de cada seção dentro do espaço de endereço linear do programa. O *número* argumento é em bytes e deve ser uma potência de dois. O padrão é 4K (4096). O vinculador emitirá um aviso se o alinhamento produz uma imagem inválida.

A menos que você estiver escrevendo um aplicativo como um driver de dispositivo, não será preciso modificar o alinhamento.

É possível modificar o alinhamento de uma determinada seção com o parâmetro align para o [/seção](section-specify-section-attributes.md) opção.

O valor de alinhamento que você especifica não pode ser menor do que o maior alinhamento de seção.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Escolha o **propriedades de configuração** > **vinculador** > **linha de comando** página de propriedades.

1. Insira a opção na **opções adicionais** caixa. Escolher **Okey** ou **aplicar** para aplicar a alteração.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
