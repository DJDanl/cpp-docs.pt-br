---
title: Estrutura once_flag | Microsoft Docs
ms.custom: ''
ms.date: 09/17/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- mutex/std::once_flag
dev_langs:
- C++
ms.assetid: 71bfb88d-ca8c-4082-a6e1-ff52151e8629
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 67cfbe06461598fbd04e124629399baa63fdd5d9
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46104329"
---
# <a name="onceflag-structure"></a>Estrutura once_flag

Representa uma **struct** que é usado com a função de modelo [call_once](../standard-library/mutex-functions.md#call_once) para garantir que a inicialização do código seja chamado apenas uma vez, mesmo na presença de vários threads de execução.

## <a name="syntax"></a>Sintaxe

estrutura once_flag {once_flag() de constexpr noexcept;};

## <a name="remarks"></a>Comentários

O `once_flag` **struct** tem apenas um construtor padrão.

Objetos do tipo `once_flag` podem ser criados, mas não podem ser copiados.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<mutex >

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<mutex>](../standard-library/mutex.md)<br/>
