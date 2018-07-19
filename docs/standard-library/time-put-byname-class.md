---
title: Classe time_put_byname | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- xloctime/std::time_put_byname
dev_langs:
- C++
helpviewer_keywords:
- time_put_byname class
ms.assetid: e08c2348-64d2-4ace-98b1-1496e14c7b1a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 10c01fcc7c75fb3ea9abf5803f5f17d3bd378333
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38953895"
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

*_Locname*  
 Um nome de localidade.

*_Refs*  
 Uma contagem de referência inicial.

## <a name="remarks"></a>Comentários

Seu comportamento é determinado pela [nomeado](../standard-library/locale-class.md#name) localidade *_Locname*. Cada construtor inicializa seu objeto base com [time_put](../standard-library/time-put-class.md#time_put)\<CharType, OutputIterator > (`_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
