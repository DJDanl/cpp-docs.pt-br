---
title: Erro fatal C1001 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1001
dev_langs:
- C++
helpviewer_keywords:
- C1001
ms.assetid: 5736cdb3-22c8-4fad-aa85-d5e0d2b232f4
caps.latest.revision: 15
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
ms.openlocfilehash: f95edeec288ab04b7c3a0aa66d4bfa96784b23ad
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1001"></a>Erro fatal C1001
INTERNO ERROR(compiler file file, line number) COMPILADOR  
  
 O compilador não pode gerar o código correto para uma construção, provavelmente devido à combinação de uma expressão e uma opção de otimização. Tente remover uma ou mais opções de otimização e recompilar a função que contém a linha indicado na mensagem de erro.  
  
 Provavelmente, você pode corrigir o problema removendo uma ou mais opções de otimização. Para determinar qual opção está com defeito, remova uma opção em uma hora e recompile até que a mensagem de erro desaparece. As opções mais comumente responsáveis são **/Og**, **/Oi**, e `/Oa`. Depois de determinar qual opção é responsável, você pode desabilitá-lo usando o [otimizar](../../preprocessor/optimize.md) pragma em torno da função onde o erro ocorre e continuar a usar a opção para o restante do módulo.  
  
 A Base de dados de Conhecimento da Microsoft possui mais informações sobre C1001; consulte [http://support.microsoft.com/default.aspx?scid=kb;en-us;134650](http://support.microsoft.com/default.aspx?scid=kb;en-us;134650).  
  
 Tente reescrever a linha onde o erro é relatado, ou várias linhas de código ao redor dessa linha.
