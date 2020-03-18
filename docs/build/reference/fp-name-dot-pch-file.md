---
title: /FP (nome &period;arquivo PCH)
description: Use a opção de compilador/FP para especificar o nome do arquivo de cabeçalho pré-compilado.
ms.date: 05/31/2019
f1_keywords:
- VC.Project.VCCLCompilerTool.PrecompiledHeaderFile
- VC.Project.VCCLWCECompilerTool.PrecompiledHeaderFile
helpviewer_keywords:
- Fp compiler option [C++]
- -Fp compiler option [C++]
- naming precompiler header files
- PCH files, naming
- names [C++], PCH
- .pch files, naming
- precompiled header files, naming
- /Fp compiler option [C++]
ms.assetid: 0fcd9cbd-e09f-44d3-9715-b41efb5d0be2
ms.openlocfilehash: d62c5bd9fc7920c0a2a5530879680fad2a01d39a
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439787"
---
# <a name="fp-name-periodpch-file"></a>/FP (nome &period;arquivo PCH)

Fornece um nome de caminho para um cabeçalho pré-compilado em vez de usar o nome de caminho padrão.

## <a name="syntax"></a>Sintaxe

> **/Fp**<em>Nome do caminho</em> /FP

## <a name="remarks"></a>Comentários

Use a opção **/FP** com [/Yc (criar arquivo de cabeçalho pré-compilado)](yc-create-precompiled-header-file.md) ou [/Yu (use o arquivo de cabeçalho pré-compilado)](yu-use-precompiled-header-file.md) para especificar o caminho e o nome do arquivo para o arquivo de cabeçalho pré-compilado (PCH). Por padrão, a opção **/YC** cria um nome de arquivo PCH usando o nome base do arquivo de origem e uma extensão *PCH* .

Se você não especificar uma extensão como parte do *nome do caminho*, uma extensão de *PCH* será assumida. Quando você especifica um nome de diretório usando uma barra ( **/** ) no final do nome do *caminho*, o arquivo padrão é vc*versão*0. pch, em que *version* é a versão principal do conjunto de ferramentas do Visual Studio. Esse diretório deve existir ou o erro C1083 é gerado.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra as **Propriedades de configuração** > página de propriedades de **cabeçalhos pré-compilados** **C++ C/**  > .

1. Modifique a propriedade do **arquivo de saída do cabeçalho pré-compilado** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="examples"></a>Exemplos

Para criar uma versão nomeada separada do arquivo de cabeçalho pré-compilado para a compilação de depuração do seu programa, você pode especificar um comando como:

```CMD
CL /DDEBUG /Zi /Yc /FpDPROG.PCH PROG.CPP
```

O comando a seguir especifica o uso de um arquivo de cabeçalho pré-compilado chamado MYPCH. pch. O compilador pré-compila o código-fonte em PROG. cpp até o final de MYAPP. h e coloca o código pré-compilado em MYPCH. pch. Em seguida, ele usa o conteúdo de MYPCH. pch e compila o restante de PROG. cpp para criar um arquivo. obj. A saída deste exemplo é um arquivo chamado PROG. exe.

```CMD
CL /YuMYAPP.H /FpMYPCH.PCH PROG.CPP
```

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
