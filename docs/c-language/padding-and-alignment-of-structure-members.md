---
title: Preenchimento e alinhamento de membros da estrutura | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: structure members, padding and alignment
ms.assetid: c999820b-dd47-41fc-b923-e4c7ebbcd30f
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 6c3a87f1277abb9d5cf3b9d87c6713104ba8e108
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="padding-and-alignment-of-structure-members"></a>Preenchimento e alinhamento de membros da estrutura
**ANSI 3.5.2.1** O preenchimento e alinhamento dos membros das estruturas e se um campo de bit pode transpor um limite de unidade de armazenamento  
  
 Os membros da estrutura são armazenados em sequência na ordem em que são declarados: o primeiro membro tem o endereço de memória mais baixo e o último membro, o mais alto.  
  
 Cada objeto de dados tem um requisito alignment-requirement. O requisito de alinhamento para todos os dados, exceto estruturas, uniões e matrizes, é o tamanho do objeto ou o tamanho do pacote atual (especificado com /Zp ou o pragma `pack`, o que for menor.) Para estruturas, uniões e matrizes, o requisito de alinhamento é o maior requisito de alinhamento de seus membros. Um offset (deslocamento) é alocado para cada objeto de modo que  
  
 *offset*  `%` *alignment-requirement* `==` 0  
  
 Os campos de bits adjacentes serão empacotados na mesma unidade de alocação de 1, 2, ou 4 bytes se os tipos integrais forem do mesmo tamanho e se o campo de bit seguinte se encaixar na unidade de alocação atual sem cruzar o limite imposto pelos requisitos comuns de alinhamento dos campos de bits.  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, uniões, enumerações e campos de bit](../c-language/structures-unions-enumerations-and-bit-fields.md)