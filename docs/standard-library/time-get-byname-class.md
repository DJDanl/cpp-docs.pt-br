---
title: Classe time_get_byname
ms.date: 11/04/2016
f1_keywords:
- xloctime/std::time_get_byname
helpviewer_keywords:
- time_get_byname class
ms.assetid: 6e54153e-da40-4bb9-a942-1a6ce57b30c9
ms.openlocfilehash: 040d140fa4250ad33e20d1c2724b6f563e865e6b
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742652"
---
# <a name="time_get_byname-class"></a>Classe time_get_byname

O modelo de classe derivada descreve um objeto que pode servir como uma faceta de localidade do tipo `time_get` \<CharType, InputIterator> .

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class InputIterator =
    istreambuf_iterator<CharType, char_traits<CharType>>>
class time_get_byname : public time_get<CharType, InputIterator>
{
public:
    explicit time_get_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit time_get_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual ~time_get_byname()
};
```

### <a name="parameters"></a>Parâmetros

*_Locname*\
Uma localidade nomeada.

*_Refs*\
Uma contagem de referência inicial.

## <a name="requirements"></a>Requisitos

Seu comportamento é determinado pela localidade nomeada *_Locname*. Cada construtor inicializa seu objeto base com [time_get](../standard-library/time-get-class.md#time_get) \<CharType, InputIterator> ( `_Refs` ).

**Cabeçalho:**\<locale>

**Namespace:** std

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
