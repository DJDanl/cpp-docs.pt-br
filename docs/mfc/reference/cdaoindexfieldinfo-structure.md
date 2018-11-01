---
title: Estrutura CDaoIndexFieldInfo
ms.date: 11/04/2016
f1_keywords:
- CDaoIndexFieldInfo
helpviewer_keywords:
- CDaoIndexFieldInfo structure [MFC]
- DAO (Data Access Objects), Index Fields collection
ms.assetid: 097ee8a6-83b1-4db7-8f05-d62a2deefe19
ms.openlocfilehash: 358e6654060e92e0df83b118fa70e1c3a3a990b3
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50449576"
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

*m_strName*<br/>
Exclusivamente nomeia o objeto de campo de índice. Para obter detalhes, consulte o tópico "Propriedade de nome" na Ajuda do DAO.

*m_bDescending*<br/>
Indica a ordem de índice definido pelo objeto do índice. TRUE se a ordem é em ordem decrescente.

## <a name="remarks"></a>Comentários

Um objeto de índice pode ter um número de campos, que indica quais campos um tabledef (ou um conjunto de registros com base em uma tabela) é indexado em. As referências primárias acima indicam como as informações são retornadas na `m_pFieldInfos` membro de uma [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) objeto obtido chamando o `GetIndexInfo` função membro da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getindexinfo) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getindexinfo).

Objetos de índice e objetos de campo de índice não são representados por uma classe do MFC. Em vez disso, o DAO objetos objetos subjacentes do MFC da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) contêm uma coleção de objetos de índice, chamado de coleção de índices. Cada objeto de índice, por sua vez, contém uma coleção de objetos de campo. Essas classes fornecem funções de membro para acessar itens individuais de informações de índice, ou você pode acessá-los todos de uma vez com um `CDaoIndexInfo` objeto chamando o `GetIndexInfo` a função de membro do objeto contentor. O `CDaoIndexInfo` objeto, em seguida, tem um membro de dados `m_pFieldInfos`, que aponta para uma matriz de `CDaoIndexFieldInfo` objetos.

Chamar o `GetIndexInfo` a função de membro do objeto contentor tabledef ou conjunto de registros em cujos índices a coleção está armazenado o objeto de índice que você está interessado. Em seguida, acesse o `m_pFieldInfos` membro do [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) objeto. O comprimento do `m_pFieldInfos` matriz é armazenada em `m_nFields`. `CDaoIndexFieldInfo` também define um `Dump` compilações de função de membro na depuração. Você pode usar `Dump` para despejar o conteúdo de um `CDaoIndexFieldInfo` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CDaoTableDef::GetIndexInfo](../../mfc/reference/cdaotabledef-class.md#getindexinfo)<br/>
[CDaoRecordset::GetIndexInfo](../../mfc/reference/cdaorecordset-class.md#getindexinfo)

