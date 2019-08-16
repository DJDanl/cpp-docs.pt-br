---
title: _com_ptr_t::GetActiveObject
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::GetActiveObject
helpviewer_keywords:
- GetActiveObject method [C++]
ms.assetid: 2fa94853-0410-4620-91f2-136dae923f9f
ms.openlocfilehash: f13a42878392f63096cdfcb405f3f91cc0efe451
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498889"
---
# <a name="_com_ptr_tgetactiveobject"></a>_com_ptr_t::GetActiveObject

**Seção específica da Microsoft**

Anexa a uma instância existente de um objeto, dado `CLSID` a ou. `ProgID`

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
Uma cadeia de caracteres Unicode que contém `CLSID` um (começando com " **{** ") ou `ProgID`um.

*clsidStringA*<br/>
Uma cadeia de caracteres multibyte, usando a página de código ANSI, que `CLSID` contém um (começando com " **{** ") `ProgID`ou um.

## <a name="remarks"></a>Comentários

Essas funções de membro chamam GetActiveObject para recuperar um ponteiro para um objeto em execução que foi registrado com OLE e, em seguida, consulta o tipo de interface do ponteiro inteligente. O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`. `Release`é chamado para diminuir a contagem de referência para o ponteiro encapsulado anteriormente. Essa rotina retorna o HRESULT para indicar êxito ou falha.

- **GetActiveObject (** `rclsid` **)** anexa a uma instância existente de um objeto, dado um `CLSID`.

- **GetActiveObject (** `clsidString` **)** anexa a uma instância existente de um objeto, considerando uma cadeia de caracteres Unicode que contém `CLSID` um (começando com " **{** ") ou `ProgID`um.

- **GetActiveObject (** `clsidStringA` **)** anexa a uma instância existente de um objeto, dado uma cadeia de caracteres multibyte que contém um `CLSID` (começando com " **{** ") ou um `ProgID`. Chama [MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar), que pressupõe que a cadeia de caracteres está na página de código ANSI em vez de uma página de código OEM.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)