---
title: _com_ptr_t::_com_ptr_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::_com_ptr_t
dev_langs:
- C++
helpviewer_keywords:
- _com_ptr_t method
ms.assetid: 0c00620a-28d2-4f60-ae4a-1696be36137e
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 99aeb2eb5eff192c24b1f309e7cb62a08213a867
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comptrtcomptrt"></a>_com_ptr_t::_com_ptr_t
**Seção específica da Microsoft**  
  
 Constrói um objeto `_com_ptr_t`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
// Default constructor.  
// Constructs a NULL smart pointer.  
_com_ptr_t() throw();  
  
// Constructs a NULL smart pointer. The NULL argument must be zero.  
_com_ptr_t(   
   int null   
);  
  
// Constructs a smart pointer as a copy of another instance of the   
// same smart pointer. AddRef is called to increment the reference   
// count for the encapsulated interface pointer.  
_com_ptr_t(   
   const _com_ptr_t& cp   
) throw();  
  
// Move constructor (Visual Studio 2015 Update 3 and later)  
_com_ptr_t(_com_ptr_t&& cp) throw();  
  
// Constructs a smart pointer from a raw interface pointer of this   
// smart pointer's type. If fAddRef is true, AddRef is called   
// to increment the reference count for the encapsulated   
// interface pointer. If fAddRef is false, this constructor   
// takes ownership of the raw interface pointer without calling AddRef.  
_com_ptr_t(   
   Interface* pInterface,   
   bool fAddRef   
) throw();  
  
// Construct pointer for a _variant_t object.  
// Constructs a smart pointer from a _variant_t object. The   
// encapsulated VARIANT must be of type VT_DISPATCH or VT_UNKNOWN, or   
// it can be converted into one of these two types. If QueryInterface   
// fails with an E_NOINTERFACE error, a NULL smart pointer is   
// constructed.  
_com_ptr_t(   
   const _variant_t& varSrc   
);  
  
// Constructs a smart pointer given the CLSID of a coclass. This   
// function calls CoCreateInstance, by the member function  
//  CreateInstance, to create a new COM object and then queries for   
// this smart pointer's interface type. If QueryInterface fails with   
// an E_NOINTERFACE error, a NULL smart pointer is constructed.  
explicit _com_ptr_t(   
   const CLSID& clsid,    
   IUnknown* pOuter = NULL,    
   DWORD dwClsContext = CLSCTX_ALL   
);  
  
// Calls CoCreateClass with provided CLSID retrieved from string.  
explicit _com_ptr_t(   
   LPCWSTR str,    
   IUnknown* pOuter = NULL,    
   DWORD dwClsContext = CLSCTX_ALL   
);  
  
// Constructs a smart pointer given a multibyte character string that   
// holds either a CLSID (starting with "{") or a ProgID. This function   
// calls CoCreateInstance, by the member function CreateInstance, to   
// create a new COM object and then queries for this smart pointer's   
// interface type. If QueryInterface fails with an E_NOINTERFACE error,   
// a NULL smart pointer is constructed.  
explicit _com_ptr_t(   
   LPCSTR str,   
   IUnknown* pOuter = NULL,   
   DWORD dwClsContext = CLSCTX_ALL   
);  
  
// Saves the interface.  
template<>    
_com_ptr_t(   
   Interface* pInterface   
) throw();  
  
// Make sure correct ctor is called  
template<>    
_com_ptr_t(   
   LPSTR str   
);  
  
// Make sure correct ctor is called  
template<>    
_com_ptr_t(   
   LPWSTR str   
);  
  
// Constructs a smart pointer from a different smart pointer type or   
// from a different raw interface pointer. QueryInterface is called to   
// find an interface pointer of this smart pointer's type. If   
// QueryInterface fails with an E_NOINTERFACE error, a NULL smart   
// pointer is constructed.  
template<typename _OtherIID>    
_com_ptr_t(   
   const _com_ptr_t<_OtherIID>& p   
);  
  
// Constructs a smart-pointer from any IUnknown-based interface pointer.  
template<typename _InterfaceType>   
_com_ptr_t(   
   _InterfaceType* p   
);  
  
// Disable conversion using _com_ptr_t* specialization of  
// template<typename _InterfaceType> _com_ptr_t(_InterfaceType* p)  
template<>    
explicit _com_ptr_t(   
   _com_ptr_t* p   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pInterface`  
 Um ponteiro de interface bruto.  
  
 `fAddRef`  
 Se **true**, `AddRef` é chamado para incrementar a contagem de referência do ponteiro de interface encapsulado.  
  
 *CP*  
 Um objeto `_com_ptr_t`.  
  
 `p`  
 Um ponteiro de interface bruto, sendo seu tipo diferente do tipo de ponteiro inteligente desse objeto `_com_ptr_t`.  
  
 *varSrc*  
 Um objeto `_variant_t`.  
  
 `clsid`  
 O **CLSID** de coclass.  
  
 `dwClsContext`  
 Contexto para execução do código executável.  
  
 *lpcStr*  
 Uma cadeia de caracteres multibyte que mantém a um **CLSID** (começando com "**{**") ou um **ProgID**.  
  
 `pOuter`  
 Externo desconhecido para [agregação](http://msdn.microsoft.com/library/windows/desktop/ms686558).  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
