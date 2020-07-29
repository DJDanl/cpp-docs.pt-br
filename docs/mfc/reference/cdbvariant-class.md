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
ms.openlocfilehash: 45a478a5ca6cfb4d9b976a29eae2ae7d98fdd6ee
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223077"
---
# <a name="cdbvariant-class"></a>Classe CDBVariant

Representa um tipo de dados Variant para as classes ODBC do MFC.

## <a name="syntax"></a>Sintaxe

```
class CDBVariant
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDBVariant::CDBVariant](#cdbvariant)|Constrói um objeto `CDBVariant`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDBVariant:: Clear](#clear)|Limpa o `CDBVariant` objeto.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDBVariant:: m_dwType](#m_dwtype)|Contém o tipo de dados do valor armazenado no momento. Digite `DWORD`.|

### <a name="public-union-members"></a>Membros da União pública

|Nome|Descrição|
|----------|-----------------|
|[CDBVariant:: m_boolVal](#m_boolval)|Contém um valor do tipo **bool**.|
|[CDBVariant:: m_chVal](#m_chval)|Contém um valor do tipo **`unsigned char`** .|
|[CDBVariant:: m_dblVal](#m_dblval)|Contém um valor do tipo **`double`** .|
|[CDBVariant:: m_fltVal](#m_fltval)|Contém um valor do tipo **`float`** .|
|[CDBVariant:: m_iVal](#m_ival)|Contém um valor do tipo **`short`** .|
|[CDBVariant:: m_lVal](#m_lval)|Contém um valor do tipo **`long`** .|
|[CDBVariant:: m_pbinary](#m_pbinary)|Contém um ponteiro para um objeto do tipo `CLongBinary` .|
|[CDBVariant:: m_pdate](#m_pdate)|Contém um ponteiro para um objeto do tipo **TIMESTAMP_STRUCT**.|
|[CDBVariant:: m_pstring](#m_pstring)|Contém um ponteiro para um objeto do tipo `CString` .|
|[CDBVariant:: m_pstringA](#m_pstringa)|Armazena um ponteiro para um objeto de [CSTRING](../../atl-mfc-shared/reference/cstringt-class.md) ASCII.|
|[CDBVariant:: m_pstringW](#m_pstringw)|Armazena um ponteiro para um objeto de [CString](../../atl-mfc-shared/reference/cstringt-class.md) maior.|

## <a name="remarks"></a>Comentários

`CDBVariant`Não tem uma classe base.

`CDBVariant`é semelhante a [COleVariant](../../mfc/reference/colevariant-class.md); no entanto, `CDBVariant` o não usa OLE. `CDBVariant`permite que você armazene um valor sem se preocupar com o tipo de dados do valor. `CDBVariant`controla o tipo de dados do valor atual, que é armazenado em uma União.

A classe [CRecordset](../../mfc/reference/crecordset-class.md) utiliza `CDBVariant` objetos em três funções de membro: `GetFieldValue` , `GetBookmark` e `SetBookmark` . Por exemplo, `GetFieldValue` permite que você busque dados dinamicamente em uma coluna. Como o tipo de dados da coluna pode não ser conhecido em tempo de execução, o `GetFieldValue` usa um `CDBVariant` objeto para armazenar os dados da coluna.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDBVariant`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDB. h

## <a name="cdbvariantcdbvariant"></a><a name="cdbvariant"></a>CDBVariant::CDBVariant

Cria um `CDBVariant` objeto nulo.

```
CDBVariant();
```

### <a name="remarks"></a>Comentários

Define o membro de dados de [m_dwType](#m_dwtype) como DBVT_NULL.

## <a name="cdbvariantclear"></a><a name="clear"></a>CDBVariant:: Clear

Chame essa função de membro para limpar o `CDBVariant` objeto.

```cpp
void Clear();
```

### <a name="remarks"></a>Comentários

Se o valor do membro de dados [m_dwType](#m_dwtype) for DBVT_DATE, DBVT_STRING ou DBVT_BINARY, `Clear` liberará a memória associada ao membro do ponteiro Union. `Clear`define `m_dwType` como DBVT_NULL.

O `CDBVariant` destruidor chama `Clear` .

## <a name="cdbvariantm_boolval"></a><a name="m_boolval"></a>CDBVariant:: m_boolVal

Armazena um valor do tipo BOOL.

### <a name="remarks"></a>Comentários

O `m_boolVal` membro de dados pertence a uma União. Antes de acessar `m_boolVal` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` for definido como DBVT_BOOL, `m_boolVal` conterá um valor válido; caso contrário, o acesso `m_boolVal` produzirá resultados não confiáveis.

## <a name="cdbvariantm_chval"></a><a name="m_chval"></a>CDBVariant:: m_chVal

Armazena um valor do tipo **`unsigned char`** .

### <a name="remarks"></a>Comentários

O `m_chVal` membro de dados pertence a uma União. Antes de acessar `m_chVal` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_UCHAR, `m_chVal` contém um valor válido; caso contrário, o acesso `m_chVal` produzirá resultados não confiáveis.

## <a name="cdbvariantm_dblval"></a><a name="m_dblval"></a>CDBVariant:: m_dblVal

Armazena um valor do tipo **`double`** .

### <a name="remarks"></a>Comentários

O `m_dblVal` membro de dados pertence a uma União. Antes de acessar `m_dblVal` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_DOUBLE, `m_dblVal` contém um valor válido; caso contrário, o acesso `m_dblVal` produzirá resultados não confiáveis.

## <a name="cdbvariantm_dwtype"></a><a name="m_dwtype"></a>CDBVariant:: m_dwType

Esse membro de dados contém o tipo de dados para o valor que está atualmente armazenado no `CDBVariant` membro de dados de União do objeto.

### <a name="remarks"></a>Comentários

Antes de acessar essa União, você deve verificar o valor de `m_dwType` para determinar qual membro de dados de União acessar. A tabela a seguir lista os possíveis valores para `m_dwType` e o membro de dados Union correspondente.

|m_dwType|Membro de dados de União|
|---------------|-----------------------|
|DBVT_NULL|Nenhum membro de União é válido para acesso.|
|DBVT_BOOL|[m_boolVal](#m_boolval)|
|DBVT_UCHAR|[m_chVal](#m_chval)|
|DBVT_SHORT|[m_iVal](#m_ival)|
|DBVT_LONG|[m_lVal](#m_lval)|
|DBVT_SINGLE|[m_fltVal](#m_fltval)|
|DBVT_DOUBLE|[m_dblVal](#m_dblval)|
|DBVT_DATE|[m_pdate](#m_pdate)|
|DBVT_STRING|[m_pstring](#m_pstring)|
|DBVT_BINARY|[m_pbinary](#m_pbinary)|
|DBVT_ASTRING|[m_pstringA](#m_pstringa)|
|DBVT_WSTRING|[m_pstringW](#m_pstringw)|

## <a name="cdbvariantm_fltval"></a><a name="m_fltval"></a>CDBVariant:: m_fltVal

Armazena um valor do tipo **`float`** .

### <a name="remarks"></a>Comentários

O `m_fltVal` membro de dados pertence a uma União. Antes de acessar `m_fltVal` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_SINGLE, `m_fltVal` contém um valor válido; caso contrário, o acesso `m_fltVal` produzirá resultados não confiáveis.

## <a name="cdbvariantm_ival"></a><a name="m_ival"></a>CDBVariant:: m_iVal

Armazena um valor do tipo **`short`** .

### <a name="remarks"></a>Comentários

O `m_iVal` membro de dados pertence a uma União. Antes de acessar `m_iVal` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_SHORT, `m_iVal` contém um valor válido; caso contrário, o acesso `m_iVal` produzirá resultados não confiáveis.

## <a name="cdbvariantm_lval"></a><a name="m_lval"></a>CDBVariant:: m_lVal

Armazena um valor do tipo **`long`** .

### <a name="remarks"></a>Comentários

O `m_lVal` membro de dados pertence a uma União. Antes de acessar `m_lVal` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_LONG, `m_lVal` contém um valor válido; caso contrário, o acesso `m_lVal` produzirá resultados não confiáveis.

## <a name="cdbvariantm_pbinary"></a><a name="m_pbinary"></a>CDBVariant:: m_pbinary

Armazena um ponteiro para um objeto do tipo [CLongBinary](../../mfc/reference/clongbinary-class.md).

### <a name="remarks"></a>Comentários

O `m_pbinary` membro de dados pertence a uma União. Antes de acessar `m_pbinary` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_BINARY, `m_pbinary` contém um ponteiro válido; caso contrário, o acesso `m_pbinary` produzirá resultados não confiáveis.

## <a name="cdbvariantm_pdate"></a><a name="m_pdate"></a>CDBVariant:: m_pdate

Armazena um ponteiro para um objeto do tipo TIMESTAMP_STRUCT.

### <a name="remarks"></a>Comentários

O `m_pdate` membro de dados pertence a uma União. Antes de acessar `m_pdate` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_DATE, `m_pdate` contém um ponteiro válido; caso contrário, o acesso `m_pdate` produzirá resultados não confiáveis.

Para obter mais informações sobre o tipo de dados TIMESTAMP_STRUCT, consulte o tópico [tipos de dados C](/sql/odbc/reference/appendixes/c-data-types) no Apêndice D da *referência do programador de ODBC* no SDK do Windows.

## <a name="cdbvariantm_pstring"></a><a name="m_pstring"></a>CDBVariant:: m_pstring

Armazena um ponteiro para um objeto do tipo [CString](../../atl-mfc-shared/reference/cstringt-class.md).

### <a name="remarks"></a>Comentários

O `m_pstring` membro de dados pertence a uma União. Antes de acessar `m_pstring` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_STRING, `m_pstring` contém um ponteiro válido; caso contrário, o acesso `m_pstring` produzirá resultados não confiáveis.

## <a name="cdbvariantm_pstringa"></a><a name="m_pstringa"></a>CDBVariant:: m_pstringA

Armazena um ponteiro para um objeto de [CSTRING](../../atl-mfc-shared/reference/cstringt-class.md) ASCII.

### <a name="remarks"></a>Comentários

O `m_pstringA` membro de dados pertence a uma União. Antes de acessar `m_pstringA` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_ASTRING, `m_pstringA` contém um ponteiro válido; caso contrário, o acesso `m_pstringA` produzirá resultados não confiáveis.

## <a name="cdbvariantm_pstringw"></a><a name="m_pstringw"></a>CDBVariant:: m_pstringW

Armazena um ponteiro para um objeto de [CString](../../atl-mfc-shared/reference/cstringt-class.md) maior.

### <a name="remarks"></a>Comentários

O `m_pstringW` membro de dados pertence a uma União. Antes de acessar `m_pstringW` , primeiro verifique o valor de [CDBVariant:: m_dwType](#m_dwtype). Se `m_dwType` é definido como DBVT_WSTRING, `m_pstringW` contém um ponteiro válido; caso contrário, o acesso `m_pstringW` produzirá resultados não confiáveis.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
