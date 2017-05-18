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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 24570403f32c519f79d654ac0b95eaf8a65c8e7c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="storage-and-alignment-of-structures"></a>Armazenamento e alinhamento de estruturas
**Seção específica da Microsoft**  
  
 Os membros da estrutura são armazenados em sequência na ordem em que são declarados: o primeiro membro tem o endereço de memória mais baixo e o último membro, o mais alto.  
  
 Cada objeto de dados tem um requisito *alignment-requirement*. Para estruturas, o requisito é o maior dos respectivos membros. Um *offset* é alocado para cada objeto de modo que  
  
 *offset* `%` *alignment-requirement* `==` 0  
  
 Os campos de bits adjacentes serão empacotados na mesma unidade de alocação de 1, 2, ou 4 bytes se os tipos integrais forem do mesmo tamanho e se o campo de bit seguinte se encaixar na unidade de alocação atual sem cruzar o limite imposto pelos requisitos comuns de alinhamento dos campos de bits.  
  
 Para conservar espaço ou ficar em conformidade com as estruturas de dados existentes, pode ser conveniente armazenar estruturas de forma mais ou menos compacta. A opção do compilador [/Zp](../build/reference/zp-struct-member-alignment.md)[*n*] e o [#pragma pack](../preprocessor/pack.md) controlam o modo como os dados da estrutura são "empacotados" na memória. Quando você usa a opção /Zp[*n*], em que *n* é 1, 2, 4, 8 ou 16, cada membro da estrutura depois do primeiro é armazenado em limites de bytes que são o requisito de alinhamento do campo ou o tamanho de empacotamento (*n*), o que for menor. Expressos como uma fórmula, os limites de bytes são  
  
```  
min( n, sizeof( item ) )  
```  
  
 em que *n* é o tamanho de empacotamento expresso com a opção /Zp[*n*] e *item* é o membro da estrutura. O tamanho de empacotamento padrão é /Zp8.  
  
 Para usar o pragma `pack` para especificar um empacotamento que não seja aquele especificado na linha de comando para determinada estrutura, atribua o pragma `pack`, onde o tamanho de empacotamento é 1, 2, 4, 8 ou 16, antes da estrutura. Para restabelecer o empacotamento atribuído na linha de comando, especifique o pragma `pack` sem argumentos.  
  
 Os campos de bits usam como padrão o tamanho **long** para o compilador de C da Microsoft. Os membros da estrutura são alinhados no tamanho do tipo ou no tamanho de /Zp[*n*], o que for menor. O tamanho padrão é 4.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de estrutura](../c-language/structure-declarations.md)
