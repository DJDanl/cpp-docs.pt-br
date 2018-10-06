---
title: Estrutura space_info | Microsoft Docs
ms.custom: ''
ms.date: 09/10/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- filesystem/std::tr2::sys::space_info
dev_langs:
- C++
ms.assetid: f2b35b42-06ff-45bd-8617-39a0f5358a54
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9bfbcbe990effa20fc91494e5586d3c34d47a0d5
ms.sourcegitcommit: a738519aa491a493a8f213971354356c0e6a5f3a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/05/2018
ms.locfileid: "48821226"
---
# <a name="spaceinfo-structure"></a>Estrutura space_info

Mantém informações sobre um volume.

## <a name="syntax"></a>Sintaxe

```cpp
struct space_info
{
    uintmax_t capacity;
    uintmax_t free;
    uintmax_t available;
};
```

## <a name="members"></a>Membros

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|`unsigned long long capacity`|Representa o número total de bytes que o volume pode representar.|
|`unsigned long long free`|Representa o número de bytes que não são usados para representar os dados no volume.|
|`unsigned long long available`|Representa o número de bytes que estão disponíveis para representar os dados no volume.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<filesystem >

**Namespace:** std::experimental::filesystem

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[\<filesystem>](../standard-library/filesystem.md)<br/>
[Navegação no sistema de arquivos (C++)](../standard-library/file-system-navigation.md)<br/>
