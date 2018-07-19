---
title: _com_ptr_t::GetActiveObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::GetActiveObject
dev_langs:
- C++
helpviewer_keywords:
- GetActiveObject method [C++]
ms.assetid: 2fa94853-0410-4620-91f2-136dae923f9f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ccff761cb9b738de9e2f0debc470746d1482ab56
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37940362"
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
 *rclsid*  
 O `CLSID` de um objeto.  
  
 *clsidString*  
 Uma cadeia de caracteres Unicode que contém um `CLSID` (começando com "**{**") ou um `ProgID`.  
  
 *clsidStringA*  
 Uma cadeia de caracteres multibyte, usando a página de código ANSI, que contém um `CLSID` (começando com "**{**") ou um `ProgID`.  
  
## <a name="remarks"></a>Comentários  
 Essas funções de membro chamam `GetActiveObject` para recuperar um ponteiro para um objeto em execução que foi registrado com OLE e depois consulta o tipo de interface desse ponteiro inteligente. O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado. Essa rotina retorna o HRESULT para indicar êxito ou falha.  
  
-   **1&gt;getactiveobject(&lt;1}{2&gt;)&lt;2 (**`rclsid`**)** anexa a uma instância existente de um objeto dado um `CLSID`.      
  
-   **1&gt;getactiveobject(&lt;1}{2&gt;)&lt;2 (**`clsidString`**)** anexa a uma instância existente de um objeto dada uma cadeia de caracteres Unicode que contém um `CLSID` (começando com "**{**") ou um `ProgID`.      
  
-   **1&gt;getactiveobject(&lt;1}{2&gt;)&lt;2 (**`clsidStringA`**)** anexa a uma instância existente de um objeto dada uma cadeia de caracteres multibyte que contém um `CLSID` (começando com "**{**") ou um `ProgID`.     Chamadas [MultiByteToWideChar](http://msdn.microsoft.com/library/windows/desktop/dd319072), que presume que a cadeia de caracteres está em página de código ANSI em vez de uma página de código OEM.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)