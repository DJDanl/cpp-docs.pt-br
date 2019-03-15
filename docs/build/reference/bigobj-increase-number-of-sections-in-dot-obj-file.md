---
title: /bigobj (aumentar número de seções no arquivo .Obj)
ms.date: 11/04/2016
f1_keywords:
- /bigobj
helpviewer_keywords:
- -bigobj compiler option [C++]
- /bigobj compiler option [C++]
- bigobj compiler option [C++]
ms.assetid: ba94d602-4015-4a8d-86ec-49241ab74c12
ms.openlocfilehash: a9685834fc3e1de246c9d9d60d206538b744ce3e
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57809854"
---
# <a name="bigobj-increase-number-of-sections-in-obj-file"></a>/bigobj (aumentar número de seções no arquivo .Obj)

**/bigobj** aumenta o número de seções que um arquivo de objeto pode conter.

## <a name="syntax"></a>Sintaxe

```
/bigobj
```

## <a name="remarks"></a>Comentários

Por padrão, um arquivo de objeto pode conter até 65.536 (2 ^ 16) seções endereçáveis. Esse é o caso, não importa qual plataforma de destino é especificada. **/bigobj** aumenta a capacidade de endereço para 4.294.967.296 (2 ^ 32).

A maioria dos módulos nunca irá gerar um arquivo. obj que contém mais de 65.536 seções. No entanto, o código gerado pelo computador, ou o código que faz uso intenso das bibliotecas de modelo pode exigir arquivos. obj que podem conter mais seções. **/bigobj** é habilitado por padrão em projetos de plataforma Universal do Windows (UWP), porque o código XAML gerado pelo computador inclui um grande número de cabeçalhos. Se você desabilitar essa opção em um projeto de aplicativo da UWP são probabilidade de encontrar o erro C1128 de compilador.

Os vinculadores fornecidos antes do Visual C++ 2005 não é possível ler os arquivos. obj que foram gerados com **/bigobj**.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
