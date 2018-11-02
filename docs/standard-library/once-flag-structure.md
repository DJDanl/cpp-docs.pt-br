---
title: Estrutura once_flag
ms.date: 09/17/2018
f1_keywords:
- mutex/std::once_flag
ms.assetid: 71bfb88d-ca8c-4082-a6e1-ff52151e8629
ms.openlocfilehash: 004a5545e2eccab83b0846e2ae30b88c8431c99d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50481965"
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
