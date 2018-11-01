---
title: /OUT (nome do arquivo de saída)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.OutputFile
- /out
helpviewer_keywords:
- output files, name linker option
- -OUT linker option
- OUT linker option
- /OUT C++ linker option
- linker [C++], output files
ms.assetid: 976210a4-e51f-4cfb-af5e-c16344455834
ms.openlocfilehash: f5ba323b830b9d06956d88d957206e3f73c15418
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50497163"
---
# <a name="out-output-file-name"></a>/OUT (nome do arquivo de saída)

```
/OUT:filename
```

## <a name="arguments"></a>Arguments

*filename*<br/>
Um nome especificado pelo usuário para o arquivo de saída. Ele substitui o nome padrão.

## <a name="remarks"></a>Comentários

A opção /out sobrescreve substitui o nome padrão e o local do programa que o vinculador cria.

Por padrão, o vinculador forma o nome do arquivo usando o nome base do primeiro arquivo. obj especificado e a extensão apropriada (.exe ou. dll).

Essa opção o nome de base padrão para uma biblioteca .mapfile ou importação. Para obter detalhes, consulte [Gerar Mapfile](../../build/reference/map-generate-mapfile.md) (/Map) e [/IMPLIB](../../build/reference/implib-name-import-library.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **geral** página de propriedades.

1. Modificar a **arquivo de saída** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.OutputFile%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)