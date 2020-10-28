---
title: 'Sintaxe de especificação de formato: `printf` e `wprintf` funções'
description: Descreve a sintaxe do especificador de formato para o tempo de execução e as funções do Microsoft C `printf` `wprintf`
ms.date: 10/26/2020
helpviewer_keywords:
- format specification fields for printf function
- printf function format specification fields
- flag directives, printf function
- type fields, printf function
- width fields, printf function
- precision fields, printf function
ms.assetid: 664b1717-2760-4c61-bd9c-22eee618d825
ms.openlocfilehash: 18642f650949e346fd3421b4a123acb4e84ed659
ms.sourcegitcommit: 9c801a43ee0d4d84956b03fd387716c818705e0d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/28/2020
ms.locfileid: "92907526"
---
# <a name="format-specification-syntax-printf-and-wprintf-functions"></a>Sintaxe de especificação de formato: funções printf e wprintf

As várias funções `printf` e `wprintf` usam uma cadeia de caracteres de formato e argumentos opcionais e produzem uma sequência formatada de caracteres de saída. A cadeia de caracteres de formato contém zero ou mais *diretivas* , que são caracteres literais para saída, ou *especificações de conversão* codificadas, que descrevem como formatar um argumento na saída. Este artigo descreve a sintaxe usada para codificar as especificações de conversão na cadeia de caracteres de formato. Para obter uma lista dessas funções, veja [E/S de fluxo](../c-runtime-library/stream-i-o.md).

Uma especificação de conversão consiste em campos obrigatórios e opcionais neste formulário:

**%** [ [*sinalizadores*](#flags)] [ [*largura*](#width)] [. [*precisão*](#precision)] [ [*tamanho*](#size)] [*tipo*](#type) de

Cada campo da especificação de conversão é um caractere ou um número que representa um especificador de conversão ou opção de formato específico. O campo *tipo* obrigatório especifica o tipo de conversão a ser aplicado a um argumento. Os campos opcionais *sinalizadores* , *largura* e *precisão* controlam aspectos de formato adicionais, como zeros ou espaços à esquerda, justificativa e precisão exibida. O campo *tamanho* especifica o tamanho do argumento consumido e convertido.

A especificação de conversão básica contém apenas o sinal de porcentagem e um caractere de *tipo* . Por exemplo, `%s` especifica uma conversão de cadeia de caracteres. Para imprimir um caractere de sinal de porcentagem, use `%%`. Se um sinal de porcentagem é seguido por um caractere que não tem nenhum significado como um campo de formato, o manipulador de parâmetro inválido é invocado. Para saber mais, confira [Validação do parâmetro](../c-runtime-library/parameter-validation.md).

> [!IMPORTANT]
> Para segurança e estabilidade, verifique se essas cadeias de caracteres de especificação de conversão não são definidas pelo usuário. Por exemplo, considere um programa que solicita que o usuário insira um nome e armazena a entrada em uma variável de cadeia de caracteres chamado `user_name`. Para imprimir `user_name`, não faça isto:
>
> `printf( user_name ); /* Danger!  If user_name contains "%s", program will crash */`
>
> Em vez disso, faça o seguinte:
>
> `printf( "%s", user_name );`

<a name="type"></a>

> [!NOTE]
> No Visual Studio 2015 `printf` , a `scanf` família e as funções foram declaradas como **`inline`** e movidas para os `<stdio.h>` `<conio.h>` cabeçalhos e. Se você estiver migrando um código mais antigo, poderá ver *LNK2019* em conexão com essas funções. Para obter mais informações, consulte [Visual C++ histórico de alterações 2003-2015](../porting/visual-cpp-change-history-2003-2015.md#stdio_and_conio).

## <a name="type-conversion-specifier"></a>Especificador de conversão de tipo

O caractere de especificador de conversão de *tipo* especifica se o argumento correspondente deve ser interpretado como um caractere, uma cadeia de caracteres, um ponteiro, um inteiro ou um número de ponto flutuante. O caractere de *tipo* é o único campo de especificação de formato necessário e aparece depois de quaisquer campos opcionais.

Os argumentos que seguem o formato cadeia de caracteres são interpretados de acordo com o caractere de *tipo* correspondente e o prefixo de [tamanho](#size) opcional. Conversões para tipos de caracteres `char` e `wchar_t` são especificadas usando **`c`** o ou o **`C`** , e cadeias de caracteres de byte único e multi-byte ou largos são especificados usando **`s`** ou **`S`** , dependendo de qual função de formatação está sendo usada. Argumentos de caractere e de cadeia de caracteres que são especificados usando **`c`** e **`s`** são interpretados como `char` e `char*` por `printf` funções de família, ou como `wchar_t` e `wchar_t*` por `wprintf` funções de família. Argumentos de caractere e de cadeia de caracteres que são especificados usando **`C`** e **`S`** são interpretados como `wchar_t` e `wchar_t*` por `printf` funções de família, ou como `char` e `char*` por `wprintf` funções de família. Esse comportamento é específico da Microsoft.

Tipos inteiros, como `short` ,,, `int` `long` `long long` e suas `unsigned` variantes, são especificados usando,,,, **`d`** **`i`** **`o`** **`u`** **`x`** e **`X`** . Tipos de ponto flutuante, como `float` , `double` e **`long double`** , são especificados usando **`a`** , **`A`** ,,,,, **`e`** **`E`** **`f`** **`F`** **`g`** e **`G`** . Por padrão, a menos que eles sejam modificados por um prefixo de *tamanho* , os argumentos inteiros são impostos no `int` tipo e argumentos de ponto flutuante são forçados `double` . Em sistemas de 64 bits, um `int` é um valor de 32 bits; portanto, os inteiros de 64 bits serão truncados quando estiverem formatados para saída, a menos que um prefixo de *tamanho* de **ll** ou **i64** seja usado. Tipos de ponteiros que são especificados pelo **`p`** usam o tamanho de ponteiro padrão para a plataforma.

> [!NOTE]
> **Específico da Microsoft:**\
> O **`Z`** caractere de tipo e o comportamento dos **`c`** caracteres, **`C`** , e de **`s`**  **`S`** tipo quando são usados com as `printf` `wprintf` funções e são extensões da Microsoft. O padrão ISO C usa **`c`** e **`s`** consistentemente para caracteres estreitos e cadeias e, **`C`** **`S`** para caracteres largos e cadeias, em todas as funções de formatação.

### <a name="type-field-characters"></a>Caracteres de campo de tipo

|Caractere de tipo|Argumento|Formato da saída|
|--------------------|--------------|-------------------|
|**`c`**|Caractere|Quando usado com funções `printf`, especifica um caractere de byte único; quando usado com funções `wprintf`, especifica um caractere largo.|
|**`C`**|Caractere|Quando usado com funções `printf`, especifica um caractere largo; quando usado com funções `wprintf`, especifica um caractere de byte único.|
|**`d`**|Integer|Inteiro decimal assinado.|
|**`i`**|Integer|Inteiro decimal assinado.|
|**`o`**|Integer|inteiro octal não assinado.|
|**`u`**|Integer|Inteiro decimal sem sinal.|
|**`x`**|Integer|Inteiro hexadecimal não assinado; usa " `abcdef` ".|
|**`X`**|Integer|Inteiro hexadecimal não assinado; usa " `ABCDEF` ".|
|**`e`**|Ponto flutuante|Um valor assinado que tem a forma [-] *`d.dddd`* __e ±__ *`dd`* \[ *`d`* ], em que *`d`* é um dígito decimal, *`dddd`* é um ou mais dígitos decimais, dependendo da precisão especificada, ou seis por padrão, e *`dd`* \[ *`d`* ] é de dois ou três dígitos decimais, dependendo do [formato de saída](../c-runtime-library/set-output-format.md) e do tamanho do expoente.|
|**`E`**|Ponto flutuante|Idêntico ao **`e`** formato, exceto que **`E`** , em vez de **`e`** introduzir o expoente.|
|**`f`**|Ponto flutuante|Valor assinado que tem a forma [-] *`dddd`* __.__ *`dddd`* , em que *`dddd`* é um ou mais dígitos decimais. O número de dígitos antes do ponto decimal depende da magnitude do número e o número de dígitos após o ponto decimal depende da precisão solicitada ou é seis, por padrão.|
|**`F`**|Ponto flutuante|Idêntico ao **`f`** formato, exceto que a saída de Infinity e Nan está em letras maiúsculas.|
|**`g`**|Ponto flutuante|Os valores assinados são exibidos no **`f`** **`e`** formato ou, o que for mais compacto para o valor e a precisão especificados. O **`e`** formato é usado somente quando o expoente do valor é menor que-4 ou maior ou igual ao argumento de *precisão* . Zeros à esquerda são truncados, e o ponto decimal é exibido somente se um ou mais dígitos vierem na sequência.|
|**`G`**|Ponto flutuante|Idêntico ao **`g`** formato, exceto que **`E`** , em vez de **`e`** , apresenta o expoente (quando apropriado).|
|**`a`**|Ponto flutuante|Valor de ponto flutuante de precisão dupla hexadecimal assinado que tem a forma *[-] 0xh. HHHH*__p ±__ *`dd`* , em que *h. HHHH* são os dígitos hexadecimais (usando letras minúsculas) do mantissa e *`dd`* são um ou mais dígitos para o expoente. A precisão especifica o número de dígitos após a vírgula.|
|**`A`**|Ponto flutuante|Valor de ponto flutuante de precisão dupla hexadecimal assinado que tem a forma *[-] 0Xh. HHHH*__P ±__ *`dd`* , em que *h. HHHH* são os dígitos hexadecimais (usando letras maiúsculas) do mantissa e *DD* são um ou mais dígitos para o expoente. A precisão especifica o número de dígitos após a vírgula.|
|**`n`**|Ponteiro para o inteiro|Número de caracteres gravados com êxito até o momento no fluxo ou no buffer. Esse valor é armazenado no inteiro cujo endereço é fornecido como o argumento. O tamanho do número inteiro apontado pode ser controlado por um prefixo de especificação de tamanho de argumento. O **`n`** especificador é desabilitado por padrão; para obter informações, consulte a observação de segurança importante.|
|**`p`**|Tipo ponteiro|Exiba o argumento como um endereço em dígitos hexadecimais.|
|**`s`**|String|Quando usado com funções `printf`, especifica uma cadeia de caracteres de byte único ou uma cadeia de caracteres de bytes múltiplos; quando usado com funções `wprintf`, especifica uma cadeia de caracteres largos. Os caracteres são exibidos até o primeiro caractere nulo ou até que o valor de *precisão* seja atingido.|
|**`S`**|String|Quando usado com funções `printf`, especifica uma cadeia de caracteres largos; quando usado com funções `wprintf`, especifica uma cadeia de caracteres de byte único ou uma cadeia de caracteres de bytes múltiplos. Os caracteres são exibidos até o primeiro caractere nulo ou até que o valor de *precisão* seja atingido.|
|**`Z`**|Estrutura `ANSI_STRING` ou `UNICODE_STRING`|Quando o endereço de uma [`ANSI_STRING`](/windows/win32/api/ntdef/ns-ntdef-string) [`UNICODE_STRING`](/windows/win32/api/ntdef/ns-ntdef-_unicode_string) estrutura ou é passado como o argumento, exibe a cadeia de caracteres contida no buffer apontado pelo `Buffer` campo da estrutura. Use um prefixo de modificador de *tamanho* de **`w`** para especificar um `UNICODE_STRING` argumento, por exemplo, `%wZ` . O campo `Length` da estrutura deve ser definido como a duração, em bytes, da cadeia de caracteres. O campo `MaximumLength` da estrutura deve ser definido como a duração, em bytes, do buffer.<br /><br />Normalmente, o **`Z`** caractere de tipo é usado apenas em funções de depuração de driver que usam uma especificação de conversão, como `dbgPrint` e `kdPrint` .|

A partir do Visual Studio 2015, se o argumento que corresponde a um especificador de conversão de ponto flutuante (,,,,,, **`a`** **`A`** **`e`** **`E`** **`f`** **`F`** **`g`** , **`G`** ) for infinito, indefinido ou NaN, a saída formatada está em conformidade com o padrão C99. Esta tabela lista a saída formatada:

|Valor|Saída|
|-----------|------------|
|infinity|`inf`|
|NaN silencioso|`nan`|
|Sinalização de NaN|`nan(snan)`|
|NaN indefinido|`nan(ind)`|

Qualquer um desses valores pode ser ter um sinal como prefixo. Se um caractere especificador de conversão de *tipo* de ponto flutuante for uma letra maiúscula, a saída também será formatada em letras maiúsculas. Por exemplo, se o especificador de formato for `%F` em vez de `%f`, um infinito será formatado como `INF` em vez de `inf`. As funções `scanf` também podem analisar essas cadeias de caracteres, para que esses valores possam fazer uma viagem de ida e volta nas funções `printf` e `scanf`.

Antes do Visual Studio 2015, o CRT usava um formato diferente não padrão para saída de valores infinitos, indefinidos e NaN:

|Valor|Saída|
|-----------|------------|
|+ infinity|`1.#INF` *random-digits*|
|- infinity|`-1.#INF` *random-digits*|
|Indefinite (mesmo que NaN silencioso)|*dígito* `.#IND` *random-digits*|
|NaN|*dígito* `.#NAN` *random-digits*|

Qualquer um deles pode ter sido prefixado por um sinal e pode ter sido formatado de forma diferente, dependendo da largura e da precisão do campo, às vezes com efeitos incomuns. Por exemplo, `printf("%.2f\n", INFINITY)` imprimes `1.#J` porque o *#INF* seria "arredondado" para dois dígitos de precisão.

> [!NOTE]
> Se o argumento que corresponde a `%s` ou `%S` ou o campo `Buffer` do argumento que corresponde a `%Z` for um ponteiro nulo, "(null)" será exibido.

> [!NOTE]
> Em todos os formatos exponenciais, o número mínimo de dígitos do expoente para exibição é dois, usando três somente se necessário. Usando a [`_set_output_format`](../c-runtime-library/set-output-format.md) função, você pode definir o número de dígitos exibidos para três para compatibilidade com versões anteriores com código escrito para Visual Studio 2013 e antes.

> [!IMPORTANT]
> Como o `%n` formato é inerentemente inseguro, ele é desabilitado por padrão. Se `%n` for encontrado em um formato de cadeia de caracteres, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../c-runtime-library/parameter-validation.md). Para habilitar o `%n` suporte, consulte [`_set_printf_count_output`](../c-runtime-library/reference/set-printf-count-output.md) .

<a name="flags"></a>

## <a name="flag-directives"></a>Diretivas de sinalizador

O primeiro campo opcional em uma especificação de conversão contém *diretivas de sinalizador* , zero ou mais caracteres de sinalizador que especificam a saída de justificação e controlam a saída de sinais, espaços em branco, zeros à esquerda, pontos decimais e prefixos octais e hexadecimais. Mais de uma diretiva de sinalizador pode aparecer em uma especificação de conversão e os caracteres de sinalizadores podem aparecer em qualquer ordem.

### <a name="flag-characters"></a>Caracteres de sinalizador

|Sinalizador|Significado|Padrão|
|----------|-------------|-------------|
|**`-`**|Alinhar à esquerda o resultado dentro da largura de campo determinada.|Alinhar à direita.|
|**`+`**|Use um sinal (+ ou-) para prefixar o valor de saída se ele for de um tipo assinado.|O sinal será exibido somente para valores assinados negativos (-).|
|**`0`**|Se a *largura* for prefixada por **`0`** , os zeros à esquerda serão adicionados até que a largura mínima seja atingida. Se **`0`** e for **`-`** exibido, o **`0`** será ignorado. Se **`0`** for especificado para um formato de inteiro (,,,, **`i`** **`u`** **`x`** **`X`** **`o`** , **`d`** ) e uma especificação de precisão também estiver presente — por exemplo, `%04.d` — o **`0`** será ignorado. Se **`0`** for especificado para o **`a`** **`A`** formato de ponto flutuante, os zeros à esquerda serão anexados ao mantissa, após o `0x` `0X` prefixo ou.|Nenhum preenchimento.|
|**em branco (' ')**|Use um espaço em branco para prefixar o valor de saída se ele for assinado e positivo. O espaço em branco será ignorado se o espaço em branco e os sinalizadores + forem exibidos.|Nenhum espaço em branco é exibido.|
|**`#`**|Quando usado com o **`o`** **`x`** formato,, ou **`X`** , o **`#`** sinalizador usa `0` , `0x` , ou `0X` , respectivamente, para prefixar qualquer valor de saída diferente de zero.|Nenhum espaço em branco é exibido.|
||Quando usado com o **`e`** formato,,,, **`E`** **`f`** **`F`** **`a`** ou **`A`** , o **`#`** sinalizador força o valor de saída a conter um ponto decimal.|O ponto decimal será exibido somente se os dígitos o seguirem.|
||Quando usado com o **`g`** **`G`** formato ou, o **`#`** sinalizador força o valor de saída a conter um ponto decimal e impede o truncamento dos zeros à direita.<br /><br /> Ignorado quando usado com **`c`** ,,, **`d`** **`i`** **`u`** ou **`s`** .|O ponto decimal será exibido somente se os dígitos o seguirem. Zeros à direita são truncados.|

<a name="width"></a>

## <a name="width-specification"></a>Especificação de largura

Em uma especificação de conversão, o campo de especificação de largura opcional aparece após quaisquer caracteres *sinalizadores* . O argumento de *largura* é um inteiro decimal não negativo que controla o número mínimo de caracteres de saída. Se o número de caracteres no valor de saída for menor que a largura especificada, os espaços em branco serão adicionados à esquerda ou à direita dos valores — dependendo se o sinalizador de alinhamento à esquerda ( **`-`** ) for especificado — até que a largura mínima seja atingida. Se a *largura* tiver 0 como prefixo, zeros à esquerda serão adicionados ao inteiro ou a conversões de ponto flutuante até que a largura mínima seja atingida, exceto quando a conversão for a um infinito ou NaN.

A especificação de largura nunca faz com que um valor seja truncado. Se o número de caracteres no valor de saída for maior que a largura especificada, ou se a *largura* não for fornecida, todos os caracteres do valor serão de saída, sujeitos à especificação de *precisão* .

Se a especificação de precisão for um asterisco (`*`), um argumento `int` da lista de argumentos fornecerá o valor. Na lista de argumentos, o argumento *largura* deve preceder o valor que está sendo formatado, conforme mostrado neste exemplo:

`printf("%0*d", 5, 3);  /* 00003 is output */`

Um valor ausente ou pequeno de *largura* em uma especificação de formato não causa o truncamento de um valor de saída. Se o resultado de uma conversão for maior do que o valor de *largura* , o campo se expandirá para conter o resultado da conversão.

<a name="precision"></a>

## <a name="precision-specification"></a>Especificação da precisão

Em uma especificação de conversão de formato, o terceiro campo opcional é a especificação de precisão. Ele consiste em um ponto ( `.` ) seguido por um inteiro decimal não negativo que, dependendo do tipo de conversão, especifica o número de caracteres de cadeias de caracteres, o número de casas decimais ou o número de dígitos significativos a serem gerados.

Ao contrário da especificação de largura, a especificação de precisão pode causar o truncamento do valor de saída ou arredondamento de um valor de ponto flutuante. Se a *precisão* for especificada como 0 e o valor a ser convertido for 0, o resultado não será uma saída de caracteres, conforme mostrado neste exemplo:

`printf( "%.0d", 0 );      /* No characters output */`

Se a especificação de precisão for um asterisco (`*`), um argumento `int` da lista de argumentos fornecerá o valor. Na lista de argumentos, o argumento de *precisão* deve preceder o valor que está sendo formatado, conforme mostrado neste exemplo:

`printf( "%.*f", 3, 3.14159265 );  /* 3.142 output */`

O caractere de *tipo* determina a interpretação de *precisão* ou a precisão padrão quando *precisão* é omitida, conforme mostrado na tabela a seguir.

### <a name="how-precision-values-affect-type"></a>Como os valores de precisão afetam o tipo

|Type|Significado|Padrão|
|----------|-------------|-------------|
|**`a`** , **`A`**|A precisão especifica o número de dígitos após a vírgula.|A precisão padrão é 13. Se precisão for 0, nenhum ponto decimal será impresso, a menos que o **`#`** sinalizador seja usado.|
|**`c`** , **`C`**|A precisão não tem nenhum efeito.|O caractere foi impresso.|
|**`d`** , **`i`** , **`o`** , **`u`** , **`x`** , **`X`**|A precisão especifica o número mínimo de dígitos a ser impresso. Se o número de dígitos no argumento for menor que *precisão* , o valor de saída será preenchido com zeros à esquerda. O valor não é truncado quando o número de dígitos excede a *precisão* .|A precisão padrão é 1.|
|**`e`** , **`E`**|A precisão especifica o número de dígitos a serem impressos após a vírgula decimal. O último dígito impresso será arredondado.|A precisão padrão é 6. Se *precisão* for 0 ou o ponto ( `.` ) aparecer sem um número após ele, nenhum ponto decimal será impresso.|
|**`f`** , **`F`**|O valor de precisão especifica o número de dígitos após a vírgula decimal. Se uma vírgula decimal aparecer, pelo menos um dígito aparecerá antes dela. O valor é arredondado para o número apropriado de dígitos.|A precisão padrão é 6. Se *precisão* for 0, ou se o ponto ( `.` ) aparecer sem um número após ele, nenhum ponto decimal será impresso.|
|**`g`** , **`G`**|A precisão especifica o número máximo de dígitos significativos impressos.|Seis dígitos significativos são impressos e os zeros à direita são truncados.|
|**`s`** , **`S`**|A precisão especifica o número máximo de caracteres a serem impressos. Os caracteres em excesso de *precisão* não são impressos.|Os caracteres são impressos até que um caractere nulo seja encontrado.|

<a name="size"></a>

## <a name="argument-size-specification"></a>Especificação de tamanho de argumento

Em uma especificação de conversão, o campo *tamanho* é um modificador de comprimento do argumento para o especificador de conversão de *tipo* . O campo de *tamanho* prefixos para o campo de *tipo* —,,, **`hh`** **`h`** **`j`** (minúscula L),,,,,, **`l`** **`L`** **`ll`** **`t`** **`w`** **`z`** **`I`** (maiúscula i), **`I32`** e **`I64`** — especifica o "tamanho" do argumento correspondente — longo ou curto, 32 bits ou 64 bits, caractere de byte único ou caractere largo — dependendo do especificador de conversão que eles modificam. Esses prefixos de tamanho são usados com caracteres de *tipo* nas famílias de funções `printf` e `wprintf` para especificar a interpretação dos tamanhos de argumento, como mostrado na tabela a seguir. O campo *tamanho* é opcional para alguns tipos de argumentos. Quando nenhum prefixo de tamanho for especificado, o formatador consumirá argumentos inteiros – por exemplo, `char`, `short`, `int`, `long` com sinal ou sem sinal e tipos de enumeração – como tipos `int` de 32 bits, e argumentos de ponto flutuante `float`, `double` e `long double` serão consumidos como tipos `double` de 64 bits. Esse comportamento corresponde às regras de promoção de argumento padrão para listas de argumentos variáveis. Para obter mais informações sobre a promoção de argumentos, consulte reticências e argumentos padrão em [expressões de sufixo](../cpp/postfix-expressions.md). Em sistemas de 32 bits e 64 bits, a especificação de conversão de um argumento inteiro de 64 bits deve incluir um prefixo de tamanho **`ll`** ou **`I64`** . Caso contrário, o comportamento do formatador será indefinido.

Alguns tipos têm tamanhos diferentes no código de 32 bits e 64 bits. Por exemplo, `size_t` é de 32 bits longa no código compilado para x86 e 64 bits no código compilado para x64. Para criar o código de formatação independente de plataforma para tipos de largura variável, você pode usar um modificador de tamanho do argumento de largura variável. Em vez disso, use um modificador de tamanho de argumento de 64 bits e promova explicitamente o tipo de argumento de largura variável para 64 bits. O modificador de tamanho do argumento específico da Microsoft **`I`** (maiúsculas e minúsculas) manipula os argumentos inteiros de largura variável, mas recomendamos os modificadores específicos de tipo **`j`** , **`t`** e **`z`** para portabilidade.

### <a name="size-prefixes-for-printf-and-wprintf-format-type-specifiers"></a>Prefixos de Tamanho para Especificadores de Tipo de Tamanho printf e wpprintf

|Para especificar|Use o prefixo|Com especificador de tipo|
|----------------|----------------|-------------------------|
|`char`<br />`unsigned char`|**`hh`**|**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`**|
|`short int`<br />`short unsigned int`|**`h`**|**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`**|
|`__int32`<br />`unsigned __int32`|**`I32`**|**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`**|
|`__int64`<br />`unsigned __int64`|**`I64`**|**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`**|
|`intmax_t`<br />`uintmax_t`|**`j`** or **`I64`**|**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`**|
|`long double`|**`l`** (minúscula L) ou **`L`**|**`a`** , **`A`** , **`e`** , **`E`** , **`f`** , **`F`** , **`g`** ou **`G`**|
|`long int`<br />`long unsigned int`|**`l`** (L minúsculo) |**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`** |
|`long long int`<br />`unsigned long long int`|**`ll`**  (minúsculas)|**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`**|
|`ptrdiff_t`|**`t`** ou **`I`** (maiúscula i)|**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`**|
|`size_t`|**`z`** ou **`I`** (maiúscula i)|**`d`** ,,, **`i`** **`o`** **`u`** , **`x`** ou **`X`**|
|Caractere de byte único|**`h`**|**`c`** or **`C`**|
|Caractere largo|**`l`** (minúscula L) ou **`w`**|**`c`** or **`C`**|
|Cadeia de caracteres de byte único|**`h`**|**`s`** , **`S`** ou **`Z`**|
|Cadeia de caracteres largos|**`l`** (minúscula L) ou **`w`**|**`s`** , **`S`** ou **`Z`**|

Os tipos `ptrdiff_t` e `size_t` são `__int32` ou `unsigned __int32` em plataformas de 32 bits e `__int64` ou `unsigned __int64` em plataformas de 64 bits. Os **`I`** prefixos (maiúsculas e minúsculas), **`j`** , **`t`** e de **`z`** tamanho assumem a largura de argumento correta para a plataforma.

No Visual C++, embora `long double` seja um tipo diferente, ele tem a mesma representação interna que `double`.

Um **`hc`** **`hC`** especificador ou tipo é sinônimo de **`c`** in `printf` Functions e with **`C`** in `wprintf` functions. Um **`lc`** **`lC`** **`wc`** especificador,, ou de **`wC`** tipo é sinônimo de **`C`** in `printf` Functions e with **`c`** in `wprintf` functions. Um **`hs`** **`hS`** especificador ou tipo é sinônimo de **`s`** in `printf` Functions e with **`S`** in `wprintf` functions. Um **`ls`** **`lS`** **`ws`** especificador,, ou de **`wS`** tipo é sinônimo de **`S`** em `printf` funções e com **`s`** `wprintf` funções in.

> [!NOTE]
> **Específico da Microsoft:**\
> Os **`I`** prefixos (maiúsculas), **`I32`** ,, e de tamanho do argumento do **`I64`** **`w`** modificador são extensões da Microsoft e não são compatíveis com ISO C. O **`h`** prefixo quando usado com os dados do tipo `char` e o **`l`** prefixo (L minúsculo) quando usado com dados do tipo `double` são extensões da Microsoft.

## <a name="see-also"></a>Confira também

[`printf, _printf_l, wprintf, _wprintf_l`](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)\
[`printf_s, _printf_s_l, wprintf_s, _wprintf_s_l`](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md)\
[`printf_p` Parâmetros posicionais](../c-runtime-library/printf-p-positional-parameters.md)
