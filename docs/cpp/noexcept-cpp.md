---
title: noexcept (C++) | Microsoft Docs
ms.custom: 
ms.date: 01/12/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- noexcept_cpp
dev_langs:
- C++
ms.assetid: df24edb9-c6a6-4e37-9914-fd5c0c3716a8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9b78c19cb156312b6087b75e50c0e0fa28a00246
ms.sourcegitcommit: c2e990450ccd528d85b2783fbc63042612987cfd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/16/2018
---
# <a name="noexcept-c"></a>noexcept (C++)
**C++ 11:** Especifica se uma função pode lançar exceções.  
  
## <a name="syntax"></a>Sintaxe  
  
> *noexcept-expression*:  
> &nbsp;&nbsp;&nbsp;&nbsp;**noexcept**  
> &nbsp;&nbsp;&nbsp;&nbsp;**noexcept(** *constant-expression* **)**  
  
### <a name="parameters"></a>Parâmetros  
 *constant-expression*  
 Uma expressão de constante do tipo `bool` que representa se o conjunto de possíveis tipos de exceção está vazio. A versão incondicional é equivalente a `noexcept(true)`.  
  
## <a name="remarks"></a>Comentários  
 Um *noexcept expressão* é um tipo de *especificação de exceção*, um sufixo a uma declaração de função que representa um conjunto de tipos que pode ser correspondido por um manipulador de exceção para qualquer exceção que sai de um função. Operador condicional unário `noexcept(` *constant_expression* `)` onde *constant_expression* yeilds `true`e seu sinônimo incondicional `noexcept`, Especifique o conjunto de possíveis tipos de exceção que pode sair de uma função está vazio. Ou seja, a função nunca gera uma exceção e nunca permite que uma exceção sejam propagadas fora de seu escopo. O operador `noexcept(` *constant_expression* `)` onde *constant_expression* yeilds `false`, ou a ausência de uma especificação de exceção (em vez de para um função destruidor ou desalocação), indica que o conjunto de exceções potenciais que pode sair da função é o conjunto de todos os tipos.  
 
 Marca uma função como `noexcept` somente se todas as funções que ela chama, direta ou indiretamente, também são `noexcept` ou `const`. O compilador não verifica cada caminho de código para exceções que podem ser bolhas até necessariamente um `noexcept` função. Se uma exceção sair do escopo externo de uma função marcado `noexcept`, [std::terminate](../standard-library/exception-functions.md#terminate) é chamado imediatamente, e não há nenhuma garantia de que serão invocados destrutores de todos os objetos no escopo. Use `noexcept` em vez do especificador de exceções dinâmicas `throw()`, que agora está obsoleto no padrão. É recomendável que você aplicar `noexcept` para qualquer função que nunca permite que uma exceção propagar a pilha de chamadas. Quando uma função é declarada `noexcept`, ela permite que o compilador gere código mais eficiente em vários contextos diferentes. Para obter mais informações, consulte [especificações de exceção](exception-specifications-throw-cpp.md).   
  
## <a name="example"></a>Exemplo  
Uma função de modelo que copia seu argumento pode ser declarado como `noexcept` se o objeto que está sendo copiado é um tipo de dados antigo simples (POD). Uma função pode ser declarada como este:  
  
```cpp  
#include <type_traits>  
  
template <typename T>  
T copy_object(const T& obj) noexcept(std::is_pod<T>)  
{  
   // ...   
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de exceção C++](cpp-exception-handling.md) [especificações de exceção (lançar, noexcept)](exception-specifications-throw-cpp.md)