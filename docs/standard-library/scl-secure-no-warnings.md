---
title: _SCL_SECURE_NO_WARNINGS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _SCL_SECURE_NO_DEPRECATE
- _SCL_SECURE_NO_WARNINGS
dev_langs: C++
helpviewer_keywords:
- _SCL_SECURE_NO_DEPRECATE
- _SCL_SECURE_NO_WARNINGS
ms.assetid: ef0ddea9-7c62-4b53-8b64-5f4fd369776f
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 288af808dfa714c10eeba1f11738cf9db31d70d5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="sclsecurenowarnings"></a>_SCL_SECURE_NO_WARNINGS
Chamar qualquer um dos métodos potencialmente não seguros na biblioteca padrão C++ resultará no [Aviso do compilador C4996 (nível 3)](../error-messages/compiler-warnings/compiler-warning-level-3-c4996.md). Para desabilitar esse aviso, defina a macro **_SCL_SECURE_NO_WARNINGS** no seu código:  
  
```  
#define _SCL_SECURE_NO_WARNINGS  
```  
  
## <a name="remarks"></a>Comentários  
 Outras maneiras de desabilitar o aviso C4996 incluem:  
  
-   Usando a opção do compilador [/D (definições de pré-processador)](../build/reference/d-preprocessor-definitions.md):  
  
 ```  
    cl /D_SCL_SECURE_NO_WARNINGS [other compiler options] myfile.cpp  
```  
  
-   Usando a opção do compilador [/w](../build/reference/compiler-option-warning-level.md):  
  
 ```  
    cl /wd4996 [other compiler options] myfile.cpp  
```  
  
-   Usando a diretiva [#pragma warning](../preprocessor/warning.md):  
  
 ```  
 #pragma warning(disable:4996)  
```  
  
 Além disso, você pode alterar manualmente o nível de aviso C4996 com o **/w\<l >\< n>**  opção de compilador. Por exemplo, para definir o aviso C4996 como nível 4:  
  
```  
cl /w44996 [other compiler options] myfile.cpp  
```  
  
 Para obter mais informações, consulte [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /we, /wo, /Wv, /WX (Nível de Aviso)](../build/reference/compiler-option-warning-level.md).  
  
## <a name="see-also"></a>Consulte também  
 [Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)

