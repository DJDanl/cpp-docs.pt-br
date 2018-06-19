---
title: NMAKE aviso U4011 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- U4011
dev_langs:
- C++
helpviewer_keywords:
- U4011
ms.assetid: e8244514-eba6-4285-8853-7baeefdcd8a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: af9c0f90c507eebe212a9c3cbfb2f2d21cded43d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33320789"
---
# <a name="nmake-warning-u4011"></a>Aviso U4011 (NMAKE)
'target': nem todos os dependentes disponíveis; destino não compilado  
  
 Um dependente de determinado destino não existe ou foi desatualizado, e um comando para atualizar o dependente retornou um código de saída diferente de zero. A opção /K informado NMAKE para continuar o processamento relacionados partes da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.  
  
 Esse aviso é precedido por aviso [U4010](../../error-messages/tool-errors/nmake-warning-u4010.md) para cada dependentes que não pôde ser criado ou atualizado.