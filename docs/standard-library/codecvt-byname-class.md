---
title: Classe codecvt_byname | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- xlocale/std::codecvt_byname
dev_langs:
- C++
helpviewer_keywords:
- codecvt_byname class
ms.assetid: b63b6c04-f60c-47b9-8e30-a933f24a8ffb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 48b1d6e93aa929d95032c04a58b5b419ca312f8d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33842788"
---
# <a name="codecvtbyname-class"></a>Classe codecvt_byname

Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas a uma área cultural no que diz respeito a conversões.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class Byte, class StateType>
class codecvt_byname: public codecvt<CharType, Byte, StateType> {
public:
    explicit codecvt_byname(
    const char* _Locname,
    size_t _Refs = 0);
```

```cpp
explicit codecvt_byname(
    const string& _Locname,
    size_t _Refs = 0);
```

```cpp
protected:
    virtual ~codecvt_byname();

};
```

### <a name="parameters"></a>Parâmetros

`_Locname` Uma localidade nomeada.

`_Refs` Uma contagem de referência inicial.

## <a name="remarks"></a>Comentários

As facetas byname são criadas automaticamente quando uma localidade nomeada é construída.

Seu comportamento é determinado pela localidade nomeada `_Locname`. Cada construtor inicializa seu objeto base com [codecvt](../standard-library/codecvt-class.md)\<CharType, Byte, StateType>( `_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
