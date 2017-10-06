---
title: _com_ptr_t::CreateInstance | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::CreateInstance
dev_langs:
- C++
helpviewer_keywords:
- CreateInstance method [C++]
ms.assetid: ab89b0e1-9da3-4784-a079-58b17340f111
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 1c07f7366c76c96580fc989475bd7f5ea23a38fe
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comptrtcreateinstance"></a>_com_ptr_t::CreateInstance
**Seção específica da Microsoft**  
  
 Cria uma nova instância de um objeto, considerando um **CLSID** ou **ProgID**.  
  
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
 `rclsid`  
 O **CLSID** de um objeto.  
  
 `clsidString`  
 Uma cadeia de caracteres Unicode que contém a um **CLSID** (começando com "**{**") ou um **ProgID**.  
  
 `clsidStringA`  
 Uma cadeia de caracteres multibyte, usando a página de código ANSI, que contém o um **CLSID** (começando com "**{**") ou um **ProgID**.  
  
 `dwClsContext`  
 Contexto para execução do código executável.  
  
 `pOuter`  
 Externo desconhecido para [agregação](../atl/aggregation.md).  
  
## <a name="remarks"></a>Comentários  
 Essas funções membro chamam `CoCreateInstance` para criar um novo objeto COM e, em seguida, buscam o tipo de interface desse ponteiro inteligente. O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`. **Versão** é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado. Essa rotina retorna `HRESULT` para indicar êxito ou falha.  
  
-   **CreateInstance (** `rclsid` **,**`dwClsContext`**)** cria uma nova instância em execução de um objeto, considerando um **CLSID**.        
  
-   **CreateInstance (** `clsidString` **,**`dwClsContext`**)** cria uma nova instância em execução de um objeto, considerando uma cadeia de caracteres Unicode que contém a um **CLSID** (começando com "**{**") ou um **ProgID**.        
  
-   **CreateInstance (** `clsidStringA` **,**`dwClsContext`**)** cria uma nova instância em execução de um objeto, considerando uma cadeia de caracteres multibyte que mantém a um ** CLSID** (começando com "**{**") ou um **ProgID**.       Chamadas [MultiByteToWideChar](http://msdn.microsoft.com/library/windows/desktop/dd319072), que assume que a cadeia de caracteres é a página de código ANSI em vez de uma página de código OEM.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
