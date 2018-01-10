---
title: Executando NMAKE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- targets, building
- response files, NMAKE
- targets
- command files
- NMAKE program, targets
- NMAKE program, running
- command files, NMAKE
ms.assetid: 0421104d-8b7b-4bf3-86c1-928d9b7c1a8c
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a6c39612cf4df47665f7ea3d529b77ee4e70ce8a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="running-nmake"></a>Executando NMAKE
## <a name="syntax"></a>Sintaxe  
  
```  
NMAKE [option...] [macros...] [targets...] [@commandfile...]  
```  
  
## <a name="remarks"></a>Comentários  
 Compilações NMAKE especificadas somente *destinos* ou, se nenhum for especificado, o primeiro de destino no makefile. O destino de makefile primeiro pode ser um [pseudotarget](../build/pseudotargets.md) que cria outros destinos. NMAKE usa makefiles especificado com /F; Se /F não for especificado, ele usa o arquivo Makefile no diretório atual. Se nenhum makefile for especificado, ele usa regras de inferência para compilação de linha de comando *destinos*.  
  
 O `commandfile` arquivo de texto (ou arquivo de resposta) contém a entrada de linha de comando. Outras entradas podem preceder ou siga`commandfile`. Um caminho é permitido. Em `commandfile`, quebras de linha são tratadas como espaços. Coloque as definições de macro entre aspas se contiverem espaços.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Opções de NMAKE](../build/nmake-options.md)  
  
 [Tools.ini e NMAKE](../build/tools-ini-and-nmake.md)  
  
 [Códigos de saída de NMAKE](../build/exit-codes-from-nmake.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência a NMAKE](../build/nmake-reference.md)