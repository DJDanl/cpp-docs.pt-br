---
title: /Fx (mesclar código injetado)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLWCECompilerTool.ExpandAttributedSource
- /Fx
- VC.Project.VCCLCompilerTool.ExpandAttributedSource
helpviewer_keywords:
- Fx compiler option [C++]
- -Fx compiler option [C++]
- injected code
- merging injected code
- /Fx compiler option [C++]
ms.assetid: 14f0e301-3bab-45a3-bbdf-e7ce66f20560
ms.openlocfilehash: b928ca63171f0f6d28859d049a1ed5008b908686
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500096"
---
# <a name="fx-merge-injected-code"></a>/Fx (mesclar código injetado)

Produz uma cópia de cada arquivo de origem com o código injetado mesclado na origem.

## <a name="syntax"></a>Sintaxe

```
/Fx
```

## <a name="remarks"></a>Comentários

Para distinguir um arquivo de origem mesclado de um arquivo de origem original, o **/FX** adiciona uma extensão. mrg entre o nome do arquivo e a extensão do arquivo. Por exemplo, um arquivo chamado myCode. cpp contendo código atribuído e criado com **/FX** cria um arquivo chamado myCode. mrg. cpp que contém o código a seguir:

```
//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has
                               // already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping
                               // injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute
                               // providers
//--- End Injected Code
```

Em um arquivo. mrg, o código que foi injetado devido a um atributo será delimitado da seguinte maneira:

```
//+++ Start Injected Code
...
//--- End Injected Code
```

O atributo [no_injected_text](../../windows/attributes/no-injected-text.md) é inserido em um arquivo. mrg, que permite a compilação do arquivo. mrg sem que o texto seja reinjetado.

Você deve estar ciente de que o arquivo de origem. mrg se destina a ser uma representação do código-fonte injetado pelo compilador. O arquivo. mrg pode não compilar ou executar exatamente como o arquivo de origem original.

As macros não são expandidas no arquivo. mrg.

Se o seu programa incluir um arquivo de cabeçalho que usa código injetado, o **/FX** gerará um arquivo. mrg. h para esse cabeçalho. **/FX** não mescla arquivos de inclusão que não usam código injetado.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++** .

1. Clique na página de propriedades **arquivos de saída** .

1. Modifique a propriedade **expandir fonte atribuída** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.ExpandAttributedSource%2A>.

## <a name="see-also"></a>Consulte também

[Opções de arquivo de saída (/F)](output-file-f-options.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
