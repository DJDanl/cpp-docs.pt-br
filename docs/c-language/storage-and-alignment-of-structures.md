---
title: Armazenamento e alinhamento de estruturas
ms.date: 11/04/2016
helpviewer_keywords:
- alignment of structures
- structure storage
- storing structures
- packing structures
ms.assetid: 60ff292f-2595-4f37-ae00-4c4b4f047196
ms.openlocfilehash: 81f5b640585ec3b55e4e3d65b37ea0929a757473
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229474"
---
# <a name="storage-and-alignment-of-structures"></a>Armazenamento e alinhamento de estruturas

**Específico da Microsoft**

Os membros da estrutura são armazenados em sequência na ordem em que são declarados: o primeiro membro tem o endereço de memória mais baixo e o último membro, o mais alto.

Cada objeto de dados tem um *requisito de alinhamento*. Para estruturas, o requisito é o maior dos respectivos membros. Cada objeto é alocado um *deslocamento* para que

*deslocamento* `%` *requisito* `==` de alinhamento 0

Os campos de bits adjacentes serão empacotados na mesma unidade de alocação de 1, 2, ou 4 bytes se os tipos integrais forem do mesmo tamanho e se o campo de bit seguinte se encaixar na unidade de alocação atual sem cruzar o limite imposto pelos requisitos comuns de alinhamento dos campos de bits.

Para conservar espaço ou ficar em conformidade com as estruturas de dados existentes, pode ser conveniente armazenar estruturas de forma mais ou menos compacta. A opção do compilador [/Zp](../build/reference/zp-struct-member-alignment.md)[*n*] e o [#pragma pack](../preprocessor/pack.md) controlam o modo como os dados da estrutura são "empacotados" na memória. Quando você usa a opção /Zp[*n*], em que *n* é 1, 2, 4, 8 ou 16, cada membro da estrutura depois do primeiro é armazenado em limites de bytes que são o requisito de alinhamento do campo ou o tamanho de empacotamento (*n*), o que for menor. Expressos como uma fórmula, os limites de bytes são

```
min( n, sizeof( item ) )
```

em que *n* é o tamanho de empacotamento expresso com a opção /Zp[*n*] e *item* é o membro da estrutura. O tamanho de empacotamento padrão é /Zp8.

Para usar o pragma `pack` para especificar um empacotamento que não seja aquele especificado na linha de comando para determinada estrutura, atribua o pragma `pack`, onde o tamanho de empacotamento é 1, 2, 4, 8 ou 16, antes da estrutura. Para restabelecer o empacotamento atribuído na linha de comando, especifique o pragma `pack` sem argumentos.

Os campos de bits assumem o tamanho padrão **`long`** para o compilador do Microsoft C. Os membros da estrutura são alinhados no tamanho do tipo ou no tamanho de /Zp[*n*], o que for menor. O tamanho padrão é 4.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Declarações de estrutura](../c-language/structure-declarations.md)
