---
title: Ferramentas de vinculador LNK2023 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK2023
dev_langs:
- C++
helpviewer_keywords:
- LNK2023
ms.assetid: c99e35a8-739a-4a20-a715-29b8c3744703
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3b53fba3743d6d072930e430c15b79e0e31d68d2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302601"
---
# <a name="linker-tools-error-lnk2023"></a>Erro das Ferramentas de Vinculador LNK2023
dll incorreta ou o ponto de entrada \<dll ou ponto de entrada >  
  
 O vinculador está carregando uma versão incorreta do msobj90.dll. Certifique-se de que link.exe e msobj90.dll em seu caminho tenham a mesma versão.  
  
 Uma dependência de msobj90.dll pode não estar presente. A lista de dependências para msobj90.dll é:  
  
-   Msvcr90.dll  
  
-   Kernel32.dll  
  
 Verifique seu computador para quaisquer outras cópias do msobj90.dll pode estar desatualizado.