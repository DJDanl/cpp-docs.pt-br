---
title: COMM
ms.date: 12/06/2019
f1_keywords:
- COMM
helpviewer_keywords:
- COMM directive
ms.assetid: a23548c4-ad04-41fa-91da-945f228de742
ms.openlocfilehash: 0ea02806cae3295af0846baa6c4e9049d54c271b
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75315167"
---
# <a name="comm"></a>COMM

Cria uma variável pouca com os atributos especificados na *definição*.

## <a name="syntax"></a>Sintaxe

> Definição de **comm** *⟦* __,__ *Definition* ... ⟧

## <a name="remarks"></a>Comentários

As variáveis pouca são alocadas pelo vinculador e não podem ser inicializadas. Isso significa que você não pode depender do local ou da sequência dessas variáveis.

Cada *definição* tem o seguinte formato:

⟦*tipo de idioma*⟧ ⟦**próximo** | rótulo ⟧ **:** _tipo_⟦ **:** _contagem_⟧

Os argumentos de *tipo de idioma*, **próximo**e **distante** são válidos somente em MASM de 32 bits.

O *tipo de idioma* opcional define as convenções de nomenclatura para o nome que segue. Ele substitui qualquer idioma especificado pelo **.** Diretiva de modelo. O opcional **próximo** ou **longe** substitui o modelo de memória atual. O *rótulo* é o nome da variável. O *tipo* pode ser qualquer especificador de tipo ([byte](byte-masm.md), [Word](word.md)e assim por diante) ou um inteiro especificando o número de bytes. A *contagem* opcional especifica o número de elementos no objeto de dados declarado. A *contagem* padrão é um.

## <a name="example"></a>Exemplo

Este exemplo cria uma matriz de elementos de 512 bytes:

```asm
COMM FAR ByteArray:BYTE:512
```

## <a name="see-also"></a>Veja também

[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
