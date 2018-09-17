---
title: -showIncludes (lista incluir arquivos) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLWCECompilerTool.ShowIncludes
- VC.Project.VCCLCompilerTool.ShowIncludes
- /showincludes
dev_langs:
- C++
helpviewer_keywords:
- include files
- /showIncludes compiler option [C++]
- include files, displaying in compilation
- -showIncludes compiler option [C++]
- showIncludes compiler option [C++]
ms.assetid: 0b74b052-f594-45a6-a7c7-09e1a319547d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 51305212f97482c6963ee2ba0d272c5c4692416e
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45709377"
---
# <a name="showincludes-list-include-files"></a>/showIncludes (listar arquivos de inclusão)

Faz com que o compilador a gerar uma lista dos arquivos de inclusão. Aninhado incluem arquivos também são exibidos (arquivos que são incluídos dos arquivos que você incluir).

## <a name="syntax"></a>Sintaxe

```
/showIncludes
```

## <a name="remarks"></a>Comentários

Quando um arquivo de inclusão é encontrado durante a compilação, uma mensagem é saída, por exemplo:

```
Note: including file: d:\MyDir\include\stdio.h
```

Aninhado incluem arquivos são indicados por um recuo, um espaço para cada nível de aninhamento, por exemplo:

```
Note: including file: d:\temp\1.h
Note: including file:  d:\temp\2.h
```

Nesse caso, `2.h` tiver sido incluído de dentro do `1.h`, portanto, o recuo.

O **/showIncludes** opção emite para `stderr`, e não `stdout`.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **Mostrar inclusões** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ShowIncludes%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)