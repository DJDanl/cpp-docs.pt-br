---
title: Classe ctype_byname
ms.date: 11/04/2016
f1_keywords:
- xlocale/std::ctype_byname
helpviewer_keywords:
- ctype_byname class
ms.assetid: a5cec021-a1f8-425f-8757-08e6f064b604
ms.openlocfilehash: 0b0f33781cc9f1f54661a44a5434c94316432a45
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68457889"
---
# <a name="ctypebyname-class"></a>Classe ctype_byname

A classe de modelo derivada descreve um objeto que pode servir como uma faceta ctype de determinada localidade, permitindo a classificação e conversão de caracteres entre maiúsculas e minúsculas, assim como entre conjuntos de caracteres especificados de localidade e nativos.

## <a name="syntax"></a>Sintaxe

```cpp
template <class _Elem>
class ctype_byname : public ctype<_Elem>
{
public:
    explicit ctype_byname(
    const char* _Locname,
    size_t _Refs = 0);

    explicit ctype_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual __CLR_OR_THIS_CALL ~ctype_byname();

};
```

## <a name="remarks"></a>Comentários

Seu comportamento é determinado pela localidade nomeada `_Locname`. Cada construtor inicializa seu objeto base com [ctype](../standard-library/ctype-class.md)\<CharType>( `_Refs`) ou o equivalente da classe base `ctype<char>`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
