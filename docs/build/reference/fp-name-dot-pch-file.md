---
title: -Fp (nome. Arquivo pch) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.PrecompiledHeaderFile
- /fp
- VC.Project.VCCLWCECompilerTool.PrecompiledHeaderFile
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0a851f93ae845d56b9c986e822e94970ad5cccd5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46427128"
---
# <a name="fp-name-pch-file"></a>/Fp (nomear arquivo .Pch)

Fornece um nome de caminho para um cabeçalho pré-compilado em vez de usar o nome do caminho padrão.

## <a name="syntax"></a>Sintaxe

> **/FP**<em>pathname</em>

## <a name="remarks"></a>Comentários

Use essa opção com [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) ou [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md) para fornecer um nome de caminho para um cabeçalho pré-compilado em vez de usar o nome do caminho padrão. Você também pode usar **/Fp** com **/Yc** para especificar o uso de um arquivo de cabeçalho pré-compilado que difere do **/Yc**<em>filename</em> argumento e do nome de base do arquivo de origem.

Se você não especificar uma extensão como parte do nome do caminho, uma extensão de. pch será assumida. Se você especificar um diretório sem um nome de arquivo, o nome de arquivo padrão é VC*x*0.pch, onde *x* é a versão principal do Visual C++ em uso.

Você também pode usar o **/Fp** com a opção **/Yu**.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **cabeçalhos pré-compilados** página de propriedades.

1. Modificar a **arquivo de cabeçalho pré-compilado** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PrecompiledHeaderFile%2A>.

## <a name="example"></a>Exemplo

Se você deseja criar um arquivo de cabeçalho pré-compilado para uma versão de depuração do seu programa e você está compilando arquivos de cabeçalho e o código-fonte, você pode especificar um comando como:

```
CL /DDEBUG /Zi /Yc /FpDPROG.PCH PROG.CPP
```

## <a name="example"></a>Exemplo

O comando a seguir especifica o uso de um arquivo de cabeçalho pré-compilado chamado MYPCH.pch. O compilador pressupõe que o código-fonte no Prog tem sido pré-compilado por meio de MYAPP.h e que o código pré-compilado reside em MYPCH.pch. Ele usa o conteúdo de MYPCH.pch e compila o restante do Prog para criar um arquivo. obj. A saída deste exemplo é um arquivo chamado PROG.exe.

```
CL /YuMYAPP.H /FpMYPCH.PCH PROG.CPP
```

## <a name="see-also"></a>Consulte também

[Opções do arquivo de saída (/F)](../../build/reference/output-file-f-options.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)