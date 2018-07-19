---
title: '&lt;streambuf&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <streambuf>
dev_langs:
- C++
helpviewer_keywords:
- streambuf header
ms.assetid: 4365b25c-5831-488b-b9c2-867bfe961b89
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 138ec5bb28e108751a7d4b03651826db38c098fa
ms.sourcegitcommit: 76fd30ff3e0352e2206460503b61f45897e60e4f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39026926"
---
# <a name="ltstreambufgt"></a>&lt;streambuf&gt;

Inclua o cabeçalho padrão iostreams \<streambuf> para definir a classe de modelo [basic_streambuf](../standard-library/basic-streambuf-class.md), que é básica para a operação das classes iostreams. Esse cabeçalho geralmente é incluído para você por outro cabeçalho iostreams, dificilmente você precisará incluí-lo diretamente.

## <a name="syntax"></a>Sintaxe

```cpp
#include <streambuf>

```

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[streambuf](../standard-library/streambuf-typedefs.md#streambuf)|Uma especialização da `basic_streambuf` que usa **char** como os parâmetros de modelo.|
|[wstreambuf](../standard-library/streambuf-typedefs.md#wstreambuf)|Uma especialização da `basic_streambuf` que usa **wchar_t** como os parâmetros de modelo.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe basic_streambuf](http://msdn.microsoft.com/d9c706ba-ce01-43e0-b0b2-a558fc53ea8d)|A classe de modelo descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos de e para uma representação específica de um fluxo.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
