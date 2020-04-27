---
title: /UTF-8 (definir conjuntos de caracteres de origem e UTF-8executáveis como)
ms.date: 04/26/2020
f1_keywords:
- /utf-8
helpviewer_keywords:
- /utf-8 compiler option
ms.assetid: f0e1f3cb-6cae-46eb-9483-04ed13d9b504
no-loc:
- UTF
- UTF-8
- UTF-16
ms.openlocfilehash: c98a30b0ec4b36b8bd87fb0956d9382751975cfd
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82168859"
---
# <a name="utf-8-set-source-and-executable-character-sets-to-opno-locutf-8"></a>`/utf-8`(Defina conjuntos de caracteres de origem e UTF-8executáveis como)

Especifica o conjunto de caracteres de origem e o conjunto de caracteres UTF-8de execução como.

## <a name="syntax"></a>Sintaxe

> **`/utf-8`**

## <a name="remarks"></a>Comentários

Você pode usar a **`/utf-8`** opção para especificar os conjuntos de caracteres de origem e de execução como codificados usando UTF-8o. É equivalente a especificar **`/source-charset:utf-8 /execution-charset:utf-8`** na linha de comando. Qualquer uma dessas opções também habilita a **`/validate-charset`** opção por padrão. Para obter uma lista de identificadores de página de código com suporte e nomes de conjuntos de caracteres, consulte [identificadores de página de código](/windows/win32/Intl/code-page-identifiers).

Por padrão, o Visual Studio detecta uma marca de ordem de byte para determinar se o arquivo de origem está em um formato Unicode codificado, UTF-16 por UTF-8exemplo, ou. Se nenhuma marca de ordem de byte for encontrada, ela assumirá que o arquivo de origem está codificado usando a página de código do usuário atual, a menos que **`/utf-8`** você tenha **`/source-charset`** especificado uma página de código usando ou a opção. O Visual Studio permite que você salve seu código-fonte C++ usando qualquer uma das várias codificações de caracteres. Para obter informações sobre conjuntos de caracteres de origem e de execução, consulte [conjuntos de caracteres](../../cpp/character-sets.md) na documentação do idioma.

## <a name="set-the-option-in-visual-studio-or-programmatically"></a>Definir a opção no Visual Studio ou programaticamente

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedade de**linha de comando** **C/C++** >  **Propriedades** > de configuração.

1. Em **Opções adicionais**, adicione a **`/utf-8`** opção para especificar sua codificação preferida.

1. Escolha **OK** para salvar suas alterações.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Execution-charset (definir conjunto de caracteres de execução)](execution-charset-set-execution-character-set.md)<br/>
[/Source-charset (definir conjunto de caracteres de origem)](source-charset-set-source-character-set.md)<br/>
[/Validate-charset (validar para caracteres compatíveis)](validate-charset-validate-for-compatible-characters.md)
