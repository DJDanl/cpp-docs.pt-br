---
title: Ferramentas de vinculador LNK2023 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK2023
dev_langs: C++
helpviewer_keywords: LNK2023
ms.assetid: c99e35a8-739a-4a20-a715-29b8c3744703
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: dfaac5729c014baff676772fb052bfbcf79489cc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk2023"></a>Erro das Ferramentas de Vinculador LNK2023
dll incorreta ou o ponto de entrada \<dll ou ponto de entrada >  
  
 O vinculador está carregando uma versão incorreta do msobj90.dll. Certifique-se de que link.exe e msobj90.dll em seu caminho tenham a mesma versão.  
  
 Uma dependência de msobj90.dll pode não estar presente. A lista de dependências para msobj90.dll é:  
  
-   Msvcr90.dll  
  
-   Kernel32.dll  
  
 Verifique seu computador para quaisquer outras cópias do msobj90.dll pode estar desatualizado.