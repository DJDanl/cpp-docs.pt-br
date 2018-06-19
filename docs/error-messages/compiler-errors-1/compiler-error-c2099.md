---
title: C2099 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2099
dev_langs:
- C++
helpviewer_keywords:
- C2099
ms.assetid: 30e151ee-d458-4901-b0c0-d45054a913f5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 28f525676f6d9238838f0dbc245d9771f99ebeb5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33170811"
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