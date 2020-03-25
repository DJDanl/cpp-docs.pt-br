---
title: _com_ptr_t::GetActiveObject
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::GetActiveObject
helpviewer_keywords:
- GetActiveObject method [C++]
ms.assetid: 2fa94853-0410-4620-91f2-136dae923f9f
ms.openlocfilehash: ea8059a039b77811dd54d4a4937ad746b7ca0937
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170795"
---
# <a name="_com_ptr_tgetactiveobject"></a>_com_ptr_t::GetActiveObject

**Seção específica da Microsoft**

Anexa a uma instância existente de um objeto, de acordo com uma `CLSID` ou `ProgID`.

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

#### <a name="parameters"></a>parâmetros

*rclsid*<br/>
A `CLSID` de um objeto.

*clsidstring*<br/>
Uma cadeia de caracteres Unicode que mantém um `CLSID` (começando com " **{** ") ou um `ProgID`.

*clsidStringA*<br/>
Uma cadeia de caracteres multibyte, usando a página de código ANSI, que contém um `CLSID` (começando com " **{** ") ou um `ProgID`.

## <a name="remarks"></a>Comentários

Essas funções de membro chamam **GetActiveObject** para recuperar um ponteiro para um objeto em execução que foi registrado com OLE e, em seguida, consulta o tipo de interface do ponteiro inteligente. O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro encapsulado anteriormente. Essa rotina retorna o HRESULT para indicar êxito ou falha.

- **GetActiveObject (** `rclsid` **)** Anexa a uma instância existente de um objeto, dado um `CLSID`.

- **GetActiveObject (** `clsidString` **)** Anexa a uma instância existente de um objeto, dada uma cadeia de caracteres Unicode que mantém um `CLSID` (começando com " **{** ") ou um `ProgID`.

- **GetActiveObject (** `clsidStringA` **)** Anexa a uma instância existente de um objeto, dado uma cadeia de caracteres multibyte que contém um `CLSID` (começando com " **{** ") ou um `ProgID`. Chama [MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar), que pressupõe que a cadeia de caracteres está na página de código ANSI em vez de uma página de código OEM.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
