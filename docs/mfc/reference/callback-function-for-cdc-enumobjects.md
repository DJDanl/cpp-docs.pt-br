---
title: "Função de retorno de chamada para CDC:: enumobjects | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- Callback Function for CDC::EnumObjects
dev_langs:
- C++
helpviewer_keywords:
- callback functions, for CDC::EnumObjects
ms.assetid: 380088b1-88a5-4fb4-bbb5-dd9e8386572b
caps.latest.revision: 10
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
ms.openlocfilehash: e4b24b5f5333d5514b9fdf69d204bca5d7947d7a
ms.lasthandoff: 02/25/2017

---
# <a name="callback-function-for-cdcenumobjects"></a>Função de retorno de chamada para CDC::EnumObjects
O *ObjectFunc* nome é um espaço reservado para o nome da função fornecida pelo aplicativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int CALLBACK EXPORT ObjectFunc(
    LPSTR lpszLogObject,  
    LPSTR* lpData);
```  
  
#### <a name="parameters"></a>Parâmetros  
 *lpszLogObject*  
 Aponta para um [LOGPEN](../../mfc/reference/logpen-structure.md) ou [LOGBRUSH](../../mfc/reference/logbrush-structure.md) estrutura de dados que contém informações sobre os atributos lógicos do objeto.  
  
 `lpData`  
 Pontos de dados fornecida pelo aplicativo passado para o `EnumObjects` função.  
  
## <a name="return-value"></a>Valor de retorno  
 A função de retorno de chamada retorna um `int`. O valor desse retorno é definido pelo usuário. Se a função de retorno de chamada retorna 0, `EnumObjects` para de enumeração no início.  
  
## <a name="remarks"></a>Comentários  
 O nome real deve ser exportado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDC:: enumobjects](../../mfc/reference/cdc-class.md#enumobjects)


