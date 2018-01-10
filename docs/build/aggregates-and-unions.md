---
title: "Agregações e uniões | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: aggregates [C++], and unions
ms.assetid: 859fc211-b111-4f12-af98-de78e48f9b92
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 74ee1bbcf1a39171b18c09274543c72e0b844748
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="aggregates-and-unions"></a>Agregações e uniões
Outros tipos, como matrizes, estruturas e uniões têm requisitos de alinhamento mais rígidos que garantem consistente union e agregar armazenamento e recuperação de dados. Aqui estão as definições de matriz, a estrutura e união:  
  
 Matriz  
 Contém um grupo ordenado de objetos de dados adjacentes. Cada objeto é chamado de um elemento. Todos os elementos em uma matriz tem o mesmo tamanho e tipo de dados.  
  
 Estrutura  
 Contém um grupo ordenado de objetos de dados. Diferentemente dos elementos de uma matriz, os objetos dentro de uma estrutura de dados podem ter tipos de dados diferentes e tamanhos. Cada objeto de dados em uma estrutura é chamado de um membro.  
  
 União  
 Um objeto que contém qualquer um de um conjunto de membros com nomes. Os membros do conjunto nomeado podem ser de qualquer tipo. O armazenamento alocado para uma união é igual para o armazenamento necessário para o membro maior que union, além de qualquer preenchimento necessários para alinhamento.  
  
 A tabela a seguir mostra o alinhamento fortemente sugerido para os membros escalares de estruturas e uniões.  
  
||||  
|-|-|-|  
|Tipo de escalar|Tipo de dados C|Alinhamento requerido|  
|**INT8**|`char`|Byte|  
|**UINT8**|`unsigned char`|Byte|  
|**INT16**|**short**|Palavra|  
|**UINT16**|**unsigned short**|Palavra|  
|**INT32**|**int, long**|Doubleword|  
|**UINT32**|**int não assinado, longo não assinado**|Doubleword|  
|**INT64**|`__int64`|Quadword|  
|**UINT64**|**unsigned __int64**|Quadword|  
|**FP32 (único precisão)**|**float**|Doubleword|  
|**FP64 (dupla precisão)**|**double**|Quadword|  
|**PONTEIRO**|**\***|Quadword|  
|`__m64`|**struct m64**|Quadword|  
|`__m128`|**struct m128**|Octaword|  
  
 As seguintes regras de alinhamento de agregação se aplicam:  
  
-   O alinhamento de uma matriz é o mesmo que o alinhamento de um dos elementos da matriz.  
  
-   O alinhamento de início de uma estrutura ou uma união é o alinhamento máximo de qualquer membro individual. Cada membro dentro da estrutura ou união deve ser colocado no seu alinhamento apropriado, conforme definido na tabela anterior, o que pode exigir o preenchimento interno implícita, dependendo do membro anterior.  
  
-   Tamanho da estrutura deve ser um múltiplo de inteiro de seu alinhamento, o que pode exigir o preenchimento após o último membro. Como estruturas e uniões podem ser agrupados em matrizes, cada elemento da matriz de uma estrutura ou união deve começar e terminar com o alinhamento adequado previamente determinado.  
  
-   É possível alinhar dados de forma a ser maior do que os requisitos de alinhamento, desde que as regras anteriores são mantidas.  
  
-   Um compilador individual pode ajustar o empacotamento de uma estrutura por motivos de tamanho. Por exemplo [/Zp (alinhamento de membro de Struct)](../build/reference/zp-struct-member-alignment.md) permite ajustar o empacotamento de estruturas.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)