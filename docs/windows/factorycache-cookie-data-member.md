---
title: 'Membro de dados factorycache:: cookie | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::FactoryCache::cookie
dev_langs:
- C++
helpviewer_keywords:
- cookie data member
ms.assetid: b1bc79af-a896-4e3b-8afa-64733022eddf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6dba6e5d7fd478d198e48e9d8517d34e13b43484
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42613660"
---
# <a name="factorycachecookie-data-member"></a>Membro de dados FactoryCache::cookie

Oferece suporte a infraestrutura de biblioteca de modelos de C++ de tempo de execução do Windows e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
union {
   WINRT_REGISTRATION_COOKIE winrt;
   DWORD com;
} cookie;
```

## <a name="remarks"></a>Comentários

Contém um valor que identifica um objeto de classe de tempo de execução do Windows ou COM registrado e é usado posteriormente para cancelar o registro do objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura FactoryCache](../windows/factorycache-structure.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)