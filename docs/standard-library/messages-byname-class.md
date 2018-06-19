---
title: Classe messages_byname | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- xlocmes/std::messages_byname
dev_langs:
- C++
helpviewer_keywords:
- messages_byname class
ms.assetid: c6c64841-3e80-43c8-b54c-fed41833ad6b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eab07f19f9d5025eba1ffe82c7e23066683b6267
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33852973"
---
# <a name="messagesbyname-class"></a>Classe messages_byname

A classe de modelo derivada descreve um objeto que pode funcionar como uma faceta de mensagem de uma determinada localidade, permitindo a recuperação das mensagens localizadas.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType>
class messages_byname : public messages<CharType> {
public:
    explicit messages_byname(
    const char *_Locname,
    size_t _Refs = 0);

    explicit messages_byname(
    const string& _Locname,
    size_t _Refs = 0);

protected:
    virtual ~messages_byname();

};
```

### <a name="parameters"></a>Parâmetros

`_Locname` Uma localidade nomeada.

`_Refs` Uma contagem de referência inicial.

## <a name="remarks"></a>Comentários

Seu comportamento é determinado pela localidade nomeada `_Locname`. Cada construtor inicializa seu objeto base com [messages](../standard-library/messages-class.md#messages)\<CharType>( `_Refs`).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
