---
title: "Método: Releaseandgetaddressof | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: client/Microsoft::WRL::ComPtr::ReleaseAndGetAddressOf
dev_langs: C++
helpviewer_keywords: ReleaseAndGetAddressOf method
ms.assetid: 3751dcb4-d50e-432c-89e4-e736be34d434
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b6711cc93071c1e260a5d216a6ad21add9c00540
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="comptrreleaseandgetaddressof-method"></a>Método ComPtr::ReleaseAndGetAddressOf
Libera a interface associada a este ComPtr e, em seguida, recupera o endereço do [PTR _](../windows/comptr-ptr-data-member.md) membro de dados, que contém um ponteiro para a interface que foi liberado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
T** ReleaseAndGetAddressOf();  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O endereço do [PTR _](../windows/comptr-ptr-data-member.md) membro de dados desse ComPtr.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)   
 [Membro de dados ComPtr::ptr_](../windows/comptr-ptr-data-member.md)