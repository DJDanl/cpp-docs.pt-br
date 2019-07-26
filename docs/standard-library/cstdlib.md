---
title: '&lt;cstdlib&gt;'
ms.date: 11/04/2016
f1_keywords:
- <cstdlib>
helpviewer_keywords:
- cstdlib header
ms.assetid: 0a6aaebf-84e9-4b60-ae90-17e11981cf54
ms.openlocfilehash: 298d6a512b2863a326bda0670f33fe8f1bda0688
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68449403"
---
# <a name="ltcstdlibgt"></a>&lt;cstdlib&gt;

Inclui o cabeçalho \<de biblioteca padrão C STDLIB. h > e adiciona os nomes associados `std` ao namespace. A inclusão desse cabeçalho garante que os nomes declarados usando vínculo externo no cabeçalho da biblioteca padrão C sejam `std` declarados no namespace.

> [!NOTE]
> \<stdlib. h > não inclui o tipo **wchar_t**.

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<cstdlib >

**Namespace:** std

## <a name="namespace-and-macros"></a>Namespace e macros

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

## <a name="exposition-only-functions"></a>Funções somente exposição

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
|[abort](#abort)|Encerra o programa sem usar destruidores.|
|[atexit](#atexit)|Registra a função para o encerramento do programa.|
|[exit](#exit)|Destrói objetos com thread e armazenamento estático e, em seguida, retorna o controle.|
|[at_quick_exit](#at_quick_exit)|Registra a função sem argumentos para o encerramento do programa.|
|[quick_exit](#quick_exit)|Registra a função com objetos preservados para o encerramento do programa.|
|[getenv](#getenv)|Consulte referência da biblioteca padrão C.|
|[system](#system)|Consulte referência da biblioteca padrão C.|

### <a name="_exit"></a>_Exit

```cpp
[[noreturn]] void _Exit(int status) noexcept;
```

#### <a name="remarks"></a>Comentários

O programa é encerrado sem executar destruidores para objetos de duração automática, de thread ou de armazenamento estático e sem chamar funções `atexit()`passadas para o. A função `_Exit` é isenta de sinal.

### <a name="abort"></a>anular

```cpp
[[noreturn]] void abort() noexcept;
```

#### <a name="remarks"></a>Comentários

O programa é encerrado sem executar destruidores para objetos de duração automática, de thread ou de armazenamento estático e sem chamar funções `atexit()`passadas para o. A função `abort` é isenta de sinal.

### <a name="at_quick_exit"></a>at_quick_exit

```cpp
int at_quick_exit(c-atexit-handler * func) noexcept;
int at_quick_exit(atexit-handler * func) noexcept;
```

#### <a name="return-value"></a>Valor de retorno

Zero se o registro for bem-sucedida, diferente de zero se falhar.

#### <a name="remarks"></a>Comentários

As `at_quick_exit()` funções registram a função apontada por *Func* para ser chamada sem argumentos `quick_exit` quando é chamado. Não é especificado se uma chamada para `at_quick_exit()` isso não acontecer antes que todas as chamadas sejam `quick_exit` bem sucedidos e as `at_quick_exit()` funções não introduzam uma corrida de dados. A ordem de registro pode ser indeterminada `at_quick_exit` se foi chamada de mais de um thread e `at_quick_exit` , como os registros são distintos dos `atexit` registros, os aplicativos podem precisar chamar ambas as funções de registro com o mesmo argumento. A implementação deve dar suporte ao registro de pelo menos funções de 32.

### <a name="atexit"></a>atexit

```cpp
int atexit(c-atexit-handler * func) noexcept;
int atexit(atexit-handler * func) noexcept;
```

#### <a name="remarks"></a>Comentários

As `atexit()` funções registram a função apontada por *Func* para ser chamada sem argumentos no término normal do programa. Não é especificado se uma chamada a `atexit()` isso não acontece antes que uma chamada para `exit()` seja bem sucedido e as `atexit()` funções não introduzem uma corrida de dados. A implementação deve dar suporte ao registro de pelo menos funções de 32.

#### <a name="return-value"></a>Valor de retorno

Retornará zero se o registro tiver êxito, diferente de zero se falhar.

### <a name="exit"></a>sido

```cpp
[[noreturn]] void exit(int status);
```

#### <a name="remarks"></a>Comentários

Primeiro, os objetos com duração de armazenamento de threads e associados ao thread atual são destruídos.

Em seguida, os objetos com duração de armazenamento estático são destruídos e `atexit` as funções registradas pela chamada são chamadas. Os objetos automáticos não são destruídos como `exit()`resultado da chamada. Se o controle deixar uma função registrada `exit` chamada por porque a função não fornece um manipulador para uma exceção `std::terminate()` gerada, deverá ser chamada. Uma função é chamada para cada vez que é registrado. Os objetos com duração de armazenamento automático são todos destruídos em um programa cuja função principal não contém objetos automáticos e executa `exit()`a chamada para. O controle pode ser transferido diretamente para essa função principal, lançando uma exceção que é capturada no principal.

Em seguida, todos os fluxos C abertos (conforme mediado pelas assinaturas de função <cstdio>declaradas em) com dados armazenados em buffer não gravados são liberados, todos os fluxos de C abertos são `tmpfile()` fechados e todos os arquivos criados pela chamada são removidos.

Por fim, o controle é retornado para o ambiente de host. Se o status for zero ou EXIT_SUCCESS, será retornada uma forma definida pela implementação do término bem-sucedido do status. Se o status for EXIT_FAILURE, será retornada uma forma definida pela implementação do estado de encerramento sem êxito. Caso contrário, o status retornado será definido como implementação.

### <a name="getenv"></a>getenv

```cpp
char* getenv(const char* name);
```

### <a name="quick_exit"></a>quick_exit

```cpp
[[noreturn]] void quick_exit(int status) noexcept;
```

#### <a name="remarks"></a>Comentários

As funções registradas por `at_quick_exit` chamadas para são chamadas na ordem inversa de seu registro, exceto que uma função deve ser chamada depois de quaisquer funções previamente registradas que já tenham sido chamadas no momento em que foram registradas. Os objetos não devem ser destruídos como resultado da `quick_exit`chamada. Se o controle deixar uma função registrada `quick_exit` chamada por porque a função não fornece um manipulador para uma exceção `std::terminate()` gerada, deverá ser chamada. Uma função registrada `at_quick_exit` via é invocada pelo thread que `quick_exit`chama, que pode ser um thread diferente daquele que o registrou, portanto, as funções registradas não devem contar com a identidade de objetos com duração de armazenamento de threads. Depois de chamar as funções `quick_exit` registradas `_Exit(status)`, o deverá chamar. Os buffers de arquivo padrão não são liberados. A função `quick_exit` é isenta de sinal quando as funções registradas `at_quick_exit` com o são.

### <a name="system"></a>sistema

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

Essas funções têm a semântica especificada na biblioteca padrão C.

##  <a name="multibyte--wide-string-and-character-conversion-functions"></a>Funções de conversão de caracteres e cadeia de caracteres multibyte/largo

```cpp
int mblen(const char* s, size_t n);
int mbtowc(wchar_t* pwc, const char* s, size_t n);
int wctomb(char* s, wchar_t wchar);
size_t mbstowcs(wchar_t* pwcs, const char* s, size_t n);
size_t wcstombs(char* s, const wchar_t* pwcs, size_t n);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca padrão C.

## <a name="algorithm-functions"></a>Funções de algoritmo

```cpp
void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, c-compare-pred * compar);
void* bsearch(const void* key, const void* base, size_t nmemb, size_t size, compare-pred * compar);
void qsort(void* base, size_t nmemb, size_t size, c-compare-pred * compar);
void qsort(void* base, size_t nmemb, size_t size, compare-pred * compar);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca padrão C.

## <a name="low-quality-random-number-generation-functions"></a>Funções de geração de números aleatórios de baixa qualidade

```cpp
int rand();
void srand(unsigned int seed);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca padrão C.

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

Essas funções têm a semântica especificada na biblioteca padrão C.

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

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
