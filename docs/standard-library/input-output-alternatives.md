---
title: "Alternativas de Entrada-Saída | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- I/O [C++], alternatives
ms.assetid: 9f8401c7-d90d-4285-8918-63573df74a80
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: 45cec9f7c4c45ef12c7d22a7c3c311f7ce3f4cb5
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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


