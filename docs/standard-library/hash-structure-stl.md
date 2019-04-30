---
title: Estrutura hash (Biblioteca Padrão C++)| Microsoft Docs
ms.date: 11/04/2016
f1_keywords:
- thread/std::hash
ms.assetid: 4a8bf5bc-4334-4070-936b-98585f8a073b
ms.openlocfilehash: bb230d401d5061f4951f8007f93c3a28ce3dab03
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405008"
---
# <a name="hash-structure-c-standard-library"></a>Estrutura hash (Biblioteca Padrão C++)

Define uma função membro que retorna um valor determinado de forma exclusiva por `Val`. A função membro define uma função de [hash](../standard-library/hash-class.md) adequada para mapear valores do tipo `thread::id` para uma distribuição de valores de índice.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct hash<thread::id> :
    public unary_function<thread::id, size_t>
{
    size_t operator()(thread::id Val) const;

};
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<thread >

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<thread>](../standard-library/thread.md)<br/>
[Struct unary_function](../standard-library/unary-function-struct.md)<br/>
