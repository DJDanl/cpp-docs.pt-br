---
title: /D (definições de pré-processador)
ms.date: 09/18/2019
f1_keywords:
- VC.Project.VCNMakeTool.PreprocessorDefinitions
- VC.Project.VCCLCompilerTool.PreprocessorDefinitions
- /d
helpviewer_keywords:
- preprocessor definition symbols
- constants, defining
- macros, compiling
- /D compiler option [C++]
- -D compiler option [C++]
- D compiler option [C++]
ms.assetid: b53fdda7-8da1-474f-8811-ba7cdcc66dba
ms.openlocfilehash: b10d611d38508f5696dd3b72fb8458e9b61082c8
ms.sourcegitcommit: 389c559918d9bfaf303d262ee5430d787a662e92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/24/2019
ms.locfileid: "71230391"
---
# <a name="d-preprocessor-definitions"></a>/D (definições de pré-processador)

Define um símbolo de pré-processamento para um arquivo de código-fonte.

## <a name="syntax"></a>Sintaxe

> **/D** ]nome`=` [[{ |  *número* da *cadeia*decaracteres | }]] \`#` \[
> **/D** \[ ]nome[ |  *[{número* da cadeia de caracteres}]]`=` `"` |  `#``"`

## <a name="remarks"></a>Comentários

Você pode usar esse símbolo junto com `#if` ou `#ifdef` para compilar o código-fonte condicionalmente. A definição de símbolo permanece em vigor até que seja redefinida no código ou seja indefinida no código por uma `#undef` diretiva.

**/D** tem o mesmo efeito que uma `#define` diretiva no início de um arquivo de código-fonte. A diferença é que **/d** retira as aspas na linha de comando e uma `#define` diretiva as mantém. Você pode ter espaço em branco entre **/d** e o símbolo. Não pode haver espaço em branco entre o símbolo e o sinal de igual ou entre o sinal de igual e qualquer valor atribuído.

Por padrão, o valor associado a um símbolo é 1. Por exemplo, `/D name` equivale a `/D name=1`. No exemplo no final deste artigo, a definição de `TEST` é mostrada para impressão. `1`

A compilação usando `/D name=` faz com que o *nome* do símbolo não tenha nenhum valor associado. Embora o símbolo ainda possa ser usado para compilar o código condicionalmente, em outros casos, sua avaliação não resulta em nada. No exemplo, se você compilar usando `/DTEST=`, ocorrerá um erro. Esse comportamento é semelhante ao uso de `#define` com ou sem um valor.

A opção **/d** não oferece suporte a definições de macro semelhantes a funções. Para inserir definições que não podem ser definidas na linha de comando, considere a opção de compilador [/Fi (nome forçado include File)](fi-name-forced-include-file.md) .

Você pode usar **/d** várias vezes na linha de comando para definir símbolos adicionais. Se o mesmo símbolo for definido mais de uma vez, a última definição será usada.

Este comando define o símbolo DEBUG em TEST.c:

```cmd
CL /DDEBUG TEST.C
```

Esse comando remove todas as ocorrências da palavra-chave `__far` em TEST.c:

```cmd
CL /D __far= TEST.C
```

A variável de ambiente **CL** não pode ser definida como uma cadeia de caracteres que contém o sinal de igual. Para usar o **/d** junto com a variável de ambiente **CL** , você deve especificar o sinal`#`numérico () em vez do sinal de igual:

```cmd
SET CL=/DTEST#0
```

Quando você definir um símbolo de pré-processamento no prompt de comando, considere as regras de análise do compilador e do shell. Por exemplo, para definir um símbolo de pré-processamento de sinal de porcentagem (`%`) em seu programa, especifique dois caracteres de sinal de porcentagem`%%`() no prompt de comando. Se você especificar apenas um, um erro de análise será emitido.

```cmd
CL /DTEST=%% TEST.C
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. No painel esquerdo, selecione **Propriedades de configuração**, **C/C++** , **pré-processador**.

1. No painel direito, na coluna à direita da propriedade **definições de pré-processador** , abra o menu suspenso e escolha **Editar**.

1. Na caixa de diálogo **definições de pré-processador** , adicione (uma por linha), modifique ou exclua uma ou mais definições. Escolha **OK** para salvar suas alterações.

   Você não precisa incluir o prefixo de opção '/D ' nas definições especificadas aqui. Na página de propriedades, as definições são separadas por ponto e`;`vírgula ().

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.PreprocessorDefinitions%2A>.

## <a name="example"></a>Exemplo

```cpp
// cpp_D_compiler_option.cpp
// compile with: cl /EHsc /DTEST cpp_D_compiler_option.cpp
#include <stdio.h>

int main( )
{
#ifdef TEST
    printf_s("TEST defined %d\n", TEST);
#else
    printf_s("TEST not defined\n");
#endif
}
```

```Output
TEST defined 1
```

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)\
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)\
[/FI (arquivo de inclusão forçada de nome)](fi-name-forced-include-file.md)\
[/U,/u (não definir símbolos)](u-u-undefine-symbols.md)\
[Diretiva #undef (C/C++)](../../preprocessor/hash-undef-directive-c-cpp.md)\
[Diretiva #define (C/C++)](../../preprocessor/hash-define-directive-c-cpp.md)
