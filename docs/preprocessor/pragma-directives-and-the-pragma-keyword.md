---
title: Diretivas Pragma e a palavra-chave __pragma
ms.date: 08/29/2019
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
ms.openlocfilehash: 6cfbcd325dc895719bad5dccc9c19bcda90cdaa0
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74858068"
---
# <a name="pragma-directives-and-the-__pragma-keyword"></a>Diretivas Pragma e a palavra-chave __pragma

As diretivas pragma especificam recursos de compilador específicos do computador ou do sistema operacional. A palavra-chave **__pragma** , que é específica para o compilador da Microsoft, permite que você codifique as diretivas pragma nas definições de macro.

## <a name="syntax"></a>Sintaxe

> **#pragma** *cadeia de caracteres de token*\
> **__pragma (** *cadeia de caracteres de token* **)**

## <a name="remarks"></a>Comentários

Cada implementação de C e C++ oferece suporte a alguns recursos exclusivos para seu computador host ou sistema operacional. Alguns programas, por exemplo, devem exercer um controle preciso sobre o local dos dados na memória ou controlar a maneira como certas funções recebem parâmetros. As diretivas de **#pragma** oferecem uma maneira para cada compilador oferecer recursos específicos de computador e de sistema operacional, ao mesmo tempo em que mantém a compatibilidade C++ geral com o C e os idiomas.

Os pragmas são específicos do sistema operacional ou da máquina por definição e são normalmente diferentes para cada compilador. Os pragmas podem ser usados em Diretivas condicionais, para fornecer uma nova funcionalidade de pré-processador ou para fornecer informações definidas para a implementação ao compilador.

O *token-String* é uma série de caracteres que fornece instruções e argumentos específicos do compilador, se houver. O sinal numérico ( **#** ) deve ser o primeiro caractere que não seja espaço em branco na linha que contém o pragma. Caracteres de espaço em branco podem separar o sinal numérico e a palavra "pragma". A seguir **#pragma**, escreva qualquer texto que o tradutor possa analisar como pré-processamento de tokens. O argumento para **#pragma** está sujeito à expansão de macro.

O compilador emite um aviso quando encontra um pragma que ele não reconhece e continua a compilação.

Os compiladores C e C++ da Microsoft reconhecem os seguintes pragmas:

||||
|-|-|-|
|[alloc_text](../preprocessor/alloc-text.md)|[auto_inline](../preprocessor/auto-inline.md)|[bss_seg](../preprocessor/bss-seg.md)|
|[check_stack](../preprocessor/check-stack.md)|[code_seg](../preprocessor/code-seg.md)|[comment](../preprocessor/comment-c-cpp.md)|
|[componente](../preprocessor/component.md)|[conformidade](../preprocessor/conform.md) <sup>1</sup>|[const_seg](../preprocessor/const-seg.md)|
|[data_seg](../preprocessor/data-seg.md)|[preterido](../preprocessor/deprecated-c-cpp.md)|[detect_mismatch](../preprocessor/detect-mismatch.md)|
|[fenv_access](../preprocessor/fenv-access.md)|[float_control](../preprocessor/float-control.md)|[fp_contract](../preprocessor/fp-contract.md)|
|[function](../preprocessor/function-c-cpp.md)|[hdrstop](../preprocessor/hdrstop.md)|[include_alias](../preprocessor/include-alias.md)|
|[init_seg](../preprocessor/init-seg.md) <sup>1</sup>|[inline_depth](../preprocessor/inline-depth.md)|[inline_recursion](../preprocessor/inline-recursion.md)|
|[intrínseco](../preprocessor/intrinsic.md)|[loop](../preprocessor/loop.md) <sup>1</sup>|[make_public](../preprocessor/make-public.md)|
|[administra](../preprocessor/managed-unmanaged.md)|[message](../preprocessor/message.md)|[omp](../preprocessor/omp.md)|
|[uma vez](../preprocessor/once.md)|[otimizar](../preprocessor/optimize.md)|[pack](../preprocessor/pack.md)|
|[pointers_to_members](../preprocessor/pointers-to-members.md) <sup>1</sup>|[pop_macro](../preprocessor/pop-macro.md)|[push_macro](../preprocessor/push-macro.md)|
|[region, endregion](../preprocessor/region-endregion.md)|[runtime_checks](../preprocessor/runtime-checks.md)|[seção](../preprocessor/section.md)|
|[setlocale](../preprocessor/setlocale.md)|[strict_gs_check](../preprocessor/strict-gs-check.md)|[não gerenciados](../preprocessor/managed-unmanaged.md)|
|[vtordisp](../preprocessor/vtordisp.md) <sup>1</sup>|[warning](../preprocessor/warning.md)||

<sup>1</sup> com suporte apenas pelo C++ compilador.

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

O compilador também dá suporte à palavra-chave **__pragma** específica da Microsoft, que tem a mesma funcionalidade que a diretiva **#pragma** . A diferença é que a palavra-chave **__pragma** é utilizável embutida em uma definição de macro. A diretiva **#pragma** não é utilizável em uma definição de macro, porque o compilador interpreta o caractere de sinal de número (' # ') na diretiva como o [operador de cadeia de caracteres (#)](../preprocessor/stringizing-operator-hash.md).

O exemplo de código a seguir demonstra como a palavra-chave **__pragma** pode ser usada em uma macro. Esse código foi retirado do cabeçalho mfcdual.h no exemplo ACDUAL em "Exemplos de suporte a COM de compilador":

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

## <a name="see-also"></a>Consulte também

[Referência deC++ C/pré-processador](../preprocessor/c-cpp-preprocessor-reference.md)\
\ de [pragmas C](../c-language/c-pragmas.md)
[Palavras-chave](../cpp/keywords-cpp.md)
