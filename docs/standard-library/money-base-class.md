---
title: Classe money_base | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- xlocmon/std::money_base
dev_langs:
- C++
helpviewer_keywords:
- money_base class
ms.assetid: 1a303c15-9272-4f26-ae16-dcf43a0fd38a
caps.latest.revision: 19
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a33e60ff54c7ec03ef806f5104513c9838449190
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="moneybase-class"></a>Classe money_base

A classe descreve uma enumeração e uma estrutura comuns para todas as especializações da classe de modelo [moneypunct](../standard-library/moneypunct-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
struct pattern
{
   char field[_PATTERN_FIELD_SIZE];
};
```

## <a name="remarks"></a>Comentários

A enumeração **part** descreve os possíveis valores nos elementos do campo de matriz no padrão da estrutura. Os valores de **part** são:

- **none** para corresponder a zero ou mais espaços ou gerar nada.

- **sign** para corresponder ou gerar um sinal positivo ou negativo.

- **space** para corresponder a zero ou mais espaços ou gerar um espaço.

- **symbol** para corresponder ou gerar um símbolo de moeda.

- **value** para corresponder ou gerar um valor monetário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
