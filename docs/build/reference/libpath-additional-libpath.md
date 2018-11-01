---
title: /LIBPATH (Libpath adicional)
ms.date: 11/04/2016
f1_keywords:
- /libpath
- VC.Project.VCLinkerTool.AdditionalLibraryDirectories
helpviewer_keywords:
- LIBPATH linker option
- /LIBPATH linker option
- Additional Libpath linker option
- environment library path override
- -LIBPATH linker option
- library path linker option
ms.assetid: 7240af0b-9a3d-4d53-8169-2a92cd6958ba
ms.openlocfilehash: 40662e77faf03de8e5ef0abf334f4ec7be69c3ad
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50615144"
---
# <a name="libpath-additional-libpath"></a>/LIBPATH (Libpath adicional)

```
/LIBPATH:dir
```

## <a name="parameters"></a>Parâmetros

*dir*<br/>
Especifica um caminho que o vinculador pesquisará antes de pesquisar o caminho especificado na opção de ambiente LIB.

## <a name="remarks"></a>Comentários

Use a opção /LIBPATH para substituir o caminho da biblioteca de ambiente. O vinculador pesquise primeiro no caminho especificado por essa opção e, em seguida, pesquise no caminho especificado na variável de ambiente LIB. Você pode especificar apenas um diretório para cada opção /LIBPATH que você inserir. Se você quiser especificar mais de um diretório, você deve especificar várias opções de /LIBPATH. O vinculador pesquisará as pastas especificadas na ordem.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **geral** página de propriedades.

1. Modificar a **diretórios de biblioteca adicionais** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalLibraryDirectories%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)