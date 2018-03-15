---
title: "/ZC: (wchar_t é do tipo nativo) | Microsoft Docs"
ms.custom: 
ms.date: 03/01/2018
ms.technology:
- cpp-tools
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.TreatWChar_tAsBuiltInType
- VC.Project.VCCLCompilerTool.TreatWChar_tAsBuiltInType
- /Zc:wchar_t
dev_langs:
- C++
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- wchar_t type
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: b0de5a84-da72-4e5a-9a4e-541099f939e0
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d4970e4aba8bf2d6aebf60f876a4770b18943781
ms.sourcegitcommit: eeb2b5ad8d3d22514a7b9bd7d756511b69ae0ccf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2018
---
# <a name="zcwchart-wchart-is-native-type"></a>/Zc:wchar_t (wchar_t é do tipo nativo)

Analise `wchar_t` como um tipo interno de acordo com o padrão C++.

## <a name="syntax"></a>Sintaxe

> **/Zc:wchar_t**[**-**]

## <a name="remarks"></a>Comentários

Se **/ZC:** está ativada, `wchar_t` é uma palavra-chave para um tipo integral interna no código compilado como C++. Se **/Zc:wchar_t-** (com um sinal de subtração) é especificado, ou em código compilado como C, `wchar_t` não é um tipo interno. Em vez disso, `wchar_t` é definido como um `typedef` para `unsigned short` no stddef.h cabeçalho canônico. (A implementação da Microsoft define-lo em outro cabeçalho incluído por stddef.h e outros cabeçalhos padrão.)

Não é recomendável **/Zc:wchar_t-** porque o padrão C++ requer que `wchar_t` ser um tipo interno. Usar a versão `typedef` pode causar problemas de portabilidade. Se você atualizar de versões anteriores do Visual C++ e encontrar o erro do compilador [C2664](../../error-messages/compiler-errors-2/compiler-error-c2664.md) porque o código está tentando converter implicitamente um `wchar_t` para `unsigned short`, recomendamos que você altere o código para corrigir o erro, em vez disso configuração **/Zc:wchar_t-**.

O **/ZC:** opção é ativada por padrão em compilações C++ e é ignorada em compilações de C. O [/ permissivo-](permissive-standards-conformance.md) não afeta a opção **/ZC:**.

A Microsoft implementa `wchar_t` como um valor sem sinal de dois bytes. Ele mapeia para o tipo nativo específicas da Microsoft `__wchar_t`. Para obter mais informações sobre `wchar_t`, consulte [intervalos de tipos de dados](../../cpp/data-type-ranges.md) e [tipos fundamentais](../../cpp/fundamental-types-cpp.md).

Se você escrever novo código que tem para interoperar com o código anterior ainda usa o `typedef` versão do `wchar_t`, você pode fornecer sobrecargas para ambos os `unsigned short` e `__wchar_t` variações de `wchar_t`, de modo que seu código pode ser vinculado a o código compilado com **/ZC:** ou código compilado sem ele. Caso contrário, você precisa fornecer dois diferentes compilações de biblioteca, uma com e sem **/ZC:** habilitado. Mesmo nesse caso, é recomendável compilar o código mais antigo usando o mesmo compilador que você usa para compilar o novo código. Nunca misture binários compilados com compiladores diferentes.

Quando **/ZC:** for especificado,  **\_WCHAR\_T\_definidas** e  **\_nativo\_WCHAR\_T\_definidas** símbolos são definidos. Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).

Se seu código usa as funções globais COM do compilador, porque **/ZC:** está agora em por padrão, é recomendável que você altere as referências explícitas aos comsupp.lib (da [pragma de comentário](../../preprocessor/comment-c-cpp.md) ou o linha de comando) para comsuppw.lib ou comsuppwd.lib. (Se você deve compilar com **/Zc:wchar_t-**, use comsupp.lib.) Se você incluir o arquivo de cabeçalho comdef.h, a biblioteca correta será especificada para você. Para obter informações sobre o suporte de COM do compilador, consulte [compilador COM suporte](../../cpp/compiler-com-support.md).

O `wchar_t` tipo interno não tem suporte quando você compila o código C. Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **idioma** página.

1. Modificar o **tratar wchar_t como tipo interno** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.TreatWChar_tAsBuiltInType%2A>.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
