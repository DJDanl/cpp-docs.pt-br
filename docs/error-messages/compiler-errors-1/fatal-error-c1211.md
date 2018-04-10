---
title: Erro fatal C1211 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: article
f1_keywords:
- C1211
dev_langs:
- C++
helpviewer_keywords:
- C1211
ms.assetid: df0ca70d-ec6e-4400-926a-b877e2599978
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a57418d53626aefa1b9616b2790bd23e0a2d941e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="fatal-error-c1211"></a>Erro fatal C1211
Não há suporte para o atributo personalizado TypeForwardedTo pela versão do tempo de execução instalada  
  
 C1211 ocorre quando você tiver um compilador para a versão atual, mas um tempo de execução de linguagem comum de uma versão anterior.  
  
 Algumas funcionalidades do compilador não podem funcionar em uma versão anterior do tempo de execução.  
  
 Para resolver C1211 instalar o common language runtime que acompanha o compilador você está usando.  
  
 Para obter mais informações, consulte [encaminhamento de tipo (C + + CLI)](../../windows/type-forwarding-cpp-cli.md).