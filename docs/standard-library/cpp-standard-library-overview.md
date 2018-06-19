---
title: Visão geral da Biblioteca Padrão C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- headers, C++ library
- C++ Standard Library
- libraries, Standard C++
- C++ Standard Library, headers
ms.assetid: 7acb83a4-da73-4ad3-bc30-a71289db7f60
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2795ab431930627160b0275866b573aff36bb97b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33845314"
---
# <a name="c-standard-library-overview"></a>Visão geral da Biblioteca Padrão C++

Todas as entidades da biblioteca C++ são declaradas ou definidas em um ou mais cabeçalhos padrão. Esta implementação inclui dois cabeçalhos adicionais, \<hash_map > e \<hash_set >, que não são exigidas pelo C++ padrão. Para obter uma lista completa de cabeçalhos para os quais essa implementação dá suporte, consulte [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md).

Uma implementação independente da biblioteca C++ fornece apenas um subconjunto destes cabeçalhos:

|||
|-|-|
|[\<cstddef>](../standard-library/cstddef.md)|[\<cstdlib>](../standard-library/cstdlib.md) (declarando, pelo menos, as funções `abort`, `atexit` e `exit`)|
|[\<exception>](../standard-library/exception.md)|[\<limits>](../standard-library/limits.md)|
|[\<new>](../standard-library/new.md)|[\<cstdarg>](../standard-library/cstdarg.md)|

Os cabeçalhos da biblioteca C++ têm duas subdivisões mais amplas:

- Convenções de [iostreams](../standard-library/iostreams-conventions.md).

- Convenções da [Referência da Biblioteca Padrão C++](../standard-library/cpp-standard-library-reference.md).

Esta seção contém as seguintes seções:

- [Usando cabeçalhos da Biblioteca C++](../standard-library/using-cpp-library-headers.md)

- [Convenções da Biblioteca C++](../standard-library/cpp-library-conventions.md)

- [Convenções de iostreams](../standard-library/iostreams-conventions.md)

- [Inicialização e encerramento do programa em C++](../standard-library/cpp-program-startup-and-termination.md)

- [Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)

- [Iteradores verificados](../standard-library/checked-iterators.md)

- [Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)

- [Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)

- [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

- [Namespace stdext](../standard-library/stdext-namespace.md)

- [Expressões Regulares (C++)](../standard-library/regular-expressions-cpp.md)

Para obter mais informações sobre as bibliotecas em tempo de execução Visual C++, consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)<br/>
