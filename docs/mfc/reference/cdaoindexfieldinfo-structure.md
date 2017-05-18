---
title: Estrutura CDaoIndexFieldInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoIndexFieldInfo
dev_langs:
- C++
helpviewer_keywords:
- CDaoIndexFieldInfo structure
- DAO (Data Access Objects), Index Fields collection
ms.assetid: 097ee8a6-83b1-4db7-8f05-d62a2deefe19
caps.latest.revision: 12
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
ms.openlocfilehash: 975b3a704936adc9d4205938bb2c757ab650f0d9
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdaoindexfieldinfo-structure"></a>Estrutura CDaoIndexFieldInfo
O `CDaoIndexFieldInfo` estrutura contém informações sobre um objeto de campo de índice definida para objetos de acesso de dados (DAO).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CDaoIndexFieldInfo  
{  
    CString m_strName;          // Primary  
    BOOL m_bDescending;         // Primary  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `m_strName`  
 Nomes exclusivamente o objeto do campo de índice. Para obter detalhes, consulte o tópico "Propriedade Name" na Ajuda do DAO.  
  
 *m_bDescending*  
 Indica a ordem de índice definido pelo objeto do índice. **TRUE** se a ordem é decrescente.  
  
## <a name="remarks"></a>Comentários  
 Um objeto de índice pode ter um número de campos, que indica quais campos um tabledef (ou um conjunto de registros com base em uma tabela) é indexado em. As referências ao primário acima indicam como as informações são retornadas no `m_pFieldInfos` membro de um [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) objeto obtido chamando o `GetIndexInfo` a função de membro da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getindexinfo) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getindexinfo).  
  
 Objetos de índice e objetos de campo de índice não são representados por uma classe do MFC. Em vez disso, o DAO objetos objetos MFC subjacentes da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) contém uma coleção de objetos de índice, chamado de coleção de índices. Cada objeto de índice, por sua vez, contém uma coleção de objetos de campo. Essas classes fornecem funções de membro para acessar itens individuais de informações de índice, ou você pode acessá-los todos de uma vez com um `CDaoIndexInfo` objeto chamando o `GetIndexInfo` a função de membro do objeto recipiente. O `CDaoIndexInfo` objeto, em seguida, tem um membro de dados, `m_pFieldInfos`, que aponta para uma matriz de `CDaoIndexFieldInfo` objetos.  
  
 Chamar o `GetIndexInfo` a função de membro do objeto recipiente tabledef ou conjunto de dados cujos índices coleção é armazenado o objeto de índice que lhe interessam. Em seguida, acessar o `m_pFieldInfos` membro do [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) objeto. O comprimento do `m_pFieldInfos` matriz é armazenada em `m_nFields`. `CDaoIndexFieldInfo`também define um `Dump` compilações de função de membro no modo de depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoIndexFieldInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDaoTableDef::GetIndexInfo](../../mfc/reference/cdaotabledef-class.md#getindexinfo)   
 [CDaoRecordset::GetIndexInfo](../../mfc/reference/cdaorecordset-class.md#getindexinfo)


