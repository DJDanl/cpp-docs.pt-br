---
title: 3.3 rotinas de tempo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 21060d64-cbe8-4e38-8718-3a68d6a57be3
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 285102b27a290d693372e414645a41f5b5de1834
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="33-timing-routines"></a>3.3 rotinas de tempo
As funções descritas nesta seção fornecem suporte a um timer de relógio portátil:  
  
-   O `omp_get_wtime` função retorna a hora do relógio decorrido.  
  
-   O `omp_get_wtick` função retorna segundos entre tiques do relógio sucessivas.