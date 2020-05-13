---
title: /Za, /Ze (desabilitar extensões de linguagem)
ms.date: 02/19/2019
f1_keywords:
- VC.Project.VCCLWCECompilerTool.DisableLanguageExtensions
- /za
- /ze
- VC.Project.VCCLCompilerTool.DisableLanguageExtensions
helpviewer_keywords:
- -Za compiler option [C++]
- Za compiler option [C++]
- language extensions, disabling in compiler
- -Ze compiler option [C++]
- language extensions
- enable language extensions
- /Za compiler option [C++]
- /Ze compiler option [C++]
- Disable Language Extensions compiler option
- Ze compiler option [C++]
ms.assetid: 65e49258-7161-4289-a176-7c5c0656b1a2
ms.openlocfilehash: 9a2584591f6ca22d6767a5c447ffb72bea0a78ea
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825869"
---
# <a name="za-ze-disable-language-extensions"></a>/Za, /Ze (desabilitar extensões de linguagem)

A opção de compilador **/za** desabilita e emite erros para extensões da Microsoft para C que não são compatíveis com C90 C89/ISO ANSI. A opção de compilador **/ze** preterida habilita extensões da Microsoft. As extensões da Microsoft são ativadas por padrão.

## <a name="syntax"></a>Sintaxe

> **/Za**\
> **/Ze**

## <a name="remarks"></a>Comentários

> [!NOTE]
> O uso de **/za** quando o código é compilado como C++ não é recomendado. A opção **/ze** foi preterida porque seu comportamento está ativado por padrão. Para obter uma lista de opções de compilador preteridas, consulte [Opções de compilador preteridas e removidas](compiler-options-listed-by-category.md#deprecated-and-removed-compiler-options).

O compilador C/C++ da Microsoft oferece suporte à compilação de código C de duas maneiras:

- O compilador usa o modo de compilação C por padrão quando um arquivo de origem tem uma extensão *. C* ou quando a opção [/TC](tc-tp-tc-tp-specify-source-file-type.md) ou [/TC](tc-tp-tc-tp-specify-source-file-type.md) é especificada. O compilador C é um compilador C89/C90 que, por padrão, habilita extensões da Microsoft para a linguagem C. Para obter mais informações sobre extensões específicas, consulte [extensões da Microsoft para C e C++](microsoft-extensions-to-c-and-cpp.md). Quando a compilação C e a opção **/za** são especificadas, o compilador c está em conformidade estritamente com o padrão C89/C90. O compilador trata as palavras-chave estendidas da Microsoft como identificadores simples, desabilita as outras extensões da Microsoft e define automaticamente [ \_ \_a\_ ](../../preprocessor/predefined-macros.md) macro predefinida stdc para programas C.

- O compilador pode compilar código C no modo de compilação C++. Esse comportamento é o padrão para arquivos de origem que não têm uma extensão *. c* e quando a opção [/TP](tc-tp-tc-tp-specify-source-file-type.md) ou [/TP](tc-tp-tc-tp-specify-source-file-type.md) é especificada. No modo de compilação C++, o compilador dá suporte a essas partes dos padrões ISO C99 e C11 que foram incorporados ao padrão C++. Quase todo o código C também é um código C++ válido. Um número pequeno de palavras-chave C e construções de código não é um código C++ válido ou é interpretado de modo diferente em C++. O compilador se comporta de acordo com o padrão C++ nesses casos. No modo de compilação C++, a opção **/za** pode causar um comportamento inesperado e não é recomendada.

Outras opções de compilador podem afetar como o compilador garante a conformidade com os padrões. Para obter maneiras de especificar configurações de comportamento padrão de C e C++, consulte a opção de compilador [/Zc](zc-conformance.md) . Para configurações adicionais de conformidade do C++ Standard, consulte as opções do compilador [/permissive-](permissive-standards-conformance.md) e [/std](std-specify-language-standard-version.md) .

Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. No painel de navegação, escolha **Propriedades** > de configuração**linguagem****C/C++** > .

1. Modifique a propriedade **desabilitar extensões de linguagem** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableLanguageExtensions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador](compiler-options.md)<br/>
[/Zc (conformidade)](zc-conformance.md)<br/>
[/permissive-(conformidade com os padrões)](permissive-standards-conformance.md)<br/>
[/STD (especifique a versão padrão do idioma)](std-specify-language-standard-version.md)<br/>
