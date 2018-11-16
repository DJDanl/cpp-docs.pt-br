---
title: 'Método Platform:: recreateexception'
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Exception
helpviewer_keywords:
- Platform::Exception Class
ms.assetid: fa73d1ab-86e4-4d26-a7d9-81938c1c7e77
ms.openlocfilehash: 9e167efc54352d125e849956a2da8d8e8cad4ed6
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693263"
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
