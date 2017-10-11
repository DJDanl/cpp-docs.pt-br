---
title: Armazenamento e alinhamento de estruturas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- alignment of structures
- structure storage
- storing structures
- packing structures
ms.assetid: 60ff292f-2595-4f37-ae00-4c4b4f047196
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: d9c09137da32c7ef9d42f0302087379af922652f
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="storage-and-alignment-of-structures"></a>Armazenamento e alinhamento de estruturas
**Seção específica da Microsoft**  
  
 Os membros da estrutura são armazenados em sequência na ordem em que são declarados: o primeiro membro tem o endereço de memória mais baixo e o último membro, o mais alto.  
  
 Cada objeto de dados tem um requisito *alignment-requirement*. Para estruturas, o requisito é o maior dos respectivos membros. Um *offset* é alocado para cada objeto de modo que  
  
 *offset* `%` *alignment-requirement* `==` 0  
  
 Os campos de bits adjacentes serão empacotados na mesma unidade de alocação de 1, 2, ou 4 bytes se os tipos integrais forem do mesmo tamanho e se o campo de bit seguinte se encaixar na unidade de alocação atual sem cruzar o limite imposto pelos requisitos comuns de alinhamento dos campos de bits.  
  
 Para conservar espaço ou ficar em conformidade com as estruturas de dados existentes, pode ser conveniente armazenar estruturas de forma mais ou menos compacta. O [/Zp](../build/reference/zp-struct-member-alignment.md)[*n*] opção de compilador e o [#pragma pacote](../preprocessor/pack.md) controle como dados de estrutura "vem" na memória. Quando você usa o /Zp [*n*] opção, onde  *n*  é 1, 2, 4, 8 ou 16, cada membro da estrutura depois que o primeiro é armazenado em limites de bytes que são o requisito de alinhamento o campo ou o tamanho de remessa (*n*), o que for menor. Expressos como uma fórmula, os limites de bytes são  
  
```  
min( n, sizeof( item ) )  
```  
  
 onde  *n*  é o tamanho de remessa expressado com o /Zp [*n*] opção e *item* é membro da estrutura. O tamanho de empacotamento padrão é /Zp8.  
  
 Para usar o pragma `pack` para especificar um empacotamento que não seja aquele especificado na linha de comando para determinada estrutura, atribua o pragma `pack`, onde o tamanho de empacotamento é 1, 2, 4, 8 ou 16, antes da estrutura. Para restabelecer o empacotamento atribuído na linha de comando, especifique o pragma `pack` sem argumentos.  
  
 Os campos de bits usam como padrão o tamanho **long** para o compilador de C da Microsoft. Membros de estrutura são alinhados no tamanho do tipo ou a /Zp [*n*] tamanho, o que for menor. O tamanho padrão é 4.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de estrutura](../c-language/structure-declarations.md)
