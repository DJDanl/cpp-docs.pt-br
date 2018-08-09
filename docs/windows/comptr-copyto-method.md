---
title: 'Método comptr:: CopyTo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::ComPtr::CopyTo
dev_langs:
- C++
helpviewer_keywords:
- CopyTo method
ms.assetid: 8801bc49-6db4-4393-a55f-a701ae3b8718
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5b387d52c9ab7b1d9033ce70d36e9f0aa5e5b33e
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39642923"
---
# <a name="comptrcopyto-method"></a>Método ComPtr::CopyTo
Copia a interface atual ou especificada associada a este **ComPtr** para o ponteiro especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
HRESULT CopyTo(  
   _Deref_out_ InterfaceType** ptr  
);  
  
HRESULT CopyTo(  
   REFIID riid,  
   _Deref_out_ void** ptr  
) const;  

template<typename U>  
HRESULT CopyTo(  
   _Deref_out_ U** ptr  
) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *U*  
 O nome de um tipo.  
  
 *ptr*  
 Quando essa operação for concluída, um ponteiro para a interface solicitada.  
  
 *riid*  
 Uma ID de interface.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que indica por que o implícita `QueryInterface` Falha na operação.  
  
## <a name="remarks"></a>Comentários  
 A primeira função retorna uma cópia de um ponteiro para a interface associada a este **ComPtr**. Esta função sempre retorna S_OK.  
  
 A segunda função executa um `QueryInterface` operação na interface associado a este **ComPtr** para a interface especificada pelo *riid* parâmetro.  
  
 A terceira função executa um `QueryInterface` operação na interface associado a este **ComPtr** para a interface subjacente dos *U* parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)