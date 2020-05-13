---
title: Estrutura CDaoParameterInfo
ms.date: 09/17/2019
f1_keywords:
- CDaoParameterInfo
helpviewer_keywords:
- CDaoParameterInfo structure [MFC]
- DAO (Data Access Objects), Parameters collection
ms.assetid: 45fd53cd-cb84-4e12-b48d-7f2979f898ad
ms.openlocfilehash: 6d594bbeec34e400eb074c136e3467e78b35c4ee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368974"
---
# <a name="cdaoparameterinfo-structure"></a>Estrutura CDaoParameterInfo

A `CDaoParameterInfo` estrutura contém informações sobre um objeto parâmetro definido para objetos de acesso a dados (DAO). DAO 3.6 é a versão final, e é considerada obsoleta.

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
Nomeie exclusivamente o objeto parâmetro. Para obter mais informações, consulte o tópico "Propriedade de nome" no DAO Help.

*m_nType*<br/>
Um valor que indica o tipo de dados de um objeto parâmetro. Para obter uma lista dos valores possíveis, consulte o *membro m_nType* da estrutura [CDaoFieldInfo.](../../mfc/reference/cdaofieldinfo-structure.md) Para obter mais informações, consulte o tópico "Tipo propriedade" no DAO Help.

*m_varValue*<br/>
O valor do parâmetro, armazenado em um objeto [COleVariant.](../../mfc/reference/colevariant-class.md)

## <a name="remarks"></a>Comentários

As referências a Principal e Secundário acima indicam como as informações são retornadas pela função de membro [GetParameterInfo](../../mfc/reference/cdaoquerydef-class.md#getparameterinfo) na classe `CDaoQueryDef`.

O MFC não encapsula objetos de parâmetro DAO em uma classe. Objetos de consulta DAO subjacentes a objetos MFC `CDaoQueryDef` armazenam parâmetros em suas coleções de Parâmetros. Para acessar os objetos de parâmetro em um objeto [CDaoQueryDef,](../../mfc/reference/cdaoquerydef-class.md) chame a função membro do `GetParameterInfo` objeto querydef para obter um nome de parâmetro específico ou um índice na coleção Parâmetros. Você pode usar a função [cdaoQueryDef::GetParameterCount](../../mfc/reference/cdaoquerydef-class.md#getparametercount) membro em conjunto com `GetParameterInfo` para fazer loop através da coleção Parâmetros.

As informações recuperadas pela função [membro CDaoQueryDef::GetParameterInfo](../../mfc/reference/cdaoquerydef-class.md#getparameterinfo) são armazenadas em uma `CDaoParameterInfo` estrutura. Chamada `GetParameterInfo` para o objeto querydef em cujos parâmetros coletam o objeto parâmetro é armazenado.

> [!NOTE]
> Se você quiser obter ou definir apenas o valor de um parâmetro, use as funções `CDaoRecordset`de membro [GetParamValue](../../mfc/reference/cdaorecordset-class.md#getparamvalue) e [SetParamValue](../../mfc/reference/cdaorecordset-class.md#setparamvalue) da classe .

`CDaoParameterInfo`também define `Dump` uma função de membro em compilações de depuração. Você pode `Dump` usar para despejar `CDaoParameterInfo` o conteúdo de um objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdao.h

## <a name="see-also"></a>Confira também

[Estruturas, estilos, retornos de chamada e mapas de mensagem](../../mfc/reference/structures-styles-callbacks-and-message-maps.md)<br/>
[Classe CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md)
