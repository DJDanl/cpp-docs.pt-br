---
title: '&lt;streambuf&gt;'
ms.date: 11/04/2016
f1_keywords:
- <streambuf>
helpviewer_keywords:
- streambuf header
ms.assetid: 4365b25c-5831-488b-b9c2-867bfe961b89
ms.openlocfilehash: 1121bd4e782fca57588d05fb29b5b9b6cdec18e9
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215602"
---
# <a name="ltstreambufgt"></a>&lt;streambuf&gt;

Inclua o cabeçalho padrão iostreams \<streambuf> para definir o modelo de classe [basic_streambuf](../standard-library/basic-streambuf-class.md), que é básico para a operação das classes iostreams. Esse cabeçalho geralmente é incluído para você por outro cabeçalho iostreams, dificilmente você precisará incluí-lo diretamente.

## <a name="syntax"></a>Sintaxe

```cpp
#include <streambuf>
```

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[streambuf](../standard-library/streambuf-typedefs.md#streambuf)|Uma especialização `basic_streambuf` que **`char`** o usa como parâmetros de modelo.|
|[wstreambuf](../standard-library/streambuf-typedefs.md#wstreambuf)|Uma especialização `basic_streambuf` que **`wchar_t`** o usa como parâmetros de modelo.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe basic_streambuf](basic-streambuf-class.md)|O modelo de classe descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos de e para uma representação específica de um fluxo.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
