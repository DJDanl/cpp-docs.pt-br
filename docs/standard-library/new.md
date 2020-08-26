---
title: '&lt;novo&gt;'
ms.date: 11/04/2016
f1_keywords:
- <new>
helpviewer_keywords:
- new header
ms.assetid: 218e2a15-34e8-4ef3-9122-1e90eccf8559
ms.openlocfilehash: 0fe2d0e57c0746f25187028b85157d66ee736ca4
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88836420"
---
# <a name="ltnewgt"></a>&lt;novo&gt;

Define vários tipos e funções que controlam a alocação e a liberação de armazenamento no controle do programa. Ele também define componentes para relatórios de erros de gerenciamento de armazenamento.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<new>

**Namespace:** std

## <a name="remarks"></a>Comentários

Algumas das funções declaradas nesse cabeçalho são substituíveis. A implementação fornece uma versão padrão, cujo comportamento é descrito neste documento. Um programa pode, no entanto, definir uma função com a mesma assinatura para substituir a versão padrão em tempo de vinculação. A versão de substituição deve satisfazer os requisitos descritos neste documento.

## <a name="members"></a>Membros

### <a name="objects"></a>Objetos

|Nome|Descrição|
|-|-|
|[nothrow](../standard-library/new-functions.md#nothrow)|Fornece um objeto a ser usado como um argumento para as **`nothrow`** versões do **`new`** e do **`delete`** .|

### <a name="typedefs"></a>Typedefs

|Nome|Descrição|
|-|-|
|[new_handler](../standard-library/new-typedefs.md#new_handler)|Um tipo aponta para uma função adequada para uso como um manipulador new.|
|[hardware_constructive_interference_size](../standard-library/new-typedefs.md#hardware_destructive_interference_size)||
|[hardware_destructive_interference_size](../standard-library/new-typedefs.md#hardware_destructive_interference_size)||

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[get_new_handler](../standard-library/new-functions.md#get_new_handler)||
|[launder](../standard-library/new-functions.md#launder)||
|[set_new_handler](../standard-library/new-functions.md#set_new_handler)|Instala uma função de usuário que deve ser chamada quando new falhar ao tentar alocar memória.|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador Delete](../standard-library/new-operators.md#op_delete)|A função que é chamada por uma expressão delete para desalocar o armazenamento de objetos individuais.|
|[operador delete&#91;&#93;](../standard-library/new-operators.md#op_delete_arr)|A função que é chamada por uma expressão delete para desalocar o armazenamento para uma matriz de objetos.|
|[novo operador](../standard-library/new-operators.md#op_new)|A função que é chamada por uma expressão new para alocar o armazenamento de objetos individuais.|
|[operador new&#91;&#93;](../standard-library/new-operators.md#op_new_arr)|A função que é chamada por uma expressão new para alocar o armazenamento de uma matriz de objetos.|

### <a name="enums"></a>Enumerações

|Nome|Descrição|
|-|-|
|[align_val_t](../standard-library/new-operators.md#op_align_val_t)||

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[Classe bad_alloc](../standard-library/bad-alloc-class.md)|A classe descreve uma exceção gerada para indicar que uma solicitação de alocação não teve êxito.|
|[Classe bad_array_new_length](../standard-library/bad-array-new-length.md)||
|[Classe nothrow_t](../standard-library/nothrow-t-structure.md)|A classe é usada como um parâmetro de função para o operador new para indicar que a função deve retornar um ponteiro nulo para relatar uma falha de alocação, em vez de lançar uma exceção.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
