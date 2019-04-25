---
title: '&lt;fstream&gt;'
ms.date: 11/04/2016
f1_keywords:
- <fstream>
helpviewer_keywords:
- fstream header
ms.assetid: 660de351-0489-41df-b239-40e0cdcab46b
ms.openlocfilehash: 20efdc755b7f706fc6ee962daa32bd352df39d45
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62159763"
---
# <a name="ltfstreamgt"></a>&lt;fstream&gt;

Define várias classes que dão suporte a operações de iostreams em sequências armazenadas em arquivos externos.

## <a name="syntax"></a>Sintaxe

```cpp
#include <fstream>
```

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[filebuf](../standard-library/fstream-typedefs.md#filebuf)|Um tipo `basic_filebuf` especializado em **char** parâmetros de modelo.|
|[fstream](../standard-library/fstream-typedefs.md#fstream)|Um tipo `basic_fstream` especializado em **char** parâmetros de modelo.|
|[ifstream](../standard-library/fstream-typedefs.md#ifstream)|Um tipo `basic_ifstream` especializado em **char** parâmetros de modelo.|
|[ofstream](../standard-library/fstream-typedefs.md#ofstream)|Um tipo `basic_ofstream` especializado em **char** parâmetros de modelo.|
|[wfstream](../standard-library/fstream-typedefs.md#wfstream)|Um tipo `basic_fstream` especializado em **wchar_t** parâmetros de modelo.|
|[wifstream](../standard-library/fstream-typedefs.md#wifstream)|Um tipo `basic_ifstream` especializado em **wchar_t** parâmetros de modelo.|
|[wofstream](../standard-library/fstream-typedefs.md#wofstream)|Um tipo `basic_ofstream` especializado em **wchar_t** parâmetros de modelo.|
|[wfilebuf](../standard-library/fstream-typedefs.md#wfilebuf)|Um tipo `basic_filebuf` especializado em **wchar_t** parâmetros de modelo.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[basic_filebuf](../standard-library/basic-filebuf-class.md)|A classe de modelo descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características dos caracteres são determinadas pela classe `Tr`, para e de uma sequência de elementos armazenados em um arquivo externo.|
|[basic_fstream](../standard-library/basic-fstream-class.md)|A classe de modelo descreve um objeto que controla a inserção e extração de elementos e objetos codificados usando um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)\<**Elem**,  **TR**>, com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`.|
|[basic_ifstream](../standard-library/basic-ifstream-class.md)|A classe de modelo descreve um objeto que controla a extração de elementos e objetos codificados de um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)\<**Elem**, **Tr**>, com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`.|
|[basic_ofstream](../standard-library/basic-ofstream-class.md)|A classe de modelo descreve um objeto que controla a inserção de elementos e objetos codificados em um buffer de fluxo da classe [basic_filebuf](../standard-library/basic-filebuf-class.md)\<**Elem**, **Tr**>, com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
