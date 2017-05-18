---
title: C2099 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2099
dev_langs:
- C++
helpviewer_keywords:
- C2099
ms.assetid: 30e151ee-d458-4901-b0c0-d45054a913f5
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: cc82e0e603fd0ce28626247f073dbc493faf5b47
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2099"></a>C2099 de erro do compilador
inicializador não é uma constante  
  
 Esse erro é emitido apenas pelo compilador C e ocorre apenas para variáveis não automático.  O compilador inicializa variáveis não automático no início do programa e os valores que são inicializados com devem ser constantes.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2099.  
  
```  
// C2099.c  
int j;  
int *p;  
j = *p;   // C2099 *p is not a constant  
```  
  
## <a name="example"></a>Exemplo  
 C2099 também pode ocorrer porque o compilador não é capaz de executar a dobra constante em uma expressão em **/fp: strict** porque o ponto flutuante configurações de ambiente de precisão (consulte [controlfp_s](../../c-runtime-library/reference/controlfp-s.md) para obter mais informações) pode ser diferente da compilação para tempo de execução.  
  
 Quando constante dobra falhar, o compilador invocará inicialização dinâmica, que não é permitida em C.  
  
 Para resolver esse erro, compilar o módulo como um arquivo. cpp ou simplificar a expressão.  
  
 Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md).  
  
 O exemplo a seguir gera C2099.  
  
```  
// C2099_2.c  
// compile with: /fp:strict /c  
float X = 2.0 - 1.0;   // C2099  
float X2 = 1.0;   // OK  
```
