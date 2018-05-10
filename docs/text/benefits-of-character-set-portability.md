---
title: Portabilidade do conjunto de benefícios de caractere | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- character sets [C++], benefits
- portability [C++], character sets
ms.assetid: bd60b925-1498-4e4f-897b-4c8ce66edcf7
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4d1b78048baebfd89aed0ccc898c2bb9e3612525
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="benefits-of-character-set-portability"></a>Benefícios da portabilidade do conjunto de caracteres
Você pode se beneficiar do uso de recursos de portabilidade de tempo de execução MFC e C mesmo se você atualmente não pretende internacionalizar seu aplicativo:  
  
-   Codificação portably torna o código base flexível. Você posteriormente pode movê-la facilmente para Unicode ou MBCS.  
  
-   Usar Unicode torna mais eficiente seus aplicativos para Windows. Como o Windows usa o Unicode, cadeias de caracteres não Unicode passadas de e para o sistema operacional devem ser convertidas, que gera sobrecarga.  

  
## <a name="see-also"></a>Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Suporte para Unicode](../text/support-for-unicode.md)