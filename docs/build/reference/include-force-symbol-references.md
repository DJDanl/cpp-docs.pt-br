---
title: /INCLUDE (forçar referências de símbolo)
ms.date: 11/04/2016
f1_keywords:
- /include
- VC.Project.VCLinkerTool.ForceSymbolReferences
helpviewer_keywords:
- INCLUDE linker option
- force symbol references linker option
- symbol references linker force
- /INCLUDE linker option
- symbols, add to symbol table
- -INCLUDE linker option
ms.assetid: 4a039677-360a-480f-bd0b-448e239b449c
ms.openlocfilehash: 389bd16829c2466b02cb879c8bc8d43c9efa6fb4
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57421214"
---
# <a name="include-force-symbol-references"></a>/INCLUDE (forçar referências de símbolo)

```
/INCLUDE:symbol
```

## <a name="parameters"></a>Parâmetros

*symbol*<br/>
Especifica um símbolo a ser adicionado à tabela de símbolos.

## <a name="remarks"></a>Comentários

A opção /INCLUDE informa o vinculador para adicionar um símbolo especificado à tabela de símbolos.

Para especificar vários símbolos, digite uma vírgula (,), um ponto e vírgula (;) ou um espaço entre os nomes de símbolos. Na linha de comando, especifique /INCLUDE:`symbol` uma vez para cada símbolo.

O vinculador resolve `symbol` adicionando o objeto que contém a definição do símbolo para o programa. Esse recurso é útil para incluir um objeto de biblioteca, caso contrário, não seria possível vincular ao programa.

Especificar um símbolo com essa opção substitui a remoção desse símbolo por [/OPT: REF](../../build/reference/opt-optimizations.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **entrada** página de propriedades.

1. Modificar a **forçar referências de símbolo** propriedade.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ForceSymbolReferences%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)
