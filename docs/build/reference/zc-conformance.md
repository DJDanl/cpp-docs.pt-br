---
title: /Zc (conformidade)
ms.date: 03/06/2018
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
ms.openlocfilehash: 6d6d3b7736fd1775372a3b2093c53e177db5099e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234348"
---
# <a name="zc-conformance"></a>`/Zc`Conformidade

Você pode usar as **`/Zc`** Opções do compilador para especificar o comportamento do compilador padrão ou específico da Microsoft.

## <a name="syntax"></a>Sintaxe

> **`/Zc:`**_opção_{,_opção_}

## <a name="remarks"></a>Comentários

Quando o Visual Studio implementou uma extensão para C ou C++ que não é compatível com o padrão, você pode usar uma **`/Zc`** opção de conformidade para especificar o comportamento padrão ou específico da Microsoft. Para algumas opções, o comportamento específico da Microsoft é o padrão, para evitar alterações significativas de grande escala para o código existente. Em outros casos, o padrão é o comportamento padrão, no qual melhorias na segurança, no desempenho ou na compatibilidade superam os custos de alterações significativas. A configuração padrão de cada opção de conformidade pode ser alterada nas versões mais recentes do Visual Studio. Para obter mais informações sobre cada opção de conformidade, consulte o tópico para a opção específica. A [`/permissive-`](permissive-standards-conformance.md) opção do compilador define implicitamente as opções de conformidade que não são definidas por padrão para sua configuração compatível.

Estas são as **`/Zc`** Opções do compilador:

| Opção | Comportamento |
|--|--|
| [`/Zc:alignedNew`](zc-alignednew.md) | Habilite a alocação dinâmica alinhada em C++ 17 (ativada por padrão no C++ 17). |
| [`/Zc:auto`](zc-auto-deduce-variable-type.md) | Impor o novo significado padrão do C++ para **`auto`** (ativado por padrão). |
| [`/Zc__cplusplus`](zc-cplusplus.md) | Habilite a `__cplusplus` macro para relatar o padrão com suporte (desativado por padrão). |
| [`/Zc:externConstexpr`](zc-externconstexpr.md) | Habilitar vínculo externo para **`constexpr`** variáveis (desativado por padrão). |
| [`/Zc:forScope`](zc-forscope-force-conformance-in-for-loop-scope.md) | Impor **`for`** regras de escopo C++ padrão (ativado por padrão). |
| [`/ZcimplicitNoexcept`](zc-implicitnoexcept-implicit-exception-specifiers.md) | Habilitar o implícito **`noexcept`** nas funções necessárias (ativado por padrão). |
| [`/Zc:inline`](zc-inline-remove-unreferenced-comdat.md) | Remova a função ou os dados sem referência se ele for COMDAT ou tiver somente vínculo interno (desativado por padrão). |
| [`/Zc:noexceptTypes`](zc-noexcepttypes.md) | Impor regras C++ 17 **`noexcept`** (ativadas por padrão no c++ 17 ou posterior). |
| [`/Zc:referenceBinding`](zc-referencebinding-enforce-reference-binding-rules.md) | Um UDT temporário não será associado a uma referência lvalue não const (desativado por padrão). |
| [`/Zc:rvalueCast`](zc-rvaluecast-enforce-type-conversion-rules.md) | Impor regras de conversão de tipo C++ Explicit padrão (desativado por padrão). |
| [`/Zc:sizedDealloc`](zc-sizeddealloc-enable-global-sized-dealloc-functions.md) | Habilitar funções de desalocação de tamanho global do C++ 14 (ativada por padrão). |
| [`/Zc:strictStrings`](zc-strictstrings-disable-string-literal-type-conversion.md) | Desabilite literal de cadeia de caracteres para `char*` ou `wchar_t*` conversão (desativado por padrão). |
| [`/Zc:ternary`](zc-ternary.md) | Impor regras de operador condicional em tipos de operando (desativado por padrão). |
| [`/Zc:threadSafeInit`](zc-threadsafeinit-thread-safe-local-static-initialization.md) | Habilitar a inicialização estática local com segurança de thread (ativada por padrão). |
| [`/Zc:throwingNew`](zc-throwingnew-assume-operator-new-throws.md) | Suponha que o **`operator new`** gere em caso de falha (desativado por padrão). |
| [`/Zc:trigraphs`](zc-trigraphs-trigraphs-substitution.md) | Habilitar trigrafos (obsoleto, desativado por padrão). |
| [`/Zc:twoPhase`](zc-twophase.md) | Use o comportamento de análise de modelo não compatível (em conformidade por padrão). |
| [`/Zc:wchar_t`](zc-wchar-t-wchar-t-is-native-type.md) | **`wchar_t`** é um tipo nativo, não um typedef (ativado por padrão). |

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

## <a name="see-also"></a>Confira também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
