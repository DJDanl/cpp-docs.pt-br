---
title: Classe CLongBinary
ms.date: 11/04/2016
f1_keywords:
- CLongBinary
- AFXDB_/CLongBinary
- AFXDB_/CLongBinary::CLongBinary
- AFXDB_/CLongBinary::m_dwDataLength
- AFXDB_/CLongBinary::m_hData
helpviewer_keywords:
- CLongBinary class [MFC]
ms.assetid: f4320059-aeb4-4ee5-bc2b-25f19d898ef5
ms.openlocfilehash: 94666c0d15898e05ae78663a15d86b7d00d5c9c6
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69505680"
---
# <a name="clongbinary-class"></a>Classe CLongBinary

Simplifica o trabalho com objetos de dados binários muito grandes (geralmente chamados de BLOBs ou "objetos binários grandes") em um banco de dados.

## <a name="syntax"></a>Sintaxe

```
class CLongBinary : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CLongBinary::CLongBinary](#clongbinary)|Constrói um objeto `CLongBinary`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CLongBinary::m_dwDataLength](#m_dwdatalength)|Contém o tamanho real em bytes do objeto de dados cujo identificador está armazenado `m_hData`.|
|[CLongBinary::m_hData](#m_hdata)|Contém um identificador de HGLOBAL do Windows para o objeto de imagem real.|

## <a name="remarks"></a>Comentários

Por exemplo, um campo de registro em uma tabela SQL pode conter um bitmap que representa uma imagem. Um `CLongBinary` objeto armazena esse objeto e controla seu tamanho.

> [!NOTE]
>  Em geral, é melhor praticar agora usar [CByteArray](../../mfc/reference/cbytearray-class.md) em conjunto com a função [DFX_Binary](record-field-exchange-functions.md#dfx_binary) . Você ainda pode usar `CLongBinary`o, mas, `CByteArray` em geral, fornece mais funcionalidade no Win32, já que não há mais a limitação de tamanho encontrada `CByteArray`com 16 bits. Esse Conselho se aplica à programação com o DAO (Data Access Objects), bem como ODBC (Open Database Connectivity).

Para usar um `CLongBinary` objeto, declare um membro de dados de campo `CLongBinary` do tipo na classe do conjunto de registros. Esse membro será um membro incorporado da classe recordset e será construído quando o conjunto de registros for construído. Depois que `CLongBinary` o objeto é construído, o mecanismo de troca de campo de registro (suporte RFX) carrega o objeto de dados de um campo no registro atual na fonte de dados e o armazena de volta para o registro quando o registro é atualizado. Suporte RFX consulta a fonte de dados quanto ao tamanho do objeto binário grande, aloca o armazenamento para ele (por meio do `CLongBinary` membro de `m_hData` dados do objeto) e armazena um `HGLOBAL` identificador para os dados no `m_hData`. Suporte RFX também armazena o tamanho real do objeto de dados no membro `m_dwDataLength` de dados. Trabalhe com os dados no objeto por meio `m_hData`de, usando as mesmas técnicas que normalmente usaria para manipular os dados armazenados em um identificador `HGLOBAL` do Windows.

Quando você destrói o conjunto de registros, `CLongBinary` o objeto incorporado também é destruído e seu destruidor Desaloca o `HGLOBAL` identificador de dados.

Para obter mais informações sobre objetos grandes e o uso `CLongBinary`do, consulte o conjunto de registros de artigos [ [(ODBC)](../../data/odbc/recordset-odbc.md) e conjunto de registros: Trabalhando com itens de dados grandes (ODBC](../../data/odbc/recordset-working-with-large-data-items-odbc.md)).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CLongBinary`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb_. h

##  <a name="clongbinary"></a>  CLongBinary::CLongBinary

Constrói um objeto `CLongBinary`.

```
CLongBinary();
```

##  <a name="m_dwdatalength"></a>  CLongBinary::m_dwDataLength

Armazena o tamanho real em bytes dos dados armazenados no identificador HGLOBAL no `m_hData`.

```
SQLULEN m_dwDataLength;
```

### <a name="remarks"></a>Comentários

Esse tamanho pode ser menor do que o tamanho do bloco de memória alocado para os dados. Chame a função [GlobalSize](/windows/win32/api/winbase/nf-winbase-globalsize) do Win32 para obter o tamanho alocado.

##  <a name="m_hdata"></a>  CLongBinary::m_hData

Armazena um identificador HGLOBAL do Windows para os dados de objeto binário grande real.

```
HGLOBAL m_hData;
```

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
