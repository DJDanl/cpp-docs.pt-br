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
ms.openlocfilehash: 9a8976700cfb0f333c2715c573aa2d239e2a8e3a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218982"
---
# <a name="h-restrict-length-of-external-names"></a>/H (restringir comprimento de nomes externos)

Preterido. Restringe o comprimento de nomes externos.

## <a name="syntax"></a>Sintaxe

> **/H**<em>número</em>

## <a name="arguments"></a>Argumentos

*number*<br/>
Especifica o comprimento máximo de nomes externos permitidos em um programa.

## <a name="remarks"></a>Comentários

Por padrão, o comprimento de nomes externos (públicos) é de 2.047 caracteres. Isso é verdadeiro para programas C e C++. O uso de **/h** só pode diminuir o comprimento máximo permitido de identificadores, não aumentá-lo. Um espaço entre **/h** e *número* é opcional.

Se um programa contiver nomes externos maiores do que o *número*, os caracteres extras serão ignorados. Se você compilar um programa sem **/h** e se um identificador contiver mais de 2.047 caracteres, o compilador gerará um [erro fatal C1064](../../error-messages/compiler-errors-1/fatal-error-c1064.md).

O limite de comprimento inclui qualquer sublinhado à esquerda ( **\_** ) ou arroba () criado pelo compilador **\@** . Esses caracteres fazem parte do identificador e usam um local significativo.

- O compilador adiciona um sublinhado à esquerda ( **\_** ) aos nomes modificados pelo **`__cdecl`** (padrão) e pelas **`__stdcall`** convenções de chamada e um sinal de arroba ( **\@** ) à esquerda para nomes modificados pela **`__fastcall`** Convenção de chamada.

- O compilador acrescenta informações de tamanho de argumento a nomes modificados **`__fastcall`** pelas **`__stdcall`** convenções de chamada e e adiciona informações de tipo a nomes C++.

Você pode encontrar **/h** útil:

- Quando você cria programas de idioma misto ou portáteis.

- Quando você usa ferramentas que impõem limites no comprimento de identificadores externos.

- Quando você deseja restringir a quantidade de espaço que os símbolos usam em uma compilação de depuração.

O exemplo a seguir mostra como o uso de **/h** pode realmente introduzir erros se os comprimentos do identificador forem muito limitados:

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

Você também deve ter cuidado ao usar a opção **/h** devido a identificadores de compilador predefinidos. Se o comprimento máximo do identificador for muito pequeno, determinados identificadores predefinidos não serão resolvidos, bem como determinadas chamadas de função de biblioteca. Por exemplo, se a `printf` função for usada e a opção **/H5** for especificada em tempo de compilação, o símbolo **_prin** será criado para fazer referência `printf` e isso não será encontrado na biblioteca.

O uso de **/h** é incompatível com [/GL (otimização do programa inteiro)](gl-whole-program-optimization.md).

A opção **/h** foi preterida desde o Visual Studio 2005; os limites de comprimento máximo foram aumentados e **/h** não é mais necessário. Para obter uma lista de opções de compilador preteridas, consulte **Opções de compilador preteridas e removidas** em [Opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Insira a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
