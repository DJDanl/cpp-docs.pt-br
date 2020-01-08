---
title: LOCAL (MASM)
ms.date: 12/16/2019
f1_keywords:
- Local
helpviewer_keywords:
- LOCAL directive
ms.assetid: 76147e2d-23ca-4f1e-8817-81428becd113
ms.openlocfilehash: 2bef6b26f1b922be6512bd6ebe8e0b2627e86f45
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75317143"
---
# <a name="local"></a>LOCAL

Na primeira diretiva, em uma macro, **local** define os rótulos que são exclusivos de cada instância da macro.

## <a name="syntax"></a>Sintaxe

> *LocalId de ⟦* local, *LocalId* ... ⟧
>
> *Rótulo* **LocalId** ⟦ __\[__ *contagem* __]__ ⟧ ⟦ __:__ *qualifiedtype*⟧ ⟦ __,__ *etiqueteid* ⟦ __\[__ *contagem* __]__ ⟧ ⟦*qualifiedtype*⟧... ⟧

## <a name="remarks"></a>Comentários

Na segunda diretiva, dentro de uma definição de procedimento (**proc**), o **local** cria variáveis baseadas em pilha que existem para a duração do procedimento. O *labelID* pode ser uma variável simples ou uma matriz que contenha elementos de *contagem* , em que *Count* é uma expressão constante.

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
