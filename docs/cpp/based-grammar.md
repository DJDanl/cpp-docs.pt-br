---
title: gramática based | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- based addressing
ms.assetid: a68ff750-c7fa-4c0c-8d5f-2df76e4686c5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 20e1c14cd7add01f8583c24541987b2980da794a
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="based-grammar"></a>Gramática __based
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O endereçamento baseado é útil quando é necessário controle preciso sobre o segmento ao qual os objetos estão alocados (dados estáticos e com base dinâmica).  
  
 O único formulário aceitável de endereçamento baseado em compilações de 32 bits e de 64 bits é o “baseado em um ponteiro”, que define um tipo que contém um deslocamento de 32 bits ou de 64 bits para uma base de 32 bits ou de 64 bits, ou com base em `void`.  
  
## <a name="grammar"></a>Gramática  
 *modificador com base de intervalo*:  
 **based (***base de dados de expressão***)**   
  
 *Base de dados de expressão*:  
 *based-variablebased-abstract-declaratorsegment-namesegment-cast*  
  
 *variável com base na*:  
 *identifier*  
  
 *Declarador com base de resumo*:  
 *Declarador abstrato*  
  
 *tipo de base*:  
 *type-name*  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Ponteiros com base](../cpp/based-pointers-cpp.md)