---
title: 'Event:: Operator operador = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::Event::operator=
dev_langs:
- C++
helpviewer_keywords:
- operator= operator
ms.assetid: d8fe9820-8856-4899-9553-56226bdc4945
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a523d6ba8679bf7d0bdf98563b86946e16e7bfca
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39571292"
---
# <a name="eventoperator-operator"></a>Operador Event::operator=
Atribui especificado **evento** referência atual **evento** instância.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW Event& operator=(  
   _Inout_ Event&& h  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *h*  
 Uma referência rvalue para um **evento** instância.  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o atual **evento** instância.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** corewrappers. h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## <a name="see-also"></a>Consulte também  
 [Classe Event (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/event-class-windows-runtime-cpp-template-library.md)