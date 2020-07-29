---
title: '&lt;cstdlib&gt;'
ms.date: 11/04/2016
f1_keywords:
- <cstdlib>
helpviewer_keywords:
- cstdlib header
ms.assetid: 0a6aaebf-84e9-4b60-ae90-17e11981cf54
ms.openlocfilehash: 1b20e13a43c5d223332af70a91e096cedc284a43
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87230046"
---
# <a name="ltcstdlibgt"></a>&lt;cstdlib&gt;

Inclui o cabeçalho da biblioteca padrão C \<stdlib.h> e adiciona os nomes associados ao `std` namespace. A inclusão desse cabeçalho garante que os nomes declarados usando vínculo externo no cabeçalho da biblioteca padrão C sejam declarados no `std` namespace.

> [!NOTE]
> \<stdlib.h>Não inclui o tipo **`wchar_t`** .

## <a name="requirements"></a>Requisitos

**Cabeçalho**:\<cstdlib>

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
|[sistema](#system)|Consulte referência da biblioteca padrão C.|

### <a name="_exit"></a><a name="_exit"></a>_Exit

```cpp
[[noreturn]] void _Exit(int status) noexcept;
```

#### <a name="remarks"></a>Comentários

O programa é encerrado sem executar destruidores para objetos de duração automática, de thread ou de armazenamento estático e sem chamar funções passadas para o `atexit()` . A função `_Exit` é isenta de sinal.

### <a name="abort"></a><a name="abort"></a>anular

```cpp
[[noreturn]] void abort() noexcept;
```

#### <a name="remarks"></a>Comentários

O programa é encerrado sem executar destruidores para objetos de duração automática, de thread ou de armazenamento estático e sem chamar funções passadas para o `atexit()` . A função `abort` é isenta de sinal.

### <a name="at_quick_exit"></a><a name="at_quick_exit"></a>at_quick_exit

```cpp
int at_quick_exit(c-atexit-handler * func) noexcept;
int at_quick_exit(atexit-handler * func) noexcept;
```

#### <a name="return-value"></a>Valor retornado

Zero se o registro for bem-sucedida, diferente de zero se falhar.

#### <a name="remarks"></a>Comentários

As `at_quick_exit()` funções registram uma função *Func*, que é chamada sem argumentos quando `quick_exit` é chamado. Uma chamada para `at_quick_exit()` isso não acontece antes que todas as chamadas para `quick_exit` possam não ter sucesso. As `at_quick_exit()` funções não introduzem uma corrida de dados. A ordem de registro pode ser indeterminada se `at_quick_exit` foi chamada de mais de um thread. Como os `at_quick_exit` registros são distintos dos `atexit` registros, os aplicativos podem precisar chamar ambas as funções de registro usando o mesmo argumento. O MSVC dá suporte ao registro de pelo menos funções de 32.

### <a name="atexit"></a><a name="atexit"></a>atexit

```cpp
int atexit(c-atexit-handler * func) noexcept;
int atexit(atexit-handler * func) noexcept;
```

#### <a name="remarks"></a>Comentários

As `atexit()` funções registram a função apontada por *Func* para ser chamada sem argumentos no término normal do programa. Uma chamada para `atexit()` isso não acontece antes que uma chamada para `exit()` não seja realizada com sucesso. As `atexit()` funções não introduzem uma corrida de dados.

#### <a name="return-value"></a>Valor retornado

Retornará zero se o registro tiver êxito, diferente de zero se falhar.

### <a name="exit"></a><a name="exit"></a>sido

```cpp
[[noreturn]] void exit(int status);
```

#### <a name="remarks"></a>Comentários

Primeiro, os objetos com duração de armazenamento de threads e associados ao thread atual são destruídos.

Em seguida, os objetos com duração de armazenamento estático são destruídos e as funções registradas pela chamada `atexit` são chamadas. Os objetos automáticos não são destruídos quando `exit()` é chamado. Se o controle deixar uma função registrada chamada por `exit` porque a função não fornece um manipulador para uma exceção gerada, `std::terminate()` será chamado. Uma função é chamada uma vez para cada vez que é registrada. Os objetos com duração de armazenamento automático são todos destruídos em um programa cuja `main` função não contém objetos automáticos e executa a chamada para `exit()` . O controle pode ser transferido diretamente para tal `main` função, lançando uma exceção que é capturada `main` .

Em seguida, todos os fluxos C abertos (conforme mediado pelas assinaturas de função declaradas em \<cstdio> ) com dados armazenados em buffer não gravados são liberados, todos os fluxos de C abertos são fechados e todos os arquivos criados pela chamada `tmpfile()` são removidos.

Por fim, o controle é retornado para o ambiente de host. Quando o *status* for zero ou EXIT_SUCCESS, será retornada uma forma definida pela implementação do status êxito do encerramento. MSVC retorna um valor de zero. Se o *status* for EXIT_FAILURE, MSVC retornará um valor de 3. Caso contrário, MSVC retornará o valor do parâmetro *status* .

### <a name="getenv"></a><a name="getenv"></a>getenv

```cpp
char* getenv(const char* name);
```

### <a name="quick_exit"></a><a name="quick_exit"></a>quick_exit

```cpp
[[noreturn]] void quick_exit(int status) noexcept;
```

#### <a name="remarks"></a>Comentários

Geralmente, as funções registradas por chamadas para `at_quick_exit` são chamadas na ordem inversa de seu registro. Esta ordem não se aplica a funções registradas depois que outras funções registradas já foram chamadas. Nenhum objeto é destruído quando `quick_exit` é chamado. Se o controle deixar uma função registrada chamada por `quick_exit` porque a função não fornece um manipulador para uma exceção gerada, `std::terminate()` será chamado. Uma função registrada via `at_quick_exit` é invocada pelo thread que chama `quick_exit` , que pode ser um thread diferente daquele que o registrou. Isso significa que as funções registradas não devem contar com a identidade de objetos que têm duração de armazenamento de threads. Depois de chamar as funções registradas, `quick_exit` chame `_Exit(status)` . Os buffers de arquivo padrão não são liberados. A função `quick_exit` é isenta de sinal quando as funções registradas com o `at_quick_exit` são.

### <a name="system"></a><a name="system"></a>sistema

```cpp
int system(const char* string);
```

## <a name="memory-allocation-functions"></a>Funções de alocação de memória

```cpp
// void* aligned_alloc(size_t alignment, size_t size); // Unsupported in MSVC
void* calloc(size_t nmemb, size_t size);
void free(void* ptr);
void* malloc(size_t size);
void* realloc(void* ptr, size_t size);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca padrão C. MSVC não dá suporte à `aligned_alloc` função. C11 especificado de `aligned_alloc()` forma incompatível com a implementação da Microsoft de `free()` , ou seja, que `free()` deve ser capaz de lidar com alocações altamente alinhadas.

## <a name="numeric-string-conversions"></a>Conversões de cadeia de caracteres numéricas

```cpp
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

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca padrão C.

## <a name="multibyte--wide-string-and-character-conversion-functions"></a>Funções de conversão de caracteres e cadeia de caracteres multibyte/largo

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
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca padrão C.

## <a name="integer-division"></a>Divisão de inteiros

```cpp
div_t div(int numer, int denom);
ldiv_t div(long int numer, long int denom);
lldiv_t div(long long int numer, long long int denom);
ldiv_t ldiv(long int numer, long int denom);
lldiv_t lldiv(long long int numer, long long int denom);
```

### <a name="remarks"></a>Comentários

Essas funções têm a semântica especificada na biblioteca padrão C.

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Visão geral da biblioteca padrão do C++](../standard-library/cpp-standard-library-overview.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
