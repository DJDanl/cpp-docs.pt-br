---
title: _com_ptr_t::GetActiveObject
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::GetActiveObject
helpviewer_keywords:
- GetActiveObject method [C++]
ms.assetid: 2fa94853-0410-4620-91f2-136dae923f9f
ms.openlocfilehash: 84e43de9c40baa3c596c68ed7739471c059cbac7
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50484494"
---
# <a name="comptrtgetactiveobject"></a>_com_ptr_t::GetActiveObject

**Seção específica da Microsoft**

Anexa a uma instância existente de um objeto, considerando um `CLSID` ou `ProgID`.

## <a name="syntax"></a>Sintaxe

```
HRESULT GetActiveObject(
   const CLSID& rclsid
) throw( );
HRESULT GetActiveObject(
   LPCWSTR clsidString
) throw( );
HRESULT GetActiveObject(
   LPCSTR clsidStringA
) throw( );
```

#### <a name="parameters"></a>Parâmetros

*rclsid*<br/>
O `CLSID` de um objeto.

*clsidString*<br/>
Uma cadeia de caracteres Unicode que contém um `CLSID` (começando com "**{**") ou um `ProgID`.

*clsidStringA*<br/>
Uma cadeia de caracteres multibyte, usando a página de código ANSI, que contém um `CLSID` (começando com "**{**") ou um `ProgID`.

## <a name="remarks"></a>Comentários

Essas funções membro chamam **1&gt;getactiveobject(&lt;1}{2&gt;)&lt;2** para recuperar um ponteiro para um objeto em execução que foi registrado com OLE e, em seguida, o tipo de interface consultas para este ponteiro inteligente. O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado. Essa rotina retorna o HRESULT para indicar êxito ou falha.

- **1&gt;getactiveobject(&lt;1}{2&gt;)&lt;2 (**`rclsid`**)** anexa a uma instância existente de um objeto dado um `CLSID`.

- **1&gt;getactiveobject(&lt;1}{2&gt;)&lt;2 (**`clsidString`**)** anexa a uma instância existente de um objeto dada uma cadeia de caracteres Unicode que contém um `CLSID` (começando com "**{**") ou um `ProgID`.

- **1&gt;getactiveobject(&lt;1}{2&gt;)&lt;2 (**`clsidStringA`**)** anexa a uma instância existente de um objeto dada uma cadeia de caracteres multibyte que contém um `CLSID` (começando com "**{**") ou um `ProgID`. Chamadas [MultiByteToWideChar](/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar), que presume que a cadeia de caracteres está em página de código ANSI em vez de uma página de código OEM.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)