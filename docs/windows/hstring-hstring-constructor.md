---
title: 'Construtor hstring:: Hstring | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::HString
dev_langs:
- C++
ms.assetid: 6da12785-ed01-4720-a004-667db60298f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 59ec7c1635b825cc300e28e5c02e2a3864a6c123
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46442247"
---
# <a name="hstringhstring-constructor"></a>Construtor HString::HString

Inicializa uma nova instância dos **HString** classe.

## <a name="syntax"></a>Sintaxe

```cpp
HString(HSTRING hstr = nullptr) throw();
HString(HString&& other) throw();
```

#### <a name="parameters"></a>Parâmetros

*HSTR*<br/>
Um identificador de HSTRING.

*other*<br/>
Um existente **HString** objeto.

## <a name="remarks"></a>Comentários

O primeiro construtor inicializa uma nova **HString** objeto que está vazio.

O segundo construtor inicializa uma nova **HString** objeto para o valor de existente *outras* parâmetro e, em seguida, destrói o *outros* parâmetro.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HString](../windows/hstring-class.md)