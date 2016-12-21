---
title: "_SCL_SECURE_NO_WARNINGS | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_SCL_SECURE_NO_DEPRECATE"
  - "_SCL_SECURE_NO_WARNINGS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "_SCL_SECURE_NO_DEPRECATE"
  - "_SCL_SECURE_NO_WARNINGS"
ms.assetid: ef0ddea9-7c62-4b53-8b64-5f4fd369776f
caps.latest.revision: 5
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _SCL_SECURE_NO_WARNINGS
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chamar qualquer um dos métodos possivelmente não seguro na biblioteca padrão C\+\+ resultará em [Compilador \(nível 3\) aviso C4996](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md).  Para desabilitar esse aviso, defina **\_SCL\_SECURE\_NO\_WARNINGS** macro em seu código:  
  
```  
#define _SCL_SECURE_NO_WARNINGS  
```  
  
## Comentários  
 Outras maneiras de desabilitar C4996 de aviso incluem:  
  
-   Usando a opção de compilador de [\/D \(definições de pré\-processador\)](../build/reference/d-preprocessor-definitions.md) :  
  
    ```  
    cl /D_SCL_SECURE_NO_WARNINGS [other compiler options] myfile.cpp  
    ```  
  
-   Usando a opção de compilador de [\/w](../build/reference/compiler-option-warning-level.md) :  
  
    ```  
    cl /wd4996 [other compiler options] myfile.cpp  
    ```  
  
-   Usando a política de [aviso de \#pragma](../preprocessor/warning.md) :  
  
    ```  
    #pragma warning(disable:4996)  
    ```  
  
 Além disso, você poderá modificar manualmente o nível de aviso C4996 com a opção do compilador de **\/w\<l\>\<n\>** .  Por exemplo, para definir C4996 de aviso para o nível 4:  
  
```  
cl /w44996 [other compiler options] myfile.cpp  
```  
  
 Para obter mais informações, consulte [\/w, \/W0, \/W1, \/W2, \/W3, \/W4, \/w1, \/w2, \/w3, \/w4, \/Wall, \/wd, \/, \/wo, \/Wv, \/WX \(nível de aviso\)](../build/reference/compiler-option-warning-level.md).  
  
## Consulte também  
 [Bibliotecas seguras: Biblioteca Padrão C\+\+](../standard-library/safe-libraries-cpp-standard-library.md)