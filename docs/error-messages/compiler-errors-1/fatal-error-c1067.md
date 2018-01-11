---
title: Erro fatal C1067 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C1067
dev_langs: C++
helpviewer_keywords: C1067
ms.assetid: e2c94be6-4573-4571-aac9-73d657fe9f96
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8889ccbfcac31917948da719444dab68a2d1b9c6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1067"></a>Erro fatal C1067
limite do compilador: limite de 64K para tamanho de um registro de tipo foi excedido  
  
 Esse erro pode ocorrer se um símbolo tiver um nome decorado exceder 247 caracteres.  Para resolver, diminua o nome do símbolo.  
  
 Quando o compilador gera informações de depuração, ele emite registros de tipo para definir tipos encontrados no código-fonte.  Por exemplo, registros de tipo incluem estruturas simples e listas de argumentos de funções.  Alguns desses registros de tipo podem ser listas grandes.  
  
 Há um limite de 64K para o tamanho de qualquer tipo de registro.  Se esse limite de 64K for excedido, este erro ocorrerá.  
  
 C1067 também pode ocorrer se houver muitos símbolos com nomes longos ou se uma classe, struct ou união muitos membros.