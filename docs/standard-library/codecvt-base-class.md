---
title: Classe codecvt_base | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- xlocale/std::codecvt_base
dev_langs:
- C++
helpviewer_keywords:
- codecvt_base class
ms.assetid: 7e95c083-91b4-4b3f-8918-0d4ea244a040
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a471cdd63ed46e15c9ec41968ed341eefaf36963
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38965386"
---
# <a name="codecvtbase-class"></a>Classe codecvt_base

Uma classe base para a classe codecvt que é usada para definir um tipo de enumeração referenciado como `result`, usado como o tipo de retorno para as funções de membro de faceta para indicar o resultado de uma conversão.

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

A classe descreve uma enumeração comum a todas as especializações da classe de modelo [codecvt](../standard-library/codecvt-class.md). O resultado da enumeração descreve os possíveis valores de retornos de [do_in](../standard-library/codecvt-class.md#do_in) ou [do_out](../standard-library/codecvt-class.md#do_out):

- `ok` Se a conversão entre codificações de caracteres internos e externos for bem-sucedida.

- `partial` Se o destino não é grande o suficiente para a conversão seja bem-sucedida.

- `error` Se a sequência de origem estiver mal formada.

- `noconv` se a função não realizar nenhuma conversão.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
