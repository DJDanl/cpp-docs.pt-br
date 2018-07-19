---
title: Classe messages_base | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- xlocmes/std::messages_base
dev_langs:
- C++
helpviewer_keywords:
- messages_base class
ms.assetid: 9aad38c6-4c13-445d-b096-364bd0836efb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e402f103a29dd4c4af49fa1c34b9cae71fc6e9af
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38964841"
---
# <a name="messagesbase-class"></a>Classe messages_base

A classe base descreve um **int** tipo para o catálogo de mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
struct messages_base : locale::facet {
    typedef int catalog;
    explicit messages_base(size_t _Refs = 0)
};
```

## <a name="remarks"></a>Comentários

O catálogo de tipo é um sinônimo do tipo **int** que descreve os possíveis valores de retornados das mensagens:: [do_open](../standard-library/messages-class.md#do_open).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
