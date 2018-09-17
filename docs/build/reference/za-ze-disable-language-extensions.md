---
title: -Za, - Ze (desabilitar extensões de linguagem) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLWCECompilerTool.DisableLanguageExtensions
- /za
- /ze
- VC.Project.VCCLCompilerTool.DisableLanguageExtensions
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4d239b6153a2fc725c2add3eddb5fbaace406469
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45712810"
---
# <a name="za-ze-disable-language-extensions"></a>/Za, /Ze (desabilitar extensões de linguagem)

O **/Za** opção de compilador emite um erro para construções de linguagem que não são compatíveis com ANSI C89 ou ISO c++11. O **/Ze** opção de compilador, que é ativado por padrão, permite que extensões da Microsoft.

## <a name="syntax"></a>Sintaxe

```
/Za
/Ze
```

## <a name="remarks"></a>Comentários

> [!NOTE]
>  O **/Ze** opção é preterida porque seu comportamento é ativado por padrão. É recomendável usar o [/Zc (conformidade)](../../build/reference/zc-conformance.md) opções do compilador para controlar os recursos de extensão de idioma específico. Para obter uma lista de opções do compilador preterido, consulte o **preteridos e removidos opções do compilador** seção [opções de compilador listadas por categoria](../../build/reference/compiler-options-listed-by-category.md).

O compilador do Visual C++ oferece vários recursos além dos determinados padrões ANSI C89, ISO C99 ou ISO C++. Esses recursos são conhecidos coletivamente como extensões da Microsoft para C e C++. Essas extensões estão disponíveis por padrão e não está disponível quando o **/Za** opção for especificada. Para obter mais informações sobre extensões específicas, consulte [Microsoft Extensions para C e C++](../../build/reference/microsoft-extensions-to-c-and-cpp.md).

Recomendamos que você desabilite extensões de linguagem, especificando o **/Za** opção se você planeja transferir seu programa em outros ambientes. Quando **/Za** for especificado, o compilador trata estendidas de palavras-chave como identificadores simples da Microsoft, desabilita as outras extensões da Microsoft e define automaticamente o `__STDC__` macro predefinida para programas em C.

Usado com outras opções do compilador **/Za** podem afetar como o compilador garante a conformidade com os padrões.

Para obter maneiras especificar as configurações de comportamento específico do compatível com padrões, consulte o [/Zc](../../build/reference/zc-conformance.md) opção de compilador.

Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. No painel de navegação, escolha **propriedades de configuração**, **C/C++**, **idioma**.

1. Modificar a **desabilitar extensões de linguagem** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DisableLanguageExtensions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/Zc (conformidade)](../../build/reference/zc-conformance.md)
