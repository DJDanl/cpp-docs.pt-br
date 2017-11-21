---
title: "Expressões no pré-processamento de Makefile | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- preprocessing makefiles
- expressions [C++], makefile preprocessing
- makefiles, preprocessing
ms.assetid: 37f0f413-97e0-452c-a83f-3c9002c44c92
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 32de1d1eb3262e1fca0a00048a61d3129347cb19
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="expressions-in-makefile-preprocessing"></a>Expressões no pré-processamento de makefile
O **! Se** ou **! ELSE IF** `constantexpression` consiste em comandos, constantes de cadeia de caracteres ou constantes de inteiro (em notação decimal ou linguagem C). Use parênteses para agrupar expressões. As expressões usam C-style longo inteiro aritmético; números são na forma de complemento de dois de 32 bits no intervalo de-2147483648 a 2147483647.  
  
 Expressões podem usar os operadores que atuam em valores de constantes, códigos de saída de comandos, cadeias de caracteres, macros e caminhos de sistema de arquivos.  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
 [Operadores de pré-processamento de makefile](../build/makefile-preprocessing-operators.md)  
  
 [Executando um programa em pré-processamento](../build/executing-a-program-in-preprocessing.md)  
  
## <a name="see-also"></a>Consulte também  
 [Pré-processamento de makefile](../build/makefile-preprocessing.md)