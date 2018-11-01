---
title: Classe time_get_byname
ms.date: 11/04/2016
f1_keywords:
- xloctime/std::time_get_byname
helpviewer_keywords:
- time_get_byname class
ms.assetid: 6e54153e-da40-4bb9-a942-1a6ce57b30c9
ms.openlocfilehash: e18f210dba03d66fa3a4ea111a6dfc61f0d0c12a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50596456"
---
# <a name="timegetbyname-class"></a>Classe time_get_byname

A classe de modelo derivada descreve um objeto que pode servir como uma faceta de localidade do tipo `time_get`\<CharType, InputIterator>.

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

*_Locname*<br/>
Uma localidade nomeada.

*_Refs*<br/>
Uma contagem de referência inicial.

## <a name="requirements"></a>Requisitos

Seu comportamento é determinado pela localidade nomeada *_Locname*. Cada construtor inicializa seu objeto base com [time_get](../standard-library/time-get-class.md#time_get)\<CharType, InputIterator>( `_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
