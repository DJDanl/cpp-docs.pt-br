---
title: ALIGN (MASM)
ms.date: 01/02/2019
f1_keywords:
- align
helpviewer_keywords:
- ALIGN directive
ms.assetid: 1c386b23-439f-4ec3-a6de-74427b25e47f
ms.openlocfilehash: 22b18f2e238c780377b84fc2be3eb6678686bb73
ms.sourcegitcommit: 9ee5df398bfd30a42739632de3e165874cb675c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/22/2019
ms.locfileid: "74399280"
---
# <a name="align-masm"></a>ALIGN (MASM)

A diretiva **align** alinha o próximo elemento de dados ou instrução em um endereço que é um múltiplo de seu parâmetro. O parâmetro deve ser uma potência de 2 (por exemplo, 1, 2, 4 e assim por diante) que seja menor ou igual ao alinhamento de segmento.

## <a name="syntax"></a>Sintaxe

> **Alinhar** *número*de ⟦ ⟧

## <a name="remarks"></a>Comentários

A diretiva **align** permite que você especifique o deslocamento inicial de um elemento de dados ou uma instrução. Os dados alinhados podem melhorar o desempenho, às custas do espaço desperdiçado entre os elementos de dados. Melhorias de desempenho grandes podem ser vistas quando os acessos aos dados estão em limites que se encaixam nas linhas de cache. Acessa em limites naturais para tipos nativos significa menos tempo gasto no microcódigo de realinhamento de hardware interno.

A necessidade de instruções alinhadas é rara em processadores modernos que usam um modelo de endereçamento simples, mas pode ser necessário para destinos de salto em código mais antigo para outros modelos de endereçamento.

Quando os dados são alinhados, o espaço ignorado é preenchido com zeros. Quando as instruções são alinhadas, o espaço ignorado é preenchido com as instruções de NOP de tamanho apropriado.

## <a name="see-also"></a>Consulte também

[Até mesmo](even.md)\
[Referência de diretivas](directives-reference.md)
