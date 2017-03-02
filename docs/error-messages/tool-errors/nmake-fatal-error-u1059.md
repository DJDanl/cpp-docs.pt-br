---
title: NMAKE Erro Fatal U1059 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1059
dev_langs:
- C++
helpviewer_keywords:
- U1059
ms.assetid: b21d9198-9c63-40d0-b589-80e17294ce24
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
ms.openlocfilehash: cec7a2405b5eae675d31936bb34137113e53ab8e
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-fatal-error-u1059"></a>Erro fatal U1059 (NMAKE)
erro de sintaxe : '}' ausente em dependente  
  
 Um caminho de pesquisa para um dependente foi especificado incorretamente. Qualquer um espaço existia no caminho ou a chave de fechamento (**}**) foi omitido.  
  
 A sintaxe para uma especificação de diretório para um dependente é  
  
 **{**   
 ***diretórios* } dependentes**  
  
 onde `directories` Especifica um ou mais caminhos, cada um separado por um ponto e vírgula (**;**). Não são permitidos espaços.  
  
 Se parte ou todo um caminho de pesquisa é substituído por uma macro, verifique se que existem sem espaços na expansão de macro.
