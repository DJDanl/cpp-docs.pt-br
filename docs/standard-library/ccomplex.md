---
title: '&lt;ccomplex&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <ccomplex>
dev_langs:
- C++
ms.assetid: a9fcb5f0-88e3-464b-a5fd-d1afb8cd7e6f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: de5c67fc88da6fc4674b7dad67b5f74dcc3ce54d
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33850379"
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
