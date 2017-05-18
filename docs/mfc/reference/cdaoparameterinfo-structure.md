---
title: Estrutura CDaoParameterInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoParameterInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoParameterInfo structure
- DAO (Data Access Objects), Parameters collection
ms.assetid: 45fd53cd-cb84-4e12-b48d-7f2979f898ad
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
ms.openlocfilehash: b41d26b736ea9f84c53f71dbd71949f74fb8ae52
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdaoparameterinfo-structure"></a>Estrutura CDaoParameterInfo
O `CDaoParameterInfo` estrutura contém informações sobre um objeto de parâmetro definido para objetos de acesso de dados (DAO).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CDaoParameterInfo  
{  
    CString m_strName;       // Primary  
    short m_nType;           // Primary  
    ColeVariant m_varValue;  // Secondary  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `m_strName`  
 Nomes exclusivamente o objeto de parâmetro. Para obter mais informações, consulte o tópico "Propriedade Name" na Ajuda do DAO.  
  
 `m_nType`  
 Um valor que indica o tipo de dados de um objeto de parâmetro. Para obter uma lista dos valores possíveis, consulte o `m_nType` membro do [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura. Para obter mais informações, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.  
  
 *m_varValue*  
 O valor do parâmetro, armazenado em uma [COleVariant](../../mfc/reference/colevariant-class.md) objeto.  
  
## <a name="remarks"></a>Comentários  
 As referências ao primário e secundário acima indicam como as informações são retornadas pelo [GetParameterInfo](../../mfc/reference/cdaoquerydef-class.md#getparameterinfo) a função de membro na classe `CDaoQueryDef`.  
  
 MFC não encapsula os objetos de parâmetro DAO em uma classe. Querydef do DAO objetos subjacente MFC `CDaoQueryDef` objetos armazenam parâmetros em suas coleções de parâmetros. Para acessar os objetos de parâmetro em uma [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) de objeto, chame o objeto querydef `GetParameterInfo` função de membro para um nome de parâmetro específico ou um índice na coleção de parâmetros. Você pode usar o [CDaoQueryDef::GetParameterCount](../../mfc/reference/cdaoquerydef-class.md#getparametercount) a função de membro em conjunto com `GetParameterInfo` para percorrer a coleção de parâmetros.  
  
 As informações recuperadas pelo [CDaoQueryDef::GetParameterInfo](../../mfc/reference/cdaoquerydef-class.md#getparameterinfo) função de membro é armazenada em um `CDaoParameterInfo` estrutura. Chamar `GetParameterInfo` para o objeto querydef cuja coleção de parâmetros do objeto de parâmetro é armazenado.  
  
> [!NOTE]
>  Se você quiser obter ou definir apenas o valor de um parâmetro, use o [GetParamValue](../../mfc/reference/cdaorecordset-class.md#getparamvalue) e [SetParamValue](../../mfc/reference/cdaorecordset-class.md#setparamvalue) funções de membro da classe `CDaoRecordset`.  
  
 `CDaoParameterInfo`também define um `Dump` compilações de função de membro no modo de depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoParameterInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)

