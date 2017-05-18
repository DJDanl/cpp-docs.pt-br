---
title: NMAKE aviso U4010 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U4010
dev_langs:
- C++
helpviewer_keywords:
- U4010
ms.assetid: 99d8eb9a-ae31-40d1-b8c5-8c66732127d3
caps.latest.revision: 7
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
ms.openlocfilehash: 23feafbf82328ab2fe1a1d20a565432681ab6dab
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-warning-u4010"></a>Aviso U4010 (NMAKE)
'target': compilação falhada; /K especificado, continuando...  
  
 Um comando no bloco de comandos para determinado destino retornou um código de saída diferente de zero. A opção /K disse NMAKE para continuar processando partes relacionadas de compilação e emita um código de saída 1 quando a sessão NMAKE for concluída.  
  
 Se o destino especificado é, em si, um dependente para outro destino, NMAKE emite aviso [U4011](../../error-messages/tool-errors/nmake-warning-u4011.md) após esse aviso.
