---
title: Pragma pointers_to_members
ms.date: 08/29/2019
f1_keywords:
- pointers_to_members_CPP
- vc-pragma.pointers_to_members
helpviewer_keywords:
- class members, pointers to
- pragmas, pointers_to_members
- members, pointers to
- pointers_to_members pragma
ms.assetid: 8325428c-c90a-4aed-9e82-cb1dda23f4ca
ms.openlocfilehash: fb5b277252b6c1422a87c5f2a2e2b7230ec49632
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70219066"
---
# <a name="pointers_to_members-pragma"></a>Pragma pointers_to_members

**C++Determinados**

Especifica se um ponteiro para um membro de classe pode ser declarado antes de sua definição de classe associada. Usado para controlar o tamanho do ponteiro e o código necessário para interpretar o ponteiro.

## <a name="syntax"></a>Sintaxe

> **#pragma pointers_to_members (** *declaração de ponteiro* [ **,** *a representação mais geral* ])

## <a name="remarks"></a>Comentários

Você pode inserir um pragma **pointers_to_members** em seu arquivo de origem como uma alternativa ao uso das opções do compilador [/VMB ou/VMG](../build/reference/vmb-vmg-representation-method.md) ou das [palavras-chave de herança](../cpp/inheritance-keywords.md).

O argumento *declaração de ponteiro* especifica se você declarou um ponteiro para um membro antes ou depois da definição da função associada. O argumento de *declaração de ponteiro* é um dos dois símbolos a seguir:

| Argumento | Comentários |
|--------------|--------------|
| **full_generality** | Gerencia o código seguro, às vezes não ideal. Você usará **full_generality** se qualquer ponteiro para um membro for declarado antes da definição de classe associada. Esse argumento sempre usa a representação de ponteiro especificada pelo argumento de *representação mais geral* . Equivalente a /vmg. |
| **best_case** | Gera o código seguro, ideal usando a melhor representação de letras maiúsculas e minúsculas para todos os ponteiros dos membros. Requer a definição da classe antes de declarar um ponteiro para um membro da classe. O padrão é **best_case**. |

O argumento de *representação mais geral* especifica a menor representação de ponteiro que o compilador pode usar com segurança para fazer referência a qualquer ponteiro para um membro de uma classe em uma unidade de tradução. O argumento pode ser um destes valores:

| Argumento | Comentários |
|--------------|--------------|
| **single_inheritance** | A representação mais geral é de herança única, ponteiro para uma função de membro. Causa um erro se o modelo de herança de uma definição de classe para a qual um ponteiro para um membro é declarado nunca for múltiplo ou virtual. |
| **multiple_inheritance** | A representação mais geral é de herança múltipla, ponteiro para uma função de membro. Causa um erro se o modelo de herança de uma definição de classe para a qual um ponteiro para um membro é declarado nunca for virtual. |
| **virtual_inheritance** | A representação mais geral é de herança virtual, ponteiro para uma função de membro. Nunca causa um erro. **virtual_inheritance** é o argumento padrão quando `#pragma pointers_to_members(full_generality)` é usado. |

> [!CAUTION]
> Aconselhamos que você coloque o pragma **pointers_to_members** somente no arquivo de código-fonte que deseja afetar e somente após qualquer `#include` diretivas. Essa prática diminui o risco de o pragma afetar outros arquivos e de você especificar acidentalmente várias definições para a mesma variável, função, ou nome da classe.

## <a name="example"></a>Exemplo

```cpp
//   Specify single-inheritance only
#pragma pointers_to_members( full_generality, single_inheritance )
```

**FINAL C++ específico**

## <a name="see-also"></a>Consulte também

[Diretivas pragma e a palavra-chave __pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)
