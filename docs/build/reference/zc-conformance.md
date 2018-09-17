---
title: /ZC (conformidade) | Microsoft Docs
ms.custom: ''
ms.date: 03/06/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /zc
dev_langs:
- C++
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3fd2ec208e872e05f8329bf5e077a74403d0c612
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45716047"
---
# <a name="zc-conformance"></a>/Zc (conformidade)

Você pode usar o **/Zc** opções do compilador para especificar o comportamento do compilador padrão ou específico da Microsoft.

## <a name="syntax"></a>Sintaxe

> **/ Zc:**_opção_{,_opção_}

## <a name="remarks"></a>Comentários

Quando o Visual Studio tiver implementado uma extensão do C ou C++ que não é compatível com o padrão, você pode usar um `/Zc` opção de conformidade para especificar o comportamento de conformidade padrão ou específico da Microsoft. Para algumas opções, o comportamento específico da Microsoft é o padrão, para evitar alterações significativas em larga escala para o código existente. Em outros casos, o padrão é o comportamento padrão, onde melhorias na segurança, desempenho ou compatibilidade superam os custos de alterações significativas. A configuração padrão de cada opção de conformidade com a pode mudar em versões mais recentes do Visual Studio. Para obter mais informações sobre cada opção de conformidade, consulte o tópico a opção específica. O [/permissive--](permissive-standards-conformance.md) opção de compilador define implicitamente as opções de conformidade que não são definidas por padrão para a configuração de acordo com as conformidades.

Esses são os `/Zc` opções do compilador:

|Opção|Comportamento|
|---|---|
|[alignedNew\[-\]](zc-alignednew.md)|Habilitar C + + 17 excessivamente alinhados alocação dinâmica (ativado por padrão no C + + 17).|
|[auto\[-\]](zc-auto-deduce-variable-type.md)|Impor o novo significado Standard C++ para `auto` (em por padrão).|
|[cplusplus\[-\]](zc-cplusplus.md)|Habilitar o **cplusplus** macro para relatar o padrão com suporte (desativado por padrão).|
|[externConstexpr\[-\]](zc-externconstexpr.md)|Habilitar vinculação externa para `constexpr` variáveis (desativado por padrão).|
|[forScope\[-\]](zc-forscope-force-conformance-in-for-loop-scope.md)|Impor Standard C++ `for` regras de escopo (em por padrão).|
|[implicitNoexcept\[-\]](zc-implicitnoexcept-implicit-exception-specifiers.md)|Habilitar implícita `noexcept` em funções necessárias (em por padrão).|
|[inline\[-\]](zc-inline-remove-unreferenced-comdat.md)|Remover função não referenciada ou dados se forem COMDAT ou tiverem apenas ligação interna (desativado por padrão).|
|[noexceptTypes\[-\]](zc-noexcepttypes.md)|Impor regras de noexcept de c++17 C + + (em por padrão em c++17 ou posterior).|
|[referenceBinding\[-\]](zc-referencebinding-enforce-reference-binding-rules.md)|Um UDT temporário não será associado a uma referência de lvalue non-const (desativado por padrão).|
|[rvalueCast\[-\]](zc-rvaluecast-enforce-type-conversion-rules.md)|Aplicar regras de conversão de tipo explícito do C++ padrão (desativado por padrão).|
|[sizedDealloc\[-\]](zc-sizeddealloc-enable-global-sized-dealloc-functions.md)|Habilitar funções de desalocação dimensionada global de 14 C + + (em por padrão).|
|[strictStrings\[-\]](zc-strictstrings-disable-string-literal-type-conversion.md)|Desabilitar o literal de cadeia de caracteres para `char*` ou `wchar_t*` conversão (desativado por padrão).|
|[Ternário\[-\]](zc-ternary.md)|Impor regras de operador condicional em tipos de operando (desativado por padrão).|
|[threadSafeInit\[-\]](zc-threadsafeinit-thread-safe-local-static-initialization.md)|Habilitar inicialização estática de local thread-safe (em por padrão).|
|[throwingNew\[-\]](zc-throwingnew-assume-operator-new-throws.md)|Suponha que `operator new` gera em caso de falha (desativado por padrão).|
|[trígrafos\[-\]](zc-trigraphs-trigraphs-substitution.md)|Habilite trígrafos (obsoletos, desativado por padrão).|
|[twoPhase-](zc-twophase.md)|Use análise de comportamento (em conformidade com por padrão) do modelo não conformes.|
|[wchar_t\[-\]](zc-wchar-t-wchar-t-is-native-type.md)|`wchar_t` é um tipo nativo, não é um typedef (em por padrão).|

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

## <a name="see-also"></a>Consulte também

[Opções do Compilador](compiler-options.md)<br/>
[Definindo opções do compilador](setting-compiler-options.md)
