---
title: -DEF (especificar arquivo de definição de módulo) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCLinkerTool.ModuleDefinitionFile
- /def
dev_langs:
- C++
helpviewer_keywords:
- module definition files, specifying
- DEF linker option
- -DEF linker option
- module definition files
- /DEF linker option
ms.assetid: 6497fa68-65f0-48ca-8f66-b87166fc631a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0ec7458f5b81dd2b9d5aac49959b935f49377081
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45720378"
---
# <a name="def-specify-module-definition-file"></a>/DEF (especificar arquivo de definição do módulo)

```
/DEF:filename
```

## <a name="arguments"></a>Arguments

*filename*<br/>
O nome de um arquivo de definição de módulo (. def) a serem passados para o vinculador.

## <a name="remarks"></a>Comentários

A opção /DEF passa um arquivo de definição de módulo (. def) para o vinculador. Apenas um arquivo. def pode ser especificado para LINK. Para obter detalhes sobre os arquivos. def, consulte [arquivos de definição de módulo](../../build/reference/module-definition-dot-def-files.md).

### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).

1. Clique o **vinculador** pasta.

1. Clique o **entrada** página de propriedades.

1. Modificar a **arquivo de definição de módulo** propriedade.

Para especificar um arquivo. def de dentro do ambiente de desenvolvimento, você deve adicioná-lo ao projeto junto com outros arquivos e, em seguida, especifique o arquivo para a opção /DEF.

### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.ModuleDefinitionFile%2A>.

## <a name="see-also"></a>Consulte também

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)