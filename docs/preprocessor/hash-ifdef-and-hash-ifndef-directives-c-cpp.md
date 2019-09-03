---
title: '#Diretivas ifdef e #ifndef (C/C++)'
ms.date: 08/29/2019
f1_keywords:
- '#ifndef'
- '#ifdef'
helpviewer_keywords:
- '#ifdef directive'
- preprocessor, directives
- ifdef directive (#ifdef)
- ifndef directive (#ifndef)
- '#ifndef directive'
ms.assetid: 2b0be69d-9e72-45d8-8e24-e4130fb2455b
ms.openlocfilehash: 433076388f3646b19d75a907c6b2254098096688
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70220110"
---
# <a name="ifdef-and-ifndef-directives-cc"></a>diretivas de #ifdef e #ifndef (CC++/)

As diretivas **#ifdef** e **#ifndef** têm o mesmo efeito que a diretiva [#if](hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md) quando ela é usada com o operador **definido** .

## <a name="syntax"></a>Sintaxe

> **#ifdef** *identificador* do\
> **#ifndef** *identificador* do

Essas diretivas são equivalentes a:

> **#if definido** *identificador* do\
> **#if! definido** *identificador* do

## <a name="remarks"></a>Comentários

Você pode usar as diretivas **#ifdef** e **#ifndef** em `#if` qualquer lugar que possam ser usadas. A instrução de *identificador* de **#ifdef** é `#if 1` equivalente a quando o *identificador* foi definido. É equivalente a `#if 0` quando o `#undef` identificador não foi definido ou foi indefinido pela diretiva. Essas políticas verificam somente a presença ou ausência de identificadores definidos com `#define`, não para identificadores declarados no código-fonte C ou C++.

Essas políticas são fornecidas somente para compatibilidade com versões anteriores da linguagem. A expressão constante **definida (** *identificador* **)** usada com a `#if` diretiva é preferida.

A diretiva **#ifndef** verifica o oposto da condição verificada por **#ifdef**. Se o identificador não tiver sido definido ou se sua definição tiver sido removida com `#undef`, a condição será true (diferente de zero). Caso contrário, a condição será false (0).

**Seção específica da Microsoft**

O *identificador* pode ser passado da linha de comando usando a opção [/d](../build/reference/d-preprocessor-definitions.md) . Até 30 macros podem ser especificadas com `/D`.

A diretiva de **#ifdef** é útil para verificar se existe uma definição, porque uma definição pode ser passada da linha de comando. Por exemplo:

```cpp
// ifdef_ifndef.CPP
// compile with: /Dtest /c
#ifndef test
#define final
#endif
```

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)
