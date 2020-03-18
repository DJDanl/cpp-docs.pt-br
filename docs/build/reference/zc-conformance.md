---
title: /Zc (conformidade)
ms.date: 03/06/2018
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
ms.openlocfilehash: 4422524deab2a749c96d5e967bc3223d0c9c9873
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438662"
---
# <a name="zc-conformance"></a>/Zc (conformidade)

Você pode usar as opções do compilador **/Zc** para especificar o comportamento do compilador padrão ou específico da Microsoft.

## <a name="syntax"></a>Sintaxe

> **/Zc:** _opção_{,_opção_}

## <a name="remarks"></a>Comentários

Quando o Visual Studio implementou uma extensão para C C++ ou que não é compatível com o padrão, você pode usar uma opção de conformidade `/Zc` para especificar o comportamento padrão ou específico da Microsoft. Para algumas opções, o comportamento específico da Microsoft é o padrão, para evitar alterações significativas de grande escala para o código existente. Em outros casos, o padrão é o comportamento padrão, no qual melhorias na segurança, no desempenho ou na compatibilidade superam os custos de alterações significativas. A configuração padrão de cada opção de conformidade pode ser alterada nas versões mais recentes do Visual Studio. Para obter mais informações sobre cada opção de conformidade, consulte o tópico para a opção específica. A opção de compilador [/permissive-](permissive-standards-conformance.md) define implicitamente as opções de conformidade que não são definidas por padrão para sua configuração compatível.

Estas são as opções do compilador `/Zc`:

|{1&gt;Opção&lt;1}|Comportamento|
|---|---|
|[alignedNew\[-\]](zc-alignednew.md)|Habilite a alocação dinâmica alinhada em C++ 17 (ativada por padrão no C++ 17).|
|[-de\[automática \]](zc-auto-deduce-variable-type.md)|Impor o novo significado C++ padrão para `auto` (ativado por padrão).|
|[__cplusplus\[-\]](zc-cplusplus.md)|Habilite a macro **__cplusplus** para relatar o padrão com suporte (desativado por padrão).|
|[externConstexpr\[-\]](zc-externconstexpr.md)|Habilitar vínculo externo para variáveis de `constexpr` (desativado por padrão).|
|[forScope\[-\]](zc-forscope-force-conformance-in-for-loop-scope.md)|Impor regras C++ de escopo de `for` padrão (ativado por padrão).|
|[implicitNoexcept\[-\]](zc-implicitnoexcept-implicit-exception-specifiers.md)|Habilitar `noexcept` implícitas em funções necessárias (ativada por padrão).|
|[-\[embutidos \]](zc-inline-remove-unreferenced-comdat.md)|Remova a função ou os dados sem referência se ele for COMDAT ou tiver somente vínculo interno (desativado por padrão).|
|[noexceptTypes\[-\]](zc-noexcepttypes.md)|Impor regras noexcept de C++ 17 (ativado por padrão no C++ 17 ou posterior).|
|[\[referencebinding -\]](zc-referencebinding-enforce-reference-binding-rules.md)|Um UDT temporário não será associado a uma referência lvalue não const (desativado por padrão).|
|[rvalueCast\[-\]](zc-rvaluecast-enforce-type-conversion-rules.md)|Impor regras C++ de conversão de tipo explícito padrão (desativado por padrão).|
|[sizedDealloc\[-\]](zc-sizeddealloc-enable-global-sized-dealloc-functions.md)|Habilitar funções de desalocação de tamanho global do C++ 14 (ativada por padrão).|
|[strictStrings\[-\]](zc-strictstrings-disable-string-literal-type-conversion.md)|Desabilite o literal de cadeia de caracteres para `char*` ou `wchar_t*` conversão (desativado por padrão).|
|[ternário\[-\]](zc-ternary.md)|Impor regras de operador condicional em tipos de operando (desativado por padrão).|
|[threadSafeInit\[-\]](zc-threadsafeinit-thread-safe-local-static-initialization.md)|Habilitar a inicialização estática local com segurança de thread (ativada por padrão).|
|[throwingNew\[-\]](zc-throwingnew-assume-operator-new-throws.md)|Suponha que `operator new` gera em caso de falha (desativado por padrão).|
|[trigrafos\[-\]](zc-trigraphs-trigraphs-substitution.md)|Habilitar trigrafos (obsoleto, desativado por padrão).|
|[twoPhase](zc-twophase.md)|Use o comportamento de análise de modelo não compatível (em conformidade por padrão).|
|[wchar_t\[-\]](zc-wchar-t-wchar-t-is-native-type.md)|`wchar_t` é um tipo nativo, não um typedef (ativado por padrão).|

Para obter mais informações sobre problemas de conformidade C++no Visual, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
