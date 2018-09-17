---
title: -FR, -Fr (criar. Arquivo SBR) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLWCECompilerTool.BrowseInformation
- VC.Project.VCCLCompilerTool.BrowseInformation
- /fr
- VC.Project.VCCLCompilerTool.BrowseInformationFile
- VC.Project.VCCLWCECompilerTool.BrowseInformationFile
dev_langs:
- C++
helpviewer_keywords:
- /FR compiler option [C++]
- -FR compiler option [C++]
- FR compiler option [C++]
- symbolic browser information
ms.assetid: 3fd8f88b-3924-4feb-9393-287036a28896
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a5691a87f7350c7816e8ddb58d5591e16cc18189
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45709582"
---
# <a name="fr-fr-create-sbr-file"></a>/FR, /Fr (criar arquivo .Sbr)

Cria arquivos. SBR.

## <a name="syntax"></a>Sintaxe

```
/FR[pathname[\filename]]
/Fr[pathname[\filename]]
```

## <a name="remarks"></a>Comentários

Durante o processo de compilação, a Microsoft procurar informações de arquivo manutenção Utility (BSCMAKE) usa esses arquivos para criar um. Arquivo BSC, que é usado para exibir informações de procura.

**/FR** cria um arquivo. SBR com informações simbólicas completas.

**/FR** cria um arquivo. SBR sem informações em variáveis locais.

Se você não especificar `filename`, o arquivo. SBR obtém o mesmo nome base que o arquivo de origem.

**/FR** foi preterida; use **/FR** em vez disso. Para obter mais informações, consulte preterido e opções do compilador removido no [opções de compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).

> [!NOTE]
>  Não altere a extensão. SBR. BSCMAKE requer os arquivos intermediários para ter essa extensão.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. No painel de navegação, escolha o **C/C++**, **procurar informações** página de propriedades.

1. Modificar a **procure o arquivo de informações** ou **permitem procurar informações** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BrowseInformation%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BrowseInformationFile%2A>.

## <a name="see-also"></a>Consulte também

[Arquivo de saída (/ F) opções](../../build/reference/output-file-f-options.md)
[opções do compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[Especificando o nome de caminho](../../build/reference/specifying-the-pathname.md)