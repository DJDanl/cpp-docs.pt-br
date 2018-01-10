---
title: C2002 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2002
dev_langs: C++
helpviewer_keywords: C2002
ms.assetid: 91982314-203a-4de1-b884-94e39a623f61
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9a2cbd21c27cff3effad69b19f42eeaecacf20d6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2002"></a>C2002 de erro do compilador
constante de caractere largo inválido  
  
 A constante de caracteres multibyte não é válida.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  A constante de caractere largo contiver mais bytes que o esperado.  
  
2.  O cabeçalho padrão STDDEF.h não está incluído.  
  
3.  Caracteres largos não podem ser concatenados com literais de cadeia de caracteres comum.  
  
4.  Uma constante de caractere largo deve ser precedida pelo caractere 'L':  
  
    ```  
    L'mbconst'  
    ```  
  
5.  Para C++ da Microsoft, os argumentos de texto de uma diretiva de pré-processador devem ser ASCII. Por exemplo, a diretiva `#pragma message(L"string")`, não é válido.