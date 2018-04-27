---
title: Contêiner Class::swap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- swap method
ms.assetid: 898c219c-bc8e-4d14-a149-6240426c693f
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3c6691b8ee8471ebf0e8edc8f1513d0229193a4a
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="container-classswap"></a>Classe de Contêiner::swap

> [!NOTE]
> Este tópico faz parte da documentação do Visual C++ como um exemplo não funcional de contêineres usados na Biblioteca Padrão C++. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Troca as sequências controladas entre **\*este** e seu argumento.

## <a name="syntax"></a>Sintaxe

```cpp
void swap(Container& right);
```

## <a name="remarks"></a>Comentários

Se for **\*this.get\_allocator ==** _right_**.get_allocator**, ele fará uma troca em tempo constante. Caso contrário, executará uma série de atribuições de elemento e de chamadas do construtor proporcional ao número de elementos nas duas sequências controladas.

## <a name="see-also"></a>Consulte também

[Classe de contêiner de amostra](../standard-library/sample-container-class.md)<br/>
