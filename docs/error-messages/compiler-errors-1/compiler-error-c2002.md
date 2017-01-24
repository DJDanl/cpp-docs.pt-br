---
title: "Erro do Compilador C2002 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2002"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2002"
ms.assetid: 91982314-203a-4de1-b884-94e39a623f61
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2002
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

constante de caractere inválido ampla  
  
 A constante do multibyte\- caractere não é válido.  
  
### Para corrigir verificando as seguintes causas possíveis  
  
1.  A constante de caractere ampla contém mais bytes do que o esperado.  
  
2.  O cabeçalho padrão STDDEF.h não está incluído.  
  
3.  Os caracteres amplos não podem ser concatenados com literais comuns.  
  
4.  Uma constante de caractere ampla deve ser precedida pelo caractere “L”:  
  
    ```  
    L'mbconst'  
    ```  
  
5.  Para Microsoft C\+\+, os argumentos de texto de uma política de pré\-processador devem ser ASCII.  Por exemplo, a política, `#pragma message(L"string")`, não é válido.