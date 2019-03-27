---
title: /bigobj (aumentar número de seções no arquivo .Obj)
ms.date: 03/26/2019
f1_keywords:
- /bigobj
helpviewer_keywords:
- -bigobj compiler option [C++]
- /bigobj compiler option [C++]
- bigobj compiler option [C++]
ms.assetid: ba94d602-4015-4a8d-86ec-49241ab74c12
ms.openlocfilehash: 46399dc0c1ff552b4fc963b686ac6aa6df8b6f71
ms.sourcegitcommit: 06fc71a46e3c4f6202a1c0bc604aa40611f50d36
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/27/2019
ms.locfileid: "58508709"
---
# <a name="bigobj-increase-number-of-sections-in-obj-file"></a>/bigobj (aumentar número de seções no arquivo .Obj)

**/bigobj** aumenta o número de seções que um arquivo de objeto pode conter.

## <a name="syntax"></a>Sintaxe

> **/bigobj**

## <a name="remarks"></a>Comentários

Por padrão, um arquivo de objeto pode conter até 65.279 (quase 2 ^ 16) seções endereçáveis. Esse limite se aplica independentemente de qual destino plataforma é especificada. **/bigobj** aumenta a capacidade de endereço para 4.294.967.296 (2 ^ 32).

A maioria dos módulos nunca gere um arquivo. obj que contém mais de 65,279 seções. No entanto, código gerado pelo computador, ou o código que faz uso intenso de bibliotecas de modelo, pode exigir os arquivos. obj que podem conter mais seções. **/bigobj** é habilitado por padrão em projetos de plataforma Universal do Windows (UWP), porque o código XAML gerado pelo computador inclui um grande número de cabeçalhos. Se você desabilitar essa opção em um projeto de aplicativo UWP, seu código pode gerar o erro C1128 de compilador.

Para obter informações sobre o formato de arquivo de objeto COFF PE, consulte [formato PE](/windows/desktop/debug/pe-format) na documentação do Windows.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira o **/bigobj** opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
