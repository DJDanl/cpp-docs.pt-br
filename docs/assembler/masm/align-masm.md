---
title: ALIGN (MASM)
ms.date: 01/02/2019
f1_keywords:
- align
helpviewer_keywords:
- ALIGN directive
ms.assetid: 1c386b23-439f-4ec3-a6de-74427b25e47f
ms.openlocfilehash: eb42b1952b3fd59438f0dd4c29d48c91c4d8864d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62166471"
---
# <a name="align-masm"></a>ALIGN (MASM)

O **ALINHAR** diretiva alinha o próximo elemento de dados ou a instrução em um endereço que é um múltiplo de seu parâmetro. O parâmetro deve ser uma potência de 2 (por exemplo, 1, 2, 4 e assim por diante) que é menor ou igual ao alinhamento de segmento.

## <a name="syntax"></a>Sintaxe

> ALIGN [[*number*]]

## <a name="remarks"></a>Comentários

O **ALINHAR** diretiva permite especificar o deslocamento de início de um elemento de dados ou uma instrução. Dados alinhados podem melhorar o desempenho, às custas de espaço desperdiçado entre os elementos de dados. Grandes melhorias de desempenho podem ser vistas quando os acessos a dados estão em limites que se ajustam a linhas de cache. Acessos em limites naturais para tipos nativos significa menos tempo gasto no hardware interno realinhamento microcódigo.

A necessidade de instruções alinhadas é rara em processadores modernos que usam um modelo de endereçamento simples, mas podem ser necessário para destinos de salto no código mais antigo para outros modelos de endereçamento.

Quando dados são alinhados, o espaço foi ignorado é preenchido com zeros. Quando as instruções estão alinhadas, o espaço foi ignorado é preenchido com instruções de NOP dimensionado adequadamente.

## <a name="see-also"></a>Consulte também

[EVEN](even.md)<br/>
[Referência de diretivas](../../assembler/masm/directives-reference.md)<br/>