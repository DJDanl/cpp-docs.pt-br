---
title: _SCL_SECURE_NO_WARNINGS | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _SCL_SECURE_NO_DEPRECATE
- _SCL_SECURE_NO_WARNINGS
dev_langs:
- C++
helpviewer_keywords:
- _SCL_SECURE_NO_DEPRECATE
- _SCL_SECURE_NO_WARNINGS
ms.assetid: ef0ddea9-7c62-4b53-8b64-5f4fd369776f
caps.latest.revision: 5
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
ms.sourcegitcommit: 3f69f0c3176d2fbe19e11ce08c071691a72d858d
ms.openlocfilehash: e2f39c4f07235c75204a63e634053f887682337e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

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
  
 Além disso, você pode alterar manualmente o nível de aviso C4996 com a opção do compilador **/w\<l>\<n>**. Por exemplo, para definir o aviso C4996 como nível 4:  
  
```  
cl /w44996 [other compiler options] myfile.cpp  
```  
  
 Para obter mais informações, consulte [/w, /W0, /W1, /W2, /W3, /W4, /w1, /w2, /w3, /w4, /Wall, /wd, /we, /wo, /Wv, /WX (Nível de Aviso)](../build/reference/compiler-option-warning-level.md).  
  
## <a name="see-also"></a>Consulte também  
 [Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)


