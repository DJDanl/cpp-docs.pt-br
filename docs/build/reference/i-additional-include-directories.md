---
title: /I (diretórios de inclusão adicionais)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLWCECompilerTool.AdditionalIncludeDirectories
- VC.Project.VCCLCompilerTool.AdditionalIncludeDirectories
- /I
- VC.Project.VCNMakeTool.IncludeSearchPath
helpviewer_keywords:
- /I compiler option [C++]
- Additional Include Directories compiler option
- I compiler option [C++]
- -I compiler option [C++]
- set include directories
- include directories, compiler option [C++]
ms.assetid: 3e9add2a-5ed8-4d15-ad79-5b411e313a49
ms.openlocfilehash: 6ec8b15e77fec5214013c484e617904ed29e8197
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57807631"
---
# <a name="i-additional-include-directories"></a>/I (diretórios de inclusão adicionais)

Adiciona um diretório à lista de diretórios procurados para os arquivos de inclusão.

## <a name="syntax"></a>Sintaxe

> **/I**[ ]*directory*

### <a name="arguments"></a>Arguments

*directory*<br/>
O diretório a ser adicionado à lista de diretórios pesquisados pelos arquivos de inclusão.

## <a name="remarks"></a>Comentários

Para adicionar mais de um diretório, use esta opção mais de uma vez. Diretórios são pesquisados até que o arquivo de inclusão especificado for encontrado.

Você pode usar essa opção com a ([/X (ignorar demarcadores de inclusão padrão)](x-ignore-standard-include-paths.md)) opção.

O compilador pesquisa diretórios na seguinte ordem:

1. Se for especificado usando um [# diretiva include](../../preprocessor/hash-include-directive-c-cpp.md) no formulário de aspas duplas, ele primeiro pesquisa diretórios locais. A pesquisa começará no mesmo diretório que o arquivo que contém o **#include** instrução. Se isso não consegue encontrar o arquivo, ele pesquisará em pastas de abertos atualmente incluem arquivos, na ordem inversa em que foram abertos. A pesquisa começará no diretório do arquivo de inclusão pai e continuará para cima até os diretórios de qualquer arquivo de inclusão avô.

1. Se especificado usando um **#include** formulário de colchete de diretiva em um ângulo, ou se a pesquisa de diretório local tiver falhado, procure nos diretórios especificados usando o **/I** opção, na ordem em que o CL encontrá-las na linha de comando.

1. Diretórios especificados na **INCLUDE** variável de ambiente.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **geral** página de propriedades.

1. Modificar a **diretórios de inclusão adicionais** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalIncludeDirectories%2A>.

## <a name="example"></a>Exemplo

O comando a seguir procura os arquivos de inclusão solicitados pelo Main. c na seguinte ordem: Em primeiro lugar, se especificado, usando aspas duplas, os arquivos locais serão pesquisados. Em seguida, a pesquisa continua no diretório \include. e, em seguida, no diretório \MY\INCLUDE e, por fim, nos diretórios atribuído à variável de ambiente INCLUDE.

```
CL /I \INCLUDE /I\MY\INCLUDE MAIN.C
```

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
