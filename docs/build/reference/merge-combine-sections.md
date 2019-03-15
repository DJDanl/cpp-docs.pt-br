---
title: /MERGE (combinar seções)
ms.date: 11/04/2016
f1_keywords:
- /merge
- VC.Project.VCLinkerTool.MergeSections
helpviewer_keywords:
- sections, combining
- /MERGE linker option
- sections, naming
- sections
- -MERGE linker option
- MERGE linker option
ms.assetid: 10fb20c2-0b3f-4c8d-98a8-f69aedf03d52
ms.openlocfilehash: f0e770425f8068b15522f405ffdcf7cf52999fe0
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57820124"
---
# <a name="merge-combine-sections"></a>/MERGE (combinar seções)

```
/MERGE:from=to
```

## <a name="remarks"></a>Comentários

A opção /MERGE combina a primeira seção (*partir*) com a segunda seção (*à*), nomeando a seção resultante *para*. Por exemplo, `/merge:.rdata=.text`.

Se a segunda seção não existir, o LINK renomeia a seção *partir* como *para*.

A opção /MERGE é útil para criar VxDs e substituindo os nomes de seção gerado pelo compilador.

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **avançado** página de propriedades.

1. Modificar a **mesclar seções** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

1. Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.MergeSections%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
