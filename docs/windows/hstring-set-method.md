---
title: "Método Hstring: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HString::Set
dev_langs: C++
ms.assetid: c9b3d613-95c4-48b0-999d-f5baf0804faf
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5919e1d0247cb8af17d98b7de97c33484be2128f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstringset-method"></a>Método HString::Set
Define o valor do objeto HString atual para a cadeia de caracteres largos especificada ou o parâmetro de HString.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
HRESULT Set(  
          const wchar_t* str) throw();  
HRESULT Set(   
          const wchar_t* str,   
          unsigned int len  
           ) throw();  
HRESULT Set(  
          const HSTRING& hstr  
           ) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `str`  
 Uma cadeia de caracteres largos.  
  
 `len`  
 O comprimento máximo do `str` parâmetro que é atribuído ao objeto HString atual.  
  
 `hstr`  
 Um objeto HString existente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)