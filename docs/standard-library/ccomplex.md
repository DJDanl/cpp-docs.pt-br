---
title: '&lt;ccomplex&gt;'
ms.date: 11/04/2016
f1_keywords:
- <ccomplex>
ms.assetid: a9fcb5f0-88e3-464b-a5fd-d1afb8cd7e6f
ms.openlocfilehash: ab9e95eb7b432a85a75d73d388ec069b0d04ac62
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51517196"
---
# <a name="ltccomplexgt"></a>&lt;ccomplex&gt;

Inclui o cabeçalho da Biblioteca Padrão C++ [\<complex>](../standard-library/complex.md), que inclui efetivamente o cabeçalho da biblioteca C Padrão \<complex.h> e adiciona os nomes associados ao namespace `std`.

## <a name="syntax"></a>Sintaxe

```cpp
#include <ccomplex>
```

## <a name="remarks"></a>Comentários

A inclusão desse cabeçalho garante que os nomes declarados usando vinculação externa no cabeçalho da biblioteca C Padrão sejam declarados no namespace `std`.

O nome `clog`, declarado em \<complex.h>, não é definido no namespace `std` devido a conflitos em potencial com o `clog` declarado em [\<iostream>](../standard-library/iostream.md).

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Visão geral da biblioteca padrão C++](../standard-library/cpp-standard-library-overview.md)<br/>
