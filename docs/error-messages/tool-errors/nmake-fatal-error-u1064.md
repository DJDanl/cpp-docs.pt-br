---
title: NMAKE Erro Fatal U1064 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1064
dev_langs:
- C++
helpviewer_keywords:
- U1064
ms.assetid: 7141e66e-cde6-4173-84df-a391f3ebcdd1
caps.latest.revision: 6
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 8cdb98a31a07326bb4f1c8df462acc5dfa5002a4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-fatal-error-u1064"></a>Erro fatal U1064 (NMAKE)
MAKEFILE não encontrado e sem destino especificado  
  
 A linha de comando NMAKE não especificou um makefile ou um destino e o diretório atual não continha um arquivo chamado MAKEFILE.  
  
 NMAKE exige um makefile ou um destino de linha de comando (ou ambos). Para disponibilizar um makefile para NMAKE, especifique a opção /F ou colocar um arquivo chamado MAKEFILE no diretório atual. NMAKE pode criar um destino de linha de comando usando uma regra de inferência se não for fornecido um makefile.
