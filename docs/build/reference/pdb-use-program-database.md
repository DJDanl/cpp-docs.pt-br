---
title: -PDB (Usar banco de dados de programa) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /pdb
- VC.Project.VCLinkerTool.ProgramDatabaseFile
dev_langs:
- C++
helpviewer_keywords:
- -PDB linker option
- /PDB linker option
- PDB linker option
- PDB files, creating
- .pdb files, creating
ms.assetid: d23db0ce-10cb-427a-bc60-d6b2a852723d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8717be9ee8f754f4e61dbed0211360a0b4f4f780
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45717219"
---
# <a name="pdb-use-program-database"></a>/PDB (usar banco de dados do programa)

```
/PDB:filename
```

## <a name="arguments"></a>Arguments

*filename*<br/>
Um nome especificado pelo usuário para o banco de dados do programa (PDB) que o vinculador cria. Ele substitui o nome padrão.

## <a name="remarks"></a>Comentários

Por padrão, quando [/Debug](../../build/reference/debug-generate-debug-info.md) for especificado, o vinculador cria um banco de dados do programa (PDB) que contém informações de depuração. O nome de arquivo padrão para o PDB tem o nome base do programa e a extensão. PDB.

Use /PDB:*filename* para especificar o nome do arquivo PDB. Se a opção /DEBUG não for especificado, a opção /PDB é ignorada.

Um arquivo PDB pode ser de até 2GB.

Para obter mais informações, consulte [arquivos. PDB como entrada de vinculador](../../build/reference/dot-pdb-files-as-linker-input.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **depurar** página de propriedades.

1. Modificar a **gerar arquivo de banco de dados do programa** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ProgramDatabaseFile%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)