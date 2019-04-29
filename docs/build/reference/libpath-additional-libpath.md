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
ms.openlocfilehash: ab586c788825a854e7d3cb3760da6e4e5558de3a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62269198"
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

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **geral** página de propriedades.

1. Modificar a **diretórios de biblioteca adicionais** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.AdditionalLibraryDirectories%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções de vinculador MSVC](linker-options.md)
