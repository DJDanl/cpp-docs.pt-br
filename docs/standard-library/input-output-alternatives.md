---
title: "Alternativas de Entrada-Saída | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: I/O [C++], alternatives
ms.assetid: 9f8401c7-d90d-4285-8918-63573df74a80
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 56b7268083239fbec6b1744e1905e100fc357cc7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="inputoutput-alternatives"></a>Alternativas de Entrada/Saída
O Visual C++ fornece várias alternativas para programação de E/S:  
  
-   E/S não armazenada em buffer, direta, da biblioteca em tempo de execução C.  
  
-   E/S de fluxo da biblioteca em tempo de execução do C ANSI.  
  
-   E/S direta de porta e console.  
  
-   Biblioteca MFC.  
  
-   Biblioteca Padrão C++ da Microsoft.  
  
 As classes iostream são úteis para E/S de texto formatado, armazenada em buffer. Elas também são úteis para E/S binária ou não armazenada em buffer se você precisar de uma interface de programação de C++ e optar por não usar a biblioteca MFC. As classes iostream são uma alternativa de E/S voltada ao objeto às funções de tempo de execução de C.  
  
 É possível usar classes iostream com o sistema operacional Microsoft Windows. Fluxos de arquivos e cadeias de caracteres funcionam sem restrições, mas os objetos de fluxo de modo de caractere `cin`, `cout`, `cerr` e `clog` são inconsistentes com a interface gráfica do usuário do Windows. Também é possível derivar classes de fluxos personalizados que interagem diretamente com o ambiente do Windows.  
  
## <a name="see-also"></a>Consulte também  
 [O que é um fluxo](../standard-library/what-a-stream-is.md)

