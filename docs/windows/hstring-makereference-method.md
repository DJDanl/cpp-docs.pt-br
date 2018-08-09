---
title: 'Método hstring:: Makereference | Microsoft Docs'
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
ms.openlocfilehash: 0c9a77a8a943dcefdf9db9d43121f2b00bde1568
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40011004"
---
# <a name="hstringmakereference-method"></a>Método HString::MakeReference
Cria um `HStringReference` objeto a partir de um parâmetro de cadeia de caracteres especificada.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
template<unsigned int sizeDest>  
    static HStringReference MakeReference(  
              wchar_t const (&str)[ sizeDest]);  
  
    template<unsigned int sizeDest>  
    static HStringReference MakeReference(  
              wchar_t const (&str)[sizeDest],   
              unsigned int len);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *sizeDest*  
 Um parâmetro de modelo que especifica o tamanho do destino `HStringReference` buffer.  
  
 *str*  
 Uma referência a uma cadeia de caracteres largos.  
  
 *Len*  
 O comprimento máximo do *str* buffer de parâmetro a ser usado nesta operação. Se o *len* parâmetro não for especificado, todo o *str* parâmetro é usado.  
  
## <a name="return-value"></a>Valor de retorno  
 Uma `HStringReference` objeto cujo valor é o mesmo que o especificado *str* parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe HString](../windows/hstring-class.md)