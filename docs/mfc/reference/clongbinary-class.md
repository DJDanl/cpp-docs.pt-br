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
ms.openlocfilehash: a7dbb7e38ec01743d994dafd6c7945e306de51ed
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50656022"
---
# <a name="clongbinary-class"></a>Classe CLongBinary

Simplifica o trabalho com dados binários muito grandes objetos (geralmente chamados de BLOBs ou "objetos binários grandes") em um banco de dados.

## <a name="syntax"></a>Sintaxe

```
class CLongBinary : public CObject
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CLongBinary::CLongBinary](#clongbinary)|Constrói um objeto `CLongBinary`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CLongBinary::m_dwDataLength](#m_dwdatalength)|Contém o tamanho real em bytes do objeto de dados cujo identificador é armazenado em `m_hData`.|
|[CLongBinary::m_hData](#m_hdata)|Contém um identificador de HGLOBAL do Windows para o objeto de imagem real.|

## <a name="remarks"></a>Comentários

Por exemplo, um campo de registro em uma tabela SQL pode conter um bitmap que representa uma imagem. Um `CLongBinary` objeto armazena esse objeto e mantém o controle de seu tamanho.

> [!NOTE]
>  Em geral, é uma prática recomendada agora usam [CByteArray](../../mfc/reference/cbytearray-class.md) em conjunto com o [DFX_Binary](record-field-exchange-functions.md#dfx_binary) função. Você ainda pode usar `CLongBinary`, mas em geral `CByteArray` fornece mais funcionalidade em Win32, já que não há não mais a limitação de tamanho encontrada com 16 bits `CByteArray`. Esse conselho se aplica a programação com objetos de acesso a dados (DAO), bem como conectividade aberta de banco de dados (ODBC).

Para usar um `CLongBinary` objeto, declarar um membro de dados do campo de tipo `CLongBinary` em sua classe de conjunto de registros. Esse membro será um membro inserido da classe de conjunto de registros e será criado quando o conjunto de registros é construído. Após o `CLongBinary` objeto é construído, o mecanismo do exchange (RFX) de campos de registro carrega o objeto de dados de um campo no registro atual na fonte de dados e armazena-o novamente para o registro quando o registro é atualizado. RFX consulta a fonte de dados para o tamanho do objeto binário grande, aloca armazenamento para ele (via o `CLongBinary` do objeto `m_hData` membro de dados) e armazena um `HGLOBAL` tratar-se aos dados no `m_hData`. RFX também armazena o tamanho real do objeto de dados no `m_dwDataLength` membro de dados. Trabalhar com os dados no objeto por meio `m_hData`, usando as mesmas técnicas que você normalmente usaria para manipular os dados armazenados em um Windows `HGLOBAL` manipular.

Quando você destruir seu conjunto de registros, o embedded `CLongBinary` objeto também é destruído e seu destruidor desaloca a `HGLOBAL` identificador de dados.

Para obter mais informações sobre objetos grandes e o uso de `CLongBinary`, consulte os artigos [conjunto de registros (ODBC)](../../data/odbc/recordset-odbc.md) e [conjunto de registros: Trabalhando com itens de dados grandes (ODBC)](../../data/odbc/recordset-working-with-large-data-items-odbc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CLongBinary`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb_.h

##  <a name="clongbinary"></a>  CLongBinary::CLongBinary

Constrói um objeto `CLongBinary`.

```
CLongBinary();
```

##  <a name="m_dwdatalength"></a>  CLongBinary::m_dwDataLength

Armazena o tamanho real em bytes dos dados armazenados no identificador de HGLOBAL em `m_hData`.

```
SQLULEN m_dwDataLength;
```

### <a name="remarks"></a>Comentários

Esse tamanho pode ser menor que o tamanho do bloco de memória alocado para os dados. Chame o Win32 [GLobalSize](/windows/desktop/api/winbase/nf-winbase-globalsize) função para obter o tamanho alocado.

##  <a name="m_hdata"></a>  CLongBinary::m_hData

Armazena um identificador do Windows HGLOBAL para os dados reais de objeto binário grande.

```
HGLOBAL m_hData;
```

## <a name="see-also"></a>Consulte também

[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
