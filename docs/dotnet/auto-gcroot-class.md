---
title: Classe auto_gcroot | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- msclr::auto_gcroot
- msclr.auto_gcroot
- auto_gcroot
dev_langs: C++
helpviewer_keywords: auto_gcroot
ms.assetid: b5790912-265d-463e-a486-47302e91042a
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: bd39306e7a56506937d0084ee3167ab121eb26c4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="autogcroot-class"></a>Classe auto_gcroot
Gerenciamento automático de recursos (como [classe auto_ptr](../standard-library/auto-ptr-class.md)) que pode ser usado para inserir um identificador virtual em um tipo nativo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template<typename _element_type>  
class auto_gcroot;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `_element_type`  
 O tipo gerenciado a ser inserido.  
  
## <a name="requirements"></a>Requisitos  
 **Arquivo de cabeçalho** \<msclr\auto_gcroot.h >  
  
 **Namespace** msclr  
  
## <a name="see-also"></a>Consulte também  
 [auto_gcroot](../dotnet/auto-gcroot.md)   
 [Membros auto_gcroot](../dotnet/auto-gcroot-members.md)   
 [Como: declarar identificadores em tipos nativos](../dotnet/how-to-declare-handles-in-native-types.md)   
 [Classe auto_handle](../dotnet/auto-handle-class.md)