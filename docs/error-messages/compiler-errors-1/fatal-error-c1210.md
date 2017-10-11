---
title: Erro fatal C1210 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C1210
dev_langs:
- C++
helpviewer_keywords:
- C1210
ms.assetid: e2208309-c284-425c-a7e8-48e96e66f35b
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 0756ef40282f9a9bffb21788ea1b396600e50362
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1210"></a>Erro fatal C1210
/CLR: pure e /CLR: safe não são suportados pela versão do tempo de execução instalada  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 C1210 ocorre quando você tiver um compilador para a versão atual, mas um tempo de execução de linguagem comum de uma versão anterior.  
  
 Algumas funcionalidades do compilador não podem funcionar em uma versão anterior do tempo de execução.  
  
 Para resolver C1210 instalar a versão de tempo de execução de linguagem comum que é destinada para uso com o compilador.
