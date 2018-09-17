---
title: Agregações e uniões | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- aggregates [C++], and unions
ms.assetid: 859fc211-b111-4f12-af98-de78e48f9b92
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1f0ac55dce5d00f8931ee263be0fc5ab8a8a3a08
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45710015"
---
# <a name="aggregates-and-unions"></a>Agregações e uniões

Outros tipos, como matrizes, estruturas e uniões, têm requisitos de alinhamento mais rígidos que garantem consistente agregada e união armazenamento e recuperação de dados. Aqui estão as definições de matriz, a estrutura e união:

- Matriz

   Contém um grupo ordenado de objetos de dados adjacentes. Cada objeto é chamado de um elemento. Todos os elementos dentro de uma matriz tem o mesmo tamanho e tipo de dados.

-  Estrutura

   Contém um grupo ordenado de objetos de dados. Diferentemente dos elementos de uma matriz, os objetos dentro de uma estrutura de dados podem ter tamanhos e tipos de dados diferentes. Cada objeto de dados em uma estrutura é chamado de um membro.

- União

   Um objeto que contém qualquer um de um conjunto de membros nomeados. Os membros do conjunto nomeado podem ser de qualquer tipo. O armazenamento alocado para uma união é igual para o armazenamento necessário para o maior membro dessa união, além de qualquer preenchimento necessários para o alinhamento.

A tabela a seguir mostra o alinhamento fortemente sugerido para os membros de escalares de uniões e estruturas.

||||
|-|-|-|
|Tipo escalar|Tipo de dados C|Alinhamento necessário|
|**INT8**|**char**|Byte|
|**UINT8**|**unsigned char**|Byte|
|**INT16**|**short**|Palavra|
|**UINT16**|**unsigned short**|Palavra|
|**INT32**|**int**, **longo**|Palavras duplas|
|**UINT32**|**int sem sinal, unsigned long**|Palavras duplas|
|**INT64**|**__int64**|Quadword|
|**UINT64**|**unsigned __int64**|Quadword|
|**FP32 (único precisão)**|**float**|Palavras duplas|
|**FP64 (duplas precisão)**|**double**|Quadword|
|**PONTEIRO**|<strong>\*</strong>|Quadword|
|**__m64**|**struct __m64**|Quadword|
|**__m128**|**struct __m128**|Octaword|

As seguintes regras de alinhamento de agregação se aplicam:

- O alinhamento de uma matriz é o mesmo que o alinhamento de um dos elementos da matriz.

- O alinhamento de início de uma estrutura ou uma união é o alinhamento máximo de qualquer membro individual. Cada membro dentro da estrutura ou união deve ser colocado em seu alinhamento adequado, conforme definido na tabela anterior, que pode exigir o preenchimento interno implícito, dependendo do membro anterior.

- Tamanho da estrutura deve ser um múltiplo inteiro de seu alinhamento, que pode exigir o preenchimento após o último membro. Já que estruturas e uniões podem ser agrupadas em matrizes, cada elemento da matriz de uma estrutura ou união deve começar e terminar no alinhamento adequado previamente determinado.

- É possível alinhar dados de maneira a ser maior do que os requisitos de alinhamento, desde que as regras anteriores são mantidas.

- Um compilador individual pode ajustar o empacotamento de uma estrutura por motivos de tamanho. Por exemplo [/Zp (alinhamento de membro de Struct)](../build/reference/zp-struct-member-alignment.md) permite ajustar o empacotamento de estruturas.

## <a name="see-also"></a>Consulte também

[Tipos e armazenamento](../build/types-and-storage.md)
