---
title: Estrutura CDaoIndexFieldInfo
ms.date: 09/17/2019
f1_keywords:
- CDaoIndexFieldInfo
helpviewer_keywords:
- CDaoIndexFieldInfo structure [MFC]
- DAO (Data Access Objects), Index Fields collection
ms.assetid: 097ee8a6-83b1-4db7-8f05-d62a2deefe19
ms.openlocfilehash: a8b0ff991b8cc4988192b89d7f70309af9b9112a
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71096088"
---
# <a name="cdaoindexfieldinfo-structure"></a>Estrutura CDaoIndexFieldInfo

A `CDaoIndexFieldInfo` estrutura contém informações sobre um objeto de campo de índice definido para DAO (objetos de acesso a dados).

O DAO tem suporte por meio do Office 2013. O DAO 3,6 é a versão final e é considerado obsoleto.

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
Nomeia exclusivamente o objeto de campo de índice. Para obter detalhes, consulte o tópico "propriedade de nome" na ajuda do DAO.

*m_bDescending*<br/>
Indica a ordenação de índice definida pelo objeto de índice. TRUE se a ordem for decrescente.

## <a name="remarks"></a>Comentários

Um objeto de índice pode ter um número de campos, indicando quais campos um TableDef (ou um conjunto de registros baseado em uma tabela) é indexado. As referências a Primary acima indicam como as informações são retornadas no `m_pFieldInfos` membro de um objeto [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) obtido chamando a `GetIndexInfo` função de membro da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md#getindexinfo) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md#getindexinfo).

Objetos de índice e objetos de campo de índice não são representados por uma classe MFC. Em vez disso, os objetos DAO subjacentes aos objetos do MFC da classe [CDaoTableDef](../../mfc/reference/cdaotabledef-class.md) ou [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md) contêm uma coleção de objetos de índice, chamada de coleção de índices. Cada objeto de índice, por sua vez, contém uma coleção de objetos Field. Essas classes fornecem funções de membro para acessar itens individuais de informações de índice ou você pode acessá-las de uma `CDaoIndexInfo` só vez com um `GetIndexInfo` objeto chamando a função membro do objeto recipiente. O `CDaoIndexInfo` objeto, então, tem um membro de dados `m_pFieldInfos`,, que aponta para uma matriz `CDaoIndexFieldInfo` de objetos.

Chame a `GetIndexInfo` função de membro do objeto tabledef ou Recordset contido em cuja coleção de índices é armazenada no objeto de índice em que você está interessado. Em seguida, `m_pFieldInfos` acesse o membro do objeto [CDaoIndexInfo](../../mfc/reference/cdaoindexinfo-structure.md) . O comprimento da `m_pFieldInfos` matriz é armazenado em `m_nFields`. `CDaoIndexFieldInfo`também define uma `Dump` função de membro em compilações de depuração. Você pode usar `Dump` para despejar o conteúdo de `CDaoIndexFieldInfo` um objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[CDaoTableDef::GetIndexInfo](../../mfc/reference/cdaotabledef-class.md#getindexinfo)<br/>
[CDaoRecordset::GetIndexInfo](../../mfc/reference/cdaorecordset-class.md#getindexinfo)
