---
title: /X (ignorar caminhos de inclusão padrão)
ms.date: 11/04/2016
f1_keywords:
- /x
- VC.Project.VCCLCompilerTool.OVERWRITEStandardIncludePath
- VC.Project.VCCLWCECompilerTool.OVERWRITEStandardIncludePath
helpviewer_keywords:
- /X compiler option [C++]
- include files, ignore standard path
- -X compiler option [C++]
- include directories, ignore standard
- X compiler option
- Ignore Standard Include Paths compiler option
ms.assetid: 16bdf2cc-c8dc-46e4-bdcc-f3caeba5e1ef
ms.openlocfilehash: dba7e49880307002a3dee983264e93666adfef17
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57818395"
---
# <a name="x-ignore-standard-include-paths"></a>/X (ignorar caminhos de inclusão padrão)

Impede que o compilador procurar pelos arquivos de inclusão em diretórios especificados nas variáveis de ambiente PATH e INCLUDE.

## <a name="syntax"></a>Sintaxe

```
/X
```

## <a name="remarks"></a>Comentários

Você pode usar essa opção com o [/I (diretórios de inclusão adicionais)](i-additional-include-directories.md) (**/I**`directory`) opção.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **pré-processador** página de propriedades.

1. Modificar a **ignorar caminho de inclusão padrão** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.IgnoreStandardIncludePath%2A>.

## <a name="example"></a>Exemplo

No comando a seguir `/X` informa ao compilador para ignorar os locais especificados pelas variáveis de ambiente PATH e INCLUDE, e `/I` Especifica o diretório no qual procurar arquivos de inclusão:

```
CL /X /I \ALT\INCLUDE MAIN.C
```

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
