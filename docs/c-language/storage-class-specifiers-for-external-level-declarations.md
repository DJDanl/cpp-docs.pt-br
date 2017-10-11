---
title: "Especificadores de classe de armazenamento para declarações de nível externo | Microsoft Docs"
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
- external definitions
- linkage [C++], external
- external linkage, variable declarations
- declaring variables, external variables
- declarations [C++], external
- declarations [C++], specifiers
- external declarations
- static variables, external declarations
- variables, visibility
- external linkage, storage-class specifiers
- referencing declarations
- visibility, variables
- static storage class specifiers
ms.assetid: b76b623a-80ec-4d5d-859b-6cef422657ee
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 729d46f1e228127b712e1533c7eab5976f690663
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="storage-class-specifiers-for-external-level-declarations"></a>Especificadores de classe de armazenamento para declarações de nível externo
As variáveis externas são variáveis no escopo de arquivo. São definidas fora de qualquer função, e estão potencialmente disponíveis para muitas funções. As funções só podem ser definidas no nível externo e, consequentemente, não podem ser aninhadas. Por padrão, todas as referências a variáveis externas e a funções do mesmo nome são referências ao mesmo objeto, o que significa que elas possuem “vinculação externa”. (Você pode usar a palavra-chave de **static** para substituir isso. Consulte as informações nesta seção para obter mais detalhes sobre **static**.)  
  
 As declarações de variáveis no nível externo são definições de variáveis (“declarações de definição”) ou referências a variáveis definidas em outro lugar (“declarações de referência”).  
  
 Uma declaração de variável externa que também inicializa a variável (implícita ou explicitamente) é uma declaração de definição da variável. Uma definição no nível externo pode ter diversos formatos:  
  
-   Uma variável declarada com o especificador de classe de armazenamento **static**. Você pode inicializar explicitamente a variável **static** com uma expressão constante, como descrito em [Inicialização](../c-language/initialization.md). Se você omitir o inicializador, a variável será inicializado com 0 por padrão. Por exemplo, essas duas instruções são consideradas definições da variável `k`.  
  
    ```  
    static int k = 16;  
    static int k;  
    ```  
  
-   Uma variável inicializada explicitamente no nível externo. Por exemplo, `int j = 3;` é uma definição da variável `j`.  
  
 Em declarações de variável no nível externo (ou seja, fora de todas as funções), você pode usar o **static** ou `extern` storage-class-specifier ou omitir totalmente esse especificador. Você não pode usar os terminais de **auto** e **register** *storage-class-specifier* no nível externo.  
  
 Depois que uma variável é definida no nível externo, ela é visível durante o resto da unidade de tradução. A variável não é visível antes de sua declaração no mesmo arquivo de origem. Além disso, ela não é visível em outros arquivos de origem do programa, a menos que uma declaração de referência torne-a visível, como descrito a seguir.  
  
 As regras relativas a **static** incluem:  
  
-   Variáveis declaradas fora de todos os blocos sem a palavra-chave de **static** sempre mantêm os valores em todo o programa. Para restringir o acesso a uma unidade de tradução específica, você deve usar a palavra-chave **static**. Isso dá a elas “vinculação interna”. Para torná-las globais a todo um programa, omita a classe de armazenamento explícita ou use a palavra-chave `extern` (consulte as regras na lista a seguir). Isso dá a elas “vinculação externa”. As vinculações interna e externa também são discutidas em [Vinculação](../c-language/linkage.md).  
  
-   Você pode definir uma variável no nível externo apenas uma vez em um programa. É possível pode definir outra variável com o mesmo nome e o especificador de classe de armazenamento **static** em uma unidade diferente da tradução. Como cada definição de **static** só é visível em sua própria unidade de tradução, não ocorre qualquer conflito. Isso fornece uma maneira útil de ocultar nomes de identificadores que devem ser compartilhados entre funções de uma única unidade de tradução, mas não devem ser visíveis para outras unidades.  
  
-   O especificador de classe de armazenamento **static** pode ser aplicado também a funções. Se você declarar uma função **static**, o nome será invisível fora do arquivo no qual ela foi declarada.  
  
 As regras para usar `extern` são:  
  
-   O especificador de classe de armazenamento `extern` declara uma referência a uma variável definida em outro lugar. Você pode usar uma declaração `extern` para tornar uma definição em outro arquivo de origem visível, ou para tornar uma variável visível antes da sua definição no mesmo arquivo de origem. Depois que você tiver declarado uma referência à variável no nível externo, a variável estará visível durante todo o restante da unidade de tradução na qual a referência declarada ocorre.  
  
-   Para que uma referência `extern` seja válida, a variável à qual ela faz referência deve ser definida apenas uma vez no nível externo. Essa definição (sem a classe de armazenamento `extern`) pode ocorrer em qualquer das unidades de tradução que compõem o programa.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir ilustra declarações externas:  
  
```  
/******************************************************************  
                      SOURCE FILE ONE   
*******************************************************************/  
#include <stdio.h>  
  
extern int i;                // Reference to i, defined below   
void next( void );           // Function prototype              
  
int main()  
{  
    i++;  
    printf_s( "%d\n", i );   // i equals 4   
    next();  
}  
  
int i = 3;                  // Definition of i  
  
void next( void )  
{  
    i++;  
    printf_s( "%d\n", i );  // i equals 5  
    other();  
}  
  
/******************************************************************  
                      SOURCE FILE TWO   
*******************************************************************/  
#include <stdio.h>  
  
extern int i;              // Reference to i in   
                           // first source file   
void other( void )  
{  
    i++;  
    printf_s( "%d\n", i ); // i equals 6   
}  
```  
  
 Os dois arquivos de origem neste exemplo contêm um total de três declarações externas de `i`. Apenas uma das declarações é uma “declaração de definição”. Esta declaração,  
  
```  
int i = 3;  
```  
  
 define a variável global `i` e a inicializa com valor inicial de 3. A declaração "de referência" `i` no topo do primeiro arquivo de origem que usa `extern` torna a variável global visível antes de sua declaração de definição no arquivo. A declaração de referência de `i` no segundo arquivo de origem também torna a variável visível no arquivo de origem. Se uma instância de definição para uma variável não for fornecida na unidade de tradução, o compilador presume que existe uma  
  
```  
extern int x;  
```  
  
 declaração de referência que uma referência de definição  
  
```  
int x = 0;  
```  
  
 aparece em outra unidade de tradução do programa.  
  
 Todas as três funções, `main`, `next`, e `other`, executadas na mesma tarefa: aumentam `i` e a imprimem. Os valores 4, 5 e 6, são impressos.  
  
 Se a variável `i` não tivesse sido inicializada, ela seria definida automaticamente como 0. Nesse caso, os valores 1, 2, e 3 seriam impressos. Consulte [Inicialização](../c-language/initialization.md) para obter mais informações sobre inicialização de variáveis.  
  
## <a name="see-also"></a>Consulte também  
 [Classes de armazenamento C](../c-language/c-storage-classes.md)
