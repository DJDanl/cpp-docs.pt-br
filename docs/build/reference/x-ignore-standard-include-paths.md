---
title: /X (ignorar caminhos de inclusão padrão)
ms.date: 07/18/2019
f1_keywords:
- /x
- VC.Project.VCCLCompilerTool.OVERWRITEStandardIncludePath
- VC.Project.VCCLWCECompilerTool.OVERWRITEStandardIncludePath
- VC.Project.VCCLCompilerTool.IgnoreStandardIncludePath
helpviewer_keywords:
- /X compiler option [C++]
- include files, ignore standard path
- -X compiler option [C++]
- include directories, ignore standard
- X compiler option
- Ignore Standard Include Paths compiler option
ms.assetid: 16bdf2cc-c8dc-46e4-bdcc-f3caeba5e1ef
ms.openlocfilehash: 16f903b98d69472fe1a33b084fe6393ecf9ec001
ms.sourcegitcommit: 0867d648e0955ebad7260b5fbebfd6cd4d58f3c7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/19/2019
ms.locfileid: "68341042"
---
# <a name="x-ignore-standard-include-paths"></a>/X (ignorar caminhos de inclusão padrão)

Impede que o compilador procure arquivos de inclusão em diretórios especificados no caminho e inclua variáveis de ambiente.

## <a name="syntax"></a>Sintaxe

```
/X
```

## <a name="remarks"></a>Comentários

Você pode usar essa opção com a opção [/i (diretórios de inclusão adicionais)](i-additional-include-directories.md) ( **/i**`directory`).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **CC++ /** .

1. Clique na página de propriedades do **pré-processador** .

1. Modifique a propriedade **Ignorar caminho de inclusão padrão** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.IgnoreStandardIncludePath%2A>.

## <a name="example"></a>Exemplo

No comando a seguir, `/X` diz ao compilador para ignorar os locais especificados pelo caminho e incluir as variáveis `/I` de ambiente e especifica o diretório no qual procurar por arquivos de inclusão:

```
CL /X /I \ALT\INCLUDE MAIN.C
```

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
