---
title: "Método: Asiid | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- client/Microsoft::WRL::WeakRef::AsIID
dev_langs:
- C++
helpviewer_keywords:
- AsIID method
ms.assetid: 94e87309-32da-4dbb-8233-e77313a1f448
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8fdefa73ac14e807c5e4100fd81e1d931f4bf6e6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="weakrefasiid-method"></a>Método WeakRef::AsIID
Define o parâmetro de ponteiro ComPtr especificado para representar a ID de interface especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
HRESULT AsIID(  
   REFIID riid,  
   _Out_ ComPtr<IInspectable>* ptr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `riid`  
 Uma ID de interface.  
  
 `ptr`  
 Quando essa operação for concluída, um objeto que representa o parâmetro `riid`.  
  
## <a name="return-value"></a>Valor de retorno  
  
-   S_OK se essa operação for bem-sucedida; Caso contrário, o HRESULT que indica o motivo da falha na operação, e `ptr` é definido como `nullptr`.  
  
-   S_OK se essa operação for bem-sucedida, mas o objeto WeakRef atual já foi liberado. Parâmetro `ptr` é definido como `nullptr`.  
  
-   S_OK se essa operação for bem-sucedida, mas o objeto WeakRef atual não é derivado do parâmetro `riid`. Parâmetro `ptr` é definido como `nullptr`. (Para obter mais informações, consulte comentários.)  
  
## <a name="remarks"></a>Comentários  
 Um erro é emitido se parâmetro `riid` não é derivado de IInspectable. Esse erro substitui o valor de retorno.  
  
 O primeiro modelo é o formulário que você deve usar em seu código. O segundo modelo (não mostrada aqui, mas declarados no arquivo de cabeçalho) é uma especialização de auxiliar interno, que dá suporte a recursos de linguagem do C++, como o [automática](../cpp/auto-cpp.md) palavra-chave de dedução de tipo.  
  
 A partir do SDK do Windows 10, esse método não define a instância de WeakRef `nullptr` se não foi possível obter a referência fraca, portanto você deve evitar código de verificação que verifica a WeakRef para `nullptr`. Em vez disso, verifique `ptr` para `nullptr`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** client.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe WeakRef](../windows/weakref-class.md)