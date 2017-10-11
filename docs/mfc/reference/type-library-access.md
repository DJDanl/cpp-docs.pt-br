---
title: "Acesso à biblioteca de tipo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- type libraries [MFC], accessing
ms.assetid: a03fa7f0-86c2-4119-bf81-202916fb74b3
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 4a770b6508067913aec51b8b3878f33e30eed4bb
ms.openlocfilehash: 8f05738c02fd70fde5fc2d92c5ee1e823747797c
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="type-library-access"></a>Acesso à biblioteca de tipos
Bibliotecas de tipo expõem as interfaces de um controle OLE para outros aplicativos com reconhecimento de OLE. Cada controle OLE deve ter uma biblioteca de tipo, se uma ou mais interfaces devem ser expostos.  
  
 As seguintes macros permitem um controle OLE fornecer acesso a sua própria biblioteca de tipos:  
  
### <a name="type-library-access"></a>Acesso à biblioteca de tipos  
  
|||  
|-|-|  
|[DECLARE_OLETYPELIB](#declare_oletypelib)|Declara um `GetTypeLib` função membro de um controle OLE (deve ser usado na declaração da classe).|  
|[IMPLEMENT_OLETYPELIB](#implement_oletypelib)|Implementa um `GetTypeLib` função membro de um controle OLE (deve ser usado na implementação de classe).|  
  
##  <a name="declare_oletypelib"></a>DECLARE_OLETYPELIB  
 Declara o `GetTypeLib` a função de membro da classe do controle.  
  
```   
DECLARE_OLETYPELIB(class_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe de controle relacionada à biblioteca de tipos.  
  
### <a name="remarks"></a>Comentários  
 Use esta macro no arquivo de cabeçalho de classe de controle.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  

##  <a name="implement_oletypelib"></a>IMPLEMENT_OLETYPELIB  
 Implementa o controle `GetTypeLib` função de membro.  
  
```   
IMPLEMENT_OLETYPELIB(class_name, tlid, wVerMajor,  wVerMinor)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe de controle relacionada à biblioteca de tipos.  
  
 *tlid*  
 O número de identificação da biblioteca de tipos.  
  
 `wVerMajor`  
 O número de versão principal da biblioteca de tipo.  
  
 `wVerMinor`  
 O número de versão secundária da biblioteca de tipo.  
  
### <a name="remarks"></a>Comentários  
 Esta macro deve aparecer no arquivo de implementação para qualquer classe de controle que usa o `DECLARE_OLETYPELIB` macro.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
   
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

