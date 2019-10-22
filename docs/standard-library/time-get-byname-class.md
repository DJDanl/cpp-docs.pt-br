---
title: Classe time_get_byname
ms.date: 11/04/2016
f1_keywords:
- xloctime/std::time_get_byname
helpviewer_keywords:
- time_get_byname class
ms.assetid: 6e54153e-da40-4bb9-a942-1a6ce57b30c9
ms.openlocfilehash: 9df3831e085f1dea1df45ff9368479fa516b944e
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72685763"
---
# <a name="time_get_byname-class"></a>Classe time_get_byname

O modelo de classe derivada descreve um objeto que pode servir como uma faceta de localidade do tipo `time_get` \<CharType, InputIterator >.

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

@No__t_1 *_Locname*
Uma localidade nomeada.

@No__t_1 *_Refs*
Uma contagem de referência inicial.

## <a name="requirements"></a>Requisitos

Seu comportamento é determinado pela localidade nomeada *_Locname*. Cada construtor inicializa seu objeto base com [time_get](../standard-library/time-get-class.md#time_get)\<CharType, InputIterator>( `_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
