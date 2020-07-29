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
ms.openlocfilehash: 114ed4a279b66571c0dc81fc1139dcdc59c17eae
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234309"
---
# <a name="zcwchar_t-wchar_t-is-native-type"></a>/Zc:wchar_t (wchar_t é do tipo nativo)

Analise **`wchar_t`** como um tipo interno de acordo com o padrão C++.

## <a name="syntax"></a>Sintaxe

> **/Zc: wchar_t**[ **-** ]

## <a name="remarks"></a>Comentários

Se **/Zc: wchar_t** for on, **`wchar_t`** será uma palavra-chave para um tipo integral interno no código compilado como C++. Se **/Zc: wchar_t-** (com um sinal de subtração) for especificado ou no código compilado como C, **`wchar_t`** não será um tipo interno. Em vez disso, **`wchar_t`** é definido como um **`typedef`** para **`unsigned short`** no cabeçalho canônico stddef. h. (A implementação da Microsoft a define em outro cabeçalho que é incluído por stddef. h e outros cabeçalhos padrão.)

Não recomendamos **/Zc: wchar_t-** porque o padrão C++ requer que **`wchar_t`** seja um tipo interno. O uso da **`typedef`** versão pode causar problemas de portabilidade. Se você atualizar de versões anteriores do Visual Studio e encontrar o erro [C2664](../../error-messages/compiler-errors-2/compiler-error-c2664.md) do compilador porque o código está tentando converter implicitamente um **`wchar_t`** para o **`unsigned short`** , recomendamos que você altere o código para corrigir o erro, em vez de definir **/Zc: wchar_t-**.

A opção **/Zc: wchar_t** está ativada por padrão em compilações de C++ e é ignorada em compilações de C. A opção [/permissive-](permissive-standards-conformance.md) não afeta **/Zc: wchar_t**.

A Microsoft implementa **`wchar_t`** como um valor não assinado de dois bytes. Ele é mapeado para o tipo nativo específico da Microsoft **`__wchar_t`** . Para obter mais informações sobre o **`wchar_t`** , consulte [intervalos de tipo de dados](../../cpp/data-type-ranges.md) e [tipos fundamentais](../../cpp/fundamental-types-cpp.md).

Se você escrever um novo código que precisa interoperar com um código mais antigo que ainda usa a **`typedef`** versão do **`wchar_t`** , você pode fornecer sobrecargas para **`unsigned short`** as **`__wchar_t`** variações de e para o **`wchar_t`** , para que seu código possa ser vinculado com o código compilado com **/Zc: wchar_t** ou código compilado sem ele. Caso contrário, você precisaria fornecer duas compilações diferentes da biblioteca, uma com e outra sem **/Zc: wchar_t** habilitado. Mesmo nesse caso, é recomendável compilar o código mais antigo usando o mesmo compilador que você usa para compilar o novo código. Nunca misture binários compilados com compiladores diferentes.

Quando **/Zc: wchar_t** é especificado, o ** \_ WCHAR \_ t \_ definido** e os símbolos ** \_ nativos de \_ WCHAR \_ t \_ ** definidos são definidos. Para obter mais informações, confira [Macros predefinidas](../../preprocessor/predefined-macros.md).

Se o seu código usa as funções globais COM do compilador, porque **/Zc: wchar_t** está agora ativado por padrão, recomendamos que você altere as referências explícitas para comsupp. lib (do [Comentário pragma](../../preprocessor/comment-c-cpp.md) ou da linha de comando) para comsuppw. lib ou comsuppwd. lib. (Se você precisar compilar com **/Zc: wchar_t-**, use comsupp. lib.) Se você incluir o arquivo de cabeçalho comdef. h, a biblioteca correta será especificada para você. Para obter informações sobre o suporte de COM do compilador, consulte [suporte de com do compilador](../../cpp/compiler-com-support.md).

O **`wchar_t`** tipo interno não tem suporte quando você compila o código C. Para obter mais informações sobre problemas de conformidade com o Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página da linguagem**C/C++** Propriedades de configuração  >  **Language** .

1. Modifique o **wchar_t de tratamento como propriedade de tipo interno** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.TreatWChar_tAsBuiltInType%2A>.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)<br/>
