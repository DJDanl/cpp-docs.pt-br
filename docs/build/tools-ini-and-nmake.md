---
title: Tools.ini e NMAKE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, reading files
- Tools.ini and NMake
ms.assetid: ebd5eab6-ddf4-430e-bf4a-1db5bb84e344
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0e4516c3206a08c2b9ee32aea4bbb669ce4cdf0d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="toolsini-and-nmake"></a>Tools.ini e NMAKE
NMAKE lê Tools.ini antes de ler makefiles, a menos que /R é usada. Ele procura Tools.ini primeiro no diretório atual e, em seguida, no diretório especificado pela variável de ambiente de inicialização. A seção de configurações de NMAKE no arquivo de inicialização começa com `[NMAKE]` e pode conter qualquer informação de makefile. Especifique um comentário em uma linha separada que começa com um sinal numérico (#).  
  
## <a name="see-also"></a>Consulte também  
 [Executando NMAKE](../build/running-nmake.md)