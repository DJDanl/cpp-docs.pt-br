---
title: "Acesso à biblioteca de tipo | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.macros
dev_langs:
- C++
helpviewer_keywords:
- type libraries, accessing
ms.assetid: a03fa7f0-86c2-4119-bf81-202916fb74b3
caps.latest.revision: 14
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 17a158366f94d27b7a46917282425d652e6b9042
ms.openlocfilehash: 8a3fbcf66036ef3df3bd34b5182dac8af3dfccef
ms.lasthandoff: 02/25/2017

---
# <a name="type-library-access"></a>Acesso à biblioteca de tipos
Bibliotecas de tipos expõem as interfaces de um controle OLE para outros aplicativos compatíveis com OLE. Cada controle OLE deve ter uma biblioteca de tipos, se uma ou mais interfaces devem ser expostos.  
  
 As seguintes macros permitem um controle OLE fornecer acesso à sua própria biblioteca de tipos:  
  
### <a name="type-library-access"></a>Acesso à biblioteca de tipos  
  
|||  
|-|-|  
|[DECLARE_OLETYPELIB](#declare_oletypelib)|Declara um `GetTypeLib` a função de membro de um controle OLE (deve ser usado na declaração da classe).|  
|[IMPLEMENT_OLETYPELIB](#implement_oletypelib)|Implementa uma `GetTypeLib` função de membro de um controle OLE (deve ser usado na implementação da classe).|  
  
##  <a name="a-namedeclareoletypeliba--declareoletypelib"></a><a name="declare_oletypelib"></a>DECLARE_OLETYPELIB  
 Declara o `GetTypeLib` função membro da sua classe de controle.  
  
```   
DECLARE_OLETYPELIB(class_name)   
```  
  
### <a name="parameters"></a>Parâmetros  
 *class_name*  
 O nome da classe de controle relacionada à biblioteca de tipos.  
  
### <a name="remarks"></a>Comentários  
 Use essa macro no arquivo de cabeçalho de classe de controle.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  

##  <a name="a-nameimplementoletypeliba--implementoletypelib"></a><a name="implement_oletypelib"></a>IMPLEMENT_OLETYPELIB  
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
 Essa macro deve aparecer no arquivo de implementação para qualquer classe de controle que usa o `DECLARE_OLETYPELIB` macro.  

### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdisp.h  
   
## <a name="see-also"></a>Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)

