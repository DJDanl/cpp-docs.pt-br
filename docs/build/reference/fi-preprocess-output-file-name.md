---
title: /Fi (pré-processar nome do arquivo de saída)
ms.date: 08/12/2020
f1_keywords:
- /Fi
helpviewer_keywords:
- Fi compiler option (C++)
- -Fi compiler option (C++)
- /Fi compiler option (C++)
- preprocessing output files, file name
ms.assetid: 6d0ba983-a8b7-41ec-84f5-b4688ef8efee
ms.openlocfilehash: 82bf09a8f01f656f90ad9971530b05f108fc95a4
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88561083"
---
# <a name="fi-preprocess-output-file-name"></a>`/Fi` (Pré-processar o nome do arquivo de saída)

Especifica o nome do arquivo de saída no qual a opção de compilador [ `/P` (pré-processar para um arquivo)](p-preprocess-to-a-file.md) grava a saída pré-processada.

## <a name="syntax"></a>Sintaxe

> **`/Fi`**_`pathname`_

### <a name="parameters"></a>Parâmetros

*`pathname`*\
O caminho relativo ou absoluto e o nome do arquivo de saída produzido pela **`/P`** opção do compilador. Ou o caminho do diretório para os *`.i`* arquivos de saída quando mais de um arquivo de entrada é especificado. Não coloque um espaço entre a **`/Fi`** opção e *`pathname`* .

## <a name="remarks"></a>Comentários

Use a **`/Fi`** opção do compilador em combinação com a **`/P`** opção do compilador. Se **`/P`** não for especificado, **`/Fi`** causará o aviso de linha de comando D9007.

Se você especificar apenas um caminho de diretório (um caminho que termina em uma barra invertida **`\`** ) para o *`pathname`* parâmetro, o nome base do arquivo de origem será usado como o nome base do arquivo de saída pré-processado. O *`pathname`* parâmetro não requer uma extensão de nome de arquivo específica. No entanto, uma extensão ". i" será usada se você não especificar uma extensão de nome de arquivo.

### <a name="example"></a>Exemplo

A linha de comando a seguir processa *`PROGRAM.cpp`* , preserva comentários, adiciona [`#line`](../../preprocessor/hash-line-directive-c-cpp.md) diretivas e grava o resultado no *`MYPROCESS.i`* arquivo:

```cmd
CL /P /FiMYPROCESS.I PROGRAM.CPP
```

Essa linha de comando processa *`main.cpp`* e em *`helper.cpp`* *`main.i`* *`helper.i`* um subdiretório chamado *`preprocessed`* :

```cmd
CL /P /Fi".\\preprocessed\\" main.cpp helper.cpp
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra o arquivo de origem ou a caixa de diálogo **páginas de propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **configuração**do pré-processador do  >  **C/C++**  >  **Preprocessor** .

1. Defina o **pré-processamento para uma** propriedade de arquivo como **Sim**.

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Insira a **`/Fi`** opção do compilador e *`pathname`* na caixa **Opções adicionais** . Especifique apenas um caminho de diretório, não um nome de arquivo, ao definir essa propriedade para um projeto.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[`/P` (Pré-processar para um arquivo)](p-preprocess-to-a-file.md)<br/>
[Especificando o nome de caminho](specifying-the-pathname.md)
