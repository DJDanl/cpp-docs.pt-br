---
title: _com_error::_com_error
ms.date: 11/04/2016
f1_keywords:
- _com_error::_com_error
helpviewer_keywords:
- _com_error method [C++]
ms.assetid: 0a69e46c-caab-49ef-b091-eee401253ce6
ms.openlocfilehash: 4ac902f0fda90f77526ef53139ef0d523d8c22e7
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180778"
---
# <a name="_com_error_com_error"></a>_com_error::_com_error

**Seção específica da Microsoft**

Constrói um objeto **_com_error** .

## <a name="syntax"></a>Sintaxe

```
_com_error(
   HRESULT hr,
   IErrorInfo* perrinfo = NULL,
   bool fAddRef=false) throw( );

_com_error( const _com_error& that ) throw( );
```

#### <a name="parameters"></a>parâmetros

*Human*<br/>
Informações de HRESULT.

*perrinfo*<br/>
Objeto `IErrorInfo`.

*fAddRef*<br/>
O padrão faz com que o Construtor chame AddRef em uma interface de `IErrorInfo` não nula. Isso fornece a contagem de referência correta no caso comum em que a propriedade da interface é passada para o objeto **_com_error** , como:

```cpp
throw _com_error(hr, perrinfo);
```

Se você não quiser que seu código transfira a propriedade para o objeto **_com_error** , e a `AddRef` for necessária para compensar o `Release` no destruidor **_com_error** , construa o objeto da seguinte maneira:

```cpp
_com_error err(hr, perrinfo, true);
```

*Isso*<br/>
Um objeto **_com_error** existente.

## <a name="remarks"></a>Comentários

O primeiro construtor cria um novo objeto, dado um HRESULT e um objeto de `IErrorInfo` opcional. O segundo cria uma cópia de um objeto de **_com_error** existente.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
