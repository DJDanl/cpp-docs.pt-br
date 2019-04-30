---
title: '&lt;exception&gt;'
ms.date: 11/04/2016
f1_keywords:
- <exception>
helpviewer_keywords:
- exception header
ms.assetid: 28900768-5dd7-4834-b907-5e37ab3407db
ms.openlocfilehash: e599a725feb46eaa90023fdb9c999f5b2d159637
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62412625"
---
# <a name="ltexceptiongt"></a>&lt;exception&gt;

Define vários tipos e funções relacionados ao tratamento de exceções. O tratamento de exceções é usado em situações nas quais o sistema pode se recuperar de um erro. Ele fornece um meio de o controle ser retornado de uma função para o programa. O objetivo de incorporar o tratamento de exceções é aumentar a robustez do programa e, ao mesmo tempo, fornecer um meio de se recuperar de um erro de maneira organizada.

## <a name="syntax"></a>Sintaxe

```cpp
#include <exception>
```

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[exception_ptr](../standard-library/exception-typedefs.md#exception_ptr)|Um tipo que descreve um ponteiro para uma exceção.|
|[terminate_handler](../standard-library/exception-typedefs.md#terminate_handler)|Um tipo que descreve um ponteiro para uma função adequada para uso como um `terminate_handler`.|
|[unexpected_handler](../standard-library/exception-typedefs.md#unexpected_handler)|Um tipo que descreve um ponteiro para uma função adequada para uso como um `unexpected_handler`.|

### <a name="functions"></a>Funções

|Função|Descrição|
|-|-|
|[current_exception](../standard-library/exception-functions.md#current_exception)|Obtém um ponteiro para a exceção atual.|
|[get_terminate](../standard-library/exception-functions.md#get_terminate)|Obtém a função `terminate_handler` atual.|
|[get_unexpected](../standard-library/exception-functions.md#get_unexpected)|Obtém a função `unexpected_handler` atual.|
|[make_exception_ptr](../standard-library/exception-functions.md#make_exception_ptr)|Cria um objeto `exception_ptr` que mantém uma cópia de uma exceção.|
|[rethrow_exception](../standard-library/exception-functions.md#rethrow_exception)|Lança uma exceção passada como um parâmetro.|
|[set_terminate](../standard-library/exception-functions.md#set_terminate)|Estabelece um novo `terminate_handler` a ser chamado na finalização do programa.|
|[set_unexpected](../standard-library/exception-functions.md#set_unexpected)|Estabelece um novo `unexpected_handler` a ser chamado quando uma exceção inesperada é encontrada.|
|[terminate](../standard-library/exception-functions.md#terminate)|Chama um manipulador de finalização.|
|[uncaught_exception](../standard-library/exception-functions.md#uncaught_exception)|Retornará **true** apenas se uma exceção lançada estiver sendo processada no momento.|
|[unexpected](../standard-library/exception-functions.md#unexpected)|Chama um manipulador inesperado.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe bad_exception](../standard-library/bad-exception-class.md)|A classe descreve uma exceção que pode ser lançada de um `unexpected_handler`.|
|[Classe exception](../standard-library/exception-class.md)|A classe atua como a classe base de todas as exceções lançadas por determinadas expressões e pela biblioteca padrão C++.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
