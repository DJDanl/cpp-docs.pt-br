---
title: /MAP (gerar mapfile)
ms.date: 11/04/2016
f1_keywords:
- /map
- VC.Project.VCLinkerTool.MapFileName
- VC.Project.VCLinkerTool.GenerateMapFile
helpviewer_keywords:
- mapfiles, creating linker
- generate mapfile linker option
- mapfile linker option
- mapfiles, information about program being linked
- MAP linker option
- -MAP linker option
- mapfiles, specifying file name
- /MAP linker option
ms.assetid: 9ccce53d-4e36-43da-87b0-7603ddfdea63
ms.openlocfilehash: 8ff2a8f54caa54247050c607004ed328c0d1b11d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50436448"
---
# <a name="map-generate-mapfile"></a>/MAP (gerar mapfile)

```
/MAP[:filename]
```

## <a name="arguments"></a>Arguments

*filename*<br/>
Um nome especificado pelo usuário para o arquivo de mapa. Ele substitui o nome padrão.

## <a name="remarks"></a>Comentários

A opção /MAP informa o vinculador para criar um arquivo de mapa.

Por padrão, o vinculador nomeia o arquivo de mapa com o nome base do programa e o. map extensão. Opcional *filename* permite que você substitua o nome padrão para um arquivo de mapa.

Um arquivo de mapa é um arquivo de texto que contém as seguintes informações sobre o programa que está sendo vinculado:

- O nome do módulo, que é o nome base do arquivo

- O carimbo de hora no cabeçalho do arquivo de programa (e não do sistema de arquivos)

- Uma lista de grupos no programa, com o endereço de início de cada grupo (como *seção*:*deslocamento*), comprimento, o nome de grupo e a classe

- Uma lista de símbolos públicos, com cada endereço (como *seção*:*deslocamento*), nome, endereço simples e arquivo. obj em que o símbolo é definido de símbolo

- O ponto de entrada (como *seção*:*deslocamento*)

O [/MAPINFO](../../build/reference/mapinfo-include-information-in-mapfile.md) opção especifica informações adicionais a serem incluídos no arquivo de mapa.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **depurar** página de propriedades.

1. Modificar a **gerar arquivo de mapa** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateMapFile%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MapFileName%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)