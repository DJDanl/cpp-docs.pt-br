---
title: Tipos de classe anônima | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- class types [C++], anonymous
- anonymous class types
ms.assetid: 9ba667b2-8c2a-4c29-82a6-fa120b9233c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8890a128ff625ead27ef34be6d057e879b22a5f6
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402728"
---
# <a name="anonymous-class-types"></a>Tipos de classe anônima
As classes podem ser anônimas — ou seja, eles podem ser declarados sem um *identificador*. Isso é útil quando você substituir um nome de classe com um **typedef** nome, da seguinte maneira:  
  
```cpp 
typedef struct  
{  
    unsigned x;  
    unsigned y;  
} POINT;  
```  
  
> [!NOTE]
>  O uso de classes anônimas mostradas no exemplo anterior é útil para preservar a compatibilidade com o código C existente. Em alguns códigos C, o uso de **typedef** em conjunto com estruturas anônimas é predominante.  
  
 As classes anônimas também são úteis quando você quer que uma referência a um membro da classe apareça como se não estivesse contida em uma classe separada, como a seguir:  
  
```cpp 
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
  
```cpp 
int i = ptv.iValue;  
```  
  
 As classes anônimas estão sujeitas a determinadas restrições. (Para obter mais informações sobre unions anônimas, consulte [uniões](../cpp/unions.md).) Classes anônimas:  
  
-   Não é possível ter um construtor ou um destruidor.  
  
-   Não é possível ser transmitido como argumentos para as funções (a menos que a verificação de tipos seja derrotada usando reticências).  
  
-   Não é possível ser retornado como valores de retorno de funções.  
  
## <a name="anonymous-structs"></a>Estruturas anônimas  
  
### <a name="microsoft-specific"></a>Específico da Microsoft  
 Uma extensão do Microsoft C permite que você declare uma variável de estrutura dentro de outra estrutura sem nomeá-la. Essas estruturas aninhadas são chamadas de estruturas anônimas. O C++ não permite estruturas anônimas.  
  
 Você pode acessar os membros de uma estrutura anônima como se fossem membros da estrutura que os contém.  
  
```cpp 
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