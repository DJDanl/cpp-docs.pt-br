---
title: /FP (nome &period;arquivo pch)
description: Use a opção de compilador /Fp para especificar o nome do arquivo de cabeçalho pré-compilado.
ms.date: 05/31/2019
f1_keywords:
- VC.Project.VCCLCompilerTool.PrecompiledHeaderFile
- /fp
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
ms.openlocfilehash: 6e7faa934d14acb5d129173c5e0c7ee67d6caf2b
ms.sourcegitcommit: 540fa2f5015de1adfa7b6bf823f6eb4ed5a6a4bd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/03/2019
ms.locfileid: "66460882"
---
# <a name="fp-name-periodpch-file"></a>/FP (nome &period;arquivo pch)

Fornece um nome de caminho para um cabeçalho pré-compilado em vez de usar o nome do caminho padrão.

## <a name="syntax"></a>Sintaxe

> **/Fp**<em>pathname</em>

## <a name="remarks"></a>Comentários

Use o **/Fp** com a opção [/Yc (criar a arquivo de cabeçalho pré-compilado)](yc-create-precompiled-header-file.md) ou [/Yu (usar arquivo de cabeçalho pré-compilado)](yu-use-precompiled-header-file.md) para especificar o nome de arquivo e caminho para o cabeçalho pré-compilado (PCH) arquivo. Por padrão, o **/Yc** opção cria um nome de arquivo PCH usando o nome base do arquivo de origem e um *pch* extensão.

Se você não especificar uma extensão como parte do *pathname*, uma extensão da *pch* será assumido. Quando você especifica um nome de diretório pelo uso de uma barra ( **/** ) no final da *pathname*, o nome de arquivo padrão é vc*versão*0.pch, onde  *versão* é a versão principal do conjunto de ferramentas do Visual Studio. Esse diretório deve existir ou erro C1083 será gerado.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Abra o **propriedades de configuração** > **C /C++**  > **cabeçalhos pré-compilados** página de propriedades.

1. Modificar a **arquivo de saída de cabeçalho pré-compilado** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="examples"></a>Exemplos

Para criar um separado chamado de versão do arquivo de cabeçalho pré-compilado para o build de depuração do seu programa, você pode especificar um comando como:

```CMD
CL /DDEBUG /Zi /Yc /FpDPROG.PCH PROG.CPP
```

O comando a seguir especifica o uso de um arquivo de cabeçalho pré-compilado chamado MYPCH.pch. O compilador pré-compila o código-fonte no Prog até o final do MYAPP.h e coloca o código pré-compilado em MYPCH.pch. Em seguida, ele utiliza o conteúdo de MYPCH.pch e compila o restante do Prog para criar um arquivo. obj. A saída deste exemplo é um arquivo chamado PROG.exe.

```CMD
CL /YuMYAPP.H /FpMYPCH.PCH PROG.CPP
```

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
