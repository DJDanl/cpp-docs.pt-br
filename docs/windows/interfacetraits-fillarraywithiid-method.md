---
title: 'Método interfacetraits:: Fillarraywithiid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::InterfaceTraits::FillArrayWithIid
dev_langs:
- C++
helpviewer_keywords:
- FillArrayWithIid method
ms.assetid: 73583177-adc9-4fcb-917d-fa7e6d07c990
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9851731635d940b878cf2012c8553773f485559b
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40017373"
---
# <a name="interfacetraitsfillarraywithiid-method"></a>Método InterfaceTraits::FillArrayWithIid
Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
__forceinline static void FillArrayWithIid(  
   _Inout_ unsigned long &index,  
   _In_ IID* iids  
);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *index*  
 Ponteiro para um campo que contém um valor de índice baseado em zero.  
  
 *IIDs*  
 Uma matriz de IDs de interface.  
  
## <a name="remarks"></a>Comentários  
 Atribui a ID de interface do `Base` ao elemento de matriz especificado pelo argumento de índice.  
  
 O nome dessa API, ao contrário do elemento de apenas uma matriz é modificado; não é a matriz inteira.  
  
 Para obter mais informações sobre `Base`, consulte a seção Typedefs públicos [estrutura InterfaceTraits](../windows/interfacetraits-structure.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** Implements. h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura InterfaceTraits](../windows/interfacetraits-structure.md)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)