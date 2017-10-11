---
title: Erro fatal C1067 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1067
dev_langs:
- C++
helpviewer_keywords:
- C1067
ms.assetid: e2c94be6-4573-4571-aac9-73d657fe9f96
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 7ef424de5d375f2d198a5f358976d058d556c506
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1067"></a>Erro fatal C1067
limite do compilador: limite de 64K para tamanho de um registro de tipo foi excedido  
  
 Esse erro pode ocorrer se um símbolo tiver um nome decorado exceder 247 caracteres.  Para resolver, diminua o nome do símbolo.  
  
 Quando o compilador gera informações de depuração, ele emite registros de tipo para definir tipos encontrados no código-fonte.  Por exemplo, registros de tipo incluem estruturas simples e listas de argumentos de funções.  Alguns desses registros de tipo podem ser listas grandes.  
  
 Há um limite de 64K para o tamanho de qualquer tipo de registro.  Se esse limite de 64K for excedido, este erro ocorrerá.  
  
 C1067 também pode ocorrer se houver muitos símbolos com nomes longos ou se uma classe, struct ou união muitos membros.
