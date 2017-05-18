---
title: NMAKE Erro Fatal U1035 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- U1035
dev_langs:
- C++
helpviewer_keywords:
- U1035
ms.assetid: 68f0cc59-007e-4109-ac30-7ac4ac447e6d
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
ms.openlocfilehash: 976e6609e10a159875a0dde4a4369baebc68634a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="nmake-fatal-error-u1035"></a>Erro fatal U1035 (NMAKE)
erro de sintaxe : ':' ou separador '=' esperado  
  
 Qualquer um dos dois-pontos (**:**) ou um sinal de igual (**=**) era esperado.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Dois-pontos não seguiu um destino.  
  
2.  Uma vírgula e nenhum espaço (por exemplo, r:) seguido de um única letra destino. NMAKE interpretado-lo como uma especificação de unidade.  
  
3.  Dois-pontos não seguiu uma regra de inferência de tipos.  
  
4.  Uma definição de macro não foi seguida por um sinal de igual.  
  
5.  Um caractere seguido de uma barra invertida (**\\**) que foi usada para continuar um comando para uma nova linha.  
  
6.  Uma cadeia de caracteres apareceu que não tenha seguido a qualquer regra de sintaxe NMAKE.  
  
7.  O makefile foi formatado por um processador de texto.
