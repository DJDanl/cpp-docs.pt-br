---
title: Classe CDBVariant
ms.date: 11/04/2016
f1_keywords:
- CDBVariant
- AFXDB/CDBVariant
- AFXDB/CDBVariant::CDBVariant
- AFXDB/CDBVariant::Clear
- AFXDB/CDBVariant::m_dwType
- AFXDB/CDBVariant::m_boolVal
- AFXDB/CDBVariant::m_chVal
- AFXDB/CDBVariant::m_dblVal
- AFXDB/CDBVariant::m_fltVal
- AFXDB/CDBVariant::m_iVal
- AFXDB/CDBVariant::m_lVal
- AFXDB/CDBVariant::m_pbinary
- AFXDB/CDBVariant::m_pdate
- AFXDB/CDBVariant::m_pstring
- AFXDB/CDBVariant::m_pstringA
- AFXDB/CDBVariant::m_pstringW
helpviewer_keywords:
- CDBVariant [MFC], CDBVariant
- CDBVariant [MFC], Clear
- CDBVariant [MFC], m_dwType
- CDBVariant [MFC], m_boolVal
- CDBVariant [MFC], m_chVal
- CDBVariant [MFC], m_dblVal
- CDBVariant [MFC], m_fltVal
- CDBVariant [MFC], m_iVal
- CDBVariant [MFC], m_lVal
- CDBVariant [MFC], m_pbinary
- CDBVariant [MFC], m_pdate
- CDBVariant [MFC], m_pstring
- CDBVariant [MFC], m_pstringA
- CDBVariant [MFC], m_pstringW
ms.assetid: de23609c-c560-4b24-bd6b-9d8903fd5b49
ms.openlocfilehash: 9bb70acb43f2e73ade86b753ebbb7949759ce88d
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754604"
---
# <a name="cdbvariant-class"></a>Classe CDBVariant

Representa um tipo de dados variante para as classes MFC ODBC.

## <a name="syntax"></a>Sintaxe

```
class CDBVariant
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDBVariante::CDBVariant](#cdbvariant)|Constrói um objeto `CDBVariant`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDBVariante::Limpar](#clear)|Limpa o `CDBVariant` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDBVariante::m_dwType](#m_dwtype)|Contém o tipo de dados do valor armazenado atualmente. Digite `DWORD`.|

### <a name="public-union-members"></a>Membros do Sindicato Público

|Nome|Descrição|
|----------|-----------------|
|[Variante do CDB::m_boolVal](#m_boolval)|Contém um valor do tipo **BOOL**.|
|[CDBVariante::m_chVal](#m_chval)|Contém um valor de **char tipo não assinado**.|
|[Variante do CDB::m_dblVal](#m_dblval)|Contém um valor de tipo **duplo**.|
|[Variante do CDB::m_fltVal](#m_fltval)|Contém um valor de **flutuação**tipo .|
|[CDBVariante::m_iVal](#m_ival)|Contém um valor de tipo **curto**.|
|[CDBVariante::m_lVal](#m_lval)|Contém um valor de tipo **longo**.|
|[CDBVariante::m_pbinary](#m_pbinary)|Contém um ponteiro para `CLongBinary`um objeto de tipo .|
|[CDBVariante::m_pdate](#m_pdate)|Contém um ponteiro para um objeto de tipo **TIMESTAMP_STRUCT**.|
|[CDBVariante::m_pstring](#m_pstring)|Contém um ponteiro para `CString`um objeto de tipo .|
|[CDBVariante::m_pstringA](#m_pstringa)|Armazena um ponteiro para um objeto ASCII [CString.](../../atl-mfc-shared/reference/cstringt-class.md)|
|[Variante do CDB::m_pstringW](#m_pstringw)|Armazena um ponteiro para um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) largo.|

## <a name="remarks"></a>Comentários

`CDBVariant`não tem uma classe base.

`CDBVariant`é semelhante ao [COleVariant;](../../mfc/reference/colevariant-class.md) no `CDBVariant` entanto, não usa OLE. `CDBVariant`permite que você armazene um valor sem se preocupar com o tipo de dados do valor. `CDBVariant`rastreia o tipo de dados do valor atual, que é armazenado em uma união.

A classe [CRecordset](../../mfc/reference/crecordset-class.md) utiliza `CDBVariant` objetos `GetFieldValue`em `GetBookmark`três `SetBookmark`funções de membros: , e . Por exemplo, `GetFieldValue` permite que você busque dados dinamicamente em uma coluna. Como o tipo de dados da coluna pode `GetFieldValue` não `CDBVariant` ser conhecido em tempo de execução, usa um objeto para armazenar os dados da coluna.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDBVariant`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdb.h

## <a name="cdbvariantcdbvariant"></a><a name="cdbvariant"></a>CDBVariante::CDBVariant

Cria um `CDBVariant` objeto NULL.

```
CDBVariant();
```

### <a name="remarks"></a>Comentários

Define o membro de dados [m_dwType](#m_dwtype) para DBVT_NULL.

## <a name="cdbvariantclear"></a><a name="clear"></a>CDBVariante::Limpar

Chame esta função de `CDBVariant` membro para limpar o objeto.

```cpp
void Clear();
```

### <a name="remarks"></a>Comentários

Se o valor do membro de dados [m_dwType](#m_dwtype) `Clear` for DBVT_DATE, DBVT_STRING ou DBVT_BINARY, liberará a memória associada ao membro do ponteiro do sindicato. `Clear`se `m_dwType` DBVT_NULL.

O `CDBVariant` destruidor chama. `Clear`

## <a name="cdbvariantm_boolval"></a><a name="m_boolval"></a>Variante do CDB::m_boolVal

Armazena um valor do tipo BOOL.

### <a name="remarks"></a>Comentários

O `m_boolVal` membro dos dados pertence a um sindicato. Antes de `m_boolVal`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` for definido como `m_boolVal` DBVT_BOOL, então conterá um valor válido; caso contrário, `m_boolVal` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_chval"></a><a name="m_chval"></a>CDBVariante::m_chVal

Armazena um valor de **char tipo não assinado**.

### <a name="remarks"></a>Comentários

O `m_chVal` membro dos dados pertence a um sindicato. Antes de `m_chVal`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_chVal` DBVT_UCHAR, então contém um valor válido; caso contrário, `m_chVal` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_dblval"></a><a name="m_dblval"></a>Variante do CDB::m_dblVal

Armazena um valor de tipo **duplo**.

### <a name="remarks"></a>Comentários

O `m_dblVal` membro dos dados pertence a um sindicato. Antes de `m_dblVal`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` for definido como `m_dblVal` DBVT_DOUBLE, então contém um valor válido; caso contrário, `m_dblVal` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_dwtype"></a><a name="m_dwtype"></a>CDBVariante::m_dwType

Este membro de dados contém o tipo de dados `CDBVariant` para o valor que está atualmente armazenado no membro de dados da união do objeto.

### <a name="remarks"></a>Comentários

Antes de acessar este sindicato, você `m_dwType` deve verificar o valor de para determinar qual membro da união de dados acessar. A tabela a seguir `m_dwType` lista os possíveis valores para e o membro correspondente dos dados da União.

|M_dwtype|Membro de dados da União|
|---------------|-----------------------|
|DBVT_NULL|Nenhum membro do sindicato é válido para acesso.|
|DBVT_BOOL|[M_boolval](#m_boolval)|
|DBVT_UCHAR|[m_chVal](#m_chval)|
|DBVT_SHORT|[m_iVal](#m_ival)|
|DBVT_LONG|[m_lVal](#m_lval)|
|DBVT_SINGLE|[m_fltVal](#m_fltval)|
|DBVT_DOUBLE|[m_dblVal](#m_dblval)|
|DBVT_DATE|[m_pdate](#m_pdate)|
|DBVT_STRING|[M_pstring](#m_pstring)|
|DBVT_BINARY|[m_pbinary](#m_pbinary)|
|DBVT_ASTRING|[M_pstringa](#m_pstringa)|
|DBVT_WSTRING|[m_pstringW](#m_pstringw)|

## <a name="cdbvariantm_fltval"></a><a name="m_fltval"></a>Variante do CDB::m_fltVal

Armazena um valor de **tipo flutuante**.

### <a name="remarks"></a>Comentários

O `m_fltVal` membro dos dados pertence a um sindicato. Antes de `m_fltVal`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_fltVal` DBVT_SINGLE, então contém um valor válido; caso contrário, `m_fltVal` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_ival"></a><a name="m_ival"></a>CDBVariante::m_iVal

Armazena um valor de tipo **curto**.

### <a name="remarks"></a>Comentários

O `m_iVal` membro dos dados pertence a um sindicato. Antes de `m_iVal`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_iVal` DBVT_SHORT, então contém um valor válido; caso contrário, `m_iVal` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_lval"></a><a name="m_lval"></a>CDBVariante::m_lVal

Armazena um valor de tipo **longo**.

### <a name="remarks"></a>Comentários

O `m_lVal` membro dos dados pertence a um sindicato. Antes de `m_lVal`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_lVal` DBVT_LONG, então contém um valor válido; caso contrário, `m_lVal` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_pbinary"></a><a name="m_pbinary"></a>CDBVariante::m_pbinary

Armazena um ponteiro para um objeto do tipo [CLongBinary](../../mfc/reference/clongbinary-class.md).

### <a name="remarks"></a>Comentários

O `m_pbinary` membro dos dados pertence a um sindicato. Antes de `m_pbinary`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_pbinary` DBVT_BINARY, então contenha um ponteiro válido; caso contrário, `m_pbinary` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_pdate"></a><a name="m_pdate"></a>CDBVariante::m_pdate

Armazena um ponteiro para um objeto de tipo TIMESTAMP_STRUCT.

### <a name="remarks"></a>Comentários

O `m_pdate` membro dos dados pertence a um sindicato. Antes de `m_pdate`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_pdate` DBVT_DATE, então contenha um ponteiro válido; caso contrário, `m_pdate` o acesso produzirá resultados não confiáveis.

Para obter mais informações sobre o TIMESTAMP_STRUCT tipo de dados, consulte o tópico [C Data Types](/sql/odbc/reference/appendixes/c-data-types) in Apêndice D da Referência do *Programador ODBC* no Windows SDK.

## <a name="cdbvariantm_pstring"></a><a name="m_pstring"></a>CDBVariante::m_pstring

Armazena um ponteiro para um objeto do tipo [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

O `m_pstring` membro dos dados pertence a um sindicato. Antes de `m_pstring`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_pstring` DBVT_STRING, então contenha um ponteiro válido; caso contrário, `m_pstring` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_pstringa"></a><a name="m_pstringa"></a>CDBVariante::m_pstringA

Armazena um ponteiro para um objeto ASCII [CString.](../../atl-mfc-shared/reference/cstringt-class.md)

### <a name="remarks"></a>Comentários

O `m_pstringA` membro dos dados pertence a um sindicato. Antes de `m_pstringA`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_pstringA` DBVT_ASTRING, então contenha um ponteiro válido; caso contrário, `m_pstringA` o acesso produzirá resultados não confiáveis.

## <a name="cdbvariantm_pstringw"></a><a name="m_pstringw"></a>Variante do CDB::m_pstringW

Armazena um ponteiro para um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) largo.

### <a name="remarks"></a>Comentários

O `m_pstringW` membro dos dados pertence a um sindicato. Antes de `m_pstringW`acessar, primeiro verifique o valor de [CDBVariant::m_dwType](#m_dwtype). Se `m_dwType` estiver definido como `m_pstringW` DBVT_WSTRING, então contenha um ponteiro válido; caso contrário, `m_pstringW` o acesso produzirá resultados não confiáveis.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
