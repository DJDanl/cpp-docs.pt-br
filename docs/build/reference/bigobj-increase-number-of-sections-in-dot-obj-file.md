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
ms.openlocfilehash: 30c02c72496e3bb91da3b39e1870f1dc5a2c040a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493108"
---
# <a name="bigobj-increase-number-of-sections-in-obj-file"></a>/bigobj (aumentar número de seções no arquivo .Obj)

**/bigobj** aumenta o número de seções que um arquivo de objeto pode conter.

## <a name="syntax"></a>Sintaxe

> **/bigobj**

## <a name="remarks"></a>Comentários

Por padrão, um arquivo de objeto pode conter até 65.279 (quase 2 ^ 16) seções endereçáveis. Esse limite se aplica independentemente da plataforma de destino especificada. **/bigobj** aumenta a capacidade de endereço para 4.294.967.296 (2 ^ 32).

A maioria dos módulos nunca gera um arquivo. obj que contém mais de 65.279 seções. No entanto, código gerado por máquina, ou código que faz uso intensivo de bibliotecas de modelos, pode exigir arquivos. obj que possam conter mais seções. o **/bigobj** é habilitado por padrão em projetos plataforma universal do Windows (UWP) porque o código XAML gerado pelo computador inclui um grande número de cabeçalhos. Se você desabilitar essa opção em um projeto de aplicativo UWP, seu código poderá gerar o erro do compilador C1128.

Para obter informações sobre o formato de arquivo de objeto do PE-COFF, consulte [formato PE](/windows/win32/debug/pe-format) na documentação do Windows.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++**  > **Linha de Comando**.

1. Insira a opção do compilador **/bigobj** na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
