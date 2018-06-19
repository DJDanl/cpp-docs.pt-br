---
title: Contêiner Class::erase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- erase method
ms.assetid: abc091c5-5a80-4bd8-93a8-a2d9bde2efec
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 368b722f03a68445ddd016705aa8bebc6f33e6f5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33842606"
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
