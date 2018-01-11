---
title: "Método Comptr: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: client/Microsoft::WRL::ComPtr::CopyTo
dev_langs: C++
helpviewer_keywords: CopyTo method
ms.assetid: 8801bc49-6db4-4393-a55f-a701ae3b8718
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1f47df584fb456c721c92823a87ca525beb052d6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comptrcopyto-method"></a>Método ComPtr::CopyTo
Cópias da interface atual ou especificada associado a este ComPtr ao ponteiro especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT CopyTo(  
   _Deref_out_ InterfaceType** ptr  
);  
  
HRESULT CopyTo(  
   REFIID riid,  
   _Deref_out_ void** ptr  
) const;  
template<  
   typename U  
>  
  
HRESULT CopyTo(  
   _Deref_out_ U** ptr  
) const;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `U`  
 O nome de um tipo.  
  
 `ptr`  
 Quando essa operação for concluída, um ponteiro para a interface solicitada.  
  
 `riid`  
 Uma ID de interface.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que indica por que a operação de QueryInterface implícita falhou.  
  
## <a name="remarks"></a>Comentários  
 A primeira função retorna uma cópia de um ponteiro para a interface associada a este ComPtr. Essa função sempre retorna S_OK.  
  
 A segunda função executa uma operação de QueryInterface na interface associado a este ComPtr para a interface especificada pelo `riid` parâmetro.  
  
 A terceira função executa uma operação de QueryInterface na interface associado a este ComPtr para a interface subjacente do `U` parâmetro.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe ComPtr](../windows/comptr-class.md)