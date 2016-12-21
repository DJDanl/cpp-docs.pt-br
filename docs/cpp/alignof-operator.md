---
title: "Operador __alignof | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "__alignof"
  - "alignof"
  - "alignas"
  - "__alignof_cpp"
  - "alignof_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __alignof [C++]"
  - "alignas"
  - "alinhamento de estruturas"
  - "alignof"
  - "tipos [C++], requisitos de alinhamento"
ms.assetid: acb1eed7-6398-40bd-b0c5-684ceb64afbc
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador __alignof
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O c \+ \+ 11 apresenta o `alignof` operador que retorna o alinhamento, em bytes, do tipo especificado.  Para fins de portabilidade máxima, você deve usar o operador alignof em vez do operador de alignof específico da Microsoft.  
  
 **Específico da Microsoft**  
  
 Retorna um valor do tipo **size\_t** que é o requisito de alinhamento do tipo.  
  
## Sintaxe  
  
```  
  
        __alignof(   
   type    
)  
```  
  
## Comentários  
 Por exemplo:  
  
|Expressão|Valor|  
|---------------|-----------|  
|**\_\_alignof\( char \)**|1|  
|**\_\_alignof\( short \)**|2|  
|**\_\_alignof\( int \)**|4|  
|**\_\_alignof\( \_\_int64 \)**|8|  
|**\_\_alignof\( float \)**|4|  
|**\_\_alignof\( double \)**|8|  
|**\_\_alignof\( char\* \)**|4|  
  
 O valor de `__alignof` é igual ao valor de `sizeof` para tipos básicos.  Considere, no entanto, este exemplo:  
  
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
  
 Um uso de `__alignof` seria como um parâmetro para uma ou mais de suas próprias rotinas de alocação de memória.  Por exemplo, dada a seguinte estrutura definida `S`, você poderia chamar uma rotina de alocação de memória de nome `aligned_malloc` para alocar memória em um limite de alinhamento específico.  
  
```  
typedef __declspec(align(32)) struct { int a; double b; } S;  
int n = 50; // array size  
S* p = (S*)aligned_malloc(n * sizeof(S), __alignof(S));  
```  
  
 Para obter mais informações sobre como modificar o alinhamento, consulte:  
  
-   [pack](../preprocessor/pack.md)  
  
-   [align](../cpp/align-cpp.md)  
  
-   [\_\_unaligned](../cpp/unaligned.md)  
  
-   [\/Zp \(alinhamento de membro do Struct\)](../Topic/-Zp%20\(Struct%20Member%20Alignment\).md)  
  
-   [Exemplos de alinhamento da estrutura](../build/examples-of-structure-alignment.md) \(específico para x64\)  
  
 Para obter mais informações sobre as diferenças em alinhamento no código para x86 e x64, consulte:  
  
-   [Conflitos com o compilador x86](../Topic/Conflicts%20with%20the%20x86%20Compiler.md)  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)