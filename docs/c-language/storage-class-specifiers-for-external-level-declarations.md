---
title: Especificadores de classe de armazenamento para declarações de nível externo
ms.date: 11/04/2016
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
ms.openlocfilehash: 6c30b8a12c0bf26bc35905872fb6fa527b367ef4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229461"
---
# <a name="storage-class-specifiers-for-external-level-declarations"></a>Especificadores de classe de armazenamento para declarações de nível externo

As variáveis externas são variáveis no escopo de arquivo. São definidas fora de qualquer função, e estão potencialmente disponíveis para muitas funções. As funções só podem ser definidas no nível externo e, consequentemente, não podem ser aninhadas. Por padrão, todas as referências a variáveis externas e funções de mesmo nome são referências ao mesmo objeto, o que significa que elas têm *vínculo externo*. (Você pode usar a **`static`** palavra-chave para substituir esse comportamento.)

As declarações de variáveis no nível externo são definições de variáveis (*definindo declarações*) ou referências a variáveis definidas em outro lugar (*declarações de referência*).

Uma declaração de variável externa que também inicializa a variável (implícita ou explicitamente) é uma declaração de definição da variável. Uma definição no nível externo pode ter diversos formatos:

- Uma variável que você declara com o **`static`** especificador de classe de armazenamento. Você pode inicializar explicitamente a **`static`** variável com uma expressão constante, conforme descrito em [inicialização](../c-language/initialization.md). Se você omitir o inicializador, a variável será inicializado com 0 por padrão. Por exemplo, essas duas instruções são consideradas definições da variável `k`.

    ```C
    static int k = 16;
    static int k;
    ```

- Uma variável inicializada explicitamente no nível externo. Por exemplo, `int j = 3;` é uma definição da variável `j`.

Em declarações de variáveis no nível externo (ou seja, fora de todas as funções), você pode usar o **`static`** **`extern`** especificador de classe de armazenamento ou ou omitir o especificador de classe de armazenamento inteiramente. Você não pode usar **`auto`** os **`register`** *`storage-class-specifier`* terminais e no nível externo.

Depois que uma variável é definida no nível externo, ela é visível durante o resto da unidade de tradução. A variável não é visível antes de sua declaração no mesmo arquivo de origem. Além disso, ela não é visível em outros arquivos de origem do programa, a menos que uma declaração de referência torne-a visível, como descrito a seguir.

As regras relacionadas a **`static`** incluem:

- Variáveis declaradas fora de todos os blocos sem a **`static`** palavra-chave sempre retêm seus valores em todo o programa. Para restringir o acesso a uma unidade de tradução específica, você deve usar a **`static`** palavra-chave. Isso lhes dá *vínculo interno*. Para torná-los globais a um programa inteiro, omita a classe de armazenamento explícita ou use a palavra-chave **`extern`** (consulte as regras na próxima lista). Isso lhes dá *vínculo externo*. As vinculações interna e externa também são discutidas em [Vinculação](../c-language/linkage.md).

- Você pode definir uma variável no nível externo apenas uma vez em um programa. Você pode definir outra variável com o mesmo nome e o **`static`** especificador de classe de armazenamento em uma unidade de tradução diferente. Como cada **`static`** definição é visível somente dentro de sua própria unidade de tradução, nenhum conflito ocorre. Ele fornece uma maneira útil de ocultar nomes de identificadores que devem ser compartilhados entre as funções de uma única unidade de tradução, mas não visíveis para outras unidades de tradução.

- O **`static`** especificador de classe de armazenamento também pode se aplicar a funções. Se você declarar uma função **`static`** , seu nome será invisível fora do arquivo no qual ele foi declarado.

As regras para uso do **`extern`** são:

- O **`extern`** especificador de classe de armazenamento declara uma referência a uma variável definida em outro lugar. Você pode usar uma **`extern`** declaração para tornar uma definição em outro arquivo de origem visível, ou para tornar uma variável visível antes de sua definição no mesmo arquivo de origem. Depois de declarar uma referência à variável no nível externo, a variável será visível no restante da unidade de tradução em que ocorre a referência declarada.

- Para que uma **`extern`** referência seja válida, a variável à qual ela se refere deve ser definida uma vez e somente uma vez no nível externo. Essa definição (sem a **`extern`** classe de armazenamento) pode estar em qualquer uma das unidades de tradução que compõem o programa.

## <a name="example"></a>Exemplo

O exemplo a seguir ilustra declarações externas:

```C
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

```C
int i = 3;
```

define a variável global `i` e a inicializa com valor inicial de 3. A declaração "referenciando" de `i` na parte superior do primeiro arquivo de origem usando **`extern`** torna a variável global visível antes de sua declaração de definição no arquivo. A declaração de referência de `i` no segundo arquivo de origem também torna a variável visível no arquivo de origem. Se uma instância de definição para uma variável não for fornecida na unidade de tradução, o compilador presume que existe uma

```C
extern int x;
```

declaração de referência que uma referência de definição

```C
int x = 0;
```

aparece em outra unidade de tradução do programa.

Todas as três funções, `main`, `next`, e `other`, executadas na mesma tarefa: aumentam `i` e a imprimem. Os valores 4, 5 e 6, são impressos.

Se a variável não `i` tiver sido inicializada, ela teria sido definida como 0 automaticamente. Nesse caso, os valores 1, 2, e 3 seriam impressos. Consulte [Inicialização](../c-language/initialization.md) para obter mais informações sobre inicialização de variáveis.

## <a name="see-also"></a>Confira também

[Classes de armazenamento C](../c-language/c-storage-classes.md)
