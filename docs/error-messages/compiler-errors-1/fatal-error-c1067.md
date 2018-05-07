---
title: Erro fatal C1067 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1067
dev_langs:
- C++
helpviewer_keywords:
- C1067
ms.assetid: e2c94be6-4573-4571-aac9-73d657fe9f96
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 89ac7084e92f7f2ed496a4c1572e94a4fa46862f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1067"></a>Erro fatal C1067
limite do compilador: limite de 64K para tamanho de um registro de tipo foi excedido  
  
 Esse erro pode ocorrer se um símbolo tiver um nome decorado exceder 247 caracteres.  Para resolver, diminua o nome do símbolo.  
  
 Quando o compilador gera informações de depuração, ele emite registros de tipo para definir tipos encontrados no código-fonte.  Por exemplo, registros de tipo incluem estruturas simples e listas de argumentos de funções.  Alguns desses registros de tipo podem ser listas grandes.  
  
 Há um limite de 64K para o tamanho de qualquer tipo de registro.  Se esse limite de 64K for excedido, este erro ocorrerá.  
  
 C1067 também pode ocorrer se houver muitos símbolos com nomes longos ou se uma classe, struct ou união muitos membros.