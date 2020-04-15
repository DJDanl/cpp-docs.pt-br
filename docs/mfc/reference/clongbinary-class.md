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
ms.openlocfilehash: 1ce1daba90f3a1dad4b9627082d63f1b3405eab4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81370129"
---
# <a name="clongbinary-class"></a>Classe CLongBinary

Simplifica o trabalho com objetos de dados binários muito grandes (muitas vezes chamados de BLOBs, ou "objetos grandes binários") em um banco de dados.

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
|[CLongBinary::m_dwDataLength](#m_dwdatalength)|Contém o tamanho real em bytes do objeto `m_hData`de dados cuja alça está armazenada em .|
|[CLongBinary::m_hData](#m_hdata)|Contém uma alça HGLOBAL do Windows para o objeto de imagem real.|

## <a name="remarks"></a>Comentários

Por exemplo, um campo de registro em uma tabela SQL pode conter um bitmap representando uma imagem. Um `CLongBinary` objeto armazena tal objeto e mantém o controle de seu tamanho.

> [!NOTE]
> Em geral, é melhor praticar agora usar [CByteArray](../../mfc/reference/cbytearray-class.md) em conjunto com a função [DFX_Binary.](record-field-exchange-functions.md#dfx_binary) Você ainda `CLongBinary`pode usar, `CByteArray` mas em geral fornece mais funcionalidade em Win32, já que `CByteArray`não há mais a limitação de tamanho encontrada com 16 bits . Este conselho se aplica à programação com Dao (Data Access Objects, objetos de acesso a dados) e conectividade de banco de dados aberto (ODBC).

Para usar `CLongBinary` um objeto, declare um `CLongBinary` membro de dados de campo de tipo em sua classe de conjunto de registros. Este membro será um membro incorporado da classe recordset e será construído quando o conjunto de registros for construído. Depois `CLongBinary` que o objeto é construído, o mecanismo RFX (Record Field Exchange, troca de campo de registro) carrega o objeto de dados de um campo no registro atual na fonte de dados e armazena-o de volta ao registro quando o registro é atualizado. O RFX consulta a fonte de dados para o tamanho do objeto `CLongBinary` grande binário, aloca o armazenamento para ele (através do membro de dados do `m_hData` objeto) e armazena uma `HGLOBAL` alça para os dados em `m_hData`. O RFX também armazena o tamanho `m_dwDataLength` real do objeto de dados no membro de dados. Trabalhe com os dados `m_hData`no objeto através, usando as mesmas técnicas `HGLOBAL` que você normalmente usaria para manipular os dados armazenados em uma alça do Windows.

Quando você destrói seu conjunto `CLongBinary` de registros, o objeto incorporado também é destruído, e seu destructor desaloca o `HGLOBAL` cabo de dados.

Para obter mais informações sobre `CLongBinary`objetos grandes e o uso de , consulte os artigos [Recordset (ODBC)](../../data/odbc/recordset-odbc.md) e [Recordset: Working with Large Data Items (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

`CLongBinary`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb_.h

## <a name="clongbinaryclongbinary"></a><a name="clongbinary"></a>CLongBinary::CLongBinary

Constrói um objeto `CLongBinary`.

```
CLongBinary();
```

## <a name="clongbinarym_dwdatalength"></a><a name="m_dwdatalength"></a>CLongBinary::m_dwDataLength

Armazena o tamanho real em bytes dos dados `m_hData`armazenados na alça HGLOBAL em .

```
SQLULEN m_dwDataLength;
```

### <a name="remarks"></a>Comentários

Este tamanho pode ser menor do que o tamanho do bloco de memória alocado para os dados. Ligue para a função Win32 [GLobalSize](/windows/win32/api/winbase/nf-winbase-globalsize) para obter o tamanho alocado.

## <a name="clongbinarym_hdata"></a><a name="m_hdata"></a>CLongBinary::m_hData

Armazena uma alça Windows HGLOBAL para os dados reais de objetos grandes binários.

```
HGLOBAL m_hData;
```

## <a name="see-also"></a>Confira também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
