---
title: Estrutura CDaoRelationInfo | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDaoRelationInfo
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), Relations collection
- CDaoRelationInfo structure
ms.assetid: 92dda090-fe72-4090-84ec-429498a48aad
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
ms.openlocfilehash: 7c3a8195aed2c3b3fe5c78c98afcc6e72a83cc21
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cdaorelationinfo-structure"></a>Estrutura CDaoRelationInfo
O `CDaoRelationInfo` estrutura contém informações sobre uma relação definida entre os campos de duas tabelas em um [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
struct CDaoRelationInfo  
{  
    CDaoRelationInfo();
*// Constructor  
    CString m_strName;      // Primary  
    CString m_strTable;     // Primary  
    CString m_strForeignTable;              // Primary  
    long m_lAttributes;     // Secondary  
    CDaoRelationFieldInfo* m_pFieldInfos;   // Secondary  
    short m_nFields;        // Secondary *// Below the // Implementation comment: *// Destructor, not otherwise documented  
};  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `m_strName`  
 Exclusivamente nomeia o objeto de relação. Para obter mais informações, consulte o tópico "Propriedade Name" na Ajuda do DAO.  
  
 *m_strTable*  
 Nomeia a tabela primária da relação.  
  
 *m_strForeignTable*  
 Nomes de tabela externa na relação. Uma tabela externa é uma tabela usada para conter chaves estrangeiras. Geralmente, você usa uma tabela externa para estabelecer ou impor a integridade referencial. A tabela externa normalmente está no lado muitos de uma relação um-para-muitos. Exemplos de tabelas externas incluem tabelas que contêm códigos para o American estados ou províncias canadenses ou pedidos de clientes.  
  
 `m_lAttributes`  
 Contém informações sobre o tipo de relação. O valor desse membro pode ser qualquer um dos seguintes:  
  
- **dbRelationUnique** relação é-para-um.  
  
- **dbRelationDontEnforce** relação não é imposta (sem integridade referencial).  
  
- **dbRelationInherited** relação existe em um banco de dados não atuais que contém as duas tabelas anexadas.  
  
- **dbRelationLeft** a relação é uma associação à esquerda. Uma junção externa esquerda inclui todos os registros da primeira (esquerda) de duas tabelas, mesmo que não existem valores correspondentes para os registros da segunda tabela (direita).  
  
- **dbRelationRight** a relação é uma associação à direita. Uma junção externa direita inclui todos os registros da segunda (direita) de duas tabelas, mesmo que não existem valores correspondentes para os registros da primeira tabela (esquerda).  
  
- **dbRelationUpdateCascade** atualizações ocorrerão em cascata.  
  
- **dbRelationDeleteCascade** exclusões serão transmitida.  
  
 `m_pFieldInfos`  
 Um ponteiro para uma matriz de [CDaoRelationFieldInfo](../../mfc/reference/cdaorelationfieldinfo-structure.md) estruturas. A matriz contém um objeto para cada campo na relação. O `m_nFields` membro de dados fornece uma contagem dos elementos da matriz.  
  
 `m_nFields`  
 O número de `CDaoRelationFieldInfo` objetos no `m_pFieldInfos` membro de dados.  
  
## <a name="remarks"></a>Comentários  
 As referências ao primário e secundário acima indicam como as informações são retornadas pelo [GetRelationInfo](../../mfc/reference/cdaodatabase-class.md#getrelationinfo) a função de membro na classe `CDaoDatabase`.  
  
 Objetos de relação não são representados por uma classe do MFC. Em vez disso, o objeto DAO subjacente de um objeto MFC do `CDaoDatabase` classe mantém uma coleção de objetos de relação: `CDaoDatabase` fornece funções de membro para acessar alguns itens individuais de informações de relação, ou você podem acessá-los todos de uma vez com um `CDaoRelationInfo` objeto chamando o `GetRelationInfo` a função de membro do objeto de banco de dados que contém.  
  
 As informações recuperadas pelo [CDaoDatabase::GetRelationInfo](../../mfc/reference/cdaodatabase-class.md#getrelationinfo) função de membro é armazenada em um `CDaoRelationInfo` estrutura. `CDaoRelationInfo`também define um `Dump` compilações de função de membro no modo de depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoRelationInfo` objeto.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdao.h  
  
## <a name="see-also"></a>Consulte também  
 [Estrutura CDaoRelationFieldInfo](../../mfc/reference/cdaorelationfieldinfo-structure.md)

