---
title: Estrutura identity
ms.date: 11/04/2016
f1_keywords:
- utility/std::identity
helpviewer_keywords:
- identity class
- identity structure
ms.assetid: 990756fd-7969-4b39-ad7e-0878e8dac8fd
ms.openlocfilehash: 722eb9c0579d0c07765434127d0a7c43718fbc37
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404988"
---
# <a name="identity-structure"></a>Estrutura identity

Um struct que fornece uma definição de tipo como o parâmetro do modelo.

## <a name="syntax"></a>Sintaxe

```cpp
struct identity {
   typedef Type type;
   Type operator()(const Type& left) const;
   };
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*left*|O valor a ser identificado.|

## <a name="remarks"></a>Comentários

A classe contém a definição de tipo público `type`, que é a mesma do parâmetro de modelo Type. Ela é usada em conjunto com a função de modelo [forward](../standard-library/utility-functions.md#forward) para garantir que o parâmetro da função tem o tipo desejado.

Para compatibilidade com o código anterior, a classe define também a função identity `operator()` que retorna o argumento *esquerdo*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<utility>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<utility>](../standard-library/utility.md)<br/>
