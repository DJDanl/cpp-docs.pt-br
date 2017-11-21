---
title: NMAKE Erro Fatal U1064 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: U1064
dev_langs: C++
helpviewer_keywords: U1064
ms.assetid: 7141e66e-cde6-4173-84df-a391f3ebcdd1
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 123b84922df702aad9dc391da1b83bfa81265fe0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="nmake-fatal-error-u1064"></a>Erro fatal U1064 (NMAKE)
MAKEFILE não encontrado e nenhum destino especificado  
  
 A linha de comando NMAKE não especificou um makefile ou destino e a pasta atual não contém um arquivo chamado MAKEFILE.  
  
 NMAKE requer um makefile ou um destino de linha de comando (ou ambos). Para disponibilizar um makefile para NMAKE, especifique a opção /F ou colocar um arquivo chamado MAKEFILE no diretório atual. NMAKE pode criar um destino de linha de comando usando uma regra de inferência se não for fornecido um makefile.