---
title: Diretivas Pragma e a palavra-chave __pragma
description: Descreve as diretivas pragma disponíveis no Microsoft Visual C e C++ (MSVC)
ms.date: 10/30/2020
f1_keywords:
- '#pragma'
helpviewer_keywords:
- '#pragma directives, C/C++'
- __pragma keyword
- pragma directives, C/C++
- pragmas, C/C++
- preprocessor
- pragmas
- preprocessor, pragmas
- pragma directives (#pragma)
ms.assetid: 9867b438-ac64-4e10-973f-c3955209873f
ms.openlocfilehash: bf4bbdcf74808edd8ef54149f8258f47bd94c600
ms.sourcegitcommit: 4abc6c4c9694f91685cfd77940987e29a51e3143
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/03/2020
ms.locfileid: "93238402"
---
# <a name="pragma-directives-and-the-__pragma-keyword"></a>Diretivas Pragma e a palavra-chave __pragma

As diretivas pragma especificam recursos de compilador específicos do computador ou do sistema operacional. A palavra-chave **__pragma** , que é específica para o compilador da Microsoft, permite que você codifique as diretivas pragma nas definições de macro.

## <a name="syntax"></a>Syntax

> **#`pragma`***cadeia de caracteres de token*\
> **`__pragma(`***cadeia de caracteres* **`)`** de token dois sublinhados à esquerda- **`_Pragma(`** *cadeia de caracteres de* extensão específica da Microsoft-literal **`)`** //C99

## <a name="remarks"></a>Comentários

Cada implementação de C e C++ oferece suporte a alguns recursos exclusivos para seu computador host ou sistema operacional. Alguns programas, por exemplo, devem exercer um controle preciso sobre o local dos dados na memória ou controlar a maneira como certas funções recebem parâmetros. As diretivas de **#pragma** oferecem uma maneira para cada compilador oferecer recursos específicos de computador e de sistema operacional, ao mesmo tempo em que mantém a compatibilidade geral com as linguagens C e C++.

Os pragmas são específicos do sistema operacional ou da máquina por definição e são normalmente diferentes para cada compilador. Os pragmas podem ser usados em Diretivas condicionais, para fornecer uma nova funcionalidade de pré-processador ou para fornecer informações definidas para a implementação ao compilador.

A *cadeia* de caracteres de token é uma série de caracteres que representam uma instrução e argumentos de compilador específicos, se houver. O sinal numérico ( **#** ) deve ser o primeiro caractere que não seja espaço em branco na linha que contém o pragma. Caracteres de espaço em branco podem separar o sinal numérico e a palavra "pragma". A seguir **#pragma** , escreva qualquer texto que o tradutor possa analisar como pré-processamento de tokens. O argumento para **#pragma** está sujeito à expansão de macro.

A *cadeia de caracteres literal* é a entrada para `_Pragma` . Aspas externas e espaços em branco à esquerda/à direita são removidos. `\"` é substituído por `"` e `\\` é substituído por `\` .

O compilador emite um aviso quando encontra um pragma que ele não reconhece e continua a compilação.

Os compiladores C e C++ da Microsoft reconhecem os seguintes pragmas:

:::row:::
   :::column span="":::
      [`alloc_text`](../preprocessor/alloc-text.md)\
      [`auto_inline`](../preprocessor/auto-inline.md)\
      [`bss_seg`](../preprocessor/bss-seg.md)\
      [`check_stack`](../preprocessor/check-stack.md)\
      [`code_seg`](../preprocessor/code-seg.md)\
      [`comment`](../preprocessor/comment-c-cpp.md)\
      [`component`](../preprocessor/component.md)\
      [`conform`](../preprocessor/conform.md)<sup>1</sup>\
      [`const_seg`](../preprocessor/const-seg.md)\
      [`data_seg`](../preprocessor/data-seg.md)\
      [`deprecated`](../preprocessor/deprecated-c-cpp.md)
   :::column-end:::
   :::column span="":::
      [`detect_mismatch`](../preprocessor/detect-mismatch.md)\
      [`fenv_access`](../preprocessor/fenv-access.md)\
      [`float_control`](../preprocessor/float-control.md)\
      [`fp_contract`](../preprocessor/fp-contract.md)\
      [`function`](../preprocessor/function-c-cpp.md)\
      [`hdrstop`](../preprocessor/hdrstop.md)\
      [`include_alias`](../preprocessor/include-alias.md)\
      [`init_seg`](../preprocessor/init-seg.md)<sup>1</sup>\
      [`inline_depth`](../preprocessor/inline-depth.md)\
      [`inline_recursion`](../preprocessor/inline-recursion.md)
   :::column-end:::
   :::column span="":::
      [`intrinsic`](../preprocessor/intrinsic.md)\
      [`loop`](../preprocessor/loop.md)<sup>1</sup>\
      [`make_public`](../preprocessor/make-public.md)\
      [`managed`](../preprocessor/managed-unmanaged.md)\
      [`message`](../preprocessor/message.md)\
      [`omp`](../preprocessor/omp.md)\
      [`once`](../preprocessor/once.md)\
      [`optimize`](../preprocessor/optimize.md)\
      [`pack`](../preprocessor/pack.md)\
      [`pointers_to_members`](../preprocessor/pointers-to-members.md)<sup>1</sup>
   :::column-end:::
   :::column span="":::
      [`pop_macro`](../preprocessor/pop-macro.md)\
      [`push_macro`](../preprocessor/push-macro.md)\
      [`region`, endregion](../preprocessor/region-endregion.md)\
      [`runtime_checks`](../preprocessor/runtime-checks.md)\
      [`section`](../preprocessor/section.md)\
      [`setlocale`](../preprocessor/setlocale.md)\
      [`strict_gs_check`](../preprocessor/strict-gs-check.md)\
      [`unmanaged`](../preprocessor/managed-unmanaged.md)\
      [`vtordisp`](../preprocessor/vtordisp.md)<sup>1</sup>\
      [`warning`](../preprocessor/warning.md)
   :::column-end:::
:::row-end:::

<sup>1</sup> com suporte apenas pelo compilador C++.

## <a name="pragmas-and-compiler-options"></a>Opções de pragmas e compilador

Alguns pragmas oferecem a mesma funcionalidade que as opções de compilador. Quando um pragma está localizado no código-fonte, ele substitui o comportamento especificado pela opção do compilador. Por exemplo, se você especificou [/Zp8](../build/reference/zp-struct-member-alignment.md), poderá substituir essa configuração de compilador para seções específicas do código com [Pack](../preprocessor/pack.md):

```cmd
cl /Zp8 some_file.cpp
```

```cpp
// some_file.cpp - packing is 8
// ...
#pragma pack(push, 1) - packing is now 1
// ...
#pragma pack(pop) - packing is 8 again
// ...
```

## <a name="the-__pragma-keyword"></a>A palavra-chave __pragma ()

O compilador também dá suporte à palavra-chave específica da Microsoft **`__pragma`** , que tem a mesma funcionalidade que a **`#pragma`** diretiva. A diferença é que a **`__pragma`** palavra-chave é utilizável embutida em uma definição de macro. A **`#pragma`** diretiva não pode ser usada em uma definição de macro, porque o compilador interpreta o caractere de sinal de número (' # ') na diretiva como o [operador de cadeia de caracteres (#)](../preprocessor/stringizing-operator-hash.md).

O exemplo de código a seguir demonstra como a **`__pragma`** palavra-chave pode ser usada em uma macro. Esse código é extraído do cabeçalho *MFCDUAL. h* no exemplo de ACDUAL em "exemplos de suporte de com do compilador":

```cpp
#define CATCH_ALL_DUAL \
CATCH(COleException, e) \
{ \
_hr = e->m_sc; \
} \
AND_CATCH_ALL(e) \
{ \
__pragma(warning(push)) \
__pragma(warning(disable:6246)) /*disable _ctlState prefast warning*/ \
AFX_MANAGE_STATE(pThis->m_pModuleState); \
__pragma(warning(pop)) \
_hr = DualHandleException(_riidSource, e); \
} \
END_CATCH_ALL \
return _hr; \
```

## <a name="the-_pragma-preprocessing-operator-c99-c11"></a>O `_Pragma` operador de pré-processamento (C99, c++ 11)

`_Pragma` é semelhante à palavra-chave específica da Microsoft [`__pragma`](#the-__pragma-keyword) , exceto que faz parte do padrão. Ele foi introduzido para C no C99. Para o C++, ele foi introduzido no C++ 11.

 Ele permite colocar pragmas em uma definição de macro. Ele tem um sublinhado à esquerda `_` em vez de dois sublinhados à esquerda `__` que a palavra-chave específica da Microsoft tem, e a primeira letra é capitalizada.

O literal de cadeia de caracteres deve ser o que seria colocado seguindo uma *`#pragma`* instrução. Por exemplo:

```c
#pragma message("--the #pragma way")
_Pragma ("message( \"the _Pragma way\")") 
```

Aspas e barras invertidas devem ter escape, como mostrado acima. Uma cadeia de caracteres pragma que não é reconhecida é ignorada.

O exemplo de código a seguir demonstra como a **`_Pragma`** palavra-chave pode ser usada em uma macro semelhante a Assert quando você não deseja receber um aviso quando a expressão de condição for constante. 

A definição de macro usa o idioma do/while (0) para macros de várias instruções para que possa ser usada como se fosse uma instrução. Consulte [C macro de várias linhas](https://stackoverflow.com/questions/1067226/c-multi-line-macro-do-while0-vs-scope-block) no stack overflow para obter mais informações. A instrução _Pragma só se aplica à linha de código que a segue.

```C
// Compile with /W4

#include <stdio.h>
#include <stdlib.h>

#define MY_ASSERT(BOOL_EXPRESSION) \
    do { \
        _Pragma("warning(suppress: 4127)") /* C4127 conditional expression is constant */  \
        if (!(BOOL_EXPRESSION)) {   \
            printf("MY_ASSERT FAILED: \"" #BOOL_EXPRESSION "\" on %s(%d)", __FILE__, __LINE__); \
            exit(-1); \
        } \
    } while (0)

int main()
{
    MY_ASSERT(0 && "Note that there is no warning: C4127 conditional expression is constant");

    return 0;
}
```

## <a name="see-also"></a>Confira também

[Referência de pré-processador do C/C++](../preprocessor/c-cpp-preprocessor-reference.md)\
[Pragmas de C](../c-language/c-pragmas.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
