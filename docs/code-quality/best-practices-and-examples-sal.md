---
title: Práticas recomendadas e exemplos (SAL)
ms.date: 11/04/2016
ms.topic: conceptual
ms.openlocfilehash: 304ba98ae5118f2ca8fb425c8dd7065bd19c8287
ms.sourcegitcommit: 7bea0420d0e476287641edeb33a9d5689a98cb98
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/17/2020
ms.locfileid: "77418616"
---
# <a name="best-practices-and-examples-sal"></a>Práticas recomendadas e exemplos (SAL)

Aqui estão algumas maneiras de aproveitar ao máximo a SAL (linguagem de anotação de código-fonte) e evitar alguns problemas comuns.

## <a name="_in_"></a>\_In\_

Se a função deve gravar no elemento, use `_Inout_` em vez de `_In_`. Isso é particularmente relevante em casos de conversão automatizada de macros antigas para SAL. Antes do SAL, muitos programadores usaram macros como comentários — macros nomeadas `IN`, `OUT`, `IN_OUT`ou variantes desses nomes. Embora seja recomendável converter essas macros em SAL, também recomendamos que você tenha cuidado ao convertê-las porque o código pode ter sido alterado desde que o protótipo original foi escrito e a macro antiga pode não refletir mais o que o código faz. Tenha cuidado especialmente com a macro de comentário `OPTIONAL` porque ela é colocada incorretamente, por exemplo, no lado errado de uma vírgula.

```cpp

// Incorrect
void Func1(_In_ int *p1)
{
    if (p1 == NULL)
        return;

    *p1 = 1;
}

// Correct
void Func2(_Inout_ PCHAR p1)
{
    if (p1 == NULL)
        return;

    *p1 = 1;
}
```

## <a name="_opt_"></a>\_opt\_

Se o chamador não tiver permissão para passar um ponteiro nulo, use `_In_` ou `_Out_` em vez de `_In_opt_` ou `_Out_opt_`. Isso se aplica mesmo a uma função que verifica seus parâmetros e retorna um erro se ele for nulo quando não deveria ser. Embora ter uma função Verifique seu parâmetro para NULL inesperado e retornar normalmente é uma boa prática de codificação defensiva, isso não significa que a anotação de parâmetro pode ser de um tipo opcional (`_*Xxx*_opt_`).

```cpp

// Incorrect
void Func1(_Out_opt_ int *p1)
{
    *p = 1;
}

// Correct
void Func2(_Out_ int *p1)
{
    *p = 1;
}
```

## <a name="_pre_defensive_-and-_post_defensive_"></a>\_pré\_\_ defensiva e \_postar\_defensiva\_

Se uma função aparecer em um limite de confiança, recomendamos que você use a anotação `_Pre_defensive_`.  O modificador "defensiva" modifica certas anotações para indicar que, no ponto de chamada, a interface deve ser marcada estritamente, mas no corpo da implementação, ela deve assumir que os parâmetros incorretos podem ser passados. Nesse caso, `_In_ _Pre_defensive_` é preferencial em um limite de confiança para indicar que, embora um chamador receba um erro se ele tentar passar NULL, o corpo da função será analisado como se o parâmetro fosse nulo e qualquer tentativa de fazer a referência ao ponteiro sem primeiro verificá-lo como NULL será sinalizada.  Uma anotação `_Post_defensive_` também está disponível, para uso em retornos de chamada, em que a parte confiável é considerada como o chamador e o código não confiável é o código chamado.

## <a name="_out_writes_"></a>\_\_gravações\_

O exemplo a seguir demonstra um uso indevido comum de `_Out_writes_`.

```cpp

// Incorrect
void Func1(_Out_writes_(size) CHAR *pb,
    DWORD size
);
```

A anotação `_Out_writes_` significa que você tem um buffer. Ele tem `cb` bytes alocados, com o primeiro byte inicializado na saída. Essa anotação não é estritamente errada e é útil expressar o tamanho alocado. No entanto, ele não informa quantos elementos são inicializados pela função.

O exemplo a seguir mostra três maneiras corretas de especificar completamente o tamanho exato da parte inicializada do buffer.

```cpp

// Correct
void Func1(_Out_writes_to_(size, *pCount) CHAR *pb,
    DWORD size,
    PDWORD pCount
);

void Func2(_Out_writes_all_(size) CHAR *pb,
    DWORD size
);

void Func3(_Out_writes_(size) PSTR pb,
    DWORD size
);
```

## <a name="_out_-pstr"></a>\_out\_ PSTR

O uso de `_Out_ PSTR` está quase sempre errado. Isso é interpretado como tendo um parâmetro de saída que aponta para um buffer de caracteres e é encerrado com NULL.

```cpp

// Incorrect
void Func1(_Out_ PSTR pFileName, size_t n);

// Correct
void Func2(_Out_writes_(n) PSTR wszFileName, size_t n);
```

Uma anotação como `_In_ PCSTR` é comum e útil. Ele aponta para uma cadeia de caracteres de entrada que tem terminação nula porque a pré-condição de `_In_` permite o reconhecimento de uma cadeia de caracteres terminada em nulo.

## <a name="_in_-wchar-p"></a>\_em\_ WCHAR * p

`_In_ WCHAR* p` diz que há um ponteiro de entrada `p` que aponta para um caractere. No entanto, na maioria dos casos, essa provavelmente não é a especificação pretendida. Em vez disso, o que é provavelmente pretendido é a especificação de uma matriz terminada em nulo; para fazer isso, use `_In_ PWSTR`.

```cpp

// Incorrect
void Func1(_In_ WCHAR* wszFileName);

// Correct
void Func2(_In_ PWSTR wszFileName);
```

A especificação apropriada de terminação nula não é comum. Use a versão de `STR` apropriada para substituir o tipo, conforme mostrado no exemplo a seguir.

```cpp

// Incorrect
BOOL StrEquals1(_In_ PCHAR p1, _In_ PCHAR p2)
{
    return strcmp(p1, p2) == 0;
}

// Correct
BOOL StrEquals2(_In_ PSTR p1, _In_ PSTR p2)
{
    return strcmp(p1, p2) == 0;
}
```

## <a name="_out_range_"></a>\_out\_intervalo\_

Se o parâmetro for um ponteiro e você quiser expressar o intervalo do valor do elemento que é apontado pelo ponteiro, use `_Deref_out_range_` em vez de `_Out_range_`. No exemplo a seguir, o intervalo de * pcbFilled é expresso, não pcbFilled.

```cpp

// Incorrect
void Func1(
    _Out_writes_bytes_to_(cbSize, *pcbFilled) BYTE *pb,
    DWORD cbSize,
    _Out_range_(0, cbSize) DWORD *pcbFilled
);

// Correct
void Func2(
    _Out_writes_bytes_to_(cbSize, *pcbFilled) BYTE *pb,
    DWORD cbSize,
    _Deref_out_range_(0, cbSize) _Out_ DWORD *pcbFilled
);
```

a `_Deref_out_range_(0, cbSize)` não é estritamente necessária para algumas ferramentas porque ela pode ser inferida de `_Out_writes_to_(cbSize,*pcbFilled)`, mas é mostrada aqui para fins de integridade.

## <a name="wrong-context-in-_when_"></a>Contexto errado em \_quando\_

Outro erro comum é usar a avaliação de pós-Estado para pré-condições. No exemplo a seguir, `_Requires_lock_held_` é uma pré-condição.

```cpp

// Incorrect
_When_(return == 0, _Requires_lock_held_(p->cs))
int Func1(_In_ MyData *p, int flag);

// Correct
_When_(flag == 0, _Requires_lock_held_(p->cs))
int Func2(_In_ MyData *p, int flag);
```

A expressão `result` se refere a um valor de pós-Estado que não está disponível em pré-estado.

## <a name="true-in-_success_"></a>VERDADEIRO em \_êxito\_

Se a função for bem-sucedida quando o valor de retorno for diferente de zero, use `return != 0` como a condição de êxito em vez de `return == TRUE`. Diferente de zero não significa necessariamente a equivalência para o valor real que o compilador fornece para `TRUE`. O parâmetro para `_Success_` é uma expressão e as expressões a seguir são avaliadas como equivalentes: `return != 0`, `return != false`, `return != FALSE`e `return` sem parâmetros ou comparações.

```cpp
// Incorrect
_Success_(return == TRUE) _Acquires_lock_(*lpCriticalSection)
BOOL WINAPI TryEnterCriticalSection(
  _Inout_ LPCRITICAL_SECTION lpCriticalSection
);

// Correct
_Success_(return != 0) _Acquires_lock_(*lpCriticalSection)
BOOL WINAPI TryEnterCriticalSection(
  _Inout_ LPCRITICAL_SECTION lpCriticalSection
);
```

## <a name="reference-variable"></a>Variável de referência

Para uma variável de referência, a versão anterior de SAL usou o ponteiro implícito como o alvo da anotação e exigia a adição de um `__deref` a anotações que foram anexadas a uma variável de referência. Essa versão usa o próprio objeto e não requer o `_Deref_`adicional.

```cpp

// Incorrect
void Func1(
    _Out_writes_bytes_all_(cbSize) BYTE *pb,
    _Deref_ _Out_range_(0, 2) _Out_ DWORD &cbSize
);

// Correct
void Func2(
    _Out_writes_bytes_all_(cbSize) BYTE *pb,
    _Out_range_(0, 2) _Out_ DWORD &cbSize
);
```

## <a name="annotations-on-return-values"></a>Anotações em valores de retorno

O exemplo a seguir mostra um problema comum em anotações de valor de retorno.

```cpp

// Incorrect
_Out_opt_ void *MightReturnNullPtr1();

// Correct
_Ret_maybenull_ void *MightReturnNullPtr2();
```

Neste exemplo, `_Out_opt_` afirma que o ponteiro pode ser nulo como parte da pré-condição. No entanto, as pré-condições não podem ser aplicadas ao valor de retorno. Nesse caso, a anotação correta é `_Ret_maybenull_`.

## <a name="see-also"></a>Confira também

[Usando anotações de SAL para reduzir defeitos de código do C/C++](../code-quality/using-sal-annotations-to-reduce-c-cpp-code-defects.md)  
[Noções básicas de SAL](../code-quality/understanding-sal.md)  
[Anotando parâmetros de função e valores de retorno](../code-quality/annotating-function-parameters-and-return-values.md)  
[Anotando o comportamento da função](../code-quality/annotating-function-behavior.md)  
[Anotando estruturas e classes](../code-quality/annotating-structs-and-classes.md)  
[Anotando o comportamento de bloqueio](../code-quality/annotating-locking-behavior.md)  
[Especificando quando e onde uma anotação se aplica](../code-quality/specifying-when-and-where-an-annotation-applies.md)  
[Funções intrínsecas](../code-quality/intrinsic-functions.md)
