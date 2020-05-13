---
title: /FR, /Fr (criar arquivo .Sbr)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLWCECompilerTool.BrowseInformation
- VC.Project.VCCLCompilerTool.BrowseInformation
- /fr
- VC.Project.VCCLCompilerTool.BrowseInformationFile
- VC.Project.VCCLWCECompilerTool.BrowseInformationFile
helpviewer_keywords:
- /FR compiler option [C++]
- -FR compiler option [C++]
- FR compiler option [C++]
- symbolic browser information
ms.assetid: 3fd8f88b-3924-4feb-9393-287036a28896
ms.openlocfilehash: 58f55811f5d2bb81bc77da38a87c35bae91ce6cb
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320513"
---
# <a name="fr-fr-create-sbr-file"></a>/FR, /Fr (criar arquivo .Sbr)

Cria arquivos .sbr.

## <a name="syntax"></a>Sintaxe

```
/FR[pathname[\filename]]
/Fr[pathname[\filename]]
```

## <a name="remarks"></a>Comentários

> [!WARNING]
> Embora o BSCMAKE ainda esteja instalado no Visual Studio, ele não é mais usado pelo IDE. Desde o Visual Studio 2008, as informações de navegação e símbolo são armazenadas automaticamente em um arquivo SQL Server .sdf na pasta de solução.

Durante o processo de compilação, o Microsoft Browse Information File Maintenance Utility (BSCMAKE) usa esses arquivos para criar um . Arquivo BSC, que é usado para exibir informações de navegação.

**/FR** cria um arquivo .sbr com informações simbólicas completas.

**/Fr** cria um arquivo .sbr sem informações sobre variáveis locais.

Se você não `filename`especificar, o arquivo .sbr recebe o mesmo nome base do arquivo de origem.

**/Fr** é preterido; em vez **disso, use /FR.** Para obter mais informações, consulte Opções de compilador depreciado e removido em [opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

> [!NOTE]
> Não altere a extensão .sbr. O BSCMAKE requer que os arquivos intermediários tenham essa extensão.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. No painel de navegação, escolha a página **c/c++**, **procurar informações.**

1. Modifique o **arquivo de informações de navegação** ou a propriedade Ativar informações **de** navegação.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Veja <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BrowseInformation%2A> e <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BrowseInformationFile%2A>.

## <a name="see-also"></a>Confira também

[Opções de arquivo de saída (/f)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
