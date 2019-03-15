---
title: /H (restringir comprimento de nomes externos)
ms.date: 09/05/2018
f1_keywords:
- /h
helpviewer_keywords:
- public name length
- /H compiler option [C++]
- H compiler option [C++]
- external names
- -H compiler option [C++]
ms.assetid: de701dd3-ed04-4c88-8195-960d2520ec2e
ms.openlocfilehash: bdd3da8d3a5165262c00bc3475122e31f5770726
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57811258"
---
# <a name="h-restrict-length-of-external-names"></a>/H (restringir comprimento de nomes externos)

Preterido. Restringe o comprimento dos nomes externos.

## <a name="syntax"></a>Sintaxe

> **/H**<em>number</em>

## <a name="arguments"></a>Arguments

*number*<br/>
Especifica o comprimento máximo de nomes externos permitidos em um programa.

## <a name="remarks"></a>Comentários

Por padrão, o comprimento dos nomes (públicos) externos é 2047 caracteres. Isso é verdadeiro para programas em C e C++. Usando o **/H** pode diminuir somente o comprimento máximo permitido de identificadores, não aumentá-lo. Um espaço entre **/H** e *número* é opcional.

Se um programa contém nomes externos maiores que *número*, os caracteres extras serão ignorados. Se você compilar um programa sem **/H** e se um identificador contiver mais de 2047 caracteres, o compilador irá gerar [Fatal C1064 de erro](../../error-messages/compiler-errors-1/fatal-error-c1064.md).

O limite no tamanho inclui qualquer sublinhado inicial criado pelo compilador (**\_**) ou sinal de arroba (**\@**). Esses caracteres são parte do identificador e levar a um local significativo.

- O compilador adiciona um sublinhado à esquerda (**\_**) para nomes modificados pela `__cdecl` (padrão) e `__stdcall` convenções de chamada e uma líder do sinal de arroba (**\@** ) para nomes modificados pelo `__fastcall` convenção de chamada.

- O compilador acrescenta informações de tamanho de argumento para nomes modificados pela `__fastcall` e `__stdcall` convenções de chamada e adiciona informações de tipo para nomes de C++.

Você pode achar **/H** úteis:

- Quando você cria programas de linguagens mistas ou portátil.

- Quando você usa ferramentas que impõem limites na duração do identificadores externos.

- Quando você deseja restringir a quantidade de espaço que usar de símbolos em um build de depuração.

A exemplo a seguir mostra como o uso **/H** realmente pode introduzir erros se comprimentos de identificador são muito limitados:

```cpp
// compiler_option_H.cpp
// compile with: /H5
// processor: x86
// LNK2005 expected
void func1(void);
void func2(void);

int main() { func1(); }

void func1(void) {}
void func2(void) {}
```

Você também deve ter cuidado ao usar o **/H** opção por causa de identificadores de compilador predefinidos. Se o comprimento máximo do identificador é muito pequeno, determinados identificadores predefinidos será biblioteca não resolvidas, bem como determinadas chamadas de função. Por exemplo, se o `printf` função é usada e a opção **/H5** é especificado em tempo de compilação, o símbolo **_prin** será criado para fazer referência a `printf`, e isso não será encontrado na biblioteca.

Uso de **/H** é incompatível com [/GL (otimização de programa inteiro)](gl-whole-program-optimization.md).

O **/H** opção foi preterida desde o Visual Studio 2005; os limites de comprimento máximo aumentaram e **/H** não for mais necessário. Para obter uma lista de opções do compilador preterido, consulte **preteridos e removidos opções do compilador** na [opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Insira a opção de compilador na **opções adicionais** caixa.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
