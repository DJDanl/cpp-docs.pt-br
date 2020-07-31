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
ms.openlocfilehash: 63bce4695e4e1142b797f24cfbbae71638177d04
ms.sourcegitcommit: 13f42c339fb7af935e3a93ac80e350d5e784c9f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/31/2020
ms.locfileid: "87470895"
---
# <a name="colevariant-class"></a>Classe COleVariant

Encapsula o tipo de dados [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) .

## <a name="syntax"></a>Syntax

```
class COleVariant : public tagVARIANT
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Name|Descrição|
|----------|-----------------|
|[COleVariant::COleVariant](#colevariant)|Constrói um objeto `COleVariant`.|

### <a name="public-methods"></a>Métodos públicos

|Name|Descrição|
|----------|-----------------|
|[COleVariant:: Attach](#attach)|Anexa uma variante a um `COleVariant` .|
|[COleVariant:: ChangeType](#changetype)|Altera o tipo de variante deste `COleVariant` objeto.|
|[COleVariant:: Clear](#clear)|Limpa esse objeto `COleVariant`.|
|[COleVariant::D Etach](#detach)|Desanexa uma variante de a `COleVariant` e retorna a variante.|
|[COleVariant::GetByteArrayFromVariantArray](#getbytearrayfromvariantarray)|Recupera uma matriz de bytes de uma matriz Variant existente.|
|[COleVariant:: SetString](#setstring)|Define a cadeia de caracteres para um tipo específico, normalmente ANSI.|

### <a name="public-operators"></a>Operadores públicos

|Name|Descrição|
|----------|-----------------|
|[Operador COleVariant:: Operator LPCVARIANT](#operator_lpcvariant)|Converte um `COleVariant` valor em um `LPCVARIANT` .|
|[Operador COleVariant:: Operator LPVARIANT](#operator_lpvariant)|Converte um `COleVariant` objeto em um `LPVARIANT` .|
|[COleVariant:: Operator =](#operator_eq)|Copia um `COleVariant` valor.|
|[COleVariant:: Operator = =](#operator_eq_eq)|Compara dois `COleVariant` valores.|
|[Operador COleVariant:: &lt; &lt; ,&gt;&gt;](#operator_lt_lt__gt_gt)|Gera um `COleVariant` valor para `CArchive` ou `CDumpContext` e insere um `COleVariant` objeto de `CArchive` .|

## <a name="remarks"></a>Comentários

Esse tipo de dados é usado na automação OLE. Especificamente, a estrutura [DISPPARAMS](/windows/win32/api/oaidl/ns-oaidl-dispparams) contém um ponteiro para uma matriz de estruturas Variant. Uma `DISPPARAMS` estrutura é usada para passar parâmetros para [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke).

> [!NOTE]
> Essa classe é derivada da `VARIANT` estrutura. Isso significa que você pode passar um `COleVariant` em um parâmetro que chama um `VARIANT` e que os membros de dados da `VARIANT` estrutura são membros de dados acessíveis do `COleVariant` .

As duas classes do MFC relacionadas [COleCurrency](../../mfc/reference/colecurrency-class.md) e [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) encapsulam a moeda dos tipos de dados Variant ( `VT_CY` ) e Date ( `VT_DATE` ). A `COleVariant` classe é usada extensivamente nas classes DAO; Veja essas classes para uso típico dessa classe, por exemplo, [CDaoQueryDef](../../mfc/reference/cdaoquerydef-class.md) e [CDaoRecordset](../../mfc/reference/cdaorecordset-class.md).

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant), [Currency](/windows/win32/api/wtypes/ns-wtypes-cy-r1), [DISPPARAMS](/windows/win32/api/oaidl/ns-oaidl-dispparams)e [IDispatch:: Invoke](/windows/win32/api/oaidl/nf-oaidl-idispatch-invoke) no SDK do Windows.

Para obter mais informações sobre a `COleVariant` classe e seu uso na automação OLE, consulte "passando parâmetros na automação OLE" no artigo [automação](../../mfc/automation.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`tagVARIANT`

`COleVariant`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="colevariantattach"></a><a name="attach"></a>COleVariant:: Attach

Chame essa função para anexar o objeto [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) fornecido ao objeto atual `COleVariant` .

```cpp
void Attach(VARIANT& varSrc);
```

### <a name="parameters"></a>Parâmetros

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um `VARIANT` objeto existente a ser anexado ao objeto atual `COleVariant` .

### <a name="remarks"></a>Comentários

Essa função define o VARTYPE de *varSrc* como VT_EMPTY.

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) e [VarEnum](/windows/win32/api/wtypes/ne-wtypes-varenum) no SDK do Windows.

## <a name="colevariantcolevariant"></a><a name="colevariant"></a>COleVariant::COleVariant

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

*{1&amp;gt;varSrc&amp;lt;1}*<br/>
Um `COleVariant` objeto existente ou `VARIANT` a ser copiado para o novo `COleVariant` objeto.

*pSrc*<br/>
Um ponteiro para um `VARIANT` objeto que será copiado para o novo `COleVariant` objeto.

*lpszSrc*<br/>
Uma cadeia de caracteres terminada em nulo a ser copiada para o novo `COleVariant` objeto.

*vtSrc*<br/>
O `VARTYPE` para o novo `COleVariant` objeto.

*strSrc*<br/>
Um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) a ser copiado para o novo `COleVariant` objeto.

*nSrc*, *lSrc* um valor numérico a ser copiado para o novo `COleVariant` objeto.

*vtSrc*<br/>
O `VARTYPE` para o novo `COleVariant` objeto.

*curSrc*<br/>
Um objeto [COleCurrency](../../mfc/reference/colecurrency-class.md) a ser copiado para o novo `COleVariant` objeto.

*fltSrc*, *dblSrc*<br/>
Um valor numérico a ser copiado no novo objeto `COleVariant`.

*timeSrc*<br/>
Um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) a ser copiado para o novo `COleVariant` objeto.

*arrSrc*<br/>
Um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) a ser copiado para o novo `COleVariant` objeto.

*lbSrc*<br/>
Um objeto [CLongBinary](../../mfc/reference/clongbinary-class.md) a ser copiado para o novo `COleVariant` objeto.

*pidl*<br/>
Um ponteiro para uma estrutura [ITEMIDLIST](/windows/win32/api/shtypes/ns-shtypes-itemidlist) a ser copiada para o novo `COleVariant` objeto.

### <a name="remarks"></a>Comentários

Todos esses construtores criam novos `COleVariant` objetos inicializados para o valor especificado. Segue uma breve descrição de cada um desses construtores.

- **COleVariant ()** Cria um `COleVariant` objeto vazio, VT_EMPTY.

- **COleVariant (** *varSrc* **)** Copia um `VARIANT` objeto ou existente `COleVariant` . O tipo de variante é mantido.

- **COleVariant (** *pSrc* **)** Copia um `VARIANT` objeto ou existente `COleVariant` . O tipo de variante é mantido.

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

## <a name="colevariantchangetype"></a><a name="changetype"></a>COleVariant:: ChangeType

Converte o tipo de valor de variante neste `COleVariant` objeto.

```cpp
void ChangeType(VARTYPE vartype, LPVARIANT pSrc = NULL);
```

### <a name="parameters"></a>Parâmetros

*VarType*<br/>
O VARTYPE deste `COleVariant` objeto.

*pSrc*<br/>
Um ponteiro para o objeto [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) a ser convertido. Se esse valor for nulo, esse `COleVariant` objeto será usado como a origem da conversão.

### <a name="remarks"></a>Comentários

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant), [VarEnum](/windows/win32/api/wtypes/ne-wtypes-varenum)e [VariantChangeType](/windows/win32/api/oleauto/nf-oleauto-variantchangetype) no SDK do Windows.

## <a name="colevariantclear"></a><a name="clear"></a>COleVariant:: Clear

Limpa o `VARIANT`.

```cpp
void Clear();
```

### <a name="remarks"></a>Comentários

Isso define o VARTYPE para este objeto como VT_EMPTY. O `COleVariant` destruidor chama essa função.

Para obter mais informações, consulte o `VARIANT` , VARTYPE e `VariantClear` entradas no SDK do Windows.

## <a name="colevariantdetach"></a><a name="detach"></a>COleVariant::D Etach

Desanexa o objeto [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) subjacente deste `COleVariant` objeto.

```
VARIANT Detach();
```

### <a name="remarks"></a>Comentários

Essa função define o VARTYPE para este `COleVariant` objeto como VT_EMPTY.

> [!NOTE]
> Depois de chamar `Detach` , é responsabilidade do chamador chamar `VariantClear` na `VARIANT` estrutura resultante.

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant), [VarEnum](/windows/win32/api/wtypes/ne-wtypes-varenum)e [VariantClear](/windows/win32/api/oleauto/nf-oleauto-variantclear) no SDK do Windows.

## <a name="colevariantgetbytearrayfromvariantarray"></a><a name="getbytearrayfromvariantarray"></a>COleVariant::GetByteArrayFromVariantArray

Recupera uma matriz de bytes de uma matriz Variant existente

```cpp
void GetByteArrayFromVariantArray(CByteArray& bytes);
```

### <a name="parameters"></a>Parâmetros

*bytes*<br/>
Uma referência a um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) existente.

## <a name="colevariantoperator-lpcvariant"></a><a name="operator_lpcvariant"></a>Operador COleVariant:: Operator LPCVARIANT

Esse operador de conversão retorna uma `VARIANT` estrutura cujo valor é copiado deste `COleVariant` objeto.

```
operator LPCVARIANT() const;
```

### <a name="remarks"></a>Comentários

## <a name="colevariantoperator-lpvariant"></a><a name="operator_lpvariant"></a>Operador COleVariant:: Operator LPVARIANT

Chame esse operador de conversão para acessar a `VARIANT` estrutura subjacente desse `COleVariant` objeto.

```
operator LPVARIANT();
```

### <a name="remarks"></a>Comentários

> [!CAUTION]
> Alterar o valor na `VARIANT` estrutura acessado pelo ponteiro retornado por essa função alterará o valor desse `COleVariant` objeto.

## <a name="colevariantoperator-"></a><a name="operator_eq"></a>COleVariant:: Operator =

Esses operadores de atribuição sobrecarregados copiam o valor de origem nesse `COleVariant` objeto.

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

- **Operator = (** *strSrc* **)** Copia um objeto [CString](../../atl-mfc-shared/reference/cstringt-class.md) nesse objeto e define o VARTYPE como VT_BSTR.

- **Operator = (** *nSrc* **)** Copia um valor inteiro de 8 ou 16 bits nesse objeto. Se *nSrc* for um valor de 8 bits, o VarType dessa configuração será definido como VT_UI1. Se *nSrc* for um valor de 16 bits e o VARTYPE for VT_BOOL, ele será mantido; caso contrário, ele será definido como VT_I2.

- **Operator = (** *lSrc* **)** Copia um valor inteiro de 32 bits para esse objeto. Se o VARTYPE deste for VT_ERROR, ele será mantido; caso contrário, ele será definido como VT_I4.

- **Operator = (** *curSrc* **)** Copia um objeto [COleCurrency](../../mfc/reference/colecurrency-class.md) nesse objeto e define o VARTYPE como VT_CY.

- **Operator = (** *fltSrc* **)** Copia um valor de ponto flutuante de 32 bits para esse objeto e define o VARTYPE como VT_R4.

- **Operator = (** *dblSrc* **)** Copia um valor de ponto flutuante de 64 bits para esse objeto e define o VARTYPE como VT_R8.

- **Operator = (** *dateSrc* **)** Copia um objeto [COleDateTime](../../atl-mfc-shared/reference/coledatetime-class.md) nesse objeto e define o VARTYPE como VT_DATE.

- **Operator = (** *arrSrc* **)** Copia um objeto [CByteArray](../../mfc/reference/cbytearray-class.md) nesse `COleVariant` objeto.

- **Operator = (** *lbSrc* **)** Copia um objeto [CLongBinary](../../mfc/reference/clongbinary-class.md) nesse `COleVariant` objeto.

Para obter mais informações, consulte as entradas [Variant](/windows/win32/api/oaidl/ns-oaidl-variant) e [VarEnum](/windows/win32/api/wtypes/ne-wtypes-varenum) no SDK do Windows.

## <a name="colevariantoperator-"></a><a name="operator_eq_eq"></a>COleVariant:: Operator = =

Esse operador compara dois valores variantes e retorna zero, se forem iguais; caso contrário, 0.

```
BOOL operator==(const VARIANT& varSrc) const;
BOOL operator==(LPCVARIANT pSrc) const;
```

## <a name="colevariantoperator-ltlt-gtgt"></a><a name="operator_lt_lt__gt_gt"></a>Operador COleVariant:: &lt; &lt; ,&gt;&gt;

Gera um `COleVariant` valor para `CArchive` ou `CdumpContext` e insere um `COleVariant` objeto de `CArchive` .

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

O `COleVariant` operador de inserção ( **\<\<**) operator supports diagnostic dumping and storing to an archive. The extraction (**>>** ) dá suporte ao carregamento de um arquivo morto.

## <a name="colevariantsetstring"></a><a name="setstring"></a>COleVariant:: SetString

Define a cadeia de caracteres para um tipo específico.

```cpp
void SetString(LPCTSTR lpszSrc, VARTYPE vtSrc);
```

### <a name="parameters"></a>Parâmetros

*lpszSrc*<br/>
Uma cadeia de caracteres terminada em nulo a ser copiada para o novo `COleVariant` objeto.

*VtSrc*<br/>
O VARTYPE para o novo `COleVariant` objeto.

### <a name="remarks"></a>Comentários

O parâmetro *vtSrc* deve ser VT_BSTR (Unicode) ou VT_BSTRT (ANSI). `SetString`normalmente é usado para definir cadeias de caracteres para ANSI, pois o padrão para o construtor [COleVariant:: COleVariant](#colevariant) com um parâmetro de ponteiro de cadeia de caracteres ou cadeia de caracteres e nenhum VARTYPE é Unicode.

Um conjunto de registros DAO em uma compilação não-UNICODE espera que as cadeias de caracteres sejam ANSI. Portanto, para funções do DAO que usam `COleVariant` objetos, se você não estiver criando um conjunto de registros Unicode, deverá usar a forma **COleVariant:: COleVariant (** *lpszSrc* **,** *vtSrc* **)** do construtor com *vtSrc* definido como VT_BSTRT (ANSI) ou usar `SetString` with *vtSrc* definido como VT_BSTRT para criar cadeias de caracteres ANSI. Por exemplo, as `CDaoRecordset` funções [CDaoRecordset:: Seek](../../mfc/reference/cdaorecordset-class.md#seek) e [CDaoRecordset:: SetFieldValue](../../mfc/reference/cdaorecordset-class.md#setfieldvalue) usam `COleVariant` objetos como parâmetros. Esses objetos deverão ser ANSI se o conjunto de registros DAO não for UNICODE.

## <a name="see-also"></a>Veja também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
