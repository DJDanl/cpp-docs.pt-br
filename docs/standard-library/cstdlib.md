---
title: '&lt;cstdlib&gt;'
ms.date: 11/04/2016
f1_keywords:
- <cstdlib>
helpviewer_keywords:
- cstdlib header
ms.assetid: 0a6aaebf-84e9-4b60-ae90-17e11981cf54
ms.openlocfilehash: 70e05ad734fa49ba8cb96e4bf83bc05b99c5f55c
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68246522"
---
# <a name="ltcstdlibgt"></a>&lt;cstdlib&gt;

Inclui o cabeçalho da biblioteca C padrão \<stdlib. h > e adiciona os nomes associados ao `std` namespace. Inclusão desse cabeçalho garante que os nomes declarados usando vinculação externa no cabeçalho da biblioteca padrão C são declarados no `std` namespace.

> [!NOTE]
> \<stdlib. h > não inclui o tipo **wchar_t**.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<cstdlib >

**Namespace:** std

## <a name="namespace-and-macros"></a>Namespace e Macros

```cpp
namespace std {
    using size_t = see definition;
    using div_t = see definition;
    using ldiv_t = see definition;
    using lldiv_t = see definition;
}

#define NULL
#define EXIT_FAILURE
#define EXIT_SUCCESS
#define RAND_MAX
#define MB_CUR_MAX
```

## <a name="exposition-only-functions"></a>Somente funções de exposição

```cpp
extern "C" using c-atexit-handler = void();
extern "C++" using atexit-handler = void();
extern "C" using c-compare-pred = int(const void*, const void*);
extern "C++" using compare-pred = int(const void*, const void*);
```

## <a name="start-and-termination-functions"></a>Funções de início e término

|Função|Descrição|
|-|-|
|[_Exit](#_exit)|Encerra o programa sem usar destruidores ou funções registradas.|
|[abort](#abort)|Encerra o programa sem o uso de destruidores.|
|[atexit](#atexit)|Registra a função de encerramento do programa.|
|[exit](#exit)|Destrói os objetos com thread e o armazenamento estático, em seguida, retorna o controle.|
|[at_quick_exit](#at_quick_exit)|Registra a função sem argumentos para o encerramento do programa.|
|[quick_exit](#quick_exit)|Função de registros com objetos preservados para encerramento do programa.|
|[getenv](#getenv)|Consulte a referência da biblioteca padrão C.|
|[system](#system)|Consulte a referência da biblioteca padrão C.|

### <a name="_exit"></a> Exit

```cpp
[[noreturn]] void _Exit(int status) noexcept;
```

#### <a name="remarks"></a>Comentários

O programa é encerrado sem executar os destruidores para objetos de automático, thread ou duração de armazenamento estático e sem chamar as funções transmitidas para `atexit()`. A função `_Exit` é sinal-safe.

### <a name="abort"></a> Anular

```cpp
[[noreturn]] void abort() noexcept;
```

#### <a name="remarks"></a>Comentários

O programa é encerrado sem executar os destruidores para objetos de automático, thread ou duração de armazenamento estático e sem chamar as funções transmitidas para `atexit()`. A função `abort` é sinal-safe.

### <a name="at_quick_exit"></a> at_quick_exit

```cpp
int at_quick_exit(c-atexit-handler * func) noexcept;
int at_quick_exit(atexit-handler * func) noexcept;
```

#### <a name="return-value"></a>Valor de retorno

Zero se o registro terá êxito, diferente de zero se ele falhar.

#### <a name="remarks"></a>Comentários

O `at_quick_exit()` funções de registram a função apontada por *func* a ser chamado sem argumentos quando `quick_exit` é chamado. Ele tem não for especificado se uma chamada para `at_quick_exit()` que não acontece antes de todas as chamadas para `quick_exit` terá êxito e o `at_quick_exit()` funções não introduzem uma corrida de dados. A ordem de registro pode ser indeterminada se `at_quick_exit` foi chamado de mais de um thread e desde `at_quick_exit` registros são distintos do `atexit` registros, aplicativos podem precisar chamar ambas as funções de registro com o mesmo argumento. A implementação deve aceitar o registro das funções de pelo menos 32.

### <a name="atexit"></a> atexit

```cpp
int atexit(c-atexit-handler * func) noexcept;
int atexit(atexit-handler * func) noexcept;
```

#### <a name="remarks"></a>Comentários

O `atexit()` funções de registram a função apontada por *func* a ser chamado sem argumentos no encerramento do programa normal. Ele tem não for especificado se uma chamada para `atexit()` que não acontece antes de uma chamada para `exit()` terá êxito e o `atexit()` funções não introduzem uma corrida de dados. A implementação deve aceitar o registro das funções de pelo menos 32.

#### <a name="return-value"></a>Valor de retorno

Retorna zero se o registro terá êxito, diferente de zero se ele falhar.

### <a name="exit"></a> sair

```cpp
[[noreturn]] void exit(int status);
```

#### <a name="remarks"></a>Comentários

Em primeiro lugar, objetos com duração de armazenamento de thread e associados ao atual thread são destruídos.

Em seguida, com duração de armazenamento estático, os objetos são destruídos e funções registradas por meio da chamada `atexit` são chamados. Objetos automáticos não são destruídos como resultado da chamada `exit()`. Se o controle sai de uma função registrada chamada pelo `exit` porque a função não fornece um manipulador para uma exceção lançada, `std::terminate()` deverá ser chamado. Uma função é chamada para toda vez que ele está registrado. Objetos com duração de armazenamento automático são todos destruídos em um programa cuja função principal não contém nenhum objetos automáticos e executa a chamada para `exit()`. Controle pode ser transferido diretamente para uma função principal, lançando uma exceção que é detectada em main.

Em seguida, todos os fluxos de C, abra (como mediadas pelas assinaturas de função declaradas em <cstdio>) com dados armazenados em buffer não gravados são liberada, todos os fluxos de C são fechados e todos os arquivos criados chamando `tmpfile()` são removidos.

Por fim, o controle é retornado para o ambiente de host. Se o status for zero ou EXIT_SUCCESS, um formulário definido pela implementação do término bem-sucedido status será retornado. Se o status for EXIT_FAILURE, um formulário definido pela implementação do encerramento malsucedida status será retornado. Caso contrário, o status retornado é definido pela implementação.

### <a name="getenv"></a> GETENV

```cpp
char* getenv(const char* name);
```

### <a name="quick_exit"></a> quick_exit

```cpp
[[noreturn]] void quick_exit(int status) noexcept;
```

#### <a name="remarks"></a>Comentários

Funções registradas por chamadas para `at_quick_exit` são chamados na ordem inversa de seu registro, exceto que uma função deverá ser chamada depois que qualquer registrado anteriormente funções que já foi chamadas no momento em que ele foi registrado. Objetos não deverão ser destruídos como resultado da chamada `quick_exit`. Se o controle sai de uma função registrada chamada pelo `quick_exit` porque a função não fornece um manipulador para uma exceção lançada, `std::terminate()` deverá ser chamado. Uma função registrada por meio `at_quick_exit` é invocado pelo thread que chama `quick_exit`, que pode ser um thread diferente do que aquele que registrá-lo, portanto, registrado funções não deve confiar na identidade de objetos com duração de armazenamento de thread. Depois de chamar funções registradas, `quick_exit` deve ser chamado de `_Exit(status)`. Os buffers de arquivo padrão não são liberados. A função `quick_exit` é o sinal seguro quando as funções registradas com `at_quick_exit` são.

### <a name="system"></a> Sistema

```cpp
int system(const char* string);
```

## <a name="memory-allocation-functions"></a>Funções de alocação de memória

```cpp
void* aligned_alloc(size_t alignment, size_t size);
void* calloc(size_t nmemb, size_t size);
void free(void* ptr);
void* malloc(size_t size);
void* realloc(void* ptr, size_t size);
double atof(const char* nptr);
int atoi(const char* nptr);
long int atol(const char* nptr);
long long int atoll(const char* nptr);
double strtod(const char* nptr, char** endptr);
float strtof(const char* nptr, char** endptr);
long double strtold(const char* nptr, char** endptr);
long int strtol(const char* nptr, char** endptr, int base);
long long int strtoll(const char* nptr, char** endptr, int base);
unsigned long int strtoul(const char* nptr, char** endptr, int base);
unsigned long long int strtoull(const char* nptr, char** endptr, int base);
```

#### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca C padrão.

##  <a name="multibyte--wide-string-and-character-conversion-functions"></a>Cadeia de caracteres multibyte / ampla e funções de conversão de caractere

```cpp
int mblen(const char* s, size_t n);
int mbtowc(wchar_t* pwc, const char* s, size_t n);
int wctomb(char* s, wchar_t wchar);
size_t mbstowcs(wchar_t* pwcs, const char* s, size_t n);
size_t wcstombs(char* s, const wchar_t* pwcs, size_t n);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca C padrão.

## <a name="algorithm-functions"></a>Funções de algoritmo

```cpp
void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, c-compare-pred * compar);
void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, compare-pred * compar);
void qsort(void* base, size_t nmemb, size_t size, c-compare-pred * compar);
void qsort(void* base, size_t nmemb, size_t size, compare-pred * compar);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca C padrão.

## <a name="low-quality-random-number-generation-functions"></a>Funções geração de números aleatórios baixa qualidade

```cpp
int rand();
void srand(unsigned int seed);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca C padrão.

## <a name="absolute-values"></a>Valores absolutos

```cpp
int abs(int j);
long int abs(long int j);
long long int abs(long long int j);
float abs(float j);
double abs(double j);
long double abs(long double j);
long int labs(long int j);
long long int llabs(long long int j);
div_t div(int numer, int denom);
ldiv_t div(long int numer, long int denom);
lldiv_t div(long long int numer, long long int denom);
ldiv_t ldiv(long int numer, long int denom);
lldiv_t lldiv(long long int numer, long long int denom);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca C padrão.

## <a name="functions"></a>Funções

```cpp
void* bsearch(const void* key, const void* base, size_t nmemb, size_t size,
c-compare-pred * compar);
void* bsearch(const void* key, const void* base, size_t nmemb, size_t size,
compare-pred * compar);
void qsort(void* base, size_t nmemb, size_t size, c-compare-pred * compar);
void qsort(void* base, size_t nmemb, size_t size, compare-pred * compar);
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
