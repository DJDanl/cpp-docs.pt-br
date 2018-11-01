---
title: Typedefs &lt;exception&gt;
ms.date: 11/04/2016
f1_keywords:
- exception/std::exception_ptr
- exception/std::terminate_handler
- exception/std::unexpected_handler
ms.assetid: 2a338480-35e2-46f7-b223-52d4e84a5768
ms.openlocfilehash: 98a7e8197a0d729ab3a4e9ec0daf55a28cdaeb2d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50641453"
---
# <a name="ltexceptiongt-typedefs"></a>Typedefs &lt;exception&gt;

||||
|-|-|-|
|[exception_ptr](#exception_ptr)|[terminate_handler](#terminate_handler)|[unexpected_handler](#unexpected_handler)|

## <a name="exception_ptr"></a>  exception_ptr

Um tipo que descreve um ponteiro para uma exceção.

```cpp
typedef unspecified exception_ptr;
```

### <a name="remarks"></a>Comentários

Uma classe interna não especificada que é usada para implementar o tipo `exception_ptr`.

Use um objeto `exception_ptr` para fazer referência à exceção atual ou a uma instância de uma exceção especificada pelo usuário. Na implementação da Microsoft, uma exceção é representada por uma estrutura [EXCEPTION_RECORD](/windows/desktop/api/winnt/ns-winnt-_exception_record). Cada objeto `exception_ptr` inclui um campo de referência de exceção que aponta para uma cópia da estrutura `EXCEPTION_RECORD` que representa a exceção.

Quando você declara uma variável `exception_ptr`, ela não é associada a nenhuma exceção. Isto é, o campo de referência de exceção é NULL. Esse objeto `exception_ptr` é chamado de *null exception_ptr*.

Use a função `current_exception` ou `make_exception_ptr` para atribuir uma exceção a um objeto `exception_ptr`. Quando você atribui uma exceção a uma variável `exception_ptr`, o campo de referência de exceção da variável aponta para uma cópia da exceção. Se não houver memória suficiente para copiar a exceção, o campo de referência de exceção apontará para uma cópia de uma exceção [std::bad_alloc](../standard-library/bad-alloc-class.md). Se o `current_exception` ou `make_exception_ptr` função não é possível copiar a exceção por qualquer outro motivo, a função chamará o `terminate` função CRT para encerrar o processo atual.

Apesar do nome, um objeto `exception_ptr` não é, em si, um ponteiro. Ele não obedece à semântica do ponteiro e não pode ser usado com o acesso do membro do ponteiro (`->`) ou operadores (*) de indireção. O objeto `exception_ptr` não tem membros de dados públicos ou funções de membro.

**Comparações:**

Você pode usar os operadores igual (`==`) e diferente (`!=`) para comparar dois objetos `exception_ptr`. Os operadores não comparam o valor binário (padrão de bit) das estruturas `EXCEPTION_RECORD` que representam as exceções. Em vez disso, os operadores comparam os endereços no campo de referência de exceção dos objetos `exception_ptr`. Consequentemente, um `exception_ptr` nulo e o valor NULL são comparados como iguais.

## <a name="terminate_handler"></a>  terminate_handler

O tipo descreve um ponteiro para uma função adequada para uso como um `terminate_handler`.

```cpp
typedef void (*terminate_handler)();
```

### <a name="remarks"></a>Comentários

O tipo descreve um ponteiro para uma função adequada para uso como um manipulador de finalização.

### <a name="example"></a>Exemplo

Consulte [set_terminate](../standard-library/exception-functions.md#set_terminate) para obter um exemplo do uso de `terminate_handler`.

## <a name="unexpected_handler"></a>  unexpected_handler

O tipo descreve um ponteiro para uma função adequada para uso como um `unexpected_handler`.

```cpp
typedef void (*unexpected_handler)();
```

### <a name="example"></a>Exemplo

Consulte [set_unexpected](../standard-library/exception-functions.md#set_unexpected) para obter um exemplo do uso de `unexpected_handler`.

## <a name="see-also"></a>Consulte também

[\<exception>](../standard-library/exception.md)<br/>
