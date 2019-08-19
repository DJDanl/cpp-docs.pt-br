---
title: Classe COleVariant
ms.date: 11/04/2016
f1_keywords:
- COleVariant
- AFXDISP/COleVariant
- AFXDISP/COleVariant::COleVariant
- AFXDISP/COleVariant::Attach
- AFXDISP/COleVariant::ChangeType
- AFXDISP/COleVariant::Clear
- AFXDISP/COleVariant::Detach
- AFXDISP/COleVariant::GetByteArrayFromVariantArray
- AFXDISP/COleVariant::SetString
helpviewer_keywords:
- COleVariant [MFC], COleVariant
- COleVariant [MFC], Attach
- COleVariant [MFC], ChangeType
- COleVariant [MFC], Clear
- COleVariant [MFC], Detach
- COleVariant [MFC], GetByteArrayFromVariantArray
- COleVariant [MFC], SetString
ms.assetid: e1b5cd4a-b066-4b9b-b48b-6215ed52d998
ms.openlocfilehash: 0676f4896401ab777570666236c4639ad94c3a05
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503047"
---
# <a name="colevariant-class"></a>Classe COleVariant

Encapsula o tipo de dados [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) .

## <a name="syntax"></a>Sintaxe

```
class COleVariant : public tagVARIANT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleVariant::COleVariant](#colevariant)|Constrói um objeto `COleVariant`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleVariant::Attach](#attach)|Anexa uma variante a um `COleVariant`.|
|[COleVariant::ChangeType](#changetype)|Altera o tipo de `COleVariant` variante deste objeto.|
|[COleVariant::Clear](#clear)|Limpa esse objeto `COleVariant`.|
|[COleVariant::Detach](#detach)|Desanexa uma variante de a `COleVariant` e retorna a variante.|
|[COleVariant::GetByteArrayFromVariantArray](#getbytearrayfromvariantarray)|Recupera uma matriz de bytes de uma matriz Variant existente.|
|[COleVariant::SetString](#setstring)|Define a cadeia de caracteres para um tipo específico, normalmente ANSI.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador COleVariant:: Operator LPCVARIANT](#operator_lpcvariant)|Converte um `COleVariant` valor em um `LPCVARIANT`.|
|[Operador COleVariant:: Operator LPVARIANT](#operator_lpvariant)|Converte um `COleVariant` objeto em um `LPVARIANT`.|
|[COleVariant:: Operator =](#operator_eq)|Copia um `COleVariant` valor.|
|[COleVariant::operator ==](#operator_eq_eq)|Compara dois `COleVariant` valores.|
|[&lt; Operador&lt;COleVariant::,&gt;&gt;](#operator_lt_lt__gt_gt)|Gera um `COleVariant` valor para `CArchive` ou `CDumpContext` e insere um `COleVariant` objeto de `CArchive`.|

## <a name="remarks"></a>Comentários

Esse tipo de dados é usado na automação OLE. Especificamente, a estrutura [DISPPARAMS](/windows/win32/api/oaidl/ns-oaidl-tagdispparams) contém um ponteiro para uma matriz de estruturas Variant. Uma `DISPPARAMS` estrutura é usada para passar parâmetros para [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke).

> [!NOTE]
> Essa classe é derivada da `VARIANT` estrutura. Isso significa que você pode passar `COleVariant` um em um parâmetro que chama um `VARIANT` e que `VARIANT` os membros de dados da estrutura são membros de dados acessíveis `COleVariant`do.

As duas classes do MFC relacionadas [COleCurrency](../../mfc/reference/colecurrency-class.md) e [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) encapsulam a moeda dos tipos de `VT_CY`dados Variant () `VT_DATE`e Date (). A `COleVariant` classe é usada extensivamente nas classes DAO; Veja essas classes para uso típico dessa classe, por exemplo, [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant), [Currency](/windows/win32/api/wtypes/ns-wtypes-cy), [DISPPARAMS](/windows/win32/api/oaidl/ns-oaidl-tagdispparams)e [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) no SDK do Windows.

Para obter mais informações sobre `COleVariant` a classe e seu uso na automação OLE, consulte "passando parâmetros na automação OLE" no artigo [automação](../../mfc/automation.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagVARIANT`

`COleVariant`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

##  <a name="attach"></a>  COleVariant::Attach

Chame essa função para anexar o objeto [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) fornecido ao objeto atual `COleVariant` .

```
void Attach(VARIANT& varSrc);
```

### <a name="parameters"></a>Parâmetros

*varSrc*<br/>
Um objeto `VARIANT` existente a ser anexado ao objeto atual `COleVariant` .

### <a name="remarks"></a>Comentários

Essa função define o VARTYPE de *varSrc* como VT_EMPTY.

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) e [VarEnum](/windows/win32/api/wtypes/ne-wtypes-varenum) no SDK do Windows.

##  <a name="colevariant"></a>  COleVariant::COleVariant

Constrói um objeto `COleVariant`.

```
COleVariant();
COleVariant(const VARIANT& varSrc);
COleVariant(const COleVariant& varSrc);
COleVariant(LPCVARIANT pSrc);
COleVariant(LPCTSTR lpszSrc);
COleVariant(LPCTSTR lpszSrc, VARTYPE vtSrc);
COleVariant(CString& strSrc);
COleVariant(BYTE nSrc);
COleVariant(short nSrc, VARTYPE vtSrc = VT_I2);
COleVariant(long lSrc,VARTYPE vtSrc = VT_I4);
COleVariant(const COleCurrency& curSrc);
COleVariant(float fltSrc);
COleVariant(double dblSrc);
COleVariant(const COleDateTime& timeSrc);
COleVariant(const CByteArray& arrSrc);
COleVariant(const CLongBinary& lbSrc);
COleVariant(LPCITEMIDLIST pidl);
```

### <a name="parameters"></a>Parâmetros

*varSrc*<br/>
Um objeto `COleVariant` existente `VARIANT` ou a ser copiado para o `COleVariant` novo objeto.

*pSrc*<br/>
Um ponteiro para um `VARIANT` objeto que será copiado para o novo `COleVariant` objeto.

*lpszSrc*<br/>
Uma cadeia de caracteres terminada em nulo a ser copiada para o novo `COleVariant` objeto.

*vtSrc*<br/>
O `VARTYPE` para o novo `COleVariant` objeto.

*strSrc*<br/>
Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) a ser copiado para o `COleVariant` novo objeto.

*nSrc*, *lSrc* um valor numérico a ser copiado para o novo `COleVariant` objeto.

*vtSrc*<br/>
O `VARTYPE` para o novo `COleVariant` objeto.

*curSrc*<br/>
Um objeto [COleCurrency](../../mfc/reference/colecurrency-class.md) a ser copiado para o `COleVariant` novo objeto.

*fltSrc*, *dblSrc*<br/>
Um valor numérico a ser copiado no novo objeto `COleVariant`.

*timeSrc*<br/>
Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) a ser copiado para o `COleVariant` novo objeto.

*arrSrc*<br/>
Um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) a ser copiado para o `COleVariant` novo objeto.

*lbSrc*<br/>
Um objeto [CLongBinary](../../mfc/reference/clongbinary-class.md) a ser copiado para o `COleVariant` novo objeto.

*pidl*<br/>
Um ponteiro para uma estrutura [ITEMIDLIST](/windows/win32/api/shtypes/ns-shtypes-itemidlist) a ser copiada para o novo objeto `COleVariant`.

### <a name="remarks"></a>Comentários

Todos esses construtores criam novos `COleVariant` objetos inicializados para o valor especificado. Segue uma breve descrição de cada um desses construtores.

- **COleVariant ()** Cria um objeto `COleVariant` vazio, VT_EMPTY.

- **COleVariant (** *varSrc* **)** Copia um objeto `VARIANT` ou `COleVariant` existente. O tipo de variante é mantido.

- **COleVariant (** *pSrc* **)** Copia um objeto `VARIANT` ou `COleVariant` existente. O tipo de variante é mantido.

- **COleVariant (** *lpszSrc* **)** Copia uma cadeia de caracteres no novo objeto, VT_BSTR (UNICODE).

- **COleVariant (** *lpszSrc* **,** *vtSrc* **)** Copia uma cadeia de caracteres no novo objeto. O parâmetro *vtSrc* deve ser VT_BSTR (Unicode) ou VT_BSTRT (ANSI).

- **COleVariant (** *strSrc* **)** Copia uma cadeia de caracteres no novo objeto, VT_BSTR (UNICODE).

- **COleVariant (** *nSrc* **)** Copia um inteiro de 8 bits no novo objeto, VT_UI1.

- **COleVariant (** *nSrc* **,** *vtSrc* **)** Copia um inteiro de 16 bits (ou valor booliano) para o novo objeto. O parâmetro *vtSrc* deve ser VT_I2 ou VT_BOOL.

- **COleVariant (** *lSrc* **,** *vtSrc* **)** Copia um inteiro de 32 bits (ou valor SCODE) no novo objeto. O parâmetro *vtSrc* deve ser VT_I4, VT_ERROR ou VT_BOOL.

- **COleVariant (** *curSrc* **)** Copia um `COleCurrency` valor para o novo objeto, VT_CY.

- **COleVariant (** *fltSrc* **)** Copia um valor de ponto flutuante de 32 bits para o novo objeto, VT_R4.

- **COleVariant (** *dblSrc* **)** Copia um valor de ponto flutuante de 64 bits para o novo objeto, VT_R8.

- **COleVariant (** *timeSrc* **)** Copia um `COleDateTime` valor para o novo objeto, VT_DATE.

- **COleVariant (** *arrSrc* **)** Copia um `CByteArray` objeto para o novo objeto, VT_EMPTY.

- **COleVariant (** *lbSrc* **)** Copia um `CLongBinary` objeto para o novo objeto, VT_EMPTY.

Para obter mais informações sobre SCODE, consulte [estrutura de códigos de erro com](/windows/win32/com/structure-of-com-error-codes) no SDK do Windows.

##  <a name="changetype"></a>  COleVariant::ChangeType

Converte o tipo de valor de variante neste `COleVariant` objeto.

```
void ChangeType(VARTYPE vartype, LPVARIANT pSrc = NULL);
```

### <a name="parameters"></a>Parâmetros

*VarType*<br/>
O VarType deste `COleVariant` objeto.

*pSrc*<br/>
Um ponteiro para o objeto [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) a ser convertido. Se esse valor for nulo, esse `COleVariant` objeto será usado como a origem da conversão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant), [VarEnum](/windows/win32/api/wtypes/ne-wtypes-varenum)e [VariantChangeType](/windows/win32/api/oleauto/nf-oleauto-variantchangetype) no SDK do Windows.

##  <a name="clear"></a>  COleVariant::Clear

Limpa o `VARIANT`.

```
void Clear();
```

### <a name="remarks"></a>Comentários

Isso define o VARTYPE para esse objeto como VT_EMPTY. O `COleVariant` destruidor chama essa função.

Para obter mais informações, consulte `VARIANT`o, VARTYPE e `VariantClear` entradas no SDK do Windows.

##  <a name="detach"></a>  COleVariant::Detach

Desanexa o objeto `COleVariant` [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) subjacente deste objeto.

```
VARIANT Detach();
```

### <a name="remarks"></a>Comentários

Essa função define o VarType para esse `COleVariant` objeto como VT_EMPTY.

> [!NOTE]
>  Depois de `Detach`chamar, é responsabilidade do chamador chamar `VariantClear` na estrutura resultante `VARIANT` .

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant), [VarEnum](/windows/win32/api/wtypes/ne-wtypes-varenum)e [VariantClear](/windows/win32/api/oleauto/nf-oleauto-variantclear) no SDK do Windows.

##  <a name="getbytearrayfromvariantarray"></a>  COleVariant::GetByteArrayFromVariantArray

Recupera uma matriz de bytes de uma matriz Variant existente

```
void GetByteArrayFromVariantArray(CByteArray& bytes);
```

### <a name="parameters"></a>Parâmetros

*bytes*<br/>
Uma referência a um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) existente.

##  <a name="operator_lpcvariant"></a>Operador COleVariant:: Operator LPCVARIANT

Esse operador de conversão retorna `VARIANT` uma estrutura cujo valor é copiado `COleVariant` deste objeto.

```
operator LPCVARIANT() const;
```

### <a name="remarks"></a>Comentários

##  <a name="operator_lpvariant"></a>Operador COleVariant:: Operator LPVARIANT

Chame esse operador de conversão para acessar a `VARIANT` estrutura subjacente desse `COleVariant` objeto.

```
operator LPVARIANT();
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Alterar o valor na `VARIANT` estrutura acessado pelo ponteiro retornado por essa função alterará o valor `COleVariant` desse objeto.

##  <a name="operator_eq"></a>  COleVariant::operator =

Esses operadores de atribuição sobrecarregados copiam o valor `COleVariant` de origem nesse objeto.

```
const COleVariant& operator=(const VARIANT& varSrc);
const COleVariant& operator=(LPCVARIANT pSrc);
const COleVariant& operator=(const COleVariant& varSrc);
const COleVariant& operator=(const LPCTSTR lpszSrc);
const COleVariant& operator=(const CString& strSrc);
const COleVariant& operator=(BYTE nSrc);
const COleVariant& operator=(short nSrc);
const COleVariant& operator=(long lSrc);
const COleVariant& operator=(const COleCurrency& curSrc);
const COleVariant& operator=(float fltSrc);
const COleVariant& operator=(double dblSrc);
const COleVariant& operator=(const COleDateTime& dateSrc);
const COleVariant& operator=(const CByteArray& arrSrc);
const COleVariant& operator=(const CLongBinary& lbSrc);
```

### <a name="remarks"></a>Comentários

Segue uma breve descrição de cada operador:

- **Operator = (** *varSrc* **)** Copia uma variante ou `COleVariant` objeto existente para este objeto.

- **Operator = (** *pSrc* **)** Copia o objeto VARIANT acessado por *pSrc* nesse objeto.

- **Operator = (** *lpszSrc* **)** Copia uma cadeia de caracteres terminada em nulo nesse objeto e define o VARTYPE como VT_BSTR.

- **Operator = (** *strSrc* **)** Copia um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) nesse objeto e define o VarType como VT_BSTR.

- **Operator = (** *nSrc* **)** Copia um valor inteiro de 8 ou 16 bits nesse objeto. Se *nSrc* for um valor de 8 bits, o VarType será definido como VT_UI1. Se *nSrc* for um valor de 16 bits e o VarType de isso for VT_BOOL, ele será mantido; caso contrário, ele será definido como VT_I2.

- **Operator = (** *lSrc* **)** Copia um valor inteiro de 32 bits para esse objeto. Se o VARTYPE de isso for VT_ERROR, ele será mantido; caso contrário, ele será definido como VT_I4.

- **Operator = (** *curSrc* **)** Copia um objeto [COleCurrency](../../mfc/reference/colecurrency-class.md) nesse objeto e define o VarType como VT_CY.

- **Operator = (** *fltSrc* **)** Copia um valor de ponto flutuante de 32 bits para esse objeto e define o VARTYPE como VT_R4.

- **Operator = (** *dblSrc* **)** Copia um valor de ponto flutuante de 64 bits para esse objeto e define o VARTYPE como VT_R8.

- **Operator = (** *dateSrc* **)** Copia um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) nesse objeto e define o VarType como VT_DATE.

- **Operator = (** *arrSrc* **)** Copia um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) nesse objeto `COleVariant`.

- **Operator = (** *lbSrc* **)** Copia um objeto [CLongBinary](../../mfc/reference/clongbinary-class.md) nesse objeto `COleVariant`.

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) e [VarEnum](/windows/win32/api/wtypes/ne-wtypes-varenum) no SDK do Windows.

##  <a name="operator_eq_eq"></a>  COleVariant::operator ==

Esse operador compara dois valores variantes e retorna zero, se forem iguais; caso contrário, 0.

```
BOOL operator==(const VARIANT& varSrc) const;
BOOL operator==(LPCVARIANT pSrc) const;
```

##  <a name="operator_lt_lt__gt_gt"></a>&lt; Operador&lt;COleVariant::,&gt;&gt;

Gera um `COleVariant` valor para `CArchive` ou `CdumpContext` e insere um `COleVariant` objeto de `CArchive`.

```
friend CDumpContext& AFXAPI operator<<(
    CDumpContext& dc,
    OleVariant varSrc);

friend CArchive& AFXAPI operator<<(
    CArchive& ar,
    COleVariant varSrc);

friend CArchive& AFXAPI operator>>(
    CArchive& ar,
    COleVariant& varSrc);
```

### <a name="remarks"></a>Comentários

O `COleVariant` operador de **\<inserção(\<** ) dá suporte ao despejo de diagnóstico e ao armazenamento em um arquivo morto. O operador Extraction ( **>>** ) dá suporte ao carregamento de um arquivo morto.

##  <a name="setstring"></a>  COleVariant::SetString

Define a cadeia de caracteres para um tipo específico.

```
void SetString(LPCTSTR lpszSrc, VARTYPE vtSrc);
```

### <a name="parameters"></a>Parâmetros

*lpszSrc*<br/>
Uma cadeia de caracteres terminada em nulo a ser copiada para o novo `COleVariant` objeto.

*VtSrc*<br/>
O VarType para o novo `COleVariant` objeto.

### <a name="remarks"></a>Comentários

O parâmetro *vtSrc* deve ser VT_BSTR (Unicode) ou VT_BSTRT (ANSI). `SetString`normalmente é usado para definir cadeias de caracteres para ANSI, pois o padrão para o construtor [COleVariant:: COleVariant](#colevariant) com um parâmetro de ponteiro de cadeia de caracteres ou cadeia de caracteres e nenhum VARTYPE é Unicode.

Um conjunto de registros DAO em uma compilação não-UNICODE espera que as cadeias de caracteres sejam ANSI. Portanto, para funções do DAO que `COleVariant` usam objetos, se você não estiver criando um conjunto de registros Unicode, deverá usar a forma **COleVariant:: COleVariant (** *lpszSrc* **,** *vtSrc* **)** do construtor com *vtSrc* definido como VT _BSTRT (ANSI) ou use `SetString` com *vtSrc* definido como VT_BSTRT para criar cadeias de caracteres ANSI. Por exemplo, as `CDaoRecordset` funções [CDaoRecordset:: Seek](../../mfc/reference/cdaorecordset-class.md#seek) e [CDaoRecordset::](../../mfc/reference/cdaorecordset-class.md#setfieldvalue) SetFieldValue usam `COleVariant` objetos como parâmetros. Esses objetos deverão ser ANSI se o conjunto de registros DAO não for UNICODE.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
