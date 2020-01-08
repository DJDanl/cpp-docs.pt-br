---
title: ALIGN (MASM)
ms.date: 12/17/2019
f1_keywords:
- align
helpviewer_keywords:
- ALIGN directive
ms.assetid: 1c386b23-439f-4ec3-a6de-74427b25e47f
ms.openlocfilehash: 700721768deaf92e88b32a97e68c6e017219d19d
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75316584"
---
# <a name="align"></a>ALIGN

A diretiva **align** alinha o próximo elemento de dados ou instrução em um endereço que é um múltiplo de seu parâmetro. O parâmetro deve ser uma potência de 2 (por exemplo, 1, 2, 4 e assim por diante) que seja menor ou igual ao alinhamento de segmento.

## <a name="syntax"></a>Sintaxe

> **Alinhar** ⟦*constanty*⟧

## <a name="remarks"></a>Comentários

A diretiva **align** permite que você especifique o deslocamento inicial de um elemento de dados ou uma instrução. Os dados alinhados podem melhorar o desempenho, às custas do espaço desperdiçado entre os elementos de dados. Melhorias de desempenho grandes podem ser vistas quando os acessos aos dados estão em limites que se encaixam nas linhas de cache. Acessa em limites naturais para tipos nativos significa menos tempo gasto no microcódigo de realinhamento de hardware interno.

A necessidade de instruções alinhadas é rara em processadores modernos que usam um modelo de endereçamento simples, mas pode ser necessário para destinos de salto em código mais antigo para outros modelos de endereçamento.

Quando os dados são alinhados, o espaço ignorado é preenchido com zeros. Quando as instruções são alinhadas, o espaço ignorado é preenchido com as instruções de NOP de tamanho apropriado.

## <a name="see-also"></a>Veja também

[Até mesmo](even.md)\
[Referência de diretivas](directives-reference.md)\
[MASM BNF Grammar](masm-bnf-grammar.md)
