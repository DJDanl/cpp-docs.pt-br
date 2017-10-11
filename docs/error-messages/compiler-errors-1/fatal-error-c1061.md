---
title: Erro fatal C1061 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1061
dev_langs:
- C++
helpviewer_keywords:
- C1061
ms.assetid: 9366c0bc-96e0-4967-aa7d-4ebf098de806
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 57766a4ff0b58fdc599a7124e217892e4b28539d
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1061"></a>Erro fatal C1061
limite do compilador: blocos aninhados muito profundamente  
  
 O aninhamento de blocos de código excede o limite de 128 níveis de aninhamento. Esse é um limite fixo do compilador para C e C++, no conjunto de ferramentas de 32 bits e de 64 bits. A contagem de níveis de aninhamento pode ser aumentada em qualquer proporção que crie um escopo ou um bloco. Por exemplo, namespaces, usar diretivas, expansões de pré-processador, expansão do modelo, tratamento de exceções, construções de loop e cláusulas else-if podem qualquer aumentar o nível de aninhamento visto pelo compilador.  
  
 Para corrigir esse erro, é necessário refatorar seu código. Em qualquer caso, o código aninhado é difícil de compreender e justificar. Refatorar seu código para ter menos níveis de aninhamento pode melhorar a qualidade do código e simplificar a manutenção. Divida o código aninhado profundamente em funções que são chamadas pelo contexto original. Limite o número de loops ou cláusulas else-if encadeadas dentro de um bloco.
