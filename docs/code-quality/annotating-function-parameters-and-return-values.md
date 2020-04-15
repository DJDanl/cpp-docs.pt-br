---
title: Anotando parâmetros de função e valores de retorno
description: Guia de referência para parâmetro de função e anotações de valor de retorno.
ms.date: 10/15/2019
ms.topic: conceptual
f1_keywords:
- _Outptr_opt_result_bytebuffer_to_
- _Inout_updates_all_opt_
- _Post_equal_to_
- _Outptr_opt_result_maybenull_
- _Out_writes_bytes_all_
- _Out_writes_all_opt_
- _In_opt_
- _Outptr_
- _Outptr_result_maybenull_
- _Outref_result_bytebuffer_all_maybenull_
- _Inout_updates_opt_z_
- _Inout_updates_z_
- _Out_writes_
- _Out_writes_to_ptr_opt_z_
- _In_reads_to_ptr_opt_
- _Ret_writes_to_maybenull_
- _Outref_result_maybenull_
- _Ret_writes_bytes_
- _Outptr_result_bytebuffer_
- _Out_writes_opt_
- _Inout_updates_bytes_opt_
- _In_z_
- _Inout_updates_to_
- _Ret_maybenull_
- _Ret_writes_bytes_to_
- _Ret_z_
- _COM_Outptr_
- _Ret_maybenull_z_
- _Out_opt_
- _In_reads_opt_z_
- _Outptr_result_bytebuffer_to_
- _Ret_notnull_
- _COM_Outptr_opt_result_maybenull_
- _Inout_updates_to_opt_
- _Inout_updates_
- _Outptr_opt_result_buffer_
- _Outptr_result_buffer_to_
- _Out_writes_to_ptr_opt_
- _Out_writes_bytes_all_opt_
- _Inout_updates_all_
- _Deref_inout_range_
- _Ret_writes_
- _Out_writes_z_
- _Ret_writes_to_
- _Out_writes_to_ptr_z_
- _Out_writes_bytes_to_opt_
- _In_reads_or_z_
- _Inout_updates_bytes_to_
- _In_reads_z_
- _In_opt_z_
- _Outref_result_buffer_maybenull_
- _Ret_range_
- _COM_Outptr_opt_
- _Outptr_opt_result_maybenull_z_
- _In_reads_opt_
- _Inout_
- _Field_range_
- _Ret_writes_z_
- _Out_writes_to_
- _Out_writes_to_ptr_
- _Inout_opt_z_
- _Outref_
- _Deref_out_range_
- _Outref_result_buffer_
- _Outref_result_buffer_to_
- _Outref_result_bytebuffer_to_maybenull_
- _In_reads_bytes_
- _Outptr_opt_result_buffer_to_
- _Outref_result_buffer_all_
- _Out_writes_bytes_to_
- _Result_zeroonfailure_
- _In_reads_bytes_opt_
- _Outref_result_buffer_to_maybenull_
- _Outref_result_bytebuffer_all_
- _Outref_result_buffer_all_maybenull_
- _Ret_writes_maybenull_z_
- _In_range_
- _Inout_updates_bytes_all_opt_
- _Outref_result_bytebuffer_to_
- _Inout_updates_bytes_to_opt_
- _Pre_equal_to_
- _Ret_writes_bytes_maybenull_
- _COM_Outptr_result_maybenull_
- _Ret_writes_maybenull_
- _Out_writes_bytes_
- _Outptr_opt_
- _Out_writes_opt_z_
- _Outref_result_nullonfailure_
- _Outptr_opt_result_z_
- _Inout_opt_
- _Deref_in_range_
- _Outptr_result_z_
- _In_reads_to_ptr_opt_z_
- _Struct_size_bytes_
- _Outptr_result_nullonfailure_
- _In_
- _Inout_updates_bytes_
- _In_reads_to_ptr_z_
- _Ret_writes_bytes_to_maybenull
- _Outptr_opt_result_nullonfailure_
- _In_reads_to_ptr_
- _Outptr_result_buffer_
- _Out_
- _Outref_result_bytebuffer_maybenull_
- _Outptr_result_maybenull_z_
- _In_reads_
- _Inout_updates_opt_
- _Out_writes_to_opt_
- _Outptr_opt_result_bytebuffer_
- _Out_writes_all_
- _Out_range_
- _Inout_updates_bytes_all_
- _Inout_z_
- _Outref_result_bytebuffer_
- _Result_nullonfailure_
- _Ret_null_
- _Scanf_format_string_
- _Scanf_s_format_string_
- _Printf_format_string_
ms.assetid: 82826a3d-0c81-421c-8ffe-4072555dca3a
ms.openlocfilehash: c787dcfb252da1abe47251d66c46689db289cf15
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81328006"
---
# <a name="annotating-function-parameters-and-return-values"></a>Anotando parâmetros de função e valores de retorno

Este artigo descreve os usos típicos de anotações para parâmetros de função simples — escalares e ponteiros para estruturas e classes — e a maioria dos tipos de buffers. Este artigo também mostra padrões de uso comuns para anotações. Para obter anotações adicionais relacionadas às funções, consulte [Comportamento de função anotador](../code-quality/annotating-function-behavior.md).

## <a name="pointer-parameters"></a>Parâmetros do ponteiro

Para as anotações na tabela a seguir, quando um parâmetro de ponteiro está sendo anotado, o analisador relata um erro se o ponteiro estiver nulo. Esta anotação se aplica a ponteiros e a qualquer item de dados apontado.

### <a name="annotations-and-descriptions"></a>Anotações e descrições

- `_In_`

     Anota parâmetros de entrada que são escalares, estruturas, ponteiros para estruturas e afins. Explicitamente pode ser usado em escalares simples. O parâmetro deve ser válido no pré-estado e não será modificado.

- `_Out_`

     Anota parâmetros de saída que são escalares, estruturas, ponteiros para estruturas e afins. Não aplique essa anotação a um objeto que não pode retornar um valor — por exemplo, um escalar que é passado por valor. O parâmetro não precisa ser válido no pré-estado, mas deve ser válido no pós-estado.

- `_Inout_`

     Anota um parâmetro que será alterado pela função. Deve ser válido tanto no pré-estado quanto no pós-estado, mas presume-se que tenha valores diferentes antes e depois da chamada. Deve aplicar-se a um valor modificável.

- `_In_z_`

     Um ponteiro para uma seqüência de terminadas nula que é usado como entrada. A seqüência deve ser válida no pré-estado. Variantes `PSTR`de , que já têm as anotações corretas, são preferidas.

- `_Inout_z_`

     Um ponteiro para uma matriz de caracteres com término nulo que será modificada. Deve ser válido antes e depois da chamada, mas presume-se que o valor tenha mudado. O exterminador nulo pode ser movido, mas apenas os elementos até o exterminador nulo original podem ser acessados.

- `_In_reads_(s)`

     `_In_reads_bytes_(s)`

     Um ponteiro para uma matriz, que é lida pela função. A matriz é `s` de elementos de tamanho, todos os quais devem ser válidos.

     A `_bytes_` variante dá o tamanho em bytes em vez de elementos. Use esta variante somente quando o tamanho não puder ser expresso como elementos. Por exemplo, `char` as strings usariam a `_bytes_` variante apenas se uma função semelhante que usa. `wchar_t`

- `_In_reads_z_(s)`

     Um ponteiro para uma matriz que é nula e tem um tamanho conhecido. Os elementos até o `s` exterminador nulo — ou se não houver um exterminador nulo — devem ser válidos no pré-estado. Se o tamanho for conhecido em `s` bytes, dimensione pelo tamanho do elemento.

- `_In_reads_or_z_(s)`

     Um ponteiro para uma matriz que é nula ou tem um tamanho conhecido, ou ambos. Os elementos até o `s` exterminador nulo — ou se não houver um exterminador nulo — devem ser válidos no pré-estado. Se o tamanho for conhecido em `s` bytes, dimensione pelo tamanho do elemento. (Usado para `strn` a família.)

- `_Out_writes_(s)`

     `_Out_writes_bytes_(s)`

     Um ponteiro para `s` uma matriz de elementos (resp. bytes) que será escrito pela função. Os elementos de matriz não devem ser válidos no pré-estado, e o número de elementos válidos no pós-estado não é especificado. Se houver anotações no tipo de parâmetro, elas são aplicadas no pós-estado. Por exemplo, considere o código a seguir.

     ```cpp
     typedef _Null_terminated_ wchar_t *PWSTR;
     void MyStringCopy(_Out_writes_(size) PWSTR p1, _In_ size_t size, _In_ PWSTR p2);
     ```

     Neste exemplo, o chamador `size` fornece `p1`um buffer de elementos para . `MyStringCopy`torna alguns desses elementos válidos. Mais importante, `_Null_terminated_` a anotação `PWSTR` `p1` em meios que é nulo-encerrado no pós-estado. Desta forma, o número de elementos válidos ainda é bem definido, mas uma contagem específica de elementos não é necessária.

     A `_bytes_` variante dá o tamanho em bytes em vez de elementos. Use esta variante somente quando o tamanho não puder ser expresso como elementos. Por exemplo, `char` as strings usariam a `_bytes_` variante apenas se uma função semelhante que usa. `wchar_t`

- `_Out_writes_z_(s)`

     Um ponteiro para `s` uma matriz de elementos. Os elementos não têm que ser válidos no pré-estado. No pós-estado, os elementos através do exterminador nulo — que devem estar presentes — devem ser válidos. Se o tamanho for conhecido em `s` bytes, dimensione pelo tamanho do elemento.

- `_Inout_updates_(s)`

     `_Inout_updates_bytes_(s)`

     Um ponteiro para uma matriz, que é ao mesmo tempo lido e escrito na função. É de elementos de tamanho, `s` e válido em pré-estado e pós-estado.

     A `_bytes_` variante dá o tamanho em bytes em vez de elementos. Use esta variante somente quando o tamanho não puder ser expresso como elementos. Por exemplo, `char` as strings usariam a `_bytes_` variante apenas se uma função semelhante que usa. `wchar_t`

- `_Inout_updates_z_(s)`

     Um ponteiro para uma matriz que é nula e tem um tamanho conhecido. Os elementos através do exterminador nulo — que devem estar presentes — devem ser válidos tanto no pré-estado quanto no pós-estado. Presume-se que o valor no pós-estado seja diferente do valor no pré-estado; que inclui a localização do exterminador nulo. Se o tamanho for conhecido em `s` bytes, dimensione pelo tamanho do elemento.

- `_Out_writes_to_(s,c)`

     `_Out_writes_bytes_to_(s,c)`

     `_Out_writes_all_(s)`

     `_Out_writes_bytes_all_(s)`

     Um ponteiro para `s` uma matriz de elementos. Os elementos não têm que ser válidos no pré-estado. No pós-estado, os elementos até o `c`elemento -th devem ser válidos. A `_bytes_` variante pode ser usada se o tamanho for conhecido em bytes em vez de número de elementos.

     Por exemplo:

     ```cpp
     void *memcpy(_Out_writes_bytes_all_(s) char *p1, _In_reads_bytes_(s) char *p2, _In_ int s);
     void *wordcpy(_Out_writes_all_(s) DWORD *p1, _In_reads_(s) DWORD *p2, _In_ int s);
     ```

- `_Inout_updates_to_(s,c)`

     `_Inout_updates_bytes_to_(s,c)`

     Um ponteiro para uma matriz, que é ao mesmo tempo lido e escrito pela função. É de elementos de tamanho, `s` todos os quais devem `c` ser válidos em pré-estado, e os elementos devem ser válidos em pós-estado.

     A `_bytes_` variante dá o tamanho em bytes em vez de elementos. Use esta variante somente quando o tamanho não puder ser expresso como elementos. Por exemplo, `char` as strings usariam a `_bytes_` variante apenas se uma função semelhante que usa. `wchar_t`

- `_Inout_updates_all_(s)`

     `_Inout_updates_bytes_all_(s)`

     Um ponteiro para uma matriz, que é ao `s` mesmo tempo lido e escrito pela função dos elementos de tamanho. Definido como equivalente a:

     `_Inout_updates_to_(_Old_(s), _Old_(s))    _Inout_updates_bytes_to_(_Old_(s), _Old_(s))`

     Em outras palavras, todos os elementos que existem no buffer até `s` o pré-estado são válidos no pré-estado e pós-estado.

     A `_bytes_` variante dá o tamanho em bytes em vez de elementos. Use esta variante somente quando o tamanho não puder ser expresso como elementos. Por exemplo, `char` as strings usariam a `_bytes_` variante apenas se uma função semelhante que usa. `wchar_t`

- `_In_reads_to_ptr_(p)`

     Um ponteiro para uma `p - _Curr_` matriz para `p` `_Curr_`a qual (isto é, menos) é uma expressão válida. Os elementos anteriores `p` devem ser válidos no pré-estado.

    Por exemplo:

    ```cpp
    int ReadAllElements(_In_reads_to_ptr_(EndOfArray) const int *Array, const int *EndOfArray);
    ```

- `_In_reads_to_ptr_z_(p)`

     Um ponteiro para uma matriz terminada `p - _Curr_` nula `p` para `_Curr_`qual expressão (ou seja, menos) é uma expressão válida. Os elementos anteriores `p` devem ser válidos no pré-estado.

- `_Out_writes_to_ptr_(p)`

     Um ponteiro para uma `p - _Curr_` matriz para `p` `_Curr_`a qual (isto é, menos) é uma expressão válida. Os elementos anteriores `p` não precisam ser válidos no pré-estado e devem ser válidos no pós-estado.

- `_Out_writes_to_ptr_z_(p)`

     Um ponteiro para uma matriz terminada nula para a qual `p - _Curr_` (isto é, `p` menos) `_Curr_`é uma expressão válida. Os elementos anteriores `p` não precisam ser válidos no pré-estado e devem ser válidos no pós-estado.

## <a name="optional-pointer-parameters"></a>Parâmetros de ponteiro opcionais

Quando uma anotação de `_opt_`parâmetro de ponteiro inclui, indica que o parâmetro pode ser nulo. Caso contrário, a anotação se comporta da mesma forma `_opt_`que a versão que não inclui . Aqui está uma `_opt_` lista das variantes das anotações do parâmetro do ponteiro:

||||
|-|-|-|
|`_In_opt_`<br /><br /> `_Out_opt_`<br /><br /> `_Inout_opt_`<br /><br /> `_In_opt_z_`<br /><br /> `_Inout_opt_z_`<br /><br /> `_In_reads_opt_`<br /><br /> `_In_reads_bytes_opt_`<br /><br /> `_In_reads_opt_z_`|`_Out_writes_opt_`<br /><br /> `_Out_writes_opt_z_`<br /><br /> `_Inout_updates_opt_`<br /><br /> `_Inout_updates_bytes_opt_`<br /><br /> `_Inout_updates_opt_z_`<br /><br /> `_Out_writes_to_opt_`<br /><br /> `_Out_writes_bytes_to_opt_`<br /><br /> `_Out_writes_all_opt_`<br /><br /> `_Out_writes_bytes_all_opt_`|`_Inout_updates_to_opt_`<br /><br /> `_Inout_updates_bytes_to_opt_`<br /><br /> `_Inout_updates_all_opt_`<br /><br /> `_Inout_updates_bytes_all_opt_`<br /><br /> `_In_reads_to_ptr_opt_`<br /><br /> `_In_reads_to_ptr_opt_z_`<br /><br /> `_Out_writes_to_ptr_opt_`<br /><br /> `_Out_writes_to_ptr_opt_z_`|

## <a name="output-pointer-parameters"></a>Parâmetros do ponteiro de saída

Os parâmetros do ponteiro de saída requerem notação especial para desambiguar a nulidade no parâmetro e no local apontado para.

### <a name="annotations-and-descriptions"></a>Anotações e descrições

- `_Outptr_`

   Parâmetro não pode ser nulo, e no pós-estado o local apontado para não pode ser nulo e deve ser válido.

- `_Outptr_opt_`

   Parâmetro pode ser nulo, mas no pós-estado o local apontado não pode ser nulo e deve ser válido.

- `_Outptr_result_maybenull_`

   Parâmetro não pode ser nulo, e no pós-estado o local apontado para a ponta pode ser nulo.

- `_Outptr_opt_result_maybenull_`

   Parâmetro pode ser nulo, e no pós-estado o local apontado pode ser nulo.

  Na tabela a seguir, substrings adicionais são inseridas no nome da anotação para qualificar ainda mais o significado da anotação. As várias subcordas `_COM_` `_buffer_`são, `_bytebuffer_` `_z` `_to_`e .

> [!IMPORTANT]
> Se a interface que você está anotando for COM, use a forma COM dessas anotações. Não use as anotações COM com qualquer outra interface de tipo.

- `_Outptr_result_z_`

   `_Outptr_opt_result_z_`

   `_Outptr_result_maybenull_z_`

   `_Outptr_opt_result_maybenull_z_`

   O ponteiro retornado `_Null_terminated_` tem a anotação.

- `_COM_Outptr_`

   `_COM_Outptr_opt_`

   `_COM_Outptr_result_maybenull_`

   `_COM_Outptr_opt_result_maybenull_`

   O ponteiro retornado tem semântica `_On_failure_` COM e, portanto, carrega uma condição pós-condição de que o ponteiro retornado é nulo.

- `_Outptr_result_buffer_(s)`

   `_Outptr_result_bytebuffer_(s)`

   `_Outptr_opt_result_buffer_(s)`

   `_Outptr_opt_result_bytebuffer_(s)`

   O ponteiro retornado aponta para `s` um buffer válido de elementos de tamanho ou bytes.

- `_Outptr_result_buffer_to_(s, c)`

   `_Outptr_result_bytebuffer_to_(s, c)`

   `_Outptr_opt_result_buffer_to_(s,c)`

   `_Outptr_opt_result_bytebuffer_to_(s,c)`

   O ponteiro retornado aponta para `s` um buffer de elementos `c` de tamanho ou bytes, dos quais o primeiro é válido.

Certas convenções de interface presumem que os parâmetros de saída são anulados por falha. Exceto pelo código COM explicitamente, os formulários na tabela a seguir são preferidos. Para o código COM, use os formulários COM correspondentes listados na seção anterior.

- `_Result_nullonfailure_`

   Modifica outras anotações. O resultado é definido como nulo se a função falhar.

- `_Result_zeroonfailure_`

   Modifica outras anotações. O resultado é definido como zero se a função falhar.

- `_Outptr_result_nullonfailure_`

   O ponteiro retornado aponta para um buffer válido se a função for bem sucedida ou nula se a função falhar. Esta anotação é para um parâmetro não opcional.

- `_Outptr_opt_result_nullonfailure_`

   O ponteiro retornado aponta para um buffer válido se a função for bem sucedida ou nula se a função falhar. Esta anotação é para um parâmetro opcional.

- `_Outref_result_nullonfailure_`

   O ponteiro retornado aponta para um buffer válido se a função for bem sucedida ou nula se a função falhar. Esta anotação é para um parâmetro de referência.

## <a name="output-reference-parameters"></a>Parâmetros de referência de saída

Um uso comum do parâmetro de referência é para parâmetros de saída. Para parâmetros simples `int&`de `_Out_` referência de saída, como , fornece a semântica correta. No entanto, quando o valor `int *&`de saída é um `_Outptr_ int **` ponteiro, como , as anotações de ponteiro equivalente como não fornecem a semântica correta. Para expressar concisamente a semântica dos parâmetros de referência de saída para tipos de ponteiros, use estas anotações compostas:

### <a name="annotations-and-descriptions"></a>Anotações e descrições

- `_Outref_`

     O resultado deve ser válido no pós-estado e não pode ser nulo.

- `_Outref_result_maybenull_`

     O resultado deve ser válido no pós-estado, mas pode ser nulo no pós-estado.

- `_Outref_result_buffer_(s)`

     O resultado deve ser válido no pós-estado e não pode ser nulo. Aponta para o `s` buffer válido dos elementos de tamanho.

- `_Outref_result_bytebuffer_(s)`

     O resultado deve ser válido no pós-estado e não pode ser nulo. Aponta para buffer `s` válido de bytes de tamanho.

- `_Outref_result_buffer_to_(s, c)`

     O resultado deve ser válido no pós-estado e não pode ser nulo. Aponta para `s` o buffer de `c` elementos, dos quais os primeiros são válidos.

- `_Outref_result_bytebuffer_to_(s, c)`

     O resultado deve ser válido no pós-estado e não pode ser nulo. Pontos para `s` buffer de bytes `c` dos quais os primeiros são válidos.

- `_Outref_result_buffer_all_(s)`

     O resultado deve ser válido no pós-estado e não pode ser nulo. Aponta para buffer `s` válido de elementos válidos de tamanho.

- `_Outref_result_bytebuffer_all_(s)`

     O resultado deve ser válido no pós-estado e não pode ser nulo. Aponta para buffer `s` válido de bytes de elementos válidos.

- `_Outref_result_buffer_maybenull_(s)`

     O resultado deve ser válido no pós-estado, mas pode ser nulo no pós-estado. Aponta para o `s` buffer válido dos elementos de tamanho.

- `_Outref_result_bytebuffer_maybenull_(s)`

     O resultado deve ser válido no pós-estado, mas pode ser nulo no pós-estado. Aponta para buffer `s` válido de bytes de tamanho.

- `_Outref_result_buffer_to_maybenull_(s, c)`

     O resultado deve ser válido no pós-estado, mas pode ser nulo no pós-estado. Aponta para `s` o buffer de `c` elementos, dos quais os primeiros são válidos.

- `_Outref_result_bytebuffer_to_maybenull_(s,c)`

     O resultado deve ser válido no pós-estado, mas pode ser nulo no estado pós-estado. Pontos para `s` buffer de bytes `c` dos quais os primeiros são válidos.

- `_Outref_result_buffer_all_maybenull_(s)`

     O resultado deve ser válido no pós-estado, mas pode ser nulo no estado pós-estado. Aponta para buffer `s` válido de elementos válidos de tamanho.

- `_Outref_result_bytebuffer_all_maybenull_(s)`

     O resultado deve ser válido no pós-estado, mas pode ser nulo no estado pós-estado. Aponta para buffer `s` válido de bytes de elementos válidos.

## <a name="return-values"></a>Valores retornados

O valor de retorno de `_Out_` uma função se assemelha a um parâmetro, mas está em um nível diferente de de-referência, e você não precisa considerar o conceito do ponteiro para o resultado. Para as seguintes anotações, o valor de retorno é o objeto anotado — um escalar, um ponteiro para uma estrutura ou um ponteiro para um buffer. Estas anotações têm a mesma semântica que a anotação correspondente. `_Out_`

|||
|-|-|
|`_Ret_z_`<br /><br /> `_Ret_writes_(s)`<br /><br /> `_Ret_writes_bytes_(s)`<br /><br /> `_Ret_writes_z_(s)`<br /><br /> `_Ret_writes_to_(s,c)`<br /><br /> `_Ret_writes_maybenull_(s)`<br /><br /> `_Ret_writes_to_maybenull_(s)`<br /><br /> `_Ret_writes_maybenull_z_(s)`|`_Ret_maybenull_`<br /><br /> `_Ret_maybenull_z_`<br /><br /> `_Ret_null_`<br /><br /> `_Ret_notnull_`<br /><br /> `_Ret_writes_bytes_to_`<br /><br /> `_Ret_writes_bytes_maybenull_`<br /><br /> `_Ret_writes_bytes_to_maybenull_`|

## <a name="format-string-parameters"></a>Parâmetros de seqüência de formato

- `_Printf_format_string_`Indica que o parâmetro é uma seqüência de formato para uso em uma `printf` expressão.

     **Exemplo**

    ```cpp
    int MyPrintF(_Printf_format_string_ const wchar_t* format, ...)
    {
           va_list args;
           va_start(args, format);
           int ret = vwprintf(format, args);
           va_end(args);
           return ret;
    }
    ```

- `_Scanf_format_string_`Indica que o parâmetro é uma seqüência de formato para uso em uma `scanf` expressão.

     **Exemplo**

    ```cpp
    int MyScanF(_Scanf_format_string_ const wchar_t* format, ...)
    {
           va_list args;
           va_start(args, format);
           int ret = vwscanf(format, args);
           va_end(args);
           return ret;
    }
    ```

- `_Scanf_s_format_string_`Indica que o parâmetro é uma seqüência de formato para uso em uma `scanf_s` expressão.

     **Exemplo**

    ```cpp
    int MyScanF_s(_Scanf_s_format_string_ const wchar_t* format, ...)
    {
           va_list args;
           va_start(args, format);
           int ret = vwscanf_s(format, args);
           va_end(args);
           return ret;
    }
    ```

## <a name="other-common-annotations"></a>Outras anotações comuns

### <a name="annotations-and-descriptions"></a>Anotações e descrições

- `_In_range_(low, hi)`

     `_Out_range_(low, hi)`

     `_Ret_range_(low, hi)`

     `_Deref_in_range_(low, hi)`

     `_Deref_out_range_(low, hi)`

     `_Deref_inout_range_(low, hi)`

     `_Field_range_(low, hi)`

     O parâmetro, campo ou resultado está na faixa `low` `hi`(inclusive) de até . Equivalente `_Satisfies_(_Curr_ >= low && _Curr_ <= hi)` a isso é aplicado ao objeto anotado juntamente com as condições adequadas pré-estado ou pós-estado.

    > [!IMPORTANT]
    > Embora os nomes contenham "dentro" e "fora", a semântica de `_In_` e `_Out_` **não** se aplica a essas anotações.

- `_Pre_equal_to_(expr)`

     `_Post_equal_to_(expr)`

     O valor anotado é `expr`exatamente . Equivalente `_Satisfies_(_Curr_ == expr)` a isso é aplicado ao objeto anotado juntamente com as condições adequadas pré-estado ou pós-estado.

- `_Struct_size_bytes_(size)`

     Aplica-se a uma estrutura ou declaração de classe. Indica que um objeto válido desse tipo pode ser maior do que o tipo `size`declarado, com o número de bytes sendo dado por . Por exemplo:

     `typedef _Struct_size_bytes_(nSize) struct MyStruct {    size_t nSize;    ... };`

     O tamanho do buffer em bytes de um parâmetro `pM` de tipo `MyStruct *` é então considerado:

     `min(pM->nSize, sizeof(MyStruct))`

## <a name="related-resources"></a>Recursos relacionados

[Blog da equipe de análise de código](https://blogs.msdn.microsoft.com/codeanalysis/)

## <a name="see-also"></a>Confira também

- [Usando anotações de SAL para reduzir defeitos de código do C/C++](../code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects.md)
- [Noções básicas de SAL](../code-quality/understanding-sal.md)
- [Anotando o comportamento da função](../code-quality/annotating-function-behavior.md)
- [Anotando estruturas e classes](../code-quality/annotating-structs-and-classes.md)
- [Anotando o comportamento de bloqueio](../code-quality/annotating-locking-behavior.md)
- [Especificando quando e onde uma anotação se aplica](../code-quality/specifying-when-and-where-an-annotation-applies.md)
- [Funções intrínsecas](../code-quality/intrinsic-functions.md)
- [Práticas recomendadas e exemplos](../code-quality/best-practices-and-examples-sal.md)
