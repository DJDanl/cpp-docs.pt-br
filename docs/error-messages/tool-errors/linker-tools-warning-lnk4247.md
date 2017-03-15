---
title: Aviso LNK4247 das ferramentas de vinculador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK4247
dev_langs:
- C++
helpviewer_keywords:
- LNK4247
ms.assetid: 085d7fdf-9eaf-4641-8473-6eaadd073c7b
caps.latest.revision: 9
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
ms.openlocfilehash: aab2dcff80974c5ef4e53488bd305f71192b2d4a
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-warning-lnk4247"></a>Aviso LNK4247 (Ferramentas de Vinculador)
ponto de entrada 'decorated_function_name' já tem um atributo de thread; 'attribute' ignorado  
  
 Um ponto de entrada especificado com [/ENTRY (símbolo de ponto de entrada)](../../build/reference/entry-entry-point-symbol.md), tinha um atributo de thread, mas [/CLRTHREADATTRIBUTE (Definir Thread atributo CLR)](../../build/reference/clrthreadattribute-set-clr-thread-attribute.md) também foi especificado, com um modelo de threading diferente.  
  
 O vinculador ignorado o valor especificado com /CLRTHREADATTRIBUTE.  
  
 Para resolver este aviso:  
  
-   Remova /CLRTHREADATTRIBUTE sua compilação.  
  
-   Remova o atributo do arquivo de código fonte.  
  
-   Remover os dois o atributo de origem e /CLRTHREADATTRIBUTE de compilação e aceite o modelo de threading do CLR padrão.  
  
-   Altere o valor passado para /CLRTHREADATTRIBUTE, de forma que, estão de acordo com o atributo de origem.  
  
-   Altere o atributo de origem, de forma que, estão de acordo com o valor passado para /CLRTHREADATTRIBUTE.  
  
 O exemplo a seguir gera LNK4247  
  
```  
// LNK4247.cpp  
// compile with: /clr /c  
// post-build command: link /CLRTHREADATTRIBUTE:STA LNK4247.obj /entry:functionTitle /SUBSYSTEM:Console  
 [System::MTAThreadAttribute]  
void functionTitle (){}  
```
