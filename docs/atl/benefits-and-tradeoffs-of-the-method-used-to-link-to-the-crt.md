---
title: "Vantagens e desvantagens do método usado para vincular CRT | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- _ATL_MIN_CRT macro
ms.assetid: 49b485f7-9487-49e4-b12a-0f710b620e2b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 244415a947918a836e8c4c67dbd18758ec40393c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="benefits-and-tradeoffs-of-the-method-used-to-link-to-the-crt"></a>Vantagens e desvantagens do método usado para vincular CRT
Seu projeto pode vincular com CRT dinamicamente ou estaticamente. A tabela a seguir descreve os benefícios e os inconvenientes envolvidos na escolha de qual método usar.  
  
|Método|Benefício|Compensação|  
|------------|-------------|--------------|  
|A vinculação estática para CRT<br /><br /> (**Biblioteca de tempo de execução** definida como **Single-threaded**)|A DLL do CRT não é necessário no sistema onde a imagem será executado.|Cerca de 25K de código de inicialização é adicionado à sua imagem, aumentar substancialmente o seu tamanho.|  
|Vinculando dinamicamente a CRT<br /><br /> (**Biblioteca de tempo de execução** definida como **multi-threaded**)|Sua imagem não requer o código de inicialização do CRT, portanto, é muito menor.|A DLL do CRT deve ser no sistema executando a imagem.|  
  
 O tópico [vinculando a CRT em seu projeto de ATL](../atl/linking-to-the-crt-in-your-atl-project.md) discute como selecionar a maneira pela qual deseja vincular a CRT.  
  
## <a name="see-also"></a>Consulte também  
 [Programando com código ATL e C Run-Time](../atl/programming-with-atl-and-c-run-time-code.md)   
 [DLLs e o comportamento de biblioteca de tempo de execução do Visual C++](../build/run-time-library-behavior.md)   
 [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md)

