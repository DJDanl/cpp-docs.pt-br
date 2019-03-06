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
ms.openlocfilehash: 71718aed7853e7d09b15734bad6a350f9a19fd5e
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57422826"
---
# <a name="za-ze-disable-language-extensions"></a>/Za, /Ze (desabilitar extensões de linguagem)

O **/Za** opção do compilador desabilita e emite erros para extensões da Microsoft para C que não são compatíveis com ANSI C89/ISO C90. Preteridas **/Ze** habilita a opção de compilador extensões da Microsoft. As extensões da Microsoft são ativadas por padrão.

## <a name="syntax"></a>Sintaxe

> **/Za**<br/>
> **/Ze**

## <a name="remarks"></a>Comentários

> [!NOTE]
> O uso de **/Za** quando o código é compilado como C++ não é recomendado. O **/Ze** opção é preterida porque seu comportamento é ativado por padrão. Para obter uma lista de opções do compilador preterido, consulte [opções de compilador removidos e preteridos](compiler-options-listed-by-category.md#deprecated-and-removed-compiler-options).

O compilador Microsoft C/C++ oferece suporte à compilação de código C de duas maneiras:

- O compilador usa o modo de compilação do C por padrão quando um arquivo de origem tem um *1).c* extensão, ou quando o [/Tc](tc-tp-tc-tp-specify-source-file-type.md) ou [/TC](tc-tp-tc-tp-specify-source-file-type.md) opção for especificada. O compilador de C é um compilador C89/C90 que, por padrão, permite que extensões da Microsoft para a linguagem C. Para obter mais informações sobre extensões específicas, consulte [Microsoft Extensions para C e C++](microsoft-extensions-to-c-and-cpp.md). Quando ambos os compilação do C e o **/Za** opção forem especificados, o compilador C estritamente compatível com o padrão de C89/C90. O compilador trata estendidas de palavras-chave como identificadores simples da Microsoft, desabilita as outras extensões da Microsoft e define automaticamente a [ \_ \_STDC\_ \_ ](../../preprocessor/predefined-macros.md) predefinidos macro para programas em C.

- O compilador pode compilar código C no modo de compilação do C++. Esse comportamento é o padrão para arquivos de origem que não têm uma *1).c* extensão e quando o [/Tp](tc-tp-tc-tp-specify-source-file-type.md) ou [/TP](tc-tp-tc-tp-specify-source-file-type.md) opção for especificada. No modo de compilação do C++, o compilador dá suporte a essas partes dos padrões ISO C99 e C11 que foram incorporados ao padrão C++. Quase todo o código C também é um código de C++ válido. Um pequeno número de palavras-chave C e construções de código não é o código de C++ válido ou é interpretado de forma diferente em C++. O compilador se comporta de acordo com o C++ padrão nesses casos. No modo de compilação do C++, o **/Za** opção pode causar um comportamento inesperado e não é recomendada.

Outras opções do compilador podem afetar como o compilador garante a conformidade com os padrões. Para obter maneiras especificar o padrão C e C++ comportamento configurações específicas, consulte a [/Zc](zc-conformance.md) opção de compilador. Para configurações adicionais de conformidade padrão do C++, consulte a [/permissive--](permissive-standards-conformance.md) e [/std](std-specify-language-standard-version.md) opções do compilador.

Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. No painel de navegação, escolha **propriedades de configuração** > **C/C++** > **idioma**.

1. Modificar a **desabilitar extensões de linguagem** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableLanguageExtensions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](compiler-options.md)<br/>
[Definindo opções do compilador](setting-compiler-options.md)<br/>
[/Zc (conformidade)](zc-conformance.md)<br/>
[/permissive- (conformidade com padrões)](permissive-standards-conformance.md)<br/>
[/std (especificar versão de idioma padrão)](std-specify-language-standard-version.md)<br/>
