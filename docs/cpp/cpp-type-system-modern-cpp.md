---
title: Sistema de tipo C++ (C++ moderno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: article
dev_langs:
- C++
ms.assetid: 553c0ed6-77c4-43e9-87b1-c903eec53e80
caps.latest.revision: 24
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7abede5a7370461b0e77bd51ea12f7ab9b184e5c
ms.sourcegitcommit: cff1a8a49f0cd50f315a250c5dd27e15c173845f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/06/2018
---
# <a name="c-type-system-modern-c"></a>Sistema do tipo C++ (C++ moderno)
O conceito de *tipo* é muito importante em C++. Cada variável, argumento de função e valor de retorno de função deve ter um tipo para ser compilado. Além disso, cada expressão (incluindo valores literais) recebe implicitamente um tipo do compilador antes de ser avaliada. Alguns exemplos de tipos de `int` para armazenar valores inteiros, `double` para armazenar valores de ponto flutuante (também conhecido como *escalar* tipos de dados), ou a classe de biblioteca padrão [std::basic_string](../standard-library/basic-string-class.md) para armazenar texto. É possível criar seu próprio tipo definindo uma `class` ou `struct`. O tipo especifica a quantidade de memória que será atribuída à variável (ou o resultado da expressão), os tipos de valores que podem ser armazenados nessa variável, como os valores (como padrão de bits) são interpretados e as operações que podem ser executadas nele. Este artigo contém uma visão geral informal dos principais recursos do sistema de tipos C++.  
  
## <a name="terminology"></a>Terminologia  
 **Variável**: O simbólico nome de uma quantidade de dados para que o nome pode ser usado para acessar os dados que se refere a em todo o escopo do código onde ele está definido. No C++, *variável* geralmente é usado para se referir às instâncias dos tipos de dados escalares, ao passo que são geralmente chamadas de instâncias de outros tipos de *objetos*.  
  
 **Objeto**: para manter a simplicidade e a consistência, este artigo usa o termo *objeto* para se referir a qualquer instância de uma classe ou estrutura, e quando ele é usado no sentido geral inclui todos os tipos, até mesmo variáveis escalares.  
  
 **Tipo POD** (dados antigos simples): esta categoria informal dos tipos de dados em C++ refere-se aos tipos escalares (consulte a seção de tipos fundamentais) ou *classes POD*. Uma classe POD não tem membros de dados estáticos que também não sejam PODs e não tem construtores definidos pelo usuário, destruidores definidos pelo usuário ou operadores de atribuição definidos pelo usuário. Além disso, uma classe POD não tem função virtual, nenhuma classe base e nenhum membro de dados não estático particular ou protegido. Os tipos POD são quase sempre usados para a troca de dados externos, por exemplo, com um módulo escrito na linguagem C (que tem apenas tipos POD).  
  
## <a name="specifying-variable-and-function-types"></a>Especificando tipos de variável e de função  
 C++ é um *fortemente tipado* idiomas e é também *digitado estaticamente*; cada objeto tem um tipo e que tipo nunca é alterado (não deve ser confundido com objetos de dados estáticos).   
**Quando você declara uma variável** em seu código, você deve especificar o tipo explicitamente, ou usar o `auto` palavra-chave para instruir o compilador para deduzir o tipo do inicializador.   
**Quando você declara uma função** em seu código, você deve especificar o tipo de cada argumento e seu valor de retorno, ou `void` se nenhum valor é retornado pela função. A exceção se dá quando você está usando modelos de função, que permitem argumentos de tipos arbitrários.  
  
 Após a primeira declaração de uma variável, você não pode alterar seu tipo em um momento posterior. No entanto, você pode copiar o valor da variável ou o valor de retorno de uma função para outra variável de tipo diferente. Essas operações são chamadas *conversões de tipo*, que, às vezes, são necessário, mas também são fontes potenciais de perda de dados ou incorrectness.  
  
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
 Ao contrário de algumas linguagens, C++ não tem tipo base universal do qual todos os outros tipos são derivados. A implementação do Visual C++ do idioma inclui muitas *tipos fundamentais*, também conhecido como *tipos internos*. Isso inclui tipos numéricos como `int`, `double`, `long`, `bool`, além dos tipos `char` e `wchar_t` para caracteres ASCII e UNICODE, respectivamente. A maioria dos tipos fundamentais (exceto `bool`, `double`, `wchar_t` e tipos relacionados) tem todas as versões sem sinal, que modificam o intervalo de valores que a variável pode armazenar. Por exemplo, um `int`, que armazena um inteiro de 32 bits com sinal, pode representar um valor de -2.147.483.648 a 2.147.483.647. Um `unsigned int`, que também é armazenado como 32 bits, pode armazenar um valor de 0 a 4.294.967.295. O número total de valores possíveis em cada caso é o mesmo; somente o intervalo é diferente.  
  
 Os tipos fundamentais são reconhecidos pelo compilador, que tem regras internas que controlam que operações você poderá executar neles e como eles serão convertidos em outros tipos fundamentais. Para obter uma lista completa de tipos internos e seu tamanho e os limites numéricos, consulte [tipos fundamentais](../cpp/fundamental-types-cpp.md).  
  
 A ilustração a seguir mostra os tamanhos relativos dos tipos internos:  
  
 ![Tamanho em bytes do criados&#45;em tipos](../cpp/media/built-intypesizes.png "inTYpeSizes internos")  
  
 A tabela a seguir lista os tipos fundamentais usados com mais frequência:  
  
|Tipo|Tamanho|Comentário|  
|----------|----------|-------------|  
|int|4 bytes|A opção padrão para valores integrais.|  
|double|8 bytes|A opção padrão para valores de ponto flutuante.|  
|bool|1 byte|Representa valores que podem ser true ou false.|  
|char|1 byte|Use os caracteres ASCII em cadeias de caracteres do estilo C mais antigo ou objetos std::string que nunca precisarão ser convertidos em UNICODE.|  
|wchar_t|2 bytes|Representa os valores de caractere "largos" que podem ser codificados no formato UNICODE (UTF-16 no Windows, outros sistemas operacionais podem ser diferentes). Esse é o tipo de caractere usado em cadeias de caracteres do tipo `std::wstring`.|  
|unsigned char|1 byte|O C++ não tem o tipo `byte` interno.  Use unsigned char para representar um valor de bytes.|  
|unsigned int|4 bytes|Escolha padrão para sinalizadores de bit.|  
|long long|8 bytes|Representa valores inteiros muito grandes.|  
  
## <a name="the-void-type"></a>O tipo void  
 O tipo `void` é especial; você não pode declarar uma variável do tipo `void`, mas pode declarar uma variável do tipo `void *` (ponteiro para `void`), que às vezes é necessário ao alocar memória bruta (não tipada). No entanto, os ponteiros para `void` não são seguros para o tipo e, geralmente, seu uso é altamente desaconselhável em C++ moderno. Em uma declaração de função, um valor de retorno `void` significa que a função não retorna um valor; esse é um uso comum e aceitável de `void`. Enquanto a linguagem C exigia funções com parâmetros de valor zero para declarar `void` na lista de parâmetros, por exemplo, `fou(void)`, essa prática foi desencorajada no C++ moderno e deve ser declarada `fou()`. Para obter mais informações, consulte [conversões e segurança de tipo](../cpp/type-conversions-and-type-safety-modern-cpp.md).  
  
## <a name="const-type-qualifier"></a>Qualificador do tipo const  
 Qualquer tipo interno ou definido pelo usuário pode ser qualificado pela palavra-chave const. Além disso, as funções de membro podem ser qualificadas por `const` e, até mesmo, sobrecarregadas por `const`. O valor de tipo `const` não pode ser modificado depois de inicializado.  
  
```cpp  
  
const double PI = 3.1415;  
PI = .75 //Error. Cannot modify const variable.  
  
```  
  
 O qualificador `const` é amplamente usado em declarações de função e de variável e a "exatidão de const" é um conceito importante em C++; essencialmente, significa usar `const` para garantir, no momento da compilação, que os valores não sejam inadvertidamente alterados. Para obter mais informações, consulte [const](../cpp/const-cpp.md).  
  
 Um tipo `const` é diferente da sua versão não const; por exemplo, `const int` é um tipo diferente de `int`. Você pode usar o C++ `const_cast` operador nesses raras ocasiões em que você deve remover *qualidade de const* de uma variável. Para obter mais informações, consulte [conversões e segurança de tipo](../cpp/type-conversions-and-type-safety-modern-cpp.md).  
  
## <a name="string-types"></a>Tipos de cadeia de caracteres  
 Estritamente falando, a linguagem C++ não tem nenhum tipo de cadeia de caracteres; `char` e `wchar_t` armazenar caracteres único - você deve declarar uma matriz desses tipos para aproximar uma cadeia de caracteres, adicionando um valor nulo de terminação (por exemplo, ASCII `'\0'`) a um elemento da matriz após o último caractere válido (também chamado de um *Cadeia de caracteres de estilo C*). As cadeias de caracteres de estilo C exigiam que muito mais códigos fossem escritos ou o uso de funções da biblioteca de utilitários de cadeia de caracteres externos. Mas em C++ moderno, temos os tipos de Biblioteca Padrão `std::string` (para cadeias de caracteres do tipo `char` de 8 bits) ou `std::wstring` (para cadeias de caracteres do tipo `wchar_t` de 16 bits). Esses contêineres de biblioteca padrão C++ podem ser considerados como tipos de cadeia de caracteres nativa porque elas fazem parte das bibliotecas padrão que estão incluídos em qualquer ambiente de compilação C++ compatível com. Basta usar a diretiva `#include <string>` para tornar esses tipos disponíveis em seu programa. (Se você estiver usando o MFC ou o ATL, a classe CString também estará disponível, mas não fará parte do padrão C++.) O uso de matrizes de caracteres de terminação nula (as cadeias de caracteres de estilo C mencionadas anteriormente) não é nada aconselhável em C++ moderno.  
  
## <a name="user-defined-types"></a>Tipos definidos pelo usuário  
 Ao definir `class`, `struct`, `union` ou `enum`, essa construção é usada no restante do código como se fosse um tipo fundamental. Ele tem um tamanho conhecido na memória e certas regras sobre como pode ser usado aplicado para verificar o tempo de compilação e, no tempo de execução, para a vida útil de seu programa. As principais diferenças entre os tipos internos fundamentais e os tipos definidos pelo usuário são:  
  
-   O compilador não tem conhecimento interno de um tipo definido pelo usuário. Aprende do tipo quando ele encontra primeiro a definição durante o processo de compilação.  
  
-   Você especifica que operações podem ser executadas em seu tipo, e como ele pode ser convertido em outros tipos, definindo (por meio de sobrecarga) os operadores apropriados, como membros de classe ou funções de não membro. Para obter mais informações, consulte [sobrecarga de função](function-overloading.md).  
  
-   Não precisam ser estaticamente tipados (a regra é que o tipo de um objeto nunca muda). Por meio de mecanismos de *herança* e *polimorfismo*, uma variável declarada como um tipo definido pelo usuário da classe (conhecido como uma instância de uma classe de objeto) pode ter um tipo diferente em tempo de execução que no tempo de compilação. Para obter mais informações, consulte [Herança](../cpp/inheritance-cpp.md).  
  
## <a name="pointer-types"></a>Tipos de ponteiro  
 Desde as primeiras versões da linguagem C, o C++ continua permitindo que você declare uma variável de um tipo de ponteiro usando o declarador especial `*` (asterisco). Um tipo de ponteiro armazena o endereço do local na memória em que o valor real de dados é armazenado. Em C++ moderna, eles são denominados *ponteiros brutos*e são acessados em seu código por meio de operadores especiais `*` (asterisco) ou `->` (tracejado com maior-de). Isso é chamado de *desreferenciando*, e que aquele que você usa depende são de referência um ponteiro para um valor escalar ou um ponteiro para um membro em um objeto. O trabalho com tipos de ponteiro foi durante muito tempo um dos aspectos mais desafiadores e confusos do desenvolvimento de programas em C e C++. Esta seção descreve alguns fatos e práticas recomendadas para usar ponteiros brutos para, mas em C++ moderno, que não é mais necessário (ou recomendado) para usar ponteiros brutos para a propriedade de objeto, devido a evolução do [ponteiro inteligente](../cpp/smart-pointers-modern-cpp.md) ( abordado mais no final desta seção). Ainda é útil e seguro usar ponteiros brutos para observar objetos, mas se você tiver de usá-los para a propriedade de objeto, faça isso com muito cuidado e considerando como os objetos possuídos por eles são criados e destruídos.  
  
 A primeira coisa que você deve saber é que a declaração de uma variável de ponteiro bruto alocará somente a memória necessária para armazenar um endereço do local da memória a que o ponteiro fará referência quando sua referência for removida. Alocação de memória para o valor de dados (também chamado de *repositório de backup*) ainda não foi alocado. Ou seja, declarando uma variável de ponteiro bruto, você está criando uma variável do endereço de memória, não uma variável de dados real. Remover a referência de uma variável de ponteiro antes de verificar se ela contém um endereço válido para um repositório de backup causará um comportamento indefinido (geralmente um erro fatal) em seu programa. O exemplo a seguir demonstra esse tipo de erro:  
  
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
  
 O exemplo de código corrigido usa a memória de pilha local para criar o repositório de backup para o qual `pNumber` aponta. Usamos um tipo fundamental para simplificar. Na prática, o armazenamento de backup para ponteiros são a maioria dos tipos geralmente definidas pelo usuário que estão alocados dinamicamente em uma área da memória denominada o *heap* (ou *armazenamento livre*) usando um `new` palavra-chave expressão (na programação do estilo C, o antigo `malloc()` função de biblioteca de tempo de execução C foi usada). Uma vez alocada, essas variáveis são normalmente conhecidas como objetos, especialmente se eles se baseiam em uma definição de classe. A memória que é alocada com `new` deve ser excluída por uma função `delete` correspondente (ou, se você usou a função `malloc()` para atribuí-la, a função C `free()` de tempo de execução).  
  
 No entanto, é fácil se esqueça de excluir um alocada dinamicamente object-especialmente em códigos complexos, o que faz com que um bug de recursos chamado um *vazamento de memória*. Por esse motivo, o uso de ponteiros brutos é altamente desaconselhável em C++ moderno. Quase sempre é melhor encapsular um ponteiro bruto em um [ponteiro inteligente](../cpp/smart-pointers-modern-cpp.md), que automaticamente irá liberar a memória quando seu destruidor é invocado (quando o código sai do escopo para o ponteiro inteligente); usando ponteiros inteligentes você praticamente elimine uma classe inteira de bugs nos programas do C++. No exemplo a seguir, suponha que `MyClass` seja um tipo definido pelo usuário que tem um método público `DoSomeWork();`  
  
```cpp  
  
void someFunction() {  
    unique_ptr<MyClass> pMc(new MyClass);  
    pMc->DoSomeWork();  
}  
  // No memory leak. Out-of-scope automatically calls the destructor  
  // for the unique_ptr, freeing the resource.  
  
```  
  
 Para obter mais informações sobre como ponteiros inteligentes, consulte [ponteiros inteligentes](../cpp/smart-pointers-modern-cpp.md).  
  
 Para obter mais informações sobre conversões de ponteiro, consulte [conversões e segurança de tipo](../cpp/type-conversions-and-type-safety-modern-cpp.md).  
  
 Para obter mais informações sobre ponteiros em geral, consulte [ponteiros](../cpp/pointers-cpp.md).  
  
## <a name="windows-data-types"></a>Tipos de dados do Windows  
 Na programação Win32 clássica para C e C++, a maioria das funções usa typedefs e macros #define específicas do Windows (definidas em `windef.h`) para especificar os tipos de parâmetros e valores de retorno. Esses tipos de dados do Windows são basicamente apenas especiais nomes (alias) para tipos internos do C/C++. Para obter uma lista completa dessas definições de tipo e as definições de pré-processador, consulte [tipos de dados do Windows](http://msdn.microsoft.com/en-us/4553cafc-450e-4493-a4d4-cb6e2f274d46). Alguns desses typedefs, como HRESULT e LCID, são úteis e descritivos. Outros, como INT, não têm significado especial e são apenas aliases para tipos C++ fundamentais. Outros tipos de dados do Windows têm nomes que foram mantidos desde a época da programação em C e de processadores de 16 bits, e não têm finalidade ou significado em hardware ou sistemas operacionais modernos. Também existem tipos de dados especiais associados à biblioteca de tempo de execução do Windows, listado como [tipos de dados base de tempo de execução do Windows](http://msdn.microsoft.com/en-us/b5735851-ec07-48c1-92b4-ca9f768096f6). Em C++ moderno, a orientação geral é dar preferência aos tipos C++ fundamentais, a menos que o tipo do Windows comunique qualquer significado adicional sobre como o valor deve ser interpretado.  
  
## <a name="more-information"></a>Mais informações  
 Para obter mais informações sobre o sistema de tipos C++, consulte os tópicos a seguir.  
  
|||  
|-|-|  
|[Tipos de valor](../cpp/value-types-modern-cpp.md)|Descreve *os tipos de valor* junto com problemas relacionados ao seu uso.|  
|[Conversões de tipo e segurança de tipo](../cpp/type-conversions-and-type-safety-modern-cpp.md)|Descreve problemas de conversão de tipos comuns e mostra como evitá-los.|  
  
## <a name="see-also"></a>Consulte também  
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
