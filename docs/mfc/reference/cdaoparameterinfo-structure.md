---
title: Estrutura CDaoParameterInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoParameterInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoParameterInfo structure [MFC]
- DAO (Data Access Objects), Parameters collection
ms.assetid: 45fd53cd-cb84-4e12-b48d-7f2979f898ad
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1e743e7456c185acd100c898cfb946182d63ce63
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33366233"
---
# <a name="cdaoparameterinfo-structure"></a>Estrutura CDaoParameterInfo
O `CDaoParameterInfo` estrutura contém informações sobre um objeto de parâmetro definida para os objetos de acesso de dados (DAO).  
  
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
 Exclusivamente nomeia o objeto de parâmetro. Para obter mais informações, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
 `m_nType`  
 Um valor que indica o tipo de dados de um objeto de parâmetro. Para obter uma lista dos valores possíveis, consulte o `m_nType` membro o [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) estrutura. Para obter mais informações, consulte o tópico "Propriedade do tipo" na Ajuda do DAO.  
  
 *m_varValue*  
 O valor do parâmetro, armazenado em um [COleVariant](../../mfc/reference/colevariant-class.md) objeto.  
  
## <a name="remarks"></a>Comentários  
 As referências a primária e secundária acima indicam como as informações são retornadas pelo [GetParameterInfo](../../mfc/reference/cdaoquerydef-class.md#getparameterinfo) a função de membro na classe `CDaoQueryDef`.  
  
 MFC não encapsula os objetos de parâmetro DAO em uma classe. Objetos de querydef do DAO MFC subjacente `CDaoQueryDef` objetos armazenam parâmetros em suas coleções de parâmetros. Para acessar os objetos de parâmetro em uma [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) de objeto, chame do objeto `GetParameterInfo` função de membro para um nome de parâmetro específico ou um índice na coleção de parâmetros. Você pode usar o [CDaoQueryDef::GetParameterCount](../../mfc/reference/cdaoquerydef-class.md#getparametercount) a função de membro em conjunto com `GetParameterInfo` para percorrer a coleção de parâmetros.  
  
 As informações recuperadas pelo [CDaoQueryDef::GetParameterInfo](../../mfc/reference/cdaoquerydef-class.md#getparameterinfo) função de membro é armazenada em um `CDaoParameterInfo` estrutura. Chamar `GetParameterInfo` para o objeto querydef cuja coleção de parâmetros, o objeto de parâmetro é armazenado.  
  
> [!NOTE]
>  Se você quiser obter ou definir apenas o valor de um parâmetro, use o [GetParamValue](../../mfc/reference/cdaorecordset-class.md#getparamvalue) e [SetParamValue](../../mfc/reference/cdaorecordset-class.md#setparamvalue) funções membro de classe `CDaoRecordset`.  
  
 `CDaoParameterInfo` também define uma `Dump` cria a função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoParameterInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)
