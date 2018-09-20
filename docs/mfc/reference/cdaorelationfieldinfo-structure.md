---
title: Estrutura CDaoRelationFieldInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDaoRelationFieldInfo
dev_langs:
- C++
helpviewer_keywords:
- DAO (Data Access Objects), Relations collection
- CDaoRelationFieldInfo structure [MFC]
ms.assetid: 47cb89ca-dc80-47ce-96fd-cc4b88512558
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0e61eb5a1abab68d4833bb8eb0953758234d9be6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46423528"
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

*m_strName*<br/>
O nome do campo na tabela primária da relação.

*m_strForeignName*<br/>
O nome do campo na tabela estrangeira da relação.

## <a name="remarks"></a>Comentários

Um objeto de relação DAO Especifica os campos em uma tabela primária e os campos em uma tabela externa que definem a relação. As referências para o primário na definição de estrutura acima indicam como as informações são retornadas na `m_pFieldInfos` membro de uma [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) objeto obtido chamando o [GetRelationInfo](../../mfc/reference/cdaodatabase-class.md#getrelationinfo)função de membro da classe `CDaoDatabase`.

Objetos de relação e objetos de campo de relação não são representados por uma classe do MFC. Em vez disso, o DAO objetos objetos subjacentes do MFC da classe [CDaoDatabase](../../mfc/reference/cdaodatabase-class.md) contêm uma coleção de objetos de relação, chamados da coleção de relações. Cada objeto de relação, por sua vez, contém uma coleção de objetos de campo de relação. Cada objeto de campo de relação se correlaciona a um campo na tabela primária com um campo da tabela externa. Juntos, os objetos de campo de relação definem um grupo de campos em cada tabela, que juntas definem a relação. `CDaoDatabase` permite que você acesse objetos de relação com uma `CDaoRelationInfo` objeto chamando o `GetRelationInfo` função de membro. O `CDaoRelationInfo` objeto, em seguida, tem um membro de dados `m_pFieldInfos`, que aponta para uma matriz de `CDaoRelationFieldInfo` objetos.

Chame o [GetRelationInfo](../../mfc/reference/cdaodatabase-class.md#getrelationinfo) função de membro de recipiente `CDaoDatabase` objeto cuja relações de coleção está armazenado o objeto de relação que lhe interessam. Em seguida, acesse o `m_pFieldInfos` membro do [CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md) objeto. `CDaoRelationFieldInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoRelationFieldInfo` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Estrutura CDaoRelationInfo](../../mfc/reference/cdaorelationinfo-structure.md)
