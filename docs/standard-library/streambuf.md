---
title: '&lt;streambuf&gt;'
ms.date: 11/04/2016
f1_keywords:
- <streambuf>
helpviewer_keywords:
- streambuf header
ms.assetid: 4365b25c-5831-488b-b9c2-867bfe961b89
ms.openlocfilehash: ca5f53d67bb32e59c20d1d440879144f0a617c66
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72686019"
---
# <a name="ltstreambufgt"></a>&lt;streambuf&gt;

Inclua o cabeçalho padrão iostreams \<streambuf > para definir o modelo de classe [basic_streambuf](../standard-library/basic-streambuf-class.md), que é básico para a operação das classes iostreams. Esse cabeçalho geralmente é incluído para você por outro cabeçalho iostreams, dificilmente você precisará incluí-lo diretamente.

## <a name="syntax"></a>Sintaxe

```cpp
#include <streambuf>
```

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[streambuf](../standard-library/streambuf-typedefs.md#streambuf)|Uma especialização de `basic_streambuf` que usa **Char** como parâmetros de modelo.|
|[wstreambuf](../standard-library/streambuf-typedefs.md#wstreambuf)|Uma especialização de `basic_streambuf` que usa **wchar_t** como os parâmetros de modelo.|

### <a name="classes"></a>Classes

|Class|Descrição|
|-|-|
|[Classe basic_streambuf](basic-streambuf-class.md)|O modelo de classe descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos de e para uma representação específica de um fluxo.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
