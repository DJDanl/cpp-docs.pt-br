---
title: noexcept (C++)
ms.date: 11/19/2019
f1_keywords:
- noexcept_cpp
ms.assetid: df24edb9-c6a6-4e37-9914-fd5c0c3716a8
ms.openlocfilehash: efb5ad272c8857e7a0dbd2c75885b826f2b8b9f8
ms.sourcegitcommit: 6b749db14b4cf3a2b8d581fda6fdd8cb98bc3207
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/05/2020
ms.locfileid: "82825358"
---
# <a name="noexcept-c"></a>noexcept (C++)

**C++ 11:** Especifica se uma função pode gerar exceções.

## <a name="syntax"></a>Sintaxe

> *noexcept-expressão*: \
> &nbsp;&nbsp;&nbsp;&nbsp;**noexcept**\
> &nbsp;&nbsp;&nbsp;&nbsp;**noexcept (** *expressão de constante* **)**

### <a name="parameters"></a>Parâmetros

*expressão de constante*<br/>
Uma expressão constante do tipo **bool** que representa se o conjunto de possíveis tipos de exceção está vazio. A versão incondicional é equivalente a `noexcept(true)`.

## <a name="remarks"></a>Comentários

Uma *expressão noexcept* é um tipo de *especificação de exceção*, um sufixo para uma declaração de função que representa um conjunto de tipos que podem ser correspondidos por um manipulador de exceção para qualquer exceção que saia de uma função. Operador `noexcept(`condicional unário *constant_expression* `)` em que *constant_expression* produz **true**e seu sinônimo incondicional **noexcept**, especifique que o conjunto de possíveis tipos de exceção que pode sair de uma função está vazio. Ou seja, a função nunca gera uma exceção e nunca permite que uma exceção seja propagada fora do seu escopo. O operador `noexcept(` *constant_expression* `)` onde *constant_expression* produz **false**ou a ausência de uma especificação de exceção (diferente de para um destruidor ou função de desalocação) indica que o conjunto de possíveis exceções que podem sair da função é o conjunto de todos os tipos.

Marque uma função como **noexcept** somente se todas as funções que ele chama, direta ou indiretamente, também são **noexcept** ou **const**. O compilador não verifica necessariamente cada caminho de código para exceções que possam emergir uma função **noexcept** . Se uma exceção sair do escopo externo de uma função marcada `noexcept`, [std:: Terminate](../standard-library/exception-functions.md#terminate) será invocado imediatamente e não haverá nenhuma garantia de que os destruidores de quaisquer objetos no escopo serão invocados. Use **noexcept** , em vez do especificador `throw()`de exceção dinâmica, que agora está preterido no padrão. Recomendamos que você `noexcept` aplique a qualquer função que nunca permita que uma exceção propague a pilha de chamadas. Quando uma função é declarada **noexcept**, ela permite que o compilador gere um código mais eficiente em vários contextos diferentes. Para obter mais informações, consulte [especificações de exceção](exception-specifications-throw-cpp.md).

## <a name="example"></a>Exemplo

Uma função de modelo que copia seu argumento pode ser declarada **noexcept** na condição que o objeto que está sendo copiado é um tipo de dados antigo (Pod). Essa função pode ser declarada da seguinte maneira:

```cpp
#include <type_traits>

template <typename T>
T copy_object(const T& obj) noexcept(std::is_pod<T>)
{
   // ...
}
```

## <a name="see-also"></a>Confira também

[Práticas recomendadas do C++ moderno para exceções e tratamento de erros](errors-and-exception-handling-modern-cpp.md)<br/>
[Especificações de exceção (throw, noexcept)](exception-specifications-throw-cpp.md)
