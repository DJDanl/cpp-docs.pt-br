---
title: /Fo (Nome do arquivo de objeto)
description: Guia de referência para a opção de compilador Microsoft C++ /Fo (nome do arquivo objeto) no Visual Studio.
ms.date: 04/20/2020
f1_keywords:
- /Fo
- VC.Project.VCCLCompilerTool.ObjectFile
- VC.Project.VCCLWCECompilerTool.ObjectFile
helpviewer_keywords:
- Fo compiler option [C++]
- object files, naming
- /Fo compiler option [C++]
- -Fo compiler option [C++]
ms.assetid: 0e6d593e-4e7f-4990-9e6e-92e1dcbcf6e6
ms.openlocfilehash: cd22ba745128fe1df67853d98c1495491b9ca840
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81748965"
---
# <a name="fo-object-file-name"></a>/Fo (Nome do arquivo de objeto)

Especifica um nome*`.obj`* de arquivo ou diretório de objeto ( ) a ser usado em vez do padrão.

## <a name="syntax"></a>Sintaxe

> **`/Fo`**_Caminho_

## <a name="remarks"></a>Comentários

Você pode **`/Fo`** usar a opção compilador para definir um diretório de saída para todos os arquivos de objeto gerados pelo comando cl compilador. Ou, você pode usá-lo para renomear um único arquivo de objeto.

Por padrão, os arquivos de objeto gerados pelo compilador são colocados no diretório atual. Eles têm o nome base do arquivo *`.obj`* de origem e uma extensão.

Para usar **`/Fo`** a opção de renomear um arquivo de objeto, especifique o nome do arquivo de saída como o argumento *nome de caminho.* Quando você renomeia um arquivo de objeto, você pode usar qualquer *`.obj`* nome e extensão que quiser, mas a convenção recomendada é usar . O compilador gera erro de linha de comando D8036 se você especificar um nome de arquivo para **`/Fo`** quando você tiver especificado mais de um arquivo de origem para compilar.

Para usar **`/Fo`** a opção de definir um diretório de saída para todos os arquivos de objeto criados pelo comando CL, especifique o diretório como o argumento *nome de caminho.* Um diretório é indicado por uma barra de arrasto no argumento *pathname.* O diretório especificado deve existir; não é criado automaticamente.

## <a name="example"></a>Exemplo

A linha de comando a seguir cria um arquivo de objeto chamado *sample.obj* em um diretório existente, * \\intermediário,* na unidade D.

```cmd
CL /Fo"D:\intermediate\" /EHsc /c sample.cpp
```

## <a name="set-the-option-in-visual-studio-or-programmatically"></a>Defina a opção no Visual Studio ou programática

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedade **Propriedades de** > configuração**C/C++** > **De si.**

1. Modifique a propriedade **Nome do arquivo do objeto** para definir o diretório de saída. No IDE, o arquivo de objeto *`.obj`* deve ter uma extensão de .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ObjectFile%2A>.

## <a name="see-also"></a>Confira também

[Opções de arquivo de saída (/f)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
