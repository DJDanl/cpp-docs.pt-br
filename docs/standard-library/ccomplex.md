---
title: '&lt;ccomplex&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- <ccomplex>
dev_langs:
- C++
ms.assetid: a9fcb5f0-88e3-464b-a5fd-d1afb8cd7e6f
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4ea7ffa0db396242ab072efd01ccdd3def75fea9
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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
