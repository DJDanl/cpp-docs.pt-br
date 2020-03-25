---
title: _com_ptr_t::CreateInstance
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::CreateInstance
helpviewer_keywords:
- CreateInstance method [C++]
ms.assetid: ab89b0e1-9da3-4784-a079-58b17340f111
ms.openlocfilehash: 2ec4e90c8f0c1009cc47e9022a09b3b8f7dbb284
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189995"
---
# <a name="_com_ptr_tcreateinstance"></a>_com_ptr_t::CreateInstance

**Seção específica da Microsoft**

Cria uma nova instância de um objeto, de acordo com um `CLSID` ou `ProgID`.

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

#### <a name="parameters"></a>parâmetros

*rclsid*<br/>
A `CLSID` de um objeto.

*clsidstring*<br/>
Uma cadeia de caracteres Unicode que mantém um `CLSID` (começando com " **{** ") ou um `ProgID`.

*clsidStringA*<br/>
Uma cadeia de caracteres multibyte, usando a página de código ANSI, que contém um `CLSID` (começando com " **{** ") ou um `ProgID`.

*dwClsContext*<br/>
Contexto para execução do código executável.

*pOuter*<br/>
O desconhecido externo para [agregação](../atl/aggregation.md).

## <a name="remarks"></a>Comentários

Essas funções membro chamam `CoCreateInstance` para criar um novo objeto COM e, em seguida, buscam o tipo de interface desse ponteiro inteligente. O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro encapsulado anteriormente. Essa rotina retorna o HRESULT para indicar êxito ou falha.

- **CreateInstance (**  *rclsid* **,**  *dwClsContext*  **)** Cria uma nova instância em execução de um objeto, dado um `CLSID`.

- **CreateInstance (**  *clsidstring* **,**  *dwClsContext*  **)** Cria uma nova instância em execução de um objeto, considerando uma cadeia de caracteres Unicode que contém um `CLSID` (começando com " **{** ") ou um `ProgID`.

- **CreateInstance (**  *clsidStringA* **,**  *dwClsContext*  **)** Cria uma nova instância em execução de um objeto, dado uma cadeia de caracteres multibyte que contém um `CLSID` (começando com " **{** ") ou um `ProgID`. Chama [MultiByteToWideChar](/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar), que pressupõe que a cadeia de caracteres está na página de código ANSI em vez de uma página de código OEM.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
