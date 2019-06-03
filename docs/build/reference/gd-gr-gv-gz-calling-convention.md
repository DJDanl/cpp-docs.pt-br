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
ms.openlocfilehash: 72d65ce7471ed047ab8347a45c58a6b8a9f39a7a
ms.sourcegitcommit: 28eae422049ac3381c6b1206664455dbb56cbfb6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/31/2019
ms.locfileid: "66450850"
---
# <a name="gd-gr-gv-gz-calling-convention"></a>/Gd, /Gr, /Gv, /Gz (convenção de chamada)

Essas opções determinam a ordem na qual os argumentos de função são enviados para a pilha, se a função do chamador ou a função chamada remove os argumentos da pilha no final da chamada e a convenção de decoração de nome que o compilador usa para identificar funções individuais.

## <a name="syntax"></a>Sintaxe

> **/Gd**<br/>
> **/Gr**<br/>
> **/Gv**<br/>
> **/Gz**<br/>

## <a name="remarks"></a>Comentários

**/Gd**, a configuração padrão, especifica a convenção de chamada [__cdecl](../../cpp/cdecl.md) para todas as funções, exceto funções de membro C++ e funções marcadas como [__stdcall](../../cpp/stdcall.md), [__fastcall](../../cpp/fastcall.md) ou [__vectorcall](../../cpp/vectorcall.md).

**/Gr** especifica a convenção de chamada `__fastcall` para todas as funções, exceto funções de membro C++, funções chamadas `main` e funções marcadas como `__cdecl`, `__stdcall` ou `__vectorcall`. Todas as funções `__fastcall` precisam ter protótipos. Essa convenção de chamada só está disponível nos compiladores direcionados ao x86 e é ignorada pelos compiladores direcionados a outras arquiteturas.

**/Gz** especifica a convenção de chamada `__stdcall` para todas as funções, exceto funções de membro C++, funções chamadas `main` e funções marcadas como `__cdecl`, `__fastcall` ou `__vectorcall`. Todas as funções `__stdcall` precisam ter protótipos. Essa convenção de chamada só está disponível nos compiladores direcionados ao x86 e é ignorada pelos compiladores direcionados a outras arquiteturas.

**/GV** Especifica o `__vectorcall` convenção de chamada para todas as funções, exceto C++ funções de membro, funções nomeadas `main`, funções com uma `vararg` lista de argumentos variáveis ou funções que são marcadas com um conflito `__cdecl`, `__stdcall`, ou `__fastcall` atributo. Essa convenção de chamada só está disponível em arquiteturas x86 e x64 que dão suporte a /arch:SSE2 e posterior e é ignorada pelos compiladores direcionados à arquitetura ARM.

As funções que usam um número variável de argumentos precisam ser marcadas como `__cdecl`.

**/Gd**, **/Gr**, **/Gv** e **/Gz** não são compatíveis com [/clr:safe](clr-common-language-runtime-compilation.md) ou **/clr:pure**. As opções do compilador **/clr:pure** e **/clr:safe** foram preteridas no Visual Studio 2015 e estão sem suporte no Visual Studio 2017 e posterior.

> [!NOTE]
> Por padrão, para processadores x86, as funções de membro C++ usam [__thiscall](../../cpp/thiscall.md).

Para todos os processadores, uma função de membro que está explicitamente marcada como `__cdecl`, `__fastcall`, `__vectorcall` ou `__stdcall` usa a convenção de chamada especificada se ela não é ignorada na arquitetura. Uma função de membro que usa um número variável de argumentos sempre usa a convenção de chamada `__cdecl`.

Essas opções do compilador não têm efeito sobre a decoração de nome de funções e métodos C++. A menos que declarado como `extern "C"`, as funções e métodos C++ usam um esquema de decoração de nome diferente. Para obter mais informações, confira [Nomes decorados](decorated-names.md).

Para obter mais informações sobre convenções de chamada, confira [Convenções de chamada](../../cpp/calling-conventions.md).

## <a name="cdecl-specifics"></a>Especificações de __cdecl

Em processadores x86, todos os argumentos de função são passados na pilha da direita para a esquerda. Em arquiteturas ARM e x64, alguns argumentos são passados pelo registro e o restante é passado na pilha da direita para a esquerda. A rotina de chamada remove os argumentos mais recentes da pilha.

Para o C, a convenção de nomenclatura `__cdecl` usa o nome da função precedido por um sublinhado (`_`); nenhuma conversão de maiúsculas e minúsculas é realizada. A menos que declarado como `extern "C"`, as funções C++ usam um esquema de decoração de nome diferente. Para obter mais informações, confira [Nomes decorados](decorated-names.md).

## <a name="fastcall-specifics"></a>Especificações de __fastcall

Alguns argumentos da função de um `__fastcall` são passados em registros (para processadores x86, ECX e EDX), e o restante é enviado para a pilha da direita para a esquerda. A rotina de chamada remove esses argumentos da pilha antes de retornar. Normalmente, **/Gr** diminui o tempo de execução.

> [!NOTE]
> Tenha cuidado ao usar a convenção de chamada `__fastcall` para qualquer função que seja escrita na linguagem assembly embutido. O uso de registros pode entrar em conflito com o uso do compilador.

Para o C, a convenção de nomenclatura `__fastcall` usa o nome da função precedido por um sinal de arroba ( **\@** ) seguido pelo tamanho dos argumentos da função em bytes. Nenhuma conversão de maiúsculas e minúsculas é realizada. O compilador usa este modelo para a convenção de nomenclatura:

`@function_name@number`

Ao usar a convenção de nomenclatura `__fastcall`, use os arquivos de inclusão padrão. Caso contrário, você obterá referências externas não resolvidas.

## <a name="stdcall-specifics"></a>Especificações de __stdcall

Os argumentos da função de um `__stdcall` são enviados para a pilha da direita para a esquerda, sendo que e a função chamada remove esses argumentos da pilha antes de retornar.

Para o C, a convenção de nomenclatura `__stdcall` usa o nome da função precedido por um sublinhado ( **\_** ) e seguido por um sinal de arroba ( **\@** ) e pelo tamanho dos argumentos da função em bytes. Nenhuma tradução realizada. O compilador usa este modelo para a convenção de nomenclatura:

`_functionname@number`

## <a name="vectorcall-specifics"></a>Especificações de __vectorcall

Os argumentos de inteiro da função de um `__vectorcall` são passados por valor, usando até dois (no x86) ou quatro (no x64) registros de inteiros e até seis registros de XMM para valores de ponto flutuante e de vetor, sendo que o restante é passado na pilha da direita para a esquerda. A função chamada limpa a pilha antes de retornar. Os valores retornados de vetor e de ponto flutuante são retornados em XMM0.

Para o C, a convenção de nomenclatura `__vectorcall` usa o nome da função seguido por dois sinais de arroba ( **\@\@** ) e pelo tamanho dos argumentos da função em bytes. Nenhuma tradução realizada. O compilador usa este modelo para a convenção de nomenclatura:

`functionname@@number`

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **C/C++**  > **Avançado**.

1. Modifique a propriedade **Convenção de Chamada**.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CallingConvention%2A>.

## <a name="see-also"></a>Consulte também

- [Opções do compilador MSVC](compiler-options.md)
- [Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
