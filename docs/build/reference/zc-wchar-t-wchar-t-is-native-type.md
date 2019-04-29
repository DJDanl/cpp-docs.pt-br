---
title: /Zc:wchar_t (wchar_t é do tipo nativo)
ms.date: 03/01/2018
f1_keywords:
- VC.Project.VCCLWCECompilerTool.TreatWChar_tAsBuiltInType
- VC.Project.VCCLCompilerTool.TreatWChar_tAsBuiltInType
- /Zc:wchar_t
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- wchar_t type
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: b0de5a84-da72-4e5a-9a4e-541099f939e0
ms.openlocfilehash: b2563ba0ae2a07bc9f9d81128745ed4b9651fb6c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315632"
---
# <a name="zcwchart-wchart-is-native-type"></a>/Zc:wchar_t (wchar_t é do tipo nativo)

Analise `wchar_t` como um tipo interno de acordo com o padrão C++.

## <a name="syntax"></a>Sintaxe

> **/Zc:wchar_t**[**-**]

## <a name="remarks"></a>Comentários

Se **/ZC: wchar_t** estiver ativado, `wchar_t` é uma palavra-chave para um tipo integral interna no código compilado como C++. Se **/Zc:wchar_t-** (com um sinal de subtração) é especificado, ou no código compilado como C, `wchar_t` não é um tipo interno. Em vez disso, `wchar_t` é definido como um `typedef` para `unsigned short` em stddef. h do cabeçalho canônico. (A implementação da Microsoft define-lo em outro cabeçalho é incluído por stddef. h e outros cabeçalhos padrão.)

Não recomendamos **/Zc:wchar_t-** porque o C++ padrão requer que `wchar_t` seja um tipo interno. Usar a versão `typedef` pode causar problemas de portabilidade. Se você atualizar de versões anteriores do Visual C++ e encontrar o erro do compilador [C2664](../../error-messages/compiler-errors-2/compiler-error-c2664.md) porque o código está tentando converter implicitamente um `wchar_t` para `unsigned short`, é recomendável que você altere o código para corrigir o erro, em vez de definir **/Zc:wchar_t-**.

O **/ZC: wchar_t** opção permanece ativada por padrão em C++ compilações e é ignorada em compilações de C. O [/permissive--](permissive-standards-conformance.md) opção não afeta **/ZC: wchar_t**.

A Microsoft implementa `wchar_t` como um valor sem sinal de dois bytes. Ela mapeia para o tipo nativo do específico da Microsoft `__wchar_t`. Para obter mais informações sobre `wchar_t`, consulte [intervalos de tipos de dados](../../cpp/data-type-ranges.md) e [tipos fundamentais](../../cpp/fundamental-types-cpp.md).

Se você escrever novo código que precisa interoperar com o código anterior que ainda usa o `typedef` versão do `wchar_t`, você pode fornecer sobrecargas para ambos o `unsigned short` e `__wchar_t` variações de `wchar_t`, de modo que seu código pode ser vinculado a o código compilado com **/ZC: wchar_t** ou código compilado sem ele. Caso contrário, você precisaria fornecer duas diferentes compilações da biblioteca, uma com e sem **/ZC: wchar_t** habilitado. Mesmo nesse caso, é recomendável compilar o código mais antigo usando o mesmo compilador que você usa para compilar o novo código. Nunca misture binários compilados com compiladores diferentes.

Quando **/ZC: wchar_t** for especificado,  **\_WCHAR\_T\_definidas** e  **\_nativo\_WCHAR\_T\_definido pelo** símbolos definidos. Para obter mais informações, consulte [Macros predefinidas](../../preprocessor/predefined-macros.md).

Se seu código usa as funções globais COM do compilador, porque **/ZC: wchar_t** está agora em por padrão, é recomendável que você altere referências explícitas a comsupp (a partir de [pragma de comentário](../../preprocessor/comment-c-cpp.md) ou, no linha de comando) para o comsuppw. lib ou comsuppwd. (Se você deve compilar com **/Zc:wchar_t-**, use comsupp.) Se você incluir o arquivo de cabeçalho comdef.h, a biblioteca correta será especificada para você. Para obter informações sobre o suporte COM do compilador, consulte [compilador COM suporte para](../../cpp/compiler-com-support.md).

O `wchar_t` tipo interno não tem suporte quando você compila código C. Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **idioma** página.

1. Modificar a **trate wchar_t como tipo interno** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.TreatWChar_tAsBuiltInType%2A>.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)<br/>
