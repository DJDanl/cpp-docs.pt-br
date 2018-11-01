---
title: 'Método Platform:: recreateexception'
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Exception
helpviewer_keywords:
- Platform::Exception Class
ms.assetid: fa73d1ab-86e4-4d26-a7d9-81938c1c7e77
ms.openlocfilehash: 8173377a3d7a75bc85088037c229bac19f341649
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50568864"
---
# <a name="platformrecreateexception-method"></a>Método Platform::ReCreateException

Este método é somente para uso interno e não se destina a código de usuário. Use o método Exception:: createexception.

## <a name="syntax"></a>Sintaxe

```cpp
static Exception^ ReCreateException(int hr)
```

### <a name="parameters"></a>Parâmetros

*hr*

### <a name="property-valuereturn-value"></a>Valor da propriedade/valor de retorno

Retorna um novo Platform::Exception^, com base no HRESULT especificado.
