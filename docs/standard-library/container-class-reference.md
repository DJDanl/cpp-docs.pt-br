---
title: Contêiner Class::reference | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- reference method
ms.assetid: ab85a9fb-c628-4761-9a5f-a0231fad7690
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 13883e1426be22c8cf3d329be33258c69511900d
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38966002"
---
# <a name="container-classreference"></a>Classe de Contêiner::reference

> [!NOTE]
> Este tópico faz parte da documentação do Visual C++ como um exemplo não funcional de contêineres usados na Biblioteca Padrão C++. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Descreve um objeto que pode servir como uma referência para um elemento da sequência controlada.

## <a name="syntax"></a>Sintaxe

```

typedef T2 reference;
```

## <a name="remarks"></a>Comentários

Ele é descrito aqui como um sinônimo para o tipo não especificado `T2` (normalmente `Alloc::reference`). Um objeto do tipo `reference` pode ser convertido em um objeto do tipo [const_reference](../standard-library/container-class-const-reference.md).

## <a name="see-also"></a>Consulte também

[Classe de contêiner de amostra](../standard-library/sample-container-class.md)<br/>
