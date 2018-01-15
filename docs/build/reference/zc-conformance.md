---
title: -Zc (conformidade) | Microsoft Docs
ms.custom: 
ms.date: 9/29/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: /zc
dev_langs: C++
helpviewer_keywords:
- /Zc compiler options [C++]
- -Zc compiler options [C++]
- Conformance compiler options
- Zc compiler options [C++]
ms.assetid: db1cc175-6e93-4a2e-9396-c3725d2d8f71
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 86b12604a5348c3a1aabb33c7e13a4e7a3c57932
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zc-conformance"></a>/Zc (conformidade)

Você pode usar o **/Zc** opções do compilador para especificar o comportamento do compilador padrão ou específico da Microsoft.

## <a name="syntax"></a>Sintaxe

> / Zc:_opção_{,_opção_}

## <a name="remarks"></a>Comentários

Quando o Visual Studio implementou uma extensão do C ou C++ que não é compatível com o padrão, você pode usar um `/Zc` opção de conformidade para especificar o comportamento padrão conformes ou específico da Microsoft. Para algumas opções, o comportamento específico da Microsoft é o padrão, para evitar alterações significativas em larga escala para o código existente. Em outros casos, o padrão é o comportamento padrão, onde melhorias na segurança, desempenho ou compatibilidade superam os custos de alterações significativas. A configuração padrão de cada opção de conformidade pode ser alteradas em versões mais recentes do Visual Studio. Para obter mais informações sobre cada opção de conformidade, consulte o tópico para a opção específica.

Estes são os `/Zc` opções do compilador:

|Opção|Comportamento|
|---|---|
|[alignedNew\[-\]](zc-alignednew.md)|Habilitar C++ 17 excesso alinhados alocação dinâmica (em por padrão em C++ 17).|
|[Automático\[-\]](zc-auto-deduce-variable-type.md)|Impor o novo significado Standard C++ para `auto` (em por padrão).|
|[externConstexpr\[-\]](zc-externconstexpr.md)|Habilitar vínculo externo para `constexpr` variáveis (desativado por padrão).|
|[forScope\[-\]](zc-forscope-force-conformance-in-for-loop-scope.md)|Impor Standard C++ `for` regras de escopo (em por padrão).|
|[implicitNoexcept\[-\]](zc-implicitnoexcept-implicit-exception-specifiers.md)|Habilitar implícita `noexcept` em funções requeridas (em por padrão).|
|[embutido\[-\]](zc-inline-remove-unreferenced-comdat.md)|Remover dados ou função não referenciado COMDAT ou tiverem apenas ligação interna (desativada por padrão).|
|[noexceptTypes\[-\]](zc-noexcepttypes.md)|Aplicar regras de noexcept de 17 C + + (em por padrão em C++ 17 ou posterior).|
|[referenceBinding\[-\]](zc-referencebinding-enforce-reference-binding-rules.md)|Um UDT temporário não será associado a uma referência não const lvalue (desligado por padrão).|
|[rvalueCast\[-\]](zc-rvaluecast-enforce-type-conversion-rules.md)|Aplicar regras de conversão de tipo explícito de C++ padrão (desativado por padrão).|
|[sizedDealloc\[-\]](zc-sizeddealloc-enable-global-sized-dealloc-functions.md)|Habilitar C + + 14 global desalocação dimensionada funções (em por padrão).|
|[strictStrings\[-\]](zc-strictstrings-disable-string-literal-type-conversion.md)|Desabilitar literal de cadeia de caracteres para `char*` ou `wchar_t*` conversão (desativado por padrão).|
|[threadSafeInit\[-\]](zc-threadsafeinit-thread-safe-local-static-initialization.md)|Habilitar a inicialização local estática do thread-safe (em por padrão).|
|[throwingNew\[-\]](zc-throwingnew-assume-operator-new-throws.md)|Suponha que `operator new` lança em caso de falha (desativado por padrão).|
|[trigraphs\[-\]](zc-trigraphs-trigraphs-substitution.md)|Habilite trígrafos (obsoletos, desativado por padrão).|
|[wchar_t\[-\]](zc-wchar-t-wchar-t-is-native-type.md)|`wchar_t`é um tipo nativo, não é um typedef (em por padrão).|

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

## <a name="see-also"></a>Consulte também

[Opções do Compilador](compiler-options.md)  
[Definindo opções do compilador](setting-compiler-options.md)
