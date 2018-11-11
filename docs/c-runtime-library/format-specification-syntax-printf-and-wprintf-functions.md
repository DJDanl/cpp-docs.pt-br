---
title: 'Sintaxe de especificação de formato: funções printf e and wprintf'
ms.date: 11/04/2016
helpviewer_keywords:
- format specification fields for printf function
- printf function format specification fields
- flag directives, printf function
- type fields, printf function
- width fields, printf function
- precision fields, printf function
ms.assetid: 664b1717-2760-4c61-bd9c-22eee618d825
ms.openlocfilehash: cb7d99077a082323a6662d29c0386cd1d416297c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50665329"
---
# <a name="format-specification-syntax-printf-and-wprintf-functions"></a>Sintaxe de especificação de formato: funções printf e wprintf

As várias funções `printf` e `wprintf` usam uma cadeia de caracteres de formato e argumentos opcionais e produzem uma sequência formatada de caracteres de saída. A cadeia de caracteres de formato contém zero ou mais *diretivas*, que são caracteres literais para saída, ou *especificações de conversão* codificadas, que descrevem como formatar um argumento na saída. Este tópico descreve a sintaxe usada para codificar as especificações de conversão na cadeia de caracteres de formato. Para obter uma lista dessas funções, veja [E/S de fluxo](../c-runtime-library/stream-i-o.md).

Uma especificação de conversão consiste em campos obrigatórios e opcionais neste formulário:

**%**[[*sinalizadores*](#flags)][[*largura*](#width)][.[*precisão*](#precision)][[*tamanho*](#size)][*tipo*](#type)

Cada campo da especificação de conversão é um caractere ou um número que representa um especificador de conversão ou opção de formato específico. O campo *tipo* obrigatório especifica o tipo de conversão a ser aplicado a um argumento. Os campos opcionais *sinalizadores*, *largura* e *precisão* controlam aspectos de formato adicionais, como zeros ou espaços à esquerda, justificativa e precisão exibida. O campo *tamanho* especifica o tamanho do argumento consumido e convertido.

A especificação de conversão básica contém apenas o sinal de porcentagem e um caractere de *tipo*. Por exemplo, `%s` especifica uma conversão de cadeia de caracteres. Para imprimir um caractere de sinal de porcentagem, use `%%`. Se um sinal de porcentagem é seguido por um caractere que não tem nenhum significado como um campo de formato, o manipulador de parâmetro inválido é invocado. Para saber mais, confira [Validação do parâmetro](../c-runtime-library/parameter-validation.md).

> [!IMPORTANT]
> Para segurança e estabilidade, verifique se essas cadeias de caracteres de especificação de conversão não são definidas pelo usuário. Por exemplo, considere um programa que solicita que o usuário insira um nome e armazena a entrada em uma variável de cadeia de caracteres chamado `user_name`. Para imprimir `user_name`, não faça isto:
>
> `printf( user_name ); /* Danger!  If user_name contains "%s", program will crash */`
>
> Em vez disso, faça o seguinte:
>
> `printf( "%s", user_name );`

<a name="type"></a>

## <a name="type-conversion-specifier"></a>Especificador de conversão de tipo

O caractere de especificador de conversão de *tipo* especifica se o argumento correspondente deve ser interpretado como um caractere, uma cadeia de caracteres, um ponteiro, um inteiro ou um número de ponto flutuante. O caractere de *tipo* é o único campo de especificação de formato necessário e aparece depois de quaisquer campos opcionais.

Os argumentos que seguem o formato cadeia de caracteres são interpretados de acordo com o caractere de *tipo* correspondente e o prefixo de [tamanho](#size) opcional. As conversões dos tipos de caracteres `char` e `wchar_t` são especificadas usando **c** ou **C**, e as cadeias de caracteres de byte único e vários bytes ou de caracteres largos são especificadas usando **s** ou **S**, dependendo de qual função de formatação está sendo usada. Argumentos de caractere e de cadeia de caracteres que são especificados usando **c** e **s** são interpretados como `char` e `char*` pelas funções da família `printf` ou como `wchar_t` e `wchar_t*` pelas funções da família `wprintf`. Argumentos de caractere e de cadeia de caracteres que são especificados usando **C** e **S** são interpretados como `wchar_t` e `wchar_t*` pelas funções da família `printf` ou como `char` e `char*` pelas funções da família `wprintf`. O comportamento é específico da Microsoft.

Tipos de inteiro como `short`, `int`, `long`, `long long` e suas variações `unsigned` são especificados usando **d**, **i**, **o**, **u**, **x** e **X**. Tipos de ponto flutuante como `float`, `double` e `long double` são especificados usando **a**, **A**, **e**, **E**, **f**, **F**, **g** e **G**. Por padrão, a menos que sejam modificados por um prefixo de *tamanho*, os argumentos inteiros são forçados para o tipo `int` e argumentos de ponto flutuante são forçados a `double`. Em sistemas de 64 bits, um `int` é um valor de 32 bits; portanto, inteiros de 64 bits serão truncados quando forem formatados para saída, a menos que um prefixo de *tamanho* de **ll** ou **I64** seja usado. Tipos de ponteiro que são especificados por **p** usam o tamanho de ponteiro padrão para a plataforma.

> [!NOTE]
> **Específico para a Microsoft** O caractere de tipo **Z** e o comportamento do **c**, **C**, **s** e os caracteres de tipo **S**, quando usados com as funções `printf` e `wprintf`, são extensões da Microsoft. O padrão ISO C usa **c** e **s** consistentemente para cadeias de caracteres e caracteres estreitos, e **C** e **S** para cadeias de caracteres e caracteres largos, em todas as funções de formatação.

### <a name="type-field-characters"></a>Caracteres de campo de tipo

|Caractere de tipo|Argumento|Formato de saída|
|--------------------|--------------|-------------------|
|**c**|Caractere|Quando usado com funções `printf`, especifica um caractere de byte único; quando usado com funções `wprintf`, especifica um caractere largo.|
|**C**|Caractere|Quando usado com funções `printf`, especifica um caractere largo; quando usado com funções `wprintf`, especifica um caractere de byte único.|
|**d**|Inteiro|Inteiro decimal assinado.|
|**i**|Inteiro|Inteiro decimal assinado.|
|**o**|Inteiro|inteiro octal não assinado.|
|**u**|Inteiro|Inteiro decimal sem sinal.|
|**x**|Inteiro|Inteiro hexadecimal não assinado; usa "abcdef".|
|**X**|Inteiro|Inteiro hexadecimal não assinado; usa "ABCDEF".|
|**e**|Ponto flutuante|O valor assinado que tem a forma [-]*d.dddd*__e±__*dd*[*d*], em que *d* é um dígito decimal, *dddd* é um ou mais dígitos decimais dependendo da precisão especificada ou seis, por padrão e *dd*[*d*] é dois ou três dígitos decimais dependendo do [formato de saída](../c-runtime-library/set-output-format.md) e do tamanho do expoente.|
|**E**|Ponto flutuante|Idêntico ao formato **e**, exceto pelo fato de que **E** em vez de **e** apresenta o expoente.|
|**f**|Ponto flutuante|Valor assinado que tem a forma [-]*dddd*__.__*dddd*, em que *dddd* é um ou mais dígitos decimais. O número de dígitos antes do ponto decimal depende da magnitude do número e o número de dígitos após o ponto decimal depende da precisão solicitada ou é seis, por padrão.|
|**F**|Ponto flutuante|Idêntico ao formato **f**, exceto pelo fato de que a saída de infinito e de nan está em maiúsculas.|
|**g**|Ponto flutuante|Valores assinados são exibidos no formato **f** ou **e**, dependendo do que é mais compacto para o valor e a precisão especificados. O formato **e** será usado somente quando o expoente do valor for menor do que -4 ou maior ou igual ao argumento de *precisão*. Zeros à esquerda são truncados, e o ponto decimal é exibido somente se um ou mais dígitos vierem na sequência.|
|**G**|Ponto flutuante|Idêntico ao formato **g**, com a exceção de que **E** em vez de **e** apresenta o expoente (quando apropriado).|
|**a**|Ponto flutuante|Valor hexadecimal de ponto flutuante de precisão dupla e assinado que tem o formato [-]0x*h.hhhh*__p±__*dd*, no qual *h.hhhh* são os dígitos hexadecimais (usando letras minúsculas) da mantissa e *dd* são um ou mais dígitos para o expoente. A precisão especifica o número de dígitos após a vírgula.|
|**A**|Ponto flutuante|Valor hexadecimal de ponto flutuante de precisão dupla e assinado que tem o formato [-]0X*h.hhhh*__P±__*dd*, em que *h.hhhh* são os dígitos hexadecimais (usando letras maiúsculas) da mantissa e *dd* são um ou mais dígitos para o expoente. A precisão especifica o número de dígitos após a vírgula.|
|**n**|Ponteiro para o inteiro|Número de caracteres gravados com êxito até o momento no fluxo ou no buffer. Esse valor é armazenado no inteiro cujo endereço é fornecido como o argumento. O tamanho do número inteiro apontado pode ser controlado por um prefixo de especificação de tamanho de argumento. O especificador **n** é desabilitado por padrão; para obter mais informações, consulte a observação de segurança importante.|
|**p**|Tipo ponteiro|Exibe o argumento como um endereço usando dígitos hexadecimais.|
|**s**|Cadeia de Caracteres|Quando usado com funções `printf`, especifica uma cadeia de caracteres de byte único ou uma cadeia de caracteres de bytes múltiplos; quando usado com funções `wprintf`, especifica uma cadeia de caracteres largos. Os caracteres são exibidos até o primeiro caractere nulo ou até que o valor de *precisão* seja atingido.|
|**S**|Cadeia de Caracteres|Quando usado com funções `printf`, especifica uma cadeia de caracteres largos; quando usado com funções `wprintf`, especifica uma cadeia de caracteres de byte único ou uma cadeia de caracteres de bytes múltiplos. Os caracteres são exibidos até o primeiro caractere nulo ou até que o valor de *precisão* seja atingido.|
|**Z**|Estrutura `ANSI_STRING` ou `UNICODE_STRING`|Quando o endereço de uma estrutura [ANSI_STRING](/windows/desktop/api/ntdef/ns-ntdef-_string) ou [UNICODE_STRING](https://msdn.microsoft.com/library/windows/hardware/ff564879.aspx) é passado como o argumento, exibe a cadeia de caracteres contida no buffer apontado pelo campo `Buffer` da estrutura. Use um prefixo modificador de *tamanho* de **w** para especificar um argumento `UNICODE_STRING` – por exemplo, `%wZ`. O campo `Length` da estrutura deve ser definido como a duração, em bytes, da cadeia de caracteres. O campo `MaximumLength` da estrutura deve ser definido como a duração, em bytes, do buffer.<br /><br /> Normalmente, o caractere de tipo **Z** é usado somente em funções de depuração de driver que usam uma especificação de conversão, como `dbgPrint` e `kdPrint`.|

A partir do Visual Studio 2015, se o argumento que corresponde a um especificador de conversão de ponto flutuante (**a**, **A**, **e**, **E**, **f**, **F**, **g**, **G**) for infinito, indefinido ou NaN, a saída formatada estará em conformidade com o padrão C99. Esta tabela lista a saída formatada:

|Valor|Saída|
|-----------|------------|
|infinity|`inf`|
|NaN silencioso|`nan`|
|Sinalização NaN|`nan(snan)`|
|NaN indefinido|`nan(ind)`|

Qualquer um desses valores pode ser ter um sinal como prefixo. Se um caractere especificador de conversão de *tipo* de ponto flutuante for uma letra maiúscula, a saída também será formatada em letras maiúsculas. Por exemplo, se o especificador de formato for `%F` em vez de `%f`, um infinito será formatado como `INF` em vez de `inf`. As funções `scanf` também podem analisar essas cadeias de caracteres, para que esses valores possam fazer uma viagem de ida e volta nas funções `printf` e `scanf`.

Antes do Visual Studio 2015, o CRT usava um formato diferente não padrão para saída de valores infinitos, indefinidos e NaN:

|Valor|Saída|
|-----------|------------|
|+ infinity|`1.#INF` *random-digits*|
|- infinity|`-1.#INF` *random-digits*|
|Indefinite (mesmo que NaN silencioso)|*dígito* `.#IND` *random-digits*|
|NaN|*dígito* `.#NAN` *random-digits*|

Qualquer um desses poderia ter um sinal como prefixo e poderia ser formatado de forma ligeiramente diferente, dependendo da largura do campo e da precisão, às vezes com efeitos incomuns. Por exemplo, `printf("%.2f\n", INFINITY)` imprimiria `1.#J` porque o #INF poderia ser "arredondado" para uma precisão de 2 dígitos.

> [!NOTE]
> Se o argumento que corresponde a `%s` ou `%S` ou o campo `Buffer` do argumento que corresponde a `%Z` for um ponteiro nulo, "(null)" será exibido.

> [!NOTE]
> Em todos os formatos exponenciais, o número mínimo de dígitos do expoente para exibição é dois, usando três somente se necessário. Usando a função [set_output_format](../c-runtime-library/set-output-format.md), você pode definir o número de dígitos exibidos para três para compatibilidade com versões anteriores, com o código escrito para o Visual Studio 2013 e versões anteriores.

> [!IMPORTANT]
> Pela insegurança inerente do formato `%n`, ela fica desabilitada por padrão. Se `%n` for encontrado em um formato de cadeia de caracteres, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../c-runtime-library/parameter-validation.md). Para habilitar o suporte a `%n`, confira [set_printf_count_output](../c-runtime-library/reference/set-printf-count-output.md).

<a name="flags"></a>

## <a name="flag-directives"></a>Diretivas de sinalizador

O primeiro campo opcional em uma especificação de conversão contém *diretivas de sinalizador*, zero ou mais caracteres de sinalizador que especificam a saída de justificação e controlam a saída de sinais, espaços em branco, zeros à esquerda, pontos decimais e prefixos octais e hexadecimais. Mais de uma diretiva de sinalizador pode aparecer em uma especificação de conversão e os caracteres de sinalizadores podem aparecer em qualquer ordem.

### <a name="flag-characters"></a>Caracteres de sinalizador

|Sinalizador|Significado|Padrão|
|----------|-------------|-------------|
|**-**|Alinhar à esquerda o resultado dentro da largura de campo determinada.|Alinhar à direita.|
|**+**|Use um sinal (+ ou -) como prefixo no valor de saída se for de um tipo com sinal.|O sinal será exibido somente para valores assinados negativos (-).|
|**0**|Se a *largura* tiver **0** como prefixo, zeros à esquerda serão adicionados até que a largura mínima seja atingida. Se **0** e **-** aparecerem, o **0** será ignorado. Se **0** for especificado como um formato inteiro (**i**, **u**, **x**, **X**, **o**, **d**) e uma especificação de precisão também estiver presente (por exemplo, `%04.d`), o **0** será ignorado. Se **0** for especificado para o formato de ponto flutuante **a** ou **A**, zeros à esquerda serão pré-anexados à mantissa, após o prefixo `0x` ou `0X`.|Nenhum preenchimento.|
|**blank** (' ')|Use um espaço em branco como prefixo do valor de saída se tiver um sinal e for positivo. O espaço em branco será ignorado se o espaço em branco e os sinalizadores + forem exibidos.|Nenhum espaço em branco é exibido.|
|**#**|Quando ele for usado com o formato **o**, **x** ou **X**, o sinalizador **#** usará 0, 0x ou 0X, respectivamente, para o prefixo de qualquer valor de saída diferente de zero.|Nenhum espaço em branco é exibido.|
||Quando ele for usado com o formato **e**, **E**, **f**, **F**, **a** ou **A**, o sinalizador **#** obrigará o valor de saída a conter um ponto decimal.|O ponto decimal será exibido somente se os dígitos o seguirem.|
||Quando ele for usado com o formato **g** ou **G**, o sinalizador **#** obrigará o valor de saída a conter um ponto decimal e evitará o truncamento de zeros à direita.<br /><br /> Ignorado quando usado com **c**, **d**, **i**, **u** ou **s**.|O ponto decimal será exibido somente se os dígitos o seguirem. Zeros à direita são truncados.|

<a name="width"></a>

## <a name="width-specification"></a>Especificação de largura

Em uma especificação de conversão, o campo de especificação de largura opcional aparece após quaisquer caracteres *sinalizadores*. O argumento de *largura* é um inteiro decimal não negativo que controla o número mínimo de caracteres de saída. Se o número de caracteres no valor de saída for menor que a largura especificada, espaços em branco serão adicionados à esquerda ou à direita dos valores – dependendo se o sinalizador de alinhamento à esquerda (**-**) for especificado – até que a largura mínima seja atingida. Se a *largura* tiver 0 como prefixo, zeros à esquerda serão adicionados ao inteiro ou a conversões de ponto flutuante até que a largura mínima seja atingida, exceto quando a conversão for a um infinito ou NaN.

A especificação de largura nunca faz com que um valor seja truncado. Se o número de caracteres no valor de saída for maior que a largura especificada ou se a *largura* não for fornecida, todos os caracteres do valor serão de saída, sujeitos à especificação de *precisão*.

Se a especificação de precisão for um asterisco (`*`), um argumento `int` da lista de argumentos fornecerá o valor. Na lista de argumentos, o argumento *largura* deve preceder o valor que está sendo formatado, conforme mostrado neste exemplo:

`printf("%0*f", 5, 3);  /* 00003 is output */`

Um valor de *largura* ausente ou pequeno em uma especificação de formato não causa o truncamento de um valor de saída. Se o resultado de uma conversão for maior do que o valor de *largura*, o campo se expandirá para conter o resultado da conversão.

<a name="precision"></a>

## <a name="precision-specification"></a>Especificação da precisão

Em uma especificação de conversão de formato, o terceiro campo opcional é a especificação de precisão. Ele consiste em um ponto (.) seguido de um inteiro de decimal não negativo que, dependendo do tipo de conversão, especifica o número de caracteres da cadeia de caracteres, o número de casas decimais ou o número de dígitos significativos para a saída.

Ao contrário da especificação de largura, a especificação de precisão pode causar o truncamento do valor de saída ou arredondamento de um valor de ponto flutuante. Se *precisão* for especificado como 0 e o valor a ser convertido for 0, o resultado não será uma saída de caracteres, conforme mostrado neste exemplo:

`printf( "%.0d", 0 );      /* No characters output */`

Se a especificação de precisão for um asterisco (\*), um argumento `int` da lista de argumentos fornecerá o valor. Na lista de argumentos, o argumento de *precisão* deve preceder o valor que está sendo formatado, conforme mostrado neste exemplo:

`printf( "%.*f", 3, 3.14159265 );  /* 3.142 output */`

O caractere de *tipo* determina a interpretação de *precisão* ou a precisão padrão quando *precisão* é omitida, conforme mostrado na tabela a seguir.

### <a name="how-precision-values-affect-type"></a>Como os valores de precisão afetam o tipo

|Tipo|Significado|Padrão|
|----------|-------------|-------------|
|**a**, **A**|A precisão especifica o número de dígitos após a vírgula.|A precisão padrão é 13. Se a precisão for 0, nenhum ponto decimal será impresso, a menos que o sinalizador **#** seja usado.|
|**c**, **C**|A precisão não tem nenhum efeito.|O caractere foi impresso.|
|**d**, **i**, **o**, **u**, **x**, **X**|A precisão especifica o número mínimo de dígitos a ser impresso. Se o número de dígitos no argumento for menor que *precisão*, o valor de saída será preenchido com zeros à esquerda. O valor não será truncado quando o número de dígitos exceder *precisão*.|A precisão padrão é 1.|
|**e**, **E**|A precisão especifica o número de dígitos a serem impressos após a vírgula decimal. O último dígito impresso será arredondado.|A precisão padrão é 6. Se *precisão* for 0 ou o ponto (.) aparecer sem um número a seguir, nenhum ponto decimal será impresso.|
|**f**, **F**|O valor de precisão especifica o número de dígitos após a vírgula decimal. Se uma vírgula decimal aparecer, pelo menos um dígito aparecerá antes dela. O valor é arredondado para o número apropriado de dígitos.|A precisão padrão é 6. Se *precisão* for 0 ou se o ponto (.) aparecer sem um número a seguir, nenhum ponto decimal será impresso.|
|**g**, **G**|A precisão especifica o número máximo de dígitos significativos impressos.|Seis dígitos significativos são impressos e os zeros à direita são truncados.|
|**s**, **S**|A precisão especifica o número máximo de caracteres a serem impressos. Os caracteres em excesso de *precisão* não são impressos.|Os caracteres são impressos até que seja encontrado um caractere nulo.|

<a name="size"></a>

## <a name="argument-size-specification"></a>Especificação de tamanho de argumento

Em uma especificação de conversão, o campo *tamanho* é um modificador de comprimento do argumento para o especificador de conversão de *tipo*. O campo *tamanho* é prefixado para o campo *tipo* – **hh**, **h**, **j**, **l** (L minúsculo), **L**, **ll**, **t**, **w**, **z**, **I** (i maiúsculo), **I32** e **I64** – especifique o "tamanho" do argumento correspondente – longo ou curto, 32 bits ou 64 bits, caracteres de byte único ou de caractere largo – dependendo do especificador de conversão que eles modificam. Esses prefixos de tamanho são usados com caracteres de *tipo* nas famílias de funções `printf` e `wprintf` para especificar a interpretação dos tamanhos de argumento, como mostrado na tabela a seguir. O campo *tamanho* é opcional para alguns tipos de argumentos. Quando nenhum prefixo de tamanho for especificado, o formatador consumirá argumentos inteiros – por exemplo, `char`, `short`, `int`, `long` com sinal ou sem sinal e tipos de enumeração – como tipos `int` de 32 bits, e argumentos de ponto flutuante `float`, `double` e `long double` serão consumidos como tipos `double` de 64 bits. Isso coincide com as regras de promoção de argumento padrão para listas de argumentos variáveis. Para saber mais sobre a promoção de argumento, veja reticências e argumentos padrão em [expressões de sufixo](../cpp/postfix-expressions.md). Em sistemas de 32 bits e 64 bits, a especificação de conversão de um argumento de inteiro de 64 bits deve incluir um prefixo de tamanho de **ll** ou **I64**. Caso contrário, o comportamento do formatador será indefinido.

Alguns tipos têm tamanhos diferentes no código de 32 bits e 64 bits. Por exemplo, `size_t` é de 32 bits longa no código compilado para x86 e 64 bits no código compilado para x64. Para criar o código de formatação independente de plataforma para tipos de largura variável, você pode usar um modificador de tamanho do argumento de largura variável. Como alternativa, use um modificador de tamanho do argumento de 64 bits e promova explicitamente o tipo de argumento de largura variável 64 bits. O modificador de tamanho de argumento específicos da Microsoft **I** (i maiúsculo) lida com argumentos inteiros de largura variável, mas é recomendável os modificadores **j**, **t** e **z** específicos de tipo para portabilidade.

### <a name="size-prefixes-for-printf-and-wprintf-format-type-specifiers"></a>Prefixos de Tamanho para Especificadores de Tipo de Tamanho printf e wpprintf

|Para especificar|Use o prefixo|Com especificador de tipo|
|----------------|----------------|-------------------------|
|`char`<br />`unsigned char`|**hh**|**d**, **i**, **o**, **u**, **x** ou **X**|
|`short int`<br />`short unsigned int`|**h**|**d**, **i**, **o**, **u**, **x** ou **X**|
|`__int32`<br />`unsigned __int32`|**I32**|**d**, **i**, **o**, **u**, **x** ou **X**|
|`__int64`<br />`unsigned __int64`|**I64**|**d**, **i**, **o**, **u**, **x** ou **X**|
|`intmax_t`<br />`uintmax_t`|**j** ou **I64**|**d**, **i**, **o**, **u**, **x** ou **X**|
|`long double`|**l** (L minúsculo) ou **L**|**a**, **A**, **e**, **E**, **f**, **F**, **g** ou **G**|
|`long int`<br />`long unsigned int`|**l** (L minúsculo)|**d**, **i**, **o**, **u**, **x** ou **X**|
|`long long int`<br />`unsigned long long int`|**ll** (LL minúsculo)|**d**, **i**, **o**, **u**, **x** ou **X**|
|`ptrdiff_t`|**t** ou **I** (i maiúsculo)|**d**, **i**, **o**, **u**, **x** ou **X**|
|`size_t`|**z** ou **I** (i maiúsculo)|**d**, **i**, **o**, **u**, **x** ou **X**|
|Caractere de byte único|**h**|**c** ou **C**|
|Caractere largo|**l** (L minúsculo) ou **w**|**c** ou **C**|
|Cadeia de caracteres de byte único|**h**|**s**, **S** ou **Z**|
|Cadeia de caracteres largos|**l** (L minúsculo) ou **w**|**s**, **S** ou **Z**|

Os tipos `ptrdiff_t` e `size_t` são `__int32` ou `unsigned __int32` em plataformas de 32 bits e `__int64` ou `unsigned __int64` em plataformas de 64 bits. Os prefixos de tamanho **I** (i maiúsculo), **j**, **t** e **z** levam a largura de argumento corretos para a plataforma.

No Visual C++, embora `long double` seja um tipo diferente, ele tem a mesma representação interna que `double`.

Um especificador de tipo **hc** ou **hC** é sinônimo de **c** em funções `printf` e de **C** em funções `wprintf`. Um especificador de tipo **lc**, **lC**, **wc** ou **wC** é sinônimo de **C** em funções `printf` e de **c** em funções `wprintf`. Um especificador de tipo **hs** ou **hS** é sinônimo de **s** em funções `printf` e de **S** em funções `wprintf`. Um especificador de tipo **ls**, **lS**, **ws** ou **wS** é sinônimo de **S** em funções `printf` e de **s** em funções `wprintf`.

> [!NOTE]
> **Específico para a Microsoft** Os prefixos modificadores de tamanho de argumento **I** (i maiúsculo), **I32**, **I64** e **w** são extensões da Microsoft e não são compatíveis com ISO C. O prefixo **h** quando é usado com o tipo de dados `char` e o prefixo **l** (L minúsculo) quando usado com o tipo de dados `double` são extensões da Microsoft.

## <a name="see-also"></a>Consulte também

[printf, _printf_l, wprintf, _wprintf_l](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)<br/>
[printf_s, _printf_s_l, wprintf_s, _wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)<br/>
[Parâmetros posicionais printf_p](../c-runtime-library/printf-p-positional-parameters.md)