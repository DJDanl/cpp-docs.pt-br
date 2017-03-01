---
title: C2002 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2002
dev_langs:
- C++
helpviewer_keywords:
- C2002
ms.assetid: 91982314-203a-4de1-b884-94e39a623f61
caps.latest.revision: 10
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
ms.openlocfilehash: 68cb3b5b63d2b3267332be8e2e5375445aa2f5cf
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2002"></a>C2002 de erro do compilador
constante de caractere largo inválida  
  
 A constante de caractere multibyte não é válida.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  A constante de caractere largo contiver mais bytes que o esperado.  
  
2.  O cabeçalho padrão stddef não está incluído.  
  
3.  Caracteres largos não podem ser concatenados com literais de cadeia de caracteres comum.  
  
4.  Uma constante de caractere largo deve ser precedida pelo caractere 'L',':  
  
    ```  
    L'mbconst'  
    ```  
  
5.  Para o Microsoft C++, os argumentos de texto de uma diretiva de pré-processador devem ser ASCII. Por exemplo, a diretiva `#pragma message(L"string")`, não é válido.
