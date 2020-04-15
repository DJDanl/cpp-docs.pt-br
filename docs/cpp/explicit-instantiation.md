---
title: Instanciação explícita
ms.date: 11/04/2016
helpviewer_keywords:
- templates, instantiation
- explicit instantiation
- instantiation, explicit
ms.assetid: 8b0d4e32-45a6-49d5-8041-1ebdd674410e
ms.openlocfilehash: 0b1290bc23c56c0f35ddd3bb93e37ce4f5f0d2ed
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361954"
---
# <a name="explicit-instantiation"></a>Instanciação explícita

Você pode usar uma criação de instanciação explícita para criar uma instanciação de uma classe ou função com modelo sem realmente usá-la no código. Como isso é útil quando você está criando arquivos de biblioteca (.lib) que usam modelos de distribuição, definições de modelo sem instanciação não são colocadas em arquivos de objeto (.obj).

Este código instancia `MyStack` explicitamente para variáveis **int** e seis itens:

```cpp
template class MyStack<int, 6>;
```

Essa instrução cria uma instanciação de `MyStack` sem reservar nenhum armazenamento para um objeto. O código é gerado para todos os membros.

A linha a seguir cria instanciações explicitamente somente para a função membro do construtor:

```cpp
template MyStack<int, 6>::MyStack( void );
```

Você pode instanciar explicitamente modelos de função usando um argumento de tipo específico para redeclará-los, como mostrado no exemplo em [Instanciação do Modelo de Função](../cpp/function-template-instantiation.md).

Você pode usar a **palavra-chave extern** para evitar a instanciação automática dos membros. Por exemplo:

```cpp
extern template class MyStack<int, 6>;
```

De forma semelhante, você pode marcar membros específicos como sendo externos e sem instanciação:

```cpp
extern template MyStack<int, 6>::MyStack( void );
```

Você pode usar a palavra-chave **extern** para impedir que o compilador gere o mesmo código de instanciação em mais de um módulo de objeto. Você deve instanciar a função do modelo usando os parâmetros de modelo explícitos especificados em pelo menos um módulo vinculado, caso a função seja chamada, ou receberá um erro do vinculador quando o programa for criado.

> [!NOTE]
> A **palavra-chave extern** na especialização só se aplica às funções dos membros definidas fora do corpo da classe. As funções definidas na declaração de classe são consideradas funções embutidas e sempre têm instanciações.

## <a name="see-also"></a>Confira também

[Modelos de função](../cpp/function-templates.md)
