---
title: LCID | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.lcid
dev_langs: C++
helpviewer_keywords: LCID attribute
ms.assetid: 7f248c69-ee1c-42c3-9411-39cf27c9f43d
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: fc811d4522872f14d86ea08fc93e5253830f779b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="lcid"></a>lcid
Permite que você passar um identificador de localidade para uma função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[lcid]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **lcid** atributo C++ implementa a funcionalidade do [lcid](http://msdn.microsoft.com/library/windows/desktop/aa367067) atributo MIDL. Se você deseja implementar a localidade para um bloco de biblioteca, use o **lcid =** `lcid` parâmetro para o [módulo](../windows/module-cpp.md) atributo.  
  
## <a name="example"></a>Exemplo  
  
```  
// cpp_attr_ref_lcid.cpp  
// compile with: /LD  
#include <unknwn.h>  
[module(name="MyLibrary")];  
typedef long HRESULT;  
  
[dual, uuid("2F5F63F1-16DA-11d2-9E7B-00C04FB926DA")]  
__interface IStatic {  
   HRESULT MyFunc([in, lcid] long LocaleID, [out, retval] BSTR * ReturnVal);  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Parâmetro de interface|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de parâmetro](../windows/parameter-attributes.md)   
