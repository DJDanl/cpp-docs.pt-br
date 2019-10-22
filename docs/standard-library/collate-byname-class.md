---
title: Classe collate_byname
ms.date: 11/04/2016
f1_keywords:
- locale/std::collate_byname
helpviewer_keywords:
- collate_byname class
ms.assetid: 3dc380df-867c-4763-b60e-ba62a8e63ca7
ms.openlocfilehash: 3e9a256ac7bdb5f6d077746fe2a08990ed41e931
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688267"
---
# <a name="collate_byname-class"></a>Classe collate_byname

Um modelo de classe derivada que descreve um objeto que pode servir como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas para uma área cultural relacionada a convenções de classificação de cadeias de caracteres.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType>
class collate_byname : public collate<CharType> {
public:
    explicit collate_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit collate_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual ~collate_byname();

};
```

### <a name="parameters"></a>Parâmetros

@No__t_1 *_Locname*
Uma localidade nomeada.

@No__t_1 *_Refs*
Uma contagem de referência inicial.

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que pode servir como uma [faceta de localidade](../standard-library/locale-class.md#facet_class) do tipo [COLLATE](../standard-library/collate-class.md#collate) \<CharType >. Seu comportamento é determinado pela localidade [nomeada](../standard-library/locale-class.md#name) *_Locname*. Cada construtor inicializa seu objeto base com [collate](../standard-library/collate-class.md#collate)\<CharType>( `_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
