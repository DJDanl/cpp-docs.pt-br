---
title: "Função de retorno de chamada para CDC:: graystring | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- Callback Function for CDC::GrayString
dev_langs:
- C++
helpviewer_keywords:
- callback functions, for CDC::GrayString
ms.assetid: 5217e183-df48-426b-931b-6245022ca36f
caps.latest.revision: 11
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 3ce3afefae9618420a8a97b27994c33604745677
ms.lasthandoff: 02/25/2017

---
# <a name="callback-function-for-cdcgraystring"></a>Função de retorno de chamada para CDC::GrayString
*OutputFunc* é um espaço reservado para o nome da função de retorno de chamada fornecido pelo aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
BOOL CALLBACK EXPORT OutputFunc(
    HDC hDC,  
    LPARAM lpData,  
    int nCount);
```  
  
#### <a name="parameters"></a>Parâmetros  
 `hDC`  
 Identifica um contexto de dispositivo de memória com um bitmap pelo menos a largura e altura especificada pela `nWidth` e `nHeight` para `GrayString`.  
  
 `lpData`  
 Aponta para a cadeia de caracteres a ser desenhada.  
  
 `nCount`  
 Especifica o número de caracteres de saída.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor de retorno da função de retorno de chamada deve ser **TRUE** para indicar êxito; caso contrário, será **FALSE**.  
  
## <a name="remarks"></a>Comentários  
 A função de retorno de chamada (*OutputFunc*) deve desenhar uma imagem em relação as coordenadas (0,0) em vez de (*x*, *y*).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC:: graystring](../../mfc/reference/cdc-class.md#graystring)


