---
title: NMAKE Erro Fatal U1095 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1095
dev_langs:
- C++
helpviewer_keywords:
- U1095
ms.assetid: a392582b-06db-4568-9c13-450293a4fbda
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 9b84204f518b5a860d899b54bd579d5f4a0d86d2
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-fatal-error-u1095"></a>Erro fatal U1095 (NMAKE)
linha de comando expandida 'commandline' muito longo  
  
 Após a expansão de macro, a linha de comando determinada excedeu o limite no comprimento das linhas de comando para o sistema operacional.  
  
 MS-DOS permite até 128 caracteres em uma linha de comando.  
  
 Se o comando é um programa que pode aceitar entrada de linha de comando de um arquivo, altere o comando e fornecer a entrada de um arquivo em disco ou um arquivo embutido. Por exemplo, o LINK e LIB aceitam entrada de um arquivo de resposta.
