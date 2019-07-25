---
title: Classe collate_byname
ms.date: 11/04/2016
f1_keywords:
- locale/std::collate_byname
helpviewer_keywords:
- collate_byname class
ms.assetid: 3dc380df-867c-4763-b60e-ba62a8e63ca7
ms.openlocfilehash: b8ed428da05e706796a981b8ca9d601033156c6f
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68458617"
---
# <a name="collatebyname-class"></a>Classe collate_byname

Uma classe de modelo derivada que descreve um objeto que pode funcionar como uma faceta de agrupamento de uma determinada localidade, permitindo a recuperação de informações específicas a uma área cultural no que diz respeito a convenções de classificação de cadeia de caracteres.

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

*_Locname*\
Uma localidade nomeada.

*_Refs*\
Uma contagem de referência inicial.

## <a name="remarks"></a>Comentários

Uma classe de modelo que descreve um objeto que pode funcionar como uma [faceta de localidade](../standard-library/locale-class.md#facet_class) do tipo [collate](../standard-library/collate-class.md#collate)\<CharType>. Seu comportamento é determinado pela localidade [nomeada](../standard-library/locale-class.md#name) *_Locname*. Cada construtor inicializa seu objeto base com [collate](../standard-library/collate-class.md#collate)\<CharType>( `_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
