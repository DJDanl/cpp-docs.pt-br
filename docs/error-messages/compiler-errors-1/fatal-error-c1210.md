---
title: Erro fatal C1210 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1210
dev_langs:
- C++
helpviewer_keywords:
- C1210
ms.assetid: e2208309-c284-425c-a7e8-48e96e66f35b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: df1b970454af8ab692aea949d437e4c1cce4e0cb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1210"></a>Erro fatal C1210
/CLR: pure e /CLR: safe não são suportados pela versão do tempo de execução instalada  
  
 As opções do compilador **/clr:pure** e **/clr:safe** são preteridas no Visual Studio 2015.  
  
 C1210 ocorre quando você tiver um compilador para a versão atual, mas um tempo de execução de linguagem comum de uma versão anterior.  
  
 Algumas funcionalidades do compilador não podem funcionar em uma versão anterior do tempo de execução.  
  
 Para resolver C1210 instalar a versão de tempo de execução de linguagem comum que é destinada para uso com o compilador.