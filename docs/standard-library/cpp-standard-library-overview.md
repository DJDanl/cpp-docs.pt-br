---
title: Visão geral da Biblioteca Padrão C++
ms.date: 11/04/2016
helpviewer_keywords:
- headers, C++ library
- C++ Standard Library
- libraries, Standard C++
- C++ Standard Library, headers
ms.assetid: 7acb83a4-da73-4ad3-bc30-a71289db7f60
ms.openlocfilehash: e4d49b01f9602d5e6d7316a3a258ffa69bbcc369
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88839030"
---
# <a name="c-standard-library-overview"></a>Visão geral da Biblioteca Padrão C++

Todas as entidades da biblioteca C++ são declaradas ou definidas em um ou mais cabeçalhos padrão. Essa implementação inclui dois cabeçalhos adicionais, \<hash_map> e \<hash_set>, que não são necessários no Padrão C++. Para obter uma lista completa de cabeçalhos para os quais essa implementação dá suporte, consulte [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md).

Uma implementação independente da biblioteca C++ fornece apenas um subconjunto destes cabeçalhos:

[\<cstdarg>](../standard-library/cstdarg.md)\
[\<cstddef>](../standard-library/cstddef.md)\
[\<cstdlib>](../standard-library/cstdlib.md) (declarando pelo menos as funções `abort` , `atexit` e `exit` ) \
[\<exception>](../standard-library/exception.md)\
[\<limits>](../standard-library/limits.md)\
[\<new>](../standard-library/new.md)

Os cabeçalhos da biblioteca C++ têm duas subdivisões mais amplas:

- convenções de [iostreams](../standard-library/iostreams-conventions.md) .

- Convenções da [Referência da Biblioteca Padrão C++](../standard-library/cpp-standard-library-reference.md).

Esta seção contém as seguintes seções:

- [Usando cabeçalhos de biblioteca C++](../standard-library/using-cpp-library-headers.md)

- [Convenções de biblioteca C++](../standard-library/cpp-library-conventions.md)

- [Convenções de iostreams](../standard-library/iostreams-conventions.md)

- [Inicialização e encerramento do programa C++](../standard-library/cpp-program-startup-and-termination.md)

- [Bibliotecas seguras: biblioteca padrão do C++](../standard-library/safe-libraries-cpp-standard-library.md)

- [Iteradores selecionados](../standard-library/checked-iterators.md)

- [Suporte de iterador de depuração](../standard-library/debug-iterator-support.md)

- [Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)

- [Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

- [Namespace stdext](../standard-library/stdext-namespace.md)

- [Expressões regulares (C++)](../standard-library/regular-expressions-cpp.md)

Para obter mais informações sobre as bibliotecas em tempo de execução Visual C++, consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Confira também

[Biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
