---
title: Especificador de classe de armazenamento externa | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- extern keyword [C]
- storage class specifiers, extern
- extern keyword [C], storage class specifier
- external linkage, storage-class specifiers
- external linkage, extern modifier
ms.assetid: 6e16d927-291f-49e4-986c-9d91a482a441
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 0f11789f985c67b59b076bed7ec849a864688743
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="extern-storage-class-specifier"></a>Especificador de classe de armazenamento externa
Uma variável declarada com o especificador de classe de armazenamento `extern` é uma referência a uma variável com o mesmo nome definida no nível externo de qualquer um dos arquivos de origem do programa. A declaração interna de `extern` é usada para tornar a definição de variável de nível externo visível dentro do bloco. A menos que seja declarado de outra forma no nível externo, uma variável declarada com a palavra-chave `extern` é visível somente no bloco em que é declarada.  
  
## <a name="example"></a>Exemplo  
 Este exemplo ilustra declarações de nível interno e externo:  
  
```  
// extern_StorageClassSpecified.c  
#include <stdio.h>  
  
void other( void );  
  
int main()  
{  
    // Reference to i, defined below:   
    extern int i;  
  
    // Initial value is zero; a is visible only within main:   
    static int a;  
  
    // b is stored in a register, if possible:   
    register int b = 0;  
  
    // Default storage class is auto:   
    int c = 0;  
  
    // Values printed are 1, 0, 0, 0:   
    printf_s( "%d\n%d\n%d\n%d\n", i, a, b, c );  
    other();  
    return;  
}  
  
int i = 1;  
  
void other( void )  
{  
    // Address of global i assigned to pointer variable:  
    static int *external_i = &i;  
  
    // i is redefined; global i no longer visible:   
    int i = 16;  
  
    // This a is visible only within the other function:   
    static int a = 2;  
  
    a += 2;  
    // Values printed are 16, 4, and 1:  
    printf_s( "%d\n%d\n%d\n", i, a, *external_i );  
}  
```  
  
 Nesse exemplo, a variável `i` é definida no nível externo com o valor inicial 1. Uma declaração de `extern` na função `main` é usada para declarar uma referência à variável `i` de nível externo. A variável **static** `a` é inicializada como 0 por padrão, já que o inicializador é omitido. A chamada para `printf` imprime os valores 1, 0, 0 e 0.  
  
 Na função `other`, o endereço da variável global `i` é usado para inicializar a variável de ponteiro **static** `external_i`. Isso funciona porque a variável global tem tempo de vida **static**, ou seja, seu endereço não é alterado durante a execução do programa. Em seguida, a variável `i` é redefinida como uma variável local com valor inicial 16. Essa redefinição não afeta o valor da variável `i` de nível externo, que é ocultada pelo uso do respectivo nome para a variável local. O valor da `i` global agora é acessível apenas indiretamente dentro desse bloco, por meio do ponteiro `external_i`. A tentativa de atribuir o endereço da variável **auto** `i` a um ponteiro não funciona, pois ela pode ser diferente cada vez que se entra no bloco. A variável `a` é declarada como uma variável **static** e inicializada como 2. Essa variável `a` não entra em conflito com a variável `a` em `main`, pois as variáveis **static** no nível interno são visíveis apenas dentro do bloco em que são declaradas.  
  
 A variável `a` é aumentada em 2, dando 4 como resultado. Se a função `other` fosse chamada novamente no mesmo programa, o valor inicial de `a` seria 4. As variáveis **static** internas mantêm seus valores quando o programa sai do bloco em que elas são declaradas e depois torna a entrar nele.  
  
## <a name="see-also"></a>Consulte também  
 [Especificadores de classe de armazenamento para declarações de nível interno](../c-language/storage-class-specifiers-for-internal-level-declarations.md)
