---
title: C2002 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
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
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: d8f6fc5983a462850581f69ca32dd7c305f9e847
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

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
