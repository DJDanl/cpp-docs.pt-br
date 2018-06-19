---
title: C2002 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2002
dev_langs:
- C++
helpviewer_keywords:
- C2002
ms.assetid: 91982314-203a-4de1-b884-94e39a623f61
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 01124fc839d6e788ff2dccae325f01f7d4337f5d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33164860"
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