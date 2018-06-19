---
title: ML erro não fatal A2096 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2096
dev_langs:
- C++
helpviewer_keywords:
- A2096
ms.assetid: bab0b5ee-b39f-4e44-a41a-3f949fab4297
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6e5d07afa864c9f6f4214de953aa9e03fe0e7e4f
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32053666"
---
# <a name="ml-nonfatal-error-a2096"></a>Erro não fatal A2096 (ML)
**segmento, grupo ou registro de segmento esperado**  
  
 Um segmento ou grupo era esperado, mas não foi encontrado.  
  
 Um dos procedimentos a seguir ocorreu:  
  
-   O operando da esquerda especificado com o segmento de substituir o operador (**:**) não era um segmento register (CS, DS, SS, ES, FS ou GS), nome do grupo de, um nome de segmento ou uma expressão de segmento.  
  
-   O [assumir](../../assembler/masm/assume.md) diretiva foi fornecida um registrador de segmento sem um endereço de segmento válido, registro de segmento, grupo ou especiais **simples** grupo.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)