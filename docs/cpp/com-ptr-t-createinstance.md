---
title: "_com_ptr_t::CreateInstance | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "_com_ptr_t::CreateInstance"
  - "_com_ptr_t.CreateInstance"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método CreateInstance"
ms.assetid: ab89b0e1-9da3-4784-a079-58b17340f111
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# _com_ptr_t::CreateInstance
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Cria uma nova instância de um objeto dado um **CLSID** ou **ProgID**.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `rclsid`  
 O **CLSID** de um objeto.  
  
 `clsidString`  
 Uma cadeia de caracteres Unicode que contém **CLSID** \(começando com “**{**"\) ou **ProgID**.  
  
 `clsidStringA`  
 Uma cadeia de caracteres multibyte, usando a página de códigos ANSI, que contém **CLSID** \(começando com “**{**"\) ou **ProgID**.  
  
 `dwClsContext`  
 Contexto para execução do código executável.  
  
 `pOuter`  
 O externo desconhecido para [agregação](../atl/aggregation.md).  
  
## Comentários  
 Essas funções membro chamam `CoCreateInstance` para criar um novo objeto COM e, em seguida, buscam o tipo de interface desse ponteiro inteligente.  O ponteiro resultante é encapsulado nesse objeto `_com_ptr_t`.  **Release** é chamado para diminuir a contagem de referências para o ponteiro anteriormente encapsulado.  Essa rotina retorna `HRESULT` para indicar êxito ou falha.  
  
-   **CreateInstance\(**  `rclsid` **,**  `dwClsContext`  **\)** Cria uma nova instância em execução de um objeto a partir de um **CLSID**.  
  
-   **CreateInstance\(**  `clsidString` **,**  `dwClsContext`  **\)** Cria uma nova instância em execução de um objeto a partir de uma cadeia de caracteres Unicode que contenha um **CLSID** \(começando por "**{**"\) ou um **ProgID**.  
  
-   **CreateInstance\(**  `clsidStringA` **,**  `dwClsContext`  **\)** Cria uma nova instância em execução de um objeto a partir de uma cadeia de caracteres multibyte que contenha um **CLSID** \(começando por "**{**"\) ou um **ProgID**.  Chama [MultiByteToWideChar](http://msdn.microsoft.com/library/windows/desktop/dd319072), que presume que a cadeia de caracteres esteja na página de códigos ANSI em vez de uma página de códigos OEM.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Classe \_com\_ptr\_t](../cpp/com-ptr-t-class.md)