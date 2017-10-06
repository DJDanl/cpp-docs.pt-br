---
title: operador alignof | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- alignas_cpp
- __alignof_cpp
- alignof_cpp
dev_langs:
- C++
helpviewer_keywords:
- alignas
- alignment of structures
- __alignof keyword [C++]
- alignof
- types [C++], alignment requirements
ms.assetid: acb1eed7-6398-40bd-b0c5-684ceb64afbc
caps.latest.revision: 11
author: mikeblome
ms.author: mblome
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
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 66ec7ff196a4f22aec043d8b76faf0189e05cd0f
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="alignof-operator"></a>Operador __alignof
C++ 11 apresenta o `alignof` operador que retorna o alinhamento, em bytes, do tipo especificado. Para portabilidade máximo, você deve usar o operador alignof em vez do operador de alignof específicas da Microsoft.  
  
 **Seção específica da Microsoft**  
  
 Retorna um valor do tipo **size_t** que é o requisito de alinhamento do tipo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      __alignof(   
   type    
)  
```  
  
## <a name="remarks"></a>Comentários  
 Por exemplo:  
  
|Expressão|Valor|  
|----------------|-----------|  
|**alignof (char)**|1|  
|**alignof (curta)**|2|  
|**alignof (int)**|4|  
|**alignof ( \__int64)**|8|  
|**alignof (float)**|4|  
|**alignof (double)**|8|  
|**alignof (char\* )**|4|  
  
 O valor de `__alignof` é igual ao valor de `sizeof` para tipos básicos. Considere, no entanto, este exemplo:  
  
```  
typedef struct { int a; double b; } S;  
// __alignof(S) == 8  
```  
  
 Nesse caso, o valor de `__alignof` é o requisito de alinhamento do maior elemento na estrutura.  
  
 De maneira semelhante, para  
  
```  
typedef __declspec(align(32)) struct { int a; } S;  
```  
  
 `__alignof(S)` é igual a `32`.  
  
 Um uso de `__alignof` seria como um parâmetro para uma ou mais de suas próprias rotinas de alocação de memória. Por exemplo, dada a seguinte estrutura definida `S`, você poderia chamar uma rotina de alocação de memória de nome `aligned_malloc` para alocar memória em um limite de alinhamento específico.  
  
```  
typedef __declspec(align(32)) struct { int a; double b; } S;  
int n = 50; // array size  
S* p = (S*)aligned_malloc(n * sizeof(S), __alignof(S));  
```  
  
 Para obter mais informações sobre como modificar o alinhamento, consulte:  
  
-   [pack](../preprocessor/pack.md)  
  
-   [align](../cpp/align-cpp.md)  
  
-   [__unaligned](../cpp/unaligned.md)  
  
-   [/ZP (alinhamento de membro de Struct)](../build/reference/zp-struct-member-alignment.md)  
  
-   [Exemplos de alinhamento da estrutura](../build/examples-of-structure-alignment.md) (específico para x64)  
  
 Para obter mais informações sobre as diferenças no alinhamento em código para x86 e x64, consulte:  
  
-   [conflitos com o compilador x86](../build/conflicts-with-the-x86-compiler.md)  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)
