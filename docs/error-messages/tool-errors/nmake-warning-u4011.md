---
title: NMAKE aviso U4011 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: U4011
dev_langs: C++
helpviewer_keywords: U4011
ms.assetid: e8244514-eba6-4285-8853-7baeefdcd8a4
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0ae15a3912fe3172e9dec98e1a90a3a262c47117
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="nmake-warning-u4011"></a>Aviso U4011 (NMAKE)
'target': nem todos os dependentes disponíveis; destino não compilado  
  
 Um dependente de determinado destino não existe ou foi desatualizado, e um comando para atualizar o dependente retornou um código de saída diferente de zero. A opção /K informado NMAKE para continuar o processamento relacionados partes da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.  
  
 Esse aviso é precedido por aviso [U4010](../../error-messages/tool-errors/nmake-warning-u4010.md) para cada dependentes que não pôde ser criado ou atualizado.