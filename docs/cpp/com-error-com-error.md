---
title: _com_error::_com_error
ms.date: 11/04/2016
f1_keywords:
- _com_error::_com_error
helpviewer_keywords:
- _com_error method [C++]
ms.assetid: 0a69e46c-caab-49ef-b091-eee401253ce6
ms.openlocfilehash: 8856289605cce430fdab36d6e3e8b743190e02ea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62155118"
---
# <a name="comerrorcomerror"></a>_com_error::_com_error

**Seção específica da Microsoft**

Constrói uma **com_error** objeto.

## <a name="syntax"></a>Sintaxe

```
_com_error(
   HRESULT hr,
   IErrorInfo* perrinfo = NULL,
   bool fAddRef=false) throw( );

_com_error( const _com_error& that ) throw( );
```

#### <a name="parameters"></a>Parâmetros

*hr*<br/>
Informações de HRESULT.

*perrinfo*<br/>
Objeto `IErrorInfo`.

*fAddRef*<br/>
O padrão faz com que o construtor chame AddRef em não nulo `IErrorInfo` interface. Isso fornece de referência correta de contagem no caso comum em que a propriedade da interface é passada para o **com_error** objeto, como:

```cpp
throw _com_error(hr, perrinfo);
```

Se você não quiser que seu código para transferir a propriedade para o **com_error** objeto e o `AddRef` é necessário para deslocar o `Release` no **com_error** destruidor, construir o objeto como a seguir:

```cpp
_com_error err(hr, perrinfo, true);
```

*that*<br/>
Um existente **com_error** objeto.

## <a name="remarks"></a>Comentários

O primeiro construtor cria um novo objeto dado um HRESULT e opcional `IErrorInfo` objeto. O segundo cria uma cópia de um existente **com_error** objeto.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)