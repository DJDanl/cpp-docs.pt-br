---
title: /MANIFESTFILE (nomear arquivo de manifesto)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.ManifestFile
helpviewer_keywords:
- MANIFESTFILE linker option
- -MANIFESTFILE linker option
- /MANIFESTFILE linker option
ms.assetid: befa5ab2-a9cf-4c9b-969a-e7b4a930f08d
ms.openlocfilehash: e75c6d8171aae22312ba6aaa2d4304d831ec6d0f
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57813832"
---
# <a name="manifestfile-name-manifest-file"></a>/MANIFESTFILE (nomear arquivo de manifesto)

```
/MANIFESTFILE:filename
```

## <a name="remarks"></a>Comentários

/MANIFESTFILE permite alterar o nome padrão do arquivo de manifesto.  O nome padrão do arquivo de manifesto é o nome do arquivo. manifest junto.

/MANIFESTFILE não terá efeito se você também vincular [/manifest](manifest-create-side-by-side-assembly-manifest.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Expanda o nó **Propriedades de Configuração**.

1. Expanda o **vinculador** nó.

1. Selecione o **o arquivo de manifesto** página de propriedades.

1. Modificar a **o arquivo de manifesto** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ManifestFile%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
