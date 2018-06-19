---
title: Acesso à biblioteca de tipo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- type libraries [MFC], accessing
ms.assetid: a03fa7f0-86c2-4119-bf81-202916fb74b3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fb81a8aa7d9262992da29a2d93cf770fad754316
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33373205"
---
# <a name="type-library-access"></a>Acesso à biblioteca de tipos
Bibliotecas de tipo expõem as interfaces de um controle OLE para outros aplicativos com reconhecimento de OLE. Cada controle OLE deve ter uma biblioteca de tipo, se uma ou mais interfaces devem ser expostos.  
  
 As seguintes macros permitem um controle OLE fornecer acesso a sua própria biblioteca de tipos:  
  
### <a name="type-library-access"></a>Acesso à biblioteca de tipos  
  
|||  
|-|-|  
|[DECLARE_OLETYPELIB](#declare_oletypelib)|Declara um `GetTypeLib` função membro de um controle OLE (deve ser usado na declaração da classe).|  
|[IMPLEMENT_OLETYPELIB](#implement_oletypelib)|Implementa um `GetTypeLib` função membro de um controle OLE (deve ser usado na implementação de classe).|  
  
##  <a name="declare_oletypelib"></a>  DECLARE_OLETYPELIB  
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

##  <a name="implement_oletypelib"></a>  IMPLEMENT_OLETYPELIB  
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
