---
title: C++arquivos de cabeçalho de biblioteca padrão
ms.date: 07/12/2019
helpviewer_keywords:
- header files, C++ Standard Library
- C++ Standard Library, header files
ms.assetid: e7bf497a-0f63-48d0-9b54-cb0eef4073c4
ms.openlocfilehash: dc337ef078108d86849aa7b7452512dfb69e6e18
ms.sourcegitcommit: 0867d648e0955ebad7260b5fbebfd6cd4d58f3c7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/19/2019
ms.locfileid: "68341131"
---
# <a name="c-standard-library-header-files"></a>C++arquivos de cabeçalho de biblioteca padrão

Arquivos de cabeçalho para C++ a biblioteca padrão e extensões, por categoria.

## <a name="headers-by-category"></a>Cabeçalhos por categoria

::: moniker range=">=vs-2017"

| Categoria | Cabeçalhos |
| - | - |
| [Algoritmos](../cpp/algorithms-modern-cpp.md) | algoritmo > [, cstdlib>\<](cstdlib.md), [ numeric\<>](numeric.md) [ \<](algorithm.md) |
| Operações atômicas |  > atômica<sup>11</sup> [ \<](atomic.md) |
| Invólucros da biblioteca C | [ \<](cfenv.md)<sup></sup> [ \<](cerrno.md) [ \<cassert >](cctype.md), [ccomplex > 11 a b, cctype >, cerrno >, cfenv > 11, \<](ccomplex.md) [ \<](cassert.md)<sup></sup> [ \<cfloat >](cfloat.md),<sup></sup> [ \<cinttypes >](cinttypes.md)11, [ \<ciso646 >](ciso646.md)<sup>b</sup>, [ \<climits >](climits.md), [ \<clocale >](clocale.md), [ cmath\<>](cmath.md), [ csetjmp>,csignal>,cstdalign>11ab,cstdarg>,\<](csetjmp.md) [ \<](cstdarg.md) [ \<](csignal.md) [ \<](cstdalign.md)<sup></sup> [ \<cstdbool >](cstdbool.md)<sup>11 b</sup>, [ \<cstddef >](cstddef.md), [ \<cstdint >](cstdint.md)<sup>11</sup>, [ \<cstdio >](cstdio.md), [ \<cstdlib >](cstdlib.md), [ CString\<>](cstring.md),<sup></sup> [ \<](ctime.md)<sup></sup> [ \<](cuchar.md) [ \<](cwchar.md) [ ctgmath>11\<](ctgmath.md)a b, CTime >, cuchar > 11, cwchar >, [ >\<cwctype](cwctype.md) |
| Conceitos | \<conceitos ><sup>20</sup> |
| [Contêineres](../cpp/containers-modern-cpp.md) | |
| Contêineres de sequência | <sup></sup><sup></sup> [ array\<>](array.md)11, [ deque>,forward_list>11,>delista,vetor>\<](deque.md) [ \<](vector.md) [ \<](forward-list.md) [ \<](list.md) |
| Contêineres de associação ordenada| [\<map>](map.md), [\<set>](set.md) |
| Contêineres associativos não ordenados | unordered_map ><sup>11</sup>, [ unordered_set>\<](unordered-set.md)<sup>11</sup> [ \<](unordered-map.md) |
| Adaptadores de contêiner | [\<queue>](queue.md), [\<stack>](stack.md) |
| Exibições de contêiner | \<> de span<sup>20</sup> |
| [Erros e tratamento de exceção](../cpp/errors-and-exception-handling-modern-cpp.md) | <sup></sup> [ cassert\<>](cassert.md) [, Exception\<>](exception.md) [, stdexcept\<>](stdexcept.md) [, system_error\<>](system-error.md)11 |
| Utilitários gerais | \<qualquer ><sup>17</sup>, [ \<conjunto >](bitset.md), \<charconv ><sup>17</sup>, [ \<cstdlib >](cstdlib.md), \<execução ><sup>17</sup>, [ \<funcional >](functional.md), [ memória\<>](memory.md), \< [ \<](ratio.md)<sup></sup><sup></sup><sup></sup>memory_resource > 17, opcional > 17, Ratio > 11, scoped_allocator > \< [ \< ](scoped-allocator.md) <sup>11</sup>,<sup></sup><sup></sup><sup></sup> [ tupla\<>](tuple.md)11, [ type_traits>11,typeindex>11,utilitário>,\<](type-traits.md) [ \<](typeindex.md) [ \<](utility.md) \<variante ><sup>17</sup> |
| [E/s e formatação](../cpp/string-and-i-o-formatting-modern-cpp.md) | <sup></sup><sup></sup> [ cinttypes\<>](cinttypes.md)11, [ cstdio>,FileSystem>17,fstream>,iomanip>,\<](cstdio.md) [ \<](filesystem.md) [ \<](fstream.md) [ \<](iomanip.md) [ Ios\<>](ios.md), [ iosfwd>,iostream>,IStream>,ostream>,sstream>\<](iosfwd.md) [ \<](iostream.md) [ \<](istream.md) [ \<](ostream.md) [ \<](sstream.md) \< [ ,\<streambuf >](streambuf.md) [ ,\<strstream >](strstream.md)<sup>c</sup>, syncstream ><sup>20</sup> |
| Iterators | [\<iterator>](iterator.md) |
| Suporte a linguagens | \< \< \< <sup></sup><sup></sup><sup></sup> [ cfloat\<>](cfloat.md) [, climits\<>](climits.md) [, codecvt\<>](codecvt.md)11 a, comparar > 20, contrato > 20, > de corrotinas<sup>20</sup>, [ \<csetjmp >](csetjmp.md), [ \<csignal >](csignal.md), [ \<cstdarg >](cstdarg.md), [ \<cstddef >](cstddef.md), [ \<cstdint > ](cstdint.md) <sup>11</sup><sup></sup> [, cstdlib\<>](cstdlib.md) [, Exception\<>](exception.md) [, initializer_list\<>](initializer-list.md)11 [, Limits>,\<](limits.md) [ \< novos >](new.md), [ \<TypeInfo >](typeinfo.md), \<versão ><sup>20</sup> |
| Localização | [ \<](locale.md) <sup></sup> [ clocale>\<](cvt-wbuffer.md), [codecvt > 11 a, CVT/wbuffer >, CVT/wstring >, localidade > \<](codecvt.md) [ \<](cvt-wstring.md) [ \<](clocale.md) |
| Matemática e numéricos | \<bit ><sup>20</sup>, [ \<cfenv >](cfenv.md)<sup>11</sup>, [ \<cmath >](cmath.md), [ \<Complex >](complex.md), [ \<cstdlib >](cstdlib.md), [ \<Limits >](limits.md), [ >\<](numeric.md)numéricos [ ,\<Random >](random.md)<sup>11</sup>, [ \<proporção >](ratio.md)<sup>11</sup>, [ \<valarray >](valarray.md) |
| [Gerenciamento de memória](../cpp/smart-pointers-modern-cpp.md) | \< [ \<](new.md) [ \<](scoped-allocator.md)<sup></sup> [ \<](memory.md)<sup></sup> alocadores >, > de memória, memory_resource > 17, novo >, scoped_allocator > 11 [ \<](allocators-header.md) |
| Multithreading | <sup></sup><sup></sup><sup></sup><sup></sup> [ Atomic\<>](atomic.md)11, [ CONDITION_VARIABLE>11,futuro>11,mutex>11,\<](condition-variable.md) [ \<](future.md) [ \<](mutex.md) [ \< shared_mutex >](shared-mutex.md)<sup>14</sup>, [ \<thread >](thread.md)<sup>11</sup> |
| Intervalos | \<intervalos de ><sup>20</sup> |
| Expressões regulares | Regex ><sup>11</sup> [ \<](regex.md) |
| Cadeias de caracteres e dados de caractere | <sup></sup> [ cctype\<>](cctype.md), [ cstdlib>,CString>,cuchar>11,cwchar>,cwctype\<](cstdlib.md) [ \<](cstring.md) [ \<](cuchar.md) [ \<](cwchar.md) [ \< >](cwctype.md) [ ,\<Regex >](regex.md)<sup>11</sup>, [ \<cadeia de caracteres >](string.md), [ \<string_view >](string-view.md)<sup>17</sup> |
| Hora | Chrono ><sup>11</sup>, [ CTime\<>](ctime.md) [ \<](chrono.md) |

<sup>11</sup> adicionado no padrão c++ 11.
<sup>14</sup> adicionado no padrão c++ 14. \
<sup>17</sup> adicionado no padrão c++ 17. \
<sup>20</sup> adicionados no padrão de rascunho de c++ 20. \
<sup>um</sup> preterido no padrão c++ 17. \
<sup>b</sup> removido no rascunho de c++ 20 padrão. \
<sup>c</sup> preterido no padrão c++ 98.

::: moniker-end

::: moniker range="vs-2015"

|Categoria|Cabeçalhos|
|-|-|
|[Algoritmos](../cpp/algorithms-modern-cpp.md)|[\<algorithm>](algorithm.md)|
|Invólucros da biblioteca C|[\<cassert>](cassert.md), [\<cctype>](cctype.md), [\<cerrno>](cerrno.md), [\<cfenv>](cfenv.md), [\<cfloat>](cfloat.md), [\<cinttypes>](cinttypes.md), [\<ciso646>](ciso646.md), [\<climits>](climits.md), [\<clocale>](clocale.md), [\<cmath>](cmath.md), [\<csetjmp>](csetjmp.md), [\<csignal>](csignal.md), [\<cstdarg>](cstdarg.md), [\<cstdbool>](cstdbool.md), [\<cstddef>](cstddef.md), [\<cstdint>](cstdint.md), [\<cstdio>](cstdio.md), [\<cstdlib>](cstdlib.md), [\<cstring>](cstring.md), [\<ctgmath>](ctgmath.md), [\<ctime>](ctime.md), [\<cwchar>](cwchar.md), [\<cwctype>](cwctype.md)|
|[Contêineres](../cpp/containers-modern-cpp.md)||
|Contêineres de sequência|[ matriz>\<](vector.md) , [deque >, forward_list >, > de lista, vetor > \<](deque.md) [ \<](array.md) [ \<](forward-list.md) [ \<](list.md)|
|Contêineres de associação ordenada| [\<map>](map.md), [\<set>](set.md)|
|Contêineres associativos não ordenados|unordered_map >, [ \<](unordered-map.md) [ unordered_set>\<](unordered-set.md)|
|Contêineres do adaptador|[\<queue>](queue.md), [\<stack>](stack.md)|
|[Erros e tratamento de exceção](../cpp/errors-and-exception-handling-modern-cpp.md)|exceção > [, stdexcept>\<](stdexcept.md), [ system_error\<>](system-error.md) [ \<](exception.md)|
|[E/s e formatação](../cpp/string-and-i-o-formatting-modern-cpp.md)|[\<filesystem>](filesystem.md), [\<fstream>](fstream.md), [\<iomanip>](iomanip.md), [\<ios>](ios.md), [\<iosfwd>](iosfwd.md), [\<iostream>](iostream.md), [\<istream>](istream.md), [\<ostream>](ostream.md), [\<sstream>](sstream.md), [\<streambuf>](streambuf.md), [\<strstream>](strstream.md)|
|Iterators|[\<iterator>](iterator.md)|
|Localização|[\<codecvt>](codecvt.md), [\<cvt/wbuffer>](cvt-wbuffer.md), [\<cvt/wstring>](cvt-wstring.md), [\<locale>](locale.md)|
|Matemática e numéricos|[\<complex>](complex.md), [\<limits>](limits.md), [\<numeric>](numeric.md), [\<random>](random.md), [\<ratio>](ratio.md), [\<valarray>](valarray.md)|
|[Gerenciamento de memória](../cpp/smart-pointers-modern-cpp.md)|alocadores >, [ \<> de memória](memory.md), [ \<novo >](new.md), [ \<scoped_allocator >](scoped-allocator.md) [ \<](allocators-header.md)|
|Multithreading|[ >\<atômico](atomic.md), [ CONDITION_VARIABLE>,>futuro,>mutex,shared_mutex>,thread\<](condition-variable.md) [ \<](future.md) [ \<](mutex.md) [ \<](shared-mutex.md) [ \< >](thread.md)|
|Outros utilitários|[ conjunto\<>](bitset.md), [ Chrono>,>funcional,initializer_list>,tupla>,type_traits\<](chrono.md) [ \<](functional.md) [ \<](initializer-list.md) [ \<](tuple.md) [ \< >](type-traits.md) [ ,\<TypeInfo >](typeinfo.md), [ \<typeindex >](typeindex.md), [ \<utilitário >](utility.md)|
|Cadeias de caracteres e dados de caractere|[\<regex>](regex.md), [\<string>](string.md), [\<string_view>](string-view.md)

::: moniker-end

## <a name="see-also"></a>Consulte também

[Usando C++ cabeçalhos de biblioteca](using-cpp-library-headers.md)\
[C++biblioteca padrão](cpp-standard-library-reference.md)
