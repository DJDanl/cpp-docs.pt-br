---
title: Contêiner Class::erase | Microsoft Docs
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
- erase method
ms.assetid: abc091c5-5a80-4bd8-93a8-a2d9bde2efec
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d5a817ed259f5bd264d82fc948afa4cdcd70be2e
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="container-classerase"></a>Classe de Contêiner::erase

> [!NOTE]
> Este tópico faz parte da documentação do Visual C++ como um exemplo não funcional de contêineres usados na Biblioteca Padrão C++. Para obter mais informações, consulte [Contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

Apaga um elemento.

## <a name="syntax"></a>Sintaxe

```

    iterator erase(
    iterator _Where);

iterator erase(
    iterator first,
    iterator last);
```

## <a name="remarks"></a>Comentários

A primeira função de membro remove o elemento de sequência controlada apontada pelo *_Where*. A segunda função de membro remove os elementos da sequência controlada no intervalo [`first`, `last`). As duas retornarão um iterador que designa o primeiro elemento restante além de todos os elementos removidos ou [end](../standard-library/container-class-end.md) se esse elemento não existir.

As funções de membro gerarão uma exceção apenas se uma operação de cópia gerar uma exceção.

## <a name="see-also"></a>Consulte também

[Classe de contêiner de amostra](../standard-library/sample-container-class.md)<br/>
