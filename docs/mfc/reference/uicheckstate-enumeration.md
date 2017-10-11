---
title: "Enumeração UICheckState | Microsoft Docs"
ms.custom: 
ms.date: 04/03/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- afxwinforms/uicheckstate
dev_langs:
- C++
helpviewer_keywords:
- uicheckstate enumeration [MFC]
ms.assetid: 2ac0098c-20e7-410c-9685-5ead5cb02b63
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: 21b23efdbad9f2b867b104d0a0d9d0bbb4338e5a
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---

# <a name="uicheckstate-enumeration"></a>Enumeração UICheckState
Descreve o estado de seleção de um item de interface do usuário para o comando.  
   
### <a name="syntax"></a>Sintaxe   
```  
public enum class 
{  
   [DefaultValue(typeid<Microsoft::VisualC::MFC::UICheckState>, "Checked")]  
   Unchecked,   
   Checked,   
   Indeterminate 
};  
```  
   
### <a name="remarks"></a>Comentários  
 [ICommandUI::Check](icommandui-interface.md#check) usa esses valores para descrever o estado de um item de interface do usuário.    
 Para obter mais informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  

