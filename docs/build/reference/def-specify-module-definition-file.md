---
title: /DEF (especificar arquivo de definição do módulo)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCLinkerTool.ModuleDefinitionFile
- /def
helpviewer_keywords:
- module definition files, specifying
- DEF linker option
- -DEF linker option
- module definition files
- /DEF linker option
ms.assetid: 6497fa68-65f0-48ca-8f66-b87166fc631a
ms.openlocfilehash: c08412fb50835485e7941b2bb1db088943387b71
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57807436"
---
# <a name="def-specify-module-definition-file"></a>/DEF (especificar arquivo de definição do módulo)

```
/DEF:filename
```

## <a name="arguments"></a>Arguments

*filename*<br/>
O nome de um arquivo de definição de módulo (. def) a serem passados para o vinculador.

## <a name="remarks"></a>Comentários

A opção /DEF passa um arquivo de definição de módulo (. def) para o vinculador. Apenas um arquivo. def pode ser especificado para LINK. Para obter detalhes sobre os arquivos. def, consulte [arquivos de definição de módulo](module-definition-dot-def-files.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **entrada** página de propriedades.

1. Modificar a **arquivo de definição de módulo** propriedade.

Para especificar um arquivo. def de dentro do ambiente de desenvolvimento, você deve adicioná-lo ao projeto junto com outros arquivos e, em seguida, especifique o arquivo para a opção /DEF.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ModuleDefinitionFile%2A>.

## <a name="see-also"></a>Consulte também

[Referência de vinculador MSVC](linking.md)<br/>
[Opções do vinculador MSVC](linker-options.md)
