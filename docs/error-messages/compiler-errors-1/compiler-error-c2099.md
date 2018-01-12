---
title: C2099 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C2099
dev_langs: C++
helpviewer_keywords: C2099
ms.assetid: 30e151ee-d458-4901-b0c0-d45054a913f5
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 44e5faccc28877793aa42c5fb765e6d21eb19a1b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2099"></a>C2099 de erro do compilador
inicializador não é uma constante  
  
 Esse erro é emitido somente pelo compilador C e ocorre apenas para variáveis não automático.  O compilador inicializa variáveis não automático no início do programa e os valores que são inicializados com devem ser constantes.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2099.  
  
```  
// C2099.c  
int j;  
int *p;  
j = *p;   // C2099 *p is not a constant  
```  
  
## <a name="example"></a>Exemplo  
 C2099 também pode ocorrer porque o compilador não é capaz de executar a dobra constante em uma expressão em **/fp: strict** porque o ponto flutuante configurações de ambiente de precisão (consulte [controlfp_s](../../c-runtime-library/reference/controlfp-s.md) para obter mais informações) podem diferir da compilação em tempo de execução.  
  
 Quando constante dobra falhar, o compilador chama inicialização dinâmica, o que não é permitida em C.  
  
 Para resolver esse erro, compilar o módulo como um arquivo. cpp ou Simplifique a expressão.  
  
 Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md).  
  
 O exemplo a seguir gera C2099.  
  
```  
// C2099_2.c  
// compile with: /fp:strict /c  
float X = 2.0 - 1.0;   // C2099  
float X2 = 1.0;   // OK  
```