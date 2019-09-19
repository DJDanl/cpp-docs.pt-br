---
title: Estrutura CDaoParameterInfo
ms.date: 09/17/2019
f1_keywords:
- CDaoParameterInfo
helpviewer_keywords:
- CDaoParameterInfo structure [MFC]
- DAO (Data Access Objects), Parameters collection
ms.assetid: 45fd53cd-cb84-4e12-b48d-7f2979f898ad
ms.openlocfilehash: 4f0ee7ebe1d5d4eff50194c2d5c5cccf8f373c61
ms.sourcegitcommit: 2f96e2fda591d7b1b28842b2ea24e6297bcc3622
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2019
ms.locfileid: "71096076"
---
# <a name="cdaoparameterinfo-structure"></a>Estrutura CDaoParameterInfo

A `CDaoParameterInfo` estrutura contém informações sobre um objeto de parâmetro definido para DAO (objetos de acesso a dados).
O DAO 3,6 é a versão final e é considerado obsoleto.


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

*m_strName*<br/>
Nomeia exclusivamente o objeto de parâmetro. Para obter mais informações, consulte o tópico "propriedade de nome" na ajuda do DAO.

*m_nType*<br/>
Um valor que indica o tipo de dados de um objeto de parâmetro. Para obter uma lista dos valores possíveis, consulte o membro *m_nType* da estrutura [CDaoFieldInfo](../../mfc/reference/cdaofieldinfo-structure.md) . Para obter mais informações, consulte o tópico "Type Property" na ajuda do DAO.

*m_varValue*<br/>
O valor do parâmetro, armazenado em um objeto [COleVariant](../../mfc/reference/colevariant-class.md) .

## <a name="remarks"></a>Comentários

As referências a primária e secundária acima indicam como as informações são retornadas pela função de membro [GetParameterInfo](../../mfc/reference/cdaoquerydef-class.md#getparameterinfo) na `CDaoQueryDef`classe.

O MFC não encapsula objetos de parâmetro DAO em uma classe. Objetos de QueryDef do DAO `CDaoQueryDef` os objetos do MFC subjacentes armazenam parâmetros em suas coleções de parâmetros. Para acessar os objetos de parâmetro em um objeto [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) , chame a função de `GetParameterInfo` membro do objeto querydef para um nome de parâmetro específico ou um índice na coleção de parâmetros. Você pode usar a função de membro [CDaoQueryDef:: GetParameterCount](../../mfc/reference/cdaoquerydef-class.md#getparametercount) em conjunto `GetParameterInfo` com para fazer o loop pela coleção de parâmetros.

As informações recuperadas pela função de membro [CDaoQueryDef:: GetParameterInfo](../../mfc/reference/cdaoquerydef-class.md#getparameterinfo) são armazenadas `CDaoParameterInfo` em uma estrutura. Chame `GetParameterInfo` o objeto QueryDef em cuja coleção de parâmetros o objeto de parâmetro está armazenado.

> [!NOTE]
>  Se você quiser obter ou definir apenas o valor de um parâmetro, use as funções de membro [GetParamValue](../../mfc/reference/cdaorecordset-class.md#getparamvalue) e [SetParamValue](../../mfc/reference/cdaorecordset-class.md#setparamvalue) da classe `CDaoRecordset`.

`CDaoParameterInfo`também define uma `Dump` função de membro em compilações de depuração. Você pode usar `Dump` para despejar o conteúdo de `CDaoParameterInfo` um objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDAO. h

## <a name="see-also"></a>Consulte também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)
