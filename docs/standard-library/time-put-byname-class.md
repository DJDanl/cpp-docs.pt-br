---
title: Classe time_put_byname
ms.date: 11/04/2016
f1_keywords:
- xloctime/std::time_put_byname
helpviewer_keywords:
- time_put_byname class
ms.assetid: e08c2348-64d2-4ace-98b1-1496e14c7b1a
ms.openlocfilehash: ffe7aa276e9380b6544a78c1c1735ab57765507a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62411962"
---
# <a name="timeputbyname-class"></a>Classe time_put_byname

A classe de modelo derivada descreve um objeto que pode servir como uma faceta de localidade do tipo `time_put`\< CharType, OutputIterator >.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType, class OutIt = ostreambuf_iterator<CharType, char_traits<CharType>>>
class time_put_byname : public time_put<CharType, OutputIterator>
{
public:
    explicit time_put_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit time_put_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual ~time_put_byname();

};
```

### <a name="parameters"></a>Parâmetros

*_Locname*<br/>
Um nome de localidade.

*_Refs*<br/>
Uma contagem de referência inicial.

## <a name="remarks"></a>Comentários

Seu comportamento é determinado pela [nomeado](../standard-library/locale-class.md#name) localidade *_Locname*. Cada construtor inicializa seu objeto base com [time_put](../standard-library/time-put-class.md#time_put)\<CharType, OutputIterator > (`_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
