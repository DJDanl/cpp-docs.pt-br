---
title: -INCLUDE (forçar referências de símbolo) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /include
- VC.Project.VCLinkerTool.ForceSymbolReferences
dev_langs:
- C++
helpviewer_keywords:
- INCLUDE linker option
- force symbol references linker option
- symbol references linker force
- /INCLUDE linker option
- symbols, add to symbol table
- -INCLUDE linker option
ms.assetid: 4a039677-360a-480f-bd0b-448e239b449c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6528f6edc51a2dd01e8f91107827b570a44785de
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45715774"
---
# <a name="include-force-symbol-references"></a>/INCLUDE (forçar referências de símbolo)

```
/INCLUDE:symbol
```

## <a name="parameters"></a>Parâmetros

*Símbolo*<br/>
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