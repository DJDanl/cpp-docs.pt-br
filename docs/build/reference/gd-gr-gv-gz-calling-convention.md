---
title: /Gd, /Gr, /Gv, /Gz (convenção de chamada) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /gr
- /Gv
- /gz
- /Gd
- VC.Project.VCCLCompilerTool.CallingConvention
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3da8b4fcddbc384a785b27f0a7d706236a46ccf0
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34703766"
---
# <a name="gd-gr-gv-gz-calling-convention"></a>/Gd, /Gr, /Gv, /Gz (convenção de chamada)
Essas opções determinam a ordem na qual a função argumentos são colocados na pilha, se a função do chamador ou a função chamada remove os argumentos da pilha no final da chamada e a convenção de decoração de nome que o compilador usa para identificar funções individuais.

## <a name="syntax"></a>Sintaxe

> **/Gd**<br/>
> **/Gr**<br/>
> **/Gv**<br/>
> **/Gz**<br/>

## <a name="remarks"></a>Comentários

**/Gd**, a configuração padrão, especifica o [cdecl](../../cpp/cdecl.md) convenção de chamada para todas as funções, exceto o membro de C++ funções e funções que são marcadas [stdcall](../../cpp/stdcall.md), [_ fastcall](../../cpp/fastcall.md), ou [vectorcall](../../cpp/vectorcall.md).

**/GR** Especifica o `__fastcall` convenção de chamada para todas as funções, exceto as funções de membro de C++, chamado de funções `main`e as funções que são marcados como `__cdecl`, `__stdcall`, ou `__vectorcall`. Todos os `__fastcall` funções devem possuir protótipos. Essa convenção de chamada está disponível apenas no compiladores que x86 de destino e é ignorada por compiladores que outras arquiteturas de destino.

**/Gz** Especifica o `__stdcall` convenção de chamada para todas as funções, exceto as funções de membro de C++, chamado de funções `main`e as funções que são marcados como `__cdecl`, `__fastcall`, ou `__vectorcall`. Todos os `__stdcall` funções devem possuir protótipos. Essa convenção de chamada está disponível apenas no compiladores que x86 de destino e é ignorada por compiladores que outras arquiteturas de destino.

**/GV** Especifica o `__vectorcall` convenção de chamada para todas as funções, exceto as funções de membro de C++, nomeado principal de funções, as funções com um `vararg` lista de argumentos variáveis ou funções que são marcadas com um conflito `__cdecl`, `__stdcall`, ou `__fastcall` atributo. Essa convenção de chamada só está disponível em arquiteturas x86 e x64 que dão suporte a /arch: SSE2 e acima e é ignorada por compiladores que se destinam a arquitetura ARM.

Funções que possuem um número variável de argumentos devem ser marcado como `__cdecl`.

**/Gd**, **/Gr**, **/Gv** e **/Gz** não são compatíveis com [/CLR: safe](../../build/reference/clr-common-language-runtime-compilation.md) ou **/clr: pure**. O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

> [!NOTE]
> Por padrão para x86 processadores, funções de membro de C++ usam [thiscall](../../cpp/thiscall.md).

Para todos os processadores, uma função de membro que é marcado explicitamente como `__cdecl`, `__fastcall`, `__vectorcall`, ou `__stdcall` usa a convenção de chamada especificada se ele não será ignorado na arquitetura. Uma função de membro que usa um número variável de argumentos sempre usa o `__cdecl` convenção de chamada.

Essas opções de compilador não têm efeito sobre a decoração de nome de funções e métodos de C++. A menos que declarado como `extern "C"`, funções e métodos de C++ usar um esquema diferente de decoração de nome. Para obter mais informações, consulte [nomes decorados](../../build/reference/decorated-names.md).

Para obter mais informações sobre convenções de chamada, consulte [convenções de chamada](../../cpp/calling-conventions.md).

## <a name="cdecl-specifics"></a>especificações de cdecl

X86 processadores, todos os argumentos de função são passados na pilha da direita para esquerda. Em ARM e x64 arquiteturas, alguns argumentos são passadas por registro e o restante são passados na pilha da direita para esquerda. Chamar a rotina exibe os argumentos da pilha.

Para C, o `__cdecl` o nome da função de usos de convenção de nomenclatura precedido por um sublinhado ( `_` ); nenhuma conversão caso é executada. A menos que declarado como `extern "C"`, funções C++ usam um esquema diferente de decoração de nome. Para obter mais informações, consulte [nomes decorados](../../build/reference/decorated-names.md).

## <a name="fastcall-specifics"></a>especificações de fastcall

Alguns de um `__fastcall` argumentos de função são passados em registros (para x86 EDX, ECX e processadores), e o restante são enviados por push para a pilha da direita para esquerda. A rotina de chamadas exibe esses argumentos da pilha antes de retornar. Normalmente, **/Gr** diminui o tempo de execução.

> [!NOTE]
> Tenha cuidado ao usar o `__fastcall` convenção de chamada para qualquer função que está escrita na linguagem de assembly embutido. O uso de registros pode entrar em conflito com o uso do compilador.

Para C, o `__fastcall` o nome da função de usos de convenção de nomenclatura precedido por um sinal de arroba (`@`) seguido pelo tamanho dos argumentos da função em bytes. Nenhuma conversão caso é feito. O compilador usa esse modelo para a convenção de nomenclatura:

`@function_name@number`

Quando você usa o `__fastcall` convenção de nomenclatura, use os arquivos de inclusão padrão. Caso contrário, você obterá referências externas não resolvidas.

## <a name="stdcall-specifics"></a>especificações de stdcall

Um `__stdcall` argumentos de função são enviados por push para a pilha da direita para esquerda e a função chamada pops esses argumentos da pilha antes de retornar.

Para C, o `__stdcall` o nome da função de usos de convenção de nomenclatura precedido por um sublinhado ( `_` ) e seguido por um sinal de arroba (@) e o tamanho dos argumentos da função em bytes. Nenhuma tradução realizada. O compilador usa esse modelo para a convenção de nomenclatura:

`_functionname@number`

## <a name="vectorcall-specifics"></a>especificações de vectorcall

Um `__vectorcall` inteiro argumentos de função são transmitidos por valor, usando até dois (em x86) ou quatro (em x64) inteiro registra e até seis XMM registros de ponto flutuante e vetor de valores e o restante são passados na pilha da direita para esquerda. A função chamada limpa na pilha antes de retornar. Vetor e valores de retorno de ponto flutuante são retornados no XMM0.

Para C, o `__vectorcall` convenção de nomenclatura usa o nome da função seguido por dois sinais de @ (@) e o tamanho dos argumentos da função em bytes. Nenhuma tradução realizada. O compilador usa esse modelo para a convenção de nomenclatura:

`functionname@@number`

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **C/C++** > **avançado** página de propriedades.

1. Modificar o **convenção de chamada** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.CallingConvention%2A>.

## <a name="see-also"></a>Consulte também

- [Opções do Compilador](../../build/reference/compiler-options.md)
- [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)
