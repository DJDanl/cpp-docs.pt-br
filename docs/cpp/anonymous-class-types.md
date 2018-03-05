---
title: "Tipos de classe anônima | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- class types [C++], anonymous
- anonymous class types
ms.assetid: 9ba667b2-8c2a-4c29-82a6-fa120b9233c8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2f2b3f46a463eed0d330f7e22975197f76c900b0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="anonymous-class-types"></a>Tipos de classe anônima
As classes podem ser anônimas — ou seja, eles podem ser declarados sem um *identificador*. Isso é útil quando você substitui um nome de classe por um nome de `typedef`, como a seguir:  
  
```  
typedef struct  
{  
    unsigned x;  
    unsigned y;  
} POINT;  
```  
  
> [!NOTE]
>  O uso de classes anônimas mostradas no exemplo anterior é útil para preservar a compatibilidade com o código C existente. Em alguns códigos C, o uso de `typedef` em conjunto com estruturas anônimas será prevalente.  
  
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
  
 No código anterior, `iValue` podem ser acessados usando o operador de seleção de membro de objeto (**.**) da seguinte maneira:  
  
```  
int i = ptv.iValue;  
```  
  
 As classes anônimas estão sujeitas a determinadas restrições. (Para obter mais informações sobre uniões anônimas, consulte [uniões](../cpp/unions.md).) Classes anônimas:  
  
-   Não é possível ter um construtor ou um destruidor.  
  
-   Não é possível ser transmitido como argumentos para as funções (a menos que a verificação de tipos seja derrotada usando reticências).  
  
-   Não é possível ser retornado como valores de retorno de funções.  
  
## <a name="anonymous-structs"></a>Estruturas anônimas  
  
### <a name="microsoft-specific"></a>Específico da Microsoft  
 Uma extensão do Microsoft C permite que você declare uma variável de estrutura dentro de outra estrutura sem nomeá-la. Essas estruturas aninhadas são chamadas de estruturas anônimas. O C++ não permite estruturas anônimas.  
  
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
  
**Fim da seção específica da Microsoft**  
  
