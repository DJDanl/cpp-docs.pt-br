---
title: /Gd, /Gr, /Gv, /Gz (convenção de chamada)
ms.date: 09/05/2018
f1_keywords:
- /gr
- /Gv
- /gz
- /Gd
- VC.Project.VCCLCompilerTool.CallingConvention
helpviewer_keywords:
- -Gd compiler option [C++]
- -Gv compiler option [C++]
- /Gv compiler option [C++]
- -Gr compiler option [C++]
- Gd compiler option [C++]
- Gr compiler option [C++]
- /Gz compiler option [C++]
- -Gz compiler option [C++]
- /Gd compiler option [C++]
- Gz compiler option [C++]
- Gv compiler option [C++]
- /Gr compiler option [C++]
ms.assetid: fd3110cb-2d77-49f2-99cf-a03f9ead00a3
ms.openlocfilehash: 7c4f7e6edb020f5c8d2abf80f14df33e18a915c5
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57817456"
---
# <a name="gd-gr-gv-gz-calling-convention"></a>/Gd, /Gr, /Gv, /Gz (convenção de chamada)

Essas opções determinam a ordem na qual função argumentos são enviados por push para a pilha, se a função do chamador ou a função chamada remove os argumentos da pilha no final da chamada e a convenção de decoração de nome que o compilador usa para identificar funções individuais.

## <a name="syntax"></a>Sintaxe

> **/Gd**<br/>
> **/Gr**<br/>
> **/Gv**<br/>
> **/Gz**<br/>

## <a name="remarks"></a>Comentários

**/Gd**, a configuração padrão, especifica o [cdecl](../../cpp/cdecl.md) convenção de chamada para todas as funções exceto membro C++ funções e funções que são marcadas [stdcall](../../cpp/stdcall.md), [_ fastcall](../../cpp/fastcall.md), ou [vectorcall](../../cpp/vectorcall.md).

**/GR** Especifica o `__fastcall` convenção de chamada para todas as funções exceto funções de membro de C++, chamado de funções `main`e funções que são marcadas `__cdecl`, `__stdcall`, ou `__vectorcall`. Todos os `__fastcall` funções devem ter protótipos. Esta convenção de chamada só está disponível nos compiladores que direcionam o x86 e é ignorada pelos compiladores que direcionam outras arquiteturas.

**/Gz** Especifica o `__stdcall` convenção de chamada para todas as funções exceto funções de membro de C++, chamado de funções `main`e funções que são marcadas `__cdecl`, `__fastcall`, ou `__vectorcall`. Todos os `__stdcall` funções devem ter protótipos. Esta convenção de chamada só está disponível nos compiladores que direcionam o x86 e é ignorada pelos compiladores que direcionam outras arquiteturas.

**/GV** Especifica o `__vectorcall` convenção de chamada para todas as funções exceto funções de membro de C++, funções chamadas main, funções com um `vararg` lista de argumentos variáveis ou funções que são marcadas com um conflito `__cdecl`, `__stdcall`, ou `__fastcall` atributo. Esta convenção de chamada só está disponível em arquiteturas x86 e x64 que compatíveis com/arch:SSE2 e superior e é ignorada pelos compiladores que direcionam a arquitetura ARM.

Funções que usam um número variável de argumentos devem ser marcada como `__cdecl`.

**/Gd**, **/Gr**, **/Gv** e **/Gz** não são compatíveis com [/CLR: safe](clr-common-language-runtime-compilation.md) ou **/clr: pure**. O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

> [!NOTE]
> Por padrão para x86 de processadores, as funções de membro de C++ usam [thiscall](../../cpp/thiscall.md).

Para todos os processadores, uma função de membro que está explicitamente marcada como `__cdecl`, `__fastcall`, `__vectorcall`, ou `__stdcall` usa a convenção de chamada especificada se ele não é ignorado na arquitetura. Uma função de membro que aceita um número variável de argumentos sempre usa o `__cdecl` convenção de chamada.

Essas opções do compilador não têm efeito sobre a decoração de nome de funções e métodos de C++. A menos que declarado como `extern "C"`, funções e métodos de C++ usam um esquema de decoração de nome diferente. Para obter mais informações, consulte [nomes decorados](decorated-names.md).

Para obter mais informações sobre as convenções de chamada, consulte [convenções de chamada](../../cpp/calling-conventions.md).

## <a name="cdecl-specifics"></a>especificações de cdecl

Em x86 processadores, todos os argumentos de função são passados na pilha da direita para esquerda. No ARM e x64 arquiteturas, alguns argumentos são passadas pelo registro e o restante é passado na pilha da direita para esquerda. A rotina chamada remove os argumentos da pilha.

Para o C, o `__cdecl` usos de convenção de nomenclatura no nome da função precedido por um sublinhado ( `_` ); nenhuma tradução realizada. A menos que declarado como `extern "C"`, funções de C++ usam um esquema de decoração de nome diferente. Para obter mais informações, consulte [nomes decorados](decorated-names.md).

## <a name="fastcall-specifics"></a>especificações de fastcall

Alguns de um `__fastcall` argumentos da função são passados em registros (para x86 de processadores, ECX e EDX), e o restante é empurrado para a pilha da direita para esquerda. A rotina chamada remove esses argumentos da pilha antes de retornar. Normalmente, **/Gr** diminui o tempo de execução.

> [!NOTE]
> Tenha cuidado ao usar o `__fastcall` convenção de chamada para qualquer função que está escrita na linguagem de assembly embutido. O uso de registros poderia entrar em conflito com o uso do compilador.

Para o C, o `__fastcall` usos de convenção de nomenclatura no nome da função precedido por um sinal de arroba (**\@**) seguido pelo tamanho dos argumentos da função em bytes. Nenhuma tradução realizada. O compilador usa esse modelo para a convenção de nomenclatura:

`@function_name@number`

Quando você usa o `__fastcall` convenção de nomenclatura, use os arquivos de inclusão padrão. Caso contrário, você obterá referências externas não resolvidas.

## <a name="stdcall-specifics"></a>especificações de stdcall

Um `__stdcall` argumentos da função são colocados na pilha da direita para esquerda e a função chamada remove esses argumentos da pilha antes de retornar.

Para o C, o `__stdcall` usos de convenção de nomenclatura no nome da função precedido por um sublinhado (**\_**) e seguido por um sinal de arroba (**\@**) e o tamanho da função argumentos em bytes. Nenhuma tradução realizada. O compilador usa esse modelo para a convenção de nomenclatura:

`_functionname@number`

## <a name="vectorcall-specifics"></a>especificações de vectorcall

Um `__vectorcall` inteiro argumentos de função são passados por valor, usando até dois (em x86) ou quatro (em x64) inteiro registra e até seis registros de MMX se registra para ponto flutuante e valores do vetor e o restante são passados na pilha da direita para esquerda. A função chamada limpa a pilha antes de retornar. Vetor e valores de retorno de ponto flutuantes são retornados em XMM0.

Para o C, o `__vectorcall` convenção de nomenclatura usa o nome da função seguido por dois sinais de arroba (**\@\@**) e o tamanho dos argumentos da função em bytes. Nenhuma tradução realizada. O compilador usa esse modelo para a convenção de nomenclatura:

`functionname@@number`

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **C/C++** > **avançado** página de propriedades.

1. Modificar a **convenção de chamada** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CallingConvention%2A>.

## <a name="see-also"></a>Consulte também

- [Opções do compilador MSVC](compiler-options.md)
- [Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
