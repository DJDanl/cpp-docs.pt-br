---
title: "ML erro não fatal A2096 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: A2096
dev_langs: C++
helpviewer_keywords: A2096
ms.assetid: bab0b5ee-b39f-4e44-a41a-3f949fab4297
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 6d4466d87e33068b10b3f620bfbe764e4aec76c7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ml-nonfatal-error-a2096"></a>Erro não fatal A2096 (ML)
**segmento, grupo ou registro de segmento esperado**  
  
 Um segmento ou grupo era esperado, mas não foi encontrado.  
  
 Um dos procedimentos a seguir ocorreu:  
  
-   O operando da esquerda especificado com o segmento de substituir o operador (**:**) não era um segmento register (CS, DS, SS, ES, FS ou GS), nome do grupo de, um nome de segmento ou uma expressão de segmento.  
  
-   O [assumir](../../assembler/masm/assume.md) diretiva foi fornecida um registrador de segmento sem um endereço de segmento válido, registro de segmento, grupo ou especiais **simples** grupo.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)