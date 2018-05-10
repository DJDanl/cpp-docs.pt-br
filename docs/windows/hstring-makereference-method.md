---
title: 'Método: Makereference | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HString::MakeReference
dev_langs:
- C++
ms.assetid: 9e1fd2b2-66ad-4a50-b647-a20ab10e522f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e30b3ea3c6b791eb654a6fbbe91b3c87353f31c1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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