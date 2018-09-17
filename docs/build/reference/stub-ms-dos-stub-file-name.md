---
title: -STUB (nome de arquivo de Stub do MS-DOS) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /stub
- VC.Project.VCLinkerTool.DosStub
dev_langs:
- C++
helpviewer_keywords:
- Win32 [C++], attaching MS-DOS stub program
- STUB linker option
- MS-DOS stub file name linker option
- /STUB linker option
- Windows API [C++], attaching MS-DOS stub program
- -STUB linker option
ms.assetid: 65221ffe-4f9a-4a14-ac69-3cfb79b40b5f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0c279d6f33befb4c308afe0c92b7dcca3d45ba66
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45707714"
---
# <a name="stub-ms-dos-stub-file-name"></a>/STUB (nome de arquivo stub do MS-DOS)

```
/STUB:filename
```

## <a name="arguments"></a>Arguments

*filename*<br/>
Um aplicativo do MS-DOS.

## <a name="remarks"></a>Comentários

A opção /STUB anexa um programa stub MS-DOS a um programa Win32.

Um programa stub é invocado se o arquivo é executado no MS-DOS. Ele normalmente exibe uma mensagem apropriada; No entanto, qualquer aplicativo MS-DOS válido pode ser um programa stub.

Especifique um *filename* para o programa stub após dois-pontos (:) na linha de comando. As verificações de vinculador *filename* e emite uma mensagem de erro se o arquivo não é um executável. O programa deve ser um arquivo de .exe; um arquivo. com é inválido para um programa stub.

Se essa opção não for usada, o vinculador anexa um programa stub padrão que emite a seguinte mensagem:

```
This program cannot be run in MS-DOS mode.
```

Ao criar um driver de dispositivo virtual *filename* permite que o usuário especifique um nome de arquivo que contém uma estrutura IMAGE_DOS_HEADER (definida em WINNT. H) a ser usado no VXD, em vez do cabeçalho padrão.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **linha de comando** página de propriedades.

1. Digite a opção para o **opções adicionais** caixa.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)