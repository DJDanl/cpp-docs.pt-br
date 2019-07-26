---
title: Usando operadores de inserção e controlando o formato
ms.date: 11/04/2016
helpviewer_keywords:
- insertion operators
ms.assetid: cdefe986-6548-4cd1-8a67-b431d7d36a1c
ms.openlocfilehash: 2cf399501c0eab32e8bee80dfcb98d870c0193cb
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68458020"
---
# <a name="using-insertion-operators-and-controlling-format"></a>Usando operadores de inserção e controlando o formato

Este tópico mostra como controlar o formato e a criação de operadores de inserção para suas próprias classes. O operador de inserção ( **<<** ), que é programado previamente para todos os tipos de dados C++, envia bytes a um objeto de fluxo de saída. Operadores de inserção trabalham com "manipuladores" predefinidos, que são elementos que alteram o formato padrão de argumentos inteiros.

É possível controlar o formato com as seguintes opções:

- [Largura da Saída](#vclrfoutputwidthanchor3)

- [Alinhamento](#vclrfalignmentanchor4)

- [Precisão](#vclrfprecisionanchor5)

- [Base](#vclrfradixanchor6)

## <a name="vclrfoutputwidthanchor3"></a> Largura da Saída

Para alinhar a saída, especifique a largura de saída para cada item colocando `setw` o manipulador no fluxo ou chamando a função `width` de membro. Este exemplo alinha à direita os valores em uma coluna com pelo menor 10 caracteres de largura:

```cpp
// output_width.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

int main( )
{
   double values[] = { 1.23, 35.36, 653.7, 4358.24 };
   for( int i = 0; i < 4; i++ )
   {
      cout.width(10);
      cout << values[i] << '\n';
   }
}
```

```Output
      1.23
     35.36
     653.7
   4358.24
```

Os espaços em branco são adicionados a qualquer valor menor do que 10 caracteres de largura.

Para preencher um campo, use a `fill` função membro, que define o valor do caractere de preenchimento para campos que têm uma largura especificada. O padrão é um espaço em branco. Para preencher a coluna de números com asteriscos, modifique o loop **for** anterior, da seguinte maneira:

```cpp
for (int i = 0; i <4; i++)
{
    cout.width(10);
    cout.fill('*');
    cout << values[i] << endl;
}
```

O manipulador `endl` substitui o caractere de nova linha (`'\n'`). O resultado terá a seguinte aparência:

```Output
******1.23
*****35.36
*****653.7
***4358.24
```

Para especificar as larguras de elementos de dados na mesma linha, use o manipulador `setw`:

```cpp
// setw.cpp
// compile with: /EHsc
#include <iostream>
#include <iomanip>
using namespace std;

int main( )
{
   double values[] = { 1.23, 35.36, 653.7, 4358.24 };
   char *names[] = { "Zoot", "Jimmy", "Al", "Stan" };
   for( int i = 0; i < 4; i++ )
      cout << setw( 7 )  << names[i]
           << setw( 10 ) << values[i] << endl;
}
```

A `width` função de membro é declarada em \<iostream >. Se você usar `setw` ou qualquer outro manipulador com argumentos, inclua \<iomanip>. Na saída, as cadeias de caracteres são impressas em um campo de largura 6 e inteiros em um campo de largura 10:

```Output
   Zoot      1.23
  Jimmy     35.36
     Al     653.7
   Stan   4358.24
```

`setw` Nem`width` trunca valores. Se a saída formatada exceder a largura, o valor inteiro será impresso, sujeito a configuração de precisão do fluxo. Ambos `setw` e`width` afetam apenas o campo a seguir. A largura do campo será revertida para seu comportamento padrão (a largura necessária) após a impressão de um campo. No entanto, as outras opções de formato de fluxo permanecerão em vigor até serem alteradas.

## <a name="vclrfalignmentanchor4"></a> Alinhamento

Fluxos de saída padrão para o texto alinhado à direita. Para alinhar os nomes do exemplo anterior à esquerda e os números à direita, substitua o loop **for** da seguinte maneira:

```cpp
for (int i = 0; i <4; i++)
    cout << setiosflags(ios::left)
         << setw(6) << names[i]
         << resetiosflags(ios::left)
         << setw(10) << values[i] << endl;
```

O resultado terá a seguinte aparência:

```Output
Zoot        1.23
Jimmy      35.36
Al         653.7
Stan     4358.24
```

O sinalizador de alinhamento à esquerda é definido usando o manipulador [setiosflags](../standard-library/iomanip-functions.md#setiosflags) com o enumerador `left`. Esse enumerador é definido na classe [ios](../standard-library/basic-ios-class.md), então, sua referência deve incluir o prefixo **ios::** . O manipulador [resetiosflags](../standard-library/iomanip-functions.md#resetiosflags) desativa o sinalizador de alinhamento à esquerda. Ao `width` contrário `setw`de e, o `setiosflags` efeito `resetiosflags` de e é permanente.

## <a name="vclrfprecisionanchor5"></a> Precisão

O valor padrão para a precisão de ponto flutuante é seis. Por exemplo, o número 3466.9768 será impresso como 3466.98. Para alterar a maneira pela qual esse valor é impresso, use o manipulador [setprecision](../standard-library/iomanip-functions.md#setprecision). O manipulador tem dois sinalizadores: [fixo](../standard-library/ios-functions.md#fixed) e [científico](../standard-library/ios-functions.md#scientific). Se for definido como [fixo](../standard-library/ios-functions.md#fixed), o número será impresso como 3466.976800. Se `scientific` for definido, ele será impresso como 3.4669773 + 003.

Para exibir os números de ponto flutuante mostrados em [Alinhamento](#vclrfalignmentanchor4) com um dígito significativo, substitua o loop **for** da seguinte maneira:

```cpp
for (int i = 0; i <4; i++)
    cout << setiosflags(ios::left)
         << setw(6)
         << names[i]
         << resetiosflags(ios::left)
         << setw(10)
         << setprecision(1)
         << values[i]
         << endl;
```

O programa imprime esta lista:

```Output
Zoot          1
Jimmy     4e+01
Al        7e+02
Stan      4e+03
```

Para eliminar a notação científica, insira essa instrução antes do loop **for**:

```cpp
cout << setiosflags(ios::fixed);
```

Com notação fixa, o programa imprime com um dígito após a vírgula decimal.

```Output
Zoot         1.2
Jimmy       35.4
Al         653.7
Stan      4358.2
```

Se você alterar o `ios::fixed` sinalizador para `ios::scientific`, o programa imprime isto:

```cpp
Zoot    1.2e+00
Jimmy   3.5e+01
Al      6.5e+02
Stan    4.4e+03
```

Novamente, o programa imprimirá um dígito após a vírgula decimal. `ios::fixed` Se ou `ios::scientific` for definido, o valor de precisão determinará o número de dígitos após o ponto decimal. Se nenhum sinalizador for definido, o valor de precisão determinará o número total de dígitos significativos. O manipulador `resetiosflags` limpará esses sinalizadores.

## <a name="vclrfradixanchor6"></a> Base

Os `dec`manipuladores `oct`, `hex` e definem a base padrão para entrada e saída. Por exemplo, se você inserir o `hex` manipulador no fluxo de saída, o objeto converterá corretamente a representação de dados internos de inteiros em um formato de saída hexadecimal. Os números serão exibidos com dígitos de a-f, em minúsculas se o sinalizador [maiúsculas](../standard-library/ios-functions.md#uppercase) estiver limpo (padrão); caso contrário, eles serão exibidos em maiúsculas. A base padrão é `dec` (Decimal).

## <a name="quoted-strings-c14"></a>Cadeias de caracteres entre aspas (C++14)

Ao inserir uma cadeia de caracteres em um fluxo, é possível recuperar facilmente essa mesma cadeia de caracteres chamando a função membro stringstream::str(). No entanto, se você quiser usar o operador de extração para inserir o fluxo em uma nova cadeia de caracteres em um momento posterior, você poderá obter um resultado inesperado, pois o >> operador, por padrão, parará quando encontrar o primeiro caractere de espaço em branco.

```cpp
std::stringstream ss;
std::string inserted = "This is a sentence.";
std::string extracted;

ss << inserted;
ss >> extracted;

std::cout << inserted;     //  This is a sentence.
std::cout << extracted;    //  This
```

Esse comportamento pode ser superado manualmente, mas para tornar a cadeia de caracteres de ida e volta mais conveniente, `std::quoted` o c++ 14 \<adiciona o fluxo manipulador no iomanip >. Após a inserção, `quoted()` envolve a cadeia de caracteres com um delimitador (aspas duplas ' " ', por padrão) e, após a extração, manipula o fluxo para extrair todos os caracteres até encontrar o delimitador final. Quaisquer aspas inseridas serão ignoradas com um caractere de escape ('\\\\' por padrão).

Os delimitadores estão presentes apenas no objeto de fluxo; Eles não estão presentes na cadeia de caracteres extraída, mas estão presentes na cadeia de caracteres retornada por [basic_stringstream:: Str](../standard-library/basic-stringstream-class.md#str).

O comportamento de espaço em branco das operações de inserção e extração é independe de como uma cadeia de caracteres é representada no código, assim, o operador entre aspas será útil mesmo se a cadeia de caracteres de entrada for uma cadeia de caracteres bruta, literal ou regular. A cadeia de caracteres de entrada, seja qual for seu formato, pode ter aspas incorporadas, quebras de linha, guias e assim por diante e todos esses serão preservados pelo manipulador quoted().

Para obter mais informações e exemplos de código completo [](../standard-library/iomanip-functions.md#quoted), consulte quoted.

## <a name="see-also"></a>Consulte também

[Fluxos de saída](../standard-library/output-streams.md)
