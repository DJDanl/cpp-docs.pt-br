---
title: Estrutura once_flag
ms.date: 09/17/2018
f1_keywords:
- mutex/std::once_flag
ms.assetid: 71bfb88d-ca8c-4082-a6e1-ff52151e8629
ms.openlocfilehash: fb85bd48f9b1ac10ec2fefbc6738aae777f67bcf
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68455202"
---
# <a name="onceflag-structure"></a>Estrutura once_flag

Representa uma **struct** que é usada com a função de modelo [call_once](../standard-library/mutex-functions.md#call_once) para garantir que o código de inicialização seja chamado apenas uma vez, mesmo na presença de vários threads de execução.

## <a name="syntax"></a>Sintaxe

struct once_flag { constexpr once_flag() noexcept; };

## <a name="remarks"></a>Comentários

A `once_flag` **struct** tem apenas um construtor padrão.

Objetos do tipo `once_flag` podem ser criados, mas não podem ser copiados.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> mutex

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<mutex>](../standard-library/mutex.md)
