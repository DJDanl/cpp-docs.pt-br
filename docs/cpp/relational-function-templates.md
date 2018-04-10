---
title: Modelos de função relacional | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- relational function templates
ms.assetid: 57893a51-9adb-41fc-941d-2ca97687db2a
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 959c8d75e40903f827a273e5d57660b0efed00b8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="relational-function-templates"></a>Modelos de função relacional
**Seção específica da Microsoft**  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      template<typename _InterfaceType> bool operator==(  
   int NULL,  
   _com_ptr_t<_InterfaceType>& p   
);  
template<typename _Interface,  
   typename _InterfacePtr> bool operator==(  
   _Interface* i,  
   _com_ptr_t<_InterfacePtr>& p   
);  
template<typename _Interface> bool operator!=(  
   int NULL,  
   _com_ptr_t<_Interface>& p   
);  
template<typename _Interface,  
   typename _InterfacePtr> bool operator!=(  
   _Interface* i,  
   _com_ptr_t<_InterfacePtr>& p   
);  
template<typename _Interface> bool operator<(  
   int NULL,  
   _com_ptr_t<_Interface>& p   
);  
template<typename _Interface,  
   typename _InterfacePtr> bool operator<(  
   _Interface* i,  
   _com_ptr_t<_InterfacePtr>& p   
);  
template<typename _Interface> bool operator>(  
   int NULL,  
   _com_ptr_t<_Interface>& p   
);  
template<typename _Interface,  
   typename _InterfacePtr> bool operator>(  
   _Interface* i,  
   _com_ptr_t<_InterfacePtr>& p   
);  
template<typename _Interface> bool operator<=(  
   int NULL,  
   _com_ptr_t<_Interface>& p   
);  
template<typename _Interface,  
   typename _InterfacePtr> bool operator<=(  
   _Interface* i,  
   _com_ptr_t<_InterfacePtr>& p   
);  
template<typename _Interface> bool operator>=(  
   int NULL,  
   _com_ptr_t<_Interface>& p   
);  
template<typename _Interface,  
   typename _InterfacePtr> bool operator>=(  
   _Interface* i,  
   _com_ptr_t<_InterfacePtr>& p   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *i*  
 Um ponteiro de interface bruto.  
  
 `p`  
 Um ponteiro inteligente.  
  
## <a name="remarks"></a>Comentários  
 Esses modelos de função permitem a comparação com um ponteiro inteligente à direita do operador de comparação. Eles não são funções de membro de `_com_ptr_t`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)