---
title: Sistema do tipo C++ (C++ moderno)
ms.date: 11/19/2018
ms.topic: conceptual
ms.assetid: 553c0ed6-77c4-43e9-87b1-c903eec53e80
ms.openlocfilehash: b947bd6955a80e051d1dab81061b4b2bf2ab19c8
ms.sourcegitcommit: 8178d22701047d24f69f10d01ba37490e3d67241
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/18/2019
ms.locfileid: "69498637"
---
# <a name="c-type-system-modern-c"></a>Sistema do tipo C++ (C++ moderno)

O conceito do *tipo* é muito importante no C++. Cada variável, argumento de função e valor de retorno de função deve ter um tipo para ser compilado. Além disso, cada expressão (incluindo valores literais) recebe implicitamente um tipo do compilador antes de ser avaliada. Alguns exemplos de tipos incluem **int** para armazenar valores integrais, **duplo** para armazenar valores de ponto flutuante (também conhecidos como tipos de dados *escalares* ) ou a classe de biblioteca padrão [std:: basic_string](../standard-library/basic-string-class.md) para armazenar texto. Você pode criar seu próprio tipo definindo uma **classe** ou **struct**. O tipo especifica a quantidade de memória que será atribuída à variável (ou o resultado da expressão), os tipos de valores que podem ser armazenados nessa variável, como os valores (como padrão de bits) são interpretados e as operações que podem ser executadas nele. Este artigo contém uma visão geral informal dos principais recursos do sistema de tipos C++.

## <a name="terminology"></a>Terminologia

**Variável**: o nome simbólico de uma quantidade de dados para que o nome possa ser usado para acessar os dados aos quais ele se refere em todo o escopo do código onde ele está definido. No C++, a *variável* geralmente é usada para fazer referência a instâncias de tipos de dados escalares, enquanto instâncias de outros tipos geralmente são chamadas de *objetos*.

**Objeto**: para simplificar e consistência, este artigo usa o termo *objeto* para se referir a qualquer instância de uma classe ou estrutura, e quando ele é usado no sentido geral inclui todos os tipos, até mesmo variáveis escalares.

**Tipo de Pod** (dados antigos simples): essa categoria informal de C++ tipos de dados no refere-se a tipos que são escalares (consulte a seção tipos fundamentais) ou que são *classes Pod*. Uma classe POD não tem membros de dados estáticos que também não sejam PODs e não tem construtores definidos pelo usuário, destruidores definidos pelo usuário ou operadores de atribuição definidos pelo usuário. Além disso, uma classe POD não tem função virtual, nenhuma classe base e nenhum membro de dados não estático particular ou protegido. Os tipos POD são quase sempre usados para a troca de dados externos, por exemplo, com um módulo escrito na linguagem C (que tem apenas tipos POD).

## <a name="specifying-variable-and-function-types"></a>Especificando tipos de variável e de função

C++é uma linguagem *fortemente tipada* e também é *digitada estaticamente*; cada objeto tem um tipo e esse tipo nunca é alterado (não deve ser confundido com objetos de dados estáticos).
**Quando você declara uma variável** em seu código, deve especificar seu tipo explicitamente ou usar a palavra-chave **auto** para instruir o compilador a deduzir o tipo do inicializador.
**Quando você declara uma função** em seu código, deve especificar o tipo de cada argumento e seu valor de retorno, ou **void** se nenhum valor for retornado pela função. A exceção se dá quando você está usando modelos de função, que permitem argumentos de tipos arbitrários.

Após a primeira declaração de uma variável, você não pode alterar seu tipo em um momento posterior. No entanto, você pode copiar o valor da variável ou o valor de retorno de uma função para outra variável de tipo diferente. Essas operações são chamadas de *conversões de tipo*, que às vezes são necessárias, mas também são fontes potenciais de perda ou incorreção de dados.

Ao declarar uma variável do tipo POD, é altamente recomendável inicializá-la, ou seja, dar a ela um valor inicial. Até que você inicialize uma variável, ela terá o valor “garbage”, que consiste nos bits que estavam nesse local de memória anteriormente. Esse é um aspecto importante da linguagem C++ a ser lembrado, especialmente se você estiver vindo de outra linguagem que manipule a inicialização para você. Ao declarar uma variável do tipo de classe não POD, o construtor manipula a inicialização.

O exemplo a seguir mostra algumas declarações de variável simples com algumas descrições para cada uma. O exemplo também mostra como o compilador usa informações de tipo para permitir ou não permitir determinadas operações subsequentes na variável.

```cpp
int result = 0;              // Declare and initialize an integer.
double coefficient = 10.8;   // Declare and initialize a floating
                             // point value.
auto name = "Lady G.";       // Declare a variable and let compiler
                             // deduce the type.
auto address;                // error. Compiler cannot deduce a type
                             // without an intializing value.
age = 12;                    // error. Variable declaration must
                             // specify a type or use auto!
result = "Kenny G.";         // error. Can’t assign text to an int.
string result = "zero";      // error. Can’t redefine a variable with
                             // new type.
int maxValue;                // Not recommended! maxValue contains
                             // garbage bits until it is initialized.
```

## <a name="fundamental-built-in-types"></a>Tipos (internos) fundamentais

Ao contrário de algumas linguagens, C++ não tem tipo base universal do qual todos os outros tipos são derivados. O idioma inclui muitos *tipos fundamentais*, também conhecidos como *tipos internos*. Isso inclui tipos numéricos, como **int**, **Double**, **Long**, **bool**, mais os tipos **Char** e **wchar_t** para caracteres ASCII e Unicode, respectivamente. Todos os tipos fundamentais (exceto **bool**, **Double**, **wchar_t** e os tipos relacionados) têm todas as versões não assinadas, que modificam o intervalo de valores que a variável pode armazenar. Por exemplo, um **int**, que armazena um inteiro com sinal de 32 bits, pode representar um valor de-2.147.483.648 a 2.147.483.647. Um **int não assinado**, que também é armazenado como 32 bits, pode armazenar um valor de 0 a 4.294.967.295. O número total de valores possíveis em cada caso é o mesmo; somente o intervalo é diferente.

Os tipos fundamentais são reconhecidos pelo compilador, que tem regras internas que controlam que operações você poderá executar neles e como eles serão convertidos em outros tipos fundamentais. Para obter uma lista completa de tipos internos e seus limites de tamanho e numérico, consulte [tipos fundamentais](../cpp/fundamental-types-cpp.md).

A ilustração a seguir mostra os tamanhos relativos dos tipos internos:

![Tamanho em bytes de tipos&#45;internos](../cpp/media/built-intypesizes.png "Tamanho em bytes de tipos&#45;internos")

A tabela a seguir lista os tipos fundamentais usados com mais frequência:

|Digite|Tamanho|Comentário|
|----------|----------|-------------|
|int|4 bytes|A opção padrão para valores integrais.|
|double|8 bytes|A opção padrão para valores de ponto flutuante.|
|bool|1 byte|Representa valores que podem ser true ou false.|
|char|1 byte|Use os caracteres ASCII em cadeias de caracteres do estilo C mais antigo ou objetos std::string que nunca precisarão ser convertidos em UNICODE.|
|wchar_t|2 bytes|Representa os valores de caractere "largos" que podem ser codificados no formato UNICODE (UTF-16 no Windows, outros sistemas operacionais podem ser diferentes). Esse é o tipo de caractere usado em cadeias de caracteres do tipo `std::wstring`.|
|unsigned&nbsp;char|1 byte|O C++ não tem o tipo `byte` interno.  Use unsigned char para representar um valor de bytes.|
|unsigned int|4 bytes|Escolha padrão para sinalizadores de bit.|
|long long|8 bytes|Representa valores inteiros muito grandes.|

## <a name="the-void-type"></a>O tipo void

O tipo **void** é um tipo especial; Você não pode declarar uma variável do tipo **void**, mas pode declarar uma variável do tipo __void \*__ (ponteiro para **void**), que às vezes é necessário ao alocar memória bruta (não tipada). No entanto, os ponteiros para **void** não são de tipo seguro e, em geral, seu uso C++é fortemente desencorajado no moderno. Em uma declaração de função, um valor de retorno **nulo** significa que a função não retorna um valor; Esse é um uso comum e aceitável de **void**. Embora a linguagem C exigia funções que têm zero parâmetros para declarar **void** na lista de parâmetros, por exemplo, `fou(void)`, essa prática é desencorajada em C++ moderno e deve ser declarada `fou()`. Para obter mais informações, consulte [conversões de tipo e segurança de tipo](../cpp/type-conversions-and-type-safety-modern-cpp.md).

## <a name="const-type-qualifier"></a>Qualificador do tipo const

Qualquer tipo interno ou definido pelo usuário pode ser qualificado pela palavra-chave const. Além disso, as funções de membro podem ser qualificadas como **const**e até mesmo **constantes**sobrecarregadas. O valor de um tipo **const** não pode ser modificado após ser inicializado.

```cpp

const double PI = 3.1415;
PI = .75 //Error. Cannot modify const variable.
```

O qualificador **const** é usado extensivamente em declarações de função e variável, e a "correção constante" é um C++conceito importante no; Basicamente, isso significa usar **const** para garantir, no momento da compilação, que os valores não são modificados de forma não intencional. Para obter mais informações, consulte [const](../cpp/const-cpp.md).

Um tipo **const** é diferente de sua versão não const; por exemplo, **const int** é um tipo distinto de **int**. Você pode usar o C++ operador **const_cast** nessas raras ocasiões em que você deve remover *const-qualidade* de uma variável. Para obter mais informações, consulte [conversões de tipo e segurança de tipo](../cpp/type-conversions-and-type-safety-modern-cpp.md).

## <a name="string-types"></a>Tipos de cadeia de caracteres

Estritamente falando, a C++ linguagem não tem nenhum tipo de cadeia de caracteres interno; **Char** e **wchar_t** armazenam caracteres únicos-você deve declarar uma matriz desses tipos para aproximar uma cadeia de caracteres, adicionando um valor nulo de encerramento (por exemplo, ASCII `'\0'`) ao elemento da matriz, um após o último caractere válido (também chamado de  *Cadeia de caracteres C-Style*). As cadeias de caracteres de estilo C exigiam que muito mais códigos fossem escritos ou o uso de funções da biblioteca de utilitários de cadeia de caracteres externos. Mas, no C++moderno, temos os tipos de biblioteca padrão `std::string` (para cadeias de caracteres de caractere de tipo **de caractere de 8 bits)** ou `std::wstring` (para cadeias de caracteres de tipo **wchar_t**de 16 bits). Esses C++ contêineres de biblioteca padrão podem ser considerados como tipos de cadeia de caracteres nativos porque fazem parte das bibliotecas padrão incluídas em qualquer ambiente C++ de compilação compatível. Basta usar a diretiva `#include <string>` para tornar esses tipos disponíveis em seu programa. (Se você estiver usando MFC ou ATL, a classe CString também estará disponível, mas não faz parte do C++ padrão.) O uso de matrizes de caracteres com terminação nula (as cadeias de estilo C mencionadas anteriormente) é altamente C++desencorajado no moderno.

## <a name="user-defined-types"></a>Tipos definidos pelo usuário

Quando você define uma **classe**, **struct**, **Union**ou **enum**, essa construção é usada no restante do seu código como se fosse um tipo fundamental. Ele tem um tamanho conhecido na memória e certas regras sobre como pode ser usado aplicado para verificar o tempo de compilação e, no runtime, para a vida útil de seu programa. As principais diferenças entre os tipos internos fundamentais e os tipos definidos pelo usuário são:

- O compilador não tem conhecimento interno de um tipo definido pelo usuário. Ele aprende o tipo quando ele encontra a definição pela primeira vez durante o processo de compilação.

- Você especifica que operações podem ser executadas em seu tipo, e como ele pode ser convertido em outros tipos, definindo (por meio de sobrecarga) os operadores apropriados, como membros de classe ou funções de não membro. Para obter mais informações, consulte [sobrecarga de função](function-overloading.md)

## <a name="pointer-types"></a>Tipos de ponteiro

Desde as primeiras versões da linguagem C, o C++ continua permitindo que você declare uma variável de um tipo de ponteiro usando o declarador especial `*` (asterisco). Um tipo de ponteiro armazena o endereço do local na memória em que o valor real de dados é armazenado. No moderno C++, eles são chamados de *ponteiros brutos*e são acessados em seu código por meio de operadores especiais `*` (asterisco) ou `->` (Dash com maior que). Isso é chamado de cancelamento de *referência*e qual deles você usa depende se você está desreferenciando um ponteiro para um escalar ou um ponteiro para um membro em um objeto. O trabalho com tipos de ponteiro foi durante muito tempo um dos aspectos mais desafiadores e confusos do desenvolvimento de programas em C e C++. Esta seção descreve alguns fatos e práticas para ajudar a usar ponteiros brutos se você quiser, mas, no C++ moderno, ele não é mais necessário (ou recomendado) para usar ponteiros brutos para a propriedade do objeto, devido à evolução do [ponteiro inteligente](../cpp/smart-pointers-modern-cpp.md) (discutido mais no final desta seção). Ainda é útil e seguro usar ponteiros brutos para observar objetos, mas se você tiver de usá-los para a propriedade de objeto, faça isso com muito cuidado e considerando como os objetos possuídos por eles são criados e destruídos.

A primeira coisa que você deve saber é que a declaração de uma variável de ponteiro bruto alocará somente a memória necessária para armazenar um endereço do local da memória a que o ponteiro fará referência quando sua referência for removida. A alocação da memória do próprio valor de dados (também chamada de *armazenamento de backup*) ainda não está alocada. Ou seja, declarando uma variável de ponteiro bruto, você está criando uma variável do endereço de memória, não uma variável de dados real. Remover a referência de uma variável de ponteiro antes de verificar se ela contém um endereço válido para um repositório de backup causará um comportamento indefinido (geralmente um erro fatal) em seu programa. O exemplo a seguir demonstra esse tipo de erro:

```cpp
int* pNumber;       // Declare a pointer-to-int variable.
*pNumber = 10;      // error. Although this may compile, it is
                    // a serious error. We are dereferencing an
                    // uninitialized pointer variable with no
                    // allocated memory to point to.
```

O exemplo remove a referência de um tipo de ponteiro sem ter memória alocada para armazenar os dados inteiros reais ou um endereço de memória válido atribuído a ele. O código a seguir corrige esses erros:

```cpp
    int number = 10;          // Declare and initialize a local integer
                              // variable for data backing store.
    int* pNumber = &number;   // Declare and initialize a local integer
                              // pointer variable to a valid memory
                              // address to that backing store.
...
    *pNumber = 41;            // Dereference and store a new value in
                              // the memory pointed to by
                              // pNumber, the integer variable called
                              // "number". Note "number" was changed, not
                              // "pNumber".
```

O exemplo de código corrigido usa a memória de pilha local para criar o repositório de backup para o qual `pNumber` aponta. Usamos um tipo fundamental para simplificar. Na prática, o armazenamento de backup para ponteiros é, geralmente, tipos definidos pelo usuário que são alocados dinamicamente em uma área de memória chamada *heap* (ou *armazenamento gratuito*) usando uma **nova** expressão de palavra-chave (em programação em estilo C, o @no_ mais antigo a função de biblioteca de tempo de execução _t_3 C foi usada). Uma vez alocadas, essas variáveis são geralmente chamadas de objetos, especialmente se elas forem baseadas em uma definição de classe. A memória alocada com **New** deve ser excluída por uma instrução **delete** correspondente (ou, se você usou a função `malloc()` para alocá-la, a função de tempo de execução C `free()`).

No entanto, é fácil esquecer de excluir um objeto alocado dinamicamente, especialmente em um código complexo, que causa um bug de recurso chamado de *vazamento de memória*. Por esse motivo, o uso de ponteiros brutos é altamente desaconselhável em C++ moderno. É quase sempre melhor encapsular um ponteiro bruto em um [ponteiro inteligente](../cpp/smart-pointers-modern-cpp.md), que liberará automaticamente a memória quando o destruidor for invocado (quando o código sair do escopo do ponteiro inteligente); usando ponteiros inteligentes, você praticamente elimina uma classe inteira de bugs em C++ seus programas. No exemplo a seguir, suponha que `MyClass` seja um tipo definido pelo usuário que tem um método público `DoSomeWork();`

```cpp
void someFunction() {
    unique_ptr<MyClass> pMc(new MyClass);
    pMc->DoSomeWork();
}
  // No memory leak. Out-of-scope automatically calls the destructor
  // for the unique_ptr, freeing the resource.
```

Para obter mais informações sobre apontadores inteligentes, consulte [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md).

Para obter mais informações sobre conversões de ponteiro, consulte [conversões de tipo e segurança de tipo](../cpp/type-conversions-and-type-safety-modern-cpp.md).

Para obter mais informações sobre ponteiros em geral, consulte [ponteiros](../cpp/pointers-cpp.md).

## <a name="windows-data-types"></a>Tipos de dados do Windows

Na programação Win32 clássica para C e C++, a maioria das funções usa typedefs e macros #define específicas do Windows (definidas em `windef.h`) para especificar os tipos de parâmetros e valores de retorno. Esses tipos de dados do Windows são basicamente apenas nomes especiais (aliases) fornecidos para tiposC++ C/internos. Para obter uma lista completa desses TYPEDEFs e definições de pré-processador, consulte [tipos de dados do Windows](/windows/win32/WinProg/windows-data-types). Alguns desses typedefs, como HRESULT e LCID, são úteis e descritivos. Outros, como INT, não têm significado especial e são apenas aliases para tipos C++ fundamentais. Outros tipos de dados do Windows têm nomes que foram mantidos desde a época da programação em C e de processadores de 16 bits, e não têm finalidade ou significado em hardware ou sistemas operacionais modernos. Também há tipos de dados especiais associados à biblioteca de Windows Runtime, listados como [Windows Runtime tipos de dados base](/windows/win32/WinRT/base-data-types). Em C++ moderno, a orientação geral é dar preferência aos tipos C++ fundamentais, a menos que o tipo do Windows comunique qualquer significado adicional sobre como o valor deve ser interpretado.

## <a name="more-information"></a>Mais informações

Para obter mais informações sobre o sistema de tipos C++, consulte os tópicos a seguir.

|||
|-|-|
|[Tipos de valor](../cpp/value-types-modern-cpp.md)|Descreve *tipos de valor* juntamente com problemas relacionados ao seu uso.|
|[Conversões de tipo e segurança de tipo](../cpp/type-conversions-and-type-safety-modern-cpp.md)|Descreve problemas de conversão de tipos comuns e mostra como evitá-los.|

## <a name="see-also"></a>Consulte também

[Bem-vindo ao C++ (C++ moderno)](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
