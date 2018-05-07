---
title: Erro fatal C1211 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1211
dev_langs:
- C++
helpviewer_keywords:
- C1211
ms.assetid: df0ca70d-ec6e-4400-926a-b877e2599978
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4ef92816c157d6bbc72d7c7539f2d0644c70082b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1211"></a>Erro fatal C1211
Não há suporte para o atributo personalizado TypeForwardedTo pela versão do tempo de execução instalada  
  
 C1211 ocorre quando você tiver um compilador para a versão atual, mas um tempo de execução de linguagem comum de uma versão anterior.  
  
 Algumas funcionalidades do compilador não podem funcionar em uma versão anterior do tempo de execução.  
  
 Para resolver C1211 instalar o common language runtime que acompanha o compilador você está usando.  
  
 Para obter mais informações, consulte [encaminhamento de tipo (C + + CLI)](../../windows/type-forwarding-cpp-cli.md).