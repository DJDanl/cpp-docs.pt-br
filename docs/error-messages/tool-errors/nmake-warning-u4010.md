---
title: NMAKE aviso U4010 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: U4010
dev_langs: C++
helpviewer_keywords: U4010
ms.assetid: 99d8eb9a-ae31-40d1-b8c5-8c66732127d3
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 2665ef691048eb280a2ca68fc6b82016276604db
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="nmake-warning-u4010"></a>Aviso U4010 (NMAKE)
'target': compilação falhou; /K especificado, continuando...  
  
 Um comando no bloco de comandos para o destino fornecido retornou um código de saída diferente de zero. A opção /K informado NMAKE para continuar o processamento relacionados partes da compilação e emitir um código de saída 1 quando a sessão NMAKE for concluída.  
  
 Se o destino especificado é, em si, um dependente de outro destino, NMAKE emite o aviso [U4011](../../error-messages/tool-errors/nmake-warning-u4011.md) após este aviso.