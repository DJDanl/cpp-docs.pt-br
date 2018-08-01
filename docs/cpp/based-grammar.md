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
ms.openlocfilehash: 69d1713b0cc8e1d5d53d3b30f3dd48a0b54a3782
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39401955"
---
# <a name="based-grammar"></a>Gramática __based
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O endereçamento baseado é útil quando é necessário controle preciso sobre o segmento ao qual os objetos estão alocados (dados estáticos e com base dinâmica).  
  
 A única forma de endereçamento baseado aceitável em compilações de 32 bits e 64 bits é "com base em um ponteiro" que define um tipo que contém um deslocamento de 32 bits ou 64 bits a uma base de 32 bits ou 64 bits ou com base em **void**.  
  
## <a name="grammar"></a>Gramática  
 *com base-intervalo-modifier*:  
 **based (***base-expression***)**   
  
 *expressão de base*:  
 *based-variablebased-abstract-declaratorsegment-namesegment-cast*  
  
 *variável com base na*:  
 *identifier*  
  
 *com base-abstract-declarator*:  
 *abstract-declarator&lt;1}{2&gt;opt&lt;2*  
  
 *tipo base*:  
 *type-name*  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Ponteiros com base](../cpp/based-pointers-cpp.md)