---
title: "Tipos de classe an&#244;nima | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de classe anônima"
  - "tipos de classes, anônimos"
ms.assetid: 9ba667b2-8c2a-4c29-82a6-fa120b9233c8
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tipos de classe an&#244;nima
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As classes podem ser anônimas, ou seja, podem ser declaradas sem um *identificador*.  Isso é útil quando você substitui um nome de classe por um nome de `typedef`, como a seguir:  
  
```  
typedef struct  
{  
    unsigned x;  
    unsigned y;  
} POINT;  
```  
  
> [!NOTE]
>  O uso de classes anônimas mostradas no exemplo anterior é útil para preservar a compatibilidade com o código C existente.  Em alguns códigos C, o uso de `typedef` em conjunto com estruturas anônimas será prevalente.  
  
 As classes anônimas também são úteis quando você quer que uma referência a um membro da classe apareça como se não estivesse contida em uma classe separada, como a seguir:  
  
```  
struct PTValue  
{  
    POINT ptLoc;  
    union  
    {  
        int  iValue;  
        long lValue;  
    };  
};  
  
PTValue ptv;  
```  
  
 No código anterior, `iValue` pode ser acessado usando o operador de seleção de membros de objeto \(**.**\) como segue:  
  
```  
int i = ptv.iValue;  
```  
  
 As classes anônimas estão sujeitas a determinadas restrições.  \(Para obter mais informações sobre unions anônimas, consulte [Unions](../cpp/unions.md).\) Classes anônimas:  
  
-   Não é possível ter um construtor ou um destruidor.  
  
-   Não é possível ser transmitido como argumentos para as funções \(a menos que a verificação de tipos seja derrotada usando reticências\).  
  
-   Não é possível ser retornado como valores de retorno de funções.  
  
## Estruturas anônimas  
  
### Específico da Microsoft  
 Uma extensão do Microsoft C permite que você declare uma variável de estrutura dentro de outra estrutura sem nomeá\-la.  Essas estruturas aninhadas são chamadas de estruturas anônimas.  O C\+\+ não permite estruturas anônimas.  
  
 Você pode acessar os membros de uma estrutura anônima como se fossem membros da estrutura que os contém.  
  
```  
// anonymous_structures.c  
#include <stdio.h>  
  
struct phone  
{  
    int  areacode;  
    long number;  
};  
  
struct person  
{  
    char   name[30];  
    char   gender;  
    int    age;  
    int    weight;  
    struct phone;    // Anonymous structure; no name needed  
} Jim;  
  
int main()  
{  
    Jim.number = 1234567;  
    printf_s("%d\n", Jim.number);     
}  
//Output: 1234567  
```  
  
### FIM de Específico da Microsoft  
  
## Consulte também  
 [\(NOTINBUILD\) Defining Class Types](http://msdn.microsoft.com/pt-br/e8c65425-0f3a-4dca-afc2-418c3b1e57da)