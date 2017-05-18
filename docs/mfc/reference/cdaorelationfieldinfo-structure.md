---
title: Estrutura CDaoRelationFieldInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoRelationFieldInfo
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), Relations collection
- CDaoRelationFieldInfo structure
ms.assetid: 47cb89ca-dc80-47ce-96fd-cc4b88512558
caps.latest.revision: 13
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 23d7497502f611cf2311e574556186dc5f7c7d3d
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdaorelationfieldinfo-structure"></a>Estrutura CDaoRelationFieldInfo
O `CDaoRelationFieldInfo` estrutura contém informações sobre um campo em uma relação definida para objetos de acesso de dados (DAO).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CDaoRelationFieldInfo  
{  
    CString m_strName;           // Primary  
    CString m_strForeignName;    // Primary  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `m_strName`  
 O nome do campo na tabela primária da relação.  
  
 `m_strForeignName`  
 O nome do campo da tabela externa da relação.  
  
## <a name="remarks"></a>Comentários  
 Um objeto de relação do DAO Especifica os campos em uma tabela primária e os campos em uma tabela externa que definem a relação. As referências ao principal na definição de estrutura acima indicam como as informações são retornadas no `m_pFieldInfos` membro de um [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) objeto obtido chamando o [GetRelationInfo](../../mfc/reference/cdaodatabase-class.md#getrelationinfo) a função de membro da classe `CDaoDatabase`.  
  
 Objetos e objetos de campo de relação não são representados por uma classe do MFC. Em vez disso, o DAO objetos objetos MFC subjacentes da classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) contém uma coleção de objetos de relação, chamado de coleção de relações. Cada objeto de relação, por sua vez, contém uma coleção de objetos de campo de relação. Cada objeto de campo de relação um campo na tabela primária se correlaciona com um campo da tabela externa. Juntos, os objetos de campo de relação definem um grupo de campos em cada tabela, que juntas definem a relação. `CDaoDatabase`permite que você acesse objetos de relação com um `CDaoRelationInfo` objeto chamando o `GetRelationInfo` função de membro. O `CDaoRelationInfo` objeto, em seguida, tem um membro de dados, `m_pFieldInfos`, que aponta para uma matriz de `CDaoRelationFieldInfo` objetos.  
  
 Chamar o [GetRelationInfo](../../mfc/reference/cdaodatabase-class.md#getrelationinfo) a função de membro de recipiente `CDaoDatabase` objeto cuja relações de coleção é armazenado o objeto de relação que lhe interessam. Em seguida, acessar o `m_pFieldInfos` membro do [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) objeto. `CDaoRelationFieldInfo`também define um `Dump` compilações de função de membro no modo de depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoRelationFieldInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Estrutura CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md)

