---
title: Macros (C/C++)
ms.date: 08/29/2019
helpviewer_keywords:
- preprocessor
- preprocessor, macros
- Visual C++, preprocessor macros
ms.assetid: a7bfc5d4-2537-4fe0-bef0-70cec0b43388
ms.openlocfilehash: ba2c0f012974a528876219d00c61c0f31a6cd820
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218867"
---
# <a name="macros-cc"></a>Macros (C/C++)

O pré-processador expande macros em todas as linhas, exceto *diretivas de pré-processador*, linhas que têm um **#** como o primeiro caractere que não seja espaço em branco. Ele expande as macros em partes de algumas diretivas que não são ignoradas como parte de uma compilação condicional. As *diretivas de compilação condicional* permitem suprimir a compilação de partes de um arquivo de origem. Eles testam uma expressão constante ou um identificador para determinar quais blocos de texto serão passados para o compilador e quais serão removidos do arquivo de origem durante o pré-processamento.

A política `#define` normalmente é usada para associar identificadores significativos a constantes, palavras-chave e instruções ou expressões de uso geral. Identificadores que representam constantes às vezes são chamados de constantes simbólicas ou *constantes de manifesto*. Identificadores que representam instruções ou expressões são chamadosde macros. Nesta documentação de pré-processador, somente o termo “macro” é usado.

Quando o nome de uma macro é reconhecido no texto de origem do programa ou nos argumentos de alguns outros comandos de pré-processador, ele é tratado como uma chamada para essa macro. O nome da macro é substituído por uma cópia do corpo da macro. Se a macro aceitar argumentos, os argumentos reais após o nome da macro serão substituídos por parâmetros formais no corpo da macro. O processo de substituir uma chamada de macro pela cópia processada do corpo é chamado de *expansão* da chamada de macro.

Em termos práticos, há dois tipos de macros. Macros *semelhantes a objeto* não usam argumentos. Macros *semelhantes à função* podem ser definidas para aceitar argumentos, para que eles pareçam e atuem como chamadas de função. Como as macros não geram chamadas de função reais, às vezes você pode fazer com que os programas sejam executados mais rapidamente substituindo as chamadas de função por macros (Em C++, as funções embutidas frequentemente são o método preferencial.) No entanto, as macros podem criar problemas se você não defini-las e usá-las com cuidado. Você pode precisar usar parênteses em definições de macro com argumentos para preservar a precedência apropriada em uma expressão. Além disso, as macros podem não manipular corretamente expressões com efeitos colaterais. Para obter mais informações, consulte `getrandom` o exemplo na [diretiva #define](../preprocessor/hash-define-directive-c-cpp.md).

Depois de definir uma macro, você não poderá redefini-la para um valor diferente sem primeiro remover a definição original. No entanto, você pode redefinir a macro com exatamente a mesma definição. Assim, a mesma definição pode aparecer mais de uma vez em um programa.

A `#undef` diretiva remove a definição de uma macro. Depois de remover a definição, você poderá redefinir a macro para um valor diferente. [A diretiva #define](../preprocessor/hash-define-directive-c-cpp.md) e [a diretiva #undef](../preprocessor/hash-undef-directive-c-cpp.md) discutem `#define` as `#undef` diretivas e, respectivamente.

Para obter mais informações, consulte

- [Macros e C++](../preprocessor/macros-and-cpp.md)

- [Macros variadic](../preprocessor/variadic-macros.md)

- [Macros predefinidas](../preprocessor/predefined-macros.md)

## <a name="see-also"></a>Consulte também

[Referência deC++ C/pré-processador](../preprocessor/c-cpp-preprocessor-reference.md)
