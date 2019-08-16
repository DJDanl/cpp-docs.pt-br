---
title: _com_ptr_t::CreateInstance
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::CreateInstance
helpviewer_keywords:
- CreateInstance method [C++]
ms.assetid: ab89b0e1-9da3-4784-a079-58b17340f111
ms.openlocfilehash: 82b180b3f40683495ed2cfa284bdae8e1afaef9e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69498658"
---
# <a name="_com_ptr_tcreateinstance"></a>_com_ptr_t::CreateInstance

**Seção específica da Microsoft**

Cria uma nova instância de um objeto dado a `CLSID` um `ProgID`ou.

## <a name="syntax"></a>Sintaxe

```
HRESULT CreateInstance(
   const CLSID& rclsid,
   IUnknown* pOuter=NULL,
   DWORD dwClsContext = CLSCTX_ALL
) throw( );
HRESULT CreateInstance(
   LPCWSTR clsidString,
   IUnknown* pOuter=NULL,
   DWORD dwClsContext = CLSCTX_ALL
) throw( );
HRESULT CreateInstance(
   LPCSTR clsidStringA,
   IUnknown* pOuter=NULL,
   DWORD dwClsContext = CLSCTX_ALL
) throw( );
```

#### <a name="parameters"></a>Parâmetros

*rclsid*<br/>
O `CLSID` de um objeto.

*clsidString*<br/>
Uma cadeia de caracteres Unicode que contém `CLSID` um (começando com " **{** ") ou `ProgID`um.

*clsidStringA*<br/>
Uma cadeia de caracteres multibyte, usando a página de código ANSI, que `CLSID` contém um (começando com " **{** ") `ProgID`ou um.

*dwClsContext*<br/>
Contexto para execução do código executável.

*pOuter*<br/>
O desconhecido externo para [agregação](../atl/aggregation.md).

## <a name="remarks"></a>Comentários

Essas funções membro chamam `CoCreateInstance` para criar um novo objeto COM e, em seguida, buscam o tipo de interface desse ponteiro inteligente. O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`. `Release`é chamado para diminuir a contagem de referência para o ponteiro encapsulado anteriormente. Essa rotina retorna o HRESULT para indicar êxito ou falha.

- **CreateInstance (** *rclsid* **,** *dwClsContext* **)** Cria uma nova instância em execução de um objeto dado `CLSID`um.

- **CreateInstance (** *clsidstring* **,** *dwClsContext* **)** Cria uma nova instância em execução de um objeto, considerando uma cadeia de caracteres Unicode `CLSID` que contém um (começando com " **{** " `ProgID`) ou um.

- **CreateInstance (** *clsidStringA* **,** *dwClsContext* **)** Cria uma nova instância em execução de um objeto, dado uma cadeia de caracteres multibyte que `CLSID` contém um (começando com " **{** ") `ProgID`ou um. Chama [MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar), que pressupõe que a cadeia de caracteres está na página de código ANSI em vez de uma página de código OEM.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)