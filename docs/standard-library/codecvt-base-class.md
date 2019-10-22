---
title: Classe codecvt_base
ms.date: 11/04/2016
f1_keywords:
- xlocale/std::codecvt_base
helpviewer_keywords:
- codecvt_base class
ms.assetid: 7e95c083-91b4-4b3f-8918-0d4ea244a040
ms.openlocfilehash: 6fca9b2130407b165a7a7bfb1fb2a9ec81774e20
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689887"
---
# <a name="codecvt_base-class"></a>Classe codecvt_base

Uma classe base para a classe codecvt que é usada para definir um tipo de enumeração referido como `result`, usada como o tipo de retorno para as funções de membro da faceta para indicar o resultado de uma conversão.

## <a name="syntax"></a>Sintaxe

```cpp
class codecvt_base : public locale::facet {
public:
    enum result {ok, partial, error, noconv};
    codecvt_base( size_t _Refs = 0);
    bool always_noconv() const;
    int max_length() const;
    int encoding() const;
    ~codecvt_base()

protected:
    virtual bool do_always_noconv() const;
    virtual int do_max_length() const;
    virtual int do_encoding() const;
};
```

## <a name="remarks"></a>Comentários

A classe descreve uma enumeração comum a todas as especializações do modelo de classe [codecvt](../standard-library/codecvt-class.md). O resultado da enumeração descreve os possíveis valores de retornos de [do_in](../standard-library/codecvt-class.md#do_in) ou [do_out](../standard-library/codecvt-class.md#do_out):

- `ok` se a conversão entre as codificações de caracteres internas e externas for bem sucedido.

- `partial` se o destino não for grande o suficiente para que a conversão tenha sucesso.

- `error` se a sequência de origem estiver mal formada.

- `noconv` se a função não realizar nenhuma conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
