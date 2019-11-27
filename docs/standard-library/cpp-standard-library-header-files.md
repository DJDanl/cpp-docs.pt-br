---
title: C++arquivos de cabeçalho de biblioteca padrão
ms.date: 07/12/2019
helpviewer_keywords:
- header files, C++ Standard Library
- C++ Standard Library, header files
ms.assetid: e7bf497a-0f63-48d0-9b54-cb0eef4073c4
ms.openlocfilehash: 807e65c69e55d8790b77a493e4ae1878aa740557
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74305406"
---
# <a name="c-standard-library-header-files"></a>C++arquivos de cabeçalho de biblioteca padrão

Arquivos de cabeçalho para C++ a biblioteca padrão e extensões, por categoria.

## <a name="headers-by-category"></a>Cabeçalhos por categoria

::: moniker range=">=vs-2017"

| Categoria | Cabeçalhos |
| - | - |
| [Algoritmos](../cpp/algorithms-modern-cpp.md) | [> de algoritmo\<](algorithm.md), [\<cstdlib >](cstdlib.md), [\<numérico](numeric.md) > |
| Operações atômicas |  [\<atomic >](atomic.md)<sup>11</sup> |
| Invólucros da biblioteca C | [\<cassert >](cassert.md), [\<ccomplex >](ccomplex.md)<sup>11 a b</sup>, [\<cctype >](cctype.md), [\<cerrno >](cerrno.md), [\<cfenv >](cfenv.md)<sup>11</sup>, [\<cfloat >](cfloat.md), [\<cinttypes >](cinttypes.md)<sup>11</sup>, [\<ciso646 >](ciso646.md)<sup>b</sup>, [\<climits >](climits.md), [\<clocale >](clocale.md), [\<cmath >](cmath.md), [\<csetjmp >](csetjmp.md), [\<csignal >](csignal.md), [\<cstdalign >](cstdalign.md)<sup>11 b</sup>, [\<cstdarg >](cstdarg.md), [\<cstdbool >](cstdbool.md)<sup>11 a b</sup>, [\<cstddef >](cstddef.md), [\<cstdint >](cstdint.md)<sup>11</sup>, [\<cstdio >](cstdio.md), [\<cstdlib >](cstdlib.md), [\<CString >](cstring.md), [\<ctgmath >](ctgmath.md)<sup>11 a b</sup>, [\<CTime >](ctime.md), [\<cuchar >](cuchar.md)<sup>11</sup> , [\<cwchar >](cwchar.md), [\<cwctype >](cwctype.md) |
| Conceitos | conceitos de \<><sup>20</sup> |
| [Contêineres](../cpp/containers-modern-cpp.md) | |
| Contêineres de sequência | [\<matriz >](array.md)<sup>11</sup>, [\<deque >](deque.md), [\<forward_list >](forward-list.md)<sup>11</sup>, [\<List](list.md)>,\<[vetor](vector.md) > |
| Contêineres de associação ordenada| [\<map>](map.md), [\<set>](set.md) |
| Contêineres associativos não ordenados | [\<unordered_map >](unordered-map.md)<sup>11</sup>, [\<unordered_set >](unordered-set.md)<sup>11</sup> |
| Adaptadores de contêiner | [\<queue>](queue.md), [\<stack>](stack.md) |
| Exibições de contêiner | \<span ><sup>20</sup> |
| [Erros e tratamento de exceção](../cpp/errors-and-exception-handling-modern-cpp.md) | [\<cassert >](cassert.md), [\<> de exceção](exception.md), [\<stdexcept >](stdexcept.md), [\<system_error >](system-error.md)<sup>11</sup> |
| Utilitários gerais | \<qualquer ><sup>17</sup>, [\<conjunto >](bitset.md), \<charconv ><sup>17</sup>, [\<cstdlib >](cstdlib.md), \<execução ><sup>17,\<</sup> [funcional](functional.md)>,\<de [memória](memory.md)>, \<memory_resource ><sup>17</sup>, \<opcional<sup>> 17</sup>,\<[proporção](ratio.md)><sup>11</sup>, [\<scoped_allocator >](scoped-allocator.md)<sup>11</sup>, [\<tupla >](tuple.md)<sup>11</sup>, [\<type_traits >](type-traits.md)<sup>11</sup>, [\<typeindex >](typeindex.md)<sup>11</sup>, [\<Utility](utility.md)>, \<variante ><sup>17</sup> |
| [E/s e formatação](../text/string-and-i-o-formatting-modern-cpp.md) | [\<cinttypes >](cinttypes.md)<sup>11</sup>, [\<cstdio >](cstdio.md), [\<FileSystem >](filesystem.md)<sup>17</sup>, [\<fstream >](fstream.md), [\<iomanip >](iomanip.md), [\<ios >](ios.md), [\<iosfwd >](iosfwd.md), [\<iostream >](iostream.md), [\<IStream >](istream.md), [\<ostream >](ostream.md), [\<sstream >](sstream.md), [\<streambuf >](streambuf.md), [\<strstream >](strstream.md)<sup>c </sup>, \<syncstream ><sup>20</sup> |
| {1&gt;Iteradores&lt;1} | [\<iterator>](iterator.md) |
| Suporte a linguagens | [\<cfloat >](cfloat.md), [\<climits >](climits.md), [\<codecvt >](codecvt.md)<sup>11 a</sup>, \<Compare ><sup>20</sup>, \<Contract ><sup>20</sup>, \<corrotineiro ><sup>20</sup>, [\<csetjmp >](csetjmp.md), [\<csignal >](csignal.md), [\<cstdarg >](cstdarg.md), [\<cstddef >](cstddef.md), [\<cstdint >](cstdint.md)<sup>11</sup>, [\<](cstdlib.md)cstdlib >,\<[exceção](exception.md) > , [\<initializer_list >](initializer-list.md)<sup>11</sup>, [\<limites >](limits.md), [\<novo >](new.md),\<[TypeInfo >](typeinfo.md), \<versão ><sup>20</sup> |
| Localização | [\<clocale >](clocale.md), [\<codecvt >](codecvt.md)<sup>11</sup>, [\<CVT/wbuffer >](cvt-wbuffer.md), [\<CVT/wstring >](cvt-wstring.md), [\<locale](locale.md) > |
| Matemática e numéricos | \<bit ><sup>20</sup>, [\<cfenv >](cfenv.md)<sup>11</sup>, [\<cmath >](cmath.md), [\<Complex >](complex.md), [\<cstdlib >](cstdlib.md), [\<limites >](limits.md),\<[numérico](numeric.md)>, [\<Random >](random.md)<sup>11</sup>,\<[proporção >](ratio.md)<sup>11</sup>, [\<valarray >](valarray.md) |
| [Gerenciamento de memória](../cpp/smart-pointers-modern-cpp.md) | [\<alocadores >](allocators-header.md), [\<> de memória](memory.md), \<memory_resource ><sup>17</sup>, [\<novo >](new.md), [\<scoped_allocator >](scoped-allocator.md)<sup>11</sup> |
| Multithreading | [\<atomic >](atomic.md)<sup>11</sup>, [\<CONDITION_VARIABLE >](condition-variable.md)<sup>11</sup>, [\<futuro >](future.md)<sup>11</sup>, [\<mutex >](mutex.md)<sup>11</sup>, [\<shared_mutex >](shared-mutex.md)<sup>14</sup>, [\<thread >](thread.md)<sup>11</sup> |
| Intervalos | intervalos de \<><sup>20</sup> |
| Expressões regulares | [\<regex >](regex.md)<sup>11</sup> |
| Cadeias de caracteres e dados de caractere | [\<cctype >](cctype.md), [\<cstdlib >](cstdlib.md), [\<cstring >](cstring.md), [\<cuchar >](cuchar.md)<sup>11</sup>, [\<cwchar >](cwchar.md), [\<cwctype >](cwctype.md), [\<Regex >](regex.md)<sup>11</sup>, [\<String](string.md)>, [\<string_view](string-view.md)><sup>17</sup> |
| Tempo | [\<chrono >](chrono.md)<sup>11</sup>, [\<CTime >](ctime.md) |

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
|Contêineres de sequência|[\<> de matriz](array.md), [\<deque >](deque.md) [,\<forward_list >,\<](forward-list.md) [list](list.md)>,\<[vetor >](vector.md)|
|Contêineres de associação ordenada| [\<map>](map.md), [\<set>](set.md)|
|Contêineres associativos não ordenados|[\<unordered_map >](unordered-map.md), [\<unordered_set](unordered-set.md) >|
|Contêineres do adaptador|[\<queue>](queue.md), [\<stack>](stack.md)|
|[Erros e tratamento de exceção](../cpp/errors-and-exception-handling-modern-cpp.md)|[\<de exceção >](exception.md), [\<stdexcept >](stdexcept.md) [,\<system_error >](system-error.md)|
|[E/s e formatação](../text/string-and-i-o-formatting-modern-cpp.md)|[\<filesystem>](filesystem.md), [\<fstream>](fstream.md), [\<iomanip>](iomanip.md), [\<ios>](ios.md), [\<iosfwd>](iosfwd.md), [\<iostream>](iostream.md), [\<istream>](istream.md), [\<ostream>](ostream.md), [\<sstream>](sstream.md), [\<streambuf>](streambuf.md), [\<strstream>](strstream.md)|
|{1&gt;Iteradores&lt;1}|[\<iterator>](iterator.md)|
|Localização|[\<codecvt>](codecvt.md), [\<cvt/wbuffer>](cvt-wbuffer.md), [\<cvt/wstring>](cvt-wstring.md), [\<locale>](locale.md)|
|Matemática e numéricos|[\<complex>](complex.md), [\<limits>](limits.md), [\<numeric>](numeric.md), [\<random>](random.md), [\<ratio>](ratio.md), [\<valarray>](valarray.md)|
|[Gerenciamento de memória](../cpp/smart-pointers-modern-cpp.md)|[\<alocadores >](allocators-header.md), [\<> de memória](memory.md), [\<novo >](new.md), [\<scoped_allocator >](scoped-allocator.md)|
|Multithreading|[\<atomic >](atomic.md), [\<CONDITION_VARIABLE >](condition-variable.md),\<> [futuro](future.md),\<[mutex >](mutex.md), [\<shared_mutex >](shared-mutex.md),\<[thread](thread.md) >|
|Outros utilitários|[\<conjunto >](bitset.md), [\<Chrono >](chrono.md), [\<funcional >](functional.md), [\<initializer_list >](initializer-list.md),\<[tupla >](tuple.md), [\<type_traits](type-traits.md)>, [\<TypeInfo >](typeinfo.md), [\<typeindex >](typeindex.md),\<[Utility >](utility.md)|
|Cadeias de caracteres e dados de caractere|[\<regex >](regex.md), [\<cadeia de caracteres >](string.md) [,\<string_view >](string-view.md)

::: moniker-end

## <a name="see-also"></a>Consulte também

[Usando C++ cabeçalhos de biblioteca](using-cpp-library-headers.md)\
[C++biblioteca padrão](cpp-standard-library-reference.md)
