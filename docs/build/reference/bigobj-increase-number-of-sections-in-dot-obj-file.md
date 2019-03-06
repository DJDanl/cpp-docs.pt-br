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
ms.openlocfilehash: 051eaeb568418a8a01d25f738617fa171039f27d
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57416482"
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

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
