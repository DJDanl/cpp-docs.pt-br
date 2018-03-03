---
title: Estrutura CDaoIndexFieldInfo | Microsoft Docs
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
- CDaoIndexFieldInfo structure [MFC]
- DAO (Data Access Objects), Index Fields collection
ms.assetid: 097ee8a6-83b1-4db7-8f05-d62a2deefe19
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0b745a6f450bdf96389f49c673dc623b614e04db
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cdaoindexfieldinfo-structure"></a>Estrutura CDaoIndexFieldInfo
O `CDaoIndexFieldInfo` estrutura contém informações sobre um objeto de campo de índice definida para os objetos de acesso de dados (DAO).  
  
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
 Exclusivamente nomeia o objeto de campo de índice. Para obter detalhes, consulte o tópico "Propriedade de nome" na Ajuda do DAO.  
  
 *m_bDescending*  
 Indica a ordenação de índice definido pelo objeto do índice. **TRUE** se a ordem é decrescente.  
  
## <a name="remarks"></a>Comentários  
 Um objeto de índice pode ter um número de campos, que indica quais campos um tabledef (ou um conjunto de registros com base em uma tabela) é indexado em. As referências ao primário acima indicam como as informações são retornadas no `m_pFieldInfos` membro de um [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) objeto obtido chamando o `GetIndexInfo` função de membro de classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getindexinfo) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getindexinfo).  
  
 Objetos de índice e objetos de campo de índice não são representados por uma classe do MFC. Em vez disso, o DAO objetos subjacentes objetos MFC classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) contém uma coleção de objetos de índice, chamado de coleção de índices. Cada objeto de índice, por sua vez, contém uma coleção de objetos de campo. Essas classes fornecem funções de membro para acessar itens individuais de informações de índice, ou você pode acessá-los todos de uma vez com um `CDaoIndexInfo` objeto chamando o `GetIndexInfo` a função de membro do objeto contentor. O `CDaoIndexInfo` objeto, em seguida, tem um membro de dados, `m_pFieldInfos`, que aponta para uma matriz de `CDaoIndexFieldInfo` objetos.  
  
 Chamar o `GetIndexInfo` a função de membro do objeto contentor tabledef ou conjunto de registros cujos índices coleção é armazenado o objeto de índice que você está interessado. Acesse o `m_pFieldInfos` membro o [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) objeto. O comprimento do `m_pFieldInfos` matriz é armazenada em `m_nFields`. `CDaoIndexFieldInfo`também define uma `Dump` cria a função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoIndexFieldInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)   
 [CDaoTableDef::GetIndexInfo](../../mfc/reference/cdaotabledef-class.md#getindexinfo)   
 [CDaoRecordset::GetIndexInfo](../../mfc/reference/cdaorecordset-class.md#getindexinfo)

