---
title: _com_ptr_t::CreateInstance
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::CreateInstance
helpviewer_keywords:
- CreateInstance method [C++]
ms.assetid: ab89b0e1-9da3-4784-a079-58b17340f111
ms.openlocfilehash: c4f6cd54b90ab5fab69f91df67a8bf60b0b658f8
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399350"
---
# <a name="comptrtcreateinstance"></a>_com_ptr_t::CreateInstance

**Seção específica da Microsoft**

Cria uma nova instância de um objeto, considerando um `CLSID` ou `ProgID`.

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
Uma cadeia de caracteres Unicode que contém um `CLSID` (começando com "**{**") ou um `ProgID`.

*clsidStringA*<br/>
Uma cadeia de caracteres multibyte, usando a página de código ANSI, que contém um `CLSID` (começando com "**{**") ou um `ProgID`.

*dwClsContext*<br/>
Contexto para execução do código executável.

*pOuter*<br/>
O externo desconhecido para [agregação](../atl/aggregation.md).

## <a name="remarks"></a>Comentários

Essas funções membro chamam `CoCreateInstance` para criar um novo objeto COM e, em seguida, buscam o tipo de interface desse ponteiro inteligente. O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado. Essa rotina retorna o HRESULT para indicar êxito ou falha.

- **CreateInstance (***rclsid* **,***dwClsContext***)** cria uma nova instância em execução de um objeto dado um `CLSID`.

- **CreateInstance (***clsidString* **,***dwClsContext***)** cria uma nova instância em execução de um objeto dado um Cadeia de caracteres Unicode que contém um `CLSID` (começando com "**{**") ou um `ProgID`.

- **CreateInstance (***clsidStringA* **,***dwClsContext***)** cria uma nova instância em execução de um objeto dado um cadeia de caracteres multibyte que contém um `CLSID` (começando com "**{**") ou um `ProgID`. Chamadas [MultiByteToWideChar](/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar), que presume que a cadeia de caracteres está em página de código ANSI em vez de uma página de código OEM.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)