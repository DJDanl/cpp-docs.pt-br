---
title: "Método: Makereference | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: corewrappers/Microsoft::WRL::Wrappers::HString::MakeReference
dev_langs: C++
ms.assetid: 9e1fd2b2-66ad-4a50-b647-a20ab10e522f
caps.latest.revision: "2"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3e2eba5756f2c18830c4c8fe7e16f2751ea61ac1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="hstringmakereference-method"></a>Método HString::MakeReference
Cria um objeto HStringReference de um parâmetro de cadeia de caracteres especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<unsigned int sizeDest>  
    static HStringReference MakeReference(  
              wchar_t const (&str)[ sizeDest]);  
  
    template<unsigned int sizeDest>  
    static HStringReference MakeReference(  
              wchar_t const (&str)[sizeDest],   
              unsigned int len);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `sizeDest`  
 Um parâmetro de modelo que especifica o tamanho do buffer de HStringReference de destino.  
  
 `str`  
 Uma referência a uma cadeia de caracteres largos.  
  
 `len`  
 O comprimento máximo do `str` buffer de parâmetro a ser usado nesta operação. Se o `len` parâmetro não for especificado, todo o `str` parâmetro é usado.  
  
## <a name="return-value"></a>Valor de retorno  
 Um objeto HStringReference cujo valor é o mesmo que o especificado `str` parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)